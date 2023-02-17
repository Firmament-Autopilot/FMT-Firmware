/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#define SECTOR_SIZE 512

/* local sector buffer, 4B alignment */
static uint32_t sector_buffer[SECTOR_SIZE / 4];

static rt_err_t hal_sd_init(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;
    sd_dev_t sd;

    RT_ASSERT(dev != RT_NULL);

    sd = (sd_dev_t)dev;

    /* init low-level device */
    if (sd->ops->sd_init) {
        ret = sd->ops->sd_init(sd);
    }

    return ret;
}

static rt_size_t hal_sd_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    uint32_t sector = pos;
    uint32_t count = size;
    uint8_t* rp = (rt_uint8_t*)buffer;
    sd_dev_t sd;
    int i;

    RT_ASSERT(dev != RT_NULL);

    sd = (sd_dev_t)dev;

    /* check if the buffer address is 4B allignment since DMA is configured to transfer word,
    make sure the buffer is 4B allignment to improve the transfer speed */
    if ((uint32_t)buffer & 0x03) {
        for (i = 0; i < count; i++) {
            /* read 1 sector */
            if (sd->ops->sd_read(sd, (rt_uint8_t*)sector_buffer, sector + i, 1) != RT_EOK) {
                if (dev->rx_indicate) {
                    dev->rx_indicate(dev, i);
                }
                return i;
            }
            /* copy data to user buffer */
            rt_memcpy(rp, sector_buffer, SECTOR_SIZE);
            rp += SECTOR_SIZE;
        }
    } else {
        /* read multi sectors */
        if (sd->ops->sd_read(sd, rp, sector, count) != RT_EOK) {
            return 0;
        }
    }

    if (dev->rx_indicate) {
        dev->rx_indicate(dev, size);
    }

    return size;
}

static rt_size_t hal_sd_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    uint32_t sector = pos;
    uint32_t count = size;
    uint8_t* wp = (rt_uint8_t*)buffer;
    sd_dev_t sd;
    int i;

    RT_ASSERT(dev != RT_NULL);

    sd = (sd_dev_t)dev;

    /* check if the buffer address is 4B allignment since DMA is configured to transfer word,
    make sure the buffer is 4B allignment to improve the transfer speed */
    if ((uint32_t)buffer & 0x03) {
        for (i = 0; i < count; i++) {
            /* copy data to a 4B alignment buffer */
            rt_memcpy(sector_buffer, wp, SECTOR_SIZE);
            wp += SECTOR_SIZE;
            /* write 1 sector */
            if (sd->ops->sd_write(sd, (uint8_t*)sector_buffer, sector + i, 1) != RT_EOK) {
                return i;
            }
        }
    } else {
        /* write multi sectors */
        if (sd->ops->sd_write(sd, wp, sector, count) != RT_EOK) {
            return 0;
        }
    }

    if (dev->tx_complete) {
        /* inform upper layer the write is completed */
        dev->tx_complete(dev, NULL);
    }

    return size;
}

rt_err_t hal_sd_control(rt_device_t dev, int cmd, void* args)
{
    rt_err_t ret = RT_EOK;
    sd_dev_t sd;

    RT_ASSERT(dev != RT_NULL);

    sd = (sd_dev_t)dev;

    switch (cmd) {
    default:
        if (sd->ops->sd_control) {
            ret = sd->ops->sd_control(sd, cmd, args);
        }
        break;
    }

    return ret;
}

/**
 * @brief register a sd device
 * 
 * @param sd sd device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_sd_register(sd_dev_t sd, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;
    struct rt_device* device;

    RT_ASSERT(sd != RT_NULL);

    device = &(sd->parent);

    device->type = RT_Device_Class_SDIO;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_sd_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_sd_read;
    device->write = hal_sd_write;
    device->control = hal_sd_control;
    device->user_data = data;

    /* register device to system */
    ret = rt_device_register(device, name, flag);

    return ret;
}
