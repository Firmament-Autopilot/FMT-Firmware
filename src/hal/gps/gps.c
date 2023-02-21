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

#include "hal/gps/gps.h"

static rt_err_t hal_gps_init(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;
    gps_dev_t gps_dev;

    RT_ASSERT(dev != RT_NULL);

    gps_dev = (gps_dev_t)dev;

    if (gps_dev->ops->gps_control) {
        ret = gps_dev->ops->gps_control(gps_dev, GPS_CMD_INIT, NULL);
    }

    return ret;
}

static rt_err_t hal_gps_open(rt_device_t dev, rt_uint16_t oflag)
{
    rt_err_t ret = RT_EOK;
    gps_dev_t gps_dev;

    RT_ASSERT(dev != RT_NULL);

    gps_dev = (gps_dev_t)dev;

    if (gps_dev->ops->gps_control) {
        ret = gps_dev->ops->gps_control(gps_dev, GPS_CMD_OPEN, &oflag);
    }

    return ret;
}

static rt_err_t hal_gps_close(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;
    gps_dev_t gps_dev;

    RT_ASSERT(dev != RT_NULL);

    gps_dev = (gps_dev_t)dev;

    if (gps_dev->ops->gps_control) {
        ret = gps_dev->ops->gps_control(gps_dev, GPS_CMD_CLOSE, NULL);
    }

    return ret;
}

static rt_size_t hal_gps_read(struct rt_device* dev,
                              rt_off_t pos,
                              void* buffer,
                              rt_size_t size)
{
    rt_size_t rb = 0;
    gps_dev_t gps_dev;

    RT_ASSERT(dev != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    gps_dev = (gps_dev_t)dev;

    if (pos == GPS_READ_REPORT && gps_dev->ops->gps_read) {
        rb = gps_dev->ops->gps_read(gps_dev, buffer);
    }

    return rb;
}

static rt_err_t hal_gps_control(struct rt_device* dev,
                                int cmd,
                                void* args)
{
    rt_err_t ret = RT_EOK;
    gps_dev_t gps_dev;

    RT_ASSERT(dev != RT_NULL);

    gps_dev = (gps_dev_t)dev;

    if (gps_dev->ops->gps_control) {
        ret = gps_dev->ops->gps_control(gps_dev, cmd, args);
    }

    return ret;
}

/**
 * @brief register a gps device
 * 
 * @param gps_dev gps device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_gps_register(gps_dev_t gps_dev, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;
    struct rt_device* device;

    RT_ASSERT(gps_dev != RT_NULL);

    device = &(gps_dev->parent);

    device->type = RT_Device_Class_Char;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_gps_init;
    device->open = hal_gps_open;
    device->close = hal_gps_close;
    device->read = hal_gps_read;
    device->write = RT_NULL;
    device->control = hal_gps_control;
    device->user_data = data;

    /* register device to system */
    ret = rt_device_register(device, name, flag);

    return ret;
}