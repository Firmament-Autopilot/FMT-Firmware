/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2122
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 17 17:26:33 2024
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

/* Block states (default storage) for system '<S363>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S366>/Delay' */
  uint8_T icLoad;                      /* '<S366>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S363>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S370>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S370>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S364>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S364>/Motion Status' */
  uint8_T is_active_c10_FMS;           /* '<S364>/Motion Status' */
  uint8_T is_c10_FMS;                  /* '<S364>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S373>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S376>/Delay' */
  uint8_T icLoad;                      /* '<S376>/Delay' */
} DW_HoldControl_FMS_j_T;

/* Block states (default storage) for system '<S374>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S374>/Motion State' */
  uint8_T is_active_c23_FMS;           /* '<S374>/Motion State' */
  uint8_T is_c23_FMS;                  /* '<S374>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S293>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S296>/Delay' */
  uint8_T icLoad;                      /* '<S296>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S293>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S302>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S302>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S305>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S315>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S315>/Integrator' */
} DW_MoveControl_FMS_k_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  Commander_In_Bus Cmd_In;             /* '<Root>/FMS State Machine' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real_T lla[3];                       /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T href;                         /* '<Root>/FMS State Machine' */
  real_T psio;                         /* '<Root>/FMS State Machine' */
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T DataTypeConversion[3];      /* '<S416>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S417>/Reshape' */
  real32_T Merge;                      /* '<S45>/Merge' */
  real32_T Merge_m;                    /* '<S63>/Merge' */
  real32_T Merge_n[2];                 /* '<S139>/Merge' */
  real32_T Merge_e;                    /* '<S129>/Merge' */
  real32_T Merge_o[2];                 /* '<S305>/Merge' */
  real32_T Merge_ey;                   /* '<S283>/Merge' */
  real32_T Merge_n1;                   /* '<S293>/Merge' */
  real32_T Merge_a[2];                 /* '<S373>/Merge' */
  real32_T Merge_j;                    /* '<S363>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S12>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T Compare;                   /* '<S26>/Compare' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare_k;                 /* '<S429>/Compare' */
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
  real32_T Integrator1_DSTATE;         /* '<S59>/Integrator1' */
  real32_T Integrator1_DSTATE_o;       /* '<S60>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S60>/Integrator' */
  real32_T Integrator_DSTATE_b;        /* '<S59>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S118>/Delay' */
  real32_T Acceleration_Speed_DSTATE;  /* '<S114>/Acceleration_Speed' */
  real32_T l1_heading;                 /* '<S166>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S96>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S99>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S99>/Integrator' */
  real32_T Delay_DSTATE_e[2];          /* '<S352>/Delay' */
  real32_T Acceleration_Speed_DSTATE_j;/* '<S348>/Acceleration_Speed' */
  real32_T l1_heading_e;               /* '<S400>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_a;             /* '<S330>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S333>/Integrator1' */
  real32_T Delay_DSTATE_p[2];          /* '<S329>/Delay' */
  real32_T Integrator_DSTATE_bs;       /* '<S333>/Integrator' */
  real32_T Integrator1_DSTATE_m[2];    /* '<S383>/Integrator1' */
  real32_T Integrator_DSTATE_bz[2];    /* '<S383>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S321>/Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S321>/Integrator' */
  real32_T cur_waypoint_DSTATE[3];     /* '<S413>/cur_waypoint' */
  real32_T Integrator1_DSTATE_a;       /* '<S409>/Integrator1' */
  real32_T Integrator_DSTATE_m;        /* '<S409>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S15>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S11>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S22>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S17>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S18>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S23>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S24>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S8>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S415>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_c;            /* '<S13>/Delay' */
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
  uint32_T temporalCounter_i1;         /* '<Root>/FMS State Machine' */
  uint32_T mission_timestamp_prev;     /* '<Root>/FMS State Machine' */
  uint32_T mission_timestamp_start;    /* '<Root>/FMS State Machine' */
  FMS_Cmd M;                           /* '<Root>/FMS State Machine' */
  FMS_Cmd save_cmd;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_prev;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_start;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgData;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgReservedData;           /* '<Root>/FMS State Machine' */
  PilotMode mode_prev;                 /* '<Root>/FMS State Machine' */
  PilotMode mode_start;                /* '<Root>/FMS State Machine' */
  uint16_T nav_cmd;                    /* '<Root>/FMS State Machine' */
  uint16_T temporalCounter_i1_a;       /* '<S46>/Motion Status' */
  uint8_T Delay_DSTATE_o;              /* '<S9>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S91>/Delay Input1' */
  uint8_T DiscreteTimeIntegrator_DSTATE_k;/* '<S119>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_DSTATE_m;/* '<S353>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S27>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S29>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S33>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S45>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S63>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S34>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetSta;/* '<S114>/Acceleration_Speed' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S139>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S129>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S36>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S305>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S283>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S293>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetS_j;/* '<S348>/Acceleration_Speed' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S373>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S363>/Switch Case' */
  uint8_T is_active_c3_FMS;            /* '<Root>/SafeMode' */
  uint8_T is_c3_FMS;                   /* '<Root>/SafeMode' */
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
  uint8_T is_active_c18_FMS;           /* '<S64>/Motion State' */
  uint8_T is_c18_FMS;                  /* '<S64>/Motion State' */
  uint8_T temporalCounter_i1_f;        /* '<S64>/Motion State' */
  uint8_T is_active_c17_FMS;           /* '<S46>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S46>/Motion Status' */
  uint8_T icLoad;                      /* '<S118>/Delay' */
  uint8_T icLoad_k;                    /* '<S96>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S99>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S294>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S294>/Motion State' */
  uint8_T temporalCounter_i1_ai;       /* '<S294>/Motion State' */
  uint8_T icLoad_l;                    /* '<S352>/Delay' */
  uint8_T icLoad_j;                    /* '<S330>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S333>/Integrator1' */
  uint8_T icLoad_c;                    /* '<S329>/Delay' */
  uint8_T icLoad_j1;                   /* '<S413>/cur_waypoint' */
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
  DW_MoveControl_FMS_c_T MoveControl_cr;/* '<S63>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S63>/Hold Control' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S45>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S140>/Motion State' */
  DW_MoveControl_FMS_k_T MoveControl_c;/* '<S139>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_d;/* '<S139>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S130>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S129>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S129>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S306>/Motion State' */
  DW_MoveControl_FMS_k_T MoveControl_i;/* '<S305>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_f;/* '<S305>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S293>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_k;/* '<S293>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S284>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S283>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S283>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S374>/Motion State' */
  DW_HoldControl_FMS_j_T HoldControl_m;/* '<S373>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S364>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S363>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S363>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S88>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S12>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S363>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S371>/Square' */
  const real32_T d;                    /* '<S371>/Multiply' */
  const real32_T Gain4;                /* '<S371>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S373>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S380>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_f_T;

/* Invariant block signals for system '<S293>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S303>/Square' */
  const real32_T d;                    /* '<S303>/Multiply' */
  const real32_T Gain4;                /* '<S303>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S305>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S316>/Square' */
  const real32_T d;                    /* '<S316>/Multiply' */
  const real32_T Gain4;                /* '<S316>/Gain4' */
} ConstB_MoveControl_FMS_o_T;

