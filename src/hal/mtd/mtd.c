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

#include "hal/mtd/mtd.h"

static rt_err_t hal_mtd_init(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;
    mtd_dev_t mtd = (mtd_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    /* init low-level device, init can be NULL */
    if (mtd->ops->init) {
        ret = mtd->ops->init(mtd);
    }

    return ret;
}

static rt_size_t hal_mtd_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rt_uint32_t sector = pos;
    rt_uint32_t count = size;
    mtd_dev_t mtd = (mtd_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    if (mtd->ops->read == RT_NULL) {
        return 0;
    }

    if (mtd->ops->read(mtd, buffer, sector, count) != RT_EOK) {
        return 0;
    }

    if (dev->rx_indicate) {
        dev->rx_indicate(dev, size);
    }

    return size;
}

static rt_size_t hal_mtd_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    rt_uint32_t sector = pos;
    rt_uint32_t count = size;
    mtd_dev_t mtd = (mtd_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    /* earase ops can be NULL as some device doesn't need erase before write */
    if (mtd->ops->write == RT_NULL) {
        return 0;
    }

    if (mtd->ops->erase != RT_NULL) {
        if (mtd->ops->erase(mtd, sector, count) != RT_EOK) {
            return 0;
        }
    }

    if (mtd->ops->write(mtd, buffer, sector, count) != RT_EOK) {
        return 0;
    }

    if (dev->tx_complete) {
        /* inform upper layer the write is completed */
        dev->tx_complete(dev, NULL);
    }

    return size;
}

rt_err_t hal_mtd_control(rt_device_t dev, int cmd, void* args)
{
    rt_err_t ret = RT_EOK;
    mtd_dev_t mtd = (mtd_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    switch (cmd) {
    default:
        /* control ops can be NULL */
        if (mtd->ops->control) {
            ret = mtd->ops->control(mtd, cmd, args);
        }
        break;
    }

    return ret;
}

/**
 * @brief register a mtd device
 * 
 * @param mtd mtd device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_mtd_register(mtd_dev_t mtd, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;
    struct rt_device* device;

    RT_ASSERT(mtd != RT_NULL);

    device = &(mtd->parent);

    device->type = RT_Device_Class_Block;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_mtd_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_mtd_read;
    device->write = hal_mtd_write;
    device->control = hal_mtd_control;
    device->user_data = data;

    /* register device to system */
    ret = rt_device_register(device, name, flag);

    return ret;
}
