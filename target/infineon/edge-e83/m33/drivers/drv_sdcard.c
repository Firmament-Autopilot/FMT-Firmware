/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author         Notes
 * 2023-05-05     vandoul        first version
 * 2025-11-25     Rbb666         Reworked to use MMCSD host framework
 */

#include <rtthread.h>
#include "rtdevice.h"
#include "cybsp.h"

#ifdef BSP_USING_SDCARD

/* DCache operations using CMSIS API for Cortex-M55 */
#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define CY_SDIO_DCACHE_CLEAN(addr, size)       SCB_CleanDCache_by_Addr((void *)(addr), (int32_t)(size))
#define CY_SDIO_DCACHE_INVALIDATE(addr, size)  SCB_InvalidateDCache_by_Addr((void *)(addr), (int32_t)(size))
#else
#define CY_SDIO_DCACHE_CLEAN(addr, size)       ((void)0)
#define CY_SDIO_DCACHE_INVALIDATE(addr, size)  ((void)0)
#endif

//#define DRV_DEBUG
#define LOG_TAG              "drv.sdio"
#ifdef DRV_DEBUG
#define DBG_LVL              DBG_LOG
#else
#define DBG_LVL              DBG_INFO
#endif
#include <drv_log.h>

/* SDHC configuration */
#define SDHC_IRQ_PRIORITY           (3U)

/* SD Host timing parameters */
#define CY_SDIO_MIN_FREQ_HZ         (400000U)       /* 400KHz for identification */
#define CY_SDIO_DEFAULT_FREQ_HZ     (25000000U)     /* 25MHz default speed */
#define CY_SDIO_MAX_FREQ_HZ         (50000000U)     /* 50MHz high speed */

/* DMA and buffer configuration */
#define CY_SDIO_ADMA_MAX_LEN        (0xFFFFU)       /* ADMA max length 64KB */
#define CY_SDIO_MAX_BLOCKS          (CY_SDIO_ADMA_MAX_LEN / 512U)
#define CY_SDIO_BOUNCE_ALIGN        (32U)           /* DMA buffer alignment */
#define CY_SDIO_BUFF_SIZE           (CY_SDIO_ADMA_MAX_LEN)

/* Command timeout in milliseconds */
#define CY_SDIO_CMD_TIMEOUT_MS      (5000U)
#define CY_SDIO_DATA_TIMEOUT_MS     (30000U)

/* Lock macros */
#define CY_SDIO_LOCK(sdio)      rt_mutex_take(&(sdio)->mutex, RT_WAITING_FOREVER)
#define CY_SDIO_UNLOCK(sdio)    rt_mutex_release(&(sdio)->mutex)

/* SDHC hardware objects */
static mtb_hal_sdhc_t sdhc_obj;
static cy_stc_sd_host_context_t sdhc_host_context;

/**
 * @brief PSE84 SDIO driver private data structure
 */
struct cy_pse_sdio
{
    struct rt_mmcsd_host *host;         /* RT-Thread MMCSD host */
    struct rt_mutex mutex;              /* Access mutex */
    struct rt_event event;              /* Event for interrupt handling */
    rt_uint8_t *bounce_buf;             /* DMA bounce buffer */
    rt_size_t bounce_size;              /* Bounce buffer size */
    rt_uint8_t power_mode;              /* Current power mode */
    rt_uint8_t bus_width;               /* Current bus width */
    rt_uint32_t current_freq;           /* Current clock frequency */
    SDHC_Type *hw_base;                 /* Hardware base address */
    rt_bool_t auto_cmd12_sent;          /* Flag: Auto CMD12 was sent in last transfer */
};

static struct cy_pse_sdio *cy_sdio = RT_NULL;

/**
 * @brief Convert RT-Thread response type to HAL response type
 */
