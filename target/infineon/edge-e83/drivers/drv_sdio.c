/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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
#include "hal/sd/sd.h"
#include <firmament.h>

#include "cy_sd_host.h"
#include "mtb_hal_gpio.h"
#include "mtb_hal_sdhc.h"

#ifdef RT_USING_FINSH
    #include <finsh.h>
#endif

#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    #define CY_SDIO_DCACHE_CLEAN(addr, size) \
        SCB_CleanDCache_by_Addr((void*)(addr), (int32_t)(size))
    #define CY_SDIO_DCACHE_INVALIDATE(addr, size) \
        SCB_InvalidateDCache_by_Addr((void*)(addr), (int32_t)(size))
#else
    #define CY_SDIO_DCACHE_CLEAN(addr, size)      ((void)0)
    #define CY_SDIO_DCACHE_INVALIDATE(addr, size) ((void)0)
#endif

#define IFX_SD_EVENT_RX_DONE  (1U << 0)
#define IFX_SD_EVENT_TX_DONE  (1U << 1)
#define IFX_SD_EVENT_ERROR    (1U << 2)

#define IFX_SDHC_IRQ_PRIORITY (3U)
#define IFX_SD_SECTOR_SIZE    (512U)

#define CY_SDIO_BOUNCE_ALIGN  (32U)
#define CY_SDIO_ADMA_MAX_LEN  (64U * 1024U)
#define IFX_SD_LOCK_TIMEOUT_MS (2000U)
#define IFX_SD_XFER_TIMEOUT_MS (5000U)
#define IFX_SD_BUS_FREQ_HZ    (50U * 1000U * 1000U)

#define IFX_SD_ERROR_MASK (CY_SD_HOST_CMD_TOUT_ERR | CY_SD_HOST_CMD_CRC_ERR | \
                           CY_SD_HOST_CMD_END_BIT_ERR | CY_SD_HOST_CMD_IDX_ERR | \
                           CY_SD_HOST_DATA_TOUT_ERR | CY_SD_HOST_DATA_CRC_ERR | \
                           CY_SD_HOST_DATA_END_BIT_ERR | CY_SD_HOST_CUR_LMT_ERR | \
                           CY_SD_HOST_AUTO_CMD_ERR | CY_SD_HOST_ADMA_ERR | \
                           CY_SD_HOST_TUNING_ERR | CY_SD_HOST_RESP_ERR | \
                           CY_SD_HOST_BOOT_ACK_ERR)

struct ifx_sdio {
    mtb_hal_sdhc_t* sdhc_obj;

    rt_uint8_t* bounce_buf;
    rt_size_t bounce_size;
};

struct ifx_sd_stats {
    rt_uint32_t read_direct_ops;
    rt_uint32_t read_bounce_ops;
    rt_uint32_t write_direct_ops;
    rt_uint32_t write_bounce_ops;
    rt_uint32_t read_single_ops;
    rt_uint32_t read_multi_ops;
    rt_uint32_t write_single_ops;
    rt_uint32_t write_multi_ops;
    rt_uint32_t read_sectors;
    rt_uint32_t write_sectors;
    rt_uint32_t read_max_blocks;
    rt_uint32_t write_max_blocks;
};

static struct sd_device ifx_sd_dev;
static struct rt_mutex ifx_sd_lock;
static cy_stc_sd_host_context_t ifx_sd_ctx;
static mtb_hal_sdhc_t ifx_sdhc_obj;
static struct ifx_sdio ifx_sdio_ctx;
static struct ifx_sd_stats ifx_sd_stats;

static void ifx_sd_cache_range(const void* addr,
                               rt_size_t size,
                               uintptr_t* start,
                               rt_size_t* len)
{
#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    uintptr_t begin = (uintptr_t)addr;
    uintptr_t aligned = begin & ~((uintptr_t)CY_SDIO_BOUNCE_ALIGN - 1U);
    uintptr_t end = (begin + size + CY_SDIO_BOUNCE_ALIGN - 1U) & ~((uintptr_t)CY_SDIO_BOUNCE_ALIGN - 1U);

    *start = aligned;
    *len = (rt_size_t)(end - aligned);
#else
    CY_UNUSED_PARAMETER(addr);
    *start = 0U;
    *len = 0U;
#endif
}

static bool ifx_sd_is_cacheline_aligned(const void* buf)
{
    uintptr_t addr = (uintptr_t)buf;

    return ((addr & (CY_SDIO_BOUNCE_ALIGN - 1U)) == 0U);
}

