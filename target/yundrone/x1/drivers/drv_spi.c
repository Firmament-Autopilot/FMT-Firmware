/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "drv_spi.h"
#include "hal/spi/spi.h"
#include "stm32h7xx_ll_spi.h"

// #define SPI_USE_DMA

#define SPI_TIMEOUT_US (500)

struct stm32_spi_bus {
    struct rt_spi_bus parent;
    SPI_TypeDef* SPI;
#ifdef SPI_USE_DMA
    DMA_Stream_TypeDef* DMA_Stream_TX;
    uint32_t DMA_Channel_TX;

    DMA_Stream_TypeDef* DMA_Stream_RX;
    uint32_t DMA_Channel_RX;

    uint32_t DMA_Channel_TX_FLAG_TC;
    uint32_t DMA_Channel_RX_FLAG_TC;
#endif /* #ifdef SPI_USE_DMA */
};

struct stm32_spi_cs {
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
};

static fmt_err_t wait_flag_until_timeout(const SPI_TypeDef *SPIx, uint32_t flag, uint32_t status, uint64_t timeout_us)
{
    uint64_t time_start = systime_now_us();

    while (((READ_BIT(SPIx->SR, flag) == flag) ? 1UL : 0UL) == status) {
        if ((systime_now_us() - time_start) > timeout_us) {
            return FMT_ETIMEOUT;
        }
    }
    return FMT_EOK;
}

/**
 * @brief Configure spi device
 *
 * @param device SPI device
 * @param configuration SPI device configuration
 * @return rt_err_t RT_EOK for success
 */
static rt_err_t configure(struct rt_spi_device* device, struct rt_spi_configuration* configuration)
{
    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;

    LL_SPI_InitTypeDef SPI_InitStruct = { 0 };
    LL_SPI_StructInit(&SPI_InitStruct);

    if (configuration->data_width <= 8) {
        SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    } else if (configuration->data_width <= 16) {
        SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_16BIT;
    } else {
        return RT_EIO;
    }

    /* baudrate */
    {
        uint32_t spi_clock;
        uint32_t max_hz = configuration->max_hz;

        if (stm32_spi_bus->SPI == SPI1 || stm32_spi_bus->SPI == SPI2 || stm32_spi_bus->SPI == SPI3) {
            spi_clock = LL_RCC_GetSPIClockFreq(LL_RCC_SPI123_CLKSOURCE);
        } else if (stm32_spi_bus->SPI == SPI4 || stm32_spi_bus->SPI == SPI5) {
            spi_clock = LL_RCC_GetSPIClockFreq(LL_RCC_SPI45_CLKSOURCE);
        }

        if (max_hz > spi_clock) {
            max_hz = spi_clock;
        }

        if (max_hz >= spi_clock / 2) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
        } else if (max_hz >= spi_clock / 4) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV4;
        } else if (max_hz >= spi_clock / 8) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8;
        } else if (max_hz >= spi_clock / 16) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV16;
        } else if (max_hz >= spi_clock / 32) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV32;
        } else if (max_hz >= spi_clock / 64) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV64;
        } else if (max_hz >= spi_clock / 128) {
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV128;
        } else {
            /*  min prescaler 256 */
            SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV256;
        }
    } /* baudrate */

    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_HIGH;
    } else {
        SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
    }

    /* CPHA */
    if (configuration->mode & RT_SPI_CPHA) {
        SPI_InitStruct.ClockPhase = LL_SPI_PHASE_2EDGE;
    } else {
        SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
    }

    /* MSB or LSB */
    if (configuration->mode & RT_SPI_MSB) {
        SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
    } else {
        SPI_InitStruct.BitOrder = LL_SPI_LSB_FIRST;
    }

    SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
    SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
    SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
    SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    SPI_InitStruct.CRCPoly = 0x0;

    LL_SPI_DeInit(stm32_spi_bus->SPI);
    LL_SPI_Init(stm32_spi_bus->SPI, &SPI_InitStruct);
    LL_SPI_SetStandard(stm32_spi_bus->SPI, LL_SPI_PROTOCOL_MOTOROLA);
    LL_SPI_DisableNSSPulseMgt(stm32_spi_bus->SPI);
    LL_SPI_Enable(stm32_spi_bus->SPI);

    return RT_EOK;
}

/**
 * @brief SPI transfer function
 *
 * @param device SPI device instance
 * @param message SPI message to be transfered
 * @return rt_uint32_t bytes have been transfered
 */
