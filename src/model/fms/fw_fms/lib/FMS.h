/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2015
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 29 14:23:53 2023
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

/* Block states (default storage) for system '<S44>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S47>/Delay' */
  uint8_T icLoad;                      /* '<S47>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S45>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S45>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S45>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S45>/Motion Status' */
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
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T DataTypeConversion[3];      /* '<S216>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S217>/Reshape' */
  real32_T Merge;                      /* '<S65>/Merge' */
  real32_T Merge_p;                    /* '<S79>/Merge' */
  real32_T Merge_l;                    /* '<S44>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S7>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator2;          /* '<S2>/Logical Operator2' */
  boolean_T Compare;                   /* '<S21>/Compare' */
  boolean_T Compare_k;                 /* '<S229>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission_takeoff;         /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_c[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_p;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real32_T start_vel_DSTATE[2];        /* '<S86>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S86>/start_wp' */
  real32_T start_vel_DSTATE_g[2];      /* '<S158>/start_vel' */
  real32_T Delay_DSTATE;               /* '<S153>/Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S18>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_e;       /* '<S19>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S215>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_a;       /* '<S10>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S6>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S17>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S13>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S12>/Delay Input1' */
  PilotMode Delay_DSTATE_c;            /* '<S8>/Delay' */
  real32_T home[4];                    /* '<Root>/Data Store Memory' */
  real32_T home_p[4];                  /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_k;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_c;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2_a;/* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_i;       /* '<S80>/Motion State' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S122>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S24>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S28>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S79>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_ba;/* '<S65>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S44>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S29>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S31>/Switch Case' */
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
  uint8_T is_Lost_Return;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Lost_Return;       /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S80>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S80>/Motion State' */
  uint8_T icLoad;                      /* '<S86>/start_vel' */
  uint8_T icLoad_c;                    /* '<S86>/start_wp' */
  uint8_T icLoad_n;                    /* '<S158>/start_vel' */
  uint8_T icLoad_b;                    /* '<S153>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_k;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_g;/* '<Root>/FMS State Machine' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S66>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_l;  /* '<S65>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S45>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S44>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S119>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S7>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S31>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S152>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S152>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S220>/Sum' */
  const real_T ff;                     /* '<S220>/Multiply3' */
  const real_T Sum4;                   /* '<S220>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S106>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S30>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S30>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S30>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S35>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S35>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S35>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S34>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S34>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S34>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S36>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S36>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S36>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S33>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S33>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S33>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S123>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S123>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S123>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S120>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S120>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S148>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S148>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S148>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S150>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S150>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S150>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S149>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S149>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_ml;/* '<S149>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_k;  /* '<S151>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_ok;/* '<S151>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S151>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S26>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S26>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S24>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S28>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S29>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S31>/Unknown' */
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
extern struct_lsSw80pJwzMfDv47oR1SCF FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S2>/Constant1'
                                                *   '<S20>/Constant'
                                                *   '<S217>/Constant'
                                                *   '<S146>/Gain'
                                                *   '<S146>/Gain4'
                                                *   '<S146>/Gain5'
                                                *   '<S150>/Constant4'
                                                *   '<S151>/Constant4'
                                                *   '<S40>/Gain'
                                                *   '<S42>/Gain'
                                                *   '<S43>/Gain1'
                                                *   '<S61>/Gain'
                                                *   '<S63>/Gain1'
                                                *   '<S107>/Gain'
                                                *   '<S107>/Gain1'
                                                *   '<S108>/Gain1'
                                                *   '<S123>/Constant4'
                                                *   '<S153>/Gain2'
                                                *   '<S153>/Saturation1'
                                                *   '<S154>/L1'
                                                *   '<S154>/R'
                                                *   '<S171>/Gain'
                                                *   '<S171>/Saturation1'
                                                *   '<S193>/Gain'
                                                *   '<S193>/Saturation1'
                                                *   '<S44>/Saturation1'
                                                *   '<S55>/Dead Zone'
                                                *   '<S55>/Gain'
                                                *   '<S58>/Dead Zone'
                                                *   '<S58>/Gain'
                                                *   '<S65>/Saturation1'
                                                *   '<S76>/Dead Zone'
                                                *   '<S76>/Gain'
                                                *   '<S79>/Saturation1'
                                                *   '<S110>/Dead Zone'
                                                *   '<S110>/Gain'
                                                *   '<S111>/Dead Zone'
                                                *   '<S111>/Gain'
                                                *   '<S116>/Dead Zone'
                                                *   '<S116>/Gain'
                                                *   '<S124>/Gain'
                                                *   '<S124>/Saturation1'
                                                *   '<S176>/L1'
                                                *   '<S176>/Saturation1'
                                                *   '<S198>/L1'
                                                *   '<S198>/Saturation1'
                                                *   '<S47>/Gain2'
                                                *   '<S48>/Gain1'
                                                *   '<S53>/Constant'
                                                *   '<S68>/Gain2'
                                                *   '<S69>/Gain1'
                                                *   '<S74>/Constant'
                                                *   '<S82>/L1'
                                                *   '<S83>/Gain6'
                                                *   '<S103>/Constant'
                                                *   '<S129>/L1'
                                                *   '<S129>/Saturation1'
                                                *   '<S50>/Dead Zone'
                                                *   '<S50>/Gain'
                                                *   '<S71>/Dead Zone'
                                                *   '<S71>/Gain'
                                                *   '<S100>/Dead Zone'
                                                *   '<S100>/Gain'
                                                */
