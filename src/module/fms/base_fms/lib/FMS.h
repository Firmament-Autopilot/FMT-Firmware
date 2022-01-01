/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1213
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan  1 10:44:14 2022
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

/* Block states (default storage) for system '<S207>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S210>/Delay' */
  uint8_T icLoad;                      /* '<S210>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S207>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S214>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S214>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S208>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S208>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S208>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S208>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S217>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S220>/Delay' */
  uint8_T icLoad;                      /* '<S220>/Delay' */
} DW_HoldControl_FMS_l_T;

/* Block states (default storage) for system '<S217>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S227>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S227>/Integrator' */
} DW_MoveControl_FMS_d_T;

/* Block states (default storage) for system '<S218>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S218>/Motion State' */
  uint8_T is_active_c2_FMS;            /* '<S218>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S218>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S151>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S154>/Delay' */
  uint8_T icLoad;                      /* '<S154>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S151>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S160>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S160>/Integrator' */
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
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  Cmd_In_Bus Cmd_In;                   /* '<Root>/FMS State Machine' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real32_T Merge[2];                   /* '<S93>/Merge' */
  real32_T Merge_k;                    /* '<S69>/Merge' */
  real32_T Merge_d;                    /* '<S80>/Merge' */
  real32_T Merge_l;                    /* '<S36>/Merge' */
  real32_T Merge_m;                    /* '<S53>/Merge' */
  real32_T Merge_j;                    /* '<S117>/Merge' */
  real32_T Merge_o[2];                 /* '<S163>/Merge' */
  real32_T Merge_e;                    /* '<S141>/Merge' */
  real32_T Merge_n;                    /* '<S151>/Merge' */
  real32_T Merge_mv[2];                /* '<S217>/Merge' */
  real32_T Merge_mu;                   /* '<S207>/Merge' */
  VehicleState VehicleState_f;         /* '<Root>/FMS State Machine' */
  PilotMode safe_mode;                 /* '<Root>/Mode Degrade' */
  FMS_Cmd fms_cmd;                     /* '<S8>/Switch' */
  boolean_T LogicalOperator1;          /* '<S6>/Logical Operator1' */
  boolean_T Compare;                   /* '<S252>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_p[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_o;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S254>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S255>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S49>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S49>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S50>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S50>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S113>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S113>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S114>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S114>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S183>/Delay' */
  real32_T l1_heading;                 /* '<S243>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_a;             /* '<S184>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S187>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S187>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S11>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S7>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S16>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S12>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_m;       /* '<S13>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S20>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_c;            /* '<S9>/Delay' */
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
  uint16_T temporalCounter_i1_i;       /* '<S94>/Motion State' */
  int8_T Delay_DSTATE_g;               /* '<S8>/Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S2>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S17>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S21>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S93>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S69>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S80>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S36>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S53>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S117>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S24>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S163>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S141>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S151>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S217>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S207>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S254>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S255>/Discrete-Time Integrator5' */
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
  uint8_T is_active_c16_FMS;           /* '<S94>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S94>/Motion State' */
  uint8_T is_active_c15_FMS;           /* '<S152>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S152>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S152>/Motion State' */
  uint8_T icLoad;                      /* '<S183>/Delay' */
  uint8_T icLoad_j;                    /* '<S184>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S187>/Integrator1' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_i;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_j;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_l;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  DW_MoveControl_FMS_d_T MoveControl_k1;/* '<S93>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_a;/* '<S93>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_j;/* '<S81>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_m;/* '<S80>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S80>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_i;/* '<S70>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_be; /* '<S69>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S69>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S54>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_c;/* '<S53>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S53>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S37>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_l;  /* '<S36>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S36>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S118>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S117>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S117>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S164>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_i;/* '<S163>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_f;/* '<S163>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S151>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_kq;/* '<S151>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S142>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S141>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S141>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S218>/Motion State' */
  DW_MoveControl_FMS_d_T MoveControl_o;/* '<S217>/Move Control' */
  DW_HoldControl_FMS_l_T HoldControl_k;/* '<S217>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S208>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S207>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S207>/Hold Control' */
} DW_FMS_T;

/* Invariant block signals for system '<S2>/Disarm' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S18>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S18>/Data Type Conversion1' */
} ConstB_Disarm_FMS_T;

/* Invariant block signals for system '<S207>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S215>/Square' */
  const real32_T d;                    /* '<S215>/Multiply' */
  const real32_T Gain4;                /* '<S215>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S217>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S224>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S217>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S228>/Square' */
  const real32_T d;                    /* '<S228>/Multiply' */
  const real32_T Gain4;                /* '<S228>/Gain4' */
} ConstB_MoveControl_FMS_k_T;

