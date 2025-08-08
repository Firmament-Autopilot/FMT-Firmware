/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.423
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug  7 17:30:19 2025
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
  real32_T mc_torque_cmd[3];           /* '<S2>/Merge' */
  real32_T mc_force_cmd[3];            /* '<S2>/Merge' */
  real32_T fw_torque_cmd[3];           /* '<S2>/Merge' */
  real32_T fw_force_cmd[3];            /* '<S2>/Merge' */
  real32_T Constant;                   /* '<S167>/Constant' */
  real32_T Constant_m;                 /* '<S48>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S119>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S141>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S146>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S148>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S117>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S121>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S141>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S164>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S167>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S169>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S164>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S55>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S53>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S52>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S26>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_f;/* '<S99>/Discrete-Time Integrator5' */
  real32_T _DSTATE;                    /* '<S94>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S95>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S24>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S28>/Discrete-Time Integrator1' */
  real32_T _DSTATE_d;                  /* '<S97>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S98>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_i;       /* '<S45>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S48>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S50>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTA_jo;/* '<S51>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S73>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S45>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S8>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S119>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S146>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S148>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S121>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S167>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S169>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S26>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S94>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S95>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S28>/Discrete-Time Integrator1' */
  int8_T _PrevResetState_e;            /* '<S97>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S98>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S48>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S50>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S73>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S148>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S117>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S121>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S169>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S55>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S53>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S52>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_n;/* '<S99>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S95>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S24>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S28>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S98>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S50>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S51>/Discrete-Time Integrator5' */
  boolean_T Relay_Mode;                /* '<S54>/Relay' */
  boolean_T Relay_Mode_m;              /* '<S10>/Relay' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T fw_torque_cmd[3];     /* '<S5>/Constant' */
  const real32_T fw_force_cmd[3];      /* '<S5>/Constant1' */
  const real32_T Constant[3];          /* '<S119>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S143>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S146>/Constant' */
  const real32_T Gain;                 /* '<S131>/Gain' */
  const real32_T Square;               /* '<S144>/Square' */
  const real32_T d;                    /* '<S144>/Multiply' */
  const real32_T Gain4;                /* '<S144>/Gain4' */
  const real32_T TmpBufferAtConstantOutport1;/* '<S158>/Constant' */
  const real32_T Square_h;             /* '<S165>/Square' */
  const real32_T d_i;                  /* '<S165>/Multiply' */
  const real32_T Gain4_p;              /* '<S165>/Gain4' */
  const real32_T VectorConcatenate3_g[3];/* '<S92>/Vector Concatenate3' */
  const real32_T Constant_j[3];        /* '<S26>/Constant' */
  const real32_T Square1;              /* '<S10>/Square1' */
  const real32_T Zero1;                /* '<S94>/Zero1' */
  const real32_T Gain_n;               /* '<S34>/Gain' */
  const real32_T Zero;                 /* '<S97>/Zero' */
  const real32_T Constant_c[3];        /* '<S73>/Constant' */
  const real32_T Square_h2;            /* '<S46>/Square' */
  const real32_T d_m;                  /* '<S46>/Multiply' */
  const real32_T Gain4_o;              /* '<S46>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S175>/Effective_Matrix'
   *   '<S184>/Effective_Matrix'
   */
  real32_T pooled5[12];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S182>/Disarm'
   *   '<S191>/Disarm'
   */
  real32_T pooled7[5];

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
extern struct_wPl8ajGklGKyYxGcwjdpiH CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S64>/Saturation'
                                                    *   '<S65>/Gain'
                                                    *   '<S65>/Gain1'
                                                    *   '<S65>/balabnce_ratio2'
                                                    *   '<S65>/balance_ratio'
                                                    *   '<S65>/pitch_ff'
                                                    *   '<S65>/thorttle_ff'
                                                    *   '<S65>/ucmd2pitch'
                                                    *   '<S65>/ucmd2thor'
                                                    *   '<S65>/wcmd2pitch'
                                                    *   '<S65>/wcmd2thor'
                                                    *   '<S159>/hover_throttle'
                                                    *   '<S40>/hover_throttle'
                                                    *   '<S67>/FF'
                                                    *   '<S67>/FF_limit'
                                                    *   '<S67>/PI_limit'
                                                    *   '<S85>/P_control'
                                                    *   '<S86>/P_control'
                                                    *   '<S87>/Kv'
                                                    *   '<S136>/Saturation'
                                                    *   '<S174>/Bias1'
                                                    *   '<S174>/Bias2'
                                                    *   '<S174>/Bias3'
                                                    *   '<S174>/Bias4'
                                                    *   '<S183>/Bias1'
                                                    *   '<S183>/Bias2'
                                                    *   '<S183>/Bias3'
                                                    *   '<S183>/Bias4'
                                                    *   '<S20>/Saturation'
                                                    *   '<S20>/Saturation1'
                                                    *   '<S71>/trim_speed'
                                                    *   '<S72>/trim_speed'
                                                    *   '<S93>/Gain'
                                                    *   '<S94>/ '
                                                    *   '<S94>/Gain3'
                                                    *   '<S96>/Gain'
                                                    *   '<S97>/Gain'
                                                    *   '<S112>/Saturation'
                                                    *   '<S112>/Saturation1'
                                                    *   '<S145>/kd'
                                                    *   '<S145>/Saturation'
                                                    *   '<S146>/ki'
                                                    *   '<S146>/Discrete-Time Integrator'
                                                    *   '<S147>/kp'
                                                    *   '<S166>/kd'
                                                    *   '<S166>/Saturation'
                                                    *   '<S167>/Constant'
                                                    *   '<S167>/ki'
                                                    *   '<S167>/Discrete-Time Integrator'
                                                    *   '<S168>/kp'
                                                    *   '<S177>/Constant1'
                                                    *   '<S177>/Constant12'
                                                    *   '<S177>/Constant2'
                                                    *   '<S177>/Constant7'
                                                    *   '<S181>/Bias'
                                                    *   '<S181>/Bias1'
                                                    *   '<S181>/Bias2'
                                                    *   '<S181>/Bias3'
                                                    *   '<S182>/Bias'
                                                    *   '<S182>/Bias1'
                                                    *   '<S182>/Bias2'
                                                    *   '<S182>/Bias3'
                                                    *   '<S186>/Constant1'
                                                    *   '<S186>/Constant11'
                                                    *   '<S186>/Constant12'
                                                    *   '<S186>/Constant2'
                                                    *   '<S186>/Constant7'
                                                    *   '<S186>/Constant8'
                                                    *   '<S190>/Bias'
                                                    *   '<S190>/Bias1'
                                                    *   '<S190>/Bias2'
                                                    *   '<S190>/Bias3'
                                                    *   '<S191>/Bias'
                                                    *   '<S191>/Bias1'
                                                    *   '<S191>/Bias2'
                                                    *   '<S191>/Bias3'
                                                    *   '<S32>/Constant1'
                                                    *   '<S32>/Constant2'
                                                    *   '<S47>/kd'
                                                    *   '<S47>/Saturation'
                                                    *   '<S48>/Constant'
                                                    *   '<S48>/ki'
                                                    *   '<S48>/Discrete-Time Integrator'
                                                    *   '<S49>/kp'
                                                    *   '<S73>/gain1'
                                                    *   '<S73>/gain2'
                                                    *   '<S73>/gain3'
                                                    *   '<S73>/Discrete-Time Integrator'
                                                    *   '<S74>/gain1'
                                                    *   '<S74>/gain2'
                                                    *   '<S74>/gain3'
                                                    *   '<S78>/Pitch Offset'
                                                    *   '<S78>/Saturation'
                                                    *   '<S79>/Constant1'
                                                    *   '<S79>/Constant2'
                                                    *   '<S129>/Constant1'
                                                    *   '<S129>/Constant2'
                                                    *   '<S25>/gain1'
                                                    *   '<S25>/gain2'
                                                    *   '<S25>/gain3'
                                                    *   '<S25>/Saturation'
                                                    *   '<S26>/gain1'
                                                    *   '<S26>/gain2'
                                                    *   '<S26>/gain3'
                                                    *   '<S26>/Discrete-Time Integrator'
                                                    *   '<S27>/gain1'
                                                    *   '<S27>/gain2'
                                                    *   '<S27>/gain3'
                                                    *   '<S118>/gain1'
                                                    *   '<S118>/gain2'
                                                    *   '<S118>/gain3'
                                                    *   '<S118>/Saturation'
                                                    *   '<S119>/gain1'
                                                    *   '<S119>/gain2'
                                                    *   '<S119>/gain3'
                                                    *   '<S119>/Discrete-Time Integrator'
                                                    *   '<S120>/gain1'
                                                    *   '<S120>/gain2'
                                                    *   '<S120>/gain3'
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
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S35>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Sum' : Unused code path elimination
 * Block '<S66>/cruise_throttle' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S51>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S68>/Reshape' : Reshape block reduction
 * Block '<S77>/Logical Operator1' : Eliminated due to no operation
 * Block '<S99>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S117>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S162>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S172>/Reshape' : Reshape block reduction
 * Block '<S173>/Reshape' : Reshape block reduction
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
 * '<S6>'   : 'Controller/Controller/VTOL_Control_Allocation'
 * '<S7>'   : 'Controller/Controller/ctrl_mode_mask'
 * '<S8>'   : 'Controller/Controller/switch-case'
 * '<S9>'   : 'Controller/Controller/FW_Controller/Aux_MC_Controller'
 * '<S10>'  : 'Controller/Controller/FW_Controller/Effective_Factor'
 * '<S11>'  : 'Controller/Controller/FW_Controller/FW_Controller'
 * '<S12>'  : 'Controller/Controller/FW_Controller/Signal_Select'
 * '<S13>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S14>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S15>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S16>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S17>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S18>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S19>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S20>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S21>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S22>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S23>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S24>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S25>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S26>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S27>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S28>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S29>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S30>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S31>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S32>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S33>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S34>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S35>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S36>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S37>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S38>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S39>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S40>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S41>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S42>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S43>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S44>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S45>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S46>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S47>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S48>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S49>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S50>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S51>'  : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF'
 * '<S52>'  : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF1'
 * '<S53>'  : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF2'
 * '<S54>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed'
 * '<S55>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/First Order LPF3'
 * '<S56>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction'
 * '<S57>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM'
 * '<S58>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize'
 * '<S59>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_1'
 * '<S60>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_2'
 * '<S61>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_3'
 * '<S62>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S63>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S64>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S65>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S66>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S67>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S68>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S69>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S70>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S71>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S72>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S73>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S74>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S75>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S76>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S77>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S78>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S79>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S80>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S81>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S82>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S83>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S84>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S85>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S86>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S87>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S88>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S89>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S90>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S91>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S92>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S93>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S94>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S95>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S96>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S97>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S98>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S99>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/First Order LPF'
 * '<S100>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S101>' : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S102>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S103>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual_Command'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S105>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S106>' : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S129>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S130>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S131>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S132>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S133>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S134>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S135>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S136>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S137>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S138>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S139>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S140>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S141>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S142>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S143>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S144>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S145>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S146>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S147>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S148>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S149>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S150>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S151>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S152>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S153>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S154>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S155>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S156>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S157>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S158>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S159>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S160>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S161>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S162>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S163>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S164>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S165>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S166>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S167>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S168>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S169>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S170>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S171>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S172>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S173>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S174>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S175>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S176>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S177>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S178>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S179>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S180>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S181>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S182>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S183>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S184>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S185>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S186>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S187>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S188>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S189>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S190>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S191>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
