/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2127
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May  4 16:24:12 2024
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

/* Block states (default storage) for system '<S368>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S371>/Delay' */
  uint8_T icLoad;                      /* '<S371>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S368>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S375>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S375>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S369>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S369>/Motion Status' */
  uint8_T is_active_c10_FMS;           /* '<S369>/Motion Status' */
  uint8_T is_c10_FMS;                  /* '<S369>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S378>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S381>/Delay' */
  uint8_T icLoad;                      /* '<S381>/Delay' */
} DW_HoldControl_FMS_j_T;

/* Block states (default storage) for system '<S379>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S379>/Motion State' */
  uint8_T is_active_c23_FMS;           /* '<S379>/Motion State' */
  uint8_T is_c23_FMS;                  /* '<S379>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S310>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S320>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S320>/Integrator' */
} DW_MoveControl_FMS_k_T;

/* Block states (default storage) for system '<S46>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S46>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S46>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S46>/Motion Status' */
} DW_MotionStatus_FMS_b_T;

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
  real32_T DataTypeConversion[3];      /* '<S421>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S422>/Reshape' */
  real32_T Merge;                      /* '<S59>/Merge' */
  real32_T Merge_p;                    /* '<S69>/Merge' */
  real32_T Merge_py;                   /* '<S45>/Merge' */
  real32_T Merge_n[2];                 /* '<S144>/Merge' */
  real32_T Merge_e;                    /* '<S134>/Merge' */
  real32_T Merge_o[2];                 /* '<S310>/Merge' */
  real32_T Merge_ey;                   /* '<S288>/Merge' */
  real32_T Merge_n1;                   /* '<S298>/Merge' */
  real32_T Merge_a[2];                 /* '<S378>/Merge' */
  real32_T Merge_j;                    /* '<S368>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S12>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T Compare;                   /* '<S26>/Compare' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare_k;                 /* '<S434>/Compare' */
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
  real32_T Delay_DSTATE;               /* '<S72>/Delay' */
  real32_T Delay_DSTATE_p[2];          /* '<S123>/Delay' */
  real32_T Acceleration_Speed_DSTATE;  /* '<S119>/Acceleration_Speed' */
  real32_T l1_heading;                 /* '<S171>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S101>/Delay' */
  real32_T Integrator1_DSTATE;         /* '<S104>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S104>/Integrator' */
  real32_T Integrator1_DSTATE_k;       /* '<S307>/Integrator1' */
  real32_T Integrator_DSTATE_h;        /* '<S307>/Integrator' */
  real32_T Delay_DSTATE_g;             /* '<S301>/Delay' */
  real32_T Delay_DSTATE_e[2];          /* '<S357>/Delay' */
  real32_T Acceleration_Speed_DSTATE_j;/* '<S353>/Acceleration_Speed' */
  real32_T l1_heading_e;               /* '<S405>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_a;             /* '<S335>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S338>/Integrator1' */
  real32_T Delay_DSTATE_px[2];         /* '<S334>/Delay' */
  real32_T Integrator_DSTATE_b;        /* '<S338>/Integrator' */
  real32_T Integrator1_DSTATE_m[2];    /* '<S388>/Integrator1' */
  real32_T Integrator_DSTATE_bz[2];    /* '<S388>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S326>/Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S326>/Integrator' */
  real32_T cur_waypoint_DSTATE[3];     /* '<S418>/cur_waypoint' */
  real32_T Integrator1_DSTATE_a;       /* '<S414>/Integrator1' */
  real32_T Integrator_DSTATE_m;        /* '<S414>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S15>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S11>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S22>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S17>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S18>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S23>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S24>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S8>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S420>/Discrete-Time Integrator' */
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
  uint16_T temporalCounter_i1_i;       /* '<S70>/Motion State' */
  uint8_T Delay_DSTATE_o;              /* '<S9>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S96>/Delay Input1' */
  uint8_T DiscreteTimeIntegrator_DSTATE_k;/* '<S124>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_DSTATE_m;/* '<S358>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S27>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S29>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S33>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S69>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S59>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S45>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S34>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetSta;/* '<S119>/Acceleration_Speed' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S144>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S134>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S36>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pv;/* '<S310>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S288>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S298>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetS_j;/* '<S353>/Acceleration_Speed' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S378>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S368>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S70>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S70>/Motion State' */
  uint8_T icLoad;                      /* '<S72>/Delay' */
  uint8_T icLoad_i;                    /* '<S123>/Delay' */
  uint8_T icLoad_k;                    /* '<S101>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S104>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S299>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S299>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S299>/Motion State' */
  uint8_T icLoad_g;                    /* '<S301>/Delay' */
  uint8_T icLoad_l;                    /* '<S357>/Delay' */
  uint8_T icLoad_j;                    /* '<S335>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S338>/Integrator1' */
  uint8_T icLoad_c;                    /* '<S334>/Delay' */
  uint8_T icLoad_j1;                   /* '<S418>/cur_waypoint' */
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
  DW_MotionStatus_FMS_b_T sf_MotionStatus_h;/* '<S60>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_kw; /* '<S59>/Hold Control' */
  DW_MotionStatus_FMS_b_T sf_MotionStatus_n;/* '<S46>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_da; /* '<S45>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S145>/Motion State' */
  DW_MoveControl_FMS_k_T MoveControl_c;/* '<S144>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_d;/* '<S144>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S135>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S134>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S134>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S311>/Motion State' */
  DW_MoveControl_FMS_k_T MoveControl_i;/* '<S310>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_f;/* '<S310>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S289>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S288>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S288>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S379>/Motion State' */
  DW_HoldControl_FMS_j_T HoldControl_m;/* '<S378>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S369>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S368>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S368>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S93>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S12>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S368>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S376>/Square' */
  const real32_T d;                    /* '<S376>/Multiply' */
  const real32_T Gain4;                /* '<S376>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S378>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S385>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_f_T;

/* Invariant block signals for system '<S310>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S321>/Square' */
  const real32_T d;                    /* '<S321>/Multiply' */
  const real32_T Gain4;                /* '<S321>/Gain4' */
} ConstB_MoveControl_FMS_o_T;

