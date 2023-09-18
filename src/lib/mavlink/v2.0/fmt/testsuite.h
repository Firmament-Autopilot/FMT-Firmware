/** @file
 *    @brief MAVLink comm protocol testsuite generated from fmt.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef FMT_TESTSUITE_H
#define FMT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_fmt(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_fmt(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_fmt_pilot_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FMT_PILOT_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fmt_pilot_cmd_t packet_in = {
        963497464,45.0,73.0,101.0,129.0,963498504,963498712,963498920
    };
    mavlink_fmt_pilot_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.ls_lr = packet_in.ls_lr;
        packet1.ls_ud = packet_in.ls_ud;
        packet1.rs_lr = packet_in.rs_lr;
        packet1.rs_ud = packet_in.rs_ud;
        packet1.mode = packet_in.mode;
        packet1.command_1 = packet_in.command_1;
        packet1.command_2 = packet_in.command_2;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fmt_pilot_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_pack(system_id, component_id, &msg , packet1.timestamp , packet1.ls_lr , packet1.ls_ud , packet1.rs_lr , packet1.rs_ud , packet1.mode , packet1.command_1 , packet1.command_2 );
    mavlink_msg_fmt_pilot_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.ls_lr , packet1.ls_ud , packet1.rs_lr , packet1.rs_ud , packet1.mode , packet1.command_1 , packet1.command_2 );
    mavlink_msg_fmt_pilot_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fmt_pilot_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.ls_lr , packet1.ls_ud , packet1.rs_lr , packet1.rs_ud , packet1.mode , packet1.command_1 , packet1.command_2 );
    mavlink_msg_fmt_pilot_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FMT_PILOT_CMD") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FMT_PILOT_CMD) != NULL);
#endif
}

static void mavlink_test_fmt_external_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FMT_EXTERNAL_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fmt_external_state_t packet_in = {
        963497464,{ 45.0, 46.0, 47.0, 48.0 },{ 157.0, 158.0, 159.0 },{ 241.0, 242.0, 243.0 },{ 325.0, 326.0, 327.0 },{ 409.0, 410.0, 411.0 },{ 963501000, 963501001, 963501002 },577.0,963501832
    };
    mavlink_fmt_external_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.h_AGL = packet_in.h_AGL;
        packet1.flag = packet_in.flag;
        
        mav_array_memcpy(packet1.quat, packet_in.quat, sizeof(float)*4);
        mav_array_memcpy(packet1.rot, packet_in.rot, sizeof(float)*3);
        mav_array_memcpy(packet1.acc, packet_in.acc, sizeof(float)*3);
        mav_array_memcpy(packet1.vel, packet_in.vel, sizeof(float)*3);
        mav_array_memcpy(packet1.pos, packet_in.pos, sizeof(float)*3);
        mav_array_memcpy(packet1.lla, packet_in.lla, sizeof(int32_t)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FMT_EXTERNAL_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_external_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fmt_external_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_external_state_pack(system_id, component_id, &msg , packet1.timestamp , packet1.quat , packet1.rot , packet1.acc , packet1.vel , packet1.pos , packet1.lla , packet1.h_AGL , packet1.flag );
    mavlink_msg_fmt_external_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_external_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.quat , packet1.rot , packet1.acc , packet1.vel , packet1.pos , packet1.lla , packet1.h_AGL , packet1.flag );
    mavlink_msg_fmt_external_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fmt_external_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_external_state_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.quat , packet1.rot , packet1.acc , packet1.vel , packet1.pos , packet1.lla , packet1.h_AGL , packet1.flag );
    mavlink_msg_fmt_external_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FMT_EXTERNAL_STATE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FMT_EXTERNAL_STATE) != NULL);
#endif
}

static void mavlink_test_fmt_environment_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fmt_environment_info_t packet_in = {
        { 17.0, 18.0, 19.0 },{ 101.0, 102.0, 103.0 },{ 185.0, 186.0, 187.0 }
    };
    mavlink_fmt_environment_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.hit_point, packet_in.hit_point, sizeof(float)*3);
        mav_array_memcpy(packet1.hit_normal, packet_in.hit_normal, sizeof(float)*3);
        mav_array_memcpy(packet1.hit_location, packet_in.hit_location, sizeof(float)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_environment_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fmt_environment_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_environment_info_pack(system_id, component_id, &msg , packet1.hit_point , packet1.hit_normal , packet1.hit_location );
    mavlink_msg_fmt_environment_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_environment_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.hit_point , packet1.hit_normal , packet1.hit_location );
    mavlink_msg_fmt_environment_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fmt_environment_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_environment_info_send(MAVLINK_COMM_1 , packet1.hit_point , packet1.hit_normal , packet1.hit_location );
    mavlink_msg_fmt_environment_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FMT_ENVIRONMENT_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FMT_ENVIRONMENT_INFO) != NULL);
#endif
}

static void mavlink_test_fmt(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_fmt_pilot_cmd(system_id, component_id, last_msg);
    mavlink_test_fmt_external_state(system_id, component_id, last_msg);
    mavlink_test_fmt_environment_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // FMT_TESTSUITE_H
