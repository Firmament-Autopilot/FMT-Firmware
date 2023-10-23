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
#include "Plant.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/ftp/ftp_manager.h"
#include "module/math/quaternion.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/px4_custom_mode.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/task_manager/task_manager.h"

#ifdef BIT
    #undef BIT
#endif

#define BIT(u, n) (u & (1 << n))

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
MCN_DECLARE(bat_status);
MCN_DECLARE(fms_output);
MCN_DECLARE(auto_cmd);
MCN_DECLARE(bat_status);
#ifdef FMT_USING_SIH
MCN_DECLARE(plant_states);
#endif

static mavlink_system_t mavlink_system;

fmt_err_t mavgcs_init(void);
fmt_err_t mavobc_init(void);

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
    mavlink_heartbeat_t heartbeat = { 0 };
    FMS_Out_Bus         fms_out;

    heartbeat.type          = MAV_TYPE_QUADROTOR;
    heartbeat.autopilot     = MAV_AUTOPILOT_PX4;
    heartbeat.base_mode     = MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;
    heartbeat.custom_mode   = 0;
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
    FMS_Out_Bus                  fms_out;

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
    mavlink_sys_status_t  sys_status = { 0 };
    INS_Out_Bus           ins_out;
    struct battery_status bat_status;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    if (mcn_copy_from_hub(MCN_HUB(bat_status), &bat_status) != FMT_EOK) {
        return false;
    }

    if (BIT(ins_out.status, 0)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_3D_GYRO | MAV_SYS_STATUS_SENSOR_3D_ACCEL;
    }

    if (BIT(ins_out.status, 1)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_3D_GYRO2 | MAV_SYS_STATUS_SENSOR_3D_ACCEL2;
    }

    if (BIT(ins_out.status, 2)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_3D_MAG;
    }

    if (BIT(ins_out.status, 3)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_ABSOLUTE_PRESSURE;
    }

    if (BIT(ins_out.status, 4)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_GPS;
    }

    if (BIT(ins_out.status, 5)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_LASER_POSITION;
    }

    if (BIT(ins_out.status, 6)) {
        sys_status.onboard_control_sensors_present |= MAV_SYS_STATUS_SENSOR_OPTICAL_FLOW;
    }

    if (BIT(ins_out.flag, 1)) {
        sys_status.onboard_control_sensors_enabled |= MAV_SYS_STATUS_SENSOR_ANGULAR_RATE_CONTROL | MAV_SYS_STATUS_SENSOR_ATTITUDE_STABILIZATION;
    }

    if (BIT(ins_out.flag, 2)) {
        sys_status.onboard_control_sensors_enabled |= MAV_SYS_STATUS_SENSOR_YAW_POSITION;
    }

    if (BIT(ins_out.flag, 5)) {
        sys_status.onboard_control_sensors_enabled |= MAV_SYS_STATUS_SENSOR_XY_POSITION_CONTROL;
    }

    if (BIT(ins_out.flag, 6)) {
        sys_status.onboard_control_sensors_enabled |= MAV_SYS_STATUS_SENSOR_Z_ALTITUDE_CONTROL;
    }

    if (BIT(ins_out.flag, 7)) {
        sys_status.onboard_control_sensors_enabled |= MAV_SYS_STATUS_TERRAIN;
    }

    sys_status.onboard_control_sensors_health = sys_status.onboard_control_sensors_enabled;
    sys_status.load                           = (uint16_t)(get_cpu_usage() * 1e3);
    sys_status.voltage_battery                = bat_status.battery_voltage;
    sys_status.current_battery                = bat_status.battery_current;
    sys_status.battery_remaining              = bat_status.battery_remaining;

    mavlink_msg_sys_status_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &sys_status);

    return true;
}

bool mavlink_msg_system_time_pack_func(mavlink_message_t* msg_t)
{
    mavlink_system_time_t system_time = { 0 };

    system_time.time_unix_usec = systime_now_us();
    system_time.time_boot_ms   = systime_now_ms();

    mavlink_msg_system_time_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &system_time);

    return true;
}

bool mavlink_msg_attitude_pack_func(mavlink_message_t* msg_t)
{
    mavlink_attitude_t attitude = { 0 };
    INS_Out_Bus        ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    attitude.roll       = ins_out.phi;
    attitude.pitch      = ins_out.theta;
    attitude.yaw        = ins_out.psi;
    attitude.rollspeed  = ins_out.p;
    attitude.pitchspeed = ins_out.q;
    attitude.yawspeed   = ins_out.r;

    mavlink_msg_attitude_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &attitude);

    return true;
}

