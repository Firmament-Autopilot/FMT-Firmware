/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1110
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 13:51:52 2025
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
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S9>/Discrete-Time Integrator5' */
  real32_T _DSTATE;                    /* '<S42>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S43>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S16>/Discrete-Time Integrator' */
  real32_T _DSTATE_m;                  /* '<S45>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S46>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S42>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S43>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S16>/Discrete-Time Integrator' */
  int8_T _PrevResetState_k;            /* '<S45>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_m;/* '<S46>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S9>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S43>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_o;/* '<S46>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Zero1;                /* '<S42>/Zero1' */
  const real32_T Constant[3];          /* '<S16>/Constant' */
  const real32_T Zero;                 /* '<S45>/Zero' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Disarm_Value
   * Referenced by: '<S31>/Disarm'
   */
  uint16_T Disarm_Value[6];

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S31>/Standby'
   */
  uint16_T Standby_Value[6];
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
extern struct_cGQ7mab9VSTQmeIosgrbRH CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S7>/Saturation'
                                                    *   '<S8>/Gain'
                                                    *   '<S8>/Gain1'
                                                    *   '<S8>/balabnce_ratio2'
                                                    *   '<S8>/balance_ratio'
                                                    *   '<S8>/pitch_ff'
                                                    *   '<S8>/thorttle_ff'
                                                    *   '<S8>/ucmd2pitch'
                                                    *   '<S8>/ucmd2thor'
                                                    *   '<S8>/wcmd2pitch'
                                                    *   '<S8>/wcmd2thor'
                                                    *   '<S10>/FF'
                                                    *   '<S10>/FF_limit'
                                                    *   '<S10>/PI_limit'
                                                    *   '<S37>/P_control'
                                                    *   '<S38>/P_control'
                                                    *   '<S14>/trim_speed'
                                                    *   '<S15>/trim_speed'
                                                    *   '<S28>/Constant1'
                                                    *   '<S28>/Constant12'
                                                    *   '<S28>/Constant2'
                                                    *   '<S28>/Constant7'
                                                    *   '<S41>/Gain'
                                                    *   '<S42>/ '
                                                    *   '<S42>/Gain3'
                                                    *   '<S44>/Gain'
                                                    *   '<S45>/ '
                                                    *   '<S45>/Gain'
                                                    *   '<S16>/gain1'
                                                    *   '<S16>/gain2'
                                                    *   '<S16>/gain3'
                                                    *   '<S16>/Discrete-Time Integrator'
                                                    *   '<S17>/gain1'
                                                    *   '<S17>/gain2'
                                                    *   '<S17>/gain3'
                                                    *   '<S21>/Pitch Offset'
                                                    *   '<S21>/Saturation'
                                                    *   '<S22>/Constant1'
                                                    *   '<S22>/Constant2'
                                                    */
extern struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
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
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Reshape' : Reshape block reduction
 * Block '<S20>/Logical Operator1' : Eliminated due to no operation
 * Block '<S27>/Reshape' : Reshape block reduction
 * Block '<S36>/Logical Operator' : Eliminated due to no operation
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
 * '<S4>'   : 'Controller/Controller/Airspeed'
 * '<S5>'   : 'Controller/Controller/Attitude_Control'
 * '<S6>'   : 'Controller/Controller/Control_Allocation'
 * '<S7>'   : 'Controller/Controller/Lateral_Control'
 * '<S8>'   : 'Controller/Controller/TECS_Core'
 * '<S9>'   : 'Controller/Controller/Airspeed/First Order LPF'
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
 * '<S27>'  : 'Controller/Controller/Control_Allocation/Fixwing'
 * '<S28>'  : 'Controller/Controller/Control_Allocation/Fixwing/Effective_Matrix'
 * '<S29>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select'
 * '<S30>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select1'
 * '<S31>'  : 'Controller/Controller/Control_Allocation/Fixwing/actuator_cmd_routing'
 * '<S32>'  : 'Controller/Controller/Control_Allocation/Fixwing/throttle_mapping'
 * '<S33>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select/Compare To Constant'
 * '<S34>'  : 'Controller/Controller/Control_Allocation/Fixwing/Signal_Select1/Compare To Constant'
 * '<S35>'  : 'Controller/Controller/TECS_Core/path_angle_control'
 * '<S36>'  : 'Controller/Controller/TECS_Core/phi_cmd'
 * '<S37>'  : 'Controller/Controller/TECS_Core/pitch_pid_out'
 * '<S38>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out'
 * '<S39>'  : 'Controller/Controller/TECS_Core/velocity_control'
 * '<S40>'  : 'Controller/Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S41>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S42>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S43>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S44>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S45>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S46>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S47>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S48>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Compare To Constant'
 * '<S49>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM'
 * '<S50>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S51>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_1'
 * '<S52>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_2'
 * '<S53>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_3'
 * '<S54>'  : 'Controller/Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
