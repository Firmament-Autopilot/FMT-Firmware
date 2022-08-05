/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1752
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  5 21:43:03 2022
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

/* Block states (default storage) for system '<S281>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S284>/Delay' */
  uint8_T icLoad;                      /* '<S284>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S281>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S288>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S288>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S282>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S282>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S282>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S282>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S291>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S294>/Delay' */
  uint8_T icLoad;                      /* '<S294>/Delay' */
} DW_HoldControl_FMS_l_T;

/* Block states (default storage) for system '<S291>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S301>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S301>/Integrator' */
} DW_MoveControl_FMS_d_T;

/* Block states (default storage) for system '<S292>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S292>/Motion State' */
  uint8_T is_active_c2_FMS;            /* '<S292>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S292>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S225>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S228>/Delay' */
  uint8_T icLoad;                      /* '<S228>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S225>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S234>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S234>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S119>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S119>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S119>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S119>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S38>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S38>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S38>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S38>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Commander_In_Bus Cmd_In;             /* '<Root>/FMS State Machine' */
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real_T lla[3];                       /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T href;                         /* '<Root>/FMS State Machine' */
  real_T psio;                         /* '<Root>/FMS State Machine' */
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T DataTypeConversion[3];      /* '<S331>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S332>/Reshape' */
  real32_T Merge[2];                   /* '<S94>/Merge' */
  real32_T Merge_k;                    /* '<S70>/Merge' */
  real32_T Merge_d;                    /* '<S81>/Merge' */
  real32_T Merge_l;                    /* '<S37>/Merge' */
  real32_T Merge_m;                    /* '<S54>/Merge' */
  real32_T Merge_j;                    /* '<S118>/Merge' */
  real32_T Merge_n[2];                 /* '<S176>/Merge' */
  real32_T Merge_e;                    /* '<S166>/Merge' */
  real32_T Merge_o[2];                 /* '<S237>/Merge' */
  real32_T Merge_ey;                   /* '<S215>/Merge' */
  real32_T Merge_n1;                   /* '<S225>/Merge' */
  real32_T Merge_mv[2];                /* '<S291>/Merge' */
  real32_T Merge_mu;                   /* '<S281>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S7>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T on_ground;                 /* '<S4>/Logical Operator1' */
  boolean_T Compare;                   /* '<S344>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission_takeoff;         /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_c[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_p;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S346>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S347>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S50>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S50>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S51>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S51>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S114>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S114>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S115>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S115>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S159>/Delay' */
  real32_T l1_heading;                 /* '<S203>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S139>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S142>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S142>/Integrator' */
  real32_T Delay_DSTATE_e[2];          /* '<S277>/Delay' */
  real32_T l1_heading_p;               /* '<S318>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_p[2];          /* '<S257>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S258>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S261>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S261>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S10>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S6>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S15>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S11>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S12>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S330>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_c;            /* '<S8>/Delay' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_j;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_k;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_c;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2_a;/* '<Root>/FMS State Machine' */
  int32_T M_qId;                       /* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1;         /* '<Root>/FMS State Machine' */
  uint16_T temporalCounter_i1_i;       /* '<S95>/Motion State' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S134>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S16>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S18>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S94>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S70>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S81>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S37>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S54>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S118>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S23>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S176>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S166>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S25>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S237>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S215>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S225>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S291>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S281>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S346>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S347>/Discrete-Time Integrator5' */
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
  uint8_T is_Mission;                  /* '<Root>/FMS State Machine' */
  uint8_T is_Assist;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Manual;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Combo_Stick;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Combo_Stick;       /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S95>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S95>/Motion State' */
  uint8_T icLoad;                      /* '<S159>/Delay' */
  uint8_T icLoad_k;                    /* '<S139>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S142>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S226>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S226>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S226>/Motion State' */
  uint8_T icLoad_o;                    /* '<S277>/Delay' */
  uint8_T icLoad_c;                    /* '<S257>/Delay' */
  uint8_T icLoad_j;                    /* '<S258>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S261>/Integrator1' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_k;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d0;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_g;/* '<Root>/FMS State Machine' */
  DW_MoveControl_FMS_d_T MoveControl_k1;/* '<S94>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_at;/* '<S94>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S82>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_mr;/* '<S81>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S81>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S71>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_be; /* '<S70>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S70>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S55>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_cr;/* '<S54>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S54>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S38>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_l;  /* '<S37>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S37>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S119>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S118>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S118>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S177>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_c;/* '<S176>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_d;/* '<S176>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S167>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S166>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S166>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S238>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_i;/* '<S237>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_f;/* '<S237>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S225>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_kq;/* '<S225>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S216>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S215>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S215>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S292>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_o;/* '<S291>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_k;/* '<S291>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S282>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S281>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S281>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S131>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S16>/Disarm' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S20>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S20>/Data Type Conversion1' */
} ConstB_Disarm_FMS_T;

