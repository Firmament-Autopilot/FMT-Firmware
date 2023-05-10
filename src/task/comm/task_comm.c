/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/px4_custom_mode.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(sensor_rangefinder);
MCN_DECLARE(sensor_airspeed);
MCN_DECLARE(ins_output);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(rc_channels);
MCN_DECLARE(bat0_status);
MCN_DECLARE(fms_output);
MCN_DECLARE(auto_cmd);

static mavlink_system_t mavlink_system;

fmt_err_t gcs_handler_init(void);

static uint32_t get_custom_mode(FMS_Out_Bus fms_out)
{
    uint32_t custom_mode = 0;

    if (fms_out.status == VehicleStatus_Arm) {
        switch (fms_out.state) {
        case VehicleState_Manual:
            custom_mode = PX4_CUSTOM_MAIN_MODE_MANUAL << 16;
            break;
        case VehicleState_Altitude:
            custom_mode = PX4_CUSTOM_MAIN_MODE_ALTCTL << 16;
            break;
        case VehicleState_Position:
            custom_mode = PX4_CUSTOM_MAIN_MODE_POSCTL << 16;
            break;
        case VehicleState_Takeoff:
            custom_mode = (PX4_CUSTOM_MAIN_MODE_AUTO << 16) + (PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF << 24);
            break;
        case VehicleState_Hold:
            custom_mode = (PX4_CUSTOM_MAIN_MODE_AUTO << 16) + (PX4_CUSTOM_SUB_MODE_AUTO_LOITER << 24);
            break;
        case VehicleState_Mission:
            custom_mode = (PX4_CUSTOM_MAIN_MODE_AUTO << 16) + (PX4_CUSTOM_SUB_MODE_AUTO_MISSION << 24);
            break;
        case VehicleState_Return:
            custom_mode = (PX4_CUSTOM_MAIN_MODE_AUTO << 16) + (PX4_CUSTOM_SUB_MODE_AUTO_RTL << 24);
            break;
        case VehicleState_Land:
            custom_mode = (PX4_CUSTOM_MAIN_MODE_AUTO << 16) + (PX4_CUSTOM_SUB_MODE_AUTO_LAND << 24);
            break;
        case VehicleState_Acro:
            custom_mode = PX4_CUSTOM_MAIN_MODE_ACRO << 16;
            break;
        case VehicleState_Offboard:
            custom_mode = PX4_CUSTOM_MAIN_MODE_OFFBOARD << 16;
            break;
        case VehicleState_Stabilize:
            custom_mode = PX4_CUSTOM_MAIN_MODE_STABILIZED << 16;
            break;
        default:
            custom_mode = 0;
        }
    } else {
        switch (fms_out.mode) {
        case PilotMode_Manual:
            custom_mode = PX4_CUSTOM_MAIN_MODE_MANUAL << 16;
            break;
        case PilotMode_Acro:
            custom_mode = PX4_CUSTOM_MAIN_MODE_ACRO << 16;
            break;
        case PilotMode_Stabilize:
            custom_mode = PX4_CUSTOM_MAIN_MODE_STABILIZED << 16;
            break;
        case PilotMode_Altitude:
            custom_mode = PX4_CUSTOM_MAIN_MODE_ALTCTL << 16;
            break;
        case PilotMode_Position:
            custom_mode = PX4_CUSTOM_MAIN_MODE_POSCTL << 16;
            break;
        case PilotMode_Mission:
            custom_mode = (PX4_CUSTOM_MAIN_MODE_AUTO << 16) + (PX4_CUSTOM_SUB_MODE_AUTO_MISSION << 24);
            break;
        case PilotMode_Offboard:
            custom_mode = PX4_CUSTOM_MAIN_MODE_OFFBOARD << 16;
            break;
        default:
            custom_mode = 0;
            break;
        }
    }

    return custom_mode;
}

bool mavlink_msg_heartbeat_pack_func(mavlink_message_t* msg_t)
{
    mavlink_heartbeat_t heartbeat;
    FMS_Out_Bus fms_out;

    heartbeat.type = MAV_TYPE_QUADROTOR;
    heartbeat.autopilot = MAV_AUTOPILOT_PX4;
    heartbeat.base_mode = MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;
    heartbeat.custom_mode = 0;
    heartbeat.system_status = MAV_STATE_STANDBY;

    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
        return false;
    }

    if (fms_out.status == VehicleStatus_Arm || fms_out.status == VehicleStatus_Standby) {
        heartbeat.base_mode |= MAV_MODE_FLAG_SAFETY_ARMED;
        heartbeat.system_status = MAV_STATE_ACTIVE;
    }
    /* map fms mode to px4 ctrl mode */
    heartbeat.custom_mode = get_custom_mode(fms_out);

    mavlink_msg_heartbeat_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &heartbeat);

    return true;
}

