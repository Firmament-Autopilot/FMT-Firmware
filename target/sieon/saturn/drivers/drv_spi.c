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

#define DRV_USE_SPI1
#define DRV_USE_SPI2
#define DRV_USE_SPI4
#define DRV_USE_SPI6

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
                while (LL_SPI_IsActiveFlag_TXP(SPI) == RESET)
                    ;

                /* Send the byte */
                LL_SPI_TransmitData8(SPI, data);

                /* Wait until a data is received */
                while (LL_SPI_IsActiveFlag_RXP(SPI) == RESET)
                    ;
                // RT_ASSERT(RT_EOK);

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
                while (LL_SPI_IsActiveFlag_TXP(SPI) == RESET)
                    ;

                /* Send the byte */
                LL_SPI_TransmitData16(SPI, data);
                /* Wait until a data is received */
                while (LL_SPI_IsActiveFlag_RXP(SPI) == RESET)
                    ;

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
#ifdef DRV_USE_SPI1
        stm32_spi->SPI = SPI1;

        /* Peripheral clock enable */
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOG);
        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);
        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
        /**SPI1 GPIO Configuration
        PG11   ------> SPI1_SCK
        PD7   ------> SPI1_MOSI
        PA6   ------> SPI1_MISO
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    #ifdef SPI_USE_DMA

    #endif
#else
        return RT_ENOSYS;
#endif
    } else if (SPI == SPI2) {
#ifdef DRV_USE_SPI2
        stm32_spi->SPI = SPI2;

        /* Peripheral clock enable */
        LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);
        /**SPI2 GPIO Configuration
        PI1   ------> SPI2_SCK
        PI2   ------> SPI2_MISO
        PI3   ------> SPI2_MOSI
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    #ifdef SPI_USE_DMA

    #endif
#else
        return RT_ENOSYS;
#endif
    } else if (SPI == SPI4) {
#ifdef DRV_USE_SPI4
        stm32_spi->SPI = SPI4;

        /* Peripheral clock enable */
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI4);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
        /**SPI4 GPIO Configuration
        PE2   ------> SPI4_SCK
        PE6   ------> SPI4_MOSI
        PE13   ------> SPI4_MISO
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_6 | LL_GPIO_PIN_13;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
#else
        return RT_ENOSYS;
#endif

    } else if (SPI == SPI6) {
#ifdef DRV_USE_SPI6
        stm32_spi->SPI = SPI6;

        /* Peripheral clock enable */
        LL_APB4_GRP1_EnableClock(LL_APB4_GRP1_PERIPH_SPI6);

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOG);
        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
        /**SPI6 GPIO Configuration
        PG12   ------> SPI6_MISO
        PG13   ------> SPI6_SCK
        PA7   ------> SPI6_MOSI
        */
        GPIO_InitStruct.Pin = LL_GPIO_PIN_12 | LL_GPIO_PIN_13;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
        LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_7;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
        GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
        LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
#else
        return RT_ENOSYS;
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
    LL_RCC_SetSPIClockSource(LL_RCC_SPI6_CLKSOURCE_PCLK4);

    /* register SPI bus */
#ifdef DRV_USE_SPI1
    static struct stm32_spi_bus stm32_spi1;

    /* register SPI1 bus */
    RT_TRY(stm32_spi_register(SPI1, &stm32_spi1, "spi1"));

    /* attach spi1_device_1 (ICM20689) to spi1 */
    {
        static struct rt_spi_device rt_spi1_device_1;
        static struct stm32_spi_cs stm32_spi1_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi1_cs_1.GPIOx = GPIOG;
        stm32_spi1_cs_1.GPIO_Pin = LL_GPIO_PIN_6;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOG);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_6);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_device_1, "spi1_dev1", "spi1", (void*)&stm32_spi1_cs_1));
    }

    /* attach spi1_device_2 (RM3100) to spi1 */
    {
        static struct rt_spi_device rt_spi1_device_2;
        static struct stm32_spi_cs stm32_spi1_cs_2;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi1_cs_2.GPIOx = GPIOF;
        stm32_spi1_cs_2.GPIO_Pin = LL_GPIO_PIN_2;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_2);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi1_device_2, "spi1_dev2", "spi1", (void*)&stm32_spi1_cs_2));
    }