static bool ifx_sd_can_dma_direct_read(const void* buf, rt_size_t size)
{
    return ifx_sd_is_cacheline_aligned(buf) && (size <= CY_SDIO_ADMA_MAX_LEN);
}

static bool ifx_sd_can_dma_direct_write(const void* buf, rt_size_t size)
{
    uintptr_t addr = (uintptr_t)buf;

    return ((addr & 0x3U) == 0U) && (size <= CY_SDIO_ADMA_MAX_LEN);
}

static void ifx_sd_update_stats(rt_uint32_t* single_ops,
                                rt_uint32_t* multi_ops,
                                rt_uint32_t* sectors,
                                rt_uint32_t* max_blocks,
                                rt_uint32_t count)
{
    *sectors += count;

    if (count > *max_blocks) {
        *max_blocks = count;
    }

    if (count > 1U) {
        (*multi_ops)++;
    } else {
        (*single_ops)++;
    }
}

static void ifx_sd_reset_stats(void)
{
    rt_memset(&ifx_sd_stats, 0, sizeof(ifx_sd_stats));
}

bool Cy_SD_Host_IsCardConnected(SDHC_Type const* base)
{
    CY_UNUSED_PARAMETER(base);
    return (Cy_GPIO_Read(CYBSP_SDHC_DETECT_PORT,
                         CYBSP_SDHC_DETECT_PIN)
            == 0);
}

void SDHC_IRQHandler(void)
{
    uint32_t normal, error;
    uint32_t handled_normal = 0;

    normal = Cy_SD_Host_GetNormalInterruptStatus(SDHC1);
    error = Cy_SD_Host_GetErrorInterruptStatus(SDHC1);

    if ((normal & CY_SD_HOST_ERR_INTERRUPT) || error) {
        Cy_SD_Host_ClearErrorInterruptStatus(SDHC1, error);
        rt_event_send(&ifx_sd_dev.event, IFX_SD_EVENT_ERROR);
        handled_normal |= CY_SD_HOST_ERR_INTERRUPT;
    }

    if (normal & CY_SD_HOST_XFER_COMPLETE) {
        rt_event_send(&ifx_sd_dev.event,
                      IFX_SD_EVENT_RX_DONE | IFX_SD_EVENT_TX_DONE);
        handled_normal |= CY_SD_HOST_XFER_COMPLETE;
    }

    if (normal & CY_SD_HOST_CARD_INSERTION) {
        handled_normal |= CY_SD_HOST_CARD_INSERTION;
    }

    if (normal & CY_SD_HOST_CARD_REMOVAL) {
        handled_normal |= CY_SD_HOST_CARD_REMOVAL;
    }

    if (handled_normal) {
        Cy_SD_Host_ClearNormalInterruptStatus(SDHC1, handled_normal);
    }
}

static rt_err_t ifx_sd_get_bounce(struct ifx_sdio* sdio,
                                  rt_size_t size,
                                  rt_uint8_t** buf)
{
    if (size > CY_SDIO_ADMA_MAX_LEN)
        return -RT_EINVAL;

    if (!sdio->bounce_buf || sdio->bounce_size < size) {
        if (sdio->bounce_buf)
            rt_free_align(sdio->bounce_buf);

        sdio->bounce_buf = rt_malloc_align(size, CY_SDIO_BOUNCE_ALIGN);
        if (!sdio->bounce_buf)
            return -RT_ENOMEM;

        sdio->bounce_size = size;
    }

    *buf = sdio->bounce_buf;
    return RT_EOK;
}

static void ifx_sd_recover(sd_dev_t dev,
                           const char* op,
                           cy_en_sd_host_status_t status)
{
    uint32_t normal = Cy_SD_Host_GetNormalInterruptStatus(SDHC1);
    uint32_t error = Cy_SD_Host_GetErrorInterruptStatus(SDHC1);

    if (normal) {
        Cy_SD_Host_ClearNormalInterruptStatus(SDHC1, normal);
    }

    if (error) {
        Cy_SD_Host_ClearErrorInterruptStatus(SDHC1, error);
    }

    (void)Cy_SD_Host_AbortTransfer(SDHC1, &ifx_sd_ctx);
    rt_event_control(&dev->event, RT_IPC_CMD_RESET, RT_NULL);

    rt_kprintf("SD recover on %s: status=%d normal=0x%04lx error=0x%04lx\n",
               op,
               status,
               normal,
               error);
}