bool mavlink_msg_attitude_quaternion_pack_func(mavlink_message_t* msg_t)
{
    mavlink_attitude_quaternion_t att_quat = { 0 };
    INS_Out_Bus                   ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    att_quat.time_boot_ms = systime_now_us();
    att_quat.q1           = ins_out.quat[0];
    att_quat.q2           = ins_out.quat[1];
    att_quat.q3           = ins_out.quat[2];
    att_quat.q4           = ins_out.quat[3];
    att_quat.rollspeed    = ins_out.p;
    att_quat.pitchspeed   = ins_out.q;
    att_quat.yawspeed     = ins_out.r;

    mavlink_msg_attitude_quaternion_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &att_quat);

    return true;
}

bool mavlink_msg_local_position_ned_pack_func(mavlink_message_t* msg_t)
{
    mavlink_local_position_ned_t local_position_ned = { 0 };
    INS_Out_Bus                  ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    local_position_ned.time_boot_ms = systime_now_ms();
    local_position_ned.x            = ins_out.x_R;
    local_position_ned.y            = ins_out.y_R;
    local_position_ned.z            = -ins_out.h_R;
    local_position_ned.vx           = ins_out.vn;
    local_position_ned.vy           = ins_out.ve;
    local_position_ned.vz           = ins_out.vd;

    mavlink_msg_local_position_ned_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &local_position_ned);

    return true;
}

bool mavlink_msg_global_position_int_pack_func(mavlink_message_t* msg_t)
{
    mavlink_global_position_int_t global_position_int = { 0 };
    INS_Out_Bus                   ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    global_position_int.time_boot_ms = systime_now_ms();
    global_position_int.lat          = RAD2DEG(ins_out.lat) * 1e7;
    global_position_int.lon          = RAD2DEG(ins_out.lon) * 1e7;
    global_position_int.alt          = ins_out.alt * 1e3;
    global_position_int.relative_alt = ins_out.h_R * 1e3;
    global_position_int.vx           = ins_out.vn * 10;
    global_position_int.vy           = ins_out.ve * 10;
    global_position_int.vz           = ins_out.vd * 10;
    global_position_int.hdg          = RAD2DEG(ins_out.psi < 0 ? ins_out.psi + 2 * PI : ins_out.psi) * 100;

    mavlink_msg_global_position_int_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &global_position_int);

    return true;
}

bool mavlink_msg_vfr_hud_pack_func(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;
    float       groundspeed;
    int16_t     heading;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    groundspeed = sqrtf(ins_out.vn * ins_out.vn + ins_out.ve * ins_out.ve);
    heading     = RAD2DEG(ins_out.psi < 0 ? ins_out.psi + 2 * PI : ins_out.psi);

    mavlink_msg_vfr_hud_pack(mavlink_system.sysid, mavlink_system.compid, msg_t, ins_out.airspeed, groundspeed, heading, 0, ins_out.alt, -ins_out.vd);

    return true;
}

bool mavlink_msg_altitude_pack_func(mavlink_message_t* msg_t)
{
    mavlink_altitude_t altitude = { 0 };
    INS_Out_Bus        ins_out;
    FMS_Out_Bus        fms_out;
    fmt_err_t          fms_res;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    fms_res = mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out);

    altitude.time_usec          = systime_now_us();
    altitude.altitude_monotonic = 0.0f;
    altitude.altitude_amsl      = ins_out.alt;
    altitude.altitude_local     = ins_out.h_R;
    altitude.altitude_relative  = fms_res == FMT_EOK ? ins_out.h_R - fms_out.home[2] : 0.0f;
    altitude.altitude_terrain   = ins_out.h_AGL;
    altitude.bottom_clearance   = 0.0f;

    mavlink_msg_altitude_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &altitude);

    return true;
}

