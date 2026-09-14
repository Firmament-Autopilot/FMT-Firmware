/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.864
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 14:57:33 2026
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
  real32_T Multiply1[3];               /* '<S6>/Multiply1' */
  real32_T Saturation;                 /* '<S134>/Saturation' */
  real32_T Saturation_h[2];            /* '<S113>/Saturation' */
  real32_T Reshape[3];                 /* '<S18>/Reshape' */
  real32_T Switch[6];                  /* '<S11>/Switch' */
  real32_T Multiply_c[3];              /* '<S5>/Multiply' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S9>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S8>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S100>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S97>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S102>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE;         /* '<S140>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S144>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S146>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S140>/Integrator' */
  real32_T Integrator1_DSTATE_p[2];    /* '<S120>/Integrator1' */
  real32_T Integrator_DSTATE_o[2];     /* '<S120>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S125>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[2];/* '<S127>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S66>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S26>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_c;       /* '<S36>/Integrator1' */
  real32_T Integrator1_DSTATE_j;       /* '<S38>/Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S25>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S23>/Discrete-Time Integrator' */
  real32_T _DSTATE;                    /* '<S41>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S62>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n;/* '<S61>/Discrete-Time Integrator1' */
  real32_T _DSTATE_h;                  /* '<S58>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S59>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S38>/Integrator' */
  real32_T Integrator_DSTATE_n;        /* '<S36>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  uint8_T Delay_DSTATE;                /* '<S75>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S100>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S102>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S144>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S146>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S125>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S127>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S23>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S62>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_Prev_dx;/* '<S61>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S58>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S9>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S8>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;/* '<S97>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S102>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S144>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S146>/Discrete-Time Integrator1' */
  uint8_T Integrator1_IC_LOADING;      /* '<S120>/Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_m;/* '<S127>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_i;/* '<S66>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_h;/* '<S26>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_hl;/* '<S25>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_n;/* '<S62>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S61>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S59>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S2>/Relay' */
  boolean_T Relay1_Mode;               /* '<S2>/Relay1' */
  boolean_T MC_Controller_MODE;        /* '<S2>/MC_Controller' */
  boolean_T Veloxity_Z_Controller_MODE;/* '<S75>/Veloxity_Z_Controller' */
  boolean_T Velocity_Controller_MODE;  /* '<S74>/Velocity_Controller' */
  boolean_T FW_Controller_MODE;        /* '<S2>/FW_Controller' */
} DW_Controller_T;

/* Invariant block signals for system '<S148>/VTOL1' */
#if AIRFRAME == 1

typedef struct {
  const real32_T Gain[12];             /* '<S152>/Gain' */
  const real32_T r_column[4];          /* '<S152>/r_column' */
  const real32_T pq_column[8];         /* '<S152>/pq_column' */
} ConstB_VTOL1_Controller_T;

#endif

/* Invariant block signals for system '<S148>/VTOL2' */
#if AIRFRAME == 2

typedef struct {
  const real32_T Gain[12];             /* '<S162>/Gain' */
  const real32_T r_column[4];          /* '<S162>/r_column' */
  const real32_T pq_column[8];         /* '<S162>/pq_column' */
} ConstB_VTOL2_Controller_T;

#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant[3];          /* '<S100>/Constant' */
  const real32_T Gain;                 /* '<S108>/Gain' */
  const real32_T Subtract;             /* '<S83>/Subtract' */
  const real32_T Divide;               /* '<S83>/Divide' */
  const real32_T Subtract_g;           /* '<S86>/Subtract' */
  const real32_T Divide_k;             /* '<S86>/Divide' */
  const real32_T Square;               /* '<S141>/Square' */
  const real32_T d;                    /* '<S141>/Multiply' */
  const real32_T Gain4;                /* '<S141>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S122>/Vector Concatenate3' */
  const real32_T Square_a;             /* '<S123>/Square' */
  const real32_T d_j;                  /* '<S123>/Multiply' */
  const real32_T Gain4_l;              /* '<S123>/Gain4' */
  const real32_T Constant_e;           /* '<S125>/Constant' */
  const real32_T Constant_c[3];        /* '<S23>/Constant' */
  const real32_T VectorConcatenate3_g[3];/* '<S55>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S58>/Zero1' */
  const real32_T Square_j;             /* '<S43>/Square' */
  const real32_T d_f;                  /* '<S43>/Multiply' */
  const real32_T Gain4_n;              /* '<S43>/Gain4' */
  const real32_T Square_c;             /* '<S37>/Square' */
  const real32_T d_i;                  /* '<S37>/Multiply' */
  const real32_T Gain4_g;              /* '<S37>/Gain4' */

