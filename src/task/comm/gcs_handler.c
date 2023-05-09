/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/px4_custom_mode.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/gcs_cmd.h"
#include "module/system/statistic.h"

#define TAG "GCS Handler"

MCN_DEFINE(mav_ext_state, sizeof(mavlink_fmt_external_state_t));

MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(ins_output);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(rc_channels);
MCN_DECLARE(bat0_status);
MCN_DECLARE(fms_output);

static mavlink_system_t mavlink_system;

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

static bool mavlink_msg_heartbeat_cb(mavlink_message_t* msg_t)
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

static bool mavlink_msg_extended_sys_state_cb(mavlink_message_t* msg_t)
{
    mavlink_extended_sys_state_t ext_sys_state = { .vtol_state = 0, .landed_state = MAV_LANDED_STATE_UNDEFINED };
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

    mavlink_msg_sys_status_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &sys_status);

    return true;
}

static bool mavlink_msg_system_time_cb(mavlink_message_t* msg_t)
{
    mavlink_system_time_t system_time;

    system_time.time_unix_usec = systime_now_us();
    system_time.time_boot_ms = systime_now_ms();

    mavlink_msg_system_time_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &system_time);

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

    mavlink_msg_attitude_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &attitude);

    return true;
}

static bool mavlink_msg_local_pos_cb(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    mavlink_msg_local_position_ned_pack(
        mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms(), ins_out.x_R, ins_out.y_R, -ins_out.h_R, ins_out.vn, ins_out.ve, ins_out.vd);

    return true;
}

static bool mavlink_msg_global_pos_cb(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;
    uint16_t hdg;

    if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
        return false;
    }

    hdg = RAD2DEG(ins_out.psi < 0 ? ins_out.psi + 2 * PI : ins_out.psi) * 100;

    mavlink_msg_global_position_int_pack(mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms(), RAD2DEG(ins_out.lat) * 1e7, RAD2DEG(ins_out.lon) * 1e7, ins_out.alt * 1e3, ins_out.h_R * 1e3, ins_out.vn * 10, ins_out.ve * 10, ins_out.vd * 10, hdg);

    return true;
}

static bool mavlink_msg_vfr_hud_cb(mavlink_message_t* msg_t)
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

    mavlink_msg_altitude_pack(mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms() * 1e3, baro_report.altitude_m, baro_report.altitude_m, ins_out.h_R, ins_out.h_R, ins_out.h_AGL, 0.0f);

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

static void acknowledge(uint16_t command, uint8_t result)
{
    mavlink_system_t mav_sys = mavproxy_get_system();
    mavlink_command_ack_t command_ack = { 0 };
    mavlink_message_t msg;

    command_ack.command = command;
    command_ack.result = result;

    mavlink_msg_command_ack_encode(mav_sys.sysid, mav_sys.compid, &msg, &command_ack);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
}

