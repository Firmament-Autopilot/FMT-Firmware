/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "hal/rtc/rtc.h"

static rt_err_t hal_rtc_init(struct rt_device* dev)
{
    rt_err_t ret = RT_EOK;
    rtc_dev_t rtc;

    RT_ASSERT(dev != RT_NULL);

    rtc = (rtc_dev_t)dev;

    /* apply init function */
    if (rtc->ops->init) {
        ret = rtc->ops->init(rtc);
    }

    return ret;
}

static rt_size_t hal_rtc_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rtc_dev_t rtc = (rtc_dev_t)dev;

    if (dev == NULL || buffer == NULL)
        return 0;

    if (rtc->ops->read) {
        if (rtc->ops->read(rtc, buffer) != RT_EOK)
            return 0;
    }

    return size;
}

static rt_size_t hal_rtc_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    rtc_dev_t rtc = (rtc_dev_t)dev;

    if (dev == NULL || buffer == NULL)
        return 0;

    if (rtc->ops->write) {
        if (rtc->ops->write(rtc, buffer) != RT_EOK)
            return 0;
    }

    return size;
}

/**
 * @brief register a rtc device
 *
 * @param systick rtc device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_rtc_register(rtc_dev_t rtc, const char* name, rt_uint32_t flag, void* data)
{
    struct rt_device* device;

    RT_ASSERT(rtc != RT_NULL);

    device = &(rtc->parent);

    device->type = RT_Device_Class_Timer;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_rtc_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_rtc_read;
    device->write = hal_rtc_write;
    device->control = RT_NULL;

    device->user_data = data;

    /* register device to system */
    return rt_device_register(device, name, flag);
}
