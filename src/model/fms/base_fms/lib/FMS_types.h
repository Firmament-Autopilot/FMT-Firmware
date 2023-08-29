/*
 * File: FMS_types.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2022
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 29 14:19:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FMS_types_h_
#define RTW_HEADER_FMS_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Pilot_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Pilot_Cmd_Bus_

typedef struct {
  uint32_T timestamp;

  /* Stick value of yaw channel */
  real32_T stick_yaw;

  /* Stick value of throttle channel */
  real32_T stick_throttle;

  /* Stick value of roll chanel */
  real32_T stick_roll;

  /* Stick value of pitch channel */
  real32_T stick_pitch;
  uint32_T mode;

  /* Operation channel 1 */
  uint32_T cmd_1;

  /* Operation channel 2 */
  uint32_T cmd_2;
} Pilot_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GCS_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_GCS_Cmd_Bus_

typedef struct {
  uint32_T timestamp;
  uint32_T mode;

  /* Operation channel 1 */
  uint32_T cmd_1;

  /* Operation channel 2 */
  uint32_T cmd_2;
  real32_T param[7];
} GCS_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Auto_Cmd_Bus_
#define DEFINED_TYPEDEF_FOR_Auto_Cmd_Bus_

typedef struct {
  uint32_T timestamp;

  /* rate x command in body frame */
  real32_T p_cmd;

  /* rate y command in body frame */
  real32_T q_cmd;

  /* rate z command in body frame */
  real32_T r_cmd;

  /* roll command */
  real32_T phi_cmd;

  /* pitch command */
  real32_T theta_cmd;
  real32_T psi_cmd;

  /* yaw rate command */
  real32_T psi_rate_cmd;
  real32_T x_cmd;
  real32_T y_cmd;
  real32_T z_cmd;
  int32_T lat_cmd;
  int32_T lon_cmd;
  real32_T alt_cmd;

  /* velocity x command in control frame */
  real32_T u_cmd;

  /* velocity y command in control frame */
  real32_T v_cmd;

  /* velocity z command in control frame */
  real32_T w_cmd;
  real32_T ax_cmd;
  real32_T ay_cmd;
  real32_T az_cmd;

  /* throttle command */
  uint16_T throttle_cmd;

  /* Coordinate Frame:
     0:FRAME_GLOBAL_NED
     1:FRAME_LOCAL_FRD
     2:FRAME_BODY_FRD */
  uint8_T frame;
  uint8_T reserved;

  /* Type mask for auto command:
     1: p_cmd valid
     2: q_cmd valid
     3: r_cmd valid
     4: phi_cmd valid
     5: theta_cmd valid
     6: psi__cmd_valid
     7: psi_rate_cmd_valid
     8: x_cmd valid
     9: y_cmd valid
     10: z_cmd valid
     11: lat_cmd valid
     12: lon_cmd valid
     13: alt_cmd valid
     14: u_cmd valid
     15: v_cmd valid
     16: w_cmd valid
     17: ax_cmd valid
     18: ay_cmd valid
     19: ax_cmd valid
     20: throttle_cmd valid */
  uint32_T cmd_mask;
} Auto_Cmd_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Mission_Data_Bus_
#define DEFINED_TYPEDEF_FOR_Mission_Data_Bus_

typedef struct {
  uint32_T timestamp;
  uint16_T valid_items;
  uint16_T reserved;

  /* Start from 0 */
  uint16_T seq[8];
  uint16_T command[8];
  uint8_T frame[8];
  uint8_T current[8];
  uint8_T autocontinue[8];
  uint8_T mission_type[8];
  real32_T param1[8];
  real32_T param2[8];
  real32_T param3[8];
  real32_T param4[8];
  int32_T x[8];
  int32_T y[8];
  real32_T z[8];
} Mission_Data_Bus;

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

#ifndef DEFINED_TYPEDEF_FOR_FMS_Cmd_
#define DEFINED_TYPEDEF_FOR_FMS_Cmd_

/* enumeration of FMS command */
typedef enum {
  FMS_Cmd_None = 0,                    /* Default value */
  FMS_Cmd_PreArm = 1000,
  FMS_Cmd_Arm,
  FMS_Cmd_Disarm,
  FMS_Cmd_Takeoff,
  FMS_Cmd_Land,
  FMS_Cmd_Return,
  FMS_Cmd_Pause,
  FMS_Cmd_Continue,
  FMS_Cmd_SetHome = 2000
} FMS_Cmd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PilotMode_
#define DEFINED_TYPEDEF_FOR_PilotMode_

/* enumeration of pilot mode */
typedef enum {
  PilotMode_None = 0,                  /* Default value */
  PilotMode_Manual,
  PilotMode_Acro,
  PilotMode_Stabilize,
  PilotMode_Altitude,
  PilotMode_Position,
  PilotMode_Mission,
  PilotMode_Offboard
} PilotMode;

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

