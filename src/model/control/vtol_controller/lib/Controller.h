/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.221
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 20 13:42:12 2024
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
  real32_T Constant;                   /* '<S141>/Constant' */
  real32_T Constant_i;                 /* '<S57>/Constant' */
  real32_T Constant_m;                 /* '<S186>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S93>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S115>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S120>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S122>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S91>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S95>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_e;       /* '<S138>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S141>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S143>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S115>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S138>/Integrator' */
  real32_T Integrator1_DSTATE_h[2];    /* '<S42>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_kh[2];/* '<S47>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_g[2];/* '<S49>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S23>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S25>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l[3];/* '<S27>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_o;       /* '<S54>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S57>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_d;/* '<S59>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_jg[2];    /* '<S42>/Integrator' */
  real32_T Integrator_DSTATE_e;        /* '<S54>/Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S191>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S190>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_i;       /* '<S183>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S186>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTA_ld;/* '<S188>/Discrete-Time Integrator1' */
  real32_T _DSTATE;                    /* '<S226>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S227>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S159>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S161>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S163>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S189>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S201>/Discrete-Time Integrator' */
  real32_T _DSTATE_d;                  /* '<S229>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S230>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_f;        /* '<S183>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S8>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S93>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S120>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S122>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S95>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S141>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S143>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S47>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S49>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ps;/* '<S25>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_c;/* '<S27>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S57>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S59>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S186>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S188>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S226>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S227>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S161>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S163>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S201>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S229>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S230>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S122>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S91>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S95>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S143>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S49>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S23>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_p;/* '<S27>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_b;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S191>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S190>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S188>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S227>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S159>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h2;/* '<S163>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S189>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S230>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S145>/Relay' */
} DW_Controller_T;

/* Invariant block signals for system '<S61>/VTOL1' */
#if AIRFRAME == 1

typedef struct {
  const uint32_T Gain1;                /* '<S68>/Gain1' */
  const uint32_T Sum1;                 /* '<S68>/Sum1' */
  const real32_T Saturation5[3];       /* '<S64>/Saturation5' */
  const real32_T Saturation4;          /* '<S64>/Saturation4' */
  const real32_T Saturation;           /* '<S68>/Saturation' */
  const uint16_T DataTypeConversion;   /* '<S68>/Data Type Conversion' */
} ConstB_VTOL1_Controller_f_T;

#endif

/* Invariant block signals for system '<S61>/VTOL2' */
#if AIRFRAME == 2

typedef struct {
  const uint32_T Gain1;                /* '<S74>/Gain1' */
  const uint32_T Sum1;                 /* '<S74>/Sum1' */
  const real32_T Saturation5[3];       /* '<S70>/Saturation5' */
  const real32_T Saturation4;          /* '<S70>/Saturation4' */
  const real32_T Saturation;           /* '<S74>/Saturation' */
  const uint16_T DataTypeConversion;   /* '<S74>/Data Type Conversion' */
} ConstB_VTOL2_Controller_l_T;

#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant[3];          /* '<S93>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S117>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S120>/Constant' */
  const real32_T Gain;                 /* '<S105>/Gain' */
  const real32_T Square;               /* '<S118>/Square' */
  const real32_T d;                    /* '<S118>/Multiply' */
  const real32_T Gain4;                /* '<S118>/Gain4' */
  const real32_T Square_h;             /* '<S139>/Square' */
  const real32_T d_i;                  /* '<S139>/Multiply' */
  const real32_T Gain4_p;              /* '<S139>/Gain4' */
  const real32_T VectorConcatenate3_a[3];/* '<S44>/Vector Concatenate3' */
  const real32_T Constant_e4;          /* '<S47>/Constant' */
  const real32_T Gain_n;               /* '<S35>/Gain' */
  const real32_T Constant_a[3];        /* '<S25>/Constant' */
  const real32_T Square_b;             /* '<S45>/Square' */
  const real32_T d_ih;                 /* '<S45>/Multiply' */
  const real32_T Gain4_f;              /* '<S45>/Gain4' */
  const real32_T Square_a;             /* '<S55>/Square' */
  const real32_T d_j;                  /* '<S55>/Multiply' */
  const real32_T Gain4_n;              /* '<S55>/Gain4' */
  const real32_T Square1;              /* '<S145>/Square1' */
  const real32_T VectorConcatenate3_c[3];/* '<S221>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S223>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S226>/Zero1' */
  const real32_T Gain_np;              /* '<S169>/Gain' */
  const real32_T Constant_j[3];        /* '<S161>/Constant' */
  const real32_T Constant_c[3];        /* '<S201>/Constant' */
  const real32_T Zero;                 /* '<S229>/Zero' */
  const real32_T Square_h2;            /* '<S184>/Square' */
  const real32_T d_m;                  /* '<S184>/Multiply' */
  const real32_T Gain4_o;              /* '<S184>/Gain4' */

