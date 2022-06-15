/******************************************************************************
 * Copyright 2016-2021 The Firmament Authors. All Rights Reserved.
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

#define SPI_USE_DMA

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

#ifdef SPI_USE_DMA
static uint8_t dummy = 0xFF;
static void DMA_RxConfiguration(struct stm32_spi_bus* stm32_spi_bus,
                                const void* send_addr,
                                void* recv_addr,
                                rt_size_t size)
{
    DMA_InitTypeDef DMA_InitStructure;

    /* Reset DMA Stream registers (for debug purpose) */
    DMA_DeInit(stm32_spi_bus->DMA_Stream_RX);
    DMA_DeInit(stm32_spi_bus->DMA_Stream_TX);

    /* Check if the DMA Stream is disabled before enabling it.
	   Note that this step is useful when the same Stream is used multiple times:
	   enabled, then disabled then re-enabled... In this case, the DMA Stream disable
	   will be effective only at the end of the ongoing data transfer and it will
	   not be possible to re-configure it before making sure that the Enable bit
	   has been cleared by hardware. If the Stream is used only once, this step might
	   be bypassed. */
    while (DMA_GetCmdStatus(stm32_spi_bus->DMA_Stream_RX) != DISABLE)
        ;

    while (DMA_GetCmdStatus(stm32_spi_bus->DMA_Stream_TX) != DISABLE)
        ;

    /* Configure DMA_RX Stream */
    DMA_Cmd(stm32_spi_bus->DMA_Stream_RX, DISABLE);

    DMA_InitStructure.DMA_Channel = stm32_spi_bus->DMA_Channel_RX;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&(stm32_spi_bus->SPI->DR));
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_BufferSize = (uint32_t)size;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

    if (recv_addr != RT_NULL) {
        DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)recv_addr;
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    } else {
        DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)(&dummy);
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    }

    DMA_Init(stm32_spi_bus->DMA_Stream_RX, &DMA_InitStructure);

    DMA_Cmd(stm32_spi_bus->DMA_Stream_RX, ENABLE);

    /* Configure DMA_TX Stream */
    DMA_Cmd(stm32_spi_bus->DMA_Stream_TX, DISABLE);

    DMA_InitStructure.DMA_Channel = stm32_spi_bus->DMA_Channel_TX;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&(stm32_spi_bus->SPI->DR));
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_BufferSize = (uint32_t)size;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

    if (send_addr != RT_NULL) {
        DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)send_addr;
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    } else {
        dummy = 0xFF;
        DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)(&dummy);
        ;
        DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    }

    DMA_Init(stm32_spi_bus->DMA_Stream_TX, &DMA_InitStructure);

    DMA_Cmd(stm32_spi_bus->DMA_Stream_TX, ENABLE);
}
#endif

static rt_err_t configure(struct rt_spi_device* device,
                          struct rt_spi_configuration* configuration)
{
    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;
    SPI_InitTypeDef SPI_InitStructure;

    SPI_StructInit(&SPI_InitStructure);

    RCC_ClocksTypeDef rcc_clocks;

    RCC_GetClocksFreq(&rcc_clocks);

    /* data_width */
    if (configuration->data_width <= 8) {
        SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    } else if (configuration->data_width <= 16) {
        SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;
    } else {
        return RT_EIO;
    }

    /* baudrate */
    {
        uint32_t stm32_spi_max_clock;
        uint32_t max_hz;
        uint32_t PCLK;

        /* stm32f4xx SPI max_clock=PCLK/2 */
        if (stm32_spi_bus->SPI == SPI2 || stm32_spi_bus->SPI == SPI3) {
            PCLK = rcc_clocks.PCLK1_Frequency;
        } else {
            PCLK = rcc_clocks.PCLK2_Frequency;
        }

        stm32_spi_max_clock = PCLK / 2;
        max_hz = configuration->max_hz;

        if (max_hz > stm32_spi_max_clock) {
            max_hz = stm32_spi_max_clock;
        }

        if (max_hz >= PCLK / 2) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
        } else if (max_hz >= PCLK / 4) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
        } else if (max_hz >= PCLK / 8) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
        } else if (max_hz >= PCLK / 16) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
        } else if (max_hz >= PCLK / 32) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
        } else if (max_hz >= PCLK / 64) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
        } else if (max_hz >= PCLK / 128) {
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
        } else {
            /*  min prescaler 256 */
            SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
        }
    } /* baudrate */

    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
    } else {
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    }

    /* CPHA */
    if (configuration->mode & RT_SPI_CPHA) {
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
    } else {
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    }

    /* MSB or LSB */
    if (configuration->mode & RT_SPI_MSB) {
        SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    } else {
        SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_LSB;
    }

    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;

    /* init SPI */
    SPI_I2S_DeInit(stm32_spi_bus->SPI);
    SPI_Init(stm32_spi_bus->SPI, &SPI_InitStructure);
    SPI_CalculateCRC(stm32_spi_bus->SPI, DISABLE);
    /* Enable SPI_MASTER */
    SPI_Cmd(stm32_spi_bus->SPI, ENABLE);

    return RT_EOK;
};

