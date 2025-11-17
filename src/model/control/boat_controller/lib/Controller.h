/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1188
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Nov 15 11:15:33 2025
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
  real32_T Merge;                      /* '<S16>/Merge' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S37>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S39>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S26>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S28>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S22>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p;/* '<S24>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S37>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S39>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S26>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S28>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S22>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_f;/* '<S24>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S39>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_c;/* '<S28>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_m;/* '<S24>/Discrete-Time Integrator1' */
  boolean_T Forward_MODE;              /* '<S16>/Forward' */
  boolean_T Backward_MODE;             /* '<S16>/Backward' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S35>/Vector Concatenate3' */
  const real32_T Constant;             /* '<S37>/Constant' */
  const real32_T Constant_e;           /* '<S26>/Constant' */
  const real32_T Constant_b;           /* '<S22>/Constant' */
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

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_KPrsn48OrR8nBbHqB69JGB CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S7>/Bias'
                                                    *   '<S7>/Bias1'
                                                    *   '<S7>/Gain'
                                                    *   '<S7>/Gain1'
                                                    *   '<S7>/Saturation1'
                                                    *   '<S7>/Saturation2'
                                                    *   '<S8>/Bias'
                                                    *   '<S8>/Bias1'
                                                    *   '<S8>/Gain'
                                                    *   '<S8>/Gain1'
                                                    *   '<S8>/Gain2'
                                                    *   '<S8>/Saturation1'
                                                    *   '<S8>/Saturation2'
                                                    *   '<S15>/BW_FF'
                                                    *   '<S15>/FW_FF'
                                                    *   '<S36>/gain1'
                                                    *   '<S36>/Saturation'
                                                    *   '<S37>/gain1'
                                                    *   '<S37>/Discrete-Time Integrator'
                                                    *   '<S38>/gain1'
                                                    *   '<S10>/Disarm'
                                                    *   '<S10>/Disarm1'
                                                    *   '<S11>/Standby'
                                                    *   '<S11>/Standby1'
                                                    *   '<S13>/Disarm'
                                                    *   '<S13>/Disarm1'
                                                    *   '<S14>/Standby'
                                                    *   '<S14>/Standby1'
                                                    *   '<S21>/gain1'
                                                    *   '<S22>/gain1'
                                                    *   '<S23>/gain1'
                                                    *   '<S25>/gain1'
                                                    *   '<S26>/gain1'
                                                    *   '<S27>/gain1'
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
 * Block '<S8>/Reshape' : Reshape block reduction
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
 * '<S8>'   : 'Controller/Controller/Control_Allocation/Boat_2'
 * '<S9>'   : 'Controller/Controller/Control_Allocation/Boat_1/actuator_cmd_routing'
 * '<S10>'  : 'Controller/Controller/Control_Allocation/Boat_1/actuator_cmd_routing/Disarm'
 * '<S11>'  : 'Controller/Controller/Control_Allocation/Boat_1/actuator_cmd_routing/Standby'
 * '<S12>'  : 'Controller/Controller/Control_Allocation/Boat_2/actuator_cmd_routing'
 * '<S13>'  : 'Controller/Controller/Control_Allocation/Boat_2/actuator_cmd_routing/Disarm'
 * '<S14>'  : 'Controller/Controller/Control_Allocation/Boat_2/actuator_cmd_routing/Standby'
 * '<S15>'  : 'Controller/Controller/Heading_Controller/FF_Controller'
 * '<S16>'  : 'Controller/Controller/Heading_Controller/PID_Controller'
 * '<S17>'  : 'Controller/Controller/Heading_Controller/Signal_Select'
 * '<S18>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Backward'
 * '<S19>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Compare To Zero'
 * '<S20>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Forward'
 * '<S21>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Backward/D_Control'
 * '<S22>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Backward/I_Control'
 * '<S23>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Backward/P_Control'
 * '<S24>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Backward/D_Control/DT Filter'
 * '<S25>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Forward/D_Control'
 * '<S26>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Forward/I_Control'
 * '<S27>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Forward/P_Control'
 * '<S28>'  : 'Controller/Controller/Heading_Controller/PID_Controller/Forward/D_Control/DT Filter'
 * '<S29>'  : 'Controller/Controller/Heading_Controller/Signal_Select/Position'
 * '<S30>'  : 'Controller/Controller/Speed_Controller/Error'
 * '<S31>'  : 'Controller/Controller/Speed_Controller/PID_Controller'
 * '<S32>'  : 'Controller/Controller/Speed_Controller/Signal_Select'
 * '<S33>'  : 'Controller/Controller/Speed_Controller/Error/Bus_Select'
 * '<S34>'  : 'Controller/Controller/Speed_Controller/Error/Bus_Select/Psi To DCM'
 * '<S35>'  : 'Controller/Controller/Speed_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S36>'  : 'Controller/Controller/Speed_Controller/PID_Controller/D_Control'
 * '<S37>'  : 'Controller/Controller/Speed_Controller/PID_Controller/I_Control'
 * '<S38>'  : 'Controller/Controller/Speed_Controller/PID_Controller/P_Control'
 * '<S39>'  : 'Controller/Controller/Speed_Controller/PID_Controller/D_Control/DT Filter'
 * '<S40>'  : 'Controller/Controller/Speed_Controller/Signal_Select/Position'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
