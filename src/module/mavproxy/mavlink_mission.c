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

#include "module/file_manager/file_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sysio/mission_data.h"

#undef LOG_TAG
#define LOG_TAG "MavMission"

static uint16_t wp_cnt;
static uint16_t wp_seq;
static int wp_fd = -1;

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
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
}

static void send_mission_item(uint8_t sysid, uint8_t compid, uint16_t seq)
{
    mavlink_system_t mavsys = mavproxy_get_system();
    mavlink_message_t msg;
    mavlink_mission_item_int_t mav_mission_item;
    struct mission_item* mission_item;

    mission_item = get_mission_item(seq);
    if (mission_item == NULL) {
        LOG_E("can't find mission item with seq %d", seq);
        return;
    }

    if (mission_item->seq != seq) {
        LOG_E("mission item seq not matched! expect %d, current %d", seq, mission_item->seq);
        return;
    }

    mav_mission_item.param1 = mission_item->param1;
    mav_mission_item.param2 = mission_item->param2;
    mav_mission_item.param3 = mission_item->param3;
    mav_mission_item.param4 = mission_item->param4;
    mav_mission_item.x = mission_item->x;
    mav_mission_item.y = mission_item->y;
    mav_mission_item.z = mission_item->z;
    mav_mission_item.seq = mission_item->seq;
    mav_mission_item.command = mission_item->command;
    mav_mission_item.target_system = sysid;
    mav_mission_item.target_component = compid;
    mav_mission_item.frame = mission_item->frame;
    mav_mission_item.current = mission_item->current;
    mav_mission_item.autocontinue = mission_item->autocontinue;
    mav_mission_item.mission_type = mission_item->mission_type;

    mavlink_msg_mission_item_int_encode(mavsys.sysid, mavsys.compid, &msg, &mav_mission_item);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
}

static void send_mission_request(uint8_t sysid, uint8_t compid, uint16_t seq)
{
    mavlink_system_t mavsys = mavproxy_get_system();
    mavlink_message_t msg;
    mavlink_mission_request_int_t mission_req;

    mission_req.seq = seq;
    mission_req.target_system = sysid;
    mission_req.target_component = compid;
    mission_req.mission_type = MAV_MISSION_TYPE_MISSION;

    mavlink_msg_mission_request_int_encode(mavsys.sysid, mavsys.compid, &msg, &mission_req);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
}

static void send_mission_ack(uint8_t sysid, uint8_t compid, uint8_t type)
{
    mavlink_system_t mavsys = mavproxy_get_system();
    mavlink_message_t msg;
    mavlink_mission_ack_t mission_ack;

    mission_ack.target_system = sysid;
    mission_ack.target_component = compid;
    mission_ack.type = type;
    mission_ack.mission_type = MAV_MISSION_TYPE_MISSION;

    mavlink_msg_mission_ack_encode(mavsys.sysid, mavsys.compid, &msg, &mission_ack);
    mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, true);
}

static void handle_message_mission_clear_all(mavlink_message_t* msg)
{
    mavlink_mission_clear_all_t mission_clear_all;

    mavlink_msg_mission_clear_all_decode(msg, &mission_clear_all);

    if (mission_clear_all.mission_type == MAV_MISSION_TYPE_MISSION) {
        if (clear_mission_data(MISSION_FILE) == FMT_EOK) {
            /* after cleared, reset the mission data */
            mission_reset();
            LOG_I("mission data cleared.");
            /* send accepted ack */
            send_mission_ack(msg->sysid, msg->compid, MAV_MISSION_ACCEPTED);
        } else {
            send_mission_ack(msg->sysid, msg->compid, MAV_MISSION_ERROR);
        }
    }
}

static void handle_message_mission_request_list(mavlink_message_t* msg)
{
    send_mission_count(msg->sysid, msg->compid, get_mission_count(), MAV_MISSION_TYPE_MISSION);
}

