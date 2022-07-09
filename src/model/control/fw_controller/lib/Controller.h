/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.937
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul  6 20:31:41 2022
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S15>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S4>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S15>/Discrete-Time Integrator' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Gain1;                /* '<S28>/Gain1' */
  const uint32_T Sum1;                 /* '<S28>/Sum1' */
  const real32_T Saturation2;          /* '<S8>/Saturation2' */
  const real32_T Sum;                  /* '<S28>/Sum' */
  const real32_T Saturation;           /* '<S28>/Saturation' */
  const real32_T Constant[3];          /* '<S15>/Constant' */
  const uint16_T DataTypeConversion;   /* '<S28>/Data Type Conversion' */
} ConstB_Controller_T;

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

/* Block states (default storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller_T Controller_Y;

/* External data declarations for dependent source files */
extern const Control_Out_Bus Controller_rtZControl_Out_Bus;/* Control_Out_Bus ground */
extern const ConstB_Controller_T Controller_ConstB;/* constant block i/o */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_PV3SQCFgY9osXK4X1JOmc CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                   * Referenced by:
                                                   *   '<S5>/Saturation'
                                                   *   '<S9>/FF'
                                                   *   '<S9>/FF_limit'
                                                   *   '<S9>/PI_limit'
                                                   *   '<S26>/Constant1'
                                                   *   '<S26>/Constant12'
                                                   *   '<S26>/Constant2'
                                                   *   '<S26>/Constant7'
                                                   *   '<S13>/trim_speed'
                                                   *   '<S14>/trim_speed'
                                                   *   '<S15>/gain1'
                                                   *   '<S15>/gain2'
                                                   *   '<S15>/gain3'
                                                   *   '<S15>/Discrete-Time Integrator'
                                                   *   '<S16>/gain1'
                                                   *   '<S16>/gain2'
                                                   *   '<S16>/gain3'
                                                   *   '<S21>/Constant1'
                                                   *   '<S21>/Constant2'
                                                   */
extern struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
                                                     * Referenced by: '<S4>/Constant'
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
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Reshape' : Reshape block reduction
 * Block '<S19>/Logical Operator1' : Eliminated due to no operation
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
 * '<S3>'   : 'Controller/Bus_Constructor/Compare To Constant'
 * '<S4>'   : 'Controller/Bus_Constructor/timestamp'
 * '<S5>'   : 'Controller/Controller/Attitude_Control'
 * '<S6>'   : 'Controller/Controller/TECS_Core'
 * '<S7>'   : 'Controller/Controller/Velocity_Control'
 * '<S8>'   : 'Controller/Controller/mixer'
 * '<S9>'   : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S10>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S11>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S12>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S13>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S14>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S15>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S16>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S17>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S18>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S19>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S20>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S21>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S22>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S23>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S24>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S25>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S26>'  : 'Controller/Controller/mixer/Effective_Matrix'
 * '<S27>'  : 'Controller/Controller/mixer/Signal_Select'
 * '<S28>'  : 'Controller/Controller/mixer/throttle_mapping'
 * '<S29>'  : 'Controller/Controller/mixer/Signal_Select/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
