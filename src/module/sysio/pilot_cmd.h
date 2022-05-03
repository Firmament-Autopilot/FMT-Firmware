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

#ifndef PILOT_CMD_H__
#define PILOT_CMD_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

// Pilot Command 1 (Event Command)
#define FMS_CMD_FORCE_DISARM 1000

// Pilot Command 2 (State Command)
#define FMS_CMD_TEST_MOTOR 2000

typedef struct {
    int8_t mode;
    int8_t chan_dim;
    int8_t* channel;
    int16_t* range;
} pilot_mode_config;

typedef struct {
    int32_t cmd;
    int8_t chan_dim;
    int8_t* channel;
    int16_t* range;
    uint8_t _set;
} pilot_event_cmd_t;

typedef struct {
    int32_t cmd;
    int8_t chan_dim;
    int8_t* channel;
    int16_t* range;
} pilot_status_cmd_t;

fmt_err_t pilot_cmd_init(void);
fmt_err_t pilot_cmd_collect(void);
fmt_err_t pilot_cmd_set_device(const char* dev_name);
fmt_err_t pilot_cmd_set_chan_num(uint8_t chan_num);
fmt_err_t pilot_cmd_map_stick(uint8_t yaw_chan, uint8_t thro_chan, uint8_t roll_chan, uint8_t pitch_chan);

#ifdef __cplusplus
}
#endif

#endif