/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2015
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec  9 14:26:54 2024
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
  real32_T Merge;                      /* '<S41>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S12>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T Compare;                   /* '<S24>/Compare' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare_k;                 /* '<S146>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission;                 /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_a[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_g;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  real32_T DelayInput1_DSTATE;         /* '<S61>/Delay Input1' */
  real32_T start_vel_DSTATE[2];        /* '<S48>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S48>/start_wp' */
  real32_T Integrator1_DSTATE;         /* '<S75>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S75>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S117>/Delay' */
  uint32_T DelayInput1_DSTATE_j;       /* '<S21>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S22>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S8>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_j;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S133>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_ak;      /* '<S15>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S11>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S20>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S17>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S16>/Delay Input1' */
  PilotMode Delay_DSTATE_c;            /* '<S13>/Delay' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_k;/* '<Root>/FMS State Machine' */
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
  uint8_T Delay_DSTATE_p;              /* '<S9>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S73>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S25>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S27>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S31>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_d; /* '<S41>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S32>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S34>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S42>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S42>/Motion State' */
  uint8_T temporalCounter_i1_o;        /* '<S42>/Motion State' */
  uint8_T icLoad;                      /* '<S48>/start_vel' */
  uint8_T icLoad_o;                    /* '<S48>/start_wp' */
  uint8_T icLoad_c;                    /* '<S117>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_k;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState start_vel_Reset_ZCE;      /* '<S48>/start_vel' */
  ZCSigState start_wp_Reset_ZCE;       /* '<S48>/start_wp' */
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S70>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S34>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S115>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S115>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S137>/Sum' */
  const real_T ff;                     /* '<S137>/Multiply3' */
  const real_T Sum4;                   /* '<S137>/Sum4' */
  const real32_T Square;               /* '<S78>/Square' */
  const real32_T d;                    /* '<S78>/Multiply' */
  const real32_T Gain4;                /* '<S78>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S108>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S110>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S33>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S33>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S33>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S36>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S36>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S36>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ba; /* '<S37>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S37>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S37>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S74>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S74>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S74>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_d;  /* '<S71>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_c; /* '<S71>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_f; /* '<S71>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_h;  /* '<S113>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S113>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S113>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S114>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m0;/* '<S114>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S114>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S30>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S30>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S29>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S29>/Data Type Conversion1' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S27>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S31>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S32>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S34>/Unknown' */
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
extern struct_IanTaCoVQ0ZTLiFhTJ6eFB FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S3>/Constant1'
                                                *   '<S23>/Constant'
                                                *   '<S29>/Constant6'
                                                *   '<S30>/Constant6'
                                                *   '<S37>/Gain'
                                                *   '<S114>/L1'
                                                *   '<S114>/vel'
                                                *   '<S40>/Gain'
                                                *   '<S74>/L1'
                                                *   '<S74>/vel'
                                                *   '<S116>/AY_P'
                                                *   '<S76>/AY_P'
                                                *   '<S44>/L1'
                                                *   '<S44>/AY_P'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S11>/Constant1'
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
 * Block '<S10>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Reshape' : Reshape block reduction
 * Block '<S77>/Reshape' : Reshape block reduction
 * Block '<S77>/Reshape1' : Reshape block reduction
 * Block '<S77>/Reshape2' : Reshape block reduction
 * Block '<S118>/Reshape' : Reshape block reduction
 * Block '<S117>/Reshape' : Reshape block reduction
 * Block '<S117>/Reshape1' : Reshape block reduction
 * Block '<S117>/Reshape2' : Reshape block reduction
 * Block '<S133>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S26>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S26>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S26>/Signal Copy6' : Eliminate redundant signal conversion block
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
 * '<S1>'   : 'FMS/Auto_Cmd_Valid'
 * '<S2>'   : 'FMS/CommandProcess'
 * '<S3>'   : 'FMS/Detect_Lost_Connect'
 * '<S4>'   : 'FMS/FMS Commander'
 * '<S5>'   : 'FMS/FMS State Machine'
 * '<S6>'   : 'FMS/SafeMode'
 * '<S7>'   : 'FMS/Auto_Cmd_Valid/Compare To Constant4'
 * '<S8>'   : 'FMS/Auto_Cmd_Valid/Detect Change'
 * '<S9>'   : 'FMS/Auto_Cmd_Valid/Ever_Valid'
 * '<S10>'  : 'FMS/Auto_Cmd_Valid/Interval Test'
 * '<S11>'  : 'FMS/CommandProcess/Check Valid'
 * '<S12>'  : 'FMS/CommandProcess/Command Routing'
 * '<S13>'  : 'FMS/CommandProcess/Mode Routing'
 * '<S14>'  : 'FMS/CommandProcess/Check Valid/Compare To Constant1'
 * '<S15>'  : 'FMS/CommandProcess/Check Valid/Detect Change1'
 * '<S16>'  : 'FMS/CommandProcess/Command Routing/Detect Change3'
 * '<S17>'  : 'FMS/CommandProcess/Command Routing/Detect Change4'
 * '<S18>'  : 'FMS/CommandProcess/Mode Routing/Compare To Zero'
 * '<S19>'  : 'FMS/CommandProcess/Mode Routing/Compare To Zero1'
 * '<S20>'  : 'FMS/CommandProcess/Mode Routing/Detect Change'
 * '<S21>'  : 'FMS/Detect_Lost_Connect/Detect Change'
 * '<S22>'  : 'FMS/Detect_Lost_Connect/Detect Change1'
 * '<S23>'  : 'FMS/Detect_Lost_Connect/timeout1_s'
 * '<S24>'  : 'FMS/Detect_Lost_Connect/timeout2_s'
 * '<S25>'  : 'FMS/FMS Commander/Commander'
 * '<S26>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Velocity_Command'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Detect Change'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/sign'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Velocity_Command/DeadZone'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/DeadZone'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/DeadZone1'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/TD'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/TD/fhan '
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero6'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Body_Frame'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Command_Mask'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Global_Frame'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Local_Frame'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Global_Frame/Psi To DCM'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Local_Frame/Psi To DCM2'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
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