#if AIRFRAME == 2

  ConstB_VTOL2_Controller_l_T VTOL2_p; /* '<S61>/VTOL2' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  ConstB_VTOL1_Controller_f_T VTOL1_n; /* '<S61>/VTOL1' */

#define CONSTB_CONTROLLER_T_VARIANT_EXISTS
#endif

} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S127>/Effective_Matrix'
   *   '<S65>/Effective_Matrix'
   *   '<S71>/Effective_Matrix'
   *   '<S244>/Effective_Matrix'
   *   '<S252>/Effective_Matrix'
   */
  real32_T pooled16[12];

#if AIRFRAME == 1

  /* Pooled Parameter (Expression: [1000 1000 1000 1000 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S66>/Disarm'
   *   '<S245>/Disarm'
   */
  uint16_T pooled37[9];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if AIRFRAME == 1

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S66>/Standby'
   *   '<S245>/Standby'
   */
  uint16_T pooled38[9];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S129>/Disarm1'
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
extern struct_66Lz2XM6ObrCrxI96MstFF CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S9>/mc_hover_throttle'
                                                    *   '<S150>/mc_hover_throttle'
                                                    *   '<S193>/Saturation'
                                                    *   '<S194>/Gain'
                                                    *   '<S194>/Gain1'
                                                    *   '<S194>/balabnce_ratio2'
                                                    *   '<S194>/balance_ratio'
                                                    *   '<S194>/pitch_ff'
                                                    *   '<S194>/thorttle_ff'
                                                    *   '<S194>/ucmd2pitch'
                                                    *   '<S194>/ucmd2thor'
                                                    *   '<S194>/wcmd2pitch'
                                                    *   '<S194>/wcmd2thor'
                                                    *   '<S110>/Saturation'
                                                    *   '<S130>/hover_throttle'
                                                    *   '<S195>/FF'
                                                    *   '<S195>/FF_limit'
                                                    *   '<S195>/PI_limit'
                                                    *   '<S214>/P_control'
                                                    *   '<S215>/P_control'
                                                    *   '<S38>/Saturation'
                                                    *   '<S70>/Bias1'
                                                    *   '<S70>/Bias2'
                                                    *   '<S70>/Bias3'
                                                    *   '<S70>/Bias4'
                                                    *   '<S86>/Saturation'
                                                    *   '<S86>/Saturation1'
                                                    *   '<S119>/kd'
                                                    *   '<S119>/Saturation'
                                                    *   '<S120>/ki'
                                                    *   '<S120>/Discrete-Time Integrator'
                                                    *   '<S121>/kp'
                                                    *   '<S140>/kd'
                                                    *   '<S140>/Saturation'
                                                    *   '<S141>/Constant'
                                                    *   '<S141>/ki'
                                                    *   '<S141>/Discrete-Time Integrator'
                                                    *   '<S142>/kp'
                                                    *   '<S155>/Saturation'
                                                    *   '<S155>/Saturation1'
                                                    *   '<S199>/trim_speed'
                                                    *   '<S200>/trim_speed'
                                                    *   '<S225>/Gain'
                                                    *   '<S226>/ '
                                                    *   '<S226>/Gain3'
                                                    *   '<S228>/Gain'
                                                    *   '<S229>/Gain'
                                                    *   '<S251>/Bias1'
                                                    *   '<S251>/Bias2'
                                                    *   '<S251>/Bias3'
                                                    *   '<S251>/Bias4'
                                                    *   '<S18>/Saturation'
                                                    *   '<S18>/Saturation1'
                                                    *   '<S46>/kd'
                                                    *   '<S46>/Saturation'
                                                    *   '<S47>/ki'
                                                    *   '<S47>/Discrete-Time Integrator'
                                                    *   '<S48>/kp'
                                                    *   '<S56>/kd'
                                                    *   '<S56>/Saturation'
                                                    *   '<S57>/Constant'
                                                    *   '<S57>/ki'
                                                    *   '<S57>/Discrete-Time Integrator'
                                                    *   '<S58>/kp'
                                                    *   '<S67>/Constant1'
                                                    *   '<S67>/Constant12'
                                                    *   '<S67>/Constant2'
                                                    *   '<S67>/Constant7'
                                                    *   '<S73>/Constant1'
                                                    *   '<S73>/Constant11'
                                                    *   '<S73>/Constant12'
                                                    *   '<S73>/Constant2'
                                                    *   '<S73>/Constant7'
                                                    *   '<S73>/Constant8'
                                                    *   '<S76>/Bias'
                                                    *   '<S76>/Bias1'
                                                    *   '<S76>/Bias2'
                                                    *   '<S76>/Bias3'
                                                    *   '<S77>/Bias'
                                                    *   '<S77>/Bias1'
                                                    *   '<S77>/Bias2'
                                                    *   '<S77>/Bias3'
                                                    *   '<S103>/Constant1'
                                                    *   '<S103>/Constant2'
                                                    *   '<S167>/Constant1'
                                                    *   '<S167>/Constant2'
                                                    *   '<S185>/kd'
                                                    *   '<S185>/Saturation'
                                                    *   '<S186>/Constant'
                                                    *   '<S186>/ki'
                                                    *   '<S186>/Discrete-Time Integrator'
                                                    *   '<S187>/kp'
                                                    *   '<S201>/gain1'
                                                    *   '<S201>/gain2'
                                                    *   '<S201>/gain3'
                                                    *   '<S201>/Discrete-Time Integrator'
                                                    *   '<S202>/gain1'
                                                    *   '<S202>/gain2'
                                                    *   '<S202>/gain3'
                                                    *   '<S206>/Pitch Offset'
                                                    *   '<S206>/Saturation'
                                                    *   '<S207>/Constant1'
                                                    *   '<S207>/Constant2'
                                                    *   '<S246>/Constant1'
                                                    *   '<S246>/Constant12'
                                                    *   '<S246>/Constant2'
                                                    *   '<S246>/Constant7'
                                                    *   '<S254>/Constant1'
                                                    *   '<S254>/Constant11'
                                                    *   '<S254>/Constant12'
                                                    *   '<S254>/Constant2'
                                                    *   '<S254>/Constant7'
                                                    *   '<S254>/Constant8'
                                                    *   '<S259>/Bias'
                                                    *   '<S259>/Bias1'
                                                    *   '<S259>/Bias2'
                                                    *   '<S259>/Bias3'
                                                    *   '<S260>/Bias'
                                                    *   '<S260>/Bias1'
                                                    *   '<S260>/Bias2'
                                                    *   '<S260>/Bias3'
                                                    *   '<S33>/Constant1'
                                                    *   '<S33>/Constant2'
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
                                                    *   '<S160>/gain1'
                                                    *   '<S160>/gain2'
                                                    *   '<S160>/gain3'
                                                    *   '<S160>/Saturation'
                                                    *   '<S161>/gain1'
                                                    *   '<S161>/gain2'
                                                    *   '<S161>/gain3'
                                                    *   '<S161>/Discrete-Time Integrator'
                                                    *   '<S162>/gain1'
                                                    *   '<S162>/gain2'
                                                    *   '<S162>/gain3'
                                                    *   '<S24>/gain1'
                                                    *   '<S24>/gain2'
                                                    *   '<S24>/gain3'
                                                    *   '<S24>/Saturation'
                                                    *   '<S25>/gain1'
                                                    *   '<S25>/gain2'
                                                    *   '<S25>/gain3'
                                                    *   '<S25>/Discrete-Time Integrator'
                                                    *   '<S26>/gain1'
                                                    *   '<S26>/gain2'
                                                    *   '<S26>/gain3'
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
 * Block '<S9>/Constant' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Propagation' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Propagation' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S91>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S136>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S159>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S181>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S189>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S190>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S191>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S196>/Reshape' : Reshape block reduction
 * Block '<S205>/Logical Operator1' : Eliminated due to no operation
 * Block '<S213>/Logical Operator' : Eliminated due to no operation
 * Block '<S241>/Reshape' : Reshape block reduction
 * Block '<S242>/Reshape' : Reshape block reduction
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
 * '<S4>'   : 'Controller/Controller/BackTrans_Controller'
 * '<S5>'   : 'Controller/Controller/MC_Controller'
 * '<S6>'   : 'Controller/Controller/VTOL_Controller'
 * '<S7>'   : 'Controller/Controller/ctrl_mode_mask'
 * '<S8>'   : 'Controller/Controller/switch-case'
 * '<S9>'   : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller'
 * '<S10>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation'
 * '<S11>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control'
 * '<S12>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S13>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S14>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S15>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S16>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S17>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S18>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S19>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S20>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S21>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S22>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S23>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S24>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S25>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S26>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S27>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S28>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S29>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S30>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S31>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S32>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S33>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S34>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S35>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S36>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S37>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S38>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S39>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S40>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S41>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S42>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S43>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S44>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S45>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S46>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S47>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S48>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S49>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S50>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S51>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S52>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S53>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S54>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S55>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S56>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S57>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S58>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S59>'  : 'Controller/Controller/BackTrans_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S60>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S61>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S62>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S63>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S64>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S65>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S66>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S67>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S68>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S69>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S70>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S71>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S72>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S73>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S74>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S75>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S76>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S77>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 * '<S78>'  : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S79>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S80>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S81>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S82>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S83>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S84>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S85>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S86>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S87>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S88>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S89>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S90>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S91>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S92>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S93>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S94>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S95>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S125>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S126>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S127>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S128>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S129>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S130>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S131>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S132>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S133>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S134>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S135>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S136>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S137>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S138>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S139>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S140>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S141>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S142>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S143>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S144>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller'
 * '<S145>' : 'Controller/Controller/VTOL_Controller/Effective_Factor'
 * '<S146>' : 'Controller/Controller/VTOL_Controller/FW_Controller'
 * '<S147>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation'
 * '<S148>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S149>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S150>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S151>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S152>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S153>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S154>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S155>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S156>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S157>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S158>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S159>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S160>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S161>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S162>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S163>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S164>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S165>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S166>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S167>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S168>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S169>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S170>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S171>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S172>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S173>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S174>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S175>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S176>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Stabilize'
 * '<S177>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Stabilize'
 * '<S178>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S179>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S180>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S181>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S182>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S183>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S184>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S185>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S186>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S187>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S188>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S189>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF'
 * '<S190>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF1'
 * '<S191>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF2'
 * '<S192>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control'
 * '<S193>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Lateral_Control'
 * '<S194>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core'
 * '<S195>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S196>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S197>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S198>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S199>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S200>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S201>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S202>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S203>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S204>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S205>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S206>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S207>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S208>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S209>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S210>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S211>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S212>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S213>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S214>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S215>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S216>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S217>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S218>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem2'
 * '<S219>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S220>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM'
 * '<S221>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S222>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM'
 * '<S223>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S224>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S225>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S226>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S227>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S228>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S229>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S230>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S231>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S232>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Compare To Constant'
 * '<S233>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM'
 * '<S234>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S235>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_1'
 * '<S236>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_2'
 * '<S237>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_3'
 * '<S238>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S239>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S240>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S241>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S242>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S243>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S244>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S245>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S246>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S247>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S248>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S249>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S250>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S251>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S252>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S253>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S254>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S255>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S256>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S257>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S258>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 * '<S259>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Disarm'
 * '<S260>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing/Standby'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
