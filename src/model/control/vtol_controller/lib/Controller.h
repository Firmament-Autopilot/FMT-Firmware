/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.824
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 30 15:14:14 2025
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
  real32_T Constant;                   /* '<S139>/Constant' */
  real32_T Multiply1[3];               /* '<S6>/Multiply1' */
  real32_T Reshape[3];                 /* '<S18>/Reshape' */
  real32_T Switch[6];                  /* '<S11>/Switch' */
  real32_T Multiply_c[3];              /* '<S5>/Multiply' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S9>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_k;/* '<S8>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S97>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S117>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S122>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S124>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S94>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S99>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S117>/Integrator' */
  real32_T Integrator1_DSTATE_e;       /* '<S136>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S139>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S141>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_j;        /* '<S136>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S64>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_c;       /* '<S34>/Integrator1' */
  real32_T Integrator1_DSTATE_j;       /* '<S36>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S23>/Discrete-Time Integrator' */
  real32_T _DSTATE;                    /* '<S39>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S60>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S59>/Discrete-Time Integrator1' */
  real32_T _DSTATE_h;                  /* '<S56>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S57>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S36>/Integrator' */
  real32_T Integrator_DSTATE_n;        /* '<S34>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S97>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S122>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S124>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S99>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S139>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S141>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S23>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S60>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_Prev_dx;/* '<S59>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S56>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S57>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S9>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S8>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S124>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;/* '<S94>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S99>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S141>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_i;/* '<S64>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_n;/* '<S60>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S57>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S2>/Relay' */
  boolean_T Relay1_Mode;               /* '<S2>/Relay1' */
  boolean_T MC_Controller_MODE;        /* '<S2>/MC_Controller' */
  boolean_T FW_Controller_MODE;        /* '<S2>/FW_Controller' */
} DW_Controller_T;

/* Invariant block signals for system '<S143>/VTOL1' */
#if AIRFRAME == 1

typedef struct {
  const real32_T Gain[12];             /* '<S147>/Gain' */
  const real32_T r_column[4];          /* '<S147>/r_column' */
  const real32_T pq_column[8];         /* '<S147>/pq_column' */
} ConstB_VTOL1_Controller_T;

#endif

/* Invariant block signals for system '<S143>/VTOL2' */
#if AIRFRAME == 2

typedef struct {
  const real32_T Gain[12];             /* '<S163>/Gain' */
  const real32_T r_column[4];          /* '<S163>/r_column' */
  const real32_T pq_column[8];         /* '<S163>/pq_column' */
} ConstB_VTOL2_Controller_T;

#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant[3];          /* '<S97>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S119>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S122>/Constant' */
  const real32_T Gain;                 /* '<S105>/Gain' */
  const real32_T Subtract;             /* '<S80>/Subtract' */
  const real32_T Divide;               /* '<S80>/Divide' */
  const real32_T Subtract_g;           /* '<S83>/Subtract' */
  const real32_T Divide_k;             /* '<S83>/Divide' */
  const real32_T Square;               /* '<S120>/Square' */
  const real32_T d;                    /* '<S120>/Multiply' */
  const real32_T Gain4;                /* '<S120>/Gain4' */
  const real32_T Square_h;             /* '<S137>/Square' */
  const real32_T d_i;                  /* '<S137>/Multiply' */
  const real32_T Gain4_p;              /* '<S137>/Gain4' */
  const real32_T Constant_c[3];        /* '<S23>/Constant' */
  const real32_T VectorConcatenate3_g[3];/* '<S53>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S56>/Zero1' */
  const real32_T Square_j;             /* '<S41>/Square' */
  const real32_T d_f;                  /* '<S41>/Multiply' */
  const real32_T Gain4_n;              /* '<S41>/Gain4' */
  const real32_T Square_c;             /* '<S35>/Square' */
  const real32_T d_ih;                 /* '<S35>/Multiply' */
  const real32_T Gain4_g;              /* '<S35>/Gain4' */