static void handle_mavlink_command(mavlink_command_long_t* command, mavlink_message_t* msg)
{
    switch (command->command) {
    case MAV_CMD_REQUEST_PROTOCOL_VERSION: {
        mavlink_system_t mav_sys = mavproxy_get_system();
        mavlink_protocol_version_t protocol_version = { 0 };

        acknowledge(command->command, MAV_RESULT_ACCEPTED);

#ifdef FMT_USING_MAVLINK_V2
        protocol_version.version = 200;
#else
        protocol_version.version = 100;
#endif
        protocol_version.min_version = 100;
        protocol_version.max_version = 200;

        mavlink_msg_protocol_version_encode(mav_sys.sysid, mav_sys.compid, msg, &protocol_version);
        mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, msg, true);
    } break;
    case MAV_CMD_REQUEST_AUTOPILOT_CAPABILITIES: {
        mavlink_system_t mav_sys = mavproxy_get_system();
        mavlink_autopilot_version_t autopilot_version = { 0 };

        acknowledge(command->command, MAV_RESULT_ACCEPTED);

        autopilot_version.capabilities = MAV_PROTOCOL_CAPABILITY_MISSION_FLOAT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MISSION_INT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_PARAM_FLOAT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_COMMAND_INT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_FTP;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_ATTITUDE_TARGET;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_POSITION_TARGET_LOCAL_NED;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_ACTUATOR_TARGET;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MAVLINK2;
        // autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MISSION_FENCE;
        // autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MISSION_RALLY;

        /* cheat QGC that we are using the right px4 version */
        autopilot_version.flight_sw_version = ((uint8_t)1 << 8 * 3) | ((uint8_t)10 << 8 * 2) | ((uint8_t)0 << 8 * 1);
        autopilot_version.middleware_sw_version = autopilot_version.flight_sw_version;

        mavlink_msg_autopilot_version_encode(mav_sys.sysid, mav_sys.compid, msg, &autopilot_version);
        mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, msg, true);
    } break;

    case MAV_CMD_PREFLIGHT_CALIBRATION:
        if (command->param1 == 1) { // calibration gyr
            mavproxy_cmd_set(MAVCMD_CALIBRATION_GYR, NULL);
        } else if (command->param2 == 1) { // calibration mag
            mavproxy_cmd_set(MAVCMD_CALIBRATION_MAG, NULL);
        } else if (command->param5 == 1) { // calibration acc
            mavproxy_cmd_set(MAVCMD_CALIBRATION_ACC, NULL);
        } else if (command->param5 == 2) { // calibration level
            mavproxy_cmd_set(MAVCMD_CALIBRATION_LEVEL, NULL);
        } else {
            /* all 0 command, cancel current process */
        }

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
        break;

    case MAV_CMD_COMPONENT_ARM_DISARM:
        if (command->param1 == 1.0f) {
            gcs_set_cmd(FMS_Cmd_PreArm, (float[7]) { 0 });
        } else if (command->param1 == 0.0f) {
            gcs_set_cmd(FMS_Cmd_Disarm, (float[7]) { 0 });
        }

        acknowledge(command->command, MAV_RESULT_ACCEPTED);

        break;

    case MAV_CMD_NAV_TAKEOFF: {
        gcs_set_cmd(FMS_Cmd_Takeoff, (float[7]) { 0 });

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_NAV_LAND: {
        gcs_set_cmd(FMS_Cmd_Land, (float[7]) { 0 });

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_REPOSITION: {
        /* When click pause button, GCS will send this command */
        gcs_set_cmd(FMS_Cmd_Pause, (float[7]) { 0 });

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_SET_HOME: {
        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    default:
        printf("unhandled command long:%d\n", command->command);
        break;
    }
}

static fmt_err_t handle_mavlink_message(mavlink_message_t* msg, mavlink_system_t this_system)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_SET_MODE: {
        if (this_system.sysid == mavlink_msg_set_mode_get_target_system(msg)) {
            mavlink_set_mode_t set_mode;
            mavlink_msg_set_mode_decode(msg, &set_mode);

            uint8_t base_mode = set_mode.base_mode;
            uint8_t custom_main_mode = (set_mode.custom_mode >> 16) & 0xFF;
            uint8_t custom_sub_mode = (set_mode.custom_mode >> 24) & 0xFF;

            if (base_mode & VEHICLE_MODE_FLAG_CUSTOM_MODE_ENABLED) {
                if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_AUTO) {
                    if (custom_sub_mode > 0) {
                        switch (custom_sub_mode) {
                        case PX4_CUSTOM_SUB_MODE_AUTO_RTL:
                            gcs_set_cmd(FMS_Cmd_Return, (float[7]) { 0 });
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF:
                            gcs_set_cmd(FMS_Cmd_Takeoff, (float[7]) { 0 });
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_LAND:
                            gcs_set_cmd(FMS_Cmd_Land, (float[7]) { 0 });
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_LOITER:
                            gcs_set_cmd(FMS_Cmd_Pause, (float[7]) { 0 });
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_MISSION:
                            gcs_set_mode(PilotMode_Mission);
                            break;
                        default:
                            mavlink_send_statustext(MAV_SEVERITY_INFO, "Unsupported auto mode: %d", custom_sub_mode);
                            break;
                        }
                    }
                } else if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_MANUAL) {
                    gcs_set_mode(PilotMode_Manual);
                } else if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_ALTCTL) {
                    gcs_set_mode(PilotMode_Altitude);
                } else if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_POSCTL) {
                    gcs_set_mode(PilotMode_Position);
                } else if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_ACRO) {
                    gcs_set_mode(PilotMode_Acro);
                } else if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_OFFBOARD) {
                    gcs_set_mode(PilotMode_Offboard);
                } else if (custom_main_mode == PX4_CUSTOM_MAIN_MODE_STABILIZED) {
                    gcs_set_mode(PilotMode_Stabilize);
                }
            }
        }
    }

    case MAVLINK_MSG_ID_PARAM_REQUEST_READ: {
        if (this_system.sysid == mavlink_msg_param_request_read_get_target_system(msg)) {
            mavlink_param_request_read_t request_read;
            mavlink_msg_param_request_read_decode(msg, &request_read);

            /* -1 to use the param ID field as identifier */
            if (request_read.param_index == -1) {
                param_t* param = param_get_by_name(request_read.param_id);

                if (param) {
                    mavlink_param_send(param);
                } else {
                    send_mavparam_by_name(request_read.param_id);
                }
            } else {
                uint16_t mavparam_num = get_mavparam_num();

                if (request_read.param_index < mavparam_num) {
                    send_mavparam_by_index(request_read.param_index);
                } else {
                    param_t* param = param_get_by_index(request_read.param_index - mavparam_num);
                    mavlink_param_send(param);
                }
            }
        }
    } break;

    case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: {
        if (this_system.sysid == mavlink_msg_param_request_list_get_target_system(msg)) {
            mavproxy_send_event(EVENT_SEND_ALL_PARAM);
        }
    } break;

    case MAVLINK_MSG_ID_PARAM_SET: {
        if (this_system.sysid == mavlink_msg_param_set_get_target_system(msg)) {
            mavlink_param_set_t param_set;
            mavlink_msg_param_set_decode(msg, &param_set);

            if (param_set.param_type != MAV_PARAM_TYPE_REAL32) {
                ulog_w(TAG, "Unsupported parameter type:%d\n", param_set.param_type);
                break;
            }

            if (mavlink_param_set(param_set.param_id, param_set.param_value) != FMT_EOK) {
                ulog_w(TAG, "Patameter set failed! Unknown parameter:%s\n", param_set.param_id);
                break;
            }
        }
    } break;

    case MAVLINK_MSG_ID_COMMAND_LONG: {
        if (this_system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_long_t command;
            mavlink_msg_command_long_decode(msg, &command);

            handle_mavlink_command(&command, msg);
        }
    } break;

    case MAVLINK_MSG_ID_SERIAL_CONTROL: {
        mavlink_serial_control_t serial_control;
        mavlink_msg_serial_control_decode(msg, &serial_control);

        /* handle received msg */
        mavlink_console_process_rx_msg(&serial_control);
    } break;

    case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: {
        if (this_system.sysid == mavlink_msg_file_transfer_protocol_get_target_system(msg)) {
            mavlink_file_transfer_protocol_t ftp_protocol_t;

            mavlink_msg_file_transfer_protocol_decode(msg, &ftp_protocol_t);

            if (ftp_process_request(ftp_protocol_t.payload, msg->sysid, msg->compid) == FMT_EOK) {

                ftp_protocol_t.target_system = msg->sysid;
                ftp_protocol_t.target_component = msg->compid;
                ftp_protocol_t.target_network = 0;

                mavlink_msg_file_transfer_protocol_encode(this_system.sysid, this_system.compid, msg, &ftp_protocol_t);

                if (mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, msg, 0) != FMT_EOK) {
                    console_printf("ftp msg send err\n");
                    return FMT_ERROR;
                }
            }
        }
    } break;

    case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
    case MAVLINK_MSG_ID_MISSION_COUNT:
    case MAVLINK_MSG_ID_MISSION_REQUEST_INT:
    case MAVLINK_MSG_ID_MISSION_ITEM_INT:
    case MAVLINK_MSG_ID_MISSION_CLEAR_ALL:
    case MAVLINK_MSG_ID_MISSION_ACK:
        handle_mission_message(msg);
        break;

