/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#include "board_device.h"
#include "module/fmtio/fmtio.h"
#include "module/task_manager/task_manager.h"

fmt_err_t task_fmtio_init(void)
{
    return fmtio_init(FMTIO_DEVICE_NAME);
}

void task_fmtio_entry(void* parameter)
{
    /* execute fmtio main loop */
    fmtio_loop();
}

FMT_TASK_EXPORT(
    fmtio,                 /* name */
    task_fmtio_init,       /* init */
    task_fmtio_entry,      /* entry */
    FMTIO_THREAD_PRIORITY, /* priority */
    2048,                  /* stack size */
    NULL,                  /* param */
    NULL                   /* dependency */
);