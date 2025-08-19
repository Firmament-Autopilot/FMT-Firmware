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

#include <Controller.h>
#include <firmament.h>

#include "module/log/mlog.h"
#include "module/param/param.h"

#define TAG "Controller"

/* controller input topic */
MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);

/* controller output topic */
MCN_DEFINE(control_output, sizeof(Control_Out_Bus));

/* define parameters */
static param_t __param_list[] = {
    PARAM_UINT8(AIRFRAME, AIRFRAME, true),
    PARAM_FLOAT(MC_VEL_XY_P, 1.4, false),
    PARAM_FLOAT(MC_VEL_XY_I, 0.2, false),
    PARAM_FLOAT(MC_VEL_XY_D, 0.1, false),
    PARAM_FLOAT(MC_VEL_Z_P, 0.5, false),
    PARAM_FLOAT(MC_VEL_Z_I, 0.12, false),
    PARAM_FLOAT(MC_VEL_Z_D, 0.0, false),
    PARAM_FLOAT(MC_VEL_XY_I_MIN, -1, false),
    PARAM_FLOAT(MC_VEL_XY_I_MAX, 1, false),
    PARAM_FLOAT(MC_VEL_XY_D_MIN, -1, false),
    PARAM_FLOAT(MC_VEL_XY_D_MAX, 1, false),
    PARAM_FLOAT(MC_VEL_Z_I_MIN, -0.2, false),
    PARAM_FLOAT(MC_VEL_Z_I_MAX, 0.2, false),
    PARAM_FLOAT(MC_VEL_Z_D_MIN, -0.1, false),
    PARAM_FLOAT(MC_VEL_Z_D_MAX, 0.1, false),
    PARAM_FLOAT(MC_ROLL_P, 5, false),
    PARAM_FLOAT(MC_PITCH_P, 5, false),
    PARAM_FLOAT(MC_ROLL_PITCH_CMD_LIM, PI / 6, false),
    PARAM_FLOAT(MC_ROLL_RATE_P, 0.24, false),
    PARAM_FLOAT(MC_PITCH_RATE_P, 0.3, false),
    PARAM_FLOAT(MC_YAW_RATE_P, 0.6, false),
    PARAM_FLOAT(MC_ROLL_RATE_I, 0.15, false),
    PARAM_FLOAT(MC_PITCH_RATE_I, 0.15, false),
    PARAM_FLOAT(MC_YAW_RATE_I, 0.2, false),
    PARAM_FLOAT(MC_ROLL_RATE_D, 0.003, false),
    PARAM_FLOAT(MC_PITCH_RATE_D, 0.006, false),
    PARAM_FLOAT(MC_YAW_RATE_D, 0.004, false),
    PARAM_FLOAT(MC_RATE_I_MIN, -0.3, false),
    PARAM_FLOAT(MC_RATE_I_MAX, 0.3, false),
    PARAM_FLOAT(MC_RATE_D_MIN, -0.3, false),
    PARAM_FLOAT(MC_RATE_D_MAX, 0.3, false),
    PARAM_FLOAT(MC_P_Q_CMD_LIM, PI / 2, false),
    PARAM_FLOAT(MC_R_CMD_LIM, PI, false),
    PARAM_FLOAT(MC_HOVER_THRO, 0.5, false),
    PARAM_UINT16(MC_OUT_MAX, 1950, false),
    PARAM_UINT16(MC_OUT_MIN, 1050, false),

    PARAM_FLOAT(FW_ROLL_P, 7.0, false),
    PARAM_FLOAT(FW_PITCH_P, 7.0, false),
    PARAM_FLOAT(FW_ROLL_PITCH_CMD_LIM, PI / 4, false),
    PARAM_FLOAT(FW_ROLL_RATE_P, 0.1, false),
    PARAM_FLOAT(FW_PITCH_RATE_P, 0.2, false),
    PARAM_FLOAT(FW_YAW_RATE_P, 0.15, false),
    PARAM_FLOAT(FW_ROLL_RATE_I, 0.1, false),
    PARAM_FLOAT(FW_PITCH_RATE_I, 0.1, false),
    PARAM_FLOAT(FW_YAW_RATE_I, 0.2, false),
    PARAM_FLOAT(FW_RATE_I_MIN, -0.1, false),
    PARAM_FLOAT(FW_RATE_I_MAX, 0.1, false),
    PARAM_FLOAT(FW_P_Q_CMD_LIM, PI / 2, false),
    PARAM_FLOAT(FW_R_CMD_LIM, PI / 2, false),
    PARAM_FLOAT(FW_YAW_RATE_LIM2, PI / 4, false),

    PARAM_FLOAT(FW_AIRSPEED_TRIM, 17.0, false),
    PARAM_FLOAT(FW_FF, 0.2, false),
    PARAM_FLOAT(FW_FF_LIMIT, 0.3, false),
    PARAM_FLOAT(FW_PI_LIMIT, 1.0, false),
    PARAM_FLOAT(FW_ROLL_EFFC, 1.0, false),
    PARAM_FLOAT(FW_PITCH_EFFC, 1.0, false),
    PARAM_FLOAT(FW_YAW_EFFC, 1.0, false),
    PARAM_FLOAT(FW_PITCH_OFFSET, 0.0, false),
    PARAM_FLOAT(FW_CRUISE_THRO, 0.5, false),

    PARAM_FLOAT(FW_TECS_PITCH_F, 0.1, false),
    PARAM_FLOAT(FW_TECS_THOR_FF, 0.1, false),
    PARAM_FLOAT(FW_TECS_PITCH_P, 0.12, false),
    PARAM_FLOAT(FW_TECS_THOR_P, 0.1, false),
    PARAM_FLOAT(FW_TECS_PITCH_I, 0.1, false),
    PARAM_FLOAT(FW_TECS_PITCH_I_LIM, 0.15, false),
    PARAM_FLOAT(FW_TECS_THOR_I, 0.2, false),
    PARAM_FLOAT(FW_TECS_PITCH_D, 0.0, false),
    PARAM_FLOAT(FW_TECS_THOR_D, 0.0, false),
    PARAM_FLOAT(FW_TECS_VEL_P, 1.0, false),
    PARAM_FLOAT(FW_TECS_RATIO, 1.0, false),
    PARAM_FLOAT(FW_TECS_SWITCH, 2.0, false),
    PARAM_FLOAT(FW_TECS_ANSW, 2.0, false),
    PARAM_FLOAT(FW_TECS_W2T, 1.0, false),
    PARAM_FLOAT(FW_TECS_U2T, 1.0, false),
    PARAM_FLOAT(FW_TECS_W2P, 2.0, false),
    PARAM_FLOAT(FW_TECS_U2P, 0.1, false),
    PARAM_FLOAT(FW_TECS_R2P, 0.1, false),
    PARAM_FLOAT(FW_TECS_R2T, 0.1, false),
    PARAM_UINT16(FW_OUT_MAX, 2000, false),
    PARAM_UINT16(FW_OUT_MIN, 1000, false),

    PARAM_FLOAT(FW_AILERON1_DIR, 1.0, false),
    PARAM_FLOAT(FW_AILERON2_DIR, 1.0, false),
    PARAM_FLOAT(FW_ELEVATOR_DIR, 1.0, false),
    PARAM_FLOAT(FW_RUDDER_DIR, 1.0, false),
    PARAM_FLOAT(FW_TAIL1_DIR, 1.0, false),
    PARAM_FLOAT(FW_TAIL2_DIR, 1.0, false),
    PARAM_FLOAT(SERVO1_BIAS, 0.0, false),
    PARAM_FLOAT(SERVO2_BIAS, 0.0, false),
    PARAM_FLOAT(SERVO3_BIAS, 0.0, false),
    PARAM_FLOAT(SERVO4_BIAS, 0.0, false),
};
PARAM_GROUP_DEFINE(CONTROL, __param_list);

