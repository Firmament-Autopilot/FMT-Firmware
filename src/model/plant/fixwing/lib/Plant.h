/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.92
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun May  5 13:48:06 2024
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
  GPS_uBlox_Bus RateTransition;        /* '<S133>/Rate Transition' */
  MAG_Bus RateTransition_l;            /* '<S171>/Rate Transition' */
  Barometer_Bus RateTransition_p;      /* '<S127>/Rate Transition' */
  AirSpeed_Bus RateTransition_e;       /* '<S125>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S138>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S143>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[250];           /* '<S139>/Delay1' */
  real_T Delay_DSTATE_b[250];          /* '<S139>/Delay' */
  real_T Delay_DSTATE_f[3];            /* '<S44>/Delay' */
  real_T Delay1_DSTATE_c[3];           /* '<S44>/Delay1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S168>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];/* '<S157>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S163>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[4];/* '<S152>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_j[150];       /* '<S138>/Delay1' */
  real32_T DiscreteFIRFilter_states_i[3];/* '<S144>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_j[4];/* '<S92>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_l[3];/* '<S86>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n[3];/* '<S87>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S87>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[2];/* '<S35>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S89>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S103>/Delay Input1' */
  uint32_T Delay_DSTATE_h;             /* '<S42>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S118>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S181>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S181>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_h[3];/* '<S159>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f[6];/* '<S159>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_e[3];/* '<S170>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_p[6];/* '<S170>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_a[3];/* '<S141>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f2[6];/* '<S141>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S141>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S141>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_fn[2];/* '<S132>/Random Source' */
  boolean_T DelayInput1_DSTATE_b;      /* '<S55>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S92>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S86>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S87>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S87>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S168>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S157>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S92>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S87>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S44>/Delay1' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S145>/Sum' */
  const real_T ff;                     /* '<S145>/Multiply3' */
  const real_T Sum4;                   /* '<S145>/Sum4' */
  const real_T Subtract1;              /* '<S50>/Subtract1' */
  const real_T Product1;               /* '<S50>/Product1' */
  const real32_T Add[9];               /* '<S180>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S179>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S178>/Vector Concatenate3' */
  const real32_T Add_g[9];             /* '<S158>/Add' */
  const real32_T Add_k[9];             /* '<S169>/Add' */
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
   * Referenced by: '<S152>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S53>/Gain'
   *   '<S54>/Constant'
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
   *   '<S100>/Constant'
   *   '<S100>/Constant1'
   *   '<S100>/Constant2'
   *   '<S100>/Constant3'
   *   '<S135>/Saturation'
   *   '<S138>/Delay1'
   *   '<S63>/Constant1'
   *   '<S63>/Constant2'
   *   '<S63>/Constant3'
   *   '<S63>/Constant4'
   *   '<S130>/Limit  altitude  to Stratosphere'
   *   '<S130>/Limit  altitude  to troposhere'
   *   '<S131>/Constant3'
   *   '<S132>/Random Source'
   *   '<S141>/Random Source'
   *   '<S141>/Random Source1'
   *   '<S144>/Discrete FIR Filter'
   *   '<S159>/Random Source'
   *   '<S170>/Random Source'
   *   '<S181>/Random Source'
   *   '<S178>/Constant'
   *   '<S178>/Constant2'
   *   '<S178>/Constant3'
   *   '<S178>/Constant4'
   *   '<S179>/Constant1'
   *   '<S179>/Constant2'
   *   '<S179>/Constant3'
   *   '<S179>/Constant4'
   */
  real32_T pooled27;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S86>/Inertia_Matrix'
   *   '<S67>/Inertia_Matrix'
   */
  real32_T pooled33[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S175>/Saturation'
   *   '<S132>/Random Source'
   */
  real32_T pooled38;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S141>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S141>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_h
   * Referenced by: '<S159>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_h[3];

  /* Computed Parameter: RandomSource_VarianceRTP_o
   * Referenced by: '<S170>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_o[3];

  /* Expression: wmm_declination
   * Referenced by: '<S176>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S176>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S176>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_om
   * Referenced by: '<S181>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_om[3];
} ConstP_Plant_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Environment_Info_Bus Environment_Info;/* '<Root>/Environment_Info' */
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
  States_Init_Bus States_Init;         /* '<Root>/States_Init' */
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
extern struct_3bORdf2BsPDFMyyhwl9bpH PLANT_PARAM;/* Variable: PLANT_PARAM
                                                  * Referenced by:
                                                  *   '<S2>/Constant1'
                                                  *   '<S2>/Constant2'
                                                  *   '<S2>/Constant3'
                                                  *   '<S44>/Constant1'
                                                  *   '<S44>/Constant2'
                                                  *   '<S44>/Constant3'
                                                  */
extern struct_jgVLU9PsiazymsYzo6u6IH PLANT_EXPORT;/* Variable: PLANT_EXPORT
                                                   * Referenced by:
                                                   *   '<S42>/dt'
                                                   *   '<S118>/dt'
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
 * Block '<S130>/Product' : Unused code path elimination
 * Block '<S130>/Product3' : Unused code path elimination
 * Block '<S130>/a' : Unused code path elimination
 * Block '<S130>/gamma*R' : Unused code path elimination
 * Block '<S130>/rho0' : Unused code path elimination
 * Block '<S1>/Reshape' : Reshape block reduction
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S42>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S53>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S81>/Reshape' : Reshape block reduction
 * Block '<S82>/Reshape1' : Reshape block reduction
 * Block '<S118>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S125>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Switch' : Eliminated due to constant selection input
 * Block '<S127>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S133>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S133>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S133>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S133>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S136>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S136>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S136>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S139>/Switch' : Eliminated due to constant selection input
 * Block '<S139>/Switch1' : Eliminated due to constant selection input
 * Block '<S152>/Reshape' : Reshape block reduction
 * Block '<S157>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S151>/Switch' : Eliminated due to constant selection input
 * Block '<S163>/Reshape' : Reshape block reduction
 * Block '<S168>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S162>/Switch' : Eliminated due to constant selection input
 * Block '<S175>/Switch' : Eliminated due to constant selection input
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
 * '<S89>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Detect Change'
 * '<S90>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion'
 * '<S91>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S92>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S93>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S94>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S95>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion/Quaternion Normalize'
 * '<S96>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion/Quaternion Normalize/Quaternion Modulus'
 * '<S97>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S98>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S99>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion Normalize'
 * '<S100>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S101>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion Normalize/Quaternion Modulus'
 * '<S102>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S103>' : 'Plant/Kinematic_Equation/Position_Dynamic/Detect Change'
 * '<S104>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S105>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S106>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S107>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S108>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S109>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S110>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S111>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S112>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S113>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S114>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S115>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S116>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S117>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S118>' : 'Plant/Sensor_Model/Counter'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_Airspeed'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_Airspeed/Airspeed'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_Airspeed/Bus_Constructor'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S149>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S150>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S151>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S152>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S153>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S154>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S155>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S156>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S157>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S158>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S159>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S160>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S161>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S162>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S163>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S164>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S165>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S166>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S167>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S168>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S169>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S170>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S171>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S172>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S173>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S174>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S175>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S176>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S177>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S178>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S179>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S180>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S181>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
