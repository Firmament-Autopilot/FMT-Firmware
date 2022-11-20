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
#include "module/workqueue/workqueue_manager.h"
#include "debuglog.h"
#include "sys_event.h"
#include "bb_match_id.h"
#include "ar1002_hal.h"
#include "board_device.h"
#include "board.h"

#include "local_task.h"
#include "bb_led.h"
#include "sky_sbus.h"

#include "inter_core.h"
#include "xc7027.h"


//--------------------------------------
static void sys_event_start(void);

_EXT_DTCM1
fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

_EXT_DTCM1
void task_local_entry(void* parameter)
{

    sys_event_start();
    sbus_start();
    bb_led_start();
    bb_match_id_start();

    xc7027_start();

    while (1) {
        DLOG_Process(NULL);
        sys_msleep(10);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "local",
    .init = task_local_init,
    .entry = task_local_entry,
    .priority = 25,
    .auto_start = true,
    .stack_size = 1024,
    .param = NULL,
    .dependency = NULL
};


/////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////
// incore handle

static void run_intercore_irq0_callback(void* parameter)
{
    InterCore_IRQ0_CALL();
}

static struct WorkItem intercore_irq0_callback_item = {
    .name = "intercore_irq0_callback",
    .period = 0,
    .schedule_time = 0,
    .run = run_intercore_irq0_callback
};

void intercore_irq0_callback(void)
{
    WorkQueue_t sysevent_wq = workqueue_find("wq:sysevent_work");

    RT_ASSERT(sysevent_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(sysevent_wq, &intercore_irq0_callback_item));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void run_sys_event(void* parameter)
{
    // SYS_EVENT_DumpAllListNodes();
    // SYS_EVENT_MallocFreeCntCheck();
    SYS_EVENT_Process();
}

static struct WorkItem sys_event_item = {
    .name = "sys_event",
    .period = 10,
    .schedule_time = 0,
    .run = run_sys_event
};

static void sys_event_start(void)
{
    WorkQueue_t sysevent_wq = workqueue_find("wq:sysevent_work");

    RT_ASSERT(sysevent_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(sysevent_wq, &sys_event_item));
}