#if defined(FMT_USING_HIL)
    case MAVLINK_MSG_ID_HIL_SENSOR: {
        mavlink_hil_sensor_t hil_sensor;
        imu_data_t imu_data;
        mag_data_t mag_data;
        baro_data_t baro_data;

        mavlink_msg_hil_sensor_decode(msg, &hil_sensor);

        /* publish hil sensor data */
        imu_data.acc_B_mDs2[0] = hil_sensor.xacc;
        imu_data.acc_B_mDs2[1] = hil_sensor.yacc;
        imu_data.acc_B_mDs2[2] = hil_sensor.zacc;
        imu_data.gyr_B_radDs[0] = hil_sensor.xgyro;
        imu_data.gyr_B_radDs[1] = hil_sensor.ygyro;
        imu_data.gyr_B_radDs[2] = hil_sensor.zgyro;
        imu_data.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_imu0), &imu_data);

        mag_data.mag_B_gauss[0] = hil_sensor.xmag;
        mag_data.mag_B_gauss[1] = hil_sensor.ymag;
        mag_data.mag_B_gauss[2] = hil_sensor.zmag;
        mag_data.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_mag0), &mag_data);

        baro_data.pressure_pa = hil_sensor.abs_pressure * 1e-3;
        baro_data.temperature_deg = hil_sensor.temperature;
        baro_data.altitude_m = hil_sensor.pressure_alt;
        baro_data.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_baro), &baro_data);
    } break;

    case MAVLINK_MSG_ID_HIL_GPS: {
        mavlink_hil_gps_t hil_gps;
        gps_data_t gps_data;

        mavlink_msg_hil_gps_decode(msg, &hil_gps);

        gps_data.lat = hil_gps.lat;
        gps_data.lon = hil_gps.lon;
        gps_data.height = hil_gps.alt;
        gps_data.velN = (float)hil_gps.vn * 0.01f;
        gps_data.velE = (float)hil_gps.ve * 0.01f;
        gps_data.velD = (float)hil_gps.vd * 0.01f;
        gps_data.hAcc = (float)hil_gps.eph * 0.01f;
        gps_data.vAcc = (float)hil_gps.epv * 0.01f;
        gps_data.sAcc = 0; // speed accurancy unknown
        gps_data.numSV = hil_gps.satellites_visible;
        gps_data.fixType = hil_gps.fix_type;
        gps_data.timestamp_ms = systime_now_ms();

        mcn_publish(MCN_HUB(sensor_gps), &gps_data);
    } break;