/* Invariant block signals for system '<S36>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S284>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S284>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S425>/Sum' */
  const real_T ff;                     /* '<S425>/Multiply3' */
  const real_T Sum4;                   /* '<S425>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S262>/Sum' */
  const real_T ff;                     /* '<S262>/Multiply3' */
  const real_T Sum4;                   /* '<S262>/Sum4' */
  const real_T deg2rad2;               /* '<S261>/deg2rad2' */
  const real_T SinCos_o1;              /* '<S264>/SinCos' */
  const real_T SinCos_o2;              /* '<S264>/SinCos' */
  const real32_T VectorConcatenate3[3];/* '<S76>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S174>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S114>/Math Function' */
  const real32_T SumofElements;        /* '<S114>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S114>/Math Function1' */
  const real32_T Product[2];           /* '<S114>/Product' */
  const real32_T Switch[3];            /* '<S114>/Switch' */
  const real32_T Divide[2];            /* '<S114>/Divide' */
  const real32_T Square;               /* '<S110>/Square' */
  const real32_T d;                    /* '<S110>/Multiply' */
  const real32_T Gain4;                /* '<S110>/Gain4' */
  const real32_T VectorConcatenate3_n[3];/* '<S255>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e0[3];/* '<S256>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_i[3];/* '<S252>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_nj[3];/* '<S248>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e1[3];/* '<S186>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S188>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S277>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_iz[3];/* '<S279>/Vector Concatenate3' */
  const real32_T Square_n;             /* '<S308>/Square' */
  const real32_T d_j;                  /* '<S308>/Multiply' */
  const real32_T Gain4_c;              /* '<S308>/Gain4' */
  const real32_T VectorConcatenate3_c[3];/* '<S408>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S348>/Math Function' */
  const real32_T SumofElements_p;      /* '<S348>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S348>/Math Function1' */
  const real32_T Product_c[2];         /* '<S348>/Product' */
  const real32_T Switch_h[3];          /* '<S348>/Switch' */
  const real32_T Divide_d[2];          /* '<S348>/Divide' */
  const real32_T Square_k;             /* '<S344>/Square' */
  const real32_T d_l;                  /* '<S344>/Multiply' */
  const real32_T Gain4_n;              /* '<S344>/Gain4' */
  const real32_T Square_f;             /* '<S389>/Square' */
  const real32_T d_a;                  /* '<S389>/Multiply' */
  const real32_T Gain4_m;              /* '<S389>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S331>/Vector Concatenate3' */
  const real32_T Square_e;             /* '<S327>/Square' */
  const real32_T d_p;                  /* '<S327>/Multiply' */
  const real32_T Gain4_e;              /* '<S327>/Gain4' */
  const real32_T VectorConcatenate3_fb[3];/* '<S419>/Vector Concatenate3' */
  const real32_T Square_b;             /* '<S415>/Square' */
  const real32_T d_m;                  /* '<S415>/Multiply' */
  const real32_T Gain4_a;              /* '<S415>/Gain4' */
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
  const uint8_T DataTypeConversion_l;  /* '<S97>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S97>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S97>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S94>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S94>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S94>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S280>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S280>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S280>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S282>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S282>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S282>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S281>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S281>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S281>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S283>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S283>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S283>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S32>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S32>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S31>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S31>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S29>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S33>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S34>/Unknown' */
  ConstB_MoveControl_FMS_o_T MoveControl_c;/* '<S144>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_d;/* '<S144>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S134>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S36>/Unknown' */
  ConstB_MoveControl_FMS_o_T MoveControl_i;/* '<S310>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_f;/* '<S310>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S288>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_m;/* '<S378>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S368>/Move Control' */
} ConstB_FMS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S241>/Saturation1'
   *   '<S243>/Saturation'
   *   '<S244>/Saturation1'
   */
  real32_T pooled22[3];

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S241>/Saturation1'
   *   '<S243>/Saturation'
   *   '<S244>/Saturation1'
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
extern struct_pJ9vX14fiEgD1ptfg18n3D FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S3>/Constant1'
                                                *   '<S25>/Constant'
                                                *   '<S422>/Constant'
                                                *   '<S282>/L1'
                                                *   '<S43>/Gain6'
                                                *   '<S44>/Gain6'
                                                *   '<S57>/Gain6'
                                                *   '<S87>/Gain6'
                                                *   '<S88>/Gain6'
                                                *   '<S89>/Gain6'
                                                *   '<S97>/L1'
                                                *   '<S178>/Saturation'
                                                *   '<S179>/Saturation1'
                                                *   '<S179>/Saturation2'
                                                *   '<S179>/Saturation3'
                                                *   '<S323>/Land_Speed'
                                                *   '<S324>/Saturation1'
                                                *   '<S410>/Takeoff_Speed'
                                                *   '<S411>/Gain2'
                                                *   '<S411>/Saturation1'
                                                *   '<S45>/Saturation1'
                                                *   '<S54>/Dead Zone'
                                                *   '<S54>/Gain'
                                                *   '<S55>/Dead Zone'
                                                *   '<S55>/Gain'
                                                *   '<S59>/Saturation1'
                                                *   '<S68>/Dead Zone'
                                                *   '<S68>/Gain'
                                                *   '<S69>/Saturation1'
                                                *   '<S90>/Dead Zone'
                                                *   '<S90>/Gain'
                                                *   '<S91>/Dead Zone'
                                                *   '<S91>/Gain'
                                                *   '<S92>/Dead Zone'
                                                *   '<S92>/Gain'
                                                *   '<S232>/Gain2'
                                                *   '<S239>/Gain1'
                                                *   '<S239>/Gain2'
                                                *   '<S288>/Saturation1'
                                                *   '<S298>/Saturation'
                                                *   '<S310>/Saturation1'
                                                *   '<S325>/Constant'
                                                *   '<S328>/Gain2'
                                                *   '<S350>/Gain'
                                                *   '<S350>/Saturation1'
                                                *   '<S353>/Constant'
                                                *   '<S353>/vel'
                                                *   '<S353>/Switch'
                                                *   '<S48>/Gain2'
                                                *   '<S49>/Gain1'
                                                *   '<S52>/Constant'
                                                *   '<S62>/Gain2'
                                                *   '<S63>/Gain1'
                                                *   '<S66>/Constant'
                                                *   '<S72>/Gain2'
                                                *   '<S73>/Gain6'
                                                *   '<S79>/Constant'
                                                *   '<S116>/Gain'
                                                *   '<S116>/Saturation1'
                                                *   '<S119>/Constant'
                                                *   '<S119>/vel'
                                                *   '<S119>/Switch'
                                                *   '<S291>/Gain2'
                                                *   '<S292>/Gain1'
                                                *   '<S301>/Gain2'
                                                *   '<S302>/Gain1'
                                                *   '<S313>/Gain2'
                                                *   '<S314>/Gain6'
                                                *   '<S337>/Gain2'
                                                *   '<S337>/Saturation'
                                                *   '<S338>/Integrator'
                                                *   '<S51>/Dead Zone'
                                                *   '<S51>/Gain'
                                                *   '<S65>/Dead Zone'
                                                *   '<S65>/Gain'
                                                *   '<S77>/Dead Zone'
                                                *   '<S77>/Gain'
                                                *   '<S103>/Gain2'
                                                *   '<S103>/Saturation'
                                                *   '<S104>/Integrator'
                                                *   '<S294>/Dead Zone'
                                                *   '<S294>/Gain'
                                                *   '<S306>/Dead Zone'
                                                *   '<S306>/Gain'
                                                *   '<S318>/Dead Zone'
                                                *   '<S318>/Gain'
                                                *   '<S319>/Dead Zone'
                                                *   '<S319>/Gain'
                                                *   '<S368>/Saturation1'
                                                *   '<S378>/Saturation1'
                                                *   '<S134>/Saturation1'
                                                *   '<S144>/Saturation1'
                                                *   '<S371>/Gain2'
                                                *   '<S372>/Gain1'
                                                *   '<S381>/Gain2'
                                                *   '<S382>/Gain6'
                                                *   '<S137>/Gain2'
                                                *   '<S138>/Gain1'
                                                *   '<S147>/Gain2'
                                                *   '<S148>/Gain6'
                                                *   '<S374>/Dead Zone'
                                                *   '<S374>/Gain'
                                                *   '<S386>/Dead Zone'
                                                *   '<S386>/Gain'
                                                *   '<S387>/Dead Zone'
                                                *   '<S387>/Gain'
                                                *   '<S140>/Dead Zone'
                                                *   '<S140>/Gain'
                                                *   '<S152>/Dead Zone'
                                                *   '<S152>/Gain'
                                                *   '<S153>/Dead Zone'
                                                *   '<S153>/Gain'
                                                */
