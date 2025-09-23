/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.799
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 23 16:31:22 2025
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
  real32_T Constant;                   /* '<S176>/Constant' */
  real32_T Multiply1[3];               /* '<S6>/Multiply1' */
  real32_T Reshape[3];                 /* '<S54>/Reshape' */
  real32_T Switch[6];                  /* '<S13>/Switch' */
  real32_T Multiply_c[3];              /* '<S5>/Multiply' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S10>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S9>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S134>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S154>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S159>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S161>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S131>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S136>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S154>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S173>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S176>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S178>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S173>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S101>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_c;       /* '<S70>/Integrator1' */
  real32_T Integrator1_DSTATE_j;       /* '<S73>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S59>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S97>/Discrete-Time Integrator1' */
  real32_T _DSTATE;                    /* '<S95>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S96>/Discrete-Time Integrator1' */
  real32_T _DSTATE_h;                  /* '<S92>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S93>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S73>/Integrator' */
  real32_T Integrator_DSTATE_n;        /* '<S70>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S134>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S159>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S161>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S136>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S176>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S178>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S59>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S97>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S95>/ ' */
  int8_T DiscreteTimeIntegrator1_Prev_dx;/* '<S96>/Discrete-Time Integrator1' */
  int8_T _PrevResetState_b;            /* '<S92>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S93>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S10>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S9>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S161>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;/* '<S131>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S136>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S178>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_i;/* '<S101>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_n;/* '<S97>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S96>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S93>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S2>/Relay' */
  boolean_T Relay1_Mode;               /* '<S2>/Relay1' */
  boolean_T MC_Controller_MODE;        /* '<S2>/MC_Controller' */
  boolean_T FW_Controller_MODE;        /* '<S2>/FW_Controller' */
} DW_Controller_T;

/* Invariant block signals for system '<S180>/VTOL1' */
#if AIRFRAME == 1

typedef struct {
  const real32_T Gain[12];             /* '<S184>/Gain' */
  const real32_T r_column[4];          /* '<S184>/r_column' */
  const real32_T pq_column[8];         /* '<S184>/pq_column' */
} ConstB_VTOL1_Controller_T;

#endif

/* Invariant block signals for system '<S180>/VTOL2' */
#if AIRFRAME == 2

typedef struct {
  const real32_T Gain[12];             /* '<S200>/Gain' */
  const real32_T r_column[4];          /* '<S200>/r_column' */
  const real32_T pq_column[8];         /* '<S200>/pq_column' */
} ConstB_VTOL2_Controller_T;

#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant[3];          /* '<S134>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S156>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S159>/Constant' */
  const real32_T Gain;                 /* '<S142>/Gain' */
  const real32_T Subtract;             /* '<S117>/Subtract' */
  const real32_T Divide;               /* '<S117>/Divide' */
  const real32_T Subtract_g;           /* '<S120>/Subtract' */
  const real32_T Divide_k;             /* '<S120>/Divide' */
  const real32_T Square;               /* '<S157>/Square' */
  const real32_T d;                    /* '<S157>/Multiply' */
  const real32_T Gain4;                /* '<S157>/Gain4' */
  const real32_T Square_h;             /* '<S174>/Square' */
  const real32_T d_i;                  /* '<S174>/Multiply' */
  const real32_T Gain4_p;              /* '<S174>/Gain4' */
  const real32_T Constant_c[3];        /* '<S59>/Constant' */
  const real32_T VectorConcatenate3_g[3];/* '<S90>/Vector Concatenate3' */
  const real32_T Zero;                 /* '<S95>/Zero' */
  const real32_T Zero1;                /* '<S92>/Zero1' */
  const real32_T Square_j;             /* '<S78>/Square' */
  const real32_T d_f;                  /* '<S78>/Multiply' */
  const real32_T Gain4_n;              /* '<S78>/Gain4' */
  const real32_T Square_c;             /* '<S71>/Square' */
  const real32_T d_ih;                 /* '<S71>/Multiply' */
  const real32_T Gain4_g;              /* '<S71>/Gain4' */

