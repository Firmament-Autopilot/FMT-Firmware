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

#include "hal/actuator/actuator.h"
#include "model/control/control_interface.h"
#include "module/config/actuator_config.h"
#include "module/mavproxy/mavproxy.h"

MCN_DECLARE(control_output);
MCN_DECLARE(rc_trim_channels);
MCN_DECLARE(mav_actuator_control);

enum {
    ACTUATOR_FROM_CONTROLLER,
    ACTUATOR_FROM_RC_CHANNEL,
    ACTUATOR_FROM_MAVLINK,
    ACTUATOR_FROM_UNKNOWN
};

static McnNode_t control_out_nod;
static McnNode_t rc_channels_nod;
static McnNode_t mav_actuator_control_nod;
static uint8_t* from_dev;
static rt_device_t* to_dev;
static uint8_t mapping_num;
static actuator_mapping* mapping_list;

fmt_err_t send_hil_actuator_cmd(uint16_t chan_mask, const uint16_t* chan_val)
{
    fmt_err_t err = FMT_EOK;
#if defined(FMT_USING_HIL)
    /* For hil simulation, we need faster actuator cmd send speed */
    DEFINE_TIMETAG(hil_actuator_tt, 4);
#else
    DEFINE_TIMETAG(hil_actuator_tt, 100);
#endif

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
    bool has_poll_mavlink = false;
    Control_Out_Bus control_out;
    int16_t rc_channel[16];
    uint16_t chan_val[16] = { 0 };

    for (i = 0; i < mapping_num; i++) {
        rt_size_t size = mapping_list[i].map_size;
        uint16_t chan_sel = 0;

        if (from_dev[i] == ACTUATOR_FROM_CONTROLLER) {
            if (has_poll_control_out == false) {
                if (mcn_poll(control_out_nod) == false) {
                    /* no control_out topic updated, continue for next mapping */
                    continue;
                }
                mcn_copy(MCN_HUB(control_output), control_out_nod, &control_out);
                has_poll_control_out = true;
            }

            for (j = 0; j < mapping_list[i].map_size; j++) {
                /* set channel select according to to mapping */
                chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                /* set channel value according to from mapping */
                chan_val[j] = control_out.actuator_cmd[mapping_list[i].from_map[j] - 1];
            }
        } else if (from_dev[i] == ACTUATOR_FROM_RC_CHANNEL) {
            if (has_poll_rc_channels == false) {
                if (mcn_poll(rc_channels_nod) == false) {
                    /* no rc_channels topic updated, continue for next mapping */
                    continue;
                }
                mcn_copy(MCN_HUB(rc_trim_channels), rc_channels_nod, &rc_channel);
                has_poll_rc_channels = true;
            }

            for (j = 0; j < mapping_list[i].map_size; j++) {
                /* set channel select according to mapping */
                chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                /* set channel value according to from mapping */
                chan_val[j] = rc_channel[mapping_list[i].from_map[j] - 1];
            }
        } else if (from_dev[i] == ACTUATOR_FROM_MAVLINK) {
            if (has_poll_mavlink == false) {
                if (mcn_poll(mav_actuator_control_nod) == false) {
                    /* no mav_actuator_control topic updated, continue for next mapping */
                    continue;
                }
                mcn_copy(MCN_HUB(mav_actuator_control), mav_actuator_control_nod, &control_out);
                has_poll_mavlink = true;
            }

            for (j = 0; j < mapping_list[i].map_size; j++) {
                /* set channel select according to mapping */
                chan_sel |= 1 << (mapping_list[i].to_map[j] - 1);
                /* set channel value according to from mapping */
                chan_val[j] = control_out.actuator_cmd[mapping_list[i].from_map[j] - 1];
            }
        } else {
            /* to avoid warning */
            (void)size;
            (void)chan_sel;
            (void)chan_val;
            continue;
        }

#if defined(FMT_SIM_WITH_ACTUATOR) || (!defined(FMT_USING_HIL) && !defined(FMT_USING_SIH))
        /* write actuator command */
        if (rt_device_write(to_dev[i], chan_sel, chan_val, size) != size) {
            err = FMT_ERROR;
        }
#endif

#if defined(FMT_USING_HIL) || defined(FMT_USING_SIH) || defined(FMT_USING_VR)
        send_hil_actuator_cmd(chan_sel, chan_val);
#endif
    }

    return err;
}

fmt_err_t actuator_init(void)
{
    control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL);
    if (control_out_nod == NULL) {
        return FMT_ERROR;
    }

    rc_channels_nod = mcn_subscribe(MCN_HUB(rc_trim_channels), NULL);
    if (rc_channels_nod == NULL) {
        return FMT_ERROR;
    }

    mav_actuator_control_nod = mcn_subscribe(MCN_HUB(mav_actuator_control), NULL);
    if (mav_actuator_control_nod == NULL) {
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
            from_dev[i] = ACTUATOR_FROM_CONTROLLER;
        } else if (strcmp(mapping_list[i].from, "rc_channels") == 0) {
            from_dev[i] = ACTUATOR_FROM_RC_CHANNEL;
        } else if (strcmp(mapping_list[i].from, "mav_actuator_control") == 0) {
            from_dev[i] = ACTUATOR_FROM_MAVLINK;
        } else {
            from_dev[i] = ACTUATOR_FROM_UNKNOWN;
        }

        to_dev[i] = rt_device_find(mapping_list[i].to);
        if (to_dev[i] == NULL) {
            return FMT_EEMPTY;
        }

        if (to_dev[i]->type == RT_Device_Class_Miscellaneous) {
            actuator_dev_t act_dev = (actuator_dev_t)to_dev[i];
            for (int j = 0; j < mapping_list[i].map_size; j++) {
                uint16_t to_chan = mapping_list[i].to_map[j];
                if (to_chan < 1 || to_chan > 16 || !(act_dev->chan_mask & (1 << (to_chan - 1)))) {
                    printf("Actuator error: invalid channel %d mapped to %s\n", to_chan, mapping_list[i].to);
                    return FMT_ERROR;
                }
            }
        }
    }

    return FMT_EOK;
}