static rt_err_t ifx_sd_read(sd_dev_t dev,
                            rt_uint8_t* buf,
                            rt_uint32_t sector,
                            rt_uint32_t count)
{
    struct ifx_sdio* sdio = dev->parent.user_data;
    cy_stc_sd_host_write_read_config_t cfg = { 0 };
    cy_en_sd_host_status_t sd_status;
    rt_size_t total;
    rt_uint8_t* dma_buf;
    uintptr_t cache_addr;
    rt_size_t cache_size;
    rt_uint32_t evt;
    rt_err_t err = RT_EOK;

    if (!buf || count == 0)
        return -RT_EINVAL;

    total = count * IFX_SD_SECTOR_SIZE;

    if (rt_mutex_take(&ifx_sd_lock, rt_tick_from_millisecond(IFX_SD_LOCK_TIMEOUT_MS)) != RT_EOK) {
        return -RT_ETIMEOUT;
    }

    if (ifx_sd_can_dma_direct_read(buf, total)) {
        dma_buf = buf;
        ifx_sd_stats.read_direct_ops++;
    } else {
        err = ifx_sd_get_bounce(sdio, total, &dma_buf);
        if (err != RT_EOK)
            goto exit;

        ifx_sd_stats.read_bounce_ops++;
    }

    ifx_sd_update_stats(&ifx_sd_stats.read_single_ops,
                        &ifx_sd_stats.read_multi_ops,
                        &ifx_sd_stats.read_sectors,
                        &ifx_sd_stats.read_max_blocks,
                        count);

    ifx_sd_cache_range(dma_buf, total, &cache_addr, &cache_size);
    CY_SDIO_DCACHE_INVALIDATE(cache_addr, cache_size);

    cfg.address = sector;
    cfg.numberOfBlocks = count;
    cfg.autoCommand = CY_SD_HOST_AUTO_CMD_AUTO;
    cfg.enableDma = true;
    cfg.data = (uint32_t*)dma_buf;
    cfg.dataTimeout = 12;

    rt_event_control(&dev->event, RT_IPC_CMD_RESET, RT_NULL);

    sd_status = Cy_SD_Host_Read(SDHC1, &cfg, &ifx_sd_ctx);
    if (sd_status != CY_SD_HOST_SUCCESS) {
        ifx_sd_recover(dev, "read-start", sd_status);
        err = -RT_ERROR;
        goto exit;
    }

    if (rt_event_recv(&dev->event,
                      IFX_SD_EVENT_RX_DONE | IFX_SD_EVENT_ERROR,
                      RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
                      rt_tick_from_millisecond(IFX_SD_XFER_TIMEOUT_MS),
                      &evt)
        != RT_EOK) {
        ifx_sd_recover(dev, "read-wait", CY_SD_HOST_ERROR_TIMEOUT);
        err = -RT_ETIMEOUT;
        goto exit;
    }

    if (evt & IFX_SD_EVENT_ERROR) {
        ifx_sd_recover(dev, "read-event", CY_SD_HOST_ERROR);
        err = -RT_ERROR;
        goto exit;
    }

    CY_SDIO_DCACHE_INVALIDATE(cache_addr, cache_size);
    if (dma_buf != buf) {
        rt_memcpy(buf, dma_buf, total);
    }

exit:
    rt_mutex_release(&ifx_sd_lock);
    return err;
}

