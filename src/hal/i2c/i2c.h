/*
 * File      : i2c.h
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

#ifndef I2C_H__
#define I2C_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RT_I2C_WR          0x0000
#define RT_I2C_RD          (1u << 0)
#define RT_I2C_ADDR_10BIT  (1u << 2) /* this is a ten bit chip address */
#define RT_I2C_NO_START    (1u << 4)
#define RT_I2C_IGNORE_NACK (1u << 5)
#define RT_I2C_NO_READ_ACK (1u << 6) /* when I2C reading, we do not ACK */

struct rt_i2c_msg {
    rt_uint16_t flags;
    rt_uint16_t len;
    rt_uint8_t* buf;
};

struct rt_i2c_bus;
struct rt_i2c_device;

struct rt_i2c_bus_device_ops {
    /**
     * @brief i2c master transfer function
     * @param bus i2c bus
     * @param slave_addr i2c 7-bit/10-bit address
     * @param msgs i2c messages to transfer
     * @param num number of i2c messages
     */
    rt_size_t (*master_xfer)(struct rt_i2c_bus* bus,
                             rt_uint16_t slave_addr,
                             struct rt_i2c_msg msgs[],
                             rt_uint32_t num);
    /**
     * @brief i2c slave transfer function
     * @param bus i2c bus
     * @param msgs i2c messages to transfer
     * @param num number of i2c messages
     */
    rt_size_t (*slave_xfer)(struct rt_i2c_bus* bus,
                            struct rt_i2c_msg msgs[],
                            rt_uint32_t num);
    /**
     * @brief i2c control function (optional)
     * @param bus i2c bus
     * @param cmd operation command
     * @param arg command arguments
     */
    rt_err_t (*i2c_bus_control)(struct rt_i2c_bus* bus,
                                int cmd,
                                void* arg);
};

/*for i2c bus driver*/
struct rt_i2c_bus {
    struct rt_device parent;
    const struct rt_i2c_bus_device_ops* ops;
    rt_uint16_t flags;
    rt_uint16_t addr;
    struct rt_mutex lock;
    rt_uint32_t timeout;
    rt_uint32_t retries;
    void* priv;
};

struct rt_i2c_device {
    struct rt_device parent;
    struct rt_i2c_bus* bus;
    rt_uint16_t slave_addr;
    rt_uint16_t flags;
};

#define i2c_dbg(fmt, ...)
// #define i2c_dbg(fmt, ...) printf(fmt, ##__VA_ARGS__)

rt_err_t rt_i2c_bus_device_register(struct rt_i2c_bus* bus,
                                    const char* bus_name);
rt_err_t rt_i2c_bus_attach_device(struct rt_i2c_device* device,
                                  const char* name,
                                  const char* bus_name,
                                  void* user_data);
rt_size_t rt_i2c_transfer(struct rt_i2c_bus* bus,
                          rt_uint16_t addr,
                          struct rt_i2c_msg msgs[],
                          rt_uint32_t num);
rt_size_t rt_i2c_master_send(struct rt_i2c_bus* bus,
                             rt_uint16_t addr,
                             rt_uint16_t flags,
                             const rt_uint8_t* buf,
                             rt_uint32_t count);
rt_size_t rt_i2c_master_recv(struct rt_i2c_bus* bus,
                             rt_uint16_t addr,
                             rt_uint16_t flags,
                             rt_uint8_t* buf,
                             rt_uint32_t count);

rt_err_t i2c_read_reg(rt_device_t i2c_dev, uint8_t reg, uint8_t* buffer);
rt_err_t i2c_write_reg(rt_device_t i2c_dev, uint8_t reg, uint8_t val);
rt_err_t i2c_read_regs(rt_device_t i2c_dev, uint8_t reg, uint8_t* buffer, uint16_t count);
rt_err_t i2c_write_regs(rt_device_t i2c_dev, uint8_t reg, uint8_t* vals, uint16_t count);

#ifdef __cplusplus
}
#endif

#endif
