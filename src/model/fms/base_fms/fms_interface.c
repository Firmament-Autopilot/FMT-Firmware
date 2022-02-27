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
#include <string.h>

#include "module/log/mlog.h"
#include "module/param/param.h"

#define TAG "FMS"

// FMS input topic
MCN_DECLARE(pilot_cmd);
MCN_DECLARE(gcs_cmd);
MCN_DECLARE(ins_output);
MCN_DECLARE(control_output);

MCN_DEFINE(auto_cmd, sizeof(Auto_Cmd_Bus));

/* FMS output topic */
MCN_DEFINE(fms_output, sizeof(FMS_Out_Bus));

/* define parameters */
static param_t __param_list[] = {
    /* Stick Dead Zone */
    PARAM_FLOAT(THROTTLE_DZ, 0.15),
    PARAM_FLOAT(YAW_DZ, 0.15),
    PARAM_FLOAT(ROLL_DZ, 0.1),
    PARAM_FLOAT(PITCH_DZ, 0.1),
    PARAM_FLOAT(XY_P, 0.95),
    PARAM_FLOAT(Z_P, 1),
    PARAM_FLOAT(VEL_XY_LIM, 5.0),
    PARAM_FLOAT(VEL_Z_LIM, 2.5),
    PARAM_FLOAT(YAW_P, 2.5),
    PARAM_FLOAT(YAW_RATE_LIM, PI / 3),
    PARAM_FLOAT(ROLL_PITCH_LIM, PI / 6),
};
PARAM_GROUP_DEFINE(FMS, __param_list);

/* define log data */
static mlog_elem_t Pilot_Cmd_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(stick_yaw, MLOG_FLOAT),
    MLOG_ELEMENT(stick_throttle, MLOG_FLOAT),
    MLOG_ELEMENT(stick_roll, MLOG_FLOAT),
    MLOG_ELEMENT(stick_pitch, MLOG_FLOAT),
    MLOG_ELEMENT(mode, MLOG_UINT32),
    MLOG_ELEMENT(cmd_1, MLOG_UINT32),
    MLOG_ELEMENT(cmd_2, MLOG_UINT32),
};
MLOG_BUS_DEFINE(Pilot_Cmd, Pilot_Cmd_Elems);

static mlog_elem_t GCS_Cmd_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(mode, MLOG_UINT32),
    MLOG_ELEMENT(cmd_1, MLOG_UINT32),
    MLOG_ELEMENT(cmd_2, MLOG_UINT32),
};
MLOG_BUS_DEFINE(GCS_Cmd, GCS_Cmd_Elems);

static mlog_elem_t FMS_Out_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(p_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(q_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(r_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(phi_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(theta_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(psi_rate_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(u_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(v_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(w_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(throttle_cmd, MLOG_UINT32),
    MLOG_ELEMENT_VEC(actuator_cmd, MLOG_UINT16, 16),
    MLOG_ELEMENT(status, MLOG_UINT8),
    MLOG_ELEMENT(state, MLOG_UINT8),
    MLOG_ELEMENT(ctrl_mode, MLOG_UINT8),
    MLOG_ELEMENT(reset, MLOG_UINT8),
    MLOG_ELEMENT(mode, MLOG_UINT8),
    MLOG_ELEMENT(reserved1, MLOG_UINT8),
    MLOG_ELEMENT(reserved2, MLOG_UINT16),
};
MLOG_BUS_DEFINE(FMS_Out, FMS_Out_Elems);

static McnNode_t pilot_cmd_nod;
static McnNode_t gcs_cmd_nod;
static McnNode_t ins_out_nod;
static McnNode_t control_out_nod;
static uint8_t pilot_cmd_updated = 1;
static uint8_t gcs_cmd_updated = 1;

static int Pilot_Cmd_ID;
static int GCS_Cmd_ID;
static int FMS_Out_ID;

fmt_model_info_t fms_model_info;

static void mlog_start_cb(void)
{
    pilot_cmd_updated = 1;
    gcs_cmd_updated = 1;
}

static void init_parameter(void)
{
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, THROTTLE_DZ), &FMS_PARAM.THROTTLE_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, YAW_DZ), &FMS_PARAM.YAW_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ROLL_DZ), &FMS_PARAM.ROLL_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, PITCH_DZ), &FMS_PARAM.PITCH_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, XY_P), &FMS_PARAM.XY_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, Z_P), &FMS_PARAM.Z_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, VEL_XY_LIM), &FMS_PARAM.VEL_XY_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, VEL_Z_LIM), &FMS_PARAM.VEL_Z_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, YAW_P), &FMS_PARAM.YAW_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, YAW_RATE_LIM), &FMS_PARAM.YAW_RATE_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ROLL_PITCH_LIM), &FMS_PARAM.ROLL_PITCH_LIM));
}

