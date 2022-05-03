/******************************************************************************
 * Copyright 2016-2021 The Firmament Authors. All Rights Reserved.
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

#include "hal/actuator/actuator.h"

static rt_bool_t dev_suspend;

static rt_err_t hal_actuator_init(struct rt_device* dev)
{
    RT_ASSERT(dev != RT_NULL);

    actuator_dev_t act = (actuator_dev_t)dev;

    /* apply default configuration */
    if (act->ops->dev_config) {
        return act->ops->dev_config(act, &act->config);
    }

    return RT_EOK;
}

static rt_err_t hal_actuator_control(struct rt_device* dev, int cmd, void* args)
{
    RT_ASSERT(dev != RT_NULL);

    actuator_dev_t act = (actuator_dev_t)dev;

    switch (cmd) {
    case RT_DEVICE_CTRL_SUSPEND:
        dev_suspend = RT_TRUE;
        break;

    case RT_DEVICE_CTRL_RESUME:
        dev_suspend = RT_FALSE;
        break;

    default:
        if (act->ops->dev_control) {
            return act->ops->dev_control(act, cmd, args);
        }
    }

    return RT_EOK;
}

static rt_err_t hal_actuator_open(rt_device_t dev, rt_uint16_t oflag)
{
    return hal_actuator_control(dev, ACT_CMD_CHANNEL_ENABLE, NULL);
}

static rt_err_t hal_actuator_close(rt_device_t dev)
{
    return hal_actuator_control(dev, ACT_CMD_CHANNEL_DISABLE, NULL);
}

static rt_size_t hal_actuator_read(struct rt_device* dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    actuator_dev_t act = (actuator_dev_t)dev;
    rt_size_t rb = 0;

    if (buffer == NULL || pos == 0) {
        return 0;
    }

    /* apply channel mask */
    pos = pos & act->chan_mask;

    if (act->ops->dev_read) {
        rb = act->ops->dev_read(act, pos, buffer, size);
    }

    return rb;
}

static rt_size_t hal_actuator_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    actuator_dev_t act = (actuator_dev_t)dev;
    rt_size_t wb = 0;
    uint16_t chan_val[16];
    uint8_t index = 0;
    uint16_t* val_ptr = (uint16_t*)buffer;

    if (dev_suspend == RT_TRUE || buffer == NULL || pos == 0) {
        return 0;
    }

    /* apply channel mask */
    pos = pos & act->chan_mask;
    /* saturate channel value */
    for (uint8_t i = 0; i < 16; i++) {
        if (pos & (1 << i)) {
            chan_val[index] = constrain_uint16(val_ptr[index], act->range[0], act->range[1]);
            index++;
        }
    }

    if (act->ops->dev_write) {
        wb = act->ops->dev_write(act, pos, chan_val, size);
    }

    return wb;
}

rt_err_t hal_actuator_register(actuator_dev_t dev, const char* name, rt_uint32_t flag, void* data)
{
    RT_ASSERT(dev != RT_NULL);

    struct rt_device* device;

    device = &(dev->parent);

    device->type = RT_Device_Class_Miscellaneous;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_actuator_init;
    device->open = hal_actuator_open;
    device->close = hal_actuator_close;
    device->read = hal_actuator_read;
    device->write = hal_actuator_write;
    device->control = hal_actuator_control;
    device->user_data = data;

    /* register device */
    return rt_device_register(device, name, flag);
}
