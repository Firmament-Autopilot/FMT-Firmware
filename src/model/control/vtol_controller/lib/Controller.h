/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.207
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Aug 19 14:49:22 2024
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
  real32_T Constant;                   /* '<S139>/Constant' */
  real32_T Constant_i;                 /* '<S57>/Constant' */
  real32_T Constant_m;                 /* '<S184>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S91>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S113>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S118>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S120>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S89>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S93>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_e;       /* '<S136>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S139>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S141>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S113>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S136>/Integrator' */
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
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S189>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S188>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_i;       /* '<S181>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S184>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTA_ld;/* '<S186>/Discrete-Time Integrator1' */
  real32_T _DSTATE;                    /* '<S224>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S225>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S157>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S159>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S161>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S187>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S199>/Discrete-Time Integrator' */
  real32_T _DSTATE_d;                  /* '<S227>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S228>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_f;        /* '<S181>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S8>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S91>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S118>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S120>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S93>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S139>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S141>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S47>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S49>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ps;/* '<S25>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_c;/* '<S27>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S57>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S59>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S184>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S186>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S224>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S225>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S159>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S161>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S199>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S227>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S228>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S120>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S89>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S93>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S141>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S49>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S23>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_p;/* '<S27>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_b;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S189>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S188>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S186>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S225>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S157>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h2;/* '<S161>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S187>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S228>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S143>/Relay' */
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
  const real32_T Constant[3];          /* '<S91>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S115>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S118>/Constant' */
  const real32_T Gain;                 /* '<S103>/Gain' */
  const real32_T Square;               /* '<S116>/Square' */
  const real32_T d;                    /* '<S116>/Multiply' */
  const real32_T Gain4;                /* '<S116>/Gain4' */
  const real32_T Square_h;             /* '<S137>/Square' */
  const real32_T d_i;                  /* '<S137>/Multiply' */
  const real32_T Gain4_p;              /* '<S137>/Gain4' */
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
  const real32_T Square1;              /* '<S143>/Square1' */
  const real32_T VectorConcatenate3_c[3];/* '<S219>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S221>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S224>/Zero1' */
  const real32_T Gain_np;              /* '<S167>/Gain' */
  const real32_T Constant_j[3];        /* '<S159>/Constant' */
  const real32_T Constant_c[3];        /* '<S199>/Constant' */
  const real32_T Zero;                 /* '<S227>/Zero' */
  const real32_T Square_h2;            /* '<S182>/Square' */
  const real32_T d_m;                  /* '<S182>/Multiply' */
  const real32_T Gain4_o;              /* '<S182>/Gain4' */

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
   *   '<S125>/Effective_Matrix'
   *   '<S65>/Effective_Matrix'
   *   '<S71>/Effective_Matrix'
   *   '<S242>/Effective_Matrix'
   *   '<S250>/Effective_Matrix'
   */
  real32_T pooled16[12];

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1000 1000 1000 1000 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S66>/Disarm'
   *   '<S72>/Disarm'
   *   '<S243>/Disarm'
   *   '<S251>/Disarm'
   */
  uint16_T pooled34[9];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S66>/Standby'
   *   '<S72>/Standby'
   *   '<S243>/Standby'
   *   '<S251>/Standby'
   */
  uint16_T pooled35[9];

