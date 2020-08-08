/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.455
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug  5 17:18:29 2020
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

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  GPS_uBlox_Bus RateTransition;        /* '<S63>/Rate Transition' */
  MAG_Bus RateTransition_b;            /* '<S110>/Rate Transition' */
  Barometer_Bus RateTransition_m;      /* '<S57>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[3];             /* '<S24>/Delay1' */
  real_T Delay_DSTATE[3];              /* '<S24>/Delay' */
  real_T w_z_int_PRot_P_err_radDs_DSTATE[3];/* '<S97>/w_z_int_PRot_P_err_radDs' */
  real_T w_z_int_PRot_P_err_radDs_DSTA_a[3];/* '<S96>/w_z_int_PRot_P_err_radDs' */
  real_T Delay_DSTATE_b[225];          /* '<S65>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S73>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S36>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e[3];/* '<S34>/Discrete-Time Integrator' */
  real32_T DiscreteFilter_states[4];   /* '<S10>/Discrete Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[3];/* '<S35>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S35>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_h[3];/* '<S106>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S106>/Discrete-Time Integrator2' */
  real32_T Delay1_DSTATE_a[150];       /* '<S65>/Delay1' */
  real32_T DiscreteFIRFilter_states_f[3];/* '<S74>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_a[4];/* '<S103>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[4];/* '<S87>/Discrete-Time Integrator' */
  uint32_T Memory1_PreviousInput;      /* '<S22>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S109>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S109>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_f[3];/* '<S93>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_k[6];/* '<S93>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_b[3];/* '<S122>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_j[6];/* '<S122>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_b[2];/* '<S59>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_m[3];/* '<S69>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_l[6];/* '<S69>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S69>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S69>/Random Source1' */
  uint32_T Memory1_PreviousInput_e;    /* '<S52>/Memory1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S36>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S34>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S35>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S35>/Discrete-Time Integrator1' */
  int8_T w_z_int_PRot_P_err_radDs_PrevRe;/* '<S97>/w_z_int_PRot_P_err_radDs' */
  int8_T w_z_int_PRot_P_err_radDs_Prev_d;/* '<S96>/w_z_int_PRot_P_err_radDs' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Subtract1;              /* '<S25>/Subtract1' */
  const real_T e_2;                    /* '<S25>/Product1' */
  const real_T Constant3;              /* '<S95>/Constant3' */
  const real_T Constant3_m;            /* '<S94>/Constant3' */
  const real_T Subtract1_j;            /* '<S78>/Subtract1' */
  const real_T e_2_c;                  /* '<S78>/Product1' */
  const real_T Gain6[4];               /* '<S103>/Gain6' */
  const real_T Divide1[4];             /* '<S103>/Divide1' */
  const real_T Gain6_b[4];             /* '<S87>/Gain6' */
  const real_T Divide1_f[4];           /* '<S87>/Divide1' */
  const real32_T Add[9];               /* '<S121>/Add' */
  const real32_T Add_m[9];             /* '<S92>/Add' */
  const real32_T Add_g[9];             /* '<S108>/Add' */
  const real32_T VecConcentate3[3];    /* '<S9>/VecConcentate3' */
  const real32_T Constant1[4];         /* '<S34>/Constant1' */
  const real32_T VectorConcatenate3[3];/* '<S119>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_l[3];/* '<S118>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S63>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S63>/Data Type Conversion1' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Gain
   * Referenced by: '<S87>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Computed Parameter: X_Frame_Value
   * Referenced by: '<S18>/X_Frame'
   */
  real32_T X_Frame_Value[12];

  /* Computed Parameter: Inertia_Matrix_Value
   * Referenced by: '<S34>/Inertia_Matrix'
   */
  real32_T Inertia_Matrix_Value[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<S35>/Constant'
   *   '<S10>/Discrete Filter'
   *   '<S11>/Constant'
   *   '<S11>/Constant1'
   *   '<S29>/Constant'
   *   '<S31>/Constant'
   *   '<S59>/Random Source'
   *   '<S65>/Delay1'
   *   '<S9>/Constant1'
   *   '<S13>/Saturation1'
   *   '<S39>/Constant'
   *   '<S39>/Constant1'
   *   '<S39>/Constant2'
   *   '<S39>/Constant3'
   *   '<S60>/Limit  altitude  to Stratosphere'
   *   '<S60>/Limit  altitude  to troposhere'
   *   '<S62>/Constant3'
   *   '<S67>/Saturation'
   *   '<S69>/Random Source'
   *   '<S69>/Random Source1'
   *   '<S74>/Discrete FIR Filter'
   *   '<S93>/Random Source'
   *   '<S106>/Discrete-Time Integrator1'
   *   '<S106>/Discrete-Time Integrator2'
   *   '<S109>/Random Source'
   *   '<S122>/Random Source'
   *   '<S118>/Constant'
   *   '<S118>/Constant2'
   *   '<S118>/Constant3'
   *   '<S118>/Constant4'
   *   '<S119>/Constant1'
   *   '<S119>/Constant2'
   *   '<S119>/Constant3'
   *   '<S119>/Constant4'
   */
  real32_T pooled27;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S109>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_f
   * Referenced by: '<S93>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_f[3];

  /* Computed Parameter: RandomSource_VarianceRTP_a
   * Referenced by: '<S122>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_a[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S59>/Random Source'
   *   '<S114>/Saturation'
   */
  real32_T pooled32;

  /* Computed Parameter: RandomSource_VarianceRTP_b
   * Referenced by: '<S69>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_b[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S69>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: DeclinationLookup_table
   * Referenced by: '<S117>/Declination Lookup'
   */
  int16_T DeclinationLookup_table[629];

  /* Computed Parameter: InclinationLookup_table
   * Referenced by: '<S117>/Inclination Lookup'
   */
  int8_T InclinationLookup_table[629];

  /* Computed Parameter: MagnitudeLookup_table
   * Referenced by: '<S117>/Magnitude Lookup'
   */
  uint8_T MagnitudeLookup_table[629];
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
  GPS_uBlox_Bus GPS_uBlox;             /* '<Root>/GPS_uBlox' */
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
      uint8_T TID[3];
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
extern struct_4XfCoaAMTej5uH3d8u88xB PLANT_EXPORT;/* Variable: PLANT_EXPORT
                                                   * Referenced by:
                                                   *   '<S22>/dt'
                                                   *   '<S52>/dt'
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
 * Block '<S60>/Product' : Unused code path elimination
 * Block '<S60>/Product3' : Unused code path elimination
 * Block '<S60>/a' : Unused code path elimination
 * Block '<S60>/gamma*R' : Unused code path elimination
 * Block '<S60>/rho0' : Unused code path elimination
 * Block '<S117>/Scope' : Unused code path elimination
 * Block '<S117>/dec_deg' : Unused code path elimination
 * Block '<S117>/inc_degg' : Unused code path elimination
 * Block '<S117>/mag_uT' : Unused code path elimination
 * Block '<S22>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S30>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S30>/Reshape' : Reshape block reduction
 * Block '<S31>/Reshape1' : Reshape block reduction
 * Block '<S52>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Switch' : Eliminated due to constant selection input
 * Block '<S63>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S63>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S63>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S63>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S63>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S66>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S66>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S66>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S70>/Switch' : Eliminated due to constant selection input
 * Block '<S71>/Switch' : Eliminated due to constant selection input
 * Block '<S87>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S87>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S87>/Reshape' : Reshape block reduction
 * Block '<S90>/Switch' : Eliminated due to constant selection input
 * Block '<S103>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S103>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S103>/Reshape' : Reshape block reduction
 * Block '<S107>/Switch' : Eliminated due to constant selection input
 * Block '<S120>/Switch' : Eliminated due to constant selection input
 * Block '<S114>/Signal Conversion1' : Unused code path elimination
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
 * '<S2>'   : 'Plant/Bus_Assignment'
 * '<S3>'   : 'Plant/Environment'
 * '<S4>'   : 'Plant/Kinematic_Equation'
 * '<S5>'   : 'Plant/Sensor_Model'
 * '<S6>'   : 'Plant/Actuators/Aerodynamic'
 * '<S7>'   : 'Plant/Actuators/Motors'
 * '<S8>'   : 'Plant/Actuators/Aerodynamic/Air_Drag'
 * '<S9>'   : 'Plant/Actuators/Aerodynamic/Air_Drag/M_CO'
 * '<S10>'  : 'Plant/Actuators/Motors/ESCs'
 * '<S11>'  : 'Plant/Actuators/Motors/Force'
 * '<S12>'  : 'Plant/Actuators/Motors/Torque'
 * '<S13>'  : 'Plant/Actuators/Motors/ESCs/Calculate_Rotor_Speed'
 * '<S14>'  : 'Plant/Actuators/Motors/ESCs/Signal_Unified'
 * '<S15>'  : 'Plant/Actuators/Motors/ESCs/Calculate_Rotor_Speed/Compare To Constant'
 * '<S16>'  : 'Plant/Actuators/Motors/Force/Thrust'
 * '<S17>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque'
 * '<S18>'  : 'Plant/Actuators/Motors/Torque/Rotor_Generated_Torque'
 * '<S19>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/cross_product'
 * '<S20>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/cross_product/Subsystem'
 * '<S21>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/cross_product/Subsystem1'
 * '<S22>'  : 'Plant/Bus_Assignment/Counter'
 * '<S23>'  : 'Plant/Bus_Assignment/Quat_to_M_OB'
 * '<S24>'  : 'Plant/Bus_Assignment/WGS84'
 * '<S25>'  : 'Plant/Bus_Assignment/WGS84/WGS84_Derivatives'
 * '<S26>'  : 'Plant/Bus_Assignment/WGS84/Zero_Value_Exclusion'
 * '<S27>'  : 'Plant/Environment/Gravity'
 * '<S28>'  : 'Plant/Environment/Ground_Model'
 * '<S29>'  : 'Plant/Environment/Ground_Model/Compare To Zero'
 * '<S30>'  : 'Plant/Environment/Ground_Model/Ground_Force'
 * '<S31>'  : 'Plant/Environment/Ground_Model/Ground_Torque'
 * '<S32>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant'
 * '<S33>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant1'
 * '<S34>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S35>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S36>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S37>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/cross_product'
 * '<S38>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/quat to euler'
 * '<S39>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S40>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/cross_product/Subsystem'
 * '<S41>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/cross_product/Subsystem1'
 * '<S42>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth'
 * '<S43>'  : 'Plant/Kinematic_Equation/Position_Dynamic/cross_product'
 * '<S44>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth/Subsystem'
 * '<S45>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth/Subsystem1'
 * '<S46>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth/Subsystem2'
 * '<S47>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth/quat normalize'
 * '<S48>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth/quat normalize/quat modulus'
 * '<S49>'  : 'Plant/Kinematic_Equation/Position_Dynamic/body to earth/quat normalize/quat modulus/quat norm'
 * '<S50>'  : 'Plant/Kinematic_Equation/Position_Dynamic/cross_product/Subsystem'
 * '<S51>'  : 'Plant/Kinematic_Equation/Position_Dynamic/cross_product/Subsystem1'
 * '<S52>'  : 'Plant/Sensor_Model/Counter'
 * '<S53>'  : 'Plant/Sensor_Model/Sensor_Baro'
 * '<S54>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S55>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S56>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S57>'  : 'Plant/Sensor_Model/Sensor_Baro/Bus_Assignment'
 * '<S58>'  : 'Plant/Sensor_Model/Sensor_Baro/Physical_Model'
 * '<S59>'  : 'Plant/Sensor_Model/Sensor_Baro/Sensor_Model'
 * '<S60>'  : 'Plant/Sensor_Model/Sensor_Baro/Physical_Model/ISA Atmosphere Model'
 * '<S61>'  : 'Plant/Sensor_Model/Sensor_Baro/Sensor_Model/Routing'
 * '<S62>'  : 'Plant/Sensor_Model/Sensor_Baro/Sensor_Model/Sensor_Error'
 * '<S63>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Assignment'
 * '<S64>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model'
 * '<S65>'  : 'Plant/Sensor_Model/Sensor_GPS/Physical_Model'
 * '<S66>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Assignment/WGS84_Position'
 * '<S67>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Assignment/gSpeed_mDs'
 * '<S68>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/Accurancy_Estimate'
 * '<S69>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/GPS_Error'
 * '<S70>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/Routing'
 * '<S71>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/Routing1'
 * '<S72>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/WGS84_Linearization'
 * '<S73>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/pos_filter'
 * '<S74>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/vel_filter'
 * '<S75>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/Accurancy_Estimate/Routing'
 * '<S76>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/Accurancy_Estimate/Routing1'
 * '<S77>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/Accurancy_Estimate/Routing2'
 * '<S78>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS_Model/WGS84_Linearization/WGS84_Linearization'
 * '<S79>'  : 'Plant/Sensor_Model/Sensor_IMU/Bus Assignment'
 * '<S80>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer'
 * '<S81>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope'
 * '<S82>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Bus Assignment'
 * '<S83>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Physical_Model'
 * '<S84>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model'
 * '<S85>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Physical_Model/Routing'
 * '<S86>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Physical_Model/Specific_Force'
 * '<S87>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Physical_Model/Vibration_Model'
 * '<S88>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Physical_Model/prop_vel'
 * '<S89>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Logic'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Lowpass_Filter'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Sensor_Error'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/White Noise'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Lowpass_Filter/Integration'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Lowpass_Filter/Integration1'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Lowpass_Filter/Integration/Integrator_RUN_w_z_int_err_radDs'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Accelerometer/Sensor_Model/Lowpass_Filter/Integration1/Integrator_RUN_w_z_int_err_radDs'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Bus Assignment'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Physical Model'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Sensor Model'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Physical Model/Bus_selection'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Physical Model/Routing'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Physical Model/Vibration_Model'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Physical Model/prop_vel'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Physical Model/Vibration_Model/Compare To Constant1'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Sensor Model/Lowpass_Filter'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Sensor Model/Routing'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Sensor Model/Sensor_Error'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_IMU/Sensor_Gyroscope/Sensor Model/White Noise'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_MAG/Bus Assignment'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Bus Assignment'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Physical Model'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Sensor_Model'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Physical Model/B_B'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Physical Model/Magnetic_Field'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Physical Model/wmm_lookup'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Physical Model/Magnetic_Field/Rot_y to M'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Physical Model/Magnetic_Field/Rot_z to M'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Sensor_Model/Logic'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Sensor_Model/Sensor_Error'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_MAG/Sensor_Magnetometer/Sensor_Model/White_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
