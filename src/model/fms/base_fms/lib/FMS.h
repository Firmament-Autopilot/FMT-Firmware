/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1971
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul  8 09:55:29 2023
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

/* Block states (default storage) for system '<S402>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S405>/Delay' */
  uint8_T icLoad;                      /* '<S405>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S402>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S409>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S409>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S403>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S403>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S403>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S403>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S412>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S415>/Delay' */
  uint8_T icLoad;                      /* '<S415>/Delay' */
} DW_HoldControl_FMS_l_T;

/* Block states (default storage) for system '<S412>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S422>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S422>/Integrator' */
} DW_MoveControl_FMS_d_T;

/* Block states (default storage) for system '<S413>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S413>/Motion State' */
  uint8_T is_active_c2_FMS;            /* '<S413>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S413>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S345>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S348>/Delay' */
  uint8_T icLoad;                      /* '<S348>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S345>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S354>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S354>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S135>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S135>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S135>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S135>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S50>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S50>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S50>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S50>/Motion Status' */
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
  real32_T DataTypeConversion[3];      /* '<S454>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S455>/Reshape' */
  real32_T Merge[2];                   /* '<S110>/Merge' */
  real32_T Merge_k;                    /* '<S82>/Merge' */
  real32_T Merge_d;                    /* '<S97>/Merge' */
  real32_T Merge_l;                    /* '<S49>/Merge' */
  real32_T Merge_m;                    /* '<S66>/Merge' */
  real32_T Merge_j;                    /* '<S134>/Merge' */
  real32_T Merge_n[2];                 /* '<S192>/Merge' */
  real32_T Merge_e;                    /* '<S182>/Merge' */
  real32_T Merge_o[2];                 /* '<S357>/Merge' */
  real32_T Merge_ey;                   /* '<S335>/Merge' */
  real32_T Merge_n1;                   /* '<S345>/Merge' */
  real32_T Merge_mv[2];                /* '<S412>/Merge' */
  real32_T Merge_mu;                   /* '<S402>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S13>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T on_ground;                 /* '<S6>/Logical Operator1' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T Compare;                   /* '<S27>/Compare' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare_k;                 /* '<S467>/Compare' */
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
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S468>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S470>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S469>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE;         /* '<S62>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S62>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S63>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S63>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S130>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S130>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S131>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S131>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S175>/Delay' */
  real32_T l1_heading;                 /* '<S219>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S155>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S158>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S158>/Integrator' */
  real32_T Delay_DSTATE_e[2];          /* '<S398>/Delay' */
  real32_T l1_heading_p;               /* '<S439>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_p[2];          /* '<S378>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S379>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S382>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S382>/Integrator' */
  real32_T cur_waypoint_DSTATE[3];     /* '<S451>/cur_waypoint' */
  real32_T Integrator1_DSTATE_a;       /* '<S447>/Integrator1' */
  real32_T Integrator_DSTATE_m;        /* '<S447>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S16>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S12>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S23>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S18>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S19>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S24>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S25>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S9>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S453>/Discrete-Time Integrator' */
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
  uint16_T temporalCounter_i1_i;       /* '<S111>/Motion State' */
  uint8_T Delay_DSTATE_o;              /* '<S10>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S150>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S28>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S30>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S34>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S82>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S110>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S97>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S49>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S66>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S134>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S35>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S192>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S182>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S37>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S357>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S335>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S345>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S412>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S402>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S468>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S470>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S469>/Discrete-Time Integrator5' */
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
  uint8_T is_active_c16_FMS;           /* '<S111>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S111>/Motion State' */
  uint8_T icLoad;                      /* '<S175>/Delay' */
  uint8_T icLoad_k;                    /* '<S155>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S158>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S346>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S346>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S346>/Motion State' */
  uint8_T icLoad_o;                    /* '<S398>/Delay' */
  uint8_T icLoad_c;                    /* '<S378>/Delay' */
  uint8_T icLoad_j;                    /* '<S379>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S382>/Integrator1' */
  uint8_T icLoad_j1;                   /* '<S451>/cur_waypoint' */
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
  DW_MoveControl_FMS_d_T MoveControl_k1;/* '<S110>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_at;/* '<S110>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S98>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_mr;/* '<S97>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S97>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S83>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S82>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S67>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_cr;/* '<S66>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S66>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S50>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S49>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S135>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S134>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S134>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S193>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_c;/* '<S192>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_d;/* '<S192>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S183>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S182>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S182>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S358>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_i;/* '<S357>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_f;/* '<S357>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S345>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_kq;/* '<S345>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S336>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S335>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S335>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S413>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_o;/* '<S412>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_k;/* '<S412>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S403>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S402>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S402>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S147>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S13>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S402>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S410>/Square' */
  const real32_T d;                    /* '<S410>/Multiply' */
  const real32_T Gain4;                /* '<S410>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S412>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S419>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S412>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S423>/Square' */
  const real32_T d;                    /* '<S423>/Multiply' */
  const real32_T Gain4;                /* '<S423>/Gain4' */
} ConstB_MoveControl_FMS_k_T;

