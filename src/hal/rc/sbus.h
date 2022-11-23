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

typedef struct {
    uint16_t rc_count;
    uint16_t max_channels;
    bool sbus_failsafe;
    bool sbus_frame_drop;
    uint32_t sbus_frame_drops;
    uint32_t partial_frame_count;
    uint64_t last_rx_time;
    uint64_t last_frame_time;
    ringbuffer* sbus_rb;
    uint8_t sbus_frame[SBUS_FRAME_SIZE + (SBUS_FRAME_SIZE / 2)];
    uint16_t sbus_val[MAX_SBUS_CHANNEL];
} sbus_decoder_t;

rt_err_t sbus_decoder_init(void);
uint32_t sbus_input(const uint8_t* values, uint32_t size);
bool sbus_update(uint16_t* values, uint16_t* num_values, bool* sbus_failsafe,
                 bool* sbus_frame_drop, uint16_t max_channels);

#ifdef __cplusplus
}
#endif

#endif
