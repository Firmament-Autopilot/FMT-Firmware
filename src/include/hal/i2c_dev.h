/*
 * File      : i2c_dev.h
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

#ifndef I2C_DEV_H__
#define I2C_DEV_H__

#include <firmament.h>

#include "i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RT_I2C_DEV_CTRL_10BIT   0x20
#define RT_I2C_DEV_CTRL_ADDR    0x21
#define RT_I2C_DEV_CTRL_TIMEOUT 0x22
#define RT_I2C_DEV_CTRL_RW      0x23

struct rt_i2c_priv_data {
    rt_uint16_t addr;
    struct rt_i2c_msg* msgs;
    rt_size_t number;
};

rt_err_t rt_i2c_bus_init(struct rt_i2c_bus* bus, const char* name);
rt_err_t rt_i2c_device_init(struct rt_i2c_device* dev, const char* name);

#ifdef __cplusplus
}
#endif

#endif
