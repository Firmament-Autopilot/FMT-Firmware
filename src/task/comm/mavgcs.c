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
#include "Plant.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/px4_custom_mode.h"
#include "module/pmu/power_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/gcs_cmd.h"
#include "module/system/statistic.h"
#include "task_comm.h"

#undef LOG_TAG
#define LOG_TAG "MAVGCS"

MCN_DEFINE(environment_info, sizeof(Environment_Info_Bus));
MCN_DEFINE(external_state, sizeof(mavlink_fmt_external_state_t));

MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(mission_data);

static void handle_mavlink_command(mavlink_command_long_t* command, mavlink_message_t* msg)
{
    switch (command->command) {
    case MAV_CMD_REQUEST_PROTOCOL_VERSION: {
        mavlink_system_t           mav_sys          = mavproxy_get_system();
        mavlink_protocol_version_t protocol_version = { 0 };

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);

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
        mavlink_system_t            mav_sys           = mavproxy_get_system();
        mavlink_autopilot_version_t autopilot_version = { 0 };

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);

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
        autopilot_version.flight_sw_version     = ((uint8_t)1 << 8 * 3) | ((uint8_t)10 << 8 * 2) | ((uint8_t)0 << 8 * 1);
        autopilot_version.middleware_sw_version = autopilot_version.flight_sw_version;

        mavlink_msg_autopilot_version_encode(mav_sys.sysid, mav_sys.compid, msg, &autopilot_version);
        mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, msg, true);
    } break;

    case MAV_CMD_PREFLIGHT_CALIBRATION:
        if (command->param1 == 1) {        // calibration gyr
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

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);
        break;

    case MAV_CMD_COMPONENT_ARM_DISARM:
        if (command->param1 == 1.0f) {
            gcs_set_cmd(FMS_Cmd_PreArm, (float[7]) { 0 });
        } else if (command->param1 == 0.0f) {
            gcs_set_cmd(FMS_Cmd_Disarm, (float[7]) { 0 });
        }

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);

        break;

    case MAV_CMD_NAV_TAKEOFF: {
        gcs_set_cmd(FMS_Cmd_Takeoff, (float[7]) { 0 });

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_NAV_LAND: {
        gcs_set_cmd(FMS_Cmd_Land, (float[7]) { 0 });

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_REPOSITION: {
        /* When click pause button, GCS will send this command */
        gcs_set_cmd(FMS_Cmd_Pause, (float[7]) { 0 });

        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_SET_HOME: {
        mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command->command, MAV_RESULT_ACCEPTED);
    } break;

    default:
        LOG_W("unhandled mavlink command:%d", command->command);
        break;
    }
}

static fmt_err_t handle_mavlink_message(mavlink_message_t* msg, mavlink_system_t this_system)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
        gcs_cmd_heartbeat();
        break;

    case MAVLINK_MSG_ID_SYSTEM_TIME:
        /* do nothing */
        break;

    case MAVLINK_MSG_ID_SET_MODE: {
        if (this_system.sysid == mavlink_msg_set_mode_get_target_system(msg)) {
            mavlink_set_mode_t set_mode;
            mavlink_msg_set_mode_decode(msg, &set_mode);

            uint8_t base_mode        = set_mode.base_mode;
            uint8_t custom_main_mode = (set_mode.custom_mode >> 16) & 0xFF;
            uint8_t custom_sub_mode  = (set_mode.custom_mode >> 24) & 0xFF;

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
            mavproxy_send_event(MAVPROXY_GCS_CHAN, EVENT_SEND_ALL_PARAM);
        }
    } break;

    case MAVLINK_MSG_ID_PARAM_SET: {
        if (this_system.sysid == mavlink_msg_param_set_get_target_system(msg)) {
            mavlink_param_set_t param_set;
            mavlink_msg_param_set_decode(msg, &param_set);

            if (mavlink_param_set(param_set.param_id, param_set.param_value, param_set.param_type) != FMT_EOK) {
                LOG_W("patameter set failed! Unknown parameter:%s", param_set.param_id);
                break;
            }
        }
    } break;

    case MAVLINK_MSG_ID_COMMAND_INT:
        if (this_system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_int_t command;
            Mission_Data_Bus      mission_data = { 0 };
            mavlink_msg_command_int_decode(msg, &command);

            if (mcn_copy_from_hub(MCN_HUB(mission_data), &mission_data) == FMT_EOK) {
                /* check if there is no ongoing mission */
                if (mission_data.valid_items == 0) {
                    if (command.command == MAV_CMD_DO_REPOSITION) {
                        mission_data.timestamp       = systime_now_ms();
                        mission_data.valid_items     = 1;
                        mission_data.seq[0]          = 0;
                        mission_data.command[0]      = MAV_CMD_NAV_WAYPOINT; /* we treat reposition command as single waypoint */
                        mission_data.frame[0]        = command.frame;
                        mission_data.current[0]      = command.current;
                        mission_data.autocontinue[0] = command.autocontinue;
                        mission_data.mission_type[0] = 0;
                        mission_data.x[0]            = command.x;
                        mission_data.y[0]            = command.y;
                        mission_data.z[0]            = command.z;

                        if (mcn_publish(MCN_HUB(mission_data), &mission_data) == FMT_EOK) {
                            /* now we set mode to mission to execute the reposition command */
                            gcs_set_mode(PilotMode_Mission);
                            mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command.command, MAV_RESULT_ACCEPTED);
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
            mavlink_command_acknowledge(MAVPROXY_GCS_CHAN, command.command, MAV_RESULT_DENIED);
        }
        break;

    case MAVLINK_MSG_ID_COMMAND_LONG:
        if (this_system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_long_t command;
            mavlink_msg_command_long_decode(msg, &command);

            handle_mavlink_command(&command, msg);
        }
        break;

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

                ftp_protocol_t.target_system    = msg->sysid;
                ftp_protocol_t.target_component = msg->compid;
                ftp_protocol_t.target_network   = 0;

                mavlink_msg_file_transfer_protocol_encode(this_system.sysid, this_system.compid, msg, &ftp_protocol_t);

                mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, msg, false);
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
        imu_data_t           imu_data;
        mag_data_t           mag_data;
        baro_data_t          baro_data;

        mavlink_msg_hil_sensor_decode(msg, &hil_sensor);

        /* publish hil sensor data */
        imu_data.acc_B_mDs2[0]  = hil_sensor.xacc;
        imu_data.acc_B_mDs2[1]  = hil_sensor.yacc;
        imu_data.acc_B_mDs2[2]  = hil_sensor.zacc;
        imu_data.gyr_B_radDs[0] = hil_sensor.xgyro;
        imu_data.gyr_B_radDs[1] = hil_sensor.ygyro;
        imu_data.gyr_B_radDs[2] = hil_sensor.zgyro;
        imu_data.timestamp_ms   = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_imu0), &imu_data);

        mag_data.mag_B_gauss[0] = hil_sensor.xmag;
        mag_data.mag_B_gauss[1] = hil_sensor.ymag;
        mag_data.mag_B_gauss[2] = hil_sensor.zmag;
        mag_data.timestamp_ms   = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_mag0), &mag_data);

        baro_data.pressure_pa     = hil_sensor.abs_pressure * 1e-3;
        baro_data.temperature_deg = hil_sensor.temperature;
        baro_data.altitude_m      = hil_sensor.pressure_alt;
        baro_data.timestamp_ms    = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_baro), &baro_data);
    } break;

    case MAVLINK_MSG_ID_HIL_GPS: {
        mavlink_hil_gps_t hil_gps;
        gps_data_t        gps_data;

        mavlink_msg_hil_gps_decode(msg, &hil_gps);

        gps_data.lat          = hil_gps.lat;
        gps_data.lon          = hil_gps.lon;
        gps_data.height       = hil_gps.alt;
        gps_data.velN         = (float)hil_gps.vn * 0.01f;
        gps_data.velE         = (float)hil_gps.ve * 0.01f;
        gps_data.velD         = (float)hil_gps.vd * 0.01f;
        gps_data.hAcc         = (float)hil_gps.eph * 0.01f;
        gps_data.vAcc         = (float)hil_gps.epv * 0.01f;
        gps_data.sAcc         = 0; // speed accurancy unknown
        gps_data.numSV        = hil_gps.satellites_visible;
        gps_data.fixType      = hil_gps.fix_type;
        gps_data.timestamp_ms = systime_now_ms();

        mcn_publish(MCN_HUB(sensor_gps), &gps_data);
    } break;