#if AIRFRAME == 2

  ConstB_VTOL2_Controller_T VTOL2;     /* '<S180>/VTOL2' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  ConstB_VTOL1_Controller_T VTOL1;     /* '<S180>/VTOL1' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S198>/Standby'
   *   '<S210>/Disarm'
   */
  real32_T pooled31[5];

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
                                                    *   '<S50>/Saturation'
                                                    *   '<S51>/balabnce_ratio2'
                                                    *   '<S51>/balance_ratio'
                                                    *   '<S51>/pitch_ff'
                                                    *   '<S51>/thorttle_ff'
                                                    *   '<S51>/ucmd2pitch'
                                                    *   '<S51>/ucmd2thor'
                                                    *   '<S51>/wcmd2pitch'
                                                    *   '<S51>/wcmd2thor'
                                                    *   '<S167>/hover_throttle'
                                                    *   '<S53>/FF'
                                                    *   '<S75>/P_control'
                                                    *   '<S76>/P_control'
                                                    *   '<S77>/Kv'
                                                    *   '<S147>/Saturation'
                                                    *   '<S183>/Bias1'
                                                    *   '<S183>/Bias2'
                                                    *   '<S183>/Bias3'
                                                    *   '<S183>/Bias4'
                                                    *   '<S183>/Saturation1'
                                                    *   '<S184>/Constant'
                                                    *   '<S184>/Constant1'
                                                    *   '<S184>/Saturation'
                                                    *   '<S199>/Bias1'
                                                    *   '<S199>/Bias2'
                                                    *   '<S199>/Bias3'
                                                    *   '<S199>/Bias4'
                                                    *   '<S199>/Saturation1'
                                                    *   '<S200>/Constant'
                                                    *   '<S200>/Constant1'
                                                    *   '<S200>/Saturation'
                                                    *   '<S57>/trim_speed'
                                                    *   '<S58>/trim_speed'
                                                    *   '<S62>/Saturation'
                                                    *   '<S91>/Gain'
                                                    *   '<S92>/ '
                                                    *   '<S92>/Gain3'
                                                    *   '<S94>/Gain'
                                                    *   '<S95>/Gain'
                                                    *   '<S115>/Saturation'
                                                    *   '<S115>/Saturation1'
                                                    *   '<S115>/Saturation2'
                                                    *   '<S158>/kd'
                                                    *   '<S158>/Saturation'
                                                    *   '<S159>/ki'
                                                    *   '<S159>/Discrete-Time Integrator'
                                                    *   '<S160>/kp'
                                                    *   '<S175>/kd'
                                                    *   '<S175>/Saturation'
                                                    *   '<S176>/Constant'
                                                    *   '<S176>/ki'
                                                    *   '<S176>/Discrete-Time Integrator'
                                                    *   '<S177>/kp'
                                                    *   '<S188>/Constant1'
                                                    *   '<S188>/Constant12'
                                                    *   '<S188>/Constant2'
                                                    *   '<S188>/Constant7'
                                                    *   '<S197>/Bias'
                                                    *   '<S197>/Bias1'
                                                    *   '<S197>/Bias2'
                                                    *   '<S197>/Bias3'
                                                    *   '<S198>/Bias'
                                                    *   '<S198>/Bias1'
                                                    *   '<S198>/Bias2'
                                                    *   '<S198>/Bias3'
                                                    *   '<S203>/Constant1'
                                                    *   '<S203>/Constant11'
                                                    *   '<S203>/Constant12'
                                                    *   '<S203>/Constant2'
                                                    *   '<S203>/Constant7'
                                                    *   '<S203>/Constant8'
                                                    *   '<S209>/Bias'
                                                    *   '<S209>/Bias1'
                                                    *   '<S209>/Bias2'
                                                    *   '<S209>/Bias3'
                                                    *   '<S210>/Bias'
                                                    *   '<S210>/Bias1'
                                                    *   '<S210>/Bias2'
                                                    *   '<S210>/Bias3'
                                                    *   '<S59>/gain1'
                                                    *   '<S59>/gain2'
                                                    *   '<S59>/gain3'
                                                    *   '<S59>/Discrete-Time Integrator'
                                                    *   '<S60>/gain1'
                                                    *   '<S60>/gain2'
                                                    *   '<S60>/gain3'
                                                    *   '<S64>/Pitch Offset'
                                                    *   '<S64>/Saturation'
                                                    *   '<S65>/Constant1'
                                                    *   '<S65>/Constant2'
                                                    *   '<S128>/Gain'
                                                    *   '<S128>/Gain1'
                                                    *   '<S140>/Constant1'
                                                    *   '<S140>/Constant2'
                                                    *   '<S133>/gain1'
                                                    *   '<S133>/gain2'
                                                    *   '<S133>/gain3'
                                                    *   '<S133>/Saturation'
                                                    *   '<S134>/gain1'
                                                    *   '<S134>/gain2'
                                                    *   '<S134>/gain3'
                                                    *   '<S134>/Discrete-Time Integrator'
                                                    *   '<S135>/gain1'
                                                    *   '<S135>/gain2'
                                                    *   '<S135>/gain3'
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
 * Block '<S98>/Data Type Conversion' : Unused code path elimination
 * Block '<S98>/Discrete-Time Integrator5' : Unused code path elimination
 * Block '<S98>/Gain' : Unused code path elimination
 * Block '<S98>/Sum5' : Unused code path elimination
 * Block '<S52>/Sum' : Unused code path elimination
 * Block '<S52>/cruise_throttle' : Unused code path elimination
 * Block '<S143>/Data Type Duplicate' : Unused code path elimination
 * Block '<S143>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S63>/Logical Operator1' : Eliminated due to no operation
 * Block '<S97>/Switch' : Eliminated due to constant selection input
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S131>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S170>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S184>/Reshape' : Reshape block reduction
 * Block '<S181>/Reshape' : Reshape block reduction
 * Block '<S200>/Reshape' : Reshape block reduction
 * Block '<S182>/Reshape' : Reshape block reduction
 * Block '<S97>/Gain1' : Unused code path elimination
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
 * '<S7>'   : 'Controller/Controller/Trigger'
 * '<S8>'   : 'Controller/Controller/VTOL_Control_Allocation'
 * '<S9>'   : 'Controller/Controller/ControlFactor/First Order LPF1'
 * '<S10>'  : 'Controller/Controller/ControlFactor/First Order LPF3'
 * '<S11>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller'
 * '<S12>'  : 'Controller/Controller/FW_Controller/FW_Controller'
 * '<S13>'  : 'Controller/Controller/FW_Controller/Signal_Select'
 * '<S14>'  : 'Controller/Controller/FW_Controller/True_FlySpeed'
 * '<S15>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S16>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S17>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S18>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S19>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S20>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S21>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S22>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S23>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S24>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S25>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S26>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S27>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S28>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S29>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S30>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S31>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S32>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S33>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S34>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S35>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S36>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S37>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S38>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S39>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S40>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S41>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S42>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S43>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S44>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S45>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S46>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S47>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S48>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S49>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S50>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S51>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S52>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S53>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S54>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S55>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S56>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S57>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S58>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S59>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S60>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S61>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S62>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S63>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S64>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S65>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S66>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S67>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S68>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S69>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S70>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control/TD'
 * '<S71>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control/TD/fhan '
 * '<S72>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/Compare To Constant'
 * '<S73>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/TD'
 * '<S74>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S75>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S76>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S77>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S78>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/TD/fhan '
 * '<S79>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S80>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed'
 * '<S81>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S82>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S83>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM'
 * '<S84>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S85>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_1'
 * '<S86>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_2'
 * '<S87>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_3'
 * '<S88>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S89>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S90>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S91>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S92>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S93>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S94>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S95>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S96>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S97>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/DT Filter'
 * '<S98>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/First Order LPF'
 * '<S99>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S100>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S101>' : 'Controller/Controller/FW_Controller/True_FlySpeed/First Order LPF3'
 * '<S102>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed'
 * '<S103>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM'
 * '<S104>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S105>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_1'
 * '<S106>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_2'
 * '<S107>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_3'
 * '<S108>' : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S110>' : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Backward_Mixer'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Euler To Angle Rate'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Forward_Mixer'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_1'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_2'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_3'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S129>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S130>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S131>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S132>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S133>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S134>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S135>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S136>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S137>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S138>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S139>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S140>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S141>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S142>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S143>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S144>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S145>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S146>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S147>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S148>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Compare To Constant'
 * '<S149>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S150>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S151>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S152>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S153>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Compare To Constant'
 * '<S154>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S155>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S156>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S157>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S158>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S159>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S160>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S161>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S162>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S163>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S164>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S165>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S166>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S167>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S168>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S169>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S170>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S171>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S172>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/Compare To Constant'
 * '<S173>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S174>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S175>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S176>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S177>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S178>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S179>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S180>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S181>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S182>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S183>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S184>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S185>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation1'
 * '<S186>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2'
 * '<S187>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S188>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S189>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S190>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S191>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/P_Q_Remix'
 * '<S192>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/R_Remix'
 * '<S193>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation1/throttle_mapping'
 * '<S194>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/MATLAB Function'
 * '<S195>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/MATLAB Function1'
 * '<S196>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/thrust_mapping'
 * '<S197>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S198>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S199>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S200>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S201>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation2'
 * '<S202>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S203>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S204>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S205>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S206>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix'
 * '<S207>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/R_Remix'
 * '<S208>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation2/throttle_mapping'
 * '<S209>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S210>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
