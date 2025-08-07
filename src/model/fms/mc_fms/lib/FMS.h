/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2228
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug  7 10:16:57 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FMS_h_
#define RTW_HEADER_FMS_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#ifndef FMS_COMMON_INCLUDES_
# define FMS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FMS_COMMON_INCLUDES_ */

#include "FMS_types.h"
#include "arm_math.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S436>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S439>/Delay' */
  uint8_T icLoad;                      /* '<S439>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S436>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S443>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S443>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S437>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S437>/Motion Status' */
  uint8_T is_active_c10_FMS;           /* '<S437>/Motion Status' */
  uint8_T is_c10_FMS;                  /* '<S437>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S446>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S449>/Delay' */
  uint8_T icLoad;                      /* '<S449>/Delay' */
} DW_HoldControl_FMS_j_T;

/* Block states (default storage) for system '<S446>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S456>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S456>/Integrator' */
} DW_MoveControl_FMS_f_T;

/* Block states (default storage) for system '<S447>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S447>/Motion State' */
  uint8_T is_active_c23_FMS;           /* '<S447>/Motion State' */
  uint8_T is_c23_FMS;                  /* '<S447>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S366>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S369>/Delay' */
  uint8_T icLoad;                      /* '<S369>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S366>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S375>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S375>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S143>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S143>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S143>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S143>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S52>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S52>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S52>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S52>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  Commander_In_Bus Cmd_In;             /* '<Root>/FMS State Machine' */
  real_T degrade;                      /* '<Root>/SafeMode' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real_T lla[3];                       /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T href;                         /* '<Root>/FMS State Machine' */
  real_T psio;                         /* '<Root>/FMS State Machine' */
  uint32_T Add;                        /* '<S488>/Add' */
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T DataTypeConversion[3];      /* '<S490>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S491>/Reshape' */
  real32_T Merge[2];                   /* '<S113>/Merge' */
  real32_T Merge_k;                    /* '<S88>/Merge' */
  real32_T Merge_d;                    /* '<S100>/Merge' */
  real32_T Merge_l;                    /* '<S51>/Merge' */
  real32_T Merge_m;                    /* '<S72>/Merge' */
  real32_T Merge_j;                    /* '<S142>/Merge' */
  real32_T Merge_n[2];                 /* '<S206>/Merge' */
  real32_T Merge_e;                    /* '<S196>/Merge' */
  real32_T Merge_o[2];                 /* '<S378>/Merge' */
  real32_T Merge_ey;                   /* '<S356>/Merge' */
  real32_T Merge_n1;                   /* '<S366>/Merge' */
  real32_T Merge_a[2];                 /* '<S446>/Merge' */
  real32_T Merge_jj;                   /* '<S436>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S14>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T Compare;                   /* '<S29>/Compare' */
  boolean_T on_ground;                 /* '<S7>/Logical Operator1' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare_k;                 /* '<S503>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission_takeoff;         /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_i[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_b;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S504>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S506>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S505>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE[2];      /* '<S123>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S123>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S115>/Delay' */
  real32_T Integrator1_DSTATE_g;       /* '<S66>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S66>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S67>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S67>/Integrator' */
  real32_T Integrator1_DSTATE_k;       /* '<S136>/Integrator1' */
  real32_T Integrator_DSTATE_a;        /* '<S136>/Integrator' */
  real32_T Integrator1_DSTATE_n;       /* '<S137>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S137>/Integrator' */
  real32_T Delay_DSTATE_p[2];          /* '<S185>/Delay' */
  real32_T Acceleration_Speed_DSTATE;  /* '<S181>/Acceleration_Speed' */
  real32_T l1_heading;                 /* '<S233>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S163>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S166>/Integrator1' */
  real32_T Integrator_DSTATE_ip;       /* '<S166>/Integrator' */
  real32_T Delay_DSTATE_e[2];          /* '<S425>/Delay' */
  real32_T Acceleration_Speed_DSTATE_j;/* '<S421>/Acceleration_Speed' */
  real32_T l1_heading_e;               /* '<S473>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_a;             /* '<S403>/Delay' */
  real32_T Integrator1_DSTATE_eh;      /* '<S406>/Integrator1' */
  real32_T Delay_DSTATE_px[2];         /* '<S402>/Delay' */
  real32_T Integrator_DSTATE_bs;       /* '<S406>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S394>/Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S394>/Integrator' */
  real32_T cur_waypoint_DSTATE[3];     /* '<S486>/cur_waypoint' */
  real32_T Integrator1_DSTATE_a;       /* '<S482>/Integrator1' */
  real32_T Integrator_DSTATE_m;        /* '<S482>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S19>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S20>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S17>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S13>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S24>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S25>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S26>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S10>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S489>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_c;            /* '<S15>/Delay' */
  real32_T home[4];                    /* '<Root>/Data Store Memory' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_k;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n5;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_b;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2_n;/* '<Root>/FMS State Machine' */
  int32_T M_qId;                       /* '<Root>/FMS State Machine' */
  uint32_T flag_prev;                  /* '<Root>/SafeMode' */
  uint32_T flag_start;                 /* '<Root>/SafeMode' */
  uint32_T temporalCounter_i1;         /* '<Root>/FMS State Machine' */
  uint32_T mission_timestamp_prev;     /* '<Root>/FMS State Machine' */
  uint32_T mission_timestamp_start;    /* '<Root>/FMS State Machine' */
  FMS_Cmd M;                           /* '<Root>/FMS State Machine' */
  FMS_Cmd save_cmd;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_prev;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_start;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgData;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgReservedData;           /* '<Root>/FMS State Machine' */
  PilotMode mode_prev;                 /* '<Root>/SafeMode' */
  PilotMode mode_start;                /* '<Root>/SafeMode' */
  PilotMode mode_prev_n;               /* '<Root>/FMS State Machine' */
  PilotMode mode_start_a;              /* '<Root>/FMS State Machine' */
  uint16_T nav_cmd;                    /* '<Root>/FMS State Machine' */
  uint16_T temporalCounter_i1_i;       /* '<S114>/Motion State' */
  uint8_T Delay_DSTATE_o;              /* '<S11>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S158>/Delay Input1' */
  uint8_T DiscreteTimeIntegrator_DSTATE_k;/* '<S186>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_DSTATE_m;/* '<S426>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S30>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S32>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S36>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S88>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S113>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S100>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S51>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S72>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S142>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S37>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetSta;/* '<S181>/Acceleration_Speed' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S206>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S196>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S39>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S378>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S356>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S366>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetS_j;/* '<S421>/Acceleration_Speed' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S446>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_ld;/* '<S436>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S504>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S506>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S505>/Discrete-Time Integrator5' */
  uint8_T is_active_c1_FMS;            /* '<Root>/SafeMode' */
  uint8_T is_Mode;                     /* '<Root>/SafeMode' */
  uint8_T is_active_c11_FMS;           /* '<Root>/FMS State Machine' */
  uint8_T is_Command_Listener;         /* '<Root>/FMS State Machine' */
  uint8_T is_active_Command_Listener;  /* '<Root>/FMS State Machine' */
  uint8_T is_Vehicle;                  /* '<Root>/FMS State Machine' */
  uint8_T is_active_Vehicle;           /* '<Root>/FMS State Machine' */
  uint8_T is_Arm;                      /* '<Root>/FMS State Machine' */
  uint8_T is_SubMode;                  /* '<Root>/FMS State Machine' */
  uint8_T is_Auto;                     /* '<Root>/FMS State Machine' */
  uint8_T is_Offboard;                 /* '<Root>/FMS State Machine' */
  uint8_T is_Mission;                  /* '<Root>/FMS State Machine' */
  uint8_T is_Assist;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Manual;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Combo_Stick;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Combo_Stick;       /* '<Root>/FMS State Machine' */
  uint8_T is_Lost_Return;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Lost_Return;       /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S114>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S114>/Motion State' */
  uint8_T icLoad;                      /* '<S115>/Delay' */
  uint8_T icLoad_i;                    /* '<S185>/Delay' */
  uint8_T icLoad_k;                    /* '<S163>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S166>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S367>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S367>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S367>/Motion State' */
  uint8_T icLoad_l;                    /* '<S425>/Delay' */
  uint8_T icLoad_j;                    /* '<S403>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S406>/Integrator1' */
  uint8_T icLoad_c;                    /* '<S402>/Delay' */
  uint8_T icLoad_j1;                   /* '<S486>/cur_waypoint' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_k;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_b;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h0;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_b;/* '<Root>/FMS State Machine' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S101>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_mr;/* '<S100>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S100>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S89>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S88>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S73>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_cr;/* '<S72>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S72>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S52>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S51>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S143>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S142>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S142>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S207>/Motion State' */
  DW_MoveControl_FMS_f_T MoveControl_c;/* '<S206>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_d;/* '<S206>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S197>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S196>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S196>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S379>/Motion State' */
  DW_MoveControl_FMS_f_T MoveControl_i;/* '<S378>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_f;/* '<S378>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S366>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_k;/* '<S366>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S357>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S356>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S356>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S447>/Motion State' */
  DW_MoveControl_FMS_f_T MoveControl_j;/* '<S446>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_m;/* '<S446>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S437>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S436>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S436>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S155>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S14>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S436>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S444>/Square' */
  const real32_T d;                    /* '<S444>/Multiply' */
  const real32_T Gain4;                /* '<S444>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S446>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S453>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_f_T;

/* Invariant block signals for system '<S446>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S457>/Square' */
  const real32_T d;                    /* '<S457>/Multiply' */
  const real32_T Gain4;                /* '<S457>/Gain4' */
} ConstB_MoveControl_FMS_i_T;