/* Invariant block signals for system '<S281>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S289>/Square' */
  const real32_T d;                    /* '<S289>/Multiply' */
  const real32_T Gain4;                /* '<S289>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S291>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S298>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S291>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S302>/Square' */
  const real32_T d;                    /* '<S302>/Multiply' */
  const real32_T Gain4;                /* '<S302>/Gain4' */
} ConstB_MoveControl_FMS_k_T;

/* Invariant block signals for system '<S225>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S235>/Square' */
  const real32_T d;                    /* '<S235>/Multiply' */
  const real32_T Gain4;                /* '<S235>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S335>/Sum' */
  const real_T ff;                     /* '<S335>/Multiply3' */
  const real_T Sum4;                   /* '<S335>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Square;               /* '<S52>/Square' */
  const real32_T d;                    /* '<S52>/Multiply' */
  const real32_T Gain4;                /* '<S52>/Gain4' */
  const real32_T Square_d;             /* '<S53>/Square' */
  const real32_T d_c;                  /* '<S53>/Multiply' */
  const real32_T Gain4_m;              /* '<S53>/Gain4' */
  const real32_T Square_m;             /* '<S116>/Square' */
  const real32_T d_d;                  /* '<S116>/Multiply' */
  const real32_T Gain4_n;              /* '<S116>/Gain4' */
  const real32_T Square_n;             /* '<S117>/Square' */
  const real32_T d_o;                  /* '<S117>/Multiply' */
  const real32_T Gain4_n3;             /* '<S117>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S206>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S152>/Math Function' */
  const real32_T SumofElements;        /* '<S152>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S152>/Math Function1' */
  const real32_T Product[2];           /* '<S152>/Product' */
  const real32_T Switch[3];            /* '<S152>/Switch' */
  const real32_T Divide[2];            /* '<S152>/Divide' */
  const real32_T Square_g;             /* '<S148>/Square' */
  const real32_T d_j;                  /* '<S148>/Multiply' */
  const real32_T Gain4_c;              /* '<S148>/Gain4' */
  const real32_T VectorConcatenate3_k[3];/* '<S321>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S271>/Math Function' */
  const real32_T SumofElements_p;      /* '<S271>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S271>/Math Function1' */
  const real32_T Product_c[2];         /* '<S271>/Product' */
  const real32_T Switch_h[3];          /* '<S271>/Switch' */
  const real32_T Divide_d[2];          /* '<S271>/Divide' */
  const real32_T Square_k;             /* '<S267>/Square' */
  const real32_T d_l;                  /* '<S267>/Multiply' */
  const real32_T Gain4_np;             /* '<S267>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S254>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S329>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S24>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S24>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S29>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S29>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S29>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S28>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S28>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S30>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S30>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S30>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S27>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S135>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S135>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S135>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S132>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S132>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S207>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S207>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S207>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S209>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S209>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S209>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S208>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S208>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S208>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S210>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S210>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S210>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S21>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S21>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Disarm_FMS_T Unknown;         /* '<S18>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_i;       /* '<S22>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_k1;/* '<S94>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_at;/* '<S94>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_mr;/* '<S81>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_be;/* '<S70>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_cr;/* '<S54>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_l;/* '<S37>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S118>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_d;       /* '<S23>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_c;/* '<S176>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_d;/* '<S176>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S166>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_g;       /* '<S25>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_i;/* '<S237>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S237>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S225>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S215>/Move Control' */
  ConstB_MoveControl_FMS_k_T MoveControl_o;/* '<S291>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_k;/* '<S291>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S281>/Move Control' */
  ConstB_Disarm_FMS_T Disarm;          /* '<S16>/Disarm' */
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
extern struct_z8TbXuqo9JNiexfZo6b1iC FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S332>/Constant'
                                                *   '<S209>/L1'
                                                *   '<S35>/Gain'
                                                *   '<S35>/Gain1'
                                                *   '<S109>/Gain'
                                                *   '<S109>/Gain1'
                                                *   '<S135>/L1'
                                                *   '<S250>/Saturation1'
                                                *   '<S323>/Gain2'
                                                *   '<S323>/Saturation1'
                                                *   '<S37>/Saturation1'
                                                *   '<S48>/Dead Zone'
                                                *   '<S48>/Gain'
                                                *   '<S49>/Dead Zone'
                                                *   '<S49>/Gain'
                                                *   '<S54>/Saturation'
                                                *   '<S70>/Saturation1'
                                                *   '<S81>/Saturation'
                                                *   '<S94>/Saturation1'
                                                *   '<S112>/Dead Zone'
                                                *   '<S112>/Gain'
                                                *   '<S113>/Dead Zone'
                                                *   '<S113>/Gain'
                                                *   '<S118>/Saturation'
                                                *   '<S215>/Saturation1'
                                                *   '<S225>/Saturation'
                                                *   '<S237>/Saturation1'
                                                *   '<S251>/Gain2'
                                                *   '<S273>/vel'
                                                *   '<S273>/Saturation'
                                                *   '<S273>/Switch'
                                                *   '<S40>/Gain2'
                                                *   '<S41>/Gain1'
                                                *   '<S46>/Constant'
                                                *   '<S57>/Gain2'
                                                *   '<S58>/Gain1'
                                                *   '<S65>/Constant'
                                                *   '<S73>/Gain2'
                                                *   '<S74>/Gain1'
                                                *   '<S79>/Constant'
                                                *   '<S84>/Gain2'
                                                *   '<S85>/Gain1'
                                                *   '<S92>/Constant'
                                                *   '<S97>/Gain2'
                                                *   '<S98>/Gain6'
                                                *   '<S106>/Constant'
                                                *   '<S107>/Constant'
                                                *   '<S121>/Gain2'
                                                *   '<S122>/Gain1'
                                                *   '<S129>/Constant'
                                                *   '<S154>/Gain'
                                                *   '<S154>/Saturation1'
                                                *   '<S155>/vel'
                                                *   '<S155>/Saturation'
                                                *   '<S155>/Switch'
                                                *   '<S218>/Gain2'
                                                *   '<S219>/Gain1'
                                                *   '<S228>/Gain2'
                                                *   '<S229>/Gain1'
                                                *   '<S240>/Gain2'
                                                *   '<S241>/Gain6'
                                                *   '<S260>/Gain2'
                                                *   '<S260>/Saturation'
                                                *   '<S261>/Integrator'
                                                *   '<S43>/Dead Zone'
                                                *   '<S43>/Gain'
                                                *   '<S62>/Dead Zone'
                                                *   '<S62>/Gain'
                                                *   '<S76>/Dead Zone'
                                                *   '<S76>/Gain'
                                                *   '<S89>/Dead Zone'
                                                *   '<S89>/Gain'
                                                *   '<S102>/Dead Zone'
                                                *   '<S102>/Gain'
                                                *   '<S103>/Dead Zone'
                                                *   '<S103>/Gain'
                                                *   '<S126>/Dead Zone'
                                                *   '<S126>/Gain'
                                                *   '<S141>/Gain2'
                                                *   '<S141>/Saturation'
                                                *   '<S142>/Integrator'
                                                *   '<S221>/Dead Zone'
                                                *   '<S221>/Gain'
                                                *   '<S233>/Dead Zone'
                                                *   '<S233>/Gain'
                                                *   '<S245>/Dead Zone'
                                                *   '<S245>/Gain'
                                                *   '<S246>/Dead Zone'
                                                *   '<S246>/Gain'
                                                *   '<S281>/Saturation1'
                                                *   '<S291>/Saturation1'
                                                *   '<S166>/Saturation1'
                                                *   '<S176>/Saturation1'
                                                *   '<S284>/Gain2'
                                                *   '<S285>/Gain1'
                                                *   '<S294>/Gain2'
                                                *   '<S295>/Gain6'
                                                *   '<S169>/Gain2'
                                                *   '<S170>/Gain1'
                                                *   '<S179>/Gain2'
                                                *   '<S180>/Gain6'
                                                *   '<S287>/Dead Zone'
                                                *   '<S287>/Gain'
                                                *   '<S299>/Dead Zone'
                                                *   '<S299>/Gain'
                                                *   '<S300>/Dead Zone'
                                                *   '<S300>/Gain'
                                                *   '<S172>/Dead Zone'
                                                *   '<S172>/Gain'
                                                *   '<S184>/Dead Zone'
                                                *   '<S184>/Gain'
                                                *   '<S185>/Dead Zone'
                                                *   '<S185>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S6>/Constant1'
                                                 *   '<S330>/Constant'
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
 * Block '<S152>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S271>/Data Type Duplicate' : Unused code path elimination
 * Block '<S272>/Data Type Duplicate' : Unused code path elimination
 * Block '<S315>/Data Type Duplicate' : Unused code path elimination
 * Block '<S316>/Data Type Duplicate' : Unused code path elimination
 * Block '<S312>/Data Type Duplicate' : Unused code path elimination
 * Block '<S313>/Data Type Duplicate' : Unused code path elimination
 * Block '<S319>/Data Type Duplicate' : Unused code path elimination
 * Block '<S348>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Reshape' : Reshape block reduction
 * Block '<S138>/Reshape' : Reshape block reduction
 * Block '<S138>/Reshape1' : Reshape block reduction
 * Block '<S138>/Reshape2' : Reshape block reduction
 * Block '<S208>/Reshape' : Reshape block reduction
 * Block '<S275>/Reshape' : Reshape block reduction
 * Block '<S257>/Reshape' : Reshape block reduction
 * Block '<S257>/Reshape1' : Reshape block reduction
 * Block '<S257>/Reshape2' : Reshape block reduction
 * Block '<S328>/Reshape' : Reshape block reduction
 * Block '<S330>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S17>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S17>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S17>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S17>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S331>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S346>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'FMS/Command Process'
 * '<S2>'   : 'FMS/FMS Commander'
 * '<S3>'   : 'FMS/FMS State Machine'
 * '<S4>'   : 'FMS/Onground Check'
 * '<S5>'   : 'FMS/SafeMode'
 * '<S6>'   : 'FMS/Command Process/Check Valid'
 * '<S7>'   : 'FMS/Command Process/Command Routing'
 * '<S8>'   : 'FMS/Command Process/Mode Routing'
 * '<S9>'   : 'FMS/Command Process/Check Valid/Compare To Constant1'
 * '<S10>'  : 'FMS/Command Process/Check Valid/Detect Change1'
 * '<S11>'  : 'FMS/Command Process/Command Routing/Detect Change3'
 * '<S12>'  : 'FMS/Command Process/Command Routing/Detect Change4'
 * '<S13>'  : 'FMS/Command Process/Mode Routing/Compare To Zero'
 * '<S14>'  : 'FMS/Command Process/Mode Routing/Compare To Zero1'
 * '<S15>'  : 'FMS/Command Process/Mode Routing/Detect Change'
 * '<S16>'  : 'FMS/FMS Commander/Commander'
 * '<S17>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S18>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S19>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S20>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S21>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S22>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S23>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S24>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S25>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S26>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S330>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S331>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S332>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S333>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S334>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S335>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S336>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S337>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S338>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S339>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S340>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S341>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S342>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S343>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S344>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S345>' : 'FMS/Onground Check/Compare To Constant'
 * '<S346>' : 'FMS/Onground Check/First Order LPF'
 * '<S347>' : 'FMS/Onground Check/First Order LPF2'
 * '<S348>' : 'FMS/Onground Check/Interval Test'
 * '<S349>' : 'FMS/Onground Check/Quaternion To DCM'
 * '<S350>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize'
 * '<S351>' : 'FMS/Onground Check/Quaternion To DCM/column_1'
 * '<S352>' : 'FMS/Onground Check/Quaternion To DCM/column_2'
 * '<S353>' : 'FMS/Onground Check/Quaternion To DCM/column_3'
 * '<S354>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
