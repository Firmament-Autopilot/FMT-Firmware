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
#include "stm32h7xx_hal.h"

// Use HAL library instead of LL library
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

#ifdef DRV_USE_SPI4
SPI_HandleTypeDef hspi4;
#endif

// #define SPI_USE_DMA

#define DRV_USE_SPI1

/* Use CubeMX-generated FMU pin definitions when available to keep names consistent */
#ifdef FMU_SPI1_CS1_BMI055_ACC_Pin
    #define SPI1_CS1_Pin       FMU_SPI1_CS1_BMI055_ACC_Pin
    #define SPI1_CS1_GPIO_Port FMU_SPI1_CS1_BMI055_ACC_GPIO_Port
#else
    #define SPI1_CS1_Pin       GPIO_PIN_13
    #define SPI1_CS1_GPIO_Port GPIOC
#endif

#ifdef FMU_SPI1_CS2_BMI055_GYRO_Pin
    #define SPI1_CS2_Pin       FMU_SPI1_CS2_BMI055_GYRO_Pin
    #define SPI1_CS2_GPIO_Port FMU_SPI1_CS2_BMI055_GYRO_GPIO_Port
#else
    #define SPI1_CS2_Pin       GPIO_PIN_14
    #define SPI1_CS2_GPIO_Port GPIOC
#endif

#ifdef FMU_SPI1_CS3_ICM42688_Pin
    #define SPI1_CS3_Pin       FMU_SPI1_CS3_ICM42688_Pin
    #define SPI1_CS3_GPIO_Port FMU_SPI1_CS3_ICM42688_GPIO_Port
#else
    #define SPI1_CS3_Pin       GPIO_PIN_15
    #define SPI1_CS3_GPIO_Port GPIOC
#endif

// #define SPI1_CS4_Pin       GPIO_PIN_10
// #define SPI1_CS4_GPIO_Port GPIOG

// #define SPI1_CS5_Pin       GPIO_PIN_5
// #define SPI1_CS5_GPIO_Port GPIOH

#define DRV_USE_SPI2
#define SPI2_CS1_Pin       GPIO_PIN_4
#define SPI2_CS1_GPIO_Port GPIOD

// #define DRV_USE_SPI4
// #define SPI4_CS1_Pin       GPIO_PIN_13
// #define SPI4_CS1_GPIO_Port GPIOC

// #define SPI4_CS2_Pin       GPIO_PIN_4
// #define SPI4_CS2_GPIO_Port GPIOE

struct stm32_spi_bus {
    struct rt_spi_bus parent;
    SPI_HandleTypeDef* hspi; // Use HAL handle
#ifdef SPI_USE_DMA
    DMA_HandleTypeDef* hdma_tx;
    DMA_HandleTypeDef* hdma_rx;
#endif /* #ifdef SPI_USE_DMA */
};

struct stm32_spi_cs {
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
};

