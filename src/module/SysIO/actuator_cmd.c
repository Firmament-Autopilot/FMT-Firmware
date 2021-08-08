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
#include <string.h>

#include "hal/motor.h"
#include "module/controller/controller_model.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/actuator_config.h"
#include "module/toml/toml.h"

#define TOML_DBG_E(...)             toml_debug("Actuator_Cmd", "E", __VA_ARGS__)
#define TOML_DBG_W(...)             toml_debug("Actuator_Cmd", "W", __VA_ARGS__)
#define MAX_DEVICE_NUM              5
#define MATCH(a, b)                 (strcmp(a, b) == 0)
#define DEVICE_LIST                 _actuator_cmd_device_list
#define DEVICE_NUM                  _actuator_cmd_device_num
#define DEVICE_TYPE_IS(_idx, _name) MATCH(DEVICE_LIST[_idx].type, #_name)

MCN_DECLARE(control_output);
MCN_DECLARE(rc_channels);

typedef struct {
    uint16_t freq;
    uint16_t chan_idx;
    uint16_t range[2];
} pwm_dev_config;

typedef struct {
    char* type;
    char* name;
    void* config;
} actuator_cmd_device_info;

typedef struct {
    rt_device_t dev;
    uint16_t chan_num;
    uint16_t* buffer;
} actuator_send_list;

enum {
    ACTUATOR_FROM_CONTROL_OUT,
    ACTUATOR_FROM_RC_CHANNELS,
    ACTUATOR_FROM_UNKNOWN
};

static McnNode_t _control_out_nod;
static McnNode_t _rc_channels_nod;
static uint8_t _actuator_cmd_device_num;
static actuator_cmd_device_info _actuator_cmd_device_list[MAX_DEVICE_NUM] = { 0 };
static actuator_send_list _actuator_send_list[MAX_DEVICE_NUM] = { 0 };
static uint8_t* from_dev;
static rt_device_t* to_dev;
static uint8_t mapping_num;
static actuator_mapping* mapping_list;

void list_actuator_devices(void)
{
    for (int i = 0; i < DEVICE_NUM; i++) {
        console_printf("[actuator %d]:\n", i);
        console_printf("type:%s\n", DEVICE_LIST[i].type);
        console_printf("name:%s\n", DEVICE_LIST[i].name);
        if (DEVICE_TYPE_IS(i, pwm)) {
            pwm_dev_config* config = (pwm_dev_config*)DEVICE_LIST[i].config;
            console_printf("freq:%d\n", config->freq);
            console_printf("chan-id:0x%02x\n", config->chan_idx);
            console_printf("range:[%d,%d]\n", config->range[0], config->range[1]);
        }
        console_printf("\n");
    }
}

static void _init_device_list(void)
{
    for (int i = 0; i < MAX_DEVICE_NUM; i++) {
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

static fmt_err_t _actuator_parse_device(const toml_table_t* curtab, int idx)
{
    fmt_err_t err = FMT_EOK;
    toml_array_t* arr;
    int i;
    const char* key;

    /* get device type */
    if (toml_string_in(curtab, "type", &DEVICE_LIST[idx].type) == 0) {
        if (DEVICE_TYPE_IS(idx, pwm)) {
            pwm_dev_config pwm_default_config = {
                .freq = 50,
                .chan_idx = 0x000F,
                .range = { 1000, 2000 }
            };
            DEVICE_LIST[idx].config = rt_malloc(sizeof(pwm_dev_config));

            /* set default value */
            if (DEVICE_LIST[idx].config) {
                *(pwm_dev_config*)DEVICE_LIST[idx].config = pwm_default_config;
            } else {
                TOML_DBG_E("Fail to malloc memory\n");
                return FMT_ENOMEM;
            }
        } else {
            TOML_DBG_E("Unknown device type: %s\n", DEVICE_LIST[idx].type);
            return FMT_ERROR;
        }
    } else {
        TOML_DBG_E("Fail to parse type value\n");
        return FMT_ERROR;
    }

    if (toml_string_in(curtab, "name", &DEVICE_LIST[idx].name) != 0) {
        TOML_DBG_E("Fail to parse name value\n");
        return FMT_ERROR;
    }

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(curtab, i)); i++) {
        if (MATCH(key, "type") || MATCH(key, "name")) {
            /* already handled */
            continue;
        }

        if (DEVICE_TYPE_IS(idx, pwm)) {
            pwm_dev_config* config = (pwm_dev_config*)DEVICE_LIST[idx].config;
            if (MATCH(key, "freq")) {
                int64_t ival;
                if (toml_int_in(curtab, key, &ival) == 0) {
                    config->freq = (uint32_t)ival;
                } else {
                    TOML_DBG_W("Fail to parse %s value\n", key);
                    continue;
                }
            } else if (MATCH(key, "chan-idx")) {
                int64_t ival;
                if (toml_int_in(curtab, key, &ival) == 0) {
                    config->chan_idx = (uint32_t)ival;
                } else {
                    TOML_DBG_W("Fail to parse %s value\n", key);
                    continue;
                }
            } else if (MATCH(key, "range")) {
                int64_t ival;
                int j;
                if (toml_array_value_in(curtab, key, &arr) == 0 && toml_array_nelem(arr) == 2) {
                    for (j = 0; j < 2; j++) {
                        if (toml_int_at(arr, j, &ival) == 0) {
                            config->range[j] = (uint16_t)ival;
                        } else {
                            TOML_DBG_W("Fail to parse %s value\n", key);
                            continue;
                        }
                    }
                }
            } else {
                TOML_DBG_W("Unknown config key: %s\n", key);
                continue;
            }
        } else {
            // unknown type
            continue;
        }
    }

    return err;
}

