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

#define SIGN(_val) (_val > 0 ? 1.0f : -1.0f)
#define DT_MS      50

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void fly_to(float start[2], float end[2])
{
    Auto_Cmd_Bus auto_cmd;
    float pos_cmd[2] = { start[0], start[1] };
    float dis[2] = { end[0] - start[0], end[1] - start[1] };
    float dx, dy;

    while (1) {

        if (pos_cmd[0] == end[0]) {
            dx = 0;
        } else {
            dx = fabs(end[0] - pos_cmd[0]) <= 1.0 ? (end[0] - pos_cmd[0]) * 0.05 : SIGN(dis[0]) * 0.05;
            if (fabs(dx) < 0.005) {
                dx = SIGN(dis[0]) * 0.005;
            }
        }

        if (pos_cmd[1] == end[1]) {
            dy = 0;
        } else {
            dy = fabs(end[1] - pos_cmd[1]) <= 1.0 ? (end[1] - pos_cmd[1]) * 0.05 : SIGN(dis[1]) * 0.05;
            if (fabs(dy) < 0.005) {
                dy = SIGN(dis[1]) * 0.005;
            }
        }

        pos_cmd[0] += dx;
        pos_cmd[1] += dy;

        if ((dis[0] > 0 && pos_cmd[0] > end[0]) || (dis[0] < 0 && pos_cmd[0] < end[0])) {
            pos_cmd[0] = end[0];
        }

        if ((dis[1] > 0 && pos_cmd[1] > end[1]) || (dis[1] < 0 && pos_cmd[1] < end[1])) {
            pos_cmd[1] = end[1];
        }

        auto_cmd.timestamp = systime_now_ms();
        auto_cmd.frame = FRAME_LOCAL_FRD;
        auto_cmd.x_cmd = pos_cmd[0];
        auto_cmd.y_cmd = pos_cmd[1];
        auto_cmd.u_cmd = dx / (DT_MS / 1000.0);
        auto_cmd.v_cmd = dy / (DT_MS / 1000.0);
        auto_cmd.cmd_mask = X_CMD_VALID
            | Y_CMD_VALID
            | U_CMD_VALID
            | V_CMD_VALID;

        mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);

        sys_msleep(DT_MS);

        if (pos_cmd[0] == end[0] && pos_cmd[1] == end[1]) {
            break;
        }
    }

    uint32_t time_start = systime_now_ms();
    while (systime_now_ms() - time_start <= 2000) {
        auto_cmd.timestamp = systime_now_ms();
        auto_cmd.frame = FRAME_LOCAL_FRD;
        auto_cmd.x_cmd = end[0];
        auto_cmd.y_cmd = end[1];
        auto_cmd.cmd_mask = X_CMD_VALID
            | Y_CMD_VALID;

        mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);

        sys_msleep(DT_MS);
    }
}

static void task_entry(void* parameter)
{
    printf("Offboard rectangle demo!\n");

    McnNode_t fms_out_nod;
    FMS_Out_Bus fms_out;

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL);

    /* Set mode to offboard */
    gcs_set_mode(PilotMode_Offboard);

    systime_mdelay(1000);

    PARAM_SET_FLOAT(FMS, TAKEOFF_H, 1.5);           /* Set takeoff height to 1.5m */
    gcs_set_cmd(FMS_Cmd_Takeoff, (float[7]) { 0 }); /* Send takeoff command */

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

    float A0[2] = { 0, 0 };
    float A1[2] = { 5, 0 };
    float A2[2] = { 5, 10 };
    float A3[2] = { 0, 10 };

    fly_to(A0, A1);
    fly_to(A1, A2);
    fly_to(A2, A3);
    fly_to(A3, A0);

    gcs_set_cmd(FMS_Cmd_Land, (float[7]) { 0 }); /* Send land command */
}

TASK_EXPORT __fmt_task_desc = {
    .name = "offboard1",
    .init = task_init,
    .entry = task_entry,
    .priority = 25,
    .auto_start = false,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};