/* Invariant block signals for system '<S36>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S279>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S279>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S420>/Sum' */
  const real_T ff;                     /* '<S420>/Multiply3' */
  const real_T Sum4;                   /* '<S420>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S257>/Sum' */
  const real_T ff;                     /* '<S257>/Multiply3' */
  const real_T Sum4;                   /* '<S257>/Sum4' */
  const real_T deg2rad2;               /* '<S256>/deg2rad2' */
  const real_T SinCos_o1;              /* '<S259>/SinCos' */
  const real_T SinCos_o2;              /* '<S259>/SinCos' */
  const real32_T Square;               /* '<S62>/Square' */
  const real32_T d;                    /* '<S62>/Multiply' */
  const real32_T Gain4;                /* '<S62>/Gain4' */
  const real32_T Square_g;             /* '<S61>/Square' */
  const real32_T d_e;                  /* '<S61>/Multiply' */
  const real32_T Gain4_d;              /* '<S61>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S169>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S109>/Math Function' */
  const real32_T SumofElements;        /* '<S109>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S109>/Math Function1' */
  const real32_T Product[2];           /* '<S109>/Product' */
  const real32_T Switch[3];            /* '<S109>/Switch' */
  const real32_T Divide[2];            /* '<S109>/Divide' */
  const real32_T Square_gd;            /* '<S105>/Square' */
  const real32_T d_j;                  /* '<S105>/Multiply' */
  const real32_T Gain4_c;              /* '<S105>/Gain4' */
  const real32_T VectorConcatenate3_n[3];/* '<S250>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S251>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_i[3];/* '<S247>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_nj[3];/* '<S243>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e1[3];/* '<S181>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S183>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S272>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_iz[3];/* '<S274>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_c[3];/* '<S403>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S343>/Math Function' */
  const real32_T SumofElements_p;      /* '<S343>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S343>/Math Function1' */
  const real32_T Product_c[2];         /* '<S343>/Product' */
  const real32_T Switch_h[3];          /* '<S343>/Switch' */
  const real32_T Divide_d[2];          /* '<S343>/Divide' */
  const real32_T Square_k;             /* '<S339>/Square' */
  const real32_T d_l;                  /* '<S339>/Multiply' */
  const real32_T Gain4_n;              /* '<S339>/Gain4' */
  const real32_T Square_f;             /* '<S384>/Square' */
  const real32_T d_a;                  /* '<S384>/Multiply' */
  const real32_T Gain4_m;              /* '<S384>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S326>/Vector Concatenate3' */
  const real32_T Square_e;             /* '<S322>/Square' */
  const real32_T d_p;                  /* '<S322>/Multiply' */
  const real32_T Gain4_e;              /* '<S322>/Gain4' */
  const real32_T VectorConcatenate3_fb[3];/* '<S414>/Vector Concatenate3' */
  const real32_T Square_b;             /* '<S410>/Square' */
  const real32_T d_m;                  /* '<S410>/Multiply' */
  const real32_T Gain4_a;              /* '<S410>/Gain4' */
  const uint8_T DataTypeConversion;    /* '<S35>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S35>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S39>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S39>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S39>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S38>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S38>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S38>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S40>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S40>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S40>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S92>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S92>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S92>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S89>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S89>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S89>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S275>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S275>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S275>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S277>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S277>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S277>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S276>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S276>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S276>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S278>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S278>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S278>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S32>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S32>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S31>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S31>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S29>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S33>/Unknown' */
  ConstB_MoveControl_FMS_f_T MoveControl_cr;/* '<S63>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S34>/Unknown' */
  ConstB_MoveControl_FMS_o_T MoveControl_c;/* '<S139>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_d;/* '<S139>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S129>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S36>/Unknown' */
  ConstB_MoveControl_FMS_o_T MoveControl_i;/* '<S305>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_f;/* '<S305>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S293>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S283>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_m;/* '<S373>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S363>/Move Control' */
} ConstB_FMS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S236>/Saturation1'
   *   '<S238>/Saturation'
   *   '<S239>/Saturation1'
   */
  real32_T pooled22[3];

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S236>/Saturation1'
   *   '<S238>/Saturation'
   *   '<S239>/Saturation1'
   */
  real32_T pooled23[3];
} ConstP_FMS_T;

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