/* Invariant block signals for system '<S366>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S376>/Square' */
  const real32_T d;                    /* '<S376>/Multiply' */
  const real32_T Gain4;                /* '<S376>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S39>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S352>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S352>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S494>/Sum' */
  const real_T ff;                     /* '<S494>/Multiply3' */
  const real_T Sum4;                   /* '<S494>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S329>/Sum' */
  const real_T ff;                     /* '<S329>/Multiply3' */
  const real_T Sum4;                   /* '<S329>/Sum4' */
  const real_T deg2rad2;               /* '<S328>/deg2rad2' */
  const real_T SinCos_o1;              /* '<S331>/SinCos' */
  const real_T SinCos_o2;              /* '<S331>/SinCos' */
  const real32_T Square;               /* '<S126>/Square' */
  const real32_T VectorConcatenate3[3];/* '<S119>/Vector Concatenate3' */
  const real32_T Square_j;             /* '<S70>/Square' */
  const real32_T Square_c;             /* '<S71>/Square' */
  const real32_T Square_ct;            /* '<S140>/Square' */
  const real32_T Square_b;             /* '<S141>/Square' */
  const real32_T VectorConcatenate3_e[3];/* '<S236>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S176>/Math Function' */
  const real32_T SumofElements;        /* '<S176>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S176>/Math Function1' */
  const real32_T Product[2];           /* '<S176>/Product' */
  const real32_T Switch[3];            /* '<S176>/Switch' */
  const real32_T Divide[2];            /* '<S176>/Divide' */
  const real32_T Square_g;             /* '<S172>/Square' */
  const real32_T d;                    /* '<S172>/Multiply' */
  const real32_T Gain4;                /* '<S172>/Gain4' */
  const real32_T VectorConcatenate3_n[3];/* '<S313>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_i[3];/* '<S317>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_a[3];/* '<S323>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e0[3];/* '<S321>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_ny[3];/* '<S320>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e1[3];/* '<S249>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S251>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S345>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_iz[3];/* '<S347>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_c[3];/* '<S476>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S416>/Math Function' */
  const real32_T SumofElements_p;      /* '<S416>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S416>/Math Function1' */
  const real32_T Product_c[2];         /* '<S416>/Product' */
  const real32_T Switch_h[3];          /* '<S416>/Switch' */
  const real32_T Divide_d[2];          /* '<S416>/Divide' */
  const real32_T Square_k;             /* '<S412>/Square' */
  const real32_T d_l;                  /* '<S412>/Multiply' */
  const real32_T Gain4_n;              /* '<S412>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S399>/Vector Concatenate3' */
  const real32_T Square_e;             /* '<S395>/Square' */
  const real32_T d_p;                  /* '<S395>/Multiply' */
  const real32_T Gain4_e;              /* '<S395>/Gain4' */
  const real32_T VectorConcatenate3_fb[3];/* '<S487>/Vector Concatenate3' */
  const real32_T Square_bz;            /* '<S483>/Square' */
  const real32_T d_m;                  /* '<S483>/Multiply' */
  const real32_T Gain4_a;              /* '<S483>/Gain4' */
  const uint8_T DataTypeConversion;    /* '<S38>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S38>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S43>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S43>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S43>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S42>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S42>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S42>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S44>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S44>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S44>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S41>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S41>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S41>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S159>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S159>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S159>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S156>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S156>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S156>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S348>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S348>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S348>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S350>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S350>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S350>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S349>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S349>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S349>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S351>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S351>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S351>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S35>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S35>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S34>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S34>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S32>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S36>/Unknown' */
  ConstB_MoveControl_FMS_f_T MoveControl_mr;/* '<S100>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_cr;/* '<S72>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S142>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S37>/Unknown' */
  ConstB_MoveControl_FMS_i_T MoveControl_c;/* '<S206>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_d;/* '<S206>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S196>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S39>/Unknown' */
  ConstB_MoveControl_FMS_i_T MoveControl_i;/* '<S378>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_f;/* '<S378>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S366>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S356>/Move Control' */
  ConstB_MoveControl_FMS_i_T MoveControl_j;/* '<S446>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_m;/* '<S446>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S436>/Move Control' */
} ConstB_FMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Pilot_Cmd_Bus Pilot_Cmd;             /* '<Root>/Pilot_Cmd' */
  GCS_Cmd_Bus GCS_Cmd;                 /* '<Root>/GCS_Cmd' */
  Auto_Cmd_Bus Auto_Cmd;               /* '<Root>/Auto_Cmd' */
  Mission_Data_Bus Mission_Data;       /* '<Root>/Mission_Data' */
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
} ExtU_FMS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  FMS_Out_Bus FMS_Out;                 /* '<Root>/FMS_Out' */
} ExtY_FMS_T;

