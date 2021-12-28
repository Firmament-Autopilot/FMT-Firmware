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
MCN_DECLARE(gcs_cmd);
MCN_DECLARE(ins_output);
MCN_DECLARE(control_output);

MCN_DEFINE(auto_cmd, sizeof(Auto_Cmd_Bus));

/* FMS output topic */
MCN_DEFINE(fms_output, sizeof(FMS_Out_Bus));

static McnNode_t _pilot_cmd_nod;
static McnNode_t _gcs_cmd_nod;
static McnNode_t _ins_out_nod;
static McnNode_t _control_out_nod;
static uint8_t _pilot_cmd_update = 1;

fmt_model_info_t fms_model_info;

static void mlog_start_cb(void)
{
    _pilot_cmd_update = 1;
}

static void update_parameter(void)
{
    FMS_PARAM.THROTTLE_DZ = PARAM_GET_FLOAT(FMS, THROTTLE_DZ);
    FMS_PARAM.YAW_DZ = PARAM_GET_FLOAT(FMS, YAW_DZ);
    FMS_PARAM.ROLL_DZ = PARAM_GET_FLOAT(FMS, ROLL_DZ);
    FMS_PARAM.PITCH_DZ = PARAM_GET_FLOAT(FMS, PITCH_DZ);
    FMS_PARAM.XY_P = PARAM_GET_FLOAT(FMS, XY_P);
    FMS_PARAM.Z_P = PARAM_GET_FLOAT(FMS, Z_P);
    FMS_PARAM.VEL_XY_LIM = PARAM_GET_FLOAT(FMS, VEL_XY_LIM);
    FMS_PARAM.VEL_Z_LIM = PARAM_GET_FLOAT(FMS, VEL_Z_LIM);
    FMS_PARAM.YAW_P = PARAM_GET_FLOAT(FMS, YAW_P);
    FMS_PARAM.YAW_RATE_LIM = PARAM_GET_FLOAT(FMS, YAW_RATE_LIM);
    FMS_PARAM.ROLL_PITCH_LIM = PARAM_GET_FLOAT(FMS, ROLL_PITCH_LIM);
}

void fms_interface_step(void)
{
    static uint32_t start_time = 0;
    uint32_t time_now = systime_now_ms();

#ifdef FMT_ONLINE_PARAM_TUNING
    update_parameter();
#endif

    if (start_time == 0) {
        /* record first execution time */
        start_time = time_now;
    }

    if (mcn_poll(_pilot_cmd_nod)) {
        mcn_copy(MCN_HUB(pilot_cmd), _pilot_cmd_nod, &FMS_U.Pilot_Cmd);
        _pilot_cmd_update = 1;
    }

    if (mcn_poll(_gcs_cmd_nod)) {
        mcn_copy(MCN_HUB(gcs_cmd), _gcs_cmd_nod, &FMS_U.GCS_Cmd);
    }

    if (mcn_poll(_ins_out_nod)) {
        mcn_copy(MCN_HUB(ins_output), _ins_out_nod, &FMS_U.INS_Out);
    }

    if (mcn_poll(_control_out_nod)) {
        mcn_copy(MCN_HUB(control_output), _control_out_nod, &FMS_U.Control_Out);
    }

    FMS_step();

    mcn_publish(MCN_HUB(fms_output), &FMS_Y.FMS_Out);

    if (_pilot_cmd_update) {
        FMS_U.Pilot_Cmd.timestamp = time_now - start_time;
        /* Log pilot command */
        if (mlog_push_msg((uint8_t*)&FMS_U.Pilot_Cmd, MLOG_PILOT_CMD_ID, sizeof(Pilot_Cmd_Bus)) == FMT_EOK) {
            _pilot_cmd_update = 0;
        }
    }

    DEFINE_TIMETAG(fms_output, 100);

    /* Log FMS output bus data */
    if (check_timetag(TIMETAG(fms_output))) {
        /* rewrite timestmp */
        FMS_Y.FMS_Out.timestamp = time_now - start_time;
        /* Log FMS out data */
        mlog_push_msg((uint8_t*)&FMS_Y.FMS_Out, MLOG_FMS_OUT_ID, sizeof(FMS_Out_Bus));
    }
}

void fms_interface_init(void)
{
    fms_model_info.period = FMS_EXPORT.period;
    fms_model_info.info = (char*)FMS_EXPORT.model_info;

    mcn_advertise(MCN_HUB(fms_output), NULL);

    _pilot_cmd_nod = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);
    _gcs_cmd_nod = mcn_subscribe(MCN_HUB(gcs_cmd), NULL, NULL);
    _ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    _control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);

    mlog_register_callback(MLOG_CB_START, mlog_start_cb);

    FMS_init();

    update_parameter();
}
