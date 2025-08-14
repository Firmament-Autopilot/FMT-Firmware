/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.430
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 13 14:18:47 2025
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
  real32_T Constant;                   /* '<S164>/Constant' */
  real32_T Constant_m;                 /* '<S51>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S121>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S143>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S148>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S150>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S119>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S123>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S143>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S161>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S164>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S166>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S161>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S59>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S56>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S55>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S26>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_f;/* '<S103>/Discrete-Time Integrator5' */
  real32_T _DSTATE;                    /* '<S98>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S99>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S24>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S28>/Discrete-Time Integrator1' */
  real32_T _DSTATE_d;                  /* '<S101>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S102>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_i;       /* '<S48>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S51>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S53>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTA_jo;/* '<S54>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S77>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S48>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S8>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S121>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S148>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S150>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S123>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S164>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S166>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S26>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S98>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S99>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S28>/Discrete-Time Integrator1' */
  int8_T _PrevResetState_e;            /* '<S101>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S102>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S51>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S53>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S77>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S150>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S119>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S123>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S166>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S59>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S56>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S55>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_n;/* '<S103>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S99>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S24>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S28>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S102>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S53>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S54>/Discrete-Time Integrator5' */
  boolean_T Relay_Mode;                /* '<S57>/Relay' */
  boolean_T Relay_Mode_m;              /* '<S10>/Relay' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T fw_torque_cmd[3];     /* '<S5>/Constant' */
  const real32_T fw_force_cmd[3];      /* '<S5>/Constant1' */
  const real32_T Constant[3];          /* '<S121>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S145>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S148>/Constant' */
  const real32_T Gain;                 /* '<S133>/Gain' */
  const real32_T Square;               /* '<S146>/Square' */
  const real32_T d;                    /* '<S146>/Multiply' */
  const real32_T Gain4;                /* '<S146>/Gain4' */
  const real32_T TmpBufferAtConstantOutport1;/* '<S155>/Constant' */
  const real32_T Square_h;             /* '<S162>/Square' */
  const real32_T d_i;                  /* '<S162>/Multiply' */
  const real32_T Gain4_p;              /* '<S162>/Gain4' */
  const real32_T VectorConcatenate3_g[3];/* '<S96>/Vector Concatenate3' */
  const real32_T Constant_j[3];        /* '<S26>/Constant' */
  const real32_T Square1;              /* '<S10>/Square1' */
  const real32_T Zero1;                /* '<S98>/Zero1' */
  const real32_T Gain_n;               /* '<S34>/Gain' */
  const real32_T Zero;                 /* '<S101>/Zero' */
  const real32_T Constant_c[3];        /* '<S77>/Constant' */
  const real32_T Square_h2;            /* '<S49>/Square' */
  const real32_T d_m;                  /* '<S49>/Multiply' */
  const real32_T Gain4_o;              /* '<S49>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S172>/Effective_Matrix'
   *   '<S182>/Effective_Matrix'
   */
  real32_T pooled5[12];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S180>/Disarm'
   *   '<S190>/Disarm'
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
extern struct_EmZSH4Jwlm4SR6cVayiT1B CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S68>/Saturation'
                                                    *   '<S69>/Gain'
                                                    *   '<S69>/Gain1'
                                                    *   '<S69>/balabnce_ratio2'
                                                    *   '<S69>/balance_ratio'
                                                    *   '<S69>/pitch_ff'
                                                    *   '<S69>/thorttle_ff'
                                                    *   '<S69>/ucmd2pitch'
                                                    *   '<S69>/ucmd2thor'
                                                    *   '<S69>/wcmd2pitch'
                                                    *   '<S69>/wcmd2thor'
                                                    *   '<S156>/hover_throttle'
                                                    *   '<S43>/hover_throttle'
                                                    *   '<S71>/FF'
                                                    *   '<S71>/FF_limit'
                                                    *   '<S71>/PI_limit'
                                                    *   '<S89>/P_control'
                                                    *   '<S90>/P_control'
                                                    *   '<S91>/Kv'
                                                    *   '<S138>/Saturation'
                                                    *   '<S171>/Bias1'
                                                    *   '<S171>/Bias2'
                                                    *   '<S171>/Bias3'
                                                    *   '<S171>/Bias4'
                                                    *   '<S181>/Bias1'
                                                    *   '<S181>/Bias2'
                                                    *   '<S181>/Bias3'
                                                    *   '<S181>/Bias4'
                                                    *   '<S20>/Saturation'
                                                    *   '<S20>/Saturation1'
                                                    *   '<S75>/trim_speed'
                                                    *   '<S76>/trim_speed'
                                                    *   '<S80>/Saturation'
                                                    *   '<S97>/Gain'
                                                    *   '<S98>/ '
                                                    *   '<S98>/Gain3'
                                                    *   '<S100>/Gain'
                                                    *   '<S101>/Gain'
                                                    *   '<S114>/Saturation'
                                                    *   '<S114>/Saturation1'
                                                    *   '<S147>/kd'
                                                    *   '<S147>/Saturation'
                                                    *   '<S148>/ki'
                                                    *   '<S148>/Discrete-Time Integrator'
                                                    *   '<S149>/kp'
                                                    *   '<S163>/kd'
                                                    *   '<S163>/Saturation'
                                                    *   '<S164>/Constant'
                                                    *   '<S164>/ki'
                                                    *   '<S164>/Discrete-Time Integrator'
                                                    *   '<S165>/kp'
                                                    *   '<S174>/Constant1'
                                                    *   '<S174>/Constant12'
                                                    *   '<S174>/Constant2'
                                                    *   '<S174>/Constant7'
                                                    *   '<S179>/Bias'
                                                    *   '<S179>/Bias1'
                                                    *   '<S179>/Bias2'
                                                    *   '<S179>/Bias3'
                                                    *   '<S180>/Bias'
                                                    *   '<S180>/Bias1'
                                                    *   '<S180>/Bias2'
                                                    *   '<S180>/Bias3'
                                                    *   '<S184>/Constant1'
                                                    *   '<S184>/Constant11'
                                                    *   '<S184>/Constant12'
                                                    *   '<S184>/Constant2'
                                                    *   '<S184>/Constant7'
                                                    *   '<S184>/Constant8'
                                                    *   '<S189>/Bias'
                                                    *   '<S189>/Bias1'
                                                    *   '<S189>/Bias2'
                                                    *   '<S189>/Bias3'
                                                    *   '<S190>/Bias'
                                                    *   '<S190>/Bias1'
                                                    *   '<S190>/Bias2'
                                                    *   '<S190>/Bias3'
                                                    *   '<S32>/Constant1'
                                                    *   '<S32>/Constant2'
                                                    *   '<S50>/kd'
                                                    *   '<S50>/Saturation'
                                                    *   '<S51>/Constant'
                                                    *   '<S51>/ki'
                                                    *   '<S51>/Discrete-Time Integrator'
                                                    *   '<S52>/kp'
                                                    *   '<S77>/gain1'
                                                    *   '<S77>/gain2'
                                                    *   '<S77>/gain3'
                                                    *   '<S77>/Discrete-Time Integrator'
                                                    *   '<S78>/gain1'
                                                    *   '<S78>/gain2'
                                                    *   '<S78>/gain3'
                                                    *   '<S82>/Pitch Offset'
                                                    *   '<S82>/Saturation'
                                                    *   '<S83>/Constant1'
                                                    *   '<S83>/Constant2'
                                                    *   '<S131>/Constant1'
                                                    *   '<S131>/Constant2'
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
                                                    *   '<S120>/gain1'
                                                    *   '<S120>/gain2'
                                                    *   '<S120>/gain3'
                                                    *   '<S120>/Saturation'
                                                    *   '<S121>/gain1'
                                                    *   '<S121>/gain2'
                                                    *   '<S121>/gain3'
                                                    *   '<S121>/Discrete-Time Integrator'
                                                    *   '<S122>/gain1'
                                                    *   '<S122>/gain2'
                                                    *   '<S122>/gain3'
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
 * Block '<S70>/Sum' : Unused code path elimination
 * Block '<S70>/cruise_throttle' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S46>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S54>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Reshape' : Reshape block reduction
 * Block '<S81>/Logical Operator1' : Eliminated due to no operation
 * Block '<S103>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S119>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S159>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S169>/Reshape' : Reshape block reduction
 * Block '<S170>/Reshape' : Reshape block reduction
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
 * '<S40>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S41>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Stabilize'
 * '<S42>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Stabilize'
 * '<S43>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S44>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S45>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S46>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S47>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S48>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S49>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S50>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S51>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S52>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S53>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S54>'  : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF'
 * '<S55>'  : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF1'
 * '<S56>'  : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF2'
 * '<S57>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed'
 * '<S58>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Compare To Zero'
 * '<S59>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/First Order LPF3'
 * '<S60>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction'
 * '<S61>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM'
 * '<S62>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize'
 * '<S63>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_1'
 * '<S64>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_2'
 * '<S65>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_3'
 * '<S66>'  : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S67>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S68>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S69>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S70>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S71>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S72>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S73>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S74>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S75>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S76>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S77>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S78>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S79>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S80>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S81>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S82>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S83>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S84>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S85>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S86>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S87>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S88>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S89>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S90>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S91>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S92>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S93>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S94>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S95>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S96>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S97>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S98>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S99>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S100>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S101>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S102>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S103>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/First Order LPF'
 * '<S104>' : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S105>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S106>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual_Command'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S108>' : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S129>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S130>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S131>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S132>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S133>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S134>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S135>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S136>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S137>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S138>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S139>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S140>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S141>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S142>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S143>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S144>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S145>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S146>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S147>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S148>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S149>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S150>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S151>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S152>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S153>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S154>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S155>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S156>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S157>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S158>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S159>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S160>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S161>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S162>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S163>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S164>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S165>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S166>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S167>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S168>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S169>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S170>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S171>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S172>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S173>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S174>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S175>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S176>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S177>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S178>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S179>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S180>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S181>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S182>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S183>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S184>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S185>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S186>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S187>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S188>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S189>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S190>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
