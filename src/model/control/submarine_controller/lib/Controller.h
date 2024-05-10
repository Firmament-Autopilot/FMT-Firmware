/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1000
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 12:15:37 2024
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

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S13>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S17>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S37>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m;/* '<S39>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_mf;/* '<S43>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S45>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S17>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S37>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S39>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S43>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S45>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S13>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S17>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_b;/* '<S39>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_k;/* '<S45>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Gain;                 /* '<S21>/Gain' */
  const real32_T Constant;             /* '<S15>/Constant' */
  const real32_T Constant_g;           /* '<S37>/Constant' */
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
extern struct_ggPnHVpLLXFM79yHB3eR4D CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S8>/Saturation'
                                                    *   '<S8>/Saturation1'
                                                    *   '<S8>/Saturation2'
                                                    *   '<S19>/Constant2'
                                                    *   '<S36>/kd'
                                                    *   '<S36>/Saturation'
                                                    *   '<S37>/ki'
                                                    *   '<S37>/Discrete-Time Integrator'
                                                    *   '<S38>/kp'
                                                    *   '<S42>/kd'
                                                    *   '<S42>/Saturation'
                                                    *   '<S43>/Constant'
                                                    *   '<S43>/ki'
                                                    *   '<S43>/Discrete-Time Integrator'
                                                    *   '<S44>/kp'
                                                    *   '<S14>/q_kd'
                                                    *   '<S14>/r_kd'
                                                    *   '<S14>/Saturation'
                                                    *   '<S15>/q_ki'
                                                    *   '<S15>/r_ki'
                                                    *   '<S15>/Discrete-Time Integrator'
                                                    *   '<S16>/q_kp'
                                                    *   '<S16>/r_kp'
                                                    */
extern struct_3c1tBoNX9Tmevk4CbFSC3G CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
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
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S40>/Signal Copy1' : Eliminate redundant signal conversion block
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
 * '<S4>'   : 'Controller/Controller/Attitude_Controller'
 * '<S5>'   : 'Controller/Controller/Control_Allocation'
 * '<S6>'   : 'Controller/Controller/Velocity_Controller'
 * '<S7>'   : 'Controller/Controller/Attitude_Controller/Inner_Loop'
 * '<S8>'   : 'Controller/Controller/Attitude_Controller/Outter_Loop'
 * '<S9>'   : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S10>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S11>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S12>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S13>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S14>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S15>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S16>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S17>'  : 'Controller/Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S18>'  : 'Controller/Controller/Attitude_Controller/Outter_Loop/Error'
 * '<S19>'  : 'Controller/Controller/Attitude_Controller/Outter_Loop/Sqrt_Root_Controller'
 * '<S20>'  : 'Controller/Controller/Attitude_Controller/Outter_Loop/Error/Bus_Select'
 * '<S21>'  : 'Controller/Controller/Attitude_Controller/Outter_Loop/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S22>'  : 'Controller/Controller/Attitude_Controller/Outter_Loop/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S23>'  : 'Controller/Controller/Control_Allocation/Submarine_1'
 * '<S24>'  : 'Controller/Controller/Control_Allocation/Submarine_1/actuator_cmd_routing'
 * '<S25>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control'
 * '<S26>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control'
 * '<S27>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error'
 * '<S28>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller'
 * '<S29>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select'
 * '<S30>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM'
 * '<S31>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/Quaternion Normalize'
 * '<S32>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/column_1'
 * '<S33>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/column_2'
 * '<S34>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/column_3'
 * '<S35>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S36>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/D_Control'
 * '<S37>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/I_Control'
 * '<S38>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/P_Control'
 * '<S39>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/D_Control/DT Filter'
 * '<S40>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/Error'
 * '<S41>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller'
 * '<S42>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/D_Control'
 * '<S43>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/I_Control'
 * '<S44>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/P_Control'
 * '<S45>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
