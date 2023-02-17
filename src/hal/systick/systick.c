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

#include "hal/systick/systick.h"

rt_size_t systick_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    systick_dev_t systick = (systick_dev_t)dev;

    if (pos == SYSTICK_RD_TIME_US) {
        *(uint32_t*)buffer = systick->ops->systick_read(systick);
        return sizeof(uint32_t);
    }

    return 0;
}

static rt_err_t systick_control(rt_device_t dev, int cmd, void* args)
{
    systick_dev_t systick;

    RT_ASSERT(dev != RT_NULL);

    systick = (systick_dev_t)dev;

    if (cmd == SYSTICK_CMD_SET_FREQUENCY) {
        if (systick->ops->systick_configure) {
            struct systick_configure config;
            config.tick_freq = *(rt_uint16_t*)args;

            systick->ops->systick_configure(systick, &config);
        }
    }

    return RT_EOK;
}

/**
 * @brief systick isr handler
 * 
 * @param systick systick device
 */
void hal_systick_isr(systick_dev_t systick)
{
    if (systick->systick_isr_cb) {
        systick->systick_isr_cb();
    }
}

/**
 * @brief register a systick device
 * 
 * @param systick systick device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_systick_register(systick_dev_t systick, const char* name, rt_uint32_t flag, void* data)
{
    struct rt_device* device;

    RT_ASSERT(systick != RT_NULL);

    device = &(systick->parent);

    device->type = RT_Device_Class_Timer;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = RT_NULL;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = systick_read;
    device->write = RT_NULL;
    device->control = systick_control;

    device->user_data = data;

    /* register device to system */
    return rt_device_register(device, name, flag);
}
