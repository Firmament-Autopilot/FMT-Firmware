/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1018
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 21 14:39:40 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FMS_h_
#define RTW_HEADER_FMS_h_
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

/* Block states (default storage) for system '<S130>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S133>/Delay' */
  uint8_T icLoad;                      /* '<S133>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S130>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S137>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S137>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S140>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S143>/Delay' */
  uint8_T icLoad;                      /* '<S143>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S140>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S149>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S149>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S152>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S155>/Delay' */
  uint8_T icLoad;                      /* '<S155>/Delay' */
} DW_HoldControl_FMS_f_T;

/* Block states (default storage) for system '<S152>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S162>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S162>/Integrator' */
} DW_MoveControl_FMS_k_T;

/* Block states (default storage) for system '<S107>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S107>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S107>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S107>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S26>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S26>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S26>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S26>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Cmd_In_Bus Cmd_In;                   /* '<Root>/FMS State Machine' */
  real32_T Merge[2];                   /* '<S82>/Merge' */
  real32_T Merge_k;                    /* '<S58>/Merge' */
  real32_T Merge_d;                    /* '<S69>/Merge' */
  real32_T Merge_l;                    /* '<S25>/Merge' */
  real32_T Merge_m;                    /* '<S42>/Merge' */
  real32_T Merge_j;                    /* '<S106>/Merge' */
  real32_T Merge_o[2];                 /* '<S152>/Merge' */
  real32_T Merge_e;                    /* '<S130>/Merge' */
  real32_T Merge_n;                    /* '<S140>/Merge' */
  VehicleMode VehicleMode_e;           /* '<Root>/FMS State Machine' */
  PilotMode DataTypeConversion1;       /* '<S1>/Data Type Conversion1' */
  FMS_Cmd DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  boolean_T LogicalOperator1;          /* '<S5>/Logical Operator1' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T valid_cmd;                    /* '<Root>/FMS State Machine' */
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_m[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_p;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S211>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S212>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S38>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S38>/Integrator' */
  real32_T Integrator1_DSTATE_o;       /* '<S39>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S39>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S102>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S102>/Integrator' */
  real32_T Integrator1_DSTATE_jt;      /* '<S103>/Integrator1' */
  real32_T Integrator_DSTATE_cq;       /* '<S103>/Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S170>/Delay' */
  real32_T l1_heading;                 /* '<S202>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S176>/Integrator1' */
  real32_T Integrator_DSTATE_bs;       /* '<S176>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S9>/Discrete-Time Integrator' */
  real32_T home[3];                    /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_d;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_e;/* '<Root>/FMS State Machine' */
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
  uint16_T temporalCounter_i1_i;       /* '<S83>/Motion State' */
  uint16_T temporalCounter_i1_a;       /* '<S153>/Motion State' */
  uint16_T temporalCounter_i1_n;       /* '<S131>/Motion Status' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S2>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S6>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S10>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S82>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_o; /* '<S58>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_j; /* '<S69>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S25>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_h; /* '<S42>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S106>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S13>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S152>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S130>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S140>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S211>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S212>/Discrete-Time Integrator5' */
  uint8_T is_active_c11_FMS;           /* '<Root>/FMS State Machine' */
  uint8_T is_Command_Listener;         /* '<Root>/FMS State Machine' */
  uint8_T is_active_Command_Listener;  /* '<Root>/FMS State Machine' */
  uint8_T is_Mode_Manager;             /* '<Root>/FMS State Machine' */
  uint8_T is_active_Mode_Manager;      /* '<Root>/FMS State Machine' */
  uint8_T is_Arm;                      /* '<Root>/FMS State Machine' */
  uint8_T is_SubMode;                  /* '<Root>/FMS State Machine' */
  uint8_T is_Auto;                     /* '<Root>/FMS State Machine' */
  uint8_T is_Assist;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Manual;                   /* '<Root>/FMS State Machine' */
  uint8_T is_Combo_Stick;              /* '<Root>/FMS State Machine' */
  uint8_T is_active_Combo_Stick;       /* '<Root>/FMS State Machine' */
  uint8_T is_active_c16_FMS;           /* '<S83>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S83>/Motion State' */
  uint8_T is_active_c22_FMS;           /* '<S153>/Motion State' */
  uint8_T is_c22_FMS;                  /* '<S153>/Motion State' */
  uint8_T is_active_c15_FMS;           /* '<S141>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S141>/Motion State' */
  uint8_T temporalCounter_i1_ai;       /* '<S141>/Motion State' */
  uint8_T is_active_c14_FMS;           /* '<S131>/Motion Status' */
  uint8_T is_c14_FMS;                  /* '<S131>/Motion Status' */
  uint8_T icLoad;                      /* '<S170>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S176>/Integrator1' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_o;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_g;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_om;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  DW_MoveControl_FMS_k_T MoveControl_k1;/* '<S82>/Move Control' */
  DW_HoldControl_FMS_f_T HoldControl_a;/* '<S82>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_j;/* '<S70>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_m;/* '<S69>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_e;/* '<S69>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_i;/* '<S59>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_be; /* '<S58>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_p;  /* '<S58>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_k;/* '<S43>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_c;/* '<S42>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_o;/* '<S42>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_b;/* '<S26>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_l;  /* '<S25>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S25>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_e;/* '<S107>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S106>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S106>/Hold Control' */
  DW_MoveControl_FMS_k_T MoveControl_i;/* '<S152>/Move Control' */
  DW_HoldControl_FMS_f_T HoldControl_f;/* '<S152>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S140>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_k;/* '<S140>/Hold Control' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S130>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S130>/Hold Control' */
} DW_FMS_T;

