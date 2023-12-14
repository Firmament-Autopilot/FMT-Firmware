/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.82
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Dec 15 05:17:08 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Plant_h_
#define RTW_HEADER_Plant_h_
#include <math.h>
#include <string.h>
#ifndef Plant_COMMON_INCLUDES_
# define Plant_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Plant_COMMON_INCLUDES_ */

#include "Plant_types.h"
#include "arm_math.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_look2d_normal.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  GPS_uBlox_Bus RateTransition;        /* '<S126>/Rate Transition' */
  MAG_Bus RateTransition_l;            /* '<S164>/Rate Transition' */
  Barometer_Bus RateTransition_p;      /* '<S120>/Rate Transition' */
  AirSpeed_Bus RateTransition_e;       /* '<S118>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S131>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S136>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[250];           /* '<S132>/Delay1' */
  real_T Delay_DSTATE_b[250];          /* '<S132>/Delay' */
  real_T Delay1_DSTATE_c[3];           /* '<S44>/Delay1' */
  real_T Delay_DSTATE_f[3];            /* '<S44>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S161>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];/* '<S150>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S156>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[4];/* '<S145>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_j[150];       /* '<S131>/Delay1' */
  real32_T DiscreteFIRFilter_states_i[3];/* '<S137>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S90>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S86>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b[3];/* '<S87>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S87>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[2];/* '<S35>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_h;             /* '<S42>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S111>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S174>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S174>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_h[3];/* '<S152>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f[6];/* '<S152>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_e[3];/* '<S163>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_p[6];/* '<S163>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_a[3];/* '<S134>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f2[6];/* '<S134>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S134>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S134>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_fn[2];/* '<S125>/Random Source' */
  boolean_T DelayInput1_DSTATE;        /* '<S55>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S90>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S86>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S87>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S87>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S161>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S150>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S138>/Sum' */
  const real_T ff;                     /* '<S138>/Multiply3' */
  const real_T Sum4;                   /* '<S138>/Sum4' */
  const real_T Subtract1;              /* '<S50>/Subtract1' */
  const real_T Product1;               /* '<S50>/Product1' */
  const real32_T Add[9];               /* '<S173>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S172>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S171>/Vector Concatenate3' */
  const real32_T Add_g[9];             /* '<S151>/Add' */
  const real32_T Add_k[9];             /* '<S162>/Add' */
  const real32_T quat0[4];             /* '<S86>/quat0' */
  const real32_T VectorConcatenate3_h[3];/* '<S63>/Vector Concatenate3' */
  const real32_T Add_o;                /* '<S67>/Add' */
  const real32_T Sum_k[3];             /* '<S29>/Sum' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S23>/CD'
   *   '<S23>/CY'
   *   '<S23>/Cl'
   *   '<S23>/Cn'
   *   '<S24>/CD'
   *   '<S24>/CL'
   *   '<S24>/Cm'
   */
  real_T pooled5[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S20>/CD_beta'
   *   '<S20>/CL_beta'
   *   '<S20>/CY_basic'
   *   '<S20>/Cl_basic'
   *   '<S20>/Cm_beta'
   *   '<S20>/Cn_basic'
   *   '<S23>/CD'
   *   '<S23>/CY'
   *   '<S23>/Cl'
   *   '<S23>/Cn'
   *   '<S24>/CD'
   *   '<S24>/CL'
   *   '<S24>/Cm'
   *   '<S25>/CD_dr'
   *   '<S25>/CY_dr'
   *   '<S25>/Cm_dr'
   *   '<S25>/Cn_dr'
   */
  real_T pooled6[6];

  /* Expression: ada.CD
   * Referenced by: '<S23>/CD'
   */
  real_T CD_Table[42];

  /* Expression: ada.CY
   * Referenced by: '<S23>/CY'
   */
  real_T CY_Table[42];

  /* Expression: ada.Cl
   * Referenced by: '<S23>/Cl'
   */
  real_T Cl_Table[42];

  /* Expression: ada.Cn
   * Referenced by: '<S23>/Cn'
   */
  real_T Cn_Table[42];

  /* Expression: ade.CD
   * Referenced by: '<S24>/CD'
   */
  real_T CD_Table_e[42];

  /* Expression: ade.CL
   * Referenced by: '<S24>/CL'
   */
  real_T CL_Table[42];

  /* Expression: ade.Cm
   * Referenced by: '<S24>/Cm'
   */
  real_T Cm_Table[42];

  /* Pooled Parameter (Expression: adr.dd)
   * Referenced by:
   *   '<S25>/CD_dr'
   *   '<S25>/CY_dr'
   *   '<S25>/Cm_dr'
   *   '<S25>/Cn_dr'
   */
  real_T pooled8[9];

  /* Expression: adr.CD
   * Referenced by: '<S25>/CD_dr'
   */
  real_T CD_dr_Table[54];

  /* Expression: adr.CY
   * Referenced by: '<S25>/CY_dr'
   */
  real_T CY_dr_Table[54];

  /* Expression: adr.Cm
   * Referenced by: '<S25>/Cm_dr'
   */
  real_T Cm_dr_Table[54];

  /* Expression: adr.Cn
   * Referenced by: '<S25>/Cn_dr'
   */
  real_T Cn_dr_Table[54];

  /* Pooled Parameter (Expression: alat.beta)
   * Referenced by:
   *   '<S20>/CD_beta'
   *   '<S20>/CL_beta'
   *   '<S20>/CY_basic'
   *   '<S20>/Cl_basic'
   *   '<S20>/Cm_beta'
   *   '<S20>/Cn_basic'
   */
  real_T pooled9[7];

  /* Expression: alat.CY
   * Referenced by: '<S20>/CY_basic'
   */
  real_T CY_basic_Table[42];

  /* Expression: alat.Cl
   * Referenced by: '<S20>/Cl_basic'
   */
  real_T Cl_basic_Table[42];

  /* Expression: alat.Cn
   * Referenced by: '<S20>/Cn_basic'
   */
  real_T Cn_basic_Table[42];

  /* Pooled Parameter (Expression: alon.alpha)
   * Referenced by:
   *   '<S20>/CD_basic'
   *   '<S20>/CL_basic'
   *   '<S20>/Cm_basic'
   */
  real_T pooled10[23];

  /* Expression: alon.CL
   * Referenced by: '<S20>/CL_basic'
   */
  real_T CL_basic_YData[23];

  /* Expression: alat.CL
   * Referenced by: '<S20>/CL_beta'
   */
  real_T CL_beta_Table[42];

  /* Expression: alon.CD
   * Referenced by: '<S20>/CD_basic'
   */
  real_T CD_basic_YData[23];

  /* Expression: alat.CD
   * Referenced by: '<S20>/CD_beta'
   */
  real_T CD_beta_Table[42];

  /* Expression: alon.Cm
   * Referenced by: '<S20>/Cm_basic'
   */
  real_T Cm_basic_YData[23];

  /* Expression: alat.Cm
   * Referenced by: '<S20>/Cm_beta'
   */
  real_T Cm_beta_Table[42];

  /* Pooled Parameter (Expression: adyn.alpha)
   * Referenced by:
   *   '<S26>/CYp'
   *   '<S26>/Clp'
   *   '<S26>/Cnp'
   *   '<S27>/CLq'
   *   '<S27>/Cmq'
   *   '<S28>/CYr'
   *   '<S28>/Clr'
   *   '<S28>/Cnr'
   */
  real_T pooled11[5];

  /* Expression: adyn.CYp
   * Referenced by: '<S26>/CYp'
   */
  real_T CYp_YData[5];

  /* Expression: adyn.Clp
   * Referenced by: '<S26>/Clp'
   */
  real_T Clp_YData[5];

  /* Expression: adyn.Cnp
   * Referenced by: '<S26>/Cnp'
   */
  real_T Cnp_YData[5];

  /* Expression: adyn.CLq
   * Referenced by: '<S27>/CLq'
   */
  real_T CLq_YData[5];

  /* Expression: adyn.Cmq
   * Referenced by: '<S27>/Cmq'
   */
  real_T Cmq_YData[5];

  /* Expression: adyn.CYr
   * Referenced by: '<S28>/CYr'
   */
  real_T CYr_YData[5];

  /* Expression: adyn.Clr
   * Referenced by: '<S28>/Clr'
   */
  real_T Clr_YData[5];

  /* Expression: adyn.Cnr
   * Referenced by: '<S28>/Cnr'
   */
  real_T Cnr_YData[5];

  /* Expression: gain
   * Referenced by: '<S145>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S53>/Gain'
   *   '<S54>/Constant'
   *   '<S87>/Constant'
   *   '<S87>/Discrete-Time Integrator'
   *   '<S87>/Discrete-Time Integrator1'
   *   '<S34>/Constant'
   *   '<S34>/Constant1'
   *   '<S64>/Constant'
   *   '<S65>/Constant'
   *   '<S68>/Switch'
   *   '<S80>/Constant'
   *   '<S82>/Constant'
   *   '<S85>/Constant'
   *   '<S35>/Discrete-Time Integrator'
   *   '<S36>/Saturation1'
   *   '<S70>/Switch'
   *   '<S95>/Constant'
   *   '<S95>/Constant1'
   *   '<S95>/Constant2'
   *   '<S95>/Constant3'
   *   '<S128>/Saturation'
   *   '<S131>/Delay1'
   *   '<S63>/Constant1'
   *   '<S63>/Constant2'
   *   '<S63>/Constant3'
   *   '<S63>/Constant4'
   *   '<S123>/Limit  altitude  to Stratosphere'
   *   '<S123>/Limit  altitude  to troposhere'
   *   '<S124>/Constant3'
   *   '<S125>/Random Source'
   *   '<S134>/Random Source'
   *   '<S134>/Random Source1'
   *   '<S137>/Discrete FIR Filter'
   *   '<S152>/Random Source'
   *   '<S163>/Random Source'
   *   '<S174>/Random Source'
   *   '<S171>/Constant'
   *   '<S171>/Constant2'
   *   '<S171>/Constant3'
   *   '<S171>/Constant4'
   *   '<S172>/Constant1'
   *   '<S172>/Constant2'
   *   '<S172>/Constant3'
   *   '<S172>/Constant4'
   */
  real32_T pooled27;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S86>/Inertia_Matrix'
   *   '<S67>/Inertia_Matrix'
   */
  real32_T pooled32[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S168>/Saturation'
   *   '<S125>/Random Source'
   */
  real32_T pooled36;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S134>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S134>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_h
   * Referenced by: '<S152>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_h[3];

  /* Computed Parameter: RandomSource_VarianceRTP_o
   * Referenced by: '<S163>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_o[3];

  /* Expression: wmm_declination
   * Referenced by: '<S169>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S169>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S169>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_om
   * Referenced by: '<S174>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_om[3];
} ConstP_Plant_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Environment_Info_Bus Environment_Info;/* '<Root>/Environment_Info' */
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
} ExtU_Plant_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Plant_States_Bus Plant_States;       /* '<Root>/Plant_States' */
  Extended_States_Bus Extended_States; /* '<Root>/Extended_States' */
  IMU_Bus IMU;                         /* '<Root>/IMU' */
  MAG_Bus MAG;                         /* '<Root>/MAG' */
  Barometer_Bus Barometer;             /* '<Root>/Barometer' */
  GPS_uBlox_Bus GPS;                   /* '<Root>/GPS' */
  AirSpeed_Bus Airspeed;               /* '<Root>/Airspeed' */
} ExtY_Plant_T;

