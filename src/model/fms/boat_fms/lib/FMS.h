/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1985
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov  7 11:14:41 2024
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
  real32_T DataTypeConversion[3];      /* '<S125>/Data Type Conversion' */
  real32_T Merge;                      /* '<S36>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S11>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T Compare;                   /* '<S137>/Compare' */
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
  real32_T DelayInput1_DSTATE;         /* '<S55>/Delay Input1' */
  real32_T start_vel_DSTATE[2];        /* '<S42>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S42>/start_wp' */
  real32_T Delay_DSTATE[2];            /* '<S108>/Delay' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S7>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S124>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_ak;      /* '<S14>/Delay Input1' */
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
  uint8_T Delay_DSTATE_p;              /* '<S8>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S66>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S20>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S26>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_d; /* '<S36>/Switch Case' */
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
  uint8_T is_Offboard;                 /* '<Root>/FMS State Machine' */
  uint8_T is_Mission;                  /* '<Root>/FMS State Machine' */
  uint8_T is_Assist;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Manual;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Combo_Stick;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Combo_Stick;       /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S37>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S37>/Motion State' */
  uint8_T icLoad;                      /* '<S42>/start_vel' */
  uint8_T icLoad_o;                    /* '<S42>/start_wp' */
  uint8_T icLoad_c;                    /* '<S108>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState start_vel_Reset_ZCE;      /* '<S42>/start_vel' */
  ZCSigState start_wp_Reset_ZCE;       /* '<S42>/start_wp' */
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S63>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S29>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S106>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S106>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S128>/Sum' */
  const real_T ff;                     /* '<S128>/Multiply3' */
  const real_T Sum4;                   /* '<S128>/Sum4' */
  const real32_T VectorConcatenate3[3];/* '<S99>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S101>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S28>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S28>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S31>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S31>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S31>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ba; /* '<S32>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S32>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S32>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S67>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S67>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S67>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_d;  /* '<S64>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_c; /* '<S64>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_f; /* '<S64>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_h;  /* '<S104>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S104>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S104>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S105>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m0;/* '<S105>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S105>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S25>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S25>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S24>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S24>/Data Type Conversion1' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S22>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S26>/Unknown' */
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
extern struct_JxjeS66VNGfjrjCrA9f7AC FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S24>/Constant6'
                                                *   '<S25>/Constant6'
                                                *   '<S32>/Gain'
                                                *   '<S32>/Gain1'
                                                *   '<S105>/L1'
                                                *   '<S105>/vel'
                                                *   '<S35>/Gain'
                                                *   '<S67>/L1'
                                                *   '<S67>/vel'
                                                *   '<S107>/AccToRate'
                                                *   '<S68>/AccToRate'
                                                *   '<S38>/L1'
                                                *   '<S38>/AccToRate'
                                                *   '<S39>/Gain6'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S10>/Constant1'
                                                 *   '<S124>/Constant'
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
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Reshape' : Reshape block reduction
 * Block '<S69>/Reshape' : Reshape block reduction
 * Block '<S69>/Reshape1' : Reshape block reduction
 * Block '<S69>/Reshape2' : Reshape block reduction
 * Block '<S109>/Reshape' : Reshape block reduction
 * Block '<S108>/Reshape' : Reshape block reduction
 * Block '<S108>/Reshape1' : Reshape block reduction
 * Block '<S108>/Reshape2' : Reshape block reduction
 * Block '<S124>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S21>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S21>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S21>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S125>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Velocity_Command'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Detect Change'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/sign'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Velocity_Command/DeadZone'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/DeadZone'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/DeadZone1'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero6'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Body_Frame'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Command_Mask'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Global_Frame'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Local_Frame'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Global_Frame/Psi To DCM'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Global_Frame/Psi To DCM/Rotation Matrix Z'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Local_Frame/Psi To DCM2'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Local_Frame/Psi To DCM2/Rotation Matrix Z'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S124>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S125>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S126>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S127>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S128>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S129>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S130>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S131>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S132>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S133>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S134>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S135>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S136>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S137>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