/* Constant parameters (default storage) */
extern const ConstP_FMS_T FMS_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_NBjn9jnE53XzbTzYqi5PkH FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S3>/Constant1'
                                                *   '<S25>/Constant'
                                                *   '<S417>/Constant'
                                                *   '<S277>/L1'
                                                *   '<S43>/Gain'
                                                *   '<S43>/Gain1'
                                                *   '<S76>/Gain6'
                                                *   '<S77>/Gain6'
                                                *   '<S78>/Gain6'
                                                *   '<S82>/Gain6'
                                                *   '<S83>/Gain6'
                                                *   '<S84>/Gain6'
                                                *   '<S92>/L1'
                                                *   '<S173>/Saturation'
                                                *   '<S174>/Saturation1'
                                                *   '<S174>/Saturation2'
                                                *   '<S174>/Saturation3'
                                                *   '<S318>/Land_Speed'
                                                *   '<S319>/Saturation1'
                                                *   '<S405>/Takeoff_Speed'
                                                *   '<S406>/Gain2'
                                                *   '<S406>/Saturation1'
                                                *   '<S45>/Saturation1'
                                                *   '<S57>/Dead Zone'
                                                *   '<S57>/Gain'
                                                *   '<S58>/Dead Zone'
                                                *   '<S58>/Gain'
                                                *   '<S63>/Saturation'
                                                *   '<S79>/Dead Zone'
                                                *   '<S79>/Gain'
                                                *   '<S80>/Dead Zone'
                                                *   '<S80>/Gain'
                                                *   '<S81>/Dead Zone'
                                                *   '<S81>/Gain'
                                                *   '<S85>/Dead Zone'
                                                *   '<S85>/Gain'
                                                *   '<S86>/Dead Zone'
                                                *   '<S86>/Gain'
                                                *   '<S87>/Dead Zone'
                                                *   '<S87>/Gain'
                                                *   '<S227>/Gain2'
                                                *   '<S234>/Gain1'
                                                *   '<S234>/Gain2'
                                                *   '<S283>/Saturation1'
                                                *   '<S293>/Saturation'
                                                *   '<S305>/Saturation1'
                                                *   '<S320>/Constant'
                                                *   '<S323>/Gain2'
                                                *   '<S345>/Gain'
                                                *   '<S345>/Saturation1'
                                                *   '<S348>/Constant'
                                                *   '<S348>/vel'
                                                *   '<S348>/Switch'
                                                *   '<S48>/Gain2'
                                                *   '<S49>/Gain1'
                                                *   '<S55>/Constant'
                                                *   '<S66>/Gain2'
                                                *   '<S67>/Gain1'
                                                *   '<S74>/Constant'
                                                *   '<S111>/Gain'
                                                *   '<S111>/Saturation1'
                                                *   '<S114>/Constant'
                                                *   '<S114>/vel'
                                                *   '<S114>/Switch'
                                                *   '<S286>/Gain2'
                                                *   '<S287>/Gain1'
                                                *   '<S296>/Gain2'
                                                *   '<S297>/Gain1'
                                                *   '<S308>/Gain2'
                                                *   '<S309>/Gain6'
                                                *   '<S332>/Gain2'
                                                *   '<S332>/Saturation'
                                                *   '<S333>/Integrator'
                                                *   '<S51>/Land_Speed'
                                                *   '<S52>/Constant'
                                                *   '<S54>/Dead Zone'
                                                *   '<S54>/Gain'
                                                *   '<S71>/Dead Zone'
                                                *   '<S71>/Gain'
                                                *   '<S98>/Gain2'
                                                *   '<S98>/Saturation'
                                                *   '<S99>/Integrator'
                                                *   '<S289>/Dead Zone'
                                                *   '<S289>/Gain'
                                                *   '<S301>/Dead Zone'
                                                *   '<S301>/Gain'
                                                *   '<S313>/Dead Zone'
                                                *   '<S313>/Gain'
                                                *   '<S314>/Dead Zone'
                                                *   '<S314>/Gain'
                                                *   '<S363>/Saturation1'
                                                *   '<S373>/Saturation1'
                                                *   '<S129>/Saturation1'
                                                *   '<S139>/Saturation1'
                                                *   '<S366>/Gain2'
                                                *   '<S367>/Gain1'
                                                *   '<S376>/Gain2'
                                                *   '<S377>/Gain6'
                                                *   '<S132>/Gain2'
                                                *   '<S133>/Gain1'
                                                *   '<S142>/Gain2'
                                                *   '<S143>/Gain6'
                                                *   '<S369>/Dead Zone'
                                                *   '<S369>/Gain'
                                                *   '<S381>/Dead Zone'
                                                *   '<S381>/Gain'
                                                *   '<S382>/Dead Zone'
                                                *   '<S382>/Gain'
                                                *   '<S135>/Dead Zone'
                                                *   '<S135>/Gain'
                                                *   '<S147>/Dead Zone'
                                                *   '<S147>/Gain'
                                                *   '<S148>/Dead Zone'
                                                *   '<S148>/Gain'
                                                */
