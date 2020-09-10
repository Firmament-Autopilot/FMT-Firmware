/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.681
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 10 23:11:27 2020
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

/* Block states (default storage) for system '<S73>/Motion_State' */
typedef struct {
  uint8_T is_active_c5_FMS;            /* '<S73>/Motion_State' */
  uint8_T is_c5_FMS;                   /* '<S73>/Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S73>/Motion_State' */
} DW_Motion_State_FMS_T;

/* Block states (default storage) for system '<S89>/Z_Motion_State' */
typedef struct {
  uint8_T is_active_c8_FMS;            /* '<S89>/Z_Motion_State' */
  uint8_T is_c8_FMS;                   /* '<S89>/Z_Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S89>/Z_Motion_State' */
} DW_Z_Motion_State_FMS_T;

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S120>/Disarm_Event' */
  real_T arm_event;                    /* '<S120>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Mode_Logic' */
  uint16_T PWM_Cmd;                    /* '<S3>/State_Logic' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S131>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S54>/Integrator1' */
  real32_T Integrator1_DSTATE_n;       /* '<S55>/Integrator1' */
  real32_T Delay_DSTATE;               /* '<S69>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S55>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S54>/Integrator' */
  real32_T Integrator1_DSTATE_f;       /* '<S17>/Integrator1' */
  real32_T Integrator1_DSTATE_a;       /* '<S18>/Integrator1' */
  real32_T Delay_DSTATE_e;             /* '<S47>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S32>/Delay' */
  real32_T Integrator_DSTATE_b;        /* '<S18>/Integrator' */
  real32_T Integrator_DSTATE_g;        /* '<S17>/Integrator' */
  real32_T Delay_DSTATE_pp[2];         /* '<S105>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S106>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S86>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S125>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Mode_Logic' */
  uint16_T temporalCounter_i1;         /* '<S3>/State_Logic' */
  uint16_T temporalCounter_i1_b;       /* '<S89>/XY_Motion_State' */
  uint8_T Delay_DSTATE_pi;             /* '<S3>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S119>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S61>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i;      /* '<S60>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S46>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S24>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S23>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_iu;     /* '<S103>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pv;     /* '<S104>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S78>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S77>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c4_FMS;            /* '<S3>/State_Logic' */
  uint8_T is_c4_FMS;                   /* '<S3>/State_Logic' */
  uint8_T is_active_c10_FMS;           /* '<S120>/Disarm_Event' */
  uint8_T is_c10_FMS;                  /* '<S120>/Disarm_Event' */
  uint8_T temporalCounter_i1_a;        /* '<S120>/Disarm_Event' */
  uint8_T is_active_c3_FMS;            /* '<S120>/Arm_Event' */
  uint8_T is_c3_FMS;                   /* '<S120>/Arm_Event' */
  uint8_T icLoad;                      /* '<S69>/Delay' */
  uint8_T icLoad_d;                    /* '<S47>/Delay' */
  uint8_T icLoad_i;                    /* '<S32>/Delay' */
  uint8_T icLoad_f;                    /* '<S105>/Delay' */
  uint8_T icLoad_a;                    /* '<S106>/Delay' */
  uint8_T icLoad_o;                    /* '<S86>/Delay' */
  uint8_T is_active_c7_FMS;            /* '<S89>/XY_Motion_State' */
  uint8_T is_c7_FMS;                   /* '<S89>/XY_Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Mode_Logic' */
  uint8_T is_c1_FMS;                   /* '<S1>/Mode_Logic' */
  DW_Motion_State_FMS_T sf_Motion_State_j;/* '<S52>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State_l;/* '<S35>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State_c;/* '<S15>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State;/* '<S89>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State;/* '<S73>/Motion_State' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VecConcentate3[3];    /* '<S116>/VecConcentate3' */
  const real32_T Square;               /* '<S57>/Square' */
  const real32_T d;                    /* '<S57>/Multiply' */
  const real32_T Gain4;                /* '<S57>/Gain4' */
  const real32_T Square_h;             /* '<S56>/Square' */
  const real32_T d_i;                  /* '<S56>/Multiply' */
  const real32_T Gain4_h;              /* '<S56>/Gain4' */
  const real32_T Square_i;             /* '<S20>/Square' */
  const real32_T d_l;                  /* '<S20>/Multiply' */
  const real32_T Gain4_p;              /* '<S20>/Gain4' */
  const real32_T Square_n;             /* '<S19>/Square' */
  const real32_T d_g;                  /* '<S19>/Multiply' */
  const real32_T Gain4_k;              /* '<S19>/Gain4' */
  const boolean_T Arm_Allowed_Logical_Operato;/* '<S121>/Arm_Allowed_Logical_Operator' */
  const boolean_T Disarm_Allowed_Logical_Oper;/* '<S121>/Disarm_Allowed_Logical_Operator' */
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
                                                *   '<S111>/Constant'
                                                *   '<S111>/Dead Zone'
                                                *   '<S112>/Constant'
                                                *   '<S112>/Dead Zone'
                                                *   '<S113>/Constant'
                                                *   '<S113>/Dead Zone'
                                                *   '<S114>/Constant'
                                                *   '<S114>/Dead Zone'
                                                *   '<S14>/Gain'
                                                *   '<S14>/Gain1'
                                                *   '<S15>/Saturation1'
                                                *   '<S16>/Saturation'
                                                *   '<S51>/Gain1'
                                                *   '<S51>/Gain2'
                                                *   '<S52>/Saturation1'
                                                *   '<S73>/Saturation1'
                                                *   '<S25>/Gain2'
                                                *   '<S26>/Gain1'
                                                *   '<S62>/Gain2'
                                                *   '<S63>/Gain1'
                                                *   '<S79>/Gain2'
                                                *   '<S80>/Gain1'
                                                *   '<S90>/Saturation'
                                                *   '<S90>/Saturation1'
                                                *   '<S41>/Gain4'
                                                *   '<S42>/Gain6'
                                                *   '<S97>/Gain2'
                                                *   '<S97>/Gain4'
                                                *   '<S98>/Gain1'
                                                *   '<S98>/Gain5'
                                                *   '<S98>/Gain6'
                                                */
