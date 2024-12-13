/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1121
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 10 10:47:05 2024
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
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S19>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S21>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S19>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S21>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S21>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S17>/Vector Concatenate3' */
  const real32_T Constant;             /* '<S19>/Constant' */
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
extern struct_2HV4h0wnvObh5FK8iPBjE CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                   * Referenced by:
                                                   *   '<S7>/Bias'
                                                   *   '<S7>/Bias1'
                                                   *   '<S7>/Gain'
                                                   *   '<S7>/Gain1'
                                                   *   '<S18>/gain1'
                                                   *   '<S18>/Saturation'
                                                   *   '<S19>/gain1'
                                                   *   '<S19>/Discrete-Time Integrator'
                                                   *   '<S20>/gain1'
                                                   *   '<S11>/Disarm'
                                                   *   '<S12>/Standby'
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
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S7>/Reshape' : Reshape block reduction
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
 * '<S4>'   : 'Controller/Controller/Control_Allocation'
 * '<S5>'   : 'Controller/Controller/Heading_Controller'
 * '<S6>'   : 'Controller/Controller/Speed_Controller'
 * '<S7>'   : 'Controller/Controller/Control_Allocation/Boat_1'
 * '<S8>'   : 'Controller/Controller/Control_Allocation/Boat_1/Signal_Router'
 * '<S9>'   : 'Controller/Controller/Control_Allocation/Boat_1/actuator_cmd_routing'
 * '<S10>'  : 'Controller/Controller/Control_Allocation/Boat_1/Signal_Router/Compare To Constant1'
 * '<S11>'  : 'Controller/Controller/Control_Allocation/Boat_1/actuator_cmd_routing/Disarm'
 * '<S12>'  : 'Controller/Controller/Control_Allocation/Boat_1/actuator_cmd_routing/Standby'
 * '<S13>'  : 'Controller/Controller/Speed_Controller/Error'
 * '<S14>'  : 'Controller/Controller/Speed_Controller/PID_Controller'
 * '<S15>'  : 'Controller/Controller/Speed_Controller/Error/Bus_Select'
 * '<S16>'  : 'Controller/Controller/Speed_Controller/Error/Bus_Select/Psi To DCM'
 * '<S17>'  : 'Controller/Controller/Speed_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S18>'  : 'Controller/Controller/Speed_Controller/PID_Controller/D_Control'
 * '<S19>'  : 'Controller/Controller/Speed_Controller/PID_Controller/I_Control'
 * '<S20>'  : 'Controller/Controller/Speed_Controller/PID_Controller/P_Control'
 * '<S21>'  : 'Controller/Controller/Speed_Controller/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
