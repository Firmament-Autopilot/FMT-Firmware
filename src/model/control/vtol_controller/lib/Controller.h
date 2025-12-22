/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.859
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec 22 15:59:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Controller_COMMON_INCLUDES_
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"
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
  real32_T Multiply[3];                /* '<S6>/Multiply' */
  real32_T Constant;                   /* '<S141>/Constant' */
  real32_T Multiply1[3];               /* '<S6>/Multiply1' */
  real32_T Reshape[3];                 /* '<S18>/Reshape' */
  real32_T Switch[6];                  /* '<S11>/Switch' */
  real32_T Multiply_c[3];              /* '<S5>/Multiply' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S9>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S8>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S99>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S119>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S124>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S126>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S96>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S101>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S119>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S138>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S141>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S143>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S138>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S66>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S26>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_c;       /* '<S36>/Integrator1' */
  real32_T Integrator1_DSTATE_j;       /* '<S38>/Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S25>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S23>/Discrete-Time Integrator' */
  real32_T _DSTATE;                    /* '<S41>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S62>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S61>/Discrete-Time Integrator1' */
  real32_T _DSTATE_h;                  /* '<S58>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S59>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S38>/Integrator' */
  real32_T Integrator_DSTATE_n;        /* '<S36>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S99>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S124>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S126>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S101>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S141>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S143>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S23>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S62>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_Prev_dx;/* '<S61>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S58>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S9>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S8>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S126>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;/* '<S96>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S101>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S143>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_i;/* '<S66>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_h;/* '<S26>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_hl;/* '<S25>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_n;/* '<S62>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S61>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S59>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S2>/Relay' */
  boolean_T Relay1_Mode;               /* '<S2>/Relay1' */
  boolean_T MC_Controller_MODE;        /* '<S2>/MC_Controller' */
  boolean_T FW_Controller_MODE;        /* '<S2>/FW_Controller' */
} DW_Controller_T;

/* Invariant block signals for system '<S145>/VTOL1' */
#if AIRFRAME == 1

typedef struct {
  const real32_T Gain[12];             /* '<S149>/Gain' */
  const real32_T r_column[4];          /* '<S149>/r_column' */
  const real32_T pq_column[8];         /* '<S149>/pq_column' */
} ConstB_VTOL1_Controller_T;

#endif

/* Invariant block signals for system '<S145>/VTOL2' */
#if AIRFRAME == 2

typedef struct {
  const real32_T Gain[12];             /* '<S159>/Gain' */
  const real32_T r_column[4];          /* '<S159>/r_column' */
  const real32_T pq_column[8];         /* '<S159>/pq_column' */
} ConstB_VTOL2_Controller_T;

#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant[3];          /* '<S99>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S121>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S124>/Constant' */
  const real32_T Gain;                 /* '<S107>/Gain' */
  const real32_T Subtract;             /* '<S82>/Subtract' */
  const real32_T Divide;               /* '<S82>/Divide' */
  const real32_T Subtract_g;           /* '<S85>/Subtract' */
  const real32_T Divide_k;             /* '<S85>/Divide' */
  const real32_T Square;               /* '<S122>/Square' */
  const real32_T d;                    /* '<S122>/Multiply' */
  const real32_T Gain4;                /* '<S122>/Gain4' */
  const real32_T Square_h;             /* '<S139>/Square' */
  const real32_T d_i;                  /* '<S139>/Multiply' */
  const real32_T Gain4_p;              /* '<S139>/Gain4' */
  const real32_T Constant_c[3];        /* '<S23>/Constant' */
  const real32_T VectorConcatenate3_g[3];/* '<S55>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S58>/Zero1' */
  const real32_T Square_j;             /* '<S43>/Square' */
  const real32_T d_f;                  /* '<S43>/Multiply' */
  const real32_T Gain4_n;              /* '<S43>/Gain4' */
  const real32_T Square_c;             /* '<S37>/Square' */
  const real32_T d_ih;                 /* '<S37>/Multiply' */
  const real32_T Gain4_g;              /* '<S37>/Gain4' */

#if AIRFRAME == 2

  ConstB_VTOL2_Controller_T VTOL2;     /* '<S145>/VTOL2' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  ConstB_VTOL1_Controller_T VTOL1;     /* '<S145>/VTOL1' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S157>/Standby'
   *   '<S168>/Disarm'
   */
  real32_T pooled33[5];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#ifndef CONSTP_CONTROLLER_T_VARIANT_EXISTS

  char _rt_unused;

#endif

} ConstP_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  FMS_Out_Bus FMS_Out;                 /* '<Root>/FMS_Out' */
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExtU_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
} ExtY_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Controller_T Controller_B;

