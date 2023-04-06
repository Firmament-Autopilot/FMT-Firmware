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
#include "module/task_manager/task_manager.h"

MCN_DECLARE(fms_output);

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