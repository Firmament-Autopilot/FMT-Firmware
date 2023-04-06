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
#include <firmament.h>

#include "hal/serial/serial.h"
#include "module/obc/mavobc.h"
#include "module/obc/mavobc_config.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"

#define TOML_DBG_E(...) toml_debug("Mavobc", "E", __VA_ARGS__)
#define TOML_DBG_W(...) toml_debug("Mavobc", "W", __VA_ARGS__)

#define MAVOBC_MAX_DEVICE_NUM       5
#define MATCH(a, b)                 (strcmp(a, b) == 0)
#define DEVICE_LIST                 mavobc_device_list
#define DEVICE_NUM                  mavobc_device_num
#define DEVICE_TYPE_IS(_idx, _name) MATCH(DEVICE_LIST[_idx].type, #_name)
#define FIND_DEVICE(_idx)           rt_device_find(DEVICE_LIST[_idx].name)
#define MAVOBC_SERIAL_BAUDRATE      57600

static mavobc_device_info mavobc_device_list[MAVOBC_MAX_DEVICE_NUM];
static uint8_t mavobc_device_num;

static void reset_device_list(void)
{
    for (int i = 0; i < MAVOBC_MAX_DEVICE_NUM; i++) {
        if (DEVICE_LIST[i].type) {
            rt_free(DEVICE_LIST[i].type);
        }
        if (DEVICE_LIST[i].name) {
            rt_free(DEVICE_LIST[i].name);
        }
        if (DEVICE_LIST[i].config) {
            rt_free(DEVICE_LIST[i].config);
        }
        DEVICE_LIST[i].type = NULL;
        DEVICE_LIST[i].name = NULL;
        DEVICE_LIST[i].config = NULL;
    }
    DEVICE_NUM = 0;
}

static fmt_err_t mavobc_parse_device(const toml_table_t* curtab, int idx)
{
    fmt_err_t err = FMT_EOK;
    int i;
    const char* key;

    /* get device type */
    if (toml_string_in(curtab, "type", &DEVICE_LIST[idx].type) == 0) {
        if (DEVICE_TYPE_IS(idx, serial)) {
            mavobc_serial_dev_config serial_default_config = {
                .baudrate = MAVOBC_SERIAL_BAUDRATE
            };
            DEVICE_LIST[idx].config = rt_malloc(sizeof(mavobc_serial_dev_config));

            /* set default value */
            if (DEVICE_LIST[idx].config) {
                *(mavobc_serial_dev_config*)DEVICE_LIST[idx].config = serial_default_config;
            } else {
                TOML_DBG_E("malloc fail\n");
                err = FMT_ERROR;
            }
        } else if (DEVICE_TYPE_IS(idx, usb)) {
            /* do nothing */
        } else {
            TOML_DBG_E("unknown device type: %s\n", DEVICE_LIST[idx].type);
            err = FMT_ERROR;
        }
    } else {
        TOML_DBG_E("fail to parse type value\n");
        return FMT_ERROR;
    }

    if (toml_string_in(curtab, "name", &DEVICE_LIST[idx].name) != 0) {
        TOML_DBG_E("fail to parse name value\n");
        return FMT_ERROR;
    }

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(curtab, i)); i++) {
        if (MATCH(key, "type") || MATCH(key, "name")) {
            /* already handled */
            continue;
        }

        if (DEVICE_TYPE_IS(idx, serial)) {
            mavobc_serial_dev_config* config = (mavobc_serial_dev_config*)DEVICE_LIST[idx].config;
            if (MATCH(key, "baudrate")) {
                int64_t ival;
                if (toml_int_in(curtab, key, &ival) == 0) {
                    config->baudrate = (uint32_t)ival;
                } else {
                    TOML_DBG_W("fail to parse baudrate value\n");
                    continue;
                }
            } else {
                TOML_DBG_W("unknown config key: %s\n", key);
                continue;
            }
        } else if (DEVICE_TYPE_IS(idx, usb)) {
            /* do nothing */
        } else {
            TOML_DBG_W("unknown device type:%s \n", DEVICE_LIST[idx].type);
            continue;
        }
    }

    return err;
}

static fmt_err_t mavobc_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = mavobc_parse_device(curtab, idx);

        if (err != FMT_EOK) {
            TOML_DBG_W("device parse fail: %d\n", err);
            continue;
        }

        if (++idx >= MAVOBC_MAX_DEVICE_NUM) {
            TOML_DBG_W("too many devices\n");
            break;
        }
    }

    DEVICE_NUM = idx;

    return err;
}

uint8_t mavobc_get_channel_num(void)
{
    return DEVICE_NUM;
}

fmt_err_t mavobc_get_devinfo(rt_device_t dev, mavobc_device_info* info)
{
    for (int idx = 0; idx < DEVICE_NUM; idx++) {
        if (rt_device_find(DEVICE_LIST[idx].name) == dev) {
            *info = DEVICE_LIST[idx];
            return FMT_EOK;
        }
    }

    return FMT_EINVAL;
}

fmt_err_t mavobc_switch_channel(uint8_t chan)
{
    rt_device_t old_device, new_device;

    if (chan >= DEVICE_NUM) {
        return FMT_EINVAL;
    }

    old_device = mavobc_get_device();
    if (mavobc_set_device(DEVICE_LIST[chan].name) == FMT_EOK) {
        /* configure serial device if needed */
        if (DEVICE_TYPE_IS(chan, serial)) {
            serial_dev_t serial_dev;
            mavobc_serial_dev_config* config = (mavobc_serial_dev_config*)DEVICE_LIST[chan].config;

            new_device = mavobc_get_device();
            serial_dev = (serial_dev_t)new_device;

            if (serial_dev->config.baud_rate != config->baudrate) {
                struct serial_configure pconfig = serial_dev->config;
                pconfig.baud_rate = config->baudrate;
                if (rt_device_control(new_device, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
                    return FMT_ERROR;
                }
            }
        }
        /* now we can safely close the old device */
        if (old_device != NULL) {
            rt_device_close(old_device);
        }
    } else {
        TOML_DBG_E("mavobc_set_device failed \n");
        return FMT_ERROR;
    }

    return FMT_EOK;
}

/* config mavobc via toml system configuration file */
fmt_err_t mavobc_toml_config(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    toml_table_t* tab;
    fmt_err_t err = FMT_EOK;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            /* we get new device configuration, override original one */
            reset_device_list();

            if (toml_array_table_in(table, key, &arr) == 0) {
                err = mavobc_parse_devices(arr);
                if (err != FMT_EOK) {
                    TOML_DBG_E("fail to parse devices\n");
                    return err;
                }
            } else {
                TOML_DBG_E("fail to get devices table\n");
                return FMT_ERROR;
            }
        } else if (MATCH(key, "device")) {
            /* we get new device configuration, override original one */
            reset_device_list();

            if ((tab = toml_table_in(table, key)) != 0) {
                err = mavobc_parse_device(tab, 0);
                if (err == FMT_EOK) {
                    DEVICE_NUM = 1;
                }
            } else {
                TOML_DBG_E("wrong element type: %s\n", key);
                err = FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown config key: %s\n", key);
            err = FMT_ERROR;
        }
    }

    return err;
}
