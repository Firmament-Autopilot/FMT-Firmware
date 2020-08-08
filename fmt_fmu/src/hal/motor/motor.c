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

#include "hal/motor.h"
#include <firmament.h>

static uint8_t _suspend = 0;

static rt_err_t hal_motor_control(struct rt_device* dev, int cmd, void* args);

static rt_err_t hal_motor_init(struct rt_device* dev)
{
    rt_err_t ret = RT_EOK;
    motor_dev_t motor;

    RT_ASSERT(dev != RT_NULL);

    motor = (motor_dev_t)dev;

    /* apply configuration */
    if (motor->ops->motor_configure) {
        ret = motor->ops->motor_configure(motor, &motor->config);
    }

    return ret;
}

rt_err_t hal_motor_open(rt_device_t dev, rt_uint16_t oflag)
{
    return hal_motor_control(dev, MOTOR_CMD_CHANNEL_ENABLE, (void*)MOTOR_MASK_ALL);
}

rt_err_t hal_motor_close(rt_device_t dev)
{
    return hal_motor_control(dev, MOTOR_CMD_CHANNEL_DISABLE, (void*)MOTOR_MASK_ALL);
}

static rt_size_t hal_motor_read(struct rt_device* dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    rt_size_t rb = 0;
    motor_dev_t motor;

    RT_ASSERT(dev != RT_NULL);

    motor = (motor_dev_t)dev;

    if (motor->ops->motor_read && buffer) {
        rb = motor->ops->motor_read(motor, (uint16_t)pos, buffer, size);
    }

    return rb;
}

static rt_size_t hal_motor_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    rt_size_t wb = 0;
    motor_dev_t motor;

    RT_ASSERT(dev != RT_NULL);

    if (_suspend) {
        return 0;
    }

    motor = (motor_dev_t)dev;

    if (motor->ops->motor_write && buffer) {
        wb = motor->ops->motor_write(motor, (uint16_t)pos, buffer, size);
    }

    return wb;
}

static rt_err_t hal_motor_control(struct rt_device* dev, int cmd, void* args)
{
    motor_dev_t motor;

    RT_ASSERT(dev != RT_NULL);

    motor = (motor_dev_t)dev;

    switch (cmd) {
    case RT_DEVICE_CTRL_SUSPEND: {
        _suspend = 1;
    } break;

    case RT_DEVICE_CTRL_RESUME: {
        _suspend = 0;
    } break;

    case MOTOR_CMD_GET_CHANNEL_NUM: {
        *(rt_uint8_t*)args = motor->channel_num;
    } break;

    default: {
        if (motor->ops->motor_control) {
            return motor->ops->motor_control(motor, cmd, args);
        }
    } break;
    }

    return RT_EOK;
}

rt_err_t hal_motor_register(motor_dev_t motor, const char* name, rt_uint32_t flag, void* data)
{
    struct rt_device* device;

    RT_ASSERT(motor != RT_NULL);

    device = &(motor->parent);

    device->type = RT_Device_Class_Miscellaneous;
    device->ref_count = 0;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;

    device->init = hal_motor_init;
    device->open = hal_motor_open;
    device->close = hal_motor_close;
    device->read = hal_motor_read;
    device->write = hal_motor_write;
    device->control = hal_motor_control;

    device->user_data = data;

    if (motor->channel_num > MAX_MOTOR_CHANNEL_NUM) {
        motor->channel_num = MAX_MOTOR_CHANNEL_NUM;
    }

    /* register pin device */
    return rt_device_register(device, name, flag);
}