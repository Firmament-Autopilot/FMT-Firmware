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
    #if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        #include "core_cm7.h"
    #endif

    #define SD_TIMEOUT    5000
    #define SD_BLOCK_SIZE 512U
    #define EVENT_TX_CPLT 0x00000001
    #define EVENT_RX_CPLT 0x00000002
    #define EVENT_ERROR   0x00000004
    #define EVENT_ABORT   0x00000008

    #if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) && defined(__SCB_DCACHE_LINE_SIZE)
        #define SD_DMA_CACHE_ALIGNMENT __SCB_DCACHE_LINE_SIZE
    #else
        #define SD_DMA_CACHE_ALIGNMENT 32U
    #endif

/* SDMMC2 */
extern SD_HandleTypeDef hsd2;

static struct sd_device sd0_dev;

/* Cache maintenance with runtime D-Cache check. */
static inline int sd_is_dcache_enabled(void)
{
    #if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    return ((SCB->CCR & SCB_CCR_DC_Msk) != 0U);
    #else
    return 0;
    #endif
}

static void sd_dma_clean_buffer(const void* buffer, rt_size_t size)
{
    if (buffer == RT_NULL || size == 0) {
        return;
    }

    if (sd_is_dcache_enabled()) {
        SCB_CleanDCache_by_Addr((uint32_t*)buffer, (int32_t)size);
    }
}

static void sd_dma_invalidate_buffer(void* buffer, rt_size_t size)
{
    if (buffer == RT_NULL || size == 0) {
        return;
    }

    if (sd_is_dcache_enabled()) {
        SCB_InvalidateDCache_by_Addr(buffer, (int32_t)size);
    }
}

/*
 * Ensure DMA buffer is located in DMA-capable RAM.
 * H7 memory map (used here): SRAMD1: 0x24000000 (512KB), SRAMD2: 0x30000000 (256KB),
 * SRAMD3: 0x38000000 (64KB). We treat 0x24000000 and 0x30000000 as DMA-capable.
 */
static inline int sd_addr_is_dma_capable(uint8_t* addr, rt_size_t size)
{
    if (addr == RT_NULL || size == 0) {
        return 0;
    }

    uintptr_t a = (uintptr_t)addr;
    uintptr_t s = (uintptr_t)size;

    /* SRAMD1: 0x24000000 - 0x24080000 (512KB) */
    if ((a >= 0x24000000UL) && (s <= (0x24080000UL - a))) {
        return 1;
    }

    /* SRAMD2: 0x30000000 - 0x30040000 (256KB) */
    if ((a >= 0x30000000UL) && (s <= (0x30040000UL - a))) {
        return 1;
    }

    /* SRAMD3: 0x38000000 - 0x38010000 (64KB) */
    if ((a >= 0x38000000UL) && (s <= (0x38010000UL - a))) {
        return 1;
    }

    return 0;
}

    /* Static DMA pool placed to a linker section we expect to be in SRAMD1.
     * Size can be tuned; keep conservative default. */
    #ifndef SD_DMA_POOL_SIZE
        #define SD_DMA_POOL_SIZE (64 * 1024)
    #endif
static uint8_t sd_dma_static_pool[SD_DMA_POOL_SIZE] __attribute__((section(".sram_dma"), aligned(32)));
static rt_size_t sd_dma_static_pool_used = 0;

static rt_bool_t sd_dma_pool_inuse = RT_FALSE;

static rt_uint8_t* sd_dma_alloc_buffer(rt_size_t size, rt_size_t* aligned_size)
{
    rt_size_t dma_size;
    rt_uint8_t* buffer;

    dma_size = (size + SD_DMA_CACHE_ALIGNMENT - 1U) & ~(SD_DMA_CACHE_ALIGNMENT - 1U);

    /* Try normal aligned malloc first */
    buffer = rt_malloc_align(dma_size, SD_DMA_CACHE_ALIGNMENT);
    if (buffer != RT_NULL) {
        if (sd_addr_is_dma_capable(buffer, dma_size)) {
            if (aligned_size != RT_NULL) {
                *aligned_size = dma_size;
            }
            return buffer;
        }

        /* not DMA-capable memory, free and fall through */
        rt_free_align(buffer);
        buffer = RT_NULL;
    }

    /* Fallback: use static DMA pool if size fits and pool is free */
    if (dma_size <= SD_DMA_POOL_SIZE) {
        rt_base_t level = rt_hw_interrupt_disable();
        if (sd_dma_pool_inuse == RT_FALSE) {
            sd_dma_pool_inuse = RT_TRUE;
            sd_dma_static_pool_used = dma_size;
            rt_hw_interrupt_enable(level);
            if (aligned_size != RT_NULL) {
                *aligned_size = dma_size;
            }
            return sd_dma_static_pool;
        }
        rt_hw_interrupt_enable(level);
    }

    /* allocation failed */
    return RT_NULL;
}

static void sd_dma_free_buffer(rt_uint8_t* buffer)
{
    if (buffer == RT_NULL) {
        return;
    }

    if (buffer == sd_dma_static_pool) {
        rt_base_t level = rt_hw_interrupt_disable();
        sd_dma_pool_inuse = RT_FALSE;
        sd_dma_static_pool_used = 0;
        rt_hw_interrupt_enable(level);
        return;
    }

    rt_free_align(buffer);
}

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

/* HAL_SD_MspInit and HAL_SD_MspDeInit are defined in stm32h7xx_hal_msp.c */

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
    // hsd2.Init.TranceiverPresent = SDMMC_TRANSCEIVER_NOT_PRESENT;
    if (HAL_SD_Init(&hsd2) != HAL_OK) {
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t write_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;
    rt_uint32_t status;
    rt_uint8_t* dma_buffer;
    rt_size_t data_size;
    rt_size_t dma_size;
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    data_size = count * SD_BLOCK_SIZE;
    dma_buffer = sd_dma_alloc_buffer(data_size, &dma_size);
    if (dma_buffer == RT_NULL) {
        return RT_ENOMEM;
    }

    rt_memcpy(dma_buffer, buffer, data_size);
    sd_dma_clean_buffer(dma_buffer, dma_size);

    if (HAL_SD_WriteBlocks_DMA(sd_handle, dma_buffer, sector, count) != HAL_OK) {
        sd_dma_free_buffer(dma_buffer);
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

    sd_dma_free_buffer(dma_buffer);

    return err;
}

static rt_err_t read_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;
    rt_uint32_t status;
    rt_uint8_t* dma_buffer;
    rt_size_t data_size;
    rt_size_t dma_size;
    SD_HandleTypeDef* sd_handle = sd->parent.user_data;

    RT_ASSERT(sd_handle != RT_NULL);

    data_size = count * SD_BLOCK_SIZE;
    dma_buffer = sd_dma_alloc_buffer(data_size, &dma_size);
    if (dma_buffer == RT_NULL) {
        return RT_ENOMEM;
    }

    sd_dma_invalidate_buffer(dma_buffer, dma_size);

    if (HAL_SD_ReadBlocks_DMA(sd_handle, dma_buffer, sector, count) != HAL_OK) {
        sd_dma_free_buffer(dma_buffer);
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

        if (err == RT_EOK) {
            sd_dma_invalidate_buffer(dma_buffer, dma_size);
            rt_memcpy(buffer, dma_buffer, data_size);
        }
    }

    sd_dma_free_buffer(dma_buffer);

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

    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &hsd2);

#endif
    return RT_ERROR;
}
