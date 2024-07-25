/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 24 10:38:02 2024
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
  real32_T Constant;                   /* '<S117>/Constant' */
  real32_T Constant_b;                 /* '<S72>/Constant' */
  uint16_T Reshape[16];                /* '<S156>/Reshape' */
  uint16_T Reshape_g[16];              /* '<S60>/Reshape' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T _DSTATE;                    /* '<S150>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S151>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S91>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S93>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S95>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE;         /* '<S114>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S117>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S119>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l[3];/* '<S130>/Discrete-Time Integrator' */
  real32_T _DSTATE_d;                  /* '<S153>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n;/* '<S154>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE;          /* '<S114>/Integrator' */
  real32_T Integrator1_DSTATE_e[2];    /* '<S46>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S51>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[2];/* '<S53>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S22>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_b0[3];/* '<S24>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm[3];/* '<S26>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_eq;      /* '<S69>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_lc;/* '<S72>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S74>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_l[2];     /* '<S46>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S69>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S7>/Switch Case1' */
  int8_T _PrevResetState;              /* '<S150>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S151>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S93>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S95>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S117>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S119>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S130>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S153>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S154>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S51>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S53>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S24>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S26>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S72>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S74>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S151>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S91>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S95>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S119>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S154>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_m;/* '<S53>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;/* '<S22>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S26>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S74>/Discrete-Time Integrator1' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Square1;              /* '<S120>/Square1' */
  const real32_T Zero1;                /* '<S150>/Zero1' */
  const real32_T Gain;                 /* '<S101>/Gain' */
  const real32_T Constant[3];          /* '<S93>/Constant' */
  const real32_T Constant_c[3];        /* '<S130>/Constant' */
  const real32_T Zero;                 /* '<S153>/Zero' */
  const real32_T Square;               /* '<S115>/Square' */
  const real32_T d;                    /* '<S115>/Multiply' */
  const real32_T Gain4;                /* '<S115>/Gain4' */
  const real32_T VectorConcatenate3[3];/* '<S48>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S51>/Constant' */
  const real32_T Gain_d;               /* '<S36>/Gain' */
  const real32_T Constant_a[3];        /* '<S24>/Constant' */
  const real32_T Square_o;             /* '<S49>/Square' */
  const real32_T d_f;                  /* '<S49>/Multiply' */
  const real32_T Gain4_b;              /* '<S49>/Gain4' */
  const real32_T Square_h;             /* '<S70>/Square' */
  const real32_T d_i;                  /* '<S70>/Multiply' */
  const real32_T Gain4_p;              /* '<S70>/Gain4' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S58>/Effective_Matrix'
   *   '<S165>/Effective_Matrix'
   */
  real32_T pooled5[12];

  /* Pooled Parameter (Expression: [1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S60>/Disarm1'
   *   '<S162>/Disarm'
   */
  uint16_T pooled28[5];

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S162>/Standby'
   */
  uint16_T Standby_Value[5];
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
extern struct_04mtDUt8mpbOWDWTaHkfhC CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S122>/Gain'
                                                    *   '<S122>/Gain1'
                                                    *   '<S122>/balabnce_ratio2'
                                                    *   '<S122>/balance_ratio'
                                                    *   '<S122>/pitch_ff'
                                                    *   '<S122>/thorttle_ff'
                                                    *   '<S122>/ucmd2pitch'
                                                    *   '<S122>/ucmd2thor'
                                                    *   '<S122>/wcmd2pitch'
                                                    *   '<S122>/wcmd2thor'
                                                    *   '<S123>/Saturation'
                                                    *   '<S41>/Saturation'
                                                    *   '<S61>/hover_throttle'
                                                    *   '<S124>/FF'
                                                    *   '<S124>/FF_limit'
                                                    *   '<S124>/PI_limit'
                                                    *   '<S143>/P_control'
                                                    *   '<S144>/P_control'
                                                    *   '<S17>/Saturation'
                                                    *   '<S17>/Saturation1'
                                                    *   '<S50>/kd'
                                                    *   '<S50>/Saturation'
                                                    *   '<S51>/ki'
                                                    *   '<S51>/Discrete-Time Integrator'
                                                    *   '<S52>/kp'
                                                    *   '<S71>/kd'
                                                    *   '<S71>/Saturation'
                                                    *   '<S72>/Constant'
                                                    *   '<S72>/ki'
                                                    *   '<S72>/Discrete-Time Integrator'
                                                    *   '<S73>/kp'
                                                    *   '<S87>/Saturation'
                                                    *   '<S87>/Saturation1'
                                                    *   '<S128>/trim_speed'
                                                    *   '<S129>/trim_speed'
                                                    *   '<S146>/Constant'
                                                    *   '<S147>/Constant'
                                                    *   '<S149>/Gain'
                                                    *   '<S150>/ '
                                                    *   '<S150>/Gain3'
                                                    *   '<S152>/Gain'
                                                    *   '<S153>/Gain'
                                                    *   '<S155>/Constant'
                                                    *   '<S160>/Constant1'
                                                    *   '<S160>/Constant12'
                                                    *   '<S160>/Constant2'
                                                    *   '<S160>/Constant7'
                                                    *   '<S167>/hover_throttle'
                                                    *   '<S34>/Constant1'
                                                    *   '<S34>/Constant2'
                                                    *   '<S99>/Constant1'
                                                    *   '<S99>/Constant2'
                                                    *   '<S116>/kd'
                                                    *   '<S116>/Saturation'
                                                    *   '<S117>/Constant'
                                                    *   '<S117>/ki'
                                                    *   '<S117>/Discrete-Time Integrator'
                                                    *   '<S118>/kp'
                                                    *   '<S130>/gain1'
                                                    *   '<S130>/gain2'
                                                    *   '<S130>/gain3'
                                                    *   '<S130>/Discrete-Time Integrator'
                                                    *   '<S131>/gain1'
                                                    *   '<S131>/gain2'
                                                    *   '<S131>/gain3'
                                                    *   '<S135>/Pitch Offset'
                                                    *   '<S135>/Saturation'
                                                    *   '<S136>/Constant1'
                                                    *   '<S136>/Constant2'
                                                    *   '<S23>/gain1'
                                                    *   '<S23>/gain2'
                                                    *   '<S23>/gain3'
                                                    *   '<S23>/Saturation'
                                                    *   '<S24>/gain1'
                                                    *   '<S24>/gain2'
                                                    *   '<S24>/gain3'
                                                    *   '<S24>/Discrete-Time Integrator'
                                                    *   '<S25>/gain1'
                                                    *   '<S25>/gain2'
                                                    *   '<S25>/gain3'
                                                    *   '<S92>/gain1'
                                                    *   '<S92>/gain2'
                                                    *   '<S92>/gain3'
                                                    *   '<S92>/Saturation'
                                                    *   '<S93>/gain1'
                                                    *   '<S93>/gain2'
                                                    *   '<S93>/gain3'
                                                    *   '<S93>/Discrete-Time Integrator'
                                                    *   '<S94>/gain1'
                                                    *   '<S94>/gain2'
                                                    *   '<S94>/gain3'
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
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Propagation' : Unused code path elimination
 * Block '<S120>/Constant1' : Unused code path elimination
 * Block '<S120>/Sum' : Unused code path elimination
 * Block '<S77>/Multiply1' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S67>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S91>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S112>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S125>/Reshape' : Reshape block reduction
 * Block '<S134>/Logical Operator1' : Eliminated due to no operation
 * Block '<S142>/Logical Operator' : Eliminated due to no operation
 * Block '<S159>/Reshape' : Reshape block reduction
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
 * '<S5>'   : 'Controller/Controller/Subsystem'
 * '<S6>'   : 'Controller/Controller/VTOL_Controller'
 * '<S7>'   : 'Controller/Controller/switch-case'
 * '<S8>'   : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S9>'   : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S10>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S11>'  : 'Controller/Controller/MC_Controller/ctrl_mode_mask'
 * '<S12>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S13>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S14>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S15>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S16>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S17>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S18>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S19>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S20>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S21>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S22>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S23>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S24>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S25>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S26>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S27>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S28>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S29>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S30>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S31>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S32>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S33>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S34>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S35>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S36>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S37>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S38>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S39>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S40>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S41>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S42>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S43>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S44>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S45>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S46>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S47>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S48>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S49>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S50>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S51>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S52>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S53>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S54>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S55>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S56>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S57>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S58>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S59>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S60>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S61>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S62>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S63>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S64>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S65>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S66>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S67>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S68>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S69>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S70>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S71>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S72>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S73>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S74>'  : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S75>'  : 'Controller/Controller/Subsystem/Compare To Zero'
 * '<S76>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller'
 * '<S77>'  : 'Controller/Controller/VTOL_Controller/Effective_Factor'
 * '<S78>'  : 'Controller/Controller/VTOL_Controller/FW_Controller'
 * '<S79>'  : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation'
 * '<S80>'  : 'Controller/Controller/VTOL_Controller/ctrl_mode_mask'
 * '<S81>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S82>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S83>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S84>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S85>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S86>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S87>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S88>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S89>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S90>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S91>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S92>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S93>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S94>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S95>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S96>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S97>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S98>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S99>'  : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S100>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S101>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S102>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S103>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S104>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S105>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S106>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S107>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S108>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Stabilize'
 * '<S109>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Stabilize'
 * '<S110>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S111>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S112>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S113>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S114>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S115>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S116>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S117>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S118>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S119>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S120>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/Factor'
 * '<S121>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control'
 * '<S122>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core'
 * '<S123>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Velocity_Control'
 * '<S124>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S125>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S126>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S127>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S128>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S129>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S130>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S131>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S132>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S133>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S134>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S135>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S136>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S137>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S138>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S139>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S140>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S141>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S142>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S143>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S144>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S145>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S146>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S147>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem1'
 * '<S148>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S149>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S150>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S151>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S152>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S153>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S154>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S155>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/speed_ax_out'
 * '<S156>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S157>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation'
 * '<S158>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/MC_Control_Allocation'
 * '<S159>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation/Fixwing'
 * '<S160>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation/Fixwing/Effective_Matrix1'
 * '<S161>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation/Fixwing/Signal_Select1'
 * '<S162>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation/Fixwing/actuator_cmd_routing'
 * '<S163>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation/Fixwing/throttle_mapping1'
 * '<S164>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/FW_Control_Allocation/Fixwing/Signal_Select1/Compare To Constant'
 * '<S165>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/MC_Control_Allocation/Quadcopter_x'
 * '<S166>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S167>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S168>' : 'Controller/Controller/switch-case/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
