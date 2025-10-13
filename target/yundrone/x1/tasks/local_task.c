/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "module/task_manager/task_manager.h"

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
    /* main loop */
    while (1) {
        printf("Hello FMT");
        sys_msleep(1000);
    }
}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "local",
//     .init = task_init,
//     .entry = task_entry,
//     .priority = 25,
//     .auto_start = true,
//     .stack_size = 4096,
//     .param = NULL,
//     .dependency = NULL
// };
