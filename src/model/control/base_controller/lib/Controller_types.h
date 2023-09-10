/*
 * File: Controller_types.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.968
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 10 08:50:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_types_h_
#define RTW_HEADER_Controller_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
/**
 * Variant choices for normal variant control variables can be selected via:
 *  1. -DVC_VARIABLE1=VALUE1 -DVC_VARIABLE2=VALUE2 *  2. -DUSE_VARIANT_DEFINES_HEADER="header.h"  (header.h contains #define's)
 *
 * Given a variant control expression in a Variant block such as "V==1", V is a
 * variant control variable. A normal variant control variable is a plain MATLAB
 * variable, i.e. not a Simulink.Parameter. By default the value defined for a
 * normal variant control variable is the value seen when generating code.
 * Alternatively, you can use Simulink.Parameter variant control variables to
 * specify code generation behavior.
 */
#ifdef USE_VARIANT_DEFINES_HEADER
#define VARIANT_DEFINES_HEADER_STR(h)  #h
#define VARIANT_DEFINES_HEADER(h)      VARIANT_DEFINES_HEADER_STR(h)
#include VARIANT_DEFINES_HEADER(USE_VARIANT_DEFINES_HEADER)
#endif                                 /* USE_VARIANT_DEFINES_HEADER */

/*
 * Validate the variant control variables are consistent with the model requirements
 */
#ifndef AIRFRAME
#define AIRFRAME                       1
#endif

/* Exactly one variant for '<S2>/Control_Allocation' should be active */
#if ((AIRFRAME == 6) ? 1 : 0) + ((AIRFRAME == 3) ? 1 : 0) + ((AIRFRAME == 5) ? 1 : 0) + ((AIRFRAME == 4) ? 1 : 0) + ((AIRFRAME == 8) ? 1 : 0) + ((AIRFRAME == 7) ? 1 : 0) + ((AIRFRAME == 2) ? 1 : 0) + ((AIRFRAME == 1) ? 1 : 0) != 1
#error Exactly one variant for '<S2>/Control_Allocation' should be active
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

#ifndef DEFINED_TYPEDEF_FOR_struct_biZzOMrg0u3lxrb7POOubF_
#define DEFINED_TYPEDEF_FOR_struct_biZzOMrg0u3lxrb7POOubF_

typedef struct {
  uint32_T period;
  int8_T model_info[23];
} struct_biZzOMrg0u3lxrb7POOubF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_2EnWz3ceFwjQa7SDRNn3C_
#define DEFINED_TYPEDEF_FOR_struct_2EnWz3ceFwjQa7SDRNn3C_

typedef struct {
  real32_T VEL_XY_P;
  real32_T VEL_XY_I;
  real32_T VEL_XY_D;
  real32_T VEL_Z_P;
  real32_T VEL_Z_I;
  real32_T VEL_Z_D;
  real32_T VEL_XY_I_MIN;
  real32_T VEL_XY_I_MAX;
  real32_T VEL_XY_D_MIN;
  real32_T VEL_XY_D_MAX;
  real32_T VEL_Z_I_MIN;
  real32_T VEL_Z_I_MAX;
  real32_T VEL_Z_D_MIN;
  real32_T VEL_Z_D_MAX;
  real32_T ROLL_P;
  real32_T PITCH_P;
  real32_T ROLL_PITCH_CMD_LIM;
  real32_T ROLL_RATE_P;
  real32_T PITCH_RATE_P;
  real32_T YAW_RATE_P;
  real32_T ROLL_RATE_I;
  real32_T PITCH_RATE_I;
  real32_T YAW_RATE_I;
  real32_T ROLL_RATE_D;
  real32_T PITCH_RATE_D;
  real32_T YAW_RATE_D;
  real32_T RATE_I_MIN;
  real32_T RATE_I_MAX;
  real32_T RATE_D_MIN;
  real32_T RATE_D_MAX;
  real32_T P_Q_CMD_LIM;
  real32_T R_CMD_LIM;
  real32_T HOVER_THRO;
} struct_2EnWz3ceFwjQa7SDRNn3C;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif                                 /* RTW_HEADER_Controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
