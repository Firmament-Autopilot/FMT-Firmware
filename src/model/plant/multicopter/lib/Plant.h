/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.797
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 14 09:08:42 2023
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
  GPS_uBlox_Bus RateTransition;        /* '<S95>/Rate Transition' */
  MAG_Bus RateTransition_b;            /* '<S133>/Rate Transition' */
  Barometer_Bus RateTransition_m;      /* '<S89>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S100>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S105>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[3];             /* '<S23>/Delay1' */
  real_T Delay_DSTATE_a[3];            /* '<S23>/Delay' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S130>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S119>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S125>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[4];/* '<S114>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_a[150];       /* '<S100>/Delay1' */
  real32_T DiscreteFIRFilter_states_f[3];/* '<S106>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[4];/* '<S62>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e[3];/* '<S58>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f[3];/* '<S59>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S59>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_n[4];/* '<S12>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE;         /* '<S40>/Delay Input1' */
  uint32_T Delay_DSTATE_c;             /* '<S21>/Delay' */
  real32_T Divide2_DWORK4[9];          /* '<S41>/Divide2' */
  uint32_T Memory1_PreviousInput;      /* '<S83>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S143>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S143>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_f[3];/* '<S121>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_k[6];/* '<S121>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_n[3];/* '<S132>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_h[6];/* '<S132>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_m[3];/* '<S103>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_l[6];/* '<S103>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S103>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S103>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_b[2];/* '<S94>/Random Source' */
  uint8_T Delay_DSTATE_p;              /* '<S37>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S62>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S58>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S59>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S59>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S130>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_j;/* '<S119>/Discrete-Time Integrator5' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S107>/Sum' */
  const real_T ff;                     /* '<S107>/Multiply3' */
  const real_T Sum4;                   /* '<S107>/Sum4' */
  const real_T Subtract1;              /* '<S29>/Subtract1' */
  const real_T Product1;               /* '<S29>/Product1' */
  const real32_T Add[9];               /* '<S142>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S141>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_a[3];/* '<S140>/Vector Concatenate3' */
  const real32_T Add_m[9];             /* '<S120>/Add' */
  const real32_T Add_g[9];             /* '<S131>/Add' */
  const real32_T quat0[4];             /* '<S58>/quat0' */
  const real32_T VectorConcatenate3_e[3];/* '<S36>/Vector Concatenate3' */
  const real32_T Add_n;                /* '<S41>/Add' */
  const uint8_T DataTypeConversion;    /* '<S95>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S95>/Data Type Conversion1' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: gain
   * Referenced by: '<S114>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Computed Parameter: X_Frame_CM_Value
   * Referenced by: '<S17>/X_Frame_CM'
   */
  real32_T X_Frame_CM_Value[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<S59>/Constant'
   *   '<S10>/Constant'
   *   '<S10>/Constant1'
   *   '<S12>/Discrete-Time Integrator'
   *   '<S13>/Saturation1'
   *   '<S67>/Constant'
   *   '<S67>/Constant1'
   *   '<S67>/Constant2'
   *   '<S67>/Constant3'
   *   '<S97>/Saturation'
   *   '<S100>/Delay1'
   *   '<S36>/Constant1'
   *   '<S36>/Constant2'
   *   '<S36>/Constant3'
   *   '<S36>/Constant4'
   *   '<S53>/Constant'
   *   '<S55>/Constant'
   *   '<S92>/Limit  altitude  to Stratosphere'
   *   '<S92>/Limit  altitude  to troposhere'
   *   '<S93>/Constant3'
   *   '<S94>/Random Source'
   *   '<S103>/Random Source'
   *   '<S103>/Random Source1'
   *   '<S106>/Discrete FIR Filter'
   *   '<S121>/Random Source'
   *   '<S132>/Random Source'
   *   '<S143>/Random Source'
   *   '<S140>/Constant'
   *   '<S140>/Constant2'
   *   '<S140>/Constant3'
   *   '<S140>/Constant4'
   *   '<S141>/Constant1'
   *   '<S141>/Constant2'
   *   '<S141>/Constant3'
   *   '<S141>/Constant4'
   */
  real32_T pooled14;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S58>/Inertia_Matrix'
   *   '<S41>/Inertia_Matrix'
   */
  real32_T pooled22[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S137>/Saturation'
   *   '<S94>/Random Source'
   */
  real32_T pooled26;

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S103>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S103>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_f
   * Referenced by: '<S121>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_f[3];

  /* Computed Parameter: RandomSource_VarianceRTP_b
   * Referenced by: '<S132>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_b[3];

  /* Expression: wmm_declination
   * Referenced by: '<S138>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S138>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S138>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_a
   * Referenced by: '<S143>/Random Source'
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
                                                   *   '<S21>/dt'
                                                   *   '<S83>/dt'
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
 * Block '<S92>/Product' : Unused code path elimination
 * Block '<S92>/Product3' : Unused code path elimination
 * Block '<S92>/a' : Unused code path elimination
 * Block '<S92>/gamma*R' : Unused code path elimination
 * Block '<S92>/rho0' : Unused code path elimination
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S54>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S54>/Reshape' : Reshape block reduction
 * Block '<S55>/Reshape1' : Reshape block reduction
 * Block '<S83>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S91>/Switch' : Eliminated due to constant selection input
 * Block '<S89>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S95>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S95>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S95>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S95>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S95>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S98>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S98>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S98>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S101>/Switch' : Eliminated due to constant selection input
 * Block '<S101>/Switch1' : Eliminated due to constant selection input
 * Block '<S114>/Reshape' : Reshape block reduction
 * Block '<S119>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S113>/Switch' : Eliminated due to constant selection input
 * Block '<S125>/Reshape' : Reshape block reduction
 * Block '<S130>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S124>/Switch' : Eliminated due to constant selection input
 * Block '<S137>/Switch' : Eliminated due to constant selection input
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
 * '<S32>'  : 'Plant/Environment/Environment'
 * '<S33>'  : 'Plant/Environment/Gravity'
 * '<S34>'  : 'Plant/Environment/Aerodynamic/Air_Drag'
 * '<S35>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM'
 * '<S36>'  : 'Plant/Environment/Aerodynamic/Air_Drag/Psi To DCM/Rotation Matrix Z'
 * '<S37>'  : 'Plant/Environment/Environment/Check_Ever_Valid'
 * '<S38>'  : 'Plant/Environment/Environment/Environment'
 * '<S39>'  : 'Plant/Environment/Environment/Simple_Environment'
 * '<S40>'  : 'Plant/Environment/Environment/Check_Ever_Valid/Detect Increase'
 * '<S41>'  : 'Plant/Environment/Environment/Environment/Collision_Response'
 * '<S42>'  : 'Plant/Environment/Environment/Environment/External_Forces'
 * '<S43>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product'
 * '<S44>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product1'
 * '<S45>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product2'
 * '<S46>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product/Subsystem'
 * '<S47>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product/Subsystem1'
 * '<S48>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product1/Subsystem'
 * '<S49>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product1/Subsystem1'
 * '<S50>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product2/Subsystem'
 * '<S51>'  : 'Plant/Environment/Environment/Environment/Collision_Response/Cross Product2/Subsystem1'
 * '<S52>'  : 'Plant/Environment/Environment/Simple_Environment/Ground_Model'
 * '<S53>'  : 'Plant/Environment/Environment/Simple_Environment/Ground_Model/Compare To Zero'
 * '<S54>'  : 'Plant/Environment/Environment/Simple_Environment/Ground_Model/Ground_Force'
 * '<S55>'  : 'Plant/Environment/Environment/Simple_Environment/Ground_Model/Ground_Torque'
 * '<S56>'  : 'Plant/Environment/Environment/Simple_Environment/Ground_Model/Ground_Force/Compare To Constant'
 * '<S57>'  : 'Plant/Environment/Environment/Simple_Environment/Ground_Model/Ground_Force/Compare To Constant1'
 * '<S58>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S59>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S60>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S61>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S62>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S63>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S64>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S65>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S66>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S67>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S68>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S69>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S70>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S71>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S72>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S73>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S74>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S75>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S76>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S77>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S78>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S79>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S80>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S81>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S82>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S83>'  : 'Plant/Sensor_Model/Counter'
 * '<S84>'  : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S85>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S86>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S87>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S88>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S89>'  : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S114>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S115>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S116>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S117>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S118>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S119>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S120>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S121>' : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S122>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S123>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S124>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S125>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S126>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S127>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S128>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S129>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S130>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S131>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S132>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S133>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S134>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S135>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S136>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S137>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S138>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S139>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S140>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S141>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S142>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S143>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