extern struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S11>/Constant1'
                                                 *   '<S415>/Constant'
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
 * Block '<S10>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Propagation' : Unused code path elimination
 * Block '<S163>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S343>/Data Type Duplicate' : Unused code path elimination
 * Block '<S344>/Data Type Duplicate' : Unused code path elimination
 * Block '<S358>/Data Type Duplicate' : Unused code path elimination
 * Block '<S358>/Data Type Propagation' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate' : Unused code path elimination
 * Block '<S359>/Data Type Propagation' : Unused code path elimination
 * Block '<S397>/Data Type Duplicate' : Unused code path elimination
 * Block '<S398>/Data Type Duplicate' : Unused code path elimination
 * Block '<S394>/Data Type Duplicate' : Unused code path elimination
 * Block '<S395>/Data Type Duplicate' : Unused code path elimination
 * Block '<S401>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Reshape' : Reshape block reduction
 * Block '<S95>/Reshape' : Reshape block reduction
 * Block '<S95>/Reshape1' : Reshape block reduction
 * Block '<S95>/Reshape2' : Reshape block reduction
 * Block '<S350>/Reshape' : Reshape block reduction
 * Block '<S329>/Reshape' : Reshape block reduction
 * Block '<S329>/Reshape1' : Reshape block reduction
 * Block '<S329>/Reshape2' : Reshape block reduction
 * Block '<S413>/Reshape' : Reshape block reduction
 * Block '<S415>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy7' : Eliminate redundant signal conversion block
 * Block '<S416>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S4>'   : 'FMS/FMS Commander'
 * '<S5>'   : 'FMS/FMS State Machine'
 * '<S6>'   : 'FMS/SafeMode'
 * '<S7>'   : 'FMS/Auto_Cmd_Valid/Compare To Constant4'
 * '<S8>'   : 'FMS/Auto_Cmd_Valid/Detect Change'
 * '<S9>'   : 'FMS/Auto_Cmd_Valid/Ever_Valid'
 * '<S10>'  : 'FMS/Auto_Cmd_Valid/Interval Test'
 * '<S11>'  : 'FMS/Command Process/Check Valid'
 * '<S12>'  : 'FMS/Command Process/Command PreProcess'
 * '<S13>'  : 'FMS/Command Process/Mode PreProcess'
 * '<S14>'  : 'FMS/Command Process/Check Valid/Compare To Constant1'
 * '<S15>'  : 'FMS/Command Process/Check Valid/Detect Change1'
 * '<S16>'  : 'FMS/Command Process/Command PreProcess/Compare To Constant'
 * '<S17>'  : 'FMS/Command Process/Command PreProcess/Detect Change3'
 * '<S18>'  : 'FMS/Command Process/Command PreProcess/Detect Change4'
 * '<S19>'  : 'FMS/Command Process/Command PreProcess/SetHome'
 * '<S20>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero'
 * '<S21>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero1'
 * '<S22>'  : 'FMS/Command Process/Mode PreProcess/Detect Change'
 * '<S23>'  : 'FMS/Detect_Lost_Connect/Detect Change'
 * '<S24>'  : 'FMS/Detect_Lost_Connect/Detect Change1'
 * '<S25>'  : 'FMS/Detect_Lost_Connect/timeout1_s'
 * '<S26>'  : 'FMS/Detect_Lost_Connect/timeout2_s'
 * '<S27>'  : 'FMS/FMS Commander/Commander'
 * '<S28>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Assist Land Speed'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command '
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command /DeadZone2'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone2'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/DeadZone2'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command '
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command /DeadZone2'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone2'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command/DeadZone2'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Constant'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Zero'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Compare To Zero'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic1'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter/Compare To Constant'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Body_Frame'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask/Compare To Zero2'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero12'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero4'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero5'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Constant'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero6'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero7'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero8'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Constant'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero10'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero11'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero9'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid/bit_shift'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid/bit_shift'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid/bit_shift'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid/bit_shift'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid/bit_shift'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid/bit_shift'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid/bit_shift'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid/bit_shift'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Compare To Zero'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation/Compare To Constant'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command/Compare To Zero1'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_State'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero1'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM/Rotation Matrix Z'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1'
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2/Rotation Matrix Z'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Local_Position_Command'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask/Compare To Zero'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LAT2FLAT Curve'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/Rotation'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Body_Frame'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/Compare To Constant'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD'
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD/fhan '
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S330>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S331>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S332>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S333>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S334>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S335>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S336>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S337>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S338>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S339>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S340>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S341>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S342>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S343>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S344>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S345>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control'
 * '<S346>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Compare To Constant'
 * '<S347>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Compare To Zero'
 * '<S348>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed '
 * '<S349>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position'
 * '<S350>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP'
 * '<S351>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration'
 * '<S352>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed'
 * '<S353>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/ValidCounter'
 * '<S354>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height'
 * '<S355>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height/Vector Modulus'
 * '<S356>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height/Vector Modulus1'
 * '<S357>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Compare To Zero'
 * '<S358>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Saturation Dynamic'
 * '<S359>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Saturation Dynamic1'
 * '<S360>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Vector Modulus'
 * '<S361>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold'
 * '<S362>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold'
 * '<S363>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller'
 * '<S364>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Detect Movement'
 * '<S365>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S366>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S367>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S368>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S369>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S370>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S371>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S372>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S373>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller'
 * '<S374>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Detect Movement'
 * '<S375>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Brake Control'
 * '<S376>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control'
 * '<S377>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control'
 * '<S378>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S379>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S380>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S381>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S382>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S383>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S384>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S385>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S386>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/Compare To Constant'
 * '<S387>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/Compare To Constant1'
 * '<S388>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/NearbyRefWP'
 * '<S389>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/OutRegionRegWP'
 * '<S390>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/SearchL1RefWP'
 * '<S391>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle'
 * '<S392>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Modulus'
 * '<S393>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Modulus1'
 * '<S394>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Normalize'
 * '<S395>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Normalize1'
 * '<S396>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S397>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S398>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S399>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Ground Speed'
 * '<S400>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S401>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S402>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S403>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S404>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/ValidCounter/Compare To Constant'
 * '<S405>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S406>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S407>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S408>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S409>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD'
 * '<S410>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD/fhan '
 * '<S411>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S412>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S413>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S414>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S415>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S416>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S417>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S418>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S419>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S420>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S421>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S422>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S423>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S424>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S425>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S426>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S427>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S428>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S429>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
