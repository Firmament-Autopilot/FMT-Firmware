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

#include "hal/rc/rc.h"
#include "model/fms/fms_interface.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/pilot_cmd.h"

/* channel index start from 0 */
#define CHAN_IDX(_stick_idx) (stickMapping[_stick_idx] - 1)

uint8_t modeNum = 0;
uint8_t eventCmdNum = 0;
uint8_t statusCmdNum = 0;
pilot_mode_config* pilotModes = NULL;
pilot_event_cmd_t* pilotEventCmds = NULL;
pilot_status_cmd_t* pilotStatusCmds = NULL;

static rt_device_t rcDev;
static uint8_t stickMapping[4];
static int16_t rcChannel[16];
static int16_t rcTrimChannel[16];

static uint16_t rc_read_mask;
static uint8_t rc_chan_num;
static Pilot_Cmd_Bus pilot_cmd_bus;

/* Define uMCN topic */
MCN_DEFINE(pilot_cmd, sizeof(Pilot_Cmd_Bus));        /* FMS pilot command topic */
MCN_DEFINE(rc_channels, sizeof(rcChannel));          /* RC raw channels value topic */
MCN_DEFINE(rc_trim_channels, sizeof(rcTrimChannel)); /* RC calibrated channels value topic */

static int echo_pilot_cmd(void* parameter)
{
    fmt_err_t err;
    Pilot_Cmd_Bus pilot_cmd;

    err = mcn_copy_from_hub((McnHub*)parameter, &pilot_cmd);

    if (err != FMT_EOK)
        return -1;

    console_printf("stick_yaw:%.2f stick_throttle:%.2f stick_roll:%.2f stick_pitch:%.2f mode:%u cmd:[%u %u]\n",
                   pilot_cmd.stick_yaw,
                   pilot_cmd.stick_throttle,
                   pilot_cmd.stick_roll,
                   pilot_cmd.stick_pitch,
                   pilot_cmd.mode,
                   pilot_cmd.cmd_1,
                   pilot_cmd.cmd_2);

    return 0;
}

static int echo_rc_channels(void* parameter)
{
    fmt_err_t err;
    int16_t rc_chan_val[16];

    err = mcn_copy_from_hub((McnHub*)parameter, rc_chan_val);

    if (err != FMT_EOK)
        return -1;

    console_printf("rc channel: [");
    for (int i = 0; i < rc_chan_num; i++) {
        if (i == rc_chan_num - 1) {
            console_printf("%d]\n", rc_chan_val[i]);
        } else {
            console_printf("%d,", rc_chan_val[i]);
        }
    }

    return 0;
}

#ifdef FMT_OUTPUT_PILOT_CMD
static void mavlink_send_pilot_cmd(void)
{
    mavlink_message_t msg;
    mavlink_fmt_pilot_cmd_t mav_pilot_cmd;
    mavlink_system_t mav_sys = mavproxy_get_system();

    mav_pilot_cmd.timestamp = pilot_cmd_bus.timestamp;
    mav_pilot_cmd.ls_lr = pilot_cmd_bus.stick_yaw;
    mav_pilot_cmd.ls_ud = pilot_cmd_bus.stick_throttle;
    mav_pilot_cmd.rs_lr = pilot_cmd_bus.stick_roll;
    mav_pilot_cmd.rs_ud = pilot_cmd_bus.stick_pitch;
    mav_pilot_cmd.mode = pilot_cmd_bus.mode;
    mav_pilot_cmd.command_1 = pilot_cmd_bus.cmd_1;
    mav_pilot_cmd.command_2 = pilot_cmd_bus.cmd_2;

    mavlink_msg_fmt_pilot_cmd_encode(mav_sys.sysid, mav_sys.compid, &msg, &mav_pilot_cmd);

    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, false);
}
#endif

static void rc_channels_trim(const int16_t raw_chan_val[], int16_t trim_chan_val[])
{
    float rc_max, rc_min, rc_rev, rc_trim;
    float p;
    int32_t start_idx = param_get_index(PARAM_GET(RC, RC1_MAX));
    if (start_idx < 0) {
        /* Fail to find RC1_MAX parameter */
        return;
    }

    for (uint8_t i = 0; i < 16; i++) {
        rc_max = PARAM_VALUE_FLOAT(param_get_by_index(start_idx + i * 4));
        rc_min = PARAM_VALUE_FLOAT(param_get_by_index(start_idx + i * 4 + 1));
        rc_rev = PARAM_VALUE_FLOAT(param_get_by_index(start_idx + i * 4 + 2));
        rc_trim = PARAM_VALUE_FLOAT(param_get_by_index(start_idx + i * 4 + 3));

        if (raw_chan_val[i] > rc_trim) {
            p = (float)(raw_chan_val[i] - rc_trim) / (rc_max - rc_trim);
        } else {
            p = (float)(raw_chan_val[i] - rc_trim) / (rc_trim - rc_min);
        }

        /* saturate proportion and apply reverse */
        p = constrain_float(p, -1.0f, 1.0f) * rc_rev;
        /* calculate calibrated rc channel value, with range of [1000, 2000] */
        trim_chan_val[i] = p * 500 + 1500;
    }
}

