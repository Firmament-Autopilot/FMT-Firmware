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
#include "module/mavproxy/px4_custom_mode.h"
#include "module/obc/mavobc.h"
#include "module/sysio/auto_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(fms_output);
MCN_DECLARE(auto_cmd);

static mavlink_system_t mavlink_system;
static McnNode_t fms_out_nod;

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

    if (mcn_poll(fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out);

        if (fms_out.status == VehicleStatus_Arm || fms_out.status == VehicleStatus_Standby) {
            heartbeat.base_mode |= MAV_MODE_FLAG_SAFETY_ARMED;
            heartbeat.system_status = MAV_STATE_ACTIVE;
        }
        /* map fms mode to px4 ctrl mode */
        heartbeat.custom_mode = get_custom_mode(fms_out);
    }

    mavlink_msg_heartbeat_encode(mavlink_system.sysid, mavlink_system.compid, msg_t, &heartbeat);

    return true;
}

static void acknowledge(uint16_t command, uint8_t result)
{
    mavlink_system_t mav_sys = mavobc_get_system();
    mavlink_command_ack_t command_ack = { 0 };
    mavlink_message_t msg;

    command_ack.command = command;
    command_ack.result = result;

    mavlink_msg_command_ack_encode(mav_sys.sysid, mav_sys.compid, &msg, &command_ack);
    mavobc_send_immediate_msg(&msg, true);
}