static fmt_err_t _actuator_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err_t err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = _actuator_parse_device(curtab, idx);

        if (err != FMT_EOK) {
            TOML_DBG_E("Device parse fail: %d\n", err);
            return FMT_ERROR;
        }

        if (++idx >= MAX_DEVICE_NUM) {
            TOML_DBG_W("Too many devices\n");
            break;
        }
    }

    DEVICE_NUM = idx;

    return err;
}

fmt_err_t send_hil_actuator_cmd(void)
{
    fmt_err_t err = FMT_EOK;
    DEFINE_TIMETAG(hil_actuator_tt, 20);

    if (_control_out_nod == NULL) {
        _control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);
    }

    if (mcn_poll(_control_out_nod) && check_timetag(TIMETAG(hil_actuator_tt))) {
        Control_Out_Bus control_out;
        mavlink_hil_actuator_controls_t hil_actuator_ctrl;
        mavlink_message_t msg;
        mavlink_system_t mav_sys;

        mcn_copy(MCN_HUB(control_output), _control_out_nod, &control_out);

        /* send command by mavlink */
        mav_sys = mavproxy_get_system();

        hil_actuator_ctrl.time_usec = systime_now_us();
        hil_actuator_ctrl.mode = MAV_MODE_FLAG_SAFETY_ARMED;
        /* map to -1~1 */
        hil_actuator_ctrl.controls[0] = (float)control_out.actuator_cmd[0] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[1] = (float)control_out.actuator_cmd[1] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[2] = (float)control_out.actuator_cmd[2] * 0.002f - 3.0f;
        hil_actuator_ctrl.controls[3] = (float)control_out.actuator_cmd[3] * 0.002f - 3.0f;
        mavlink_msg_hil_actuator_controls_encode(mav_sys.sysid, mav_sys.compid, &msg, &hil_actuator_ctrl);

        err = mavproxy_send_immediate_msg(&msg, true);
    }

    return err;
}

fmt_err_t send_actuator_cmd(void)
{
    fmt_err_t err = FMT_EOK;
    int i, j;

    DEFINE_TIMETAG(actuator_intv, 2);

    if (check_timetag(TIMETAG(actuator_intv)) == 0) {
        return FMT_EBUSY;
    }

    for (i = 0; i < mapping_num; i++) {
        if (from_dev[i] == ACTUATOR_FROM_CONTROL_OUT) {
            if (mcn_poll(_control_out_nod)) {
                rt_size_t size;
                Control_Out_Bus control_out;
                uint16_t chan_sel = 0;
                uint16_t chan_val[16];

                mcn_copy(MCN_HUB(control_output), _control_out_nod, &control_out);

                for (j = 0; j < mapping_list[i].map_size; j++) {
                    rt_size_t wb;

                    size = mapping_list[i].map_size * sizeof(uint16_t);
                    /* set channel select according to to mapping */
                    chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                    /* set channel value according to from mapping */
                    chan_val[j] = control_out.actuator_cmd[mapping_list[i].from_map[j] - 1];
                    /* write actuator command */
                    wb = rt_device_write(to_dev[i], chan_sel, chan_val, size);

                    if (wb != size) {
                        err = FMT_ERROR;
                    }
                }
            }
        } else if (from_dev[i] == ACTUATOR_FROM_RC_CHANNELS) {
            if (mcn_poll(_rc_channels_nod)) {
                rt_size_t size;
                int16_t rc_channel[16];
                uint16_t chan_val[16];
                uint16_t chan_sel = 0;

                mcn_copy(MCN_HUB(rc_channels), _rc_channels_nod, &rc_channel);

                for (j = 0; j < mapping_list[i].map_size; j++) {
                    rt_size_t wb;

                    size = mapping_list[i].map_size * sizeof(uint16_t);
                    /* set channel select according to to mapping */
                    chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                    /* set channel value according to from mapping */
                    chan_val[j] = rc_channel[mapping_list[i].from_map[j] - 1];
                    /* write actuator command */
                    wb = rt_device_write(to_dev[i], chan_sel, chan_val, size);

                    if (wb != size) {
                        err = FMT_ERROR;
                    }
                }
            }
        } else {
            continue;
        }
    }

    if (mcn_poll(_control_out_nod) && check_timetag(TIMETAG(actuator_intv))) {
        rt_size_t size;
        Control_Out_Bus control_out;

        mcn_copy(MCN_HUB(control_output), _control_out_nod, &control_out);

        for (i = 0; i < DEVICE_NUM; i++) {
            int cnt = 0;
            pwm_dev_config* config = (pwm_dev_config*)DEVICE_LIST[i].config;

            if (_actuator_send_list[i].chan_num == 0) {
                continue;
            }

            /* copy data to send list buffer */
            for (j = 0; j < 16 && cnt < _actuator_send_list[i].chan_num; j++) {
                if (config->chan_idx & (1 << j)) {
                    _actuator_send_list[i].buffer[cnt++] = control_out.actuator_cmd[j];
                }
            }

            size = rt_device_write(_actuator_send_list[i].dev, config->chan_idx,
                _actuator_send_list[i].buffer, _actuator_send_list[i].chan_num * sizeof(uint16_t));

            if (size != _actuator_send_list[i].chan_num * sizeof(uint16_t)) {
                err = FMT_ERROR;
            }
        }
    }

    return err;
}