static void stick_mapping(Pilot_Cmd_Bus* pilot_cmd, const int16_t chan_val[])
{
    RT_ASSERT(stickMapping[0] && stickMapping[1] && stickMapping[2] && stickMapping[3]);

    struct rc_configure config = ((rc_dev_t)rcDev)->config;
    float scale = 2.0f / (float)(config.rc_max_value - config.rc_min_value);
    float offset = -1.0f;

    pilot_cmd->stick_yaw = (float)(chan_val[CHAN_IDX(STICK_YAW)] - config.rc_min_value) * scale + offset;
    pilot_cmd->stick_throttle = (float)(chan_val[CHAN_IDX(STICK_THRO)] - config.rc_min_value) * scale + offset;
    pilot_cmd->stick_roll = (float)(chan_val[CHAN_IDX(STICK_ROLL)] - config.rc_min_value) * scale + offset;
    pilot_cmd->stick_pitch = (float)(chan_val[CHAN_IDX(STICK_PITCH)] - config.rc_min_value) * scale + offset;
}

static void mode_switch(Pilot_Cmd_Bus* pilot_cmd, int16_t* rc_channel)
{
    int i, j;
    int16_t val;
    bool in_range;

    pilot_cmd->mode = 0xFF; // unknow mode

    for (i = 0; i < modeNum; i++) {
        in_range = true;

        for (j = 0; j < pilotModes[i].chan_dim; j++) {
            if (pilotModes[i].channel[j] < 1) {
                /* invalid channel */
                in_range = false;
                break;
            }

            val = rc_channel[pilotModes[i].channel[j] - 1];
            if (val < pilotModes[i].range[j * 2] || val > pilotModes[i].range[j * 2 + 1]) {
                /* channel value out of range */
                in_range = false;
                break;
            }
        }

        if (in_range) {
            pilot_cmd->mode = pilotModes[i].mode;
            /* Sync gcs mode with pilot_cmd mode */
            GCS_Cmd_Bus gcs_cmd = gcs_cmd_get();
            if (pilot_cmd->mode <= PilotMode_Offboard && gcs_cmd.mode != pilot_cmd->mode) {
                gcs_set_mode(pilot_cmd->mode);
            }
        }
    }
}

static void generate_cmd(Pilot_Cmd_Bus* pilot_cmd, int16_t* rc_channel)
{
    int i, j;
    int16_t val;
    uint8_t state_new;
    bool in_range;

    /* command history */
    static uint32_t _last_cmd_timestamp = 0;

    uint32_t time_now = systime_now_ms();

    /* command 1: event command */
    for (i = 0; i < eventCmdNum; i++) {
        in_range = true;

        for (j = 0; j < pilotEventCmds[i].chan_dim; j++) {
            if (pilotEventCmds[i].channel[j] < 1) {
                /* invalid channel */
                in_range = false;
                break;
            }

            val = rc_channel[pilotEventCmds[i].channel[j] - 1];
            if (val < pilotEventCmds[i].range[j * 2] || val > pilotEventCmds[i].range[j * 2 + 1]) {
                /* channel value out of range */
                in_range = false;
                break;
            }
        }

        if (in_range) {
            state_new = 1;
        } else {
            state_new = 0;
        }

        if (state_new != pilotEventCmds[i]._set) {
            if (state_new) {
                /* set event command */
                pilot_cmd_bus.cmd_1 = pilotEventCmds[i].cmd;
                /* record last event command trigger time */
                _last_cmd_timestamp = time_now;
            }

            pilotEventCmds[i]._set = state_new;

            /* only one command is allowed at the same time */
            if (state_new)
                break;
        }
    }
    /* the command need to last at least FMS_CONST.dt */
    if (time_now - _last_cmd_timestamp > 100) {
        pilot_cmd_bus.cmd_1 = 0;
    }

    /* command 2: status command */
    for (i = 0; i < statusCmdNum; i++) {
        in_range = true;

        for (j = 0; j < pilotStatusCmds[i].chan_dim; j++) {
            if (pilotStatusCmds[i].channel[j] < 1) {
                /* invalid channel */
                in_range = false;
                break;
            }

            val = rc_channel[pilotStatusCmds[i].channel[j] - 1];
            if (val < pilotStatusCmds[i].range[j * 2] || val > pilotStatusCmds[i].range[j * 2 + 1]) {
                /* channel value out of range */
                in_range = false;
                break;
            }
        }

        if (in_range) {
            pilot_cmd_bus.cmd_2 = pilotStatusCmds[i].cmd;
        } else {
            pilot_cmd_bus.cmd_2 = 0;
        }
    }
}

