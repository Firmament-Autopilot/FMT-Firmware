/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar  8 09:30:38 2023
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
  GPS_uBlox_Bus RateTransition;        /* '<S102>/Rate Transition' */
  MAG_Bus RateTransition_l;            /* '<S140>/Rate Transition' */
  Barometer_Bus RateTransition_p;      /* '<S96>/Rate Transition' */
  AirSpeed_Bus RateTransition_e;       /* '<S94>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S107>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S112>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[3];             /* '<S44>/Delay1' */
  real_T Delay_DSTATE_f[3];            /* '<S44>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S137>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];/* '<S126>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S132>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[4];/* '<S121>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_j[150];       /* '<S107>/Delay1' */
  real32_T DiscreteFIRFilter_states_i[3];/* '<S113>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S64>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S59>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b[3];/* '<S60>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S60>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[2];/* '<S35>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_h;             /* '<S42>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S87>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S150>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S150>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_h[3];/* '<S128>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f[6];/* '<S128>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_e[3];/* '<S139>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_p[6];/* '<S139>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_a[3];/* '<S110>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_f2[6];/* '<S110>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S110>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S110>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_fn[2];/* '<S101>/Random Source' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S64>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S59>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S60>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S60>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S137>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;/* '<S126>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S64>/Discrete-Time Integrator' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S114>/Sum' */
  const real_T ff;                     /* '<S114>/Multiply3' */
  const real_T Sum4;                   /* '<S114>/Sum4' */
  const real_T Subtract1;              /* '<S50>/Subtract1' */
  const real_T Product1;               /* '<S50>/Product1' */
  const real_T Sum_k[3];               /* '<S28>/Sum' */
  const real32_T Add[9];               /* '<S149>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S148>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_e[3];/* '<S147>/Vector Concatenate3' */
  const real32_T Add_g[9];             /* '<S127>/Add' */
  const real32_T Add_k[9];             /* '<S138>/Add' */
  const real32_T Gain[3];              /* '<S62>/Gain' */
  const real32_T cr;                   /* '<S62>/Cos' */
  const real32_T cp;                   /* '<S62>/Cos1' */
  const real32_T cy;                   /* '<S62>/Cos2' */
  const real32_T Multiply;             /* '<S62>/Multiply' */
  const real32_T sr;                   /* '<S62>/Sin' */
  const real32_T sp;                   /* '<S62>/Sin1' */
  const real32_T sy;                   /* '<S62>/Sin2' */
  const real32_T Multiply1;            /* '<S62>/Multiply1' */
  const real32_T Add_d;                /* '<S62>/Add' */
  const real32_T Multiply4;            /* '<S62>/Multiply4' */
  const real32_T Multiply5;            /* '<S62>/Multiply5' */
  const real32_T Add1;                 /* '<S62>/Add1' */
  const real32_T Multiply2;            /* '<S62>/Multiply2' */
  const real32_T Multiply3;            /* '<S62>/Multiply3' */
  const real32_T Subtract;             /* '<S62>/Subtract' */
  const real32_T Multiply6;            /* '<S62>/Multiply6' */
  const real32_T Multiply7;            /* '<S62>/Multiply7' */
  const real32_T Subtract1_e;          /* '<S62>/Subtract1' */
  const real32_T TmpSignalConversionAtSquare[4];
  const real32_T Square[4];            /* '<S68>/Square' */
  const real32_T SumofElements;        /* '<S68>/Sum of Elements' */
  const real32_T Sqrt;                 /* '<S68>/Sqrt' */
  const real32_T Divide[4];            /* '<S67>/Divide' */
  const uint8_T DataTypeConversion;    /* '<S102>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S102>/Data Type Conversion1' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S22>/CD'
   *   '<S22>/CY'
   *   '<S22>/Cl'
   *   '<S22>/Cn'
   *   '<S23>/CD'
   *   '<S23>/CL'
   *   '<S23>/Cm'
   */
  real_T pooled5[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S19>/CD_beta'
   *   '<S19>/CL_beta'
   *   '<S19>/CY_basic'
   *   '<S19>/Cl_basic'
   *   '<S19>/Cm_beta'
   *   '<S19>/Cn_basic'
   *   '<S22>/CD'
   *   '<S22>/CY'
   *   '<S22>/Cl'
   *   '<S22>/Cn'
   *   '<S23>/CD'
   *   '<S23>/CL'
   *   '<S23>/Cm'
   *   '<S24>/CD_dr'
   *   '<S24>/CY_dr'
   *   '<S24>/Cn_dr'
   */
  real_T pooled6[6];

  /* Expression: ada.CD
   * Referenced by: '<S22>/CD'
   */
  real_T CD_Table[42];

  /* Expression: ada.CY
   * Referenced by: '<S22>/CY'
   */
  real_T CY_Table[42];

  /* Expression: ada.Cl
   * Referenced by: '<S22>/Cl'
   */
  real_T Cl_Table[42];

  /* Expression: ada.Cn
   * Referenced by: '<S22>/Cn'
   */
  real_T Cn_Table[42];

  /* Expression: ade.CD
   * Referenced by: '<S23>/CD'
   */
  real_T CD_Table_e[42];

  /* Expression: ade.CL
   * Referenced by: '<S23>/CL'
   */
  real_T CL_Table[42];

  /* Expression: ade.Cm
   * Referenced by: '<S23>/Cm'
   */
  real_T Cm_Table[42];

  /* Pooled Parameter (Expression: adr.dd)
   * Referenced by:
   *   '<S24>/CD_dr'
   *   '<S24>/CY_dr'
   *   '<S24>/Cn_dr'
   */
  real_T pooled8[9];

  /* Expression: adr.CD
   * Referenced by: '<S24>/CD_dr'
   */
  real_T CD_dr_Table[54];

  /* Expression: adr.CY
   * Referenced by: '<S24>/CY_dr'
   */
  real_T CY_dr_Table[54];

  /* Expression: adr.Cn
   * Referenced by: '<S24>/Cn_dr'
   */
  real_T Cn_dr_Table[54];

  /* Pooled Parameter (Expression: alat.beta)
   * Referenced by:
   *   '<S19>/CD_beta'
   *   '<S19>/CL_beta'
   *   '<S19>/CY_basic'
   *   '<S19>/Cl_basic'
   *   '<S19>/Cm_beta'
   *   '<S19>/Cn_basic'
   */
  real_T pooled9[7];

  /* Expression: alat.CY
   * Referenced by: '<S19>/CY_basic'
   */
  real_T CY_basic_Table[42];

  /* Expression: alat.Cl
   * Referenced by: '<S19>/Cl_basic'
   */
  real_T Cl_basic_Table[42];

  /* Expression: alat.Cn
   * Referenced by: '<S19>/Cn_basic'
   */
  real_T Cn_basic_Table[42];

  /* Pooled Parameter (Expression: alon.alpha)
   * Referenced by:
   *   '<S19>/CD_basic'
   *   '<S19>/CL_basic'
   *   '<S19>/Cm_basic'
   */
  real_T pooled10[23];

  /* Expression: alon.CL
   * Referenced by: '<S19>/CL_basic'
   */
  real_T CL_basic_YData[23];

  /* Expression: alat.CL
   * Referenced by: '<S19>/CL_beta'
   */
  real_T CL_beta_Table[42];

  /* Expression: alon.CD
   * Referenced by: '<S19>/CD_basic'
   */
  real_T CD_basic_YData[23];

  /* Expression: alat.CD
   * Referenced by: '<S19>/CD_beta'
   */
  real_T CD_beta_Table[42];

  /* Expression: alon.Cm
   * Referenced by: '<S19>/Cm_basic'
   */
  real_T Cm_basic_YData[23];

  /* Expression: alat.Cm
   * Referenced by: '<S19>/Cm_beta'
   */
  real_T Cm_beta_Table[42];

  /* Pooled Parameter (Expression: adyn.alpha)
   * Referenced by:
   *   '<S25>/CYp'
   *   '<S25>/Clp'
   *   '<S25>/Cnp'
   *   '<S26>/CLq'
   *   '<S26>/Cmq'
   *   '<S27>/CYr'
   *   '<S27>/Clr'
   *   '<S27>/Cnr'
   */
  real_T pooled11[5];

  /* Expression: adyn.CYp
   * Referenced by: '<S25>/CYp'
   */
  real_T CYp_YData[5];

  /* Expression: adyn.Clp
   * Referenced by: '<S25>/Clp'
   */
  real_T Clp_YData[5];

  /* Expression: adyn.Cnp
   * Referenced by: '<S25>/Cnp'
   */
  real_T Cnp_YData[5];

  /* Expression: adyn.CLq
   * Referenced by: '<S26>/CLq'
   */
  real_T CLq_YData[5];

  /* Expression: adyn.Cmq
   * Referenced by: '<S26>/Cmq'
   */
  real_T Cmq_YData[5];

  /* Expression: adyn.CYr
   * Referenced by: '<S27>/CYr'
   */
  real_T CYr_YData[5];

  /* Expression: adyn.Clr
   * Referenced by: '<S27>/Clr'
   */
  real_T Clr_YData[5];

  /* Expression: adyn.Cnr
   * Referenced by: '<S27>/Cnr'
   */
  real_T Cnr_YData[5];

  /* Expression: gain
   * Referenced by: '<S121>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<S60>/Constant'
   *   '<S60>/Discrete-Time Integrator'
   *   '<S60>/Discrete-Time Integrator1'
   *   '<S34>/Constant'
   *   '<S34>/Constant1'
   *   '<S54>/Constant'
   *   '<S56>/Constant'
   *   '<S35>/Discrete-Time Integrator'
   *   '<S36>/Saturation1'
   *   '<S71>/Constant'
   *   '<S71>/Constant1'
   *   '<S71>/Constant2'
   *   '<S71>/Constant3'
   *   '<S104>/Saturation'
   *   '<S107>/Delay1'
   *   '<S99>/Limit  altitude  to Stratosphere'
   *   '<S99>/Limit  altitude  to troposhere'
   *   '<S100>/Constant3'
   *   '<S101>/Random Source'
   *   '<S110>/Random Source'
   *   '<S110>/Random Source1'
   *   '<S113>/Discrete FIR Filter'
   *   '<S128>/Random Source'
   *   '<S139>/Random Source'
   *   '<S150>/Random Source'
   *   '<S147>/Constant'
   *   '<S147>/Constant2'
   *   '<S147>/Constant3'
   *   '<S147>/Constant4'
   *   '<S148>/Constant1'
   *   '<S148>/Constant2'
   *   '<S148>/Constant3'
   *   '<S148>/Constant4'
   */
  real32_T pooled27;

  /* Computed Parameter: Inertia_Matrix_Value
   * Referenced by: '<S59>/Inertia_Matrix'
   */
  real32_T Inertia_Matrix_Value[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S144>/Saturation'
   *   '<S101>/Random Source'
   */
  real32_T pooled34;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S110>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S110>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_h
   * Referenced by: '<S128>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_h[3];

  /* Computed Parameter: RandomSource_VarianceRTP_o
   * Referenced by: '<S139>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_o[3];

  /* Expression: wmm_declination
   * Referenced by: '<S145>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S145>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S145>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_om
   * Referenced by: '<S150>/Random Source'
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
                                                   *   '<S87>/dt'
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
 * Block '<S99>/Product' : Unused code path elimination
 * Block '<S99>/Product3' : Unused code path elimination
 * Block '<S99>/a' : Unused code path elimination
 * Block '<S99>/gamma*R' : Unused code path elimination
 * Block '<S99>/rho0' : Unused code path elimination
 * Block '<S1>/Reshape' : Reshape block reduction
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S42>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S55>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S55>/Reshape' : Reshape block reduction
 * Block '<S56>/Reshape1' : Reshape block reduction
 * Block '<S87>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S98>/Switch' : Eliminated due to constant selection input
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S102>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S102>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S102>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S102>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S105>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S105>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S105>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S108>/Switch' : Eliminated due to constant selection input
 * Block '<S108>/Switch1' : Eliminated due to constant selection input
 * Block '<S121>/Reshape' : Reshape block reduction
 * Block '<S126>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S120>/Switch' : Eliminated due to constant selection input
 * Block '<S132>/Reshape' : Reshape block reduction
 * Block '<S137>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S131>/Switch' : Eliminated due to constant selection input
 * Block '<S144>/Switch' : Eliminated due to constant selection input
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
 * '<S3>'   : 'Plant/Environment'
 * '<S4>'   : 'Plant/Kinematic_Equation'
 * '<S5>'   : 'Plant/Sensor_Model'
 * '<S6>'   : 'Plant/Actuators/Aerodynamics Forces and Moments'
 * '<S7>'   : 'Plant/Actuators/Propulsion Forces and Moments'
 * '<S8>'   : 'Plant/Actuators/Wind_Triangle'
 * '<S9>'   : 'Plant/Actuators/selector'
 * '<S10>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command'
 * '<S11>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients'
 * '<S12>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments1'
 * '<S13>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Diff Pressure'
 * '<S14>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/nonunit value'
 * '<S15>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/aileron_cmd'
 * '<S16>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/elevator_cmd'
 * '<S17>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Actuator Command/rudder_cmd'
 * '<S18>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments'
 * '<S19>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Basic Coefficients'
 * '<S20>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body axis forces'
 * '<S21>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping'
 * '<S22>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/aileron'
 * '<S23>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/elevator'
 * '<S24>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/Actuator increments/rudder'
 * '<S25>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/p'
 * '<S26>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/q'
 * '<S27>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Coefficients/body rate damping/r'
 * '<S28>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments1/Moments about CG  due to Forces'
 * '<S29>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments1/Moments about CG  due to Forces1'
 * '<S30>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments1/Moments about CG  due to Forces/Cross Product'
 * '<S31>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments1/Moments about CG  due to Forces/Cross Product/Subsystem'
 * '<S32>'  : 'Plant/Actuators/Aerodynamics Forces and Moments/Aerodynamic Forces and Moments1/Moments about CG  due to Forces/Cross Product/Subsystem1'
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
 * '<S52>'  : 'Plant/Environment/Gravity'
 * '<S53>'  : 'Plant/Environment/Ground_Model'
 * '<S54>'  : 'Plant/Environment/Ground_Model/Compare To Zero'
 * '<S55>'  : 'Plant/Environment/Ground_Model/Ground_Force'
 * '<S56>'  : 'Plant/Environment/Ground_Model/Ground_Torque'
 * '<S57>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant'
 * '<S58>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant1'
 * '<S59>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S60>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S61>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S62>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion'
 * '<S63>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S64>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S65>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S66>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S67>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion/Quaternion Normalize'
 * '<S68>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion/Quaternion Normalize/Quaternion Modulus'
 * '<S69>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S70>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S71>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S72>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S73>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S74>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S75>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S76>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S77>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S78>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S79>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S80>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S81>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S82>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S83>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S84>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S85>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S86>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S87>'  : 'Plant/Sensor_Model/Counter'
 * '<S88>'  : 'Plant/Sensor_Model/Sensor_Airspeed'
 * '<S89>'  : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_Airspeed/Airspeed'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_Airspeed/Bus_Constructor'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S149>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S150>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
