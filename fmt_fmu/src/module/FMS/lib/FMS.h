/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.718
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 20 09:13:05 2020
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

/* Block states (default storage) for system '<S80>/Motion_State' */
typedef struct {
  uint8_T is_active_c11_FMS;           /* '<S80>/Motion_State' */
  uint8_T is_c11_FMS;                  /* '<S80>/Motion_State' */
  uint8_T temporalCounter_i1;          /* '<S80>/Motion_State' */
} DW_Motion_State_FMS_T;

/* Block states (default storage) for system '<S99>/Z_Motion_State' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S99>/Z_Motion_State' */
  uint8_T is_active_c8_FMS;            /* '<S99>/Z_Motion_State' */
  uint8_T is_c8_FMS;                   /* '<S99>/Z_Motion_State' */
} DW_Z_Motion_State_FMS_T;

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S135>/Disarm_Event' */
  real_T arm_event;                    /* '<S135>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Mode_Logic' */
  uint16_T PWM_Cmd;                    /* '<S3>/State_Logic' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S146>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE;         /* '<S60>/Integrator1' */
  real32_T Integrator1_DSTATE_n;       /* '<S61>/Integrator1' */
  real32_T Delay_DSTATE;               /* '<S75>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S61>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S60>/Integrator' */
  real32_T Integrator1_DSTATE_f;       /* '<S17>/Integrator1' */
  real32_T Integrator1_DSTATE_a;       /* '<S18>/Integrator1' */
  real32_T Integrator1_DSTATE_p;       /* '<S46>/Integrator1' */
  real32_T Integrator1_DSTATE_d;       /* '<S28>/Integrator1' */
  real32_T Delay_DSTATE_p;             /* '<S33>/Delay' */
  real32_T Integrator_DSTATE_o;        /* '<S28>/Integrator' */
  real32_T Delay_DSTATE_e;             /* '<S51>/Delay' */
  real32_T Integrator_DSTATE_g;        /* '<S46>/Integrator' */
  real32_T Integrator_DSTATE_b;        /* '<S18>/Integrator' */
  real32_T Integrator_DSTATE_gx;       /* '<S17>/Integrator' */
  real32_T Integrator1_DSTATE_c[3];    /* '<S109>/Integrator1' */
  real32_T Integrator1_DSTATE_c1;      /* '<S89>/Integrator1' */
  real32_T Delay_DSTATE_pp[2];         /* '<S116>/Delay' */
  real32_T Delay_DSTATE_n;             /* '<S117>/Delay' */
  real32_T Integrator_DSTATE_f[3];     /* '<S109>/Integrator' */
  real32_T Delay_DSTATE_k;             /* '<S94>/Delay' */
  real32_T Integrator_DSTATE_m;        /* '<S89>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S140>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Mode_Logic' */
  uint16_T temporalCounter_i1;         /* '<S3>/State_Logic' */
  uint16_T temporalCounter_i1_a;       /* '<S135>/Disarm_Event' */
  uint16_T temporalCounter_i1_b;       /* '<S99>/XY_Motion_State' */
  uint8_T Delay_DSTATE_pi;             /* '<S3>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S134>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S67>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i;      /* '<S66>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S23>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S24>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S50>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_iu;     /* '<S114>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pv;     /* '<S115>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S84>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S85>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  uint8_T is_active_c4_FMS;            /* '<S3>/State_Logic' */
  uint8_T is_c4_FMS;                   /* '<S3>/State_Logic' */
  uint8_T is_active_c10_FMS;           /* '<S135>/Disarm_Event' */
  uint8_T is_c10_FMS;                  /* '<S135>/Disarm_Event' */
  uint8_T is_active_c3_FMS;            /* '<S135>/Arm_Event' */
  uint8_T is_c3_FMS;                   /* '<S135>/Arm_Event' */
  uint8_T icLoad;                      /* '<S75>/Delay' */
  uint8_T icLoad_i;                    /* '<S33>/Delay' */
  uint8_T icLoad_d;                    /* '<S51>/Delay' */
  uint8_T icLoad_f;                    /* '<S116>/Delay' */
  uint8_T icLoad_a;                    /* '<S117>/Delay' */
  uint8_T icLoad_o;                    /* '<S94>/Delay' */
  uint8_T is_active_c7_FMS;            /* '<S99>/XY_Motion_State' */
  uint8_T is_c7_FMS;                   /* '<S99>/XY_Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Mode_Logic' */
  uint8_T is_c1_FMS;                   /* '<S1>/Mode_Logic' */
  DW_Motion_State_FMS_T sf_Motion_State_j;/* '<S58>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State_l;/* '<S38>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State_c;/* '<S15>/Motion_State' */
  DW_Z_Motion_State_FMS_T sf_Z_Motion_State;/* '<S99>/Z_Motion_State' */
  DW_Motion_State_FMS_T sf_Motion_State;/* '<S80>/Motion_State' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VecConcentate3[3];    /* '<S131>/VecConcentate3' */
  const real32_T Square;               /* '<S63>/Square' */
  const real32_T d;                    /* '<S63>/Multiply' */
  const real32_T Gain4;                /* '<S63>/Gain4' */
  const real32_T Square_e;             /* '<S62>/Square' */
  const real32_T d_i;                  /* '<S62>/Multiply' */
  const real32_T Gain4_f;              /* '<S62>/Gain4' */
  const real32_T Square_d;             /* '<S36>/Square' */
  const real32_T d_j;                  /* '<S36>/Multiply' */
  const real32_T Gain4_d;              /* '<S36>/Gain4' */
  const real32_T Square_o;             /* '<S54>/Square' */
  const real32_T d_a;                  /* '<S54>/Multiply' */
  const real32_T Gain4_m;              /* '<S54>/Gain4' */
  const real32_T Square_f;             /* '<S20>/Square' */
  const real32_T d_av;                 /* '<S20>/Multiply' */
  const real32_T Gain4_a;              /* '<S20>/Gain4' */
  const real32_T Square_k;             /* '<S19>/Square' */
  const real32_T d_f;                  /* '<S19>/Multiply' */
  const real32_T Gain4_e;              /* '<S19>/Gain4' */
  const real32_T Square_i;             /* '<S123>/Square' */
  const real32_T d_az;                 /* '<S123>/Multiply' */
  const real32_T Gain4_o;              /* '<S123>/Gain4' */
  const real32_T Square_g;             /* '<S97>/Square' */
  const real32_T d_h;                  /* '<S97>/Multiply' */
  const real32_T Gain4_ea;             /* '<S97>/Gain4' */
  const boolean_T Arm_Allowed_Logical_Operato;/* '<S136>/Arm_Allowed_Logical_Operator' */
  const boolean_T Disarm_Allowed_Logical_Oper;/* '<S136>/Disarm_Allowed_Logical_Operator' */
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
                                                *   '<S126>/Constant'
                                                *   '<S126>/Dead Zone'
                                                *   '<S127>/Constant'
                                                *   '<S127>/Dead Zone'
                                                *   '<S128>/Constant'
                                                *   '<S128>/Dead Zone'
                                                *   '<S129>/Constant'
                                                *   '<S129>/Dead Zone'
                                                *   '<S14>/Gain'
                                                *   '<S14>/Gain1'
                                                *   '<S15>/Saturation1'
                                                *   '<S16>/Saturation'
                                                *   '<S57>/Gain1'
                                                *   '<S57>/Gain2'
                                                *   '<S58>/Saturation1'
                                                *   '<S80>/Saturation1'
                                                *   '<S25>/Gain2'
                                                *   '<S26>/Gain1'
                                                *   '<S68>/Gain2'
                                                *   '<S69>/Gain1'
                                                *   '<S86>/Gain2'
                                                *   '<S87>/Gain1'
                                                *   '<S100>/Saturation'
                                                *   '<S100>/Saturation1'
                                                *   '<S35>/Dead Zone'
                                                *   '<S35>/Gain'
                                                *   '<S44>/Gain4'
                                                *   '<S45>/Gain6'
                                                *   '<S77>/Dead Zone'
                                                *   '<S77>/Gain'
                                                *   '<S96>/Dead Zone'
                                                *   '<S96>/Gain'
                                                *   '<S107>/Gain2'
                                                *   '<S107>/Gain4'
                                                *   '<S108>/Gain1'
                                                *   '<S108>/Gain5'
                                                *   '<S108>/Gain6'
                                                *   '<S53>/Dead Zone'
                                                *   '<S53>/Gain'
                                                *   '<S120>/Dead Zone'
                                                *   '<S120>/Gain'
                                                *   '<S121>/Dead Zone'
                                                *   '<S121>/Gain'
                                                *   '<S122>/Dead Zone'
                                                *   '<S122>/Gain'
                                                */
