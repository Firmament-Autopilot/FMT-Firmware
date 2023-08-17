/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.763
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 17 14:39:34 2023
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
  GPS_uBlox_Bus RateTransition;        /* '<S79>/Rate Transition' */
  MAG_Bus RateTransition_b;            /* '<S117>/Rate Transition' */
  Barometer_Bus RateTransition_m;      /* '<S73>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S84>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S89>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[3];             /* '<S23>/Delay1' */
  real_T Delay_DSTATE_a[3];            /* '<S23>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S114>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S103>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S109>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[4];/* '<S98>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_a[150];       /* '<S84>/Delay1' */
  real32_T DiscreteFIRFilter_states_f[3];/* '<S90>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[4];/* '<S46>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e[3];/* '<S42>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[3];/* '<S43>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S43>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_n[4];/* '<S12>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_c;             /* '<S21>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S67>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S127>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S127>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_f[3];/* '<S105>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_k[6];/* '<S105>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_n[3];/* '<S116>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_h[6];/* '<S116>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_m[3];/* '<S87>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_l[6];/* '<S87>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S87>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S87>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_b[2];/* '<S78>/Random Source' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S46>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S42>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S43>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S43>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S114>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_j;/* '<S103>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S91>/Sum' */
  const real_T ff;                     /* '<S91>/Multiply3' */
  const real_T Sum4;                   /* '<S91>/Sum4' */
  const real_T Subtract1;              /* '<S29>/Subtract1' */
  const real_T Product1;               /* '<S29>/Product1' */
  const real32_T Add[9];               /* '<S126>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S125>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_a[3];/* '<S124>/Vector Concatenate3' */
  const real32_T Add_m[9];             /* '<S104>/Add' */
  const real32_T Add_g[9];             /* '<S115>/Add' */
  const real32_T quat0[4];             /* '<S42>/quat0' */
  const real32_T VectorConcatenate3_e[3];/* '<S36>/Vector Concatenate3' */
  const uint8_T DataTypeConversion;    /* '<S79>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S79>/Data Type Conversion1' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: gain
   * Referenced by: '<S98>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Computed Parameter: X_Frame_CM_Value
   * Referenced by: '<S17>/X_Frame_CM'
   */
  real32_T X_Frame_CM_Value[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<S43>/Constant'
   *   '<S10>/Constant'
   *   '<S10>/Constant1'
   *   '<S37>/Constant'
   *   '<S39>/Constant'
   *   '<S12>/Discrete-Time Integrator'
   *   '<S13>/Saturation1'
   *   '<S51>/Constant'
   *   '<S51>/Constant1'
   *   '<S51>/Constant2'
   *   '<S51>/Constant3'
   *   '<S81>/Saturation'
   *   '<S84>/Delay1'
   *   '<S36>/Constant1'
   *   '<S36>/Constant2'
   *   '<S36>/Constant3'
   *   '<S36>/Constant4'
   *   '<S76>/Limit  altitude  to Stratosphere'
   *   '<S76>/Limit  altitude  to troposhere'
   *   '<S77>/Constant3'
   *   '<S78>/Random Source'
   *   '<S87>/Random Source'
   *   '<S87>/Random Source1'
   *   '<S90>/Discrete FIR Filter'
   *   '<S105>/Random Source'
   *   '<S116>/Random Source'
   *   '<S127>/Random Source'
   *   '<S124>/Constant'
   *   '<S124>/Constant2'
   *   '<S124>/Constant3'
   *   '<S124>/Constant4'
   *   '<S125>/Constant1'
   *   '<S125>/Constant2'
   *   '<S125>/Constant3'
   *   '<S125>/Constant4'
   */
  real32_T pooled14;

  /* Computed Parameter: Inertia_Matrix_Value
   * Referenced by: '<S42>/Inertia_Matrix'
   */
  real32_T Inertia_Matrix_Value[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S121>/Saturation'
   *   '<S78>/Random Source'
   */
  real32_T pooled25;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S87>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S87>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_f
   * Referenced by: '<S105>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_f[3];

  /* Computed Parameter: RandomSource_VarianceRTP_b
   * Referenced by: '<S116>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_b[3];

  /* Expression: wmm_declination
   * Referenced by: '<S122>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S122>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S122>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_a
   * Referenced by: '<S127>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_a[3];
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
extern struct_zjTVXoT1Wcig2PfNqPD1gB PLANT_EXPORT;/* Variable: PLANT_EXPORT
                                                   * Referenced by:
                                                   *   '<S21>/dt'
                                                   *   '<S67>/dt'
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
 * Block '<S76>/Product' : Unused code path elimination
 * Block '<S76>/Product3' : Unused code path elimination
 * Block '<S76>/a' : Unused code path elimination
 * Block '<S76>/gamma*R' : Unused code path elimination
 * Block '<S76>/rho0' : Unused code path elimination
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S38>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S38>/Reshape' : Reshape block reduction
 * Block '<S39>/Reshape1' : Reshape block reduction
 * Block '<S67>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S75>/Switch' : Eliminated due to constant selection input
 * Block '<S73>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S79>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S79>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S79>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S79>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S79>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S82>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S82>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S82>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S85>/Switch' : Eliminated due to constant selection input
 * Block '<S85>/Switch1' : Eliminated due to constant selection input
 * Block '<S98>/Reshape' : Reshape block reduction
 * Block '<S103>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S97>/Switch' : Eliminated due to constant selection input
 * Block '<S109>/Reshape' : Reshape block reduction
 * Block '<S114>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Switch' : Eliminated due to constant selection input
 * Block '<S121>/Switch' : Eliminated due to constant selection input
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
 * '<S7>'   : 'Plant/Actuators/Bus_Selection'
 * '<S8>'   : 'Plant/Actuators/Motors'
 * '<S9>'   : 'Plant/Actuators/Motors/ESCs'
 * '<S10>'  : 'Plant/Actuators/Motors/Force'
 * '<S11>'  : 'Plant/Actuators/Motors/Torque'
 * '<S12>'  : 'Plant/Actuators/Motors/ESCs/Rotor_Delay'
 * '<S13>'  : 'Plant/Actuators/Motors/ESCs/Rotor_Speed'
 * '<S14>'  : 'Plant/Actuators/Motors/ESCs/Rotor_Speed/Compare To Constant'
 * '<S15>'  : 'Plant/Actuators/Motors/Force/Rotor_Thrust'
 * '<S16>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque'
 * '<S17>'  : 'Plant/Actuators/Motors/Torque/Rotor_Torque'
 * '<S18>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/Cross Product'
 * '<S19>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/Cross Product/Subsystem'
 * '<S20>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/Cross Product/Subsystem1'
 * '<S21>'  : 'Plant/Bus_Constructor/Counter'
 * '<S22>'  : 'Plant/Bus_Constructor/Quaternion To DCM'
 * '<S23>'  : 'Plant/Bus_Constructor/WGS84'
 * '<S24>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize'
 * '<S25>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_1'
 * '<S26>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_2'
 * '<S27>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_3'
 * '<S28>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S29>'  : 'Plant/Bus_Constructor/WGS84/WGS84_Derivative'
 * '<S30>'  : 'Plant/Bus_Constructor/WGS84/Zero_Value_Exclusion'
 * '<S31>'  : 'Plant/Environment/Aerodynamic'
 * '<S32>'  : 'Plant/Environment/Gravity'
 * '<S33>'  : 'Plant/Environment/Ground_Model'
 * '<S34>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S35>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM'
 * '<S36>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM/Rotation Matrix Z'
 * '<S37>'  : 'Plant/Environment/Ground_Model/Compare To Zero'
 * '<S38>'  : 'Plant/Environment/Ground_Model/Ground_Force'
 * '<S39>'  : 'Plant/Environment/Ground_Model/Ground_Torque'
 * '<S40>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant'
 * '<S41>'  : 'Plant/Environment/Ground_Model/Ground_Force/Compare To Constant1'
 * '<S42>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S43>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S44>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S45>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S46>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S47>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S48>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S49>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S50>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S51>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S52>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S53>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S54>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S55>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S56>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S57>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S58>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S59>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S60>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S61>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S62>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S63>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S64>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S65>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S66>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S67>'  : 'Plant/Sensor_Model/Counter'
 * '<S68>'  : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S69>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S70>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S71>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S72>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S73>'  : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S74>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S75>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S76>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S77>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S78>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S79>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S80>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S81>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S82>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S83>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S84>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S85>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S86>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S87>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S88>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S89>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
