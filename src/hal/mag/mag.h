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

#ifndef MAG_H__
#define MAG_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LSM303D_MAG_DEFAULT_RANGE_GA 2
#define LSM303D_MAG_DEFAULT_RATE     100

#define LSM303D_ONE_G 9.80665f

#define MAG_RANGE_2GA  2
#define MAG_RANGE_4GA  4
#define MAG_RANGE_8GA  6
#define MAG_RANGE_12GA 12
#define MAG_RANGE_16GA 16

/* mag device bus type */
#define MAG_SPI_BUS_TYPE 1
#define MAG_I2C_BUS_TYPE 2

/* mag read pos */
#define MAG_RD_RAW   1
#define MAG_RD_SCALE 2

/* default config for mag sensor */
#define MAG_CONFIG_DEFAULT                                  \
    {                                                       \
        100,               /* 100hz sample rate */          \
            50,            /* 260Hz internal lpf for mag */ \
            MAG_RANGE_8GA, /* +-8guess */                   \
    }

struct mag_configure {
    rt_uint32_t sample_rate_hz;
    rt_uint16_t dlpf_freq_hz;
    rt_uint32_t mag_range_ga;
};

struct mag_device {
    struct rt_device parent;
    const struct mag_ops* ops;
    struct mag_configure config;
    rt_uint8_t bus_type;
};
typedef struct mag_device* mag_dev_t;

/* mag driver opeations */
struct mag_ops {
    rt_err_t (*mag_config)(mag_dev_t mag, const struct mag_configure* cfg);
    rt_err_t (*mag_control)(mag_dev_t mag, int cmd, void* arg);
    rt_size_t (*mag_read)(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size);
};

rt_err_t hal_mag_register(mag_dev_t mag, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
