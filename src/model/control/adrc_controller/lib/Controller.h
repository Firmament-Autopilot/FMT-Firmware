/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.975
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov  2 15:47:35 2023
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
  real32_T Integrator1_DSTATE[2];      /* '<S102>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S107>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S109>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S76>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S80>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];/* '<S82>/Discrete-Time Integrator1' */
  real32_T Integrator11_DSTATE;        /* '<S78>/Integrator1 1' */
  real32_T Integrator12_DSTATE;        /* '<S78>/Integrator1 2' */
  real32_T Integrator13_DSTATE;        /* '<S78>/Integrator1 3' */
  real32_T Integrator1_DSTATE_p;       /* '<S118>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S121>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S123>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_a[3];    /* '<S77>/Integrator1 ' */
  real32_T Integrator_DSTATE[2];       /* '<S102>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S118>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S107>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S109>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S80>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S82>/Discrete-Time Integrator1' */
  int8_T Integrator11_PrevResetState;  /* '<S78>/Integrator1 1' */
  int8_T Integrator12_PrevResetState;  /* '<S78>/Integrator1 2' */
  int8_T Integrator13_PrevResetState;  /* '<S78>/Integrator1 3' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S121>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_iy;/* '<S123>/Discrete-Time Integrator1' */
  int8_T Integrator1_PrevResetState;   /* '<S77>/Integrator1 ' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S109>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S76>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_l;/* '<S82>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_k;/* '<S123>/Discrete-Time Integrator1' */
  uint8_T Integrator1_IC_LOADING;      /* '<S77>/Integrator1 ' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T VectorConcatenate3[3];/* '<S104>/Vector Concatenate3' */
  const real32_T Constant;             /* '<S107>/Constant' */
  const real32_T Gain;                 /* '<S92>/Gain' */
  const real32_T Constant_n[3];        /* '<S80>/Constant' */
  const real32_T Square;               /* '<S105>/Square' */
  const real32_T d;                    /* '<S105>/Multiply' */
  const real32_T Gain4;                /* '<S105>/Gain4' */
  const real32_T Square_g;             /* '<S119>/Square' */
  const real32_T d_n;                  /* '<S119>/Multiply' */
  const real32_T Gain4_k;              /* '<S119>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {

#if AIRFRAME == 6

  /* Computed Parameter: Effective_Matrix_Value
   * Referenced by: '<S7>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value[36];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 3

  /* Computed Parameter: Effective_Matrix_Value_j
   * Referenced by: '<S8>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_j[24];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 5

  /* Computed Parameter: Effective_Matrix_Value_je
   * Referenced by: '<S9>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_je[18];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 4

  /* Computed Parameter: Effective_Matrix_Value_f
   * Referenced by: '<S10>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_f[18];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 8

  /* Computed Parameter: Effective_Matrix_Value_m
   * Referenced by: '<S11>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_m[24];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 7

  /* Computed Parameter: Effective_Matrix_Value_k
   * Referenced by: '<S12>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_k[24];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 2

  /* Computed Parameter: Effective_Matrix_Value_fr
   * Referenced by: '<S13>/Effective_Matrix'
   */
  real32_T Effective_Matrix_Value_fr[12];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  /* Computed Parameter: Effective_Matrix_Value_h
   * Referenced by: '<S14>/Effective_Matrix'
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
extern struct_9l8r30AuvaBTupxphpyOQF CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S17>/hover_throttle'
                                                    *   '<S23>/hover_throttle'
                                                    *   '<S29>/hover_throttle'
                                                    *   '<S35>/hover_throttle'
                                                    *   '<S41>/hover_throttle'
                                                    *   '<S47>/hover_throttle'
                                                    *   '<S53>/hover_throttle'
                                                    *   '<S59>/hover_throttle'
                                                    *   '<S97>/Saturation'
                                                    *   '<S68>/Saturation'
                                                    *   '<S68>/Saturation1'
                                                    *   '<S106>/kd'
                                                    *   '<S106>/Saturation'
                                                    *   '<S107>/ki'
                                                    *   '<S107>/Discrete-Time Integrator'
                                                    *   '<S108>/kp'
                                                    *   '<S120>/kd'
                                                    *   '<S120>/Saturation'
                                                    *   '<S121>/Constant'
                                                    *   '<S121>/ki'
                                                    *   '<S121>/Discrete-Time Integrator'
                                                    *   '<S122>/kp'
                                                    *   '<S71>/Constant3'
                                                    *   '<S71>/Constant4'
                                                    *   '<S71>/Constant5'
                                                    *   '<S71>/Constant6'
                                                    *   '<S71>/Constant7'
                                                    *   '<S71>/Constant8'
                                                    *   '<S90>/Constant1'
                                                    *   '<S90>/Constant2'
                                                    *   '<S77>/Constant3'
                                                    *   '<S77>/Constant4'
                                                    *   '<S77>/Constant5'
                                                    *   '<S77>/Constant6'
                                                    *   '<S77>/Constant7'
                                                    *   '<S77>/Constant8'
                                                    *   '<S78>/Constant'
                                                    *   '<S78>/Constant1'
                                                    *   '<S78>/Constant2'
                                                    *   '<S79>/gain1'
                                                    *   '<S79>/gain2'
                                                    *   '<S79>/gain3'
                                                    *   '<S79>/Saturation'
                                                    *   '<S80>/gain1'
                                                    *   '<S80>/gain2'
                                                    *   '<S80>/gain3'
                                                    *   '<S80>/Discrete-Time Integrator'
                                                    *   '<S81>/gain1'
                                                    *   '<S81>/gain2'
                                                    *   '<S81>/gain3'
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
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S116>/Signal Copy1' : Eliminate redundant signal conversion block
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
 * '<S7>'   : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x'
 * '<S8>'   : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x'
 * '<S9>'   : 'Controller/Controller/Control_Allocation/Hexacopter_+'
 * '<S10>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x'
 * '<S11>'  : 'Controller/Controller/Control_Allocation/Octocopter_+'
 * '<S12>'  : 'Controller/Controller/Control_Allocation/Octocopter_x'
 * '<S13>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+'
 * '<S14>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x'
 * '<S15>'  : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x/Signal_Select'
 * '<S16>'  : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x/actuator_cmd_routing'
 * '<S17>'  : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x/throttle_mapping'
 * '<S18>'  : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x/Signal_Select/Compare To Constant'
 * '<S19>'  : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x/Signal_Select/Compare To Constant1'
 * '<S20>'  : 'Controller/Controller/Control_Allocation/Coxial_Hexacopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S21>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select'
 * '<S22>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/actuator_cmd_routing'
 * '<S23>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/throttle_mapping'
 * '<S24>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S25>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S26>'  : 'Controller/Controller/Control_Allocation/Coxial_Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S27>'  : 'Controller/Controller/Control_Allocation/Hexacopter_+/Signal_Select'
 * '<S28>'  : 'Controller/Controller/Control_Allocation/Hexacopter_+/actuator_cmd_routing'
 * '<S29>'  : 'Controller/Controller/Control_Allocation/Hexacopter_+/throttle_mapping'
 * '<S30>'  : 'Controller/Controller/Control_Allocation/Hexacopter_+/Signal_Select/Compare To Constant'
 * '<S31>'  : 'Controller/Controller/Control_Allocation/Hexacopter_+/Signal_Select/Compare To Constant1'
 * '<S32>'  : 'Controller/Controller/Control_Allocation/Hexacopter_+/Signal_Select/Offboard_Signal_Select'
 * '<S33>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x/Signal_Select'
 * '<S34>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x/actuator_cmd_routing'
 * '<S35>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x/throttle_mapping'
 * '<S36>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x/Signal_Select/Compare To Constant'
 * '<S37>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x/Signal_Select/Compare To Constant1'
 * '<S38>'  : 'Controller/Controller/Control_Allocation/Hexacopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S39>'  : 'Controller/Controller/Control_Allocation/Octocopter_+/Signal_Select'
 * '<S40>'  : 'Controller/Controller/Control_Allocation/Octocopter_+/actuator_cmd_routing'
 * '<S41>'  : 'Controller/Controller/Control_Allocation/Octocopter_+/throttle_mapping'
 * '<S42>'  : 'Controller/Controller/Control_Allocation/Octocopter_+/Signal_Select/Compare To Constant'
 * '<S43>'  : 'Controller/Controller/Control_Allocation/Octocopter_+/Signal_Select/Compare To Constant1'
 * '<S44>'  : 'Controller/Controller/Control_Allocation/Octocopter_+/Signal_Select/Offboard_Signal_Select'
 * '<S45>'  : 'Controller/Controller/Control_Allocation/Octocopter_x/Signal_Select'
 * '<S46>'  : 'Controller/Controller/Control_Allocation/Octocopter_x/actuator_cmd_routing'
 * '<S47>'  : 'Controller/Controller/Control_Allocation/Octocopter_x/throttle_mapping'
 * '<S48>'  : 'Controller/Controller/Control_Allocation/Octocopter_x/Signal_Select/Compare To Constant'
 * '<S49>'  : 'Controller/Controller/Control_Allocation/Octocopter_x/Signal_Select/Compare To Constant1'
 * '<S50>'  : 'Controller/Controller/Control_Allocation/Octocopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S51>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select'
 * '<S52>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/actuator_cmd_routing'
 * '<S53>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/throttle_mapping'
 * '<S54>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Compare To Constant'
 * '<S55>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Compare To Constant1'
 * '<S56>'  : 'Controller/Controller/Control_Allocation/Quadcopter_+/Signal_Select/Offboard_Signal_Select'
 * '<S57>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S58>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S59>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S60>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S61>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S62>'  : 'Controller/Controller/Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S63>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller'
 * '<S64>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller'
 * '<S65>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S66>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S67>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S68>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S69>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S70>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Bus_Select'
 * '<S71>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Disturbance_Compensation'
 * '<S72>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S73>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/LESO'
 * '<S74>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S75>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S76>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S77>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/LESO/leso_z1'
 * '<S78>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/LESO/leso_z2'
 * '<S79>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S80>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S81>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S82>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S83>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S84>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S85>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S86>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S87>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S88>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S89>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S90>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S91>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S92>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S93>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S94>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S95>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S96>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S97>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S98>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S99>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S100>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S101>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S102>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S103>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S104>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S105>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S106>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S107>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S108>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S109>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S110>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S111>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S112>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S113>' : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S114>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S115>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S116>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S117>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S118>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S119>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S120>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S121>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S122>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S123>' : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
