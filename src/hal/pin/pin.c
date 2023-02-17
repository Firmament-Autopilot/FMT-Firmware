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

#include "hal/pin/pin.h"

static rt_size_t hal_pin_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    struct device_pin_status* status;
    pin_dev_t pin = (struct pin_device*)dev;

    RT_ASSERT(dev != RT_NULL);

    status = (struct device_pin_status*)buffer;

    if (status == RT_NULL || size != sizeof(*status))
        return 0;

    status->status = pin->ops->pin_read(pin, status->pin);
    return size;
}

static rt_size_t hal_pin_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    struct device_pin_status* status;
    pin_dev_t pin = (struct pin_device*)dev;

    RT_ASSERT(dev != RT_NULL);

    status = (struct device_pin_status*)buffer;

    if (status == RT_NULL || size != sizeof(*status))
        return 0;

    pin->ops->pin_write(pin, (rt_base_t)status->pin, (rt_base_t)status->status);

    return size;
}

static rt_err_t hal_pin_control(rt_device_t dev, int cmd, void* args)
{
    struct device_pin_mode* mode;
    pin_dev_t pin = (struct pin_device*)dev;

    RT_ASSERT(dev != RT_NULL);

    mode = (struct device_pin_mode*)args;

    if (mode == RT_NULL)
        return -RT_ERROR;

    pin->ops->pin_mode(pin, (rt_base_t)mode->pin, (rt_base_t)mode->mode, (rt_base_t)mode->otype);

    return RT_EOK;
}

/**
 * @brief register a pin device
 * 
 * @param pin pin device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_pin_register(pin_dev_t pin, const char* name, rt_uint32_t flag, void* data)
{
    struct rt_device* device;
    RT_ASSERT(pin != RT_NULL);

    device = &(pin->parent);

    device->type = RT_Device_Class_Miscellaneous;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = RT_NULL;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_pin_read;
    device->write = hal_pin_write;
    device->control = hal_pin_control;

    device->user_data = data;

    /* register device to system */
    return rt_device_register(device, name, flag);
}
