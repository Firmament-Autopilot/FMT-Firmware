/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1952
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 13 10:18:22 2023
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

/* Block states (default storage) for system '<S401>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S404>/Delay' */
  uint8_T icLoad;                      /* '<S404>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S401>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S408>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S408>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S402>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S402>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S402>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S402>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S411>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S414>/Delay' */
  uint8_T icLoad;                      /* '<S414>/Delay' */
} DW_HoldControl_FMS_l_T;

/* Block states (default storage) for system '<S411>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S421>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S421>/Integrator' */
} DW_MoveControl_FMS_d_T;

/* Block states (default storage) for system '<S412>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S412>/Motion State' */
  uint8_T is_active_c2_FMS;            /* '<S412>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S412>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S344>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S347>/Delay' */
  uint8_T icLoad;                      /* '<S347>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S344>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S353>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S353>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S134>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S134>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S134>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S134>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S49>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S49>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S49>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S49>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

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
  real32_T DataTypeConversion[3];      /* '<S451>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S452>/Reshape' */
  real32_T Merge[2];                   /* '<S109>/Merge' */
  real32_T Merge_k;                    /* '<S81>/Merge' */
  real32_T Merge_d;                    /* '<S96>/Merge' */
  real32_T Merge_l;                    /* '<S48>/Merge' */
  real32_T Merge_m;                    /* '<S65>/Merge' */
  real32_T Merge_j;                    /* '<S133>/Merge' */
  real32_T Merge_n[2];                 /* '<S191>/Merge' */
  real32_T Merge_e;                    /* '<S181>/Merge' */
  real32_T Merge_o[2];                 /* '<S356>/Merge' */
  real32_T Merge_ey;                   /* '<S334>/Merge' */
  real32_T Merge_n1;                   /* '<S344>/Merge' */
  real32_T Merge_mv[2];                /* '<S411>/Merge' */
  real32_T Merge_mu;                   /* '<S401>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S13>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T on_ground;                 /* '<S6>/Logical Operator1' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare;                   /* '<S464>/Compare' */
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
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S465>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S467>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S466>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE;         /* '<S61>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S61>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S62>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S62>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S129>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S129>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S130>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S130>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S174>/Delay' */
  real32_T l1_heading;                 /* '<S218>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S154>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S157>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S157>/Integrator' */
  real32_T Delay_DSTATE_e[2];          /* '<S397>/Delay' */
  real32_T l1_heading_p;               /* '<S438>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_p[2];          /* '<S377>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S378>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S381>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S381>/Integrator' */
  real32_T cur_waypoint_DSTATE[3];     /* '<S448>/cur_waypoint' */
  uint32_T DelayInput1_DSTATE;         /* '<S16>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S12>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S23>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S18>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S19>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S24>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S25>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S9>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S450>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_c;            /* '<S14>/Delay' */
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
  uint16_T temporalCounter_i1_i;       /* '<S110>/Motion State' */
  uint8_T Delay_DSTATE_o;              /* '<S10>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S149>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S27>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S29>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S33>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S81>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S109>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S96>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S48>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S65>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S133>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S34>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S191>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S181>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S36>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S356>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S334>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S344>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S411>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S401>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S465>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S467>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S466>/Discrete-Time Integrator5' */
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
  uint8_T is_active_c16_FMS;           /* '<S110>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S110>/Motion State' */
  uint8_T icLoad;                      /* '<S174>/Delay' */
  uint8_T icLoad_k;                    /* '<S154>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S157>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S345>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S345>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S345>/Motion State' */
  uint8_T icLoad_o;                    /* '<S397>/Delay' */
  uint8_T icLoad_c;                    /* '<S377>/Delay' */
  uint8_T icLoad_j;                    /* '<S378>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S381>/Integrator1' */
  uint8_T icLoad_j1;                   /* '<S448>/cur_waypoint' */
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
  DW_MoveControl_FMS_d_T MoveControl_k1;/* '<S109>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_at;/* '<S109>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S97>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_mr;/* '<S96>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S96>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S82>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S81>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S66>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_cr;/* '<S65>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S65>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S49>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S48>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S134>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S133>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S133>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S192>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_c;/* '<S191>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_d;/* '<S191>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S182>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S181>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S181>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S357>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_i;/* '<S356>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_f;/* '<S356>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S344>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_kq;/* '<S344>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S335>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S334>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S334>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S412>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_o;/* '<S411>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_k;/* '<S411>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S402>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S401>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S401>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S146>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S13>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S27>/Disarm' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S31>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S31>/Data Type Conversion1' */
} ConstB_Disarm_FMS_T;