/* Real-time Model Data Structure */
struct tag_RTM_FMS_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_FMS_T FMS_B;

/* Block states (default storage) */
extern DW_FMS_T FMS_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_FMS_T FMS_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_FMS_T FMS_Y;

/* External data declarations for dependent source files */
extern const FMS_Out_Bus FMS_rtZFMS_Out_Bus;/* FMS_Out_Bus ground */
extern const ConstB_FMS_T FMS_ConstB;  /* constant block i/o */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_xXeuwAPh0ajaUfdgPpGaUB FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S3>/Constant1'
                                                *   '<S7>/Land_Lock_Thro'
                                                *   '<S28>/Constant'
                                                *   '<S491>/Constant'
                                                *   '<S350>/L1'
                                                *   '<S49>/Gain'
                                                *   '<S49>/Gain1'
                                                *   '<S130>/Gain'
                                                *   '<S130>/Gain1'
                                                *   '<S132>/Constant'
                                                *   '<S159>/L1'
                                                *   '<S240>/Saturation'
                                                *   '<S241>/Saturation1'
                                                *   '<S241>/Saturation2'
                                                *   '<S241>/Saturation3'
                                                *   '<S391>/Land_Speed'
                                                *   '<S392>/Saturation1'
                                                *   '<S478>/Takeoff_Speed'
                                                *   '<S479>/Gain2'
                                                *   '<S479>/Saturation1'
                                                *   '<S51>/Saturation1'
                                                *   '<S64>/Dead Zone'
                                                *   '<S64>/Gain'
                                                *   '<S65>/Dead Zone'
                                                *   '<S65>/Gain'
                                                *   '<S66>/Constant'
                                                *   '<S67>/Constant'
                                                *   '<S72>/Saturation'
                                                *   '<S88>/Saturation1'
                                                *   '<S100>/Saturation'
                                                *   '<S113>/Saturation1'
                                                *   '<S134>/Dead Zone'
                                                *   '<S134>/Gain'
                                                *   '<S135>/Dead Zone'
                                                *   '<S135>/Gain'
                                                *   '<S136>/Constant'
                                                *   '<S137>/Constant'
                                                *   '<S142>/Saturation'
                                                *   '<S296>/Gain2'
                                                *   '<S303>/Gain1'
                                                *   '<S303>/Gain2'
                                                *   '<S356>/Saturation1'
                                                *   '<S366>/Saturation'
                                                *   '<S378>/Saturation1'
                                                *   '<S393>/Constant'
                                                *   '<S396>/Gain2'
                                                *   '<S418>/Gain'
                                                *   '<S418>/Saturation1'
                                                *   '<S421>/Constant'
                                                *   '<S421>/vel'
                                                *   '<S421>/Switch'
                                                *   '<S54>/Gain2'
                                                *   '<S55>/Gain1'
                                                *   '<S61>/Constant'
                                                *   '<S75>/Gain2'
                                                *   '<S76>/Gain1'
                                                *   '<S83>/Constant'
                                                *   '<S91>/Gain2'
                                                *   '<S92>/Gain1'
                                                *   '<S98>/Constant'
                                                *   '<S103>/Gain2'
                                                *   '<S104>/Gain1'
                                                *   '<S111>/Constant'
                                                *   '<S115>/Gain2'
                                                *   '<S116>/Gain6'
                                                *   '<S127>/Constant'
                                                *   '<S128>/Constant'
                                                *   '<S145>/Gain2'
                                                *   '<S146>/Gain1'
                                                *   '<S153>/Constant'
                                                *   '<S178>/Gain'
                                                *   '<S178>/Saturation1'
                                                *   '<S181>/Constant'
                                                *   '<S181>/vel'
                                                *   '<S181>/Switch'
                                                *   '<S359>/Gain2'
                                                *   '<S360>/Gain1'
                                                *   '<S369>/Gain2'
                                                *   '<S370>/Gain1'
                                                *   '<S381>/Gain2'
                                                *   '<S382>/Gain6'
                                                *   '<S405>/Gain2'
                                                *   '<S405>/Saturation'
                                                *   '<S406>/Integrator'
                                                *   '<S57>/Land_Speed'
                                                *   '<S58>/Constant'
                                                *   '<S60>/Dead Zone'
                                                *   '<S60>/Gain'
                                                *   '<S80>/Dead Zone'
                                                *   '<S80>/Gain'
                                                *   '<S94>/Land_Speed'
                                                *   '<S95>/Constant'
                                                *   '<S97>/Dead Zone'
                                                *   '<S97>/Gain'
                                                *   '<S108>/Dead Zone'
                                                *   '<S108>/Gain'
                                                *   '<S121>/Dead Zone'
                                                *   '<S121>/Gain'
                                                *   '<S122>/Dead Zone'
                                                *   '<S122>/Gain'
                                                *   '<S123>/Constant'
                                                *   '<S150>/Dead Zone'
                                                *   '<S150>/Gain'
                                                *   '<S165>/Gain2'
                                                *   '<S165>/Saturation'
                                                *   '<S166>/Integrator'
                                                *   '<S362>/Dead Zone'
                                                *   '<S362>/Gain'
                                                *   '<S374>/Dead Zone'
                                                *   '<S374>/Gain'
                                                *   '<S386>/Dead Zone'
                                                *   '<S386>/Gain'
                                                *   '<S387>/Dead Zone'
                                                *   '<S387>/Gain'
                                                *   '<S436>/Saturation1'
                                                *   '<S446>/Saturation1'
                                                *   '<S196>/Saturation1'
                                                *   '<S206>/Saturation1'
                                                *   '<S439>/Gain2'
                                                *   '<S440>/Gain1'
                                                *   '<S449>/Gain2'
                                                *   '<S450>/Gain6'
                                                *   '<S199>/Gain2'
                                                *   '<S200>/Gain1'
                                                *   '<S209>/Gain2'
                                                *   '<S210>/Gain6'
                                                *   '<S442>/Dead Zone'
                                                *   '<S442>/Gain'
                                                *   '<S454>/Dead Zone'
                                                *   '<S454>/Gain'
                                                *   '<S455>/Dead Zone'
                                                *   '<S455>/Gain'
                                                *   '<S202>/Dead Zone'
                                                *   '<S202>/Gain'
                                                *   '<S214>/Dead Zone'
                                                *   '<S214>/Gain'
                                                *   '<S215>/Dead Zone'
                                                *   '<S215>/Gain'
                                                */
