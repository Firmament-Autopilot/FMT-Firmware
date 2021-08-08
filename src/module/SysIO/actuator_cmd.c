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

#include "module/controller/controller_model.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/actuator_config.h"

MCN_DECLARE(control_output);
MCN_DECLARE(rc_channels);

enum {
    ACTUATOR_FROM_CONTROL_OUT,
    ACTUATOR_FROM_RC_CHANNELS,
    ACTUATOR_FROM_UNKNOWN
};

static McnNode_t _control_out_nod;
static McnNode_t _rc_channels_nod;
static uint8_t* from_dev;
static rt_device_t* to_dev;
static uint8_t mapping_num;
static actuator_mapping* mapping_list;

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
        if (to_dev[i] == NULL) {
            return FMT_EEMPTY;
        }
    }

    return FMT_EOK;
}