#if AIRFRAME == 2

  ConstB_VTOL2_Controller_T VTOL2;     /* '<S148>/VTOL2' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  ConstB_VTOL1_Controller_T VTOL1;     /* '<S148>/VTOL1' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S160>/Standby'
   *   '<S171>/Disarm'
   */
  real32_T pooled32[5];

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
                                                    *   '<S134>/hover_throttle'
                                                    *   '<S17>/FF'
                                                    *   '<S40>/P_control'
                                                    *   '<S41>/Gain'
                                                    *   '<S41>/Gain1'
                                                    *   '<S41>/P_control'
                                                    *   '<S42>/Kv'
                                                    *   '<S113>/Saturation'
                                                    *   '<S151>/Bias1'
                                                    *   '<S151>/Bias2'
                                                    *   '<S151>/Bias3'
                                                    *   '<S151>/Bias4'
                                                    *   '<S151>/Saturation1'
                                                    *   '<S152>/Constant'
                                                    *   '<S152>/Constant1'
                                                    *   '<S152>/Saturation'
                                                    *   '<S161>/Bias1'
                                                    *   '<S161>/Bias2'
                                                    *   '<S161>/Bias3'
                                                    *   '<S161>/Bias4'
                                                    *   '<S161>/Saturation1'
                                                    *   '<S162>/Constant'
                                                    *   '<S162>/Constant1'
                                                    *   '<S162>/Saturation'
                                                    *   '<S21>/trim_speed'
                                                    *   '<S22>/trim_speed'
                                                    *   '<S28>/Saturation'
                                                    *   '<S57>/Gain'
                                                    *   '<S58>/ '
                                                    *   '<S58>/Gain3'
                                                    *   '<S81>/Saturation'
                                                    *   '<S81>/Saturation1'
                                                    *   '<S81>/Saturation2'
                                                    *   '<S124>/kd'
                                                    *   '<S124>/Saturation'
                                                    *   '<S125>/ki'
                                                    *   '<S125>/Discrete-Time Integrator'
                                                    *   '<S126>/kp'
                                                    *   '<S143>/kd'
                                                    *   '<S143>/Saturation'
                                                    *   '<S144>/Constant'
                                                    *   '<S144>/ki'
                                                    *   '<S144>/Discrete-Time Integrator'
                                                    *   '<S145>/kp'
                                                    *   '<S154>/Constant1'
                                                    *   '<S154>/Constant12'
                                                    *   '<S154>/Constant2'
                                                    *   '<S154>/Constant7'
                                                    *   '<S159>/Bias'
                                                    *   '<S159>/Bias1'
                                                    *   '<S159>/Bias2'
                                                    *   '<S159>/Bias3'
                                                    *   '<S160>/Bias'
                                                    *   '<S160>/Bias1'
                                                    *   '<S160>/Bias2'
                                                    *   '<S160>/Bias3'
                                                    *   '<S164>/Constant1'
                                                    *   '<S164>/Constant11'
                                                    *   '<S164>/Constant12'
                                                    *   '<S164>/Constant2'
                                                    *   '<S164>/Constant7'
                                                    *   '<S164>/Constant8'
                                                    *   '<S170>/Bias'
                                                    *   '<S170>/Bias1'
                                                    *   '<S170>/Bias2'
                                                    *   '<S170>/Bias3'
                                                    *   '<S171>/Bias'
                                                    *   '<S171>/Bias1'
                                                    *   '<S171>/Bias2'
                                                    *   '<S171>/Bias3'
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
                                                    *   '<S94>/Gain'
                                                    *   '<S94>/Gain1'
                                                    *   '<S106>/Constant1'
                                                    *   '<S106>/Constant2'
                                                    *   '<S99>/gain1'
                                                    *   '<S99>/gain2'
                                                    *   '<S99>/gain3'
                                                    *   '<S99>/Saturation'
                                                    *   '<S100>/gain1'
                                                    *   '<S100>/gain2'
                                                    *   '<S100>/gain3'
                                                    *   '<S100>/Discrete-Time Integrator'
                                                    *   '<S101>/gain1'
                                                    *   '<S101>/gain2'
                                                    *   '<S101>/gain3'
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
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S97>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S137>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S152>/Reshape' : Reshape block reduction
 * Block '<S149>/Reshape' : Reshape block reduction
 * Block '<S162>/Reshape' : Reshape block reduction
 * Block '<S150>/Reshape' : Reshape block reduction
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
 * '<S77>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Compare To Constant'
 * '<S78>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S79>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S80>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S81>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer'
 * '<S82>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S83>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Backward_Mixer'
 * '<S84>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Euler To Angle Rate'
 * '<S85>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed'
 * '<S86>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Forward_Mixer'
 * '<S87>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM'
 * '<S88>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S89>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_1'
 * '<S90>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_2'
 * '<S91>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_3'
 * '<S92>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S93>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S94>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S95>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Compare To Constant'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Compare To Zero'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S129>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S130>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S131>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S132>' : 'Controller/Controller/MC_Controller/Vertical_Control/Compare To Constant'
 * '<S133>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S134>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S135>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S136>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S137>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S138>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S139>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/Compare To Constant'
 * '<S140>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S141>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S142>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/Compare To Constant'
 * '<S143>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S144>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S145>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S146>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S147>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S148>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S149>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S150>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S151>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S152>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S153>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S154>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S155>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S156>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S157>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/P_Q_Remix'
 * '<S158>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/R_Remix'
 * '<S159>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S160>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S161>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S162>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S163>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S164>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S165>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S166>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S167>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix'
 * '<S168>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix1'
 * '<S169>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/R_Remix'
 * '<S170>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S171>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
