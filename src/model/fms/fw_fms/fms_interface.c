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
MCN_DECLARE(auto_cmd);
MCN_DECLARE(mission_data);
MCN_DECLARE(ins_output);
MCN_DECLARE(control_output);

// MCN_DEFINE(auto_cmd, sizeof(Auto_Cmd_Bus));

/* FMS output topic */
MCN_DEFINE(fms_output, sizeof(FMS_Out_Bus));

/* define parameters */
static param_t __param_list[] = {
    /* Stick Dead Zone */
    PARAM_FLOAT(THROTTLE_DZ, 0.15, false),
    PARAM_FLOAT(YAW_DZ, 0.15, false),
    PARAM_FLOAT(ROLL_DZ, 0.1, false),
    PARAM_FLOAT(PITCH_DZ, 0.1, false),
    PARAM_FLOAT(XY_P, 0.95, false),
    PARAM_FLOAT(Z_P, 1, false),
    PARAM_FLOAT(VEL_Z_LIM, 5, false),
    PARAM_FLOAT(YAW_P, 2.5, false),
    PARAM_FLOAT(YAW_RATE_LIM, PI / 3, false),
    PARAM_FLOAT(ROLL_PITCH_LIM, PI / 6, false),
    PARAM_FLOAT(L1, 30.0, false),
    PARAM_FLOAT(CRUISE_SPEED, 13.0, false),
    PARAM_FLOAT(TAKEOFF_H, 10.0, false),
    PARAM_FLOAT(ACCEPT_R, 55, false),
    PARAM_FLOAT(LOITER_R, 50, false),
    PARAM_FLOAT(MANUAL_ROLL_REV, 1.0, false),
    PARAM_FLOAT(MANUAL_PITCH_REV, 1.0, false),
    PARAM_FLOAT(MANUAL_YAW_REV, 1.0, false),
    PARAM_FLOAT(Y_P, 0.95, false),
    PARAM_FLOAT(ACC_Y_LIM, 10, false),
    PARAM_FLOAT(ROLL_LIM, PI / 4, false),
    PARAM_FLOAT(PITCH_LIM, PI / 4, false),
    PARAM_FLOAT(FW_AIRSPD_MAX, 30, false),
    PARAM_UINT16(LOST_RETURN_TIME, 120, false),
    PARAM_UINT8(LOST_RETURN_EN, 1, false),
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
    MLOG_ELEMENT_VEC(param, MLOG_FLOAT, 7),
};
MLOG_BUS_DEFINE(GCS_Cmd, GCS_Cmd_Elems);