bool mavlink_msg_gps_raw_int_pack_func(mavlink_message_t* msg_t)
{
    mavlink_gps_raw_int_t gps_raw_int = { 0 };
    gps_data_t            gps_report;

    if (mcn_copy_from_hub(MCN_HUB(sensor_gps), &gps_report) != FMT_EOK) {
        return false;
    }

    gps_raw_int.time_usec          = systime_now_us();
    gps_raw_int.lat                = gps_report.lat;
    gps_raw_int.lon                = gps_report.lon;
    gps_raw_int.alt                = gps_report.height;
    gps_raw_int.eph                = gps_report.hAcc * 1e2;
    gps_raw_int.epv                = gps_report.vAcc * 1e2;
    gps_raw_int.vel                = gps_report.vel * 1e2;
    gps_raw_int.cog                = RAD2DEG(gps_report.cog + PI) * 1e2;
    gps_raw_int.fix_type           = gps_report.fixType;
    gps_raw_int.satellites_visible = gps_report.numSV;
    gps_raw_int.alt_ellipsoid      = gps_report.height;
    gps_raw_int.h_acc              = gps_report.hAcc * 1e3;
    gps_raw_int.v_acc              = gps_report.vAcc * 1e3;
    gps_raw_int.vel_acc            = gps_report.sAcc * 1e3;
    gps_raw_int.hdg_acc            = 0;
    gps_raw_int.yaw                = 0;

    mavlink_msg_gps_raw_int_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &gps_raw_int);

    return true;
}

bool mavlink_msg_rc_channels_pack_func(mavlink_message_t* msg_t)
{
    mavlink_rc_channels_t mavlink_rc_channels = { 0 };
    int16_t               rc_channels[16];
    McnHub*               hub = MCN_HUB(rc_channels);

    if (!hub->published) {
        return false;
    }

    if (mcn_copy_from_hub(hub, &rc_channels) != FMT_EOK) {
        return false;
    }

    mavlink_rc_channels.time_boot_ms = systime_now_ms();
    mavlink_rc_channels.chancount    = pilot_cmd_get_chan_num();
    mavlink_rc_channels.rssi         = 255; /* unknown */
    memcpy(&mavlink_rc_channels.chan1_raw, &rc_channels, sizeof(rc_channels));

    mavlink_msg_rc_channels_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &mavlink_rc_channels);

    return true;
}

bool mavlink_msg_highres_imu_pack_func(mavlink_message_t* msg_t)
{
    mavlink_highres_imu_t highres_imu   = { 0 };
    imu_data_t            imu_data      = { 0 };
    mag_data_t            mag_data      = { 0 };
    baro_data_t           baro_data     = { 0 };
    airspeed_data_t       airspeed_data = { 0 };
    fmt_err_t             imu_res, mag_res, baro_res, airspeed_res;

    imu_res      = mcn_copy_from_hub(MCN_HUB(sensor_imu0), &imu_data);
    mag_res      = mcn_copy_from_hub(MCN_HUB(sensor_mag0), &mag_data);
    baro_res     = mcn_copy_from_hub(MCN_HUB(sensor_baro), &baro_data);
    airspeed_res = mcn_copy_from_hub(MCN_HUB(sensor_airspeed), &airspeed_data);

    if (imu_res != FMT_EOK
        && mag_res != FMT_EOK
        && baro_res != FMT_EOK
        && airspeed_res != FMT_EOK) {
        return false;
    }

    highres_imu.time_usec     = systime_now_us();
    highres_imu.xacc          = imu_data.acc_B_mDs2[0];
    highres_imu.yacc          = imu_data.acc_B_mDs2[1];
    highres_imu.zacc          = imu_data.acc_B_mDs2[2];
    highres_imu.xgyro         = imu_data.gyr_B_radDs[0];
    highres_imu.ygyro         = imu_data.gyr_B_radDs[1];
    highres_imu.zgyro         = imu_data.gyr_B_radDs[2];
    highres_imu.xmag          = mag_data.mag_B_gauss[0];
    highres_imu.ymag          = mag_data.mag_B_gauss[1];
    highres_imu.zmag          = mag_data.mag_B_gauss[2];
    highres_imu.abs_pressure  = baro_data.pressure_pa * 1000;          /* Pa to mPa */
    highres_imu.diff_pressure = airspeed_data.diff_pressure_pa * 1000; /* Pa to mPa */
    highres_imu.pressure_alt  = baro_data.altitude_m;
    highres_imu.temperature   = baro_data.temperature_deg;

    mavlink_msg_highres_imu_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &highres_imu);

    return true;
}