/* Block states (default storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller_T Controller_Y;

/* External data declarations for dependent source files */
extern const Control_Out_Bus Controller_rtZControl_Out_Bus;/* Control_Out_Bus ground */
extern const ConstB_Controller_T Controller_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Controller_T Controller_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_AGLUWHQ2VVXz72aZazl5HE CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S14>/Saturation'
                                                    *   '<S15>/Gain'
                                                    *   '<S15>/Gain1'
                                                    *   '<S15>/Gain2'
                                                    *   '<S15>/Gain3'
                                                    *   '<S15>/Gain4'
                                                    *   '<S15>/Gain5'
                                                    *   '<S15>/Gain6'
                                                    *   '<S15>/Gain7'
                                                    *   '<S15>/pitch_ff'
                                                    *   '<S15>/thorttle_ff'
                                                    *   '<S132>/hover_throttle'
                                                    *   '<S17>/FF'
                                                    *   '<S40>/P_control'
                                                    *   '<S41>/Gain'
                                                    *   '<S41>/Gain1'
                                                    *   '<S41>/P_control'
                                                    *   '<S42>/Kv'
                                                    *   '<S112>/Saturation'
                                                    *   '<S148>/Bias1'
                                                    *   '<S148>/Bias2'
                                                    *   '<S148>/Bias3'
                                                    *   '<S148>/Bias4'
                                                    *   '<S148>/Saturation1'
                                                    *   '<S149>/Constant'
                                                    *   '<S149>/Constant1'
                                                    *   '<S149>/Saturation'
                                                    *   '<S158>/Bias1'
                                                    *   '<S158>/Bias2'
                                                    *   '<S158>/Bias3'
                                                    *   '<S158>/Bias4'
                                                    *   '<S158>/Saturation1'
                                                    *   '<S159>/Constant'
                                                    *   '<S159>/Constant1'
                                                    *   '<S159>/Saturation'
                                                    *   '<S21>/trim_speed'
                                                    *   '<S22>/trim_speed'
                                                    *   '<S28>/Saturation'
                                                    *   '<S57>/Gain'
                                                    *   '<S58>/ '
                                                    *   '<S58>/Gain3'
                                                    *   '<S80>/Saturation'
                                                    *   '<S80>/Saturation1'
                                                    *   '<S80>/Saturation2'
                                                    *   '<S123>/kd'
                                                    *   '<S123>/Saturation'
                                                    *   '<S124>/ki'
                                                    *   '<S124>/Discrete-Time Integrator'
                                                    *   '<S125>/kp'
                                                    *   '<S140>/kd'
                                                    *   '<S140>/Saturation'
                                                    *   '<S141>/Constant'
                                                    *   '<S141>/ki'
                                                    *   '<S141>/Discrete-Time Integrator'
                                                    *   '<S142>/kp'
                                                    *   '<S151>/Constant1'
                                                    *   '<S151>/Constant12'
                                                    *   '<S151>/Constant2'
                                                    *   '<S151>/Constant7'
                                                    *   '<S156>/Bias'
                                                    *   '<S156>/Bias1'
                                                    *   '<S156>/Bias2'
                                                    *   '<S156>/Bias3'
                                                    *   '<S157>/Bias'
                                                    *   '<S157>/Bias1'
                                                    *   '<S157>/Bias2'
                                                    *   '<S157>/Bias3'
                                                    *   '<S161>/Constant1'
                                                    *   '<S161>/Constant11'
                                                    *   '<S161>/Constant12'
                                                    *   '<S161>/Constant2'
                                                    *   '<S161>/Constant7'
                                                    *   '<S161>/Constant8'
                                                    *   '<S167>/Bias'
                                                    *   '<S167>/Bias1'
                                                    *   '<S167>/Bias2'
                                                    *   '<S167>/Bias3'
                                                    *   '<S168>/Bias'
                                                    *   '<S168>/Bias1'
                                                    *   '<S168>/Bias2'
                                                    *   '<S168>/Bias3'
                                                    *   '<S23>/gain1'
                                                    *   '<S23>/gain2'
                                                    *   '<S23>/gain3'
                                                    *   '<S23>/Discrete-Time Integrator'
                                                    *   '<S24>/gain1'
                                                    *   '<S24>/gain2'
                                                    *   '<S24>/gain3'
                                                    *   '<S30>/Pitch Offset'
                                                    *   '<S30>/Saturation'
                                                    *   '<S31>/Constant1'
                                                    *   '<S31>/Constant2'
                                                    *   '<S93>/Gain'
                                                    *   '<S93>/Gain1'
                                                    *   '<S105>/Constant1'
                                                    *   '<S105>/Constant2'
                                                    *   '<S98>/gain1'
                                                    *   '<S98>/gain2'
                                                    *   '<S98>/gain3'
                                                    *   '<S98>/Saturation'
                                                    *   '<S99>/gain1'
                                                    *   '<S99>/gain2'
                                                    *   '<S99>/gain3'
                                                    *   '<S99>/Discrete-Time Integrator'
                                                    *   '<S100>/gain1'
                                                    *   '<S100>/gain2'
                                                    *   '<S100>/gain3'
                                                    */
