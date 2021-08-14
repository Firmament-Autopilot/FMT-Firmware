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

#ifndef ACTUATOR_CONFIG_H__
#define ACTUATOR_CONFIG_H__

#include <firmament.h>

#include "module/toml/toml.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint16_t freq;
} act_pwm_drv_config;

typedef struct {
    uint16_t speed;
    bool telem_req;
} act_dshot_drv_config;

typedef struct {
    char* protocol;
    char* name;
    void* config;
} actuator_device_info;

typedef struct {
    char* from;
    char* to;
    uint8_t map_size;
    uint8_t from_map[16]; /* channel mapping start from 1 */
    uint8_t to_map[16];   /* channel mapping start from 1 */
} actuator_mapping;

/* toml configuration */
fmt_err_t actuator_toml_config(toml_table_t* table);
uint8_t actuator_toml_get_device_num(void);
uint8_t actuator_toml_get_mapping_num(void);
actuator_device_info* actuator_toml_get_device_list(void);
actuator_mapping* actuator_toml_get_mapping_list(void);

#ifdef __cplusplus
}
#endif

#endif /* ACTUATOR_CONFIG_H__ */
