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

#ifndef __SYSTIME_H__
#define __SYSTIME_H__

#include <firmament.h>

typedef struct {
    uint32_t tag;
    uint32_t period;
} TimeTag;

#define DEFINE_TIMETAG(_name, _period)   \
    static TimeTag __timetag_##_name = { \
        .tag = 0,                        \
        .period = _period                \
    }

#define TIMETAG(_name) (&__timetag_##_name)

#define TIMETAG_CHECK_EXECUTE(_name, _period, _operation) \
    DEFINE_TIMETAG(_name, _period);                       \
    do {                                                  \
        if (check_timetag(TIMETAG(_name))) {              \
            _operation                                    \
        }                                                 \
    } while (0)

#define TIMETAG_CHECK_EXECUTE2(_name, _period, _time_now, _operation) \
    DEFINE_TIMETAG(_name, _period);                                   \
    do {                                                              \
        if (check_timetag2(TIMETAG(_name), _time_now)) {              \
            _operation                                                \
        }                                                             \
    } while (0)

#define TIMETAG_CHECK_EXECUTE3(_name, _period, _time_now, _operation) \
    DEFINE_TIMETAG(_name, 0);                                         \
    do {                                                              \
        if (check_timetag3(TIMETAG(_name), _time_now, _period)) {     \
            _operation                                                \
        }                                                             \
    } while (0)

uint64_t systime_now_us(void);
uint32_t systime_now_ms(void);
void sys_udelay(uint32_t delay);
void sys_mdelay(uint32_t time_ms);
uint8_t check_timetag(TimeTag* timetag);
uint8_t check_timetag2(TimeTag* timetag, uint32_t now);
uint8_t check_timetag3(TimeTag* timetag, uint32_t now, uint32_t period);
fmt_err systime_init(void);

#endif