extern struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S11>/Constant1'
                                                 *   '<S420>/Constant'
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
 * Block '<S114>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Propagation' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Propagation' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S348>/Data Type Duplicate' : Unused code path elimination
 * Block '<S349>/Data Type Duplicate' : Unused code path elimination
 * Block '<S363>/Data Type Duplicate' : Unused code path elimination
 * Block '<S363>/Data Type Propagation' : Unused code path elimination
 * Block '<S364>/Data Type Duplicate' : Unused code path elimination
 * Block '<S364>/Data Type Propagation' : Unused code path elimination
 * Block '<S402>/Data Type Duplicate' : Unused code path elimination
 * Block '<S403>/Data Type Duplicate' : Unused code path elimination
 * Block '<S399>/Data Type Duplicate' : Unused code path elimination
 * Block '<S400>/Data Type Duplicate' : Unused code path elimination
 * Block '<S406>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Signal Copy7' : Unused code path elimination
 * Block '<S121>/Reshape' : Reshape block reduction
 * Block '<S100>/Reshape' : Reshape block reduction
 * Block '<S100>/Reshape1' : Reshape block reduction
 * Block '<S100>/Reshape2' : Reshape block reduction
 * Block '<S355>/Reshape' : Reshape block reduction
 * Block '<S334>/Reshape' : Reshape block reduction
 * Block '<S334>/Reshape1' : Reshape block reduction
 * Block '<S334>/Reshape2' : Reshape block reduction
 * Block '<S418>/Reshape' : Reshape block reduction
 * Block '<S420>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S28>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S421>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Speed Command'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone2'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Speed Command/DeadZone2'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone2'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Brake Control'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Move Control'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Bus_Selection'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Psi To DCM'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Move Control/DeadZone'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Compare To Constant1'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Motion State'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/Quaternion Normalize'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_1'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_2'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_3'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command '
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command /DeadZone2'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone2'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command/DeadZone2'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Constant'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Zero'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Compare To Zero'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic1'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter/Compare To Constant'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Body_Frame'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask/Compare To Zero2'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero12'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero4'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero5'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Constant'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero6'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero7'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero8'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Constant'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero10'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero11'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero9'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid/bit_shift'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid/bit_shift'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid/bit_shift'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid/bit_shift'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid/bit_shift'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid/bit_shift'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid/bit_shift'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid/bit_shift'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Compare To Zero'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation/Compare To Constant'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command/Compare To Zero1'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_State'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero1'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM/Rotation Matrix Z'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2/Rotation Matrix Z'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Local_Position_Command'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask/Compare To Zero'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LAT2FLAT Curve'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/Rotation'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Body_Frame'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/Compare To Constant'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD/fhan '
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S330>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S331>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S332>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S333>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1'
 * '<S334>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S335>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S336>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S337>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S338>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S339>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S340>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S341>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S342>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S343>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S344>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S345>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S346>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S347>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S348>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S349>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S350>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control'
 * '<S351>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Compare To Constant'
 * '<S352>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Compare To Zero'
 * '<S353>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed '
 * '<S354>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position'
 * '<S355>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP'
 * '<S356>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration'
 * '<S357>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed'
 * '<S358>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/ValidCounter'
 * '<S359>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height'
 * '<S360>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height/Vector Modulus'
 * '<S361>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Altitude Control/Target Height/Vector Modulus1'
 * '<S362>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Compare To Zero'
 * '<S363>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Saturation Dynamic'
 * '<S364>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Saturation Dynamic1'
 * '<S365>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Cruise Speed /Vector Modulus'
 * '<S366>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold'
 * '<S367>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold'
 * '<S368>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller'
 * '<S369>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Detect Movement'
 * '<S370>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S371>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S372>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S373>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S374>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S375>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S376>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S377>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S378>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller'
 * '<S379>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Detect Movement'
 * '<S380>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Brake Control'
 * '<S381>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control'
 * '<S382>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control'
 * '<S383>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S384>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S385>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S386>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S387>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S388>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S389>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S390>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S391>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/Compare To Constant'
 * '<S392>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/Compare To Constant1'
 * '<S393>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/NearbyRefWP'
 * '<S394>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/OutRegionRegWP'
 * '<S395>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/L1 Reference WP/SearchL1RefWP'
 * '<S396>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle'
 * '<S397>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Modulus'
 * '<S398>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Modulus1'
 * '<S399>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Normalize'
 * '<S400>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Vector Normalize1'
 * '<S401>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S402>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S403>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S404>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Ground Speed'
 * '<S405>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S406>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S407>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S408>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S409>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander1/ValidCounter/Compare To Constant'
 * '<S410>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S411>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S412>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S413>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S414>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD'
 * '<S415>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD/fhan '
 * '<S416>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S417>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S418>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S419>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S420>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S421>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S422>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S423>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S424>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S425>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S426>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S427>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S428>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S429>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S430>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S431>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S432>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S433>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S434>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
