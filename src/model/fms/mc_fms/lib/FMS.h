/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2338
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jul 20 15:54:09 2026
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

/* Block states (default storage) for system '<S482>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S485>/Delay' */
  uint8_T icLoad;                      /* '<S485>/Delay' */
} DW_HoldControl_FMS_T;

/* Block states (default storage) for system '<S482>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S489>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S489>/Integrator' */
} DW_MoveControl_FMS_T;

/* Block states (default storage) for system '<S483>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S483>/Motion Status' */
  uint8_T is_active_c10_FMS;           /* '<S483>/Motion Status' */
  uint8_T is_c10_FMS;                  /* '<S483>/Motion Status' */
} DW_MotionStatus_FMS_T;

/* Block states (default storage) for system '<S492>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S495>/Delay' */
  uint8_T icLoad;                      /* '<S495>/Delay' */
} DW_HoldControl_FMS_j_T;

/* Block states (default storage) for system '<S492>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S502>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S502>/Integrator' */
} DW_MoveControl_FMS_f_T;

/* Block states (default storage) for system '<S493>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S493>/Motion State' */
  uint8_T is_active_c23_FMS;           /* '<S493>/Motion State' */
  uint8_T is_c23_FMS;                  /* '<S493>/Motion State' */
} DW_MotionState_FMS_T;

/* Block states (default storage) for system '<S412>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S415>/Delay' */
  uint8_T icLoad;                      /* '<S415>/Delay' */
} DW_HoldControl_FMS_g_T;

/* Block states (default storage) for system '<S412>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE;         /* '<S421>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S421>/Integrator' */
} DW_MoveControl_FMS_c_T;

/* Block states (default storage) for system '<S141>/Motion State' */
typedef struct {
  uint8_T is_active_c19_FMS;           /* '<S141>/Motion State' */
  uint8_T is_c19_FMS;                  /* '<S141>/Motion State' */
  uint8_T temporalCounter_i1;          /* '<S141>/Motion State' */
} DW_MotionState_FMS_g_T;

/* Block states (default storage) for system '<S54>/Motion Status' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S54>/Motion Status' */
  uint8_T is_active_c17_FMS;           /* '<S54>/Motion Status' */
  uint8_T is_c17_FMS;                  /* '<S54>/Motion Status' */
} DW_MotionStatus_FMS_a_T;

/* Block states (default storage) for system '<S111>/Hold Control' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S113>/Delay' */
  uint8_T icLoad;                      /* '<S113>/Delay' */
} DW_HoldControl_FMS_a_T;

/* Block states (default storage) for system '<S111>/Move Control' */
typedef struct {
  real32_T Integrator1_DSTATE[2];      /* '<S121>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S121>/Integrator' */
} DW_MoveControl_FMS_j_T;

/* Block states (default storage) for system '<S112>/Motion State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S112>/Motion State' */
  uint8_T is_active_c16_FMS;           /* '<S112>/Motion State' */
  uint8_T is_c16_FMS;                  /* '<S112>/Motion State' */
} DW_MotionState_FMS_c_T;

