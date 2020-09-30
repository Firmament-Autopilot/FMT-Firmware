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

#ifndef __SBUS_H__
#define __SBUS_H__
#include <stdio.h>
#include <stdbool.h>
#include "time.h"
#include "protocol.h"
#include "usart.h"

unsigned sbus_dropped_frames(void);

void sbus1_output(uint16_t* values, uint16_t num_values);
void sbus2_output(uint16_t* values, uint16_t num_values);
bool sbus_input(uint16_t* values, uint16_t* num_values, bool* sbus_failsafe,
                bool* sbus_frame_drop, uint16_t max_channels);
uint8_t send_sbus_value(void);

uint8_t sbus_init(void);
void sbus_deinit(void);
#endif
