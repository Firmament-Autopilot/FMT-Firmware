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

#include "model/control/control_interface.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/actuator_config.h"

MCN_DECLARE(control_output);
MCN_DECLARE(rc_trim_channels);

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

fmt_err_t send_hil_actuator_cmd(uint16_t chan_mask, const uint16_t* chan_val)
{
    fmt_err_t err = FMT_EOK;
    DEFINE_TIMETAG(hil_actuator_tt, 20);

    if (check_timetag(TIMETAG(hil_actuator_tt))) {
        mavlink_hil_actuator_controls_t hil_actuator_ctrl;
        mavlink_message_t msg;
        mavlink_system_t mav_sys;
        uint8_t val_index = 0;

        /* send command by mavlink */
        mav_sys = mavproxy_get_system();

        hil_actuator_ctrl.time_usec = systime_now_us();
        hil_actuator_ctrl.mode = MAV_MODE_FLAG_SAFETY_ARMED;
        hil_actuator_ctrl.flags = 0;
        for (int i = 0; i < 16; i++) {
            if (chan_mask & (1 << i)) {
                /* map to -1~1 */
                hil_actuator_ctrl.controls[i] = (float)chan_val[val_index++] * 0.002f - 3.0f;
            } else {
                hil_actuator_ctrl.controls[i] = 0.0f;
            }
        }
        /* encode hil msg */
        mavlink_msg_hil_actuator_controls_encode(mav_sys.sysid, mav_sys.compid, &msg, &hil_actuator_ctrl);
        /* async mode to avoid block the task when usb is not connected */
        err = mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, false);
    }

    return err;
}

fmt_err_t send_actuator_cmd(void)
{
    fmt_err_t err = FMT_EOK;
    int i, j;
    bool has_poll_control_out = false;
    bool has_poll_rc_channels = false;
    Control_Out_Bus control_out;
    int16_t rc_channel[16];
    uint16_t chan_val[16] = { 0 };

    DEFINE_TIMETAG(actuator_intv, 2);

    if (check_timetag(TIMETAG(actuator_intv)) == 0) {
        return FMT_EBUSY;
    }

    for (i = 0; i < mapping_num; i++) {
        rt_size_t size = mapping_list[i].map_size;
        uint16_t chan_sel = 0;

        if (from_dev[i] == ACTUATOR_FROM_CONTROL_OUT) {
            if (has_poll_control_out == false) {
                if (mcn_poll(_control_out_nod) == false) {
                    return FMT_ERROR;
                }
                mcn_copy(MCN_HUB(control_output), _control_out_nod, &control_out);
                has_poll_control_out = true;
            }

            for (j = 0; j < mapping_list[i].map_size; j++) {
                /* set channel select according to to mapping */
                chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                /* set channel value according to from mapping */
                chan_val[j] = control_out.actuator_cmd[mapping_list[i].from_map[j] - 1];
            }
        } else if (from_dev[i] == ACTUATOR_FROM_RC_CHANNELS) {
            if (has_poll_rc_channels == false) {
                if (mcn_poll(_rc_channels_nod) == 0) {
                    return FMT_ERROR;
                }
                mcn_copy(MCN_HUB(rc_trim_channels), _rc_channels_nod, &rc_channel);
                has_poll_rc_channels = true;
            }

            for (j = 0; j < mapping_list[i].map_size; j++) {
                /* set channel select according to mapping */
                chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                /* set channel value according to from mapping */
                chan_val[j] = rc_channel[mapping_list[i].from_map[j] - 1];
            }
        } else {
            /* to avoid warning */
            (void)size;
            (void)chan_sel;
            (void)chan_val;
            continue;
        }

#if defined(FMT_HIL_WITH_ACTUATOR) || (!defined(FMT_USING_HIL) && !defined(FMT_USING_SIH))
        /* write actuator command */
        if (rt_device_write(to_dev[i], chan_sel, chan_val, size) != size) {
            err = FMT_ERROR;
        }
#endif

#if defined(FMT_USING_HIL) || defined(FMT_USING_SIH)
        send_hil_actuator_cmd(chan_sel, chan_val);
#endif
    }

    return err;
}

fmt_err_t actuator_init(void)
{
    _control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);
    if (_control_out_nod == NULL) {
        return FMT_ERROR;
    }

    _rc_channels_nod = mcn_subscribe(MCN_HUB(rc_trim_channels), NULL, NULL);
    if (_rc_channels_nod == NULL) {
        return FMT_ERROR;
    }

    mapping_num = actuator_toml_get_mapping_num();
    mapping_list = actuator_toml_get_mapping_list();

    if (mapping_num) {
        from_dev = (uint8_t*)rt_malloc(sizeof(uint8_t) * mapping_num);
        to_dev = (rt_device_t*)rt_malloc(sizeof(rt_device_t) * mapping_num);
        if (from_dev == NULL || to_dev == NULL) {
            return FMT_ENOMEM;
        }
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
