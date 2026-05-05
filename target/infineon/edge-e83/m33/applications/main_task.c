/******************************************************************************
 * Copyright 2021-2023 The Firmament Authors. All Rights Reserved.
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

#include "interface.h"
#include "module/task_manager/task_manager.h"


static fmt_err_t task_init(void)
{
    FMT_TRY(interface_init());
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
    printf("main task started.\n");

    /* main loop */
    while (1) {
        interface_listen();

        if (sync_finish()) {
            // led_type = LED_BLUE;
            // led_on(LED_RED);

            // if (rc_config.protocol == 1) {
            //     send_sbus_value();
            // } else if (rc_config.protocol == 2) {
            //     send_ppm_value();
            // }
        } else {
            // led_type = LED_RED;
            // led_on(LED_BLUE);

            /* try send sync cmd to fmu */
            PERIOD_EXECUTE(fmu_sync, 200, send_io_cmd(IO_CODE_SYNC, NULL, 0););
        }
        sys_msleep(1);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "main",
    .init = task_init,
    .entry = task_entry,
    .priority = 6,
    .auto_start = true,
    .stack_size = 10240,
    .param = NULL,
    .dependency = NULL
};
