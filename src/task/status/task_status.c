/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#include "module/fms/fms_interface.h"
#include "module/ins/ins_interface.h"
#include "module/mavproxy/mavproxy.h"
#include "module/pmu/power_manager.h"
#include "module/sysio/pilot_cmd.h"
#include "module/task_manager/task_manager.h"
#include "task/task_logger.h"

#define TAG "StatusTask"

MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);
MCN_DECLARE(pilot_cmd);

static McnNode_t fms_out_nod;
static McnNode_t ins_out_nod;
static McnNode_t pilot_cmd_nod;

RT_WEAK void vehicle_status_change_cb(uint8_t status);
RT_WEAK void vehicle_state_change_cb(uint8_t mode);

static void update_fms_status(void)
{
    /* set initial status/state to disarm to avoid mlog stop unintentionally */
    static FMS_Out_Bus old_fms_out = {.status = VehicleStatus_Disarm, .state = VehicleState_Disarm};
    FMS_Out_Bus fms_out;

    if (fms_out_nod == NULL)
        return;

    if (mcn_poll(fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out);

        if (fms_out.status != old_fms_out.status) {
            switch (fms_out.status) {
            case VehicleStatus_Disarm:
                ulog_i(TAG, "[Status] Disarm");

                /* stop mlog when disarm */
                if (PARAM_GET_INT32(SYSTEM, MLOG_MODE) == 1 || PARAM_GET_INT32(SYSTEM, MLOG_MODE) == 2) {
                    mlog_stop();
                }
                break;

            case VehicleStatus_Standby:
                ulog_i(TAG, "[Status] Standby");
                break;

            case VehicleStatus_Arm:
                ulog_i(TAG, "[Status] Arm");

                /* start mlog from arm */
                if (PARAM_GET_INT32(SYSTEM, MLOG_MODE) == 1 && mlog_get_status() == MLOG_STATUS_IDLE) {
                    logger_start_mlog(NULL);
                }
                break;

            default:
                ulog_w(TAG, "[Status] Unknown");
                break;
            }

            if (vehicle_status_change_cb) {
                vehicle_status_change_cb(fms_out.status);
            }
        }

        if (fms_out.state != old_fms_out.state) {
            switch (fms_out.state) {
            case VehicleState_Takeoff:
                mavlink_send_statustext(MAV_SEVERITY_INFO, "Takeoff detected");
                break;
            case VehicleState_Land:
                mavlink_send_statustext(MAV_SEVERITY_INFO, "Landing detected");
                break;
            default:
                break;
            }

            if (vehicle_state_change_cb) {
                vehicle_state_change_cb(fms_out.state);
            }
        }

        old_fms_out = fms_out;
    }
}

static void update_ins_status(void)
{
    //TODO
}

static void update_pilot_cmd_status(void)
{
    static Pilot_Cmd_Bus old_pilot_cmd;
    Pilot_Cmd_Bus pilot_cmd;

    if (mcn_poll(pilot_cmd_nod)) {
        mcn_copy(MCN_HUB(pilot_cmd), pilot_cmd_nod, &pilot_cmd);

        if (pilot_cmd.cmd_1 != old_pilot_cmd.cmd_1) {
            switch (pilot_cmd.cmd_1) {
            case CMD_PreArm:
                ulog_i(TAG, "[FMS Cmd] PreArm");
                break;
            case CMD_Arm:
                ulog_i(TAG, "[FMS Cmd] Arm");
                break;
            case CMD_Disarm:
                ulog_i(TAG, "[FMS Cmd] Disarm");
                break;
            case CMD_Takeoff:
                ulog_i(TAG, "[FMS Cmd] Takeoff");
                break;
            case CMD_Land:
                ulog_i(TAG, "[FMS Cmd] Land");
                break;
            case CMD_Return:
                ulog_i(TAG, "[FMS Cmd] Return");
                break;
            case CMD_Pause:
                ulog_i(TAG, "[FMS Cmd] Pause");
                break;
            case CMD_Continue:
                ulog_i(TAG, "[FMS Cmd] Continue");
                break;
            default:
                break;
            }
        }

        if (pilot_cmd.mode != old_pilot_cmd.mode) {
            switch (pilot_cmd.mode) {
            case PilotMode_Manual:
                ulog_i(TAG, "[Pilot Mode] Manual");
                break;
            case PilotMode_Acro:
                ulog_i(TAG, "[Pilot Mode] Acro");
                break;
            case PilotMode_Stabilize:
                ulog_i(TAG, "[Pilot Mode] Stabilize");
                break;
            case PilotMode_Altitude:
                ulog_i(TAG, "[Pilot Mode] Altitude");
                break;
            case PilotMode_Position:
                ulog_i(TAG, "[Pilot Mode] Position");
                break;
            case PilotMode_Mission:
                ulog_i(TAG, "[Pilot Mode] Mission");
                break;
            case PilotMode_Offboard:
                ulog_i(TAG, "[Pilot Mode] Offboard");
                break;
            default:
                ulog_i(TAG, "[Pilot Mode] Unknown");
                break;
            }
        }

        old_pilot_cmd = pilot_cmd;
    }
}

fmt_err_t task_status_init(void)
{
    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    RT_ASSERT(fms_out_nod != NULL);

    ins_out_nod = mcn_subscribe(MCN_HUB(ins_output), NULL, NULL);
    RT_ASSERT(ins_out_nod != NULL);

    pilot_cmd_nod = mcn_subscribe(MCN_HUB(pilot_cmd), NULL, NULL);
    RT_ASSERT(pilot_cmd_nod != NULL);

    return FMT_EOK;
}

void task_status_entry(void* parameter)
{
#if defined(FMT_USING_HIL)
    ulog_i(TAG, "HIL Simulation");
#endif

#if defined(FMT_USING_SIH)
    ulog_i(TAG, "SIH Simulation");
#endif

#ifdef FMT_HIL_WITH_ACTUATOR
    ulog_w(TAG, "Actuator enabled for HIL, make sure you have removed all propellers!");
#endif

    while (1) {
        // update pilot command status
        update_pilot_cmd_status();

        // update FMS output status
        update_fms_status();

        // update INS output status
        update_ins_status();

        TIMETAG_CHECK_EXECUTE(poll_bat_status, 500, pmu_poll_battery_status(););

        sys_msleep(10);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "status",
    .init = task_status_init,
    .entry = task_status_entry,
    .priority = STATUS_THREAD_PRIORITY,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};
