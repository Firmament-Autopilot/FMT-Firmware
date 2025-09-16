/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.724
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 15 11:14:44 2025
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
  real32_T Multiply[3];                /* '<S5>/Multiply' */
  real32_T Constant;                   /* '<S156>/Constant' */
  real32_T Multiply1[3];               /* '<S5>/Multiply1' */
  real32_T Reshape[3];                 /* '<S52>/Reshape' */
  real32_T Switch[6];                  /* '<S12>/Switch' */
  real32_T Multiply_c[3];              /* '<S4>/Multiply' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S160>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S159>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE[3];      /* '<S117>/Integrator1' */
  real32_T Integrator1_DSTATE_e[2];    /* '<S135>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S140>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S142>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[3];       /* '<S117>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b[3];/* '<S111>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S108>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S113>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_l[2];     /* '<S135>/Integrator' */
  real32_T Integrator1_DSTATE_eq;      /* '<S153>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S156>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S158>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S153>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S87>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_f;/* '<S84>/Discrete-Time Integrator5' */
  real32_T _DSTATE;                    /* '<S79>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S80>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S57>/Discrete-Time Integrator' */
  real32_T _DSTATE_d;                  /* '<S82>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S83>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S140>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S142>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S111>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S113>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S156>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S158>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S79>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S80>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S57>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S82>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S83>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S160>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S159>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S142>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;/* '<S108>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S113>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S158>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_i;/* '<S87>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_n;/* '<S84>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S80>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S83>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S11>/Relay' */
  boolean_T MC_Controller_MODE;        /* '<S2>/MC_Controller' */
  boolean_T FW_Controller_MODE;        /* '<S2>/FW_Controller' */
} DW_Controller_T;

/* Invariant block signals for system '<S164>/VTOL1' */
#if AIRFRAME == 1

typedef struct {
  const real32_T Gain[12];             /* '<S168>/Gain' */
  const real32_T r_column[4];          /* '<S168>/r_column' */
  const real32_T pq_column[8];         /* '<S168>/pq_column' */
} ConstB_VTOL1_Controller_T;

#endif

/* Invariant block signals for system '<S164>/VTOL2' */
#if AIRFRAME == 2

typedef struct {
  const real32_T Gain[12];             /* '<S184>/Gain' */
  const real32_T r_column[4];          /* '<S184>/r_column' */
  const real32_T pq_column[8];         /* '<S184>/pq_column' */
} ConstB_VTOL2_Controller_T;

#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S137>/Vector Concatenate3' */
  const real32_T Constant;             /* '<S140>/Constant' */
  const real32_T Gain;                 /* '<S124>/Gain' */
  const real32_T Square;               /* '<S118>/Square' */
  const real32_T d;                    /* '<S118>/Multiply' */
  const real32_T Gain4;                /* '<S118>/Gain4' */
  const real32_T Constant_a[3];        /* '<S111>/Constant' */
  const real32_T Square_o;             /* '<S138>/Square' */
  const real32_T d_f;                  /* '<S138>/Multiply' */
  const real32_T Gain4_b;              /* '<S138>/Gain4' */
  const real32_T Square_h;             /* '<S154>/Square' */
  const real32_T d_i;                  /* '<S154>/Multiply' */
  const real32_T Gain4_p;              /* '<S154>/Gain4' */
  const real32_T VectorConcatenate3_g[3];/* '<S77>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S79>/Zero1' */
  const real32_T Constant_c[3];        /* '<S57>/Constant' */
  const real32_T Zero;                 /* '<S82>/Zero' */

