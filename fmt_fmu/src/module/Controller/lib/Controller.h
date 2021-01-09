/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.795
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan  9 08:58:31 2021
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
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S54>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S56>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m[2];/* '<S36>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l[2];/* '<S39>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S19>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_f[3];/* '<S21>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S4>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S54>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S56>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S36>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_e;/* '<S39>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S19>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_j;/* '<S21>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant;             /* '<S54>/Constant' */
  const real32_T VecConcentate3[3];    /* '<S34>/VecConcentate3' */
  const real32_T Constant_g;           /* '<S36>/Constant' */
  const real32_T Gain;                 /* '<S27>/Gain' */
  const real32_T Constant_n[3];        /* '<S19>/Constant' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: X_Frame_Effective_Matrix_Value
   * Referenced by: '<S6>/X_Frame_Effective_Matrix'
   */
  real32_T X_Frame_Effective_Matrix_Value[12];
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
extern struct_Ae52N6uY2eO0jd5TMQiCYB CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S9>/Saturation'
                                                    *   '<S53>/kd'
                                                    *   '<S53>/Saturation'
                                                    *   '<S54>/ki'
                                                    *   '<S54>/Discrete-Time Integrator'
                                                    *   '<S55>/kp'
                                                    *   '<S12>/Saturation'
                                                    *   '<S12>/Saturation1'
                                                    *   '<S35>/kd'
                                                    *   '<S35>/Saturation'
                                                    *   '<S36>/ki'
                                                    *   '<S36>/Discrete-Time Integrator'
                                                    *   '<S37>/kp'
                                                    *   '<S26>/Constant1'
                                                    *   '<S26>/Constant2'
                                                    *   '<S18>/gain1'
                                                    *   '<S18>/gain2'
                                                    *   '<S18>/gain3'
                                                    *   '<S18>/Saturation'
                                                    *   '<S19>/gain1'
                                                    *   '<S19>/gain2'
                                                    *   '<S19>/gain3'
                                                    *   '<S19>/Discrete-Time Integrator'
                                                    *   '<S20>/gain1'
                                                    *   '<S20>/gain2'
                                                    *   '<S20>/gain3'
                                                    */
extern struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
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
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'Controller/Bus_Assignment'
 * '<S2>'   : 'Controller/Controller'
 * '<S3>'   : 'Controller/Bus_Assignment/Compare To Constant'
 * '<S4>'   : 'Controller/Bus_Assignment/timestamp'
 * '<S5>'   : 'Controller/Controller/Horizontal_Control'
 * '<S6>'   : 'Controller/Controller/Static_Control_Allocation'
 * '<S7>'   : 'Controller/Controller/Vertical_Control'
 * '<S8>'   : 'Controller/Controller/Horizontal_Control/Attitude_Controller'
 * '<S9>'   : 'Controller/Controller/Horizontal_Control/Velocity_Controller'
 * '<S10>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S11>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S12>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Conversion'
 * '<S13>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S14>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Routing'
 * '<S15>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Conversion/euler_to_ang_rate'
 * '<S16>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S17>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S18>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S19>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S20>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S21>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT1_Filter'
 * '<S22>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Routing/Compare To Constant'
 * '<S23>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S24>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Routing'
 * '<S25>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S26>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S27>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S28>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S29>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Routing/Compare To Constant'
 * '<S30>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Conversion'
 * '<S31>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S32>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S33>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Subsystem'
 * '<S34>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Subsystem/M_CO'
 * '<S35>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S36>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S37>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S38>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT1_Filter'
 * '<S39>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT1_Filter1'
 * '<S40>'  : 'Controller/Controller/Static_Control_Allocation/Signal_Routing'
 * '<S41>'  : 'Controller/Controller/Static_Control_Allocation/throttle_map'
 * '<S42>'  : 'Controller/Controller/Static_Control_Allocation/Signal_Routing/Compare To Constant'
 * '<S43>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller'
 * '<S44>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S45>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller1'
 * '<S46>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller/Error'
 * '<S47>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller/PID_Controller'
 * '<S48>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller/PID_Controller/Boosted_Throttle'
 * '<S49>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller/PID_Controller/D_Control'
 * '<S50>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller/PID_Controller/I_Control'
 * '<S51>'  : 'Controller/Controller/Vertical_Control/Accel_Z_Controller/PID_Controller/P_Control'
 * '<S52>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S53>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/D_Control'
 * '<S54>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/I_Control'
 * '<S55>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/P_Control'
 * '<S56>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/D_Control/DT1_Filter'
 * '<S57>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/D_Control/Derivative'
 * '<S58>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller1/Error'
 * '<S59>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller1/P_Controller'
 * '<S60>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller1/P_Controller/P_Control'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