fmt_err_t actuator_deinit(const rt_device_t dev)
{
    if (dev == NULL) {
        return FMT_ERROR;
    }

    if (rt_device_close(dev) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t actuator_toml_init(toml_table_t* table)
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
            _init_device_list();

            if (toml_array_table_in(table, key, &arr) == 0) {
                err = _actuator_parse_devices(arr);
                if (err != FMT_EOK) {
                    TOML_DBG_E("Fail to parse devices\n");
                    return err;
                }
            } else {
                TOML_DBG_E("Wrong element type: %s\n", key);
                return FMT_ERROR;
            }
        } else if (MATCH(key, "device")) {
            /* we get new device configuration, override original one */
            _init_device_list();

            if ((tab = toml_table_in(table, key)) != 0) {
                err = _actuator_parse_device(tab, 0);
                if (err != FMT_EOK) {
                    TOML_DBG_E("Fail to parse device\n");
                    return err;
                }
                DEVICE_NUM = 1;
            } else {
                TOML_DBG_E("Wrong element type: %s\n", key);
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_W("Unknown config key: %s\n", key);
        }
    }

    if (err == FMT_EOK) {
        rt_device_t dev;
        motor_dev_t motor_dev;
        pwm_dev_config* config;
        int j;

        /* Open actuator device */
        for (i = 0; i < DEVICE_NUM; i++) {
            config = (pwm_dev_config*)DEVICE_LIST[i].config;

            if ((dev = rt_device_find(DEVICE_LIST[i].name)) == NULL) {
                TOML_DBG_E("Can not find device %s\n", DEVICE_LIST[i].name);
                return FMT_EEMPTY;
            }

            motor_dev = (motor_dev_t)dev;
            motor_dev->config.pwm_frequency = config->freq;
            motor_dev->config.motor_min_value = config->range[0];
            motor_dev->config.motor_max_value = config->range[1];

            if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
                TOML_DBG_E("Fail to open device %s\n", DEVICE_LIST[i].name);
                return FMT_EEMPTY;
            }

            /* init send list */
            _actuator_send_list[i].dev = dev;
            for (j = 0, _actuator_send_list[i].chan_num = 0; j < 16; j++) {
                if (config->chan_idx & (1 << j)) {
                    _actuator_send_list[i].chan_num++;
                }
            }

            if (_actuator_send_list[i].chan_num == 0) {
                continue;
            }

            _actuator_send_list[i].buffer = (uint16_t*)rt_malloc(_actuator_send_list[i].chan_num * sizeof(uint16_t));
            if (_actuator_send_list[i].buffer == NULL) {
                TOML_DBG_E("Fail to malloc\n");
                return FMT_ENOMEM;
            }
        }
    }

    return err;
}

fmt_err_t actuator_init(void)
{
    _control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);
    if (_control_out_nod == NULL) {
        return FMT_ERROR;
    }

    _rc_channels_nod = mcn_subscribe(MCN_HUB(rc_channels), NULL, NULL);
    if (_rc_channels_nod == NULL) {
        return FMT_ERROR;
    }

    mapping_num = actuator_toml_get_mapping_num();
    mapping_list = actuator_toml_get_mapping_list();

    from_dev = (uint8_t*)rt_malloc(sizeof(uint8_t) * mapping_num);
    to_dev = (rt_device_t*)rt_malloc(sizeof(rt_device_t) * mapping_num);
    if (from_dev == NULL || to_dev == NULL) {
        return FMT_ENOMEM;
    }

    for (int i = 0; i < mapping_num; i++) {
        if (strcmp(mapping_list[i].from, "control_out") == 0) {
            from_dev[i] = ACTUATOR_FROM_CONTROL_OUT;
        } else if (strcmp(mapping_list[i].from, "rc_channels") == 0) {
            from_dev[i] = ACTUATOR_FROM_RC_CHANNELS;
        } else {
            from_dev[i] = ACTUATOR_FROM_UNKNOWN;
        }

        to_dev[i] = rt_device_find(mapping_list[i].to);
    }

    return FMT_EOK;
}
