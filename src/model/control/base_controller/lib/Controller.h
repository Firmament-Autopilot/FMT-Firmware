/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.903
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Oct 12 14:06:21 2022
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
  real32_T Integrator1_DSTATE;         /* '<S63>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S66>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S68>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_g[2];    /* '<S42>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_m[2];/* '<S47>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m[2];/* '<S49>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S18>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S20>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];/* '<S22>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S42>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S63>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S4>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S66>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S68>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S47>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S49>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S20>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S22>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S18>/Discrete-Time Integrator5' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant;             /* '<S66>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S44>/Vector Concatenate3' */
  const real32_T Constant_g;           /* '<S47>/Constant' */
  const real32_T Gain;                 /* '<S32>/Gain' */
  const real32_T Constant_n[3];        /* '<S20>/Constant' */
  const real32_T Square;               /* '<S45>/Square' */
  const real32_T d;                    /* '<S45>/Multiply' */
  const real32_T Gain4;                /* '<S45>/Gain4' */
  const real32_T Square_g;             /* '<S64>/Square' */
  const real32_T d_n;                  /* '<S64>/Multiply' */
  const real32_T Gain4_k;              /* '<S64>/Gain4' */
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
                                                    *   '<S37>/Saturation'
                                                    *   '<S13>/Saturation'
                                                    *   '<S13>/Saturation1'
                                                    *   '<S46>/kd'
                                                    *   '<S46>/Saturation'
                                                    *   '<S47>/ki'
                                                    *   '<S47>/Discrete-Time Integrator'
                                                    *   '<S48>/kp'
                                                    *   '<S65>/kd'
                                                    *   '<S65>/Saturation'
                                                    *   '<S66>/ki'
                                                    *   '<S66>/Discrete-Time Integrator'
                                                    *   '<S67>/kp'
                                                    *   '<S30>/Constant1'
                                                    *   '<S30>/Constant2'
                                                    *   '<S19>/gain1'
                                                    *   '<S19>/gain2'
                                                    *   '<S19>/gain3'
                                                    *   '<S19>/Saturation'
                                                    *   '<S20>/gain1'
                                                    *   '<S20>/gain2'
                                                    *   '<S20>/gain3'
                                                    *   '<S20>/Discrete-Time Integrator'
                                                    *   '<S21>/gain1'
                                                    *   '<S21>/gain2'
                                                    *   '<S21>/gain3'
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
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Signal Copy1' : Eliminate redundant signal conversion block
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
 * '<S5>'   : 'Controller/Controller/Horizontal_Control'
 * '<S6>'   : 'Controller/Controller/Static_Control_Allocation'
 * '<S7>'   : 'Controller/Controller/Vertical_Control'
 * '<S8>'   : 'Controller/Controller/Horizontal_Control/Attitude_Controller'
 * '<S9>'   : 'Controller/Controller/Horizontal_Control/Velocity_Controller'
 * '<S10>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S11>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S12>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S13>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S14>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S15>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S16>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S17>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S18>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S19>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S20>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S21>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S22>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S23>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S24>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S25>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S26>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S27>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S28>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S29>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S30>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S31>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S32>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S33>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S34>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S35>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S36>'  : 'Controller/Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S37>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S38>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S39>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S40>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S41>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S42>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S43>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S44>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S45>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S46>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S47>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S48>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S49>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S50>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S51>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S52>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S53>'  : 'Controller/Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S54>'  : 'Controller/Controller/Static_Control_Allocation/Signal_Select'
 * '<S55>'  : 'Controller/Controller/Static_Control_Allocation/throttle_mapping'
 * '<S56>'  : 'Controller/Controller/Static_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S57>'  : 'Controller/Controller/Static_Control_Allocation/Signal_Select/Compare To Constant1'
 * '<S58>'  : 'Controller/Controller/Static_Control_Allocation/Signal_Select/Offboard_Signal_Select'
 * '<S59>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S60>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S61>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S62>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S63>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S64>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S65>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S66>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S67>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S68>'  : 'Controller/Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
