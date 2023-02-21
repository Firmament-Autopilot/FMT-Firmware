/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "hal/accel/accel.h"

static rt_err_t hal_accel_init(struct rt_device* dev)
{
    rt_err_t ret = RT_EOK;
    accel_dev_t accel;

    RT_ASSERT(dev != RT_NULL);

    accel = (accel_dev_t)dev;

    /* invoke driver configu function */
    if (accel->ops->accel_config) {
        ret = accel->ops->accel_config(accel, &accel->config);
    }

    return ret;
}

static rt_size_t hal_accel_read(struct rt_device* dev,
                                rt_off_t pos,
                                void* buffer,
                                rt_size_t size)
{
    rt_size_t rb = 0;
    accel_dev_t accel;

    RT_ASSERT(dev != RT_NULL);

    accel = (accel_dev_t)dev;

    /* invoke driver read function to read data */
    if (accel->ops->accel_read && size) {
        rb = accel->ops->accel_read(accel, pos, buffer, size);
    }

    return rb;
}

static rt_err_t hal_accel_control(struct rt_device* dev,
                                  int cmd,
                                  void* args)
{
    rt_err_t ret = RT_EOK;
    accel_dev_t accel;

    RT_ASSERT(dev != RT_NULL);

    accel = (accel_dev_t)dev;

    /* invoke driver control function to handle command */
    if (accel->ops->accel_control) {
        ret = accel->ops->accel_control(accel, cmd, args);
    }

    return ret;
}

/**
 * @brief register an accel device
 * 
 * @param accel accel device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_accel_register(accel_dev_t accel, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;
    struct rt_device* device;

    RT_ASSERT(accel != RT_NULL);

    device = &(accel->parent);

    device->type = (accel->bus_type == ACCEL_SPI_BUS_TYPE) ? RT_Device_Class_SPIDevice : RT_Device_Class_I2CBUS;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_accel_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_accel_read;
    device->write = RT_NULL;
    device->control = hal_accel_control;
    device->user_data = data;

    /* register device to system */
    ret = rt_device_register(device, name, flag);

    return ret;
}