bool mavlink_msg_distance_sensor_pack_func(mavlink_message_t* msg_t)
{
    mavlink_distance_sensor_t distance_sensor = { 0 };
    rf_data_t                 rf_data;

    if (mcn_copy_from_hub(MCN_HUB(sensor_rangefinder), &rf_data) != FMT_EOK) {
        return false;
    }

    distance_sensor.time_boot_ms     = systime_now_ms();
    distance_sensor.current_distance = rf_data.distance_m > 0.0f ? rf_data.distance_m * 100 : 0;
    distance_sensor.signal_quality   = rf_data.distance_m > 0.0f ? 100 : 0;
    distance_sensor.orientation      = ROTATION_PITCH_270;
    distance_sensor.quaternion[0]    = 1.0f;

    mavlink_msg_distance_sensor_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &distance_sensor);

    return true;
}

bool mavlink_msg_gps_global_origin_pack_func(mavlink_message_t* msg_t)
{
    mavlink_gps_global_origin_t gps_global_origin = { 0 };
    INS_Out_Bus                 ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    gps_global_origin.time_usec = systime_now_us();
    gps_global_origin.latitude  = RAD2DEG(ins_out.lat_0) * 1e7;
    gps_global_origin.longitude = RAD2DEG(ins_out.lon_0) * 1e7;
    gps_global_origin.altitude  = ins_out.alt_0 * 1e3;

    mavlink_msg_gps_global_origin_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &gps_global_origin);

    return true;
}

bool mavlink_msg_home_position_pack_func(mavlink_message_t* msg_t)
{
    mavlink_home_position_t home_position = { 0 };
    INS_Out_Bus             ins_out       = { 0 };
    FMS_Out_Bus             fms_out       = { 0 };
    fmt_err_t               ins_res, fms_res;

    ins_res = mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out);
    fms_res = mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out);

    if (ins_res != FMT_EOK && fms_res != FMT_EOK) {
        return false;
    }

    home_position.time_usec = systime_now_us();
    home_position.x         = fms_out.home[0];
    home_position.y         = fms_out.home[1];
    home_position.z         = -fms_out.home[2];
    home_position.latitude  = ins_out.dx_dlat > 0.0 ? RAD2DEG(fms_out.home[0] / ins_out.dx_dlat + ins_out.lat_0) * 1e7 : 0;
    home_position.longitude = ins_out.dy_dlon > 0.0 ? RAD2DEG(fms_out.home[1] / ins_out.dy_dlon + ins_out.lon_0) * 1e7 : 0;
    home_position.altitude  = (fms_out.home[2] + ins_out.alt_0) * 100;

    mavlink_msg_home_position_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &home_position);

    return true;
}

bool mavlink_msg_attitude_target_pack_func(mavlink_message_t* msg_t)
{
    mavlink_attitude_target_t att_target = { 0 };
    Auto_Cmd_Bus              auto_cmd;

    if (mcn_copy_from_hub(MCN_HUB(auto_cmd), &auto_cmd) != FMT_EOK) {
        return false;
    }

    att_target.time_boot_ms = systime_now_ms();

    if ((auto_cmd.cmd_mask & PHI_CMD_VALID) && (auto_cmd.cmd_mask & THETA_CMD_VALID) && (auto_cmd.cmd_mask & PSI_CMD_VALID)) {
        Euler euler;

        euler.roll  = auto_cmd.phi_cmd;
        euler.pitch = auto_cmd.phi_cmd;
        euler.yaw   = auto_cmd.psi_cmd;
        quaternion_fromEuler(euler, (quaternion*)att_target.q);
    } else {
        att_target.type_mask |= 128;
    }

    if (auto_cmd.cmd_mask & P_CMD_VALID) {
        att_target.body_roll_rate = auto_cmd.p_cmd;
    } else {
        att_target.type_mask |= 1;
    }

    if (auto_cmd.cmd_mask & Q_CMD_VALID) {
        att_target.body_pitch_rate = auto_cmd.q_cmd;
    } else {
        att_target.type_mask |= 2;
    }

    if (auto_cmd.cmd_mask & R_CMD_VALID) {
        att_target.body_yaw_rate = auto_cmd.r_cmd;
    } else {
        att_target.type_mask |= 3;
    }

    if (auto_cmd.cmd_mask & THROTTLE_CMD_VALID) {
        att_target.thrust = (float)(auto_cmd.throttle_cmd - 1000) / 1000.0f;
    } else {
        att_target.type_mask |= 64;
    }

    mavlink_msg_attitude_target_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &att_target);

    return true;
}

