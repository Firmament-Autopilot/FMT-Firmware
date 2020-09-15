/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.710
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 08:38:14 2020
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

/* Block states (default storage) for system '<S78>/Motion_State' */
typedef struct {
  uint8_T is_active_c5_FMS;            /* '<S78>/Motion_State' */
  uint8_T is_c5_FMS;                   /* '<S78>/Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S78>/Motion_State' */
} DW_Motion_State_FMS_T;

/* Block states (default storage) for system '<S95>/Z_Motion_State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S95>/Z_Motion_State' */
  uint8_T is_active_c8_FMS;            /* '<S95>/Z_Motion_State' */
  uint8_T is_c8_FMS;                   /* '<S95>/Z_Motion_State' */
} DW_Z_Motion_State_FMS_T;

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S129>/Disarm_Event' */
  real_T arm_event;                    /* '<S129>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Mode_Logic' */
  uint16_T PWM_Cmd;                    /* '<S3>/State_Logic' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S140>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S58>/Integrator1' */
  real32_T Integrator1_DSTATE_n;       /* '<S59>/Integrator1' */
  real32_T Delay_DSTATE;               /* '<S73>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S59>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S58>/Integrator' */
  real32_T Integrator1_DSTATE_f;       /* '<S17>/Integrator1' */
  real32_T Integrator1_DSTATE_a;       /* '<S18>/Integrator1' */
  real32_T Integrator1_DSTATE_p;       /* '<S44>/Integrator1' */
  real32_T Delay_DSTATE_p;             /* '<S32>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S49>/Delay' */
  real32_T Integrator_DSTATE_g;        /* '<S44>/Integrator' */
  real32_T Integrator_DSTATE_b;        /* '<S18>/Integrator' */
  real32_T Integrator_DSTATE_gx;       /* '<S17>/Integrator' */
  real32_T Delay_DSTATE_pp[2];         /* '<S111>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S112>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S91>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S134>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Mode_Logic' */
  uint16_T temporalCounter_i1;         /* '<S3>/State_Logic' */
  uint16_T temporalCounter_i1_a;       /* '<S129>/Disarm_Event' */
  uint16_T temporalCounter_i1_b;       /* '<S95>/XY_Motion_State' */
  uint8_T Delay_DSTATE_pi;             /* '<S3>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S128>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S65>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i;      /* '<S64>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S24>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S23>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S48>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_iu;     /* '<S109>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pv;     /* '<S110>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S83>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S82>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c4_FMS;            /* '<S3>/State_Logic' */
  uint8_T is_c4_FMS;                   /* '<S3>/State_Logic' */
  uint8_T is_active_c10_FMS;           /* '<S129>/Disarm_Event' */
  uint8_T is_c10_FMS;                  /* '<S129>/Disarm_Event' */
  uint8_T is_active_c3_FMS;            /* '<S129>/Arm_Event' */
  uint8_T is_c3_FMS;                   /* '<S129>/Arm_Event' */
  uint8_T icLoad;                      /* '<S73>/Delay' */
  uint8_T icLoad_i;                    /* '<S32>/Delay' */
  uint8_T icLoad_d;                    /* '<S49>/Delay' */
  uint8_T icLoad_f;                    /* '<S111>/Delay' */
  uint8_T icLoad_a;                    /* '<S112>/Delay' */
  uint8_T icLoad_o;                    /* '<S91>/Delay' */
  uint8_T is_active_c7_FMS;            /* '<S95>/XY_Motion_State' */
  uint8_T is_c7_FMS;                   /* '<S95>/XY_Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Mode_Logic' */
  uint8_T is_c1_FMS;                   /* '<S1>/Mode_Logic' */
  DW_Motion_State_FMS_T sf_Motion_State_j;/* '<S56>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State_l;/* '<S36>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State_c;/* '<S15>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State;/* '<S95>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State;/* '<S78>/Motion_State' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VecConcentate3[3];    /* '<S125>/VecConcentate3' */
  const real32_T Square;               /* '<S61>/Square' */
  const real32_T d;                    /* '<S61>/Multiply' */
  const real32_T Gain4;                /* '<S61>/Gain4' */
  const real32_T Square_e;             /* '<S60>/Square' */
  const real32_T d_i;                  /* '<S60>/Multiply' */
  const real32_T Gain4_f;              /* '<S60>/Gain4' */
  const real32_T Square_o;             /* '<S52>/Square' */
  const real32_T d_a;                  /* '<S52>/Multiply' */
  const real32_T Gain4_m;              /* '<S52>/Gain4' */
  const real32_T Square_f;             /* '<S20>/Square' */
  const real32_T d_av;                 /* '<S20>/Multiply' */
  const real32_T Gain4_a;              /* '<S20>/Gain4' */
  const real32_T Square_k;             /* '<S19>/Square' */
  const real32_T d_f;                  /* '<S19>/Multiply' */
  const real32_T Gain4_e;              /* '<S19>/Gain4' */
  const boolean_T Arm_Allowed_Logical_Operato;/* '<S130>/Arm_Allowed_Logical_Operator' */
  const boolean_T Disarm_Allowed_Logical_Oper;/* '<S130>/Disarm_Allowed_Logical_Operator' */
} ConstB_FMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Pilot_Cmd_Bus Pilot_Cmd;             /* '<Root>/Pilot_Cmd' */
  INS_Out_Bus INS_Output;              /* '<Root>/INS_Output' */
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
} ExtU_FMS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  FMS_Out_Bus FMS_Output;              /* '<Root>/FMS_Output' */
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
extern struct_QTHD3FieMDlB4oEKy11VyG FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<S120>/Constant'
                                                *   '<S120>/Dead Zone'
                                                *   '<S121>/Constant'
                                                *   '<S121>/Dead Zone'
                                                *   '<S122>/Constant'
                                                *   '<S122>/Dead Zone'
                                                *   '<S123>/Constant'
                                                *   '<S123>/Dead Zone'
                                                *   '<S14>/Gain'
                                                *   '<S14>/Gain1'
                                                *   '<S15>/Saturation1'
                                                *   '<S16>/Saturation'
                                                *   '<S55>/Gain1'
                                                *   '<S55>/Gain2'
                                                *   '<S56>/Saturation1'
                                                *   '<S78>/Saturation1'
                                                *   '<S25>/Gain2'
                                                *   '<S26>/Gain1'
                                                *   '<S66>/Gain2'
                                                *   '<S67>/Gain1'
                                                *   '<S84>/Gain2'
                                                *   '<S85>/Gain1'
                                                *   '<S96>/Saturation'
                                                *   '<S96>/Saturation1'
                                                *   '<S34>/Dead Zone'
                                                *   '<S34>/Gain'
                                                *   '<S42>/Gain4'
                                                *   '<S43>/Gain6'
                                                *   '<S75>/Dead Zone'
                                                *   '<S75>/Gain'
                                                *   '<S93>/Dead Zone'
                                                *   '<S93>/Gain'
                                                *   '<S103>/Gain2'
                                                *   '<S103>/Gain4'
                                                *   '<S104>/Gain1'
                                                *   '<S104>/Gain5'
                                                *   '<S104>/Gain6'
                                                *   '<S51>/Dead Zone'
                                                *   '<S51>/Gain'
                                                *   '<S115>/Dead Zone'
                                                *   '<S115>/Gain'
                                                *   '<S116>/Dead Zone'
                                                *   '<S116>/Gain'
                                                *   '<S117>/Dead Zone'
                                                *   '<S117>/Gain'
                                                */