/* Block signals (default storage) */
typedef struct {
  INS_Out_Bus BusConversion_InsertedFor_FMSSt;
  Pilot_Cmd_Bus BusConversion_InsertedFor_FMS_f;
  Pilot_Cmd_Bus pilot_cmd;             /* '<Root>/FMS State Machine' */
  Commander_In_Bus Cmd_In;             /* '<Root>/FMS State Machine' */
  real_T degrade;                      /* '<Root>/SafeMode' */
  real_T stick_val[4];                 /* '<Root>/FMS State Machine' */
  real_T lla[3];                       /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T href;                         /* '<Root>/FMS State Machine' */
  real_T psio;                         /* '<Root>/FMS State Machine' */
  uint32_T Add;                        /* '<S540>/Add' */
  real32_T xy_R[2];                    /* '<Root>/FMS State Machine' */
  real32_T DataTypeConversion[3];      /* '<S542>/Data Type Conversion' */
  real32_T Reshape[3];                 /* '<S543>/Reshape' */
  real32_T Merge[2];                   /* '<S181>/Merge' */
  real32_T Merge_a;                    /* '<S155>/Merge' */
  real32_T Merge_l;                    /* '<S169>/Merge' */
  real32_T Merge_p[2];                 /* '<S111>/Merge' */
  real32_T Merge_ld;                   /* '<S88>/Merge' */
  real32_T Merge_e;                    /* '<S99>/Merge' */
  real32_T Merge_lf;                   /* '<S53>/Merge' */
  real32_T Merge_h;                    /* '<S73>/Merge' */
  real32_T Merge_j;                    /* '<S140>/Merge' */
  real32_T Merge_n[2];                 /* '<S249>/Merge' */
  real32_T Merge_e3;                   /* '<S239>/Merge' */
  real32_T Merge_o[2];                 /* '<S424>/Merge' */
  real32_T Merge_ey;                   /* '<S402>/Merge' */
  real32_T Merge_n1;                   /* '<S412>/Merge' */
  real32_T Merge_ah[2];                /* '<S492>/Merge' */
  real32_T Merge_jj;                   /* '<S482>/Merge' */
  VehicleState state;                  /* '<Root>/FMS State Machine' */
  PilotMode target_mode;               /* '<Root>/SafeMode' */
  FMS_Cmd Switch1;                     /* '<S15>/Switch1' */
  uint8_T wp_consume;                  /* '<Root>/FMS State Machine' */
  uint8_T wp_index;                    /* '<Root>/FMS State Machine' */
  boolean_T LogicalOperator;           /* '<S9>/Logical Operator' */
  boolean_T LogicalOperator2;          /* '<S3>/Logical Operator2' */
  boolean_T Compare;                   /* '<S30>/Compare' */
  boolean_T on_ground;                 /* '<S7>/Logical Operator1' */
  boolean_T LogicalOperator_c;         /* '<S1>/Logical Operator' */
  boolean_T Compare_k;                 /* '<S555>/Compare' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T prep_takeoff;                 /* '<Root>/FMS State Machine' */
  real_T llo[2];                       /* '<Root>/FMS State Machine' */
  real_T prep_mission_takeoff;         /* '<Root>/FMS State Machine' */
  Msg_FMS_Cmd Msg_FMS_Cmd_i[11];       /* '<Root>/FMS State Machine' */
  Queue_FMS_Cmd Queue_FMS_Cmd_b;       /* '<Root>/FMS State Machine' */
  void* M_msgInterface;                /* '<Root>/FMS State Machine' */
  void* M_msgHandle;                   /* '<Root>/FMS State Machine' */
  void* M_msgDataPtr;                  /* '<Root>/FMS State Machine' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S556>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_d;/* '<S558>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S557>/Discrete-Time Integrator5' */
  real32_T Delay_DSTATE;               /* '<S159>/Delay' */
  real32_T Integrator1_DSTATE;         /* '<S165>/Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S165>/Integrator' */
  real32_T Integrator1_DSTATE_n;       /* '<S67>/Integrator1' */
  real32_T Integrator_DSTATE_c;        /* '<S67>/Integrator' */
  real32_T Integrator1_DSTATE_i;       /* '<S68>/Integrator1' */
  real32_T Integrator_DSTATE_g;        /* '<S68>/Integrator' */
  real32_T Integrator1_DSTATE_k;       /* '<S134>/Integrator1' */
  real32_T Integrator_DSTATE_a;        /* '<S134>/Integrator' */
  real32_T Integrator1_DSTATE_nf;      /* '<S135>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S135>/Integrator' */
  real32_T Delay_DSTATE_c[2];          /* '<S228>/Delay' */
  real32_T Acceleration_Speed_DSTATE;  /* '<S224>/Acceleration_Speed' */
  real32_T l1_heading;                 /* '<S278>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S206>/Delay' */
  real32_T Integrator1_DSTATE_p;       /* '<S209>/Integrator1' */
  real32_T Integrator_DSTATE_i;        /* '<S209>/Integrator' */
  real32_T Delay_DSTATE_e[2];          /* '<S471>/Delay' */
  real32_T Acceleration_Speed_DSTATE_j;/* '<S467>/Acceleration_Speed' */
  real32_T l1_heading_e;               /* '<S521>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_a;             /* '<S449>/Delay' */
  real32_T Integrator1_DSTATE_e;       /* '<S452>/Integrator1' */
  real32_T Delay_DSTATE_p[2];          /* '<S448>/Delay' */
  real32_T Integrator_DSTATE_bs;       /* '<S452>/Integrator' */
  real32_T Integrator1_DSTATE_j;       /* '<S440>/Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S440>/Integrator' */
  real32_T cur_waypoint_DSTATE[3];     /* '<S538>/cur_waypoint' */
  real32_T Integrator1_DSTATE_a;       /* '<S534>/Integrator1' */
  real32_T Integrator_DSTATE_m;        /* '<S534>/Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S18>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S14>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE_f;       /* '<S25>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_j;       /* '<S568>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S9>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S20>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_p;       /* '<S21>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S26>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S27>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S11>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S1>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S541>/Discrete-Time Integrator' */
  PilotMode Delay_DSTATE_cn;           /* '<S16>/Delay' */
  real32_T home[4];                    /* '<Root>/Data Store Memory' */
  real32_T stick_val[4];               /* '<Root>/FMS State Machine' */
  int32_T sfEvent;                     /* '<Root>/FMS State Machine' */
  int32_T chartAbsoluteTimeCounter;    /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_k;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2; /* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_n5;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_1_b;/* '<Root>/FMS State Machine' */
  int32_T durationLastReferenceTick_2_n;/* '<Root>/FMS State Machine' */
  int32_T M_qId;                       /* '<Root>/FMS State Machine' */
  uint32_T flag_prev;                  /* '<Root>/SafeMode' */
  uint32_T flag_start;                 /* '<Root>/SafeMode' */
  uint32_T temporalCounter_i1;         /* '<Root>/FMS State Machine' */
  uint32_T mission_timestamp_prev;     /* '<Root>/FMS State Machine' */
  uint32_T mission_timestamp_start;    /* '<Root>/FMS State Machine' */
  FMS_Cmd M;                           /* '<Root>/FMS State Machine' */
  FMS_Cmd save_cmd;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_prev;                    /* '<Root>/FMS State Machine' */
  FMS_Cmd cmd_start;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgData;                   /* '<Root>/FMS State Machine' */
  FMS_Cmd M_msgReservedData;           /* '<Root>/FMS State Machine' */
  PilotMode mode_prev;                 /* '<Root>/SafeMode' */
  PilotMode mode_start;                /* '<Root>/SafeMode' */
  PilotMode mode_prev_n;               /* '<Root>/FMS State Machine' */
  PilotMode mode_start_a;              /* '<Root>/FMS State Machine' */
  uint16_T nav_cmd;                    /* '<Root>/FMS State Machine' */
  uint16_T temporalCounter_i1_j;       /* '<S156>/Motion Status' */
  uint8_T Delay_DSTATE_o;              /* '<S569>/Delay' */
  uint8_T Delay_DSTATE_oi;             /* '<S12>/Delay' */
  uint8_T DelayInput1_DSTATE_pe;       /* '<S201>/Delay Input1' */
  uint8_T DiscreteTimeIntegrator_DSTATE_k;/* '<S229>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_DSTAT_mx;/* '<S472>/Discrete-Time Integrator' */
  boolean_T Delay1_DSTATE;             /* '<S228>/Delay1' */
  boolean_T Delay1_DSTATE_b;           /* '<S471>/Delay1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S31>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_b; /* '<S33>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_f; /* '<S37>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_n; /* '<S181>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fi;/* '<S155>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_l; /* '<S169>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_a; /* '<S88>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_lm;/* '<S111>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bu;/* '<S99>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_m; /* '<S53>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_mn;/* '<S73>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_fs;/* '<S140>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_i; /* '<S38>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetSta;/* '<S224>/Acceleration_Speed' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S278>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem_ai;/* '<S249>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_e; /* '<S239>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_at;/* '<S40>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S424>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_pp;/* '<S402>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_bn;/* '<S412>/Switch Case' */
  int8_T Acceleration_Speed_PrevResetS_j;/* '<S467>/Acceleration_Speed' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S521>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem_g; /* '<S492>/Switch Case' */
  int8_T SwitchCase_ActiveSubsystem_ld;/* '<S482>/Switch Case' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S556>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_a;/* '<S558>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S557>/Discrete-Time Integrator5' */
  uint8_T is_active_c1_FMS;            /* '<Root>/SafeMode' */
  uint8_T is_Mode;                     /* '<Root>/SafeMode' */
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
  uint8_T is_active_c12_FMS;           /* '<S156>/Motion Status' */
  uint8_T is_c12_FMS;                  /* '<S156>/Motion Status' */
  uint8_T icLoad;                      /* '<S159>/Delay' */
  uint8_T icLoad_h;                    /* '<S228>/Delay' */
  uint8_T icLoad_k;                    /* '<S206>/Delay' */
  uint8_T Integrator1_IC_LOADING;      /* '<S209>/Integrator1' */
  uint8_T is_active_c15_FMS;           /* '<S413>/Motion State' */
  uint8_T is_c15_FMS;                  /* '<S413>/Motion State' */
  uint8_T temporalCounter_i1_a;        /* '<S413>/Motion State' */
  uint8_T icLoad_l;                    /* '<S471>/Delay' */
  uint8_T icLoad_j;                    /* '<S449>/Delay' */
  uint8_T Integrator1_IC_LOADING_j;    /* '<S452>/Integrator1' */
  uint8_T icLoad_c;                    /* '<S448>/Delay' */
  uint8_T icLoad_j1;                   /* '<S538>/cur_waypoint' */
  boolean_T valid_cmd;                 /* '<Root>/FMS State Machine' */
  boolean_T bl;                        /* '<Root>/FMS State Machine' */
  boolean_T br;                        /* '<Root>/FMS State Machine' */
  boolean_T M_isValid;                 /* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_k;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_b;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_1_h0;/* '<Root>/FMS State Machine' */
  boolean_T condWasTrueAtLastTimeStep_2_b;/* '<Root>/FMS State Machine' */
  DW_MotionState_FMS_c_T sf_MotionState_ej;/* '<S182>/Motion State' */
  DW_MoveControl_FMS_j_T MoveControl_mz;/* '<S181>/Move Control' */
  DW_HoldControl_FMS_a_T HoldControl_nn;/* '<S181>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_k;/* '<S170>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_nm;/* '<S169>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_ha;/* '<S169>/Hold Control' */
  DW_HoldControl_FMS_T HoldControl_l;  /* '<S155>/Hold Control' */
  DW_MotionState_FMS_c_T sf_MotionState_a;/* '<S112>/Motion State' */
  DW_MoveControl_FMS_j_T MoveControl_k1;/* '<S111>/Move Control' */
  DW_HoldControl_FMS_a_T HoldControl_at;/* '<S111>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_l;/* '<S100>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_m1;/* '<S99>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h2;/* '<S99>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_h;/* '<S89>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_c;  /* '<S88>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_b;/* '<S74>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_o;/* '<S73>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_hb;/* '<S73>/Hold Control' */
  DW_MotionStatus_FMS_a_T sf_MotionStatus_b;/* '<S54>/Motion Status' */
  DW_HoldControl_FMS_T HoldControl_k2; /* '<S53>/Hold Control' */
  DW_MotionState_FMS_g_T sf_MotionState_e;/* '<S141>/Motion State' */
  DW_MoveControl_FMS_c_T MoveControl_k;/* '<S140>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_h;/* '<S140>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_n;/* '<S250>/Motion State' */
  DW_MoveControl_FMS_f_T MoveControl_c;/* '<S249>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_d;/* '<S249>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_jt;/* '<S240>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_m;  /* '<S239>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_a;  /* '<S239>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState_g;/* '<S425>/Motion State' */
  DW_MoveControl_FMS_f_T MoveControl_i;/* '<S424>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_f;/* '<S424>/Hold Control' */
  DW_MoveControl_FMS_c_T MoveControl_b;/* '<S412>/Move Control' */
  DW_HoldControl_FMS_g_T HoldControl_k;/* '<S412>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus_j;/* '<S403>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl_n;  /* '<S402>/Move Control' */
  DW_HoldControl_FMS_T HoldControl_n;  /* '<S402>/Hold Control' */
  DW_MotionState_FMS_T sf_MotionState; /* '<S493>/Motion State' */
  DW_MoveControl_FMS_f_T MoveControl_j;/* '<S492>/Move Control' */
  DW_HoldControl_FMS_j_T HoldControl_m;/* '<S492>/Hold Control' */
  DW_MotionStatus_FMS_T sf_MotionStatus;/* '<S483>/Motion Status' */
  DW_MoveControl_FMS_T MoveControl;    /* '<S482>/Move Control' */
  DW_HoldControl_FMS_T HoldControl;    /* '<S482>/Hold Control' */
} DW_FMS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Mission_SubSystem_Reset_ZCE;/* '<S198>/Mission_SubSystem' */
  ZCSigState Delay_Reset_ZCE;          /* '<S228>/Delay' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S471>/Delay' */
  ZCSigState SetHome_Trig_ZCE;         /* '<S15>/SetHome' */
} PrevZCX_FMS_T;