bool mavlink_msg_extended_sys_state_pack_func(mavlink_message_t* msg_t)
{
    mavlink_extended_sys_state_t ext_sys_state = { 0 };
    FMS_Out_Bus fms_out;

    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
        return false;
    }

    if (fms_out.status == VehicleStatus_Disarm || fms_out.status == VehicleStatus_Standby) {
        ext_sys_state.landed_state = MAV_LANDED_STATE_ON_GROUND;
    } else {
        if (fms_out.state == VehicleState_Takeoff) {
            ext_sys_state.landed_state = MAV_LANDED_STATE_TAKEOFF;
        } else if (fms_out.state == VehicleState_Land) {
            ext_sys_state.landed_state = MAV_LANDED_STATE_LANDING;
        } else {
            ext_sys_state.landed_state = MAV_LANDED_STATE_IN_AIR;
        }
    }

    mavlink_msg_extended_sys_state_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &ext_sys_state);

    return true;
}

bool mavlink_msg_sys_status_pack_func(mavlink_message_t* msg_t)
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

    mavlink_msg_sys_status_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &sys_status);

    return true;
}

bool mavlink_msg_system_time_pack_func(mavlink_message_t* msg_t)
{
    mavlink_system_time_t system_time;

    system_time.time_unix_usec = systime_now_us();
    system_time.time_boot_ms = systime_now_ms();

    mavlink_msg_system_time_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &system_time);

    return true;
}

bool mavlink_msg_attitude_pack_func(mavlink_message_t* msg_t)
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

    mavlink_msg_attitude_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &attitude);

    return true;
}

bool mavlink_msg_local_position_ned_pack_func(mavlink_message_t* msg_t)
{
    mavlink_local_position_ned_t local_position_ned;
    INS_Out_Bus ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    local_position_ned.time_boot_ms = systime_now_ms();
    local_position_ned.x = ins_out.x_R;
    local_position_ned.y = ins_out.y_R;
    local_position_ned.z = -ins_out.h_R;
    local_position_ned.vx = ins_out.vn;
    local_position_ned.vy = ins_out.ve;
    local_position_ned.vz = ins_out.vd;

    mavlink_msg_local_position_ned_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &local_position_ned);

    return true;
}

bool mavlink_msg_global_position_int_pack_func(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;
    mavlink_global_position_int_t global_position_int;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    global_position_int.time_boot_ms = systime_now_ms();
    global_position_int.lat = RAD2DEG(ins_out.lat) * 1e7;
    global_position_int.lon = RAD2DEG(ins_out.lon) * 1e7;
    global_position_int.alt = ins_out.alt * 1e3;
    global_position_int.relative_alt = ins_out.h_R * 1e3;
    global_position_int.vx = ins_out.vn * 10;
    global_position_int.vy = ins_out.ve * 10;
    global_position_int.vz = ins_out.vd * 10;
    global_position_int.hdg = RAD2DEG(ins_out.psi < 0 ? ins_out.psi + 2 * PI : ins_out.psi) * 100;

    mavlink_msg_global_position_int_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &global_position_int);

    return true;
}

bool mavlink_msg_vfr_hud_pack_func(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;
    float groundspeed;
    int16_t heading;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    groundspeed = sqrtf(ins_out.vn * ins_out.vn + ins_out.ve * ins_out.ve);
    heading = RAD2DEG(ins_out.psi < 0 ? ins_out.psi + 2 * PI : ins_out.psi);

    mavlink_msg_vfr_hud_pack(mavlink_system.sysid, mavlink_system.compid, msg_t, ins_out.airspeed, groundspeed, heading, 0, ins_out.alt, -ins_out.vd);

    return true;
}

bool mavlink_msg_altitude_pack_func(mavlink_message_t* msg_t)
{
    mavlink_altitude_t altitude;
    INS_Out_Bus ins_out;
    FMS_Out_Bus fms_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
        return false;
    }

    altitude.time_usec = systime_now_us();
    altitude.altitude_monotonic = 0.0f;
    altitude.altitude_amsl = ins_out.alt;
    altitude.altitude_local = ins_out.h_R;
    altitude.altitude_relative = ins_out.h_R - fms_out.home[2];
    altitude.altitude_terrain = ins_out.h_AGL;
    altitude.bottom_clearance = 0.0f;

    mavlink_msg_altitude_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &altitude);

    return true;
}

bool mavlink_msg_gps_raw_int_pack_func(mavlink_message_t* msg_t)
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

bool mavlink_msg_rc_channels_pack_func(mavlink_message_t* msg_t)
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
    mavlink_rc_channels.chancount = pilot_cmd_get_chan_num();
    mavlink_rc_channels.rssi = 255; /* unknown */
    memcpy(&mavlink_rc_channels.chan1_raw, &rc_channels, sizeof(rc_channels));

    mavlink_msg_rc_channels_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &mavlink_rc_channels);

    return true;
}