#endif

#ifdef DRV_USE_SPI2
    static struct stm32_spi_bus stm32_spi2;

    /* register SPI2 bus */
    RT_TRY(stm32_spi_register(SPI2, &stm32_spi2, "spi2"));

    /* attach spi2_device_1 (FRAM) to spi2 */
    {
        static struct rt_spi_device rt_spi2_device_1;
        static struct stm32_spi_cs stm32_spi2_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi2_cs_1.GPIOx = GPIOF;
        stm32_spi2_cs_1.GPIO_Pin = LL_GPIO_PIN_5;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_5);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_device_1, "spi2_dev1", "spi2", (void*)&stm32_spi2_cs_1));
    }

    /* attach spi2_device_2 (RM3100) to spi2 */
    {
        static struct rt_spi_device rt_spi2_device_2;
        static struct stm32_spi_cs stm32_spi2_cs_2;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi2_cs_2.GPIOx = GPIOF;
        stm32_spi2_cs_2.GPIO_Pin = LL_GPIO_PIN_2;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOF);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOF, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOF, LL_GPIO_PIN_2);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi2_device_2, "spi2_dev2", "spi2", (void*)&stm32_spi2_cs_2));
    }
#endif

#ifdef DRV_USE_SPI4
    static struct stm32_spi_bus stm32_spi4;

    /* register SPI4 bus */
    RT_TRY(stm32_spi_register(SPI4, &stm32_spi4, "spi4"));

    /* attach spi4_device_1 (ICM42688-P) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_1;
        static struct stm32_spi_cs stm32_spi4_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_1.GPIOx = GPIOA;
        stm32_spi4_cs_1.GPIO_Pin = LL_GPIO_PIN_15;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_15);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_1, "spi4_dev1", "spi4", (void*)&stm32_spi4_cs_1));
    }

    /* attach spi4_device_2 (MS5611) to spi4 */
    {
        static struct rt_spi_device rt_spi4_device_2;
        static struct stm32_spi_cs stm32_spi4_cs_2;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi4_cs_2.GPIOx = GPIOG;
        stm32_spi4_cs_2.GPIO_Pin = LL_GPIO_PIN_10;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOG);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOG, LL_GPIO_PIN_10);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi4_device_2, "spi4_dev2", "spi4", (void*)&stm32_spi4_cs_2));
    }
#endif

#ifdef DRV_USE_SPI6
    static struct stm32_spi_bus stm32_spi6;

    /* register SPI6 bus */
    RT_TRY(stm32_spi_register(SPI6, &stm32_spi6, "spi6"));

    /* attach spi6_device_1 (ICM20649) to spi6 */
    {
        static struct rt_spi_device rt_spi6_device_1;
        static struct stm32_spi_cs stm32_spi6_cs_1;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi6_cs_1.GPIOx = GPIOI;
        stm32_spi6_cs_1.GPIO_Pin = LL_GPIO_PIN_12;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_12;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_12);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi6_device_1, "spi6_dev1", "spi6", (void*)&stm32_spi6_cs_1));
    }

    /* attach spi6_device_2 (MS5611) to spi6 */
    {
        static struct rt_spi_device rt_spi6_device_2;
        static struct stm32_spi_cs stm32_spi6_cs_2;
        LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        stm32_spi6_cs_2.GPIOx = GPIOI;
        stm32_spi6_cs_2.GPIO_Pin = LL_GPIO_PIN_8;

        LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOI);

        GPIO_InitStruct.Pin = LL_GPIO_PIN_8;
        GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
        GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
        GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
        GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
        LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

        LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_8);

        RT_TRY(rt_spi_bus_attach_device(&rt_spi6_device_2, "spi6_dev2", "spi6", (void*)&stm32_spi6_cs_2));
    }
#endif

    return RT_EOK;
}