/* Invariant block signals for system '<S482>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S490>/Square' */
  const real32_T d;                    /* '<S490>/Multiply' */
  const real32_T Gain4;                /* '<S490>/Gain4' */
} ConstB_MoveControl_FMS_T;

/* Invariant block signals for system '<S492>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S499>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_f_T;

/* Invariant block signals for system '<S492>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S503>/Square' */
  const real32_T d;                    /* '<S503>/Multiply' */
  const real32_T Gain4;                /* '<S503>/Gain4' */
} ConstB_MoveControl_FMS_i_T;

/* Invariant block signals for system '<S412>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S422>/Square' */
  const real32_T d;                    /* '<S422>/Multiply' */
  const real32_T Gain4;                /* '<S422>/Gain4' */
} ConstB_MoveControl_FMS_f_T;

/* Invariant block signals for system '<S40>/Unknown' */
typedef struct {
  const uint8_T DataTypeConversion;    /* '<S398>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S398>/Data Type Conversion1' */
} ConstB_Unknown_FMS_T;

/* Invariant block signals for system '<S111>/Hold Control' */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S117>/Vector Concatenate3' */
} ConstB_HoldControl_FMS_i_T;

/* Invariant block signals for system '<S111>/Move Control' */
typedef struct {
  const real32_T Square;               /* '<S124>/Square' */
} ConstB_MoveControl_FMS_b_T;

