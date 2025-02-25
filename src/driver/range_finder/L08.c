/******************************************************************************
 * Copyright 2024 The Firmament Authors. All Rights Reserved.
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

/*
    This driver shoud work for benewake TF serial devices, such as TFmini, TFmini-Plus, etc.
*/

#include <firmament.h>

#include "module/sensor/sensor_hub.h"
#include "module/workqueue/workqueue_manager.h"

#define EVENT_L08_UPDATE (1 << 0)

MCN_DECLARE(sensor_rangefinder);

typedef enum {
    L08_HEADER = 0XFF,
    L08_DATA_H,
    L08_DATA_L,
    L08_CHECKSUM
} L08_State;

typedef struct {
    uint32_t timestamp;   // ms
    int16_t  distance;    // distance of TFmini_S (0~2000)cm,
} L08_data;

static rt_device_t     dev;
static rt_thread_t     thread;
static struct rt_event event;
static L08_data       data;
static rf_data_t       rf_report;
static int             RF_ID;

static void start_thread(void* parameter)
{
    RT_CHECK(rt_thread_startup(thread));
}

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_L08_UPDATE);
}

static bool parse_package(uint8_t c)
{
    static L08_State state    = L08_HEADER;
    static uint16_t    dis;
    static uint8_t    cs;
    bool              cmplt = false;

    switch (state) {
        case L08_HEADER:
            if (c == 0xFF) {
                cs = c;
                state++;
            }
            break;
        case L08_DATA_H:
            if (cs == 0xFF) {
                cs += c;
                state++;
                dis = c << 8;
            } else {
                state = L08_HEADER;
            }
            break;
        case L08_DATA_L:
            cs += c;
            dis = dis | c;
            state++;
            break;

        case L08_CHECKSUM:
            if (cs == c) {
                cmplt            = true;
                data.timestamp   = systime_now_ms();
                data.distance    = (float)dis;
            } else {
                printf("wrong cheksum:%x %x\n", cs, c);
            }
            state = L08_HEADER;
            break;
        default:
            state = L08_HEADER;
            break;
    }

    return cmplt;
}

static void thread_entry(void* args)
{
    rt_err_t    res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_L08_UPDATE;
    uint8_t     c;

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        printf("L08 fail to open device!\n");
        return;
    }

    while (1) {
        uint8_t ch = 0;
        rt_device_write(dev, 0, &ch, 1);

        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 20, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_L08_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if (parse_package(c) == true) {
                    uint32_t time_now = systime_now_ms();

                    rf_report.timestamp_ms = time_now;

                    if (data.distance < 5.0 || data.distance > 1000.0) {
                        /* negative value indicate range finder invalid */
                        rf_report.distance_m = -1;
                    } else {
                        /* cm to meter */
                        rf_report.distance_m = data.distance * 0.001f;
                    }
                    /* publish range finder data */
                    mcn_publish(MCN_HUB(sensor_rangefinder), &rf_report);
                    RF_ID = mlog_get_bus_id("Rangefinder");
                    mlog_push_msg((uint8_t*)&rf_report, RF_ID, sizeof(rf_report));
                }
            }
        }
        systime_msleep(25);
    }
}

static struct WorkItem work_item = {
    .name          = "L08",
    .period        = 0,
    .schedule_time = 1000,
    .run           = start_thread
};

rt_err_t L08_drv_init(const char* uart_dev_name)
{
    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    thread = rt_thread_create("L08", thread_entry, RT_NULL, 2 * 1024, 7, 1);

    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_event_init(&event, "L08", RT_IPC_FLAG_FIFO));

    RT_CHECK(rt_device_set_rx_indicate(dev, rx_ind_cb));

    /* pospone start of thread */
    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq != NULL);
    FMT_CHECK(workqueue_schedule_work(lp_wq, &work_item));

    return RT_EOK;
}