/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1863
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Aug  6 09:40:09 2022
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

/* Block states (default storage) for system '<S262>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S265>/Delay' */
  uint8_T icLoad;                      /* '<S265>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S262>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S269>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S269>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S263>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S263>/Motion Status' */
  uint8_T is_active_c1_FMS;            /* '<S263>/Motion Status' */
  uint8_T is_c1_FMS;                   /* '<S263>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S38>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S38>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S38>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S38>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Commander_In_Bus Cmd_In;             /* '<Root>/FMS State Machine' */
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real_T lla[3];                       /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T href;                         /* '<Root>/FMS State Machine' */
  real_T psio;                         /* '<Root>/FMS State Machine' */
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T DataTypeConversion[3];      /* '<S312>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S313>/Reshape' */
  real32_T Merge;                      /* '<S58>/Merge' */
  real32_T Merge_p;                    /* '<S72>/Merge' */
  real32_T Merge_l;                    /* '<S37>/Merge' */
  real32_T Merge_e;                    /* '<S197>/Merge' */
  real32_T Merge_n;                    /* '<S207>/Merge' */
  real32_T Merge_m[2];                 /* '<S272>/Merge' */
  real32_T Merge_mu;                   /* '<S262>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S6>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T Compare;                   /* '<S325>/Compare' */
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
  real32_T start_vel_DSTATE[2];        /* '<S79>/start_vel' */
  real32_T start_wp_DSTATE[2];         /* '<S79>/start_wp' */
  real32_T Delay_DSTATE[2];            /* '<S140>/Delay' */
  real32_T l1_heading;                 /* '<S183>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S120>/Delay' */
  real32_T Integrator1_DSTATE;         /* '<S123>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S123>/Integrator' */
  real32_T Integrator1_DSTATE_k;       /* '<S216>/Integrator1' */
  real32_T Integrator_DSTATE_h;        /* '<S216>/Integrator' */
  real32_T Delay_DSTATE_g;             /* '<S210>/Delay' */
  real32_T Delay_DSTATE_e[2];          /* '<S258>/Delay' */
  real32_T l1_heading_p;               /* '<S299>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_p[2];          /* '<S238>/Delay' */
  real32_T Delay_DSTATE_a;             /* '<S239>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S242>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S242>/Integrator' */
  real32_T Integrator1_DSTATE_p[2];    /* '<S282>/Integrator1' */
  real32_T Integrator_DSTATE_p[2];     /* '<S282>/Integrator' */
  real32_T Delay_DSTATE_n[2];          /* '<S275>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S311>/Discrete-Time Integrator' */
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
  int32_T durationLastReferenceTick_1_j;/* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_i;       /* '<S73>/Motion State' */
  uint16_T temporalCounter_i1_j;       /* '<S273>/Motion State' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S115>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S15>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S17>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S21>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S72>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_ba;/* '<S58>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S37>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S22>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S24>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S197>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S207>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_k; /* '<S272>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S262>/Switch Case' */
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
  uint8_T is_active_c16_FMS;           /* '<S73>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S73>/Motion State' */
  uint8_T icLoad;                      /* '<S79>/start_vel' */
  uint8_T icLoad_c;                    /* '<S79>/start_wp' */
  uint8_T icLoad_i;                    /* '<S140>/Delay' */
  uint8_T icLoad_k;                    /* '<S120>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S123>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S208>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S208>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S208>/Motion State' */
  uint8_T icLoad_g;                    /* '<S210>/Delay' */
  uint8_T icLoad_o;                    /* '<S258>/Delay' */
  uint8_T icLoad_cg;                   /* '<S238>/Delay' */
  uint8_T icLoad_j;                    /* '<S239>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S242>/Integrator1' */
  uint8_T is_active_c2_FMS;            /* '<S273>/Motion State' */
  uint8_T is_c2_FMS;                   /* '<S273>/Motion State' */
  uint8_T icLoad_if;                   /* '<S275>/Delay' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_k;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_d0;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_g;/* '<Root>/FMS State Machine' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_jn;/* '<S59>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_l;  /* '<S58>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S38>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S37>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S198>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S197>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S197>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S263>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S262>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S262>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S112>/Mission_SubSystem' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S262>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S270>/Square' */
  const real32_T d;                    /* '<S270>/Multiply' */
  const real32_T Gain4;                /* '<S270>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S24>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S193>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S193>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S316>/Sum' */
  const real_T ff;                     /* '<S316>/Multiply3' */
  const real_T Sum4;                   /* '<S316>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S99>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S186>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S133>/Math Function' */
  const real32_T SumofElements;        /* '<S133>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S133>/Math Function1' */
  const real32_T Product[2];           /* '<S133>/Product' */
  const real32_T Switch[3];            /* '<S133>/Switch' */
  const real32_T Divide[2];            /* '<S133>/Divide' */
  const real32_T Square;               /* '<S129>/Square' */
  const real32_T d;                    /* '<S129>/Multiply' */
  const real32_T Gain4;                /* '<S129>/Gain4' */
  const real32_T Square_n;             /* '<S217>/Square' */
  const real32_T d_j;                  /* '<S217>/Multiply' */
  const real32_T Gain4_c;              /* '<S217>/Gain4' */
  const real32_T VectorConcatenate3_k[3];/* '<S302>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S252>/Math Function' */
  const real32_T SumofElements_p;      /* '<S252>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S252>/Math Function1' */
  const real32_T Product_c[2];         /* '<S252>/Product' */
  const real32_T Switch_h[3];          /* '<S252>/Switch' */
  const real32_T Divide_d[2];          /* '<S252>/Divide' */
  const real32_T Square_k;             /* '<S248>/Square' */
  const real32_T d_l;                  /* '<S248>/Multiply' */
  const real32_T Gain4_n;              /* '<S248>/Gain4' */
  const real32_T Square_l;             /* '<S283>/Square' */
  const real32_T d_n;                  /* '<S283>/Multiply' */
  const real32_T Gain4_a;              /* '<S283>/Gain4' */
  const real32_T VectorConcatenate3_g[3];/* '<S279>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_f[3];/* '<S235>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S310>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S23>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S23>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S23>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S28>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S28>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S28>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S27>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S27>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S27>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S29>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S29>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S29>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S26>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S26>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S26>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S116>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S116>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S116>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_a;  /* '<S113>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S113>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S189>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S189>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S189>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S191>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S191>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S191>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S190>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S190>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_ml;/* '<S190>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S192>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S192>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S192>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S20>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S20>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S19>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S19>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S17>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S21>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S22>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S24>/Unknown' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S197>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S262>/Move Control' */
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
extern struct_iFzoGS6ezHkwxeSA09xa0B FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S313>/Constant'
                                                *   '<S19>/Constant6'
                                                *   '<S20>/Constant6'
                                                *   '<S191>/L1'
                                                *   '<S33>/Gain'
                                                *   '<S35>/Gain'
                                                *   '<S36>/Gain1'
                                                *   '<S54>/Gain'
                                                *   '<S56>/Gain1'
                                                *   '<S100>/Gain'
                                                *   '<S100>/Gain1'
                                                *   '<S101>/Gain1'
                                                *   '<S116>/L1'
                                                *   '<S231>/Saturation1'
                                                *   '<S304>/Gain2'
                                                *   '<S304>/Saturation1'
                                                *   '<S37>/Saturation1'
                                                *   '<S48>/Dead Zone'
                                                *   '<S48>/Gain'
                                                *   '<S51>/Dead Zone'
                                                *   '<S51>/Gain'
                                                *   '<S58>/Saturation1'
                                                *   '<S69>/Dead Zone'
                                                *   '<S69>/Gain'
                                                *   '<S72>/Saturation1'
                                                *   '<S103>/Dead Zone'
                                                *   '<S103>/Gain'
                                                *   '<S104>/Dead Zone'
                                                *   '<S104>/Gain'
                                                *   '<S109>/Dead Zone'
                                                *   '<S109>/Gain'
                                                *   '<S197>/Saturation1'
                                                *   '<S207>/Saturation'
                                                *   '<S232>/Gain2'
                                                *   '<S254>/vel'
                                                *   '<S254>/Saturation'
                                                *   '<S254>/Switch'
                                                *   '<S40>/Gain2'
                                                *   '<S41>/Gain1'
                                                *   '<S46>/Constant'
                                                *   '<S61>/Gain2'
                                                *   '<S62>/Gain1'
                                                *   '<S67>/Constant'
                                                *   '<S75>/L1'
                                                *   '<S76>/Gain6'
                                                *   '<S96>/Constant'
                                                *   '<S135>/Gain'
                                                *   '<S135>/Saturation1'
                                                *   '<S136>/vel'
                                                *   '<S136>/Saturation'
                                                *   '<S136>/Switch'
                                                *   '<S200>/Gain2'
                                                *   '<S201>/Gain1'
                                                *   '<S210>/Gain2'
                                                *   '<S211>/Gain1'
                                                *   '<S241>/Gain2'
                                                *   '<S241>/Saturation'
                                                *   '<S242>/Integrator'
                                                *   '<S43>/Dead Zone'
                                                *   '<S43>/Gain'
                                                *   '<S64>/Dead Zone'
                                                *   '<S64>/Gain'
                                                *   '<S93>/Dead Zone'
                                                *   '<S93>/Gain'
                                                *   '<S122>/Gain2'
                                                *   '<S122>/Saturation'
                                                *   '<S123>/Integrator'
                                                *   '<S203>/Dead Zone'
                                                *   '<S203>/Gain'
                                                *   '<S215>/Dead Zone'
                                                *   '<S215>/Gain'
                                                *   '<S262>/Saturation1'
                                                *   '<S272>/Saturation1'
                                                *   '<S265>/Gain2'
                                                *   '<S266>/Gain1'
                                                *   '<S275>/Gain2'
                                                *   '<S276>/Gain6'
                                                *   '<S268>/Dead Zone'
                                                *   '<S268>/Gain'
                                                *   '<S280>/Dead Zone'
                                                *   '<S280>/Gain'
                                                *   '<S281>/Dead Zone'
                                                *   '<S281>/Gain'
                                                */
