/*
 * File: FMS.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.966
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan  9 08:56:59 2021
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

/* Block signals (default storage) */
typedef struct {
  real_T disarm_event;                 /* '<S93>/Disarm_Event' */
  real_T arm_event;                    /* '<S93>/Arm_Event' */
  uint32_T control_mode;               /* '<S1>/Control_Mode' */
  uint16_T PWM_Cmd;                    /* '<S2>/State_Management' */
} B_FMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S101>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_e;/* '<S102>/Discrete-Time Integrator5' */
  real32_T Delay_DSTATE_g[2];          /* '<S78>/Delay' */
  real32_T Delay_DSTATE_f;             /* '<S79>/Delay' */
  real32_T Integrator1_DSTATE;         /* '<S70>/Integrator1' */
  real32_T Integrator1_DSTATE_j[2];    /* '<S69>/Integrator1' */
  real32_T Integrator1_DSTATE_p;       /* '<S30>/Integrator1' */
  real32_T Integrator1_DSTATE_g;       /* '<S17>/Integrator1' */
  real32_T Integrator1_DSTATE_e;       /* '<S16>/Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S69>/Integrator' */
  real32_T Integrator_DSTATE_c;        /* '<S16>/Integrator' */
  real32_T Integrator_DSTATE_h;        /* '<S17>/Integrator' */
  real32_T Delay_DSTATE_l;             /* '<S33>/Delay' */
  real32_T Integrator_DSTATE_m;        /* '<S30>/Integrator' */
  real32_T Integrator_DSTATE_ch;       /* '<S70>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S86>/Discrete-Time Integrator' */
  uint32_T local_mode;                 /* '<S1>/Control_Mode' */
  uint16_T temporalCounter_i1;         /* '<S93>/Disarm_Event' */
  uint16_T temporalCounter_i1_g;       /* '<S2>/State_Management' */
  uint16_T temporalCounter_i1_c;       /* '<S49>/Z_Motion_SM' */
  uint16_T temporalCounter_i1_cu;      /* '<S49>/XY_Motion_SM' */
  boolean_T DelayInput1_DSTATE;        /* '<S95>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S62>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_i[2];   /* '<S63>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S61>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S64>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S45>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S44>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pc;     /* '<S43>/Delay Input1' */
  uint8_T is_active_c12_FMS;           /* '<S93>/Disarm_Event' */
  uint8_T is_c12_FMS;                  /* '<S93>/Disarm_Event' */
  uint8_T is_active_c5_FMS;            /* '<S93>/Arm_Event' */
  uint8_T is_c5_FMS;                   /* '<S93>/Arm_Event' */
  uint8_T is_active_c4_FMS;            /* '<S2>/State_Management' */
  uint8_T is_c4_FMS;                   /* '<S2>/State_Management' */
  uint8_T icLoad;                      /* '<S78>/Delay' */
  uint8_T icLoad_a;                    /* '<S79>/Delay' */
  uint8_T icLoad_k;                    /* '<S33>/Delay' */
  uint8_T is_active_c10_FMS;           /* '<S49>/Z_Motion_SM' */
  uint8_T is_c10_FMS;                  /* '<S49>/Z_Motion_SM' */
  uint8_T is_active_c13_FMS;           /* '<S49>/XY_Motion_SM' */
  uint8_T is_c13_FMS;                  /* '<S49>/XY_Motion_SM' */
  uint8_T is_active_c3_FMS;            /* '<S20>/Motion_State' */
  uint8_T is_c3_FMS;                   /* '<S20>/Motion_State' */
  uint8_T temporalCounter_i1_gq;       /* '<S20>/Motion_State' */
  uint8_T is_active_c1_FMS;            /* '<S1>/Control_Mode' */
  uint8_T is_c1_FMS;                   /* '<S1>/Control_Mode' */
} DW_FMS_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Square;               /* '<S80>/Square' */
  const real32_T d;                    /* '<S80>/Multiply' */
  const real32_T Gain4;                /* '<S80>/Gain4' */
  const real32_T Square_b;             /* '<S18>/Square' */
  const real32_T d_e;                  /* '<S18>/Multiply' */
  const real32_T Gain4_f;              /* '<S18>/Gain4' */
  const real32_T Square_n;             /* '<S19>/Square' */
  const real32_T d_a;                  /* '<S19>/Multiply' */
  const real32_T Gain4_b;              /* '<S19>/Gain4' */
  const real32_T Square_e;             /* '<S38>/Square' */
  const real32_T d_l;                  /* '<S38>/Multiply' */
  const real32_T Gain4_c;              /* '<S38>/Gain4' */
  const real32_T Square_ba;            /* '<S81>/Square' */
  const real32_T d_aw;                 /* '<S81>/Multiply' */
  const real32_T Gain4_m;              /* '<S81>/Gain4' */
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
extern struct_5vUBwe4VfGkNikzOx8lYKF FMS_PARAM;/* Variable: FMS_PARAM
                                                * Referenced by:
                                                *   '<S12>/Gain'
                                                *   '<S12>/Gain1'
                                                *   '<S104>/Constant'
                                                *   '<S104>/Dead Zone'
                                                *   '<S105>/Constant'
                                                *   '<S105>/Dead Zone'
                                                *   '<S106>/Constant'
                                                *   '<S106>/Dead Zone'
                                                *   '<S107>/Constant'
                                                *   '<S107>/Dead Zone'
                                                *   '<S21>/Saturation'
                                                *   '<S48>/Saturation'
                                                *   '<S48>/Saturation1'
                                                *   '<S28>/Gain2'
                                                *   '<S29>/Gain1'
                                                *   '<S67>/Gain1'
                                                *   '<S67>/Gain5'
                                                *   '<S67>/Gain6'
                                                *   '<S68>/Gain1'
                                                *   '<S68>/Gain2'
                                                *   '<S68>/Gain4'
                                                *   '<S37>/Dead Zone'
                                                *   '<S37>/Gain'
                                                *   '<S73>/Dead Zone'
                                                *   '<S73>/Gain'
                                                *   '<S74>/Dead Zone'
                                                *   '<S74>/Gain'
                                                *   '<S75>/Dead Zone'
                                                *   '<S75>/Gain'
                                                */