extern struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
                                                     * Referenced by: '<S3>/Constant'
                                                     */

/* Model entry point functions */
extern void Controller_init(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S63>/Data Type Conversion' : Unused code path elimination
 * Block '<S63>/Discrete-Time Integrator5' : Unused code path elimination
 * Block '<S63>/Gain' : Unused code path elimination
 * Block '<S63>/Sum5' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Logical Operator1' : Eliminated due to no operation
 * Block '<S62>/Switch' : Eliminated due to constant selection input
 * Block '<S66>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S135>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S149>/Reshape' : Reshape block reduction
 * Block '<S146>/Reshape' : Reshape block reduction
 * Block '<S159>/Reshape' : Reshape block reduction
 * Block '<S147>/Reshape' : Reshape block reduction
 * Block '<S62>/Gain1' : Unused code path elimination
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
 * '<Root>' : 'Controller'
 * '<S1>'   : 'Controller/Bus_Constructor'
 * '<S2>'   : 'Controller/Controller'
 * '<S3>'   : 'Controller/Bus_Constructor/timestamp'
 * '<S4>'   : 'Controller/Controller/ControlFactor'
 * '<S5>'   : 'Controller/Controller/FW_Controller'
 * '<S6>'   : 'Controller/Controller/MC_Controller'
 * '<S7>'   : 'Controller/Controller/VTOL_Control_Allocation'
 * '<S8>'   : 'Controller/Controller/ControlFactor/First Order LPF1'
 * '<S9>'   : 'Controller/Controller/ControlFactor/First Order LPF3'
 * '<S10>'  : 'Controller/Controller/FW_Controller/FW_Controller'
 * '<S11>'  : 'Controller/Controller/FW_Controller/Signal_Select'
 * '<S12>'  : 'Controller/Controller/FW_Controller/True_FlySpeed'
 * '<S13>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S14>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S15>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S16>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S17>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S18>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S19>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S20>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S21>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S22>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S23>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S24>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S25>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler/First Order LPF'
 * '<S26>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler/First Order LPF'
 * '<S27>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S28>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S29>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S30>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S31>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S32>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S33>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S34>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S35>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S36>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control/TD'
 * '<S37>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control/TD/fhan '
 * '<S38>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/TD'
 * '<S39>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S40>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller'
 * '<S41>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_controller'
 * '<S42>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S43>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/TD/fhan '
 * '<S44>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S45>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed'
 * '<S46>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S47>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S48>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM'
 * '<S49>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S50>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_1'
 * '<S51>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_2'
 * '<S52>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_3'
 * '<S53>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S54>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S55>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S56>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/Compare To Constant'
 * '<S57>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/D_control'
 * '<S58>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/I_control'
 * '<S59>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/D_control/DT Filter'
 * '<S60>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_controller/Compare To Constant'
 * '<S61>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_controller/DT Filter'
 * '<S62>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/DT Filter'
 * '<S63>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/First Order LPF'
 * '<S64>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S65>'  : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S66>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/First Order LPF3'
 * '<S67>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed'
 * '<S68>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM'
 * '<S69>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S70>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_1'
 * '<S71>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_2'
 * '<S72>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_3'
 * '<S73>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S74>'  : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S75>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S76>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S77>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S78>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S79>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S80>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer'
 * '<S81>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S82>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Backward_Mixer'
 * '<S83>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Euler To Angle Rate'
 * '<S84>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed'
 * '<S85>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Forward_Mixer'
 * '<S86>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM'
 * '<S87>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S88>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_1'
 * '<S89>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_2'
 * '<S90>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_3'
 * '<S91>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S92>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S93>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S94>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S95>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Compare To Constant'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Compare To Constant'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S129>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S130>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S131>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S132>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S133>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S134>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S135>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S136>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S137>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/Compare To Constant'
 * '<S138>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S139>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S140>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S141>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S142>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S143>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S144>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S145>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S146>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S147>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S148>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S149>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S150>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S151>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S152>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S153>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S154>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/P_Q_Remix'
 * '<S155>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/R_Remix'
 * '<S156>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S157>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S158>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S159>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S160>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S161>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S162>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S163>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S164>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix'
 * '<S165>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix1'
 * '<S166>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/R_Remix'
 * '<S167>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S168>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
