/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.669
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep  6 09:55:56 2020
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

/* Block states (default storage) for system '<S65>/Motion_State' */
typedef struct {
  uint8_T is_active_c5_FMS;            /* '<S65>/Motion_State' */
  uint8_T is_c5_FMS;                   /* '<S65>/Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S65>/Motion_State' */
} DW_Motion_State_FMS_T;

/* Block states (default storage) for system '<S81>/Z_Motion_State' */
typedef struct {
  uint8_T is_active_c8_FMS;            /* '<S81>/Z_Motion_State' */
  uint8_T is_c8_FMS;                   /* '<S81>/Z_Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S81>/Z_Motion_State' */
} DW_Z_Motion_State_FMS_T;

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S112>/Disarm_Event' */
  real_T arm_event;                    /* '<S112>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Mode_Logic' */
  uint16_T PWM_Cmd;                    /* '<S3>/State_Logic' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S123>/Discrete-Time Integrator5' */
  real32_T Delay_DSTATE;               /* '<S61>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S43>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S28>/Delay' */
  real32_T Delay_DSTATE_pp[2];         /* '<S97>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S98>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S78>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S117>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Mode_Logic' */
  uint16_T temporalCounter_i1;         /* '<S3>/State_Logic' */
  uint16_T temporalCounter_i1_b;       /* '<S81>/XY_Motion_State' */
  uint8_T Delay_DSTATE_pi;             /* '<S3>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S111>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S53>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i;      /* '<S52>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S42>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S20>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S19>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_iu;     /* '<S95>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pv;     /* '<S96>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S70>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S69>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c4_FMS;            /* '<S3>/State_Logic' */
  uint8_T is_c4_FMS;                   /* '<S3>/State_Logic' */
  uint8_T is_active_c10_FMS;           /* '<S112>/Disarm_Event' */
  uint8_T is_c10_FMS;                  /* '<S112>/Disarm_Event' */
  uint8_T temporalCounter_i1_a;        /* '<S112>/Disarm_Event' */
  uint8_T is_active_c3_FMS;            /* '<S112>/Arm_Event' */
  uint8_T is_c3_FMS;                   /* '<S112>/Arm_Event' */
  uint8_T icLoad;                      /* '<S61>/Delay' */
  uint8_T icLoad_d;                    /* '<S43>/Delay' */
  uint8_T icLoad_i;                    /* '<S28>/Delay' */
  uint8_T icLoad_f;                    /* '<S97>/Delay' */
  uint8_T icLoad_a;                    /* '<S98>/Delay' */
  uint8_T icLoad_o;                    /* '<S78>/Delay' */
  uint8_T is_active_c7_FMS;            /* '<S81>/XY_Motion_State' */
  uint8_T is_c7_FMS;                   /* '<S81>/XY_Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Mode_Logic' */
  uint8_T is_c1_FMS;                   /* '<S1>/Mode_Logic' */
  DW_Motion_State_FMS_T sf_Motion_State_j;/* '<S48>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State_l;/* '<S31>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State_c;/* '<S15>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State;/* '<S81>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State;/* '<S65>/Motion_State' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VecConcentate3[3];    /* '<S108>/VecConcentate3' */
  const boolean_T Arm_Allowed_Logical_Operato;/* '<S113>/Arm_Allowed_Logical_Operator' */
  const boolean_T Disarm_Allowed_Logical_Oper;/* '<S113>/Disarm_Allowed_Logical_Operator' */
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
                                                *   '<S103>/Constant'
                                                *   '<S103>/Dead Zone'
                                                *   '<S104>/Constant'
                                                *   '<S104>/Dead Zone'
                                                *   '<S105>/Constant'
                                                *   '<S105>/Dead Zone'
                                                *   '<S106>/Constant'
                                                *   '<S106>/Dead Zone'
                                                *   '<S14>/Gain'
                                                *   '<S14>/Gain1'
                                                *   '<S15>/Saturation1'
                                                *   '<S16>/Saturation'
                                                *   '<S47>/Gain1'
                                                *   '<S47>/Gain2'
                                                *   '<S48>/Saturation1'
                                                *   '<S65>/Saturation1'
                                                *   '<S21>/Gain2'
                                                *   '<S22>/Gain1'
                                                *   '<S54>/Gain2'
                                                *   '<S55>/Gain1'
                                                *   '<S71>/Gain2'
                                                *   '<S72>/Gain1'
                                                *   '<S82>/Saturation'
                                                *   '<S82>/Saturation1'
                                                *   '<S37>/Gain4'
                                                *   '<S38>/Gain6'
                                                *   '<S89>/Gain2'
                                                *   '<S89>/Gain4'
                                                *   '<S90>/Gain1'
                                                *   '<S90>/Gain5'
                                                *   '<S90>/Gain6'
                                                */
