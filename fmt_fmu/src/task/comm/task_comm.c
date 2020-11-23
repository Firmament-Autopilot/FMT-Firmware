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

#include <firmament.h>
#include <string.h>

#include "driver/gps.h"
#include "hal/cdcacm.h"
#include "module/ftp/ftp_manager.h"
#include "module/ins/ins_model.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sensor/sensor_manager.h"
#include "module/system/statistic.h"
#include "task/task_comm.h"
#include "task/task_vehicle.h"

MCN_DECLARE(ins_output);

static mavlink_system_t mavlink_system;

static void mavproxy_msg_heartbeat_pack(mavlink_message_t* msg_t)
{
    mavlink_heartbeat_t heartbeat;
    // uint16_t len;

    heartbeat.type = MAV_TYPE_QUADROTOR;
    heartbeat.autopilot = MAV_AUTOPILOT_PX4;
    // TODO, fill base_mode and custom_mode
    heartbeat.base_mode = MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;
    heartbeat.custom_mode = 0;
    heartbeat.system_status = MAV_STATE_STANDBY;

    mavlink_msg_heartbeat_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &heartbeat);
}

static void mavproxy_msg_sys_status_pack(mavlink_message_t* msg_t)
{
    mavlink_sys_status_t sys_status;
    // uint16_t len;

    sys_status.onboard_control_sensors_present = 1;
    sys_status.onboard_control_sensors_enabled = 1;
    sys_status.onboard_control_sensors_health = 1;
    sys_status.load = (uint16_t)(sysstat_get_cpu_usage() * 1e3);
    sys_status.voltage_battery = 11000;
    sys_status.current_battery = -1;
    sys_status.battery_remaining = -1;

    mavlink_msg_sys_status_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &sys_status);
}

static void mavproxy_msg_attitude_pack(mavlink_message_t* msg_t)
{
    mavlink_attitude_t attitude;
    INS_Out_Bus ins_out;

    mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out);

    attitude.roll = ins_out.phi;
    attitude.pitch = ins_out.theta;
    attitude.yaw = ins_out.psi;
    attitude.rollspeed = ins_out.p;
    attitude.pitchspeed = ins_out.q;
    attitude.yawspeed = ins_out.r;

    mavlink_msg_attitude_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &attitude);
}

static void _msg_local_pos_pack(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;

    mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out);

    mavlink_msg_local_position_ned_pack(
        mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms(),
        ins_out.x_R, ins_out.y_R, -ins_out.h_R, ins_out.vn, ins_out.ve,
        ins_out.vd);
}

fmt_err task_comm_init(void)
{
    fmt_err err;

    err = mavproxy_init();

    return err;
}

void task_comm_entry(void* parameter)
{
    mavlink_system = mavproxy_get_system();

    /* register periodical mavlink msg */
    mavproxy_register_period_msg(MAVLINK_MSG_ID_HEARTBEAT, 1000,
        mavproxy_msg_heartbeat_pack, 1);
    mavproxy_register_period_msg(MAVLINK_MSG_ID_SYS_STATUS, 1000,
        mavproxy_msg_sys_status_pack, 1);
    mavproxy_register_period_msg(MAVLINK_MSG_ID_ATTITUDE, 100,
        mavproxy_msg_attitude_pack, 1);
    mavproxy_register_period_msg(MAVLINK_MSG_ID_LOCAL_POSITION_NED, 200,
        _msg_local_pos_pack, 1);

    /* execute mavproxy main loop */
    mavproxy_loop();
}
