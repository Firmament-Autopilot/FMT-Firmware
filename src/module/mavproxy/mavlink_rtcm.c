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

#include "hal/serial/serial.h"
#include "module/mavproxy/mavproxy.h"
#include "module/mavproxy/mavproxy_config.h"

#define MAX_RTCM_DEV_NUM 5

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

static uint8_t rtcm_dev_num;
static rt_device_t rtcm_dev[MAX_RTCM_DEV_NUM];
static struct rt_completion tx_cplt[MAX_RTCM_DEV_NUM];

static rt_err_t rtcm_tx_done(rt_device_t dev, void* buffer)
{
    for (uint8_t i = 0; i < rtcm_dev_num; i++) {
        if (dev == rtcm_dev[i]) {
            rt_completion_done(&tx_cplt[i]);
        }
    }

    return RT_EOK;
}

static void inject_data(const uint8_t* data, uint16_t len)
{
    // TODO: check write complete before next write;
    for (uint8_t i = 0; i < rtcm_dev_num; i++) {
        if (rtcm_dev[i] != NULL) {
            if (rt_device_write(rtcm_dev[i], 0, data, len) > 0) {
                /* wait write complete (synchronized write) */
                rt_completion_wait(&tx_cplt[i], TICKS_FROM_MS(100));
            }
        }
    }
}

void handle_gps_rtcm_data(const mavlink_message_t* msg)
{
    mavlink_gps_rtcm_data_t packet;
    mavlink_msg_gps_rtcm_data_decode(msg, &packet);

    // printf("rtcm pkg, len:%d fragmented:%d, fragment_id:%d, seq_id:%d\n", packet.len, packet.flags & 1, (packet.flags >> 1U) & 0x03, (packet.flags >> 3U) & 0x1F);

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
        const bool sequence_nr_changed = rtcm_buffer->sequence != sequence;
        const bool seen_this_fragment_index = rtcm_buffer->fragments_received & (1U << fragment);

        // check whether this is a duplicate fragment. If it is, we can
        // return early.
        if (!sequence_nr_changed && seen_this_fragment_index && !rt_memcmp(start_of_fragment_in_buffer, packet.data, packet.len)) {
            return;
        }

        // not a duplicate
        should_clear_previous_fragments = sequence_nr_changed || seen_this_fragment_index;
    }

    if (should_clear_previous_fragments) {
        // we have one or more partial fragments already received
        // which conflict with the new fragment, discard previous fragments
        rtcm_buffer->fragment_count = 0;
        // rtcm_stats.fragments_discarded += __builtin_popcount(rtcm_buffer->fragments_received);
        rtcm_buffer->fragments_received = 0;
    }

    // add this fragment
    rtcm_buffer->sequence = sequence;
    rtcm_buffer->fragments_received |= (1U << fragment);

    // copy the data
    rt_memcpy(start_of_fragment_in_buffer, packet.data, packet.len);

    // when we get a fragment of less than max size then we know the
    // number of fragments. Note that this means if you want to send a
    // block of RTCM data of an exact multiple of the buffer size you
    // need to send a final packet of zero length
    if (packet.len < MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN) {
        rtcm_buffer->fragment_count = fragment + 1;
        rtcm_buffer->total_length = (MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN * fragment) + packet.len;
    } else if (rtcm_buffer->fragments_received == 0x0F) {
        // special case of 4 full fragments
        rtcm_buffer->fragment_count = 4;
        rtcm_buffer->total_length = MAVLINK_MSG_GPS_RTCM_DATA_FIELD_DATA_LEN * 4;
    }

    // see if we have all fragments
    if (rtcm_buffer->fragment_count != 0 && rtcm_buffer->fragments_received == (1U << rtcm_buffer->fragment_count) - 1) {
        // we have them all, inject
        inject_data(rtcm_buffer->buffer, rtcm_buffer->total_length);
        rtcm_buffer->fragment_count = 0;
        rtcm_buffer->fragments_received = 0;
    }
}

fmt_err_t mavlink_rtcm_device_init(void)
{
    mavproxy_device_info* rtcm_dev_list = mavproxy_get_rtcm_dev_list();
    uint8_t dev_num = mavproxy_get_rtcm_dev_num();

    for (uint8_t i = 0; i < dev_num && i < MAX_RTCM_DEV_NUM; i++) {
        if (strcmp(rtcm_dev_list[i].type, "serial") == 0) {
            rt_device_t dev = rt_device_find(rtcm_dev_list[i].name);

            if (dev == NULL) {
                continue;
            }

            /* If device is not opened, then open it */
            if (!(dev->open_flag & RT_DEVICE_OFLAG_OPEN)) {
                rt_uint16_t oflag = RT_DEVICE_OFLAG_WRONLY;

                if (dev->flag & RT_DEVICE_FLAG_DMA_TX) {
                    oflag |= RT_DEVICE_FLAG_DMA_TX;
                }

                RT_TRY(rt_device_open(dev, oflag));

                serial_dev_t serial_dev = (serial_dev_t)dev;
                mavproxy_serial_dev_config* config = rtcm_dev_list[i].config;

                if (serial_dev->config.baud_rate != config->baudrate) {
                    struct serial_configure pconfig = serial_dev->config;
                    pconfig.baud_rate = config->baudrate;

                    RT_TRY(rt_device_control(dev, RT_DEVICE_CTRL_CONFIG, &pconfig));
                }
            }

            rt_completion_init(&tx_cplt[i]);
            /* set callback functions */
            rt_device_set_tx_complete(dev, rtcm_tx_done);

            rtcm_dev[rtcm_dev_num++] = dev;
        }
    }

    return FMT_EOK;
}
