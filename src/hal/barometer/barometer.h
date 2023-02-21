/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#ifndef BAROMETER_H__
#define BAROMETER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* baro read pos */
#define BARO_RD_REPORT 1

/* baro command */
#define BARO_CMD_CHECK_READY 0x20

typedef struct {
    uint32_t timestamp_ms;
    float temperature_deg;
    float pressure_Pa;
    float altitude_m;
} baro_report_t;

struct baro_configure {
    rt_uint16_t osr; /* oversampling ratio */
};

struct baro_device {
    struct rt_device parent;
    const struct baro_ops* ops;
};
typedef struct baro_device* baro_dev_t;

/* baro driver opeations */
struct baro_ops {
    /**
     * @brief baro meter control function (optional)
     * @param dev barometer device
     * @param cmd operation command
     * @param arg command arguments
     */
    rt_err_t (*baro_control)(baro_dev_t dev, int cmd, void* arg);
    /**
     * @brief read barometer report
     * @param dev barometer device
     * @param report barometer report buffer
     */
    rt_size_t (*baro_read)(baro_dev_t dev, baro_report_t* report);
};

rt_err_t hal_baro_register(baro_dev_t baro, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
