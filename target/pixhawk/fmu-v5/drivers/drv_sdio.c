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

#include "drv_sdio.h"
#include "board.h"
#include "hal/sd/sd.h"
#include "stm32f7xx_ll_sdmmc.h"


#define SD_TIMEOUT    5000
#define EVENT_TX_CPLT 0x00000001
#define EVENT_RX_CPLT 0x00000002
#define EVENT_ERROR   0x00000004
#define EVENT_ABORT   0x00000008

/* SDMMC1 */
static SD_HandleTypeDef hsd1;
static DMA_HandleTypeDef hdma_sdmmc1_rx;
static DMA_HandleTypeDef hdma_sdmmc1_tx;
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
void SDMMC1_IRQHandler(void)
{
    HAL_SD_IRQHandler(&hsd1);
}

/**
 * @brief This function handles DMA2 stream3 global interrupt.
 */
void DMA2_Stream3_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_sdmmc1_tx);
}

/**
 * @brief This function handles DMA2 stream6 global interrupt.
 */
void DMA2_Stream6_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_sdmmc1_rx);
}

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
        /* SDMMC1 GPIO Configuration
            PC12     ------> SDMMC1_CK
            PC11     ------> SDMMC1_D3
            PC10     ------> SDMMC1_D2
            PD2     ------> SDMMC1_CMD
            PC9     ------> SDMMC1_D1
            PC8     ------> SDMMC1_D0
            */
        GPIO_InitStruct.Pin = GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDMMC1;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDMMC1;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF12_SDMMC1;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /* SDMMC1 DMA Init */
        /* SDMMC1_TX Init */
        hdma_sdmmc1_tx.Instance = DMA2_Stream3;
        hdma_sdmmc1_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_sdmmc1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_sdmmc1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_sdmmc1_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_sdmmc1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
        hdma_sdmmc1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
        hdma_sdmmc1_tx.Init.Mode = DMA_PFCTRL;
        hdma_sdmmc1_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_sdmmc1_tx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
        hdma_sdmmc1_tx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
        hdma_sdmmc1_tx.Init.MemBurst = DMA_MBURST_INC4;
        hdma_sdmmc1_tx.Init.PeriphBurst = DMA_PBURST_INC4;
        if (HAL_DMA_Init(&hdma_sdmmc1_tx) != HAL_OK) {
            Error_Handler();
        }

        __HAL_LINKDMA(sdHandle, hdmatx, hdma_sdmmc1_tx);

        /* SDMMC1_RX Init */
        hdma_sdmmc1_rx.Instance = DMA2_Stream6;
        hdma_sdmmc1_rx.Init.Channel = DMA_CHANNEL_4;
        hdma_sdmmc1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_sdmmc1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_sdmmc1_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_sdmmc1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
        hdma_sdmmc1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
        hdma_sdmmc1_rx.Init.Mode = DMA_PFCTRL;
        hdma_sdmmc1_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_sdmmc1_rx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
        hdma_sdmmc1_rx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
        hdma_sdmmc1_rx.Init.MemBurst = DMA_MBURST_INC4;
        hdma_sdmmc1_rx.Init.PeriphBurst = DMA_PBURST_INC4;
        if (HAL_DMA_Init(&hdma_sdmmc1_rx) != HAL_OK) {
            Error_Handler();
        }

        __HAL_LINKDMA(sdHandle, hdmarx, hdma_sdmmc1_rx);

        /* SDMMC1 interrupt Init */
        HAL_NVIC_SetPriority(SDMMC1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(SDMMC1_IRQn);
    }
}

void HAL_SD_MspDeInit(SD_HandleTypeDef* sdHandle)
{
    if (sdHandle->Instance == SDMMC1) {
        /* Peripheral clock disable */
        __HAL_RCC_SDMMC1_CLK_DISABLE();

        /* SDMMC1 GPIO Configuration
            PC12     ------> SDMMC1_CK
            PC11     ------> SDMMC1_D3
            PC10     ------> SDMMC1_D2
            PD2     ------> SDMMC1_CMD
            PC9     ------> SDMMC1_D1
            PC8     ------> SDMMC1_D0
            */
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_12 | GPIO_PIN_11 | GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8);

        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);

        /* SDMMC1 DMA DeInit */
        HAL_DMA_DeInit(sdHandle->hdmatx);
        HAL_DMA_DeInit(sdHandle->hdmarx);

        /* SDMMC1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(SDMMC1_IRQn);
    }
}

static rt_err_t sdio_wait_complete(sd_dev_t sd_dev, rt_uint32_t* status)
{
    if (rt_event_recv(&sd_dev->event, 0xffffffff, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, TICKS_FROM_MS(SD_TIMEOUT), status)
        != RT_EOK) {
        /* wait timeout */
        return RT_ETIMEOUT;
    }

    return RT_EOK;
}

static rt_err_t init(sd_dev_t sd)
{
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    /* DMA controller clock enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);
    /* DMA2_Stream3_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
    /* DMA2_Stream6_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

    sd_handle->Instance = SDMMC1;
    sd_handle->Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
    sd_handle->Init.ClockBypass = SDMMC_CLOCK_BYPASS_DISABLE;
    sd_handle->Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
    sd_handle->Init.BusWide = SDMMC_BUS_WIDE_1B;
    sd_handle->Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
    sd_handle->Init.ClockDiv = 0;
    if (HAL_SD_Init(sd_handle) != HAL_OK) {
        return RT_ERROR;
    }
    if (HAL_SD_ConfigWideBusOperation(sd_handle, SDMMC_BUS_WIDE_4B) != HAL_OK) {
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

    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &hsd1);
}
