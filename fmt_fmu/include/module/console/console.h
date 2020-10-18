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

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <firmament.h>
#include "module/toml/toml.h"

#define CONSOLE_CURRENT_DEVICE      (-1)

fmt_err console_init(char* dev_name);
fmt_err console_enable_shell(rt_device_t dev);
fmt_err console_set_device(char* dev_name);
uint32_t console_printf(const char* fmt, ...);
uint32_t console_println(const char* fmt, ...);
uint32_t console_write(const char* content, uint32_t len);
void console_format(char* buffer, const char* fmt, ...);

/* toml system configuration API */
fmt_err console_toml_init(toml_table_t* table);
fmt_err console_switch_device(int idx);
rt_device_t console_get_device(int idx);
int console_get_device_id(rt_device_t device);
void list_console_devices(void);

#endif
