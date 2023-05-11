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
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/mavproxy_config.h"
#include "module/toml/toml.h"
#include "module/utils/devmq.h"

#define TOML_DBG_E(...) toml_debug("Mavproxy", "E", __VA_ARGS__)
#define TOML_DBG_W(...) toml_debug("Mavproxy", "W", __VA_ARGS__)

#define MAVPROXY_MAX_DEVICE_NUM            5
#define MATCH(a, b)                        (strcmp(a, b) == 0)
#define DEVICE_LIST(_chan)                 mavproxy_device_list[_chan]
#define DEVICE_NUM(_chan)                  mavproxy_device_num[_chan]
#define DEVICE_TYPE_IS(_chan, _idx, _name) MATCH(DEVICE_LIST(_chan)[_idx].type, #_name)
#define FIND_DEVICE(_chan, _idx)           rt_device_find(DEVICE_LIST(_chan)[_idx].name)
#define MAVPROXY_SERIAL_BAUDRATE           57600

static mavproxy_device_info mavproxy_device_list[MAVPROXY_CHAN_NUM][MAVPROXY_MAX_DEVICE_NUM];
static uint8_t mavproxy_device_num[MAVPROXY_CHAN_NUM];

static void __handle_device_msg(rt_device_t dev, void* msg)
{
    device_status status = *((device_status*)msg);

    for (uint8_t chan = 0; chan < MAVPROXY_CHAN_NUM; chan++) {
        for (uint8_t idx = 0; idx < DEVICE_NUM(chan); idx++) {
            if (rt_device_find(DEVICE_LIST(chan)[idx].name) == dev) {
                if (status == DEVICE_STATUS_CONNECT) {
                    /* if usb conncted, switch to usb channel */
                    mavproxy_set_device(chan, idx);
                } else if (status == DEVICE_STAUTS_DISCONNECT) {
                    /* if usb disconncted, switch to default channel */
                    mavproxy_set_device(chan, 0);
                }
                break;
            }
        }
    }
}

static fmt_err_t mavproxy_parse_device(const toml_table_t* curtab)
{
    fmt_err_t err = FMT_EOK;
    int i;
    const char* key;
    uint8_t chan;
    uint8_t idx;

    /* get channel */
    int64_t ival;
    if (toml_int_in(curtab, "chan", &ival) == 0) {
        chan = (uint8_t)ival;

        if (chan >= MAVPROXY_CHAN_NUM) {
            TOML_DBG_E("invalid channel:%d\n", chan);
            return FMT_EINVAL;
        }

        if (DEVICE_NUM(chan) >= MAVPROXY_MAX_DEVICE_NUM) {
            TOML_DBG_W("too many devices for chan:%d\n", chan);
            return FMT_ENOTHANDLE;
        }

        idx = DEVICE_NUM(chan);
    } else {
        TOML_DBG_E("fail to parse chan value\n");
        return FMT_ERROR;
    }

    /* get device type */
    if (toml_string_in(curtab, "type", &DEVICE_LIST(chan)[idx].type) == 0) {
        if (DEVICE_TYPE_IS(chan, idx, serial)) {
            mavproxy_serial_dev_config serial_default_config = {
                .baudrate = MAVPROXY_SERIAL_BAUDRATE
            };
            (DEVICE_LIST(chan)[idx].config) = rt_malloc(sizeof(mavproxy_serial_dev_config));

            /* set default value */
            if (DEVICE_LIST(chan)[idx].config) {
                *(mavproxy_serial_dev_config*)DEVICE_LIST(chan)[idx].config = serial_default_config;
            } else {
                TOML_DBG_E("malloc fail\n");
                err = FMT_ERROR;
            }
        } else if (DEVICE_TYPE_IS(chan, idx, usb)) {
            /* do nothing */
        } else if (DEVICE_TYPE_IS(chan, idx, bb_com)) {
            /* do nothing */
        } else {
            TOML_DBG_E("unknown device type: %s\n", DEVICE_LIST(chan)[idx].type);
            err = FMT_ERROR;
        }
    } else {
        TOML_DBG_E("fail to parse type value\n");
        return FMT_ERROR;
    }

    if (toml_string_in(curtab, "name", &DEVICE_LIST(chan)[idx].name) != 0) {
        TOML_DBG_E("fail to parse name value\n");
        return FMT_ERROR;
    }

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(curtab, i)); i++) {
        if (MATCH(key, "chan") || MATCH(key, "type") || MATCH(key, "name")) {
            /* already handled */
            continue;
        }

        if (DEVICE_TYPE_IS(chan, idx, serial)) {
            mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)DEVICE_LIST(chan)[idx].config;
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
        } else if (DEVICE_TYPE_IS(chan, idx, usb)) {
            if (MATCH(key, "auto-switch")) {
                int bval;
                if (toml_bool_in(curtab, key, &bval) == 0) {
                    if (bval) {
                        /* if auto-switch is true, register devmq to monitor device status */
                        if (devmq_register(FIND_DEVICE(chan, idx), __handle_device_msg) != FMT_EOK) {
                            TOML_DBG_W("fail to register %s message queue\n", DEVICE_LIST(chan)[idx].name);
                        }
                    }
                } else {
                    TOML_DBG_E("fail to parse auto-switch value\n");
                    continue;
                }
            } else {
                TOML_DBG_E("unknown config key: %s\n", key);
                continue;
            }
        } else if (DEVICE_TYPE_IS(chan, idx, bb_com)) {
            // DEVICE_NUM = idx + 1; /* the DEVICE_NUM has not set here, so add 1 for temp */
            // if (MATCH(key, "auto-switch")) {
            //     rt_device_t ret = rt_device_find(DEVICE_LIST(chan)[idx].name);
            //     if (ret != RT_NULL) {
            //         fmt_err_t ret = mavproxy_set_device(chan, idx);
            //         if (ret != RT_EOK) {
            //             TOML_DBG_W("mavproxy_set_device = %d failed!!! \n", idx);
            //         } else {
            //             TOML_DBG_E("mavproxy_set_device bb_com  \n");
            //         }
            //     } else {
            //         TOML_DBG_E("can't find bb_com  \n");
            //     }
            // } else {
            //     TOML_DBG_E("unknown config key: %s \n", key);
            //     continue;
            // }
        } else {
            TOML_DBG_W("unknown device type:%s \n", DEVICE_LIST(chan)[idx].type);
            continue;
        }
    }

    if (err == FMT_EOK) {
        DEVICE_NUM(chan) += 1;
    }

    return err;
}

