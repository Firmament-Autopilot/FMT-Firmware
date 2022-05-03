/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "hal/adc/adc.h"

#define ADC_TIMEOUT_MS 5

rt_err_t hal_adc_open(rt_device_t dev, rt_uint16_t oflag)
{
    RT_ASSERT(dev != NULL);

    adc_dev_t adc_dev = (adc_dev_t)dev;

    if (dev->ref_count == 0) {
        adc_dev->ops->enable(adc_dev, ADC_CMD_ENABLE);
    }

    return RT_EOK;
}

rt_err_t hal_adc_close(rt_device_t dev)
{
    RT_ASSERT(dev != NULL);

    adc_dev_t adc_dev = (adc_dev_t)dev;

    if (dev->ref_count == 0) {
        adc_dev->ops->enable(adc_dev, ADC_CMD_DISABLE);
    }

    return RT_EOK;
}

rt_size_t hal_adc_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    RT_ASSERT(dev != NULL);

    rt_size_t res = 0;
    adc_dev_t adc_dev = (adc_dev_t)dev;

    if (rt_mutex_take(adc_dev->lock, TICKS_FROM_MS(ADC_TIMEOUT_MS)) != RT_EOK) {
        return 0;
    }

    if (adc_dev->ops->measure(adc_dev, pos, buffer) == RT_EOK) {
        res = size;
    }

    rt_mutex_release(adc_dev->lock);

    return res;
}

rt_err_t hal_adc_register(adc_dev_t adc_dev, const char* name, rt_uint32_t flag, void* data)
{
    rt_err_t ret;
    struct rt_device* device;

    RT_ASSERT(adc_dev != RT_NULL);

    device = &(adc_dev->parent);

    device->type = RT_Device_Class_Char;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = RT_NULL;
    device->open = hal_adc_open;
    device->close = hal_adc_close;
    device->read = hal_adc_read;
    device->write = RT_NULL;
    device->control = RT_NULL;
    device->user_data = data;

    adc_dev->lock = rt_mutex_create(name, RT_IPC_FLAG_FIFO);
    RT_ASSERT(adc_dev->lock != NULL);

    /* register a character device */
    ret = rt_device_register(device, name, flag);

    return ret;
}