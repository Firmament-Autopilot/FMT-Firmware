/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1995
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed May  3 13:51:29 2023
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

/* Block states (default storage) for system '<S39>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S42>/Delay' */
  uint8_T icLoad;                      /* '<S42>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S40>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S40>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S40>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S40>/Motion Status' */
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
  real32_T DataTypeConversion[3];      /* '<S211>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S212>/Reshape' */
  real32_T Merge;                      /* '<S60>/Merge' */
  real32_T Merge_p;                    /* '<S74>/Merge' */
  real32_T Merge_l;                    /* '<S39>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S6>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T Compare;                   /* '<S224>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission_takeoff;         /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_o[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_p;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T start_vel_DSTATE[2];        /* '<S81>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S81>/start_wp' */
  real32_T start_vel_DSTATE_g[2];      /* '<S153>/start_vel' */
  real32_T Delay_DSTATE;               /* '<S148>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S210>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S9>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S5>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S16>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S12>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S11>/Delay Input1' */
  PilotMode Delay_DSTATE_c;            /* '<S7>/Delay' */
  real32_T home[4];                    /* '<Root>/Data Store Memory' */
  real32_T home_l[4];                  /* '<Root>/FMS State Machine' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_j;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_c;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2_j;/* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_i;       /* '<S75>/Motion State' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S117>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S17>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S19>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S23>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S74>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_ba;/* '<S60>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S39>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S24>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S26>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S75>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S75>/Motion State' */
  uint8_T icLoad;                      /* '<S81>/start_vel' */
  uint8_T icLoad_c;                    /* '<S81>/start_wp' */
  uint8_T icLoad_n;                    /* '<S153>/start_vel' */
  uint8_T icLoad_b;                    /* '<S148>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_b;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d0;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_g;/* '<Root>/FMS State Machine' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S61>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_l;  /* '<S60>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S40>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S39>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S114>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S6>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S26>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S147>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S147>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S215>/Sum' */
  const real_T ff;                     /* '<S215>/Multiply3' */
  const real_T Sum4;                   /* '<S215>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S101>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S25>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S25>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S25>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S30>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S30>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S30>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S29>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S29>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S29>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S31>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S31>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S31>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S28>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S28>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S118>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S118>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S118>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S115>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S115>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S143>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S143>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S143>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S145>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S145>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S145>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S144>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S144>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_ml;/* '<S144>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_k;  /* '<S146>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_ok;/* '<S146>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S146>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S22>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S22>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S21>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S21>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S19>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S23>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S24>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S26>/Unknown' */
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
extern struct_LQbHTlAQVN7sVz7acpAn4 FMS_PARAM;/* Variable: FMS_PARAM
                                               * Referenced by:
                                               *   '<Root>/ACCEPT_R'
                                               *   '<S212>/Constant'
                                               *   '<S21>/Constant6'
                                               *   '<S22>/Constant6'
                                               *   '<S141>/Gain'
                                               *   '<S141>/Gain4'
                                               *   '<S141>/Gain5'
                                               *   '<S145>/Constant4'
                                               *   '<S146>/Constant4'
                                               *   '<S35>/Gain'
                                               *   '<S37>/Gain'
                                               *   '<S38>/Gain1'
                                               *   '<S56>/Gain'
                                               *   '<S58>/Gain1'
                                               *   '<S102>/Gain'
                                               *   '<S102>/Gain1'
                                               *   '<S103>/Gain1'
                                               *   '<S118>/Constant4'
                                               *   '<S148>/Gain2'
                                               *   '<S149>/L1'
                                               *   '<S149>/R'
                                               *   '<S166>/Gain'
                                               *   '<S166>/Saturation1'
                                               *   '<S188>/Gain'
                                               *   '<S188>/Saturation1'
                                               *   '<S39>/Saturation1'
                                               *   '<S50>/Dead Zone'
                                               *   '<S50>/Gain'
                                               *   '<S53>/Dead Zone'
                                               *   '<S53>/Gain'
                                               *   '<S60>/Saturation1'
                                               *   '<S71>/Dead Zone'
                                               *   '<S71>/Gain'
                                               *   '<S74>/Saturation1'
                                               *   '<S105>/Dead Zone'
                                               *   '<S105>/Gain'
                                               *   '<S106>/Dead Zone'
                                               *   '<S106>/Gain'
                                               *   '<S111>/Dead Zone'
                                               *   '<S111>/Gain'
                                               *   '<S119>/Gain'
                                               *   '<S119>/Saturation1'
                                               *   '<S171>/L1'
                                               *   '<S171>/Saturation1'
                                               *   '<S193>/L1'
                                               *   '<S193>/Saturation1'
                                               *   '<S42>/Gain2'
                                               *   '<S43>/Gain1'
                                               *   '<S48>/Constant'
                                               *   '<S63>/Gain2'
                                               *   '<S64>/Gain1'
                                               *   '<S69>/Constant'
                                               *   '<S77>/L1'
                                               *   '<S78>/Gain6'
                                               *   '<S98>/Constant'
                                               *   '<S124>/L1'
                                               *   '<S124>/Saturation1'
                                               *   '<S45>/Dead Zone'
                                               *   '<S45>/Gain'
                                               *   '<S66>/Dead Zone'
                                               *   '<S66>/Gain'
                                               *   '<S95>/Dead Zone'
                                               *   '<S95>/Gain'
                                               */