extern struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S6>/Constant1'
                                                 *   '<S215>/Constant'
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
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S144>/Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Reshape' : Reshape block reduction
 * Block '<S130>/Reshape' : Reshape block reduction
 * Block '<S130>/Reshape1' : Reshape block reduction
 * Block '<S130>/Reshape2' : Reshape block reduction
 * Block '<S156>/Reshape' : Reshape block reduction
 * Block '<S156>/Reshape1' : Reshape block reduction
 * Block '<S156>/Reshape2' : Reshape block reduction
 * Block '<S156>/Reshape3' : Reshape block reduction
 * Block '<S178>/Reshape' : Reshape block reduction
 * Block '<S177>/Reshape' : Reshape block reduction
 * Block '<S177>/Reshape1' : Reshape block reduction
 * Block '<S177>/Reshape2' : Reshape block reduction
 * Block '<S200>/Reshape' : Reshape block reduction
 * Block '<S199>/Reshape' : Reshape block reduction
 * Block '<S199>/Reshape1' : Reshape block reduction
 * Block '<S199>/Reshape2' : Reshape block reduction
 * Block '<S215>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S23>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S23>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S23>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S216>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S2>'   : 'FMS/Detect_Lost_Connect'
 * '<S3>'   : 'FMS/FMS Commander'
 * '<S4>'   : 'FMS/FMS State Machine'
 * '<S5>'   : 'FMS/SafeMode'
 * '<S6>'   : 'FMS/CommandProcess/Check Valid'
 * '<S7>'   : 'FMS/CommandProcess/Command PreProcess'
 * '<S8>'   : 'FMS/CommandProcess/Mode PreProcess'
 * '<S9>'   : 'FMS/CommandProcess/Check Valid/Compare To Constant1'
 * '<S10>'  : 'FMS/CommandProcess/Check Valid/Detect Change1'
 * '<S11>'  : 'FMS/CommandProcess/Command PreProcess/Compare To Constant'
 * '<S12>'  : 'FMS/CommandProcess/Command PreProcess/Detect Change3'
 * '<S13>'  : 'FMS/CommandProcess/Command PreProcess/Detect Change4'
 * '<S14>'  : 'FMS/CommandProcess/Command PreProcess/SetHome'
 * '<S15>'  : 'FMS/CommandProcess/Mode PreProcess/Compare To Zero'
 * '<S16>'  : 'FMS/CommandProcess/Mode PreProcess/Compare To Zero1'
 * '<S17>'  : 'FMS/CommandProcess/Mode PreProcess/Detect Change'
 * '<S18>'  : 'FMS/Detect_Lost_Connect/Detect Change'
 * '<S19>'  : 'FMS/Detect_Lost_Connect/Detect Change1'
 * '<S20>'  : 'FMS/Detect_Lost_Connect/timeout1_s'
 * '<S21>'  : 'FMS/Detect_Lost_Connect/timeout2_s'
 * '<S22>'  : 'FMS/FMS Commander/Commander'
 * '<S23>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S24>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S25>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S26>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Airspeed Command'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD/fhan '
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Airspeed Command'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD/fhan '
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM/Rotation Matrix Z'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD/fhan '
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus1'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/WayPoints'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude_Hold'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude_Hold/Bus_Selection'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/Reference_Point'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/Compare To Constant'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/OutRegionRegWP'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/SearchL1RefWP'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/Reference_Point/Vector Normalize'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus1'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/WayPoints'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height/Vector Modulus'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height/Vector Modulus1'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/WayPoints'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S215>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S216>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S217>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S218>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S219>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S220>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S221>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S222>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S223>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S224>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S225>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S226>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S227>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S228>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S229>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
