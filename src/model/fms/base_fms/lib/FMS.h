/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1679
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Mar 22 16:04:04 2022
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

/* Block states (default storage) for system '<S277>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S280>/Delay' */
  uint8_T icLoad;                      /* '<S280>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S277>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S284>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S284>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S278>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S278>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S278>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S278>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S287>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S290>/Delay' */
  uint8_T icLoad;                      /* '<S290>/Delay' */
} DW_HoldControl_FMS_l_T;

/* Block states (default storage) for system '<S287>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S297>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S297>/Integrator' */
} DW_MoveControl_FMS_d_T;

/* Block states (default storage) for system '<S288>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S288>/Motion State' */
  uint8_T is_active_c2_FMS;            /* '<S288>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S288>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S221>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S224>/Delay' */
  uint8_T icLoad;                      /* '<S224>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S221>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S230>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S230>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S118>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S118>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S118>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S118>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S37>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S37>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S37>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S37>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Commander_In_Bus Cmd_In;             /* '<Root>/FMS State Machine' */
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  real_T lla[3];                       /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T href;                         /* '<Root>/FMS State Machine' */
  real_T psio;                         /* '<Root>/FMS State Machine' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T Reshape[3];                 /* '<S326>/Reshape' */
  real32_T DataTypeConversion[3];      /* '<S325>/Data Type Conversion' */
  real32_T Merge[2];                   /* '<S93>/Merge' */
  real32_T Merge_k;                    /* '<S69>/Merge' */
  real32_T Merge_d;                    /* '<S80>/Merge' */
  real32_T Merge_l;                    /* '<S36>/Merge' */
  real32_T Merge_m;                    /* '<S53>/Merge' */
  real32_T Merge_j;                    /* '<S117>/Merge' */
  real32_T Merge_n[2];                 /* '<S173>/Merge' */
  real32_T Merge_e;                    /* '<S163>/Merge' */
  real32_T Merge_o[2];                 /* '<S233>/Merge' */
  real32_T Merge_ey;                   /* '<S211>/Merge' */
  real32_T Merge_n1;                   /* '<S221>/Merge' */
  real32_T Merge_mv[2];                /* '<S287>/Merge' */
  real32_T Merge_mu;                   /* '<S277>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/Mode Degrade' */
  FMS_Cmd Switch1;                     /* '<S8>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator1;          /* '<S6>/Logical Operator1' */
  boolean_T Compare;                   /* '<S338>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission_takeoff;         /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_m[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_p;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S340>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S341>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S49>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S49>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S50>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S50>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S113>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S113>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S114>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S114>/Integrator' */
  real32_T l1_heading;                 /* '<S199>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE;               /* '<S136>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S139>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S139>/Integrator' */
  real32_T Delay_DSTATE_p[2];          /* '<S253>/Delay' */
  real32_T l1_heading_m;               /* '<S313>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_a;             /* '<S254>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S257>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S257>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S11>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S7>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S16>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S12>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S13>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S20>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_c;            /* '<S9>/Delay' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_p;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_l;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_g;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_a;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2_d;/* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_i;       /* '<S94>/Motion State' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S2>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S17>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S21>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S93>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S69>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S80>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S36>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S53>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S117>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S173>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S163>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S24>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S233>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S211>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S221>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S287>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S277>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S340>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S341>/Discrete-Time Integrator5' */
  uint8_T is_active_c3_FMS;            /* '<Root>/Mode Degrade' */
  uint8_T is_c3_FMS;                   /* '<Root>/Mode Degrade' */
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
  uint8_T is_active_c16_FMS;           /* '<S94>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S94>/Motion State' */
  uint8_T icLoad;                      /* '<S136>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S139>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S222>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S222>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S222>/Motion State' */
  uint8_T icLoad_c;                    /* '<S253>/Delay' */
  uint8_T icLoad_j;                    /* '<S254>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S257>/Integrator1' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_g;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_n;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_i;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_gz;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_l;/* '<Root>/FMS State Machine' */
  DW_MoveControl_FMS_d_T MoveControl_k1;/* '<S93>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_at;/* '<S93>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S81>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_mr;/* '<S80>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S80>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S70>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_be; /* '<S69>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S69>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S54>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_cr;/* '<S53>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S53>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S37>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_l;  /* '<S36>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S36>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S118>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S117>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S117>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S174>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_c;/* '<S173>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_d;/* '<S173>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S164>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S163>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S163>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S234>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_i;/* '<S233>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_f;/* '<S233>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S221>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_kq;/* '<S221>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S212>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S211>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S211>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S288>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_o;/* '<S287>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_k;/* '<S287>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S278>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S277>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S277>/Hold Control' */
} DW_FMS_T;