/* Invariant block signals for system '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
typedef struct {
  const real_T Sum;                    /* '<S546>/Sum' */
  const real_T ff;                     /* '<S546>/Multiply3' */
  const real_T Sum4;                   /* '<S546>/Sum4' */
} ConstB_VehicleArmAutoMissionL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S375>/Sum' */
  const real_T ff;                     /* '<S375>/Multiply3' */
  const real_T Sum4;                   /* '<S375>/Sum4' */
  const real_T deg2rad2;               /* '<S374>/deg2rad2' */
  const real_T SinCos_o1;              /* '<S377>/SinCos' */
  const real_T SinCos_o2;              /* '<S377>/SinCos' */
  const real32_T Square;               /* '<S166>/Square' */
  const real32_T Square_m;             /* '<S71>/Square' */
  const real32_T Square_i;             /* '<S72>/Square' */
  const real32_T Square_c;             /* '<S138>/Square' */
  const real32_T Square_b;             /* '<S139>/Square' */
  const real32_T VectorConcatenate3[3];/* '<S285>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMathFu[2];
  const real32_T MathFunction[2];      /* '<S219>/Math Function' */
  const real32_T SumofElements;        /* '<S219>/Sum of Elements' */
  const real32_T MathFunction1;        /* '<S219>/Math Function1' */
  const real32_T Product[2];           /* '<S219>/Product' */
  const real32_T Switch[3];            /* '<S219>/Switch' */
  const real32_T Divide[2];            /* '<S219>/Divide' */
  const real32_T Square_g;             /* '<S215>/Square' */
  const real32_T d;                    /* '<S215>/Multiply' */
  const real32_T Gain4;                /* '<S215>/Gain4' */
  const real32_T VectorConcatenate3_n[3];/* '<S361>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_i[3];/* '<S365>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S369>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_ny[3];/* '<S368>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e1[3];/* '<S298>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S300>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S391>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_iz[3];/* '<S393>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_c[3];/* '<S528>/Vector Concatenate3' */
  const real32_T TmpSignalConversionAtMath_a[2];
  const real32_T MathFunction_n[2];    /* '<S462>/Math Function' */
  const real32_T SumofElements_p;      /* '<S462>/Sum of Elements' */
  const real32_T MathFunction1_m;      /* '<S462>/Math Function1' */
  const real32_T Product_c[2];         /* '<S462>/Product' */
  const real32_T Switch_h[3];          /* '<S462>/Switch' */
  const real32_T Divide_d[2];          /* '<S462>/Divide' */
  const real32_T Square_k;             /* '<S458>/Square' */
  const real32_T d_l;                  /* '<S458>/Multiply' */
  const real32_T Gain4_n;              /* '<S458>/Gain4' */
  const real32_T VectorConcatenate3_f[3];/* '<S445>/Vector Concatenate3' */
  const real32_T Square_e;             /* '<S441>/Square' */
  const real32_T d_p;                  /* '<S441>/Multiply' */
  const real32_T Gain4_e;              /* '<S441>/Gain4' */
  const real32_T VectorConcatenate3_fb[3];/* '<S539>/Vector Concatenate3' */
  const real32_T Square_bz;            /* '<S535>/Square' */
  const real32_T d_m;                  /* '<S535>/Multiply' */
  const real32_T Gain4_a;              /* '<S535>/Gain4' */
  const uint8_T DataTypeConversion;    /* '<S39>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S39>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_a;  /* '<S46>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_i; /* '<S46>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S46>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_b;  /* '<S44>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_o; /* '<S44>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_m; /* '<S44>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_d; /* '<S43>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_n; /* '<S43>/Data Type Conversion2' */
  const uint8_T DataTypeConversion3;   /* '<S43>/Data Type Conversion3' */
  const uint8_T DataTypeConversion_ba; /* '<S45>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_k; /* '<S45>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_o; /* '<S45>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_j;  /* '<S42>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_do;/* '<S42>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_b; /* '<S42>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_l;  /* '<S202>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_b; /* '<S202>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_by;/* '<S202>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_an; /* '<S199>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_n; /* '<S199>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_k; /* '<S199>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_g;  /* '<S394>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_ie;/* '<S394>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_j; /* '<S394>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_o;  /* '<S396>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_m; /* '<S396>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_p; /* '<S396>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_c;  /* '<S395>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_h; /* '<S395>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_ml;/* '<S395>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_ld; /* '<S397>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_dh;/* '<S397>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_d; /* '<S397>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_h; /* '<S36>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_f; /* '<S36>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_m;  /* '<S35>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_a; /* '<S35>/Data Type Conversion1' */
  ConstB_VehicleArmAutoMissionL_T VehicleArmAutoMissionLLA2FLAT;/* '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  ConstB_Unknown_FMS_T Unknown;        /* '<S33>/Unknown' */
  ConstB_Unknown_FMS_T Unknown_i;      /* '<S37>/Unknown' */
  ConstB_MoveControl_FMS_b_T MoveControl_mz;/* '<S181>/Move Control' */
  ConstB_HoldControl_FMS_i_T HoldControl_nn;/* '<S181>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_nm;/* '<S169>/Move Control' */
  ConstB_MoveControl_FMS_b_T MoveControl_k1;/* '<S111>/Move Control' */
  ConstB_HoldControl_FMS_i_T HoldControl_at;/* '<S111>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_m1;/* '<S99>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_o;/* '<S73>/Move Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_k;/* '<S140>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_d;      /* '<S38>/Unknown' */
  ConstB_MoveControl_FMS_i_T MoveControl_c;/* '<S249>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_d;/* '<S249>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl_m;/* '<S239>/Move Control' */
  ConstB_Unknown_FMS_T Unknown_g;      /* '<S40>/Unknown' */
  ConstB_MoveControl_FMS_i_T MoveControl_i;/* '<S424>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_f;/* '<S424>/Hold Control' */
  ConstB_MoveControl_FMS_f_T MoveControl_b;/* '<S412>/Move Control' */
  ConstB_MoveControl_FMS_T MoveControl_n;/* '<S402>/Move Control' */
  ConstB_MoveControl_FMS_i_T MoveControl_j;/* '<S492>/Move Control' */
  ConstB_HoldControl_FMS_f_T HoldControl_m;/* '<S492>/Hold Control' */
  ConstB_MoveControl_FMS_T MoveControl;/* '<S482>/Move Control' */
} ConstB_FMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Pilot_Cmd_Bus Pilot_Cmd;             /* '<Root>/Pilot_Cmd' */
  GCS_Cmd_Bus GCS_Cmd;                 /* '<Root>/GCS_Cmd' */
  Auto_Cmd_Bus Auto_Cmd;               /* '<Root>/Auto_Cmd' */
  Mission_Data_Bus Mission_Data;       /* '<Root>/Mission_Data' */
  Terrain_Info_Bus Terrain_Info;       /* '<Root>/Terrain_Info' */
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
extern struct_xXeuwAPh0ajaUfdgPpGaUB FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<Root>/ACCEPT_R'
                                                *   '<S3>/Constant1'
                                                *   '<S7>/Land_Lock_Thro'
                                                *   '<S29>/Constant'
                                                *   '<S543>/Constant'
                                                *   '<S396>/L1'
                                                *   '<S51>/Gain'
                                                *   '<S51>/Gain1'
                                                *   '<S128>/Gain'
                                                *   '<S128>/Gain1'
                                                *   '<S130>/Constant'
                                                *   '<S202>/L1'
                                                *   '<S289>/Saturation'
                                                *   '<S290>/Saturation1'
                                                *   '<S290>/Saturation2'
                                                *   '<S290>/Saturation3'
                                                *   '<S437>/Land_Speed'
                                                *   '<S438>/Saturation1'
                                                *   '<S530>/Takeoff_Speed'
                                                *   '<S531>/Gain2'
                                                *   '<S531>/Saturation1'
                                                *   '<S53>/Saturation1'
                                                *   '<S65>/Dead Zone'
                                                *   '<S65>/Gain'
                                                *   '<S66>/Dead Zone'
                                                *   '<S66>/Gain'
                                                *   '<S67>/Constant'
                                                *   '<S68>/Constant'
                                                *   '<S73>/Saturation'
                                                *   '<S88>/Saturation1'
                                                *   '<S99>/Saturation'
                                                *   '<S111>/Saturation1'
                                                *   '<S132>/Dead Zone'
                                                *   '<S132>/Gain'
                                                *   '<S133>/Dead Zone'
                                                *   '<S133>/Gain'
                                                *   '<S134>/Constant'
                                                *   '<S135>/Constant'
                                                *   '<S140>/Saturation'
                                                *   '<S155>/Saturation1'
                                                *   '<S169>/Saturation'
                                                *   '<S181>/Saturation1'
                                                *   '<S345>/Gain2'
                                                *   '<S352>/Gain1'
                                                *   '<S352>/Gain2'
                                                *   '<S402>/Saturation1'
                                                *   '<S412>/Saturation'
                                                *   '<S424>/Saturation1'
                                                *   '<S439>/Constant'
                                                *   '<S442>/Gain2'
                                                *   '<S464>/Gain'
                                                *   '<S464>/Saturation1'
                                                *   '<S467>/Constant'
                                                *   '<S467>/vel'
                                                *   '<S467>/Switch'
                                                *   '<S55>/Gain2'
                                                *   '<S56>/Gain1'
                                                *   '<S62>/Constant'
                                                *   '<S75>/Gain2'
                                                *   '<S76>/Gain1'
                                                *   '<S83>/Constant'
                                                *   '<S90>/Gain2'
                                                *   '<S91>/Gain1'
                                                *   '<S97>/Constant'
                                                *   '<S101>/Gain2'
                                                *   '<S102>/Gain1'
                                                *   '<S109>/Constant'
                                                *   '<S113>/Gain2'
                                                *   '<S114>/Gain6'
                                                *   '<S125>/Constant'
                                                *   '<S126>/Constant'
                                                *   '<S142>/Gain2'
                                                *   '<S143>/Gain1'
                                                *   '<S150>/Constant'
                                                *   '<S157>/Gain2'
                                                *   '<S158>/Gain1'
                                                *   '<S159>/Gain2'
                                                *   '<S167>/Constant'
                                                *   '<S171>/Gain2'
                                                *   '<S172>/Gain1'
                                                *   '<S179>/Constant'
                                                *   '<S183>/Gain2'
                                                *   '<S184>/Gain6'
                                                *   '<S195>/Constant'
                                                *   '<S196>/Constant'
                                                *   '<S221>/Gain'
                                                *   '<S221>/Saturation1'
                                                *   '<S224>/Constant'
                                                *   '<S224>/vel'
                                                *   '<S224>/Switch'
                                                *   '<S405>/Gain2'
                                                *   '<S406>/Gain1'
                                                *   '<S415>/Gain2'
                                                *   '<S416>/Gain1'
                                                *   '<S427>/Gain2'
                                                *   '<S428>/Gain6'
                                                *   '<S451>/Gain2'
                                                *   '<S451>/Saturation'
                                                *   '<S452>/Integrator'
                                                *   '<S58>/Land_Speed'
                                                *   '<S59>/Constant'
                                                *   '<S61>/Dead Zone'
                                                *   '<S61>/Gain'
                                                *   '<S80>/Dead Zone'
                                                *   '<S80>/Gain'
                                                *   '<S93>/Land_Speed'
                                                *   '<S94>/Constant'
                                                *   '<S96>/Dead Zone'
                                                *   '<S96>/Gain'
                                                *   '<S106>/Dead Zone'
                                                *   '<S106>/Gain'
                                                *   '<S119>/Dead Zone'
                                                *   '<S119>/Gain'
                                                *   '<S120>/Dead Zone'
                                                *   '<S120>/Gain'
                                                *   '<S121>/Constant'
                                                *   '<S147>/Dead Zone'
                                                *   '<S147>/Gain'
                                                *   '<S161>/Land_Speed'
                                                *   '<S162>/Constant'
                                                *   '<S164>/Dead Zone'
                                                *   '<S164>/Gain'
                                                *   '<S165>/Constant'
                                                *   '<S176>/Dead Zone'
                                                *   '<S176>/Gain'
                                                *   '<S189>/Dead Zone'
                                                *   '<S189>/Gain'
                                                *   '<S190>/Dead Zone'
                                                *   '<S190>/Gain'
                                                *   '<S191>/Constant'
                                                *   '<S208>/Gain2'
                                                *   '<S208>/Saturation'
                                                *   '<S209>/Integrator'
                                                *   '<S408>/Dead Zone'
                                                *   '<S408>/Gain'
                                                *   '<S420>/Dead Zone'
                                                *   '<S420>/Gain'
                                                *   '<S432>/Dead Zone'
                                                *   '<S432>/Gain'
                                                *   '<S433>/Dead Zone'
                                                *   '<S433>/Gain'
                                                *   '<S482>/Saturation1'
                                                *   '<S492>/Saturation1'
                                                *   '<S239>/Saturation1'
                                                *   '<S249>/Saturation1'
                                                *   '<S485>/Gain2'
                                                *   '<S486>/Gain1'
                                                *   '<S495>/Gain2'
                                                *   '<S496>/Gain6'
                                                *   '<S242>/Gain2'
                                                *   '<S243>/Gain1'
                                                *   '<S252>/Gain2'
                                                *   '<S253>/Gain6'
                                                *   '<S488>/Dead Zone'
                                                *   '<S488>/Gain'
                                                *   '<S500>/Dead Zone'
                                                *   '<S500>/Gain'
                                                *   '<S501>/Dead Zone'
                                                *   '<S501>/Gain'
                                                *   '<S245>/Dead Zone'
                                                *   '<S245>/Gain'
                                                *   '<S257>/Dead Zone'
                                                *   '<S257>/Gain'
                                                *   '<S258>/Dead Zone'
                                                *   '<S258>/Gain'
                                                */
