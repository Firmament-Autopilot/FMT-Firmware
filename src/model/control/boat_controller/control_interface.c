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
    PARAM_FLOAT(VEL_P, 0.5, false),
    PARAM_FLOAT(VEL_I, 0.1, false),
    PARAM_FLOAT(VEL_D, 0.0, false),
    PARAM_FLOAT(VEL_I_MAX, 0.2, false),
    PARAM_FLOAT(VEL_I_MIN, -0.2, false),
    PARAM_FLOAT(VEL_D_MAX, 0.1, false),
    PARAM_FLOAT(VEL_D_MIN, -0.1, false),
    PARAM_FLOAT(PSI_RATE_P, 1.0, false),
    PARAM_FLOAT(THROTTLE_SCALE, 1000, false),
    PARAM_UINT16(THROTTLE_BIAS, 1000, false),
    PARAM_FLOAT(SERVO_SCALE, 250, false),
    PARAM_UINT16(SERVO_BIAS, 1500, false),
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
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_P), &CONTROL_PARAM.VEL_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_I), &CONTROL_PARAM.VEL_I));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_D), &CONTROL_PARAM.VEL_D));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_I_MAX), &CONTROL_PARAM.VEL_I_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_I_MIN), &CONTROL_PARAM.VEL_I_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_D_MAX), &CONTROL_PARAM.VEL_D_MAX));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, VEL_D_MIN), &CONTROL_PARAM.VEL_D_MIN));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, PSI_RATE_P), &CONTROL_PARAM.PSI_RATE_P));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, THROTTLE_SCALE), &CONTROL_PARAM.THROTTLE_SCALE));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, THROTTLE_BIAS), &CONTROL_PARAM.THROTTLE_BIAS));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, SERVO_SCALE), &CONTROL_PARAM.SERVO_SCALE));
    FMT_CHECK(param_link_variable(PARAM_GET(CONTROL, SERVO_BIAS), &CONTROL_PARAM.SERVO_BIAS));
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