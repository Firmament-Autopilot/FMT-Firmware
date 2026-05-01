/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#ifndef GNSS_CONFIG_H__
#define GNSS_CONFIG_H__

#include <firmament.h>

#include "module/toml/toml.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t baudrate;
} gnss_serial_dev_config;

typedef struct {
    uint32_t id;
    char* protocol;
    char* type;
    char* name;
    bool auto_config;
    void* config;
} gnss_device_info;

/* toml configuration */
fmt_err_t gnss_toml_config(toml_table_t* table);
uint8_t gnss_get_dev_num(void);
gnss_device_info* gnss_get_dev_list(void);

#ifdef __cplusplus
}
#endif

#endif
