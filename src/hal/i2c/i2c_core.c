/*
 * File      : i2c_core.c
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
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_bit_ops.h"
#include "hal/i2c/i2c_dev.h"
// #include <firmament.h>

rt_err_t rt_i2c_bus_device_register(struct rt_i2c_bus* bus,
                                    const char* bus_name)
{
    rt_err_t res = RT_EOK;

    rt_mutex_init(&bus->lock, "i2c_bus_lock", RT_IPC_FLAG_FIFO);

    if (bus->timeout == 0)
        bus->timeout = RT_TICK_PER_SECOND;

    res = rt_i2c_bus_init(bus, bus_name);

    i2c_dbg("I2C bus [%s] registered\n", bus_name);

    return res;
}

rt_err_t rt_i2c_bus_attach_device(struct rt_i2c_device* device,
                                  const char* name,
                                  const char* bus_name,
                                  void* user_data)
{
    rt_err_t result;
    rt_device_t bus;

    /* get physical i2c bus */
    bus = rt_device_find(bus_name);

    if (bus != RT_NULL && bus->type == RT_Device_Class_I2CBUS) {
        device->bus = (struct rt_i2c_bus*)bus;

        /* initialize i2c device */
        result = rt_i2c_device_init(device, name);
        if (result != RT_EOK)
            return result;

        device->parent.user_data = user_data;

        return RT_EOK;
    }

    /* not found the host bus */
    return RT_ERROR;
}

rt_size_t rt_i2c_transfer(struct rt_i2c_bus* bus,
                          rt_uint16_t addr,
                          struct rt_i2c_msg msgs[],
                          rt_uint32_t num)
{
    rt_size_t ret;

    if (bus == RT_NULL) {
        return 0;
    }

    if (bus->ops->master_xfer) {
#ifdef RT_I2C_DEBUG
        for (ret = 0; ret < num; ret++) {
            i2c_dbg("msgs[%d] %c, len=%d%s\n", ret, (msgs[ret].flags & RT_I2C_RD) ? 'R' : 'W', msgs[ret].len);
        }
#endif
        if (!(msgs[0].flags & RT_I2C_ADDR_10BIT)) {
            addr = addr << 1;
        }

        rt_mutex_take(&bus->lock, RT_WAITING_FOREVER);
        ret = bus->ops->master_xfer(bus, addr, msgs, num);
        rt_mutex_release(&bus->lock);

        return ret;
    } else {
        i2c_dbg("I2C bus operation not supported\n");

        return 0;
    }
}

rt_size_t rt_i2c_master_send(struct rt_i2c_bus* bus,
                             rt_uint16_t addr,
                             rt_uint16_t flags,
                             const rt_uint8_t* buf,
                             rt_uint32_t count)
{
    rt_size_t ret;
    struct rt_i2c_msg msg;

    if (bus == RT_NULL) {
        return 0;
    }

    msg.flags = flags & RT_I2C_ADDR_10BIT;
    msg.len = count;
    msg.buf = (rt_uint8_t*)buf;

    ret = rt_i2c_transfer(bus, addr, &msg, 1);

    return ret == 1 ? count : 0;
}

rt_size_t rt_i2c_master_recv(struct rt_i2c_bus* bus,
                             rt_uint16_t addr,
                             rt_uint16_t flags,
                             rt_uint8_t* buf,
                             rt_uint32_t count)
{
    rt_size_t ret;
    struct rt_i2c_msg msg;

    if (bus == RT_NULL) {
        return 0;
    }

    msg.flags = flags & RT_I2C_ADDR_10BIT;
    msg.flags |= RT_I2C_RD;
    msg.len = count;
    msg.buf = buf;

    ret = rt_i2c_transfer(bus, addr, &msg, 1);

    return ret == 1 ? count : 0;
}

rt_err_t i2c_read_reg(rt_device_t i2c_dev, uint8_t reg, uint8_t* buffer)
{
    rt_size_t ret;
    struct rt_i2c_msg msgs[2];
    struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

    msgs[0].flags = RT_I2C_WR | i2c_device->flags;
    msgs[0].buf = &reg;
    msgs[0].len = 1;

    msgs[1].flags = RT_I2C_RD | i2c_device->flags;
    msgs[1].buf = buffer;
    msgs[1].len = 1;

    ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, msgs, 2);

    return ret == 2 ? RT_EOK : RT_ERROR;
}

rt_err_t i2c_write_reg(rt_device_t i2c_dev, uint8_t reg, uint8_t val)
{
    rt_size_t ret;
    rt_uint8_t buffer[2];
    struct rt_i2c_msg msgs;
    struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

    buffer[0] = reg;
    buffer[1] = val;

    msgs.flags = RT_I2C_WR | i2c_device->flags;
    msgs.buf = buffer;
    msgs.len = 2;

    ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, &msgs, 1);

    return ret == 1 ? RT_EOK : RT_ERROR;
}

rt_err_t i2c_read_regs(rt_device_t i2c_dev, uint8_t reg, uint8_t* buffer, uint16_t count)
{
    rt_size_t ret;
    struct rt_i2c_msg msgs[2];
    struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

    msgs[0].flags = RT_I2C_WR | i2c_device->flags;
    msgs[0].buf = &reg;
    msgs[0].len = 1;

    msgs[1].flags = RT_I2C_RD | i2c_device->flags;
    msgs[1].buf = buffer;
    msgs[1].len = count;

    ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, msgs, 2);

    return ret == 2 ? RT_EOK : RT_ERROR;
}

rt_err_t i2c_write_regs(rt_device_t i2c_dev, uint8_t reg, uint8_t* vals, uint16_t count)
{
    rt_size_t ret;
    struct rt_i2c_msg msgs[2];
    struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

    msgs[0].flags = RT_I2C_WR | i2c_device->flags;
    msgs[0].buf = &reg;
    msgs[0].len = 1;

    msgs[1].flags = RT_I2C_WR | i2c_device->flags;
    msgs[1].buf = vals;
    msgs[1].len = count;

    ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, msgs, 2);

    return ret == 2 ? RT_EOK : RT_ERROR;
}
