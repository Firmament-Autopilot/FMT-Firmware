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

#include <FMS.h>
#include <firmament.h>

#define TAG "FMS"

// FMS input topic
MCN_DECLARE(pilot_cmd);
MCN_DECLARE(ins_output);
MCN_DECLARE(control_output);

/* FMS output topic */
MCN_DEFINE(fms_output, sizeof(FMS_Out_Bus));

static McnNode_t _pilot_cmd_nod;
static McnNode_t _ins_out_nod;
static McnNode_t _control_out_nod;
static uint8_t _pilot_cmd_update = 1;

static void _blog_start_cb(void)
{
    _pilot_cmd_update = 1;
}

static void _update_model_parameter(void)
{
    FMS_PARAM.StickDeadZone = PARAM_GET_FLOAT(FMS, STICK_DEADZONE);
    FMS_PARAM.XY_P = PARAM_GET_FLOAT(FMS, XY_P);
    FMS_PARAM.Z_P = PARAM_GET_FLOAT(FMS, Z_P);
    FMS_PARAM.VEL_XY_LIM = PARAM_GET_FLOAT(FMS, VEL_XY_LIM);
    FMS_PARAM.VEL_Z_LIM = PARAM_GET_FLOAT(FMS, VEL_Z_LIM);
    FMS_PARAM.YAW_P = PARAM_GET_FLOAT(FMS, YAW_P);
    FMS_PARAM.YAW_RATE_LIM = PARAM_GET_FLOAT(FMS, YAW_RATE_LIM);
    FMS_PARAM.ROLL_PITCH_LIM = PARAM_GET_FLOAT(FMS, ROLL_PITCH_LIM);
}

void fms_model_step(void)
{
    static uint32_t start_time = 0;
    uint32_t time_now = systime_now_ms();

#ifdef FMT_ONLINE_PARAM_TUNING
    _update_model_parameter();
#endif

    if (start_time == 0) {
        /* record first execution time */
        start_time = time_now;
    }

    if (mcn_poll(_pilot_cmd_nod)) {
        mcn_copy(MCN_ID(pilot_cmd), _pilot_cmd_nod, &FMS_U.Pilot_Cmd);
        _pilot_cmd_update = 1;
    }

    if (mcn_poll(_ins_out_nod)) {
        mcn_copy(MCN_ID(ins_output), _ins_out_nod, &FMS_U.INS_Output);
    }

    if (mcn_poll(_control_out_nod)) {
        mcn_copy(MCN_ID(control_output), _control_out_nod, &FMS_U.Control_Out);
    }

    FMS_step();

    mcn_publish(MCN_ID(fms_output), &FMS_Y.FMS_Output);

    if (_pilot_cmd_update) {
        FMS_U.Pilot_Cmd.timestamp = time_now - start_time;
        /* Log pilot command */
        if (blog_push_msg((uint8_t*)&FMS_U.Pilot_Cmd, BLOG_PILOT_CMD_ID, sizeof(Pilot_Cmd_Bus)) == FMT_EOK) {
            _pilot_cmd_update = 0;
        }
    }

    DEFINE_TIMETAG(fms_output, 100);

    /* Log FMS output bus data */
    if (check_timetag(TIMETAG(fms_output))) {
        /* rewrite timestmp */
        FMS_Y.FMS_Output.timestamp = time_now - start_time;
        /* Log FMS out data */
        blog_push_msg((uint8_t*)&FMS_Y.FMS_Output, BLOG_FMS_OUT_ID, sizeof(FMS_Out_Bus));
    }
}

void fms_model_init(void)
{
    mcn_advertise(MCN_ID(fms_output), NULL);

    _pilot_cmd_nod = mcn_subscribe(MCN_ID(pilot_cmd), NULL, NULL);
    _ins_out_nod = mcn_subscribe(MCN_ID(ins_output), NULL, NULL);
    _control_out_nod = mcn_subscribe(MCN_ID(control_output), NULL, NULL);

    blog_register_callback(BLOG_CB_START, _blog_start_cb);

    FMS_init();

    _update_model_parameter();
}