extern struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S13>/Constant1'
                                                 *   '<S489>/Constant'
                                                 */

/* Model entry point functions */
extern void FMS_init(void);
extern void FMS_step(void);
extern void FMS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FMS_T *const FMS_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Propagation' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Propagation' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S416>/Data Type Duplicate' : Unused code path elimination
 * Block '<S417>/Data Type Duplicate' : Unused code path elimination
 * Block '<S431>/Data Type Duplicate' : Unused code path elimination
 * Block '<S431>/Data Type Propagation' : Unused code path elimination
 * Block '<S432>/Data Type Duplicate' : Unused code path elimination
 * Block '<S432>/Data Type Propagation' : Unused code path elimination
 * Block '<S470>/Data Type Duplicate' : Unused code path elimination
 * Block '<S471>/Data Type Duplicate' : Unused code path elimination
 * Block '<S467>/Data Type Duplicate' : Unused code path elimination
 * Block '<S468>/Data Type Duplicate' : Unused code path elimination
 * Block '<S474>/Data Type Duplicate' : Unused code path elimination
 * Block '<S507>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Reshape' : Reshape block reduction
 * Block '<S162>/Reshape' : Reshape block reduction
 * Block '<S162>/Reshape1' : Reshape block reduction
 * Block '<S162>/Reshape2' : Reshape block reduction
 * Block '<S423>/Reshape' : Reshape block reduction
 * Block '<S402>/Reshape' : Reshape block reduction
 * Block '<S402>/Reshape1' : Reshape block reduction
 * Block '<S402>/Reshape2' : Reshape block reduction
 * Block '<S486>/Reshape' : Reshape block reduction
 * Block '<S489>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S31>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S31>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S31>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S31>/Signal Copy7' : Eliminate redundant signal conversion block
 * Block '<S490>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S504>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S505>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FMS'
 * '<S1>'   : 'FMS/Auto_Cmd_Valid'
 * '<S2>'   : 'FMS/Command Process'
 * '<S3>'   : 'FMS/Detect_Lost_Connect'
 * '<S4>'   : 'FMS/Error_Check'
 * '<S5>'   : 'FMS/FMS Commander'
 * '<S6>'   : 'FMS/FMS State Machine'
 * '<S7>'   : 'FMS/Onground Check'
 * '<S8>'   : 'FMS/SafeMode'
 * '<S9>'   : 'FMS/Auto_Cmd_Valid/Compare To Constant4'
 * '<S10>'  : 'FMS/Auto_Cmd_Valid/Detect Change'
 * '<S11>'  : 'FMS/Auto_Cmd_Valid/Ever_Valid'
 * '<S12>'  : 'FMS/Auto_Cmd_Valid/Interval Test'
 * '<S13>'  : 'FMS/Command Process/Check Valid'
 * '<S14>'  : 'FMS/Command Process/Command PreProcess'
 * '<S15>'  : 'FMS/Command Process/Mode PreProcess'
 * '<S16>'  : 'FMS/Command Process/Check Valid/Compare To Constant1'
 * '<S17>'  : 'FMS/Command Process/Check Valid/Detect Change1'
 * '<S18>'  : 'FMS/Command Process/Command PreProcess/Compare To Constant'
 * '<S19>'  : 'FMS/Command Process/Command PreProcess/Detect Change3'
 * '<S20>'  : 'FMS/Command Process/Command PreProcess/Detect Change4'
 * '<S21>'  : 'FMS/Command Process/Command PreProcess/SetHome'
 * '<S22>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero'
 * '<S23>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero1'
 * '<S24>'  : 'FMS/Command Process/Mode PreProcess/Detect Change'
 * '<S25>'  : 'FMS/Detect_Lost_Connect/Detect Change'
 * '<S26>'  : 'FMS/Detect_Lost_Connect/Detect Change1'
 * '<S27>'  : 'FMS/Detect_Lost_Connect/Error_Check'
 * '<S28>'  : 'FMS/Detect_Lost_Connect/timeout1_s'
 * '<S29>'  : 'FMS/Detect_Lost_Connect/timeout2_s'
 * '<S30>'  : 'FMS/FMS Commander/Commander'
 * '<S31>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Assist Land Speed'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Compare To Constant'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Vector Modulus'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Vector Normalize'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Assist Land Speed'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/Compare To Constant'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/Vector Modulus'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/Vector Normalize'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Compare To Constant'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Vector Modulus'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Vector Normalize'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Constant'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Zero'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Compare To Zero'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic1'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter/Compare To Constant'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Accel_Command'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Body_FRD'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Local_NED'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_FRD'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask/Compare To Zero2'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Local_NED/Psi To DCM'
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Local_NED/Psi To DCM/Rotation Matrix Z'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_FRD/Psi To DCM2'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_FRD/Psi To DCM2/Rotation Matrix Z'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero12'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero4'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero5'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Constant'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero1'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero6'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero7'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero8'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Constant'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero10'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero11'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero9'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid/bit_shift'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid/bit_shift'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid/bit_shift'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid/bit_shift'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid/bit_shift'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid/bit_shift'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid/bit_shift'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid/bit_shift'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Compare To Zero'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation/Compare To Constant'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command/Compare To Zero1'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_FRD'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_NED'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_NED'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_State'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_FRD/Psi To DCM1'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_FRD/Psi To DCM1/Rotation Matrix Z'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero1'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_NED/Psi To DCM'
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_NED/Psi To DCM/Rotation Matrix Z'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM1'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM2'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM1/Rotation Matrix Z'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM2/Rotation Matrix Z'
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_NED/Psi To DCM2'
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_NED/Psi To DCM2/Rotation Matrix Z'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Local_Position_Command'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask/Compare To Zero'
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LAT2FLAT Curve'
 * '<S330>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap'
 * '<S331>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/Rotation'
 * '<S332>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S333>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S334>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S335>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S336>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S337>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S338>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Body_FRD'
 * '<S339>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask'
 * '<S340>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Local_NED'
 * '<S341>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_FRD'
 * '<S342>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Velocity_Command'
 * '<S343>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S344>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Local_NED/Psi To DCM'
 * '<S345>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Local_NED/Psi To DCM/Rotation Matrix Z'
 * '<S346>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_FRD/Psi To DCM2'
 * '<S347>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_FRD/Psi To DCM2/Rotation Matrix Z'
 * '<S348>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S349>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S350>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S351>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S352>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S353>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S354>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S355>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S356>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S357>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S358>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S359>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S360>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S361>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S362>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S363>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S364>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S365>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S366>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S367>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S368>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S369>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S370>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S371>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S372>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S373>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S374>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S375>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S376>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S377>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S378>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S379>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S380>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S381>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S382>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S383>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S384>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S385>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S386>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S387>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S388>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S389>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S390>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S391>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed'
 * '<S392>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S393>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/Compare To Constant'
 * '<S394>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD'
 * '<S395>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD/fhan '
 * '<S396>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S397>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S398>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S399>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S400>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S401>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1'
 * '<S402>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S403>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S404>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S405>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S406>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S407>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S408>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S409>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S410>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S411>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S412>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S413>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S414>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S415>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S416>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S417>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S418>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control'
 * '<S419>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Compare To Constant'
 * '<S420>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Compare To Zero'
 * '<S421>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed '
 * '<S422>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position'
 * '<S423>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP'
 * '<S424>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration'
 * '<S425>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed'
 * '<S426>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/ValidCounter'
 * '<S427>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height'
 * '<S428>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height/Vector Modulus'
 * '<S429>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height/Vector Modulus1'
 * '<S430>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Compare To Zero'
 * '<S431>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Saturation Dynamic'
 * '<S432>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Saturation Dynamic1'
 * '<S433>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Vector Modulus'
 * '<S434>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold'
 * '<S435>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold'
 * '<S436>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller'
 * '<S437>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Detect Movement'
 * '<S438>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S439>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S440>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S441>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S442>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S443>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S444>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S445>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S446>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller'
 * '<S447>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Detect Movement'
 * '<S448>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Brake Control'
 * '<S449>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control'
 * '<S450>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control'
 * '<S451>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S452>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S453>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S454>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S455>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S456>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S457>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S458>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S459>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/Compare To Constant'
 * '<S460>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/Compare To Constant1'
 * '<S461>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/NearbyRefWP'
 * '<S462>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/OutRegionRegWP'
 * '<S463>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/SearchL1RefWP'
 * '<S464>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle'
 * '<S465>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Modulus'
 * '<S466>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Modulus1'
 * '<S467>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Normalize'
 * '<S468>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Normalize1'
 * '<S469>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S470>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S471>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S472>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Ground Speed'
 * '<S473>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S474>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S475>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S476>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S477>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/ValidCounter/Compare To Constant'
 * '<S478>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S479>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S480>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S481>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S482>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD'
 * '<S483>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD/fhan '
 * '<S484>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S485>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S486>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S487>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S488>' : 'FMS/FMS Commander/Commander/Bus_Constructor/Collect_Errors'
 * '<S489>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S490>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S491>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S492>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S493>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S494>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S495>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S496>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S497>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S498>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S499>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S500>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S501>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S502>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S503>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S504>' : 'FMS/Onground Check/First Order LPF'
 * '<S505>' : 'FMS/Onground Check/First Order LPF1'
 * '<S506>' : 'FMS/Onground Check/First Order LPF2'
 * '<S507>' : 'FMS/Onground Check/Interval Test'
 * '<S508>' : 'FMS/Onground Check/Quaternion To DCM'
 * '<S509>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize'
 * '<S510>' : 'FMS/Onground Check/Quaternion To DCM/column_1'
 * '<S511>' : 'FMS/Onground Check/Quaternion To DCM/column_2'
 * '<S512>' : 'FMS/Onground Check/Quaternion To DCM/column_3'
 * '<S513>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
