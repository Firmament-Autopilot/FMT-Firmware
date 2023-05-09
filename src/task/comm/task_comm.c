/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#include "module/mavproxy/mavproxy.h"
#include "module/task_manager/task_manager.h"

fmt_err_t gcs_handler_init(void);

fmt_err_t task_comm_init(void)
{
    /* init mavproxy */
    FMT_TRY(mavproxy_init());
    /* init ground control station handler */
    FMT_TRY(gcs_handler_init());

    return FMT_EOK;
}

void task_comm_entry(void* parameter)
{
    /* execute mavproxy main loop */
    mavproxy_loop();
}

TASK_EXPORT __fmt_task_desc = {
    .name = "comm",
    .init = task_comm_init,
    .entry = task_comm_entry,
    .priority = COMM_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 8192,
    .param = NULL,
    .dependency = NULL
};