static rt_err_t ifx_sd_write(sd_dev_t dev,
                             rt_uint8_t* buf,
                             rt_uint32_t sector,
                             rt_uint32_t count)
{
    struct ifx_sdio* sdio = dev->parent.user_data;
    cy_stc_sd_host_write_read_config_t cfg = { 0 };
    cy_en_sd_host_status_t sd_status;
    rt_size_t total;
    rt_uint8_t* dma_buf;
    uintptr_t cache_addr;
    rt_size_t cache_size;
    rt_uint32_t evt;
    rt_err_t err = RT_EOK;

    if (!buf || count == 0)
        return -RT_EINVAL;

    total = count * IFX_SD_SECTOR_SIZE;

    if (rt_mutex_take(&ifx_sd_lock, rt_tick_from_millisecond(IFX_SD_LOCK_TIMEOUT_MS)) != RT_EOK) {
        return -RT_ETIMEOUT;
    }

    if (ifx_sd_can_dma_direct_write(buf, total)) {
        dma_buf = buf;
        ifx_sd_stats.write_direct_ops++;
    } else {
        err = ifx_sd_get_bounce(sdio, total, &dma_buf);
        if (err != RT_EOK)
            goto exit;

        ifx_sd_stats.write_bounce_ops++;
        rt_memcpy(dma_buf, buf, total);
    }

    ifx_sd_update_stats(&ifx_sd_stats.write_single_ops,
                        &ifx_sd_stats.write_multi_ops,
                        &ifx_sd_stats.write_sectors,
                        &ifx_sd_stats.write_max_blocks,
                        count);

    ifx_sd_cache_range(dma_buf, total, &cache_addr, &cache_size);
    CY_SDIO_DCACHE_CLEAN(cache_addr, cache_size);

    cfg.address = sector;
    cfg.numberOfBlocks = count;
    cfg.autoCommand = CY_SD_HOST_AUTO_CMD_AUTO;
    cfg.enableDma = true;
    cfg.data = (uint32_t*)dma_buf;
    cfg.dataTimeout = 12;

    rt_event_control(&dev->event, RT_IPC_CMD_RESET, RT_NULL);

    sd_status = Cy_SD_Host_Write(SDHC1, &cfg, &ifx_sd_ctx);
    if (sd_status != CY_SD_HOST_SUCCESS) {
        ifx_sd_recover(dev, "write-start", sd_status);
        err = -RT_ERROR;
        goto exit;
    }

    if (rt_event_recv(&dev->event,
                      IFX_SD_EVENT_TX_DONE | IFX_SD_EVENT_ERROR,
                      RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
                      rt_tick_from_millisecond(IFX_SD_XFER_TIMEOUT_MS),
                      &evt)
        != RT_EOK) {
        ifx_sd_recover(dev, "write-wait", CY_SD_HOST_ERROR_TIMEOUT);
        err = -RT_ETIMEOUT;
        goto exit;
    }

    if (evt & IFX_SD_EVENT_ERROR) {
        ifx_sd_recover(dev, "write-event", CY_SD_HOST_ERROR);
        err = -RT_ERROR;
    }

exit:
    rt_mutex_release(&ifx_sd_lock);
    return err;
}

static rt_err_t ifx_sd_control(sd_dev_t dev, int cmd, void* arg)
{
    if (cmd == RT_DEVICE_CTRL_BLK_GETGEOME) {
        struct rt_device_blk_geometry* geo = arg;
        geo->bytes_per_sector = IFX_SD_SECTOR_SIZE;
        geo->block_size = IFX_SD_SECTOR_SIZE;
        geo->sector_count = ifx_sd_ctx.maxSectorNum;
        return RT_EOK;
    }
    return -RT_ENOSYS;
}

rt_err_t ifx_sd_hw_init(sd_dev_t dev)
{
    cy_en_sd_host_status_t status;
    cy_en_sysint_status_t sysint;
    uint32_t normal_int;

    Cy_SD_Host_Enable(CYBSP_SDHC_1_HW);

    status = Cy_SD_Host_Init(CYBSP_SDHC_1_HW,
                             &CYBSP_SDHC_1_config,
                             &ifx_sd_ctx);
    if (status != CY_SD_HOST_SUCCESS)
        return RT_ERROR;

    if (mtb_hal_sdhc_setup(&ifx_sdhc_obj,
                           &CYBSP_SDHC_1_sdhc_hal_config,
                           NULL,
                           &ifx_sd_ctx)
        != CY_RSLT_SUCCESS)
        return RT_ERROR;

    if (Cy_SD_Host_InitCard(CYBSP_SDHC_1_HW,
                            &CYBSP_SDHC_1_card_cfg,
                            &ifx_sd_ctx)
        != CY_SD_HOST_SUCCESS)
        return RT_ERROR;

    if (mtb_hal_sdhc_set_frequency(&ifx_sdhc_obj, IFX_SD_BUS_FREQ_HZ, true) != CY_RSLT_SUCCESS) {
        rt_kprintf("SD set frequency to 50MHz failed, keeping negotiated default\n");
    }

    const cy_stc_sysint_t intr_cfg = {
        .intrSrc = CYBSP_SDHC_1_IRQ,
        .intrPriority = IFX_SDHC_IRQ_PRIORITY,
    };

    sysint = Cy_SysInt_Init(&intr_cfg, SDHC_IRQHandler);
    if (sysint != CY_SYSINT_SUCCESS)
        return RT_ERROR;

    normal_int = CY_SD_HOST_CARD_INSERTION | CY_SD_HOST_CARD_REMOVAL |
                 CY_SD_HOST_XFER_COMPLETE | CY_SD_HOST_ERR_INTERRUPT;

    Cy_SD_Host_ClearNormalInterruptStatus(CYBSP_SDHC_1_HW,
                                          Cy_SD_Host_GetNormalInterruptStatus(CYBSP_SDHC_1_HW));
    Cy_SD_Host_ClearErrorInterruptStatus(CYBSP_SDHC_1_HW,
                                         Cy_SD_Host_GetErrorInterruptStatus(CYBSP_SDHC_1_HW));

    Cy_SD_Host_SetNormalInterruptMask(CYBSP_SDHC_1_HW, normal_int);
    Cy_SD_Host_SetErrorInterruptMask(CYBSP_SDHC_1_HW, IFX_SD_ERROR_MASK);

    NVIC_EnableIRQ(CYBSP_SDHC_1_IRQ);

    uint32_t capacity_gib = (uint32_t)(ifx_sd_ctx.maxSectorNum * 512ULL / (1024ULL * 1024ULL * 1024ULL));

    rt_kprintf("SD init success | type: %d | max sectors: %lu | capacity: %lu GiB | bus: %d-bit | target clk: %lu Hz\n",
               ifx_sd_ctx.cardType,
               ifx_sd_ctx.maxSectorNum,
               capacity_gib,
               (ifx_sd_ctx.busWidth == CY_SD_HOST_BUS_WIDTH_4_BIT) ? 4 : 1,
               (unsigned long)IFX_SD_BUS_FREQ_HZ);

    return RT_EOK;
}

