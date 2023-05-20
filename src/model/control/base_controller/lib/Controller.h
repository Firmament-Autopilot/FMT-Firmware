/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.934
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 20 09:53:37 2023
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
  real32_T Integrator1_DSTATE;         /* '<S84>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S87>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S89>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_g[2];    /* '<S63>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m[2];/* '<S68>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m[2];/* '<S70>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S39>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S41>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];/* '<S43>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S63>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S84>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S87>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S89>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S68>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S70>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S41>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S43>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S39>/Discrete-Time Integrator5' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant;             /* '<S87>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S65>/Vector Concatenate3' */
  const real32_T Constant_g;           /* '<S68>/Constant' */
  const real32_T Gain;                 /* '<S53>/Gain' */
  const real32_T Constant_n[3];        /* '<S41>/Constant' */
  const real32_T Square;               /* '<S66>/Square' */
  const real32_T d;                    /* '<S66>/Multiply' */
  const real32_T Gain4;                /* '<S66>/Gain4' */
  const real32_T Square_g;             /* '<S85>/Square' */
  const real32_T d_n;                  /* '<S85>/Multiply' */
  const real32_T Gain4_k;              /* '<S85>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Effective_Matrix_Value
   * Referenced by: '<S10>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value[12];
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
extern struct_2EnWz3ceFwjQa7SDRNn3C CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                   * Referenced by:
                                                   *   '<S25>/hover_throttle'
                                                   *   '<S58>/Saturation'
                                                   *   '<S34>/Saturation'
                                                   *   '<S34>/Saturation1'
                                                   *   '<S67>/kd'
                                                   *   '<S67>/Saturation'
                                                   *   '<S68>/ki'
                                                   *   '<S68>/Discrete-Time Integrator'
                                                   *   '<S69>/kp'
                                                   *   '<S86>/kd'
                                                   *   '<S86>/Saturation'
                                                   *   '<S87>/ki'
                                                   *   '<S87>/Discrete-Time Integrator'
                                                   *   '<S88>/kp'
                                                   *   '<S51>/Constant1'
                                                   *   '<S51>/Constant2'
                                                   *   '<S40>/gain1'
                                                   *   '<S40>/gain2'
                                                   *   '<S40>/gain3'
                                                   *   '<S40>/Saturation'
                                                   *   '<S41>/gain1'
                                                   *   '<S41>/gain2'
                                                   *   '<S41>/gain3'
                                                   *   '<S41>/Discrete-Time Integrator'
                                                   *   '<S42>/gain1'
                                                   *   '<S42>/gain2'
                                                   *   '<S42>/gain3'
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
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S82>/Signal Copy1' : Eliminate redundant signal conversion block
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
 * '<S5>'   : 'Controller/Controller/Horizontal_Control'
 * '<S6>'   : 'Controller/Controller/Static_Control_Allocation1'
 * '<S7>'   : 'Controller/Controller/Vertical_Control'
 * '<S8>'   : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x'
 * '<S9>'   : 'Controller/Controller/Control_Allocation/Quadcopter_+'
 * '<S10>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x'
 * '<S11>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select'
 * '<S12>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/actuator_cmd_routing'
 * '<S13>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/throttle_mapping'
 * '<S14>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S15>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S16>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S17>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select'
 * '<S18>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/actuator_cmd_routing'
 * '<S19>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/throttle_mapping'
 * '<S20>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Compare To Constant'
 * '<S21>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Compare To Constant1'
 * '<S22>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Offboard_Signal_Select'
 * '<S23>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S24>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S25>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S26>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S27>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S28>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S29>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller'
 * '<S30>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller'
 * '<S31>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S32>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S33>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S34>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S35>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S36>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S37>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S38>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S39>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S40>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S41>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S42>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S43>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S44>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S45>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S46>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S47>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S48>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S49>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S50>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S51>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S52>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S53>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S54>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S55>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S56>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S57>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S58>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S59>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S60>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S61>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S62>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S63>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S64>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S65>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S66>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S67>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S68>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S69>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S70>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S71>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S72>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S73>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S74>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S75>'  : 'Controller/Controller/Static_Control_Allocation1/Signal_Select'
 * '<S76>'  : 'Controller/Controller/Static_Control_Allocation1/throttle_mapping'
 * '<S77>'  : 'Controller/Controller/Static_Control_Allocation1/Signal_Select/Compare To Constant'
 * '<S78>'  : 'Controller/Controller/Static_Control_Allocation1/Signal_Select/Compare To Constant1'
 * '<S79>'  : 'Controller/Controller/Static_Control_Allocation1/Signal_Select/Offboard_Signal_Select'
 * '<S80>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S81>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S82>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S83>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S84>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S85>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S86>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S87>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S88>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S89>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
