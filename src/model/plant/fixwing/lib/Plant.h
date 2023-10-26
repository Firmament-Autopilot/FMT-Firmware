/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.80
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Oct 26 08:28:27 2023
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
  GPS_uBlox_Bus RateTransition;        /* '<S137>/Rate Transition' */
  MAG_Bus RateTransition_l;            /* '<S175>/Rate Transition' */
  Barometer_Bus RateTransition_p;      /* '<S131>/Rate Transition' */
  AirSpeed_Bus RateTransition_e;       /* '<S129>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S142>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S147>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[3];             /* '<S45>/Delay1' */
  real_T Delay_DSTATE_f[3];            /* '<S45>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S172>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];/* '<S161>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S167>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[4];/* '<S156>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_j[150];       /* '<S142>/Delay1' */
  real32_T DiscreteFIRFilter_states_i[3];/* '<S148>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S101>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S97>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b[3];/* '<S98>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S98>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[2];/* '<S36>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_h;             /* '<S43>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S122>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S185>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S185>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_h[3];/* '<S163>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f[6];/* '<S163>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_e[3];/* '<S174>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_p[6];/* '<S174>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_a[3];/* '<S145>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f2[6];/* '<S145>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S145>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S145>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_fn[2];/* '<S136>/Random Source' */
  boolean_T DelayInput1_DSTATE;        /* '<S66>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S101>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S97>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S98>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S98>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S172>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S161>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S149>/Sum' */
  const real_T ff;                     /* '<S149>/Multiply3' */
  const real_T Sum4;                   /* '<S149>/Sum4' */
  const real_T Subtract1;              /* '<S51>/Subtract1' */
  const real_T Product1;               /* '<S51>/Product1' */
  const real32_T Add[9];               /* '<S184>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S183>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S182>/Vector Concatenate3' */
  const real32_T Add_g[9];             /* '<S162>/Add' */
  const real32_T Add_k[9];             /* '<S173>/Add' */
  const real32_T quat0[4];             /* '<S97>/quat0' */
  const real32_T VectorConcatenate3_h[3];/* '<S74>/Vector Concatenate3' */
  const real32_T Add_o;                /* '<S78>/Add' */
  const real32_T Sum_k[3];             /* '<S30>/Sum' */
  const uint8_T DataTypeConversion;    /* '<S137>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S137>/Data Type Conversion1' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S24>/CD'
   *   '<S24>/CY'
   *   '<S24>/Cl'
   *   '<S24>/Cn'
   *   '<S25>/CD'
   *   '<S25>/CL'
   *   '<S25>/Cm'
   */
  real_T pooled5[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S21>/CD_beta'
   *   '<S21>/CL_beta'
   *   '<S21>/CY_basic'
   *   '<S21>/Cl_basic'
   *   '<S21>/Cm_beta'
   *   '<S21>/Cn_basic'
   *   '<S24>/CD'
   *   '<S24>/CY'
   *   '<S24>/Cl'
   *   '<S24>/Cn'
   *   '<S25>/CD'
   *   '<S25>/CL'
   *   '<S25>/Cm'
   *   '<S26>/CD_dr'
   *   '<S26>/CY_dr'
   *   '<S26>/Cm_dr'
   *   '<S26>/Cn_dr'
   */
  real_T pooled6[6];

  /* Expression: ada.CD
   * Referenced by: '<S24>/CD'
   */
  real_T CD_Table[42];

  /* Expression: ada.CY
   * Referenced by: '<S24>/CY'
   */
  real_T CY_Table[42];

  /* Expression: ada.Cl
   * Referenced by: '<S24>/Cl'
   */
  real_T Cl_Table[42];

  /* Expression: ada.Cn
   * Referenced by: '<S24>/Cn'
   */
  real_T Cn_Table[42];

  /* Expression: ade.CD
   * Referenced by: '<S25>/CD'
   */
  real_T CD_Table_e[42];

  /* Expression: ade.CL
   * Referenced by: '<S25>/CL'
   */
  real_T CL_Table[42];

  /* Expression: ade.Cm
   * Referenced by: '<S25>/Cm'
   */
  real_T Cm_Table[42];

  /* Pooled Parameter (Expression: adr.dd)
   * Referenced by:
   *   '<S26>/CD_dr'
   *   '<S26>/CY_dr'
   *   '<S26>/Cm_dr'
   *   '<S26>/Cn_dr'
   */
  real_T pooled8[9];

  /* Expression: adr.CD
   * Referenced by: '<S26>/CD_dr'
   */
  real_T CD_dr_Table[54];

  /* Expression: adr.CY
   * Referenced by: '<S26>/CY_dr'
   */
  real_T CY_dr_Table[54];

  /* Expression: adr.Cm
   * Referenced by: '<S26>/Cm_dr'
   */
  real_T Cm_dr_Table[54];

  /* Expression: adr.Cn
   * Referenced by: '<S26>/Cn_dr'
   */
  real_T Cn_dr_Table[54];

  /* Pooled Parameter (Expression: alat.beta)
   * Referenced by:
   *   '<S21>/CD_beta'
   *   '<S21>/CL_beta'
   *   '<S21>/CY_basic'
   *   '<S21>/Cl_basic'
   *   '<S21>/Cm_beta'
   *   '<S21>/Cn_basic'
   */
  real_T pooled9[7];

  /* Expression: alat.CY
   * Referenced by: '<S21>/CY_basic'
   */
  real_T CY_basic_Table[42];

  /* Expression: alat.Cl
   * Referenced by: '<S21>/Cl_basic'
   */
  real_T Cl_basic_Table[42];

  /* Expression: alat.Cn
   * Referenced by: '<S21>/Cn_basic'
   */
  real_T Cn_basic_Table[42];

  /* Pooled Parameter (Expression: alon.alpha)
   * Referenced by:
   *   '<S21>/CD_basic'
   *   '<S21>/CL_basic'
   *   '<S21>/Cm_basic'
   */
  real_T pooled10[23];

  /* Expression: alon.CL
   * Referenced by: '<S21>/CL_basic'
   */
  real_T CL_basic_YData[23];

  /* Expression: alat.CL
   * Referenced by: '<S21>/CL_beta'
   */
  real_T CL_beta_Table[42];

  /* Expression: alon.CD
   * Referenced by: '<S21>/CD_basic'
   */
  real_T CD_basic_YData[23];

  /* Expression: alat.CD
   * Referenced by: '<S21>/CD_beta'
   */
  real_T CD_beta_Table[42];

  /* Expression: alon.Cm
   * Referenced by: '<S21>/Cm_basic'
   */
  real_T Cm_basic_YData[23];

  /* Expression: alat.Cm
   * Referenced by: '<S21>/Cm_beta'
   */
  real_T Cm_beta_Table[42];

  /* Pooled Parameter (Expression: adyn.alpha)
   * Referenced by:
   *   '<S27>/CYp'
   *   '<S27>/Clp'
   *   '<S27>/Cnp'
   *   '<S28>/CLq'
   *   '<S28>/Cmq'
   *   '<S29>/CYr'
   *   '<S29>/Clr'
   *   '<S29>/Cnr'
   */
  real_T pooled11[5];

  /* Expression: adyn.CYp
   * Referenced by: '<S27>/CYp'
   */
  real_T CYp_YData[5];

  /* Expression: adyn.Clp
   * Referenced by: '<S27>/Clp'
   */
  real_T Clp_YData[5];

  /* Expression: adyn.Cnp
   * Referenced by: '<S27>/Cnp'
   */
  real_T Cnp_YData[5];

  /* Expression: adyn.CLq
   * Referenced by: '<S28>/CLq'
   */
  real_T CLq_YData[5];

  /* Expression: adyn.Cmq
   * Referenced by: '<S28>/Cmq'
   */
  real_T Cmq_YData[5];

  /* Expression: adyn.CYr
   * Referenced by: '<S29>/CYr'
   */
  real_T CYr_YData[5];

  /* Expression: adyn.Clr
   * Referenced by: '<S29>/Clr'
   */
  real_T Clr_YData[5];

  /* Expression: adyn.Cnr
   * Referenced by: '<S29>/Cnr'
   */
  real_T Cnr_YData[5];

  /* Expression: gain
   * Referenced by: '<S156>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S6>/Constant'
   *   '<S64>/Gain'
   *   '<S65>/Constant'
   *   '<S98>/Constant'
   *   '<S98>/Discrete-Time Integrator'
   *   '<S98>/Discrete-Time Integrator1'
   *   '<S35>/Constant'
   *   '<S35>/Constant1'
   *   '<S75>/Constant'
   *   '<S76>/Constant'
   *   '<S79>/Switch'
   *   '<S91>/Constant'
   *   '<S93>/Constant'
   *   '<S96>/Constant'
   *   '<S36>/Discrete-Time Integrator'
   *   '<S37>/Saturation1'
   *   '<S81>/Switch'
   *   '<S106>/Constant'
   *   '<S106>/Constant1'
   *   '<S106>/Constant2'
   *   '<S106>/Constant3'
   *   '<S139>/Saturation'
   *   '<S142>/Delay1'
   *   '<S74>/Constant1'
   *   '<S74>/Constant2'
   *   '<S74>/Constant3'
   *   '<S74>/Constant4'
   *   '<S134>/Limit  altitude  to Stratosphere'
   *   '<S134>/Limit  altitude  to troposhere'
   *   '<S135>/Constant3'
   *   '<S136>/Random Source'
   *   '<S145>/Random Source'
   *   '<S145>/Random Source1'
   *   '<S148>/Discrete FIR Filter'
   *   '<S163>/Random Source'
   *   '<S174>/Random Source'
   *   '<S185>/Random Source'
   *   '<S182>/Constant'
   *   '<S182>/Constant2'
   *   '<S182>/Constant3'
   *   '<S182>/Constant4'
   *   '<S183>/Constant1'
   *   '<S183>/Constant2'
   *   '<S183>/Constant3'
   *   '<S183>/Constant4'
   */
  real32_T pooled27;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S97>/Inertia_Matrix'
   *   '<S78>/Inertia_Matrix'
   */
  real32_T pooled32[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S179>/Saturation'
   *   '<S136>/Random Source'
   */
  real32_T pooled37;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S145>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S145>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_h
   * Referenced by: '<S163>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_h[3];

  /* Computed Parameter: RandomSource_VarianceRTP_o
   * Referenced by: '<S174>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_o[3];

  /* Expression: wmm_declination
   * Referenced by: '<S180>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S180>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S180>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_om
   * Referenced by: '<S185>/Random Source'
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
                                                   *   '<S43>/dt'
                                                   *   '<S122>/dt'
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
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Product' : Unused code path elimination
 * Block '<S134>/Product3' : Unused code path elimination
 * Block '<S134>/a' : Unused code path elimination
 * Block '<S134>/gamma*R' : Unused code path elimination
 * Block '<S134>/rho0' : Unused code path elimination
 * Block '<S1>/Reshape' : Reshape block reduction
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S43>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S64>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S92>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S92>/Reshape' : Reshape block reduction
 * Block '<S93>/Reshape1' : Reshape block reduction
 * Block '<S122>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S129>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Switch' : Eliminated due to constant selection input
 * Block '<S131>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S137>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S137>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S137>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S137>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S137>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S140>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S140>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S140>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S143>/Switch' : Eliminated due to constant selection input
 * Block '<S143>/Switch1' : Eliminated due to constant selection input
 * Block '<S156>/Reshape' : Reshape block reduction
 * Block '<S161>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S155>/Switch' : Eliminated due to constant selection input
 * Block '<S167>/Reshape' : Reshape block reduction
 * Block '<S172>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S166>/Switch' : Eliminated due to constant selection input
 * Block '<S179>/Switch' : Eliminated due to constant selection input
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
 * '<S5>'   : 'Plant/Environment1'
 * '<S6>'   : 'Plant/Kinematic_Equation'
 * '<S7>'   : 'Plant/Sensor_Model'
 * '<S8>'   : 'Plant/Actuators/Aerodynamics Forces and Moments'
 * '<S9>'   : 'Plant/Actuators/Propulsion Forces and Moments'
 * '<S10>'  : 'Plant/Actuators/Wind_Triangle'
 * '<S11>'  : 'Plant/Actuators/selector'
 * '<S12>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command'
 * '<S13>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients'
 * '<S14>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments'
 * '<S15>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Diff Pressure'
 * '<S16>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/nonunit value'
 * '<S17>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/aileron_cmd'
 * '<S18>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/elevator_cmd'
 * '<S19>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/rudder_cmd'
 * '<S20>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments'
 * '<S21>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Basic Coefficients'
 * '<S22>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body axis forces'
 * '<S23>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping'
 * '<S24>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/aileron'
 * '<S25>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/elevator'
 * '<S26>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/rudder'
 * '<S27>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/p'
 * '<S28>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/q'
 * '<S29>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/r'
 * '<S30>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces'
 * '<S31>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product'
 * '<S32>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product/Subsystem'
 * '<S33>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product/Subsystem1'
 * '<S34>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs'
 * '<S35>'  : 'Plant/Actuators/Propulsion Forces and Moments/Force'
 * '<S36>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs/Rotor_Delay'
 * '<S37>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs/Rotor_Speed'
 * '<S38>'  : 'Plant/Actuators/Propulsion Forces and Moments/ESCs/Rotor_Speed/Compare To Constant'
 * '<S39>'  : 'Plant/Actuators/Propulsion Forces and Moments/Force/Rotor_Thrust'
 * '<S40>'  : 'Plant/Actuators/Wind_Triangle/Attack_Angle'
 * '<S41>'  : 'Plant/Actuators/Wind_Triangle/Slide_Angle'
 * '<S42>'  : 'Plant/Actuators/Wind_Triangle/Slide_Angle/Vector Modulus'
 * '<S43>'  : 'Plant/Bus_Constructor/Counter'
 * '<S44>'  : 'Plant/Bus_Constructor/Quaternion To DCM'
 * '<S45>'  : 'Plant/Bus_Constructor/WGS84'
 * '<S46>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize'
 * '<S47>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_1'
 * '<S48>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_2'
 * '<S49>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_3'
 * '<S50>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S51>'  : 'Plant/Bus_Constructor/WGS84/WGS84_Derivative'
 * '<S52>'  : 'Plant/Bus_Constructor/WGS84/Zero_Value_Exclusion'
 * '<S53>'  : 'Plant/Environment/Aerodynamic'
 * '<S54>'  : 'Plant/Environment/Gravity'
 * '<S55>'  : 'Plant/Environment/Ground_Model'
 * '<S56>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S57>'  : 'Plant/Environment/Gravity/Cross Product'
 * '<S58>'  : 'Plant/Environment/Gravity/Cross Product/Subsystem'
 * '<S59>'  : 'Plant/Environment/Gravity/Cross Product/Subsystem1'
 * '<S60>'  : 'Plant/Environment/Ground_Model/Compare To Zero'
 * '<S61>'  : 'Plant/Environment/Ground_Model/Ground_Force'
 * '<S62>'  : 'Plant/Environment/Ground_Model/Ground_Torque'
 * '<S63>'  : 'Plant/Environment1/Aerodynamic'
 * '<S64>'  : 'Plant/Environment1/Collision_Response'
 * '<S65>'  : 'Plant/Environment1/Compare To Zero'
 * '<S66>'  : 'Plant/Environment1/Detect Increase'
 * '<S67>'  : 'Plant/Environment1/External_Torque_Force'
 * '<S68>'  : 'Plant/Environment1/Gravity'
 * '<S69>'  : 'Plant/Environment1/SImple_Ground_Model'
 * '<S70>'  : 'Plant/Environment1/Total_Reponse_Force'
 * '<S71>'  : 'Plant/Environment1/Vector Modulus'
 * '<S72>'  : 'Plant/Environment1/Aerodynamic/Air_Drag'
 * '<S73>'  : 'Plant/Environment1/Aerodynamic/Air_Drag/Psi To DCM'
 * '<S74>'  : 'Plant/Environment1/Aerodynamic/Air_Drag/Psi To DCM/Rotation Matrix Z'
 * '<S75>'  : 'Plant/Environment1/Collision_Response/Compare To Zero'
 * '<S76>'  : 'Plant/Environment1/Collision_Response/Compare To Zero1'
 * '<S77>'  : 'Plant/Environment1/Collision_Response/Friction_Response'
 * '<S78>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction'
 * '<S79>'  : 'Plant/Environment1/Collision_Response/Vector Normalize'
 * '<S80>'  : 'Plant/Environment1/Collision_Response/Friction_Response/Vector Modulus'
 * '<S81>'  : 'Plant/Environment1/Collision_Response/Friction_Response/Vector Normalize'
 * '<S82>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product'
 * '<S83>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product1'
 * '<S84>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product2'
 * '<S85>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product/Subsystem'
 * '<S86>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product/Subsystem1'
 * '<S87>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product1/Subsystem'
 * '<S88>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product1/Subsystem1'
 * '<S89>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product2/Subsystem'
 * '<S90>'  : 'Plant/Environment1/Collision_Response/Impulse_Reaction/Cross Product2/Subsystem1'
 * '<S91>'  : 'Plant/Environment1/SImple_Ground_Model/Compare To Zero'
 * '<S92>'  : 'Plant/Environment1/SImple_Ground_Model/Ground_Force'
 * '<S93>'  : 'Plant/Environment1/SImple_Ground_Model/Ground_Torque'
 * '<S94>'  : 'Plant/Environment1/SImple_Ground_Model/Ground_Force/Compare To Constant'
 * '<S95>'  : 'Plant/Environment1/SImple_Ground_Model/Ground_Force/Compare To Constant1'
 * '<S96>'  : 'Plant/Environment1/Total_Reponse_Force/Compare To Zero'
 * '<S97>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S98>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S99>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S100>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S101>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S102>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S103>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S104>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S105>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S106>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S107>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S108>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S109>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S110>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S111>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S112>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S113>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S114>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S115>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S116>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S117>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S118>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S119>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S120>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S121>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S122>' : 'Plant/Sensor_Model/Counter'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_Airspeed'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_Airspeed/Airspeed'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_Airspeed/Bus_Constructor'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S149>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S150>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S151>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S152>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S153>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S154>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S155>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S156>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S157>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S158>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S159>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S160>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S161>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S162>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S163>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S164>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S165>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S166>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S167>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S168>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S169>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S170>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S171>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S172>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S173>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S174>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S175>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S176>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S177>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S178>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S179>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S180>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S181>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S182>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S183>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S184>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S185>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