/* Invariant block signals for system '<S151>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S161>/Square' */
  const real32_T d;                    /* '<S161>/Multiply' */
  const real32_T Gain4;                /* '<S161>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

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
  const real32_T VectorConcatenate3[3];/* '<S246>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S197>/Math Function' */
  const real32_T SumofElements;        /* '<S197>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S197>/Math Function1' */
  const real32_T Product[2];           /* '<S197>/Product' */
  const real32_T Switch[3];            /* '<S197>/Switch' */
  const real32_T Divide[2];            /* '<S197>/Divide' */
  const real32_T Square_k;             /* '<S193>/Square' */
  const real32_T d_l;                  /* '<S193>/Multiply' */
  const real32_T Gain4_np;             /* '<S193>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S180>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S250>/Vector Concatenate3' */
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
  const uint8_T DataTypeConversion_a;  /* '<S131>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S131>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S133>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S133>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S133>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S135>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S135>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S135>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S134>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S134>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S134>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S136>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S136>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S136>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S19>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S19>/Data Type Conversion1' */
  ConstB_Disarm_FMS_T Unknown;         /* '<S17>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_i;       /* '<S21>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_k1;/* '<S93>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_a;/* '<S93>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_m;/* '<S80>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_be;/* '<S69>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_c;/* '<S53>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_l;/* '<S36>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S117>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_d;       /* '<S22>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_g;       /* '<S24>/Unknown' */
  ConstB_MoveControl_FMS_k_T MoveControl_i;/* '<S163>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S163>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S151>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S141>/Move Control' */
  ConstB_MoveControl_FMS_k_T MoveControl_o;/* '<S217>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_k;/* '<S217>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S207>/Move Control' */
  ConstB_Disarm_FMS_T Disarm;          /* '<S2>/Disarm' */
} ConstB_FMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Pilot_Cmd_Bus Pilot_Cmd;             /* '<Root>/Pilot_Cmd' */
  Auto_Cmd_Bus Auto_Cmd;               /* '<Root>/Auto_Cmd' */
  GCS_Cmd_Bus GCS_Cmd;                 /* '<Root>/GCS_Cmd' */
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
                                                *   '<S34>/Gain'
                                                *   '<S34>/Gain1'
                                                *   '<S108>/Gain'
                                                *   '<S108>/Gain1'
                                                *   '<S176>/Saturation1'
                                                *   '<S247>/Gain2'
                                                *   '<S247>/Saturation1'
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
                                                *   '<S141>/Saturation1'
                                                *   '<S151>/Saturation'
                                                *   '<S163>/Saturation1'
                                                *   '<S177>/Gain2'
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
                                                *   '<S144>/Gain2'
                                                *   '<S145>/Gain1'
                                                *   '<S154>/Gain2'
                                                *   '<S155>/Gain1'
                                                *   '<S166>/Gain2'
                                                *   '<S167>/Gain6'
                                                *   '<S186>/Gain2'
                                                *   '<S186>/Saturation'
                                                *   '<S187>/Integrator'
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
                                                *   '<S147>/Dead Zone'
                                                *   '<S147>/Gain'
                                                *   '<S159>/Dead Zone'
                                                *   '<S159>/Gain'
                                                *   '<S171>/Dead Zone'
                                                *   '<S171>/Gain'
                                                *   '<S172>/Dead Zone'
                                                *   '<S172>/Gain'
                                                *   '<S207>/Saturation1'
                                                *   '<S217>/Saturation1'
                                                *   '<S210>/Gain2'
                                                *   '<S211>/Gain1'
                                                *   '<S220>/Gain2'
                                                *   '<S221>/Gain6'
                                                *   '<S213>/Dead Zone'
                                                *   '<S213>/Gain'
                                                *   '<S225>/Dead Zone'
                                                *   '<S225>/Gain'
                                                *   '<S226>/Dead Zone'
                                                *   '<S226>/Gain'
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
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate' : Unused code path elimination
 * Block '<S237>/Data Type Duplicate' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate' : Unused code path elimination
 * Block '<S256>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Reshape' : Reshape block reduction
 * Block '<S201>/Reshape' : Reshape block reduction
 * Block '<S183>/Reshape' : Reshape block reduction
 * Block '<S183>/Reshape1' : Reshape block reduction
 * Block '<S183>/Reshape2' : Reshape block reduction
 * Block '<S247>/Reshape' : Reshape block reduction
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S254>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S12>'  : 'FMS/Command Process/Command Routing/Detect Change1'
 * '<S13>'  : 'FMS/Command Process/Command Routing/Detect Change2'
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
 * '<S133>' : 'FMS/FMS Commander/Arm/SubMode/Hold'
 * '<S134>' : 'FMS/FMS Commander/Arm/SubMode/Land'
 * '<S135>' : 'FMS/FMS Commander/Arm/SubMode/Return'
 * '<S136>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff'
 * '<S137>' : 'FMS/FMS Commander/Arm/SubMode/Unknown'
 * '<S138>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S139>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S140>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold'
 * '<S141>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S142>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S143>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S144>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S145>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S146>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S147>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S148>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S149>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S150>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S151>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S152>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S153>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S154>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S155>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S156>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S157>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S158>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S159>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S160>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S161>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S162>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S163>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S164>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S165>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S166>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S167>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S168>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S169>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S170>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S171>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S172>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S173>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S174>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S175>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S176>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command'
 * '<S177>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S178>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S179>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S180>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S181>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander'
 * '<S182>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S183>' : 'FMS/FMS Commander/Arm/SubMode/Return/Way Points'
 * '<S184>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S185>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S186>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S187>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S188>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S189>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S190>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S191>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S192>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S193>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S194>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S195>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S196>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S197>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S198>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S199>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S200>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S201>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S202>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S203>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S204>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S205>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S206>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S207>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S208>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S209>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S210>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S211>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S212>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S213>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S214>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S215>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S216>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S217>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S218>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S219>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S220>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S221>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S222>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S223>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S224>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S225>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S226>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S227>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S228>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S229>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S230>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S231>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S232>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S233>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S234>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S235>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S236>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S237>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S238>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S239>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S240>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S241>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S242>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S243>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S244>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S245>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S246>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S247>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position'
 * '<S248>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Bus_Selection'
 * '<S249>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Psi To DCM'
 * '<S250>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Psi To DCM/Rotation Matrix Z'
 * '<S251>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S252>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S253>' : 'FMS/Onground Check/Compare To Constant'
 * '<S254>' : 'FMS/Onground Check/First Order LPF'
 * '<S255>' : 'FMS/Onground Check/First Order LPF2'
 * '<S256>' : 'FMS/Onground Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