void fms_interface_step(uint32_t timestamp)
{
    if (mcn_poll(pilot_cmd_nod)) {
        mcn_copy(MCN_HUB(pilot_cmd), pilot_cmd_nod, &FMS_U.Pilot_Cmd);

        FMS_U.Pilot_Cmd.timestamp = timestamp;
        pilot_cmd_updated = 1;
    }

    if (mcn_poll(gcs_cmd_nod)) {
        mcn_copy(MCN_HUB(gcs_cmd), gcs_cmd_nod, &FMS_U.GCS_Cmd);

        FMS_U.GCS_Cmd.timestamp = timestamp;
        gcs_cmd_updated = 1;
    }

    if (mcn_poll(ins_out_nod)) {
        mcn_copy(MCN_HUB(ins_output), ins_out_nod, &FMS_U.INS_Out);
    }

    if (mcn_poll(control_out_nod)) {
        mcn_copy(MCN_HUB(control_output), control_out_nod, &FMS_U.Control_Out);
    }

    FMS_step();

    mcn_publish(MCN_HUB(fms_output), &FMS_Y.FMS_Out);

    if (pilot_cmd_updated) {
        pilot_cmd_updated = 0;
        /* Log pilot command */
        mlog_push_msg((uint8_t*)&FMS_U.Pilot_Cmd, Pilot_Cmd_ID, sizeof(Pilot_Cmd_Bus));
    }

    if (gcs_cmd_updated) {
        gcs_cmd_updated = 0;
        /* Log gcs command */
        mlog_push_msg((uint8_t*)&FMS_U.GCS_Cmd, GCS_Cmd_ID, sizeof(GCS_Cmd_Bus));
    }

    /* Log FMS output bus data */
    DEFINE_TIMETAG(fms_output, 100);
    if (check_timetag(TIMETAG(fms_output))) {
        /* Log FMS out data */
        mlog_push_msg((uint8_t*)&FMS_Y.FMS_Out, FMS_Out_ID, sizeof(FMS_Out_Bus));
    }
}

void fms_interface_init(void)
{
    fms_model_info.period = FMS_EXPORT.period;
    fms_model_info.info = (char*)FMS_EXPORT.model_info;

    mcn_advertise(MCN_HUB(fms_output), NULL);

    pilot_cmd_nod = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);
    gcs_cmd_nod = mcn_subscribe(MCN_HUB(gcs_cmd), NULL, NULL);
    ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    control_out_nod = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);

    Pilot_Cmd_ID = mlog_get_bus_id("Pilot_Cmd");
    GCS_Cmd_ID = mlog_get_bus_id("GCS_Cmd");
    FMS_Out_ID = mlog_get_bus_id("FMS_Out");
    FMT_ASSERT(Pilot_Cmd_ID >= 0);
    FMT_ASSERT(GCS_Cmd_ID >= 0);
    FMT_ASSERT(FMS_Out_ID >= 0);

    mlog_register_callback(MLOG_CB_START, mlog_start_cb);

    FMS_init();

    init_parameter();
}