bool mavlink_msg_scaled_imu_pack_func(mavlink_message_t* msg_t)
{
    mavlink_scaled_imu_t scaled_imu = { 0 };
    imu_data_t           imu_data   = { 0 };
    mag_data_t           mag_data   = { 0 };
    fmt_err_t            imu_res, mag_res;

    imu_res = mcn_copy_from_hub(MCN_HUB(sensor_imu0), &imu_data);
    mag_res = mcn_copy_from_hub(MCN_HUB(sensor_mag0), &mag_data);

    if (imu_res != FMT_EOK && mag_res != FMT_EOK) {
        return false;
    }

    scaled_imu.time_boot_ms = systime_now_ms();
    scaled_imu.xacc         = imu_data.acc_B_mDs2[0] * 1000 / 9.806;
    scaled_imu.yacc         = imu_data.acc_B_mDs2[1] * 1000 / 9.806;
    scaled_imu.zacc         = imu_data.acc_B_mDs2[2] * 1000 / 9.806;
    scaled_imu.xgyro        = imu_data.gyr_B_radDs[0] * 1000;
    scaled_imu.ygyro        = imu_data.gyr_B_radDs[1] * 1000;
    scaled_imu.zgyro        = imu_data.gyr_B_radDs[2] * 1000;
    scaled_imu.xmag         = mag_data.mag_B_gauss[0] * 1000;
    scaled_imu.ymag         = mag_data.mag_B_gauss[1] * 1000;
    scaled_imu.zmag         = mag_data.mag_B_gauss[2] * 1000;

    mavlink_msg_scaled_imu_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &scaled_imu);

    return true;
}

bool mavlink_msg_position_target_local_pack_func(mavlink_message_t* msg_t)
{
    mavlink_position_target_local_ned_t pos_target_local = { 0 };
    Auto_Cmd_Bus                        auto_cmd;

    if (mcn_copy_from_hub(MCN_HUB(auto_cmd), &auto_cmd) != FMT_EOK) {
        return false;
    }

    pos_target_local.time_boot_ms = systime_now_ms();

    if (auto_cmd.cmd_mask & X_CMD_VALID) {
        pos_target_local.x = auto_cmd.x_cmd;
    } else {
        pos_target_local.type_mask |= 1;
    }

    if (auto_cmd.cmd_mask & Y_CMD_VALID) {
        pos_target_local.y = auto_cmd.y_cmd;
    } else {
        pos_target_local.type_mask |= 2;
    }

    if (auto_cmd.cmd_mask & Z_CMD_VALID) {
        pos_target_local.z = auto_cmd.z_cmd;
    } else {
        pos_target_local.type_mask |= 4;
    }

    if (auto_cmd.cmd_mask & U_CMD_VALID) {
        pos_target_local.vx = auto_cmd.u_cmd;
    } else {
        pos_target_local.type_mask |= 8;
    }

    if (auto_cmd.cmd_mask & V_CMD_VALID) {
        pos_target_local.vy = auto_cmd.v_cmd;
    } else {
        pos_target_local.type_mask |= 16;
    }

    if (auto_cmd.cmd_mask & W_CMD_VALID) {
        pos_target_local.vz = auto_cmd.w_cmd;
    } else {
        pos_target_local.type_mask |= 32;
    }

    if (auto_cmd.cmd_mask & AX_CMD_VALID) {
        pos_target_local.afx = auto_cmd.ax_cmd;
    } else {
        pos_target_local.type_mask |= 64;
    }

    if (auto_cmd.cmd_mask & AY_CMD_VALID) {
        pos_target_local.afy = auto_cmd.ay_cmd;
    } else {
        pos_target_local.type_mask |= 128;
    }

    if (auto_cmd.cmd_mask & AZ_CMD_VALID) {
        pos_target_local.afz = auto_cmd.az_cmd;
    } else {
        pos_target_local.type_mask |= 256;
    }

    if (auto_cmd.cmd_mask & PSI_CMD_VALID) {
        pos_target_local.yaw = auto_cmd.psi_cmd;
    } else {
        pos_target_local.type_mask |= 1024;
    }

    if (auto_cmd.cmd_mask & PSI_RATE_CMD_VALID) {
        pos_target_local.yaw_rate = auto_cmd.psi_rate_cmd;
    } else {
        pos_target_local.type_mask |= 2048;
    }

    if (auto_cmd.frame == FRAME_GLOBAL_NED) {
        pos_target_local.coordinate_frame = MAV_FRAME_LOCAL_NED;
    } else if (auto_cmd.frame == FRAME_LOCAL_FRD) {
        pos_target_local.coordinate_frame = MAV_FRAME_LOCAL_FRD;
    } else if (auto_cmd.frame == FRAME_BODY_FRD) {
        pos_target_local.coordinate_frame = MAV_FRAME_BODY_FRD;
    }

    mavlink_msg_position_target_local_ned_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &pos_target_local);

    return true;
}