static mtb_hal_sdhc_cmd_response_type_t cy_sdio_resp_type(rt_uint32_t flags)
{
    switch (flags & RESP_MASK)
    {
    case RESP_R2:
        return MTB_HAL_SDHC_RESPONSE_LEN_136;
    case RESP_R1B:
        return MTB_HAL_SDHC_RESPONSE_LEN_48B;
    case RESP_R1:
    case RESP_R3:
    case RESP_R4:
    case RESP_R5:
    case RESP_R6:
    case RESP_R7:
        return MTB_HAL_SDHC_RESPONSE_LEN_48;
    case RESP_NONE:
    default:
        return MTB_HAL_SDHC_RESPONSE_NONE;
    }
}

/**
 * @brief Check if response needs CRC check
 */
static rt_bool_t cy_sdio_resp_need_crc(rt_uint32_t flags)
{
    switch (flags & RESP_MASK)
    {
    case RESP_NONE:
    case RESP_R3:
    case RESP_R4:
        return RT_FALSE;
    default:
        return RT_TRUE;
    }
}

/**
 * @brief Check if response needs index check
 */
static rt_bool_t cy_sdio_resp_need_idx(rt_uint32_t flags)
{
    switch (flags & RESP_MASK)
    {
    case RESP_NONE:
    case RESP_R2:
    case RESP_R3:
    case RESP_R4:
        return RT_FALSE;
    default:
        return RT_TRUE;
    }
}

/**
 * @brief Fix response byte order for R2 (136-bit) response
 *
 * The SDHC controller returns 136-bit response in registers:
 *   RESP01_R = bits 39:8,   RESP23_R = bits 71:40
 *   RESP45_R = bits 103:72, RESP67_R = bits 135:104
 *
 * This means the hardware has already shifted out the CRC (bits 7:0).
 * PDL reads them sequentially into responsePtr[0..3]:
 *   resp[0] = bits 39:8,   resp[1] = bits 71:40
 *   resp[2] = bits 103:72, resp[3] = bits 135:104
 *
 * RT-Thread's GET_BITS(resp, start, size) with __off = 3 - (start/32) expects:
 *   resp[0] = CSD bits 127:96 (MSB)
 *   resp[1] = CSD bits 95:64
 *   resp[2] = CSD bits 63:32
 *   resp[3] = CSD bits 31:0 (LSB)
 *
 * Since the hardware shifted by 8 bits, we need to:
 *   1. Reverse the word order
 *   2. Shift each word to align properly (shift left by 8, bring in bits from next word)
 */
static void cy_sdio_fix_response_byteorder(struct rt_mmcsd_cmd *cmd, bool is_long)
{
    if (!is_long)
    {
        return;
    }

    rt_uint32_t raw[4];
    rt_memcpy(raw, cmd->resp, sizeof(raw));

    /* Reverse order and shift to reconstruct the proper CSD bits.
     * Hardware gives us:
     *   raw[0] = response bits 39:8   (contains CSD bits 31:0, but shifted)
     *   raw[1] = response bits 71:40  (contains CSD bits 63:32, but shifted)
     *   raw[2] = response bits 103:72 (contains CSD bits 95:64, but shifted)
     *   raw[3] = response bits 135:104 (contains CSD bits 127:96)
     *
     * After reversal we want:
     *   resp[0] = CSD bits 127:96 = raw[3]
     *   resp[1] = CSD bits 95:64  = raw[2]
     *   resp[2] = CSD bits 63:32  = raw[1]
     *   resp[3] = CSD bits 31:0   = raw[0]
     *
     * But the hardware already removed the low 8 bits (CRC), so the data is
     * pre-shifted. We need to reconstruct by shifting left 8 bits.
     */
    cmd->resp[0] = (raw[3] << 8) | (raw[2] >> 24);
    cmd->resp[1] = (raw[2] << 8) | (raw[1] >> 24);
    cmd->resp[2] = (raw[1] << 8) | (raw[0] >> 24);
    cmd->resp[3] = (raw[0] << 8);
}

/**
 * @brief Send a single command to the SD card
 */