extern struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S5>/Constant1'
                                                 *   '<S210>/Constant'
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
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate' : Unused code path elimination
 * Block '<S163>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S208>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S206>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Reshape' : Reshape block reduction
 * Block '<S125>/Reshape' : Reshape block reduction
 * Block '<S125>/Reshape1' : Reshape block reduction
 * Block '<S125>/Reshape2' : Reshape block reduction
 * Block '<S151>/Reshape' : Reshape block reduction
 * Block '<S151>/Reshape1' : Reshape block reduction
 * Block '<S151>/Reshape2' : Reshape block reduction
 * Block '<S151>/Reshape3' : Reshape block reduction
 * Block '<S173>/Reshape' : Reshape block reduction
 * Block '<S172>/Reshape' : Reshape block reduction
 * Block '<S172>/Reshape1' : Reshape block reduction
 * Block '<S172>/Reshape2' : Reshape block reduction
 * Block '<S195>/Reshape' : Reshape block reduction
 * Block '<S194>/Reshape' : Reshape block reduction
 * Block '<S194>/Reshape1' : Reshape block reduction
 * Block '<S194>/Reshape2' : Reshape block reduction
 * Block '<S210>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S211>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S6>'   : 'FMS/CommandProcess/Command PreProcess'
 * '<S7>'   : 'FMS/CommandProcess/Mode PreProcess'
 * '<S8>'   : 'FMS/CommandProcess/Check Valid/Compare To Constant1'
 * '<S9>'   : 'FMS/CommandProcess/Check Valid/Detect Change1'
 * '<S10>'  : 'FMS/CommandProcess/Command PreProcess/Compare To Constant'
 * '<S11>'  : 'FMS/CommandProcess/Command PreProcess/Detect Change3'
 * '<S12>'  : 'FMS/CommandProcess/Command PreProcess/Detect Change4'
 * '<S13>'  : 'FMS/CommandProcess/Command PreProcess/SetHome'
 * '<S14>'  : 'FMS/CommandProcess/Mode PreProcess/Compare To Zero'
 * '<S15>'  : 'FMS/CommandProcess/Mode PreProcess/Compare To Zero1'
 * '<S16>'  : 'FMS/CommandProcess/Mode PreProcess/Detect Change'
 * '<S17>'  : 'FMS/FMS Commander/Commander'
 * '<S18>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S19>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S20>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S21>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S22>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S23>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S24>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S25>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S26>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Airspeed Command'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD/fhan '
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Airspeed Command'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD/fhan '
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM/Rotation Matrix Z'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD/fhan '
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus1'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/WayPoints'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude_Hold'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude_Hold/Bus_Selection'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/Reference_Point'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/Compare To Constant'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/OutRegionRegWP'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/SearchL1RefWP'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/Reference_Point/Vector Normalize'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus1'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/WayPoints'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height/Vector Modulus'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height/Vector Modulus1'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/WayPoints'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S210>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S211>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S212>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S213>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S214>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S215>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S216>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S217>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S218>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S219>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S220>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S221>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S222>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S223>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S224>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