fmt_err_t pilot_cmd_collect(void)
{
    static uint32_t last_timestamp;
    uint32_t time_now = systime_now_ms();
    uint8_t update = 0;
    rc_dev_t rc = (rc_dev_t)rcDev;

    if (rcDev == NULL) {
        /* no rc device */
        return FMT_ENOTHANDLE;
    }

    FMT_TRY(rt_device_control(rcDev, RC_CMD_CHECK_UPDATE, &update));

    if (update && ((time_now - last_timestamp) >= rc->config.sample_time * 1000)) {
        if (rt_device_read(rcDev, rc_read_mask, rcChannel, rc_chan_num * sizeof(uint16_t))) {

            pilot_cmd_bus.timestamp = systime_now_ms();

            /* publish rc_channel topic */
            mcn_publish(MCN_HUB(rc_channels), rcChannel);

            /* calibrate rc channels value */
            rc_channels_trim(rcChannel, rcTrimChannel);
            /* publish rc_trim_channel topic */
            mcn_publish(MCN_HUB(rc_trim_channels), rcTrimChannel);

            /* stick value mapping */
            stick_mapping(&pilot_cmd_bus, rcTrimChannel);
            /* pilot mode switch */
            mode_switch(&pilot_cmd_bus, rcTrimChannel);
            /* generate pilot command */
            generate_cmd(&pilot_cmd_bus, rcTrimChannel);
            /* publish pilot_cmd topic */
            mcn_publish(MCN_HUB(pilot_cmd), &pilot_cmd_bus);

#ifdef FMT_OUTPUT_PILOT_CMD
            /* send out pilot_cmd via mavlink */
            mavlink_send_pilot_cmd();
#endif

            last_timestamp = time_now;
        }
    }

    return FMT_EOK;
}

fmt_err_t pilot_cmd_set_device(const char* dev_name)
{
    rt_device_t new_dev = rt_device_find(dev_name);

    if (new_dev == NULL) {
        return FMT_EEMPTY;
    }

    /* close old device if opened */
    if (rcDev && (rcDev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
        rt_device_close(rcDev);
    }

    /* open new device */
    FMT_TRY(rt_device_open(new_dev, RT_DEVICE_OFLAG_RDWR));

    /* set new device */
    rcDev = new_dev;

    return FMT_EOK;
}

fmt_err_t pilot_cmd_set_chan_num(uint8_t chan_num)
{
    RT_ASSERT(chan_num >= 1 && chan_num <= 16);

    uint16_t mask = 0;

    for (uint16_t i = 0; i < chan_num; i++) {
        mask |= (1 << i);
    }

    rc_read_mask = mask;
    rc_chan_num = chan_num;

    return FMT_EOK;
}

uint8_t pilot_cmd_get_chan_num(void)
{
    return rc_chan_num;
}

fmt_err_t pilot_cmd_map_stick(
    uint8_t yaw_chan, uint8_t thro_chan, uint8_t roll_chan, uint8_t pitch_chan)
{
    RT_ASSERT(yaw_chan >= 1 && yaw_chan <= 16);
    RT_ASSERT(thro_chan >= 1 && thro_chan <= 16);
    RT_ASSERT(roll_chan >= 1 && roll_chan <= 16);
    RT_ASSERT(pitch_chan >= 1 && pitch_chan <= 16);

    stickMapping[STICK_YAW] = yaw_chan;
    stickMapping[STICK_THRO] = thro_chan;
    stickMapping[STICK_ROLL] = roll_chan;
    stickMapping[STICK_PITCH] = pitch_chan;

    return FMT_EOK;
}

uint8_t pilot_cmd_get_stick_chan(stick_enum stick)
{
    return CHAN_IDX(stick);
}

fmt_err_t pilot_cmd_init(void)
{
    /* advertise pilot command topic */
    FMT_CHECK(mcn_advertise(MCN_HUB(pilot_cmd), echo_pilot_cmd));
    FMT_CHECK(mcn_advertise(MCN_HUB(rc_channels), echo_rc_channels));
    FMT_CHECK(mcn_advertise(MCN_HUB(rc_trim_channels), echo_rc_channels));

    return FMT_EOK;
}