// Helper function to convert HAL SPI handle to clock frequency
static uint32_t get_spi_clock_freq(SPI_HandleTypeDef* hspi)
{
    if (hspi->Instance == SPI1 || hspi->Instance == SPI2 || hspi->Instance == SPI3) {
        return HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI123);
    } else if (hspi->Instance == SPI4 || hspi->Instance == SPI5) {
        return HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI45);
    }
    return 0;
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
    RT_ASSERT(device != RT_NULL);
    RT_ASSERT(device->bus != RT_NULL);

    struct stm32_spi_bus* stm32_spi_bus = (struct stm32_spi_bus*)device->bus;
    RT_ASSERT(stm32_spi_bus != RT_NULL);
    RT_ASSERT(stm32_spi_bus->hspi != RT_NULL);

    SPI_HandleTypeDef* hspi = stm32_spi_bus->hspi;

    // Configure data width
    if (configuration->data_width <= 8) {
        hspi->Init.DataSize = SPI_DATASIZE_8BIT;
    } else if (configuration->data_width <= 16) {
        hspi->Init.DataSize = SPI_DATASIZE_16BIT;
    } else {
        return RT_EIO;
    }

    /* baudrate */
    {
        uint32_t spi_clock = get_spi_clock_freq(hspi);
        uint32_t max_hz = configuration->max_hz;

        if (max_hz > spi_clock) {
            max_hz = spi_clock;
        }

        if (max_hz >= spi_clock / 2) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
        } else if (max_hz >= spi_clock / 4) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
        } else if (max_hz >= spi_clock / 8) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
        } else if (max_hz >= spi_clock / 16) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
        } else if (max_hz >= spi_clock / 32) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
        } else if (max_hz >= spi_clock / 64) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
        } else if (max_hz >= spi_clock / 128) {
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
        } else {
            /*  min prescaler 256 */
            hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
        }
    } /* baudrate */

    /* CPOL */
    if (configuration->mode & RT_SPI_CPOL) {
        hspi->Init.CLKPolarity = SPI_POLARITY_HIGH;
    } else {
        hspi->Init.CLKPolarity = SPI_POLARITY_LOW;
    }

    /* CPHA */
    if (configuration->mode & RT_SPI_CPHA) {
        hspi->Init.CLKPhase = SPI_PHASE_2EDGE;
    } else {
        hspi->Init.CLKPhase = SPI_PHASE_1EDGE;
    }

    /* MSB or LSB */
    if (configuration->mode & RT_SPI_MSB) {
        hspi->Init.FirstBit = SPI_FIRSTBIT_MSB;
    } else {
        hspi->Init.FirstBit = SPI_FIRSTBIT_LSB;
    }

    hspi->Init.Direction = SPI_DIRECTION_2LINES;
    hspi->Init.Mode = SPI_MODE_MASTER;
    hspi->Init.NSS = SPI_NSS_SOFT;
    hspi->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi->Init.CRCPolynomial = 0x0;
    hspi->Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
    hspi->Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
    hspi->Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
    hspi->Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi->Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi->Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
    hspi->Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
    hspi->Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
    hspi->Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
    hspi->Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
    hspi->Init.IOSwap = SPI_IO_SWAP_DISABLE;
    hspi->Init.TIMode = SPI_TIMODE_DISABLE;

    // Only initialize if not already initialized
    // This avoids repeated DeInit/Init cycles that can cause issues
    if (hspi->State == HAL_SPI_STATE_RESET) {
        if (HAL_SPI_Init(hspi) != HAL_OK) {
            return RT_ERROR;
        }
    }

    return RT_EOK;
}

/**
 * @brief Perform a short dummy transfer to wake/synchronize an SPI device.
 *
 * This will open the named device, send a single read command for the
 * provided register and read back one byte. It's intended for devices
 * that need a wake/dummy transfer (e.g. WHO_AM_I) before their driver
 * probe sequence.
 */
rt_err_t drv_spi_warmup_device(const char* dev_name, uint8_t reg)
{
    rt_device_t dev = rt_device_find(dev_name);
    if (dev == RT_NULL) {
        return -RT_ERROR;
    }

    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return -RT_ERROR;
    }

    struct rt_spi_device* spi_dev = (struct rt_spi_device*)dev;
    uint8_t cmd = 0x80 | reg; /* DIR_READ | reg */
    uint8_t resp = 0;

    rt_err_t rr = rt_spi_send_then_recv(spi_dev, &cmd, 1, &resp, 1);

    rt_device_close(dev);

    return rr;
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
    SPI_HandleTypeDef* hspi = stm32_spi_bus->hspi;
    struct stm32_spi_cs* stm32_spi_cs = device->parent.user_data;
    rt_uint32_t size = message->length;

    /* take CS */
    if (message->cs_take) {
        HAL_GPIO_WritePin(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin, GPIO_PIN_RESET);
    }

#ifdef SPI_USE_DMA
    if (message->send_buf && message->recv_buf) {
        HAL_SPI_TransmitReceive_DMA(hspi, (uint8_t*)message->send_buf, (uint8_t*)message->recv_buf, size);
    } else if (message->send_buf) {
        HAL_SPI_Transmit_DMA(hspi, (uint8_t*)message->send_buf, size);
    } else if (message->recv_buf) {
        HAL_SPI_Receive_DMA(hspi, (uint8_t*)message->recv_buf, size);
    }
    // Wait for DMA to complete
    while (HAL_SPI_GetState(hspi) != HAL_SPI_STATE_READY)
        ;
#else
    // Use blocking mode
    if (message->send_buf && message->recv_buf) {
        HAL_SPI_TransmitReceive(hspi, (uint8_t*)message->send_buf, (uint8_t*)message->recv_buf, size, HAL_MAX_DELAY);
    } else if (message->send_buf) {
        HAL_SPI_Transmit(hspi, (uint8_t*)message->send_buf, size, HAL_MAX_DELAY);
    } else if (message->recv_buf) {
        HAL_SPI_Receive(hspi, (uint8_t*)message->recv_buf, size, HAL_MAX_DELAY);
    }
