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

#include "hal/sd/sd.h"
#include "sdcard.h"

#define SD_WAIT_TIMEOUT 10

static struct sd_device sd0_dev;
static sd_card_info_struct sd_cardinfo; /* information of SD card */
static struct rt_mutex sd_lock;

/*!
    \brief      this function handles SDIO interrupt request
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SDIO_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    sd_error_enum sd_err = sd_interrupts_process();
    if (sd_err != SD_OK) {
        printf("sd isr error:%d\n", sd_err);
    }

    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t init(sd_dev_t sd)
{
    uint32_t cardstate = 0;

    nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
    nvic_irq_enable(SDIO_IRQn, 0, 1);

    if (sd_init() != SD_OK) {
        goto error;
    }

    if (sd_card_information_get(&sd_cardinfo) != SD_OK) {
        goto error;
    }

    if (sd_card_select_deselect(sd_cardinfo.card_rca) != SD_OK) {
        goto error;
    }

    if (sd_cardstatus_get(&cardstate) != SD_OK) {
        goto error;
    }

    if (cardstate & 0x02000000) {
        printf("the card is locked!\n");
        goto error;
    }

    if (sd_bus_mode_config(SDIO_BUSMODE_4BIT) != SD_OK) {
        goto error;
    }

    if (sd_transfer_mode_config(SD_POLLING_MODE) != SD_OK) {
        goto error;
    }

    /* enable sdio hardware clock control to avoid SD_RX_OVERRUN_ERROR */
    sdio_hardware_clock_enable();

    return RT_EOK;

error:
    return RT_ERROR;
}

static rt_err_t sd_write(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    if (count == 0) {
        return RT_EOK;
    }

    RT_TRY(rt_mutex_take(&sd_lock, TICKS_FROM_MS(SD_WAIT_TIMEOUT)));

    if (count > 1) {
        if (sd_multiblocks_write((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize, count) != SD_OK) {
            err = RT_ERROR;
        }
    } else {
        if (sd_block_write((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize) != SD_OK) {
            err = RT_ERROR;
        }
    }

    RT_TRY(rt_mutex_release(&sd_lock));

    return err;
}

static rt_err_t sd_read(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    if (count == 0) {
        return RT_EOK;
    }

    RT_TRY(rt_mutex_take(&sd_lock, TICKS_FROM_MS(SD_WAIT_TIMEOUT)));

    if (count > 1) {
        if (sd_multiblocks_read((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize, count) != SD_OK) {
            err = RT_ERROR;
        }
    } else {
        if (sd_block_read((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize) != SD_OK) {
            err = RT_ERROR;
        }
    }

    RT_TRY(rt_mutex_release(&sd_lock));

    return err;
}

static rt_err_t sd_control(sd_dev_t sd, int cmd, void* arg)
{
    switch (cmd) {
    case RT_DEVICE_CTRL_BLK_GETGEOME: {
        struct rt_device_blk_geometry geometry;

        geometry.bytes_per_sector = sd_cardinfo.card_blocksize;
        geometry.block_size = sd_cardinfo.card_blocksize;
        geometry.sector_count = sd_cardinfo.card_capacity / sd_cardinfo.card_blocksize;
        *(struct rt_device_blk_geometry*)arg = geometry;
    } break;
    case RT_DEVICE_CTRL_BLK_SYNC: {
        //TODO
    } break;
    case RT_DEVICE_CTRL_BLK_ERASE: {
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
    .sd_write = sd_write,
    .sd_read = sd_read,
    .sd_control = sd_control
};

rt_err_t drv_sdio_init(void)
{
    sd0_dev.ops = &dev_ops;

    RT_TRY(rt_mutex_init(&sd_lock, "sd_lock", RT_IPC_FLAG_PRIO));

    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &sd_cardinfo);
}