static mlog_elem_t Auto_Cmd_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(p_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(q_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(r_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(phi_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(theta_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(psi_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(psi_rate_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(x_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(y_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(z_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(lat_cmd, MLOG_INT32),
    MLOG_ELEMENT(lon_cmd, MLOG_INT32),
    MLOG_ELEMENT(alt_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(u_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(v_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(w_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(ax_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(ay_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(az_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(throttle_cmd, MLOG_UINT16),
    MLOG_ELEMENT(frame, MLOG_UINT8),
    MLOG_ELEMENT(reserved, MLOG_UINT8),
    MLOG_ELEMENT(cmd_mask, MLOG_UINT32),
};
MLOG_BUS_DEFINE(Auto_Cmd, Auto_Cmd_Elems);

static mlog_elem_t Mission_Data_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(valid_items, MLOG_UINT16),
    MLOG_ELEMENT(reserved, MLOG_UINT16),
    MLOG_ELEMENT_VEC(seq, MLOG_UINT16, 8),
    MLOG_ELEMENT_VEC(command, MLOG_UINT16, 8),
    MLOG_ELEMENT_VEC(frame, MLOG_UINT8, 8),
    MLOG_ELEMENT_VEC(current, MLOG_UINT8, 8),
    MLOG_ELEMENT_VEC(autocontinue, MLOG_UINT8, 8),
    MLOG_ELEMENT_VEC(mission_type, MLOG_UINT8, 8),
    MLOG_ELEMENT_VEC(param1, MLOG_FLOAT, 8),
    MLOG_ELEMENT_VEC(param2, MLOG_FLOAT, 8),
    MLOG_ELEMENT_VEC(param3, MLOG_FLOAT, 8),
    MLOG_ELEMENT_VEC(param4, MLOG_FLOAT, 8),
    MLOG_ELEMENT_VEC(x, MLOG_INT32, 8),
    MLOG_ELEMENT_VEC(y, MLOG_INT32, 8),
    MLOG_ELEMENT_VEC(z, MLOG_FLOAT, 8),
};
MLOG_BUS_DEFINE(Mission_Data, Mission_Data_Elems);

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
    MLOG_ELEMENT(ax_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(ay_cmd, MLOG_FLOAT),
    MLOG_ELEMENT(az_cmd, MLOG_FLOAT),
    MLOG_ELEMENT_VEC(actuator_cmd, MLOG_UINT16, 16),
    MLOG_ELEMENT(throttle_cmd, MLOG_UINT16),
    MLOG_ELEMENT(cmd_mask, MLOG_UINT16),
    MLOG_ELEMENT(status, MLOG_UINT8),
    MLOG_ELEMENT(state, MLOG_UINT8),
    MLOG_ELEMENT(ctrl_mode, MLOG_UINT8),
    MLOG_ELEMENT(mode, MLOG_UINT8),
    MLOG_ELEMENT(reset, MLOG_UINT8),
    MLOG_ELEMENT(wp_consume, MLOG_UINT8),
    MLOG_ELEMENT(wp_current, MLOG_UINT8),
    MLOG_ELEMENT(reserved, MLOG_UINT8),
    MLOG_ELEMENT_VEC(home, MLOG_FLOAT, 4),
};
MLOG_BUS_DEFINE(FMS_Out, FMS_Out_Elems);

static McnNode_t pilot_cmd_nod;
static McnNode_t gcs_cmd_nod;
static McnNode_t auto_cmd_nod;
static McnNode_t mission_data_nod;
static McnNode_t ins_out_nod;
static McnNode_t control_out_nod;
static uint8_t   pilot_cmd_updated    = 1;
static uint8_t   gcs_cmd_updated      = 1;
static uint8_t   auto_cmd_updated     = 1;
static uint8_t   mission_data_updated = 1;

static int Pilot_Cmd_ID;
static int GCS_Cmd_ID;
static int Auto_Cmd_ID;
static int Mission_Data_ID;
static int FMS_Out_ID;

static char* fms_status[] = {
    "None",
    "Disarm",
    "Standby",
    "Arm",
};

static char* fms_state[] = {
    "None",
    "Disarm",
    "Standby",
    "Offboard",
    "Mission",
    "InvalidAutoMode",
    "Hold",
    "Acro",
    "Stabilize",
    "Altitude",
    "Position",
    "InvalidAssistMode",
    "Manual",
    "InValidManualMode",
    "InvalidArmMode",
    "Land",
    "Return",
    "Takeoff",
};

static char* fms_ctrl_mode[] = {
    "None",
    "Manual",
    "Acro",
    "Stabilize",
    "ALTCTL",
    "POSCTL",
    "Offboard",
};

static char* fms_mode[] = {
    "None",
    "Manual",
    "Acro",
    "Stabilize",
    "Altitude",
    "Position",
    "Mission",
    "Offboard",
};

fmt_model_info_t fms_model_info;

static int fms_output_echo(void* param)
{
    FMS_Out_Bus fms_out;

    mcn_copy_from_hub((McnHub*)param, &fms_out);

    printf("timestamp:%u\n", fms_out.timestamp);
    printf("rate cmd: %.2f %.2f %.2f\n", fms_out.p_cmd, fms_out.q_cmd, fms_out.r_cmd);
    printf("att cmd: %.2f %.2f %.2f\n", fms_out.phi_cmd, fms_out.theta_cmd, fms_out.psi_rate_cmd);
    printf("vel cmd: %.2f %.2f %.2f\n", fms_out.u_cmd, fms_out.v_cmd, fms_out.w_cmd);
    printf("acc cmd: %.2f %.2f %.2f\n", fms_out.ax_cmd, fms_out.ay_cmd, fms_out.az_cmd);
    printf("throttle cmd: %.2f\n", fms_out.throttle_cmd);
    printf("act cmd: %u %u %u %u\n", fms_out.actuator_cmd[0], fms_out.actuator_cmd[1], fms_out.actuator_cmd[2], fms_out.actuator_cmd[3]);
    printf("status:%s state:%s ctrl_mode:%s\n", fms_status[fms_out.status], fms_state[fms_out.state], fms_ctrl_mode[fms_out.ctrl_mode]);
    printf("mode:%s reset:%d\n", fms_mode[fms_out.mode], fms_out.reset);
    printf("wp_current:%d wp_consume:%d\n", fms_out.wp_current, fms_out.wp_consume);
    printf("------------------------------------------\n");

    return 0;
}

static void mlog_start_cb(void)
{
    pilot_cmd_updated    = 1;
    gcs_cmd_updated      = 1;
    auto_cmd_updated     = 1;
    mission_data_updated = 1;
}

static void init_parameter(void)
{
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, THROTTLE_DZ), &FMS_PARAM.THROTTLE_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, YAW_DZ), &FMS_PARAM.YAW_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ROLL_DZ), &FMS_PARAM.ROLL_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, PITCH_DZ), &FMS_PARAM.PITCH_DZ));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, XY_P), &FMS_PARAM.XY_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, Z_P), &FMS_PARAM.Z_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, VEL_Z_LIM), &FMS_PARAM.VEL_Z_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, YAW_P), &FMS_PARAM.YAW_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, YAW_RATE_LIM), &FMS_PARAM.YAW_RATE_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ROLL_PITCH_LIM), &FMS_PARAM.ROLL_PITCH_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, L1), &FMS_PARAM.L1));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, CRUISE_SPEED), &FMS_PARAM.CRUISE_SPEED));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, TAKEOFF_H), &FMS_PARAM.TAKEOFF_H));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ACCEPT_R), &FMS_PARAM.ACCEPT_R));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, LOITER_R), &FMS_PARAM.LOITER_R));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, MANUAL_ROLL_REV), &FMS_PARAM.MANUAL_ROLL_REV));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, MANUAL_PITCH_REV), &FMS_PARAM.MANUAL_PITCH_REV));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, MANUAL_YAW_REV), &FMS_PARAM.MANUAL_YAW_REV));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, Y_P), &FMS_PARAM.Y_P));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ACC_Y_LIM), &FMS_PARAM.ACC_Y_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, ROLL_LIM), &FMS_PARAM.ROLL_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, PITCH_LIM), &FMS_PARAM.PITCH_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, FW_AIRSPD_MAX), &FMS_PARAM.FW_AIRSPD_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, LOST_RETURN_TIME), &FMS_PARAM.LOST_RETURN_TIME));
    FMT_CHECK(param_link_variable(PARAM_GET(FMS, LOST_RETURN_EN), &FMS_PARAM.LOST_RETURN_EN));
}

