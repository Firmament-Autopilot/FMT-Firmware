/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.141
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug  6 13:46:11 2024
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
  real32_T Constant;                   /* '<S71>/Constant' */
  real32_T Constant_m;                 /* '<S119>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S23>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S45>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S50>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S52>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S21>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S25>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_e;       /* '<S68>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S71>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S73>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S45>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S68>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S124>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S123>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_i;       /* '<S116>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S119>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S121>/Discrete-Time Integrator1' */
  real32_T _DSTATE;                    /* '<S154>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S155>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S89>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S91>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S93>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S122>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S134>/Discrete-Time Integrator' */
  real32_T _DSTATE_d;                  /* '<S157>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S158>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_f;        /* '<S116>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  uint16_T Delay_DSTATE;               /* '<S167>/Delay' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S7>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S23>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S50>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S52>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S25>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S71>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S73>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S119>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S121>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S154>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S155>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S91>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S93>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S134>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S157>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S158>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S52>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S21>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S25>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S73>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S124>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S123>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S121>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S155>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S89>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S93>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S122>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S158>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S75>/Relay' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant[3];          /* '<S23>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S47>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S50>/Constant' */
  const real32_T Gain;                 /* '<S35>/Gain' */
  const real32_T Square;               /* '<S48>/Square' */
  const real32_T d;                    /* '<S48>/Multiply' */
  const real32_T Gain4;                /* '<S48>/Gain4' */
  const real32_T Square_h;             /* '<S69>/Square' */
  const real32_T d_i;                  /* '<S69>/Multiply' */
  const real32_T Gain4_p;              /* '<S69>/Gain4' */
  const real32_T Square1;              /* '<S75>/Square1' */
  const real32_T Zero1;                /* '<S154>/Zero1' */
  const real32_T Gain_n;               /* '<S99>/Gain' */
  const real32_T Constant_j[3];        /* '<S91>/Constant' */
  const real32_T Constant_c[3];        /* '<S134>/Constant' */
  const real32_T Zero;                 /* '<S157>/Zero' */
  const real32_T Square_h2;            /* '<S117>/Square' */
  const real32_T d_m;                  /* '<S117>/Multiply' */
  const real32_T Gain4_o;              /* '<S117>/Gain4' */
  const real32_T dT;                   /* '<S167>/dT' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S57>/Effective_Matrix'
   *   '<S164>/Effective_Matrix'
   */
  real32_T pooled12[12];

  /* Computed Parameter: Disarm_Value
   * Referenced by: '<S165>/Disarm'
   */
  uint16_T Disarm_Value[9];

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S165>/Standby'
   */
  uint16_T Standby_Value[9];

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S59>/Disarm1'
   */
  uint16_T Disarm1_Value[5];
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
extern struct_EKLmLRDj4sm70rxKUP2Rn CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                   * Referenced by:
                                                   *   '<S80>/mc_hover_throttle'
                                                   *   '<S126>/Saturation'
                                                   *   '<S127>/Gain'
                                                   *   '<S127>/Gain1'
                                                   *   '<S127>/balabnce_ratio2'
                                                   *   '<S127>/balance_ratio'
                                                   *   '<S127>/pitch_ff'
                                                   *   '<S127>/thorttle_ff'
                                                   *   '<S127>/ucmd2pitch'
                                                   *   '<S127>/ucmd2thor'
                                                   *   '<S127>/wcmd2pitch'
                                                   *   '<S127>/wcmd2thor'
                                                   *   '<S40>/Saturation'
                                                   *   '<S60>/hover_throttle'
                                                   *   '<S128>/FF'
                                                   *   '<S128>/FF_limit'
                                                   *   '<S128>/PI_limit'
                                                   *   '<S147>/P_control'
                                                   *   '<S148>/P_control'
                                                   *   '<S16>/Saturation'
                                                   *   '<S16>/Saturation1'
                                                   *   '<S49>/kd'
                                                   *   '<S49>/Saturation'
                                                   *   '<S50>/ki'
                                                   *   '<S50>/Discrete-Time Integrator'
                                                   *   '<S51>/kp'
                                                   *   '<S70>/kd'
                                                   *   '<S70>/Saturation'
                                                   *   '<S71>/Constant'
                                                   *   '<S71>/ki'
                                                   *   '<S71>/Discrete-Time Integrator'
                                                   *   '<S72>/kp'
                                                   *   '<S85>/Saturation'
                                                   *   '<S85>/Saturation1'
                                                   *   '<S132>/trim_speed'
                                                   *   '<S133>/trim_speed'
                                                   *   '<S150>/Constant'
                                                   *   '<S151>/Constant'
                                                   *   '<S153>/Gain'
                                                   *   '<S154>/ '
                                                   *   '<S154>/Gain3'
                                                   *   '<S156>/Gain'
                                                   *   '<S157>/Gain'
                                                   *   '<S159>/Constant'
                                                   *   '<S33>/Constant1'
                                                   *   '<S33>/Constant2'
                                                   *   '<S97>/Constant1'
                                                   *   '<S97>/Constant2'
                                                   *   '<S118>/kd'
                                                   *   '<S118>/Saturation'
                                                   *   '<S119>/Constant'
                                                   *   '<S119>/ki'
                                                   *   '<S119>/Discrete-Time Integrator'
                                                   *   '<S120>/kp'
                                                   *   '<S134>/gain1'
                                                   *   '<S134>/gain2'
                                                   *   '<S134>/gain3'
                                                   *   '<S134>/Discrete-Time Integrator'
                                                   *   '<S135>/gain1'
                                                   *   '<S135>/gain2'
                                                   *   '<S135>/gain3'
                                                   *   '<S139>/Pitch Offset'
                                                   *   '<S139>/Saturation'
                                                   *   '<S140>/Constant1'
                                                   *   '<S140>/Constant2'
                                                   *   '<S166>/Constant1'
                                                   *   '<S166>/Constant12'
                                                   *   '<S166>/Constant2'
                                                   *   '<S166>/Constant7'
                                                   *   '<S22>/gain1'
                                                   *   '<S22>/gain2'
                                                   *   '<S22>/gain3'
                                                   *   '<S22>/Saturation'
                                                   *   '<S23>/gain1'
                                                   *   '<S23>/gain2'
                                                   *   '<S23>/gain3'
                                                   *   '<S23>/Discrete-Time Integrator'
                                                   *   '<S24>/gain1'
                                                   *   '<S24>/gain2'
                                                   *   '<S24>/gain3'
                                                   *   '<S90>/gain1'
                                                   *   '<S90>/gain2'
                                                   *   '<S90>/gain3'
                                                   *   '<S90>/Saturation'
                                                   *   '<S91>/gain1'
                                                   *   '<S91>/gain2'
                                                   *   '<S91>/gain3'
                                                   *   '<S91>/Discrete-Time Integrator'
                                                   *   '<S92>/gain1'
                                                   *   '<S92>/gain2'
                                                   *   '<S92>/gain3'
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
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Propagation' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S66>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S89>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S114>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S122>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S123>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S124>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Reshape' : Reshape block reduction
 * Block '<S138>/Logical Operator1' : Eliminated due to no operation
 * Block '<S146>/Logical Operator' : Eliminated due to no operation
 * Block '<S162>/Reshape' : Reshape block reduction
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
 * '<S4>'   : 'Controller/Controller/MC_Controller'
 * '<S5>'   : 'Controller/Controller/VTOL_Controller'
 * '<S6>'   : 'Controller/Controller/ctrl_mode_mask'
 * '<S7>'   : 'Controller/Controller/switch-case'
 * '<S8>'   : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S9>'   : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S10>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S11>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S12>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S13>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S14>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S15>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S16>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S17>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S18>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S19>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S20>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S21>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S22>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S23>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S24>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S25>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S26>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S27>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S28>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S29>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S30>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S31>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S32>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S33>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S34>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S35>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S36>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S37>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S38>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S39>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S40>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S41>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S42>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S43>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S44>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S45>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S46>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S47>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S48>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S49>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S50>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S51>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S52>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S53>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S54>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S55>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S56>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S57>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S58>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S59>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S60>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S61>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S62>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S63>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S64>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S65>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S66>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S67>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S68>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S69>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S70>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S71>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S72>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S73>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S74>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller'
 * '<S75>'  : 'Controller/Controller/VTOL_Controller/Effective_Factor'
 * '<S76>'  : 'Controller/Controller/VTOL_Controller/FW_Controller'
 * '<S77>'  : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation'
 * '<S78>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S79>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S80>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S81>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S82>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S83>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S84>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S85>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S86>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S87>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S88>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S89>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S90>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S91>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S92>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S93>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S94>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S95>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S96>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S97>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S98>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S99>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S100>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S101>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S102>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S103>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S104>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S105>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S106>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Compare To Constant'
 * '<S107>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Compare To Constant'
 * '<S108>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Stabilize'
 * '<S109>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Compare To Constant'
 * '<S110>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Stabilize'
 * '<S111>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S112>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S113>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S114>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S115>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S116>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S117>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S118>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S119>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S120>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S121>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S122>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF'
 * '<S123>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF1'
 * '<S124>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF2'
 * '<S125>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control'
 * '<S126>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Lateral_Control'
 * '<S127>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core'
 * '<S128>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S129>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S130>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S131>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S132>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S133>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S134>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S135>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S136>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S137>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S138>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S139>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S140>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S141>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S142>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S143>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S144>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S145>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S146>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S147>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S148>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S149>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S150>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S151>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem1'
 * '<S152>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S153>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S154>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S155>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S156>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S157>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S158>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S159>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/speed_ax_out'
 * '<S160>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S161>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S162>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S163>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S164>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S165>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S166>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S167>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S168>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S169>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S170>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select/Compare To Constant1'
 * '<S171>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