static rt_uint32_t transfer(struct rt_spi_device* device, struct rt_spi_message* message)
{
    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;
    struct rt_spi_configuration* config = &device->config;
    SPI_TypeDef* SPI = stm32_spi_bus->SPI;
    struct stm32_spi_cs* stm32_spi_cs = device->parent.user_data;
    rt_uint32_t size = message->length;

    /* take CS */
    if (message->cs_take) {
        LL_GPIO_ResetOutputPin(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin);
    }

#ifdef SPI_USE_DMA
    #error Not support SPI DMA.
#endif

    {
        if (config->data_width <= 8) {
            const rt_uint8_t* send_ptr = message->send_buf;
            rt_uint8_t* recv_ptr = message->recv_buf;

            while (size--) {
                rt_uint8_t data = 0xFF;

                if (send_ptr != RT_NULL) {
                    data = *send_ptr++;
                }

                // start spi !!!!
                LL_SPI_StartMasterTransfer(SPI);

                /* Wait until the transmit buffer is empty */
                wait_flag_until_timeout(SPI, SPI_SR_TXP, RESET, SPI_TIMEOUT_US);

                /* Send the byte */
                LL_SPI_TransmitData8(SPI, data);

                /* Wait until a data is received */
                wait_flag_until_timeout(SPI, SPI_SR_RXP, RESET, SPI_TIMEOUT_US);


                /* Get the received data */
                data = LL_SPI_ReceiveData8(SPI);

                LL_SPI_ClearFlag_EOT(SPI);
                LL_SPI_ClearFlag_TXTF(SPI);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        } else if (config->data_width <= 16) {
            const rt_uint16_t* send_ptr = message->send_buf;
            rt_uint16_t* recv_ptr = message->recv_buf;

            while (size--) {
                rt_uint16_t data = 0xFF;

                if (send_ptr != RT_NULL) {
                    data = *send_ptr++;
                }
                /* Wait until the transmit buffer is empty */
                wait_flag_until_timeout(SPI, SPI_SR_TXP, RESET, SPI_TIMEOUT_US);

                /* Send the byte */
                LL_SPI_TransmitData16(SPI, data);
                /* Wait until a data is received */
                wait_flag_until_timeout(SPI, SPI_SR_RXP, RESET, SPI_TIMEOUT_US);

                /* Get the received data */
                data = LL_SPI_ReceiveData16(SPI);

                LL_SPI_ClearFlag_EOT(SPI);
                LL_SPI_ClearFlag_TXTF(SPI);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        }
    }

    /* release CS */
    if (message->cs_release) {
        LL_GPIO_SetOutputPin(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin);
    }

    return message->length;
}

static struct rt_spi_ops stm32_spi_ops = { configure, transfer };

/** \brief init and register stm32 spi bus.
 *
 * \param SPI: STM32 SPI, e.g: SPI1,SPI2,SPI3.
 * \param stm32_spi: stm32 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return rt_err_t RT_EOK for success
 */
static rt_err_t stm32_spi_register(SPI_TypeDef* SPI, struct stm32_spi_bus* stm32_spi, const char* spi_bus_name)
{
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    if (SPI == SPI1) {
        stm32_spi->SPI = SPI1;

        /* Peripheral clock enable */
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);
        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
        /**SPI1 GPIO Configuration
        PD7   ------> SPI1_MOSI
        PA6   ------> SPI1_MISO
        PA5   ------> SPI1_SCK
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_5;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

#ifdef SPI_USE_DMA

#endif
    } else if (SPI == SPI2) {
        stm32_spi->SPI = SPI2;

        /* Peripheral clock enable */
        LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);
        /**SPI2 GPIO Configuration
        PI1   ------> SPI2_SCK
        PI3   ------> SPI2_MOSI
        PI2   ------> SPI2_MISO
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_3 | LL_GPIO_PIN_2 | LL_GPIO_PIN_1;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

#ifdef SPI_USE_DMA

#endif
    } else if (SPI == SPI4) {
        stm32_spi->SPI = SPI4;

        /* Peripheral clock enable */
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI4);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
        /**SPI4 GPIO Configuration
        PE2   ------> SPI4_SCK
        PE5   ------> SPI4_MISO
        PE6   ------> SPI4_MOSI
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOE, &GPIO_InitStruct);

#ifdef SPI_USE_DMA

#endif
    } else if (SPI == SPI5) {
        stm32_spi->SPI = SPI5;

        /* Peripheral clock enable */
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI5);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);
        /**SPI5 GPIO Configuration
        PF7   ------> SPI5_SCK
        PF9   ------> SPI5_MOSI
        PF8   ------> SPI5_MISO
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_7 | LL_GPIO_PIN_9 | LL_GPIO_PIN_8;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

#ifdef SPI_USE_DMA

#endif
    } else {
        return RT_ENOSYS;
    }

    return rt_spi_bus_register(&stm32_spi->parent, spi_bus_name, &stm32_spi_ops);
}

/**
 * @brief Initialize spi bus and device
 *
 * @return rt_err_t RT_EOK for success
 */
