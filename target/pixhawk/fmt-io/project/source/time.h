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

#ifndef  _TIME_H_
#define  _TIME_H_

#include "stm32f10x.h"

typedef struct {
	uint32_t tag;
	uint32_t period;
} TimeTag;

#define DEFINE_TIMETAG(_name, _period)      \
    static TimeTag __timetag_##_name = {    \
        .tag = 0,                           \
        .period = _period                   \
    }

#define TIMETAG(_name)          (&__timetag_##_name)

#define PERIOD_EXECUTE(_name, _period, _operation)   \
    DEFINE_TIMETAG(_name, _period); \
    if(check_timetag(TIMETAG(_name))){_operation}

void time_init(void);
uint64_t time_nowUs(void);
uint32_t time_nowMs(void);
void time_waitUs(uint32_t delay);
void time_waitMs(uint32_t delay);
uint8_t check_timetag(TimeTag* timetag);

#endif