extern struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT;/* Variable: FMS_EXPORT
                                                 * Referenced by: '<S86>/Constant'
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
 * Block '<S100>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S90>/Signal Copy4' : Eliminate redundant signal conversion block
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
 * '<S2>'   : 'FMS/FMS_State'
 * '<S3>'   : 'FMS/Input_Process'
 * '<S4>'   : 'FMS/Control_Mode/Acro_Mode'
 * '<S5>'   : 'FMS/Control_Mode/Altitude_Hold_Mode'
 * '<S6>'   : 'FMS/Control_Mode/Control_Mode'
 * '<S7>'   : 'FMS/Control_Mode/FMS_Command_Generator'
 * '<S8>'   : 'FMS/Control_Mode/Manual_Mode'
 * '<S9>'   : 'FMS/Control_Mode/Position_Mode'
 * '<S10>'  : 'FMS/Control_Mode/Unknown_Mode'
 * '<S11>'  : 'FMS/Control_Mode/FMS_Command_Generator/Angel_Rate_Command'
 * '<S12>'  : 'FMS/Control_Mode/FMS_Command_Generator/Attitude_Command'
 * '<S13>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command'
 * '<S14>'  : 'FMS/Control_Mode/FMS_Command_Generator/Throttle_Command'
 * '<S15>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command'
 * '<S16>'  : 'FMS/Control_Mode/FMS_Command_Generator/Attitude_Command/Phi_CMD_TD'
 * '<S17>'  : 'FMS/Control_Mode/FMS_Command_Generator/Attitude_Command/Thera_CMD_TD'
 * '<S18>'  : 'FMS/Control_Mode/FMS_Command_Generator/Attitude_Command/Phi_CMD_TD/fhan '
 * '<S19>'  : 'FMS/Control_Mode/FMS_Command_Generator/Attitude_Command/Thera_CMD_TD/fhan '
 * '<S20>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Motion_Check'
 * '<S21>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander'
 * '<S22>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update'
 * '<S23>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Motion_Check/Motion_State'
 * '<S24>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Motion_Check/heading_rate'
 * '<S25>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Motion_Check/move_check'
 * '<S26>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Motion_Check/move_check/Compare To Zero'
 * '<S27>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Compare To Constant'
 * '<S28>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Heading_Control'
 * '<S29>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Motion_Heading_Rate'
 * '<S30>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/TD'
 * '<S31>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Heading_Control/Heading_Error'
 * '<S32>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Heading_Control/Heading_Error/Bus_Selection'
 * '<S33>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Heading_Control/Heading_Error/Psi_Holder'
 * '<S34>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Heading_Control/Heading_Error/psi_err_saturation'
 * '<S35>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Heading_Control/Heading_Error/psi_err_saturation/Compare To Constant'
 * '<S36>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Motion_Heading_Rate/Compare To Constant'
 * '<S37>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/Motion_Heading_Rate/remap'
 * '<S38>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Psi_Rate_Commander/TD/fhan '
 * '<S39>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Compare To Constant1'
 * '<S40>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Compare To Constant2'
 * '<S41>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Compare To Constant3'
 * '<S42>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Compare To Constant4'
 * '<S43>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Detect Increase1'
 * '<S44>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Detect Increase2'
 * '<S45>'  : 'FMS/Control_Mode/FMS_Command_Generator/Psi_Rate_Command/Update/Detect Increase3'
 * '<S46>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check'
 * '<S47>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update'
 * '<S48>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander'
 * '<S49>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/Motion_State'
 * '<S50>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/line_speed'
 * '<S51>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/move_check'
 * '<S52>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/Motion_State/XY_Motion_SM'
 * '<S53>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/Motion_State/Z_Motion_SM'
 * '<S54>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/move_check/Compare To Zero1'
 * '<S55>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Motion_Check/move_check/Compare To Zero2'
 * '<S56>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Compare To Constant1'
 * '<S57>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Compare To Constant2'
 * '<S58>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Compare To Constant3'
 * '<S59>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Compare To Constant4'
 * '<S60>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Compare To Constant5'
 * '<S61>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Detect Increase'
 * '<S62>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Detect Increase1'
 * '<S63>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Detect Increase2'
 * '<S64>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Update/Detect Increase3'
 * '<S65>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Compare To Constant'
 * '<S66>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Compare To Constant1'
 * '<S67>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Motion_Speed'
 * '<S68>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Position_Control'
 * '<S69>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/TD'
 * '<S70>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/TD1'
 * '<S71>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/TD2'
 * '<S72>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Motion_Speed/Compare To Constant'
 * '<S73>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Motion_Speed/remap'
 * '<S74>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Motion_Speed/remap1'
 * '<S75>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Motion_Speed/remap2'
 * '<S76>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Position_Control/Position_Error'
 * '<S77>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Position_Control/Position_Error/Bus_Selection'
 * '<S78>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Position_Control/Position_Error/Pos_XY_Holder'
 * '<S79>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/Position_Control/Position_Error/Pos_Z_Holder1'
 * '<S80>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/TD/fhan '
 * '<S81>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/TD1/fhan '
 * '<S82>'  : 'FMS/Control_Mode/FMS_Command_Generator/Velocity_Command/Velocity_Commander/TD2/fhan '
 * '<S83>'  : 'FMS/FMS_State/Compare To Constant'
 * '<S84>'  : 'FMS/FMS_State/State_Management'
 * '<S85>'  : 'FMS/FMS_State/expand_pwm'
 * '<S86>'  : 'FMS/FMS_State/timestamp'
 * '<S87>'  : 'FMS/Input_Process/Commander'
 * '<S88>'  : 'FMS/Input_Process/M_CO'
 * '<S89>'  : 'FMS/Input_Process/Onground_Check'
 * '<S90>'  : 'FMS/Input_Process/Stick_Value'
 * '<S91>'  : 'FMS/Input_Process/Commander/Event_Commander'
 * '<S92>'  : 'FMS/Input_Process/Commander/State_Commander'
 * '<S93>'  : 'FMS/Input_Process/Commander/Event_Commander/Arm_Disarm_Event'
 * '<S94>'  : 'FMS/Input_Process/Commander/Event_Commander/Compare To Constant'
 * '<S95>'  : 'FMS/Input_Process/Commander/Event_Commander/Detect Increase'
 * '<S96>'  : 'FMS/Input_Process/Commander/Event_Commander/Arm_Disarm_Event/Arm_Event'
 * '<S97>'  : 'FMS/Input_Process/Commander/Event_Commander/Arm_Disarm_Event/Disarm_Event'
 * '<S98>'  : 'FMS/Input_Process/Commander/State_Commander/Compare To Constant3'
 * '<S99>'  : 'FMS/Input_Process/Onground_Check/Compare To Constant'
 * '<S100>' : 'FMS/Input_Process/Onground_Check/Interval Test'
 * '<S101>' : 'FMS/Input_Process/Onground_Check/LPF'
 * '<S102>' : 'FMS/Input_Process/Onground_Check/LPF1'
 * '<S103>' : 'FMS/Input_Process/Onground_Check/Quat_to_M_OB'
 * '<S104>' : 'FMS/Input_Process/Stick_Value/Dead_Zone'
 * '<S105>' : 'FMS/Input_Process/Stick_Value/Dead_Zone1'
 * '<S106>' : 'FMS/Input_Process/Stick_Value/Dead_Zone2'
 * '<S107>' : 'FMS/Input_Process/Stick_Value/Dead_Zone3'
 */
#endif                                 /* RTW_HEADER_FMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
