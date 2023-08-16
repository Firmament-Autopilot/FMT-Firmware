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

#include "ar1002_hal.h"
#include "bb_match_id.h"
#include "board.h"
#include "board_device.h"
#include "debuglog.h"
#include "module/task_manager/task_manager.h"
#include "module/workqueue/workqueue_manager.h"
#include "sys_event.h"

#include "bb_led.h"
#include "local_task.h"
#include "sky_sbus.h"

#include "inter_core.h"
#include "mini384.h"
#include "xc7027.h"
#include "wireless_interface.h"
#include "usr_usb_task.h"

//--------------------------------------
static void sys_event_start(void);

_EXT_DTCM1 void wireless_start(void);

_EXT_DTCM1
fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

_EXT_DTCM1
void task_local_entry(void* parameter)
{
    HAL_USB_Init(HAL_USB_PORT_0, HAL_USB_DR_MODE_DEVICE);
    HAL_USB_Init(HAL_USB_PORT_1, HAL_USB_DR_MODE_DEVICE);
    sys_event_start();
    sbus_start();
    bb_led_start();
    bb_match_id_start();

    xc7027_start();
    // mini384_start();

    usr_usb0_interface();
    Wireless_TaskInit(0);
    wireless_start();

    while (1) {
        DLOG_Process(NULL);
        sys_msleep(100);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name       = "local",
    .init       = task_local_init,
    .entry      = task_local_entry,
    .priority   = 25,
    .auto_start = true,
    .stack_size = 4096,
    .param      = NULL,
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
    .name          = "intercore_irq0_callback",
    .period        = 0,
    .schedule_time = 0,
    .run           = run_intercore_irq0_callback
};

void intercore_irq0_callback(void)
{
    WorkQueue_t sysevent_wq = workqueue_find("wq:sysevent_work");

    // bug liuwei for test
    if (sysevent_wq == NULL) {
        return;
    }

    FMT_CHECK(workqueue_schedule_work(sysevent_wq, &intercore_irq0_callback_item));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void run_sys_event(void* parameter)
{

    static uint32_t old = 0;

    uint32_t now = systime_now_ms();

    if (now - old > 2000) {
        // SYS_EVENT_DumpAllListNodes();s
        SYS_EVENT_MallocFreeCntCheck();

        old = now;
    }

    SYS_EVENT_Process();
}

static struct WorkItem sys_event_item = {
    .name          = "sys_event",
    .period        = 10,
    .schedule_time = 0,
    .run           = run_sys_event
};

static void sys_event_start(void)
{
    WorkQueue_t sysevent_wq = workqueue_find("wq:sysevent_work");

    RT_ASSERT(sysevent_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(sysevent_wq, &sys_event_item));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

_EXT_DTCM1
static void run_wireless(void* parameter)
{
    Wireless_MessageProcess();
}

/////////////////////////////////////////////////////

_EXT_DTCM1_BSS
static struct WorkItem wireless_item = {
    .name          = "wireless",
    .period        = 20,
    .schedule_time = 0,
    .run           = run_wireless
};

_EXT_DTCM1
void wireless_start(void)
{

    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");

    RT_ASSERT(lp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(lp_wq, &wireless_item));
}
