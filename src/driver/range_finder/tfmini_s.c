/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "module/sensor/sensor_hub.h"
#include "module/workqueue/workqueue_manager.h"

#define EVENT_TFMINI_S_UPDATE (1 << 0)

MCN_DECLARE(sensor_rangefinder);

typedef enum {
    TFMINI_S_HEADER1 = 0,
    TFMINI_S_HEADER2,
    TFMINI_S_DIST_L,
    TFMINI_S_DIST_H,
    TFMINI_S_STRENGTH_L,
    TFMINI_S_STRENGTH_H,
    TFMINI_S_TEMP_L,
    TFMINI_S_TEMP_H,
    TFMINI_S_CHECKSUM
} TFMINI_S_State;

typedef struct {
    uint32_t timestamp;  // ms
    int16_t distance;    // distance of TFmini_S (0~2000)cm,
    int16_t strength;    // strength of the singal, 0~65535
    int16_t temperature; // t = temp/8-256
    uint8_t tof_status;  // tof status, 0:invalid 1:valid
} tfmini_s_data;

static rt_device_t dev;
static rt_thread_t thread;
static struct rt_event event;
static tfmini_s_data data;
static rf_data_t rf_report;

static void start_thread(void* parameter)
{
    RT_CHECK(rt_thread_startup(thread));
}

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_TFMINI_S_UPDATE);
}

static bool parse_package(uint8_t c)
{
    static TFMINI_S_State state = TFMINI_S_HEADER1;
    static uint8_t recv_len = 0;
    static uint8_t cs;
    bool cmplt = false;
    static uint8_t buf[6];

    // printf("state = %d  c = %02x \r\n", state, c);

    switch (state) {
    case TFMINI_S_HEADER1:
        if (c == 0x59) {
            cs = c;
            state++;
        }
        recv_len = 0;
        break;
    case TFMINI_S_HEADER2:
        if (c == 0x59) {
            cs += c;
            state++;
            rt_memset(buf, 0, 6);
        } else {
            state = TFMINI_S_HEADER1;
        }
        break;
    case TFMINI_S_DIST_L:
    case TFMINI_S_DIST_H:
    case TFMINI_S_STRENGTH_L:
    case TFMINI_S_STRENGTH_H:
    case TFMINI_S_TEMP_L:
    case TFMINI_S_TEMP_H:
        buf[recv_len] = c;
        cs += c;
        state++;
        recv_len++;
        break;

    case TFMINI_S_CHECKSUM:
        if (cs == c) {
            cmplt = true;
            data.timestamp = systime_now_ms();
            data.distance = (buf[1] << 8 | buf[0]);
            data.strength = (buf[3] << 8 | buf[2]);
            data.temperature = (buf[5] << 8 | buf[4]);

            if ((data.distance == -1) || (data.distance == -2) || (data.distance == -4)) {
                data.tof_status = 0;
            } else {
                data.tof_status = 1;
            }

        } else {
            printf("wrong cheksum:%x %x\n", cs, c);
        }
        state = TFMINI_S_HEADER1;
        break;
    default:
        state = TFMINI_S_HEADER1;
        break;
    }

    return cmplt;
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_TFMINI_S_UPDATE;
    uint8_t c;

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        printf("tfmini_s fail to open device!\n");
        return;
    }

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 10, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_TFMINI_S_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if (parse_package(c) == true) {
                    uint32_t time_now = systime_now_ms();

                    rf_report.timestamp_ms = time_now;

                    if (data.tof_status == 1) {
                        /* tof_status == 1 means tof valid */
                        rf_report.distance_m = data.distance * 0.01f;
                    } else {
                        /* negative value indicate range finder invalid */
                        rf_report.distance_m = -1;
                    }

                    /* publish tfmini_s data */
                    mcn_publish(MCN_HUB(sensor_rangefinder), &rf_report);

                    // printf("----mcn_publish  sensor_rangefinder~~~~~~ \n");
                }
            }
        }
    }
}

static struct WorkItem work_item = {
    .name = "tfmini_s",
    .period = 0,
    .schedule_time = 1000,
    .run = start_thread
};

rt_err_t tfmini_s_drv_init(const char* uart_dev_name)
{
    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    thread = rt_thread_create("tfmini_s", thread_entry, RT_NULL, 4 * 1024, 7, 1);

    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_event_init(&event, "tfmini_s", RT_IPC_FLAG_FIFO));

    RT_CHECK(rt_device_set_rx_indicate(dev, rx_ind_cb));

    /* pospone start of thread */
    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq != NULL);
    FMT_CHECK(workqueue_schedule_work(lp_wq, &work_item));

    return RT_EOK;
}