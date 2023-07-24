/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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

#include <INS.h>

#include "hal/serial/serial.h"
#include "nlink_linktrack.h"
#include "nlink_linktrack_tagframe0.h"

#define EVENT_NLINK_UPDATE (1 << 0)
#define DATA_SIZE          128

MCN_DECLARE(external_pos);

typedef enum {
    NLINK_START = 0,
    NLINK_PAYLOAD,
    NLINK_CS
} NLINK_State;

static rt_device_t dev;
static rt_thread_t thread;
static struct rt_event event;
static uint8_t frame_data[DATA_SIZE];

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_NLINK_UPDATE);
}

static bool parse_package(uint8_t c)
{
    static NLINK_State state;
    static uint8_t recv_len;
    bool cmplt = false;

    switch (state) {
    case NLINK_START:
        if (c == 0x55) {
            frame_data[recv_len++] = c;
            state++;
        }
        break;
    case NLINK_PAYLOAD:
        if (recv_len < DATA_SIZE) {
            frame_data[recv_len++] = c;
        }

        if (recv_len >= DATA_SIZE) {
            recv_len = 0;
            cmplt = true;
            state = NLINK_START;
        }
        break;
    default:
        state = NLINK_START;
        break;
    }

    return cmplt;
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_NLINK_UPDATE;
    uint8_t c;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 10, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_NLINK_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if (parse_package(c) == true) {
                    if (g_nlt_tagframe0.UnpackData(frame_data, DATA_SIZE)) {
                        nlt_tagframe0_result_t* result = &g_nlt_tagframe0.result;
                        External_Pos_Bus external_pos_report = { 0 };

                        external_pos_report.timestamp = systime_now_ms();
                        external_pos_report.x = result->pos_3d[0];
                        external_pos_report.y = -result->pos_3d[1];
                        external_pos_report.z = -result->pos_3d[2];

                        if (result->pos_3d[0] == 1.0f && result->pos_3d[1] == 1.0f && result->pos_3d[2] == 1.0f
                            && result->vel_3d[0] == 0.0f && result->vel_3d[1] == 0.0f && result->vel_3d[2] == 0.0f) {
                            external_pos_report.field_valid = 0;
                        } else {
                            external_pos_report.field_valid = 1; /* xy valid, uwb z is not stable */
                        }

                        /* publish external position */
                        mcn_publish(MCN_HUB(external_pos), &external_pos_report);
                    }
                }
            }
        }
    }
}

rt_err_t drv_nlink_linktrack_init(const char* uart_dev_name)
{
    rt_uint16_t flag = RT_DEVICE_OFLAG_RDONLY;

    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    /* if device support DMA, then use it */
    if (dev->flag & RT_DEVICE_FLAG_DMA_RX) {
        flag |= RT_DEVICE_FLAG_DMA_RX;
    } else {
        flag |= RT_DEVICE_FLAG_INT_RX;
    }

    /* open device */
    if (rt_device_open(dev, flag) != RT_EOK) {
        printf("nlink fail to open device!\n");
        return RT_ERROR;
    }

    /* config baudrate */
    serial_dev_t serial_dev = (serial_dev_t)dev;
    struct serial_configure pconfig = serial_dev->config;
    pconfig.baud_rate = 230400; /* too high baudrate would cause data lost */
    if (rt_device_control(&serial_dev->parent, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
        printf("nlink config baudrate failed!\n");
        return RT_ERROR;
    }

    thread = rt_thread_create("nlink", thread_entry, RT_NULL, 4 * 1024, 7, 1);

    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_event_init(&event, "nlink", RT_IPC_FLAG_FIFO));

    RT_CHECK(rt_device_set_rx_indicate(dev, rx_ind_cb));

    RT_CHECK(rt_thread_startup(thread));

    return RT_EOK;
}
