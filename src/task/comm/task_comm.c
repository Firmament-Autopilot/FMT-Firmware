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

#include "FMS.h"
#include "module/fms/fms_interface.h"
#include "module/ftp/ftp_manager.h"
#include "module/ins/ins_interface.h"
#include "module/mavproxy/mavproxy.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/system/statistic.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(ins_output);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(rc_channels);
MCN_DECLARE(bat0_status);
MCN_DECLARE(fms_output);

static mavlink_system_t mavlink_system;
static McnNode_t fms_out_nod;

static uint32_t get_custom_mode(uint32_t mode)
{
    uint32_t custom_mode;

    switch (mode) {
    case VehicleMode_Manual:
        custom_mode = 1 << 16;
        break;
    case VehicleMode_Altitude:
        custom_mode = 2 << 16;
        break;
    case VehicleMode_Position:
        custom_mode = 3 << 16;
        break;
    case VehicleMode_Takeoff:
        custom_mode = (4 << 16) + (2 << 24);
        break;
    case VehicleMode_Hold:
        custom_mode = (4 << 16) + (3 << 24);
        break;
    case VehicleMode_Mission:
        custom_mode = (4 << 16) + (4 << 24);
        break;
    case VehicleMode_Return:
        custom_mode = (4 << 16) + (5 << 24);
        break;
    case VehicleMode_Land:
        custom_mode = (4 << 16) + (6 << 24);
        break;
    case VehicleMode_Acro:
        custom_mode = 5 << 16;
        break;
    case VehicleMode_Offboard:
        custom_mode = 6 << 16;
        break;
    case VehicleMode_Stabilize:
        custom_mode = 7 << 16;
        break;
    default:
        custom_mode = 0;
    }

    return custom_mode;
}

static bool mavlink_msg_heartbeat_cb(mavlink_message_t* msg_t)
{
    mavlink_heartbeat_t heartbeat;
    FMS_Out_Bus fms_out;

    heartbeat.type = MAV_TYPE_QUADROTOR;
    heartbeat.autopilot = MAV_AUTOPILOT_PX4;
    heartbeat.base_mode = MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;
    heartbeat.custom_mode = 0;
    heartbeat.system_status = MAV_STATE_STANDBY;

    if (mcn_poll(fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out);

        if (fms_out.status == VehicleStatus_Arm || fms_out.status == VehicleStatus_Standby) {
            heartbeat.base_mode |= MAV_MODE_FLAG_SAFETY_ARMED;
            heartbeat.system_status = MAV_STATE_ACTIVE;
        }
        /* map fms mode to px4 ctrl mode */
        heartbeat.custom_mode = get_custom_mode(fms_out.mode);
    }

    mavlink_msg_heartbeat_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &heartbeat);

    return true;
}

static bool mavlink_msg_sys_status_cb(mavlink_message_t* msg_t)
{
    mavlink_sys_status_t sys_status;
    struct battery_status bat0_status;

    if (mcn_copy_from_hub(MCN_HUB(bat0_status), &bat0_status) != FMT_EOK) {
        return false;
    }

    sys_status.onboard_control_sensors_present = 1;
    sys_status.onboard_control_sensors_enabled = 1;
    sys_status.onboard_control_sensors_health = 1;
    sys_status.load = (uint16_t)(get_cpu_usage() * 1e3);
    sys_status.voltage_battery = bat0_status.battery_voltage;
    sys_status.current_battery = -1;
    sys_status.battery_remaining = -1;

    mavlink_msg_sys_status_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &sys_status);

    return true;
}

static bool mavlink_msg_system_time_cb(mavlink_message_t* msg_t)
{
    mavlink_system_time_t system_time;

    system_time.time_unix_usec = systime_now_us();
    system_time.time_boot_ms = systime_now_ms();

    mavlink_msg_system_time_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &system_time);

    return true;
}

static bool mavlink_msg_attitude_cb(mavlink_message_t* msg_t)
{
    mavlink_attitude_t attitude;
    INS_Out_Bus ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    attitude.roll = ins_out.phi;
    attitude.pitch = ins_out.theta;
    attitude.yaw = ins_out.psi;
    attitude.rollspeed = ins_out.p;
    attitude.pitchspeed = ins_out.q;
    attitude.yawspeed = ins_out.r;

    mavlink_msg_attitude_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &attitude);

    return true;
}

