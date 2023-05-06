/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include <FMS.h>

#include "module/sysio/auto_cmd.h"

MCN_DEFINE(auto_cmd, sizeof(Auto_Cmd_Bus));

static int auto_cmd_echo(void* param)
{
    Auto_Cmd_Bus auto_cmd;

    mcn_copy_from_hub((McnHub*)param, &auto_cmd);

    printf("timestamp:%u frame:%d\n", auto_cmd.timestamp, auto_cmd.frame);
    
    if (auto_cmd.cmd_mask & P_CMD_VALID) {
        printf("p: %.2f\n", auto_cmd.p_cmd);
    }

    if (auto_cmd.cmd_mask & Q_CMD_VALID) {
        printf("q: %.2f\n", auto_cmd.q_cmd);
    }

    if (auto_cmd.cmd_mask & R_CMD_VALID) {
        printf("r: %.2f\n", auto_cmd.r_cmd);
    }

    if (auto_cmd.cmd_mask & PHI_CMD_VALID) {
        printf("phi: %.2f\n", auto_cmd.phi_cmd);
    }

    if (auto_cmd.cmd_mask & THETA_CMD_VALID) {
        printf("theta: %.2f\n", auto_cmd.theta_cmd);
    }

    if (auto_cmd.cmd_mask & PSI_CMD_VALID) {
        printf("psi: %.2f\n", auto_cmd.psi_cmd);
    }

    if (auto_cmd.cmd_mask & X_CMD_VALID) {
        printf("x: %.2f\n", auto_cmd.x_cmd);
    }

    if (auto_cmd.cmd_mask & Y_CMD_VALID) {
        printf("y: %.2f\n", auto_cmd.y_cmd);
    }

    if (auto_cmd.cmd_mask & Z_CMD_VALID) {
        printf("z: %.2f\n", auto_cmd.z_cmd);
    }

    if (auto_cmd.cmd_mask & LAT_CMD_VALID) {
        printf("lat: %d\n", auto_cmd.lat_cmd);
    }

    if (auto_cmd.cmd_mask & LON_CMD_VALID) {
        printf("lon: %.d\n", auto_cmd.lon_cmd);
    }

    if (auto_cmd.cmd_mask & ALT_CMD_VALID) {
        printf("alt: %.2f\n", auto_cmd.alt_cmd);
    }

    if (auto_cmd.cmd_mask & U_CMD_VALID) {
        printf("u: %.2f\n", auto_cmd.u_cmd);
    }

    if (auto_cmd.cmd_mask & V_CMD_VALID) {
        printf("v: %.2f\n", auto_cmd.v_cmd);
    }

    if (auto_cmd.cmd_mask & W_CMD_VALID) {
        printf("w: %.2f\n", auto_cmd.w_cmd);
    }

    if (auto_cmd.cmd_mask & AX_CMD_VALID) {
        printf("ax: %.2f\n", auto_cmd.ax_cmd);
    }

    if (auto_cmd.cmd_mask & AY_CMD_VALID) {
        printf("ay: %.2f\n", auto_cmd.ay_cmd);
    }

    if (auto_cmd.cmd_mask & AZ_CMD_VALID) {
        printf("az: %.2f\n", auto_cmd.az_cmd);
    }

    if (auto_cmd.cmd_mask & THROTTLE_CMD_VALID) {
        printf("throttle: %d\n", auto_cmd.throttle_cmd);
    }

    printf("------------------------------------------\n");

    return 0;
}

fmt_err_t auto_cmd_init(void)
{
    FMT_TRY(mcn_advertise(MCN_HUB(auto_cmd), auto_cmd_echo));

    return FMT_EOK;
}
