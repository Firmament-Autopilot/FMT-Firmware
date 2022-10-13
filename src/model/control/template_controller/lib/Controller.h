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

#ifndef CONTROLLER_H__
#define CONTROLLER_H__

#include <firmament.h>
#include "rtwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEFINED_TYPEDEF_FOR_FMS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_FMS_Out_Bus_

typedef struct {
  /* fms output timestamp */
  uint32_T timestamp;

  /* roll rate command in body frame */
  real32_T p_cmd;

  /* pitch rate command in body frame */
  real32_T q_cmd;

  /* yaw rate command in body frame */
  real32_T r_cmd;

  /* roll command in body frame */
  real32_T phi_cmd;

  /* pitch command in body frame */
  real32_T theta_cmd;

  /* yaw rate command in body frame */
  real32_T psi_rate_cmd;

  /* velocity x command in control frame */
  real32_T u_cmd;

  /* velocity y command in control frame */
  real32_T v_cmd;

  /* velocity z command in control frame */
  real32_T w_cmd;

  /* acceleration x command in control frame */
  real32_T ax_cmd;

  /* acceleration y command in control frame */
  real32_T ay_cmd;

  /* acceleration z command in control frame */
  real32_T az_cmd;

  /* actuator command */
  uint16_T actuator_cmd[16];

  /* throttle command */
  uint16_T throttle_cmd;

  /* Type mask for offboard mode:
     1: p_cmd valid
     2: q_cmd valid
     3: r_cmd valid
     4: phi_cmd valid
     5: theta_cmd valid
     6: psi_rate_cmd_valid
     7: u_cmd valid
     8: v_cmd valid
     9: w_cmd valid
     10: ax_cmd valid
     11: ay_cmd valid
     12: ax_cmd valid
     13: throttle_cmd valid */
  uint16_T cmd_mask;

  /* enum VehicleStatus

     vehicle status:
     0: None
     1: Disarm
     2: Standby
     3: Arm */
  uint8_T status;

  /* enum VehicleState

     vehicle state:
     0: None
     1: Disarm
     2: Standby
     3: Offboard
     4: Mission
     5: InvalidAutoMode
     6: Hold
     7: Acro
     8: Stabilize
     9: Altitude
     10: Position
     11: InvalidAssistMode
     12: Manual
     13: InvalidManualMode
     14: InvalidArmMode
     15: Land
     16: Return
     17: Takeoff */
  uint8_T state;

  /* enum ControlMode

     control mode:
     0: None
     1: Manual
     2: Acro
     3: Stabilize
     4: ALTCTL
     5: POSCTL */
  uint8_T ctrl_mode;

  /* enum PilotMode

     pilot mode:
     0: None
     1: Manual
     2: Acro
     3: Stabilize
     4: Altitude
     5: Position
     6: Mission
     7: Offboard */
  uint8_T mode;

  /* reset the controller */
  uint8_T reset;

  /* consumed waypoints */
  uint8_T wp_consume;

  /* current waypoint */
  uint8_T wp_current;

  /* enum of PilotMode */
  uint8_T reserved;
} FMS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T phi;
  real32_T theta;
  real32_T psi;
  real32_T quat[4];
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T ax;
  real32_T ay;
  real32_T az;
  real32_T vn;
  real32_T ve;
  real32_T vd;
  real32_T airspeed;
  real_T lat;
  real_T lon;
  real_T alt;
  real_T lat_0;
  real_T lon_0;
  real_T alt_0;
  real32_T x_R;
  real32_T y_R;
  real32_T h_R;
  real32_T h_AGL;
  uint32_T flag;
  uint32_T status;
} INS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
  uint32_T timestamp;
  uint16_T actuator_cmd[16];
} Control_Out_Bus;

#endif

#ifdef __cplusplus
}
#endif

#endif
