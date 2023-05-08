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

#ifndef MAVPROXY_CONFIG_H__
#define MAVPROXY_CONFIG_H__

#include <firmament.h>

#include "module/toml/toml.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t baudrate;
} mavproxy_serial_dev_config;

typedef struct {
    char* type;
    char* name;
    void* config;
} mavproxy_device_info;

/* toml configuration */
fmt_err_t mavproxy_toml_config(toml_table_t* table);
fmt_err_t mavproxy_get_devinfo(uint8_t chan, rt_device_t dev, mavproxy_device_info* info);

fmt_err_t mavproxy_switch_dev(uint8_t chan, uint8_t idx);
mavproxy_device_info* mavproxy_get_dev_list(uint8_t chan);
uint8_t mavproxy_get_dev_num(uint8_t chan);

#ifdef __cplusplus
}
#endif

#endif
