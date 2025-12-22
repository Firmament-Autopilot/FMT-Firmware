/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2047
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec 22 14:38:23 2025
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

/* Block states (default storage) for system '<S46>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S49>/Delay' */
  uint8_T icLoad;                      /* '<S49>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S47>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S47>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S47>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S47>/Motion Status' */
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
  real32_T DataTypeConversion[3];      /* '<S222>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S223>/Reshape' */
  real32_T Merge;                      /* '<S67>/Merge' */
  real32_T Merge_p;                    /* '<S81>/Merge' */
  real32_T Merge_l;                    /* '<S46>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S7>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator2;          /* '<S2>/Logical Operator2' */
  boolean_T Compare;                   /* '<S21>/Compare' */
  boolean_T Compare_k;                 /* '<S235>/Compare' */
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
  real32_T Integrator1_DSTATE;         /* '<S79>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S79>/Integrator' */
  real32_T Integrator1_DSTATE_c;       /* '<S103>/Integrator1' */
  real32_T Integrator_DSTATE_h;        /* '<S103>/Integrator' */
  real32_T start_vel_DSTATE[2];        /* '<S88>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S88>/start_wp' */
  real32_T Integrator1_DSTATE_h;       /* '<S44>/Integrator1' */
  real32_T Integrator_DSTATE_k;        /* '<S44>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S58>/Integrator1' */
  real32_T Integrator1_DSTATE_l;       /* '<S61>/Integrator1' */
  real32_T Integrator_DSTATE_g;        /* '<S61>/Integrator' */
  real32_T Integrator_DSTATE_b;        /* '<S58>/Integrator' */
  real32_T start_vel_DSTATE_g[2];      /* '<S162>/start_vel' */
  real32_T Delay_DSTATE;               /* '<S157>/Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S18>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_e;       /* '<S19>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S221>/Discrete-Time Integrator' */
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
  uint32_T temporalCounter_i1;         /* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_i;       /* '<S82>/Motion State' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S124>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S24>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S28>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S81>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_ba;/* '<S67>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S46>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S82>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S82>/Motion State' */
  uint8_T icLoad;                      /* '<S88>/start_vel' */
  uint8_T icLoad_c;                    /* '<S88>/start_wp' */
  uint8_T icLoad_n;                    /* '<S162>/start_vel' */
  uint8_T icLoad_b;                    /* '<S157>/Delay' */
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
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S68>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_l;  /* '<S67>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S47>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S46>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S121>/Mission_SubSystem' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S7>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S31>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S156>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S156>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S226>/Sum' */
  const real_T ff;                     /* '<S226>/Multiply3' */
  const real_T Sum4;                   /* '<S226>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S108>/Vector Concatenate3' */
  const real32_T Square;               /* '<S80>/Square' */
  const real32_T d;                    /* '<S80>/Multiply' */
  const real32_T Gain4;                /* '<S80>/Gain4' */
  const real32_T Square_k;             /* '<S104>/Square' */
  const real32_T d_j;                  /* '<S104>/Multiply' */
  const real32_T Gain4_k;              /* '<S104>/Gain4' */
  const real32_T Square_n;             /* '<S45>/Square' */
  const real32_T d_g;                  /* '<S45>/Multiply' */
  const real32_T Gain4_h;              /* '<S45>/Gain4' */
  const real32_T Square_a;             /* '<S62>/Square' */
  const real32_T d_a;                  /* '<S62>/Multiply' */
  const real32_T Gain4_e;              /* '<S62>/Gain4' */
  const real32_T Square_nm;            /* '<S59>/Square' */
  const real32_T d_f;                  /* '<S59>/Multiply' */
  const real32_T Gain4_a;              /* '<S59>/Gain4' */
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
  const uint8_T DataTypeConversion_l;  /* '<S125>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S125>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S125>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S122>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S122>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S152>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S152>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S152>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S154>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S154>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S154>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S153>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S153>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_ml;/* '<S153>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_k;  /* '<S155>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_ok;/* '<S155>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S155>/Data Type Conversion2' */
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
                                                *   '<S223>/Constant'
                                                *   '<S150>/Gain'
                                                *   '<S150>/Gain4'
                                                *   '<S150>/Gain5'
                                                *   '<S155>/Constant4'
                                                *   '<S40>/Gain'
                                                *   '<S42>/Gain'
                                                *   '<S43>/Gain1'
                                                *   '<S63>/Gain'
                                                *   '<S65>/Gain1'
                                                *   '<S109>/Gain'
                                                *   '<S109>/Gain1'
                                                *   '<S110>/Gain1'
                                                *   '<S157>/Gain2'
                                                *   '<S157>/Saturation1'
                                                *   '<S158>/L1'
                                                *   '<S158>/R'
                                                *   '<S175>/Gain'
                                                *   '<S175>/Saturation1'
                                                *   '<S176>/vel'
                                                *   '<S199>/Gain'
                                                *   '<S199>/Saturation1'
                                                *   '<S46>/Saturation1'
                                                *   '<S57>/Dead Zone'
                                                *   '<S57>/Gain'
                                                *   '<S60>/Dead Zone'
                                                *   '<S60>/Gain'
                                                *   '<S67>/Saturation1'
                                                *   '<S78>/Dead Zone'
                                                *   '<S78>/Gain'
                                                *   '<S81>/Saturation1'
                                                *   '<S112>/Dead Zone'
                                                *   '<S112>/Gain'
                                                *   '<S113>/Dead Zone'
                                                *   '<S113>/Gain'
                                                *   '<S118>/Dead Zone'
                                                *   '<S118>/Gain'
                                                *   '<S126>/Gain'
                                                *   '<S126>/Saturation1'
                                                *   '<S127>/vel'
                                                *   '<S182>/L1'
                                                *   '<S182>/Saturation1'
                                                *   '<S204>/L1'
                                                *   '<S204>/Saturation1'
                                                *   '<S49>/Gain2'
                                                *   '<S50>/Gain1'
                                                *   '<S55>/Constant'
                                                *   '<S70>/Gain2'
                                                *   '<S71>/Gain1'
                                                *   '<S76>/Constant'
                                                *   '<S84>/L1'
                                                *   '<S85>/Gain6'
                                                *   '<S105>/Constant'
                                                *   '<S133>/L1'
                                                *   '<S133>/Saturation1'
                                                *   '<S52>/Dead Zone'
                                                *   '<S52>/Gain'
                                                *   '<S73>/Dead Zone'
                                                *   '<S73>/Gain'
                                                *   '<S102>/Dead Zone'
                                                *   '<S102>/Gain'
                                                */