extern struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by:
                                                 *   '<S1>/Constant'
                                                 *   '<S9>/Constant'
                                                 *   '<S14>/Constant1'
                                                 *   '<S541>/Constant'
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
 * Block '<S13>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Propagation' : Unused code path elimination
 * Block '<S235>/Data Type Duplicate' : Unused code path elimination
 * Block '<S235>/Data Type Propagation' : Unused code path elimination
 * Block '<S273>/Data Type Duplicate' : Unused code path elimination
 * Block '<S274>/Data Type Duplicate' : Unused code path elimination
 * Block '<S270>/Data Type Duplicate' : Unused code path elimination
 * Block '<S271>/Data Type Duplicate' : Unused code path elimination
 * Block '<S280>/Data Type Duplicate' : Unused code path elimination
 * Block '<S282>/Data Type Duplicate' : Unused code path elimination
 * Block '<S283>/Data Type Duplicate' : Unused code path elimination
 * Block '<S279>/Data Type Duplicate' : Unused code path elimination
 * Block '<S279>/Data Type Propagation' : Unused code path elimination
 * Block '<S462>/Data Type Duplicate' : Unused code path elimination
 * Block '<S463>/Data Type Duplicate' : Unused code path elimination
 * Block '<S477>/Data Type Duplicate' : Unused code path elimination
 * Block '<S477>/Data Type Propagation' : Unused code path elimination
 * Block '<S478>/Data Type Duplicate' : Unused code path elimination
 * Block '<S478>/Data Type Propagation' : Unused code path elimination
 * Block '<S516>/Data Type Duplicate' : Unused code path elimination
 * Block '<S517>/Data Type Duplicate' : Unused code path elimination
 * Block '<S513>/Data Type Duplicate' : Unused code path elimination
 * Block '<S514>/Data Type Duplicate' : Unused code path elimination
 * Block '<S523>/Data Type Duplicate' : Unused code path elimination
 * Block '<S525>/Data Type Duplicate' : Unused code path elimination
 * Block '<S526>/Data Type Duplicate' : Unused code path elimination
 * Block '<S522>/Data Type Duplicate' : Unused code path elimination
 * Block '<S522>/Data Type Propagation' : Unused code path elimination
 * Block '<S559>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Reshape' : Reshape block reduction
 * Block '<S205>/Reshape' : Reshape block reduction
 * Block '<S205>/Reshape1' : Reshape block reduction
 * Block '<S205>/Reshape2' : Reshape block reduction
 * Block '<S469>/Reshape' : Reshape block reduction
 * Block '<S448>/Reshape' : Reshape block reduction
 * Block '<S448>/Reshape1' : Reshape block reduction
 * Block '<S448>/Reshape2' : Reshape block reduction
 * Block '<S538>/Reshape' : Reshape block reduction
 * Block '<S541>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S32>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S32>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S32>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S542>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S556>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S557>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'FMS/Command Process'
 * '<S3>'   : 'FMS/Detect_Lost_Connect'
 * '<S4>'   : 'FMS/Error_Check'
 * '<S5>'   : 'FMS/FMS Commander'
 * '<S6>'   : 'FMS/FMS State Machine'
 * '<S7>'   : 'FMS/Onground Check'
 * '<S8>'   : 'FMS/SafeMode'
 * '<S9>'   : 'FMS/Terrain_Info_Valid'
 * '<S10>'  : 'FMS/Auto_Cmd_Valid/Compare To Constant4'
 * '<S11>'  : 'FMS/Auto_Cmd_Valid/Detect Change'
 * '<S12>'  : 'FMS/Auto_Cmd_Valid/Ever_Valid'
 * '<S13>'  : 'FMS/Auto_Cmd_Valid/Interval Test'
 * '<S14>'  : 'FMS/Command Process/Check Valid'
 * '<S15>'  : 'FMS/Command Process/Command PreProcess'
 * '<S16>'  : 'FMS/Command Process/Mode PreProcess'
 * '<S17>'  : 'FMS/Command Process/Check Valid/Compare To Constant1'
 * '<S18>'  : 'FMS/Command Process/Check Valid/Detect Change1'
 * '<S19>'  : 'FMS/Command Process/Command PreProcess/Compare To Constant'
 * '<S20>'  : 'FMS/Command Process/Command PreProcess/Detect Change3'
 * '<S21>'  : 'FMS/Command Process/Command PreProcess/Detect Change4'
 * '<S22>'  : 'FMS/Command Process/Command PreProcess/SetHome'
 * '<S23>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero'
 * '<S24>'  : 'FMS/Command Process/Mode PreProcess/Compare To Zero1'
 * '<S25>'  : 'FMS/Command Process/Mode PreProcess/Detect Change'
 * '<S26>'  : 'FMS/Detect_Lost_Connect/Detect Change'
 * '<S27>'  : 'FMS/Detect_Lost_Connect/Detect Change1'
 * '<S28>'  : 'FMS/Detect_Lost_Connect/Error_Check'
 * '<S29>'  : 'FMS/Detect_Lost_Connect/timeout1_s'
 * '<S30>'  : 'FMS/Detect_Lost_Connect/timeout2_s'
 * '<S31>'  : 'FMS/FMS Commander/Commander'
 * '<S32>'  : 'FMS/FMS Commander/FMS_Input'
 * '<S33>'  : 'FMS/FMS Commander/Commander/Arm'
 * '<S34>'  : 'FMS/FMS Commander/Commander/Bus_Constructor'
 * '<S35>'  : 'FMS/FMS Commander/Commander/Disarm'
 * '<S36>'  : 'FMS/FMS Commander/Commander/Standby'
 * '<S37>'  : 'FMS/FMS Commander/Commander/Arm/Assist'
 * '<S38>'  : 'FMS/FMS Commander/Commander/Arm/Auto'
 * '<S39>'  : 'FMS/FMS Commander/Commander/Arm/Manual'
 * '<S40>'  : 'FMS/FMS Commander/Commander/Arm/SubMode'
 * '<S41>'  : 'FMS/FMS Commander/Commander/Arm/Unknown'
 * '<S42>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro'
 * '<S43>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude'
 * '<S44>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position'
 * '<S45>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize'
 * '<S46>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain'
 * '<S47>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Unknown'
 * '<S48>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Angular Rate Command'
 * '<S49>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Acro/Throttle Command'
 * '<S50>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command'
 * '<S51>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command'
 * '<S52>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command'
 * '<S53>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller'
 * '<S54>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement'
 * '<S55>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control'
 * '<S56>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control'
 * '<S57>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S58>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Assist Land Speed'
 * '<S59>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S60>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S61>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Controller/Move Control/DeadZone'
 * '<S62>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Compare To Constant'
 * '<S63>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Altitude Command/Detect Movement/Motion Status'
 * '<S64>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Compare To Constant'
 * '<S65>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone'
 * '<S66>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/DeadZone2'
 * '<S67>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD'
 * '<S68>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD'
 * '<S69>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Vector Modulus'
 * '<S70>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Vector Normalize'
 * '<S71>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Phi_CMD_TD/fhan '
 * '<S72>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Attitude Command/Theta_CMD_TD/fhan '
 * '<S73>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller'
 * '<S74>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement'
 * '<S75>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control'
 * '<S76>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control'
 * '<S77>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S78>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S79>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S80>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/DeadZone'
 * '<S81>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD'
 * '<S82>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Controller/Move Control/TD/fhan '
 * '<S83>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Compare To Constant'
 * '<S84>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Altitude/Heading Command/Detect Movement/Motion State'
 * '<S85>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command'
 * '<S86>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command'
 * '<S87>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command'
 * '<S88>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller'
 * '<S89>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement'
 * '<S90>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control'
 * '<S91>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control'
 * '<S92>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S93>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Assist Land Speed'
 * '<S94>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S95>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S96>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Controller/Move Control/DeadZone'
 * '<S97>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Compare To Constant'
 * '<S98>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Altitude Command/Detect Movement/Motion Status'
 * '<S99>'  : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller'
 * '<S100>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement'
 * '<S101>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control'
 * '<S102>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control'
 * '<S103>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S104>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S105>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S106>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/DeadZone'
 * '<S107>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD'
 * '<S108>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Controller/Move Control/TD/fhan '
 * '<S109>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Compare To Constant'
 * '<S110>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Heading Command/Detect Movement/Motion State'
 * '<S111>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller'
 * '<S112>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement'
 * '<S113>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control'
 * '<S114>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control'
 * '<S115>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S116>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S117>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S118>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/Compare To Constant'
 * '<S119>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone'
 * '<S120>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/DeadZone1'
 * '<S121>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD'
 * '<S122>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/Vector Modulus'
 * '<S123>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/Vector Normalize'
 * '<S124>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Controller/Move Control/TD/fhan '
 * '<S125>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant'
 * '<S126>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Compare To Constant1'
 * '<S127>' : 'FMS/FMS Commander/Commander/Arm/Assist/Position/Position Command/Detect Movement/Motion State'
 * '<S128>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command'
 * '<S129>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command'
 * '<S130>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Throttle Command'
 * '<S131>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Compare To Constant'
 * '<S132>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone'
 * '<S133>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/DeadZone2'
 * '<S134>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD'
 * '<S135>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD'
 * '<S136>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Vector Modulus'
 * '<S137>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Vector Normalize'
 * '<S138>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Phi_CMD_TD/fhan '
 * '<S139>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Attitude Command/Theta_CMD_TD/fhan '
 * '<S140>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller'
 * '<S141>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement'
 * '<S142>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control'
 * '<S143>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control'
 * '<S144>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S145>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S146>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S147>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/DeadZone'
 * '<S148>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD'
 * '<S149>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Controller/Move Control/TD/fhan '
 * '<S150>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Compare To Constant'
 * '<S151>' : 'FMS/FMS Commander/Commander/Arm/Assist/Stabilize/Heading Command/Detect Movement/Motion State'
 * '<S152>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command'
 * '<S153>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command'
 * '<S154>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command'
 * '<S155>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller'
 * '<S156>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Detect Movement'
 * '<S157>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Hold Control'
 * '<S158>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Move Control'
 * '<S159>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Terrain Control'
 * '<S160>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Hold Control/Bus_Selection'
 * '<S161>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Move Control/Assist Land Speed'
 * '<S162>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Move Control/Compare To Constant'
 * '<S163>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Move Control/Compare To Constant1'
 * '<S164>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Move Control/DeadZone'
 * '<S165>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Terrain Control/TD'
 * '<S166>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Controller/Terrain Control/TD/fhan '
 * '<S167>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Detect Movement/Compare To Constant'
 * '<S168>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Altitude Command/Detect Movement/Motion Status'
 * '<S169>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller'
 * '<S170>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Detect Movement'
 * '<S171>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Hold Control'
 * '<S172>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Move Control'
 * '<S173>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Hold Control/Bus_Selection'
 * '<S174>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Hold Control/psi_err_saturation'
 * '<S175>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S176>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Move Control/DeadZone'
 * '<S177>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Move Control/TD'
 * '<S178>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Controller/Move Control/TD/fhan '
 * '<S179>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Detect Movement/Compare To Constant'
 * '<S180>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Heading Command/Detect Movement/Motion State'
 * '<S181>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller'
 * '<S182>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Detect Movement'
 * '<S183>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Hold Control'
 * '<S184>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control'
 * '<S185>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Hold Control/Bus_Selection'
 * '<S186>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Hold Control/Psi To DCM'
 * '<S187>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S188>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/Compare To Constant'
 * '<S189>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/DeadZone'
 * '<S190>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/DeadZone1'
 * '<S191>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/TD'
 * '<S192>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/Vector Modulus'
 * '<S193>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/Vector Normalize'
 * '<S194>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Controller/Move Control/TD/fhan '
 * '<S195>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Detect Movement/Compare To Constant'
 * '<S196>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Detect Movement/Compare To Constant1'
 * '<S197>' : 'FMS/FMS Commander/Commander/Arm/Assist/Terrain/Position Command/Detect Movement/Motion State'
 * '<S198>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission'
 * '<S199>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard'
 * '<S200>' : 'FMS/FMS Commander/Commander/Arm/Auto/Unknown'
 * '<S201>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Detect Change'
 * '<S202>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem'
 * '<S203>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander'
 * '<S204>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander'
 * '<S205>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Way Points'
 * '<S206>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control'
 * '<S207>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle'
 * '<S208>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control'
 * '<S209>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD'
 * '<S210>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation'
 * '<S211>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1'
 * '<S212>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S213>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S214>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S215>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/TD/fhan '
 * '<S216>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S217>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S218>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/2D Cross Product'
 * '<S219>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize'
 * '<S220>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Heading Commander/Included Angle/Vector Normalize1'
 * '<S221>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control'
 * '<S222>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Constant'
 * '<S223>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Compare To Zero'
 * '<S224>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed '
 * '<S225>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position'
 * '<S226>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP'
 * '<S227>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration'
 * '<S228>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed'
 * '<S229>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter'
 * '<S230>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height'
 * '<S231>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S232>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S233>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Compare To Zero'
 * '<S234>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic'
 * '<S235>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Saturation Dynamic1'
 * '<S236>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S237>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold'
 * '<S238>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold'
 * '<S239>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S240>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S241>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S242>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S243>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S244>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S245>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S246>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S247>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S248>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S249>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S250>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S251>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S252>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S253>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S254>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S255>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S256>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S257>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S258>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S259>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S260>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S261>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S262>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S263>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S264>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S265>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S266>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S267>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S268>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S269>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S270>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S271>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S272>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S273>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S274>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S275>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Compare To Constant'
 * '<S276>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S277>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Included Angle'
 * '<S278>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S279>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Saturation Dynamic'
 * '<S280>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S281>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Included Angle/Cross Product'
 * '<S282>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Included Angle/Vector Normalize'
 * '<S283>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Included Angle/Vector Normalize1'
 * '<S284>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S285>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S286>' : 'FMS/FMS Commander/Commander/Arm/Auto/Mission/Mission_SubSystem/Velocity Commander/ValidCounter/Compare To Constant'
 * '<S287>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command'
 * '<S288>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask'
 * '<S289>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command'
 * '<S290>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command'
 * '<S291>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Accel_Command'
 * '<S292>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Body_FRD'
 * '<S293>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask'
 * '<S294>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Local_NED'
 * '<S295>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_FRD'
 * '<S296>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Command_Mask/Compare To Zero2'
 * '<S297>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Local_NED/Psi To DCM'
 * '<S298>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Global_Local_NED/Psi To DCM/Rotation Matrix Z'
 * '<S299>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_FRD/Psi To DCM2'
 * '<S300>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Acc_Command/Local_FRD/Psi To DCM2/Rotation Matrix Z'
 * '<S301>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero'
 * '<S302>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero1'
 * '<S303>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero12'
 * '<S304>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero2'
 * '<S305>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero3'
 * '<S306>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero4'
 * '<S307>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Compare To Zero5'
 * '<S308>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem'
 * '<S309>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1'
 * '<S310>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid'
 * '<S311>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid'
 * '<S312>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid'
 * '<S313>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid'
 * '<S314>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid'
 * '<S315>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid'
 * '<S316>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid'
 * '<S317>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid'
 * '<S318>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid'
 * '<S319>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid'
 * '<S320>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid'
 * '<S321>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid'
 * '<S322>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid'
 * '<S323>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Constant'
 * '<S324>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero1'
 * '<S325>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero6'
 * '<S326>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero7'
 * '<S327>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem/Compare To Zero8'
 * '<S328>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Constant'
 * '<S329>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero10'
 * '<S330>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero11'
 * '<S331>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/Subsystem1/Compare To Zero9'
 * '<S332>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ax_cmd_valid/bit_shift'
 * '<S333>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/ay_cmd_valid/bit_shift'
 * '<S334>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/az_cmd_valid/bit_shift'
 * '<S335>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/p_cmd_valid/bit_shift'
 * '<S336>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/phi_cmd_valid/bit_shift'
 * '<S337>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/psi_rate_cmd_valid/bit_shift'
 * '<S338>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/q_cmd_valid/bit_shift'
 * '<S339>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/r_cmd_valid/bit_shift'
 * '<S340>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/theta_cmd_valid/bit_shift'
 * '<S341>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/throttle_cmd_valid/bit_shift'
 * '<S342>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/u_cmd_valid/bit_shift'
 * '<S343>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/v_cmd_valid/bit_shift'
 * '<S344>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Command_Mask/w_cmd_valid/bit_shift'
 * '<S345>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control'
 * '<S346>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command'
 * '<S347>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Compare To Zero'
 * '<S348>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error'
 * '<S349>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation'
 * '<S350>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Heading_Control/Error/psi_err_saturation/Compare To Constant'
 * '<S351>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Heading_Command/Psi_Rate_Command/Compare To Zero1'
 * '<S352>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control'
 * '<S353>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command'
 * '<S354>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_FRD'
 * '<S355>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask'
 * '<S356>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Local_NED'
 * '<S357>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD'
 * '<S358>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command'
 * '<S359>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_State'
 * '<S360>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_FRD/Psi To DCM1'
 * '<S361>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Body_FRD/Psi To DCM1/Rotation Matrix Z'
 * '<S362>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero'
 * '<S363>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Command_Mask/Compare To Zero1'
 * '<S364>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Local_NED/Psi To DCM'
 * '<S365>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Global_Local_NED/Psi To DCM/Rotation Matrix Z'
 * '<S366>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM1'
 * '<S367>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM2'
 * '<S368>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM1/Rotation Matrix Z'
 * '<S369>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Local_FRD/Psi To DCM2/Rotation Matrix Z'
 * '<S370>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask'
 * '<S371>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command'
 * '<S372>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Local_Position_Command'
 * '<S373>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Command_Mask/Compare To Zero'
 * '<S374>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT'
 * '<S375>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LAT2FLAT Curve'
 * '<S376>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap'
 * '<S377>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/Rotation'
 * '<S378>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S379>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S380>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S381>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S382>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S383>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Position_Control/Position_Command/Global_Position_Command/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S384>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Body_FRD'
 * '<S385>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask'
 * '<S386>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Local_NED'
 * '<S387>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_FRD'
 * '<S388>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Velocity_Command'
 * '<S389>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Command_Mask/Compare To Zero2'
 * '<S390>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Local_NED/Psi To DCM'
 * '<S391>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Global_Local_NED/Psi To DCM/Rotation Matrix Z'
 * '<S392>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_FRD/Psi To DCM2'
 * '<S393>' : 'FMS/FMS Commander/Commander/Arm/Auto/Offboard/Velocity_Command/Velocity_Command/Local_FRD/Psi To DCM2/Rotation Matrix Z'
 * '<S394>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold'
 * '<S395>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land'
 * '<S396>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return'
 * '<S397>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff'
 * '<S398>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Unknown'
 * '<S399>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold'
 * '<S400>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold'
 * '<S401>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold'
 * '<S402>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller'
 * '<S403>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement'
 * '<S404>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Brake Control'
 * '<S405>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control'
 * '<S406>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control'
 * '<S407>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S408>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S409>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1'
 * '<S410>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S411>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Altitude Hold/Detect Movement/Motion Status'
 * '<S412>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller'
 * '<S413>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement'
 * '<S414>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Brake Control'
 * '<S415>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control'
 * '<S416>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control'
 * '<S417>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/Bus_Selection'
 * '<S418>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation'
 * '<S419>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Hold Control/psi_err_saturation/Compare To Constant'
 * '<S420>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/DeadZone'
 * '<S421>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD'
 * '<S422>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Controller/Move Control/TD/fhan '
 * '<S423>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Heading Hold/Detect Movement/Motion State'
 * '<S424>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller'
 * '<S425>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement'
 * '<S426>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Brake Control'
 * '<S427>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control'
 * '<S428>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control'
 * '<S429>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S430>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S431>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S432>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone'
 * '<S433>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/DeadZone1'
 * '<S434>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD'
 * '<S435>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Controller/Move Control/TD/fhan '
 * '<S436>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Hold/Position Hold/Detect Movement/Motion State'
 * '<S437>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed'
 * '<S438>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command'
 * '<S439>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/Compare To Constant'
 * '<S440>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD'
 * '<S441>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Assist Land Speed/TD/fhan '
 * '<S442>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control'
 * '<S443>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Bus_Selection'
 * '<S444>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM'
 * '<S445>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Land/Position Command/Position Control/Psi To DCM/Rotation Matrix Z'
 * '<S446>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander'
 * '<S447>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander'
 * '<S448>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Way Points'
 * '<S449>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control'
 * '<S450>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle'
 * '<S451>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control'
 * '<S452>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD'
 * '<S453>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation'
 * '<S454>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1'
 * '<S455>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/Bus_Selection'
 * '<S456>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation'
 * '<S457>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/Heading Control/psi_saturation/Compare To Constant'
 * '<S458>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/TD/fhan '
 * '<S459>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation/Compare To Constant'
 * '<S460>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Heading Control/psi_saturation1/Compare To Constant'
 * '<S461>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/2D Cross Product'
 * '<S462>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize'
 * '<S463>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Heading Commander/Included Angle/Vector Normalize1'
 * '<S464>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Altitude Control'
 * '<S465>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Compare To Constant'
 * '<S466>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Compare To Zero'
 * '<S467>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed '
 * '<S468>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position'
 * '<S469>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP'
 * '<S470>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration'
 * '<S471>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed'
 * '<S472>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/ValidCounter'
 * '<S473>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Altitude Control/Target Height'
 * '<S474>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Altitude Control/Target Height/Vector Modulus'
 * '<S475>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Altitude Control/Target Height/Vector Modulus1'
 * '<S476>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Compare To Zero'
 * '<S477>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Saturation Dynamic'
 * '<S478>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Saturation Dynamic1'
 * '<S479>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Cruise Speed /Vector Modulus'
 * '<S480>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold'
 * '<S481>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold'
 * '<S482>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller'
 * '<S483>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement'
 * '<S484>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Brake Control'
 * '<S485>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control'
 * '<S486>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control'
 * '<S487>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Hold Control/Bus_Selection'
 * '<S488>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/DeadZone'
 * '<S489>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1'
 * '<S490>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Controller/Move Control/TD1/fhan '
 * '<S491>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Altitude Hold/Detect Movement/Motion Status'
 * '<S492>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller'
 * '<S493>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement'
 * '<S494>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Brake Control'
 * '<S495>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control'
 * '<S496>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control'
 * '<S497>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Bus_Selection'
 * '<S498>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM'
 * '<S499>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Hold Control/Psi To DCM/Rotation Matrix Z'
 * '<S500>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone'
 * '<S501>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/DeadZone1'
 * '<S502>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD'
 * '<S503>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Controller/Move Control/TD/fhan '
 * '<S504>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Hold Position/Position Hold/Detect Movement/Motion State'
 * '<S505>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant'
 * '<S506>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/Compare To Constant1'
 * '<S507>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/NearbyRefWP'
 * '<S508>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/OutRegionRegWP'
 * '<S509>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/L1 Reference WP/SearchL1RefWP'
 * '<S510>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle'
 * '<S511>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus'
 * '<S512>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Modulus1'
 * '<S513>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize'
 * '<S514>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Vector Normalize1'
 * '<S515>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/2D Cross Product'
 * '<S516>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize'
 * '<S517>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration/Included Angle/Vector Normalize1'
 * '<S518>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Compare To Constant'
 * '<S519>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed'
 * '<S520>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Included Angle'
 * '<S521>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix'
 * '<S522>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Saturation Dynamic'
 * '<S523>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Ground Speed/Vector Normalize2'
 * '<S524>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Included Angle/Cross Product'
 * '<S525>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Included Angle/Vector Normalize'
 * '<S526>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Included Angle/Vector Normalize1'
 * '<S527>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM'
 * '<S528>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/Lateral Acceleration To Speed/Rotation Matrix/Psi To DCM/Rotation Matrix Z'
 * '<S529>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Return/Velocity Commander/ValidCounter/Compare To Constant'
 * '<S530>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed'
 * '<S531>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position'
 * '<S532>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant'
 * '<S533>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/Compare To Constant1'
 * '<S534>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD'
 * '<S535>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Climb Speed/TD/fhan '
 * '<S536>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Bus_Selection'
 * '<S537>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM'
 * '<S538>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Target Position'
 * '<S539>' : 'FMS/FMS Commander/Commander/Arm/SubMode/Takeoff/Track Position/Psi To DCM/Rotation Matrix Z'
 * '<S540>' : 'FMS/FMS Commander/Commander/Bus_Constructor/Collect_Errors'
 * '<S541>' : 'FMS/FMS Commander/Commander/Bus_Constructor/timestamp'
 * '<S542>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT'
 * '<S543>' : 'FMS/FMS State Machine/Vehicle.PrepTakeoff'
 * '<S544>' : 'FMS/FMS State Machine/Vehicle.StickMoved'
 * '<S545>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT'
 * '<S546>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LAT2FLAT Curve'
 * '<S547>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap'
 * '<S548>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/Rotation'
 * '<S549>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180'
 * '<S550>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude'
 * '<S551>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Weap Angle 180/Compare To Constant1'
 * '<S552>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Compare To Constant1'
 * '<S553>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180'
 * '<S554>' : 'FMS/FMS State Machine/Vehicle.Arm.Auto.Mission.LLA2FLAT/LLA2FLAT/LatLon Wrap/Wrap Latitude/Weap Angle 180/Compare To Constant1'
 * '<S555>' : 'FMS/FMS State Machine/Vehicle.StickMoved/Compare To Constant'
 * '<S556>' : 'FMS/Onground Check/First Order LPF'
 * '<S557>' : 'FMS/Onground Check/First Order LPF1'
 * '<S558>' : 'FMS/Onground Check/First Order LPF2'
 * '<S559>' : 'FMS/Onground Check/Interval Test'
 * '<S560>' : 'FMS/Onground Check/Quaternion To DCM'
 * '<S561>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize'
 * '<S562>' : 'FMS/Onground Check/Quaternion To DCM/column_1'
 * '<S563>' : 'FMS/Onground Check/Quaternion To DCM/column_2'
 * '<S564>' : 'FMS/Onground Check/Quaternion To DCM/column_3'
 * '<S565>' : 'FMS/Onground Check/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S566>' : 'FMS/Terrain_Info_Valid/Compare To Constant4'
 * '<S567>' : 'FMS/Terrain_Info_Valid/Compare To Zero'
 * '<S568>' : 'FMS/Terrain_Info_Valid/Detect Change'
 * '<S569>' : 'FMS/Terrain_Info_Valid/Ever_Valid'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