/* Invariant block signals for system '<S2>/Disarm' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S7>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S7>/Data Type Conversion1' */
} ConstB_Disarm_FMS_T;

/* Invariant block signals for system '<S130>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S138>/Square' */
  const real32_T d;                    /* '<S138>/Multiply' */
  const real32_T Gain4;                /* '<S138>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S140>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S150>/Square' */
  const real32_T d;                    /* '<S150>/Multiply' */
  const real32_T Gain4;                /* '<S150>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S152>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S159>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_k_T;

/* Invariant block signals for system '<S152>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S163>/Square' */
  const real32_T d;                    /* '<S163>/Multiply' */
  const real32_T Gain4;                /* '<S163>/Gain4' */
} ConstB_MoveControl_FMS_o_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Square;               /* '<S40>/Square' */
  const real32_T d;                    /* '<S40>/Multiply' */
  const real32_T Gain4;                /* '<S40>/Gain4' */
  const real32_T Square_d;             /* '<S41>/Square' */
  const real32_T d_c;                  /* '<S41>/Multiply' */
  const real32_T Gain4_m;              /* '<S41>/Gain4' */
  const real32_T Square_m;             /* '<S104>/Square' */
  const real32_T d_d;                  /* '<S104>/Multiply' */
  const real32_T Gain4_n;              /* '<S104>/Gain4' */
  const real32_T Square_n;             /* '<S105>/Square' */
  const real32_T d_o;                  /* '<S105>/Multiply' */
  const real32_T Gain4_n3;             /* '<S105>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S205>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S182>/Math Function' */
  const real32_T SumofElements;        /* '<S182>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S182>/Math Function1' */
  const real32_T Product[2];           /* '<S182>/Product' */
  const real32_T Switch[3];            /* '<S182>/Switch' */
  const real32_T Divide[2];            /* '<S182>/Divide' */
  const real32_T Square_k;             /* '<S180>/Square' */
  const real32_T d_l;                  /* '<S180>/Multiply' */
  const real32_T Gain4_np;             /* '<S180>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S169>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_fb[3];/* '<S209>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S12>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S12>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_b;  /* '<S17>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S17>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S17>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S16>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S16>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S16>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S18>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S18>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S18>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S15>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S15>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S15>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S119>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S119>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_a;  /* '<S120>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S120>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_g;  /* '<S122>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S122>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S122>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S124>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S124>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S124>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S123>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S123>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S123>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S125>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S125>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S125>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S8>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S8>/Data Type Conversion1' */
  ConstB_Disarm_FMS_T Unknown;         /* '<S6>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_i;       /* '<S10>/Unknown' */
  ConstB_MoveControl_FMS_o_T MoveControl_k1;/* '<S82>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_a;/* '<S82>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_m;/* '<S69>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_be;/* '<S58>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_c;/* '<S42>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_l;/* '<S25>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S106>/Move Control' */
  ConstB_Disarm_FMS_T Unknown_d;       /* '<S11>/Unknown' */
  ConstB_Disarm_FMS_T Unknown_g;       /* '<S13>/Unknown' */
  ConstB_MoveControl_FMS_o_T MoveControl_i;/* '<S152>/Move Control' */
  ConstB_HoldControl_FMS_k_T HoldControl_f;/* '<S152>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S140>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S130>/Move Control' */
  ConstB_Disarm_FMS_T Disarm;          /* '<S2>/Disarm' */
} ConstB_FMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Pilot_Cmd_Bus Pilot_Cmd;             /* '<Root>/Pilot_Cmd' */
  Auto_Cmd_Bus Auto_Cmd;               /* '<Root>/Auto_Cmd' */
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
                                                *   '<S23>/Gain'
                                                *   '<S23>/Gain1'
                                                *   '<S97>/Gain'
                                                *   '<S97>/Gain1'
                                                *   '<S165>/Saturation1'
                                                *   '<S206>/Gain2'
                                                *   '<S206>/Saturation1'
                                                *   '<S25>/Saturation1'
                                                *   '<S36>/Dead Zone'
                                                *   '<S36>/Gain'
                                                *   '<S37>/Dead Zone'
                                                *   '<S37>/Gain'
                                                *   '<S42>/Saturation'
                                                *   '<S58>/Saturation1'
                                                *   '<S69>/Saturation'
                                                *   '<S82>/Saturation1'
                                                *   '<S100>/Dead Zone'
                                                *   '<S100>/Gain'
                                                *   '<S101>/Dead Zone'
                                                *   '<S101>/Gain'
                                                *   '<S106>/Saturation'
                                                *   '<S130>/Saturation1'
                                                *   '<S140>/Saturation'
                                                *   '<S152>/Saturation1'
                                                *   '<S166>/Gain2'
                                                *   '<S28>/Gain2'
                                                *   '<S29>/Gain1'
                                                *   '<S34>/Constant'
                                                *   '<S45>/Gain2'
                                                *   '<S46>/Gain1'
                                                *   '<S53>/Constant'
                                                *   '<S61>/Gain2'
                                                *   '<S62>/Gain1'
                                                *   '<S67>/Constant'
                                                *   '<S72>/Gain2'
                                                *   '<S73>/Gain1'
                                                *   '<S80>/Constant'
                                                *   '<S85>/Gain2'
                                                *   '<S86>/Gain6'
                                                *   '<S94>/Constant'
                                                *   '<S95>/Constant'
                                                *   '<S109>/Gain2'
                                                *   '<S110>/Gain1'
                                                *   '<S117>/Constant'
                                                *   '<S133>/Gain2'
                                                *   '<S134>/Gain1'
                                                *   '<S143>/Gain2'
                                                *   '<S144>/Gain1'
                                                *   '<S155>/Gain2'
                                                *   '<S156>/Gain6'
                                                *   '<S175>/Gain2'
                                                *   '<S175>/Saturation'
                                                *   '<S176>/Integrator'
                                                *   '<S31>/Dead Zone'
                                                *   '<S31>/Gain'
                                                *   '<S50>/Dead Zone'
                                                *   '<S50>/Gain'
                                                *   '<S64>/Dead Zone'
                                                *   '<S64>/Gain'
                                                *   '<S77>/Dead Zone'
                                                *   '<S77>/Gain'
                                                *   '<S90>/Dead Zone'
                                                *   '<S90>/Gain'
                                                *   '<S91>/Dead Zone'
                                                *   '<S91>/Gain'
                                                *   '<S114>/Dead Zone'
                                                *   '<S114>/Gain'
                                                *   '<S136>/Dead Zone'
                                                *   '<S136>/Gain'
                                                *   '<S148>/Dead Zone'
                                                *   '<S148>/Gain'
                                                *   '<S160>/Dead Zone'
                                                *   '<S160>/Gain'
                                                *   '<S161>/Dead Zone'
                                                *   '<S161>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S9>/Constant'
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
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Reshape' : Reshape block reduction
 * Block '<S170>/Reshape' : Reshape block reduction
 * Block '<S170>/Reshape1' : Reshape block reduction
 * Block '<S170>/Reshape2' : Reshape block reduction
 * Block '<S185>/Reshape' : Reshape block reduction
 * Block '<S206>/Reshape' : Reshape block reduction
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S211>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'FMS/Bus Select'
 * '<S2>'   : 'FMS/FMS Commander'
 * '<S3>'   : 'FMS/FMS Input'
 * '<S4>'   : 'FMS/FMS State Machine'
 * '<S5>'   : 'FMS/Onground Check'
 * '<S6>'   : 'FMS/FMS Commander/Arm'
 * '<S7>'   : 'FMS/FMS Commander/Disarm'
 * '<S8>'   : 'FMS/FMS Commander/Standby'
 * '<S9>'   : 'FMS/FMS Commander/timestamp'
 * '<S10>'  : 'FMS/FMS Commander/Arm/Assist'
 * '<S11>'  : 'FMS/FMS Commander/Arm/Auto'
 * '<S12>'  : 'FMS/FMS Commander/Arm/Manual'
 * '<S13>'  : 'FMS/FMS Commander/Arm/SubMode'
 * '<S14>'  : 'FMS/FMS Commander/Arm/Unknown'
 * '<S15>'  : 'FMS/FMS Commander/Arm/Assist/Acro'
 * '<S16>'  : 'FMS/FMS Commander/Arm/Assist/Altitude'
 * '<S17>'  : 'FMS/FMS Commander/Arm/Assist/Position'
 * '<S18>'  : 'FMS/FMS Commander/Arm/Assist/Stabilize'
 * '<S19>'  : 'FMS/FMS Commander/Arm/Assist/Unknown'
 * '<S20>'  : 'FMS/FMS Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S21>'  : 'FMS/FMS Commander/Arm/Assist/Acro/Throttle Command'
 * '<S22>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S23>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S24>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command'
 * '<S25>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S26>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S27>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Brake Control'
 * '<S28>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S29>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S30>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S31>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S32>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1'
 * '<S33>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S34>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S35>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S36>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S37>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S38>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S39>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S40>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S41>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S42>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S43>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S44>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Brake Control'
 * '<S45>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S46>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S47>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S48>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S49>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S50>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S51>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S52>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S53>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S54>'  : 'FMS/FMS Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S55>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command'
 * '<S56>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command'
 * '<S57>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command'
 * '<S58>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S59>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S60>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Brake Control'
 * '<S61>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S62>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S63>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S64>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S65>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1'
 * '<S66>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S67>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S68>'  : 'FMS/FMS Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S69>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S70>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S71>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Brake Control'
 * '<S72>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S73>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S74>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S75>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S76>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S77>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S78>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S79>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S80>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S81>'  : 'FMS/FMS Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S82>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S83>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S84>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Brake Control'
 * '<S85>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S86>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S87>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S88>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S89>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S90>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S91>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S92>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S93>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S94>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S95>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S96>'  : 'FMS/FMS Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S97>'  : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S98>'  : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S99>'  : 'FMS/FMS Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S100>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S101>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S102>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S103>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S104>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S105>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S106>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S107>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S108>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Brake Control'
 * '<S109>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S110>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S111>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S112>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S113>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S114>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S115>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S116>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S117>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S118>' : 'FMS/FMS Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S119>' : 'FMS/FMS Commander/Arm/Auto/Mission'
 * '<S120>' : 'FMS/FMS Commander/Arm/Auto/Offboard'
 * '<S121>' : 'FMS/FMS Commander/Arm/Auto/Unknown'
 * '<S122>' : 'FMS/FMS Commander/Arm/SubMode/Hold'
 * '<S123>' : 'FMS/FMS Commander/Arm/SubMode/Land'
 * '<S124>' : 'FMS/FMS Commander/Arm/SubMode/Return'
 * '<S125>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff'
 * '<S126>' : 'FMS/FMS Commander/Arm/SubMode/Unknown'
 * '<S127>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command'
 * '<S128>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command'
 * '<S129>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command'
 * '<S130>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller'
 * '<S131>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Detect Movement'
 * '<S132>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Brake Control'
 * '<S133>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Hold Control'
 * '<S134>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Move Control'
 * '<S135>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S136>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Move Control/DeadZone'
 * '<S137>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Move Control/TD1'
 * '<S138>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Controller/Move Control/TD1/fhan '
 * '<S139>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Altitude Command/Detect Movement/Motion Status'
 * '<S140>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller'
 * '<S141>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Detect Movement'
 * '<S142>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Brake Control'
 * '<S143>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Hold Control'
 * '<S144>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Move Control'
 * '<S145>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S146>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S147>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S148>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Move Control/DeadZone'
 * '<S149>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Move Control/TD'
 * '<S150>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Controller/Move Control/TD/fhan '
 * '<S151>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Heading Command/Detect Movement/Motion State'
 * '<S152>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller'
 * '<S153>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Detect Movement'
 * '<S154>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Brake Control'
 * '<S155>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Hold Control'
 * '<S156>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Move Control'
 * '<S157>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S158>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S159>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S160>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Move Control/DeadZone'
 * '<S161>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Move Control/DeadZone1'
 * '<S162>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Move Control/TD'
 * '<S163>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Controller/Move Control/TD/fhan '
 * '<S164>' : 'FMS/FMS Commander/Arm/SubMode/Hold/Position Command/Detect Movement/Motion State'
 * '<S165>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command'
 * '<S166>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S167>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S168>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S169>' : 'FMS/FMS Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S170>' : 'FMS/FMS Commander/Arm/SubMode/Return/Coordinate Points'
 * '<S171>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander'
 * '<S172>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S173>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S174>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S175>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S176>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S177>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S178>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_err_saturation'
 * '<S179>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_err_saturation/Compare To Constant'
 * '<S180>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S181>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S182>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S183>' : 'FMS/FMS Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S184>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S185>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S186>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S187>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S188>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S189>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S190>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S191>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S192>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S193>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S194>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S195>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S196>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S197>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S198>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S199>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S200>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S201>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S202>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S203>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S204>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S205>' : 'FMS/FMS Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S206>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position'
 * '<S207>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Bus_Selection'
 * '<S208>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Psi To DCM'
 * '<S209>' : 'FMS/FMS Commander/Arm/SubMode/Takeoff/Hold Position/Psi To DCM/Rotation Matrix Z'
 * '<S210>' : 'FMS/Onground Check/Compare To Constant'
 * '<S211>' : 'FMS/Onground Check/First Order LPF'
 * '<S212>' : 'FMS/Onground Check/First Order LPF2'
 * '<S213>' : 'FMS/Onground Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
