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

#include "FMS.h"
#include "module/sysio/auto_cmd.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(auto_cmd);

#define RATE            50   // loop rate hz

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
    printf("Offboard demo!\n");

    const float dt = 1.0f / RATE;

    while (1) {
        Auto_Cmd_Bus auto_cmd;

        auto_cmd.timestamp = systime_now_ms(),
        auto_cmd.frame = FRAME_BODY_FRD,
        auto_cmd.u_cmd = 2,
        auto_cmd.r_cmd = PI/10,
        auto_cmd.cmd_mask = U_CMD_VALID | R_CMD_VALID;

        mcn_publish(MCN_HUB(auto_cmd), &auto_cmd);

        sys_msleep(dt * 1000);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "offboard",
    .init = task_init,
    .entry = task_entry,
    .priority = 25,
    .auto_start = false,
    .stack_size = 1024,
    .param = NULL,
    .dependency = NULL
};
