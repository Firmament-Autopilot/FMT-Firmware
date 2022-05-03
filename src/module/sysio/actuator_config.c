/******************************************************************************
 * Copyright 2016-2021 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>
#include <string.h>

#include "hal/actuator/actuator.h"
#include "module/sysio/actuator_config.h"
#include "module/toml/toml.h"

#define TOML_DBG_E(...) toml_debug("Actuator", "E", __VA_ARGS__)
#define TOML_DBG_W(...) toml_debug("Actuator", "W", __VA_ARGS__)

#define ACTUATOR_MAX_DEVICE_NUM         5
#define ACTUATOR_MAX_MAPPING_NUM        10
#define MATCH(a, b)                     (strcmp(a, b) == 0)
#define DEVICE_LIST                     actuator_device_list
#define DEVICE_NUM                      actuator_device_num
#define DEVICE_PROTOCOL_IS(_idx, _name) MATCH(DEVICE_LIST[_idx].protocol, #_name)
#define FIND_DEVICE(_idx)               rt_device_find(DEVICE_LIST[_idx].name)

static actuator_device_info actuator_device_list[ACTUATOR_MAX_DEVICE_NUM];
static uint8_t actuator_device_num;
static actuator_mapping actuator_mappings_list[ACTUATOR_MAX_MAPPING_NUM];
static uint8_t actuator_mapping_num;

static fmt_err_t actuator_parse_device(const toml_table_t* curtab, int idx)
{
    fmt_err_t err = FMT_EOK;
    int i;
    const char* key;

    /* get device name */
    if (toml_string_in(curtab, "name", &DEVICE_LIST[idx].name) != 0) {
        TOML_DBG_E("fail to parse name value\n");
        return FMT_ERROR;
    }

    /* get device protocol */
    if (toml_string_in(curtab, "protocol", &DEVICE_LIST[idx].protocol) == 0) {
        actuator_dev_t act_dev = (actuator_dev_t)rt_device_find(DEVICE_LIST[idx].name);
        if (act_dev == NULL) {
            TOML_DBG_E("can't find device %s\n", DEVICE_LIST[idx].name);
            return FMT_ERROR;
        }

        if (DEVICE_PROTOCOL_IS(idx, pwm)) {
            /* set protocol if it's not the case */
            if (act_dev->config.protocol != ACT_PROTOCOL_PWM) {
                int protocol = ACT_PROTOCOL_PWM;
                if (rt_device_control(&act_dev->parent, ACT_CMD_SET_PROTOCOL, &protocol) != RT_EOK) {
                    TOML_DBG_E("fail to set protocol to pwm\n");
                    return FMT_ERROR;
                }
            }

            act_pwm_drv_config pwm_drv_default_config = {
                .freq = act_dev->config.pwm_config.pwm_freq
            };

            DEVICE_LIST[idx].config = rt_malloc(sizeof(act_pwm_drv_config));

            /* set default value */
            if (DEVICE_LIST[idx].config) {
                *(act_pwm_drv_config*)DEVICE_LIST[idx].config = pwm_drv_default_config;
            } else {
                TOML_DBG_E("fail to malloc memory\n");
                err = FMT_ERROR;
            }
        } else if (DEVICE_PROTOCOL_IS(idx, dshot)) {
            /* set protocol if it's not the case */
            if (act_dev->config.protocol != ACT_PROTOCOL_DSHOT) {
                int protocol = ACT_PROTOCOL_DSHOT;
                if (rt_device_control(&act_dev->parent, ACT_CMD_SET_PROTOCOL, &protocol) != RT_EOK) {
                    TOML_DBG_E("fail to set protocol to dshot\n");
                    return FMT_ERROR;
                }
            }

            act_dshot_drv_config dshot_drv_default_config = {
                .speed = act_dev->config.dshot_config.speed,
                .telem_req = act_dev->config.dshot_config.telem_req
            };

            DEVICE_LIST[idx].config = rt_malloc(sizeof(act_dshot_drv_config));

            /* set default value */
            if (DEVICE_LIST[idx].config) {
                *(act_dshot_drv_config*)DEVICE_LIST[idx].config = dshot_drv_default_config;
            } else {
                TOML_DBG_E("fail to malloc memory\n");
                err = FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown device protocol: %s\n", DEVICE_LIST[idx].protocol);
            err = FMT_ERROR;
        }
    } else {
        TOML_DBG_E("fail to parse protocol value\n");
        return FMT_ERROR;
    }

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(curtab, i)); i++) {
        if (MATCH(key, "protocol") || MATCH(key, "name")) {
            /* already handled */
            continue;
        }

        if (DEVICE_PROTOCOL_IS(idx, pwm)) {
            act_pwm_drv_config* config = (act_pwm_drv_config*)DEVICE_LIST[idx].config;

            if (MATCH(key, "freq")) {
                int64_t ival;
                if (toml_int_in(curtab, key, &ival) == 0) {
                    config->freq = ival;
                } else {
                    TOML_DBG_W("fail to parse freq value\n");
                    continue;
                }
            } else {
                TOML_DBG_W("unknown config key: %s\n", key);
                continue;
            }
        } else if (DEVICE_PROTOCOL_IS(idx, dshot)) {
            act_dshot_drv_config* config = (act_dshot_drv_config*)DEVICE_LIST[idx].config;

            if (MATCH(key, "speed")) {
                int64_t ival;
                if (toml_int_in(curtab, key, &ival) == 0) {
                    config->speed = ival;
                } else {
                    TOML_DBG_W("fail to parse speed value\n");
                    continue;
                }
            } else if (MATCH(key, "telem-req")) {
                int bval;
                if (toml_bool_in(curtab, key, &bval) == 0) {
                    config->telem_req = (bool)bval;
                } else {
                    TOML_DBG_W("fail to parse telem-req value\n");
                    continue;
                }
            } else {
                TOML_DBG_W("unknown config key: %s\n", key);
                continue;
            }
        } else {
            // unknown type
            TOML_DBG_W("unknown key: %s\n", key);
            continue;
        }
    }

    return err;
}