/* define log data */
static mlog_elem_t Control_Out_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT_VEC(actuator_cmd, MLOG_UINT16, 16),
};
MLOG_BUS_DEFINE(Control_Out, Control_Out_Elems);

static McnNode_t fms_out_nod;
static McnNode_t ins_out_nod;

static int Control_Out_ID;

fmt_model_info_t control_model_info;

static int control_out_echo(void* param)
{
    Control_Out_Bus control_out;

    if (mcn_copy_from_hub((McnHub*)param, &control_out) != FMT_EOK)
        return -1;

    printf("timestamp:%d actuator:", control_out.timestamp);
    for (uint8_t i = 0; i < 16; i++) {
        if (control_out.actuator_cmd[i] > 0) {
            printf(" %d", control_out.actuator_cmd[i]);
        } else {
            break;
        }
    }
    printf("\n");
    return 0;
}

static void init_parameter(void)
{
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_P), &CONTROL_PARAM.MC_VEL_XY_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_I), &CONTROL_PARAM.MC_VEL_XY_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_D), &CONTROL_PARAM.MC_VEL_XY_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_P), &CONTROL_PARAM.MC_VEL_Z_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_I), &CONTROL_PARAM.MC_VEL_Z_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_D), &CONTROL_PARAM.MC_VEL_Z_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_I_MIN), &CONTROL_PARAM.MC_VEL_XY_I_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_I_MAX), &CONTROL_PARAM.MC_VEL_XY_I_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_D_MIN), &CONTROL_PARAM.MC_VEL_XY_D_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_XY_D_MAX), &CONTROL_PARAM.MC_VEL_XY_D_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_I_MIN), &CONTROL_PARAM.MC_VEL_Z_I_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_I_MAX), &CONTROL_PARAM.MC_VEL_Z_I_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_D_MIN), &CONTROL_PARAM.MC_VEL_Z_D_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_VEL_Z_D_MAX), &CONTROL_PARAM.MC_VEL_Z_D_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_ROLL_P), &CONTROL_PARAM.MC_ROLL_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_PITCH_P), &CONTROL_PARAM.MC_PITCH_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_ROLL_PITCH_CMD_LIM), &CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_ROLL_RATE_P), &CONTROL_PARAM.MC_ROLL_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_PITCH_RATE_P), &CONTROL_PARAM.MC_PITCH_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_YAW_RATE_P), &CONTROL_PARAM.MC_YAW_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_ROLL_RATE_I), &CONTROL_PARAM.MC_ROLL_RATE_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_PITCH_RATE_I), &CONTROL_PARAM.MC_PITCH_RATE_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_YAW_RATE_I), &CONTROL_PARAM.MC_YAW_RATE_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_ROLL_RATE_D), &CONTROL_PARAM.MC_ROLL_RATE_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_PITCH_RATE_D), &CONTROL_PARAM.MC_PITCH_RATE_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_YAW_RATE_D), &CONTROL_PARAM.MC_YAW_RATE_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_RATE_I_MIN), &CONTROL_PARAM.MC_RATE_I_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_RATE_I_MAX), &CONTROL_PARAM.MC_RATE_I_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_RATE_D_MIN), &CONTROL_PARAM.MC_RATE_D_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_RATE_D_MAX), &CONTROL_PARAM.MC_RATE_D_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_P_Q_CMD_LIM), &CONTROL_PARAM.MC_P_Q_CMD_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_R_CMD_LIM), &CONTROL_PARAM.MC_R_CMD_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_HOVER_THRO), &CONTROL_PARAM.MC_HOVER_THRO));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_OUT_MAX), &CONTROL_PARAM.MC_OUT_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, MC_OUT_MIN), &CONTROL_PARAM.MC_OUT_MIN));

    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_ROLL_P), &CONTROL_PARAM.FW_ROLL_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_PITCH_P), &CONTROL_PARAM.FW_PITCH_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_ROLL_PITCH_CMD_LIM), &CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_ROLL_RATE_P), &CONTROL_PARAM.FW_ROLL_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_PITCH_RATE_P), &CONTROL_PARAM.FW_PITCH_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_YAW_RATE_P), &CONTROL_PARAM.FW_YAW_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_ROLL_RATE_I), &CONTROL_PARAM.FW_ROLL_RATE_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_PITCH_RATE_I), &CONTROL_PARAM.FW_PITCH_RATE_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_YAW_RATE_I), &CONTROL_PARAM.FW_YAW_RATE_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_RATE_I_MIN), &CONTROL_PARAM.FW_RATE_I_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_RATE_I_MAX), &CONTROL_PARAM.FW_RATE_I_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_P_Q_CMD_LIM), &CONTROL_PARAM.FW_P_Q_CMD_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_R_CMD_LIM), &CONTROL_PARAM.FW_R_CMD_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_YAW_RATE_LIM2), &CONTROL_PARAM.FW_YAW_RATE_LIM));

    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_AIRSPEED_TRIM), &CONTROL_PARAM.FW_AIRSPEED_TRIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_FF), &CONTROL_PARAM.FW_FF));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_FF_LIMIT), &CONTROL_PARAM.FW_FF_LIMIT));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_PI_LIMIT), &CONTROL_PARAM.FW_PI_LIMIT));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_ROLL_EFFC), &CONTROL_PARAM.FW_ROLL_EFFC));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_PITCH_EFFC), &CONTROL_PARAM.FW_PITCH_EFFC));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_YAW_EFFC), &CONTROL_PARAM.FW_YAW_EFFC));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_PITCH_OFFSET), &CONTROL_PARAM.FW_PITCH_OFFSET));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_CRUISE_THRO), &CONTROL_PARAM.FW_CRUISE_THRO));

    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_PITCH_F), &CONTROL_PARAM.FW_TECS_PITCH_F));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_THOR_FF), &CONTROL_PARAM.FW_TECS_THOR_FF));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_PITCH_P), &CONTROL_PARAM.FW_TECS_PITCH_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_THOR_P), &CONTROL_PARAM.FW_TECS_THOR_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_PITCH_I), &CONTROL_PARAM.FW_TECS_PITCH_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_PITCH_I_LIM), &CONTROL_PARAM.FW_TECS_PITCH_I_LIM));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_THOR_I), &CONTROL_PARAM.FW_TECS_THOR_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_PITCH_D), &CONTROL_PARAM.FW_TECS_PITCH_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_THOR_D), &CONTROL_PARAM.FW_TECS_THOR_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_VEL_P), &CONTROL_PARAM.FW_TECS_VEL_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_RATIO), &CONTROL_PARAM.FW_TECS_RATIO));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_SWITCH), &CONTROL_PARAM.FW_TECS_SWITCH));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_ANSW), &CONTROL_PARAM.FW_TECS_ANSW));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_W2T), &CONTROL_PARAM.FW_TECS_W2T));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_U2T), &CONTROL_PARAM.FW_TECS_U2T));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_W2P), &CONTROL_PARAM.FW_TECS_W2P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_U2P), &CONTROL_PARAM.FW_TECS_U2P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_R2P), &CONTROL_PARAM.FW_TECS_R2P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TECS_R2T), &CONTROL_PARAM.FW_TECS_R2T));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_OUT_MAX), &CONTROL_PARAM.FW_OUT_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_OUT_MIN), &CONTROL_PARAM.FW_OUT_MIN));

    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_AILERON1_DIR), &CONTROL_PARAM.FW_AILERON1_DIR));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_AILERON2_DIR), &CONTROL_PARAM.FW_AILERON2_DIR));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_ELEVATOR_DIR), &CONTROL_PARAM.FW_ELEVATOR_DIR));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_RUDDER_DIR), &CONTROL_PARAM.FW_RUDDER_DIR));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TAIL1_DIR), &CONTROL_PARAM.FW_TAIL1_DIR));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, FW_TAIL2_DIR), &CONTROL_PARAM.FW_TAIL2_DIR));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, SERVO1_BIAS), &CONTROL_PARAM.SERVO1_BIAS));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, SERVO2_BIAS), &CONTROL_PARAM.SERVO2_BIAS));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, SERVO3_BIAS), &CONTROL_PARAM.SERVO3_BIAS));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, SERVO4_BIAS), &CONTROL_PARAM.SERVO4_BIAS));
}

void control_interface_step(uint32_t timestamp)
{
    if (mcn_poll(fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), fms_out_nod, &Controller_U.FMS_Out);
    }

    if (mcn_poll(ins_out_nod)) {
        mcn_copy(MCN_HUB(ins_output), ins_out_nod, &Controller_U.INS_Out);
    }

    Controller_step();

    mcn_publish(MCN_HUB(control_output), &Controller_Y.Control_Out);

    DEFINE_TIMETAG(control_output, 100);
    /* Log Control output bus data */
    if (check_timetag(TIMETAG(control_output))) {
        /* Log Control out data */
        mlog_push_msg((uint8_t*)&Controller_Y.Control_Out, Control_Out_ID, sizeof(Control_Out_Bus));
    }
}

void control_interface_init(void)
{
    control_model_info.period = CONTROL_EXPORT.period;
    control_model_info.info = (char*)CONTROL_EXPORT.model_info;

    mcn_advertise(MCN_HUB(control_output), control_out_echo);

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL);
    ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL);

    Control_Out_ID = mlog_get_bus_id("Control_Out");
    FMT_ASSERT(Control_Out_ID >= 0);

    Controller_init();

    init_parameter();
}