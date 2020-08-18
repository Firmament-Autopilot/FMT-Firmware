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

#define TAG "Controller"

/* controller input topic */
MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);

/* controller output topic */
MCN_DEFINE(control_output, sizeof(Control_Out_Bus));

static McnNode_t _fms_out_nod;
static McnNode_t _ins_out_nod;

static int _control_out_echo(void* param)
{
    Control_Out_Bus control_out;
    if(mcn_copy_from_hub((McnHub*)param, &control_out) == FMT_EOK){
        console_printf("timestamp:%d actuator: %d %d %d %d\n", control_out.timestamp, control_out.actuator_cmd[0], 
            control_out.actuator_cmd[1], control_out.actuator_cmd[2], control_out.actuator_cmd[3]);
    }
    return 0;
}

static void _update_model_parameter(void)
{
    CONTROL_PARAM.VEL_XY_P = PARAM_GET_FLOAT(CONTROL, VEL_XY_P);
    CONTROL_PARAM.VEL_XY_I = PARAM_GET_FLOAT(CONTROL, VEL_XY_I);
    CONTROL_PARAM.VEL_XY_D = PARAM_GET_FLOAT(CONTROL, VEL_XY_D);
    CONTROL_PARAM.VEL_Z_P = PARAM_GET_FLOAT(CONTROL, VEL_Z_P);
    CONTROL_PARAM.VEL_Z_I = PARAM_GET_FLOAT(CONTROL, VEL_Z_I);
    CONTROL_PARAM.VEL_Z_D = PARAM_GET_FLOAT(CONTROL, VEL_Z_D);
    CONTROL_PARAM.VEL_XY_I_MIN = PARAM_GET_FLOAT(CONTROL, VEL_XY_I_MIN);
    CONTROL_PARAM.VEL_XY_I_MAX = PARAM_GET_FLOAT(CONTROL, VEL_XY_I_MAX);
    CONTROL_PARAM.VEL_XY_D_MIN = PARAM_GET_FLOAT(CONTROL, VEL_XY_D_MIN);
    CONTROL_PARAM.VEL_XY_D_MAX = PARAM_GET_FLOAT(CONTROL, VEL_XY_D_MAX);
    CONTROL_PARAM.VEL_Z_I_MIN = PARAM_GET_FLOAT(CONTROL, VEL_Z_I_MIN);
    CONTROL_PARAM.VEL_Z_I_MAX = PARAM_GET_FLOAT(CONTROL, VEL_Z_I_MAX);
    CONTROL_PARAM.VEL_Z_D_MIN = PARAM_GET_FLOAT(CONTROL, VEL_Z_D_MIN);
    CONTROL_PARAM.VEL_Z_D_MAX = PARAM_GET_FLOAT(CONTROL, VEL_Z_D_MAX);
    CONTROL_PARAM.ROLL_P = PARAM_GET_FLOAT(CONTROL, ROLL_P);
    CONTROL_PARAM.PITCH_P = PARAM_GET_FLOAT(CONTROL, PITCH_P);
    CONTROL_PARAM.ROLL_PITCH_CMD_LIM = PARAM_GET_FLOAT(CONTROL, ROLL_PITCH_CMD_LIM);
    CONTROL_PARAM.ROLL_RATE_P = PARAM_GET_FLOAT(CONTROL, ROLL_RATE_P);
    CONTROL_PARAM.PITCH_RATE_P = PARAM_GET_FLOAT(CONTROL, PITCH_RATE_P);
    CONTROL_PARAM.YAW_RATE_P = PARAM_GET_FLOAT(CONTROL, YAW_RATE_P);
    CONTROL_PARAM.ROLL_RATE_I = PARAM_GET_FLOAT(CONTROL, ROLL_RATE_I);
    CONTROL_PARAM.PITCH_RATE_I = PARAM_GET_FLOAT(CONTROL, PITCH_RATE_I);
    CONTROL_PARAM.YAW_RATE_I = PARAM_GET_FLOAT(CONTROL, YAW_RATE_I);
    CONTROL_PARAM.ROLL_RATE_D = PARAM_GET_FLOAT(CONTROL, ROLL_RATE_D);
    CONTROL_PARAM.PITCH_RATE_D = PARAM_GET_FLOAT(CONTROL, PITCH_RATE_D);
    CONTROL_PARAM.YAW_RATE_D = PARAM_GET_FLOAT(CONTROL, YAW_RATE_D);
    CONTROL_PARAM.RATE_I_MIN = PARAM_GET_FLOAT(CONTROL, RATE_I_MIN);
    CONTROL_PARAM.RATE_I_MAX = PARAM_GET_FLOAT(CONTROL, RATE_I_MAX);
    CONTROL_PARAM.RATE_D_MIN = PARAM_GET_FLOAT(CONTROL, RATE_D_MIN);
    CONTROL_PARAM.RATE_D_MAX = PARAM_GET_FLOAT(CONTROL, RATE_D_MAX);
    CONTROL_PARAM.P_Q_CMD_LIM = PARAM_GET_FLOAT(CONTROL, P_Q_CMD_LIM);
    CONTROL_PARAM.R_CMD_LIM = PARAM_GET_FLOAT(CONTROL, R_CMD_LIM);
}

void controller_model_step(void)
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

    if (mcn_poll(_fms_out_nod)) {
        mcn_copy(MCN_ID(fms_output), _fms_out_nod, &Controller_U.FMS_Out);
    }

    if (mcn_poll(_ins_out_nod)) {
        mcn_copy(MCN_ID(ins_output), _ins_out_nod, &Controller_U.INS_Out);
    }

    Controller_step();

    mcn_publish(MCN_ID(control_output), &Controller_Y.Control_Out);

    DEFINE_TIMETAG(control_output, 100);
    /* Log Control output bus data */
    if (check_timetag(TIMETAG(control_output))) {
        /* rewrite timestmp */
        Controller_Y.Control_Out.timestamp = time_now - start_time;
        /* Log Control out data */
        blog_push_msg((uint8_t*)&Controller_Y.Control_Out, BLOG_CONTROL_OUT_ID, sizeof(Control_Out_Bus));
    }
}

void controller_model_init(void)
{
    mcn_advertise(MCN_ID(control_output), _control_out_echo);

    _fms_out_nod = mcn_subscribe(MCN_ID(fms_output), NULL, NULL);
    _ins_out_nod = mcn_subscribe(MCN_ID(ins_output), NULL, NULL);

    Controller_init();

    _update_model_parameter();
}