static rt_err_t cy_sdio_send_command(struct cy_pse_sdio *sdio, struct rt_mmcsd_cmd *cmd)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    struct rt_mmcsd_data *data = cmd->data;
    mtb_hal_sdhc_cmd_config_t hal_cmd;
    mtb_hal_sdhc_data_config_t data_cfg;
    rt_err_t err = RT_EOK;

    rt_uint8_t *user_buf = RT_NULL;
    rt_uint8_t *dma_buf = RT_NULL;
    rt_size_t total_bytes = 0;
    rt_bool_t use_bounce = RT_FALSE;

    /* Clear auto cmd12 flag at start of each command */
    sdio->auto_cmd12_sent = RT_FALSE;

    LOG_D("CMD:%d ARG:0x%08x RES:%s%s%s%s%s%s%s%s%s rw:%c len:%d blksize:%d",
          cmd->cmd_code,
          cmd->arg,
          resp_type(cmd) == RESP_NONE ? "NONE" : "",
          resp_type(cmd) == RESP_R1  ? "R1"  : "",
          resp_type(cmd) == RESP_R1B ? "R1B" : "",
          resp_type(cmd) == RESP_R2  ? "R2"  : "",
          resp_type(cmd) == RESP_R3  ? "R3"  : "",
          resp_type(cmd) == RESP_R4  ? "R4"  : "",
          resp_type(cmd) == RESP_R5  ? "R5"  : "",
          resp_type(cmd) == RESP_R6  ? "R6"  : "",
          resp_type(cmd) == RESP_R7  ? "R7"  : "",
          data ? (data->flags & DATA_DIR_WRITE ? 'w' : 'r') : '-',
          data ? data->blks * data->blksize : 0,
          data ? data->blksize : 0);

    if (data)
    {
        total_bytes = (rt_size_t)data->blks * data->blksize;
        if ((total_bytes == 0) || (total_bytes > CY_SDIO_ADMA_MAX_LEN))
        {
            LOG_E("invalid transfer size %d", total_bytes);
            err = -RT_EINVAL;
            goto exit;
        }

        if (!sdio->bounce_buf || sdio->bounce_size < total_bytes)
        {
            if (sdio->bounce_buf)
            {
                rt_free_align(sdio->bounce_buf);
            }
            sdio->bounce_buf = rt_malloc_align(total_bytes, CY_SDIO_BOUNCE_ALIGN);
            if (!sdio->bounce_buf)
            {
                LOG_E("alloc bounce %d fail", total_bytes);
                err = -RT_ENOMEM;
                goto exit;
            }
            sdio->bounce_size = total_bytes;
        }

        user_buf = (rt_uint8_t *)data->buf;
        if (!user_buf)
        {
            err = -RT_EINVAL;
            goto exit;
        }

        dma_buf = sdio->bounce_buf;
        use_bounce = RT_TRUE;

        if (data->flags & DATA_DIR_WRITE)
        {
            rt_memcpy(dma_buf, user_buf, total_bytes);
            CY_SDIO_DCACHE_CLEAN(dma_buf, total_bytes);
        }
        else
        {
            CY_SDIO_DCACHE_INVALIDATE(dma_buf, total_bytes);
        }

        data->bytes_xfered = 0;

        rt_memset(&data_cfg, 0, sizeof(data_cfg));
        data_cfg.data_ptr = (uint32_t *)dma_buf;
        data_cfg.block_size = data->blksize;
        data_cfg.number_of_blocks = data->blks;
        data_cfg.is_read = (data->flags & DATA_DIR_READ) ? true : false;

        /* Use auto command for multi-block transfers */
        if (data->blks > 1)
        {
            data_cfg.auto_command = MTB_HAL_SDHC_AUTO_CMD_12;
            sdio->auto_cmd12_sent = RT_TRUE;
        }
        else
        {
            data_cfg.auto_command = MTB_HAL_SDHC_AUTO_CMD_NONE;
        }

        result = mtb_hal_sdhc_config_data_transfer(&sdhc_obj, &data_cfg);
        if (CY_RSLT_SUCCESS != result)
        {
            LOG_E("config data transfer fail: 0x%08x", (unsigned int)result);
            err = -RT_ERROR;
            goto exit;
        }
    }

    /* Clear any pending errors */
    mtb_hal_sdhc_clear_errors(&sdhc_obj);

    /* Configure command */
    rt_memset(&hal_cmd, 0, sizeof(hal_cmd));
    hal_cmd.command_index = cmd->cmd_code;
    hal_cmd.command_argument = cmd->arg;
    hal_cmd.enable_crc_check = cy_sdio_resp_need_crc(cmd->flags);
    hal_cmd.response_type = cy_sdio_resp_type(cmd->flags);
    hal_cmd.enable_idx_check = cy_sdio_resp_need_idx(cmd->flags);
    hal_cmd.command_type = MTB_HAL_SDHC_CMD_NORMAL;
    hal_cmd.data_config = data ? &data_cfg : RT_NULL;

    /* Send command */
    result = mtb_hal_sdhc_send_cmd(&sdhc_obj, &hal_cmd);
    if (CY_RSLT_SUCCESS != result)
    {
        LOG_E("send cmd %d fail: 0x%08x", cmd->cmd_code, (unsigned int)result);
        err = -RT_ERROR;
        goto exit_hw;
    }

    /* Get response if expected */
    if ((err == RT_EOK) && (hal_cmd.response_type != MTB_HAL_SDHC_RESPONSE_NONE))
    {
        bool large = (hal_cmd.response_type == MTB_HAL_SDHC_RESPONSE_LEN_136);
        rt_memset(cmd->resp, 0, sizeof(cmd->resp));
        result = mtb_hal_sdhc_get_response(&sdhc_obj, cmd->resp, large);
        if (CY_RSLT_SUCCESS != result)
        {
            LOG_E("get response fail: 0x%08x", (unsigned int)result);
            err = -RT_ERROR;
            goto exit_hw;
        }

        /* Debug: print raw response before byte order fix */
        if (large)
        {
            LOG_I("CMD%d raw resp: [%08X %08X %08X %08X]",
                  cmd->cmd_code, cmd->resp[0], cmd->resp[1], cmd->resp[2], cmd->resp[3]);
        }

        /* PDL returns response with resp[0]=LSB (bits 31-0), resp[3]=MSB (bits 127-96).
         * RT-Thread's GET_BITS expects resp[0]=MSB, resp[3]=LSB, so we need to reverse. */
        cy_sdio_fix_response_byteorder(cmd, large);

        /* Debug: print response after byte order fix */
        if (large)
        {
            LOG_I("CMD%d fixed resp: [%08X %08X %08X %08X]",
                  cmd->cmd_code, cmd->resp[0], cmd->resp[1], cmd->resp[2], cmd->resp[3]);
        }
        else
        {
            LOG_D("resp: [%08X %08X %08X %08X]",
                  cmd->resp[0], cmd->resp[1], cmd->resp[2], cmd->resp[3]);
        }
    }

    /* Wait for data transfer completion */
    if ((err == RT_EOK) && data)
    {
        result = mtb_hal_sdhc_wait_transfer_complete(&sdhc_obj);
        if (CY_RSLT_SUCCESS != result)
        {
            LOG_E("wait transfer complete fail: 0x%08x", (unsigned int)result);
            err = -RT_ERROR;
            goto exit_hw;
        }

        /* Copy data from bounce buffer for read operations */
        if (use_bounce && (data->flags & DATA_DIR_READ))
        {
            CY_SDIO_DCACHE_INVALIDATE(dma_buf, total_bytes);
            rt_memcpy(user_buf, dma_buf, total_bytes);
        }
        data->bytes_xfered = total_bytes;
    }

