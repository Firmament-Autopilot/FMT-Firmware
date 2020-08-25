/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.622
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 25 10:15:30 2020
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

/* Block states (default storage) for system '<S61>/Motion_State' */
typedef struct {
  uint8_T is_active_c5_FMS;            /* '<S61>/Motion_State' */
  uint8_T is_c5_FMS;                   /* '<S61>/Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S61>/Motion_State' */
} DW_Motion_State_FMS_T;

/* Block states (default storage) for system '<S77>/Z_Motion_State' */
typedef struct {
  uint8_T is_active_c8_FMS;            /* '<S77>/Z_Motion_State' */
  uint8_T is_c8_FMS;                   /* '<S77>/Z_Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S77>/Z_Motion_State' */
} DW_Z_Motion_State_FMS_T;

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S106>/Disarm_Event' */
  real_T arm_event;                    /* '<S106>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Mode_Logic' */
  uint16_T PWM_Cmd;                    /* '<S3>/State_Logic' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S117>/Discrete-Time Integrator5' */
  real32_T Delay_DSTATE;               /* '<S57>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S39>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S24>/Delay' */
  real32_T Delay_DSTATE_pp[2];         /* '<S93>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S94>/Delay' */
  real32_T Delay_DSTATE_c;             /* '<S74>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S111>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Mode_Logic' */
  uint16_T temporalCounter_i1;         /* '<S3>/State_Logic' */
  uint16_T temporalCounter_i1_b;       /* '<S77>/XY_Motion_State' */
  uint8_T Delay_DSTATE_pi;             /* '<S3>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S104>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S49>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i;      /* '<S48>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S38>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S16>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S15>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_iu;     /* '<S91>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pv;     /* '<S92>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S66>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S65>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c4_FMS;            /* '<S3>/State_Logic' */
  uint8_T is_Arm_Logic;                /* '<S3>/State_Logic' */
  uint8_T is_active_c10_FMS;           /* '<S106>/Disarm_Event' */
  uint8_T is_c10_FMS;                  /* '<S106>/Disarm_Event' */
  uint8_T temporalCounter_i1_a;        /* '<S106>/Disarm_Event' */
  uint8_T is_active_c3_FMS;            /* '<S106>/Arm_Event' */
  uint8_T is_c3_FMS;                   /* '<S106>/Arm_Event' */
  uint8_T icLoad;                      /* '<S57>/Delay' */
  uint8_T icLoad_d;                    /* '<S39>/Delay' */
  uint8_T icLoad_i;                    /* '<S24>/Delay' */
  uint8_T icLoad_f;                    /* '<S93>/Delay' */
  uint8_T icLoad_a;                    /* '<S94>/Delay' */
  uint8_T icLoad_o;                    /* '<S74>/Delay' */
  uint8_T is_active_c7_FMS;            /* '<S77>/XY_Motion_State' */
  uint8_T is_c7_FMS;                   /* '<S77>/XY_Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Mode_Logic' */
  uint8_T is_c1_FMS;                   /* '<S1>/Mode_Logic' */
  DW_Motion_State_FMS_T sf_Motion_State_j;/* '<S44>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State_l;/* '<S27>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State_c;/* '<S11>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State;/* '<S77>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State;/* '<S61>/Motion_State' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VecConcentate3[3];    /* '<S105>/VecConcentate3' */
  const boolean_T Arm_Allowed_Logical_Operato;/* '<S107>/Arm_Allowed_Logical_Operator' */
  const boolean_T Disarm_Allowed_Logical_Oper;/* '<S107>/Disarm_Allowed_Logical_Operator' */
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
                                                *   '<S100>/Constant'
                                                *   '<S100>/Dead Zone'
                                                *   '<S101>/Constant'
                                                *   '<S101>/Dead Zone'
                                                *   '<S102>/Constant'
                                                *   '<S102>/Dead Zone'
                                                *   '<S103>/Constant'
                                                *   '<S103>/Dead Zone'
                                                *   '<S10>/Gain'
                                                *   '<S10>/Gain1'
                                                *   '<S11>/Saturation1'
                                                *   '<S12>/Saturation'
                                                *   '<S43>/Gain1'
                                                *   '<S43>/Gain2'
                                                *   '<S44>/Saturation1'
                                                *   '<S61>/Saturation1'
                                                *   '<S17>/Gain2'
                                                *   '<S18>/Gain1'
                                                *   '<S50>/Gain2'
                                                *   '<S51>/Gain1'
                                                *   '<S67>/Gain2'
                                                *   '<S68>/Gain1'
                                                *   '<S78>/Saturation'
                                                *   '<S78>/Saturation1'
                                                *   '<S33>/Gain4'
                                                *   '<S34>/Gain6'
                                                *   '<S85>/Gain2'
                                                *   '<S85>/Gain4'
                                                *   '<S86>/Gain1'
                                                *   '<S86>/Gain5'
                                                *   '<S86>/Gain6'
                                                */
