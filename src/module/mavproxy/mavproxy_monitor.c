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

#include "module/mavproxy/mavproxy.h"
#include "module/utils/list.h"

#define EVENT_MAV_RX (1 << 0)

struct mavlink_msg_handler_func {
    fmt_err_t (*mavlink_msg_handler)(mavlink_message_t* msg, mavlink_system_t this_system);
    struct list_head link;
};

static LIST_HEAD(__mavlink_msg_chan0_handler_head);
static LIST_HEAD(__mavlink_msg_chan1_handler_head);

static char thread_mavlink_rx_stack[8192];
static struct rt_thread thread_mavlink_rx_handle;
static struct rt_event mav_rx_event;

static fmt_err_t mavproxy_rx_ind(uint32_t size)
{
    /* wakeup thread to handle received data */
    rt_err_t rt_err = rt_event_send(&mav_rx_event, EVENT_MAV_RX);

    return (rt_err == RT_EOK) ? FMT_EOK : FMT_ERROR;
}

static fmt_err_t handle_mavlink_msg(uint8_t chan, mavlink_message_t* msg, mavlink_system_t this_system)
{
    struct mavlink_msg_handler_func* node;

    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
        /* do nothing */
        break;
    }

    if (chan == 0) {
        list_for_each_entry(node, struct mavlink_msg_handler_func, &__mavlink_msg_chan0_handler_head, link)
        {
            /* invoke registered mavlink message handler */
            FMT_TRY(node->mavlink_msg_handler(msg, this_system));
        }
    } else {
        list_for_each_entry(node, struct mavlink_msg_handler_func, &__mavlink_msg_chan1_handler_head, link)
        {
            /* invoke registered mavlink message handler */
            FMT_TRY(node->mavlink_msg_handler(msg, this_system));
        }
    }

    return FMT_EOK;
}

static void mavproxy_rx_entry(void* param)
{
    mavlink_message_t msg[2];
    mavlink_status_t mav_status[2];
    mavlink_system_t mavlink_system;
    char byte;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAV_RX;
    rt_err_t rt_err;

    mavlink_system = mavproxy_get_system();

    while (1) {
        /* wait event happen */
        rt_err = rt_event_recv(&mav_rx_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_MAV_RX) {
                for (uint8_t chan = 0; chan < MAVPROXY_CHAN_NUM; chan++) {
                    while (mavproxy_dev_read(chan, &byte, 1, 0)) {
                        /* decode mavlink package */
                        if (mavlink_parse_char(0, byte, &msg[chan], &mav_status[chan]) == 1) {
                            handle_mavlink_msg(chan, &msg[chan], mavlink_system);
                        }
                    }
                }
            }
        }
    }
}

fmt_err_t mavproxy_monitor_register_handler(uint8_t chan, fmt_err_t (*handler)(mavlink_message_t*, mavlink_system_t))
{
    struct mavlink_msg_handler_func* node;

    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    if (handler == NULL) {
        return FMT_EINVAL;
    }

    node = (struct mavlink_msg_handler_func*)rt_malloc(sizeof(struct mavlink_msg_handler_func));
    if (node == NULL) {
        return FMT_ENOMEM;
    }

    INIT_LIST_HEAD(&node->link);
    node->mavlink_msg_handler = handler;

    if (chan == 0) {
        list_add_tail(&node->link, &__mavlink_msg_chan0_handler_head);
    } else {
        list_add_tail(&node->link, &__mavlink_msg_chan1_handler_head);
    }

    return FMT_EOK;
}

fmt_err_t mavproxy_monitor_deregister_handler(uint8_t chan, fmt_err_t (*handler)(mavlink_message_t*, mavlink_system_t))
{
    struct mavlink_msg_handler_func* node;

    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    if (handler == NULL) {
        return FMT_EINVAL;
    }

    if (chan == 0) {
        list_for_each_entry(node, struct mavlink_msg_handler_func, &__mavlink_msg_chan0_handler_head, link)
        {
            if (node->mavlink_msg_handler == handler) {
                list_del(&node->link);
                rt_free(node);
                return FMT_EOK;
            }
        }
    } else {
        list_for_each_entry(node, struct mavlink_msg_handler_func, &__mavlink_msg_chan1_handler_head, link)
        {
            if (node->mavlink_msg_handler == handler) {
                list_del(&node->link);
                rt_free(node);
                return FMT_EOK;
            }
        }
    }

    return FMT_EOK;
}

fmt_err_t mavproxy_monitor_create(void)
{
    rt_err_t res;

    res = rt_thread_init(&thread_mavlink_rx_handle,
                         "mav_rx",
                         mavproxy_rx_entry,
                         RT_NULL,
                         &thread_mavlink_rx_stack[0],
                         sizeof(thread_mavlink_rx_stack),
                         MAVLINK_RX_THREAD_PRIORITY,
                         5);

    if (res != RT_EOK) {
        console_printf("mav rx thread create fail\n");
        return FMT_ERROR;
    }

    if (rt_event_init(&mav_rx_event, "mav_rx", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("mav rx event create fail\n");
        return FMT_ERROR;
    }

    /* set mavproxy device rx indicator */
    for (uint8_t chan = 0; chan < MAVPROXY_CHAN_NUM; chan++) {
        mavproxy_dev_set_rx_indicate(chan, mavproxy_rx_ind);
    }

    /* start rx thread */
    RT_TRY(rt_thread_startup(&thread_mavlink_rx_handle));

    return FMT_EOK;
}