#if AIRFRAME == 2

  ConstB_VTOL2_Controller_T VTOL2;     /* '<S164>/VTOL2' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  ConstB_VTOL1_Controller_T VTOL1;     /* '<S164>/VTOL1' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S182>/Standby'
   *   '<S194>/Disarm'
   */
  real32_T pooled29[5];

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
extern struct_bbisFpyguPkQQvdqSWKvqB CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S48>/Saturation'
                                                    *   '<S49>/balabnce_ratio2'
                                                    *   '<S49>/balance_ratio'
                                                    *   '<S49>/pitch_ff'
                                                    *   '<S49>/thorttle_ff'
                                                    *   '<S49>/ucmd2pitch'
                                                    *   '<S49>/ucmd2thor'
                                                    *   '<S49>/wcmd2pitch'
                                                    *   '<S49>/wcmd2thor'
                                                    *   '<S148>/hover_throttle'
                                                    *   '<S51>/FF'
                                                    *   '<S70>/P_control'
                                                    *   '<S71>/P_control'
                                                    *   '<S72>/Kv'
                                                    *   '<S129>/Saturation'
                                                    *   '<S167>/Bias1'
                                                    *   '<S167>/Bias2'
                                                    *   '<S167>/Bias3'
                                                    *   '<S167>/Bias4'
                                                    *   '<S167>/Saturation1'
                                                    *   '<S168>/Constant'
                                                    *   '<S168>/Constant1'
                                                    *   '<S168>/Saturation'
                                                    *   '<S183>/Bias1'
                                                    *   '<S183>/Bias2'
                                                    *   '<S183>/Bias3'
                                                    *   '<S183>/Bias4'
                                                    *   '<S183>/Saturation1'
                                                    *   '<S184>/Constant'
                                                    *   '<S184>/Constant1'
                                                    *   '<S184>/Saturation'
                                                    *   '<S55>/trim_speed'
                                                    *   '<S56>/trim_speed'
                                                    *   '<S60>/Saturation'
                                                    *   '<S78>/Gain'
                                                    *   '<S79>/ '
                                                    *   '<S79>/Gain3'
                                                    *   '<S81>/Gain'
                                                    *   '<S82>/Gain'
                                                    *   '<S103>/Saturation'
                                                    *   '<S103>/Saturation1'
                                                    *   '<S103>/Saturation2'
                                                    *   '<S139>/kd'
                                                    *   '<S139>/Saturation'
                                                    *   '<S140>/ki'
                                                    *   '<S140>/Discrete-Time Integrator'
                                                    *   '<S141>/kp'
                                                    *   '<S155>/kd'
                                                    *   '<S155>/Saturation'
                                                    *   '<S156>/Constant'
                                                    *   '<S156>/ki'
                                                    *   '<S156>/Discrete-Time Integrator'
                                                    *   '<S157>/kp'
                                                    *   '<S172>/Constant1'
                                                    *   '<S172>/Constant12'
                                                    *   '<S172>/Constant2'
                                                    *   '<S172>/Constant7'
                                                    *   '<S181>/Bias'
                                                    *   '<S181>/Bias1'
                                                    *   '<S181>/Bias2'
                                                    *   '<S181>/Bias3'
                                                    *   '<S182>/Bias'
                                                    *   '<S182>/Bias1'
                                                    *   '<S182>/Bias2'
                                                    *   '<S182>/Bias3'
                                                    *   '<S187>/Constant1'
                                                    *   '<S187>/Constant11'
                                                    *   '<S187>/Constant12'
                                                    *   '<S187>/Constant2'
                                                    *   '<S187>/Constant7'
                                                    *   '<S187>/Constant8'
                                                    *   '<S193>/Bias'
                                                    *   '<S193>/Bias1'
                                                    *   '<S193>/Bias2'
                                                    *   '<S193>/Bias3'
                                                    *   '<S194>/Bias'
                                                    *   '<S194>/Bias1'
                                                    *   '<S194>/Bias2'
                                                    *   '<S194>/Bias3'
                                                    *   '<S57>/gain1'
                                                    *   '<S57>/gain2'
                                                    *   '<S57>/gain3'
                                                    *   '<S57>/Discrete-Time Integrator'
                                                    *   '<S58>/gain1'
                                                    *   '<S58>/gain2'
                                                    *   '<S58>/gain3'
                                                    *   '<S62>/Pitch Offset'
                                                    *   '<S62>/Saturation'
                                                    *   '<S63>/Constant1'
                                                    *   '<S63>/Constant2'
                                                    *   '<S105>/Gain'
                                                    *   '<S105>/Gain1'
                                                    *   '<S122>/Constant1'
                                                    *   '<S122>/Constant2'
                                                    *   '<S110>/gain1'
                                                    *   '<S110>/gain2'
                                                    *   '<S110>/gain3'
                                                    *   '<S110>/Saturation'
                                                    *   '<S111>/gain1'
                                                    *   '<S111>/gain2'
                                                    *   '<S111>/gain3'
                                                    *   '<S111>/Discrete-Time Integrator'
                                                    *   '<S112>/gain1'
                                                    *   '<S112>/gain2'
                                                    *   '<S112>/gain3'
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
 * Block '<S50>/Sum' : Unused code path elimination
 * Block '<S50>/cruise_throttle' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Logical Operator1' : Eliminated due to no operation
 * Block '<S84>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S151>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S159>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S168>/Reshape' : Reshape block reduction
 * Block '<S165>/Reshape' : Reshape block reduction
 * Block '<S184>/Reshape' : Reshape block reduction
 * Block '<S166>/Reshape' : Reshape block reduction
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
 * '<S4>'   : 'Controller/Controller/FW_Controller'
 * '<S5>'   : 'Controller/Controller/MC_Controller'
 * '<S6>'   : 'Controller/Controller/Subsystem'
 * '<S7>'   : 'Controller/Controller/Trigger'
 * '<S8>'   : 'Controller/Controller/VTOL_Control_Allocation'
 * '<S9>'   : 'Controller/Controller/FW_Controller/Aux_MC_Controller'
 * '<S10>'  : 'Controller/Controller/FW_Controller/FW_Controller'
 * '<S11>'  : 'Controller/Controller/FW_Controller/Fly_Speed'
 * '<S12>'  : 'Controller/Controller/FW_Controller/Signal_Select'
 * '<S13>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S14>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S15>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S16>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S17>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S18>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S19>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S20>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S21>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S22>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S23>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S24>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S25>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S26>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S27>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S28>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S29>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S30>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S31>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S32>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S33>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S34>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S35>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S36>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S37>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S38>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S39>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S40>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S41>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S42>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S43>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S44>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S45>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S46>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S47>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S48>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S49>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S50>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S51>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S52>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S53>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S54>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S55>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S56>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S57>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S58>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S59>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S60>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S61>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S62>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S63>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S64>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S65>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S66>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S67>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S68>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/Compare To Constant'
 * '<S69>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S70>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S71>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S72>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S73>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S74>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S75>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S76>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S77>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S78>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S79>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S80>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S81>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S82>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S83>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S84>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/First Order LPF'
 * '<S85>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S86>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Compare To Zero'
 * '<S87>'  : 'Controller/Controller/FW_Controller/Fly_Speed/First Order LPF3'
 * '<S88>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction'
 * '<S89>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction/Quaternion To DCM'
 * '<S90>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize'
 * '<S91>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction/Quaternion To DCM/column_1'
 * '<S92>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction/Quaternion To DCM/column_2'
 * '<S93>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction/Quaternion To DCM/column_3'
 * '<S94>'  : 'Controller/Controller/FW_Controller/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S95>'  : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/First Order LPF'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Multicopter'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/TD'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/TD/fhan '
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S129>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S130>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Compare To Constant'
 * '<S131>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S132>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S133>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S134>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S135>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S136>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S137>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S138>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S139>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S140>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S141>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S142>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S143>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S144>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S145>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S146>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S147>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S148>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S149>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S150>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S151>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S152>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S153>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S154>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S155>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S156>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S157>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S158>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S159>' : 'Controller/Controller/Subsystem/First Order LPF1'
 * '<S160>' : 'Controller/Controller/Subsystem/First Order LPF3'
 * '<S161>' : 'Controller/Controller/Trigger/Compare To Constant'
 * '<S162>' : 'Controller/Controller/Trigger/Compare To Constant1'
 * '<S163>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S164>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S165>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S166>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S167>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S168>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S169>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation1'
 * '<S170>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2'
 * '<S171>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S172>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S173>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S174>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S175>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/P_Q_Remix'
 * '<S176>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/R_Remix'
 * '<S177>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation1/throttle_mapping'
 * '<S178>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/MATLAB Function'
 * '<S179>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/MATLAB Function1'
 * '<S180>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/thrust_mapping'
 * '<S181>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S182>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S183>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S184>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S185>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation2'
 * '<S186>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S187>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S188>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S189>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S190>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix'
 * '<S191>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/R_Remix'
 * '<S192>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation2/throttle_mapping'
 * '<S193>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S194>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
