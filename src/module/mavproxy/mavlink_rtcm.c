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

/*
    buffer for re-assembling RTCM data for GPS injection.
    The 8 bit flags field in GPS_RTCM_DATA is interpreted as:
            1 bit for "is fragmented"
            2 bits for fragment number
            5 bits for sequence number

    The rtcm_buffer is allocated on first use. Once a block of data
    is successfully reassembled it is injected into all active GPS
    backends. This assumes we don't want more than 4*180=720 bytes
    in a RTCM data block
    */
struct rtcm_buffer {
    uint8_t fragments_received;
    uint8_t sequence;
    uint8_t fragment_count;
    uint16_t total_length;
    uint8_t buffer[MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN * 4];
}* rtcm_buffer;

static void inject_data(const uint8_t* data, uint16_t len)
{
    // //Support broadcasting to all GPSes.
    // if (_inject_to == GPS_RTK_INJECT_TO_ALL) {
    //     for (uint8_t i=0; i<GPS_MAX_RECEIVERS; i++) {
    //         if (is_rtk_rover(i)) {
    //             // we don't externally inject to moving baseline rover
    //             continue;
    //         }
    //         inject_data(i, data, len);
    //     }
    // } else {
    //     inject_data(_inject_to, data, len);
    // }
}

void handle_gps_rtcm_data(const mavlink_message_t* msg)
{
    mavlink_gps_rtcm_data_t packet;
    mavlink_msg_gps_rtcm_data_decode(msg, &packet);

    if (packet.len > sizeof(packet.data)) {
        // invalid packet
        return;
    }

    if ((packet.flags & 1) == 0) {
        // it is not fragmented, pass direct
        inject_data(packet.data, packet.len);
        return;
    }

    // see if we need to allocate re-assembly buffer
    if (rtcm_buffer == NULL) {
        rtcm_buffer = (struct rtcm_buffer*)rt_malloc(sizeof(*rtcm_buffer));
        if (rtcm_buffer == NULL) {
            // nothing to do but discard the data
            return;
        }
    }

    const uint8_t fragment = (packet.flags >> 1U) & 0x03;
    const uint8_t sequence = (packet.flags >> 3U) & 0x1F;
    uint8_t* start_of_fragment_in_buffer = &rtcm_buffer->buffer[MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN * (uint16_t)fragment];
    bool should_clear_previous_fragments = false;

    if (rtcm_buffer->fragments_received) {
        // 已经有收到fragments过
        const bool sequence_nr_changed = rtcm_buffer->sequence != sequence;                       // 新的sequence id
        const bool seen_this_fragment_index = rtcm_buffer->fragments_received & (1U << fragment); // 是否是受到过的fragment

        // check whether this is a duplicate fragment. If it is, we can
        // return early.
        if (!sequence_nr_changed && seen_this_fragment_index && !rt_memcmp(start_of_fragment_in_buffer, packet.data, packet.len)) {
            // 如果是收到过的fragment，且sequence id和数据内容都没有变化，则返回
            return;
        }

        // not a duplicate
        should_clear_previous_fragments = sequence_nr_changed || seen_this_fragment_index;
    }

    if (should_clear_previous_fragments) {
        // we have one or more partial fragments already received
        // which conflict with the new fragment, discard previous fragments
        // 清楚所有之前的fragments
        rtcm_buffer->fragment_count = 0;
        // rtcm_stats.fragments_discarded += __builtin_popcount(rtcm_buffer->fragments_received);
        rtcm_buffer->fragments_received = 0;
    }

    // add this fragment
    rtcm_buffer->sequence = sequence;
    // 每一位对应fragment是否收到
    rtcm_buffer->fragments_received |= (1U << fragment);

    // copy the data
    rt_memcpy(start_of_fragment_in_buffer, packet.data, packet.len);

    // when we get a fragment of less than max size then we know the
    // number of fragments. Note that this means if you want to send a
    // block of RTCM data of an exact multiple of the buffer size you
    // need to send a final packet of zero length
    if (packet.len < MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN) {
        // 收到一个小于180字节的fragment，则知道已经收到完成的数据
        rtcm_buffer->fragment_count = fragment + 1;
        rtcm_buffer->total_length = (MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN * fragment) + packet.len;
    } else if (rtcm_buffer->fragments_received == 0x0F) {
        // special case of 4 full fragments
        // 收到4个fragment，也认为已经收到完整的
        rtcm_buffer->fragment_count = 4;
        rtcm_buffer->total_length = MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN * 4;
    }

    // see if we have all fragments
    if (rtcm_buffer->fragment_count != 0 && rtcm_buffer->fragments_received == (1U << rtcm_buffer->fragment_count) - 1) {
        // we have them all, inject
        // 发送数据，并将fragment_count和fragments_received清除
        // rtcm_stats.fragments_used += __builtin_popcount(rtcm_buffer->fragments_received);
        inject_data(rtcm_buffer->buffer, rtcm_buffer->total_length);
        rtcm_buffer->fragment_count = 0;
        rtcm_buffer->fragments_received = 0;
    }
}