extern struct_i7E80ZuatMf603HOn7rPOE FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S125>/Constant'
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
 * Block '<S130>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S125>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S19>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD/fhan'
 * '<S20>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command/Thera_CMD_TD/fhan'
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
 * '<S34>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S35>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S36>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S37>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S38>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check'
 * '<S39>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S40>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S41>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control'
 * '<S42>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S43>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error'
 * '<S44>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Bus_Selection'
 * '<S45>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Compare To Constant1'
 * '<S46>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Detect Increase1'
 * '<S47>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Z_Holder'
 * '<S48>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S49>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S50>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator'
 * '<S51>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command'
 * '<S52>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command'
 * '<S53>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Throttle_Command'
 * '<S54>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD'
 * '<S55>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Theta_CMD_TD'
 * '<S56>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD/fhan'
 * '<S57>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Theta_CMD_TD/fhan'
 * '<S58>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S59>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S60>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S61>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S62>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S63>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S64>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S65>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S66>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S67>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S68>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S69>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S70>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S71>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S72>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator'
 * '<S73>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command'
 * '<S74>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command'
 * '<S75>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S76>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S77>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S78>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S79>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S80>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S81>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S82>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S83>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S84>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S85>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S86>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S87>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S88>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S89>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S90>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S91>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S92>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check'
 * '<S93>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/XY_Motion_State'
 * '<S94>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S95>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant'
 * '<S96>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S97>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control'
 * '<S98>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S99>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error'
 * '<S100>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Bus_Selection'
 * '<S101>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant'
 * '<S102>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant1'
 * '<S103>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase'
 * '<S104>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase1'
 * '<S105>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/XY_Holder'
 * '<S106>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Z_Holder'
 * '<S107>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant'
 * '<S108>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S109>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero'
 * '<S110>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S111>' : 'FMS/FMS_Command/Dead_Zone'
 * '<S112>' : 'FMS/FMS_Command/Dead_Zone1'
 * '<S113>' : 'FMS/FMS_Command/Dead_Zone2'
 * '<S114>' : 'FMS/FMS_Command/Dead_Zone3'
 * '<S115>' : 'FMS/FMS_Command/Handle_Command'
 * '<S116>' : 'FMS/FMS_Command/M_CO'
 * '<S117>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant'
 * '<S118>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant3'
 * '<S119>' : 'FMS/FMS_Command/Handle_Command/Detect Increase'
 * '<S120>' : 'FMS/State_Management/Arm_Event'
 * '<S121>' : 'FMS/State_Management/Arm_Prerequisite '
 * '<S122>' : 'FMS/State_Management/Compare To Constant'
 * '<S123>' : 'FMS/State_Management/State_Logic'
 * '<S124>' : 'FMS/State_Management/Subsystem'
 * '<S125>' : 'FMS/State_Management/timestamp'
 * '<S126>' : 'FMS/State_Management/Arm_Event/Arm_Event'
 * '<S127>' : 'FMS/State_Management/Arm_Event/Disarm_Event'
 * '<S128>' : 'FMS/State_Management/Arm_Event/Onground_Check'
 * '<S129>' : 'FMS/State_Management/Arm_Event/Onground_Check/Compare To Constant'
 * '<S130>' : 'FMS/State_Management/Arm_Event/Onground_Check/Interval Test'
 * '<S131>' : 'FMS/State_Management/Arm_Event/Onground_Check/LPF'
 * '<S132>' : 'FMS/State_Management/Arm_Event/Onground_Check/Quat_to_M_OB'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