void fms_interface_step(uint32_t timestamp)
{
    if (mcn_poll(pilot_cmd_nod)) {
        mcn_copy(MCN_HUB(pilot_cmd), pilot_cmd_nod, &FMS_U.Pilot_Cmd);

        FMS_U.Pilot_Cmd.timestamp = timestamp;
        pilot_cmd_updated         = 1;
    }

    if (mcn_poll(gcs_cmd_nod)) {
        mcn_copy(MCN_HUB(gcs_cmd), gcs_cmd_nod, &FMS_U.GCS_Cmd);

        FMS_U.GCS_Cmd.timestamp = timestamp;
        gcs_cmd_updated         = 1;
    }

    if (mcn_poll(auto_cmd_nod)) {
        mcn_copy(MCN_HUB(auto_cmd), auto_cmd_nod, &FMS_U.Auto_Cmd);

        FMS_U.Auto_Cmd.timestamp = timestamp;
        auto_cmd_updated         = 1;
    }

    if (mcn_poll(mission_data_nod)) {
        mcn_copy(MCN_HUB(mission_data), mission_data_nod, &FMS_U.Mission_Data);

        FMS_U.Mission_Data.timestamp = timestamp;
        mission_data_updated         = 1;
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

    if (auto_cmd_updated) {
        auto_cmd_updated = 0;
        /* Log gcs command */
        mlog_push_msg((uint8_t*)&FMS_U.Auto_Cmd, Auto_Cmd_ID, sizeof(Auto_Cmd_Bus));
    }

    if (mission_data_updated) {
        mission_data_updated = 0;
        /* Log mission data */
        mlog_push_msg((uint8_t*)&FMS_U.Mission_Data, Mission_Data_ID, sizeof(Mission_Data_Bus));
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
    fms_model_info.info   = (char*)FMS_EXPORT.model_info;

    mcn_advertise(MCN_HUB(fms_output), fms_output_echo);

    pilot_cmd_nod    = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);
    gcs_cmd_nod      = mcn_subscribe(MCN_HUB(gcs_cmd), NULL, NULL);
    auto_cmd_nod     = mcn_subscribe(MCN_HUB(auto_cmd), NULL, NULL);
    mission_data_nod = mcn_subscribe(MCN_HUB(mission_data), NULL, NULL);
    ins_out_nod      = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    control_out_nod  = mcn_subscribe(MCN_HUB(control_output), NULL, NULL);

    Pilot_Cmd_ID    = mlog_get_bus_id("Pilot_Cmd");
    GCS_Cmd_ID      = mlog_get_bus_id("GCS_Cmd");
    Auto_Cmd_ID     = mlog_get_bus_id("Auto_Cmd");
    Mission_Data_ID = mlog_get_bus_id("Mission_Data");
    FMS_Out_ID      = mlog_get_bus_id("FMS_Out");
    FMT_ASSERT(Pilot_Cmd_ID >= 0);
    FMT_ASSERT(GCS_Cmd_ID >= 0);
    FMT_ASSERT(Auto_Cmd_ID >= 0);
    FMT_ASSERT(Mission_Data_ID >= 0);
    FMT_ASSERT(FMS_Out_ID >= 0);

    mlog_register_callback(MLOG_CB_START, mlog_start_cb);

    FMS_init();

    init_parameter();
}
