/*
 * File: Plant.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.1278
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Mar 14 12:59:07 2025
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
  GPS_uBlox_Bus RateTransition;        /* '<S65>/Rate Transition' */
  MAG_Bus RateTransition_b;            /* '<S103>/Rate Transition' */
  Barometer_Bus RateTransition_m;      /* '<S59>/Rate Transition' */
} B_Plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[225];            /* '<S70>/Delay' */
  real_T DiscreteFIRFilter_states[3];  /* '<S75>/Discrete FIR Filter' */
  real_T Delay1_DSTATE[250];           /* '<S71>/Delay1' */
  real_T Delay_DSTATE_i[250];          /* '<S71>/Delay' */
  real_T Delay_DSTATE_a[3];            /* '<S10>/Delay' */
  real_T Delay1_DSTATE_n[3];           /* '<S10>/Delay1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[3];/* '<S100>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_c[3];/* '<S89>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S95>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p[4];/* '<S84>/Discrete-Time Integrator' */
  real32_T Delay1_DSTATE_a[150];       /* '<S70>/Delay1' */
  real32_T DiscreteFIRFilter_states_f[3];/* '<S76>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTAT_p4[4];/* '<S27>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_p2[3];/* '<S21>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a[3];/* '<S22>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S22>/Discrete-Time Integrator1' */
  uint32_T DelayInput1_DSTATE;         /* '<S24>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_j;       /* '<S38>/Delay Input1' */
  uint32_T Delay_DSTATE_c;             /* '<S8>/Delay' */
  uint32_T Memory1_PreviousInput;      /* '<S53>/Memory1' */
  uint32_T RandomSource_SEED_DWORK[3]; /* '<S113>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[6];/* '<S113>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_f[3];/* '<S91>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_k[6];/* '<S91>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_n[3];/* '<S102>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_h[6];/* '<S102>/Random Source' */
  uint32_T RandomSource_SEED_DWORK_m[3];/* '<S73>/Random Source' */
  uint32_T RandomSource_STATE_DWORK_l[6];/* '<S73>/Random Source' */
  uint32_T RandomSource1_SEED_DWORK[3];/* '<S73>/Random Source1' */
  uint32_T RandomSource1_STATE_DWORK[6];/* '<S73>/Random Source1' */
  uint32_T RandomSource_STATE_DWORK_b[2];/* '<S64>/Random Source' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S27>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S21>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S22>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S22>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S100>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_j;/* '<S89>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S27>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S22>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S10>/Delay1' */
} DW_Plant_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Sum;                    /* '<S77>/Sum' */
  const real_T ff;                     /* '<S77>/Multiply3' */
  const real_T Sum4;                   /* '<S77>/Sum4' */
  const real_T Subtract1;              /* '<S16>/Subtract1' */
  const real_T Product1;               /* '<S16>/Product1' */
  const real32_T Add[9];               /* '<S112>/Add' */
  const real32_T VectorConcatenate3[3];/* '<S111>/Vector Concatenate3' */
  const real32_T VectorConcatenate3_a[3];/* '<S110>/Vector Concatenate3' */
  const real32_T Add_m[9];             /* '<S90>/Add' */
  const real32_T Add_g[9];             /* '<S101>/Add' */
} ConstB_Plant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: gain
   * Referenced by: '<S84>/Gain4'
   */
  real_T Gain4_Gain[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/Constant'
   *   '<S19>/Constant4'
   *   '<S20>/Constant'
   *   '<S35>/Constant'
   *   '<S35>/Constant1'
   *   '<S35>/Constant2'
   *   '<S35>/Constant3'
   *   '<S67>/Saturation'
   *   '<S70>/Delay1'
   *   '<S62>/Limit  altitude  to Stratosphere'
   *   '<S62>/Limit  altitude  to troposhere'
   *   '<S63>/Constant3'
   *   '<S64>/Random Source'
   *   '<S73>/Random Source'
   *   '<S73>/Random Source1'
   *   '<S76>/Discrete FIR Filter'
   *   '<S91>/Random Source'
   *   '<S102>/Random Source'
   *   '<S113>/Random Source'
   *   '<S110>/Constant'
   *   '<S110>/Constant2'
   *   '<S110>/Constant3'
   *   '<S110>/Constant4'
   *   '<S111>/Constant1'
   *   '<S111>/Constant2'
   *   '<S111>/Constant3'
   *   '<S111>/Constant4'
   */
  real32_T pooled14;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S20>/Constant4'
   *   '<S107>/Saturation'
   *   '<S64>/Random Source'
   */
  real32_T pooled19;

  /* Computed Parameter: Inertia_Matrix_Value
   * Referenced by: '<S21>/Inertia_Matrix'
   */
  real32_T Inertia_Matrix_Value[9];

  /* Computed Parameter: RandomSource_VarianceRTP
   * Referenced by: '<S73>/Random Source'
   */
  real32_T RandomSource_VarianceRTP[3];

  /* Computed Parameter: RandomSource1_VarianceRTP
   * Referenced by: '<S73>/Random Source1'
   */
  real32_T RandomSource1_VarianceRTP[3];

  /* Computed Parameter: RandomSource_VarianceRTP_f
   * Referenced by: '<S91>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_f[3];

  /* Computed Parameter: RandomSource_VarianceRTP_b
   * Referenced by: '<S102>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_b[3];

  /* Expression: wmm_declination
   * Referenced by: '<S108>/Declination_Lookup_Table'
   */
  real32_T Declination_Lookup_Table_table[629];

  /* Expression: wmm_inclination
   * Referenced by: '<S108>/Inclination_Lookup_Table'
   */
  real32_T Inclination_Lookup_Table_table[629];

  /* Expression: wmm_magnitude
   * Referenced by: '<S108>/Magnitude_Lookup_Table'
   */
  real32_T Magnitude_Lookup_Table_table[629];

  /* Computed Parameter: RandomSource_VarianceRTP_a
   * Referenced by: '<S113>/Random Source'
   */
  real32_T RandomSource_VarianceRTP_a[3];
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
extern struct_3bORdf2BsPDFMyyhwl9bpH PLANT_PARAM;/* Variable: PLANT_PARAM
                                                  * Referenced by:
                                                  *   '<S2>/Constant1'
                                                  *   '<S2>/Constant2'
                                                  *   '<S2>/Constant3'
                                                  *   '<S10>/Constant1'
                                                  *   '<S10>/Constant2'
                                                  *   '<S10>/Constant3'
                                                  */
extern struct_AjtFzZRX3GJyUtRZj0A4oG PLANT_EXPORT;/* Variable: PLANT_EXPORT
                                                   * Referenced by:
                                                   *   '<S8>/dt'
                                                   *   '<S53>/dt'
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
 * Block '<S62>/Product' : Unused code path elimination
 * Block '<S62>/Product3' : Unused code path elimination
 * Block '<S62>/a' : Unused code path elimination
 * Block '<S62>/gamma*R' : Unused code path elimination
 * Block '<S62>/rho0' : Unused code path elimination
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S53>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S61>/Switch' : Eliminated due to constant selection input
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S65>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S65>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S65>/Signal Conversion6' : Eliminate redundant signal conversion block
 * Block '<S65>/Signal Conversion7' : Eliminate redundant signal conversion block
 * Block '<S68>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S68>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S68>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S71>/Switch' : Eliminated due to constant selection input
 * Block '<S71>/Switch1' : Eliminated due to constant selection input
 * Block '<S84>/Reshape' : Reshape block reduction
 * Block '<S89>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S83>/Switch' : Eliminated due to constant selection input
 * Block '<S95>/Reshape' : Reshape block reduction
 * Block '<S100>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S94>/Switch' : Eliminated due to constant selection input
 * Block '<S107>/Switch' : Eliminated due to constant selection input
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
 * '<S6>'   : 'Plant/Actuators/Motor_Model'
 * '<S7>'   : 'Plant/Actuators/Servo_Model'
 * '<S8>'   : 'Plant/Bus_Constructor/Counter'
 * '<S9>'   : 'Plant/Bus_Constructor/Quaternion To DCM'
 * '<S10>'  : 'Plant/Bus_Constructor/WGS84'
 * '<S11>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize'
 * '<S12>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_1'
 * '<S13>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_2'
 * '<S14>'  : 'Plant/Bus_Constructor/Quaternion To DCM/column_3'
 * '<S15>'  : 'Plant/Bus_Constructor/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S16>'  : 'Plant/Bus_Constructor/WGS84/WGS84_Derivative'
 * '<S17>'  : 'Plant/Bus_Constructor/WGS84/Zero_Value_Exclusion'
 * '<S18>'  : 'Plant/Environment/Water_Drag'
 * '<S19>'  : 'Plant/Environment/Water_Drag/Water_Force'
 * '<S20>'  : 'Plant/Environment/Water_Drag/Water_Torque'
 * '<S21>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic'
 * '<S22>'  : 'Plant/Kinematic_Equation/Position_Dynamic'
 * '<S23>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product'
 * '<S24>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Detect Change'
 * '<S25>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion'
 * '<S26>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler'
 * '<S27>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update'
 * '<S28>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem'
 * '<S29>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Cross Product/Subsystem1'
 * '<S30>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion/Quaternion Normalize'
 * '<S31>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Euler To Quaternion/Quaternion Normalize/Quaternion Modulus'
 * '<S32>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize'
 * '<S33>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S34>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion Normalize'
 * '<S35>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion_Update_Maxtrix'
 * '<S36>'  : 'Plant/Kinematic_Equation/Attitude_Dynamic/Quaternuin_Update/Quaternion Normalize/Quaternion Modulus'
 * '<S37>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product'
 * '<S38>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Detect Change'
 * '<S39>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation'
 * '<S40>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation'
 * '<S41>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem'
 * '<S42>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Cross Product/Subsystem1'
 * '<S43>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize'
 * '<S44>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem'
 * '<S45>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem1'
 * '<S46>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Subsystem2'
 * '<S47>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Inv-Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S48>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize'
 * '<S49>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v1'
 * '<S50>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v2'
 * '<S51>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/v3'
 * '<S52>'  : 'Plant/Kinematic_Equation/Position_Dynamic/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S53>'  : 'Plant/Sensor_Model/Counter'
 * '<S54>'  : 'Plant/Sensor_Model/Sensor_Barometer'
 * '<S55>'  : 'Plant/Sensor_Model/Sensor_GPS'
 * '<S56>'  : 'Plant/Sensor_Model/Sensor_IMU'
 * '<S57>'  : 'Plant/Sensor_Model/Sensor_MAG'
 * '<S58>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer'
 * '<S59>'  : 'Plant/Sensor_Model/Sensor_Barometer/Bus_Constructor'
 * '<S60>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model'
 * '<S61>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model'
 * '<S62>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Physical_Model/ISA Atmosphere Model'
 * '<S63>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Error'
 * '<S64>'  : 'Plant/Sensor_Model/Sensor_Barometer/Barometer/Sensor_Model/Sensor_Noise'
 * '<S65>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor'
 * '<S66>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS'
 * '<S67>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/GroundSpeed'
 * '<S68>'  : 'Plant/Sensor_Model/Sensor_GPS/Bus_Constructor/WGS84_Position'
 * '<S69>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Bus_Constructor'
 * '<S70>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Physical_Model'
 * '<S71>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model'
 * '<S72>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Accurancy_Estimate'
 * '<S73>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/Sensor_Error'
 * '<S74>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization'
 * '<S75>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/pos_filter'
 * '<S76>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/vel_filter'
 * '<S77>'  : 'Plant/Sensor_Model/Sensor_GPS/GPS/Sensor_Model/WGS84_Linearization/LAT2FLAT Curve'
 * '<S78>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer'
 * '<S79>'  : 'Plant/Sensor_Model/Sensor_IMU/Bus_Constructor'
 * '<S80>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope'
 * '<S81>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Bus_Constructor'
 * '<S82>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model'
 * '<S83>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model'
 * '<S84>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model'
 * '<S85>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/prop_vel'
 * '<S86>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/specific_force'
 * '<S87>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S88>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Physical_Model/Vibration_Model/vib_frequency'
 * '<S89>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/First Order LPF'
 * '<S90>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Error'
 * '<S91>'  : 'Plant/Sensor_Model/Sensor_IMU/Accelerometer/Sensor_Model/Sensor_Noise'
 * '<S92>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Bus_Constructor'
 * '<S93>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model'
 * '<S94>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model'
 * '<S95>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model'
 * '<S96>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/prop_vel'
 * '<S97>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/rotation_speed'
 * '<S98>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/Compare To Constant1'
 * '<S99>'  : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Physical_Model/Vibration_Model/vib_frequency'
 * '<S100>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/First Order LPF'
 * '<S101>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Error'
 * '<S102>' : 'Plant/Sensor_Model/Sensor_IMU/Gyroscope/Sensor_Model/Sensor_Noise'
 * '<S103>' : 'Plant/Sensor_Model/Sensor_MAG/Bus_Constructor'
 * '<S104>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer'
 * '<S105>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Bus_Constructor'
 * '<S106>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model'
 * '<S107>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model'
 * '<S108>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/WMM_LUT'
 * '<S109>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field'
 * '<S110>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Y'
 * '<S111>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Physical_Model/magnetic_field/Rotation Matrix Z'
 * '<S112>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Error'
 * '<S113>' : 'Plant/Sensor_Model/Sensor_MAG/Magnetometer/Sensor_Model/Sensor_Noise'
 */
#endif                                 /* RTW_HEADER_Plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