static fmt_err_t actuator_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = actuator_parse_device(curtab, idx);

        if (err != FMT_EOK) {
            TOML_DBG_E("device parse fail: %d\n", err);
            continue;
        }

        if (++idx >= ACTUATOR_MAX_DEVICE_NUM) {
            TOML_DBG_W("too many devices\n");
            break;
        }
    }

    DEVICE_NUM = idx;

    return err;
}

static fmt_err_t actuator_parse_mapping(const toml_table_t* curtab, int idx)
{
    fmt_err_t err = FMT_EOK;
    toml_array_t* arr;
    int i;
    int64_t ival;

    if (toml_string_in(curtab, "from", &actuator_mappings_list[idx].from) != 0) {
        TOML_DBG_E("fail to parse from device\n");
        return FMT_ERROR;
    }

    if (toml_string_in(curtab, "to", &actuator_mappings_list[idx].to) != 0) {
        TOML_DBG_E("fail to parse to device\n");
        return FMT_ERROR;
    }

    toml_array_t* mapping_array = toml_array_in(curtab, "chan-map");
    if (mapping_array == NULL) {
        TOML_DBG_E("fail to parse chan-map\n");
        return FMT_ERROR;
    }

    if (toml_array_nelem(mapping_array) != 2) {
        TOML_DBG_E("illegal chan-map array length: %d\n", toml_array_nelem(mapping_array));
        return FMT_ERROR;
    }

    arr = toml_array_at(mapping_array, 0);
    actuator_mappings_list[idx].map_size = toml_array_nelem(arr);
    for (i = 0; i < actuator_mappings_list[idx].map_size; i++) {
        if (toml_int_at(arr, i, &ival) == 0) {
            actuator_mappings_list[idx].from_map[i] = (uint16_t)ival;
        } else {
            TOML_DBG_E("fail to parse mapping value\n");
            return FMT_ERROR;
        }
    }

    arr = toml_array_at(mapping_array, 1);
    if (toml_array_nelem(arr) != actuator_mappings_list[idx].map_size) {
        TOML_DBG_E("illegal array length:%d %d\n", toml_array_nelem(arr), actuator_mappings_list[idx].map_size);
        return FMT_ERROR;
    }
    for (i = 0; i < actuator_mappings_list[idx].map_size; i++) {
        if (toml_int_at(arr, i, &ival) == 0) {
            actuator_mappings_list[idx].to_map[i] = (uint16_t)ival;
        } else {
            TOML_DBG_E("fail to parse mapping value\n");
            return FMT_ERROR;
        }
    }

    return err;
}

