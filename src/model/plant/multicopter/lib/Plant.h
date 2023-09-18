/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.962
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 17 22:56:54 2023
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
  GPS_uBlox_Bus RateTransition;        /* '<S100>/Rate Transition' */
  MAG_Bus RateTransition_b;            /* '<S138>/Rate Transition' */
  Barometer_Bus RateTransition_m;      /* '<S94>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S105>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S110>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[3];             /* '<S25>/Delay1' */
  real_T Delay_DSTATE_a[3];            /* '<S25>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S135>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S124>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S130>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[4];/* '<S119>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_a[150];       /* '<S105>/Delay1' */
  real32_T DiscreteFIRFilter_states_f[3];/* '<S111>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[4];/* '<S67>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e[3];/* '<S63>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[3];/* '<S64>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S64>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_n[4];/* '<S14>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_c;             /* '<S23>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S88>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S148>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S148>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_f[3];/* '<S126>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_k[6];/* '<S126>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_n[3];/* '<S137>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_h[6];/* '<S137>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_m[3];/* '<S108>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_l[6];/* '<S108>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S108>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S108>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_b[2];/* '<S99>/Random Source' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S67>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S63>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S64>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S64>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S135>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_j;/* '<S124>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S112>/Sum' */
  const real_T ff;                     /* '<S112>/Multiply3' */
  const real_T Sum4;                   /* '<S112>/Sum4' */
  const real_T Subtract1;              /* '<S31>/Subtract1' */
  const real_T Product1;               /* '<S31>/Product1' */
  const real32_T Add[9];               /* '<S147>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S146>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_a[3];/* '<S145>/Vector Concatenate3' */
  const real32_T Add_m[9];             /* '<S125>/Add' */
  const real32_T Add_g[9];             /* '<S136>/Add' */
  const real32_T quat0[4];             /* '<S63>/quat0' */
  const real32_T VectorConcatenate3_e[3];/* '<S42>/Vector Concatenate3' */
  const real32_T Add_k;                /* '<S34>/Add' */
  const uint8_T DataTypeConversion;    /* '<S100>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S100>/Data Type Conversion1' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: gain
   * Referenced by: '<S119>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Computed Parameter: X_Frame_CM_Value
   * Referenced by: '<S19>/X_Frame_CM'
   */
  real32_T X_Frame_CM_Value[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<S34>/coefficient'
   *   '<S64>/Constant'
   *   '<S12>/Constant'
   *   '<S12>/Constant1'
   *   '<S43>/Constant'
   *   '<S44>/Constant'
   *   '<S48>/Switch'
   *   '<S49>/Switch'
   *   '<S57>/Constant'
   *   '<S59>/Constant'
   *   '<S62>/Constant'
   *   '<S14>/Discrete-Time Integrator'
   *   '<S15>/Saturation1'
   *   '<S72>/Constant'
   *   '<S72>/Constant1'
   *   '<S72>/Constant2'
   *   '<S72>/Constant3'
   *   '<S102>/Saturation'
   *   '<S105>/Delay1'
   *   '<S42>/Constant1'
   *   '<S42>/Constant2'
   *   '<S42>/Constant3'
   *   '<S42>/Constant4'
   *   '<S97>/Limit  altitude  to Stratosphere'
   *   '<S97>/Limit  altitude  to troposhere'
   *   '<S98>/Constant3'
   *   '<S99>/Random Source'
   *   '<S108>/Random Source'
   *   '<S108>/Random Source1'
   *   '<S111>/Discrete FIR Filter'
   *   '<S126>/Random Source'
   *   '<S137>/Random Source'
   *   '<S148>/Random Source'
   *   '<S145>/Constant'
   *   '<S145>/Constant2'
   *   '<S145>/Constant3'
   *   '<S145>/Constant4'
   *   '<S146>/Constant1'
   *   '<S146>/Constant2'
   *   '<S146>/Constant3'
   *   '<S146>/Constant4'
   */
  real32_T pooled14;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S34>/Inertia_Matrix'
   *   '<S63>/Inertia_Matrix'
   */
  real32_T pooled22[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S142>/Saturation'
   *   '<S99>/Random Source'
   */
  real32_T pooled26;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S108>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S108>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_f
   * Referenced by: '<S126>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_f[3];

  /* Computed Parameter: RandomSource_VarianceRTP_b
   * Referenced by: '<S137>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_b[3];

  /* Expression: wmm_declination
   * Referenced by: '<S143>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S143>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S143>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_a
   * Referenced by: '<S148>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_a[3];
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
                                                   *   '<S23>/dt'
                                                   *   '<S88>/dt'
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
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Compare' : Unused code path elimination
 * Block '<S56>/Constant' : Unused code path elimination
 * Block '<S37>/Dot Product2' : Unused code path elimination
 * Block '<S37>/Multiply' : Unused code path elimination
 * Block '<S37>/Multiply1' : Unused code path elimination
 * Block '<S37>/Multiply2' : Unused code path elimination
 * Block '<S97>/Product' : Unused code path elimination
 * Block '<S97>/Product3' : Unused code path elimination
 * Block '<S97>/a' : Unused code path elimination
 * Block '<S97>/gamma*R' : Unused code path elimination
 * Block '<S97>/rho0' : Unused code path elimination
 * Block '<S23>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S34>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S34>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S58>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S58>/Reshape' : Reshape block reduction
 * Block '<S59>/Reshape1' : Reshape block reduction
 * Block '<S88>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Switch' : Eliminated due to constant selection input
 * Block '<S94>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S100>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S100>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S100>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S100>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S100>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S103>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S103>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S103>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S106>/Switch' : Eliminated due to constant selection input
 * Block '<S106>/Switch1' : Eliminated due to constant selection input
 * Block '<S119>/Reshape' : Reshape block reduction
 * Block '<S124>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S118>/Switch' : Eliminated due to constant selection input
 * Block '<S130>/Reshape' : Reshape block reduction
 * Block '<S135>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Switch' : Eliminated due to constant selection input
 * Block '<S142>/Switch' : Eliminated due to constant selection input
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
 * '<S7>'   : 'Plant/Subsystem'
 * '<S8>'   : 'Plant/Subsystem1'
 * '<S9>'   : 'Plant/Actuators/Bus_Selection'
 * '<S10>'  : 'Plant/Actuators/Motors'
 * '<S11>'  : 'Plant/Actuators/Motors/ESCs'
 * '<S12>'  : 'Plant/Actuators/Motors/Force'
 * '<S13>'  : 'Plant/Actuators/Motors/Torque'
 * '<S14>'  : 'Plant/Actuators/Motors/ESCs/Rotor_Delay'
 * '<S15>'  : 'Plant/Actuators/Motors/ESCs/Rotor_Speed'
 * '<S16>'  : 'Plant/Actuators/Motors/ESCs/Rotor_Speed/Compare To Constant'
 * '<S17>'  : 'Plant/Actuators/Motors/Force/Rotor_Thrust'
 * '<S18>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque'
 * '<S19>'  : 'Plant/Actuators/Motors/Torque/Rotor_Torque'
 * '<S20>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/Cross Product'
 * '<S21>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/Cross Product/Subsystem'
 * '<S22>'  : 'Plant/Actuators/Motors/Torque/Gyroscopic_Torque/Cross Product/Subsystem1'
 * '<S23>'  : 'Plant/Bus_Constructor/Counter'
 * '<S24>'  : 'Plant/Bus_Constructor/Quaternion To DCM'
 * '<S25>'  : 'Plant/Bus_Constructor/WGS84'
 * '<S26>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize'
 * '<S27>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_1'
 * '<S28>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_2'
 * '<S29>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_3'
 * '<S30>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S31>'  : 'Plant/Bus_Constructor/WGS84/WGS84_Derivative'
 * '<S32>'  : 'Plant/Bus_Constructor/WGS84/Zero_Value_Exclusion'
 * '<S33>'  : 'Plant/Environment/Aerodynamic'
 * '<S34>'  : 'Plant/Environment/Collision_Response'
 * '<S35>'  : 'Plant/Environment/External_Torque_Force'
 * '<S36>'  : 'Plant/Environment/Gravity'
 * '<S37>'  : 'Plant/Environment/PreProcess'
 * '<S38>'  : 'Plant/Environment/SImple_Ground_Model'
 * '<S39>'  : 'Plant/Environment/Total_Reponse_Force'
 * '<S40>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S41>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM'
 * '<S42>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM/Rotation Matrix Z'
 * '<S43>'  : 'Plant/Environment/Collision_Response/Compare To Zero'
 * '<S44>'  : 'Plant/Environment/Collision_Response/Compare To Zero1'
 * '<S45>'  : 'Plant/Environment/Collision_Response/Cross Product'
 * '<S46>'  : 'Plant/Environment/Collision_Response/Cross Product1'
 * '<S47>'  : 'Plant/Environment/Collision_Response/Cross Product2'
 * '<S48>'  : 'Plant/Environment/Collision_Response/Vector Normalize'
 * '<S49>'  : 'Plant/Environment/Collision_Response/Vector Normalize1'
 * '<S50>'  : 'Plant/Environment/Collision_Response/Cross Product/Subsystem'
 * '<S51>'  : 'Plant/Environment/Collision_Response/Cross Product/Subsystem1'
 * '<S52>'  : 'Plant/Environment/Collision_Response/Cross Product1/Subsystem'
 * '<S53>'  : 'Plant/Environment/Collision_Response/Cross Product1/Subsystem1'
 * '<S54>'  : 'Plant/Environment/Collision_Response/Cross Product2/Subsystem'
 * '<S55>'  : 'Plant/Environment/Collision_Response/Cross Product2/Subsystem1'
 * '<S56>'  : 'Plant/Environment/PreProcess/Compare To Zero'
 * '<S57>'  : 'Plant/Environment/SImple_Ground_Model/Compare To Zero'
 * '<S58>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force'
 * '<S59>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Torque'
 * '<S60>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force/Compare To Constant'
 * '<S61>'  : 'Plant/Environment/SImple_Ground_Model/Ground_Force/Compare To Constant1'
 * '<S62>'  : 'Plant/Environment/Total_Reponse_Force/Compare To Zero'
 * '<S63>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S64>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S65>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S66>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S67>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S68>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S69>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S70>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S71>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S72>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S73>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S74>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S75>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S76>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S77>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S78>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S79>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S80>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S81>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S82>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S83>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S84>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S85>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S86>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S87>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S88>'  : 'Plant/Sensor_Model/Counter'
 * '<S89>'  : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S144>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S145>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S146>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S147>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S148>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 * '<S149>' : 'Plant/Subsystem/Check_Ever_Valid'
 * '<S150>' : 'Plant/Subsystem/Compare To Constant'
 * '<S151>' : 'Plant/Subsystem/Compare To Zero'
 * '<S152>' : 'Plant/Subsystem/Counter'
 * '<S153>' : 'Plant/Subsystem/Ground_Model'
 * '<S154>' : 'Plant/Subsystem/Check_Ever_Valid/Detect Increase'
 * '<S155>' : 'Plant/Subsystem/Ground_Model/Compare To Zero'
 * '<S156>' : 'Plant/Subsystem/Ground_Model/Ground_Force'
 * '<S157>' : 'Plant/Subsystem/Ground_Model/Ground_Torque'
 * '<S158>' : 'Plant/Subsystem/Ground_Model/Ground_Force/Compare To Constant'
 * '<S159>' : 'Plant/Subsystem/Ground_Model/Ground_Force/Compare To Constant1'
 * '<S160>' : 'Plant/Subsystem1/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