static rt_uint32_t transfer(struct rt_spi_device* device, struct rt_spi_message* message)
{
    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;
    struct rt_spi_configuration* config = &device->config;
    SPI_TypeDef* SPI = stm32_spi_bus->SPI;
    struct stm32_spi_cs* stm32_spi_cs = device->parent.user_data;
    rt_uint32_t size = message->length;

    /* take CS */
    if (message->cs_take) {
        GPIO_ResetBits(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin);
    }

#ifdef SPI_USE_DMA

    if (message->length > 8) {
        if (config->data_width <= 8) {
            DMA_RxConfiguration(stm32_spi_bus, message->send_buf, message->recv_buf, message->length);
            //            SPI_I2S_ClearFlag(SPI, SPI_I2S_FLAG_RXNE);
            SPI_I2S_DMACmd(SPI, SPI_I2S_DMAReq_Tx | SPI_I2S_DMAReq_Rx, ENABLE);

            while (DMA_GetFlagStatus(stm32_spi_bus->DMA_Stream_RX, stm32_spi_bus->DMA_Channel_RX_FLAG_TC) == RESET
                   || DMA_GetFlagStatus(stm32_spi_bus->DMA_Stream_TX, stm32_spi_bus->DMA_Channel_TX_FLAG_TC) == RESET)
                ;

            SPI_I2S_DMACmd(SPI, SPI_I2S_DMAReq_Tx | SPI_I2S_DMAReq_Rx, DISABLE);
        }
    } else
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

                //Wait until the transmit buffer is empty
                while (SPI_I2S_GetFlagStatus(SPI, SPI_I2S_FLAG_TXE) == RESET)
                    ;

                // Send the byte
                SPI_I2S_SendData(SPI, data);

                //Wait until a data is received
                while (SPI_I2S_GetFlagStatus(SPI, SPI_I2S_FLAG_RXNE) == RESET)
                    ;

                // Get the received data
                data = SPI_I2S_ReceiveData(SPI);

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

                //Wait until the transmit buffer is empty
                while (SPI_I2S_GetFlagStatus(SPI, SPI_I2S_FLAG_TXE) == RESET)
                    ;

                // Send the byte
                SPI_I2S_SendData(SPI, data);

                //Wait until a data is received
                while (SPI_I2S_GetFlagStatus(SPI, SPI_I2S_FLAG_RXNE) == RESET)
                    ;

                // Get the received data
                data = SPI_I2S_ReceiveData(SPI);

                if (recv_ptr != RT_NULL) {
                    *recv_ptr++ = data;
                }
            }
        }
    }

    /* release CS */
    if (message->cs_release) {
        GPIO_SetBits(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin);
    }

    return message->length;
};

static struct rt_spi_ops stm32_spi_ops = {
    configure,
    transfer
};

/** \brief init and register stm32 spi bus.
 *
 * \param SPI: STM32 SPI, e.g: SPI1,SPI2,SPI3.
 * \param stm32_spi: stm32 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return
 *
 */