extern struct_i7E80ZuatMf603HOn7rPOE FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S140>/Constant'
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
 * Block '<S145>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S140>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S28>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Psi_rate_cmd_TD'
 * '<S29>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S30>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S31>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S32>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S33>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S34>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S35>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Stretch'
 * '<S36>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/Psi_rate_cmd_TD/fhan '
 * '<S37>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S38>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S39>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S40>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S41>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check'
 * '<S42>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S43>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S44>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control'
 * '<S45>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S46>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/W_CMD_TD'
 * '<S47>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error'
 * '<S48>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Bus_Selection'
 * '<S49>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Compare To Constant1'
 * '<S50>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Detect Increase1'
 * '<S51>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Height_Control/Position_Error/Z_Holder'
 * '<S52>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S53>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch'
 * '<S54>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/Subsystem1/W_CMD_TD/fhan '
 * '<S55>'  : 'FMS/Control_Mode/Altitude_Hold_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S56>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator'
 * '<S57>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command'
 * '<S58>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command'
 * '<S59>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Throttle_Command'
 * '<S60>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD'
 * '<S61>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Theta_CMD_TD'
 * '<S62>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Phi_CMD_TD/fhan '
 * '<S63>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Attitude_Command/Theta_CMD_TD/fhan '
 * '<S64>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant'
 * '<S65>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Compare To Constant1'
 * '<S66>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase'
 * '<S67>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Detect Increase1'
 * '<S68>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control'
 * '<S69>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map'
 * '<S70>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Motion_State'
 * '<S71>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check'
 * '<S72>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/psi_rate'
 * '<S73>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error'
 * '<S74>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Bus_Selection'
 * '<S75>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Control/Heading_Error/Holder'
 * '<S76>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Compare To Constant'
 * '<S77>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/Heading_Rate_Map/Stretch'
 * '<S78>'  : 'FMS/Control_Mode/Manual_Mode/Command_Generator/Psi_Rate_Command/move_check/Compare To Zero'
 * '<S79>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator'
 * '<S80>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1'
 * '<S81>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command'
 * '<S82>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Compare To Constant'
 * '<S83>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Compare To Constant1'
 * '<S84>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Detect Increase'
 * '<S85>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Detect Increase1'
 * '<S86>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Control'
 * '<S87>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Rate_Map'
 * '<S88>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Motion_State'
 * '<S89>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Psi_rate_cmd_TD'
 * '<S90>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/move_check'
 * '<S91>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/psi_rate'
 * '<S92>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Control/Heading_Error'
 * '<S93>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Control/Heading_Error/Bus_Selection'
 * '<S94>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Control/Heading_Error/Holder'
 * '<S95>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Rate_Map/Compare To Constant'
 * '<S96>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Heading_Rate_Map/Stretch'
 * '<S97>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/Psi_rate_cmd_TD/fhan '
 * '<S98>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Psi_Rate_Command1/move_check/Compare To Zero'
 * '<S99>'  : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State'
 * '<S100>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1'
 * '<S101>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/line_speed'
 * '<S102>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check'
 * '<S103>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/XY_Motion_State'
 * '<S104>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Motion_State/Z_Motion_State'
 * '<S105>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant'
 * '<S106>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Compare To Constant1'
 * '<S107>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control'
 * '<S108>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map'
 * '<S109>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/W_CMD_TD'
 * '<S110>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error'
 * '<S111>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Bus_Selection'
 * '<S112>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant'
 * '<S113>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Compare To Constant1'
 * '<S114>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase'
 * '<S115>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Detect Increase1'
 * '<S116>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/XY_Holder'
 * '<S117>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Position_Control/Position_Error/Z_Holder'
 * '<S118>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant'
 * '<S119>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Compare To Constant1'
 * '<S120>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch'
 * '<S121>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch1'
 * '<S122>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/Velocity_Map/Stretch2'
 * '<S123>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/Subsystem1/W_CMD_TD/fhan '
 * '<S124>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero'
 * '<S125>' : 'FMS/Control_Mode/Position_Mode/Command_Generator/Vel_Command/move_check/Compare To Zero1'
 * '<S126>' : 'FMS/FMS_Command/Dead_Zone'
 * '<S127>' : 'FMS/FMS_Command/Dead_Zone1'
 * '<S128>' : 'FMS/FMS_Command/Dead_Zone2'
 * '<S129>' : 'FMS/FMS_Command/Dead_Zone3'
 * '<S130>' : 'FMS/FMS_Command/Handle_Command'
 * '<S131>' : 'FMS/FMS_Command/M_CO'
 * '<S132>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant'
 * '<S133>' : 'FMS/FMS_Command/Handle_Command/Compare To Constant3'
 * '<S134>' : 'FMS/FMS_Command/Handle_Command/Detect Increase'
 * '<S135>' : 'FMS/State_Management/Arm_Event'
 * '<S136>' : 'FMS/State_Management/Arm_Prerequisite '
 * '<S137>' : 'FMS/State_Management/Compare To Constant'
 * '<S138>' : 'FMS/State_Management/State_Logic'
 * '<S139>' : 'FMS/State_Management/Subsystem'
 * '<S140>' : 'FMS/State_Management/timestamp'
 * '<S141>' : 'FMS/State_Management/Arm_Event/Arm_Event'
 * '<S142>' : 'FMS/State_Management/Arm_Event/Disarm_Event'
 * '<S143>' : 'FMS/State_Management/Arm_Event/Onground_Check'
 * '<S144>' : 'FMS/State_Management/Arm_Event/Onground_Check/Compare To Constant'
 * '<S145>' : 'FMS/State_Management/Arm_Event/Onground_Check/Interval Test'
 * '<S146>' : 'FMS/State_Management/Arm_Event/Onground_Check/LPF'
 * '<S147>' : 'FMS/State_Management/Arm_Event/Onground_Check/Quat_to_M_OB'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
