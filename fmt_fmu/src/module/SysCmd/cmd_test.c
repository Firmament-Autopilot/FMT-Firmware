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

#include <stdlib.h>
#include <string.h>

#include "hal/motor.h"
#include "hal/rc.h"
#include "hal/serial.h"
#include "hal/systick.h"
#include "module/console/console.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sensor/sensor_manager.h"
#include "module/syscmd/syscmd.h"
#include "module/sysio/pilot_cmd.h"
#include "module/system/statistic.h"
#include "module/toml/toml.h"
#include "module/work_queue/work_queue.h"
#include "module/work_queue/workqueue_manager.h"

void run1(void)
{
    console_printf("I am work1\n");
}

void run2(void)
{
    console_printf("I am work2\n");
}

static int handle_cmd(int argc, char** argv, int optc, optv_t* optv)
{
    // test_main();

    // WorkQueue_t wq = workqueue_create("wq:test", 10, 4096, 20);
    WorkQueue_t wq = workqueue_find("wq:system");
    if (wq == NULL) {
        RT_ASSERT(false);
    }
    static struct WorkItem item1 = { .name = "period_work", .period = 1000, .schedule_time = 0, .run = run1 };
    static struct WorkItem item2 = { .name = "period_work2", .period = 0, .schedule_time = 0, .run = run2 };

    item2.schedule_time = SCHEDULE_DELAY(2000);

    FMT_CHECK(workqueue_schedule_work(wq, &item1));
    FMT_CHECK(workqueue_schedule_work(wq, &item2));

    // FMT_CHECK(workqueue_delete(wq));

    // FMT_CHECK(workqueue_cancel_work(wq, &item4));

    // print_wq(wq);

    return 0;
}

int cmd_test(int argc, char** argv)
{
    return syscmd_process(argc, argv, handle_cmd);
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);