#endif

    case MAVLINK_MSG_ID_FMT_EXTERNAL_STATE: {
        mavlink_fmt_external_state_t ext_state;

        mavlink_msg_fmt_external_state_decode(msg, &ext_state);

        ext_state.timestamp = systime_now_ms();
        /* publish external state */
        mcn_publish(MCN_HUB(mav_ext_state), &ext_state);
    } break;

    default: {
        // printf("unknown mavlink msg:%d\n", msg->msgid);
        return FMT_ENOTHANDLE;
    } break;
    }

    return FMT_EOK;
}

fmt_err_t gcs_handler_init(void)
{
    mavlink_system = mavproxy_get_system();

    mcn_advertise(MCN_HUB(mav_ext_state), NULL);

    /* register periodical mavlink msg */
    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_HEARTBEAT, 1000, mavlink_msg_heartbeat_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_SYS_STATUS, 1000, mavlink_msg_sys_status_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_SYSTEM_TIME, 1000, mavlink_msg_system_time_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, 1000, mavlink_msg_extended_sys_state_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_ATTITUDE, 100, mavlink_msg_attitude_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_LOCAL_POSITION_NED, 100, mavlink_msg_local_pos_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_GLOBAL_POSITION_INT, 100, mavlink_msg_global_pos_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_VFR_HUD, 200, mavlink_msg_vfr_hud_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_ALTITUDE, 100, mavlink_msg_altitude_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_GPS_RAW_INT, 100, mavlink_msg_gps_raw_int_cb, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_RC_CHANNELS, 100, mavlink_msg_rc_channels_cb, true));

    /* register gcs mavlink handler */
    FMT_TRY(mavproxy_monitor_register_handler(MAVPROXY_GCS_CHAN, handle_mavlink_message));

    return FMT_EOK;
}
