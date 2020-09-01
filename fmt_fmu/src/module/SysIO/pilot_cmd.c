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
#include "module/sysio/pilot_cmd.h"
#include "task/task_comm.h"

// Channel Mapping
#define PILOT_LS_LR_CHANNEL       3
#define PILOT_LS_UD_CHANNEL       2
#define PILOT_RS_LR_CHANNEL       0
#define PILOT_RS_UD_CHANNEL       1
#define PILOT_MODE_CHANNEL        4
#define PILOT_SAFE_SWITCH_CHANNEL 5

static rt_device_t _rc_dev;
static Pilot_Cmd_Bus _pilot_cmd;

// static uint8_t _kill_motor_cmd = 0;

/* Define uMCN topic */
MCN_DEFINE(pilot_cmd, sizeof(Pilot_Cmd_Bus));

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

void _generate_cmd(Pilot_Cmd_Bus* pilot_cmd, uint16_t* rc_val)
{
    /* command history */
    static uint8_t _force_disarm_cmd = 0;
    static uint32_t _last_cmd_timestamp = 0;

    uint32_t time_now = systime_now_ms();
    uint8_t force_disarm_cmd = rc_val[PILOT_SAFE_SWITCH_CHANNEL] > 1900;

    /* command 1: event command */
    if (force_disarm_cmd != _force_disarm_cmd) {
        if (force_disarm_cmd) {
            _pilot_cmd.cmd_1 = FMS_CMD_FORCE_DISARM;
        }

        _force_disarm_cmd = force_disarm_cmd;
        _last_cmd_timestamp = time_now;
    }

    // command lasts for 200ms
    if (time_now - _last_cmd_timestamp > 200) {
        _pilot_cmd.cmd_1 = _pilot_cmd.cmd_2 = 0;
    }

    /* command 2: state command */
#ifdef FMT_TEST_MOTOR
    _pilot_cmd.cmd_2 = FMS_CMD_TEST_MOTOR;
#else
    _pilot_cmd.cmd_2 = 0;
#endif
}

uint8_t pilot_cmd_collect(void)
{
    uint8_t update;
    uint16_t rc_val[6];
    struct rc_configure config;

    RT_ASSERT(_rc_dev != NULL);

    config = ((rc_dev_t)_rc_dev)->config;

    float range = (float)(config.rc_max_value - config.rc_min_value);

    rt_device_control(_rc_dev, RC_CMD_CHECK_UPDATE, &update);

    if (update) {
        if (rt_device_read(_rc_dev, RC_MASK_1_6, rc_val, 12)) {
            _pilot_cmd.ls_lr = -1.0f + (float)(rc_val[PILOT_LS_LR_CHANNEL] - config.rc_min_value) / range * 2.0f;
            _pilot_cmd.ls_ud = -1.0f + (float)(rc_val[PILOT_LS_UD_CHANNEL] - config.rc_min_value) / range * 2.0f;
            _pilot_cmd.rs_lr = -1.0f + (float)(rc_val[PILOT_RS_LR_CHANNEL] - config.rc_min_value) / range * 2.0f;
            _pilot_cmd.rs_ud = -1.0f + (float)(rc_val[PILOT_RS_UD_CHANNEL] - config.rc_min_value) / range * 2.0f;

            /* mode switch */
            if (rc_val[PILOT_MODE_CHANNEL] <= 1100) {
                _pilot_cmd.mode = 2; //Position Mode
            } else if (rc_val[PILOT_MODE_CHANNEL] <= 1600) {
                _pilot_cmd.mode = 3; //Altitude Hold
            } else {
                _pilot_cmd.mode = 4; //Manual Mode
            }

            /* generate pilot command */
            _generate_cmd(&_pilot_cmd, rc_val);
            /* update timestamp */
            _pilot_cmd.timestamp = systime_now_ms();
            /* publish pilot_cmd topic */
            mcn_publish(MCN_ID(pilot_cmd), &_pilot_cmd);

#ifdef FMT_OUTPUT_PILOT_CMD
            /* send out pilot_cmd via mavlink */
            _mav_send_pilot_cmd();
#endif
        }

        return 1;
    }

    return 0;
}

fmt_err pilot_cmd_init(void)
{
    _rc_dev = rt_device_find("rc");

    if (_rc_dev == RT_NULL) {
        return FMT_ERROR;
    }

    if (rt_device_open(_rc_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return FMT_ERROR;
    }

    /* advertise pilot command topic to publish rc value */
    if (mcn_advertise(MCN_ID(pilot_cmd), _pilot_cmd_echo) != FMT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}