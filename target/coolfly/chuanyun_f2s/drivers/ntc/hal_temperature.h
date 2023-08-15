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

#ifndef TEMPERATURE_H__
#define TEMPERATURE_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* temperature read pos */
#define TEMPERATUE_READ_REPORT 0

typedef struct {
    uint32_t timestamp_ms;
    float    temperature_deg;
} temperature_report_t;

struct temperature_device {
    struct rt_device              parent;
    const struct temperature_ops* ops;
};
typedef struct temperature_device* temperature_dev_t;

/* temperature driver opeations */
struct temperature_ops {
    // rt_err_t (*temperature_control)(temperature_dev_t temperature_dev, int cmd, void* arg);
    rt_size_t (*temperature_read)(temperature_dev_t temperature_dev, temperature_report_t* report);
};

rt_err_t hal_temperature_register(temperature_dev_t temperature_dev, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif /* temperature_H__ */
