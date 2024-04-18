/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.992
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 17 16:02:33 2024
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
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S13>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S17>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE;         /* '<S30>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S39>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m;/* '<S41>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_p;       /* '<S44>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_mf;/* '<S47>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S49>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S44>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S30>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S17>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S39>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S41>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S47>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S49>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S13>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S17>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_b;/* '<S41>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_k;/* '<S49>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Gain;                 /* '<S21>/Gain' */
  const real32_T Constant;             /* '<S15>/Constant' */
  const real32_T Constant_g;           /* '<S39>/Constant' */
  const real32_T Square;               /* '<S45>/Square' */
  const real32_T d;                    /* '<S45>/Multiply' */
  const real32_T Gain4;                /* '<S45>/Gain4' */
  const real32_T Square_d;             /* '<S37>/Square' */
  const real32_T d_e;                  /* '<S37>/Multiply' */
  const real32_T Gain4_d;              /* '<S37>/Gain4' */
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
extern struct_Q9EVXjrqeRICCMmugN4tVD CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S7>/Saturation'
                                                    *   '<S8>/Saturation'
                                                    *   '<S19>/Constant2'
                                                    *   '<S38>/kd'
                                                    *   '<S38>/Saturation'
                                                    *   '<S39>/ki'
                                                    *   '<S39>/Discrete-Time Integrator'
                                                    *   '<S40>/kp'
                                                    *   '<S46>/kd'
                                                    *   '<S46>/Saturation'
                                                    *   '<S47>/Constant'
                                                    *   '<S47>/ki'
                                                    *   '<S47>/Discrete-Time Integrator'
                                                    *   '<S48>/kp'
                                                    *   '<S14>/kd'
                                                    *   '<S14>/Saturation'
                                                    *   '<S15>/ki'
                                                    *   '<S15>/Discrete-Time Integrator'
                                                    *   '<S16>/kp'
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
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S42>/Signal Copy1' : Eliminate redundant signal conversion block
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
 * '<S30>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/TD'
 * '<S31>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM'
 * '<S32>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/Quaternion Normalize'
 * '<S33>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/column_1'
 * '<S34>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/column_2'
 * '<S35>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/column_3'
 * '<S36>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/Bus_Select/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S37>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/Error/TD/fhan '
 * '<S38>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/D_Control'
 * '<S39>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/I_Control'
 * '<S40>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/P_Control'
 * '<S41>'  : 'Controller/Controller/Velocity_Controller/Horizontal_Control/PID_Controller/D_Control/DT Filter'
 * '<S42>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/Error'
 * '<S43>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller'
 * '<S44>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/Error/TD'
 * '<S45>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/Error/TD/fhan '
 * '<S46>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/D_Control'
 * '<S47>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/I_Control'
 * '<S48>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/P_Control'
 * '<S49>'  : 'Controller/Controller/Velocity_Controller/Vertical_Control/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
