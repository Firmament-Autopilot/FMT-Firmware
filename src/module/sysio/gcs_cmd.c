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

#include "module/utils/ringbuffer.h"
#include <FMS.h>

MCN_DEFINE(gcs_cmd, sizeof(GCS_Cmd_Bus));
MCN_DECLARE(fms_output);

static uint32_t gcs_cmd_buffer[20];
static ringbuffer* gcs_cmd_rb;
static PilotMode gcs_mode_buffer[20];
static ringbuffer* gcs_mode_rb;
// static PilotMode new_mode;
static GCS_Cmd_Bus gcs_cmd;
static McnNode_t fms_out_nod;

static int gcs_cmd_echo(void* parameter)
{
    GCS_Cmd_Bus gcs_cmd;

    if (mcn_copy_from_hub((McnHub*)parameter, &gcs_cmd) != FMT_EOK) {
        return -1;
    }

    printf("timestamp:%u mode:%u cmd1:%u cmd2:%u\n",
        gcs_cmd.timestamp, gcs_cmd.mode, gcs_cmd.cmd_1, gcs_cmd.cmd_2);

    return 0;
}

fmt_err_t gcs_set_cmd(FMS_Cmd cmd)
{
    uint32_t new_cmd = cmd;

    switch (cmd) {
    case CMD_PreArm:
        printf("GCS PreArm Command\n");
        break;
    case CMD_Arm:
        printf("GCS Arm Command\n");
        break;
    case CMD_Disarm:
        printf("GCS Disarm Command\n");
        break;
    case CMD_Takeoff:
        printf("GCS Takeoff Command\n");
        break;
    case CMD_Land:
        printf("GCS Land Command\n");
        break;
    case CMD_Return:
        printf("GCS Return Command\n");
        break;
    case CMD_Pause:
        printf("GCS Pause Command\n");
        break;
    case CMD_Continue:
        printf("GCS Continue Command\n");
        break;
    default:
        break;
    }

    ringbuffer_put(gcs_cmd_rb, (uint8_t*)&new_cmd, sizeof(new_cmd));

    return FMT_EOK;
}

fmt_err_t gcs_set_mode(PilotMode mode)
{
    uint32_t new_mode = mode;
    FMS_Out_Bus fms_out;

    switch (mode) {
    case PilotMode_Manual:
        printf("GCS Mode Manual\n");
        break;
    case PilotMode_Acro:
        printf("GCS Mode Acro\n");
        break;
    case PilotMode_Stabilize:
        printf("GCS Mode Stabilize\n");
        break;
    case PilotMode_Altitude:
        printf("GCS Mode Altitude\n");
        break;
    case PilotMode_Position:
        printf("GCS Mode Position\n");
        break;
    case PilotMode_Mission:
        printf("GCS Mode Mission\n");
        break;
    case PilotMode_Offboard:
        printf("GCS Mode Offboard\n");
        break;
    default:
        printf("GCS invalid mode %d\n", mode);
        return FMT_EINVAL;
    }

    fmt_err_t err = mcn_copy_from_hub(MCN_HUB(fms_output), &fms_out);

    if (err == FMT_EOK && (fms_out.mode == PilotMode_Mission || fms_out.mode == PilotMode_Offboard)
        && fms_out.mode == mode && fms_out.state == VehicleState_Hold) {
        uint32_t new_cmd = CMD_Continue;
        ringbuffer_put(gcs_cmd_rb, (uint8_t*)&new_cmd, sizeof(new_cmd));
    } else {
        ringbuffer_put(gcs_mode_rb, (uint8_t*)&new_mode, sizeof(new_mode));
        new_mode = PilotMode_None;
        ringbuffer_put(gcs_mode_rb, (uint8_t*)&new_mode, sizeof(new_mode));
    }

    // new_mode = mode;

    return FMT_EOK;
}

fmt_err_t gcs_cmd_collect(void)
{
    static uint32_t _last_cmd_timestamp = 0;
    uint8_t updated = 0;
    uint32_t time_now = systime_now_ms();

    // if (gcs_cmd.mode != new_mode) {
    //     gcs_cmd.mode = new_mode;

    //     updated = 1;
    // }

    if (ringbuffer_getlen(gcs_mode_rb) > 0) {
        ringbuffer_get(gcs_mode_rb, (uint8_t*)&gcs_cmd.mode, sizeof(gcs_cmd.mode));
        updated = 1;
    }

    /* command lasts for 100ms */
    if (time_now - _last_cmd_timestamp > 100) {
        /* check if there is new command in buffer */
        if (ringbuffer_getlen(gcs_cmd_rb) > 0) {
            _last_cmd_timestamp = time_now;

            ringbuffer_get(gcs_cmd_rb, (uint8_t*)&gcs_cmd.cmd_1, sizeof(gcs_cmd.cmd_1));
            updated = 1;
        } else {
            if (gcs_cmd.cmd_1 > 0) {
                gcs_cmd.cmd_1 = 0;
                updated = 1;
            }
        }
    }

    if (updated) {
        gcs_cmd.timestamp = systime_now_ms();

        FMT_TRY(mcn_publish(MCN_HUB(gcs_cmd), &gcs_cmd));
    }

    return FMT_EOK;
}

fmt_err_t gcs_cmd_init(void)
{
    gcs_cmd_rb = ringbuffer_static_create((uint8_t*)gcs_cmd_buffer, sizeof(gcs_cmd_buffer));
    gcs_mode_rb = ringbuffer_static_create((uint8_t*)gcs_mode_buffer, sizeof(gcs_mode_buffer));
    RT_ASSERT(gcs_cmd_rb != NULL);
    RT_ASSERT(gcs_mode_rb != NULL);

    FMT_TRY(mcn_advertise(MCN_HUB(gcs_cmd), gcs_cmd_echo));

    fms_out_nod = mcn_subscribe(MCN_HUB(fms_output), NULL, NULL);
    if (fms_out_nod == NULL) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}