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
#include "rtwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
    #define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
    uint32_T timestamp;
    uint16_T actuator_cmd[16];
} Control_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Plant_States_Bus_
    #define DEFINED_TYPEDEF_FOR_Plant_States_Bus_

typedef struct {
    uint32_T timestamp;
    real32_T phi;
    real32_T theta;
    real32_T psi;
    real32_T rot_x_B;
    real32_T rot_y_B;
    real32_T rot_z_B;
    real32_T acc_x_O;
    real32_T acc_y_O;
    real32_T acc_z_O;
    real32_T vel_x_O;
    real32_T vel_y_O;
    real32_T vel_z_O;
    real32_T x_R;
    real32_T y_R;
    real32_T h_R;
    real_T lat;
    real_T lon;
    real_T alt;
    real_T lat_0;
    real_T lon_0;
    real_T alt_0;
} Plant_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Extended_States_Bus_
    #define DEFINED_TYPEDEF_FOR_Extended_States_Bus_

typedef struct {
    real32_T temprature;
    real32_T prop_vel[8];
    real32_T quat[4];
    real32_T M_BO[9];
    real32_T M_OB[9];
} Extended_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Barometer_Bus_
    #define DEFINED_TYPEDEF_FOR_Barometer_Bus_

typedef struct {
    uint32_T timestamp;
    real32_T pressure;
    real32_T temperature;
} Barometer_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_
    #define DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_

typedef struct {
    uint32_T timestamp;
    uint32_T iTOW;
    uint16_T year;
    uint8_T month;
    uint8_T day;
    uint8_T hour;
    uint8_T min;
    uint8_T sec;
    uint8_T valid;
    uint32_T tAcc;
    int32_T nano;
    uint8_T fixType;
    uint8_T flags;
    uint8_T reserved1;
    uint8_T numSV;
    int32_T lon;
    int32_T lat;
    int32_T height;
    int32_T hMSL;
    uint32_T hAcc;
    uint32_T vAcc;
    int32_T velN;
    int32_T velE;
    int32_T velD;
    int32_T gSpeed;
    int32_T heading;
    uint32_T sAcc;
    uint32_T headingAcc;
    uint16_T pDOP;
    uint16_T reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
    #define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
    uint32_T timestamp;
    real32_T gyr_x;
    real32_T gyr_y;
    real32_T gyr_z;
    real32_T acc_x;
    real32_T acc_y;
    real32_T acc_z;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MAG_Bus_
    #define DEFINED_TYPEDEF_FOR_MAG_Bus_

typedef struct {
    uint32_T timestamp;
    real32_T mag_x;
    real32_T mag_y;
    real32_T mag_z;
} MAG_Bus;

#endif

#ifdef __cplusplus
}
#endif

#endif
