/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1129
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec 23 16:25:01 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FMS_h_
#define RTW_HEADER_FMS_h_
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

/* Block states (default storage) for system '<S203>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S206>/Delay' */
  uint8_T icLoad;                      /* '<S206>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S203>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S210>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S210>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S204>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S204>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S204>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S204>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S213>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S216>/Delay' */
  uint8_T icLoad;                      /* '<S216>/Delay' */
} DW_HoldControl_FMS_l_T;

/* Block states (default storage) for system '<S213>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S223>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S223>/Integrator' */
} DW_MoveControl_FMS_d_T;

/* Block states (default storage) for system '<S214>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S214>/Motion State' */
  uint8_T is_active_c2_FMS;            /* '<S214>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S214>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S149>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S152>/Delay' */
  uint8_T icLoad;                      /* '<S152>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S149>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S158>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S158>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S116>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S116>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S116>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S116>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S35>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S35>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S35>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S35>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  Cmd_In_Bus Cmd_In;                   /* '<Root>/FMS State Machine' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real32_T Merge[2];                   /* '<S91>/Merge' */
  real32_T Merge_k;                    /* '<S67>/Merge' */
  real32_T Merge_d;                    /* '<S78>/Merge' */
  real32_T Merge_l;                    /* '<S34>/Merge' */
  real32_T Merge_m;                    /* '<S51>/Merge' */
  real32_T Merge_j;                    /* '<S115>/Merge' */
  real32_T Merge_o[2];                 /* '<S161>/Merge' */
  real32_T Merge_e;                    /* '<S139>/Merge' */
  real32_T Merge_n;                    /* '<S149>/Merge' */
  real32_T Merge_mv[2];                /* '<S213>/Merge' */
  real32_T Merge_mu;                   /* '<S203>/Merge' */
  VehicleMode VehicleMode_e;           /* '<Root>/FMS State Machine' */
  PilotMode DataTypeConversion1;       /* '<S1>/Data Type Conversion1' */
  PilotMode safe_mode;                 /* '<Root>/Mode Degrade' */
  FMS_Cmd Switch;                      /* '<S7>/Switch' */
  boolean_T LogicalOperator1;          /* '<S6>/Logical Operator1' */
  boolean_T Compare;                   /* '<S248>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_p[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_o;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S250>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S251>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S47>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S47>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S48>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S48>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S111>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S111>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S112>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S112>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S181>/Delay' */
  real32_T l1_heading;                 /* '<S239>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S185>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S185>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S9>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_m;       /* '<S10>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S18>/Discrete-Time Integrator' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_d;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_l;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_m;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T M_qId;                       /* '<Root>/FMS State Machine' */
  FMS_Cmd M;                           /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_prev;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_start;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgData;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgReservedData;           /* '<Root>/FMS State Machine' */
  PilotMode mode_prev;                 /* '<Root>/FMS State Machine' */
  PilotMode mode_start;                /* '<Root>/FMS State Machine' */
  uint16_T temporalCounter_i1;         /* '<Root>/FMS State Machine' */
  uint16_T temporalCounter_i1_i;       /* '<S92>/Motion State' */
  int8_T Delay_DSTATE_g;               /* '<S7>/Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S2>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S15>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S19>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S91>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S67>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S78>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S34>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S51>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S115>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S161>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S139>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S149>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S213>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S203>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S250>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S251>/Discrete-Time Integrator5' */
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
  uint8_T is_Assist;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Manual;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Combo_Stick;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Combo_Stick;       /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S92>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S92>/Motion State' */
  uint8_T is_active_c15_FMS;           /* '<S150>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S150>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S150>/Motion State' */
  uint8_T icLoad;                      /* '<S181>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S185>/Integrator1' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_i;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_j;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_l;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  DW_MoveControl_FMS_d_T MoveControl_k1;/* '<S91>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_a;/* '<S91>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S79>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_m;/* '<S78>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S78>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S68>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_be; /* '<S67>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S67>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S52>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_c;/* '<S51>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S51>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S35>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_l;  /* '<S34>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S34>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S116>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S115>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S115>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S162>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_i;/* '<S161>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_f;/* '<S161>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S149>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_kq;/* '<S149>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S140>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S139>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S139>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S214>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_o;/* '<S213>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_k;/* '<S213>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S204>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S203>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S203>/Hold Control' */
} DW_FMS_T;

/* Invariant block signals for system '<S2>/Disarm' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S16>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S16>/Data Type Conversion1' */
} ConstB_Disarm_FMS_T;