/* Invariant block signals for system '<S345>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S355>/Square' */
  const real32_T d;                    /* '<S355>/Multiply' */
  const real32_T Gain4;                /* '<S355>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S37>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S331>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S331>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S458>/Sum' */
  const real_T ff;                     /* '<S458>/Multiply3' */
  const real_T Sum4;                   /* '<S458>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S309>/Sum' */
  const real_T ff;                     /* '<S309>/Multiply3' */
  const real_T Sum4;                   /* '<S309>/Sum4' */
  const real_T deg2rad2;               /* '<S308>/deg2rad2' */
  const real_T SinCos_o1;              /* '<S311>/SinCos' */
  const real_T SinCos_o2;              /* '<S311>/SinCos' */
  const real32_T Square;               /* '<S64>/Square' */
  const real32_T d;                    /* '<S64>/Multiply' */
  const real32_T Gain4;                /* '<S64>/Gain4' */
  const real32_T Square_d;             /* '<S65>/Square' */
  const real32_T d_c;                  /* '<S65>/Multiply' */
  const real32_T Gain4_m;              /* '<S65>/Gain4' */
  const real32_T Square_m;             /* '<S132>/Square' */
  const real32_T d_d;                  /* '<S132>/Multiply' */
  const real32_T Gain4_n;              /* '<S132>/Gain4' */
  const real32_T Square_n;             /* '<S133>/Square' */
  const real32_T d_o;                  /* '<S133>/Multiply' */
  const real32_T Gain4_n3;             /* '<S133>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S222>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S168>/Math Function' */
  const real32_T SumofElements;        /* '<S168>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S168>/Math Function1' */
  const real32_T Product[2];           /* '<S168>/Product' */
  const real32_T Switch[3];            /* '<S168>/Switch' */
  const real32_T Divide[2];            /* '<S168>/Divide' */
  const real32_T Square_g;             /* '<S164>/Square' */
  const real32_T d_j;                  /* '<S164>/Multiply' */
  const real32_T Gain4_c;              /* '<S164>/Gain4' */
  const real32_T VectorConcatenate3_n[3];/* '<S302>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S303>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_i[3];/* '<S299>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_nj[3];/* '<S295>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e1[3];/* '<S233>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S235>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S324>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_iz[3];/* '<S326>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_k[3];/* '<S442>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S392>/Math Function' */
  const real32_T SumofElements_p;      /* '<S392>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S392>/Math Function1' */
  const real32_T Product_c[2];         /* '<S392>/Product' */
  const real32_T Switch_h[3];          /* '<S392>/Switch' */
  const real32_T Divide_d[2];          /* '<S392>/Divide' */
  const real32_T Square_k;             /* '<S388>/Square' */
  const real32_T d_l;                  /* '<S388>/Multiply' */
  const real32_T Gain4_np;             /* '<S388>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S375>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S452>/Vector Concatenate3' */
  const real32_T Square_b;             /* '<S448>/Square' */
  const real32_T d_m;                  /* '<S448>/Multiply' */
  const real32_T Gain4_a;              /* '<S448>/Gain4' */
  const uint8_T DataTypeConversion;    /* '<S36>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S36>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S41>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S41>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S41>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S40>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S40>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S40>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S42>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S42>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S42>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S39>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S39>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S39>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S151>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S151>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S151>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S148>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S148>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S148>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S327>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S327>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S327>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S329>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S329>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S329>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S328>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S328>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S328>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S330>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S330>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S330>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S33>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S33>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S32>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S32>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S30>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S34>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_k1;/* '<S110>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_at;/* '<S110>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_mr;/* '<S97>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_cr;/* '<S66>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S134>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S35>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_c;/* '<S192>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_d;/* '<S192>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S182>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S37>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_i;/* '<S357>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S357>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S345>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S335>/Move Control' */
  ConstB_MoveControl_FMS_k_T MoveControl_o;/* '<S412>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_k;/* '<S412>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S402>/Move Control' */
} ConstB_FMS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S288>/Saturation1'
   *   '<S290>/Saturation'
   *   '<S291>/Saturation1'
   */
  real32_T pooled20[3];

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S288>/Saturation1'
   *   '<S290>/Saturation'
   *   '<S291>/Saturation1'
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
                                                *   '<S455>/Constant'
                                                *   '<S329>/L1'
                                                *   '<S47>/Gain'
                                                *   '<S47>/Gain1'
                                                *   '<S125>/Gain'
                                                *   '<S125>/Gain1'
                                                *   '<S151>/L1'
                                                *   '<S225>/Saturation'
                                                *   '<S226>/Saturation1'
                                                *   '<S226>/Saturation2'
                                                *   '<S226>/Saturation3'
                                                *   '<S370>/Constant'
                                                *   '<S371>/Saturation1'
                                                *   '<S444>/Gain2'
                                                *   '<S444>/Saturation1'
                                                *   '<S49>/Saturation1'
                                                *   '<S60>/Dead Zone'
                                                *   '<S60>/Gain'
                                                *   '<S61>/Dead Zone'
                                                *   '<S61>/Gain'
                                                *   '<S66>/Saturation'
                                                *   '<S82>/Saturation1'
                                                *   '<S97>/Saturation'
                                                *   '<S110>/Saturation1'
                                                *   '<S128>/Dead Zone'
                                                *   '<S128>/Gain'
                                                *   '<S129>/Dead Zone'
                                                *   '<S129>/Gain'
                                                *   '<S134>/Saturation'
                                                *   '<S279>/Gain2'
                                                *   '<S286>/Gain1'
                                                *   '<S286>/Gain2'
                                                *   '<S335>/Saturation1'
                                                *   '<S345>/Saturation'
                                                *   '<S357>/Saturation1'
                                                *   '<S372>/Gain2'
                                                *   '<S394>/vel'
                                                *   '<S394>/Saturation'
                                                *   '<S394>/Switch'
                                                *   '<S52>/Gain2'
                                                *   '<S53>/Gain1'
                                                *   '<S58>/Constant'
                                                *   '<S69>/Gain2'
                                                *   '<S70>/Gain1'
                                                *   '<S77>/Constant'
                                                *   '<S85>/Gain2'
                                                *   '<S86>/Gain1'
                                                *   '<S95>/Constant'
                                                *   '<S100>/Gain2'
                                                *   '<S101>/Gain1'
                                                *   '<S108>/Constant'
                                                *   '<S113>/Gain2'
                                                *   '<S114>/Gain6'
                                                *   '<S122>/Constant'
                                                *   '<S123>/Constant'
                                                *   '<S137>/Gain2'
                                                *   '<S138>/Gain1'
                                                *   '<S145>/Constant'
                                                *   '<S170>/Gain'
                                                *   '<S170>/Saturation1'
                                                *   '<S171>/vel'
                                                *   '<S171>/Saturation'
                                                *   '<S171>/Switch'
                                                *   '<S338>/Gain2'
                                                *   '<S339>/Gain1'
                                                *   '<S348>/Gain2'
                                                *   '<S349>/Gain1'
                                                *   '<S360>/Gain2'
                                                *   '<S361>/Gain6'
                                                *   '<S381>/Gain2'
                                                *   '<S381>/Saturation'
                                                *   '<S382>/Integrator'
                                                *   '<S55>/Constant'
                                                *   '<S57>/Dead Zone'
                                                *   '<S57>/Gain'
                                                *   '<S74>/Dead Zone'
                                                *   '<S74>/Gain'
                                                *   '<S89>/Constant'
                                                *   '<S91>/Dead Zone'
                                                *   '<S91>/Gain'
                                                *   '<S105>/Dead Zone'
                                                *   '<S105>/Gain'
                                                *   '<S118>/Dead Zone'
                                                *   '<S118>/Gain'
                                                *   '<S119>/Dead Zone'
                                                *   '<S119>/Gain'
                                                *   '<S142>/Dead Zone'
                                                *   '<S142>/Gain'
                                                *   '<S157>/Gain2'
                                                *   '<S157>/Saturation'
                                                *   '<S158>/Integrator'
                                                *   '<S341>/Dead Zone'
                                                *   '<S341>/Gain'
                                                *   '<S353>/Dead Zone'
                                                *   '<S353>/Gain'
                                                *   '<S365>/Dead Zone'
                                                *   '<S365>/Gain'
                                                *   '<S366>/Dead Zone'
                                                *   '<S366>/Gain'
                                                *   '<S402>/Saturation1'
                                                *   '<S412>/Saturation1'
                                                *   '<S182>/Saturation1'
                                                *   '<S192>/Saturation1'
                                                *   '<S405>/Gain2'
                                                *   '<S406>/Gain1'
                                                *   '<S415>/Gain2'
                                                *   '<S416>/Gain6'
                                                *   '<S185>/Gain2'
                                                *   '<S186>/Gain1'
                                                *   '<S195>/Gain2'
                                                *   '<S196>/Gain6'
                                                *   '<S408>/Dead Zone'
                                                *   '<S408>/Gain'
                                                *   '<S420>/Dead Zone'
                                                *   '<S420>/Gain'
                                                *   '<S421>/Dead Zone'
                                                *   '<S421>/Gain'
                                                *   '<S188>/Dead Zone'
                                                *   '<S188>/Gain'
                                                *   '<S200>/Dead Zone'
                                                *   '<S200>/Gain'
                                                *   '<S201>/Dead Zone'
                                                *   '<S201>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S12>/Constant1'
                                                 *   '<S453>/Constant'
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
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S392>/Data Type Duplicate' : Unused code path elimination
 * Block '<S393>/Data Type Duplicate' : Unused code path elimination
 * Block '<S436>/Data Type Duplicate' : Unused code path elimination
 * Block '<S437>/Data Type Duplicate' : Unused code path elimination
 * Block '<S433>/Data Type Duplicate' : Unused code path elimination
 * Block '<S434>/Data Type Duplicate' : Unused code path elimination
 * Block '<S440>/Data Type Duplicate' : Unused code path elimination
 * Block '<S471>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Reshape' : Reshape block reduction
 * Block '<S154>/Reshape' : Reshape block reduction
 * Block '<S154>/Reshape1' : Reshape block reduction
 * Block '<S154>/Reshape2' : Reshape block reduction
 * Block '<S396>/Reshape' : Reshape block reduction
 * Block '<S378>/Reshape' : Reshape block reduction
 * Block '<S378>/Reshape1' : Reshape block reduction
 * Block '<S378>/Reshape2' : Reshape block reduction
 * Block '<S451>/Reshape' : Reshape block reduction
 * Block '<S453>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S29>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S29>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S29>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S454>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S468>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S469>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S26>'  : 'FMS/Detect_Lost_Connect/timeout1_s'
 * '<S27>'  : 'FMS/Detect_Lost_Connect/timeout2_s'
 * '<S28>'  : 'FMS/FMS Commander/Commander'
 * '<S29>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1/DeadZone'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1/TD1'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control1/TD1/fhan '
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Body_Frame'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask/Compare To Zero2'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero12'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero4'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero5'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid'
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Constant'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero6'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero7'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero8'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Constant'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero10'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero11'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero9'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid/bit_shift'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid/bit_shift'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid/bit_shift'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid/bit_shift'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid/bit_shift'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid/bit_shift'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid/bit_shift'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid/bit_shift'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Compare To Zero'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation/Compare To Constant'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command/Compare To Zero1'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_State'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero1'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Error/Psi To DCM/Rotation Matrix Z'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM1/Rotation Matrix Z'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_Error/Psi To DCM2/Rotation Matrix Z'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Local_Position_Command'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask/Compare To Zero'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LAT2FLAT Curve'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/Rotation'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Body_Frame'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame'
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S330>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S331>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S332>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S333>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S334>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S335>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S336>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S337>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S338>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S339>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S340>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S341>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S342>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S343>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S344>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S345>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S346>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S347>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S348>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S349>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S350>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S351>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S352>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S353>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S354>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S355>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S356>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S357>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S358>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S359>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S360>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S361>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S362>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S363>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S364>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S365>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S366>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S367>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S368>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S369>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S370>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Compare To Constant'
 * '<S371>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S372>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S373>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S374>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S375>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S376>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S377>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S378>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S379>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S380>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S381>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S382>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S383>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S384>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S385>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S386>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S387>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S388>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S389>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S390>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S391>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S392>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S393>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S394>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S395>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S396>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S397>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S398>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S399>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S400>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S401>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S402>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S403>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S404>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S405>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S406>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S407>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S408>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S409>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S410>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S411>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S412>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S413>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S414>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S415>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S416>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S417>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S418>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S419>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S420>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S421>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S422>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S423>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S424>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S425>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S426>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S427>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S428>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S429>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S430>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S431>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S432>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S433>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S434>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S435>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S436>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S437>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S438>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S439>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S440>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S441>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S442>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S443>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S444>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S445>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S446>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S447>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD'
 * '<S448>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD/fhan '
 * '<S449>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S450>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S451>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S452>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S453>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S454>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S455>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S456>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S457>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S458>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S459>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S460>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S461>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S462>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S463>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S464>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S465>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S466>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S467>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S468>' : 'FMS/Onground Check/First Order LPF'
 * '<S469>' : 'FMS/Onground Check/First Order LPF1'
 * '<S470>' : 'FMS/Onground Check/First Order LPF2'
 * '<S471>' : 'FMS/Onground Check/Interval Test'
 * '<S472>' : 'FMS/Onground Check/Quaternion To DCM'
 * '<S473>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize'
 * '<S474>' : 'FMS/Onground Check/Quaternion To DCM/column_1'
 * '<S475>' : 'FMS/Onground Check/Quaternion To DCM/column_2'
 * '<S476>' : 'FMS/Onground Check/Quaternion To DCM/column_3'
 * '<S477>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
