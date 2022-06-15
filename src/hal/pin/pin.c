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

#include "hal/pin/pin.h"
#include <firmament.h>

static rt_size_t hal_pin_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    struct device_pin_status* status;
    struct pin_device* pin = (struct pin_device*)dev;

    /* check parameters */
    RT_ASSERT(pin != RT_NULL);

    status = (struct device_pin_status*)buffer;

    if (status == RT_NULL || size != sizeof(*status))
        return 0;

    status->status = pin->ops->pin_read(dev, status->pin);
    return size;
}

static rt_size_t hal_pin_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    struct device_pin_status* status;
    struct pin_device* pin = (struct pin_device*)dev;

    /* check parameters */
    RT_ASSERT(pin != RT_NULL);

    status = (struct device_pin_status*)buffer;

    if (status == RT_NULL || size != sizeof(*status))
        return 0;

    pin->ops->pin_write(dev, (rt_base_t)status->pin, (rt_base_t)status->status);

    return size;
}

static rt_err_t hal_pin_control(rt_device_t dev, int cmd, void* args)
{
    struct device_pin_mode* mode;
    struct pin_device* pin = (struct pin_device*)dev;

    /* check parameters */
    RT_ASSERT(pin != RT_NULL);

    mode = (struct device_pin_mode*)args;

    if (mode == RT_NULL)
        return -RT_ERROR;

    pin->ops->pin_mode(dev, (rt_base_t)mode->pin, (rt_base_t)mode->mode, (rt_base_t)mode->otype);

    return RT_EOK;
}

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

    /* register pin device */
    return rt_device_register(device, name, flag);
}
