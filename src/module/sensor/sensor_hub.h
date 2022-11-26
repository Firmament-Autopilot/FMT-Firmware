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
#ifndef SENSOR_HUB_H__
#define SENSOR_HUB_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RAW_TEMPERATURE_POS 0
#define RAW_PRESSURE_POS    1
#define COLLECT_DATA_POS    2
#define GYR_RAW_POS         0
#define GYR_SCALE_POS       1
#define ACC_RAW_POS         2
#define ACC_SCALE_POS       3
#define MAG_RAW_POS         4
#define MAG_SCLAE_POS       5

//common cmd
#define SENSOR_GET_DEVICE_ID 0x00
//acc,mag cmd
#define SENSOR_SET_ACC_RANGE      0x01
#define SENSOR_SET_ACC_SAMPLERATE 0x02
#define SENSOR_SET_MAG_RANGE      0x03
#define SENSOR_SET_MAG_SAMPLERATE 0x04
//gyr cmd
#define SENSOR_SET_GYR_RANGE 0x20
//baro cmd
#define SENSOR_CONVERSION  0x30
#define SENSOR_IS_CONV_FIN 0x31

struct sensor_imu {
    rt_device_t gyr_dev;
    rt_device_t acc_dev;
    float gyr_rotation[3][3];
    float gyr_offset[3];
    float acc_rotation[3][3];
    float acc_offset[3];
};
typedef struct sensor_imu* sensor_imu_t;

struct sensor_mag {
    rt_device_t dev;
    float rotation[3][3];
    float offset[3];
};
typedef struct sensor_mag* sensor_mag_t;

struct sensor_baro {
    rt_device_t dev;
};
typedef struct sensor_baro* sensor_baro_t;

struct sensor_gps {
    rt_device_t dev;
};
typedef struct sensor_gps* sensor_gps_t;

struct sensor_airspeed {
    rt_device_t dev;
};
typedef struct sensor_airspeed* sensor_airspeed_t;

typedef struct {
    uint32_t timestamp_ms;
    float gyr_B_radDs[3];
    float acc_B_mDs2[3];
} imu_data_t;

typedef struct {
    uint32_t timestamp_ms;
    float mag_B_gauss[3];
} mag_data_t;

typedef struct {
    uint32_t timestamp_ms;
    float temperature_deg;
    float pressure_pa;
    float altitude_m;
} baro_data_t;

typedef struct {
    uint32_t timestamp_ms;
    int32_t lon;
    int32_t lat;
    int32_t height;
    float hAcc;
    float vAcc;
    float velN;
    float velE;
    float velD;
    float vel;
    float cog;
    float sAcc;
    uint8_t fixType;
    uint8_t numSV;
    uint16_t reserved;
} gps_data_t;

typedef struct {
    uint32_t timestamp_ms;
    float vx_mPs;
    float vy_mPs;
    uint8_t quality;
} optflow_data_t;

typedef struct {
    uint32_t timestamp_ms;
    float distance_m; // negative value indicate invalid
} rf_data_t;

typedef struct {
    uint32_t timestamp_ms;
    float diff_pressure_pa;
    float temperature_deg;
} airspeed_data_t;

void sensor_collect(void);
fmt_err_t advertise_sensor_imu(uint8_t id);
fmt_err_t advertise_sensor_mag(uint8_t id);
fmt_err_t advertise_sensor_baro(uint8_t id);
fmt_err_t advertise_sensor_airspeed(uint8_t id);
fmt_err_t advertise_sensor_gps(uint8_t id);
fmt_err_t advertise_sensor_optflow(uint8_t id);
fmt_err_t advertise_sensor_rangefinder(uint8_t id);
fmt_err_t register_sensor_imu(const char* gyr_dev_name, const char* acc_dev_name, uint8_t id);
fmt_err_t register_sensor_mag(const char* dev_name, uint8_t id);
fmt_err_t register_sensor_barometer(const char* dev_name);
fmt_err_t register_sensor_airspeed(const char* dev_name);
fmt_err_t register_sensor_gps(const char* dev_name);

#ifdef __cplusplus
}
#endif

#endif
