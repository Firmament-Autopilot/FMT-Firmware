/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.966
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 17 14:37:52 2022
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
  real32_T _DSTATE;                    /* '<S39>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S40>/Discrete-Time Integrator1' */
  real32_T _DSTATE_n;                  /* '<S36>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S37>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S16>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S4>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S39>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S40>/Discrete-Time Integrator1' */
  int8_T _PrevResetState_c;            /* '<S36>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S37>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S16>/Discrete-Time Integrator' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Zero;                 /* '<S39>/Zero' */
  const real32_T VectorConcatenate3[3];/* '<S43>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S36>/Zero1' */
  const real32_T Constant[3];          /* '<S16>/Constant' */
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
extern struct_M8LEl4uNQE6bF6Ay89SKzG CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S5>/Saturation'
                                                    *   '<S7>/pitch_ff'
                                                    *   '<S7>/ratio'
                                                    *   '<S7>/ratio2'
                                                    *   '<S7>/thorttle_ff'
                                                    *   '<S8>/Gain'
                                                    *   '<S10>/FF'
                                                    *   '<S10>/FF_limit'
                                                    *   '<S10>/PI_limit'
                                                    *   '<S28>/Gain3'
                                                    *   '<S30>/P_control'
                                                    *   '<S31>/P_control'
                                                    *   '<S44>/Constant1'
                                                    *   '<S44>/Constant12'
                                                    *   '<S44>/Constant2'
                                                    *   '<S44>/Constant7'
                                                    *   '<S14>/trim_speed'
                                                    *   '<S15>/trim_speed'
                                                    *   '<S32>/Constant'
                                                    *   '<S33>/Constant'
                                                    *   '<S34>/Constant'
                                                    *   '<S34>/Gain1'
                                                    *   '<S35>/Gain'
                                                    *   '<S36>/Gain3'
                                                    *   '<S38>/Gain'
                                                    *   '<S39>/Gain'
                                                    *   '<S16>/gain1'
                                                    *   '<S16>/gain2'
                                                    *   '<S16>/gain3'
                                                    *   '<S16>/Discrete-Time Integrator'
                                                    *   '<S17>/gain1'
                                                    *   '<S17>/gain2'
                                                    *   '<S17>/gain3'
                                                    *   '<S22>/Constant1'
                                                    *   '<S22>/Constant2'
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
 * Block '<S11>/Reshape' : Reshape block reduction
 * Block '<S20>/Logical Operator1' : Eliminated due to no operation
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
 * '<S6>'   : 'Controller/Controller/Signal_Select'
 * '<S7>'   : 'Controller/Controller/TECS_Core'
 * '<S8>'   : 'Controller/Controller/Velocity_Control'
 * '<S9>'   : 'Controller/Controller/mixer'
 * '<S10>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S11>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S12>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S13>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S14>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S15>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S16>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S17>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S18>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S19>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S20>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S21>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S22>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S23>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S24>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S25>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S26>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S27>'  : 'Controller/Controller/Signal_Select/Compare To Constant'
 * '<S28>'  : 'Controller/Controller/TECS_Core/Subsystem'
 * '<S29>'  : 'Controller/Controller/TECS_Core/Subsystem1'
 * '<S30>'  : 'Controller/Controller/TECS_Core/pitch_pid_out'
 * '<S31>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out'
 * '<S32>'  : 'Controller/Controller/TECS_Core/Subsystem/speed_ax_out'
 * '<S33>'  : 'Controller/Controller/TECS_Core/Subsystem1/Subsystem'
 * '<S34>'  : 'Controller/Controller/TECS_Core/Subsystem1/Subsystem1'
 * '<S35>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S36>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S37>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S38>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S39>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S40>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S41>'  : 'Controller/Controller/Velocity_Control/Subsystem'
 * '<S42>'  : 'Controller/Controller/Velocity_Control/Subsystem/Psi To DCM'
 * '<S43>'  : 'Controller/Controller/Velocity_Control/Subsystem/Psi To DCM/Rotation Matrix Z'
 * '<S44>'  : 'Controller/Controller/mixer/Effective_Matrix'
 * '<S45>'  : 'Controller/Controller/mixer/Signal_Select'
 * '<S46>'  : 'Controller/Controller/mixer/throttle_mapping'
 * '<S47>'  : 'Controller/Controller/mixer/Signal_Select/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
