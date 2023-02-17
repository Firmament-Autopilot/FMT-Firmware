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

#include "hal/mag/mag.h"

static rt_err_t hal_mag_init(struct rt_device* dev)
{
    rt_err_t ret = RT_EOK;
    mag_dev_t mag;

    RT_ASSERT(dev != RT_NULL);

    mag = (mag_dev_t)dev;

    /* apply configuration */
    if (mag->ops->mag_config) {
        ret = mag->ops->mag_config(mag, &mag->config);
    }

    return ret;
}

static rt_size_t hal_mag_read(struct rt_device* dev,
                              rt_off_t pos,
                              void* buffer,
                              rt_size_t size)
{
    rt_size_t rb = 0;
    mag_dev_t mag;

    RT_ASSERT(dev != RT_NULL);

    mag = (mag_dev_t)dev;

    if (mag->ops->mag_read && size) {
        rb = mag->ops->mag_read(mag, pos, buffer, size);
    }

    return rb;
}

static rt_err_t hal_mag_control(struct rt_device* dev,
                                int cmd,
                                void* args)
{
    rt_err_t ret = RT_EOK;
    mag_dev_t mag;

    RT_ASSERT(dev != RT_NULL);

    mag = (mag_dev_t)dev;

    if (mag->ops->mag_control) {
        ret = mag->ops->mag_control(mag, cmd, args);
    }

    return ret;
}

/**
 * @brief register a mag device
 * 
 * @param mag mag device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_mag_register(mag_dev_t mag, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;
    struct rt_device* device;

    RT_ASSERT(mag != RT_NULL);

    device = &(mag->parent);

    device->type = (mag->bus_type == MAG_SPI_BUS_TYPE) ? RT_Device_Class_SPIDevice : RT_Device_Class_I2CBUS;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_mag_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_mag_read;
    device->write = RT_NULL;
    device->control = hal_mag_control;
    device->user_data = data;

    /* register device to system */
    ret = rt_device_register(device, name, flag);

    return ret;
}