/* Invariant block signals for system '<S401>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S409>/Square' */
  const real32_T d;                    /* '<S409>/Multiply' */
  const real32_T Gain4;                /* '<S409>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S411>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S418>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S411>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S422>/Square' */
  const real32_T d;                    /* '<S422>/Multiply' */
  const real32_T Gain4;                /* '<S422>/Gain4' */
} ConstB_MoveControl_FMS_k_T;

/* Invariant block signals for system '<S344>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S354>/Square' */
  const real32_T d;                    /* '<S354>/Multiply' */
  const real32_T Gain4;                /* '<S354>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S455>/Sum' */
  const real_T ff;                     /* '<S455>/Multiply3' */
  const real_T Sum4;                   /* '<S455>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S308>/Sum' */
  const real_T ff;                     /* '<S308>/Multiply3' */
  const real_T Sum4;                   /* '<S308>/Sum4' */
  const real_T deg2rad2;               /* '<S307>/deg2rad2' */
  const real_T SinCos_o1;              /* '<S310>/SinCos' */
  const real_T SinCos_o2;              /* '<S310>/SinCos' */
  const real32_T Square;               /* '<S63>/Square' */
  const real32_T d;                    /* '<S63>/Multiply' */
  const real32_T Gain4;                /* '<S63>/Gain4' */
  const real32_T Square_d;             /* '<S64>/Square' */
  const real32_T d_c;                  /* '<S64>/Multiply' */
  const real32_T Gain4_m;              /* '<S64>/Gain4' */
  const real32_T Square_m;             /* '<S131>/Square' */
  const real32_T d_d;                  /* '<S131>/Multiply' */
  const real32_T Gain4_n;              /* '<S131>/Gain4' */
  const real32_T Square_n;             /* '<S132>/Square' */
  const real32_T d_o;                  /* '<S132>/Multiply' */
  const real32_T Gain4_n3;             /* '<S132>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S221>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S167>/Math Function' */
  const real32_T SumofElements;        /* '<S167>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S167>/Math Function1' */
  const real32_T Product[2];           /* '<S167>/Product' */
  const real32_T Switch[3];            /* '<S167>/Switch' */
  const real32_T Divide[2];            /* '<S167>/Divide' */
  const real32_T Square_g;             /* '<S163>/Square' */
  const real32_T d_j;                  /* '<S163>/Multiply' */
  const real32_T Gain4_c;              /* '<S163>/Gain4' */
  const real32_T VectorConcatenate3_n[3];/* '<S301>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S302>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_i[3];/* '<S298>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_nj[3];/* '<S294>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e1[3];/* '<S232>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S234>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S323>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_iz[3];/* '<S325>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_k[3];/* '<S441>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S391>/Math Function' */
  const real32_T SumofElements_p;      /* '<S391>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S391>/Math Function1' */
  const real32_T Product_c[2];         /* '<S391>/Product' */
  const real32_T Switch_h[3];          /* '<S391>/Switch' */
  const real32_T Divide_d[2];          /* '<S391>/Divide' */
  const real32_T Square_k;             /* '<S387>/Square' */
  const real32_T d_l;                  /* '<S387>/Multiply' */
  const real32_T Gain4_np;             /* '<S387>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S374>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S449>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S35>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S35>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S40>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S40>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S40>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S39>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S39>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S39>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S41>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S41>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S41>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S38>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S38>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S38>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S150>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S150>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S150>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S147>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S147>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S147>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S326>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S326>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S326>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S328>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S328>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S328>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S327>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S327>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S327>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S329>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S329>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S329>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S32>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S32>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Disarm_FMS_T Unknown;         /* '<S29>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_i;       /* '<S33>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_k1;/* '<S109>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_at;/* '<S109>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_mr;/* '<S96>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_cr;/* '<S65>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S133>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_d;       /* '<S34>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_c;/* '<S191>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_d;/* '<S191>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S181>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_g;       /* '<S36>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_i;/* '<S356>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S356>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S344>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S334>/Move Control' */
  ConstB_MoveControl_FMS_k_T MoveControl_o;/* '<S411>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_k;/* '<S411>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S401>/Move Control' */
  ConstB_Disarm_FMS_T Disarm;          /* '<S27>/Disarm' */
} ConstB_FMS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S287>/Saturation1'
   *   '<S289>/Saturation'
   *   '<S290>/Saturation1'
   */
  real32_T pooled20[3];

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S287>/Saturation1'
   *   '<S289>/Saturation'
   *   '<S290>/Saturation1'
   */
  real32_T pooled21[3];
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
extern struct_YO5IBtWYxHURAIWIvUaGHE FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S3>/Constant1'
                                                *   '<S26>/Constant'
                                                *   '<S452>/Constant'
                                                *   '<S328>/L1'
                                                *   '<S46>/Gain'
                                                *   '<S46>/Gain1'
                                                *   '<S124>/Gain'
                                                *   '<S124>/Gain1'
                                                *   '<S150>/L1'
                                                *   '<S224>/Saturation'
                                                *   '<S225>/Saturation1'
                                                *   '<S225>/Saturation2'
                                                *   '<S225>/Saturation3'
                                                *   '<S369>/Constant'
                                                *   '<S370>/Saturation1'
                                                *   '<S443>/Gain2'
                                                *   '<S443>/Saturation1'
                                                *   '<S48>/Saturation1'
                                                *   '<S59>/Dead Zone'
                                                *   '<S59>/Gain'
                                                *   '<S60>/Dead Zone'
                                                *   '<S60>/Gain'
                                                *   '<S65>/Saturation'
                                                *   '<S81>/Saturation1'
                                                *   '<S96>/Saturation'
                                                *   '<S109>/Saturation1'
                                                *   '<S127>/Dead Zone'
                                                *   '<S127>/Gain'
                                                *   '<S128>/Dead Zone'
                                                *   '<S128>/Gain'
                                                *   '<S133>/Saturation'
                                                *   '<S278>/Gain2'
                                                *   '<S285>/Gain1'
                                                *   '<S285>/Gain2'
                                                *   '<S334>/Saturation1'
                                                *   '<S344>/Saturation'
                                                *   '<S356>/Saturation1'
                                                *   '<S371>/Gain2'
                                                *   '<S393>/vel'
                                                *   '<S393>/Saturation'
                                                *   '<S393>/Switch'
                                                *   '<S51>/Gain2'
                                                *   '<S52>/Gain1'
                                                *   '<S57>/Constant'
                                                *   '<S68>/Gain2'
                                                *   '<S69>/Gain1'
                                                *   '<S76>/Constant'
                                                *   '<S84>/Gain2'
                                                *   '<S85>/Gain1'
                                                *   '<S94>/Constant'
                                                *   '<S99>/Gain2'
                                                *   '<S100>/Gain1'
                                                *   '<S107>/Constant'
                                                *   '<S112>/Gain2'
                                                *   '<S113>/Gain6'
                                                *   '<S121>/Constant'
                                                *   '<S122>/Constant'
                                                *   '<S136>/Gain2'
                                                *   '<S137>/Gain1'
                                                *   '<S144>/Constant'
                                                *   '<S169>/Gain'
                                                *   '<S169>/Saturation1'
                                                *   '<S170>/vel'
                                                *   '<S170>/Saturation'
                                                *   '<S170>/Switch'
                                                *   '<S337>/Gain2'
                                                *   '<S338>/Gain1'
                                                *   '<S347>/Gain2'
                                                *   '<S348>/Gain1'
                                                *   '<S359>/Gain2'
                                                *   '<S360>/Gain6'
                                                *   '<S380>/Gain2'
                                                *   '<S380>/Saturation'
                                                *   '<S381>/Integrator'
                                                *   '<S54>/Constant'
                                                *   '<S56>/Dead Zone'
                                                *   '<S56>/Gain'
                                                *   '<S73>/Dead Zone'
                                                *   '<S73>/Gain'
                                                *   '<S88>/Constant'
                                                *   '<S90>/Dead Zone'
                                                *   '<S90>/Gain'
                                                *   '<S104>/Dead Zone'
                                                *   '<S104>/Gain'
                                                *   '<S117>/Dead Zone'
                                                *   '<S117>/Gain'
                                                *   '<S118>/Dead Zone'
                                                *   '<S118>/Gain'
                                                *   '<S141>/Dead Zone'
                                                *   '<S141>/Gain'
                                                *   '<S156>/Gain2'
                                                *   '<S156>/Saturation'
                                                *   '<S157>/Integrator'
                                                *   '<S340>/Dead Zone'
                                                *   '<S340>/Gain'
                                                *   '<S352>/Dead Zone'
                                                *   '<S352>/Gain'
                                                *   '<S364>/Dead Zone'
                                                *   '<S364>/Gain'
                                                *   '<S365>/Dead Zone'
                                                *   '<S365>/Gain'
                                                *   '<S401>/Saturation1'
                                                *   '<S411>/Saturation1'
                                                *   '<S181>/Saturation1'
                                                *   '<S191>/Saturation1'
                                                *   '<S404>/Gain2'
                                                *   '<S405>/Gain1'
                                                *   '<S414>/Gain2'
                                                *   '<S415>/Gain6'
                                                *   '<S184>/Gain2'
                                                *   '<S185>/Gain1'
                                                *   '<S194>/Gain2'
                                                *   '<S195>/Gain6'
                                                *   '<S407>/Dead Zone'
                                                *   '<S407>/Gain'
                                                *   '<S419>/Dead Zone'
                                                *   '<S419>/Gain'
                                                *   '<S420>/Dead Zone'
                                                *   '<S420>/Gain'
                                                *   '<S187>/Dead Zone'
                                                *   '<S187>/Gain'
                                                *   '<S199>/Dead Zone'
                                                *   '<S199>/Gain'
                                                *   '<S200>/Dead Zone'
                                                *   '<S200>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S12>/Constant1'
                                                 *   '<S450>/Constant'
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
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S215>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S391>/Data Type Duplicate' : Unused code path elimination
 * Block '<S392>/Data Type Duplicate' : Unused code path elimination
 * Block '<S435>/Data Type Duplicate' : Unused code path elimination
 * Block '<S436>/Data Type Duplicate' : Unused code path elimination
 * Block '<S432>/Data Type Duplicate' : Unused code path elimination
 * Block '<S433>/Data Type Duplicate' : Unused code path elimination
 * Block '<S439>/Data Type Duplicate' : Unused code path elimination
 * Block '<S468>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Reshape' : Reshape block reduction
 * Block '<S153>/Reshape' : Reshape block reduction
 * Block '<S153>/Reshape1' : Reshape block reduction
 * Block '<S153>/Reshape2' : Reshape block reduction
 * Block '<S395>/Reshape' : Reshape block reduction
 * Block '<S377>/Reshape' : Reshape block reduction
 * Block '<S377>/Reshape1' : Reshape block reduction
 * Block '<S377>/Reshape2' : Reshape block reduction
 * Block '<S448>/Reshape' : Reshape block reduction
 * Block '<S450>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S451>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S465>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S466>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S6>'   : 'FMS/Onground Check'
 * '<S7>'   : 'FMS/SafeMode'
 * '<S8>'   : 'FMS/Auto_Cmd_Valid/Compare To Constant4'
 * '<S9>'   : 'FMS/Auto_Cmd_Valid/Detect Change'
 * '<S10>'  : 'FMS/Auto_Cmd_Valid/Ever_Valid'
 * '<S11>'  : 'FMS/Auto_Cmd_Valid/Interval Test'
 * '<S12>'  : 'FMS/Command Process/Check Valid'
 * '<S13>'  : 'FMS/Command Process/Command PreProcess'
 * '<S14>'  : 'FMS/Command Process/Mode PreProcess'
 * '<S15>'  : 'FMS/Command Process/Check Valid/Compare To Constant1'
 * '<S16>'  : 'FMS/Command Process/Check Valid/Detect Change1'
 * '<S17>'  : 'FMS/Command Process/Command PreProcess/Compare To Constant'
 * '<S18>'  : 'FMS/Command Process/Command PreProcess/Detect Change3'
 * '<S19>'  : 'FMS/Command Process/Command PreProcess/Detect Change4'
 * '<S20>'  : 'FMS/Command Process/Command PreProcess/SetHome'
 * '<S21>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero'
 * '<S22>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero1'
 * '<S23>'  : 'FMS/Command Process/Mode PreProcess/Detect Change'
 * '<S24>'  : 'FMS/Detect_Lost_Connect/Detect Change'
 * '<S25>'  : 'FMS/Detect_Lost_Connect/Detect Change1'
 * '<S26>'  : 'FMS/Detect_Lost_Connect/timeout_s'
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
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1/DeadZone'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1/TD1'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1/TD1/fhan '
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Body_Frame'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask/Compare To Zero2'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero12'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero4'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero5'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid'
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Constant'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero6'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero7'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero8'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Constant'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero10'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero11'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero9'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid/bit_shift'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid/bit_shift'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid/bit_shift'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid/bit_shift'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid/bit_shift'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid/bit_shift'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid/bit_shift'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid/bit_shift'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Compare To Zero'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation/Compare To Constant'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command/Compare To Zero1'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_State'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero1'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM/Rotation Matrix Z'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2/Rotation Matrix Z'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Local_Position_Command'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask/Compare To Zero'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LAT2FLAT Curve'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/Rotation'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Body_Frame'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM'
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S330>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S331>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S332>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S333>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S334>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S335>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S336>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S337>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S338>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S339>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S340>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S341>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S342>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S343>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S344>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S345>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S346>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S347>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S348>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S349>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S350>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S351>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S352>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S353>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S354>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S355>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S356>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S357>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S358>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S359>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S360>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S361>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S362>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S363>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S364>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S365>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S366>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S367>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S368>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S369>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Compare To Constant'
 * '<S370>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S371>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S372>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S373>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S374>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S375>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S376>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S377>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S378>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S379>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S380>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S381>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S382>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S383>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S384>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S385>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S386>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S387>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S388>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S389>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S390>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S391>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S392>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S393>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S394>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S395>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S396>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S397>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S398>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S399>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S400>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S401>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S402>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S403>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S404>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S405>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S406>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S407>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S408>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S409>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S410>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S411>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S412>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S413>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S414>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S415>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S416>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S417>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S418>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S419>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S420>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S421>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S422>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S423>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S424>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S425>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S426>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S427>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S428>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S429>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S430>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S431>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S432>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S433>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S434>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S435>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S436>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S437>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S438>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S439>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S440>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S441>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S442>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S443>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S444>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S445>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S446>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S447>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S448>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S449>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S450>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S451>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S452>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S453>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S454>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S455>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S456>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S457>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S458>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S459>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S460>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S461>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S462>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S463>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S464>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S465>' : 'FMS/Onground Check/First Order LPF'
 * '<S466>' : 'FMS/Onground Check/First Order LPF1'
 * '<S467>' : 'FMS/Onground Check/First Order LPF2'
 * '<S468>' : 'FMS/Onground Check/Interval Test'
 * '<S469>' : 'FMS/Onground Check/Quaternion To DCM'
 * '<S470>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize'
 * '<S471>' : 'FMS/Onground Check/Quaternion To DCM/column_1'
 * '<S472>' : 'FMS/Onground Check/Quaternion To DCM/column_2'
 * '<S473>' : 'FMS/Onground Check/Quaternion To DCM/column_3'
 * '<S474>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
