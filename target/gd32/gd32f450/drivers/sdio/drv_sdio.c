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

#include "hal/sd/sd.h"
#include "sdcard.h"

#include <string.h>

static struct sd_device sd0_dev;
static sd_card_info_struct sd_cardinfo; /* information of SD card */

/*!
    \brief      this function handles SDIO interrupt request
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SDIO_IRQHandler(void)
{
    sd_interrupts_process();
}

static void nvic_config(void)
{
    nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
    nvic_irq_enable(SDIO_IRQn, 0, 0);
}

static rt_err_t init(sd_dev_t sd)
{
    sd_error_enum status = SD_OK;
    uint32_t cardstate = 0;

    nvic_config();

    status = sd_init();

    if (SD_OK == status) {
        status = sd_card_information_get(&sd_cardinfo);
    }
    if (SD_OK == status) {
        status = sd_card_select_deselect(sd_cardinfo.card_rca);
    }
    status = sd_cardstatus_get(&cardstate);
    if (cardstate & 0x02000000) {
        printf("\r\n the card is locked!");
        return RT_ERROR;
    }
    if ((SD_OK == status) && (!(cardstate & 0x02000000))) {
        /* set bus mode */
        status = sd_bus_mode_config(SDIO_BUSMODE_4BIT);
        // status = sd_bus_mode_config(SDIO_BUSMODE_1BIT);
    }
    if (SD_OK == status) {
        /* set data transfer mode */
        status = sd_transfer_mode_config(SD_DMA_MODE);
        // status = sd_transfer_mode_config(SD_POLLING_MODE);
    }

    return status == SD_OK ? RT_EOK : RT_ERROR;
}

static rt_err_t write_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    if (count == 0) {
        return RT_EOK;
    }

    if (count > 1) {
        if (sd_multiblocks_write((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize, count) != SD_OK) {
            return RT_ERROR;
        }
    } else {
        if (sd_block_write((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize) != SD_OK) {
            return RT_ERROR;
        }
    }

    return err;
}

static rt_err_t read_disk(sd_dev_t sd, rt_uint8_t* buffer, rt_uint32_t sector, rt_uint32_t count)
{
    rt_err_t err = RT_EOK;

    if (count == 0) {
        return RT_EOK;
    }

    if (count > 1) {
        if (sd_multiblocks_read((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize, count) != SD_OK) {
            return RT_ERROR;
        }
    } else {
        if (sd_block_read((uint32_t*)buffer, sector * sd_cardinfo.card_blocksize, sd_cardinfo.card_blocksize) != SD_OK) {
            return RT_ERROR;
        }
    }

    return err;
}

static rt_err_t io_control(sd_dev_t sd, int cmd, void* arg)
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
    .init = init,
    .write_disk = write_disk,
    .read_disk = read_disk,
    .io_control = io_control
};

rt_err_t drv_sdio_init(void)
{
    sd0_dev.ops = &dev_ops;

    return hal_sd_register(&sd0_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE, &sd_cardinfo);
}
