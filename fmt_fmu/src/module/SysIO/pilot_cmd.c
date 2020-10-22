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

#include "hal/rc.h"
#include "module/fms/fms_model.h"
#include "module/sysio/pilot_cmd.h"
#include "task/task_comm.h"
#include "task/task_fmtio.h"

#define TOML_DBG(...)   console_printf(__VA_ARGS__)
#define TOML_DBG_E(...) toml_debug("Pilot_Cmd", "E", __VA_ARGS__)
#define TOML_DBG_W(...) toml_debug("Pilot_Cmd", "W", __VA_ARGS__)
#define MATCH(a, b) (strcmp(a, b) == 0)

#define PILOT_CMD_MAX_DEVICE_NUM 1

// Channel Mapping Index
#define PILOT_LS_LR_MAPPING_IDX       0
#define PILOT_LS_UD_MAPPING_IDX       1
#define PILOT_RS_LR_MAPPING_IDX       2
#define PILOT_RS_UD_MAPPING_IDX       3
#define PILOT_MODE_MAPPING_IDX        4
#define PILOT_SAFE_SWITCH_MAPPING_IDX 5
// Default Channel Mapping
#define PILOT_LS_LR_CHANNEL       3
#define PILOT_LS_UD_CHANNEL       2
#define PILOT_RS_LR_CHANNEL       0
#define PILOT_RS_UD_CHANNEL       1
#define PILOT_MODE_CHANNEL        4
#define PILOT_SAFE_SWITCH_CHANNEL 5

typedef struct {
    uint16_t protocol;
    uint16_t channel_num;
    float sample_time;
    int16_t range[2];
} pilot_cmd_rc_dev_config;

typedef struct {
    char* type;
    char* name;
    void* config;
} pilot_cmd_device_info;

typedef struct {
    int8_t mode;
    int8_t chan_dim;
    int8_t* channel;
    int16_t* range;
} pilot_mode_config;

typedef struct {
    int32_t cmd;
    int8_t chan_dim;
    int8_t* channel;
    int16_t* range;
    uint8_t _set;
} pilot_event_cmd_t;

static int8_t stickMapping[4] = { 0, 0, 0, 0 }; // [ls_lr,ls_ud,rs_lr,rs_ud]
static uint8_t modeNum = 0;
static pilot_mode_config* pilotModes = NULL;
static uint8_t eventCmdNum = 0;
static pilot_event_cmd_t* pilotEventCmds = NULL;
static uint8_t statusCmdNum = 0;
static pilot_cmd_device_info rcDevInfo;
static rt_device_t rcDev = NULL;
int16_t rcChannel[16] = { 0 };

static uint16_t _rc_read_mask = RC_MASK_1_6;
static Pilot_Cmd_Bus _pilot_cmd;

/* Define uMCN topic */
MCN_DEFINE(pilot_cmd, sizeof(Pilot_Cmd_Bus));
MCN_DEFINE(rc_raw, sizeof(rcChannel));

void list_pilot_cmd_devices(void)
{
    // for (int i = 0; i < DEVICE_NUM; i++) {
    //     pilot_cmd_rc_dev_config* config = (pilot_cmd_rc_dev_config*)DEVICE_LIST[i].config;
    //     console_printf("[pilot_cmd d0]:\n");
    //     console_printf("type:%s\n", DEVICE_LIST[i].type);
    //     console_printf("name:%s\n", DEVICE_LIST[i].name);
    //     console_printf("protocol:%d\n", config->protocol);
    //     console_printf("channel-num:%d\n", config->channel_num);
    // }
}

