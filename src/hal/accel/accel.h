/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#ifndef ACCEL_H__
#define ACCEL_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* accel range type */
#define ACCEL_RANGE_2G  2
#define ACCEL_RANGE_4G  4
#define ACCEL_RANGE_8G  8
#define ACCEL_RANGE_16G 16

/* accel device bus type */
#define ACCEL_SPI_BUS_TYPE 1
#define ACCEL_I2C_BUS_TYPE 2

/* default config for accel sensor */
#define ACCEL_CONFIG_DEFAULT                                    \
    {                                                           \
        1000,                /* 1K sample rate */               \
            250,             /* 250Hz internal lpf for accel */ \
            ACCEL_RANGE_16G, /* +-16g */                        \
    }

struct accel_configure {
    rt_uint32_t sample_rate_hz; /* sample rate in Hz */
    rt_uint16_t dlpf_freq_hz;   /* internal low-pass filter cur-off freq in Hz */
    rt_uint32_t acc_range_g;    /* accel measure range in g */
};

struct accel_device {
    struct rt_device parent;
    const struct accel_ops* ops;
    struct accel_configure config;
    rt_uint8_t bus_type;
};
typedef struct accel_device* accel_dev_t;

/* accel driver opeations */
struct accel_ops {
    /**
     * @brief accel configuration function (optional)
     * @param dev accel device
     * @param cfg accel configuration
    */
    rt_err_t (*accel_config)(accel_dev_t dev, const struct accel_configure* cfg);
    /**
     * @brief accel control function (optional)
     * @param dev accel device
     * @param cmd operation command
     * @param arg command argument (optional)
    */
    rt_err_t (*accel_control)(accel_dev_t dev, int cmd, void* arg);
    /**
     * @brief accel read data function
     * @param dev accel device
     * @param pos read pos, sent by upper layer. can be used to identify the data type to read, e.g, raw data or scaled data
     * @param data read data buffer. normally it's a pointer to float[3]
     * @param size read data size
    */
    rt_size_t (*accel_read)(accel_dev_t dev, rt_off_t pos, void* data, rt_size_t size);
};

rt_err_t hal_accel_register(accel_dev_t accel, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