static fmt_err_t actuator_parse_mappings(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = actuator_parse_mapping(curtab, idx);

        if (err != FMT_EOK) {
            TOML_DBG_E("mapping parse fail: %d\n", err);
            continue;
        }

        if (++idx >= ACTUATOR_MAX_MAPPING_NUM) {
            TOML_DBG_E("too many mappings\n");
            break;
        }
    }

    actuator_mapping_num = idx;

    return err;
}

void show_actuator_config(void)
{
    for (int i = 0; i < DEVICE_NUM; i++) {
        printf("protocol:%s name:%s\n", DEVICE_LIST[i].protocol, DEVICE_LIST[i].name);
        if (DEVICE_PROTOCOL_IS(i, pwm)) {
            act_pwm_drv_config* config = (act_pwm_drv_config*)DEVICE_LIST[i].config;
            console_printf("freq:%d\n", config->freq);
        } else if (DEVICE_PROTOCOL_IS(i, dshot)) {
            act_dshot_drv_config* config = (act_dshot_drv_config*)DEVICE_LIST[i].config;
            printf("speed:%d telem_req:%d\n", config->speed, config->telem_req);
        }
    }

    for (int i = 0; i < actuator_mapping_num; i++) {
        printf("from:%s to:%s\n", actuator_mappings_list[i].from, actuator_mappings_list[i].to);
        printf("[");
        printf("[");
        for (int j = 0; j < actuator_mappings_list[i].map_size; j++) {
            printf("%d,", actuator_mappings_list[i].from_map[j]);
        }
        printf("]");
        printf("[");
        for (int j = 0; j < actuator_mappings_list[i].map_size; j++) {
            printf("%d,", actuator_mappings_list[i].to_map[j]);
        }
        printf("]");
        printf("]\n");
    }
}

uint8_t actuator_toml_get_device_num(void)
{
    return actuator_device_num;
}

actuator_device_info* actuator_toml_get_device_list(void)
{
    return actuator_device_list;
}

uint8_t actuator_toml_get_mapping_num(void)
{
    return actuator_mapping_num;
}

actuator_mapping* actuator_toml_get_mapping_list(void)
{
    return actuator_mappings_list;
}

fmt_err_t actuator_toml_config(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    fmt_err_t err = FMT_EOK;

    /* first parse devices and mappings */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            if (toml_array_table_in(table, key, &arr) == 0) {
                err = actuator_parse_devices(arr);
                if (err != FMT_EOK) {
                    return err;
                }
            } else {
                TOML_DBG_E("fail to parse devices\n");
                return FMT_ERROR;
            }
        } else if (MATCH(key, "mappings")) {
            if (toml_array_table_in(table, key, &arr) == 0) {
                err = actuator_parse_mappings(arr);
                if (err != FMT_EOK) {
                    return err;
                }
            } else {
                TOML_DBG_E("fail to parse mappings\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_W("unknown config key: %s\n", key);
        }
    }

    /* open actuator devices */
    for (i = 0; i < DEVICE_NUM; i++) {
        actuator_dev_t act_dev = (actuator_dev_t)rt_device_find(DEVICE_LIST[i].name);

        if (DEVICE_PROTOCOL_IS(i, pwm)) {
            act_pwm_drv_config* config = (act_pwm_drv_config*)DEVICE_LIST[i].config;

            act_dev->config.pwm_config.pwm_freq = config->freq;
        } else if (DEVICE_PROTOCOL_IS(i, dshot)) {
            act_dshot_drv_config* config = (act_dshot_drv_config*)DEVICE_LIST[i].config;

            act_dev->config.dshot_config.speed = config->speed;
            act_dev->config.dshot_config.telem_req = config->telem_req;
        } else {
            continue;
        }

        if (rt_device_open(&act_dev->parent, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    return FMT_EOK;
}