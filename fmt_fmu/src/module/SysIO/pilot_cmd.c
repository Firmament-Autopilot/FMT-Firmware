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

#include "hal/rc.h"
#include "module/fms/fms_model.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/pilot_cmd.h"

/* channel index start from 0 */
#define CHAN_IDX(_stick_idx) (stickMapping[_stick_idx] - 1)

enum {
    STICK_YAW = 0,
    STICK_THRO = 1,
    STICK_ROLL = 2,
    STICK_PITCH = 3,
};

uint8_t modeNum = 0;
uint8_t eventCmdNum = 0;
uint8_t statusCmdNum = 0;
pilot_mode_config* pilotModes = NULL;
pilot_event_cmd_t* pilotEventCmds = NULL;

static rt_device_t rcDev = NULL;
static uint8_t stickMapping[4] = { 0 };
static int16_t rcChannel[16] = { 0 };

static uint16_t rc_read_mask = RC_MASK_1_6;
static uint8_t rc_chan_num;
static Pilot_Cmd_Bus pilot_cmd_bus;

/* Define uMCN topic */
MCN_DEFINE(pilot_cmd, sizeof(Pilot_Cmd_Bus));
MCN_DEFINE(rc_channels, sizeof(rcChannel));

static int echo_pilot_cmd(void* parameter)
{
    fmt_err_t err;
    Pilot_Cmd_Bus pilot_cmd;

    err = mcn_copy_from_hub((McnHub*)parameter, &pilot_cmd);

    if (err != FMT_EOK)
        return -1;

    console_printf("ls_lr:%.2f ls_ud:%.2f rs_lr:%.2f rs_ud:%.2f mode:%d cmd:[%d %d]\n",
        pilot_cmd.ls_lr, pilot_cmd.ls_ud, pilot_cmd.rs_lr, pilot_cmd.rs_ud, pilot_cmd.mode,
        pilot_cmd.cmd_1, pilot_cmd.cmd_2);

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
        console_printf("%d,", rc_chan_val[i]);
    }
    console_printf("]\n");

    return 0;
}

static void mavlink_send_pilot_cmd(void)
{
    mavlink_message_t msg;
    mavlink_fmt_pilot_cmd_t mav_pilot_cmd;
    mavlink_system_t mav_sys = mavproxy_get_system();

    mav_pilot_cmd.timestamp = pilot_cmd_bus.timestamp;
    mav_pilot_cmd.ls_lr = pilot_cmd_bus.ls_lr;
    mav_pilot_cmd.ls_ud = pilot_cmd_bus.ls_ud;
    mav_pilot_cmd.rs_lr = pilot_cmd_bus.rs_lr;
    mav_pilot_cmd.rs_ud = pilot_cmd_bus.rs_ud;
    mav_pilot_cmd.mode = pilot_cmd_bus.mode;
    mav_pilot_cmd.command_1 = pilot_cmd_bus.cmd_1;
    mav_pilot_cmd.command_2 = pilot_cmd_bus.cmd_2;

    mavlink_msg_fmt_pilot_cmd_encode(mav_sys.sysid, mav_sys.compid, &msg, &mav_pilot_cmd);

    mavproxy_send_immediate_msg(&msg, false);
}

static void stick_mapping(Pilot_Cmd_Bus* pilot_cmd, const int16_t chan_val[])
{
    RT_ASSERT(stickMapping[0] && stickMapping[1] && stickMapping[2] && stickMapping[3]);

    struct rc_configure config = ((rc_dev_t)rcDev)->config;
    float scale = 2.0f / (float)(config.rc_max_value - config.rc_min_value);
    float offset = -1.0f;

    pilot_cmd->ls_lr = (float)(chan_val[CHAN_IDX(STICK_YAW)] - config.rc_min_value) * scale + offset;
    pilot_cmd->ls_ud = (float)(chan_val[CHAN_IDX(STICK_THRO)] - config.rc_min_value) * scale + offset;
    pilot_cmd->rs_lr = (float)(chan_val[CHAN_IDX(STICK_ROLL)] - config.rc_min_value) * scale + offset;
    pilot_cmd->rs_ud = (float)(chan_val[CHAN_IDX(STICK_PITCH)] - config.rc_min_value) * scale + offset;
}

static void mode_switch(Pilot_Cmd_Bus* pilot_cmd, int16_t* rc_channel)
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
                break;
            }
        }
        // TODO: support multi-channel mapping
    }
}

static void generate_cmd(Pilot_Cmd_Bus* pilot_cmd, int16_t* rc_channel)
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
    }
    /* command lasts for 200ms */
    if (time_now - _last_cmd_timestamp > 200) {
        pilot_cmd_bus.cmd_1 = 0;
    }

    /* command 2: status command */
#ifdef FMT_TEST_MOTOR
    pilot_cmd_bus.cmd_2 = FMS_CMD_TEST_MOTOR;
#else
    pilot_cmd_bus.cmd_2 = 0;
#endif
}

fmt_err_t pilot_cmd_collect(void)
{
    RT_ASSERT(rcDev != NULL);

    uint8_t update = 0;

    FMT_CHECK_RETURN(rt_device_control(rcDev, RC_CMD_CHECK_UPDATE, &update));

    if (update) {
        if (rt_device_read(rcDev, rc_read_mask, rcChannel, rc_chan_num * sizeof(uint16_t))) {

            pilot_cmd_bus.timestamp = systime_now_ms();

            /* publish rc_channel topic */
            mcn_publish(MCN_HUB(rc_channels), rcChannel);

            /* stick value mapping */
            stick_mapping(&pilot_cmd_bus, rcChannel);
            /* pilot mode switch */
            mode_switch(&pilot_cmd_bus, rcChannel);
            /* generate pilot command */
            generate_cmd(&pilot_cmd_bus, rcChannel);

            /* publish pilot_cmd topic */
            mcn_publish(MCN_HUB(pilot_cmd), &pilot_cmd_bus);

#ifdef FMT_OUTPUT_PILOT_CMD
            /* send out pilot_cmd via mavlink */
            mavlink_send_pilot_cmd();
#endif
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
    FMT_CHECK_RETURN(rt_device_open(new_dev, RT_DEVICE_OFLAG_RDWR));

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

fmt_err_t pilot_cmd_init(void)
{
    /* advertise pilot command topic */
    FMT_CHECK(mcn_advertise(MCN_HUB(pilot_cmd), echo_pilot_cmd));
    FMT_CHECK(mcn_advertise(MCN_HUB(rc_channels), echo_rc_channels));

    /* set default pilot_cmd device */
    FMT_CHECK(pilot_cmd_set_device("rc"));

    /* set default stick mapping */
    pilot_cmd_map_stick(4, 3, 1, 2);

    pilot_cmd_set_chan_num(6);

    return FMT_EOK;
}