#if AIRFRAME == 2

  ConstB_VTOL2_Controller_T VTOL2;     /* '<S143>/VTOL2' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  ConstB_VTOL1_Controller_T VTOL1;     /* '<S143>/VTOL1' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S161>/Standby'
   *   '<S173>/Disarm'
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
extern struct_PwkgbKxZIDCjZ9tSDIOmy CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                   * Referenced by:
                                                   *   '<S14>/Saturation'
                                                   *   '<S15>/balabnce_ratio2'
                                                   *   '<S15>/balance_ratio'
                                                   *   '<S15>/pitch_ff'
                                                   *   '<S15>/thorttle_ff'
                                                   *   '<S15>/ucmd2pitch'
                                                   *   '<S15>/ucmd2thor'
                                                   *   '<S15>/wcmd2pitch'
                                                   *   '<S15>/wcmd2thor'
                                                   *   '<S130>/hover_throttle'
                                                   *   '<S17>/FF'
                                                   *   '<S38>/P_control'
                                                   *   '<S39>/Gain'
                                                   *   '<S39>/Gain1'
                                                   *   '<S39>/P_control'
                                                   *   '<S40>/Kv'
                                                   *   '<S110>/Saturation'
                                                   *   '<S146>/Bias1'
                                                   *   '<S146>/Bias2'
                                                   *   '<S146>/Bias3'
                                                   *   '<S146>/Bias4'
                                                   *   '<S146>/Saturation1'
                                                   *   '<S147>/Constant'
                                                   *   '<S147>/Constant1'
                                                   *   '<S147>/Saturation'
                                                   *   '<S162>/Bias1'
                                                   *   '<S162>/Bias2'
                                                   *   '<S162>/Bias3'
                                                   *   '<S162>/Bias4'
                                                   *   '<S162>/Saturation1'
                                                   *   '<S163>/Constant'
                                                   *   '<S163>/Constant1'
                                                   *   '<S163>/Saturation'
                                                   *   '<S21>/trim_speed'
                                                   *   '<S22>/trim_speed'
                                                   *   '<S26>/Saturation'
                                                   *   '<S55>/Gain'
                                                   *   '<S56>/ '
                                                   *   '<S56>/Gain3'
                                                   *   '<S78>/Saturation'
                                                   *   '<S78>/Saturation1'
                                                   *   '<S78>/Saturation2'
                                                   *   '<S121>/kd'
                                                   *   '<S121>/Saturation'
                                                   *   '<S122>/ki'
                                                   *   '<S122>/Discrete-Time Integrator'
                                                   *   '<S123>/kp'
                                                   *   '<S138>/kd'
                                                   *   '<S138>/Saturation'
                                                   *   '<S139>/Constant'
                                                   *   '<S139>/ki'
                                                   *   '<S139>/Discrete-Time Integrator'
                                                   *   '<S140>/kp'
                                                   *   '<S151>/Constant1'
                                                   *   '<S151>/Constant12'
                                                   *   '<S151>/Constant2'
                                                   *   '<S151>/Constant7'
                                                   *   '<S160>/Bias'
                                                   *   '<S160>/Bias1'
                                                   *   '<S160>/Bias2'
                                                   *   '<S160>/Bias3'
                                                   *   '<S161>/Bias'
                                                   *   '<S161>/Bias1'
                                                   *   '<S161>/Bias2'
                                                   *   '<S161>/Bias3'
                                                   *   '<S166>/Constant1'
                                                   *   '<S166>/Constant11'
                                                   *   '<S166>/Constant12'
                                                   *   '<S166>/Constant2'
                                                   *   '<S166>/Constant7'
                                                   *   '<S166>/Constant8'
                                                   *   '<S172>/Bias'
                                                   *   '<S172>/Bias1'
                                                   *   '<S172>/Bias2'
                                                   *   '<S172>/Bias3'
                                                   *   '<S173>/Bias'
                                                   *   '<S173>/Bias1'
                                                   *   '<S173>/Bias2'
                                                   *   '<S173>/Bias3'
                                                   *   '<S23>/gain1'
                                                   *   '<S23>/gain2'
                                                   *   '<S23>/gain3'
                                                   *   '<S23>/Discrete-Time Integrator'
                                                   *   '<S24>/gain1'
                                                   *   '<S24>/gain2'
                                                   *   '<S24>/gain3'
                                                   *   '<S28>/Pitch Offset'
                                                   *   '<S28>/Saturation'
                                                   *   '<S29>/Constant1'
                                                   *   '<S29>/Constant2'
                                                   *   '<S91>/Gain'
                                                   *   '<S91>/Gain1'
                                                   *   '<S103>/Constant1'
                                                   *   '<S103>/Constant2'
                                                   *   '<S96>/gain1'
                                                   *   '<S96>/gain2'
                                                   *   '<S96>/gain3'
                                                   *   '<S96>/Saturation'
                                                   *   '<S97>/gain1'
                                                   *   '<S97>/gain2'
                                                   *   '<S97>/gain3'
                                                   *   '<S97>/Discrete-Time Integrator'
                                                   *   '<S98>/gain1'
                                                   *   '<S98>/gain2'
                                                   *   '<S98>/gain3'
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
 * Block '<S61>/Data Type Conversion' : Unused code path elimination
 * Block '<S61>/Discrete-Time Integrator5' : Unused code path elimination
 * Block '<S61>/Gain' : Unused code path elimination
 * Block '<S61>/Sum5' : Unused code path elimination
 * Block '<S16>/Sum' : Unused code path elimination
 * Block '<S16>/cruise_throttle' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S27>/Logical Operator1' : Eliminated due to no operation
 * Block '<S60>/Switch' : Eliminated due to constant selection input
 * Block '<S64>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S147>/Reshape' : Reshape block reduction
 * Block '<S144>/Reshape' : Reshape block reduction
 * Block '<S163>/Reshape' : Reshape block reduction
 * Block '<S145>/Reshape' : Reshape block reduction
 * Block '<S60>/Gain1' : Unused code path elimination
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
 * '<S25>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S26>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S27>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S28>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S29>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S30>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S31>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S32>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S33>'  : 'Controller/Controller/FW_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S34>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control/TD'
 * '<S35>'  : 'Controller/Controller/FW_Controller/FW_Controller/Lateral_Control/TD/fhan '
 * '<S36>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/TD'
 * '<S37>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S38>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller'
 * '<S39>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_controller'
 * '<S40>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S41>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/TD/fhan '
 * '<S42>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S43>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed'
 * '<S44>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S45>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S46>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM'
 * '<S47>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S48>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_1'
 * '<S49>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_2'
 * '<S50>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/column_3'
 * '<S51>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S52>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM'
 * '<S53>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S54>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/Compare To Constant'
 * '<S55>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/D_control'
 * '<S56>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/I_control'
 * '<S57>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/pitch_controller/D_control/DT Filter'
 * '<S58>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_controller/Compare To Constant'
 * '<S59>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/thorttle_controller/DT Filter'
 * '<S60>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/DT Filter'
 * '<S61>'  : 'Controller/Controller/FW_Controller/FW_Controller/TECS_Core/velocity_control/First Order LPF'
 * '<S62>'  : 'Controller/Controller/FW_Controller/FW_Controller/Throttle_Command/Compare To Constant'
 * '<S63>'  : 'Controller/Controller/FW_Controller/Signal_Select/Manual'
 * '<S64>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/First Order LPF3'
 * '<S65>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed'
 * '<S66>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM'
 * '<S67>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S68>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_1'
 * '<S69>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_2'
 * '<S70>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/column_3'
 * '<S71>'  : 'Controller/Controller/FW_Controller/True_FlySpeed/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S72>'  : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S73>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S74>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S75>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S76>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S77>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S78>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer'
 * '<S79>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S80>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Backward_Mixer'
 * '<S81>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Euler To Angle Rate'
 * '<S82>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed'
 * '<S83>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Forward_Mixer'
 * '<S84>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM'
 * '<S85>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S86>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_1'
 * '<S87>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_2'
 * '<S88>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/column_3'
 * '<S89>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/ATT_Cmd_Mixer/Fly_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S90>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S91>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller'
 * '<S92>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S93>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S94>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S95>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Feedforward_Controller/DeadZone'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Compare To Constant'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Compare To Constant'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S127>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S128>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S129>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select'
 * '<S130>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S131>' : 'Controller/Controller/MC_Controller/Vertical_Control/Signal_Select/Compare To Constant'
 * '<S132>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S133>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S134>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S135>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/Compare To Constant'
 * '<S136>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S137>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S138>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S139>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S140>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S141>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S142>' : 'Controller/Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S143>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S144>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S145>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S146>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S147>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S148>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation1'
 * '<S149>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2'
 * '<S150>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S151>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S152>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S153>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S154>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/P_Q_Remix'
 * '<S155>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/R_Remix'
 * '<S156>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation1/throttle_mapping'
 * '<S157>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/MATLAB Function'
 * '<S158>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/MATLAB Function1'
 * '<S159>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation2/thrust_mapping'
 * '<S160>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Disarm'
 * '<S161>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing/Standby'
 * '<S162>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S163>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S164>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation2'
 * '<S165>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S166>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S167>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S168>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S169>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/P_Q_Remix'
 * '<S170>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/R_Remix'
 * '<S171>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation2/throttle_mapping'
 * '<S172>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S173>' : 'Controller/Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