#endif

    /* release CS */
    if (message->cs_release) {
        HAL_GPIO_WritePin(stm32_spi_cs->GPIOx, stm32_spi_cs->GPIO_Pin, GPIO_PIN_SET);
    }

    return message->length;
}

static struct rt_spi_ops stm32_spi_ops = { configure, transfer };

/** \brief init and register stm32 spi bus.
 *
 * \param hspi: HAL SPI Handle
 * \param stm32_spi: stm32 spi bus struct.
 * \param spi_bus_name: spi bus name, e.g: "spi1"
 * \return rt_err_t RT_EOK for success
 */
static rt_err_t stm32_spi_register(SPI_HandleTypeDef* hspi, struct stm32_spi_bus* stm32_spi, const char* spi_bus_name)
{
    stm32_spi->hspi = hspi;

    // Initialize the SPI using HAL - MSP init will be called automatically
    if (HAL_SPI_Init(hspi) != HAL_OK) {
        return RT_ERROR;
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
    rt_err_t ret;
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* register SPI bus */
#ifdef DRV_USE_SPI1
    static struct stm32_spi_bus stm32_spi1;
#endif
#ifdef DRV_USE_SPI2
    static struct stm32_spi_bus stm32_spi2;
#endif
#ifdef DRV_USE_SPI4
    static struct stm32_spi_bus stm32_spi4;
#endif

#ifdef DRV_USE_SPI1
    /* Configure SPI1 */
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
    hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 0x0;
    hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
    hspi1.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
    hspi1.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
    hspi1.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi1.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi1.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
    hspi1.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
    hspi1.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
    hspi1.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
    hspi1.Init.IOSwap = SPI_IO_SWAP_DISABLE;

    /* register SPI1 bus */
    ret = stm32_spi_register(&hspi1, &stm32_spi1, "spi1");
    if (ret != RT_EOK) {
        return ret;
    }

    #ifdef SPI1_CS1_Pin
    /* attach spi_device_1 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct stm32_spi_cs stm32_spi_cs_1;

        stm32_spi_cs_1.GPIOx = SPI1_CS1_GPIO_Port;
        stm32_spi_cs_1.GPIO_Pin = SPI1_CS1_Pin;

        __HAL_RCC_GPIOC_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI1_CS1_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI1_CS1_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI1_CS1_GPIO_Port, SPI1_CS1_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi1_dev1", "spi1", (void*)&stm32_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
    #ifdef SPI1_CS2_Pin

    /* attach spi_device_2 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_2;
        static struct stm32_spi_cs stm32_spi_cs_2;

        stm32_spi_cs_2.GPIOx = SPI1_CS2_GPIO_Port;
        stm32_spi_cs_2.GPIO_Pin = SPI1_CS2_Pin;

        __HAL_RCC_GPIOC_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI1_CS2_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI1_CS2_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI1_CS2_GPIO_Port, SPI1_CS2_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_2, "spi1_dev2", "spi1", (void*)&stm32_spi_cs_2);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
    #ifdef SPI1_CS3_Pin
    /* attach spi_device_3 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_3;
        static struct stm32_spi_cs stm32_spi_cs_3;

        stm32_spi_cs_3.GPIOx = SPI1_CS3_GPIO_Port;
        stm32_spi_cs_3.GPIO_Pin = SPI1_CS3_Pin;

        __HAL_RCC_GPIOC_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI1_CS3_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI1_CS3_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI1_CS3_GPIO_Port, SPI1_CS3_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_3, "spi1_dev3", "spi1", (void*)&stm32_spi_cs_3);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
    #ifdef SPI1_CS4_Pin
    /* attach spi_device_4 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_4;
        static struct stm32_spi_cs stm32_spi_cs_4;

        stm32_spi_cs_4.GPIOx = SPI1_CS4_GPIO_Port;
        stm32_spi_cs_4.GPIO_Pin = SPI1_CS4_Pin;

        __HAL_RCC_GPIOG_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI1_CS4_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI1_CS4_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI1_CS4_GPIO_Port, SPI1_CS4_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_4, "spi1_dev4", "spi1", (void*)&stm32_spi_cs_4);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
    #ifdef SPI1_CS5_Pin
    /* attach spi_device_5 to spi1 */
    {
        static struct rt_spi_device rt_spi_device_5;
        static struct stm32_spi_cs stm32_spi_cs_5;

        stm32_spi_cs_5.GPIOx = SPI1_CS5_GPIO_Port;
        stm32_spi_cs_5.GPIO_Pin = SPI1_CS5_Pin;

        __HAL_RCC_GPIOH_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI1_CS5_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI1_CS5_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI1_CS5_GPIO_Port, SPI1_CS5_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_5, "spi1_dev5", "spi1", (void*)&stm32_spi_cs_5);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
#endif

#ifdef DRV_USE_SPI2
    /* Configure SPI2 - Mode 0 (CPOL=0, CPHA=0) */
    hspi2.Instance = SPI2;
    hspi2.Init.Mode = SPI_MODE_MASTER;
    hspi2.Init.Direction = SPI_DIRECTION_2LINES;
    hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi2.Init.CLKPolarity = SPI_POLARITY_LOW; /* CPOL = 0 */
    hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;     /* CPHA = 0 */
    hspi2.Init.NSS = SPI_NSS_SOFT;
    hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
    hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi2.Init.CRCPolynomial = 0x0;
    hspi2.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
    hspi2.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
    hspi2.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
    hspi2.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi2.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi2.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
    hspi2.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
    hspi2.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
    hspi2.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
    hspi2.Init.IOSwap = SPI_IO_SWAP_DISABLE;

    /* register SPI2 bus */
    ret = stm32_spi_register(&hspi2, &stm32_spi2, "spi2");
    if (ret != RT_EOK) {
        return ret;
    }

    #ifdef SPI2_CS1_Pin
    /* attach spi_device_1 to spi2 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct stm32_spi_cs stm32_spi_cs_1;

        stm32_spi_cs_1.GPIOx = SPI2_CS1_GPIO_Port;
        stm32_spi_cs_1.GPIO_Pin = SPI2_CS1_Pin;

        __HAL_RCC_GPIOD_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI2_CS1_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI2_CS1_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI2_CS1_GPIO_Port, SPI2_CS1_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi2_dev1", "spi2", (void*)&stm32_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
#endif

#ifdef DRV_USE_SPI4

    /* SPI4 configure */
    hspi4.Instance = SPI4;
    hspi4.Init.Mode = SPI_MODE_MASTER;
    hspi4.Init.Direction = SPI_DIRECTION_2LINES;
    hspi4.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi4.Init.CLKPolarity = SPI_POLARITY_HIGH;
    hspi4.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi4.Init.NSS = SPI_NSS_SOFT;
    hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
    hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi4.Init.CRCPolynomial = 0x0;
    hspi4.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
    hspi4.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
    hspi4.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
    hspi4.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi4.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
    hspi4.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
    hspi4.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
    hspi4.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
    hspi4.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
    hspi4.Init.IOSwap = SPI_IO_SWAP_DISABLE;

    /* register SPI4 bus */
    ret = stm32_spi_register(&hspi4, &stm32_spi4, "spi4");
    if (ret != RT_EOK) {
        return ret;
    }
    #ifdef SPI4_CS1_Pin

    /* attach spi_device_1 to spi4 */
    {
        static struct rt_spi_device rt_spi_device_1;
        static struct stm32_spi_cs stm32_spi_cs_1;

        stm32_spi_cs_1.GPIOx = SPI4_CS1_GPIO_Port;
        stm32_spi_cs_1.GPIO_Pin = SPI4_CS1_Pin;

        __HAL_RCC_GPIOC_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI4_CS1_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI4_CS1_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI4_CS1_GPIO_Port, SPI4_CS1_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_1, "spi4_dev1", "spi4", (void*)&stm32_spi_cs_1);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
    #ifdef SPI4_CS2_Pin
    /* attach spi_device_2 to spi4 */
    {
        static struct rt_spi_device rt_spi_device_2;
        static struct stm32_spi_cs stm32_spi_cs_2;

        stm32_spi_cs_2.GPIOx = SPI4_CS2_GPIO_Port;
        stm32_spi_cs_2.GPIO_Pin = SPI4_CS2_Pin;

        __HAL_RCC_GPIOE_CLK_ENABLE();

        GPIO_InitStruct.Pin = SPI4_CS2_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(SPI4_CS2_GPIO_Port, &GPIO_InitStruct);

        HAL_GPIO_WritePin(SPI4_CS2_GPIO_Port, SPI4_CS2_Pin, GPIO_PIN_SET);

        ret = rt_spi_bus_attach_device(&rt_spi_device_2, "spi4_dev2", "spi4", (void*)&stm32_spi_cs_2);
        if (ret != RT_EOK) {
            return ret;
        }
    }
    #endif
#endif

    return RT_EOK;
}