extern struct_4XfCoaAMTej5uH3d8u88xB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S117>/Constant'
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
 * Block '<S122>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S117>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S17>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S18>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S19>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S20>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S21>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S22>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S23>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S24>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S25>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S26>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S27>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S28>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S29>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S30>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S31>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S32>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S33>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S34>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check'
 * '<S35>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S36>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S37>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control'
 * '<S38>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S39>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error'
 * '<S40>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Bus_Selection'
 * '<S41>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Compare To Constant1'
 * '<S42>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Detect Increase1'
 * '<S43>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Z_Holder'
 * '<S44>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S45>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S46>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator'
 * '<S47>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command'
 * '<S48>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command'
 * '<S49>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Throttle_Command'
 * '<S50>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S51>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S52>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S53>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S54>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S55>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S56>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S57>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S58>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S59>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S60>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S61>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S62>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S63>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S64>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator'
 * '<S65>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command'
 * '<S66>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command'
 * '<S67>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S68>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S69>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S70>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S71>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S72>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S73>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S74>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S75>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S76>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S77>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S78>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S79>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S80>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S81>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S82>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S83>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S84>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check'
 * '<S85>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/XY_Motion_State'
 * '<S86>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S87>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant'
 * '<S88>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S89>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control'
 * '<S90>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S91>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error'
 * '<S92>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Bus_Selection'
 * '<S93>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant'
 * '<S94>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant1'
 * '<S95>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase'
 * '<S96>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase1'
 * '<S97>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/XY_Holder'
 * '<S98>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Z_Holder'
 * '<S99>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant'
 * '<S100>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S101>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero'
 * '<S102>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S103>' : 'FMS/FMS_Command/Dead_Zone'
 * '<S104>' : 'FMS/FMS_Command/Dead_Zone1'
 * '<S105>' : 'FMS/FMS_Command/Dead_Zone2'
 * '<S106>' : 'FMS/FMS_Command/Dead_Zone3'
 * '<S107>' : 'FMS/FMS_Command/Handle_Command'
 * '<S108>' : 'FMS/FMS_Command/M_CO'
 * '<S109>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant'
 * '<S110>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant3'
 * '<S111>' : 'FMS/FMS_Command/Handle_Command/Detect Increase'
 * '<S112>' : 'FMS/State_Management/Arm_Event'
 * '<S113>' : 'FMS/State_Management/Arm_Prerequisite '
 * '<S114>' : 'FMS/State_Management/Compare To Constant'
 * '<S115>' : 'FMS/State_Management/State_Logic'
 * '<S116>' : 'FMS/State_Management/Subsystem'
 * '<S117>' : 'FMS/State_Management/timestamp'
 * '<S118>' : 'FMS/State_Management/Arm_Event/Arm_Event'
 * '<S119>' : 'FMS/State_Management/Arm_Event/Disarm_Event'
 * '<S120>' : 'FMS/State_Management/Arm_Event/Onground_Check'
 * '<S121>' : 'FMS/State_Management/Arm_Event/Onground_Check/Compare To Constant'
 * '<S122>' : 'FMS/State_Management/Arm_Event/Onground_Check/Interval Test'
 * '<S123>' : 'FMS/State_Management/Arm_Event/Onground_Check/LPF'
 * '<S124>' : 'FMS/State_Management/Arm_Event/Onground_Check/Quat_to_M_OB'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
