/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#ifndef INS_H__
#define INS_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
    #define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
    uint32_t timestamp;
    float gyr_x;
    float gyr_y;
    float gyr_z;
    float acc_x;
    float acc_y;
    float acc_z;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MAG_Bus_
    #define DEFINED_TYPEDEF_FOR_MAG_Bus_

typedef struct {
    uint32_t timestamp;
    float mag_x;
    float mag_y;
    float mag_z;
} MAG_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Barometer_Bus_
    #define DEFINED_TYPEDEF_FOR_Barometer_Bus_

typedef struct {
    uint32_t timestamp;
    float pressure;
    float temperature;
} Barometer_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_
    #define DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_

typedef struct {
    uint32_t timestamp;
    uint32_t iTOW;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint8_t valid;
    uint32_t tAcc;
    int32_t nano;
    uint8_t fixType;
    uint8_t flags;
    uint8_t reserved1;
    uint8_t numSV;
    int32_t lon;
    int32_t lat;
    int32_t height;
    int32_t hMSL;
    uint32_t hAcc;
    uint32_t vAcc;
    int32_t velN;
    int32_t velE;
    int32_t velD;
    int32_t gSpeed;
    int32_t heading;
    uint32_t sAcc;
    uint32_t headingAcc;
    uint16_t pDOP;
    uint16_t reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rangefinder_Bus_
    #define DEFINED_TYPEDEF_FOR_Rangefinder_Bus_

typedef struct {
    uint32_t timestamp;
    float distance_m;
} Rangefinder_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_
    #define DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_

typedef struct {
    uint32_t timestamp;
    float vx;
    float vy;
    uint32_t valid;
} Optical_Flow_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
    #define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
    uint32_t timestamp;
    float phi;
    float theta;
    float psi;
    float quat[4];
    float p;
    float q;
    float r;
    float ax;
    float ay;
    float az;
    float vn;
    float ve;
    float vd;
    float airspeed;
    double lon;
    double lat;
    double alt;
    float x_R;
    float y_R;
    float h_R;
    float h_AGL;
    uint32_t flag;
    uint32_t status;
} INS_Out_Bus;

#endif

#ifdef __cplusplus
}
#endif

#endif