/* Invariant block signals for system '<S2>/Disarm' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S18>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S18>/Data Type Conversion1' */
} ConstB_Disarm_FMS_T;

/* Invariant block signals for system '<S277>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S285>/Square' */
  const real32_T d;                    /* '<S285>/Multiply' */
  const real32_T Gain4;                /* '<S285>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S287>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S294>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S287>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S298>/Square' */
  const real32_T d;                    /* '<S298>/Multiply' */
  const real32_T Gain4;                /* '<S298>/Gain4' */
} ConstB_MoveControl_FMS_k_T;

/* Invariant block signals for system '<S221>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S231>/Square' */
  const real32_T d;                    /* '<S231>/Multiply' */
  const real32_T Gain4;                /* '<S231>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S329>/Sum' */
  const real_T ff;                     /* '<S329>/Multiply3' */
  const real_T Sum4;                   /* '<S329>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Square;               /* '<S51>/Square' */
  const real32_T d;                    /* '<S51>/Multiply' */
  const real32_T Gain4;                /* '<S51>/Gain4' */
  const real32_T Square_d;             /* '<S52>/Square' */
  const real32_T d_c;                  /* '<S52>/Multiply' */
  const real32_T Gain4_m;              /* '<S52>/Gain4' */
  const real32_T Square_m;             /* '<S115>/Square' */
  const real32_T d_d;                  /* '<S115>/Multiply' */
  const real32_T Gain4_n;              /* '<S115>/Gain4' */
  const real32_T Square_n;             /* '<S116>/Square' */
  const real32_T d_o;                  /* '<S116>/Multiply' */
  const real32_T Gain4_n3;             /* '<S116>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S202>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S149>/Math Function' */
  const real32_T SumofElements;        /* '<S149>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S149>/Math Function1' */
  const real32_T Product[2];           /* '<S149>/Product' */
  const real32_T Switch[3];            /* '<S149>/Switch' */
  const real32_T Divide[2];            /* '<S149>/Divide' */
  const real32_T Square_g;             /* '<S145>/Square' */
  const real32_T d_j;                  /* '<S145>/Multiply' */
  const real32_T Gain4_c;              /* '<S145>/Gain4' */
  const real32_T VectorConcatenate3_b[3];/* '<S316>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S267>/Math Function' */
  const real32_T SumofElements_p;      /* '<S267>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S267>/Math Function1' */
  const real32_T Product_c[2];         /* '<S267>/Product' */
  const real32_T Switch_h[3];          /* '<S267>/Switch' */
  const real32_T Divide_d[2];          /* '<S267>/Divide' */
  const real32_T Square_k;             /* '<S263>/Square' */
  const real32_T d_l;                  /* '<S263>/Multiply' */
  const real32_T Gain4_np;             /* '<S263>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S250>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S324>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S23>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S23>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S28>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S28>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S27>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S29>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S29>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S29>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S26>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S26>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S26>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S130>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S130>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S130>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S131>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S131>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S203>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S203>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S203>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S205>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S205>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S205>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S204>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S204>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S204>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S206>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S206>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S206>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S19>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S19>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Disarm_FMS_T Unknown;         /* '<S17>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_i;       /* '<S21>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_k1;/* '<S93>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_at;/* '<S93>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_mr;/* '<S80>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_be;/* '<S69>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_cr;/* '<S53>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_l;/* '<S36>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S117>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_d;       /* '<S22>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_c;/* '<S173>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_d;/* '<S173>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S163>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_g;       /* '<S24>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_i;/* '<S233>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S233>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S221>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S211>/Move Control' */
  ConstB_MoveControl_FMS_k_T MoveControl_o;/* '<S287>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_k;/* '<S287>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S277>/Move Control' */
  ConstB_Disarm_FMS_T Disarm;          /* '<S2>/Disarm' */
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
extern struct_uudoY3KKhhekMiesgAnP2G FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<S326>/Constant'
                                                *   '<S130>/L1'
                                                *   '<S205>/L1'
                                                *   '<S34>/Gain'
                                                *   '<S34>/Gain1'
                                                *   '<S108>/Gain'
                                                *   '<S108>/Gain1'
                                                *   '<S246>/Saturation1'
                                                *   '<S318>/Gain2'
                                                *   '<S318>/Saturation1'
                                                *   '<S36>/Saturation1'
                                                *   '<S47>/Dead Zone'
                                                *   '<S47>/Gain'
                                                *   '<S48>/Dead Zone'
                                                *   '<S48>/Gain'
                                                *   '<S53>/Saturation'
                                                *   '<S69>/Saturation1'
                                                *   '<S80>/Saturation'
                                                *   '<S93>/Saturation1'
                                                *   '<S111>/Dead Zone'
                                                *   '<S111>/Gain'
                                                *   '<S112>/Dead Zone'
                                                *   '<S112>/Gain'
                                                *   '<S117>/Saturation'
                                                *   '<S151>/Gain'
                                                *   '<S151>/Saturation1'
                                                *   '<S152>/vel'
                                                *   '<S211>/Saturation1'
                                                *   '<S221>/Saturation'
                                                *   '<S233>/Saturation1'
                                                *   '<S247>/Gain2'
                                                *   '<S269>/vel'
                                                *   '<S39>/Gain2'
                                                *   '<S40>/Gain1'
                                                *   '<S45>/Constant'
                                                *   '<S56>/Gain2'
                                                *   '<S57>/Gain1'
                                                *   '<S64>/Constant'
                                                *   '<S72>/Gain2'
                                                *   '<S73>/Gain1'
                                                *   '<S78>/Constant'
                                                *   '<S83>/Gain2'
                                                *   '<S84>/Gain1'
                                                *   '<S91>/Constant'
                                                *   '<S96>/Gain2'
                                                *   '<S97>/Gain6'
                                                *   '<S105>/Constant'
                                                *   '<S106>/Constant'
                                                *   '<S120>/Gain2'
                                                *   '<S121>/Gain1'
                                                *   '<S128>/Constant'
                                                *   '<S138>/Gain2'
                                                *   '<S138>/Saturation'
                                                *   '<S139>/Integrator'
                                                *   '<S214>/Gain2'
                                                *   '<S215>/Gain1'
                                                *   '<S224>/Gain2'
                                                *   '<S225>/Gain1'
                                                *   '<S236>/Gain2'
                                                *   '<S237>/Gain6'
                                                *   '<S256>/Gain2'
                                                *   '<S256>/Saturation'
                                                *   '<S257>/Integrator'
                                                *   '<S42>/Dead Zone'
                                                *   '<S42>/Gain'
                                                *   '<S61>/Dead Zone'
                                                *   '<S61>/Gain'
                                                *   '<S75>/Dead Zone'
                                                *   '<S75>/Gain'
                                                *   '<S88>/Dead Zone'
                                                *   '<S88>/Gain'
                                                *   '<S101>/Dead Zone'
                                                *   '<S101>/Gain'
                                                *   '<S102>/Dead Zone'
                                                *   '<S102>/Gain'
                                                *   '<S125>/Dead Zone'
                                                *   '<S125>/Gain'
                                                *   '<S163>/Saturation1'
                                                *   '<S173>/Saturation1'
                                                *   '<S217>/Dead Zone'
                                                *   '<S217>/Gain'
                                                *   '<S229>/Dead Zone'
                                                *   '<S229>/Gain'
                                                *   '<S241>/Dead Zone'
                                                *   '<S241>/Gain'
                                                *   '<S242>/Dead Zone'
                                                *   '<S242>/Gain'
                                                *   '<S277>/Saturation1'
                                                *   '<S287>/Saturation1'
                                                *   '<S166>/Gain2'
                                                *   '<S167>/Gain1'
                                                *   '<S176>/Gain2'
                                                *   '<S177>/Gain6'
                                                *   '<S280>/Gain2'
                                                *   '<S281>/Gain1'
                                                *   '<S290>/Gain2'
                                                *   '<S291>/Gain6'
                                                *   '<S169>/Dead Zone'
                                                *   '<S169>/Gain'
                                                *   '<S181>/Dead Zone'
                                                *   '<S181>/Gain'
                                                *   '<S182>/Dead Zone'
                                                *   '<S182>/Gain'
                                                *   '<S283>/Dead Zone'
                                                *   '<S283>/Gain'
                                                *   '<S295>/Dead Zone'
                                                *   '<S295>/Gain'
                                                *   '<S296>/Dead Zone'
                                                *   '<S296>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S7>/Constant1'
                                                 *   '<S20>/Constant'
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
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S267>/Data Type Duplicate' : Unused code path elimination
 * Block '<S268>/Data Type Duplicate' : Unused code path elimination
 * Block '<S310>/Data Type Duplicate' : Unused code path elimination
 * Block '<S311>/Data Type Duplicate' : Unused code path elimination
 * Block '<S307>/Data Type Duplicate' : Unused code path elimination
 * Block '<S308>/Data Type Duplicate' : Unused code path elimination
 * Block '<S314>/Data Type Duplicate' : Unused code path elimination
 * Block '<S342>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/Reshape' : Reshape block reduction
 * Block '<S135>/Reshape' : Reshape block reduction
 * Block '<S135>/Reshape1' : Reshape block reduction
 * Block '<S135>/Reshape2' : Reshape block reduction
 * Block '<S204>/Reshape' : Reshape block reduction
 * Block '<S271>/Reshape' : Reshape block reduction
 * Block '<S253>/Reshape' : Reshape block reduction
 * Block '<S253>/Reshape1' : Reshape block reduction
 * Block '<S253>/Reshape2' : Reshape block reduction
 * Block '<S323>/Reshape' : Reshape block reduction
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S325>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S340>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S3>'   : 'FMS/FMS Input'
 * '<S4>'   : 'FMS/FMS State Machine'
 * '<S5>'   : 'FMS/Mode Degrade'
 * '<S6>'   : 'FMS/Onground Check'
 * '<S7>'   : 'FMS/Command Process/Check Valid'
 * '<S8>'   : 'FMS/Command Process/Command Routing'
 * '<S9>'   : 'FMS/Command Process/Mode Routing'
 * '<S10>'  : 'FMS/Command Process/Check Valid/Compare To Constant1'
 * '<S11>'  : 'FMS/Command Process/Check Valid/Detect Change1'
 * '<S12>'  : 'FMS/Command Process/Command Routing/Detect Change3'
 * '<S13>'  : 'FMS/Command Process/Command Routing/Detect Change4'
 * '<S14>'  : 'FMS/Command Process/Mode Routing/Compare To Zero'
 * '<S15>'  : 'FMS/Command Process/Mode Routing/Compare To Zero1'
 * '<S16>'  : 'FMS/Command Process/Mode Routing/Detect Change'
 * '<S17>'  : 'FMS/FMS Commander/Arm'
 * '<S18>'  : 'FMS/FMS Commander/Disarm'
 * '<S19>'  : 'FMS/FMS Commander/Standby'
 * '<S20>'  : 'FMS/FMS Commander/timestamp'
 * '<S21>'  : 'FMS/FMS Commander/Arm/Assist'
 * '<S22>'  : 'FMS/FMS Commander/Arm/Auto'
 * '<S23>'  : 'FMS/FMS Commander/Arm/Manual'
 * '<S24>'  : 'FMS/FMS Commander/Arm/SubMode'
 * '<S25>'  : 'FMS/FMS Commander/Arm/Unknown'
 * '<S26>'  : 'FMS/FMS Commander/Arm/Assist/Acro'
 * '<S27>'  : 'FMS/FMS Commander/Arm/Assist/Altitude'
 * '<S28>'  : 'FMS/FMS Commander/Arm/Assist/Position'
 * '<S29>'  : 'FMS/FMS Commander/Arm/Assist/Stabilize'
 * '<S30>'  : 'FMS/FMS Commander/Arm/Assist/Unknown'
 * '<S31>'  : 'FMS/FMS Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S32>'  : 'FMS/FMS Commander/Arm/Assist/Acro/Throttle Command'
 * '<S33>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S34>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S35>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command'
 * '<S36>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S37>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S38>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S39>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S40>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S41>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S42>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S43>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S44>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S45>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S46>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S47>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S48>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S49>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S50>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S51>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S52>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S53>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S54>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S55>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S56>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S57>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S58>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S59>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S60>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S61>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S62>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S63>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S64>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S65>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S66>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command'
 * '<S67>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command'
 * '<S68>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command'
 * '<S69>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S70>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S71>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S72>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S73>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S74>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S75>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S76>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S77>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S78>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S79>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S80>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S81>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S82>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S83>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S84>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S85>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S86>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S87>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S88>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S89>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S90>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S91>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S92>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S93>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S94>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S95>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S96>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S97>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S98>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S99>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S100>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S101>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S102>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S103>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S104>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S105>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S106>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S107>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S108>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S109>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S110>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S111>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S112>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S113>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S114>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S115>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S116>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S117>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S118>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S119>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S120>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S121>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S122>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S123>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S124>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S125>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S126>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S127>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S128>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S129>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S130>' : 'FMS/FMS Commander/Arm/Auto/Mission'
 * '<S131>' : 'FMS/FMS Commander/Arm/Auto/Offboard'
 * '<S132>' : 'FMS/FMS Commander/Arm/Auto/Unknown'
 * '<S133>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander'
 * '<S134>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander'
 * '<S135>' : 'FMS/FMS Commander/Arm/Auto/Mission/Way Points'
 * '<S136>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control'
 * '<S137>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Included Angle'
 * '<S138>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/Heading Control'
 * '<S139>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/TD'
 * '<S140>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/psi_saturation'
 * '<S141>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/psi_saturation1'
 * '<S142>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S143>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S144>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S145>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/TD/fhan '
 * '<S146>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S147>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S148>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Included Angle/2D Cross Product'
 * '<S149>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Included Angle/Vector Normalize'
 * '<S150>' : 'FMS/FMS Commander/Arm/Auto/Mission/Heading Commander/Included Angle/Vector Normalize1'
 * '<S151>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Altitude Control'
 * '<S152>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Cruise Speed '
 * '<S153>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position'
 * '<S154>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/L1 Reference WP'
 * '<S155>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration'
 * '<S156>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration To Speed'
 * '<S157>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Altitude Control/Target Height'
 * '<S158>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S159>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S160>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S161>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold'
 * '<S162>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold'
 * '<S163>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S164>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S165>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S166>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S167>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S168>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S169>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S170>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S171>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S172>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S173>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S174>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S175>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S176>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S177>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S178>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S179>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S180>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S181>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S182>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S183>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S184>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S185>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S186>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S187>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S188>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S189>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S190>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S191>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S192>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S193>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S194>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S195>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S196>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S197>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S198>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S199>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S200>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S201>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S202>' : 'FMS/FMS Commander/Arm/Auto/Mission/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S203>' : 'FMS/FMS Commander/Arm/SubMode/Hold'
 * '<S204>' : 'FMS/FMS Commander/Arm/SubMode/Land'
 * '<S205>' : 'FMS/FMS Commander/Arm/SubMode/Return'
 * '<S206>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff'
 * '<S207>' : 'FMS/FMS Commander/Arm/SubMode/Unknown'
 * '<S208>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S209>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S210>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold'
 * '<S211>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S212>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S213>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S214>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S215>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S216>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S217>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S218>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S219>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S220>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S221>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S222>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S223>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S224>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S225>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S226>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S227>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S228>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S229>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S230>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S231>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S232>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S233>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S234>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S235>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S236>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S237>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S238>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S239>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S240>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S241>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S242>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S243>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S244>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S245>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S246>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command'
 * '<S247>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S248>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S249>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S250>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S251>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander'
 * '<S252>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S253>' : 'FMS/FMS Commander/Arm/SubMode/Return/Way Points'
 * '<S254>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S255>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S256>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S257>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S258>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S259>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S260>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S261>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S262>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S263>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S264>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S265>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S266>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S267>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S268>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S269>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S270>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S271>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S272>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S273>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S274>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S275>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S276>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S277>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S278>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S279>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S280>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S281>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S282>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S283>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S284>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S285>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S286>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S287>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S288>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S289>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S290>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S291>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S292>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S293>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S294>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S295>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S296>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S297>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S298>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S299>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S300>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S301>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S302>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S303>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S304>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S305>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S306>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S307>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S308>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S309>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S310>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S311>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S312>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S313>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S314>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S315>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S316>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S317>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S318>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S319>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S320>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S321>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S322>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S323>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S324>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S325>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S326>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S327>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S328>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S329>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S330>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S331>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S332>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S333>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S334>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S335>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S336>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S337>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S338>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S339>' : 'FMS/Onground Check/Compare To Constant'
 * '<S340>' : 'FMS/Onground Check/First Order LPF'
 * '<S341>' : 'FMS/Onground Check/First Order LPF2'
 * '<S342>' : 'FMS/Onground Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