static rt_err_t stm32_spi_register(SPI_TypeDef* SPI,
                                   struct stm32_spi_bus* stm32_spi,
                                   const char* spi_bus_name)
{
    if (SPI == SPI1) {
        stm32_spi->SPI = SPI1;
#ifdef SPI_USE_DMA
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
        /* DMA2_Stream0 DMA_Channel_3 : SPI1_RX */
        /* DMA2_Stream2 DMA_Channel_3 : SPI1_RX */
        stm32_spi->DMA_Stream_RX = DMA2_Stream0;
        stm32_spi->DMA_Channel_RX = DMA_Channel_3;
        stm32_spi->DMA_Channel_RX_FLAG_TC = DMA_FLAG_TCIF0;
        /* DMA2_Stream3 DMA_Channel_3 : SPI1_TX */
        /* DMA2_Stream5 DMA_Channel_3 : SPI1_TX */
        stm32_spi->DMA_Stream_TX = DMA2_Stream3;
        stm32_spi->DMA_Channel_TX = DMA_Channel_3;
        stm32_spi->DMA_Channel_TX_FLAG_TC = DMA_FLAG_TCIF3;
#endif
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    } else if (SPI == SPI2) {
        stm32_spi->SPI = SPI2;
#ifdef SPI_USE_DMA
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
        /* DMA1_Stream3 DMA_Channel_0 : SPI2_RX */
        stm32_spi->DMA_Stream_RX = DMA1_Stream3;
        stm32_spi->DMA_Channel_RX = DMA_Channel_0;
        stm32_spi->DMA_Channel_RX_FLAG_TC = DMA_FLAG_TCIF3;
        /* DMA1_Stream4 DMA_Channel_0 : SPI2_TX */
        stm32_spi->DMA_Stream_TX = DMA1_Stream4;
        stm32_spi->DMA_Channel_TX = DMA_Channel_0;
        stm32_spi->DMA_Channel_TX_FLAG_TC = DMA_FLAG_TCIF4;
#endif
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
    } else if (SPI == SPI3) {
        stm32_spi->SPI = SPI3;
#ifdef SPI_USE_DMA
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
        /* DMA1_Stream2 DMA_Channel_0 : SPI3_RX */
        stm32_spi->DMA_Stream_RX = DMA1_Stream2;
        stm32_spi->DMA_Channel_RX = DMA_Channel_0;
        stm32_spi->DMA_Channel_RX_FLAG_TC = DMA_FLAG_TCIF2;
        /* DMA1_Stream5 DMA_Channel_0 : SPI3_TX */
        stm32_spi->DMA_Stream_TX = DMA1_Stream5;
        stm32_spi->DMA_Channel_TX = DMA_Channel_0;
        stm32_spi->DMA_Channel_TX_FLAG_TC = DMA_FLAG_TCIF5;
#endif
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);
    } else {
        return RT_ENOSYS;
    }

    return rt_spi_bus_register(&stm32_spi->parent, spi_bus_name, &stm32_spi_ops);
}

/*** SPI1 BUS and device
SPI1_MOSI: PA7
SPI1_MISO: PA6
SPI1_SCK : PA5
*/
rt_err_t drv_spi_init(void)
{
    rt_err_t ret = RT_EOK;
    /* register SPI bus */
    static struct stm32_spi_bus stm32_spi1;

    /* SPI1 configure */
    {
        GPIO_InitTypeDef GPIO_InitStructure;

        /* Enable SPI1 Periph clock */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

        GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
        GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
        GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);

        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //for emi
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; //NO PULL, pull up will let sdcard unsteady

        /* Configure SPI1 pins */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    } /* SPI1 configuration */

    /* register SPI1 bus */
    ret |= stm32_spi_register(SPI1, &stm32_spi1, "spi1");

    /* attach spi_device_1 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct stm32_spi_cs stm32_spi_cs_1;

        GPIO_InitTypeDef GPIO_InitStructure;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

        stm32_spi_cs_1.GPIOx = GPIOC;
        stm32_spi_cs_1.GPIO_Pin = GPIO_Pin_15;

        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        GPIO_SetBits(stm32_spi_cs_1.GPIOx, stm32_spi_cs_1.GPIO_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_1, "spi1_dev1", "spi1", (void*)&stm32_spi_cs_1);
    }

    /* attach spi_device_2 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_2;
        static struct stm32_spi_cs stm32_spi_cs_2;

        GPIO_InitTypeDef GPIO_InitStructure;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

        stm32_spi_cs_2.GPIOx = GPIOC;
        stm32_spi_cs_2.GPIO_Pin = GPIO_Pin_13;

        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        GPIO_SetBits(stm32_spi_cs_2.GPIOx, stm32_spi_cs_2.GPIO_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_2, "spi1_dev2", "spi1", (void*)&stm32_spi_cs_2);
    }

    /* attach spi_device_3 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_3;
        static struct stm32_spi_cs stm32_spi_cs_3;

        GPIO_InitTypeDef GPIO_InitStructure;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

        stm32_spi_cs_3.GPIOx = GPIOD;
        stm32_spi_cs_3.GPIO_Pin = GPIO_Pin_7;

        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
        GPIO_Init(GPIOD, &GPIO_InitStructure);

        GPIO_SetBits(stm32_spi_cs_3.GPIOx, stm32_spi_cs_3.GPIO_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_3, "spi1_dev3", "spi1", (void*)&stm32_spi_cs_3);
    }

    /* attach spi_device_4 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_4;
        static struct stm32_spi_cs stm32_spi_cs_4;

        GPIO_InitTypeDef GPIO_InitStructure;

        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

        stm32_spi_cs_4.GPIOx = GPIOC;
        stm32_spi_cs_4.GPIO_Pin = GPIO_Pin_2;

        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        GPIO_SetBits(stm32_spi_cs_4.GPIOx, stm32_spi_cs_4.GPIO_Pin);

        ret |= rt_spi_bus_attach_device(&rt_spi_device_4, "spi1_dev4", "spi1", (void*)&stm32_spi_cs_4);
    }

    return ret;
}
