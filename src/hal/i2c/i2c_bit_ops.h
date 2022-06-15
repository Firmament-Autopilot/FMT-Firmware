/*
 * File      : i2c-bit-ops.h
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

#ifndef I2C_BIT_OPS_H__
#define I2C_BIT_OPS_H__

#include <firmament.h>

#include "hal/i2c/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

struct rt_i2c_bit_ops {
    void* data; /* private data for lowlevel routines */
    void (*set_sda)(void* data, rt_int32_t state);
    void (*set_scl)(void* data, rt_int32_t state);
    rt_int32_t (*get_sda)(void* data);
    rt_int32_t (*get_scl)(void* data);

    void (*udelay)(rt_uint32_t us);

    rt_uint32_t delay_us; /* scl and sda line delay */
    rt_uint32_t timeout;  /* in tick */
};

rt_err_t rt_i2c_soft_bus_register(struct rt_i2c_bus* bus,
                                  const char* bus_name);

#ifdef __cplusplus
}
#endif

#endif
