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
#ifndef STATISTIC_H__
#define STATISTIC_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint64_t exec_time;
    uint64_t total_exec_time;
    float cpu_usage;
} cpu_usage_stats;

fmt_err_t sys_stat_init(void);
float get_cpu_usage(void);

#ifdef __cplusplus
}
#endif

#endif
