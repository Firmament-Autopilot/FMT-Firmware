/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.358
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jul 17 15:44:51 2025
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
  real32_T Constant;                   /* '<S237>/Constant' */
  real32_T Constant_m;                 /* '<S110>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S189>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S211>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S216>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S218>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S187>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S191>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S211>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S234>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S237>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S239>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S234>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S117>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S115>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S114>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S87>/Discrete-Time Integrator' */
  real32_T _DSTATE;                    /* '<S158>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S159>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S85>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S89>/Discrete-Time Integrator1' */
  real32_T _DSTATE_d;                  /* '<S161>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S162>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_i;       /* '<S107>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S110>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S112>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTA_jo;/* '<S113>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S135>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S107>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S9>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S189>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S216>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S218>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S191>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S237>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S239>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S87>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S158>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S159>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S89>/Discrete-Time Integrator1' */
  int8_T _PrevResetState_e;            /* '<S161>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S162>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S110>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S112>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S135>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S218>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S187>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S191>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S239>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S117>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S115>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S114>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S159>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S85>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S89>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S162>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S112>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S113>/Discrete-Time Integrator5' */
  boolean_T Relay_Mode;                /* '<S71>/Relay' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T fw_torque_cmd[3];     /* '<S6>/Constant' */
  const real32_T fw_force_cmd[3];      /* '<S6>/Constant1' */
  const real32_T Constant[3];          /* '<S189>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S213>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S216>/Constant' */
  const real32_T Gain;                 /* '<S201>/Gain' */
  const real32_T Square;               /* '<S214>/Square' */
  const real32_T d;                    /* '<S214>/Multiply' */
  const real32_T Gain4;                /* '<S214>/Gain4' */
  const real32_T TmpBufferAtConstantOutport1;/* '<S228>/Constant' */
  const real32_T Square_h;             /* '<S235>/Square' */
  const real32_T d_i;                  /* '<S235>/Multiply' */
  const real32_T Gain4_p;              /* '<S235>/Gain4' */
  const real32_T VectorConcatenate3_g[3];/* '<S155>/Vector Concatenate3' */
  const real32_T Constant_j[3];        /* '<S87>/Constant' */
  const real32_T Square1;              /* '<S71>/Square1' */
  const real32_T Zero1;                /* '<S158>/Zero1' */
  const real32_T Gain_n;               /* '<S95>/Gain' */
  const real32_T Zero;                 /* '<S161>/Zero' */
  const real32_T Constant_c[3];        /* '<S135>/Constant' */
  const real32_T Square_h2;            /* '<S108>/Square' */
  const real32_T d_m;                  /* '<S108>/Multiply' */
  const real32_T Gain4_o;              /* '<S108>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S245>/Effective_Matrix'
   *   '<S254>/Effective_Matrix'
   */
  real32_T pooled5[12];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S252>/Disarm'
   *   '<S261>/Disarm'
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
extern struct_QRK8c3803lO9d4oZFNG08F CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S126>/Saturation'
                                                    *   '<S127>/Gain'
                                                    *   '<S127>/Gain1'
                                                    *   '<S127>/balabnce_ratio2'
                                                    *   '<S127>/balance_ratio'
                                                    *   '<S127>/pitch_ff'
                                                    *   '<S127>/thorttle_ff'
                                                    *   '<S127>/ucmd2pitch'
                                                    *   '<S127>/ucmd2thor'
                                                    *   '<S127>/wcmd2pitch'
                                                    *   '<S127>/wcmd2thor'
                                                    *   '<S128>/cruise_throttle'
                                                    *   '<S229>/hover_throttle'
                                                    *   '<S102>/hover_throttle'
                                                    *   '<S129>/FF'
                                                    *   '<S129>/FF_limit'
                                                    *   '<S129>/PI_limit'
                                                    *   '<S148>/P_control'
                                                    *   '<S149>/P_control'
                                                    *   '<S206>/Saturation'
                                                    *   '<S244>/Bias1'
                                                    *   '<S244>/Bias2'
                                                    *   '<S244>/Bias3'
                                                    *   '<S244>/Bias4'
                                                    *   '<S253>/Bias1'
                                                    *   '<S253>/Bias2'
                                                    *   '<S253>/Bias3'
                                                    *   '<S253>/Bias4'
                                                    *   '<S81>/Saturation'
                                                    *   '<S81>/Saturation1'
                                                    *   '<S133>/trim_speed'
                                                    *   '<S134>/trim_speed'
                                                    *   '<S157>/Gain'
                                                    *   '<S158>/ '
                                                    *   '<S158>/Gain3'
                                                    *   '<S160>/Gain'
                                                    *   '<S161>/ '
                                                    *   '<S161>/Gain'
                                                    *   '<S182>/Saturation'
                                                    *   '<S182>/Saturation1'
                                                    *   '<S215>/kd'
                                                    *   '<S215>/Saturation'
                                                    *   '<S216>/ki'
                                                    *   '<S216>/Discrete-Time Integrator'
                                                    *   '<S217>/kp'
                                                    *   '<S236>/kd'
                                                    *   '<S236>/Saturation'
                                                    *   '<S237>/Constant'
                                                    *   '<S237>/ki'
                                                    *   '<S237>/Discrete-Time Integrator'
                                                    *   '<S238>/kp'
                                                    *   '<S247>/Constant1'
                                                    *   '<S247>/Constant12'
                                                    *   '<S247>/Constant2'
                                                    *   '<S247>/Constant7'
                                                    *   '<S251>/Bias'
                                                    *   '<S251>/Bias1'
                                                    *   '<S251>/Bias2'
                                                    *   '<S251>/Bias3'
                                                    *   '<S252>/Bias'
                                                    *   '<S252>/Bias1'
                                                    *   '<S252>/Bias2'
                                                    *   '<S252>/Bias3'
                                                    *   '<S256>/Constant1'
                                                    *   '<S256>/Constant11'
                                                    *   '<S256>/Constant12'
                                                    *   '<S256>/Constant2'
                                                    *   '<S256>/Constant7'
                                                    *   '<S256>/Constant8'
                                                    *   '<S260>/Bias'
                                                    *   '<S260>/Bias1'
                                                    *   '<S260>/Bias2'
                                                    *   '<S260>/Bias3'
                                                    *   '<S261>/Bias'
                                                    *   '<S261>/Bias1'
                                                    *   '<S261>/Bias2'
                                                    *   '<S261>/Bias3'
                                                    *   '<S93>/Constant1'
                                                    *   '<S93>/Constant2'
                                                    *   '<S109>/kd'
                                                    *   '<S109>/Saturation'
                                                    *   '<S110>/Constant'
                                                    *   '<S110>/ki'
                                                    *   '<S110>/Discrete-Time Integrator'
                                                    *   '<S111>/kp'
                                                    *   '<S135>/gain1'
                                                    *   '<S135>/gain2'
                                                    *   '<S135>/gain3'
                                                    *   '<S135>/Discrete-Time Integrator'
                                                    *   '<S136>/gain1'
                                                    *   '<S136>/gain2'
                                                    *   '<S136>/gain3'
                                                    *   '<S140>/Pitch Offset'
                                                    *   '<S140>/Saturation'
                                                    *   '<S141>/Constant1'
                                                    *   '<S141>/Constant2'
                                                    *   '<S199>/Constant1'
                                                    *   '<S199>/Constant2'
                                                    *   '<S86>/gain1'
                                                    *   '<S86>/gain2'
                                                    *   '<S86>/gain3'
                                                    *   '<S86>/Saturation'
                                                    *   '<S87>/gain1'
                                                    *   '<S87>/gain2'
                                                    *   '<S87>/gain3'
                                                    *   '<S87>/Discrete-Time Integrator'
                                                    *   '<S88>/gain1'
                                                    *   '<S88>/gain2'
                                                    *   '<S88>/gain3'
                                                    *   '<S188>/gain1'
                                                    *   '<S188>/gain2'
                                                    *   '<S188>/gain3'
                                                    *   '<S188>/Saturation'
                                                    *   '<S189>/gain1'
                                                    *   '<S189>/gain2'
                                                    *   '<S189>/gain3'
                                                    *   '<S189>/Discrete-Time Integrator'
                                                    *   '<S190>/gain1'
                                                    *   '<S190>/gain2'
                                                    *   '<S190>/gain3'
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
 * Block '<S96>/Data Type Duplicate' : Unused code path elimination
 * Block '<S96>/Data Type Propagation' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S85>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S105>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S113>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S115>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S117>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S130>/Reshape' : Reshape block reduction
 * Block '<S139>/Logical Operator1' : Eliminated due to no operation
 * Block '<S147>/Logical Operator' : Eliminated due to no operation
 * Block '<S187>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S232>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S242>/Reshape' : Reshape block reduction
 * Block '<S243>/Reshape' : Reshape block reduction
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
 * '<S4>'   : 'Controller/Controller/BackTrans_Controller'
 * '<S5>'   : 'Controller/Controller/FW_Controller'
 * '<S6>'   : 'Controller/Controller/MC_Controller'
 * '<S7>'   : 'Controller/Controller/VTOL_Control_Allocation'
 * '<S8>'   : 'Controller/Controller/ctrl_mode_mask'
 * '<S9>'   : 'Controller/Controller/switch-case'
 * '<S10>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller'
 * '<S11>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation'
 * '<S12>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control'
 * '<S13>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S14>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S15>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S16>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S17>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S18>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S19>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S20>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S21>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S22>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S23>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S24>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S25>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S26>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S27>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S28>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S29>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S30>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S31>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S32>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S33>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S34>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S35>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S36>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S37>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S38>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S39>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S40>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S41>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S42>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S43>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S44>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S45>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S46>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S47>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S48>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S49>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S50>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S51>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S52>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S53>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S54>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S55>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S56>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S57>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S58>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S59>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S60>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S61>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S62>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S63>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S64>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S65>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S66>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S67>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S68>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S69>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 * '<S70>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller'
 * '<S71>'  : 'Controller/Controller/FW_Controller/Effective_Factor'
 * '<S72>'  : 'Controller/Controller/FW_Controller/FW_Controller'
 * '<S73>'  : 'Controller/Controller/FW_Controller/Signal_Select'
 * '<S74>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S75>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S76>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S77>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S78>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S79>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S80>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S81>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S82>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S83>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S84>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S85>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S86>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S87>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S88>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S89>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S90>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S91>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S92>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S93>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S94>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S95>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S96>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S97>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S98>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S99>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S100>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S101>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S102>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S103>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S104>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S105>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S106>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S107>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S108>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S109>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S110>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S111>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S112>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S113>' : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF'
 * '<S114>' : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF1'
 * '<S115>' : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF2'
 * '<S116>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed'
 * '<S117>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/First Order LPF3'
 * '<S118>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction'
 * '<S119>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM'
 * '<S120>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize'
 * '<S121>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_1'
 * '<S122>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_2'
 * '<S123>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/column_3'
 * '<S124>' : 'Controller/Controller/FW_Controller/Effective_Factor/Fly_Speed/Fly_Direction/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S125>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S126>' : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S127>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S128>' : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S129>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S130>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S131>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S132>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S133>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S134>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S135>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S136>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S137>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S138>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S139>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S140>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S141>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S142>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S143>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S144>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S145>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S146>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S147>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S148>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S149>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S150>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S151>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S152>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S153>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S154>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S155>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S156>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S157>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S158>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S159>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S160>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S161>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S162>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S163>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S164>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Compare To Constant'
 * '<S165>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM'
 * '<S166>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S167>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_1'
 * '<S168>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_2'
 * '<S169>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_3'
 * '<S170>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S171>' : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S172>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S173>' : 'Controller/Controller/FW_Controller/Signal_Select/Manual_Command'
 * '<S174>' : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S175>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S176>' : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S177>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S178>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S179>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S180>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S181>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S182>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S183>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S184>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S185>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S186>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S187>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S188>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S189>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S190>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S191>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S192>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S193>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S194>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S195>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S196>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S197>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S198>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S199>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S200>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S201>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S202>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S203>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S204>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S205>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S206>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S207>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S208>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S209>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S210>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S211>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S212>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S213>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S214>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S215>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S216>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S217>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S218>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S219>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S220>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S221>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S222>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S223>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S224>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S225>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S226>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S227>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S228>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S229>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S230>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S231>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S232>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S233>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S234>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S235>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S236>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S237>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S238>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S239>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S240>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S241>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S242>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S243>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S244>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S245>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S246>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S247>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S248>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S249>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S250>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S251>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S252>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S253>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S254>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S255>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S256>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S257>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S258>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S259>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S260>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S261>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
