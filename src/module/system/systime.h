/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#ifndef SYSTIME_H__
#define SYSTIME_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TICKS_FROM_MS(_ms) ((RT_TICK_PER_SECOND * _ms + 999) / 1000)
#define sys_msleep(_ms)    systime_msleep(_ms)

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

#define PERIOD_EXECUTE(_name, _period, _operation) \
    DEFINE_TIMETAG(_name, _period);                \
    do {                                           \
        if (check_timetag(TIMETAG(_name))) {       \
            _operation                             \
        }                                          \
    } while (0)

#define PERIOD_EXECUTE2(_name, _period, _time_now, _operation) \
    DEFINE_TIMETAG(_name, _period);                            \
    do {                                                       \
        if (check_timetag2(TIMETAG(_name), _time_now)) {       \
            _operation                                         \
        }                                                      \
    } while (0)

#define PERIOD_EXECUTE3(_name, _period, _time_now, _operation)    \
    DEFINE_TIMETAG(_name, 0);                                     \
    do {                                                          \
        if (check_timetag3(TIMETAG(_name), _time_now, _period)) { \
            _operation                                            \
        }                                                         \
    } while (0)

#define WAIT_TIMEOUT(_cond, _timeout_us, _opt)               \
    do {                                                     \
        uint64_t start = systime_now_us();                   \
        uint8_t timeout = 1;                                 \
        while ((systime_now_us() - start) < (_timeout_us)) { \
            if (!(_cond)) {                                  \
                timeout = 0;                                 \
                break;                                       \
            }                                                \
        }                                                    \
        if (timeout) {                                       \
            _opt                                             \
        }                                                    \
    } while (0)

#define WAIT_TIMEOUT2(_cond, _break_cond, _timeout_us, _opt) \
    do {                                                     \
        uint64_t start = systime_now_us();                   \
        uint8_t timeout = 1;                                 \
        while ((systime_now_us() - start) < (_timeout_us)) { \
            if (!(_cond)) {                                  \
                timeout = 0;                                 \
                break;                                       \
            }                                                \
            if ((_break_cond)) {                             \
                break;                                       \
            }                                                \
        }                                                    \
        if (timeout) {                                       \
            _opt                                             \
        }                                                    \
    } while (0)

fmt_err_t systime_init(void);
uint64_t systime_now_us(void);
uint32_t systime_now_ms(void);
void systime_udelay(uint32_t delay);
void systime_mdelay(uint32_t time_ms);
void systime_msleep(uint32_t time_ms);
uint8_t check_timetag(TimeTag* timetag);
uint8_t check_timetag2(TimeTag* timetag, uint32_t now);
uint8_t check_timetag3(TimeTag* timetag, uint32_t now, uint32_t period);

#ifdef __cplusplus
}
#endif

#endif
