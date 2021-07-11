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

#include "module/fms/fms_model.h"
#include "module/ins/ins_model.h"
#include "module/sysio/pilot_cmd.h"
#include "module/task_manager/task_manager.h"
#include "module/pmu/power_manager.h"
#include "task/task_logger.h"

#define TAG "StatusTask"

MCN_DECLARE(fms_output);
MCN_DECLARE(ins_output);
MCN_DECLARE(pilot_cmd);

static McnNode_t fms_out_nod;
static McnNode_t ins_out_nod;
static McnNode_t pilot_cmd_nod;

RT_WEAK void vehicle_status_change_cb(uint8_t status);
RT_WEAK void vehicle_mode_change_cb(uint8_t mode);

static void update_fms_status(void)
{
    static FMS_Out_Bus old_fms_out;
    FMS_Out_Bus fms_out;

    if (fms_out_nod == NULL)
        return;

    if (mcn_poll(fms_out_nod)) {
        mcn_copy(MCN_HUB(fms_output), fms_out_nod, &fms_out);

        if (fms_out.mode != old_fms_out.mode) {
            switch (fms_out.mode) {
            case 1:
                ulog_i(TAG, "[Mode]] Mission");
                break;

            case 2:
                ulog_i(TAG, "[Mode] Position");
                break;

            case 3:
                ulog_i(TAG, "[Mode] Altitude Hold");
                break;

            case 4:
                ulog_i(TAG, "[Mode] Manual");
                break;

            case 5:
                ulog_i(TAG, "[Mode] Acro");
                break;

            default:
                ulog_w(TAG, "[Mode] Unknown");
                break;
            }

            if (vehicle_mode_change_cb) {
                vehicle_mode_change_cb(fms_out.mode);
            }
        }

        if (fms_out.state != old_fms_out.state) {
            switch (fms_out.state) {
            case 0:
                ulog_i(TAG, "[Status] Disarm");

                /* stop blog when disarm */
                if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 1 || PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 2) {
                    blog_stop();
                }
                break;

            case 1:
                ulog_i(TAG, "[Status] Standby");
                break;

            case 2:
                ulog_i(TAG, "[Status] Arm");

                /* start blog from arm */
                if (PARAM_GET_INT32(SYSTEM, BLOG_MODE) == 1 && blog_get_status() == BLOG_STATUS_IDLE) {
                    logger_start_blog(NULL);
                }
                break;

            default:
                ulog_w(TAG, "[Status] Unknown");
                break;
            }

            if (vehicle_status_change_cb) {
                vehicle_status_change_cb(fms_out.state);
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
            case FMS_CMD_FORCE_DISARM:
                ulog_i(TAG, "[Pilot Cmd] Force Disarm");
                break;
            default:
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
#ifdef FMT_USING_HIL
#ifdef FMT_USING_SIH
    ulog_i(TAG, "SIH Simulation");
#else
    ulog_i(TAG, "HIL Simulation");
#endif
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

FMT_TASK_EXPORT(
    status,                 /* name */
    task_status_init,       /* init */
    task_status_entry,      /* entry */
    STATUS_THREAD_PRIORITY, /* priority */
    2048,                   /* stack size */
    NULL,                   /* param */
    NULL                    /* dependency */
);
