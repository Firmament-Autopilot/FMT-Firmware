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

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* console API */
fmt_err_t console_init(void);
fmt_err_t console_enable_input(void);
fmt_err_t console_set_device(const char* device_name);
rt_device_t console_get_device(void);
uint32_t console_printf(const char* fmt, ...);
uint32_t console_println(const char* fmt, ...);
uint32_t console_print_args(const char* fmt, va_list args);
void console_format(char* buffer, const char* fmt, ...);
uint32_t console_write(const char* content, uint32_t len);

/* console helper API */
void print_item_line(const char* name, const char* content, char pad, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
