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

#include "nlink_linktrack.h"
#include "hal/serial/serial.h"

#define EVENT_NLINK_UPDATE (1 << 0)

static rt_device_t dev;
static rt_thread_t thread;
static struct rt_event event;

static rt_err_t rx_ind_cb(rt_device_t dev, rt_size_t size)
{
    return rt_event_send(&event, EVENT_NLINK_UPDATE);
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_NLINK_UPDATE;
    uint8_t c;

    uint16_t cnt = 0;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, 10, &recv_set);

        if ((res == RT_EOK && (recv_set & EVENT_NLINK_UPDATE)) || res == -RT_ETIMEOUT) {
            while (rt_device_read(dev, 0, &c, 1) > 0) {
                if(c == 0x55) {
                    printf(" [%d]\n", cnt);
                    cnt = 0;
                }
                printf("%x ", c);
                cnt++;
            }
        }
    }
}

rt_err_t drv_nlink_linktrack_init(const char* uart_dev_name)
{
    dev = rt_device_find(uart_dev_name);

    RT_ASSERT(dev != NULL);

    /* open device */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDONLY | RT_DEVICE_FLAG_INT_RX) != RT_EOK) {
        printf("nlink fail to open device!\n");
        return RT_ERROR;
    }

    /* config baudrate */
    serial_dev_t serial_dev = (serial_dev_t)dev;
    struct serial_configure pconfig = serial_dev->config;
    pconfig.baud_rate = 230400; /* to high baudrate would cause data lost */
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