extern struct_i7E80ZuatMf603HOn7rPOE FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S134>/Constant'
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
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<S139>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S134>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'FMS/Control_Mode'
 * '<S2>'   : 'FMS/FMS_Command'
 * '<S3>'   : 'FMS/State_Management'
 * '<S4>'   : 'FMS/Control_Mode/Acro_Mode'
 * '<S5>'   : 'FMS/Control_Mode/Altitude_Hold_Mode'
 * '<S6>'   : 'FMS/Control_Mode/Manual_Mode'
 * '<S7>'   : 'FMS/Control_Mode/Mode_Logic'
 * '<S8>'   : 'FMS/Control_Mode/Position_Mode'
 * '<S9>'   : 'FMS/Control_Mode/Unknown_Mode'
 * '<S10>'  : 'FMS/Control_Mode/Acro_Mode/Command_Generator'
 * '<S11>'  : 'FMS/Control_Mode/Acro_Mode/Command_Generator/Angel_Rate_Command'
 * '<S12>'  : 'FMS/Control_Mode/Acro_Mode/Command_Generator/Throttle_Command'
 * '<S13>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator'
 * '<S14>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command'
 * '<S15>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command'
 * '<S16>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command'
 * '<S17>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD'
 * '<S18>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command/Thera_CMD_TD'
 * '<S19>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD/fhan '
 * '<S20>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command/Thera_CMD_TD/fhan '
 * '<S21>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S22>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S23>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S24>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S25>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S26>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S27>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S28>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S29>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S30>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S31>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S32>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S33>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S34>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Stretch'
 * '<S35>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S36>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S37>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S38>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S39>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check'
 * '<S40>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S41>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S42>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control'
 * '<S43>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S44>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/W_CMD_TD'
 * '<S45>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error'
 * '<S46>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Bus_Selection'
 * '<S47>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Compare To Constant1'
 * '<S48>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Detect Increase1'
 * '<S49>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Z_Holder'
 * '<S50>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S51>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch'
 * '<S52>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/W_CMD_TD/fhan '
 * '<S53>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S54>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator'
 * '<S55>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command'
 * '<S56>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command'
 * '<S57>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Throttle_Command'
 * '<S58>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD'
 * '<S59>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Theta_CMD_TD'
 * '<S60>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD/fhan '
 * '<S61>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Theta_CMD_TD/fhan '
 * '<S62>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S63>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S64>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S65>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S66>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S67>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S68>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S69>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S70>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S71>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S72>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S73>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S74>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S75>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Stretch'
 * '<S76>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S77>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator'
 * '<S78>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command'
 * '<S79>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command'
 * '<S80>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S81>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S82>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S83>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S84>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S85>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S86>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S87>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S88>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S89>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S90>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S91>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S92>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S93>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Stretch1'
 * '<S94>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S95>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S96>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S97>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S98>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check'
 * '<S99>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/XY_Motion_State'
 * '<S100>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S101>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant'
 * '<S102>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S103>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control'
 * '<S104>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S105>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error'
 * '<S106>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Bus_Selection'
 * '<S107>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant'
 * '<S108>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant1'
 * '<S109>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase'
 * '<S110>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase1'
 * '<S111>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/XY_Holder'
 * '<S112>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Z_Holder'
 * '<S113>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant'
 * '<S114>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S115>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch'
 * '<S116>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch1'
 * '<S117>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch2'
 * '<S118>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero'
 * '<S119>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S120>' : 'FMS/FMS_Command/Dead_Zone'
 * '<S121>' : 'FMS/FMS_Command/Dead_Zone1'
 * '<S122>' : 'FMS/FMS_Command/Dead_Zone2'
 * '<S123>' : 'FMS/FMS_Command/Dead_Zone3'
 * '<S124>' : 'FMS/FMS_Command/Handle_Command'
 * '<S125>' : 'FMS/FMS_Command/M_CO'
 * '<S126>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant'
 * '<S127>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant3'
 * '<S128>' : 'FMS/FMS_Command/Handle_Command/Detect Increase'
 * '<S129>' : 'FMS/State_Management/Arm_Event'
 * '<S130>' : 'FMS/State_Management/Arm_Prerequisite '
 * '<S131>' : 'FMS/State_Management/Compare To Constant'
 * '<S132>' : 'FMS/State_Management/State_Logic'
 * '<S133>' : 'FMS/State_Management/Subsystem'
 * '<S134>' : 'FMS/State_Management/timestamp'
 * '<S135>' : 'FMS/State_Management/Arm_Event/Arm_Event'
 * '<S136>' : 'FMS/State_Management/Arm_Event/Disarm_Event'
 * '<S137>' : 'FMS/State_Management/Arm_Event/Onground_Check'
 * '<S138>' : 'FMS/State_Management/Arm_Event/Onground_Check/Compare To Constant'
 * '<S139>' : 'FMS/State_Management/Arm_Event/Onground_Check/Interval Test'
 * '<S140>' : 'FMS/State_Management/Arm_Event/Onground_Check/LPF'
 * '<S141>' : 'FMS/State_Management/Arm_Event/Onground_Check/Quat_to_M_OB'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
