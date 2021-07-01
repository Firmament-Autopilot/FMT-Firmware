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

#ifndef _PPM_DECODER_H_
#define _PPM_DECODER_H_

#include "stm32f10x.h"

#define MAX_PPM_CHANNEL 8 /* we need at least 2 signal for synchronization */

typedef struct {
    uint8_t chan_id;
    uint8_t total_chan; /* total ppm channel number */
    uint16_t last_ic;
    uint16_t ppm_val[16]; /* ppm raw value in microseconds */
} ppm_encoder_t;

uint8_t ppm_decoder_init(void);
void ppm_decoder_deinit(void);
void get_ppm_value(uint16_t* val);
uint8_t send_ppm_value(void);
uint8_t config_ppm_send_freq(uint8_t freq);

#endif
