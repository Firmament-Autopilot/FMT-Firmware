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
#include "INS.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/px4_custom_mode.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/pilot_cmd.h"
#include "msh.h"
#include "task_comm.h"

#undef LOG_TAG
#define LOG_TAG "MAVOBC"

MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);
MCN_DECLARE(rc_channels);
MCN_DECLARE(auto_cmd);
MCN_DECLARE(external_pos);
MCN_DECLARE(mission_data);

typedef struct
{
    uint8_t msgid;
    msg_pack_cb_t msg_pack_cb;
} msg_pack_cb_table;

static msg_pack_cb_table mav_msg_cb_table[] = {
    { MAVLINK_MSG_ID_HEARTBEAT, mavlink_msg_heartbeat_pack_func },
    { MAVLINK_MSG_ID_SYS_STATUS, mavlink_msg_sys_status_pack_func },
    { MAVLINK_MSG_ID_SYSTEM_TIME, mavlink_msg_system_time_pack_func },
    { MAVLINK_MSG_ID_GPS_RAW_INT, mavlink_msg_gps_raw_int_pack_func },
    { MAVLINK_MSG_ID_SCALED_IMU, mavlink_msg_scaled_imu_pack_func },
    { MAVLINK_MSG_ID_ATTITUDE, mavlink_msg_attitude_pack_func },
    { MAVLINK_MSG_ID_ATTITUDE_QUATERNION, mavlink_msg_attitude_quaternion_pack_func },
    { MAVLINK_MSG_ID_LOCAL_POSITION_NED, mavlink_msg_local_position_ned_pack_func },
    { MAVLINK_MSG_ID_GLOBAL_POSITION_INT, mavlink_msg_global_position_int_pack_func },
    { MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN, mavlink_msg_gps_global_origin_pack_func },
    { MAVLINK_MSG_ID_RC_CHANNELS, mavlink_msg_rc_channels_pack_func },
    { MAVLINK_MSG_ID_ATTITUDE_TARGET, mavlink_msg_attitude_target_pack_func },
    { MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED, mavlink_msg_position_target_local_pack_func },
    { MAVLINK_MSG_ID_HIGHRES_IMU, mavlink_msg_highres_imu_pack_func },
    { MAVLINK_MSG_ID_DISTANCE_SENSOR, mavlink_msg_distance_sensor_pack_func },
    { MAVLINK_MSG_ID_ALTITUDE, mavlink_msg_altitude_pack_func },
    { MAVLINK_MSG_ID_HOME_POSITION, mavlink_msg_home_position_pack_func },
    { MAVLINK_MSG_ID_EXTENDED_SYS_STATE, mavlink_msg_extended_sys_state_pack_func },
};

