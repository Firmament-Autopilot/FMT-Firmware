/*
 * File      : i2c_dev.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2012, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author        Notes
 * 2012-04-25     weety         first version
 * 2014-08-03     bernard       fix some compiling warning
 */

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
#include "hal/i2c/i2c_dev.h"
#include "hal/i2c/i2c_bit_ops.h"
#include "hal/i2c/i2c.h"
#include <firmament.h>

static rt_size_t i2c_bus_read(rt_device_t dev,
    rt_off_t pos,
    void* buffer,
    rt_size_t count)
{
    rt_uint16_t addr;
    rt_uint16_t flags;
    struct rt_i2c_bus* bus = (struct rt_i2c_bus*)dev->user_data;

    RT_ASSERT(bus != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    i2c_dbg("I2C bus dev [%s] reading %u bytes.\n", dev->parent.name, count);

    addr = pos & 0xffff;
    flags = (pos >> 16) & 0xffff;

    return rt_i2c_master_recv(bus, addr, flags, buffer, count);
}

static rt_size_t i2c_bus_write(rt_device_t dev,
    rt_off_t pos,
    const void* buffer,
    rt_size_t count)
{
    rt_uint16_t addr;
    rt_uint16_t flags;
    struct rt_i2c_bus* bus = (struct rt_i2c_bus*)dev->user_data;

    RT_ASSERT(bus != RT_NULL);
    RT_ASSERT(buffer != RT_NULL);

    i2c_dbg("I2C bus dev %s writing %u bytes.\n", dev->parent.name, count);

    addr = pos & 0xffff;
    flags = (pos >> 16) & 0xffff;

    return rt_i2c_master_send(bus, addr, flags, buffer, count);
}

static rt_err_t i2c_bus_control(rt_device_t dev,
    int cmd,
    void* args)
{
    rt_err_t ret;
    struct rt_i2c_priv_data* priv_data;
    struct rt_i2c_bus* bus = (struct rt_i2c_bus*)dev->user_data;

    RT_ASSERT(bus != RT_NULL);

    switch (cmd) {
    /* set 10-bit addr mode */
    case RT_I2C_DEV_CTRL_10BIT:
        bus->flags |= RT_I2C_ADDR_10BIT;
        break;

    case RT_I2C_DEV_CTRL_ADDR:
        bus->addr = *(rt_uint16_t*)args;
        break;

    case RT_I2C_DEV_CTRL_TIMEOUT:
        bus->timeout = *(rt_uint32_t*)args;
        break;

    case RT_I2C_DEV_CTRL_RW:
        priv_data = (struct rt_i2c_priv_data*)args;
        ret = rt_i2c_transfer(bus, priv_data->addr, priv_data->msgs, priv_data->number);

        if (ret < 0) {
            return -RT_EIO;
        }

        break;

    default:
        break;
    }

    return RT_EOK;
}

rt_err_t rt_i2c_bus_init(struct rt_i2c_bus* bus, const char* name)
{
    struct rt_device* device;
    RT_ASSERT(bus != RT_NULL);

    device = &bus->parent;

    device->user_data = bus;

    /* set device type */
    device->type = RT_Device_Class_I2CBUS;
    /* initialize device interface */
    device->init = RT_NULL;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = i2c_bus_read;
    device->write = i2c_bus_write;
    device->control = i2c_bus_control;

    /* register to device manager */
    rt_device_register(device, name, RT_DEVICE_FLAG_RDWR);

    return RT_EOK;
}

rt_err_t rt_i2c_device_init(struct rt_i2c_device* dev, const char* name)
{
    struct rt_device* device;
    RT_ASSERT(dev != RT_NULL);

    device = &(dev->parent);

    /* set device type */
    device->type = RT_Device_Class_I2CDevice;
    device->init = RT_NULL;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = RT_NULL;     /* TODO: add i2c device opts */
    device->write = RT_NULL;
    device->control = RT_NULL;

    /* register to device manager */
    return rt_device_register(device, name, RT_DEVICE_FLAG_RDWR);
}