#ifndef DEFINED_TYPEDEF_FOR_VehicleState_
#define DEFINED_TYPEDEF_FOR_VehicleState_

/* enumeration to track active leaf state of FMS/FMS State Machine/Vehicle */
typedef enum {
  VehicleState_None = 0,               /* Default value */
  VehicleState_Disarm,
  VehicleState_Standby,
  VehicleState_Offboard,
  VehicleState_Mission,
  VehicleState_InvalidAutoMode,
  VehicleState_Hold,
  VehicleState_Acro,
  VehicleState_Stabilize,
  VehicleState_Altitude,
  VehicleState_Position,
  VehicleState_InvalidAssistMode,
  VehicleState_Manual,
  VehicleState_InValidManualMode,
  VehicleState_InvalidArmMode,
  VehicleState_Land,
  VehicleState_Return,
  VehicleState_Takeoff
} VehicleState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ControlMode_
#define DEFINED_TYPEDEF_FOR_ControlMode_

/* enumeration of control mode */
typedef enum {
  ControlMode_None = 0,                /* Default value */
  ControlMode_Manual,
  ControlMode_Acro,
  ControlMode_Stabilize,
  ControlMode_ALTCTL,
  ControlMode_POSCTL,
  ControlMode_Offboard
} ControlMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VehicleStatus_
#define DEFINED_TYPEDEF_FOR_VehicleStatus_

/* enumeration of vehicle status */
typedef enum {
  VehicleStatus_None = 0,              /* Default value */
  VehicleStatus_Disarm,
  VehicleStatus_Standby,
  VehicleStatus_Arm
} VehicleStatus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MotionState_
#define DEFINED_TYPEDEF_FOR_MotionState_

/* enumeration of motion state */
typedef enum {
  MotionState_Hold = 0,                /* Default value */
  MotionState_Brake,
  MotionState_Move
} MotionState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Commander_In_Bus_
#define DEFINED_TYPEDEF_FOR_Commander_In_Bus_

typedef struct {
  real32_T sp_waypoint[3];
  real32_T cur_waypoint[3];

  /* The psi value when offboard mode entered,
     which is used for FRAME_LOCAL_FRD */
  real32_T offboard_psi_0;
} Commander_In_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_NAV_Cmd_
#define DEFINED_TYPEDEF_FOR_NAV_Cmd_

/* enumeration of navigation command */
typedef enum {
  NAV_Cmd_None = 0,                    /* Default value */
  NAV_Cmd_Waypoint = 16,
  NAV_Cmd_Return = 20,
  NAV_Cmd_Land,
  NAV_Cmd_Takeoff
} NAV_Cmd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BM28lLsAzRuenUNYKA2Ga_
#define DEFINED_TYPEDEF_FOR_struct_BM28lLsAzRuenUNYKA2Ga_

typedef struct {
  real32_T THROTTLE_DZ;
  real32_T YAW_DZ;
  real32_T ROLL_DZ;
  real32_T PITCH_DZ;
  real32_T XY_P;
  real32_T Z_P;
  real32_T VEL_XY_LIM;
  real32_T VEL_Z_LIM;
  real32_T YAW_P;
  real32_T YAW_RATE_LIM;
  real32_T ROLL_PITCH_LIM;
  real32_T L1;
  real32_T CRUISE_SPEED;
  real32_T TAKEOFF_H;
  real32_T TAKEOFF_SPEED;
  real32_T ACCEPT_R;
  real32_T ASSIST_LAND_H;
  real32_T LAND_SPEED;
  uint16_T LOST_RETURN_TIME;
  uint8_T LOST_RETURN_EN;
  uint16_T LAND_LOCK_THRO;
} struct_BM28lLsAzRuenUNYKA2Ga;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TYt7YeNdxIDXfczXumtXXB_
#define DEFINED_TYPEDEF_FOR_struct_TYt7YeNdxIDXfczXumtXXB_

typedef struct {
  uint32_T period;
  int8_T model_info[16];
} struct_TYt7YeNdxIDXfczXumtXXB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
  MSG_QUEUE_UNUSED = -1,               /* Default value */
  MSG_FIFO_QUEUE,
  MSG_LIFO_QUEUE,
  MSG_PRIORITY_QUEUE
} QueuePolicy_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_FMS_Cmd_
#define DEFINED_TYPEDEF_FOR_Msg_FMS_Cmd_

typedef struct {
  FMS_Cmd fData;
} Msg_FMS_Cmd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_FMS_Cmd_
#define DEFINED_TYPEDEF_FOR_Queue_FMS_Cmd_

typedef struct {
  QueuePolicy_T fPolicy;
  int32_T fHead;
  int32_T fTail;
  int32_T fCapacity;
  Msg_FMS_Cmd *fArray;
} Queue_FMS_Cmd;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_FMS_T RT_MODEL_FMS_T;

#endif                                 /* RTW_HEADER_FMS_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
