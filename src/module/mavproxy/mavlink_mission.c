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

#include "module/mavproxy/mavproxy.h"

static uint16_t wp_cnt;
static uint16_t wp_seq;

static void send_mission_count(uint8_t sysid, uint8_t compid, uint16_t count, MAV_MISSION_TYPE mission_type)
{
    mavlink_system_t mavsys = mavproxy_get_system();
    mavlink_message_t msg;
    mavlink_mission_count_t wpc;

    wpc.target_system = sysid;
    wpc.target_component = compid;
    wpc.count = count;
    wpc.mission_type = mission_type;

    mavlink_msg_mission_count_encode(mavsys.sysid, mavsys.compid, &msg, &wpc);

    mavproxy_send_immediate_msg(&msg, true);
}

static void send_mission_request(uint8_t sysid, uint8_t compid, uint16_t seq)
{
    mavlink_system_t mavsys = mavproxy_get_system();
    mavlink_message_t msg;
    mavlink_mission_count_t 

    mavlink_msg_mission_request_int_encode(mavsys.sysid, mavsys.compid, &msg, const mavlink_mission_request_int_t* mission_request_int);
}

void handle_mission_message(mavlink_message_t* msg)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
        send_mission_count(msg->sysid, msg->compid, 0, MAV_MISSION_TYPE_MISSION);
        break;
    case MAVLINK_MSG_ID_MISSION_COUNT: {
        mavlink_mission_count_t wpc;

        mavlink_msg_mission_count_decode(msg, &wpc);

        wp_cnt = wpc.count;
        wp_seq = 0;

        /* start to download waypoint from GCS */
        printf("mission count:%d\n", wpc.count);
    } break;
    case MAVLINK_MSG_ID_MISSION_REQUEST_INT:
        break;
    case MAVLINK_MSG_ID_MISSION_ITEM_INT:
        break;
    default:
        break;
    }
}