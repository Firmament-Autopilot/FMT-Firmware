/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#include "FMS.h"
#include "INS.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(auto_cmd);
MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);

#define FLIGHT_ALTITUDE 1.5f
#define RATE            50  // loop rate hz
#define RADIUS          5.0 // radius of figure 8 in meters
#define CYCLE_S         30  // time to complete one figure 8 cycle in seconds
#define STEPS           (CYCLE_S * RATE)

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
    /* This demo reders to: https://gitlab.com/voxl-public/voxl-sdk/services/voxl-vision-px4/-/blob/f8223eff0e2a935ce05aa395e2d44739b7b322b4/src/offboard_figure_eight.c */
    printf("Offboard figure eight demo!\n");

    const float dt = 1.0f / RATE;
    const float dadt = (2.0f * PI) / CYCLE_S; // first derivative of angle with respect to time
    const float r = RADIUS;
    uint32_t i = 0;
    McnNode_t fms_out_nod;
    McnNode_t ins_out_nod;
    FMS_Out_Bus fms_out;
    INS_Out_Bus ins_out;
    Auto_Cmd_Bus auto_cmd;

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL);
    ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL);

    /* Set mode to offboard */
    gcs_set_mode(PilotMode_Offboard);

    systime_mdelay(1000);

    PARAM_SET_FLOAT(FMS, TAKEOFF_H, FLIGHT_ALTITUDE); /* Set takeoff height to 1.5m */
    gcs_set_cmd(FMS_Cmd_Takeoff, (float[7]) { 0 });   /* Send takeoff command */

    /* Wait until takeoff complete */
    while (1) {
        if (mcn_wait(fms_out_nod, RT_WAITING_FOREVER)) {
            mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out);
            if (fms_out.state == VehicleState_Hold) {
                break;
            }
        }
    }

    systime_mdelay(2000);

    if (mcn_wait(ins_out_nod, RT_WAITING_FOREVER)) {
        mcn_copy(MCN_HUB(ins_output), ins_out_nod, &ins_out);
    }

    uint32_t time_start = systime_now_ms();
    while (1) {
        // calculate the parameter a which is an angle sweeping from -pi/2 to 3pi/2
        // through the curve
        float a = (-PI / 2.0f) + i * (2.0f * PI / STEPS);
        float c = cos(a);
        float c2a = cos(2.0 * a);
        float c4a = cos(4.0 * a);
        float c2am3 = c2a - 3.0;
        float c2am3_cubed = c2am3 * c2am3 * c2am3;
        float s = sin(a);
        float cc = c * c;
        float ss = s * s;
        float sspo = (s * s) + 1.0; // sin squared plus one
        float ssmo = (s * s) - 1.0; // sin squared minus one
        float sspos = sspo * sspo;

        auto_cmd.timestamp = systime_now_ms(),
        auto_cmd.frame = FRAME_LOCAL_FRD,
        auto_cmd.x_cmd = -(r * c * s) / sspo,
        auto_cmd.y_cmd = (r * c) / sspo,
        auto_cmd.z_cmd = -ins_out.h_R,
        auto_cmd.u_cmd = dadt * r * (ss * ss + ss + (ssmo * cc)) / sspos,
        auto_cmd.v_cmd = -dadt * r * s * (ss + 2.0 * cc + 1.0) / sspos,
        auto_cmd.ax_cmd = -dadt * dadt * 8.0 * r * s * c * ((3.0 * c2a) + 7.0) / c2am3_cubed,
        auto_cmd.ay_cmd = dadt * dadt * r * c * ((44.0 * c2a) + c4a - 21.0) / c2am3_cubed,
        auto_cmd.psi_cmd = atan2(auto_cmd.v_cmd, auto_cmd.u_cmd) + ins_out.psi,
        auto_cmd.cmd_mask = X_CMD_VALID
            | Y_CMD_VALID
            | Z_CMD_VALID
            | U_CMD_VALID
            | V_CMD_VALID
            | AX_CMD_VALID
            | AY_CMD_VALID
            | PSI_CMD_VALID;

        mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);

        i = (i + 1) % STEPS;

        if (systime_now_ms() - time_start >= 60 * 1000) {
            /* stop after 60s */
            break;
        }

        sys_msleep(dt * 1000);
    }

    gcs_set_cmd(FMS_Cmd_Return, (float[7]) { 0 }); /* Send return command */
}

TASK_EXPORT __fmt_task_desc = {
    .name = "offboard",
    .init = task_init,
    .entry = task_entry,
    .priority = 25,
    .auto_start = false,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};