extern struct_4XfCoaAMTej5uH3d8u88xB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S111>/Constant'
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
 * Block '<S116>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S111>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S14>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S15>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S16>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S17>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S18>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S19>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S20>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S21>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S22>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S23>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S24>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S25>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S26>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S27>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S28>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S29>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S30>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check'
 * '<S31>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S32>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S33>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control'
 * '<S34>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S35>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error'
 * '<S36>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Bus_Selection'
 * '<S37>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Compare To Constant1'
 * '<S38>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Detect Increase1'
 * '<S39>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Z_Holder'
 * '<S40>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S41>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S42>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator'
 * '<S43>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command'
 * '<S44>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command'
 * '<S45>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Throttle_Command'
 * '<S46>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S47>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S48>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S49>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S50>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S51>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S52>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S53>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S54>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S55>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S56>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S57>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S58>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S59>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S60>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator'
 * '<S61>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command'
 * '<S62>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command'
 * '<S63>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S64>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S65>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S66>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S67>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S68>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S69>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S70>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S71>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S72>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S73>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S74>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S75>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S76>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S77>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S78>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S79>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S80>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check'
 * '<S81>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/XY_Motion_State'
 * '<S82>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S83>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant'
 * '<S84>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S85>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control'
 * '<S86>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S87>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error'
 * '<S88>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Bus_Selection'
 * '<S89>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant'
 * '<S90>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant1'
 * '<S91>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase'
 * '<S92>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase1'
 * '<S93>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/XY_Holder'
 * '<S94>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Z_Holder'
 * '<S95>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant'
 * '<S96>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S97>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero'
 * '<S98>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S99>'  : 'FMS/FMS_Command/Compare To Constant'
 * '<S100>' : 'FMS/FMS_Command/Dead_Zone'
 * '<S101>' : 'FMS/FMS_Command/Dead_Zone1'
 * '<S102>' : 'FMS/FMS_Command/Dead_Zone2'
 * '<S103>' : 'FMS/FMS_Command/Dead_Zone3'
 * '<S104>' : 'FMS/FMS_Command/Detect Increase'
 * '<S105>' : 'FMS/FMS_Command/M_CO'
 * '<S106>' : 'FMS/State_Management/Arm_Event'
 * '<S107>' : 'FMS/State_Management/Arm_Prerequisite '
 * '<S108>' : 'FMS/State_Management/Compare To Constant'
 * '<S109>' : 'FMS/State_Management/State_Logic'
 * '<S110>' : 'FMS/State_Management/Subsystem'
 * '<S111>' : 'FMS/State_Management/timestamp'
 * '<S112>' : 'FMS/State_Management/Arm_Event/Arm_Event'
 * '<S113>' : 'FMS/State_Management/Arm_Event/Disarm_Event'
 * '<S114>' : 'FMS/State_Management/Arm_Event/Onground_Check'
 * '<S115>' : 'FMS/State_Management/Arm_Event/Onground_Check/Compare To Constant'
 * '<S116>' : 'FMS/State_Management/Arm_Event/Onground_Check/Interval Test'
 * '<S117>' : 'FMS/State_Management/Arm_Event/Onground_Check/LPF'
 * '<S118>' : 'FMS/State_Management/Arm_Event/Onground_Check/Quat_to_M_OB'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