static void handle_mavlink_command(mavlink_command_long_t* command, mavlink_message_t* msg)
{
    switch (command->command) {
    case MAV_CMD_REQUEST_PROTOCOL_VERSION: {
        mavlink_system_t mav_sys = mavobc_get_system();
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
        mavobc_send_immediate_msg(msg, true);
    } break;
    case MAV_CMD_COMPONENT_ARM_DISARM:
        if (command->param1 == 1.0f) {
            gcs_set_cmd(FMS_Cmd_PreArm);
        } else if (command->param1 == 0.0f) {
            gcs_set_cmd(FMS_Cmd_Disarm);
        }

        acknowledge(command->command, MAV_RESULT_ACCEPTED);

        break;

    case MAV_CMD_NAV_TAKEOFF: {
        gcs_set_cmd(FMS_Cmd_Takeoff);

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_NAV_LAND: {
        gcs_set_cmd(FMS_Cmd_Land);

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_DO_REPOSITION: {
        /* When click pause button, GCS will send this command */
        gcs_set_cmd(FMS_Cmd_Pause);

        acknowledge(command->command, MAV_RESULT_ACCEPTED);
    } break;

    case MAV_CMD_SET_MESSAGE_INTERVAL:
        printf("set msg interval id:%d interval:%d\n", (int)command->param1, (int)command->param2);
        break;

    default:
        printf("mavobc unhandled command long:%d\n", command->command);
        break;
    }
}

static void handle_mavlink_message(mavlink_message_t* msg, mavlink_system_t system)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
        /* do nothing */
        break;

    case MAVLINK_MSG_ID_COMMAND_LONG: {
        if (system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_long_t command;
            mavlink_msg_command_long_decode(msg, &command);

            handle_mavlink_command(&command, msg);
        }
    } break;

    case MAVLINK_MSG_ID_SET_MODE:
        if (system.sysid == mavlink_msg_set_mode_get_target_system(msg)) {
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
                            gcs_set_cmd(FMS_Cmd_Return);
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_TAKEOFF:
                            gcs_set_cmd(FMS_Cmd_Takeoff);
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_LAND:
                            gcs_set_cmd(FMS_Cmd_Land);
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_LOITER:
                            gcs_set_cmd(FMS_Cmd_Pause);
                            break;
                        case PX4_CUSTOM_SUB_MODE_AUTO_MISSION:
                            gcs_set_mode(PilotMode_Mission);
                            break;
                        default:
                            printf("mavobc unsupported auto mode: %d", custom_sub_mode);
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

    case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED:
        if (system.sysid == mavlink_msg_set_position_target_local_ned_get_target_system(msg)) {
            mavlink_set_position_target_local_ned_t pos_target_local_ned;
            Auto_Cmd_Bus auto_cmd = { 0 };

            mavlink_msg_set_position_target_local_ned_decode(msg, &pos_target_local_ned);

            auto_cmd.timestamp = systime_now_ms();

            if (pos_target_local_ned.coordinate_frame == MAV_FRAME_LOCAL_NED) {
                auto_cmd.frame = FRAME_GLOBAL_NED;
            } else if (pos_target_local_ned.coordinate_frame == MAV_FRAME_LOCAL_FRD) {
                auto_cmd.frame = FRAME_LOCAL_FRD;
            } else if (pos_target_local_ned.coordinate_frame == MAV_FRAME_BODY_FRD) {
                auto_cmd.frame = FRAME_BODY_FRD;
            } else {
                printf("unsuppurted SET_POSITION_TARGET_LOCAL_NED frame:%d\n", pos_target_local_ned.coordinate_frame);
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
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_AX_IGNORE)) {
                auto_cmd.ax_cmd = pos_target_local_ned.afx;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_AY_IGNORE)) {
                auto_cmd.ay_cmd = pos_target_local_ned.afy;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_AZ_IGNORE)) {
                auto_cmd.az_cmd = pos_target_local_ned.afz;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_YAW_IGNORE)) {
                auto_cmd.psi_cmd = pos_target_local_ned.yaw;
            }

            if (!(pos_target_local_ned.type_mask & POSITION_TARGET_TYPEMASK_YAW_RATE_IGNORE)) {
                auto_cmd.psi_rate_cmd = pos_target_local_ned.yaw_rate;
            }

            /* publish auto command */
            mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);
        }
        break;

    case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT:
        if (system.sysid == mavlink_msg_set_position_target_global_int_get_target_system(msg)) {
            mavlink_set_position_target_global_int_t pos_target_global_int;
            Auto_Cmd_Bus auto_cmd = { 0 };

            mavlink_msg_set_position_target_global_int_decode(msg, &pos_target_global_int);

            auto_cmd.timestamp = systime_now_ms();

            if (pos_target_global_int.coordinate_frame == MAV_FRAME_GLOBAL_INT) {
                auto_cmd.frame = FRAME_GLOBAL_NED;
            } else {
                printf("unsuppurted SET_POSITION_TARGET_GLOBAL_INT frame:%d\n", pos_target_global_int.coordinate_frame);
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
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_AX_IGNORE)) {
                auto_cmd.ax_cmd = pos_target_global_int.afx;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_AY_IGNORE)) {
                auto_cmd.ay_cmd = pos_target_global_int.afy;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_AZ_IGNORE)) {
                auto_cmd.az_cmd = pos_target_global_int.afz;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_YAW_IGNORE)) {
                auto_cmd.psi_cmd = pos_target_global_int.yaw;
            }

            if (!(pos_target_global_int.type_mask & POSITION_TARGET_TYPEMASK_YAW_RATE_IGNORE)) {
                auto_cmd.psi_rate_cmd = pos_target_global_int.yaw_rate;
            }

            /* publish auto command */
            mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);
        }
        break;

    default:
        // printf("mavobc unknown mavlink msg:%d\n", msg->msgid);
        break;
    }
}

fmt_err_t task_obc_init(void)
{
    fmt_err_t err;

    err = mavobc_init();

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    FMT_ASSERT(fms_out_nod != NULL);

    return err;
}

void task_obc_entry(void* parameter)
{
    mavlink_system = mavobc_get_system();

    /* register periodical mavlink msg */
    mavobc_register_period_msg(MAVLINK_MSG_ID_HEARTBEAT, 1000, mavlink_msg_heartbeat_cb, true);

    mavobc_monitor_register_handler(handle_mavlink_message);

    /* execute mavobc main loop */
    mavobc_loop();
}

TASK_EXPORT __fmt_task_desc = {
    .name = "obc",
    .init = task_obc_init,
    .entry = task_obc_entry,
    .priority = 14,
    .auto_start = true,
    .stack_size = 8192,
    .param = NULL,
    .dependency = NULL
};