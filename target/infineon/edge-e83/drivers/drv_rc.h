/******************************************************************************
 * Copyright 2024 The Firmament Authors. All Rights Reserved.
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

#ifndef DRV_RC_H__
#define DRV_RC_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif
rt_err_t drv_rc_init(void);
rt_err_t drv_rc_thread_start(void);
rt_err_t drv_rc_deinit(void);
rt_err_t rc_init(void);
void drv_rc_start_capture(void);
uint8_t drv_rc_send_ppm(void);
rt_err_t sbus_lowlevel_init(void);
uint8_t send_sbus_value(void);
#define RC_CAPTURE_BUF_SIZE 32
#define PPM_CHANNEL_COUNT 9

typedef struct {
    uint32_t capture;
    uint32_t gap;
    uint8_t  type;
} rc_capture_t;

typedef struct {
    uint16_t channels[PPM_CHANNEL_COUNT];
    uint8_t  valid;
    uint32_t frame_period;
    uint16_t history[3][PPM_CHANNEL_COUNT];
    uint8_t  history_idx;
    uint8_t  history_filled;
} ppm_data_t;

#ifdef __cplusplus
}
#endif

#endif
