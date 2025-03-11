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

#include "board.h"
#include "drv_sdio.h"
#include "hal/sd/sd.h"
#include "stm32h7xx_ll_sdmmc.h"

#define SD_TIMEOUT    5000
#define EVENT_TX_CPLT 0x00000001
#define EVENT_RX_CPLT 0x00000002
#define EVENT_ERROR   0x00000004
#define EVENT_ABORT   0x00000008

/* SDMMC2 */
static SD_HandleTypeDef hsd2;

static struct sd_device sd0_dev;

void HAL_SD_TxCpltCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd2) {
        rt_event_send(&sd0_dev.event, EVENT_TX_CPLT);
    }
}

void HAL_SD_RxCpltCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd2) {
        rt_event_send(&sd0_dev.event, EVENT_RX_CPLT);
    }
}

void HAL_SD_ErrorCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd2) {
        rt_event_send(&sd0_dev.event, EVENT_ERROR);
    }
}

void HAL_SD_AbortCallback(SD_HandleTypeDef* hsd)
{
    if (hsd == &hsd2) {
        rt_event_send(&sd0_dev.event, EVENT_ABORT);
    }
}

/**
 * @brief This function handles SDMMC2 global interrupt.
 */
void SDMMC2_IRQHandler(void)
{
    rt_interrupt_enter();

    HAL_SD_IRQHandler(&hsd2);

    rt_interrupt_leave();
}

void HAL_SD_MspInit(SD_HandleTypeDef* sdHandle)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (sdHandle->Instance == SDMMC2) {
        /* USER CODE BEGIN SDMMC2_MspInit 0 */

        /* USER CODE END SDMMC2_MspInit 0 */
        LL_RCC_SetSDMMCClockSource(LL_RCC_SDMMC_CLKSOURCE_PLL1Q);

        /* Peripheral clock enable */
        __HAL_RCC_SDMMC2_CLK_ENABLE();

        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();
        __HAL_RCC_GPIOG_CLK_ENABLE();
        /**SDMMC2 GPIO Configuration
        PB4 (NJTRST)     ------> SDMMC2_D3
        PD7     ------> SDMMC2_CMD
        PG11     ------> SDMMC2_D2
        PD6     ------> SDMMC2_CK
        PB14     ------> SDMMC2_D0
        PB15     ------> SDMMC2_D1
        */
        GPIO_InitStruct.Pin = GPIO_PIN_4 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_SDIO2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_6;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF11_SDIO2;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_11;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF10_SDIO2;
        HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        /* SDMMC2 interrupt Init */
        HAL_NVIC_SetPriority(SDMMC2_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(SDMMC2_IRQn);
    }
}

void HAL_SD_MspDeInit(SD_HandleTypeDef* sdHandle)
{
    if (sdHandle->Instance == SDMMC2) {
        __HAL_RCC_SDMMC2_CLK_DISABLE();

        /**SDMMC2 GPIO Configuration
        PB4 (NJTRST)     ------> SDMMC2_D3
        PD7     ------> SDMMC2_CMD
        PG11     ------> SDMMC2_D2
        PD6     ------> SDMMC2_CK
        PB14     ------> SDMMC2_D0
        PB15     ------> SDMMC2_D1
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4 | GPIO_PIN_14 | GPIO_PIN_15);

        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_7 | GPIO_PIN_6);

        HAL_GPIO_DeInit(GPIOG, GPIO_PIN_11);

        /* SDMMC2 interrupt DeInit */
        HAL_NVIC_DisableIRQ(SDMMC2_IRQn);
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

    hsd2.Instance = SDMMC2;
    hsd2.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
    hsd2.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
    hsd2.Init.BusWide = SDMMC_BUS_WIDE_4B;
    hsd2.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
    hsd2.Init.ClockDiv = 0;
    if (HAL_SD_Init(&hsd2) != HAL_OK) {
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

rt_err_t drv_sdio_init(void)
{
    sd0_dev.ops = &dev_ops;

    if (rt_event_init(&sd0_dev.event, "sdio", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("fail to init sdio event\n");
        return RT_ERROR;
    }

    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &hsd2);
}
