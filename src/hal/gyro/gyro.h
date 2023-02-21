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

#ifndef GYRO_H__
#define GYRO_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GYRO_RANGE_250DPS  250
#define GYRO_RANGE_500DPS  500
#define GYRO_RANGE_1000DPS 1000
#define GYRO_RANGE_2000DPS 2000

/* gyro device bus type */
#define GYRO_SPI_BUS_TYPE 1
#define GYRO_I2C_BUS_TYPE 2

/* default config for accel sensor */
#define GYRO_CONFIG_DEFAULT                              \
    {                                                    \
        1000,                   /* 1K sample rate */     \
            250,                /* 250Hz internal lpf */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */       \
    }

struct gyro_configure {
    rt_uint32_t sample_rate_hz;
    rt_uint16_t dlpf_freq_hz;
    rt_uint32_t gyro_range_dps;
};

struct gyro_device {
    struct rt_device parent;
    const struct gyro_ops* ops;
    struct gyro_configure config;
    rt_uint8_t bus_type;
};
typedef struct gyro_device* gyro_dev_t;

/* gyro driver opeations */
struct gyro_ops {
    /**
     * @brief gyro configuration function (optional)
     * @param dev gyro device
     * @param cfg gyro configuration
    */
    rt_err_t (*gyro_config)(gyro_dev_t dev, const struct gyro_configure* cfg);
    /**
     * @brief gyro control function (optional)
     * @param dev gyro device
     * @param cmd operation command
     * @param arg command argument (optional)
    */
    rt_err_t (*gyro_control)(gyro_dev_t dev, int cmd, void* arg);
    /**
     * @brief gyro read data function
     * @param dev gyro device
     * @param pos read pos, sent by upper layer. can be used to identify the data type to read, e.g, raw data or scaled data
     * @param data read data buffer. normally it's a pointer to float[3]
     * @param size read data size
    */
    rt_size_t (*gyro_read)(gyro_dev_t dev, rt_off_t pos, void* data, rt_size_t size);
};

rt_err_t hal_gyro_register(gyro_dev_t gyro, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
