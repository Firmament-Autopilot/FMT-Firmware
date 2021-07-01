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

#include "driver/ncp5623c.h"
#include "hal/i2c.h"
#include "hal/i2c_dev.h"
#include "hal/pin.h"
#include "hal/usbd_cdc.h"
#include "module/sensor/sensor_hub.h"
#include "module/task_manager/task_manager.h"
#include "module/utils/devmq.h"
#include "module/work_queue/workqueue_manager.h"

static rt_device_t rgb_led_dev;


fmt_err_t task_simple_init(void)
{
    return FMT_EOK;
}

static void rgb_led_control(void)
{
    static int bright = 0;
    static int inc = 0;
    static int max_bright = 16;
    static int min_bright = 0;
    DEFINE_TIMETAG(rgb_led, 0);

    if (bright <= min_bright) {
        TIMETAG(rgb_led)->period = 150;
    } else {
        if (bright >= max_bright) {
            TIMETAG(rgb_led)->period = 250;
        } else {
            TIMETAG(rgb_led)->period = 50;
        }
    }

    if (check_timetag(TIMETAG(rgb_led))) {
        /* breath light control */
        if (bright <= min_bright)
            inc = 1;

        if (bright >= max_bright)
            inc = -1;

        bright += inc;
        rt_device_control(rgb_led_dev, NCP5623_CMD_SET_BRIGHT, (void*)bright);
    }
}

void task_simple_entry(void* parameter)
{
    // WorkQueue_t wq = workqueue_find("wq:lp_work");
    // static struct WorkItem item = { .name = "sensor_work", .period = 1, .schedule_time = 0, .run = sensor_collect };
    // FMT_CHECK(workqueue_schedule_work(wq, &item));

    rgb_led_dev = rt_device_find("ncp5623c");
    RT_CHECK(rt_device_open(rgb_led_dev, RT_DEVICE_OFLAG_RDWR));
    RT_CHECK(rt_device_control(rgb_led_dev, NCP5623_CMD_SET_COLOR, (void*)NCP5623_LED_WHITE));
    sys_msleep(10);

    while (1) {
        rgb_led_control();
        sys_msleep(10);
    }
}

// FMT_TASK_EXPORT(
//     simple,            /* name */
//     task_simple_init,  /* init */
//     task_simple_entry, /* entry */
//     10,                /* priority */
//     2048,              /* stack size */
//     NULL,              /* param */
//     NULL               /* dependency */
// );