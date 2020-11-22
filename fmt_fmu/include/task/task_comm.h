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

#ifndef __TASK_COMM_H__
#define __TASK_COMM_H__

#include <firmament.h>
#include <mavlink.h>

#include "module/mavproxy/mavlink_status.h"
#include "module/utils/ringbuffer.h"

// #define MAX_PERIOD_MSG_QUEUE_SIZE    20
// #define MAX_IMMEDIATE_MSG_QUEUE_SIZE 10

// #define EVENT_MAVPROXY_UPDATE    (1 << 0)
// #define EVENT_MAVCONSOLE_TIMEOUT (1 << 1)
// #define EVENT_SEND_ALL_PARAM     (1 << 2)

// typedef struct {
//     uint8_t msgid;
//     uint8_t enable;
//     uint16_t period;
//     uint32_t time_stamp;
//     void (*msg_pack_cb)(mavlink_message_t* msg_t);
// } MAV_PeriodMsg;

// typedef struct {
//     MAV_PeriodMsg queue[MAX_PERIOD_MSG_QUEUE_SIZE];
//     uint16_t size;
//     uint16_t index;
// } MAV_PeriodMsg_Queue;

// typedef struct {
//     mavlink_message_t queue[MAX_IMMEDIATE_MSG_QUEUE_SIZE];
//     uint16_t head;
//     uint16_t tail;
// } MAV_ImmediateMsg_Queue;

extern ringbuffer* _mav_serial_rb;
extern uint8_t _mav_dev_chan;

fmt_err task_comm_init(void);
// mavlink_system_t mavproxy_get_system(void);
void mavproxy_rx_entry(void* param);
void task_comm_entry(void* parameter);
// uint8_t mavproxy_send_immediate_msg(const mavlink_message_t* msg, uint8_t sync);
// uint8_t mavproxy_register_period_msg(uint8_t msgid, uint16_t period_ms, void (*msg_pack_cb)(mavlink_message_t* msg_t), uint8_t enable);
// uint8_t mavproxy_msg_serial_control_send(uint8_t* data, uint8_t count);
// uint16_t mavproxy_msg_serial_control_read(uint8_t* data, uint16_t size);
// void mavproxy_proc_command(mavlink_command_long_t* command, mavlink_message_t* msg);
// void mavproxy_process_serial_control_msg(const mavlink_serial_control_t* serial_control);
// void mavproxy_send_event(uint32_t event_set);
// void mavlink_console_process_rx_msg(const mavlink_serial_control_t* serial_control);

#endif