bool mavlink_msg_hil_state_pack_func(mavlink_message_t* msg_t)
{
    mavlink_hil_state_t hil_state = { 0 };

#if defined(FMT_USING_SIH)
    Plant_States_Bus plant_states;

    if (mcn_copy_from_hub(MCN_HUB(plant_states), &plant_states) != FMT_EOK) {
        return false;
    }

    hil_state.time_usec  = systime_now_us();
    hil_state.roll       = plant_states.phi;
    hil_state.pitch      = plant_states.theta;
    hil_state.yaw        = plant_states.psi;
    hil_state.rollspeed  = plant_states.rot_x_B;
    hil_state.pitchspeed = plant_states.rot_y_B;
    hil_state.yawspeed   = plant_states.rot_z_B;
    hil_state.xacc       = plant_states.acc_x_O / 9.80665f * 1000;
    hil_state.yacc       = plant_states.acc_y_O / 9.80665f * 1000;
    hil_state.zacc       = plant_states.acc_z_O / 9.80665f * 1000;
    hil_state.vx         = plant_states.vel_x_O * 100;
    hil_state.vy         = plant_states.vel_y_O * 100;
    hil_state.vz         = plant_states.vel_z_O * 100;
    /* we don't send LLA, and send xyh in mm instead */
    hil_state.lat = plant_states.x_R * 1000;
    hil_state.lon = plant_states.y_R * 1000;
    hil_state.alt = plant_states.h_R * 1000;
#elif defined(FMT_USING_HIL)

#endif

    mavlink_msg_hil_state_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &hil_state);

    return true;
}

fmt_err_t mavlink_command_acknowledge(uint8_t chan, uint16_t command, uint8_t result)
{
    mavlink_system_t      mav_sys     = mavproxy_get_system();
    mavlink_command_ack_t command_ack = { 0 };
    mavlink_message_t     msg;

    command_ack.command = command;
    command_ack.result  = result;

    mavlink_msg_command_ack_encode(mav_sys.sysid, mav_sys.compid, &msg, &command_ack);

    return mavproxy_send_immediate_msg(chan, &msg, true);
}

static fmt_err_t task_mavgcs_init(void)
{
    /* init mavproxy */
    FMT_TRY(mavproxy_init());

    mavlink_system = mavproxy_get_system();

    /* init ground control station handler */
    FMT_TRY(mavgcs_init());

    return FMT_EOK;
}

static void task_mavgcs_entry(void* parameter)
{
    /* execute mavproxy main loop */
    mavproxy_channel_loop(MAVPROXY_GCS_CHAN);
}

static fmt_err_t task_mavobc_init(void)
{
    /* init onboard computer handler */
    FMT_TRY(mavobc_init());

    return FMT_EOK;
}

static void task_mavobc_entry(void* parameter)
{
    /* execute mavproxy main loop */
    mavproxy_channel_loop(MAVPROXY_OBC_CHAN);
}

TASK_EXPORT __fmt_task1_desc = {
    .name       = "mavgcs",
    .init       = task_mavgcs_init,
    .entry      = task_mavgcs_entry,
    .priority   = MAVGCS_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 8192,
    .param      = NULL,
    .dependency = NULL
};

TASK_EXPORT __fmt_task2_desc = {
    .name       = "mavobc",
    .init       = task_mavobc_init,
    .entry      = task_mavobc_entry,
    .priority   = MAVOBC_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 4096,
    .param      = NULL,
    .dependency = (char*[]) { "mavgcs", NULL }
};
