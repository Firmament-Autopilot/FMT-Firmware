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
#include <firmament.h>
#include <string.h>

#include "hal/serial/serial.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"

#define TOML_DBG_E(...)             toml_debug("GNSS", "E", __VA_ARGS__)
#define TOML_DBG_W(...)             toml_debug("GNSS", "W", __VA_ARGS__)

#define GNSS_MAX_DEVICE_NUM         1 // TODO: Support for more gps devices
#define MATCH(a, b)                 (strcmp(a, b) == 0)
#define DEVICE_LIST                 gnss_dev_list
#define DEVICE_NUM                  gnss_dev_num
#define DEVICE_TYPE_IS(_idx, _name) MATCH(DEVICE_LIST[_idx].type, #_name)

typedef struct {
    uint32_t baudrate;
} gnss_serial_dev_config;

typedef struct {
    uint32_t id;
    char* protocol;
    char* type;
    char* name;
    void* config;
} gnss_device_info;

static uint8_t gnss_dev_num = 0;
static gnss_device_info gnss_dev_list[GNSS_MAX_DEVICE_NUM] = { 0 };

/**
 * Parse device table
 *
 * @param array device table
 * @param idx device index in device list
 *
 * @return FMT Errors
 */
static fmt_err_t gnss_parse_device(const toml_table_t* curtab, int idx)
{
    int64_t ival;

    if (toml_int_in(curtab, "id", &ival) != 0) {
        TOML_DBG_E("fail to parse id value\n");
        return FMT_ERROR;
    }
    DEVICE_LIST[idx].id = ival;
    printf("id:%d\n", DEVICE_LIST[idx].id);

    if (toml_string_in(curtab, "protocol", &DEVICE_LIST[idx].protocol) != 0) {
        TOML_DBG_E("fail to parse protocol value\n");
        return FMT_ERROR;
    }
    printf("protocol:%s\n", DEVICE_LIST[idx].protocol);

    /* get device type */
    if (toml_string_in(curtab, "type", &DEVICE_LIST[idx].type) == 0) {
        if (DEVICE_TYPE_IS(idx, serial)) {
            gnss_serial_dev_config serial_default_config = {
                .baudrate = 0, // unset
            };
            DEVICE_LIST[idx].config = rt_malloc(sizeof(gnss_serial_dev_config));
            gnss_serial_dev_config* config = (gnss_serial_dev_config*)DEVICE_LIST[idx].config;

            if (config != NULL) {
                /* set default value */
                *config = serial_default_config;
                /* load configured baudrate */
                if (toml_int_in(curtab, "baudrate", &ival) == 0) {
                    config->baudrate = (uint32_t)ival;
                    printf("baudrate:%d\n", config->baudrate);
                }
            } else {
                TOML_DBG_E("fail to malloc memory\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown device type: %s\n", DEVICE_LIST[idx].type);
            return FMT_ERROR;
        }
    } else {
        TOML_DBG_E("fail to parse type value\n");
        return FMT_ERROR;
    }

    if (toml_string_in(curtab, "name", &DEVICE_LIST[idx].name) != 0) {
        TOML_DBG_E("fail to parse name value\n");
        return FMT_ERROR;
    }
    printf("name:%s\n", DEVICE_LIST[idx].name);

    return FMT_EOK;
}

/**
 * Parse devices table array
 *
 * @param array devices table array
 *
 * @return FMT Errors
 */
static fmt_err_t gnss_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        /* parse all devices in the table */
        err = gnss_parse_device(curtab, idx);
        if (err != FMT_EOK) {
            TOML_DBG_W("gnss device parse fail: %d\n", i);
            continue;
        }

        if (++idx >= GNSS_MAX_DEVICE_NUM) {
            break;
        }
    }

    DEVICE_NUM = idx;

    return err;
}

/**
 * Configure gnss according to toml system configuration.
 *
 * @param table gnss toml table
 *
 * @return FMT Errors
 */
fmt_err_t gnss_toml_config(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    fmt_err_t err;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            /* parse devices */
            if (toml_array_table_in(table, key, &arr) == 0) {
                err = gnss_parse_devices(arr);
                if (err != FMT_EOK) {
                    TOML_DBG_E("fail to parse devices\n");
                    return err;
                }
            } else {
                TOML_DBG_E("fail to parse devices table\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown config key: %s\n", key);
            return FMT_EINVAL;
        }
    }

    return err;
}
