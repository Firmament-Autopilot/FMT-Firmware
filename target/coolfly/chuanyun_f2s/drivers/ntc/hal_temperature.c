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

#include "hal_temperature.h"
#include "board.h"
#include <firmament.h>

_EXT_DTCM1
static rt_size_t hal_temperature_read(struct rt_device* dev,
                                      rt_off_t          pos,
                                      void*             buffer,
                                      rt_size_t         size)
{
    rt_size_t         rb = 0;
    temperature_dev_t temperature;

    RT_ASSERT(dev != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    temperature = (temperature_dev_t)dev;

    if (temperature->ops->temperature_read) {
        rb = temperature->ops->temperature_read(temperature, buffer);
    }

    return rb;
}

_EXT_DTCM1
rt_err_t hal_temperature_register(temperature_dev_t temperature, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t          ret;
    struct rt_device* device;

    RT_ASSERT(temperature != RT_NULL);

    device = &(temperature->parent);

    device->type        = RT_Device_Class_SPIDevice;
    device->ref_count   = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init      = RT_NULL;
    device->open      = RT_NULL;
    device->close     = RT_NULL;
    device->read      = hal_temperature_read;
    device->write     = RT_NULL;
    device->control   = RT_NULL;
    device->user_data = data;

    /* register a character device */
    ret = rt_device_register(device, name, flag);

    return ret;
}