static fmt_err_t mavproxy_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = mavproxy_parse_device(curtab);

        if (err != FMT_EOK) {
            TOML_DBG_E("device parse fail: %d\n", err);
            return err;
        }
    }

    return err;
}

uint8_t mavproxy_get_dev_num(uint8_t chan)
{
    return DEVICE_NUM(chan);
}

mavproxy_device_info* mavproxy_get_dev_list(uint8_t chan)
{
    return DEVICE_LIST(chan);
}

fmt_err_t mavproxy_get_devinfo(uint8_t chan, rt_device_t dev, mavproxy_device_info* info)
{
    for (int idx = 0; idx < DEVICE_NUM(chan); idx++) {
        if (rt_device_find(DEVICE_LIST(chan)[idx].name) == dev) {
            *info = DEVICE_LIST(chan)[idx];
            return FMT_EOK;
        }
    }

    return FMT_EINVAL;
}

fmt_err_t mavproxy_switch_dev(uint8_t chan, uint8_t idx)
{
    rt_device_t old_device, new_device;

    if (idx >= DEVICE_NUM(chan)) {
        return FMT_EINVAL;
    }

    old_device = mavproxy_dev_get_device(chan);
    if (mavproxy_dev_set_device(chan, DEVICE_LIST(chan)[idx].name) == FMT_EOK) {
        /* configure serial device if needed */
        if (DEVICE_TYPE_IS(chan, idx, serial)) {
            serial_dev_t serial_dev;
            mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)DEVICE_LIST(chan)[idx].config;

            new_device = mavproxy_dev_get_device(chan);
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
        TOML_DBG_E("mavproxy_dev_set_device failed \n");
        return FMT_ERROR;
    }

    return FMT_EOK;
}

/* config mavproxy via toml system configuration file */
fmt_err_t mavproxy_toml_config(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    fmt_err_t err = FMT_EOK;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            if (toml_array_table_in(table, key, &arr) == 0) {
                err = mavproxy_parse_devices(arr);
                if (err != FMT_EOK) {
                    TOML_DBG_E("fail to parse devices\n");
                    return err;
                }
            } else {
                TOML_DBG_E("fail to get devices table\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown config key: %s\n", key);
            err = FMT_ERROR;
        }
    }

    return err;
}
