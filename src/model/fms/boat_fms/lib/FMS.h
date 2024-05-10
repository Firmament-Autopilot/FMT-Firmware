/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1977
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 15:09:37 2024
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
  real32_T DataTypeConversion[3];      /* '<S103>/Data Type Conversion' */
  real32_T Merge;                      /* '<S31>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S6>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T Compare;                   /* '<S115>/Compare' */
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
  real32_T DelayInput1_DSTATE;         /* '<S50>/Delay Input1' */
  real32_T start_vel_DSTATE[2];        /* '<S37>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S37>/start_wp' */
  real32_T Delay_DSTATE[2];            /* '<S86>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S102>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S9>/Delay Input1' */
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
  uint8_T DelayInput1_DSTATE_pe;       /* '<S61>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S15>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S17>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S21>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_d; /* '<S31>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S32>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S32>/Motion State' */
  uint8_T icLoad;                      /* '<S37>/start_vel' */
  uint8_T icLoad_o;                    /* '<S37>/start_wp' */
  uint8_T icLoad_c;                    /* '<S86>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_c;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState start_vel_Reset_ZCE;      /* '<S37>/start_vel' */
  ZCSigState start_wp_Reset_ZCE;       /* '<S37>/start_wp' */
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S58>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S24>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S84>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S84>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S106>/Sum' */
  const real_T ff;                     /* '<S106>/Multiply3' */
  const real_T Sum4;                   /* '<S106>/Sum4' */
  const uint8_T DataTypeConversion;    /* '<S23>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S23>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S23>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S26>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S26>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S26>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ba; /* '<S27>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S62>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S62>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S62>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S59>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S59>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_h;  /* '<S82>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S82>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S82>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S83>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m0;/* '<S83>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S83>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S20>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S20>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S19>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S19>/Data Type Conversion1' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S17>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S21>/Unknown' */
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
extern struct_JxjeS66VNGfjrjCrA9f7AC FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S19>/Constant6'
                                                *   '<S20>/Constant6'
                                                *   '<S27>/Gain'
                                                *   '<S27>/Gain1'
                                                *   '<S83>/L1'
                                                *   '<S83>/vel'
                                                *   '<S30>/Gain'
                                                *   '<S62>/L1'
                                                *   '<S62>/vel'
                                                *   '<S85>/AccToRate'
                                                *   '<S63>/AccToRate'
                                                *   '<S33>/L1'
                                                *   '<S33>/AccToRate'
                                                *   '<S34>/Gain6'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S5>/Constant1'
                                                 *   '<S102>/Constant'
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
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Reshape' : Reshape block reduction
 * Block '<S64>/Reshape' : Reshape block reduction
 * Block '<S64>/Reshape1' : Reshape block reduction
 * Block '<S64>/Reshape2' : Reshape block reduction
 * Block '<S87>/Reshape' : Reshape block reduction
 * Block '<S86>/Reshape' : Reshape block reduction
 * Block '<S86>/Reshape1' : Reshape block reduction
 * Block '<S86>/Reshape2' : Reshape block reduction
 * Block '<S102>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S103>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S26>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Velocity_Command'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Detect Change'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/sign'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Velocity_Command/DeadZone'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/DeadZone'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/DeadZone1'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S102>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S103>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S104>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S105>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S106>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S107>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S108>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S109>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S110>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S111>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S112>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S113>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S114>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S115>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
