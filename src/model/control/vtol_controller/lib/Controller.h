/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.321
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:34:27 2025
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
  real32_T Constant;                   /* '<S234>/Constant' */
  real32_T Constant_m;                 /* '<S108>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S186>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S208>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S213>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S215>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S184>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S188>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S208>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S231>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S234>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S236>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S231>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S115>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S114>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S113>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S85>/Discrete-Time Integrator' */
  real32_T _DSTATE;                    /* '<S157>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S158>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S83>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S87>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_i;       /* '<S105>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S108>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S110>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S133>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTA_jo;/* '<S112>/Discrete-Time Integrator5' */
  real32_T Integrator_DSTATE_f;        /* '<S105>/Integrator' */
  real32_T _DSTATE_d;                  /* '<S160>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S161>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S9>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S186>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S213>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S215>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S188>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S234>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S236>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S85>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S157>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S158>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S87>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S108>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S110>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S133>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S160>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S161>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S215>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S184>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S188>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S236>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S115>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S114>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S113>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S158>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S83>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S87>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S110>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S112>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S161>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S70>/Relay' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T fw_torque_cmd[3];     /* '<S6>/Constant' */
  const real32_T fw_force_cmd[3];      /* '<S6>/Constant1' */
  const real32_T Constant[3];          /* '<S186>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S210>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S213>/Constant' */
  const real32_T Gain;                 /* '<S198>/Gain' */
  const real32_T Square;               /* '<S211>/Square' */
  const real32_T d;                    /* '<S211>/Multiply' */
  const real32_T Gain4;                /* '<S211>/Gain4' */
  const real32_T TmpBufferAtConstantOutport1;/* '<S225>/Constant' */
  const real32_T Square_h;             /* '<S232>/Square' */
  const real32_T d_i;                  /* '<S232>/Multiply' */
  const real32_T Gain4_p;              /* '<S232>/Gain4' */
  const real32_T VectorConcatenate3_c[3];/* '<S152>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S154>/Vector Concatenate3' */
  const real32_T Constant_j[3];        /* '<S85>/Constant' */
  const real32_T Square1;              /* '<S70>/Square1' */
  const real32_T Zero1;                /* '<S157>/Zero1' */
  const real32_T Gain_n;               /* '<S93>/Gain' */
  const real32_T Constant_c[3];        /* '<S133>/Constant' */
  const real32_T Square_h2;            /* '<S106>/Square' */
  const real32_T d_m;                  /* '<S106>/Multiply' */
  const real32_T Gain4_o;              /* '<S106>/Gain4' */
  const real32_T Zero;                 /* '<S160>/Zero' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S242>/Effective_Matrix'
   *   '<S249>/Effective_Matrix'
   */
  real32_T pooled4[12];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 2

  /* Computed Parameter: Disarm_Value_j
   * Referenced by: '<S256>/Disarm'
   */
  real32_T Disarm_Value_j[5];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  /* Computed Parameter: Disarm_Value_c
   * Referenced by: '<S243>/Disarm'
   */
  uint16_T Disarm_Value_c[9];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S243>/Standby'
   */
  uint16_T Standby_Value[9];

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
                                                    *   '<S124>/Saturation'
                                                    *   '<S125>/Gain'
                                                    *   '<S125>/Gain1'
                                                    *   '<S125>/balabnce_ratio2'
                                                    *   '<S125>/balance_ratio'
                                                    *   '<S125>/pitch_ff'
                                                    *   '<S125>/thorttle_ff'
                                                    *   '<S125>/ucmd2pitch'
                                                    *   '<S125>/ucmd2thor'
                                                    *   '<S125>/wcmd2pitch'
                                                    *   '<S125>/wcmd2thor'
                                                    *   '<S126>/cruise_throttle'
                                                    *   '<S226>/hover_throttle'
                                                    *   '<S100>/hover_throttle'
                                                    *   '<S127>/FF'
                                                    *   '<S127>/FF_limit'
                                                    *   '<S127>/PI_limit'
                                                    *   '<S146>/P_control'
                                                    *   '<S147>/P_control'
                                                    *   '<S203>/Saturation'
                                                    *   '<S241>/Bias1'
                                                    *   '<S241>/Bias2'
                                                    *   '<S241>/Bias3'
                                                    *   '<S241>/Bias4'
                                                    *   '<S248>/Bias1'
                                                    *   '<S248>/Bias2'
                                                    *   '<S248>/Bias3'
                                                    *   '<S248>/Bias4'
                                                    *   '<S79>/Saturation'
                                                    *   '<S79>/Saturation1'
                                                    *   '<S131>/trim_speed'
                                                    *   '<S132>/trim_speed'
                                                    *   '<S156>/Gain'
                                                    *   '<S157>/ '
                                                    *   '<S157>/Gain3'
                                                    *   '<S159>/Gain'
                                                    *   '<S160>/ '
                                                    *   '<S160>/Gain'
                                                    *   '<S179>/Saturation'
                                                    *   '<S179>/Saturation1'
                                                    *   '<S212>/kd'
                                                    *   '<S212>/Saturation'
                                                    *   '<S213>/ki'
                                                    *   '<S213>/Discrete-Time Integrator'
                                                    *   '<S214>/kp'
                                                    *   '<S233>/kd'
                                                    *   '<S233>/Saturation'
                                                    *   '<S234>/Constant'
                                                    *   '<S234>/ki'
                                                    *   '<S234>/Discrete-Time Integrator'
                                                    *   '<S235>/kp'
                                                    *   '<S244>/Constant1'
                                                    *   '<S244>/Constant12'
                                                    *   '<S244>/Constant2'
                                                    *   '<S244>/Constant7'
                                                    *   '<S251>/Constant1'
                                                    *   '<S251>/Constant11'
                                                    *   '<S251>/Constant12'
                                                    *   '<S251>/Constant2'
                                                    *   '<S251>/Constant7'
                                                    *   '<S251>/Constant8'
                                                    *   '<S255>/Bias'
                                                    *   '<S255>/Bias1'
                                                    *   '<S255>/Bias2'
                                                    *   '<S255>/Bias3'
                                                    *   '<S256>/Bias'
                                                    *   '<S256>/Bias1'
                                                    *   '<S256>/Bias2'
                                                    *   '<S256>/Bias3'
                                                    *   '<S91>/Constant1'
                                                    *   '<S91>/Constant2'
                                                    *   '<S107>/kd'
                                                    *   '<S107>/Saturation'
                                                    *   '<S108>/Constant'
                                                    *   '<S108>/ki'
                                                    *   '<S108>/Discrete-Time Integrator'
                                                    *   '<S109>/kp'
                                                    *   '<S133>/gain1'
                                                    *   '<S133>/gain2'
                                                    *   '<S133>/gain3'
                                                    *   '<S133>/Discrete-Time Integrator'
                                                    *   '<S134>/gain1'
                                                    *   '<S134>/gain2'
                                                    *   '<S134>/gain3'
                                                    *   '<S138>/Pitch Offset'
                                                    *   '<S138>/Saturation'
                                                    *   '<S139>/Constant1'
                                                    *   '<S139>/Constant2'
                                                    *   '<S196>/Constant1'
                                                    *   '<S196>/Constant2'
                                                    *   '<S84>/gain1'
                                                    *   '<S84>/gain2'
                                                    *   '<S84>/gain3'
                                                    *   '<S84>/Saturation'
                                                    *   '<S85>/gain1'
                                                    *   '<S85>/gain2'
                                                    *   '<S85>/gain3'
                                                    *   '<S85>/Discrete-Time Integrator'
                                                    *   '<S86>/gain1'
                                                    *   '<S86>/gain2'
                                                    *   '<S86>/gain3'
                                                    *   '<S185>/gain1'
                                                    *   '<S185>/gain2'
                                                    *   '<S185>/gain3'
                                                    *   '<S185>/Saturation'
                                                    *   '<S186>/gain1'
                                                    *   '<S186>/gain2'
                                                    *   '<S186>/gain3'
                                                    *   '<S186>/Discrete-Time Integrator'
                                                    *   '<S187>/gain1'
                                                    *   '<S187>/gain2'
                                                    *   '<S187>/gain3'
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
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Propagation' : Unused code path elimination
 * Block '<S111>/Bitwise AND' : Unused code path elimination
 * Block '<S111>/Switch' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S103>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S115>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S112>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S128>/Reshape' : Reshape block reduction
 * Block '<S137>/Logical Operator1' : Eliminated due to no operation
 * Block '<S145>/Logical Operator' : Eliminated due to no operation
 * Block '<S184>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S229>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S239>/Reshape' : Reshape block reduction
 * Block '<S240>/Reshape' : Reshape block reduction
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
 * '<S27>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S28>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S29>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S30>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S31>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S32>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S33>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S34>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S35>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S36>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S37>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S38>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S39>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S40>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S41>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S42>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S43>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S44>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S45>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S46>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S47>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S48>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S49>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S50>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S51>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S52>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S53>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S54>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S55>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S56>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S57>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S58>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S59>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S60>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S61>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S62>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S63>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S64>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S65>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S66>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S67>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S68>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 * '<S69>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller'
 * '<S70>'  : 'Controller/Controller/FW_Controller/Effective_Factor'
 * '<S71>'  : 'Controller/Controller/FW_Controller/FW_Controller'
 * '<S72>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S73>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S74>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S75>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S76>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S77>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S78>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S79>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S80>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S81>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S82>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S83>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S84>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S85>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S86>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S87>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S88>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S89>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S90>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S91>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S92>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S93>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S94>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S95>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S96>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S97>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S98>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S99>'  : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S100>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S101>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S102>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S103>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S104>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S105>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S106>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S107>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S108>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S109>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S110>' : 'Controller/Controller/FW_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S111>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed'
 * '<S112>' : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF'
 * '<S113>' : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF1'
 * '<S114>' : 'Controller/Controller/FW_Controller/Effective_Factor/First Order LPF2'
 * '<S115>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/First Order LPF3'
 * '<S116>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction'
 * '<S117>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction/Quaternion To DCM'
 * '<S118>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction/Quaternion To DCM/Quaternion Normalize'
 * '<S119>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction/Quaternion To DCM/column_1'
 * '<S120>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction/Quaternion To DCM/column_2'
 * '<S121>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction/Quaternion To DCM/column_3'
 * '<S122>' : 'Controller/Controller/FW_Controller/Effective_Factor/Airspeed/Fly_Direction/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S123>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control'
 * '<S124>' : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control'
 * '<S125>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core'
 * '<S126>' : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command'
 * '<S127>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S128>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S129>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S130>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S131>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S132>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S133>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S134>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S135>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S136>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S137>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S138>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S139>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S140>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S141>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S142>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S143>' : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S144>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S145>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S146>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S147>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S148>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S149>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S150>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S151>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM'
 * '<S152>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S153>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM'
 * '<S154>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S155>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S156>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S157>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S158>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S159>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S160>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S161>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S162>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S163>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Compare To Constant'
 * '<S164>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM'
 * '<S165>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S166>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_1'
 * '<S167>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_2'
 * '<S168>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_3'
 * '<S169>' : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S170>' : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S171>' : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S172>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S173>' : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S174>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S175>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S176>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S177>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S178>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S179>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S180>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S181>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S182>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S183>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S184>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S185>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S186>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S187>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S188>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S189>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S190>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S191>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S192>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S193>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S194>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S195>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S196>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S197>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S198>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S199>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S200>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S201>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S202>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S203>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S204>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S205>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S206>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S207>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S208>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S209>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S210>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S211>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S212>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S213>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S214>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S215>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S216>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S217>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S218>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S219>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S220>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S221>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S222>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S223>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S224>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S225>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S226>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S227>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S228>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S229>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S230>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S231>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S232>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S233>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S234>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S235>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S236>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S237>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S238>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S239>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S240>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S241>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S242>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S243>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S244>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S245>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S246>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S247>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S248>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S249>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S250>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S251>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S252>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S253>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S254>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S255>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S256>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
