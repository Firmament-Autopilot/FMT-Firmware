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
#ifndef MAVPROXY_H__
#define MAVPROXY_H__

#include <firmament.h>
#include <mavlink.h>

#include "module/mavproxy/mavlink_console.h"
#include "module/mavproxy/mavlink_param.h"
#include "module/mavproxy/mavlink_status.h"
#include "module/mavproxy/mavproxy_cmd.h"
#include "module/mavproxy/mavproxy_dev.h"
#include "module/mavproxy/mavlink_mission.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EVENT_MAVPROXY_UPDATE    (1 << 0)
#define EVENT_MAVCONSOLE_TIMEOUT (1 << 1)
#define EVENT_SEND_ALL_PARAM     (1 << 2)

typedef bool (*msg_pack_cb_t)(mavlink_message_t* msg_t);

fmt_err_t mavproxy_init(void);
void mavproxy_loop(void);
mavlink_system_t mavproxy_get_system(void);
fmt_err_t mavproxy_set_channel(uint8_t chan);
fmt_err_t mavproxy_send_event(uint32_t event_set);
fmt_err_t mavproxy_send_immediate_msg(const mavlink_message_t* msg, bool sync);
fmt_err_t mavproxy_register_period_msg(uint8_t msgid, uint16_t period_ms, msg_pack_cb_t msg_pack_cb, bool auto_start);

#ifdef __cplusplus
}
#endif

#endif
