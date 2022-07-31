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

#ifndef INS_INTERFACE_H__
#define INS_INTERFACE_H__

#include <INS.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    union {
        struct {
            uint32_t imu1_available : 1;
            uint32_t imu2_available : 1;
            uint32_t mag_available : 1;
            uint32_t baro_available : 1;
            uint32_t gps_available : 1;
            uint32_t sonar_available : 1;
            uint32_t optFlow_available : 1;
            uint32_t reserved : 25;
        } bit;
        uint32_t val;
    } status;
} INS_Status;

typedef struct {
    union {
        struct {
            uint32_t ready : 1;
            uint32_t standstill : 1;
            uint32_t att_valid : 1;
            uint32_t head_valid : 1;
            uint32_t vel_valid : 1;
            uint32_t WGS84_pos_valid : 1;
            uint32_t xy_R_valid : 1;
            uint32_t h_R_valid : 1;
            uint32_t h_AGL_valid : 1;
            uint32_t reserved : 23;
        } bit;
        uint32_t val;
    } flag;
} INS_Flag;

extern fmt_model_info_t ins_model_info;

void ins_interface_init(void);
void ins_interface_step(uint32_t timestamp);

#ifdef __cplusplus
}
#endif

#endif