bool mavlink_msg_highres_imu_pack_func(mavlink_message_t* msg_t)
{
    mavlink_highres_imu_t highres_imu;
    imu_data_t imu_data;
    mag_data_t mag_data;
    baro_data_t baro_data;
    airspeed_data_t airspeed_data = { 0 };

    if (mcn_copy_from_hub(MCN_HUB(sensor_imu0), &imu_data) != FMT_EOK) {
        return false;
    }

    if (mcn_copy_from_hub(MCN_HUB(sensor_mag0), &mag_data) != FMT_EOK) {
        return false;
    }

    if (mcn_copy_from_hub(MCN_HUB(sensor_baro), &baro_data) != FMT_EOK) {
        return false;
    }

    /* there could be no airspeed data, so don't check return value. */
    mcn_copy_from_hub(MCN_HUB(sensor_airspeed), &airspeed_data);

    highres_imu.time_usec = systime_now_us();
    highres_imu.xacc = imu_data.acc_B_mDs2[0];
    highres_imu.yacc = imu_data.acc_B_mDs2[1];
    highres_imu.zacc = imu_data.acc_B_mDs2[2];
    highres_imu.xgyro = imu_data.gyr_B_radDs[0];
    highres_imu.ygyro = imu_data.gyr_B_radDs[1];
    highres_imu.zgyro = imu_data.gyr_B_radDs[2];
    highres_imu.xmag = mag_data.mag_B_gauss[0];
    highres_imu.ymag = mag_data.mag_B_gauss[1];
    highres_imu.zmag = mag_data.mag_B_gauss[2];
    highres_imu.abs_pressure = baro_data.pressure_pa * 1000;           /* Pa to mPa */
    highres_imu.diff_pressure = airspeed_data.diff_pressure_pa * 1000; /* Pa to mPa */
    highres_imu.pressure_alt = baro_data.altitude_m;
    highres_imu.temperature = baro_data.temperature_deg;

    mavlink_msg_highres_imu_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &highres_imu);

    return true;
}

bool mavlink_msg_distance_sensor_pack_func(mavlink_message_t* msg_t)
{
    mavlink_distance_sensor_t distance_sensor = { 0 };
    rf_data_t rf_data;

    if (mcn_copy_from_hub(MCN_HUB(sensor_rangefinder), &rf_data) != FMT_EOK) {
        return false;
    }

    distance_sensor.time_boot_ms = systime_now_ms();
    distance_sensor.current_distance = rf_data.distance_m > 0.0f ? rf_data.distance_m * 100 : 0;
    distance_sensor.signal_quality = rf_data.distance_m > 0.0f ? 100 : 0;

    mavlink_msg_distance_sensor_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &distance_sensor);

    return true;
}

bool mavlink_msg_gps_global_origin_pack_func(mavlink_message_t* msg_t)
{
    mavlink_gps_global_origin_t gps_global_origin = { 0 };
    INS_Out_Bus ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    gps_global_origin.time_usec = systime_now_us();
    gps_global_origin.latitude = RAD2DEG(ins_out.lat_0) * 1e7;
    gps_global_origin.longitude = RAD2DEG(ins_out.lon_0) * 1e7;
    gps_global_origin.altitude = ins_out.alt_0 * 1e3;

    mavlink_msg_gps_global_origin_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &gps_global_origin);

    return true;
}

bool mavlink_msg_home_position_pack_func(mavlink_message_t* msg_t)
{
    mavlink_home_position_t home_position = { 0 };
    INS_Out_Bus ins_out;
    FMS_Out_Bus fms_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
        return false;
    }

    home_position.time_usec = systime_now_us();
    home_position.x = fms_out.home[0];
    home_position.y = fms_out.home[1];
    home_position.z = -fms_out.home[2];
    home_position.latitude = ins_out.dx_dlat > 0.0 ? RAD2DEG(fms_out.home[0] / ins_out.dx_dlat + ins_out.lat_0) * 1e7 : 0;
    home_position.longitude = ins_out.dy_dlon > 0.0 ? RAD2DEG(fms_out.home[1] / ins_out.dy_dlon + ins_out.lon_0) * 1e7 : 0;
    home_position.altitude = (fms_out.home[2] + ins_out.alt_0) * 100;

    mavlink_msg_home_position_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &home_position);

    return true;
}

fmt_err_t mavlink_command_acknowledge(uint8_t chan, uint16_t command, uint8_t result)
{
    mavlink_system_t mav_sys = mavproxy_get_system();
    mavlink_command_ack_t command_ack = { 0 };
    mavlink_message_t msg;

    command_ack.command = command;
    command_ack.result = result;

    mavlink_msg_command_ack_encode(mav_sys.sysid, mav_sys.compid, &msg, &command_ack);

    return mavproxy_send_immediate_msg(chan, &msg, true);
}

fmt_err_t task_comm_init(void)
{
    /* init mavproxy */
    FMT_TRY(mavproxy_init());

    mavlink_system = mavproxy_get_system();

    /* init ground control station handler */
    FMT_TRY(gcs_handler_init());

    return FMT_EOK;
}

void task_comm_entry(void* parameter)
{
    /* execute mavproxy main loop */
    mavproxy_loop();
}

TASK_EXPORT __fmt_task_desc = {
    .name = "comm",
    .init = task_comm_init,
    .entry = task_comm_entry,
    .priority = COMM_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 8192,
    .param = NULL,
    .dependency = NULL
};