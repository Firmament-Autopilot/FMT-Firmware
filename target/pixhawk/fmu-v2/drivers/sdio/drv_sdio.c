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

#include "diskio.h"
#include "sdio.h"

#define SECTOR_SIZE 512

static struct rt_device _sd_dev;

rt_err_t _sd_dev_init(rt_device_t dev)
{
    rt_err_t err;

    err = (SD_Init() == SD_OK) ? RT_EOK : RT_ERROR;

    return err;
}

rt_err_t _sd_dev_open(rt_device_t dev, rt_uint16_t oflag)
{
    return RT_EOK;
}

rt_err_t _sd_dev_close(rt_device_t dev)
{
    return RT_EOK;
}

rt_size_t _sd_dev_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    SD_Error Status;
    uint32_t sector = pos;
    rt_size_t r_count = 0;

    Status = SD_ReadDisk(buffer, sector, size);

    if (Status == SD_OK) {
        r_count = size;
    }

    return r_count;
}

rt_size_t _sd_dev_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    SD_Error Status;
    uint32_t sector = pos;
    rt_size_t w_count = 0;

    Status = SD_WriteDisk(buffer, sector, size);

    if (Status == SD_OK) {
        w_count = size;
    }

    return w_count;
}

rt_err_t _sd_dev_control(rt_device_t dev, int cmd, void* args)
{
    switch (cmd) {
    case RT_DEVICE_CTRL_BLK_GETGEOME: {
        struct rt_device_blk_geometry geometry;
        SD_CardInfo SDCardInfo;

        geometry.bytes_per_sector = SECTOR_SIZE;

        if (SD_GetCardInfo(&SDCardInfo) == SD_OK) {
            if (SDCardInfo.CardType == SDIO_HIGH_CAPACITY_SD_CARD) {
                geometry.sector_count = (SDCardInfo.SD_csd.DeviceSize + 1) * 1024;
            } else {
                geometry.sector_count = SDCardInfo.CardCapacity / SDCardInfo.CardBlockSize;
            }

            geometry.block_size = SDCardInfo.CardBlockSize;

            if (args) {
                *(struct rt_device_blk_geometry*)args = geometry;
            } else {
                return RT_EINVAL;
            }
        } else {
            return RT_ERROR;
        }
    } break;

    case RT_DEVICE_CTRL_BLK_SYNC: {
        if (SD_GetStatus() != SD_TRANSFER_OK) {
            return RT_ERROR;
        }
    } break;

    case RT_DEVICE_CTRL_BLK_ERASE: {
        return RT_ERROR; /* need to support */
    } break;

    default: {
        rt_kprintf("unknown sd control cmd:%d\n", cmd);
    } break;
    }

    return RT_EOK;
}

rt_err_t drv_sdio_init(const char* device_name)
{
    rt_err_t res = RT_EOK;
    ;

    /* set device type */
    _sd_dev.type = RT_Device_Class_Block;
    _sd_dev.init = _sd_dev_init;
    _sd_dev.open = _sd_dev_open;
    _sd_dev.close = _sd_dev_close;
    _sd_dev.read = _sd_dev_read;
    _sd_dev.write = _sd_dev_write;
    _sd_dev.control = _sd_dev_control;

    /* register to device manager */
    /* standalone device means it can be opened by only one host */
    res |= rt_device_register(&_sd_dev, "sd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_REMOVABLE | RT_DEVICE_FLAG_STANDALONE);

    return res;
}