static bool mavlink_msg_local_pos_cb(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    mavlink_msg_local_position_ned_pack(
        mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms(),
        ins_out.x_R, ins_out.y_R, -ins_out.h_R, ins_out.vn, ins_out.ve,
        ins_out.vd);

    return true;
}

static bool mavlink_msg_altitude_cb(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;
    baro_data_t baro_report;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }
    if (mcn_copy_from_hub(MCN_HUB(sensor_baro), &baro_report) != FMT_EOK) {
        return false;
    }

    mavlink_msg_altitude_pack(mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms() * 1e3,
        baro_report.altitude_m, baro_report.altitude_m, ins_out.h_R, ins_out.h_R, ins_out.h_AGL, 0.0f);

    return true;
}

static bool mavlink_msg_gps_raw_int_cb(mavlink_message_t* msg_t)
{
    gps_data_t gps_report;
    McnHub* hub = MCN_HUB(sensor_gps);
    mavlink_gps_raw_int_t gps_raw_int;

    if (!hub->published) {
        return false;
    }

    if (mcn_copy_from_hub(hub, &gps_report) != FMT_EOK) {
        return false;
    }

    gps_raw_int.time_usec = gps_report.timestamp_ms * 1e3;
    gps_raw_int.lat = gps_report.lat;
    gps_raw_int.lon = gps_report.lon;
    gps_raw_int.alt = gps_report.height;
    gps_raw_int.eph = gps_report.hAcc * 1e3;
    gps_raw_int.epv = gps_report.vAcc * 1e3;
    gps_raw_int.vel = gps_report.vel * 1e2;
    gps_raw_int.cog = gps_report.cog * 1e2;
    gps_raw_int.fix_type = gps_report.fixType;
    gps_raw_int.satellites_visible = gps_report.numSV;
    gps_raw_int.alt_ellipsoid = gps_report.height;
    gps_raw_int.h_acc = gps_report.hAcc * 1e3;
    gps_raw_int.v_acc = gps_report.vAcc * 1e3;
    gps_raw_int.vel_acc = gps_report.sAcc * 1e3;
    gps_raw_int.hdg_acc = 0;
    gps_raw_int.yaw = 0;

    mavlink_msg_gps_raw_int_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &gps_raw_int);

    return true;
}

static bool mavlink_msg_rc_channels_cb(mavlink_message_t* msg_t)
{
    int16_t rc_channels[16];
    McnHub* hub = MCN_HUB(rc_channels);
    mavlink_rc_channels_t mavlink_rc_channels;

    if (!hub->published) {
        return false;
    }

    if (mcn_copy_from_hub(hub, &rc_channels) != FMT_EOK) {
        return false;
    }

    mavlink_rc_channels.time_boot_ms = systime_now_ms();
    mavlink_rc_channels.chancount = 16;
    mavlink_rc_channels.rssi = 40;
    memcpy(&mavlink_rc_channels.chan1_raw, &rc_channels, sizeof(rc_channels));

    mavlink_msg_rc_channels_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &mavlink_rc_channels);

    return true;
}

fmt_err_t task_comm_init(void)
{
    fmt_err_t err;

    err = mavproxy_init();

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    FMT_ASSERT(fms_out_nod != NULL);

    return err;
}

void task_comm_entry(void* parameter)
{
    mavlink_system = mavproxy_get_system();

    /* register periodical mavlink msg */
    mavproxy_register_period_msg(MAVLINK_MSG_ID_HEARTBEAT, 1000,
        mavlink_msg_heartbeat_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_SYS_STATUS, 1000,
        mavlink_msg_sys_status_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_SYSTEM_TIME, 1000,
        mavlink_msg_system_time_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_ATTITUDE, 100,
        mavlink_msg_attitude_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_LOCAL_POSITION_NED, 200,
        mavlink_msg_local_pos_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_ALTITUDE, 100,
        mavlink_msg_altitude_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_GPS_RAW_INT, 100,
        mavlink_msg_gps_raw_int_cb, 1);

    mavproxy_register_period_msg(MAVLINK_MSG_ID_RC_CHANNELS, 100,
        mavlink_msg_rc_channels_cb, 1);

    /* execute mavproxy main loop */
    mavproxy_loop();
}

TASK_EXPORT __fmt_task_desc = {
    .name = "comm",
    .init = task_comm_init,
    .entry = task_comm_entry,
    .priority = COMM_THREAD_PRIORITY,
    .stack_size = 8192,
    .param = NULL,
    .dependency = NULL
};