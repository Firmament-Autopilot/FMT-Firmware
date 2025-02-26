/******************************************************************************
 * Copyright 2025 The Firmament Authors. All Rights Reserved.
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
#include "module/sensor/sensor_hub.h"
#include "protocol/nlink/nlink_tofsense_frame0.h"
#include "tofsense.h"

#define DATA_SIZE 16

MCN_DECLARE(sensor_rangefinder);

typedef enum {
    NLINK_HEADER = 0,
    NLINK_MARK,
    NLINK_PAYLOAD,
    NLINK_CS
} NLINK_State;

static rt_device_t dev;
static rt_thread_t thread;
static uint8_t frame_data[DATA_SIZE];

static bool parse_package(uint8_t c)
{
    static NLINK_State state = NLINK_HEADER;
    static uint8_t recv_len;
    static uint8_t crc;
    bool cmplt = false;

    switch (state) {
    case NLINK_HEADER:
        if (c == 0x57) {
            recv_len = 0;
            crc = 0;

            frame_data[recv_len++] = c;
            crc += c;
            state++;
        }
        break;
    case NLINK_MARK:
        if (c == 0x00) {
            frame_data[recv_len++] = c;
            crc += c;
            state++;
        } else {
            state = NLINK_HEADER;
        }
        break;
    case NLINK_PAYLOAD:
        if (recv_len < (DATA_SIZE - 1)) {
            frame_data[recv_len++] = c;
            crc += c;
        }

        if (recv_len >= (DATA_SIZE - 1)) {
            state++;
        }
        break;
    case NLINK_CS:
        if (crc == c) {
            frame_data[recv_len++] = c;
            cmplt = true;
        }
        state = NLINK_HEADER;
        break;
    default:
        state = NLINK_HEADER;
        break;
    }

    return cmplt;
}

static void thread_entry(void* args)
{
    uint8_t c;
    rf_data_t rf_report;

    while (1) {
        while (rt_device_read(dev, RT_WAITING_FOREVER, &c, 1) > 0) {
            if (parse_package(c) == true) {
                if (g_nts_frame0.UnpackData(frame_data, DATA_SIZE)) {
                    rf_report.timestamp_ms = systime_now_ms();
                    rf_report.distance_m = g_nts_frame0.result.dis_status > 0 ? g_nts_frame0.result.dis : -1.0f;

                    mcn_publish(MCN_HUB(sensor_rangefinder), &rf_report);
                }
            }
        }
    }
}

rt_err_t drv_tofsense_init(const char* uart_dev_name)
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
        printf("tofsense fail to open device!\n");
        return RT_ERROR;
    }

    /* config baudrate */
    serial_dev_t serial_dev = (serial_dev_t)dev;
    struct serial_configure pconfig = serial_dev->config;
    pconfig.baud_rate = 921600; /* device default baudrate is 921600 */
    if (rt_device_control(&serial_dev->parent, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
        printf("tofsense config baudrate failed!\n");
        return RT_ERROR;
    }

    thread = rt_thread_create("tofsense", thread_entry, RT_NULL, 4 * 1024, 7, 1);
    RT_ASSERT(thread != NULL);

    RT_CHECK(rt_thread_startup(thread));

    return RT_EOK;
}