#endif

    case MAVLINK_MSG_ID_FMT_EXTERNAL_STATE: {
        mavlink_fmt_external_state_t ext_state;

        mavlink_msg_fmt_external_state_decode(msg, &ext_state);

        ext_state.timestamp = systime_now_ms();
        /* publish external state */
        mcn_publish(MCN_HUB(external_state), &ext_state);
    } break;

    case MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO: {
        mavlink_fmt_environment_info_t env_info;
        Environment_Info_Bus           environment_info = { 0 };

        mavlink_msg_fmt_environment_info_decode(msg, &env_info);

        environment_info.timestamp       = systime_now_ms();
        environment_info.hit_point[0]    = env_info.hit_point[0];
        environment_info.hit_point[1]    = env_info.hit_point[1];
        environment_info.hit_point[2]    = env_info.hit_point[2];
        environment_info.hit_normal[0]   = env_info.hit_normal[0];
        environment_info.hit_normal[1]   = env_info.hit_normal[1];
        environment_info.hit_normal[2]   = env_info.hit_normal[2];
        environment_info.hit_location[0] = env_info.hit_location[0];
        environment_info.hit_location[1] = env_info.hit_location[1];
        environment_info.hit_location[2] = env_info.hit_location[2];
        // TODO: add torque and force

        mcn_publish(MCN_HUB(environment_info), &environment_info);
    } break;

    default: {
        LOG_W("unhandled mavlink msg:%d", msg->msgid);
        return FMT_ENOTHANDLE;
    } break;
    }

    return FMT_EOK;
}

fmt_err_t mavgcs_init(void)
{
    mcn_advertise(MCN_HUB(external_state), NULL);
    mcn_advertise(MCN_HUB(environment_info), NULL);

    /* register periodical mavlink msg */
    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_HEARTBEAT, 1, mavlink_msg_heartbeat_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_SYS_STATUS, 1, mavlink_msg_sys_status_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_SYSTEM_TIME, 1, mavlink_msg_system_time_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, 1, mavlink_msg_extended_sys_state_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_ATTITUDE, 10, mavlink_msg_attitude_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_LOCAL_POSITION_NED, 10, mavlink_msg_local_position_ned_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_GLOBAL_POSITION_INT, 10, mavlink_msg_global_position_int_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_VFR_HUD, 5, mavlink_msg_vfr_hud_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_ALTITUDE, 10, mavlink_msg_altitude_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_GPS_RAW_INT, 10, mavlink_msg_gps_raw_int_pack_func, true));

    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_RC_CHANNELS, 10, mavlink_msg_rc_channels_pack_func, true));

#ifdef FMT_USING_SIH
    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_GCS_CHAN, MAVLINK_MSG_ID_HIL_STATE, 60, mavlink_msg_hil_state_pack_func, true));
#endif

    /* register gcs mavlink handler */
    FMT_TRY(mavproxy_monitor_register_handler(MAVPROXY_GCS_CHAN, handle_mavlink_message));

    return FMT_EOK;
}
