/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1994
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jul 18 16:56:15 2024
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

/* Block states (default storage) for system '<S38>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S41>/Delay' */
  uint8_T icLoad;                      /* '<S41>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S39>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S39>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S39>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S39>/Motion Status' */
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
  real32_T DataTypeConversion[3];      /* '<S152>/Data Type Conversion' */
  real32_T Merge;                      /* '<S52>/Merge' */
  real32_T Merge_i;                    /* '<S62>/Merge' */
  real32_T Merge_a;                    /* '<S38>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S11>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare;                   /* '<S164>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission;                 /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_l[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_e;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T Delay_DSTATE;               /* '<S65>/Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S7>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S151>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S14>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S10>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S19>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S16>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S15>/Delay Input1' */
  PilotMode Delay_DSTATE_c;            /* '<S12>/Delay' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_j;/* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_j;       /* '<S63>/Motion State' */
  uint8_T Delay_DSTATE_k;              /* '<S8>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S89>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S20>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S26>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S62>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_c; /* '<S52>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bg;/* '<S38>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S27>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S29>/Switch Case' */
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
  uint8_T is_Offboard;                 /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S63>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S63>/Motion State' */
  uint8_T icLoad;                      /* '<S65>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  DW_MotionStatus_FMS_T sf_MotionStatus_f;/* '<S53>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S52>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S39>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S38>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S86>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S29>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S128>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S128>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S155>/Sum' */
  const real_T ff;                     /* '<S155>/Multiply3' */
  const real_T Sum4;                   /* '<S155>/Sum4' */
  const real32_T VectorConcatenate3[3];/* '<S69>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S28>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S32>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_j; /* '<S32>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S32>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S31>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S31>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S31>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_k;  /* '<S33>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_p; /* '<S33>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_f; /* '<S33>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S90>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S90>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S90>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S87>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b0;/* '<S87>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_bv;/* '<S87>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_h;  /* '<S126>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S126>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S126>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S127>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m0;/* '<S127>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S127>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_oj;/* '<S25>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_n; /* '<S25>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_a;  /* '<S24>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_bg;/* '<S24>/Data Type Conversion1' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S22>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_o;      /* '<S26>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S27>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S29>/Unknown' */
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
                                                *   '<S127>/vel'
                                                *   '<S36>/Gain6'
                                                *   '<S37>/Gain6'
                                                *   '<S50>/Gain6'
                                                *   '<S80>/Gain6'
                                                *   '<S81>/Gain6'
                                                *   '<S82>/Gain6'
                                                *   '<S90>/vel'
                                                *   '<S129>/Gain'
                                                *   '<S129>/Saturation1'
                                                *   '<S130>/L1'
                                                *   '<S38>/Saturation1'
                                                *   '<S47>/Dead Zone'
                                                *   '<S47>/Gain'
                                                *   '<S48>/Dead Zone'
                                                *   '<S48>/Gain'
                                                *   '<S52>/Saturation1'
                                                *   '<S61>/Dead Zone'
                                                *   '<S61>/Gain'
                                                *   '<S62>/Saturation1'
                                                *   '<S83>/Dead Zone'
                                                *   '<S83>/Gain'
                                                *   '<S84>/Dead Zone'
                                                *   '<S84>/Gain'
                                                *   '<S85>/Dead Zone'
                                                *   '<S85>/Gain'
                                                *   '<S91>/Gain'
                                                *   '<S91>/Saturation1'
                                                *   '<S92>/L1'
                                                *   '<S134>/AccToRate'
                                                *   '<S41>/Gain2'
                                                *   '<S42>/Gain1'
                                                *   '<S45>/Constant'
                                                *   '<S55>/Gain2'
                                                *   '<S56>/Gain1'
                                                *   '<S59>/Constant'
                                                *   '<S65>/Gain2'
                                                *   '<S66>/Gain6'
                                                *   '<S72>/Constant'
                                                *   '<S96>/AccToRate'
                                                *   '<S44>/Dead Zone'
                                                *   '<S44>/Gain'
                                                *   '<S58>/Dead Zone'
                                                *   '<S58>/Gain'
                                                *   '<S70>/Dead Zone'
                                                *   '<S70>/Gain'
                                                */
extern struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S10>/Constant1'
                                                 *   '<S151>/Constant'
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
 * Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate' : Unused code path elimination
 * Block '<S146>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/Reshape' : Reshape block reduction
 * Block '<S97>/Reshape' : Reshape block reduction
 * Block '<S97>/Reshape1' : Reshape block reduction
 * Block '<S97>/Reshape2' : Reshape block reduction
 * Block '<S136>/Reshape' : Reshape block reduction
 * Block '<S135>/Reshape' : Reshape block reduction
 * Block '<S135>/Reshape1' : Reshape block reduction
 * Block '<S135>/Reshape2' : Reshape block reduction
 * Block '<S151>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S21>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S21>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S21>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S152>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S2>'   : 'FMS/CommandProcess'
 * '<S3>'   : 'FMS/FMS Commander'
 * '<S4>'   : 'FMS/FMS State Machine'
 * '<S5>'   : 'FMS/SafeMode'
 * '<S6>'   : 'FMS/Auto_Cmd_Valid/Compare To Constant4'
 * '<S7>'   : 'FMS/Auto_Cmd_Valid/Detect Change'
 * '<S8>'   : 'FMS/Auto_Cmd_Valid/Ever_Valid'
 * '<S9>'   : 'FMS/Auto_Cmd_Valid/Interval Test'
 * '<S10>'  : 'FMS/CommandProcess/Check Valid'
 * '<S11>'  : 'FMS/CommandProcess/Command Routing'
 * '<S12>'  : 'FMS/CommandProcess/Mode Routing'
 * '<S13>'  : 'FMS/CommandProcess/Check Valid/Compare To Constant1'
 * '<S14>'  : 'FMS/CommandProcess/Check Valid/Detect Change1'
 * '<S15>'  : 'FMS/CommandProcess/Command Routing/Detect Change3'
 * '<S16>'  : 'FMS/CommandProcess/Command Routing/Detect Change4'
 * '<S17>'  : 'FMS/CommandProcess/Mode Routing/Compare To Zero'
 * '<S18>'  : 'FMS/CommandProcess/Mode Routing/Compare To Zero1'
 * '<S19>'  : 'FMS/CommandProcess/Mode Routing/Detect Change'
 * '<S20>'  : 'FMS/FMS Commander/Commander'
 * '<S21>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S22>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S23>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S24>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S25>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S26>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Speed Command'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone2'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Speed Command/DeadZone2'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone2'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Brake Control'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Move Control'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Bus_Selection'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Psi To DCM'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Controller/Move Control/DeadZone'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Compare To Constant1'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Motion State'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/Quaternion Normalize'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_1'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_2'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/column_3'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Speed Command/Detect Movement/Bus_Select/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command '
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Altitude Command /DeadZone2'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone2'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Speed Command/DeadZone2'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus1'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Way Points'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero6'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus1'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Way Points'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S151>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S152>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S153>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S154>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S155>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S156>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S157>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S158>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S159>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S160>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S161>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S162>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S163>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S164>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