rt_err_t drv_spi_init(void)
{
    LL_RCC_SetSPIClockSource(LL_RCC_SPI123_CLKSOURCE_PLL1Q);
    LL_RCC_SetSPIClockSource(LL_RCC_SPI45_CLKSOURCE_PCLK2);

    /* register SPI bus */
    static struct stm32_spi_bus stm32_spi1;
    /* register SPI1 bus */
    RT_TRY(stm32_spi_register(SPI1, &stm32_spi1, "spi1"));

    /* attach spi1_device_1 (SPL06) to spi1 */
    {
        static struct rt_spi_device rt_spi1_device_1;
        static struct stm32_spi_cs stm32_spi1_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi1_cs_1.GPIOx = GPIOB;
        stm32_spi1_cs_1.GPIO_Pin = LL_GPIO_PIN_1;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_device_1, "spi1_dev1", "spi1", (void*)&stm32_spi1_cs_1));
    }

    static struct stm32_spi_bus stm32_spi4;
    /* register SPI4 bus */
    RT_TRY(stm32_spi_register(SPI4, &stm32_spi4, "spi4"));

    /* attach spi4_device_1 (BMI088_1-G) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_1;
        static struct stm32_spi_cs stm32_spi4_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_1.GPIOx = GPIOC;
        stm32_spi4_cs_1.GPIO_Pin = LL_GPIO_PIN_13;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_1, "spi4_dev1", "spi4", (void*)&stm32_spi4_cs_1));
    }

    /* attach spi4_device_2 (BMI088_1-A) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_2;
        static struct stm32_spi_cs stm32_spi4_cs_2;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_2.GPIOx = GPIOI;
        stm32_spi4_cs_2.GPIO_Pin = LL_GPIO_PIN_8;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_8);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_2, "spi4_dev2", "spi4", (void*)&stm32_spi4_cs_2));
    }

    /* attach spi4_device_4 (BMM150) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_4;
        static struct stm32_spi_cs stm32_spi4_cs_4;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_4.GPIOx = GPIOI;
        stm32_spi4_cs_4.GPIO_Pin = LL_GPIO_PIN_4;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_4);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_4, "spi4_dev4", "spi4", (void*)&stm32_spi4_cs_4));
    }

    /* attach spi4_device_5 (BMI088_2-G) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_5;
        static struct stm32_spi_cs stm32_spi4_cs_5;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_5.GPIOx = GPIOI;
        stm32_spi4_cs_5.GPIO_Pin = LL_GPIO_PIN_10;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_10);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_5, "spi4_dev5", "spi4", (void*)&stm32_spi4_cs_5));
    }

    /* attach spi4_device_6 (BMI088_2-A) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_6;
        static struct stm32_spi_cs stm32_spi4_cs_6;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_6.GPIOx = GPIOI;
        stm32_spi4_cs_6.GPIO_Pin = LL_GPIO_PIN_11;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_11);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_6, "spi4_dev6", "spi4", (void*)&stm32_spi4_cs_6));
    }

    static struct stm32_spi_bus stm32_spi5;
    /* register SPI6 bus */
    RT_TRY(stm32_spi_register(SPI5, &stm32_spi5, "spi5"));

    /* attach spi5_device_1 (GD25Q) to spi5 */
    {
        static struct rt_spi_device rt_spi5_device_1;
        static struct stm32_spi_cs stm32_spi5_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi5_cs_1.GPIOx = GPIOF;
        stm32_spi5_cs_1.GPIO_Pin = LL_GPIO_PIN_10;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_10);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi5_device_1, "spi5_dev1", "spi5", (void*)&stm32_spi5_cs_1));
    }

    return RT_EOK;
}
