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

#include "module/obc/mavobc.h"

#define EVENT_MAV_RX (1 << 0)

static char thread_mavobc_rx_stack[4096];
static struct rt_thread thread_mavobc_rx_handle;
static struct rt_event mavobc_rx_event;
static void (*mavlink_msg_handler)(mavlink_message_t* msg, mavlink_system_t system);

static fmt_err_t mavobc_rx_ind(uint32_t size)
{
    /* wakeup thread to handle received data */
    rt_err_t rt_err = rt_event_send(&mavobc_rx_event, EVENT_MAV_RX);

    return (rt_err == RT_EOK) ? FMT_EOK : FMT_ERROR;
}

static fmt_err_t handle_mavlink_msg(mavlink_message_t* msg, mavlink_system_t system)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
        /* do nothing */
        break;

    case MAVLINK_MSG_ID_SYSTEM_TIME:
        /* do nothing */
        break;
    }

    if (mavlink_msg_handler != NULL) {
        mavlink_msg_handler(msg, system);
    }

    return FMT_EOK;
}

static void mavobc_rx_entry(void* param)
{
    mavlink_message_t msg;
    mavlink_status_t mav_status;
    mavlink_system_t mavlink_system;
    char byte;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAV_RX;
    rt_err_t rt_err;

    mavlink_system = mavobc_get_system();

    while (1) {
        /* wait event happen */
        rt_err = rt_event_recv(&mavobc_rx_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_MAV_RX) {
                while (mavobc_dev_read(&byte, 1, 0)) {
                    /* decode mavlink package */
                    if (mavlink_parse_char(0, byte, &msg, &mav_status) == 1) {
                        handle_mavlink_msg(&msg, mavlink_system);
                    }
                }
            }
        }
    }
}

fmt_err_t mavobc_monitor_register_handler(void (*handler)(mavlink_message_t*, mavlink_system_t))
{
    if (mavlink_msg_handler != NULL) {
        return FMT_EFULL;
    }

    mavlink_msg_handler = handler;

    return FMT_EOK;
}

fmt_err_t mavobc_monitor_create(void)
{
    rt_err_t res;

    res = rt_thread_init(&thread_mavobc_rx_handle,
                         "mavobc_rx",
                         mavobc_rx_entry,
                         RT_NULL,
                         &thread_mavobc_rx_stack[0],
                         sizeof(thread_mavobc_rx_stack),
                         13,
                         5);

    if (res != RT_EOK) {
        printf("mavobc rx thread create fail\n");
        return FMT_ERROR;
    }

    if (rt_event_init(&mavobc_rx_event, "mavobc_rx", RT_IPC_FLAG_FIFO) != RT_EOK) {
        printf("mavobc rx event create fail\n");
        return FMT_ERROR;
    }

    /* set mavobc device rx indicator */
    mavobc_dev_set_rx_indicate(mavobc_rx_ind);
    /* start rx thread */
    rt_thread_startup(&thread_mavobc_rx_handle);

    return FMT_EOK;
}