/* Real-time Model Data Structure */
struct tag_RTM_Plant_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Plant_T Plant_B;

/* Block states (default storage) */
extern DW_Plant_T Plant_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Plant_T Plant_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Plant_T Plant_Y;

/* External data declarations for dependent source files */
extern const Plant_States_Bus Plant_rtZPlant_States_Bus;/* Plant_States_Bus ground */
extern const Extended_States_Bus Plant_rtZExtended_States_Bus;/* Extended_States_Bus ground */
extern const AirSpeed_Bus Plant_rtZAirSpeed_Bus;/* AirSpeed_Bus ground */
extern const ConstB_Plant_T Plant_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Plant_T Plant_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_jgVLU9PsiazymsYzo6u6IH PLANT_EXPORT;/* Variable: PLANT_EXPORT
                                                   * Referenced by:
                                                   *   '<S42>/dt'
                                                   *   '<S111>/dt'
                                                   */

/* Model entry point functions */
extern void Plant_init(void);
extern void Plant_step(void);
extern void Plant_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Plant_T *const Plant_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Product' : Unused code path elimination
 * Block '<S123>/Product3' : Unused code path elimination
 * Block '<S123>/a' : Unused code path elimination
 * Block '<S123>/gamma*R' : Unused code path elimination
 * Block '<S123>/rho0' : Unused code path elimination
 * Block '<S1>/Reshape' : Reshape block reduction
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S42>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S53>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S81>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S81>/Reshape' : Reshape block reduction
 * Block '<S82>/Reshape1' : Reshape block reduction
 * Block '<S111>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S118>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S122>/Switch' : Eliminated due to constant selection input
 * Block '<S120>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S126>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S126>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S126>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S126>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S126>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S129>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S129>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S129>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S132>/Switch' : Eliminated due to constant selection input
 * Block '<S132>/Switch1' : Eliminated due to constant selection input
 * Block '<S145>/Reshape' : Reshape block reduction
 * Block '<S150>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S144>/Switch' : Eliminated due to constant selection input
 * Block '<S156>/Reshape' : Reshape block reduction
 * Block '<S161>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S155>/Switch' : Eliminated due to constant selection input
 * Block '<S168>/Switch' : Eliminated due to constant selection input
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
 * '<Root>' : 'Plant'
 * '<S1>'   : 'Plant/Actuators'
 * '<S2>'   : 'Plant/Bus_Constructor'
 * '<S3>'   : 'Plant/DocBlock'
 * '<S4>'   : 'Plant/Environment'
 * '<S5>'   : 'Plant/Kinematic_Equation'
 * '<S6>'   : 'Plant/Sensor_Model'
 * '<S7>'   : 'Plant/Actuators/Aerodynamics Forces and Moments'
 * '<S8>'   : 'Plant/Actuators/Propulsion Forces and Moments'
 * '<S9>'   : 'Plant/Actuators/Wind_Triangle'
 * '<S10>'  : 'Plant/Actuators/selector'
 * '<S11>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command'
 * '<S12>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients'
 * '<S13>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments'
 * '<S14>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Diff Pressure'
 * '<S15>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/nonunit value'
 * '<S16>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/aileron_cmd'
 * '<S17>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/elevator_cmd'
 * '<S18>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/rudder_cmd'
 * '<S19>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments'
 * '<S20>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Basic Coefficients'
 * '<S21>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body axis forces'
 * '<S22>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping'
 * '<S23>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/aileron'
 * '<S24>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/elevator'
 * '<S25>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/rudder'
 * '<S26>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/p'
 * '<S27>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/q'
 * '<S28>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/r'
 * '<S29>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces'
 * '<S30>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product'
 * '<S31>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product/Subsystem'
 * '<S32>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product/Subsystem1'
 * '<S33>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs'
 * '<S34>'  : 'Plant/Actuators/Propulsion Forces and Moments/Force'
 * '<S35>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs/Rotor_Delay'
 * '<S36>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs/Rotor_Speed'
 * '<S37>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs/Rotor_Speed/Compare To Constant'
 * '<S38>'  : 'Plant/Actuators/Propulsion Forces and Moments/Force/Rotor_Thrust'
 * '<S39>'  : 'Plant/Actuators/Wind_Triangle/Attack_Angle'
 * '<S40>'  : 'Plant/Actuators/Wind_Triangle/Slide_Angle'
 * '<S41>'  : 'Plant/Actuators/Wind_Triangle/Slide_Angle/Vector Modulus'
 * '<S42>'  : 'Plant/Bus_Constructor/Counter'
 * '<S43>'  : 'Plant/Bus_Constructor/Quaternion To DCM'
 * '<S44>'  : 'Plant/Bus_Constructor/WGS84'
 * '<S45>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize'
 * '<S46>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_1'
 * '<S47>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_2'
 * '<S48>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_3'
 * '<S49>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S50>'  : 'Plant/Bus_Constructor/WGS84/WGS84_Derivative'
 * '<S51>'  : 'Plant/Bus_Constructor/WGS84/Zero_Value_Exclusion'
 * '<S52>'  : 'Plant/Environment/Aerodynamic'
 * '<S53>'  : 'Plant/Environment/Collision_Response'
 * '<S54>'  : 'Plant/Environment/Compare To Zero'
 * '<S55>'  : 'Plant/Environment/Detect Increase'
 * '<S56>'  : 'Plant/Environment/External_Torque_Force'
 * '<S57>'  : 'Plant/Environment/Gravity'
 * '<S58>'  : 'Plant/Environment/SImple_Ground_Model'
 * '<S59>'  : 'Plant/Environment/Total_Reponse_Force'
 * '<S60>'  : 'Plant/Environment/Vector Modulus'
 * '<S61>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S62>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM'
 * '<S63>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM/Rotation Matrix Z'
 * '<S64>'  : 'Plant/Environment/Collision_Response/Compare To Zero'
 * '<S65>'  : 'Plant/Environment/Collision_Response/Compare To Zero1'
 * '<S66>'  : 'Plant/Environment/Collision_Response/Friction_Response'
 * '<S67>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction'
 * '<S68>'  : 'Plant/Environment/Collision_Response/Vector Normalize'
 * '<S69>'  : 'Plant/Environment/Collision_Response/Friction_Response/Vector Modulus'
 * '<S70>'  : 'Plant/Environment/Collision_Response/Friction_Response/Vector Normalize'
 * '<S71>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product'
 * '<S72>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product1'
 * '<S73>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product2'
 * '<S74>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product/Subsystem'
 * '<S75>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product/Subsystem1'
 * '<S76>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product1/Subsystem'
 * '<S77>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product1/Subsystem1'
 * '<S78>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product2/Subsystem'
 * '<S79>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product2/Subsystem1'
 * '<S80>'  : 'Plant/Environment/SImple_Ground_Model/Compare To Zero'
 * '<S81>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force'
 * '<S82>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Torque'
 * '<S83>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force/Compare To Constant'
 * '<S84>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force/Compare To Constant1'
 * '<S85>'  : 'Plant/Environment/Total_Reponse_Force/Compare To Zero'
 * '<S86>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S87>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S88>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S89>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S90>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S91>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S92>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S93>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S94>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S95>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S96>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S97>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S98>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S99>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S100>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S101>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S102>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S103>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S104>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S105>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S106>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S107>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S108>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S109>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S110>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S111>' : 'Plant/Sensor_Model/Counter'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_Airspeed'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_Airspeed/Airspeed'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_Airspeed/Bus_Constructor'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S149>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S150>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S151>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S152>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S153>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S154>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S155>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S156>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S157>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S158>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S159>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S160>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S161>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S162>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S163>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S164>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S165>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S166>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S167>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S168>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S169>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S170>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S171>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S172>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S173>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S174>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