exit_hw:
    /* Check for hardware errors */
    {
        mtb_hal_sdhc_error_type_t hw_err = mtb_hal_sdhc_get_last_command_errors(&sdhc_obj);
        if (hw_err != MTB_HAL_SDHC_NO_ERR)
        {
            if (hw_err & (MTB_HAL_SDHC_CMD_TOUT_ERR | MTB_HAL_SDHC_DATA_TOUT_ERR))
            {
                err = -RT_ETIMEOUT;
            }
            else if (hw_err & (MTB_HAL_SDHC_CMD_CRC_ERR | MTB_HAL_SDHC_DATA_CRC_ERR))
            {
                LOG_E("CRC error: cmd %d hw_err 0x%04x", cmd->cmd_code, (unsigned int)hw_err);
                err = -RT_ERROR;
            }
            else
            {
                err = -RT_ERROR;
            }

            LOG_E("cmd %d arg 0x%08x flags 0x%08x hw_err 0x%04x",
                  cmd->cmd_code, cmd->arg, cmd->flags, (unsigned int)hw_err);
            mtb_hal_sdhc_clear_errors(&sdhc_obj);

            /* Reset command and data lines on error */
            mtb_hal_sdhc_software_reset(&sdhc_obj);
        }
    }

exit:
    cmd->err = err;
    if (data)
    {
        data->err = err;
    }

    return err;
}