static const struct sd_ops ifx_sd_ops = {
    .sd_init = ifx_sd_hw_init,
    .sd_read = ifx_sd_read,
    .sd_write = ifx_sd_write,
    .sd_control = ifx_sd_control,
};

rt_err_t drv_sdio_init(void)
{
    rt_mutex_init(&ifx_sd_lock, "sd_lock", RT_IPC_FLAG_PRIO);
    rt_event_init(&ifx_sd_dev.event, "sd_evt", RT_IPC_FLAG_PRIO);

    ifx_sd_dev.ops = &ifx_sd_ops;
    ifx_sd_dev.parent.type = RT_Device_Class_Block;
    ifx_sd_dev.parent.user_data = &ifx_sdio_ctx;

    return hal_sd_register(&ifx_sd_dev,
                           "sd0",
                           RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE,
                           RT_NULL);
}

#ifdef RT_USING_FINSH
static int sd_stat(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    rt_kprintf("sd dmaType=%u bus=%u-bit maxSector=%lu bounce=%luB target_clk=%luHz\n",
               (unsigned int)ifx_sd_ctx.dmaType,
               (unsigned int)((ifx_sd_ctx.busWidth == CY_SD_HOST_BUS_WIDTH_4_BIT) ? 4U : 1U),
               (unsigned long)ifx_sd_ctx.maxSectorNum,
               (unsigned long)ifx_sdio_ctx.bounce_size,
               (unsigned long)IFX_SD_BUS_FREQ_HZ);
    rt_kprintf("read direct=%lu bounce=%lu single=%lu multi=%lu sectors=%lu max_blocks=%lu\n",
               (unsigned long)ifx_sd_stats.read_direct_ops,
               (unsigned long)ifx_sd_stats.read_bounce_ops,
               (unsigned long)ifx_sd_stats.read_single_ops,
               (unsigned long)ifx_sd_stats.read_multi_ops,
               (unsigned long)ifx_sd_stats.read_sectors,
               (unsigned long)ifx_sd_stats.read_max_blocks);
    rt_kprintf("write direct=%lu bounce=%lu single=%lu multi=%lu sectors=%lu max_blocks=%lu\n",
               (unsigned long)ifx_sd_stats.write_direct_ops,
               (unsigned long)ifx_sd_stats.write_bounce_ops,
               (unsigned long)ifx_sd_stats.write_single_ops,
               (unsigned long)ifx_sd_stats.write_multi_ops,
               (unsigned long)ifx_sd_stats.write_sectors,
               (unsigned long)ifx_sd_stats.write_max_blocks);

    return 0;
}
MSH_CMD_EXPORT(sd_stat, show SDIO DMA and bounce usage counters);

static int sd_stat_reset(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    ifx_sd_reset_stats();
    rt_kprintf("sd stats reset\n");

    return 0;
}
MSH_CMD_EXPORT(sd_stat_reset, reset SDIO DMA and bounce usage counters);
#endif
