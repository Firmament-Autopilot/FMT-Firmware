/******************************************************************************
 * Copyright 2016-2023 The Firmament Authors. All Rights Reserved.
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

static rt_err_t hal_actuator_init(struct rt_device* dev)
{
    actuator_dev_t act = (actuator_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    act->suspend = RT_FALSE;

    /* apply default configuration */
    if (act->ops->act_config) {
        return act->ops->act_config(act, &act->config);
    }

    return RT_EOK;
}

static rt_err_t hal_actuator_control(struct rt_device* dev, int cmd, void* args)
{
    actuator_dev_t act = (actuator_dev_t)dev;

    RT_ASSERT(dev != RT_NULL);

    switch (cmd) {
    case RT_DEVICE_CTRL_SUSPEND:
        act->suspend = RT_TRUE;
        break;

    case RT_DEVICE_CTRL_RESUME:
        act->suspend = RT_FALSE;
        break;

    default:
        if (act->ops->act_control) {
            return act->ops->act_control(act, cmd, args);
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
    actuator_dev_t act = (actuator_dev_t)dev;
    rt_size_t rb = 0;

    RT_ASSERT(dev != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    if (pos == 0) {
        return 0;
    }

    /* apply channel mask */
    pos = pos & act->chan_mask;

    if (act->ops->act_read) {
        rb = act->ops->act_read(act, pos, buffer, size);
    }

    return rb;
}

static rt_size_t hal_actuator_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    actuator_dev_t act = (actuator_dev_t)dev;
    rt_size_t wb = 0;
    uint16_t chan_val[16];
    uint8_t index = 0;
    uint16_t* val_ptr = (uint16_t*)buffer;

    RT_ASSERT(dev != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    if (act->suspend == RT_TRUE || pos == 0) {
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

    if (act->ops->act_write) {
        wb = act->ops->act_write(act, pos, chan_val, size);
    }

    return wb;
}

/**
 * @brief register an actuator device
 * 
 * @param dev actuator device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
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

    /* register device to system */
    return rt_device_register(device, name, flag);
}
