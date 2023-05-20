/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.940
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 20 10:48:40 2023
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
  real32_T Integrator1_DSTATE[2];      /* '<S62>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S67>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S69>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S38>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S40>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];/* '<S42>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_p;       /* '<S78>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S81>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S83>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S62>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S78>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S67>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S69>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S40>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S42>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S81>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_iy;/* '<S83>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S38>/Discrete-Time Integrator5' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S64>/Vector Concatenate3' */
  const real32_T Constant;             /* '<S67>/Constant' */
  const real32_T Gain;                 /* '<S52>/Gain' */
  const real32_T Constant_n[3];        /* '<S40>/Constant' */
  const real32_T Constant_b;           /* '<S81>/Constant' */
  const real32_T Square;               /* '<S65>/Square' */
  const real32_T d;                    /* '<S65>/Multiply' */
  const real32_T Gain4;                /* '<S65>/Gain4' */
  const real32_T Square_g;             /* '<S79>/Square' */
  const real32_T d_n;                  /* '<S79>/Multiply' */
  const real32_T Gain4_k;              /* '<S79>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if AIRFRAME == 3

  /* Computed Parameter: Effective_Matrix_Value
   * Referenced by: '<S7>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value[24];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 2

  /* Computed Parameter: Effective_Matrix_Value_f
   * Referenced by: '<S8>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_f[12];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  /* Computed Parameter: Effective_Matrix_Value_h
   * Referenced by: '<S9>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_h[12];

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
                                                   *   '<S12>/hover_throttle'
                                                   *   '<S18>/hover_throttle'
                                                   *   '<S24>/hover_throttle'
                                                   *   '<S57>/Saturation'
                                                   *   '<S33>/Saturation'
                                                   *   '<S33>/Saturation1'
                                                   *   '<S66>/kd'
                                                   *   '<S66>/Saturation'
                                                   *   '<S67>/ki'
                                                   *   '<S67>/Discrete-Time Integrator'
                                                   *   '<S68>/kp'
                                                   *   '<S80>/kd'
                                                   *   '<S80>/Saturation'
                                                   *   '<S81>/ki'
                                                   *   '<S81>/Discrete-Time Integrator'
                                                   *   '<S82>/kp'
                                                   *   '<S50>/Constant1'
                                                   *   '<S50>/Constant2'
                                                   *   '<S39>/gain1'
                                                   *   '<S39>/gain2'
                                                   *   '<S39>/gain3'
                                                   *   '<S39>/Saturation'
                                                   *   '<S40>/gain1'
                                                   *   '<S40>/gain2'
                                                   *   '<S40>/gain3'
                                                   *   '<S40>/Discrete-Time Integrator'
                                                   *   '<S41>/gain1'
                                                   *   '<S41>/gain2'
                                                   *   '<S41>/gain3'
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
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Signal Copy1' : Eliminate redundant signal conversion block
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
 * '<S6>'   : 'Controller/Controller/Vertical_Control'
 * '<S7>'   : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x'
 * '<S8>'   : 'Controller/Controller/Control_Allocation/Quadcopter_+'
 * '<S9>'   : 'Controller/Controller/Control_Allocation/Quadcopter_x'
 * '<S10>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select'
 * '<S11>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/actuator_cmd_routing'
 * '<S12>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/throttle_mapping'
 * '<S13>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S14>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S15>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S16>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select'
 * '<S17>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/actuator_cmd_routing'
 * '<S18>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/throttle_mapping'
 * '<S19>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Compare To Constant'
 * '<S20>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Compare To Constant1'
 * '<S21>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Offboard_Signal_Select'
 * '<S22>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S23>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S24>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S25>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S26>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S27>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S28>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller'
 * '<S29>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller'
 * '<S30>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S31>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S32>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S33>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S34>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S35>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S36>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S37>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S38>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S39>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S40>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S41>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S42>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S43>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S44>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S45>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S46>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S47>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S48>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S49>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S50>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S51>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S52>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S53>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S54>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S55>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S56>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S57>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S58>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S59>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S60>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S61>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S62>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S63>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S64>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S65>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S66>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S67>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S68>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S69>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S70>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S71>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S72>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S73>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S74>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S75>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S76>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S77>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S78>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S79>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S80>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S81>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S82>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S83>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
