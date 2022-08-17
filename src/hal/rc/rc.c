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

#include <firmament.h>

#include "hal/rc/rc.h"

static rt_err_t hal_rc_init(struct rt_device* dev)
{
    rt_err_t ret = RT_EOK;
    rc_dev_t rc;

    RT_ASSERT(dev != RT_NULL);

    rc = (rc_dev_t)dev;

    /* apply configuration */
    if (rc->ops->rc_configure) {
        ret = rc->ops->rc_configure(rc, &rc->config);
    }

    return ret;
}

static rt_size_t hal_rc_read(struct rt_device* dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rc_dev_t rc;
    uint16_t read_mask = (uint16_t)pos;
    uint16_t channel_mask;
    int16_t* rc_channel = (int16_t*)buffer;
    rt_size_t rb = 0;
    uint8_t n = 0;

    RT_ASSERT(dev != RT_NULL);

    rc = (rc_dev_t)dev;

    /* apply channel mask */
    channel_mask = (1 << rc->config.channel_num) - 1;
    read_mask &= channel_mask;

    if (rc->ops->rc_read && buffer) {
        rb = rc->ops->rc_read(rc, read_mask, buffer);
    }

    for (int i = 0; i < rc->config.channel_num; i++) {
        if (read_mask & (1 << i)) {
            /* saturate read value */
            if (rc_channel[i] > rc->config.rc_max_value) {
                rc_channel[i] = rc->config.rc_max_value;
            }
            if (rc_channel[i] < rc->config.rc_min_value) {
                rc_channel[i] = rc->config.rc_min_value;
            }
            /* check if we have saturated all value */
            if (++n >= rb / 2) {
                break;
            }
        }
    }

    return rb;
}

static rt_err_t hal_rc_control(struct rt_device* dev, int cmd, void* args)
{
    rc_dev_t rc;

    RT_ASSERT(dev != RT_NULL);

    rc = (rc_dev_t)dev;

    switch (cmd) {
    case RT_DEVICE_CTRL_CONFIG:
        if (args) {
            struct rc_configure* pconfig = (struct rc_configure*)args;
            /* set rc configure */
            rc->config = *pconfig;

            /* if device is opened before, re-configure it */
            if (rc->parent.flag & RT_DEVICE_FLAG_ACTIVATED && rc->ops->rc_configure) {
                rc->ops->rc_configure(rc, pconfig);
            }
        }
        break;

    default:
        if (rc->ops->rc_control) {
            return rc->ops->rc_control(rc, cmd, args);
        }
        break;
    }

    return RT_EOK;
}

rt_err_t hal_rc_rx_ind(rc_dev_t rc, rt_size_t size)
{
    rt_device_t device = &(rc->parent);

    if (device->rx_indicate) {
        return device->rx_indicate(device, size);
    }

    return RT_EOK;
}

rt_err_t hal_rc_register(rc_dev_t rc, const char* name, rt_uint32_t flag, void* data)
{
    struct rt_device* device;

    RT_ASSERT(rc != RT_NULL);

    device = &(rc->parent);

    device->type = RT_Device_Class_Miscellaneous;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_rc_init;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = hal_rc_read;
    device->write = RT_NULL;
    device->control = hal_rc_control;

    device->user_data = data;

    /* register pin device */
    return rt_device_register(device, name, flag);
}