void print_channel_mapping(void)
{
    // console_printf("ls_lr => %d\n", _rc_channel_mapping[PILOT_LS_LR_MAPPING_IDX]);
    // console_printf("ls_ud => %d\n", _rc_channel_mapping[PILOT_LS_UD_MAPPING_IDX]);
    // console_printf("rs_lr => %d\n", _rc_channel_mapping[PILOT_RS_LR_MAPPING_IDX]);
    // console_printf("rs_ud => %d\n", _rc_channel_mapping[PILOT_RS_UD_MAPPING_IDX]);
    // console_printf("mode => %d\n", _rc_channel_mapping[PILOT_MODE_MAPPING_IDX]);
    // console_printf("safe-switch => %d\n", _rc_channel_mapping[PILOT_SAFE_SWITCH_MAPPING_IDX]);

    int i;

    pilot_cmd_rc_dev_config* config = (pilot_cmd_rc_dev_config*)rcDevInfo.config;
    console_printf("type:%s\n", rcDevInfo.type);
    console_printf("name:%s\n", rcDevInfo.name);
    console_printf("protocol:%d\n", config->protocol);
    console_printf("channel-num:%d\n", config->channel_num);
    console_printf("sample time:%f\n", config->sample_time);
    console_printf("range: [%d %d]\n", config->range[0], config->range[1]);

    for (i = 0; i < modeNum; i++) {
        console_printf("[mode %d]:\n", i);
        console_printf("mode:%d\n", pilotModes[i].mode);
        console_printf("channel:%d\n", pilotModes[i].channel[0]);
        console_printf("dim:%d\n", pilotModes[i].chan_dim);
        console_printf("range:%d %d\n", pilotModes[i].range[0], pilotModes[i].range[1]);
    }

    for (i = 0; i < eventCmdNum; i++) {
        console_printf("[event cmd %d]:\n", i);
        console_printf("cmd:%d\n", pilotEventCmds[i].cmd);
        console_printf("channel:%d\n", pilotEventCmds[i].channel[0]);
        console_printf("dim:%d\n", pilotEventCmds[i].chan_dim);
        console_printf("range:%d %d\n", pilotEventCmds[i].range[0], pilotEventCmds[i].range[1]);
    }
}

