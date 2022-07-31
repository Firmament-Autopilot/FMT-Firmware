/** @file
 *    @brief MAVLink comm protocol testsuite generated from fmt_mavlink.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef FMT_MAVLINK_TESTSUITE_H
    #define FMT_MAVLINK_TESTSUITE_H

    #ifdef __cplusplus
extern "C" {
    #endif

    #ifndef MAVLINK_TEST_ALL
        #define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t* last_msg);
static void mavlink_test_fmt_mavlink(uint8_t, uint8_t, mavlink_message_t* last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t* last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_fmt_mavlink(system_id, component_id, last_msg);
}
    #endif

    #include "../common/testsuite.h"

static void mavlink_test_fmt_pilot_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t* last_msg)
{
    #ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t* status = mavlink_get_channel_status(MAVLINK_COMM_0);
    if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FMT_PILOT_CMD >= 256) {
        return;
    }
    #endif
    mavlink_message_t msg;
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    uint16_t i;
    mavlink_fmt_pilot_cmd_t packet_in = {
        963497464, 45.0, 73.0, 101.0, 129.0, 963498504, 963498712, 963498920
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
        memset(MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN + (char*)&packet1, 0, sizeof(packet1) - MAVLINK_MSG_ID_FMT_PILOT_CMD_MIN_LEN);
    }
    #endif
    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fmt_pilot_cmd_decode(&msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_pack(system_id, component_id, &msg, packet1.timestamp, packet1.ls_lr, packet1.ls_ud, packet1.rs_lr, packet1.rs_ud, packet1.mode, packet1.command_1, packet1.command_2);
    mavlink_msg_fmt_pilot_cmd_decode(&msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg, packet1.timestamp, packet1.ls_lr, packet1.ls_ud, packet1.rs_lr, packet1.rs_ud, packet1.mode, packet1.command_1, packet1.command_2);
    mavlink_msg_fmt_pilot_cmd_decode(&msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_to_send_buffer(buffer, &msg);
    for (i = 0; i < mavlink_msg_get_send_buffer_length(&msg); i++) {
        comm_send_ch(MAVLINK_COMM_0, buffer[i]);
    }
    mavlink_msg_fmt_pilot_cmd_decode(last_msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

    memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fmt_pilot_cmd_send(MAVLINK_COMM_1, packet1.timestamp, packet1.ls_lr, packet1.ls_ud, packet1.rs_lr, packet1.rs_ud, packet1.mode, packet1.command_1, packet1.command_2);
    mavlink_msg_fmt_pilot_cmd_decode(last_msg, &packet2);
    MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_fmt_mavlink(uint8_t system_id, uint8_t component_id, mavlink_message_t* last_msg)
{
    mavlink_test_fmt_pilot_cmd(system_id, component_id, last_msg);
}

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif     // FMT_MAVLINK_TESTSUITE_H
