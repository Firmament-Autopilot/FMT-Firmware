/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.127
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec 22 16:53:37 2025
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
  GPS_uBlox_Bus RateTransition;        /* '<S141>/Rate Transition' */
  MAG_Bus RateTransition_l;            /* '<S179>/Rate Transition' */
  Barometer_Bus RateTransition_p;      /* '<S135>/Rate Transition' */
  AirSpeed_Bus RateTransition_e;       /* '<S133>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S146>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S151>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[250];           /* '<S147>/Delay1' */
  real_T Delay_DSTATE_b[250];          /* '<S147>/Delay' */
  real_T Delay1_DSTATE_c[3];           /* '<S59>/Delay1' */
  real_T Delay_DSTATE_f[3];            /* '<S59>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S176>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];/* '<S165>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S171>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[4];/* '<S160>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_j[150];       /* '<S146>/Delay1' */
  real32_T DiscreteFIRFilter_states_i[3];/* '<S152>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S105>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S101>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b[3];/* '<S102>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S102>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_ky[4];/* '<S45>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S38>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_h;             /* '<S57>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S126>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S189>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S189>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_h[3];/* '<S167>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f[6];/* '<S167>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_e[3];/* '<S178>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_p[6];/* '<S178>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_a[3];/* '<S149>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f2[6];/* '<S149>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S149>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S149>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_fn[2];/* '<S140>/Random Source' */
  boolean_T DelayInput1_DSTATE;        /* '<S70>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S105>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S101>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S102>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S102>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S176>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S165>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S153>/Sum' */
  const real_T ff;                     /* '<S153>/Multiply3' */
  const real_T Sum4;                   /* '<S153>/Sum4' */
  const real_T Subtract1;              /* '<S65>/Subtract1' */
  const real_T Product1;               /* '<S65>/Product1' */
  const real32_T Add[9];               /* '<S188>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S187>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S186>/Vector Concatenate3' */
  const real32_T Add_g[9];             /* '<S166>/Add' */
  const real32_T Add_k[9];             /* '<S177>/Add' */
  const real32_T quat0[4];             /* '<S101>/quat0' */
  const real32_T VectorConcatenate3_h[3];/* '<S78>/Vector Concatenate3' */
  const real32_T Add_o;                /* '<S82>/Add' */
  const real32_T Sum_k[3];             /* '<S32>/Sum' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S26>/CD'
   *   '<S26>/CY'
   *   '<S26>/Cl'
   *   '<S26>/Cn'
   *   '<S27>/CD'
   *   '<S27>/CL'
   *   '<S27>/Cm'
   */
  real_T pooled5[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S22>/CD_beta'
   *   '<S22>/CL_beta'
   *   '<S22>/CY_basic'
   *   '<S22>/Cl_basic'
   *   '<S22>/Cm_beta'
   *   '<S22>/Cn_basic'
   *   '<S26>/CD'
   *   '<S26>/CY'
   *   '<S26>/Cl'
   *   '<S26>/Cn'
   *   '<S27>/CD'
   *   '<S27>/CL'
   *   '<S27>/Cm'
   *   '<S28>/CD_dr'
   *   '<S28>/CY_dr'
   *   '<S28>/Cm_dr'
   *   '<S28>/Cn_dr'
   */
  real_T pooled6[6];

  /* Expression: ada.CD
   * Referenced by: '<S26>/CD'
   */
  real_T CD_Table[42];

  /* Expression: ada.CY
   * Referenced by: '<S26>/CY'
   */
  real_T CY_Table[42];

  /* Expression: ada.Cl
   * Referenced by: '<S26>/Cl'
   */
  real_T Cl_Table[42];

  /* Expression: ada.Cn
   * Referenced by: '<S26>/Cn'
   */
  real_T Cn_Table[42];

  /* Expression: ade.CD
   * Referenced by: '<S27>/CD'
   */
  real_T CD_Table_e[42];

  /* Expression: ade.CL
   * Referenced by: '<S27>/CL'
   */
  real_T CL_Table[42];

  /* Expression: ade.Cm
   * Referenced by: '<S27>/Cm'
   */
  real_T Cm_Table[42];

  /* Pooled Parameter (Expression: adr.dd)
   * Referenced by:
   *   '<S28>/CD_dr'
   *   '<S28>/CY_dr'
   *   '<S28>/Cm_dr'
   *   '<S28>/Cn_dr'
   */
  real_T pooled8[9];

  /* Expression: adr.CD
   * Referenced by: '<S28>/CD_dr'
   */
  real_T CD_dr_Table[54];

  /* Expression: adr.CY
   * Referenced by: '<S28>/CY_dr'
   */
  real_T CY_dr_Table[54];

  /* Expression: adr.Cm
   * Referenced by: '<S28>/Cm_dr'
   */
  real_T Cm_dr_Table[54];

  /* Expression: adr.Cn
   * Referenced by: '<S28>/Cn_dr'
   */
  real_T Cn_dr_Table[54];

  /* Pooled Parameter (Expression: alat.beta)
   * Referenced by:
   *   '<S22>/CD_beta'
   *   '<S22>/CL_beta'
   *   '<S22>/CY_basic'
   *   '<S22>/Cl_basic'
   *   '<S22>/Cm_beta'
   *   '<S22>/Cn_basic'
   */
  real_T pooled9[7];

  /* Expression: alat.CY
   * Referenced by: '<S22>/CY_basic'
   */
  real_T CY_basic_Table[42];

  /* Expression: alat.Cl
   * Referenced by: '<S22>/Cl_basic'
   */
  real_T Cl_basic_Table[42];

  /* Expression: alat.Cn
   * Referenced by: '<S22>/Cn_basic'
   */
  real_T Cn_basic_Table[42];

  /* Pooled Parameter (Expression: alon.alpha)
   * Referenced by:
   *   '<S22>/CD_basic'
   *   '<S22>/CL_basic'
   *   '<S22>/Cm_basic'
   */
  real_T pooled10[23];

  /* Expression: alon.CL
   * Referenced by: '<S22>/CL_basic'
   */
  real_T CL_basic_YData[23];

  /* Expression: alat.CL
   * Referenced by: '<S22>/CL_beta'
   */
  real_T CL_beta_Table[42];

  /* Expression: alon.CD
   * Referenced by: '<S22>/CD_basic'
   */
  real_T CD_basic_YData[23];

  /* Expression: alat.CD
   * Referenced by: '<S22>/CD_beta'
   */
  real_T CD_beta_Table[42];

  /* Expression: alon.Cm
   * Referenced by: '<S22>/Cm_basic'
   */
  real_T Cm_basic_YData[23];

  /* Expression: alat.Cm
   * Referenced by: '<S22>/Cm_beta'
   */
  real_T Cm_beta_Table[42];

  /* Pooled Parameter (Expression: adyn.alpha)
   * Referenced by:
   *   '<S29>/CYp'
   *   '<S29>/Clp'
   *   '<S29>/Cnp'
   *   '<S30>/CLq'
   *   '<S30>/Cmq'
   *   '<S31>/CYr'
   *   '<S31>/Clr'
   *   '<S31>/Cnr'
   */
  real_T pooled11[5];

  /* Expression: adyn.CYp
   * Referenced by: '<S29>/CYp'
   */
  real_T CYp_YData[5];

  /* Expression: adyn.Clp
   * Referenced by: '<S29>/Clp'
   */
  real_T Clp_YData[5];

  /* Expression: adyn.Cnp
   * Referenced by: '<S29>/Cnp'
   */
  real_T Cnp_YData[5];

  /* Expression: adyn.CLq
   * Referenced by: '<S30>/CLq'
   */
  real_T CLq_YData[5];

  /* Expression: adyn.Cmq
   * Referenced by: '<S30>/Cmq'
   */
  real_T Cmq_YData[5];

  /* Expression: adyn.CYr
   * Referenced by: '<S31>/CYr'
   */
  real_T CYr_YData[5];

  /* Expression: adyn.Clr
   * Referenced by: '<S31>/Clr'
   */
  real_T Clr_YData[5];

  /* Expression: adyn.Cnr
   * Referenced by: '<S31>/Cnr'
   */
  real_T Cnr_YData[5];

  /* Expression: gain
   * Referenced by: '<S160>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Computed Parameter: X_Frame_CM_Value
   * Referenced by: '<S50>/X_Frame_CM'
   */
  real32_T X_Frame_CM_Value[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S11>/Saturation'
   *   '<S68>/Gain'
   *   '<S69>/Constant'
   *   '<S102>/Constant'
   *   '<S102>/Discrete-Time Integrator'
   *   '<S102>/Discrete-Time Integrator1'
   *   '<S37>/Constant'
   *   '<S37>/Constant1'
   *   '<S43>/Constant'
   *   '<S43>/Constant1'
   *   '<S79>/Constant'
   *   '<S80>/Constant'
   *   '<S83>/Switch'
   *   '<S95>/Constant'
   *   '<S97>/Constant'
   *   '<S100>/Constant'
   *   '<S38>/Discrete-Time Integrator'
   *   '<S39>/Saturation1'
   *   '<S45>/Discrete-Time Integrator'
   *   '<S46>/Saturation1'
   *   '<S85>/Switch'
   *   '<S110>/Constant'
   *   '<S110>/Constant1'
   *   '<S110>/Constant2'
   *   '<S110>/Constant3'
   *   '<S143>/Saturation'
   *   '<S146>/Delay1'
   *   '<S78>/Constant1'
   *   '<S78>/Constant2'
   *   '<S78>/Constant3'
   *   '<S78>/Constant4'
   *   '<S138>/Limit  altitude  to Stratosphere'
   *   '<S138>/Limit  altitude  to troposhere'
   *   '<S139>/Constant3'
   *   '<S140>/Random Source'
   *   '<S149>/Random Source'
   *   '<S149>/Random Source1'
   *   '<S152>/Discrete FIR Filter'
   *   '<S167>/Random Source'
   *   '<S178>/Random Source'
   *   '<S189>/Random Source'
   *   '<S186>/Constant'
   *   '<S186>/Constant2'
   *   '<S186>/Constant3'
   *   '<S186>/Constant4'
   *   '<S187>/Constant1'
   *   '<S187>/Constant2'
   *   '<S187>/Constant3'
   *   '<S187>/Constant4'
   */
  real32_T pooled26;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S101>/Inertia_Matrix'
   *   '<S82>/Inertia_Matrix'
   */
  real32_T pooled36[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S183>/Saturation'
   *   '<S140>/Random Source'
   */
  real32_T pooled41;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S149>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S149>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_h
   * Referenced by: '<S167>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_h[3];

  /* Computed Parameter: RandomSource_VarianceRTP_o
   * Referenced by: '<S178>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_o[3];

  /* Expression: wmm_declination
   * Referenced by: '<S184>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S184>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S184>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_om
   * Referenced by: '<S189>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_om[3];
} ConstP_Plant_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Environment_Info_Bus Environment_Info;/* '<Root>/Environment_Info' */
  States_Init_Bus States_Init;         /* '<Root>/States_Init' */
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
extern struct_AjtFzZRX3GJyUtRZj0A4oG PLANT_EXPORT;/* Variable: PLANT_EXPORT
                                                   * Referenced by:
                                                   *   '<S57>/dt'
                                                   *   '<S126>/dt'
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
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Product' : Unused code path elimination
 * Block '<S138>/Product3' : Unused code path elimination
 * Block '<S138>/a' : Unused code path elimination
 * Block '<S138>/gamma*R' : Unused code path elimination
 * Block '<S138>/rho0' : Unused code path elimination
 * Block '<S1>/Reshape' : Reshape block reduction
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S57>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S68>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S96>/Reshape' : Reshape block reduction
 * Block '<S97>/Reshape1' : Reshape block reduction
 * Block '<S126>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S137>/Switch' : Eliminated due to constant selection input
 * Block '<S135>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S141>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S141>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S141>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S141>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S141>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S144>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S144>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S144>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S147>/Switch' : Eliminated due to constant selection input
 * Block '<S147>/Switch1' : Eliminated due to constant selection input
 * Block '<S160>/Reshape' : Reshape block reduction
 * Block '<S165>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S159>/Switch' : Eliminated due to constant selection input
 * Block '<S171>/Reshape' : Reshape block reduction
 * Block '<S176>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S170>/Switch' : Eliminated due to constant selection input
 * Block '<S183>/Switch' : Eliminated due to constant selection input
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
 * '<S8>'   : 'Plant/Actuators/Bus_Selection'
 * '<S9>'   : 'Plant/Actuators/MainMotor Forces and Moments'
 * '<S10>'  : 'Plant/Actuators/Motors Forces and Moments'
 * '<S11>'  : 'Plant/Actuators/Wind_Triangle'
 * '<S12>'  : 'Plant/Actuators/selector'
 * '<S13>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command'
 * '<S14>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients'
 * '<S15>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments'
 * '<S16>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Diff Pressure'
 * '<S17>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/nonunit value'
 * '<S18>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/aileron_cmd'
 * '<S19>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/elevator_cmd'
 * '<S20>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/rudder_cmd'
 * '<S21>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments'
 * '<S22>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Basic Coefficients'
 * '<S23>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Coeff_Decay'
 * '<S24>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body axis forces'
 * '<S25>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping'
 * '<S26>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/aileron'
 * '<S27>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/elevator'
 * '<S28>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/rudder'
 * '<S29>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/p'
 * '<S30>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/q'
 * '<S31>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/r'
 * '<S32>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces'
 * '<S33>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product'
 * '<S34>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product/Subsystem'
 * '<S35>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments/Moments about CG  due to Forces/Cross Product/Subsystem1'
 * '<S36>'  : 'Plant/Actuators/MainMotor Forces and Moments/ESCs'
 * '<S37>'  : 'Plant/Actuators/MainMotor Forces and Moments/Force'
 * '<S38>'  : 'Plant/Actuators/MainMotor Forces and Moments/ESCs/Rotor_Delay'
 * '<S39>'  : 'Plant/Actuators/MainMotor Forces and Moments/ESCs/Rotor_Speed'
 * '<S40>'  : 'Plant/Actuators/MainMotor Forces and Moments/ESCs/Rotor_Speed/Compare To Constant'
 * '<S41>'  : 'Plant/Actuators/MainMotor Forces and Moments/Force/Rotor_Thrust'
 * '<S42>'  : 'Plant/Actuators/Motors Forces and Moments/ESCs'
 * '<S43>'  : 'Plant/Actuators/Motors Forces and Moments/Force'
 * '<S44>'  : 'Plant/Actuators/Motors Forces and Moments/Torque'
 * '<S45>'  : 'Plant/Actuators/Motors Forces and Moments/ESCs/Rotor_Delay'
 * '<S46>'  : 'Plant/Actuators/Motors Forces and Moments/ESCs/Rotor_Speed'
 * '<S47>'  : 'Plant/Actuators/Motors Forces and Moments/ESCs/Rotor_Speed/Compare To Constant'
 * '<S48>'  : 'Plant/Actuators/Motors Forces and Moments/Force/Rotor_Thrust'
 * '<S49>'  : 'Plant/Actuators/Motors Forces and Moments/Torque/Gyroscopic_Torque'
 * '<S50>'  : 'Plant/Actuators/Motors Forces and Moments/Torque/Rotor_Torque'
 * '<S51>'  : 'Plant/Actuators/Motors Forces and Moments/Torque/Gyroscopic_Torque/Cross Product'
 * '<S52>'  : 'Plant/Actuators/Motors Forces and Moments/Torque/Gyroscopic_Torque/Cross Product/Subsystem'
 * '<S53>'  : 'Plant/Actuators/Motors Forces and Moments/Torque/Gyroscopic_Torque/Cross Product/Subsystem1'
 * '<S54>'  : 'Plant/Actuators/Wind_Triangle/Attack_Angle'
 * '<S55>'  : 'Plant/Actuators/Wind_Triangle/Slide_Angle'
 * '<S56>'  : 'Plant/Actuators/Wind_Triangle/Slide_Angle/Vector Modulus'
 * '<S57>'  : 'Plant/Bus_Constructor/Counter'
 * '<S58>'  : 'Plant/Bus_Constructor/Quaternion To DCM'
 * '<S59>'  : 'Plant/Bus_Constructor/WGS84'
 * '<S60>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize'
 * '<S61>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_1'
 * '<S62>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_2'
 * '<S63>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_3'
 * '<S64>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S65>'  : 'Plant/Bus_Constructor/WGS84/WGS84_Derivative'
 * '<S66>'  : 'Plant/Bus_Constructor/WGS84/Zero_Value_Exclusion'
 * '<S67>'  : 'Plant/Environment/Aerodynamic'
 * '<S68>'  : 'Plant/Environment/Collision_Response'
 * '<S69>'  : 'Plant/Environment/Compare To Zero'
 * '<S70>'  : 'Plant/Environment/Detect Increase'
 * '<S71>'  : 'Plant/Environment/External_Torque_Force'
 * '<S72>'  : 'Plant/Environment/Gravity'
 * '<S73>'  : 'Plant/Environment/SImple_Ground_Model'
 * '<S74>'  : 'Plant/Environment/Total_Reponse_Force'
 * '<S75>'  : 'Plant/Environment/Vector Modulus'
 * '<S76>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S77>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM'
 * '<S78>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM/Rotation Matrix Z'
 * '<S79>'  : 'Plant/Environment/Collision_Response/Compare To Zero'
 * '<S80>'  : 'Plant/Environment/Collision_Response/Compare To Zero1'
 * '<S81>'  : 'Plant/Environment/Collision_Response/Friction_Response'
 * '<S82>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction'
 * '<S83>'  : 'Plant/Environment/Collision_Response/Vector Normalize'
 * '<S84>'  : 'Plant/Environment/Collision_Response/Friction_Response/Vector Modulus'
 * '<S85>'  : 'Plant/Environment/Collision_Response/Friction_Response/Vector Normalize'
 * '<S86>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product'
 * '<S87>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product1'
 * '<S88>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product2'
 * '<S89>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product/Subsystem'
 * '<S90>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product/Subsystem1'
 * '<S91>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product1/Subsystem'
 * '<S92>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product1/Subsystem1'
 * '<S93>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product2/Subsystem'
 * '<S94>'  : 'Plant/Environment/Collision_Response/Impulse_Reaction/Cross Product2/Subsystem1'
 * '<S95>'  : 'Plant/Environment/SImple_Ground_Model/Compare To Zero'
 * '<S96>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force'
 * '<S97>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Torque'
 * '<S98>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force/Compare To Constant'
 * '<S99>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force/Compare To Constant1'
 * '<S100>' : 'Plant/Environment/Total_Reponse_Force/Compare To Zero'
 * '<S101>' : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S102>' : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S103>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S104>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S105>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S106>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S107>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S108>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S109>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S110>' : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S111>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S112>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S113>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S114>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S115>' : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S116>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S117>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S118>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S119>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S120>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S121>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S122>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S123>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S124>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S125>' : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S126>' : 'Plant/Sensor_Model/Counter'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_Airspeed'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_Airspeed/Airspeed'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_Airspeed/Bus_Constructor'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S149>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S150>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S151>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S152>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S153>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S154>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S155>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S156>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S157>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S158>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S159>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S160>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S161>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S162>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S163>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S164>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S165>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S166>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S167>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S168>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S169>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S170>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S171>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S172>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S173>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S174>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S175>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S176>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S177>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S178>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S179>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S180>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S181>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S182>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S183>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S184>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S185>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S186>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S187>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S188>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S189>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