/* Invariant block signals for system '<S203>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S211>/Square' */
  const real32_T d;                    /* '<S211>/Multiply' */
  const real32_T Gain4;                /* '<S211>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S213>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S220>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S213>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S224>/Square' */
  const real32_T d;                    /* '<S224>/Multiply' */
  const real32_T Gain4;                /* '<S224>/Gain4' */
} ConstB_MoveControl_FMS_k_T;

/* Invariant block signals for system '<S149>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S159>/Square' */
  const real32_T d;                    /* '<S159>/Multiply' */
  const real32_T Gain4;                /* '<S159>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Square;               /* '<S49>/Square' */
  const real32_T d;                    /* '<S49>/Multiply' */
  const real32_T Gain4;                /* '<S49>/Gain4' */
  const real32_T Square_d;             /* '<S50>/Square' */
  const real32_T d_c;                  /* '<S50>/Multiply' */
  const real32_T Gain4_m;              /* '<S50>/Gain4' */
  const real32_T Square_m;             /* '<S113>/Square' */
  const real32_T d_d;                  /* '<S113>/Multiply' */
  const real32_T Gain4_n;              /* '<S113>/Gain4' */
  const real32_T Square_n;             /* '<S114>/Square' */
  const real32_T d_o;                  /* '<S114>/Multiply' */
  const real32_T Gain4_n3;             /* '<S114>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S242>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S193>/Math Function' */
  const real32_T SumofElements;        /* '<S193>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S193>/Math Function1' */
  const real32_T Product[2];           /* '<S193>/Product' */
  const real32_T Switch[3];            /* '<S193>/Switch' */
  const real32_T Divide[2];            /* '<S193>/Divide' */
  const real32_T Square_k;             /* '<S190>/Square' */
  const real32_T d_l;                  /* '<S190>/Multiply' */
  const real32_T Gain4_np;             /* '<S190>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S178>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S246>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S21>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S21>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S26>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S26>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S26>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S25>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S25>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S25>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S27>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S24>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S24>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S24>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S128>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S128>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_a;  /* '<S129>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S129>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S131>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S131>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S131>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S133>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S133>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S133>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S132>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S132>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S132>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S134>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S134>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S134>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S17>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S17>/Data Type Conversion1' */
  ConstB_Disarm_FMS_T Unknown;         /* '<S15>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_i;       /* '<S19>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_k1;/* '<S91>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_a;/* '<S91>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_m;/* '<S78>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_be;/* '<S67>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_c;/* '<S51>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_l;/* '<S34>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S115>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_d;       /* '<S20>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_g;       /* '<S22>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_i;/* '<S161>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S161>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S149>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S139>/Move Control' */
  ConstB_MoveControl_FMS_k_T MoveControl_o;/* '<S213>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_k;/* '<S213>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S203>/Move Control' */
  ConstB_Disarm_FMS_T Disarm;          /* '<S2>/Disarm' */
} ConstB_FMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Pilot_Cmd_Bus Pilot_Cmd;             /* '<Root>/Pilot_Cmd' */
  Auto_Cmd_Bus Auto_Cmd;               /* '<Root>/Auto_Cmd' */
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
extern struct_5vUBwe4VfGkNikzOx8lYKF FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<S32>/Gain'
                                                *   '<S32>/Gain1'
                                                *   '<S106>/Gain'
                                                *   '<S106>/Gain1'
                                                *   '<S174>/Saturation1'
                                                *   '<S243>/Gain2'
                                                *   '<S243>/Saturation1'
                                                *   '<S34>/Saturation1'
                                                *   '<S45>/Dead Zone'
                                                *   '<S45>/Gain'
                                                *   '<S46>/Dead Zone'
                                                *   '<S46>/Gain'
                                                *   '<S51>/Saturation'
                                                *   '<S67>/Saturation1'
                                                *   '<S78>/Saturation'
                                                *   '<S91>/Saturation1'
                                                *   '<S109>/Dead Zone'
                                                *   '<S109>/Gain'
                                                *   '<S110>/Dead Zone'
                                                *   '<S110>/Gain'
                                                *   '<S115>/Saturation'
                                                *   '<S139>/Saturation1'
                                                *   '<S149>/Saturation'
                                                *   '<S161>/Saturation1'
                                                *   '<S175>/Gain2'
                                                *   '<S37>/Gain2'
                                                *   '<S38>/Gain1'
                                                *   '<S43>/Constant'
                                                *   '<S54>/Gain2'
                                                *   '<S55>/Gain1'
                                                *   '<S62>/Constant'
                                                *   '<S70>/Gain2'
                                                *   '<S71>/Gain1'
                                                *   '<S76>/Constant'
                                                *   '<S81>/Gain2'
                                                *   '<S82>/Gain1'
                                                *   '<S89>/Constant'
                                                *   '<S94>/Gain2'
                                                *   '<S95>/Gain6'
                                                *   '<S103>/Constant'
                                                *   '<S104>/Constant'
                                                *   '<S118>/Gain2'
                                                *   '<S119>/Gain1'
                                                *   '<S126>/Constant'
                                                *   '<S142>/Gain2'
                                                *   '<S143>/Gain1'
                                                *   '<S152>/Gain2'
                                                *   '<S153>/Gain1'
                                                *   '<S164>/Gain2'
                                                *   '<S165>/Gain6'
                                                *   '<S184>/Gain2'
                                                *   '<S184>/Saturation'
                                                *   '<S185>/Integrator'
                                                *   '<S40>/Dead Zone'
                                                *   '<S40>/Gain'
                                                *   '<S59>/Dead Zone'
                                                *   '<S59>/Gain'
                                                *   '<S73>/Dead Zone'
                                                *   '<S73>/Gain'
                                                *   '<S86>/Dead Zone'
                                                *   '<S86>/Gain'
                                                *   '<S99>/Dead Zone'
                                                *   '<S99>/Gain'
                                                *   '<S100>/Dead Zone'
                                                *   '<S100>/Gain'
                                                *   '<S123>/Dead Zone'
                                                *   '<S123>/Gain'
                                                *   '<S145>/Dead Zone'
                                                *   '<S145>/Gain'
                                                *   '<S157>/Dead Zone'
                                                *   '<S157>/Gain'
                                                *   '<S169>/Dead Zone'
                                                *   '<S169>/Gain'
                                                *   '<S170>/Dead Zone'
                                                *   '<S170>/Gain'
                                                *   '<S203>/Saturation1'
                                                *   '<S213>/Saturation1'
                                                *   '<S206>/Gain2'
                                                *   '<S207>/Gain1'
                                                *   '<S216>/Gain2'
                                                *   '<S217>/Gain6'
                                                *   '<S209>/Dead Zone'
                                                *   '<S209>/Gain'
                                                *   '<S221>/Dead Zone'
                                                *   '<S221>/Gain'
                                                *   '<S222>/Dead Zone'
                                                *   '<S222>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S18>/Constant'
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
 * Block '<S11>/Compare' : Unused code path elimination
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S12>/Compare' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S8>/Constant' : Unused code path elimination
 * Block '<S8>/Constant1' : Unused code path elimination
 * Block '<S13>/Delay Input1' : Unused code path elimination
 * Block '<S13>/FixPt Relational Operator' : Unused code path elimination
 * Block '<S14>/Delay Input1' : Unused code path elimination
 * Block '<S14>/FixPt Relational Operator' : Unused code path elimination
 * Block '<S8>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S8>/Discrete-Time Integrator1' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S236>/Data Type Duplicate' : Unused code path elimination
 * Block '<S237>/Data Type Duplicate' : Unused code path elimination
 * Block '<S233>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Reshape' : Reshape block reduction
 * Block '<S197>/Reshape' : Reshape block reduction
 * Block '<S181>/Reshape' : Reshape block reduction
 * Block '<S181>/Reshape1' : Reshape block reduction
 * Block '<S181>/Reshape2' : Reshape block reduction
 * Block '<S243>/Reshape' : Reshape block reduction
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S250>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'FMS/Command Process/Command Routing'
 * '<S8>'   : 'FMS/Command Process/Subsystem'
 * '<S9>'   : 'FMS/Command Process/Command Routing/Detect Change1'
 * '<S10>'  : 'FMS/Command Process/Command Routing/Detect Change2'
 * '<S11>'  : 'FMS/Command Process/Subsystem/Compare To Constant1'
 * '<S12>'  : 'FMS/Command Process/Subsystem/Compare To Constant4'
 * '<S13>'  : 'FMS/Command Process/Subsystem/Detect Change'
 * '<S14>'  : 'FMS/Command Process/Subsystem/Detect Change1'
 * '<S15>'  : 'FMS/FMS Commander/Arm'
 * '<S16>'  : 'FMS/FMS Commander/Disarm'
 * '<S17>'  : 'FMS/FMS Commander/Standby'
 * '<S18>'  : 'FMS/FMS Commander/timestamp'
 * '<S19>'  : 'FMS/FMS Commander/Arm/Assist'
 * '<S20>'  : 'FMS/FMS Commander/Arm/Auto'
 * '<S21>'  : 'FMS/FMS Commander/Arm/Manual'
 * '<S22>'  : 'FMS/FMS Commander/Arm/SubMode'
 * '<S23>'  : 'FMS/FMS Commander/Arm/Unknown'
 * '<S24>'  : 'FMS/FMS Commander/Arm/Assist/Acro'
 * '<S25>'  : 'FMS/FMS Commander/Arm/Assist/Altitude'
 * '<S26>'  : 'FMS/FMS Commander/Arm/Assist/Position'
 * '<S27>'  : 'FMS/FMS Commander/Arm/Assist/Stabilize'
 * '<S28>'  : 'FMS/FMS Commander/Arm/Assist/Unknown'
 * '<S29>'  : 'FMS/FMS Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S30>'  : 'FMS/FMS Commander/Arm/Assist/Acro/Throttle Command'
 * '<S31>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S32>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S33>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command'
 * '<S34>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S35>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S36>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S37>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S38>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S39>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S40>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S41>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S42>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S43>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S44>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S45>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S46>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S47>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S48>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S49>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S50>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S51>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S52>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S53>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S54>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S55>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S56>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S57>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S58>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S59>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S60>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S61>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S62>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S63>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S64>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command'
 * '<S65>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command'
 * '<S66>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command'
 * '<S67>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S68>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S69>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S70>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S71>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S72>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S73>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S74>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S75>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S76>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S77>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S78>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S79>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S80>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S81>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S82>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S83>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S84>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S85>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S86>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S87>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S88>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S89>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S90>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S91>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S92>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S93>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S94>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S95>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S96>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S97>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S98>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S99>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S100>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S101>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S102>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S103>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S104>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S105>' : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S106>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S107>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S108>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S109>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S110>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S111>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S112>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S113>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S114>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S115>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S116>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S117>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S118>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S119>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S120>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S121>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S122>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S123>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S124>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S125>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S126>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S127>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S128>' : 'FMS/FMS Commander/Arm/Auto/Mission'
 * '<S129>' : 'FMS/FMS Commander/Arm/Auto/Offboard'
 * '<S130>' : 'FMS/FMS Commander/Arm/Auto/Unknown'
 * '<S131>' : 'FMS/FMS Commander/Arm/SubMode/Hold'
 * '<S132>' : 'FMS/FMS Commander/Arm/SubMode/Land'
 * '<S133>' : 'FMS/FMS Commander/Arm/SubMode/Return'
 * '<S134>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff'
 * '<S135>' : 'FMS/FMS Commander/Arm/SubMode/Unknown'
 * '<S136>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S137>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S138>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold'
 * '<S139>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S140>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S141>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S142>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S143>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S144>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S145>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S146>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S147>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S148>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S149>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S150>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S151>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S152>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S153>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S154>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S155>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S156>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S157>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S158>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S159>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S160>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S161>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S162>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S163>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S164>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S165>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S166>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S167>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S168>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S169>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S170>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S171>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S172>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S173>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S174>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command'
 * '<S175>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S176>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S177>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S178>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S179>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander'
 * '<S180>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S181>' : 'FMS/FMS Commander/Arm/SubMode/Return/Way Points'
 * '<S182>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S183>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S184>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S185>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S186>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_err_saturation'
 * '<S187>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S188>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_err_saturation'
 * '<S189>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_err_saturation/Compare To Constant'
 * '<S190>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S191>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_err_saturation/Compare To Constant'
 * '<S192>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S193>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S194>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S195>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S196>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S197>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S198>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S199>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S200>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S201>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S202>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S203>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S204>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S205>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S206>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S207>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S208>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S209>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S210>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S211>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S212>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S213>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S214>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S215>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S216>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S217>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S218>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S219>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S220>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S221>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S222>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S223>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S224>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S225>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S226>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S227>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S228>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S229>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S230>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S231>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S232>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S233>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S234>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S235>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S236>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S237>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S238>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S239>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S240>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S241>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S242>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S243>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position'
 * '<S244>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Bus_Selection'
 * '<S245>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Psi To DCM'
 * '<S246>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Psi To DCM/Rotation Matrix Z'
 * '<S247>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S248>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S249>' : 'FMS/Onground Check/Compare To Constant'
 * '<S250>' : 'FMS/Onground Check/First Order LPF'
 * '<S251>' : 'FMS/Onground Check/First Order LPF2'
 * '<S252>' : 'FMS/Onground Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
