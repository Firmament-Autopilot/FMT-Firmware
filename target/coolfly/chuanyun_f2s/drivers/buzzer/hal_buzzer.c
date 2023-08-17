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

#include "hal_buzzer.h"
#include <firmament.h>

// #define buzzer_dbg(fmt, ...) console_printf(fmt, ##__VA_ARGS__)
#define buzzer_dbg(fmt, ...)

static rt_bool_t dev_suspend;

static rt_err_t hal_buzzer_init(struct rt_device* dev)
{
    RT_ASSERT(dev != RT_NULL);

    buzzer_dev_t buz_dev = (buzzer_dev_t)dev;

    /* apply default configuration */
    if (buz_dev->ops->dev_config) {
        return buz_dev->ops->dev_config(buz_dev, &buz_dev->config);
    }

    return RT_EOK;
}

static rt_err_t hal_buzzer_control(struct rt_device* dev, int cmd, void* args)
{
    RT_ASSERT(dev != RT_NULL);

    buzzer_dev_t buz_dev = (buzzer_dev_t)dev;

    switch (cmd) {
    case RT_DEVICE_CTRL_SUSPEND:
        dev_suspend = RT_TRUE;
        break;

    case RT_DEVICE_CTRL_RESUME:
        dev_suspend = RT_FALSE;
        break;

    default:
        if (buz_dev->ops->dev_control) {
            return buz_dev->ops->dev_control(buz_dev, cmd, args);
        }
    }

    return RT_EOK;
}

static rt_err_t hal_buzzer_open(rt_device_t dev, rt_uint16_t oflag)
{
    return RT_EOK;
}

static rt_err_t hal_buzzer_close(rt_device_t dev)
{
    return hal_buzzer_control(dev, BUZZER_CMD_CHANNEL_DISABLE, NULL);
}

static rt_size_t hal_buzzer_read(struct rt_device* dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    buzzer_dev_t buz_dev = (buzzer_dev_t)dev;
    rt_size_t    rb      = 0;

    if (buffer == NULL || pos == 0) {
        return 0;
    }

    /* apply channel mask */
    pos = pos & buz_dev->chan_mask;

    if (buz_dev->ops->dev_read) {
        rb = buz_dev->ops->dev_read(buz_dev, pos, buffer, size);
    }

    return rb;
}

static rt_size_t hal_buzzer_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    buzzer_dev_t buz_dev = (buzzer_dev_t)dev;
    rt_size_t    wb      = 0;
    uint16_t     chan_val;
    uint16_t*    val_ptr = (uint16_t*)buffer;

    if (dev_suspend == RT_TRUE || buffer == NULL || pos == 0) {
        return 0;
    }

    /* apply channel mask */
    pos = pos & buz_dev->chan_mask;
    /* saturate channel value */
    chan_val = constrain_uint16(val_ptr[0], buz_dev->range[0], buz_dev->range[1]);

    if (buz_dev->ops->dev_write) {
        wb = buz_dev->ops->dev_write(buz_dev, pos, &chan_val, size);
        buzzer_dbg("buz write value %d\r\n", chan_val);
    }

    return wb;
}

rt_err_t hal_buzzer_register(buzzer_dev_t buzzer, const char* name, rt_uint32_t flag, void* data)
{
    struct rt_device* parent_device;
    RT_ASSERT(buzzer != RT_NULL);

    parent_device = &(buzzer->parent);

    parent_device->type        = RT_Device_Class_Miscellaneous;
    parent_device->ref_count   = 0;
    parent_device->rx_indicate = RT_NULL;
    parent_device->tx_complete = RT_NULL;

    parent_device->init    = hal_buzzer_init;
    parent_device->open    = hal_buzzer_open;
    parent_device->close   = hal_buzzer_close;
    parent_device->read    = hal_buzzer_read;
    parent_device->write   = hal_buzzer_write;
    parent_device->control = hal_buzzer_control;

    parent_device->user_data = data;

    /* register buzzer device */
    return rt_device_register(parent_device, name, flag);
}