static fmt_err _pilot_cmd_parse_command(const toml_array_t* curarr)
{
    int i, j;
    toml_raw_t raw;
    toml_table_t* tab;
    toml_array_t* arr;
    int64_t ival;

    if (pilotEventCmds) {
        rt_free(pilotEventCmds);
        pilotEventCmds = NULL;
    }

    /* first count the number of event command and status command */
    for (i = 0; 0 != (tab = toml_table_at(curarr, i)); i++) {
        if ((raw = toml_raw_in(tab, "type")) != 0) {
            if (toml_rtoi(raw, &ival) == 0) {
                if (ival == 1) {
                    eventCmdNum++;
                } else if (ival == 2) {
                    statusCmdNum++;
                } else {
                    TOML_DBG_E("wrong command type: %d\n", ival);
                    return FMT_ERROR;
                }
            } else {
                TOML_DBG_E("fail to parse command type\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("missing command type\n");
            return FMT_ERROR;
        }
    }

    /* memory allocation */
    pilotEventCmds = (pilot_event_cmd_t*)rt_malloc(sizeof(pilot_event_cmd_t) * eventCmdNum);
    if (pilotEventCmds == NULL) {
        TOML_DBG_E("fail to malloc memory\n");
        return FMT_ERROR;
    }

    /* start to parse command */
    int eventCmdIdx = 0;
    for (i = 0; 0 != (tab = toml_table_at(curarr, i)); i++) {
        /* get command type */
        if ((raw = toml_raw_in(tab, "type")) != 0) {
            if (toml_rtoi(raw, &ival) != 0) {
                TOML_DBG_E("fail to parse command type\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("undefine command type\n");
            return FMT_ERROR;
        }

        /* parse event command */
        if (ival == 1) {
            pilotEventCmds[eventCmdIdx]._set = 0;

            if ((raw = toml_raw_in(tab, "cmd")) != 0) {
                if (toml_rtoi(raw, &ival) == 0) {
                    pilotEventCmds[eventCmdIdx].cmd = (int32_t)ival;
                } else {
                    TOML_DBG_E("fail to parse event command\n");
                    return FMT_ERROR;
                }
            }

            if ((raw = toml_raw_in(tab, "channel")) != 0) {
                if (toml_rtoi(raw, &ival) == 0) {
                    pilotEventCmds[eventCmdIdx].channel = (int8_t*)rt_malloc(1);
                    if (pilotEventCmds[eventCmdIdx].channel) {
                        *pilotEventCmds[eventCmdIdx].channel = (int8_t)ival;
                    } else {
                        TOML_DBG_E("malloc fail\n");
                        return FMT_ERROR;
                    }
                } else {
                    TOML_DBG_E("fail to parse event command channel\n");
                    return FMT_ERROR;
                }
                pilotEventCmds[eventCmdIdx].chan_dim = 1; // single channel mapping
            } else if ((arr = toml_array_in(tab, "channel")) != 0) {
                // TBA: multi-channel mapping
                TOML_DBG_E("do not support multi-channel mapping now\n");
                return FMT_ERROR;
            } else {
                return FMT_ERROR;
            }

            if ((arr = toml_array_in(tab, "range")) != 0) {
                if ((pilotEventCmds[eventCmdIdx].range = (int16_t*)rt_malloc(pilotEventCmds[eventCmdIdx].chan_dim * 2)) == NULL) {
                    TOML_DBG_E("malloc fail\n");
                    return FMT_ERROR;
                }

                if (pilotEventCmds[eventCmdIdx].chan_dim == 1) {
                    for (j = 0; (raw = toml_raw_at(arr, j)) && j < 2; j++) {
                        if (toml_rtoi(raw, &ival) == 0) {
                            pilotEventCmds[eventCmdIdx].range[j] = (int16_t)ival;
                        } else {
                            TOML_DBG_E("fail to parse event command range\n");
                            return FMT_ERROR;
                        }
                    }
                } else {
                    // TBA: multi-channel mapping
                    TOML_DBG_E("do not support multi-channel mapping now\n");
                    return FMT_ERROR;
                }
            }

            eventCmdIdx++;
        } else {
            /* TODO, parse status command */
            console_printf("do not support status command yet\n");
            return FMT_ERROR;
        }
    }

    return FMT_EOK;
}

static fmt_err _pilot_cmd_parse_mode(const toml_array_t* curarr)
{
    int i, j;
    toml_raw_t raw;
    toml_table_t* tab;
    toml_array_t* arr;
    int64_t ival;

    if (pilotModes) {
        rt_free(pilotModes);
        pilotModes = NULL;
    }

    pilotModes = (pilot_mode_config*)rt_malloc(toml_array_nelem(curarr) * sizeof(pilot_mode_config));
    if (pilotModes == NULL) {
        TOML_DBG_E("malloc fail\n");
        return FMT_ERROR;
    }

    for (i = 0; 0 != (tab = toml_table_at(curarr, i)); i++) {
        if ((raw = toml_raw_in(tab, "mode")) != 0) {
            if (toml_rtoi(raw, &ival) == 0) {
                pilotModes[i].mode = (int8_t)ival;
            } else {
                TOML_DBG_E("fail to parse mode\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("missing mode\n");
            return FMT_ERROR;
        }

        if ((raw = toml_raw_in(tab, "channel")) != 0) {
            if (toml_rtoi(raw, &ival) == 0) {
                pilotModes[i].channel = (int8_t*)rt_malloc(1);
                if (pilotModes[i].channel) {
                    *pilotModes[i].channel = (int8_t)ival;
                } else {
                    TOML_DBG_E("malloc fail\n");
                    return FMT_ERROR;
                }
            } else {
                TOML_DBG_E("fail to parse channel\n");
                return FMT_ERROR;
            }
            pilotModes[i].chan_dim = 1; // single channel mapping
        } else if ((arr = toml_array_in(tab, "channel")) != 0) {
            // TBA: multi-channel mapping
            console_printf("do not support multi-channel mapping now\n");
            return FMT_ERROR;
        } else {
            TOML_DBG_E("wrong channel type\n");
            return FMT_ERROR;
        }

        if ((arr = toml_array_in(tab, "range")) != 0) {
            if ((pilotModes[i].range = (int16_t*)rt_malloc(pilotModes[i].chan_dim * 2)) == NULL) {
                TOML_DBG_E("malloc fail\n");
                return FMT_ERROR;
            }

            if (pilotModes[i].chan_dim == 1) {
                for (j = 0; (raw = toml_raw_at(arr, j)) && j < 2; j++) {
                    if (toml_rtoi(raw, &ival) == 0) {
                        pilotModes[i].range[j] = (int16_t)ival;
                    } else {
                        TOML_DBG_E("fail to parse mode range\n");
                        return FMT_ERROR;
                    }
                }
            } else {
                // TBA: multi-channel mapping
                console_printf("do not support multi-channel mapping now\n");
                return FMT_ERROR;
            }
        }
    }

    modeNum = i;

    return FMT_EOK;
}

static fmt_err _pilot_cmd_parse_device(const toml_table_t* tab)
{
    fmt_err err = FMT_EOK;
    int i;
    toml_raw_t raw;
    toml_array_t* arr;
    int64_t ival;
    double dval;

    /* get device type */
    if ((raw = toml_raw_in(tab, "type")) != 0) {
        if (toml_rtos(raw, &rcDevInfo.type) != 0) {
            TOML_DBG("Error: fail to parse rc type value\n");
            err = FMT_ERROR;
        }

        if (MATCH(rcDevInfo.type, "rc")) {
            pilot_cmd_rc_dev_config rc_default_config = {
                .protocol = 1, // sbus
                .channel_num = 6,
                .sample_time = 0.05,
                .range = { 1000, 2000 }
            };

            if ((rcDevInfo.config = rt_malloc(sizeof(pilot_cmd_rc_dev_config))) != NULL) {
                /* set default value */
                *(pilot_cmd_rc_dev_config*)rcDevInfo.config = rc_default_config;
            } else {
                TOML_DBG("Error: fail to malloc memory for rc device config\n");
                err = FMT_ERROR;
            }
        } else {
            TOML_DBG("Error: unknown rc device type: %s\n", rcDevInfo.type);
            err = FMT_ERROR;
        }
    } else {
        TOML_DBG("Error: fail to parse rc type value\n");
        err = FMT_ERROR;
    }

    if (err != FMT_EOK) {
        return err;
    }

    pilot_cmd_rc_dev_config* config = (pilot_cmd_rc_dev_config*)rcDevInfo.config;
    /* parse device name */
    if (0 != (raw = toml_raw_in(tab, "name"))) {
        if (toml_rtos(raw, &rcDevInfo.name) != 0) {
            TOML_DBG("Error: fail to parse rc device name\n");
            return FMT_ERROR;
        }
    } else {
        TOML_DBG("Error: must define rc device name\n");
        return FMT_ERROR;
    }

    /* parse protocol */
    if (0 != (raw = toml_raw_in(tab, "protocol"))) {
        if (toml_rtoi(raw, &ival) == 0) {
            config->protocol = (uint16_t)ival;
        } else {
            TOML_DBG("Warning: fail to parse rc protocol\n");
        }
    } else {
        TOML_DBG("Warning: do not define rc protocol\n");
    }

    /* parse channel number */
    if (0 != (raw = toml_raw_in(tab, "channel-num"))) {
        if (toml_rtoi(raw, &ival) == 0) {
            config->channel_num = (uint16_t)ival;
        } else {
            TOML_DBG("Warning: fail to parse rc channel-num\n");
        }
    } else {
        TOML_DBG("Warning: do not define rc channel-num\n");
    }

    /* parse sample time */
    if (0 != (raw = toml_raw_in(tab, "sample-time"))) {
        if (toml_rtod(raw, &dval) == 0) {
            config->sample_time = (float)dval;
        } else {
            TOML_DBG("Warning: fail to parse rc sample-time\n");
        }
    } else {
        TOML_DBG("Warning: do not define rc sample-time\n");
    }

    /* parse rc range */
    if ((arr = toml_array_in(tab, "range")) != 0) {
        if (toml_array_kind(arr) == 'v' && toml_array_nelem(arr) == 2) {
            for (i = 0; i < 2; i++) {
                raw = toml_raw_at(arr, i);
                if (toml_rtoi(raw, &ival) == 0) {
                    config->range[i] = (int16_t)ival;
                } else {
                    TOML_DBG("Error: rc parse range fail\n");
                    return FMT_ERROR;
                }
            }
        } else {
            TOML_DBG("Warning: wrong rc range type\n");
        }
    } else {
        TOML_DBG("Warning: do not define rc range\n");
    }

    return err;
}

static int _pilot_cmd_echo(void* parameter)
{
    fmt_err err;
    Pilot_Cmd_Bus pilot_cmd;

    err = mcn_copy_from_hub((McnHub*)parameter, &pilot_cmd);

    if (err != FMT_EOK)
        return -1;

    console_printf("ls_lr:%.2f ls_ud:%.2f rs_lr:%.2f rs_ud:%.2f mode:%d cmd:[%d %d]\n",
        pilot_cmd.ls_lr, pilot_cmd.ls_ud, pilot_cmd.rs_lr, pilot_cmd.rs_ud, pilot_cmd.mode,
        pilot_cmd.cmd_1, pilot_cmd.cmd_2);

    return 0;
}

static int _rc_raw_echo(void* parameter)
{
    fmt_err err;
    int16_t rc_chan_val[16];
    pilot_cmd_rc_dev_config* config = (pilot_cmd_rc_dev_config*)rcDevInfo.config;

    if (config == NULL) {
        return -1;
    }

    err = mcn_copy_from_hub((McnHub*)parameter, rc_chan_val);

    if (err != FMT_EOK)
        return -1;

    console_printf("rc channel: [");
    for (int i = 0; i < config->channel_num; i++) {
        console_printf("%d,", rc_chan_val[i]);
    }
    console_printf("]\n");

    return 0;
}

void _mav_send_pilot_cmd(void)
{
    mavlink_message_t msg;
    mavlink_fmt_pilot_cmd_t mav_pilot_cmd;
    mavlink_system_t mav_sys = mavproxy_get_system();

    mav_pilot_cmd.timestamp = _pilot_cmd.timestamp;
    mav_pilot_cmd.ls_lr = _pilot_cmd.ls_lr;
    mav_pilot_cmd.ls_ud = _pilot_cmd.ls_ud;
    mav_pilot_cmd.rs_lr = _pilot_cmd.rs_lr;
    mav_pilot_cmd.rs_ud = _pilot_cmd.rs_ud;
    mav_pilot_cmd.mode = _pilot_cmd.mode;
    mav_pilot_cmd.command_1 = _pilot_cmd.cmd_1;
    mav_pilot_cmd.command_2 = _pilot_cmd.cmd_2;

    mavlink_msg_fmt_pilot_cmd_encode(mav_sys.sysid, mav_sys.compid, &msg, &mav_pilot_cmd);

    mavproxy_send_immediate_msg(&msg, 0);
}

void _mode_switch(Pilot_Cmd_Bus* pilot_cmd, int16_t* rc_channel)
{
    int i;
    int16_t val;

    pilot_cmd->mode = 0xFF; // unknow mode

    for (i = 0; i < modeNum; i++) {
        if (pilotModes[i].chan_dim == 1) {
            if (pilotModes[i].channel[0] < 1)
                continue;
            val = rc_channel[pilotModes[i].channel[0] - 1];
            if (val >= pilotModes[i].range[0] && val <= pilotModes[i].range[1]) {
                pilot_cmd->mode = pilotModes[i].mode;
            }
        }
        // TODO: support multi-channel mapping
    }
}

void _generate_cmd(Pilot_Cmd_Bus* pilot_cmd, int16_t* rc_channel)
{
    int i;
    int16_t val;
    uint8_t state_new;

    /* command history */
    static uint32_t _last_cmd_timestamp = 0;

    uint32_t time_now = systime_now_ms();

    /* command 1: event command */
    for (i = 0; i < eventCmdNum; i++) {
        if (pilotEventCmds[i].chan_dim == 1) {
            if (pilotEventCmds[i].channel[0] < 1)
                continue;
            val = rc_channel[pilotEventCmds[i].channel[0] - 1];
            if (val >= pilotEventCmds[i].range[0] && val <= pilotEventCmds[i].range[1]) {
                state_new = 1;
            } else {
                state_new = 0;
            }

            if (state_new != pilotEventCmds[i]._set) {
                if (state_new) {
                    /* set event command */
                    _pilot_cmd.cmd_1 = pilotEventCmds[i].cmd;
                    /* record last event command trigger time */
                    _last_cmd_timestamp = time_now;
                }

                pilotEventCmds[i]._set = state_new;

                /* only one command is allowed at the mean time */
                if (state_new)
                    break;
            }
        }
    }
    /* command lasts for 200ms */
    if (time_now - _last_cmd_timestamp > 200) {
        _pilot_cmd.cmd_1 = 0;
    }

    /* command 2: status command */
#ifdef FMT_TEST_MOTOR
    _pilot_cmd.cmd_2 = FMS_CMD_TEST_MOTOR;
#else
    _pilot_cmd.cmd_2 = 0;
#endif
}

uint8_t pilot_cmd_collect(void)
{
    rt_err_t rt_err;
    uint8_t update = 0;
    struct rc_configure config;
    pilot_cmd_rc_dev_config* dev_config = (pilot_cmd_rc_dev_config*)rcDevInfo.config;
    float scale;

    if (rcDev == NULL) {
        return -1;
    }

    /* check if stick is mapped */
    if (!stickMapping[0] || !stickMapping[1] || !stickMapping[2] || !stickMapping[3]) {
        return -1;
    }

    config = ((rc_dev_t)rcDev)->config;
    scale = 2.0f / (float)(config.rc_max_value - config.rc_min_value);

    rt_err = rt_device_control(rcDev, RC_CMD_CHECK_UPDATE, &update);

    if (rt_err == RT_EOK && update) {

        if (rt_device_read(rcDev, _rc_read_mask, rcChannel, dev_config->channel_num * 2)) {
            /* convert rc value to [-1 1] */
            _pilot_cmd.ls_lr = -1.0f + (float)(rcChannel[stickMapping[0] - 1] - config.rc_min_value) * scale;
            _pilot_cmd.ls_ud = -1.0f + (float)(rcChannel[stickMapping[1] - 1] - config.rc_min_value) * scale;
            _pilot_cmd.rs_lr = -1.0f + (float)(rcChannel[stickMapping[2] - 1] - config.rc_min_value) * scale;
            _pilot_cmd.rs_ud = -1.0f + (float)(rcChannel[stickMapping[3] - 1] - config.rc_min_value) * scale;

            /* mode switch */
            _mode_switch(&_pilot_cmd, rcChannel);
            /* generate pilot command */
            _generate_cmd(&_pilot_cmd, rcChannel);
            /* update timestamp */
            _pilot_cmd.timestamp = systime_now_ms();
            /* publish pilot_cmd topic */
            mcn_publish(MCN_ID(pilot_cmd), &_pilot_cmd);
            /* publish rc_channel topic */
            mcn_publish(MCN_ID(rc_raw), rcChannel);

#ifdef FMT_OUTPUT_PILOT_CMD
            /* send out pilot_cmd via mavlink */
            _mav_send_pilot_cmd();
#endif
        }

        return 1;
    }

    return 0;
}

/* config pilot_cmd via toml system configuration file */
fmt_err pilot_cmd_toml_init(toml_table_t* table)
{
    int i, j;
    const char* key;
    toml_raw_t raw;
    toml_table_t* tab;
    toml_array_t* arr;
    int64_t ival;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "stick-channel")) {
            if ((arr = toml_array_in(table, key)) != 0) {
                if (toml_array_kind(arr) == 'v' && toml_array_nelem(arr) == 4) {
                    for (j = 0; j < 4; j++) {
                        raw = toml_raw_at(arr, j);
                        if (toml_rtoi(raw, &ival) == 0) {
                            stickMapping[j] = (int8_t)ival;
                        } else {
                            TOML_DBG_E("parse stick-channel fail\n");
                            return FMT_ERROR;
                        }
                    }
                } else {
                    TOML_DBG_E("wrong stick-channel definition\n");
                    return FMT_ERROR;
                }
            } else {
                TOML_DBG_E("wrong %s element type\n", key);
                return FMT_ERROR;
            }
        } else if (MATCH(key, "device")) {
            if ((tab = toml_table_in(table, key)) != 0) {
                if (_pilot_cmd_parse_device(tab) != FMT_EOK) {
                    TOML_DBG_E("device parse fail\n");
                    return FMT_ERROR;
                }
            } else {
                TOML_DBG_E("fail to parse device\n");
                return FMT_ERROR;
            }
        } else if (MATCH(key, "mode")) {
            if ((arr = toml_array_in(table, key)) != 0) {
                if (toml_array_kind(arr) == 't') {
                    if (_pilot_cmd_parse_mode(arr) != FMT_EOK) {
                        TOML_DBG_E("mode parse fail\n");
                        return FMT_ERROR;
                    }
                } else {
                    TOML_DBG_E("mode should be table array\n");
                    return FMT_ERROR;
                }
            } else {
                TOML_DBG_E("mode should be table array\n");
                return FMT_ERROR;
            }
        } else if (MATCH(key, "command")) {
            if ((arr = toml_array_in(table, key)) != 0) {
                if (toml_array_kind(arr) == 't') {
                    if (_pilot_cmd_parse_command(arr) != FMT_EOK) {
                        TOML_DBG_E("command parse fail\n");
                        return FMT_ERROR;
                    }
                } else {
                    TOML_DBG_E("command should be table array\n");
                    return FMT_ERROR;
                }
            } else {
                TOML_DBG_E("command should be table array\n");
                return FMT_ERROR;
            }
        } else {
            TOML_DBG_E("unknown key: %s\n", key);
            return FMT_ERROR;
        }
    }

    /* open rc device */
    if ((rcDev = rt_device_find(rcDevInfo.name)) == NULL) {
        return FMT_ERROR;
    }

    /* config rc device */
    pilot_cmd_rc_dev_config* config = (pilot_cmd_rc_dev_config*)rcDevInfo.config;
    rc_dev_t rc_dev = (rc_dev_t)rcDev;
    rc_dev->config.protocol = config->protocol;
    rc_dev->config.channel_num = config->channel_num;
    rc_dev->config.sample_time = config->sample_time;
    rc_dev->config.rc_min_value = config->range[0];
    rc_dev->config.rc_max_value = config->range[1];

    if (rt_device_open(rcDev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err pilot_cmd_init(void)
{
    /* advertise pilot command topic */
    if (mcn_advertise(MCN_ID(pilot_cmd), _pilot_cmd_echo) != FMT_EOK) {
        return FMT_ERROR;
    }

    /* advertise rc channel topic */
    if (mcn_advertise(MCN_ID(rc_raw), _rc_raw_echo) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}