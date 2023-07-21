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

#ifdef BIT
    #undef BIT
#endif

#define BIT(u, n) (u & (1 << n))

MCN_DECLARE(external_state);
static McnNode_t ext_state_node;

/* INS output bus */
MCN_DEFINE(ins_output, sizeof(INS_Out_Bus));

mlog_elem_t INS_Out_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(phi, MLOG_FLOAT),
    MLOG_ELEMENT(theta, MLOG_FLOAT),
    MLOG_ELEMENT(psi, MLOG_FLOAT),
    MLOG_ELEMENT_VEC(quat, MLOG_FLOAT, 4),
    MLOG_ELEMENT(p, MLOG_FLOAT),
    MLOG_ELEMENT(q, MLOG_FLOAT),
    MLOG_ELEMENT(r, MLOG_FLOAT),
    MLOG_ELEMENT(ax, MLOG_FLOAT),
    MLOG_ELEMENT(ay, MLOG_FLOAT),
    MLOG_ELEMENT(az, MLOG_FLOAT),
    MLOG_ELEMENT(vn, MLOG_FLOAT),
    MLOG_ELEMENT(ve, MLOG_FLOAT),
    MLOG_ELEMENT(vd, MLOG_FLOAT),
    MLOG_ELEMENT(airspeed, MLOG_FLOAT),
    MLOG_ELEMENT(lat, MLOG_DOUBLE),
    MLOG_ELEMENT(lon, MLOG_DOUBLE),
    MLOG_ELEMENT(alt, MLOG_DOUBLE),
    MLOG_ELEMENT(lat_0, MLOG_DOUBLE),
    MLOG_ELEMENT(lon_0, MLOG_DOUBLE),
    MLOG_ELEMENT(alt_0, MLOG_DOUBLE),
    MLOG_ELEMENT(x_R, MLOG_FLOAT),
    MLOG_ELEMENT(y_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_AGL, MLOG_FLOAT),
    MLOG_ELEMENT(flag, MLOG_UINT32),
    MLOG_ELEMENT(status, MLOG_UINT32),
};
MLOG_BUS_DEFINE(INS_Out, INS_Out_Elems);

static int INS_Out_ID;

/* Model information */
fmt_model_info_t ins_model_info;

static int ins_output_echo(void* param)
{
    INS_Out_Bus ins_out;

    mcn_copy_from_hub((McnHub*)param, &ins_out);

    printf("timestamp:%u\n", ins_out.timestamp);
    printf("att: %.2f %.2f %.2f\n", RAD2DEG(ins_out.phi), RAD2DEG(ins_out.theta), RAD2DEG(ins_out.psi));
    printf("rate: %.2f %.2f %.2f\n", ins_out.p, ins_out.q, ins_out.r);
    printf("accel: %.2f %.2f %.2f\n", ins_out.ax, ins_out.ay, ins_out.az);
    printf("vel: %.2f %.2f %.2f airspeed:%.2f\n", ins_out.vn, ins_out.ve, ins_out.vd, ins_out.airspeed);
    printf("xyh: %.2f %.2f %.2f, h_AGL: %.2f\n", ins_out.x_R, ins_out.y_R, ins_out.h_R, ins_out.h_AGL);
    printf("LLA: %lf %lf %f\n", ins_out.lat, ins_out.lon, ins_out.alt);
    printf("LLA0: %lf %lf %f\n", ins_out.lat_0, ins_out.lon_0, ins_out.alt_0);
    printf("standstill:%d att:%d heading:%d vel:%d LLA:%d xy:%d h:%d h_AGL:%d\n",
           BIT(ins_out.flag, 1) > 0,
           BIT(ins_out.flag, 2) > 0,
           BIT(ins_out.flag, 3) > 0,
           BIT(ins_out.flag, 4) > 0,
           BIT(ins_out.flag, 5) > 0,
           BIT(ins_out.flag, 6) > 0,
           BIT(ins_out.flag, 7) > 0,
           BIT(ins_out.flag, 8) > 0);
    printf("sensor status, imu1:%d imu2:%d mag:%d baro:%d gps:%d rf:%d optflow:%d\n",
           BIT(ins_out.status, 0) > 0,
           BIT(ins_out.status, 1) > 0,
           BIT(ins_out.status, 2) > 0,
           BIT(ins_out.status, 3) > 0,
           BIT(ins_out.status, 4) > 0,
           BIT(ins_out.status, 5) > 0,
           BIT(ins_out.status, 6) > 0);
    printf("------------------------------------------\n");

    return 0;
}

void ins_interface_step(void)
{
    if (mcn_poll(ext_state_node)) {
        mavlink_fmt_external_state_t external_state;
        Euler euler;
        INS_Out_Bus ins_out = { 0 };

        mcn_copy(MCN_HUB(external_state), ext_state_node, &external_state);

        ins_out.timestamp = external_state.timestamp;

        ins_out.quat[0] = external_state.quat[0];
        ins_out.quat[1] = external_state.quat[1];
        ins_out.quat[2] = external_state.quat[2];
        ins_out.quat[3] = external_state.quat[3];

        quaternion_toEuler((quaternion*)ins_out.quat, &euler);
        ins_out.phi = euler.roll;
        ins_out.theta = euler.pitch;
        ins_out.psi = euler.yaw;

        ins_out.p = external_state.rot[0];
        ins_out.q = external_state.rot[1];
        ins_out.r = external_state.rot[2];

        float acc_B[3];
        quaternion_inv_rotateVector((quaternion*)ins_out.quat, external_state.acc, acc_B);
        ins_out.ax = acc_B[0];
        ins_out.ay = acc_B[1];
        ins_out.az = acc_B[2];

        ins_out.vn = external_state.vel[0];
        ins_out.ve = external_state.vel[1];
        ins_out.vd = external_state.vel[2];

        ins_out.lat = DEG2RAD((double)external_state.lla[0]) * 1e-7;
        ins_out.lon = DEG2RAD((double)external_state.lla[1]) * 1e-7;
        ins_out.alt = (double)external_state.lla[2] * 1e-3;

        ins_out.x_R = external_state.pos[0];
        ins_out.y_R = external_state.pos[1];
        ins_out.h_R = -external_state.pos[2];
        ins_out.h_AGL = external_state.h_AGL;

        ins_out.flag = external_state.flag | 1;

        /* publish INS output */
        mcn_publish(MCN_HUB(ins_output), &ins_out);

        /* Log INS output bus data */
        DEFINE_TIMETAG(ins_output, 100);
        if (check_timetag(TIMETAG(ins_output))) {
            /* Log INS out data */
            mlog_push_msg((uint8_t*)&ins_out, INS_Out_ID, sizeof(ins_out));
        }
    }
}

void ins_interface_init(void)
{
    /* Fill in the modle information */
    ins_model_info.period = 1;
    ins_model_info.info = "External INS v1.0.0";

    /* advertise ins_output topic */
    mcn_advertise(MCN_HUB(ins_output), ins_output_echo);

    ext_state_node = mcn_subscribe(MCN_HUB(external_state), NULL, NULL);
    if (ext_state_node == NULL) {
        printf("External_INS fail to subscribe external_state topic!\n");
    }

    INS_Out_ID = mlog_get_bus_id("INS_Out");
    FMT_ASSERT(INS_Out_ID >= 0);
}
