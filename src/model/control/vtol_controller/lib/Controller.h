/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  9 11:40:35 2024
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
  real32_T Constant;                   /* '<S132>/Constant' */
  real32_T Constant_i;                 /* '<S57>/Constant' */
  real32_T Constant_m;                 /* '<S177>/Constant' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S84>/Discrete-Time Integrator' */
  real32_T Integrator1_DSTATE[2];      /* '<S106>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[2];/* '<S111>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S113>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S82>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S86>/Discrete-Time Integrator1' */
  real32_T Integrator1_DSTATE_e;       /* '<S129>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S132>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_i;/* '<S134>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[2];       /* '<S106>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S129>/Integrator' */
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
  real32_T DiscreteTimeIntegrator5_DSTAT_a;/* '<S182>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTA_a2;/* '<S181>/Discrete-Time Integrator5' */
  real32_T Integrator1_DSTATE_i;       /* '<S174>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S177>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTA_ld;/* '<S179>/Discrete-Time Integrator1' */
  real32_T _DSTATE;                    /* '<S217>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S218>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_l[3];/* '<S150>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S152>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S154>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTAT_j;/* '<S180>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_l5[3];/* '<S192>/Discrete-Time Integrator' */
  real32_T _DSTATE_d;                  /* '<S220>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTA_nm;/* '<S221>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_f;        /* '<S174>/Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S3>/Discrete-Time Integrator' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S8>/Switch Case1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S84>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S111>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S113>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S86>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S132>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_Prev_ks;/* '<S134>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S47>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S49>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ps;/* '<S25>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_c;/* '<S27>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S57>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S59>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S177>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_h;/* '<S179>/Discrete-Time Integrator1' */
  int8_T _PrevResetState;              /* '<S217>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S218>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S152>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_l;/* '<S154>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_ef;/* '<S192>/Discrete-Time Integrator' */
  int8_T _PrevResetState_e;            /* '<S220>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_d;/* '<S221>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S113>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S82>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_j;/* '<S86>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_d;/* '<S134>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;/* '<S49>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_e;/* '<S23>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_p;/* '<S27>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_b;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_L_eo;/* '<S182>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_o;/* '<S181>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S179>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_f;/* '<S218>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;/* '<S150>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h2;/* '<S154>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S180>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator1_IC_L_h0;/* '<S221>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S136>/Relay' */
} DW_Controller_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Gain1;                /* '<S67>/Gain1' */
  const uint32_T Sum1;                 /* '<S67>/Sum1' */
  const real32_T Constant[3];          /* '<S84>/Constant' */
  const real32_T VectorConcatenate3[3];/* '<S108>/Vector Concatenate3' */
  const real32_T Constant_e;           /* '<S111>/Constant' */
  const real32_T Gain;                 /* '<S96>/Gain' */
  const real32_T Square;               /* '<S109>/Square' */
  const real32_T d;                    /* '<S109>/Multiply' */
  const real32_T Gain4;                /* '<S109>/Gain4' */
  const real32_T Square_h;             /* '<S130>/Square' */
  const real32_T d_i;                  /* '<S130>/Multiply' */
  const real32_T Gain4_p;              /* '<S130>/Gain4' */
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
  const real32_T Saturation5[3];       /* '<S63>/Saturation5' */
  const real32_T Saturation4;          /* '<S63>/Saturation4' */
  const real32_T Saturation;           /* '<S67>/Saturation' */
  const real32_T Square1;              /* '<S136>/Square1' */
  const real32_T VectorConcatenate3_c[3];/* '<S212>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_o[3];/* '<S214>/Vector Concatenate3' */
  const real32_T Zero1;                /* '<S217>/Zero1' */
  const real32_T Gain_np;              /* '<S160>/Gain' */
  const real32_T Constant_j[3];        /* '<S152>/Constant' */
  const real32_T Constant_c[3];        /* '<S192>/Constant' */
  const real32_T Zero;                 /* '<S220>/Zero' */
  const real32_T Square_h2;            /* '<S175>/Square' */
  const real32_T d_m;                  /* '<S175>/Multiply' */
  const real32_T Gain4_o;              /* '<S175>/Gain4' */
  const uint16_T DataTypeConversion;   /* '<S67>/Data Type Conversion' */
} ConstB_Controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S118>/Effective_Matrix'
   *   '<S64>/Effective_Matrix'
   *   '<S234>/Effective_Matrix'
   */
  real32_T pooled19[12];

  /* Pooled Parameter (Expression: [1000 1000 1000 1000 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S65>/Disarm'
   *   '<S235>/Disarm'
   */
  uint16_T pooled34[9];

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S65>/Standby'
   *   '<S235>/Standby'
   */
  uint16_T pooled35[9];

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S120>/Disarm1'
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
                                                   *   '<S9>/mc_hover_throttle'
                                                   *   '<S141>/mc_hover_throttle'
                                                   *   '<S184>/Saturation'
                                                   *   '<S185>/Gain'
                                                   *   '<S185>/Gain1'
                                                   *   '<S185>/balabnce_ratio2'
                                                   *   '<S185>/balance_ratio'
                                                   *   '<S185>/pitch_ff'
                                                   *   '<S185>/thorttle_ff'
                                                   *   '<S185>/ucmd2pitch'
                                                   *   '<S185>/ucmd2thor'
                                                   *   '<S185>/wcmd2pitch'
                                                   *   '<S185>/wcmd2thor'
                                                   *   '<S101>/Saturation'
                                                   *   '<S121>/hover_throttle'
                                                   *   '<S186>/FF'
                                                   *   '<S186>/FF_limit'
                                                   *   '<S186>/PI_limit'
                                                   *   '<S205>/P_control'
                                                   *   '<S206>/P_control'
                                                   *   '<S38>/Saturation'
                                                   *   '<S77>/Saturation'
                                                   *   '<S77>/Saturation1'
                                                   *   '<S110>/kd'
                                                   *   '<S110>/Saturation'
                                                   *   '<S111>/ki'
                                                   *   '<S111>/Discrete-Time Integrator'
                                                   *   '<S112>/kp'
                                                   *   '<S131>/kd'
                                                   *   '<S131>/Saturation'
                                                   *   '<S132>/Constant'
                                                   *   '<S132>/ki'
                                                   *   '<S132>/Discrete-Time Integrator'
                                                   *   '<S133>/kp'
                                                   *   '<S146>/Saturation'
                                                   *   '<S146>/Saturation1'
                                                   *   '<S190>/trim_speed'
                                                   *   '<S191>/trim_speed'
                                                   *   '<S216>/Gain'
                                                   *   '<S217>/ '
                                                   *   '<S217>/Gain3'
                                                   *   '<S219>/Gain'
                                                   *   '<S220>/Gain'
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
                                                   *   '<S66>/Constant1'
                                                   *   '<S66>/Constant12'
                                                   *   '<S66>/Constant2'
                                                   *   '<S66>/Constant7'
                                                   *   '<S94>/Constant1'
                                                   *   '<S94>/Constant2'
                                                   *   '<S158>/Constant1'
                                                   *   '<S158>/Constant2'
                                                   *   '<S176>/kd'
                                                   *   '<S176>/Saturation'
                                                   *   '<S177>/Constant'
                                                   *   '<S177>/ki'
                                                   *   '<S177>/Discrete-Time Integrator'
                                                   *   '<S178>/kp'
                                                   *   '<S192>/gain1'
                                                   *   '<S192>/gain2'
                                                   *   '<S192>/gain3'
                                                   *   '<S192>/Discrete-Time Integrator'
                                                   *   '<S193>/gain1'
                                                   *   '<S193>/gain2'
                                                   *   '<S193>/gain3'
                                                   *   '<S197>/Pitch Offset'
                                                   *   '<S197>/Saturation'
                                                   *   '<S198>/Constant1'
                                                   *   '<S198>/Constant2'
                                                   *   '<S236>/Constant1'
                                                   *   '<S236>/Constant12'
                                                   *   '<S236>/Constant2'
                                                   *   '<S236>/Constant7'
                                                   *   '<S33>/Constant1'
                                                   *   '<S33>/Constant2'
                                                   *   '<S83>/gain1'
                                                   *   '<S83>/gain2'
                                                   *   '<S83>/gain3'
                                                   *   '<S83>/Saturation'
                                                   *   '<S84>/gain1'
                                                   *   '<S84>/gain2'
                                                   *   '<S84>/gain3'
                                                   *   '<S84>/Discrete-Time Integrator'
                                                   *   '<S85>/gain1'
                                                   *   '<S85>/gain2'
                                                   *   '<S85>/gain3'
                                                   *   '<S151>/gain1'
                                                   *   '<S151>/gain2'
                                                   *   '<S151>/gain3'
                                                   *   '<S151>/Saturation'
                                                   *   '<S152>/gain1'
                                                   *   '<S152>/gain2'
                                                   *   '<S152>/gain3'
                                                   *   '<S152>/Discrete-Time Integrator'
                                                   *   '<S153>/gain1'
                                                   *   '<S153>/gain2'
                                                   *   '<S153>/gain3'
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
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Propagation' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S52>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S82>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S127>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S150>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S172>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S180>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S181>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S182>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S187>/Reshape' : Reshape block reduction
 * Block '<S196>/Logical Operator1' : Eliminated due to no operation
 * Block '<S204>/Logical Operator' : Eliminated due to no operation
 * Block '<S232>/Reshape' : Reshape block reduction
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
 * '<S63>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S64>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S65>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S66>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S67>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S68>'  : 'Controller/Controller/BackTrans_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 * '<S69>'  : 'Controller/Controller/MC_Controller/Horizontal_Control'
 * '<S70>'  : 'Controller/Controller/MC_Controller/MC_Control_Allocation'
 * '<S71>'  : 'Controller/Controller/MC_Controller/Vertical_Control'
 * '<S72>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller'
 * '<S73>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller'
 * '<S74>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop'
 * '<S75>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop'
 * '<S76>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S77>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S78>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select'
 * '<S79>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S80>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S81>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S82>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S83>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S84>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S85>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S86>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S87>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S88>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant'
 * '<S89>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Compare To Constant1'
 * '<S90>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Inner_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S91>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S92>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select'
 * '<S93>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S94>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S95>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S96>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S97>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S98>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant'
 * '<S99>'  : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Compare To Constant1'
 * '<S100>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Attitude_Controller/Outter_Loop/Signal_Select/Offboard_Signal_Select'
 * '<S101>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Accel_to_Attitude_CMD'
 * '<S102>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error'
 * '<S103>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller'
 * '<S104>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select'
 * '<S105>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select'
 * '<S106>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD'
 * '<S107>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM'
 * '<S108>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/Bus_Select/Psi To DCM/Rotation Matrix Z'
 * '<S109>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Error/TD/fhan '
 * '<S110>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control'
 * '<S111>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/I_Control'
 * '<S112>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/P_Control'
 * '<S113>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/PID_Controller/D_Control/DT Filter'
 * '<S114>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard'
 * '<S115>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select'
 * '<S116>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero'
 * '<S117>' : 'Controller/Controller/MC_Controller/Horizontal_Control/Velocity_Controller/Signal_Select/Offboard_Signal_Select/Compare To Zero2'
 * '<S118>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x'
 * '<S119>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select'
 * '<S120>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/actuator_cmd_routing'
 * '<S121>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/throttle_mapping'
 * '<S122>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant'
 * '<S123>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Compare To Constant1'
 * '<S124>' : 'Controller/Controller/MC_Controller/MC_Control_Allocation/Quadcopter_x/Signal_Select/Offboard_Signal_Select'
 * '<S125>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S126>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S127>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S128>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S129>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S130>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S131>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S132>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S133>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S134>' : 'Controller/Controller/MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S135>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller'
 * '<S136>' : 'Controller/Controller/VTOL_Controller/Effective_Factor'
 * '<S137>' : 'Controller/Controller/VTOL_Controller/FW_Controller'
 * '<S138>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation'
 * '<S139>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller'
 * '<S140>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander'
 * '<S141>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control'
 * '<S142>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop'
 * '<S143>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop'
 * '<S144>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Compare To Zero'
 * '<S145>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller'
 * '<S146>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert'
 * '<S147>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error'
 * '<S148>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller'
 * '<S149>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/Bus_Select'
 * '<S150>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/Error/First Order LPF'
 * '<S151>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control'
 * '<S152>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/I_Control'
 * '<S153>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/P_Control'
 * '<S154>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Rate_Controller/PID_Controller/D_Control/DT Filter'
 * '<S155>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Inner_Loop/Signal_Convert/Euler To Angle Rate'
 * '<S156>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller'
 * '<S157>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error'
 * '<S158>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller'
 * '<S159>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Error/Bus_Select'
 * '<S160>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control'
 * '<S161>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Attitude_Controller/Outter_Loop/Attitude_Controller/Sqrt_Root_Controller/Sqrt_Root_Control/Saturation Dynamic1'
 * '<S162>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander'
 * '<S163>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander'
 * '<S164>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander'
 * '<S165>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander'
 * '<S166>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Phi_Commander/Altitude'
 * '<S167>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/Theta_Commander/Stabilize'
 * '<S168>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Aux_Commander/Commander/W_Commander/Stabilize'
 * '<S169>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller'
 * '<S170>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Boosted_Throttle'
 * '<S171>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Compare To Zero'
 * '<S172>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error'
 * '<S173>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller'
 * '<S174>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD'
 * '<S175>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/Error/TD/fhan '
 * '<S176>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control'
 * '<S177>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/I_Control'
 * '<S178>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/P_Control'
 * '<S179>' : 'Controller/Controller/VTOL_Controller/Aux_MC_Controller/Vertical_Control/Veloxity_Z_Controller/PID_Controller/D_Control/DT Filter'
 * '<S180>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF'
 * '<S181>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF1'
 * '<S182>' : 'Controller/Controller/VTOL_Controller/Effective_Factor/First Order LPF2'
 * '<S183>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control'
 * '<S184>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Lateral_Control'
 * '<S185>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core'
 * '<S186>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S187>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S188>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S189>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S190>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S191>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S192>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S193>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S194>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S195>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S196>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S197>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S198>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S199>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S200>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S201>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S202>' : 'Controller/Controller/VTOL_Controller/FW_Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S203>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control'
 * '<S204>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd'
 * '<S205>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out'
 * '<S206>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out'
 * '<S207>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control'
 * '<S208>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle'
 * '<S209>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Subsystem2'
 * '<S210>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle'
 * '<S211>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM'
 * '<S212>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S213>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM'
 * '<S214>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/path_angle_control/Target_Flight_Path_Angle/Psi To DCM/Rotation Matrix Z'
 * '<S215>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S216>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S217>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S218>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S219>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S220>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S221>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S222>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed'
 * '<S223>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Compare To Constant'
 * '<S224>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM'
 * '<S225>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize'
 * '<S226>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_1'
 * '<S227>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_2'
 * '<S228>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/column_3'
 * '<S229>' : 'Controller/Controller/VTOL_Controller/FW_Controller/TECS_Core/velocity_control/Flight_Speed/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S230>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/Bus_Construct'
 * '<S231>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation'
 * '<S232>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1'
 * '<S233>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation'
 * '<S234>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation'
 * '<S235>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/actuator_cmd_routing'
 * '<S236>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/FW_Effective_Matrix'
 * '<S237>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select'
 * '<S238>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/fw_throttle_mapping'
 * '<S239>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/FW_Control_Allocation/Signal_Select/Compare To Constant'
 * '<S240>' : 'Controller/Controller/VTOL_Controller/VTOL_Control_Allocation/VTOL_Control_Allocation/VTOL1/MC_Control_Allocation/throttle_mapping'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