extern struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S6>/Constant1'
                                                 *   '<S221>/Constant'
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
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/Data Type Duplicate' : Unused code path elimination
 * Block '<S146>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S195>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S135>/Reshape' : Reshape block reduction
 * Block '<S134>/Reshape' : Reshape block reduction
 * Block '<S134>/Reshape1' : Reshape block reduction
 * Block '<S134>/Reshape2' : Reshape block reduction
 * Block '<S160>/Reshape' : Reshape block reduction
 * Block '<S160>/Reshape1' : Reshape block reduction
 * Block '<S160>/Reshape2' : Reshape block reduction
 * Block '<S160>/Reshape3' : Reshape block reduction
 * Block '<S184>/Reshape' : Reshape block reduction
 * Block '<S183>/Reshape' : Reshape block reduction
 * Block '<S183>/Reshape1' : Reshape block reduction
 * Block '<S183>/Reshape2' : Reshape block reduction
 * Block '<S206>/Reshape' : Reshape block reduction
 * Block '<S205>/Reshape' : Reshape block reduction
 * Block '<S205>/Reshape1' : Reshape block reduction
 * Block '<S205>/Reshape2' : Reshape block reduction
 * Block '<S221>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S23>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S23>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S23>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S222>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Airspeed Command/TD'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Airspeed Command/TD/fhan '
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD/fhan '
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Airspeed Command'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD/fhan '
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM/Rotation Matrix Z'
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD/fhan '
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Cruise Speed'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Altitude Control/Target Height/Vector Modulus1'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Cruise Speed/Compare To Zero'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/WayPoints'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude_Hold'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude_Hold/Bus_Selection'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/Reference_Point'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/Compare To Constant'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/OutRegionRegWP'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1 Reference WP/SearchL1RefWP'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Loiter_Control/Reference_Point/Vector Normalize'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Cruise Speed'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Altitude Control/Target Height/Vector Modulus1'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Cruise Speed/Compare To Zero'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/WayPoints'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height/Vector Modulus'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Altitude Control/Target Height/Vector Modulus1'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/WayPoints'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/Compare To Constant'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/Compare To Constant1'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/NearbyRefWP'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/OutRegionRegWP'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1 Reference WP/SearchL1RefWP'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Modulus'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Position Command/L1 Control/L1_Core/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S221>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S222>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S223>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S224>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S225>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S226>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S227>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S228>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S229>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S230>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S231>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S232>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S233>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S234>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S235>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
