/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.604
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Aug  9 22:04:29 2020
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

/* Block states (default storage) for system '<S57>/Motion_State' */
typedef struct {
  uint8_T is_active_c5_FMS;            /* '<S57>/Motion_State' */
  uint8_T is_c5_FMS;                   /* '<S57>/Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S57>/Motion_State' */
} DW_Motion_State_FMS_T;

/* Block states (default storage) for system '<S71>/Z_Motion_State' */
typedef struct {
  uint8_T is_active_c8_FMS;            /* '<S71>/Z_Motion_State' */
  uint8_T is_c8_FMS;                   /* '<S71>/Z_Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S71>/Z_Motion_State' */
} DW_Z_Motion_State_FMS_T;

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S100>/Disarm_Event' */
  real_T arm_event;                    /* '<S100>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Mode_Logic' */
  uint16_T PWM_Cmd;                    /* '<S3>/State_Logic' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S53>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S37>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S22>/Delay' */
  real32_T Delay_DSTATE_pp[2];         /* '<S87>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S88>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S68>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S105>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Mode_Logic' */
  uint16_T temporalCounter_i1;         /* '<S3>/State_Logic' */
  uint16_T temporalCounter_i1_b;       /* '<S71>/XY_Motion_State' */
  uint8_T Delay_DSTATE_pi;             /* '<S3>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S98>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i;      /* '<S45>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S36>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S14>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_iu;     /* '<S85>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pv;     /* '<S86>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S60>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c4_FMS;            /* '<S3>/State_Logic' */
  uint8_T is_Arm_Logic;                /* '<S3>/State_Logic' */
  uint8_T is_active_c10_FMS;           /* '<S100>/Disarm_Event' */
  uint8_T is_c10_FMS;                  /* '<S100>/Disarm_Event' */
  uint8_T temporalCounter_i1_a;        /* '<S100>/Disarm_Event' */
  uint8_T is_active_c3_FMS;            /* '<S100>/Arm_Event' */
  uint8_T is_c3_FMS;                   /* '<S100>/Arm_Event' */
  uint8_T icLoad;                      /* '<S53>/Delay' */
  uint8_T icLoad_d;                    /* '<S37>/Delay' */
  uint8_T icLoad_i;                    /* '<S22>/Delay' */
  uint8_T icLoad_f;                    /* '<S87>/Delay' */
  uint8_T icLoad_a;                    /* '<S88>/Delay' */
  uint8_T icLoad_o;                    /* '<S68>/Delay' */
  uint8_T is_active_c7_FMS;            /* '<S71>/XY_Motion_State' */
  uint8_T is_c7_FMS;                   /* '<S71>/XY_Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Mode_Logic' */
  uint8_T is_c1_FMS;                   /* '<S1>/Mode_Logic' */
  DW_Motion_State_FMS_T sf_Motion_State_j;/* '<S42>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State_l;/* '<S25>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State_c;/* '<S11>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State;/* '<S71>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State;/* '<S57>/Motion_State' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VecConcentate3[3];    /* '<S99>/VecConcentate3' */
  const boolean_T Arm_Allowed_Logical_Operato;/* '<S101>/Arm_Allowed_Logical_Operator' */
  const boolean_T Disarm_Allowed_Logical_Oper;/* '<S101>/Disarm_Allowed_Logical_Operator' */
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
                                                *   '<S94>/Constant'
                                                *   '<S94>/Dead Zone'
                                                *   '<S95>/Constant'
                                                *   '<S95>/Dead Zone'
                                                *   '<S96>/Constant'
                                                *   '<S96>/Dead Zone'
                                                *   '<S97>/Constant'
                                                *   '<S97>/Dead Zone'
                                                *   '<S10>/Gain'
                                                *   '<S10>/Gain1'
                                                *   '<S11>/Saturation1'
                                                *   '<S12>/Saturation'
                                                *   '<S41>/Gain1'
                                                *   '<S41>/Gain2'
                                                *   '<S42>/Saturation1'
                                                *   '<S57>/Saturation1'
                                                *   '<S15>/Gain2'
                                                *   '<S16>/Gain1'
                                                *   '<S46>/Gain2'
                                                *   '<S47>/Gain1'
                                                *   '<S61>/Gain2'
                                                *   '<S62>/Gain1'
                                                *   '<S72>/Saturation'
                                                *   '<S72>/Saturation1'
                                                *   '<S31>/Gain4'
                                                *   '<S32>/Gain6'
                                                *   '<S79>/Gain2'
                                                *   '<S79>/Gain4'
                                                *   '<S80>/Gain1'
                                                *   '<S80>/Gain5'
                                                *   '<S80>/Gain6'
                                                */
