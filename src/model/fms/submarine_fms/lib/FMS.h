/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1987
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 12:17:03 2024
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

/* Block states (default storage) for system '<S33>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S36>/Delay' */
  uint8_T icLoad;                      /* '<S36>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S34>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S34>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S34>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S34>/Motion Status' */
} DW_MotionStatus_FMS_T;

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
  real32_T DataTypeConversion[3];      /* '<S134>/Data Type Conversion' */
  real32_T Merge;                      /* '<S47>/Merge' */
  real32_T Merge_i;                    /* '<S57>/Merge' */
  real32_T Merge_a;                    /* '<S33>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S6>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T Compare;                   /* '<S146>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission;                 /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_d[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_k;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T Delay_DSTATE;               /* '<S60>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S133>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S9>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S5>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S14>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S11>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S10>/Delay Input1' */
  PilotMode Delay_DSTATE_c;            /* '<S7>/Delay' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_h;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_j;       /* '<S58>/Motion State' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S84>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S15>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S17>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S21>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S57>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_c; /* '<S47>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bg;/* '<S33>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S24>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S58>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S58>/Motion State' */
  uint8_T icLoad;                      /* '<S60>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_c;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  DW_MotionStatus_FMS_T sf_MotionStatus_f;/* '<S48>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S47>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S34>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S33>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S81>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S24>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S110>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S110>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S137>/Sum' */
  const real_T ff;                     /* '<S137>/Multiply3' */
  const real_T Sum4;                   /* '<S137>/Sum4' */
  const real32_T VectorConcatenate3[3];/* '<S64>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S23>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S23>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S27>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_j; /* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S26>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S26>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S26>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_k;  /* '<S28>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_p; /* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_f; /* '<S28>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S85>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S85>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S85>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S82>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S82>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_h;  /* '<S108>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S108>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S108>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S109>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m0;/* '<S109>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S109>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_oj;/* '<S20>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_nz;/* '<S20>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_a0; /* '<S19>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_bg;/* '<S19>/Data Type Conversion1' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S17>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_o;      /* '<S21>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S22>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S24>/Unknown' */
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
extern struct_d9c0tvJ8oGGPXhDK6NoMmH FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S109>/vel'
                                                *   '<S31>/Gain6'
                                                *   '<S32>/Gain6'
                                                *   '<S45>/Gain6'
                                                *   '<S75>/Gain6'
                                                *   '<S76>/Gain6'
                                                *   '<S77>/Gain6'
                                                *   '<S85>/vel'
                                                *   '<S111>/Gain'
                                                *   '<S111>/Saturation1'
                                                *   '<S112>/L1'
                                                *   '<S33>/Saturation1'
                                                *   '<S42>/Dead Zone'
                                                *   '<S42>/Gain'
                                                *   '<S43>/Dead Zone'
                                                *   '<S43>/Gain'
                                                *   '<S47>/Saturation1'
                                                *   '<S56>/Dead Zone'
                                                *   '<S56>/Gain'
                                                *   '<S57>/Saturation1'
                                                *   '<S78>/Dead Zone'
                                                *   '<S78>/Gain'
                                                *   '<S79>/Dead Zone'
                                                *   '<S79>/Gain'
                                                *   '<S80>/Dead Zone'
                                                *   '<S80>/Gain'
                                                *   '<S86>/Gain'
                                                *   '<S86>/Saturation1'
                                                *   '<S87>/L1'
                                                *   '<S116>/AccToRate'
                                                *   '<S36>/Gain2'
                                                *   '<S37>/Gain1'
                                                *   '<S40>/Constant'
                                                *   '<S50>/Gain2'
                                                *   '<S51>/Gain1'
                                                *   '<S54>/Constant'
                                                *   '<S60>/Gain2'
                                                *   '<S61>/Gain6'
                                                *   '<S67>/Constant'
                                                *   '<S91>/AccToRate'
                                                *   '<S39>/Dead Zone'
                                                *   '<S39>/Gain'
                                                *   '<S53>/Dead Zone'
                                                *   '<S53>/Gain'
                                                *   '<S65>/Dead Zone'
                                                *   '<S65>/Gain'
                                                */
extern struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S5>/Constant1'
                                                 *   '<S133>/Constant'
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
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Reshape' : Reshape block reduction
 * Block '<S92>/Reshape' : Reshape block reduction
 * Block '<S92>/Reshape1' : Reshape block reduction
 * Block '<S92>/Reshape2' : Reshape block reduction
 * Block '<S118>/Reshape' : Reshape block reduction
 * Block '<S117>/Reshape' : Reshape block reduction
 * Block '<S117>/Reshape1' : Reshape block reduction
 * Block '<S117>/Reshape2' : Reshape block reduction
 * Block '<S133>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S134>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S1>'   : 'FMS/CommandProcess'
 * '<S2>'   : 'FMS/FMS Commander'
 * '<S3>'   : 'FMS/FMS State Machine'
 * '<S4>'   : 'FMS/SafeMode'
 * '<S5>'   : 'FMS/CommandProcess/Check Valid'
 * '<S6>'   : 'FMS/CommandProcess/Command Routing'
 * '<S7>'   : 'FMS/CommandProcess/Mode Routing'
 * '<S8>'   : 'FMS/CommandProcess/Check Valid/Compare To Constant1'
 * '<S9>'   : 'FMS/CommandProcess/Check Valid/Detect Change1'
 * '<S10>'  : 'FMS/CommandProcess/Command Routing/Detect Change3'
 * '<S11>'  : 'FMS/CommandProcess/Command Routing/Detect Change4'
 * '<S12>'  : 'FMS/CommandProcess/Mode Routing/Compare To Zero'
 * '<S13>'  : 'FMS/CommandProcess/Mode Routing/Compare To Zero1'
 * '<S14>'  : 'FMS/CommandProcess/Mode Routing/Detect Change'
 * '<S15>'  : 'FMS/FMS Commander/Commander'
 * '<S16>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S17>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S18>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S19>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S20>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S21>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S22>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S23>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S24>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S25>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S26>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Speed Command'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone2'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Speed Command/DeadZone2'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone2'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Brake Control'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Move Control'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Bus_Selection'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Psi To DCM'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Move Control/DeadZone'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Compare To Constant1'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Motion State'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/Quaternion Normalize'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_1'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_2'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_3'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command '
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command /DeadZone2'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone2'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command/DeadZone2'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus1'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Way Points'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus1'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Way Points'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S133>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S134>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S135>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S136>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S137>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S138>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S139>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S140>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S141>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S142>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S143>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S144>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S145>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S146>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
