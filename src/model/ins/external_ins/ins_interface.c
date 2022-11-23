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

#include <INS.h>
#include <firmament.h>

#include "module/mavproxy/mavproxy.h"

#ifdef FMT_USING_EXTERNAL_STATE
MCN_DECLARE(mav_ext_state);
static McnNode_t ext_state_node;
#endif

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));
/* Model information */
fmt_model_info_t ins_model_info;

void ins_interface_step(void)
{
    /* Add your code here */
#ifdef FMT_USING_EXTERNAL_STATE
    if (mcn_poll(ext_state_node)) {
        mavlink_fmt_external_state_t mav_ext_state;
        Euler euler;
        INS_Out_Bus ins_out = { 0 };

        mcn_copy(MCN_HUB(mav_ext_state), ext_state_node, &mav_ext_state);

        ins_out.timestamp = mav_ext_state.timestamp;

        ins_out.quat[0] = mav_ext_state.quat[0];
        ins_out.quat[1] = mav_ext_state.quat[1];
        ins_out.quat[2] = mav_ext_state.quat[2];
        ins_out.quat[3] = mav_ext_state.quat[3];

        quaternion_toEuler((quaternion*)ins_out.quat, &euler);
        ins_out.phi = euler.roll;
        ins_out.theta = euler.pitch;
        ins_out.psi = euler.yaw;

        ins_out.p = mav_ext_state.rot[0];
        ins_out.q = mav_ext_state.rot[1];
        ins_out.r = mav_ext_state.rot[2];

        float acc_B[3];
        quaternion_inv_rotateVector((quaternion*)ins_out.quat, mav_ext_state.acc, acc_B);
        ins_out.ax = acc_B[0];
        ins_out.ay = acc_B[1];
        ins_out.az = acc_B[2];

        ins_out.vn = mav_ext_state.vel[0];
        ins_out.ve = mav_ext_state.vel[1];
        ins_out.vd = mav_ext_state.vel[2];

        ins_out.lon = (double)mav_ext_state.lla[0] * 1e-7;
        ins_out.lat = (double)mav_ext_state.lla[1] * 1e-7;
        ins_out.alt = (double)mav_ext_state.lla[2] * 1e-3;

        ins_out.x_R = mav_ext_state.pos[0];
        ins_out.y_R = mav_ext_state.pos[1];
        ins_out.h_R = -mav_ext_state.pos[2];
        ins_out.h_AGL = mav_ext_state.h_AGL;

        ins_out.flag = mav_ext_state.flag | 1;

        /* publish INS output */
        mcn_publish(MCN_HUB(ins_output), &ins_out);
    }
#endif
}

void ins_interface_init(void)
{
    /* Fill in the modle information */
    ins_model_info.period = 1;
    ins_model_info.info = "External INS v1.0.0";

    /* advertise ins_output topic */
    mcn_advertise(MCN_HUB(ins_output), NULL);

/* Add your code here */
#ifdef FMT_USING_EXTERNAL_STATE
    ext_state_node = mcn_subscribe(MCN_HUB(mav_ext_state), NULL, NULL);
    if (ext_state_node == NULL) {
        printf("External_INS fail to subscribe mav_ext_state topic!\n");
    }
#endif
}