extern struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S5>/Constant1'
                                                 *   '<S311>/Constant'
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
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate' : Unused code path elimination
 * Block '<S296>/Data Type Duplicate' : Unused code path elimination
 * Block '<S297>/Data Type Duplicate' : Unused code path elimination
 * Block '<S293>/Data Type Duplicate' : Unused code path elimination
 * Block '<S294>/Data Type Duplicate' : Unused code path elimination
 * Block '<S300>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Reshape' : Reshape block reduction
 * Block '<S119>/Reshape' : Reshape block reduction
 * Block '<S119>/Reshape1' : Reshape block reduction
 * Block '<S119>/Reshape2' : Reshape block reduction
 * Block '<S190>/Reshape' : Reshape block reduction
 * Block '<S256>/Reshape' : Reshape block reduction
 * Block '<S238>/Reshape' : Reshape block reduction
 * Block '<S238>/Reshape1' : Reshape block reduction
 * Block '<S238>/Reshape2' : Reshape block reduction
 * Block '<S309>/Reshape' : Reshape block reduction
 * Block '<S311>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S16>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S312>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<S26>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S27>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S28>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S29>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S30>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S31>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S32>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Airspeed Command'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/DeadZone'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/TD/fhan '
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Airspeed Command'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/DeadZone'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/TD/fhan '
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/Compare To Zero'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/OutRegionRefWP'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/L1_Reference_WP/SearchL1RefWP'
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Modulus1'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Vector Normalize1'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/2D Cross Product'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Lateral_Acceleration/L1_Lateral_Acceleration/Included Angle/Vector Normalize1'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Path_Ray/Vector Normalize'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Psi To DCM/Rotation Matrix Z'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/DeadZone'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/TD/fhan '
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Manual/Manual_Cmd/throttle'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S311>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S312>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S313>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S314>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S315>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S316>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S317>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S318>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S319>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S320>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S321>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S322>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S323>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S324>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S325>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
