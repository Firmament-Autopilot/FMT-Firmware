/*
 * File: Controller_types.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1082
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 31 10:16:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_types_h_
#define RTW_HEADER_Controller_types_h_
#include "rtwtypes.h"
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

  /* home position [x y h yaw], unit [m m m rad] */
  real32_T home[4];
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
  real_T dx_dlat;
  real_T dy_dlon;
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

#ifndef DEFINED_TYPEDEF_FOR_struct_ny3PY9hontv4J5WqwlFzJB_
#define DEFINED_TYPEDEF_FOR_struct_ny3PY9hontv4J5WqwlFzJB_

typedef struct {
  uint32_T period;
  int8_T model_info[21];
} struct_ny3PY9hontv4J5WqwlFzJB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_MB1PRNEC9lKcTJkzJ82htE_
#define DEFINED_TYPEDEF_FOR_struct_MB1PRNEC9lKcTJkzJ82htE_

typedef struct {
  real32_T ROLL_P;
  real32_T PITCH_P;
  real32_T ROLL_PITCH_CMD_LIM;
  real32_T ROLL_RATE_P;
  real32_T PITCH_RATE_P;
  real32_T YAW_RATE_P;
  real32_T ROLL_RATE_I;
  real32_T PITCH_RATE_I;
  real32_T YAW_RATE_I;
  real32_T RATE_I_MIN;
  real32_T RATE_I_MAX;
  real32_T P_Q_CMD_LIM;
  real32_T R_CMD_LIM;
  real32_T FW_AIRSPEED_TRIM;
  real32_T FW_FF;
  real32_T FW_FF_LIMIT;
  real32_T FW_PI_LIMIT;
  real32_T FW_ROLL_EFFC;
  real32_T FW_PITCH_EFFC;
  real32_T FW_YAW_EFFC;
  real32_T FW_PITCH_OFFSET;
  real32_T FW_TECS_PITCH_F;
  real32_T FW_TECS_THOR_FF;
  real32_T FW_TECS_PITCH_P;
  real32_T FW_TECS_THOR_P;
  real32_T FW_TECS_PITCH_I;
  real32_T FW_TECS_THOR_I;
  real32_T FW_TECS_PITCH_D;
  real32_T FW_TECS_THOR_D;
  real32_T FW_TECS_RATIO;
  real32_T FW_TECS_SWITCH;
  real32_T FW_TECS_ANSW;
  real32_T FW_TECS_W2T;
  real32_T FW_TECS_U2T;
  real32_T FW_TECS_W2P;
  real32_T FW_TECS_U2P;
  real32_T FW_TECS_R2P;
  real32_T FW_TECS_R2T;
  real32_T FW_TECS_PITCH_I_LIM;
} struct_MB1PRNEC9lKcTJkzJ82htE;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif                                 /* RTW_HEADER_Controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
