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

#ifndef PLANT_H__
#define PLANT_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
    #define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
    uint32_t timestamp;
    uint16_t actuator_cmd[16];
} Control_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Plant_States_Bus_
    #define DEFINED_TYPEDEF_FOR_Plant_States_Bus_

typedef struct {
    uint32_t timestamp;
    float phi;
    float theta;
    float psi;
    float rot_x_B;
    float rot_y_B;
    float rot_z_B;
    float acc_x_O;
    float acc_y_O;
    float acc_z_O;
    float vel_x_O;
    float vel_y_O;
    float vel_z_O;
    float x_R;
    float y_R;
    float h_R;
    double lon;
    double lat;
    double alt;
    double lon_ref;
    double lat_ref;
    double alt_ref;
} Plant_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Extended_States_Bus_
    #define DEFINED_TYPEDEF_FOR_Extended_States_Bus_

typedef struct {
    float temprature;
    float prop_vel[8];
    float quat[4];
    float M_BO[9];
    float M_OB[9];
} Extended_States_Bus;

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

#ifdef __cplusplus
}
#endif

#endif