static void handle_message_mission_request_int(mavlink_message_t* msg)
{
    mavlink_mission_request_int_t mission_req_int;

    mavlink_msg_mission_request_int_decode(msg, &mission_req_int);
    send_mission_item(msg->sysid, msg->compid, mission_req_int.seq);
}

static void handle_message_mission_count(mavlink_message_t* msg)
{
    mavlink_mission_count_t mission_cnt;

    /* decode mission count */
    mavlink_msg_mission_count_decode(msg, &mission_cnt);

    /* save the mission count and request the first mission item */
    wp_cnt = mission_cnt.count;
    wp_seq = 0;

    if (wp_cnt > 0) {
        if (wp_fd >= 0) {
            close(wp_fd);
            wp_fd = -1;
        }
        /* open mission file */
        wp_fd = open(MISSION_FILE, O_CREAT | O_WRONLY | O_TRUNC);
        if (wp_fd < 0) {
            LOG_E("fail to open mission file %s", MISSION_FILE);
        }
        /* write mission count to the first line */
        fm_fprintf(wp_fd, "%u\n", wp_cnt);
        /* start to download waypoint from GCS */
        send_mission_request(msg->sysid, msg->compid, wp_seq);
    }
}

static void handle_message_mission_item(mavlink_message_t* msg)
{
    mavlink_mission_item_int_t mission_item_int;

    if (wp_fd < 0) {
        /* no valid mission file */
        return;
    }

    /* decode ission item */
    mavlink_msg_mission_item_int_decode(msg, &mission_item_int);

    if (mission_item_int.seq != wp_seq) {
        /* out-of-sequence received, send the requested item again */
        send_mission_request(msg->sysid, msg->compid, wp_seq);
        /* drop the out-of-sequence item */
        return;
    }

    /* Mission file format:
     * <INDEX> <CURRENT WP> <COORD FRAME> <COMMAND> <PARAM1> <PARAM2> <PARAM3> <PARAM4> 
     * <PARAM5/X/LATITUDE> <PARAM6/Y/LONGITUDE> <PARAM7/Z/ALTITUDE> <AUTOCONTINUE> 
     */
    // fm_fprintf(wp_fd, "%d\t%u\t%u\t%u\t%f\t%f\t%f\t%f\t%d\t%d\t%f\t%d\n",
    fm_fprintf(wp_fd, "%hu\t%hhu\t%hhu\t%hu\t%f\t%f\t%f\t%f\t%ld\t%ld\t%f\t%hhu\n", mission_item_int.seq, mission_item_int.current, mission_item_int.frame, mission_item_int.command, mission_item_int.param1, mission_item_int.param2, mission_item_int.param3, mission_item_int.param4, mission_item_int.x, mission_item_int.y, mission_item_int.z, mission_item_int.autocontinue);

    /* check if we received all mission items */
    if (wp_seq + 1 >= wp_cnt) {
        LOG_I("mission data received with %u items", wp_cnt);

        close(wp_fd);
        wp_fd = -1;
        /* send ack with accepted result */
        send_mission_ack(msg->sysid, msg->compid, MAV_MISSION_ACCEPTED);
        /* load new mission data */
        if (load_mission_data(MISSION_FILE) == FMT_EOK) {
            LOG_I("mission data reloaded.");
            /* reset mission data when reloaded */
            mission_reset();
        } else {
            LOG_E("mission data reloaded fail.");
        }
    } else {
        /* request next item */
        wp_seq++;
        send_mission_request(msg->sysid, msg->compid, wp_seq);
    }
}

void handle_mission_message(mavlink_message_t* msg)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
        handle_message_mission_request_list(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_COUNT:
        handle_message_mission_count(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_REQUEST_INT:
        handle_message_mission_request_int(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_ITEM_INT:
        handle_message_mission_item(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_CLEAR_ALL:
        handle_message_mission_clear_all(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_ACK:
        /* do nothing here */
        break;
    default:
        break;
    }
}