/**
 * @brief RT-Thread MMCSD request handler
 */
static void cy_sdio_request(struct rt_mmcsd_host *host, struct rt_mmcsd_req *req)
{
    struct cy_pse_sdio *sdio = host->private_data;

    RT_ASSERT(sdio != RT_NULL);
    RT_ASSERT(req != RT_NULL);

    CY_SDIO_LOCK(sdio);

    /* Handle SET_BLOCK_COUNT command for multi-block transfers */
    if (req->sbc)
    {
        if (cy_sdio_send_command(sdio, req->sbc) != RT_EOK)
            goto out;
    }

    if (req->cmd)
    {
        if (cy_sdio_send_command(sdio, req->cmd) != RT_EOK)
            goto out;
    }

    /* Send stop command if needed (skip if Auto CMD12 was used) */
    if (req->stop && !sdio->auto_cmd12_sent)
    {
        cy_sdio_send_command(sdio, req->stop);
    }

out:
    CY_SDIO_UNLOCK(sdio);
    mmcsd_req_complete(host);
}

/**
 * @brief Configure SDIO bus settings
 */
static void cy_sdio_set_iocfg(struct rt_mmcsd_host *host, struct rt_mmcsd_io_cfg *io_cfg)
{
    struct cy_pse_sdio *sdio = host->private_data;
    cy_rslt_t result;
    uint32_t clock = io_cfg->clock;

    RT_ASSERT(sdio != RT_NULL);

    LOG_D("clk:%dK width:%s%s%s power:%s%s%s",
          clock / 1000,
          io_cfg->bus_width == MMCSD_BUS_WIDTH_8 ? "8" : "",
          io_cfg->bus_width == MMCSD_BUS_WIDTH_4 ? "4" : "",
          io_cfg->bus_width == MMCSD_BUS_WIDTH_1 ? "1" : "",
          io_cfg->power_mode == MMCSD_POWER_OFF ? "OFF" : "",
          io_cfg->power_mode == MMCSD_POWER_UP ? "UP" : "",
          io_cfg->power_mode == MMCSD_POWER_ON ? "ON" : "");

    CY_SDIO_LOCK(sdio);

    /* Handle power mode changes */
    if (io_cfg->power_mode == MMCSD_POWER_OFF)
    {
        if (sdio->power_mode != MMCSD_POWER_OFF)
        {
            mtb_hal_sdhc_enable_card_power(&sdhc_obj, false);
            Cy_SD_Host_DisableSdClk(sdio->hw_base);
            sdio->power_mode = MMCSD_POWER_OFF;
            LOG_D("Card power OFF");
        }
    }
    else if (io_cfg->power_mode == MMCSD_POWER_UP)
    {
        if (sdio->power_mode == MMCSD_POWER_OFF)
        {
            /*
             * Power-up sequence per SD specification:
             * 1. Set IO voltage to 3.3V
             * 2. Set bus width to 1-bit
             * 3. Set clock to 400KHz (identification frequency)
             * 4. Enable card power
             * 5. Wait for voltage ramp-up (at least 35ms per SD spec)
             * 6. Enable SD clock
             */
            Cy_SD_Host_ChangeIoVoltage(sdio->hw_base, CY_SD_HOST_IO_VOLT_3_3V);
            (void)Cy_SD_Host_SetHostBusWidth(sdio->hw_base, CY_SD_HOST_BUS_WIDTH_1_BIT);

            /* Set identification clock frequency - negotiate=false since card not ready */
            result = mtb_hal_sdhc_set_frequency(&sdhc_obj, CY_SDIO_MIN_FREQ_HZ, false);
            if (result != CY_RSLT_SUCCESS)
            {
                LOG_W("Set init freq fail: 0x%08x", (unsigned int)result);
            }
            sdio->current_freq = CY_SDIO_MIN_FREQ_HZ;

            /* Enable card power */
            mtb_hal_sdhc_enable_card_power(&sdhc_obj, true);

            /* Wait for power supply ramp-up time (SD spec requires 35ms minimum) */
            rt_thread_mdelay(50);

            /* Enable SD clock output */
            Cy_SD_Host_EnableSdClk(sdio->hw_base);

            /* Additional stabilization delay */
            rt_thread_mdelay(10);

            sdio->power_mode = MMCSD_POWER_UP;
            sdio->bus_width = 1;
            LOG_D("Card power UP, clock 400KHz");
        }
    }
    else if (io_cfg->power_mode == MMCSD_POWER_ON)
    {
        if (sdio->power_mode == MMCSD_POWER_OFF)
        {
            /* Full power-up sequence needed */
            Cy_SD_Host_ChangeIoVoltage(sdio->hw_base, CY_SD_HOST_IO_VOLT_3_3V);
            (void)Cy_SD_Host_SetHostBusWidth(sdio->hw_base, CY_SD_HOST_BUS_WIDTH_1_BIT);
            result = mtb_hal_sdhc_set_frequency(&sdhc_obj, CY_SDIO_MIN_FREQ_HZ, false);
            if (result != CY_RSLT_SUCCESS)
            {
                LOG_W("Set init freq fail: 0x%08x", (unsigned int)result);
            }
            mtb_hal_sdhc_enable_card_power(&sdhc_obj, true);
            rt_thread_mdelay(50);
            Cy_SD_Host_EnableSdClk(sdio->hw_base);
            rt_thread_mdelay(10);
            sdio->current_freq = CY_SDIO_MIN_FREQ_HZ;
            sdio->bus_width = 1;
        }
        sdio->power_mode = MMCSD_POWER_ON;
        LOG_D("Card power ON");
    }

    /* Only configure clock and bus width when power is on */
    if (sdio->power_mode != MMCSD_POWER_OFF)
    {
        /* Configure clock frequency */
        if (clock == 0)
        {
            clock = CY_SDIO_MIN_FREQ_HZ;
        }
        if (clock < CY_SDIO_MIN_FREQ_HZ)
        {
            clock = CY_SDIO_MIN_FREQ_HZ;
        }
        if (clock > host->freq_max)
        {
            clock = host->freq_max;
        }
        if (clock != sdio->current_freq)
        {
            result = mtb_hal_sdhc_set_frequency(&sdhc_obj, clock, true);
            if (result != CY_RSLT_SUCCESS)
            {
                LOG_E("set freq %uHz fail 0x%08x", (unsigned int)clock, (unsigned int)result);
            }
            else
            {
                sdio->current_freq = mtb_hal_sdhc_get_frequency(&sdhc_obj);
                LOG_D("Clock set to %u Hz (requested %u Hz)",
                      (unsigned int)sdio->current_freq, (unsigned int)clock);
            }
        }

        /* Configure bus width */
        uint8_t width = 1;
        cy_en_sd_host_bus_width_t hw_width = CY_SD_HOST_BUS_WIDTH_1_BIT;

        if (io_cfg->bus_width == MMCSD_BUS_WIDTH_4)
        {
            width = 4;
            hw_width = CY_SD_HOST_BUS_WIDTH_4_BIT;
        }
        else if (io_cfg->bus_width == MMCSD_BUS_WIDTH_8)
        {
            width = 8;
            hw_width = CY_SD_HOST_BUS_WIDTH_8_BIT;
        }

        if (width != sdio->bus_width)
        {
            /* Set host-side bus width */
            result = Cy_SD_Host_SetHostBusWidth(sdio->hw_base, hw_width);
            if (result != CY_RSLT_SUCCESS)
            {
                LOG_E("set bus width %u fail 0x%08x", width, (unsigned int)result);
            }
            else
            {
                sdio->bus_width = width;
                LOG_D("Bus width set to %u", width);
            }
        }
    }

    CY_SDIO_UNLOCK(sdio);
}

