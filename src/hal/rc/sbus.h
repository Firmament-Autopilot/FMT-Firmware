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

#ifndef SBUS_H__
#define SBUS_H__

#include <firmament.h>

#include "module/utils/ringbuffer.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SBUS_CHANNEL 16
#define SBUS_FRAME_SIZE  25

typedef enum {
    SBUS_DECODE_STATE_DESYNC = 0xFFF,
    SBUS_DECODE_STATE_SBUS_START = 0x2FF,
    SBUS_DECODE_STATE_SBUS1_SYNC = 0x00,
    SBUS_DECODE_STATE_SBUS2_SYNC = 0x1FF,
    SBUS_DECODE_STATE_SBUS2_RX_VOLTAGE = 0x04,
    SBUS_DECODE_STATE_SBUS2_GPS = 0x14,
    SBUS_DECODE_STATE_SBUS2_DATA1 = 0x24,
    SBUS_DECODE_STATE_SBUS2_DATA2 = 0x34
} SBUS_DECODE_STATE;

typedef struct {
    uint16_t rc_count;
    uint16_t max_channels;
    bool sbus_failsafe;
    bool sbus_frame_drop;
    uint32_t sbus_frame_drops;
    uint32_t partial_frame_count;
    uint32_t last_rx_time;
    uint32_t last_frame_time;
    bool sbus_data_ready;
    uint8_t sbus_lock;
    SBUS_DECODE_STATE sbus_decode_state;
    ringbuffer* sbus_rb;
    uint8_t sbus_frame[SBUS_FRAME_SIZE + (SBUS_FRAME_SIZE / 2)];
    uint16_t sbus_val[MAX_SBUS_CHANNEL];
} sbus_decoder_t;

rt_inline void sbus_lock(sbus_decoder_t* decoder)
{
    decoder->sbus_lock = 1;
}

rt_inline void sbus_unlock(sbus_decoder_t* decoder)
{
    decoder->sbus_lock = 0;
}

rt_inline uint8_t sbus_islock(sbus_decoder_t* decoder)
{
    return decoder->sbus_lock;
}

rt_inline uint8_t sbus_data_ready(sbus_decoder_t* decoder)
{
    return decoder->sbus_data_ready;
}

rt_inline void sbus_data_clear(sbus_decoder_t* decoder)
{
    decoder->sbus_data_ready = 0;
}

rt_err_t sbus_decoder_init(sbus_decoder_t* decoder);
uint32_t sbus_input(sbus_decoder_t* decoder, const uint8_t* values, uint32_t size);
bool sbus_update(sbus_decoder_t* decoder);

#ifdef __cplusplus
}
#endif

#endif
