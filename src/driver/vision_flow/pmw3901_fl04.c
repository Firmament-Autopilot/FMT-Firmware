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

#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_dev.h"
#include "module/sensor/sensor_hub.h"
#include "module/workqueue/workqueue_manager.h"

#define EVENT_FL04_UPDATE (1 << 0)

MCN_DECLARE(sensor_optflow);
MCN_DECLARE(sensor_rangefinder);

typedef enum {
    FL04_START = 0,
    FL04_DEVID,
    FL04_SYSID,
    FL04_MSGID,
    FL04_SEQ,
    FL04_LEN,
    FL04_DATA,
    FL04_CS
} FL04_State;

typedef struct {
    uint32_t timestamp;    // ms
    int16_t vx;            // vision flow vx cm/s at 1m
    int16_t vy;            // vision flow vy cm/s at 1m
    uint8_t quality;       // vision flow quality
    uint8_t status;        // vision flow staus, 0:invalid 1:valid
    uint16_t tof_distance; // tof measured distance in mm
    uint8_t tof_strength;  // tof strength, not used
    uint8_t tof_status;    // tof status, 0:invalid 1:valid
    uint16_t reserved;
} fl04_data;

static rt_device_t dev;
static rt_thread_t thread;
static struct rt_event event;
static fl04_data data;
static uint8_t* pdata = (uint8_t*)&data;
static optflow_data_t optflow_report;
static rf_data_t rf_report;

static void start_thread(void* parameter)
{
    RT_CHECK(rt_thread_startup(thread));
}

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_FL04_UPDATE);
}

static bool parse_package(uint8_t c)
{
    static FL04_State state;
    static uint8_t recv_len;
    static uint8_t cs;
    bool cmplt = false;

    switch (state) {
    case FL04_START:
        if (c == 0xDF) {
            cs = c;
            state++;
        }
        break;
    case FL04_DEVID:
        if (c == 0x14) {
            cs += c;
            state++;
        } else {
            state = FL04_START;
        }
        break;
    case FL04_SYSID:
        if (c == 0x00) {
            cs += c;
            state++;
        } else {
            state = FL04_START;
        }
        break;
    case FL04_MSGID:
        if (c == 0x55) {
            cs += c;
            state++;
        } else {
            state = FL04_START;
        }
        break;
    case FL04_SEQ:
        cs += c;
        /* sequence is in range of 0x00~0xFF, no need check */
        state++;
        break;
    case FL04_LEN:
        if (c == 0x12) {
            cs += c;
            state++;
        } else {
            state = FL04_START;
        }
        break;
    case FL04_DATA:
        if (recv_len < 14) {
            pdata[recv_len] = c;
        }
        recv_len++;
        cs += c;
        if (recv_len >= 0x12) {
            recv_len = 0;
            state++;
        }

        break;
    case FL04_CS:
        if (cs == c) {
            cmplt = true;
        } else {
            printf("wrong cheksum:%x %x\n", cs, c);
        }
        state = FL04_START;
        break;
    default:
        state = FL04_START;
        break;
    }

    return cmplt;
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_FL04_UPDATE;
    uint8_t c;

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        printf("fl04 fail to open device!\n");
        return;
    }

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 10, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_FL04_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if (parse_package(c) == true) {
                    uint32_t time_now = systime_now_ms();

                    rf_report.timestamp_ms = time_now;
                    optflow_report.timestamp_ms = time_now;

                    if (data.tof_status == 1) {
                        /* tof_status == 1 means tof valid */
                        rf_report.distance_m = data.tof_distance * 0.001f;
                    } else {
                        /* negative value indicate range finder invalid */
                        rf_report.distance_m = -1;
                    }

                    /* actual optical flow velocity = raw_vel * distance, we just publish raw data,
                           leave it to upper layer to handle it. */
                    optflow_report.vx_mPs = data.vx * 0.01f;
                    optflow_report.vy_mPs = data.vy * 0.01f;
                    optflow_report.quality = data.quality * data.status;

                    /* publish fl04 data */
                    mcn_publish(MCN_HUB(sensor_optflow), &optflow_report);
                    mcn_publish(MCN_HUB(sensor_rangefinder), &rf_report);
                }
            }
        }
    }
}

static struct WorkItem work_item = {
    .name = "fl04",
    .period = 0,
    .schedule_time = 1000,
    .run = start_thread
};

rt_err_t pmw3901_fl04_drv_init(const char* uart_dev_name)
{
    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    thread = rt_thread_create("fl04", thread_entry, RT_NULL, 8 * 1024, 7, 1);

    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_event_init(&event, "fl04", RT_IPC_FLAG_FIFO));

    RT_CHECK(rt_device_set_rx_indicate(dev, rx_ind_cb));

    /* pospone start of thread */
    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq != NULL);
    FMT_CHECK(workqueue_schedule_work(lp_wq, &work_item));

    return RT_EOK;
}