/**
 * @brief Get card detection status
 */
static rt_int32_t cy_sdio_get_card_status(struct rt_mmcsd_host *host)
{
    (void)host;
    /* Check if card is inserted via HAL */
    if (mtb_hal_sdhc_is_card_inserted(&sdhc_obj))
    {
        return 0;  /* Card present */
    }
    return -1;  /* No card */
}

/**
 * @brief MMCSD host operations structure
 */
static const struct rt_mmcsd_host_ops cy_sdio_ops =
{
    cy_sdio_request,
    cy_sdio_set_iocfg,
    cy_sdio_get_card_status,
    RT_NULL,    /* enable_sdio_irq - not implemented */
    RT_NULL,    /* execute_tuning - not implemented */
};

/**
 * @brief Card detection stub - always returns true for now
 */
bool Cy_SD_Host_IsCardConnected(SDHC_Type const *base)
{
    (void)base;
    return true;
}

/**
 * @brief SDHC interrupt service routine
 */
static void sd_card_isr(void)
{
    rt_interrupt_enter();
    mtb_hal_sdhc_process_interrupt(&sdhc_obj);
    rt_interrupt_leave();
}

/**
 * @brief Initialize the SDIO hardware and register with RT-Thread
 */
int rt_hw_sdio_init(void)
{
    cy_rslt_t hal_status;
    cy_en_sd_host_status_t pdl_status;
    cy_en_sysint_status_t sysint_status;
    struct cy_pse_sdio *sdio;

    LOG_I("Initializing SDIO driver...");

    /* Allocate driver private data */
    sdio = rt_calloc(1, sizeof(*sdio));
    if (!sdio)
    {
        LOG_E("malloc sdio fail");
        return -RT_ENOMEM;
    }

    sdio->bounce_size = CY_SDIO_ADMA_MAX_LEN;
    sdio->bounce_buf = rt_malloc_align(sdio->bounce_size, CY_SDIO_BOUNCE_ALIGN);
    if (!sdio->bounce_buf)
    {
        rt_free(sdio);
        LOG_E("alloc bounce buf fail");
        return -RT_ENOMEM;
    }

    sdio->host = mmcsd_alloc_host();
    if (!sdio->host)
    {
        rt_free_align(sdio->bounce_buf);
        rt_free(sdio);
        LOG_E("alloc host fail");
        return -RT_ENOMEM;
    }

    /* Initialize synchronization primitives */
    rt_mutex_init(&sdio->mutex, "sdio", RT_IPC_FLAG_PRIO);
    rt_event_init(&sdio->event, "sdio", RT_IPC_FLAG_FIFO);

    /* Store hardware base address */
    sdio->hw_base = CYBSP_SDHC_1_HW;

    /* Configure interrupt */
    cy_stc_sysint_t sdhc_isr_config =
    {
        .intrSrc = CYBSP_SDHC_1_IRQ,
        .intrPriority = SDHC_IRQ_PRIORITY,
    };

    /* Enable SDHC hardware block */
    Cy_SD_Host_Enable(CYBSP_SDHC_1_HW);

    /* Initialize PDL driver */
    pdl_status = Cy_SD_Host_Init(CYBSP_SDHC_1_HW, &CYBSP_SDHC_1_config, &sdhc_host_context);
    if (CY_SD_HOST_SUCCESS != pdl_status)
    {
        LOG_E("Cy_SD_Host_Init error: %d", pdl_status);
        goto fail;
    }

    /* Setup HAL layer */
    hal_status = mtb_hal_sdhc_setup(&sdhc_obj, &CYBSP_SDHC_1_sdhc_hal_config, NULL, &sdhc_host_context);
    if (CY_RSLT_SUCCESS != hal_status)
    {
        LOG_E("mtb_hal_sdhc_setup error: 0x%08x", (unsigned int)hal_status);
        goto fail;
    }

    /* Initialize interrupt */
    sysint_status = Cy_SysInt_Init(&sdhc_isr_config, sd_card_isr);
    if (CY_SYSINT_SUCCESS != sysint_status)
    {
        LOG_E("Cy_SysInt_Init error: %d", sysint_status);
        goto fail;
    }

    /* Enable NVIC interrupt */
    NVIC_EnableIRQ((IRQn_Type)sdhc_isr_config.intrSrc);

    /*
     * Pre-initialize SD host hardware according to SD specification:
     * 1. Set IO voltage to 3.3V
     * 2. Set bus width to 1-bit (required for identification phase)
     * 3. Set clock to 400KHz (identification frequency)
     * Note: Use negotiate=false since card is not initialized yet
     */
    Cy_SD_Host_ChangeIoVoltage(CYBSP_SDHC_1_HW, CY_SD_HOST_IO_VOLT_3_3V);
    (void)Cy_SD_Host_SetHostBusWidth(CYBSP_SDHC_1_HW, CY_SD_HOST_BUS_WIDTH_1_BIT);

    /* Set initial clock to 400KHz for card identification - negotiate=false! */
    hal_status = mtb_hal_sdhc_set_frequency(&sdhc_obj, CY_SDIO_MIN_FREQ_HZ, false);
    if (CY_RSLT_SUCCESS != hal_status)
    {
        LOG_W("Initial clock set warning: 0x%08x", (unsigned int)hal_status);
    }

    LOG_D("SD clock initialized to 400KHz");

    /* Configure MMCSD host */
    sdio->host->ops = &cy_sdio_ops;
    sdio->host->freq_min = CY_SDIO_MIN_FREQ_HZ;
    sdio->host->freq_max = CY_SDIO_MAX_FREQ_HZ;

    /* Supported voltage range: 2.7V - 3.6V */
    sdio->host->valid_ocr = VDD_27_28 | VDD_28_29 | VDD_29_30 | VDD_30_31 |
                            VDD_31_32 | VDD_32_33 | VDD_33_34 | VDD_34_35 |
                            VDD_35_36;

    /* Host capabilities */
    sdio->host->flags = MMCSD_BUSWIDTH_4 | MMCSD_MUTBLKWRITE | MMCSD_SUP_HIGHSPEED;

    /* DMA constraints */
    sdio->host->max_seg_size = CY_SDIO_BUFF_SIZE;
    sdio->host->max_dma_segs = 1;
    sdio->host->max_blk_size = 512;
    sdio->host->max_blk_count = CY_SDIO_MAX_BLOCKS;

    /* Link driver data */
    sdio->host->private_data = sdio;

    /* Initialize state */
    sdio->power_mode = MMCSD_POWER_OFF;
    sdio->bus_width = 1;
    sdio->current_freq = CY_SDIO_MIN_FREQ_HZ;

    /* Save global reference */
    cy_sdio = sdio;

    LOG_I("SDIO driver initialized successfully");

    /* Notify MMCSD core that host is ready */
    mmcsd_change(sdio->host);

    return RT_EOK;

fail:
    rt_event_detach(&sdio->event);
    rt_mutex_detach(&sdio->mutex);
    if (sdio->bounce_buf)
    {
        rt_free_align(sdio->bounce_buf);
    }
    mmcsd_free_host(sdio->host);
    rt_free(sdio);
    return -RT_ERROR;
}
INIT_DEVICE_EXPORT(rt_hw_sdio_init);

#endif /* BSP_USING_SDCARD */