#define CONSTP_CONTROLLER_T_VARIANT_EXISTS
#endif

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S127>/Disarm1'
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
extern struct_DYyzgxJdfX95CMtHDL7qw CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                   * Referenced by:
                                                   *   '<S9>/mc_hover_throttle'
                                                   *   '<S148>/mc_hover_throttle'
                                                   *   '<S191>/Saturation'
                                                   *   '<S192>/Gain'
                                                   *   '<S192>/Gain1'
                                                   *   '<S192>/balabnce_ratio2'
                                                   *   '<S192>/balance_ratio'
                                                   *   '<S192>/pitch_ff'
                                                   *   '<S192>/thorttle_ff'
                                                   *   '<S192>/ucmd2pitch'
                                                   *   '<S192>/ucmd2thor'
                                                   *   '<S192>/wcmd2pitch'
                                                   *   '<S192>/wcmd2thor'
                                                   *   '<S108>/Saturation'
                                                   *   '<S128>/hover_throttle'
                                                   *   '<S193>/FF'
                                                   *   '<S193>/FF_limit'
                                                   *   '<S193>/PI_limit'
                                                   *   '<S212>/P_control'
                                                   *   '<S213>/P_control'
                                                   *   '<S38>/Saturation'
                                                   *   '<S84>/Saturation'
                                                   *   '<S84>/Saturation1'
                                                   *   '<S117>/kd'
                                                   *   '<S117>/Saturation'
                                                   *   '<S118>/ki'
                                                   *   '<S118>/Discrete-Time Integrator'
                                                   *   '<S119>/kp'
                                                   *   '<S138>/kd'
                                                   *   '<S138>/Saturation'
                                                   *   '<S139>/Constant'
                                                   *   '<S139>/ki'
                                                   *   '<S139>/Discrete-Time Integrator'
                                                   *   '<S140>/kp'
                                                   *   '<S153>/Saturation'
                                                   *   '<S153>/Saturation1'
                                                   *   '<S197>/trim_speed'
                                                   *   '<S198>/trim_speed'
                                                   *   '<S223>/Gain'
                                                   *   '<S224>/ '
                                                   *   '<S224>/Gain3'
                                                   *   '<S226>/Gain'
                                                   *   '<S227>/Gain'
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
                                                   *   '<S101>/Constant1'
                                                   *   '<S101>/Constant2'
                                                   *   '<S165>/Constant1'
                                                   *   '<S165>/Constant2'
                                                   *   '<S183>/kd'
                                                   *   '<S183>/Saturation'
                                                   *   '<S184>/Constant'
                                                   *   '<S184>/ki'
                                                   *   '<S184>/Discrete-Time Integrator'
                                                   *   '<S185>/kp'
                                                   *   '<S199>/gain1'
                                                   *   '<S199>/gain2'
                                                   *   '<S199>/gain3'
                                                   *   '<S199>/Discrete-Time Integrator'
                                                   *   '<S200>/gain1'
                                                   *   '<S200>/gain2'
                                                   *   '<S200>/gain3'
                                                   *   '<S204>/Pitch Offset'
                                                   *   '<S204>/Saturation'
                                                   *   '<S205>/Constant1'
                                                   *   '<S205>/Constant2'
                                                   *   '<S244>/Constant1'
                                                   *   '<S244>/Constant12'
                                                   *   '<S244>/Constant2'
                                                   *   '<S244>/Constant7'
                                                   *   '<S252>/Constant1'
                                                   *   '<S252>/Constant11'
                                                   *   '<S252>/Constant12'
                                                   *   '<S252>/Constant2'
                                                   *   '<S252>/Constant7'
                                                   *   '<S252>/Constant8'
                                                   *   '<S33>/Constant1'
                                                   *   '<S33>/Constant2'
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
                                                   *   '<S158>/gain1'
                                                   *   '<S158>/gain2'
                                                   *   '<S158>/gain3'
                                                   *   '<S158>/Saturation'
                                                   *   '<S159>/gain1'
                                                   *   '<S159>/gain2'
                                                   *   '<S159>/gain3'
                                                   *   '<S159>/Discrete-Time Integrator'
                                                   *   '<S160>/gain1'
                                                   *   '<S160>/gain2'
                                                   *   '<S160>/gain3'
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
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Propagation' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S89>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S134>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S157>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S179>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S187>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S188>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S189>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S194>/Reshape' : Reshape block reduction
 * Block '<S203>/Logical Operator1' : Eliminated due to no operation
 * Block '<S211>/Logical Operator' : Eliminated due to no operation
 * Block '<S239>/Reshape' : Reshape block reduction
 * Block '<S240>/Reshape' : Reshape block reduction
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
 * '<S76>'  : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S77>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S78>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S79>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S80>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S81>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S82>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S83>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S84>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S85>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S86>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S87>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S88>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S89>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S90>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S91>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S92>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S93>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S94>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S95>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S118>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S119>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S120>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S121>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S122>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S123>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S124>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S125>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S126>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S127>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S128>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S129>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S130>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S131>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S132>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S133>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S134>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S135>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S136>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S137>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S138>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S139>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S140>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S141>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S142>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller'
 * '<S143>' : 'Controller/Controller/VTOL_Controller/Effective_Factor'
 * '<S144>' : 'Controller/Controller/VTOL_Controller/FW_Controller'
 * '<S145>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation'
 * '<S146>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S147>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S148>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S149>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S150>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S151>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S152>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S153>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S154>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S155>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S156>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S157>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S158>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S159>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S160>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S161>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S162>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S163>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S164>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S165>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S166>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S167>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S168>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S169>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S170>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S171>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S172>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S173>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S174>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Stabilize'
 * '<S175>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Stabilize'
 * '<S176>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S177>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S178>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S179>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S180>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S181>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S182>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S183>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S184>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S185>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S186>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S187>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF'
 * '<S188>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF1'
 * '<S189>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF2'
 * '<S190>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control'
 * '<S191>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Lateral_Control'
 * '<S192>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core'
 * '<S193>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S194>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S195>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S196>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S197>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S198>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S199>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S200>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S201>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S202>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S203>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S204>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S205>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S206>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S207>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S208>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S209>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S210>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S211>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S212>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S213>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S214>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S215>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S216>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem2'
 * '<S217>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S218>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM'
 * '<S219>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S220>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM'
 * '<S221>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S222>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S223>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S224>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S225>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S226>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S227>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S228>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S229>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S230>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Compare To Constant'
 * '<S231>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM'
 * '<S232>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S233>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_1'
 * '<S234>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_2'
 * '<S235>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_3'
 * '<S236>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S237>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S238>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S239>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S240>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2'
 * '<S241>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S242>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S243>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S244>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S245>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S246>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S247>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S248>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S249>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation'
 * '<S250>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation'
 * '<S251>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/actuator_cmd_routing'
 * '<S252>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S253>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select'
 * '<S254>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/fw_throttle_mapping'
 * '<S255>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S256>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL2/MC_Control_Allocation/throttle_mapping'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