extern struct_4XfCoaAMTej5uH3d8u88xB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S105>/Constant'
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
 * Block '<S110>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S105>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S4>'   : 'FMS/Control_Mode/Altitude_Hold_Mode'
 * '<S5>'   : 'FMS/Control_Mode/Manual_Mode'
 * '<S6>'   : 'FMS/Control_Mode/Mode_Logic'
 * '<S7>'   : 'FMS/Control_Mode/Position_Mode'
 * '<S8>'   : 'FMS/Control_Mode/Unknown_Mode'
 * '<S9>'   : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator'
 * '<S10>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Attitude_Command'
 * '<S11>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command'
 * '<S12>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command'
 * '<S13>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S14>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S15>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S16>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S17>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S18>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S19>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S20>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S21>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S22>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S23>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S24>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S25>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S26>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S27>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S28>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check'
 * '<S29>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S30>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S31>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control'
 * '<S32>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S33>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error'
 * '<S34>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Bus_Selection'
 * '<S35>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Compare To Constant1'
 * '<S36>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Detect Increase1'
 * '<S37>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Z_Holder'
 * '<S38>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S39>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S40>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator'
 * '<S41>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command'
 * '<S42>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command'
 * '<S43>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Throttle_Command'
 * '<S44>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S45>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S46>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S47>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S48>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S49>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S50>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S51>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S52>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S53>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S54>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S55>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S56>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator'
 * '<S57>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command'
 * '<S58>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command'
 * '<S59>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S60>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S61>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S62>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S63>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S64>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S65>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S66>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S67>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S68>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S69>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S70>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S71>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S72>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S73>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S74>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check'
 * '<S75>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/XY_Motion_State'
 * '<S76>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S77>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant'
 * '<S78>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S79>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control'
 * '<S80>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S81>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error'
 * '<S82>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Bus_Selection'
 * '<S83>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant'
 * '<S84>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant1'
 * '<S85>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase'
 * '<S86>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase1'
 * '<S87>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/XY_Holder'
 * '<S88>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Z_Holder'
 * '<S89>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant'
 * '<S90>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S91>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero'
 * '<S92>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S93>'  : 'FMS/FMS_Command/Compare To Constant'
 * '<S94>'  : 'FMS/FMS_Command/Dead_Zone'
 * '<S95>'  : 'FMS/FMS_Command/Dead_Zone1'
 * '<S96>'  : 'FMS/FMS_Command/Dead_Zone2'
 * '<S97>'  : 'FMS/FMS_Command/Dead_Zone3'
 * '<S98>'  : 'FMS/FMS_Command/Detect Increase'
 * '<S99>'  : 'FMS/FMS_Command/M_CO'
 * '<S100>' : 'FMS/State_Management/Arm_Event'
 * '<S101>' : 'FMS/State_Management/Arm_Prerequisite '
 * '<S102>' : 'FMS/State_Management/Compare To Constant'
 * '<S103>' : 'FMS/State_Management/State_Logic'
 * '<S104>' : 'FMS/State_Management/Subsystem'
 * '<S105>' : 'FMS/State_Management/timestamp'
 * '<S106>' : 'FMS/State_Management/Arm_Event/Arm_Event'
 * '<S107>' : 'FMS/State_Management/Arm_Event/Disarm_Event'
 * '<S108>' : 'FMS/State_Management/Arm_Event/Onground_Check'
 * '<S109>' : 'FMS/State_Management/Arm_Event/Onground_Check/Compare To Constant'
 * '<S110>' : 'FMS/State_Management/Arm_Event/Onground_Check/Interval Test'
 * '<S111>' : 'FMS/State_Management/Arm_Event/Onground_Check/Quat_to_M_OB'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
