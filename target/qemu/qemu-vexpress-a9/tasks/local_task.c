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

#include "module/task_manager/task_manager.h"

fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

void task_local_entry(void* parameter)
{
    printf("Hello FMT! This is a local task.\n");

    while (1) {
        sys_msleep(1000);
    }
}

FMT_TASK_EXPORT(
    local_task,       /* name */
    task_local_init,  /* init */
    task_local_entry, /* entry */
    25,               /* priority */
    1024,             /* stack size */
    NULL,             /* param */
    NULL              /* dependency */
);