static void handle_mavlink_command(mavlink_command_long_t* command, mavlink_message_t* msg)
{
    mavlink_system_t mav_sys = mavproxy_get_system();

    switch (command->command) {
    case MAV_CMD_REQUEST_PROTOCOL_VERSION: {
        mavlink_protocol_version_t protocol_version = { 0 };

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

#ifdef FMT_USING_MAVLINK_V2
        protocol_version.version = 200;
#else
        protocol_version.version = 100;
#endif
        protocol_version.min_version = 100;
        protocol_version.max_version = 200;

        mavlink_msg_protocol_version_encode(mav_sys.sysid, mav_sys.compid, msg, &protocol_version);
        mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
    } break;

    case MAV_CMD_PREFLIGHT_REBOOT_SHUTDOWN: {
        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

        if (command->param1 == 1) {
            msh_exec("reboot", 6);
        }
    } break;

    case MAV_CMD_COMPONENT_ARM_DISARM:
        if (command->param1 == 1.0f) {
            gcs_set_cmd(FMS_Cmd_PreArm, (float[7]) { 0 });
        } else if (command->param1 == 0.0f) {
            gcs_set_cmd(FMS_Cmd_Disarm, (float[7]) { 0 });
        }

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

        break;

    case MAV_CMD_NAV_TAKEOFF: {
        gcs_set_cmd(FMS_Cmd_Takeoff, (float[7]) { 0 });

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_NAV_LAND: {
        gcs_set_cmd(FMS_Cmd_Land, (float[7]) { 0 });

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_REPOSITION: {
        /* When click pause button, GCS will send this command */
        gcs_set_cmd(FMS_Cmd_Pause, (float[7]) { 0 });

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_GET_HOME_POSITION: {
        mavlink_home_position_t home_position = { 0 };
        INS_Out_Bus ins_out;
        FMS_Out_Bus fms_out;

        if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
            break;
        }

        if (mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
            break;
        }

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

        home_position.time_usec = systime_now_us();
        home_position.x = fms_out.home[0];
        home_position.y = fms_out.home[1];
        home_position.z = -fms_out.home[2];
        home_position.latitude = ins_out.dx_dlat > 0.0 ? RAD2DEG(fms_out.home[0] / ins_out.dx_dlat + ins_out.lat_0) * 1e7 : 0;
        home_position.longitude = ins_out.dy_dlon > 0.0 ? RAD2DEG(fms_out.home[1] / ins_out.dy_dlon + ins_out.lon_0) * 1e7 : 0;
        home_position.altitude = (fms_out.home[2] + ins_out.alt_0) * 100;

        mavlink_msg_home_position_encode(mav_sys.sysid, mav_sys.compid, msg, &home_position);
        mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, false);
    } break;

    case MAV_CMD_REQUEST_AUTOPILOT_CAPABILITIES: {
        mavlink_autopilot_version_t autopilot_version = { 0 };

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

        autopilot_version.capabilities = MAV_PROTOCOL_CAPABILITY_MISSION_FLOAT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MISSION_INT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_PARAM_FLOAT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_COMMAND_INT;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_FTP;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_ATTITUDE_TARGET;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_POSITION_TARGET_LOCAL_NED;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_ACTUATOR_TARGET;
        autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MAVLINK2;

        /* cheat OBC that we are using the right px4 version */
        autopilot_version.flight_sw_version = ((uint8_t)1 << 8 * 3) | ((uint8_t)10 << 8 * 2) | ((uint8_t)0 << 8 * 1);
        autopilot_version.middleware_sw_version = autopilot_version.flight_sw_version;

        mavlink_msg_autopilot_version_encode(mav_sys.sysid, mav_sys.compid, msg, &autopilot_version);
        mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
    } break;

    case MAV_CMD_DO_CHANGE_SPEED: {
        float speed_type = command->param1;                                      // 1 for airspeed, 2 for groundspeed
        param_t* param = param_get_by_full_name("FMS", "CRUISE_SPEED");
        float speed = command->param2 >= 0.0f ? command->param2 : param->dval.f; // The desired speed

        if (speed_type == 1) {
            // Set airspeed
            PARAM_SET_FLOAT(FMS, CRUISE_SPEED, speed); // Set the same PARAM，saved for further use
        } else if (speed_type == 2) {
            // Set groundspeed
            PARAM_SET_FLOAT(FMS, CRUISE_SPEED, speed);
        } else {
            // Invalid speed type
            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_FAILED);
            break;
        }

        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_SET_MESSAGE_INTERVAL: {
        uint16_t message_id = (uint16_t)command->param1;
        int32_t interval_us = (int32_t)command->param2;

        // Find the message in the mav_msg_cb_table
        for (uint16_t i = 0; i < sizeof(mav_msg_cb_table) / sizeof(msg_pack_cb_table); i++) {
            if (message_id == mav_msg_cb_table[i].msgid) {
                // Calculate the rate in Hz
                float rate_hz = (interval_us > 0) ? (1000000.0f / interval_us) : 0;

                // Register or update the message interval
                fmt_err_t err = mavproxy_register_period_msg(
                    MAVPROXY_OBC_CHAN,
                    message_id,
                    (uint16_t)rate_hz,
                    mav_msg_cb_table[i].msg_pack_cb,
                    (interval_us > 0));

                if (err == FMT_EOK) {
                    mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
                } else {
                    mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_FAILED);
                }
                return;
            }
        }
        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_UNSUPPORTED);
    } break;

    case MAV_CMD_REQUEST_MESSAGE: {
        uint16_t message_id = (uint16_t)command->param1;

        // Special case for HOME_POSITION message
        if (message_id == MAVLINK_MSG_ID_HOME_POSITION) {

            mavlink_home_position_t home_position = { 0 };
            INS_Out_Bus ins_out;
            FMS_Out_Bus fms_out;

            if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK || mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out) != FMT_EOK) {
                mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_FAILED);
                return;
            }

            home_position.time_usec = systime_now_us();
            home_position.x = fms_out.home[0];
            home_position.y = fms_out.home[1];
            home_position.z = -fms_out.home[2];
            home_position.latitude = ins_out.dx_dlat > 0.0 ? RAD2DEG(fms_out.home[0] / ins_out.dx_dlat + ins_out.lat_0) * 1e7 : 0;
            home_position.longitude = ins_out.dy_dlon > 0.0 ? RAD2DEG(fms_out.home[1] / ins_out.dy_dlon + ins_out.lon_0) * 1e7 : 0;
            home_position.altitude = (fms_out.home[2] + ins_out.alt_0) * 100;
            home_position.q[0] = ins_out.quat[0];
            home_position.q[1] = ins_out.quat[1];
            home_position.q[2] = ins_out.quat[2];
            home_position.q[3] = ins_out.quat[3];

            mavlink_msg_home_position_encode(mav_sys.sysid, mav_sys.compid, msg, &home_position);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
            return;
        }

        if (message_id == MAVLINK_MSG_ID_GIMBAL_MANAGER_INFORMATION) {
            mavlink_gimbal_manager_information_t gimbal_info;
            // Populate gimbal_info with the necessary data
            // Using fake data for demonstration purposes
            gimbal_info.time_boot_ms = 123456789; // Mocked current time in milliseconds
            gimbal_info.cap_flags = 0xFF;         // Mocked capabilities flags
            gimbal_info.tilt_max = 45;            // Mocked max tilt in degrees
            gimbal_info.tilt_min = -45;           // Mocked min tilt in degrees
            gimbal_info.tilt_rate_max = 30;       // Mocked max tilt rate in degrees per second
            gimbal_info.pan_max = 90;             // Mocked max pan in degrees
            gimbal_info.pan_min = -90;            // Mocked min pan in degrees
            gimbal_info.pan_rate_max = 60;        // Mocked max pan rate in degrees per second
            gimbal_info.gimbal_device_id = 1;     // Mocked gimbal device ID
            // Send the gimbal manager information back

            mavlink_msg_gimbal_manager_information_encode(mav_sys.sysid, mav_sys.compid, msg, &gimbal_info);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
            return;
        }

        // Special case for GPS_GLOBAL_ORIGIN message
        if (message_id == MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN) {
            mavlink_gps_global_origin_t gps_global_origin = { 0 };
            INS_Out_Bus ins_out;

            if (mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out) != FMT_EOK) {
                mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_FAILED);
                return;
            }

            gps_global_origin.time_usec = systime_now_us();
            gps_global_origin.latitude = RAD2DEG(ins_out.lat_0) * 1e7;  // Assuming lat_0 is in radians
            gps_global_origin.longitude = RAD2DEG(ins_out.lon_0) * 1e7; // Assuming lon_0 is in radians
            gps_global_origin.altitude = ins_out.alt_0 * 1000;          // Assuming altitude is in meters

            mavlink_msg_gps_global_origin_encode(mav_sys.sysid, mav_sys.compid, msg, &gps_global_origin);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
            return;
        }

        if (message_id == MAVLINK_MSG_ID_AUTOPILOT_VERSION) {
            mavlink_autopilot_version_t autopilot_version = { 0 };

            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

            autopilot_version.capabilities = MAV_PROTOCOL_CAPABILITY_MISSION_FLOAT;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MISSION_INT;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_PARAM_FLOAT;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_COMMAND_INT;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_FTP;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_ATTITUDE_TARGET;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_POSITION_TARGET_LOCAL_NED;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_SET_ACTUATOR_TARGET;
            autopilot_version.capabilities |= MAV_PROTOCOL_CAPABILITY_MAVLINK2;

            /* cheat OBC that we are using the right px4 version */
            autopilot_version.flight_sw_version = ((uint8_t)1 << 8 * 3) | ((uint8_t)10 << 8 * 2) | ((uint8_t)0 << 8 * 1);
            autopilot_version.middleware_sw_version = autopilot_version.flight_sw_version;

            mavlink_msg_autopilot_version_encode(mav_sys.sysid, mav_sys.compid, msg, &autopilot_version);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);

            mavlink_msg_sys_status_pack_func(msg);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);

            return;
        }

        // Find the message in the mav_msg_cb_table
        for (uint16_t i = 0; i < sizeof(mav_msg_cb_table) / sizeof(msg_pack_cb_table); i++) {
            if (message_id == mav_msg_cb_table[i].msgid) {
                // Pack and send the requested message
                mavlink_message_t requested_msg;
                if (mav_msg_cb_table[i].msg_pack_cb(&requested_msg) == FMT_EOK) {
                    mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, &requested_msg, true);
                    mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
                } else {
                    mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_FAILED);
                }
                return;
            }
        }
    } break;

    case MAV_CMD_DO_SET_MODE: {
        uint8_t base_mode = (uint8_t)command->param1;
        uint32_t custom_main_mode = (uint32_t)command->param2;
        uint32_t custom_sub_mode = (uint32_t)command->param3;

        // Log the received command
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
                        LOG_W("unsupported auto mode: %d", custom_sub_mode);
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

        // Acknowledge the command
        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_FLIGHTTERMINATION: {
        // This command is used to terminate the flight
        // You might want to disarm the vehicle or perform a controlled shutdown
        gcs_set_cmd(FMS_Cmd_Disarm, (float[7]) { 0 });

        // Acknowledge the command
        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_SET_ACTUATOR: {
        // This function is not supported yet, just saved for further use
        // This command is used to set an actuator value
        // For example, you might want to control a servo or other actuator
        uint8_t actuator_number = 0;
        float actuator_value = 0.0f;
        if (!isnan(command->param1)) {
            actuator_number = 1 + command->param7 * 6;
            actuator_value = command->param1;
        } else if (!isnan(command->param2)) {
            actuator_number = 2 + command->param7 * 6;
            actuator_value = command->param2;
        } else if (!isnan(command->param3)) {
            actuator_number = 3 + command->param7 * 6;
            actuator_value = command->param3;
        } else if (!isnan(command->param4)) {
            actuator_number = 4 + command->param7 * 6;
            actuator_value = command->param4;
        } else if (!isnan(command->param5)) {
            actuator_number = 5 + command->param7 * 6;
            actuator_value = command->param5;
        } else if (!isnan(command->param6)) {
            actuator_number = 6 + command->param7 * 6;
            actuator_value = command->param6;
        }

        // Log the received command
        LOG_I("Setting actuator %d to value %.2f", actuator_number, actuator_value);

        // Here you would typically set the actuator value
        // publish the auto_cmd message to set the actuator, saved for further use

        // Acknowledge the command
        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_VTOL_TRANSITION: {
        ////////////////////////////////////////////////////
        // Saved for further use in VTOL transition handling
        ////////////////////////////////////////////////////

        // uint8_t vtol_state = (uint8_t)command->param1; // VTOL state to transition to

        // // Log the received command
        // if (vtol_state == MAV_VTOL_STATE_TRANSITION_TO_FW) {
        //    //transition to fixed-wing mode

        // } else if (vtol_state == MAV_VTOL_STATE_TRANSITION_TO_MC) {
        //     //transition to multicopter mode
        // } else {
        //     // Unsupported VTOL state
        //     mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_UNSUPPORTED);
        //     return;
        // }
        mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    default:
        LOG_W("unhandled mavlink command:%d", command->command);
        break;
    }
}

static fmt_err_t handle_mavlink_message(mavlink_message_t* msg, mavlink_system_t this_system)
{
    mavlink_system_t mav_sys = mavproxy_get_system();

    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
        if (PARAM_GET_UINT8(SYSTEM, OBC_HEARTBEAT)) {
            /* send obc heartbeat to gcs */
            gcs_cmd_heartbeat();
        }
        break;
    case MAVLINK_MSG_ID_SYSTEM_TIME:
    case MAVLINK_MSG_ID_TIMESYNC:
    /* we do not handle param and mission request, cause obc no need to know that and it's unsafe to change it */
    case MAVLINK_MSG_ID_PARAM_REQUEST_LIST:
    case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
        /* do nothing */
        break;

    case MAVLINK_MSG_ID_COMMAND_LONG: {
        if (this_system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_long_t command;
            mavlink_msg_command_long_decode(msg, &command);

            handle_mavlink_command(&command, msg);
        }
    } break;

    case MAVLINK_MSG_ID_PING: {

        if (this_system.sysid == mavlink_msg_ping_get_target_system(msg) || mavlink_msg_ping_get_target_system(msg) == 0) {
            mavlink_ping_t ping;
            mavlink_msg_ping_decode(msg, &ping);

            // If the ping is not a response to our ping
            // Print target_system

            mavlink_message_t response_msg;
            mavlink_system_t mav_sys = mavproxy_get_system();

            mavlink_msg_ping_pack(mav_sys.sysid, mav_sys.compid, &response_msg, ping.time_usec, ping.seq, msg->sysid, msg->compid);

            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, &response_msg, true);
        }
        break;
    }

    case MAVLINK_MSG_ID_SET_MODE:
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
                            LOG_W("unsupported auto mode: %d", custom_sub_mode);
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
        break;

    case MAVLINK_MSG_ID_SET_ATTITUDE_TARGET:
        if (this_system.sysid == mavlink_msg_set_attitude_target_get_target_system(msg)) {
            Auto_Cmd_Bus auto_cmd = { 0 };
            mavlink_set_attitude_target_t attitude_target;

            mavlink_msg_set_attitude_target_decode(msg, &attitude_target);

            auto_cmd.timestamp = systime_now_ms();
            /* att command won't use frame variable, so doesn't matter */
            auto_cmd.frame = FRAME_BODY_FRD;

            if (!(attitude_target.type_mask & 1)) {
                auto_cmd.p_cmd = attitude_target.body_roll_rate;
                auto_cmd.cmd_mask |= P_CMD_VALID;
            }

            if (!(attitude_target.type_mask & 2)) {
                auto_cmd.q_cmd = attitude_target.body_pitch_rate;
                auto_cmd.cmd_mask |= Q_CMD_VALID;
            }

            if (!(attitude_target.type_mask & 4)) {
                auto_cmd.r_cmd = attitude_target.body_yaw_rate;
                auto_cmd.cmd_mask |= R_CMD_VALID;
            }

            if (!(attitude_target.type_mask & 64)) {
                auto_cmd.throttle_cmd = attitude_target.thrust * 1000.0f + 1000.0f;
                auto_cmd.cmd_mask |= THROTTLE_CMD_VALID;
            }

            if (!(attitude_target.type_mask & 128)) {
                Euler e;
                quaternion_toEuler((quaternion*)attitude_target.q, &e);

                auto_cmd.phi_cmd = e.roll;
                auto_cmd.theta_cmd = e.pitch;
                auto_cmd.psi_cmd = e.yaw;
                auto_cmd.cmd_mask |= PHI_CMD_VALID | THETA_CMD_VALID | PSI_CMD_VALID;
            }

            /* publish auto command */
            mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);
        }
        break;

    case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED:
        if (this_system.sysid == mavlink_msg_set_position_target_local_ned_get_target_system(msg)) {
            Auto_Cmd_Bus auto_cmd = { 0 };
            mavlink_set_position_target_local_ned_t pos_target_local_ned;

            mavlink_msg_set_position_target_local_ned_decode(msg, &pos_target_local_ned);

            auto_cmd.timestamp = systime_now_ms();

            if (pos_target_local_ned.coordinate_frame == MAV_FRAME_LOCAL_NED || MAV_FRAME_LOCAL_FRD) {
                auto_cmd.frame = FRAME_LOCAL_FRD;
            } else if (pos_target_local_ned.coordinate_frame == MAV_FRAME_BODY_FRD || pos_target_local_ned.coordinate_frame == MAV_FRAME_BODY_NED) {
                auto_cmd.frame = FRAME_BODY_FRD;
            } else {
                LOG_W("unsupported SET_POSITION_TARGET_LOCAL_NED frame:%d", pos_target_local_ned.coordinate_frame);
                break;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_X_IGNORE)) {
                auto_cmd.x_cmd = pos_target_local_ned.x;
                auto_cmd.cmd_mask |= X_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_Y_IGNORE)) {
                auto_cmd.y_cmd = pos_target_local_ned.y;
                auto_cmd.cmd_mask |= Y_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_Z_IGNORE)) {
                auto_cmd.z_cmd = pos_target_local_ned.z;
                auto_cmd.cmd_mask |= Z_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_VX_IGNORE)) {
                auto_cmd.u_cmd = pos_target_local_ned.vx;
                auto_cmd.cmd_mask |= U_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_VY_IGNORE)) {
                auto_cmd.v_cmd = pos_target_local_ned.vy;
                auto_cmd.cmd_mask |= V_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_VZ_IGNORE)) {
                auto_cmd.w_cmd = pos_target_local_ned.vz;
                auto_cmd.cmd_mask |= W_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_AX_IGNORE)) {
                auto_cmd.ax_cmd = pos_target_local_ned.afx;
                auto_cmd.cmd_mask |= AX_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_AY_IGNORE)) {
                auto_cmd.ay_cmd = pos_target_local_ned.afy;
                auto_cmd.cmd_mask |= AY_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_AZ_IGNORE)) {
                auto_cmd.az_cmd = pos_target_local_ned.afz;
                auto_cmd.cmd_mask |= AZ_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_YAW_IGNORE)) {
                auto_cmd.psi_cmd = pos_target_local_ned.yaw;
                auto_cmd.cmd_mask |= PSI_CMD_VALID;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_YAW_RATE_IGNORE)) {
                auto_cmd.psi_rate_cmd = pos_target_local_ned.yaw_rate;
                auto_cmd.cmd_mask |= PSI_RATE_CMD_VALID;
            }

            /* publish auto command */
            mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);
        }
        break;

    case MAVLINK_MSG_ID_PARAM_REQUEST_READ: {
        mavlink_param_request_read_t request_read;
        mavlink_msg_param_request_read_decode(msg, &request_read);

        // Check if the request is for this system
        if (this_system.sysid == request_read.target_system) {
            // Handle the parameter request
            if (request_read.param_index == -1) {
                // Use the param ID field as identifier
                param_t* param = param_get_by_name(request_read.param_id);
                if (param) {
                    mavlink_param_send(param, MAVPROXY_OBC_CHAN);
                } else {
                    send_mavparam_by_name(request_read.param_id, MAVPROXY_OBC_CHAN);
                }
            } else {
                uint16_t mavparam_num = get_mavparam_num();
                if (request_read.param_index < mavparam_num) {
                    send_mavparam_by_index(request_read.param_index, MAVPROXY_OBC_CHAN);
                } else {
                    param_t* param = param_get_by_index(request_read.param_index - mavparam_num);
                    mavlink_param_send(param, MAVPROXY_OBC_CHAN);
                }
            }
        }
    } break;

    case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT:
        if (this_system.sysid == mavlink_msg_set_position_target_global_int_get_target_system(msg)) {
            Auto_Cmd_Bus auto_cmd = { 0 };
            mavlink_set_position_target_global_int_t pos_target_global_int;

            mavlink_msg_set_position_target_global_int_decode(msg, &pos_target_global_int);

            auto_cmd.timestamp = systime_now_ms();

            if (pos_target_global_int.coordinate_frame == MAV_FRAME_GLOBAL_INT || pos_target_global_int.coordinate_frame == MAV_FRAME_GLOBAL_RELATIVE_ALT_INT) {
                auto_cmd.frame = FRAME_GLOBAL_NED;
            } else {
                LOG_W("unsupported SET_POSITION_TARGET_GLOBAL_INT frame:%d", pos_target_global_int.coordinate_frame);
                break;
            }

            auto_cmd.frame = FRAME_GLOBAL_NED;

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_X_IGNORE)) {
                auto_cmd.lat_cmd = pos_target_global_int.lat_int;
                auto_cmd.cmd_mask |= LAT_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_Y_IGNORE)) {
                auto_cmd.lon_cmd = pos_target_global_int.lon_int;
                auto_cmd.cmd_mask |= LON_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_Z_IGNORE)) {
                auto_cmd.alt_cmd = pos_target_global_int.alt;
                auto_cmd.cmd_mask |= ALT_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_VX_IGNORE)) {
                auto_cmd.u_cmd = pos_target_global_int.vx;
                auto_cmd.cmd_mask |= U_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_VY_IGNORE)) {
                auto_cmd.v_cmd = pos_target_global_int.vy;
                auto_cmd.cmd_mask |= V_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_VZ_IGNORE)) {
                auto_cmd.w_cmd = pos_target_global_int.vz;
                auto_cmd.cmd_mask |= W_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_AX_IGNORE)) {
                auto_cmd.ax_cmd = pos_target_global_int.afx;
                auto_cmd.cmd_mask |= AX_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_AY_IGNORE)) {
                auto_cmd.ay_cmd = pos_target_global_int.afy;
                auto_cmd.cmd_mask |= AY_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_AZ_IGNORE)) {
                auto_cmd.az_cmd = pos_target_global_int.afz;
                auto_cmd.cmd_mask |= AZ_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_YAW_IGNORE)) {
                auto_cmd.psi_cmd = pos_target_global_int.yaw;
                auto_cmd.cmd_mask |= PSI_CMD_VALID;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_YAW_RATE_IGNORE)) {
                auto_cmd.psi_rate_cmd = pos_target_global_int.yaw_rate;
                auto_cmd.cmd_mask |= PSI_RATE_CMD_VALID;
            }

            /* publish auto command */
            mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);
        }
        break;

    case MAVLINK_MSG_ID_REQUEST_DATA_STREAM:
        if (this_system.sysid == mavlink_msg_request_data_stream_get_target_system(msg)) {
            mavlink_request_data_stream_t req_data_stream;
            uint16_t i;

            mavlink_msg_request_data_stream_decode(msg, &req_data_stream);

            for (i = 0; i < sizeof(mav_msg_cb_table) / sizeof(msg_pack_cb_table); i++) {
                if (req_data_stream.req_stream_id == mav_msg_cb_table[i].msgid) {
                    if (mavproxy_register_period_msg(MAVPROXY_OBC_CHAN, mav_msg_cb_table[i].msgid, req_data_stream.req_message_rate, mav_msg_cb_table[i].msg_pack_cb, req_data_stream.start_stop) == FMT_EOK) {
                        LOG_I("Message %d registered with frequency %d Hz, start:%d", req_data_stream.req_stream_id, req_data_stream.req_message_rate, req_data_stream.start_stop);
                    } else {
                        LOG_E("Message %d registered failed", req_data_stream.req_stream_id);
                    }
                    break;
                }
            }

            if (i == sizeof(mav_msg_cb_table) / sizeof(msg_pack_cb_table)) {
                LOG_E("Message %d registered failed, can not find msg in loopup table.", req_data_stream.req_stream_id);
            }
        }
        break;

    case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE: {
        /* TODO: don't know why this msg doesn't have get_target_system() */
        mavlink_vision_position_estimate_t vision_pos_est;
        External_Pos_Bus ext_pos_report = { 0 };

        mavlink_msg_vision_position_estimate_decode(msg, &vision_pos_est);

        ext_pos_report.timestamp = systime_now_ms();
        ext_pos_report.field_valid = 11;
        ext_pos_report.x = vision_pos_est.x;
        ext_pos_report.y = vision_pos_est.y;
        ext_pos_report.z = vision_pos_est.z;
        ext_pos_report.phi = vision_pos_est.roll;
        ext_pos_report.theta = vision_pos_est.pitch;
        ext_pos_report.psi = vision_pos_est.yaw;

        /* publish external position */
        mcn_publish(MCN_HUB(external_pos), &ext_pos_report);
    } break;

    case MAVLINK_MSG_ID_PARAM_SET: {
        mavlink_param_set_t param_set;
        mavlink_param_value_t param_value = { 0 };
        mavlink_msg_param_set_decode(msg, &param_set);
        if (strcmp(param_set.param_id, "MIS_TAKEOFF_ALT") == 0) {
            PARAM_SET_FLOAT(FMS, TAKEOFF_H, param_set.param_value);
            param_value.param_value = param_set.param_value;
            param_value.param_type = MAV_PARAM_TYPE_REAL32;
            memcpy(param_value.param_id, param_set.param_id, sizeof(param_value.param_id));
            mavlink_msg_param_value_encode(mav_sys.sysid, mav_sys.compid, msg, &param_value);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
        }
        if (strcmp(param_set.param_id, "MPC_XY_CRUISE") == 0) {
            PARAM_SET_FLOAT(FMS, CRUISE_SPEED, param_set.param_value);
            param_value.param_value = param_set.param_value;
            param_value.param_type = MAV_PARAM_TYPE_REAL32;
            memcpy(param_value.param_id, param_set.param_id, sizeof(param_value.param_id));
            mavlink_msg_param_value_encode(mav_sys.sysid, mav_sys.compid, msg, &param_value);
            mavproxy_send_immediate_msg(MAVPROXY_OBC_CHAN, msg, true);
        }

    } break;

    case MAVLINK_MSG_ID_COMMAND_INT:
        if (this_system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_int_t command;
            Mission_Data_Bus mission_data = { 0 };
            mavlink_msg_command_int_decode(msg, &command);

            if (mcn_copy_from_hub(MCN_HUB(mission_data), &mission_data) == FMT_EOK) {
                /* check if there is no ongoing mission */
                if (mission_data.valid_items == 0) {
                    if (command.command == MAV_CMD_DO_REPOSITION) {
                        mission_data.timestamp = systime_now_ms();
                        mission_data.valid_items = 1;
                        mission_data.seq[0] = 0;
                        mission_data.command[0] = MAV_CMD_NAV_WAYPOINT; /* we treat reposition command as single waypoint */
                        mission_data.frame[0] = command.frame;
                        mission_data.current[0] = command.current;
                        mission_data.autocontinue[0] = command.autocontinue;
                        mission_data.mission_type[0] = 0;
                        mission_data.x[0] = command.x;
                        mission_data.y[0] = command.y;
                        mission_data.z[0] = command.z;

                        if (mcn_publish(MCN_HUB(mission_data), &mission_data) == FMT_EOK) {
                            /* now we set mode to mission to execute the reposition command */
                            gcs_set_mode(PilotMode_Mission);
                            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command.command, MAV_RESULT_ACCEPTED);
                            printf("Reposition command received, setting mission mode\n");
                            break;
                        }
                    } else {
                        mavlink_send_statustext(MAV_SEVERITY_INFO, "Unsupported command:%d\n", command.command);
                        // TODO: Support MAV_CMD_DO_ORBIT
                    }
                } else {
                    mavlink_send_statustext(MAV_SEVERITY_INFO, "Please finish current mission or delete it first");
                }
            }
            mavlink_command_acknowledge(MAVPROXY_OBC_CHAN, command.command, MAV_RESULT_DENIED);
        }
        break;

    case MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET:
        if (this_system.sysid == mavlink_msg_set_actuator_control_target_get_target_system(msg)) {
            mavlink_set_actuator_control_target_t actuator_control_target;
            mavlink_msg_set_actuator_control_target_decode(msg, &actuator_control_target);
            // remained to be processed by FMS and CONTROLLER
        }
        break;

    default:
        LOG_W("unsupported mavlink msg:%d", msg->msgid);
        break;
    }

    return FMT_EOK;
}

fmt_err_t mavobc_init(void)
{
    /* register channel */
    FMT_TRY(mavproxy_register_channel(MAVPROXY_OBC_CHAN));

    /* register periodical mavlink msg */
    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_OBC_CHAN, MAVLINK_MSG_ID_HEARTBEAT, 1, mavlink_msg_heartbeat_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_OBC_CHAN, MAVLINK_MSG_ID_SYS_STATUS, 1, mavlink_msg_sys_status_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_OBC_CHAN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, 1, mavlink_msg_extended_sys_state_pack_func, true));

    /* register obc mavlink handler */
    FMT_TRY(mavproxy_monitor_register_handler(MAVPROXY_OBC_CHAN, handle_mavlink_message));

    return FMT_EOK;
}
