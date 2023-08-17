/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 17 14:57:54 2023
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
  GPS_uBlox_Bus RateTransition;        /* '<S104>/Rate Transition' */
  MAG_Bus RateTransition_l;            /* '<S142>/Rate Transition' */
  Barometer_Bus RateTransition_p;      /* '<S98>/Rate Transition' */
  AirSpeed_Bus RateTransition_e;       /* '<S96>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S109>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S114>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[3];             /* '<S44>/Delay1' */
  real_T Delay_DSTATE_f[3];            /* '<S44>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S139>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];/* '<S128>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S134>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[4];/* '<S123>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_j[150];       /* '<S109>/Delay1' */
  real32_T DiscreteFIRFilter_states_i[3];/* '<S115>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S68>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S64>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b[3];/* '<S65>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S65>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[2];/* '<S35>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_h;             /* '<S42>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S89>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S152>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S152>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_h[3];/* '<S130>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f[6];/* '<S130>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_e[3];/* '<S141>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_p[6];/* '<S141>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_a[3];/* '<S112>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f2[6];/* '<S112>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S112>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S112>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_fn[2];/* '<S103>/Random Source' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S68>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S64>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S65>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S65>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S139>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S128>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S116>/Sum' */
  const real_T ff;                     /* '<S116>/Multiply3' */
  const real_T Sum4;                   /* '<S116>/Sum4' */
  const real_T Subtract1;              /* '<S50>/Subtract1' */
  const real_T Product1;               /* '<S50>/Product1' */
  const real32_T Add[9];               /* '<S151>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S150>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S149>/Vector Concatenate3' */
  const real32_T Add_g[9];             /* '<S129>/Add' */
  const real32_T Add_k[9];             /* '<S140>/Add' */
  const real32_T quat0[4];             /* '<S64>/quat0' */
  const real32_T Sum_k[3];             /* '<S29>/Sum' */
  const uint8_T DataTypeConversion;    /* '<S104>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S104>/Data Type Conversion1' */
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
   * Referenced by: '<S123>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<S65>/Constant'
   *   '<S65>/Discrete-Time Integrator'
   *   '<S65>/Discrete-Time Integrator1'
   *   '<S34>/Constant'
   *   '<S34>/Constant1'
   *   '<S59>/Constant'
   *   '<S61>/Constant'
   *   '<S35>/Discrete-Time Integrator'
   *   '<S36>/Saturation1'
   *   '<S73>/Constant'
   *   '<S73>/Constant1'
   *   '<S73>/Constant2'
   *   '<S73>/Constant3'
   *   '<S106>/Saturation'
   *   '<S109>/Delay1'
   *   '<S101>/Limit  altitude  to Stratosphere'
   *   '<S101>/Limit  altitude  to troposhere'
   *   '<S102>/Constant3'
   *   '<S103>/Random Source'
   *   '<S112>/Random Source'
   *   '<S112>/Random Source1'
   *   '<S115>/Discrete FIR Filter'
   *   '<S130>/Random Source'
   *   '<S141>/Random Source'
   *   '<S152>/Random Source'
   *   '<S149>/Constant'
   *   '<S149>/Constant2'
   *   '<S149>/Constant3'
   *   '<S149>/Constant4'
   *   '<S150>/Constant1'
   *   '<S150>/Constant2'
   *   '<S150>/Constant3'
   *   '<S150>/Constant4'
   */
  real32_T pooled27;

  /* Computed Parameter: Inertia_Matrix_Value
   * Referenced by: '<S64>/Inertia_Matrix'
   */
  real32_T Inertia_Matrix_Value[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S146>/Saturation'
   *   '<S103>/Random Source'
   */
  real32_T pooled36;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S112>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S112>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_h
   * Referenced by: '<S130>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_h[3];

  /* Computed Parameter: RandomSource_VarianceRTP_o
   * Referenced by: '<S141>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_o[3];

  /* Expression: wmm_declination
   * Referenced by: '<S147>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S147>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S147>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_om
   * Referenced by: '<S152>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_om[3];
} ConstP_Plant_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
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
extern const Control_Out_Bus Plant_rtZControl_Out_Bus;/* Control_Out_Bus ground */
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
                                                   *   '<S89>/dt'
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
 * Block '<S101>/Product' : Unused code path elimination
 * Block '<S101>/Product3' : Unused code path elimination
 * Block '<S101>/a' : Unused code path elimination
 * Block '<S101>/gamma*R' : Unused code path elimination
 * Block '<S101>/rho0' : Unused code path elimination
 * Block '<S1>/Reshape' : Reshape block reduction
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S42>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S60>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S60>/Reshape' : Reshape block reduction
 * Block '<S61>/Reshape1' : Reshape block reduction
 * Block '<S89>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S100>/Switch' : Eliminated due to constant selection input
 * Block '<S98>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S104>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S104>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S104>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S104>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S104>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S107>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S107>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S107>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S110>/Switch' : Eliminated due to constant selection input
 * Block '<S110>/Switch1' : Eliminated due to constant selection input
 * Block '<S123>/Reshape' : Reshape block reduction
 * Block '<S128>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S122>/Switch' : Eliminated due to constant selection input
 * Block '<S134>/Reshape' : Reshape block reduction
 * Block '<S139>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Switch' : Eliminated due to constant selection input
 * Block '<S146>/Switch' : Eliminated due to constant selection input
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
 * '<S53>'  : 'Plant/Environment/Gravity'
 * '<S54>'  : 'Plant/Environment/Ground_Model'
 * '<S55>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S56>'  : 'Plant/Environment/Gravity/Cross Product'
 * '<S57>'  : 'Plant/Environment/Gravity/Cross Product/Subsystem'
 * '<S58>'  : 'Plant/Environment/Gravity/Cross Product/Subsystem1'
 * '<S59>'  : 'Plant/Environment/Ground_Model/Compare To Zero'
 * '<S60>'  : 'Plant/Environment/Ground_Model/Ground_Force'
 * '<S61>'  : 'Plant/Environment/Ground_Model/Ground_Torque'
 * '<S62>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant'
 * '<S63>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant1'
 * '<S64>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S65>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S66>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S67>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S68>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S69>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S70>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S71>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S72>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S73>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S74>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S75>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S76>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S77>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S78>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S79>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S80>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S81>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S82>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S83>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S84>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S85>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S86>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S87>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S88>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S89>'  : 'Plant/Sensor_Model/Counter'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_Airspeed'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_Airspeed/Airspeed'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_Airspeed/Bus_Constructor'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S149>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S150>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S151>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S152>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
