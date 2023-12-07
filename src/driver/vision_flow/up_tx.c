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

// This driver apply for upixel optical_flow and rangefinder module up-t1, up-t1 plus and up-t2 with UP protocol

#include <firmament.h>

#include "hal/serial/serial.h"
#include "module/sensor/sensor_hub.h"
#include "module/workqueue/workqueue_manager.h"

#define EVENT_UP_TX_UPDATE (1 << 0)
#define DATA_SIZE          sizeof(up_tx_data)

MCN_DECLARE(sensor_optflow);
MCN_DECLARE(sensor_rangefinder);

typedef enum {
    UP_START_1 = 0,
    UP_START_2,
    UP_DATA,
    UP_CHECK,
    UP_END
} UP_State;

typedef struct {
    int16_t  flow_x_int;
    int16_t  flow_y_int;
    uint16_t timespan_us;
    uint16_t distance_mm;
    uint8_t  flow_valid;
    uint8_t  tof_confidence;
} up_tx_data;

static rt_device_t     dev;
static rt_thread_t     thread;
static struct rt_event event;
static up_tx_data      up_data;
static optflow_data_t  optflow_report;
static rf_data_t       rf_report;

static void start_thread(void* parameter)
{
    RT_CHECK(rt_thread_startup(thread));
}

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_UP_TX_UPDATE);
}

static int16_t up_parse_char(uint8_t ch)
{
    int16_t        ret   = -1;
    static int     state = UP_START_1, cnt = 0;
    static uint8_t xor_calc = 0;
    static uint8_t xor_recv = 0;

    switch (state) {
    case UP_START_1:
        if (ch == 0xFE)
            state = UP_START_2;
        break;
    case UP_START_2:
        if (ch == 0x0A) {
            state    = UP_DATA;
            cnt      = 0;
            xor_calc = 0x00;
        } else {
            state = UP_START_1;
        }
        break;
    case UP_DATA:
        ((uint8_t*)&up_data)[cnt++] = ch;
        xor_calc ^= ch;
        if (cnt >= 10) {
            state = UP_CHECK;
            cnt   = 0;
        }
        break;
    case UP_CHECK:
        state    = UP_END;
        xor_recv = ch;
        break;
    case UP_END:
        if (ch == 0x55) {
            if (xor_recv == xor_calc)
                ret = 0;
        }
        state = UP_START_1;
        break;
    default:
        break;
    }

    return ret;
}

static void thread_entry(void* args)
{
    rt_err_t    res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_UP_TX_UPDATE;
    uint8_t     c;

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        printf("up-tx fail to open device!\n");
        return;
    }

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 10, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_UP_TX_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if (up_parse_char(c) >= 0) {
                    uint32_t time_now = systime_now_ms();

                    rf_report.timestamp_ms      = time_now;
                    optflow_report.timestamp_ms = time_now;

                    if (up_data.tof_confidence >= 50) {
                        rf_report.distance_m = up_data.distance_mm * 0.001f;

                        /* actual optical flow velocity = raw_vel * distance, we just publish raw data,
                            leave it to upper layer to handle it. */
                        optflow_report.vx_mPs  = -100.0f * up_data.flow_y_int / up_data.timespan_us;
                        optflow_report.vy_mPs  = 100.0f * up_data.flow_x_int / up_data.timespan_us;
                        optflow_report.quality = up_data.flow_valid == 0xF5 ? 100 : 0;
                    } else {
                        /* negative value indicate range finder invalid */
                        rf_report.distance_m = -1;

                        optflow_report.vx_mPs  = 0;
                        optflow_report.vy_mPs  = 0;
                        optflow_report.quality = 0;
                    }

                    /* publish mtf_01 data */
                    mcn_publish(MCN_HUB(sensor_optflow), &optflow_report);
                    mcn_publish(MCN_HUB(sensor_rangefinder), &rf_report);
                }
            }
        }
    }
}

static struct WorkItem work_item = {
    .name          = "up-tx",
    .period        = 0,
    .schedule_time = 1000,
    .run           = start_thread
};

rt_err_t drv_up_tx_init(const char* uart_dev_name)
{
    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    serial_dev_t serial_dev = (serial_dev_t)dev;
    /* console device configuration */
    struct serial_configure pconfig = serial_dev->config;
    /* the default baudrate for up-tx device is 115200 */
    pconfig.baud_rate = 115200;
    if (rt_device_control(&serial_dev->parent, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
        printf("fail to config uptx baudrate\n");
        return RT_ERROR;
    }

    thread = rt_thread_create("up-tx", thread_entry, RT_NULL, 2 * 1024, 7, 1);

    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_event_init(&event, "up-tx", RT_IPC_FLAG_FIFO));

    RT_CHECK(rt_device_set_rx_indicate(dev, rx_ind_cb));

    /* pospone start of thread */
    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");
    RT_ASSERT(lp_wq != NULL);
    FMT_CHECK(workqueue_schedule_work(lp_wq, &work_item));

    return RT_EOK;
}