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

struct ifx_sdio {
    mtb_hal_sdhc_t* sdhc_obj;

    rt_uint8_t* bounce_buf;
    rt_size_t bounce_size;
};

static struct sd_device ifx_sd_dev;
static struct rt_mutex ifx_sd_lock;
static cy_stc_sd_host_context_t ifx_sd_ctx;
static mtb_hal_sdhc_t ifx_sdhc_obj;
static struct ifx_sdio ifx_sdio_ctx;

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

    normal = Cy_SD_Host_GetNormalInterruptStatus(SDHC1);
    error = Cy_SD_Host_GetErrorInterruptStatus(SDHC1);

    if (error) {
        Cy_SD_Host_ClearErrorInterruptStatus(SDHC1, error);
        rt_event_send(&ifx_sd_dev.event, IFX_SD_EVENT_ERROR);
    }

    if (normal & CY_SD_HOST_XFER_COMPLETE) {
        Cy_SD_Host_ClearNormalInterruptStatus(
            SDHC1, CY_SD_HOST_XFER_COMPLETE);

        rt_event_send(&ifx_sd_dev.event,
                      IFX_SD_EVENT_RX_DONE | IFX_SD_EVENT_TX_DONE);
    }

    Cy_SD_Host_ClearNormalInterruptStatus(SDHC1, normal);
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

static rt_err_t ifx_sd_read(sd_dev_t dev,
                            rt_uint8_t* buf,
                            rt_uint32_t sector,
                            rt_uint32_t count)
{
    struct ifx_sdio* sdio = dev->parent.user_data;
    cy_stc_sd_host_write_read_config_t cfg = { 0 };
    rt_size_t total;
    rt_uint8_t* dma_buf;
    rt_uint32_t evt;
    rt_err_t err = RT_EOK;

    if (!buf || count == 0)
        return -RT_EINVAL;

    total = count * IFX_SD_SECTOR_SIZE;

    rt_mutex_take(&ifx_sd_lock, RT_WAITING_FOREVER);

    err = ifx_sd_get_bounce(sdio, total, &dma_buf);
    if (err != RT_EOK)
        goto exit;

    CY_SDIO_DCACHE_INVALIDATE(dma_buf, total);

    cfg.address = sector;
    cfg.numberOfBlocks = count;
    cfg.autoCommand = CY_SD_HOST_AUTO_CMD_AUTO;
    cfg.enableDma = true;
    cfg.data = (uint32_t*)dma_buf;
    cfg.dataTimeout = 12;

    rt_event_control(&dev->event, RT_IPC_CMD_RESET, RT_NULL);

    if (Cy_SD_Host_Read(SDHC1, &cfg, &ifx_sd_ctx) != CY_SD_HOST_SUCCESS) {
        err = -RT_ERROR;
        goto exit;
    }

    if (rt_event_recv(&dev->event,
                      IFX_SD_EVENT_RX_DONE | IFX_SD_EVENT_ERROR,
                      RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
                      rt_tick_from_millisecond(5000),
                      &evt)
        != RT_EOK) {
        err = -RT_ETIMEOUT;
        goto exit;
    }

    if (evt & IFX_SD_EVENT_ERROR) {
        err = -RT_ERROR;
        goto exit;
    }

    CY_SDIO_DCACHE_INVALIDATE(dma_buf, total);
    rt_memcpy(buf, dma_buf, total);

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
    rt_size_t total;
    rt_uint8_t* dma_buf;
    rt_uint32_t evt;
    rt_err_t err = RT_EOK;

    if (!buf || count == 0)
        return -RT_EINVAL;

    total = count * IFX_SD_SECTOR_SIZE;

    rt_mutex_take(&ifx_sd_lock, RT_WAITING_FOREVER);

    err = ifx_sd_get_bounce(sdio, total, &dma_buf);
    if (err != RT_EOK)
        goto exit;

    rt_memcpy(dma_buf, buf, total);
    CY_SDIO_DCACHE_CLEAN(dma_buf, total);

    cfg.address = sector;
    cfg.numberOfBlocks = count;
    cfg.autoCommand = CY_SD_HOST_AUTO_CMD_AUTO;
    cfg.enableDma = true;
    cfg.data = (uint32_t*)dma_buf;
    cfg.dataTimeout = 12;

    rt_event_control(&dev->event, RT_IPC_CMD_RESET, RT_NULL);

    if (Cy_SD_Host_Write(SDHC1, &cfg, &ifx_sd_ctx) != CY_SD_HOST_SUCCESS) {
        err = -RT_ERROR;
        goto exit;
    }

    if (rt_event_recv(&dev->event,
                      IFX_SD_EVENT_TX_DONE | IFX_SD_EVENT_ERROR,
                      RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
                      rt_tick_from_millisecond(5000),
                      &evt)
        != RT_EOK) {
        err = -RT_ETIMEOUT;
        goto exit;
    }

    if (evt & IFX_SD_EVENT_ERROR)
        err = -RT_ERROR;

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

    const cy_stc_sysint_t intr_cfg = {
        .intrSrc = CYBSP_SDHC_1_IRQ,
        .intrPriority = IFX_SDHC_IRQ_PRIORITY,
    };

    sysint = Cy_SysInt_Init(&intr_cfg, SDHC_IRQHandler);
    if (sysint != CY_SYSINT_SUCCESS)
        return RT_ERROR;

    Cy_SD_Host_SetNormalInterruptMask(
        CYBSP_SDHC_1_HW,
        CY_SD_HOST_CARD_INSERTION | CY_SD_HOST_CARD_REMOVAL | CY_SD_HOST_XFER_COMPLETE);

    NVIC_EnableIRQ(CYBSP_SDHC_1_IRQ);

    uint32_t capacity_gib = (uint32_t)(ifx_sd_ctx.maxSectorNum * 512ULL / (1024ULL * 1024ULL * 1024ULL));

    rt_kprintf("SD init success | type: %d | max sectors: %lu | capacity: %lu GiB | bus: %d-bit\n",
               ifx_sd_ctx.cardType,
               ifx_sd_ctx.maxSectorNum,
               capacity_gib,
               (ifx_sd_ctx.busWidth == CY_SD_HOST_BUS_WIDTH_4_BIT) ? 4 : 1);

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
