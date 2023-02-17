/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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
#include <firmament.h>

#define SDIO_ENABLE 1

#if SDIO_ENABLE == 1

    #include "board.h"
    #include "drv_sdio.h"
    #include "hal/sd/sd.h"
    #include "stm32h7xx_ll_sdmmc.h"

    #define SD_TIMEOUT    5000
    #define EVENT_TX_CPLT 0x00000001
    #define EVENT_RX_CPLT 0x00000002
    #define EVENT_ERROR   0x00000004
    #define EVENT_ABORT   0x00000008

/* SDMMC1 */
static SD_HandleTypeDef hsd1;

static struct sd_device sd0_dev;

void HAL_SD_TxCpltCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd1) {
        rt_event_send(&sd0_dev.event, EVENT_TX_CPLT);
    }
}

void HAL_SD_RxCpltCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd1) {
        rt_event_send(&sd0_dev.event, EVENT_RX_CPLT);
    }
}

void HAL_SD_ErrorCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd1) {
        rt_event_send(&sd0_dev.event, EVENT_ERROR);
    }
}

void HAL_SD_AbortCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd1) {
        rt_event_send(&sd0_dev.event, EVENT_ABORT);
    }
}

/**
 * @brief This function handles SDMMC1 global interrupt.
 */
void SDMMC1_IRQHandler(void) { HAL_SD_IRQHandler(&hsd1); }

void HAL_SD_MspInit(SD_HandleTypeDef* sdHandle)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (sdHandle->Instance == SDMMC1) {
        /* USER CODE BEGIN SDMMC1_MspInit 0 */

        /* USER CODE END SDMMC1_MspInit 0 */
        /* SDMMC1 clock enable */
        __HAL_RCC_SDMMC1_CLK_ENABLE();

        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();
        /**SDMMC1 GPIO Configuration
        PC8     ------> SDMMC1_D0
        PC9     ------> SDMMC1_D1
        PC10    ------> SDMMC1_D2
        PC11    ------> SDMMC1_D3
        PC12    ------> SDMMC1_CK
        PD2     ------> SDMMC1_CMD
        */
        GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11
            | GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDIO1;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDIO1;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /* SDMMC1 interrupt Init */
        HAL_NVIC_SetPriority(SDMMC1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(SDMMC1_IRQn);
        /* USER CODE BEGIN SDMMC1_MspInit 1 */

        /* USER CODE END SDMMC1_MspInit 1 */
    }
}

void HAL_SD_MspDeInit(SD_HandleTypeDef* sdHandle)
{
    if (sdHandle->Instance == SDMMC1) {
        /* USER CODE BEGIN SDMMC1_MspDeInit 0 */

        /* USER CODE END SDMMC1_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_SDMMC1_CLK_DISABLE();

        /**SDMMC1 GPIO Configuration
    PC8     ------> SDMMC1_D0
    PC9     ------> SDMMC1_D1
    PC10     ------> SDMMC1_D2
    PC11     ------> SDMMC1_D3
    PC12     ------> SDMMC1_CK
    PD2     ------> SDMMC1_CMD
    */
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12);

        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);

        /* SDMMC1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(SDMMC1_IRQn);
        /* USER CODE BEGIN SDMMC1_MspDeInit 1 */

        /* USER CODE END SDMMC1_MspDeInit 1 */
    }
}

static rt_err_t sdio_wait_complete(sd_dev_t sd_dev, rt_uint32_t* status)
{
    if (rt_event_recv(&sd_dev->event, 0xffffffff, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, TICKS_FROM_MS(SD_TIMEOUT), status) != RT_EOK) {
        /* wait timeout */
        return RT_ETIMEOUT;
    }

    return RT_EOK;
}

static rt_err_t init(sd_dev_t sd)
{
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    hsd1.Instance = SDMMC1;
    hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
    hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
    hsd1.Init.BusWide = SDMMC_BUS_WIDE_4B;
    hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
    hsd1.Init.ClockDiv = 0;
    hsd1.Init.TranceiverPresent = SDMMC_TRANSCEIVER_NOT_PRESENT;
    if (HAL_SD_Init(&hsd1) != HAL_OK) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t write_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;
    rt_uint32_t status;
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    if (HAL_SD_WriteBlocks_DMA(sd_handle, buffer, sector, count) != HAL_OK) {
        return RT_ERROR;
    }

    err = sdio_wait_complete(sd, &status);
    if ((err == RT_EOK) && (status & EVENT_TX_CPLT)) {
        /* block until SDIO IP is ready or a timeout occur */
        uint32_t start = systime_now_ms();
        uint32_t now;
        while (HAL_SD_GetCardState(sd_handle) != HAL_SD_CARD_TRANSFER) {
            now = systime_now_ms();
            if (now - start > SD_TIMEOUT) {
                err = RT_ETIMEOUT;
                break;
            }
            sys_msleep(1);
        }
    }

    return err;
}

static rt_err_t read_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;
    rt_uint32_t status;
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    if (HAL_SD_ReadBlocks_DMA(sd_handle, buffer, sector, count) != HAL_OK) {
        return RT_ERROR;
    }

    err = sdio_wait_complete(sd, &status);
    if ((err == RT_EOK) && (status & EVENT_RX_CPLT)) {
        /* block until SDIO IP is ready or a timeout occur */
        uint32_t start = systime_now_ms();
        uint32_t now;
        while (HAL_SD_GetCardState(sd_handle) != HAL_SD_CARD_TRANSFER) {
            now = systime_now_ms();
            if (now - start > SD_TIMEOUT) {
                err = RT_ETIMEOUT;
                break;
            }
            sys_msleep(1);
        }
    }

    return err;
}

static rt_err_t io_control(sd_dev_t sd, int cmd, void* arg)
{
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    switch (cmd) {
    case RT_DEVICE_CTRL_BLK_GETGEOME: {
        struct rt_device_blk_geometry geometry;
        HAL_SD_CardInfoTypeDef pCardInfo;

        if (arg == RT_NULL) {
            return RT_EINVAL;
        }
        /* get sd card information */
        if (HAL_SD_GetCardInfo(sd_handle, &pCardInfo) != HAL_OK) {
            return RT_ERROR;
        }

        geometry.bytes_per_sector = pCardInfo.BlockSize;
        geometry.block_size = pCardInfo.BlockSize;
        geometry.sector_count = pCardInfo.BlockNbr;
        *(struct rt_device_blk_geometry*)arg = geometry;
    } break;
    case RT_DEVICE_CTRL_BLK_SYNC: {
        // TODO, improve it?
        if (HAL_SD_GetCardState(sd_handle) != HAL_SD_CARD_TRANSFER) {
            return RT_ERROR;
        }
    } break;
    case RT_DEVICE_CTRL_BLK_ERASE: {
        // uint32_t* tbl = (uint32_t*)arg;
        // HAL_SD_Erase(sd_handle, tbl[0], tbl[1]);

        /* sd card is not needed to erase */
        return RT_ERROR;
    } break;
    default: {
        console_printf("unknown sd control cmd:%d\n", cmd);
    } break;
    }

    return RT_EOK;
}

const static struct sd_ops dev_ops = {
    .sd_init = init,
    .sd_write = write_disk,
    .sd_read = read_disk,
    .sd_control = io_control
};

#endif
rt_err_t drv_sdio_init(void)
{
#if SDIO_ENABLE == 1
    sd0_dev.ops = &dev_ops;

    if (rt_event_init(&sd0_dev.event, "sdio", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("fail to init sdio event\n");
        return RT_ERROR;
    }

    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &hsd1);

#endif
    return RT_ERROR;
}
