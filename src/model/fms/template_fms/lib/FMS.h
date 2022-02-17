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

#ifndef FMS_H__
#define FMS_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEFINED_TYPEDEF_FOR_Pilot_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Pilot_Cmd_Bus_

typedef struct {
  uint32_t timestamp;
  float ls_lr;
  float ls_ud;
  float rs_lr;
  float rs_ud;
  uint32_t mode;
  uint32_t cmd_1;
  uint32_t cmd_2;
} Pilot_Cmd_Bus;

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
  float reserved;
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

#ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
  uint32_t timestamp;
  uint16_t actuator_cmd[16];
} Control_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FMS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_FMS_Out_Bus_

typedef struct {
  uint32_t timestamp;
  float p_cmd;
  float q_cmd;
  float r_cmd;
  float phi_cmd;
  float theta_cmd;
  float psi_rate_cmd;
  float u_cmd;
  float v_cmd;
  float w_cmd;
  uint32_t throttle_cmd;
  uint16_t actuator_cmd[16];
  uint8_t state;
  uint8_t mode;
  uint8_t reset;
  uint8_t reserved;
} FMS_Out_Bus;

#endif

#ifdef __cplusplus
}
#endif

#endif
