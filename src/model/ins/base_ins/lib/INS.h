/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.3588
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Mar 13 09:23:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_INS_h_
#define RTW_HEADER_INS_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef INS_COMMON_INCLUDES_
# define INS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* INS_COMMON_INCLUDES_ */

#include "arm_math.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_INS_T RT_MODEL_INS_T;

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
#define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T gyr_x;
  real32_T gyr_y;
  real32_T gyr_z;
  real32_T acc_x;
  real32_T acc_y;
  real32_T acc_z;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MAG_Bus_
#define DEFINED_TYPEDEF_FOR_MAG_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T mag_x;
  real32_T mag_y;
  real32_T mag_z;
} MAG_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Barometer_Bus_
#define DEFINED_TYPEDEF_FOR_Barometer_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T pressure;
  real32_T temperature;
} Barometer_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_
#define DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_

typedef struct {
  uint32_T timestamp;
  uint32_T iTOW;
  uint16_T year;
  uint8_T month;
  uint8_T day;
  uint8_T hour;
  uint8_T min;
  uint8_T sec;
  uint8_T valid;
  uint32_T tAcc;
  int32_T nano;
  uint8_T fixType;
  uint8_T flags;
  uint8_T reserved1;
  uint8_T numSV;
  int32_T lon;
  int32_T lat;
  int32_T height;
  int32_T hMSL;
  uint32_T hAcc;
  uint32_T vAcc;
  int32_T velN;
  int32_T velE;
  int32_T velD;
  int32_T gSpeed;
  int32_T heading;
  uint32_T sAcc;
  uint32_T headingAcc;
  uint16_T pDOP;
  uint16_T reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rangefinder_Bus_
#define DEFINED_TYPEDEF_FOR_Rangefinder_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T distance_m;
} Rangefinder_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_
#define DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T vx;
  real32_T vy;
  uint32_T valid;
} Optical_Flow_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
#define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T phi;
  real32_T theta;
  real32_T psi;
  real32_T quat[4];
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T ax;
  real32_T ay;
  real32_T az;
  real32_T vn;
  real32_T ve;
  real32_T vd;
  real32_T reserved;
  real_T lat;
  real_T lon;
  real_T alt;
  real_T lat_0;
  real_T lon_0;
  real_T alt_0;
  real32_T x_R;
  real32_T y_R;
  real32_T h_R;
  real32_T h_AGL;
  uint32_T flag;
  uint32_T status;
} INS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TYt7YeNdxIDXfczXumtXXB_
#define DEFINED_TYPEDEF_FOR_struct_TYt7YeNdxIDXfczXumtXXB_

typedef struct {
  uint32_T period;
  int8_T model_info[16];
} struct_TYt7YeNdxIDXfczXumtXXB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Gsh1YUlqR57cYRpVuxG74E_
#define DEFINED_TYPEDEF_FOR_struct_Gsh1YUlqR57cYRpVuxG74E_

typedef struct {
  real_T dt;
  real32_T g;
  real32_T wmm_mag[629];
  real32_T wmm_dec[629];
  real32_T wmm_inc[629];
} struct_Gsh1YUlqR57cYRpVuxG74E;

#endif

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion;           /* '<S303>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S303>/Data Type Conversion1' */
  real_T Multiply2;                    /* '<S317>/Multiply2' */
  real_T Rm;                           /* '<S317>/Product3' */
  real32_T Divide;                     /* '<S290>/Divide' */
  real32_T h_0;                        /* '<S222>/Merge' */
  real32_T vel_D_0;                    /* '<S222>/Merge1' */
  real32_T Sum1[3];                    /* '<S211>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S202>/Sum1' */
  real32_T Saturation;                 /* '<S202>/Saturation' */
  real32_T Reshape[2];                 /* '<S197>/Reshape' */
  real32_T DataTypeConversion_n[2];    /* '<S196>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S181>/Sum1' */
  real32_T Merge[4];                   /* '<S129>/Merge' */
  real32_T OutportBufferForquat_0[4];  /* '<S113>/DCM To Quaternion' */
  real32_T Integrator[3];              /* '<S91>/Integrator' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S251>/Delay1' */
  real_T Delay_DSTATE[2];              /* '<S252>/Delay' */
  real_T Delay1_DSTATE_o[2];           /* '<S252>/Delay1' */
  real32_T Delay_8_DSTATE[9];          /* '<Root>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S333>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S333>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m;/* '<S316>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S316>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_d;             /* '<S290>/Delay' */
  real32_T Delay_4_DSTATE;             /* '<S56>/Delay' */
  real32_T Delay_5_DSTATE;             /* '<S56>/Delay' */
  real32_T Delay_6_DSTATE;             /* '<S56>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S260>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S272>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S271>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S259>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_l[6];          /* '<S191>/Delay' */
  real32_T Delay_DSTATE_b[3];          /* '<S220>/Delay' */
  real32_T h_delay_DSTATE[75];         /* '<S215>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S215>/vd_delay' */
  real32_T Delay_DSTATE_dr[3];         /* '<S204>/Delay' */
  real32_T x_delay_DSTATE[5];          /* '<S206>/x_delay' */
  real32_T Delay_DSTATE_h;             /* '<S208>/Delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S185>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S185>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S185>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S185>/vn_delay1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S165>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_m;/* '<S163>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S164>/Discrete-Time Integrator5' */
  real32_T Delay_7_DSTATE[9];          /* '<S57>/Delay' */
  real32_T Delay_8_DSTATE_l[9];        /* '<S57>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S97>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S98>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];/* '<S88>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S86>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTAT_lq[3];/* '<S88>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b[3];/* '<S95>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_ce[3];/* '<S95>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE[3];       /* '<S91>/Integrator' */
  real32_T Integrator1_DSTATE[3];      /* '<S91>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_bo;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_hi;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_b3;/* '<S17>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_ca;/* '<S11>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_kg;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S16>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S312>/Unit Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S340>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lg;/* '<S326>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S321>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S319>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S315>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S306>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S293>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S296>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nm;/* '<S289>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_f;             /* '<S291>/Delay' */
  uint32_T Delay1_DSTATE_i;            /* '<S290>/Delay1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S212>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S203>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S182>/Delay Input1' */
  uint32_T Delay_DSTATE_i;             /* '<S122>/Delay' */
  uint32_T Delay_DSTATE_n;             /* '<S119>/Delay' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S217>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S213>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S188>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S183>/Memory' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S245>/Delay Input1' */
  boolean_T Delay_DSTATE_k;            /* '<S260>/Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S246>/Delay Input1' */
  boolean_T Delay_DSTATE_k4;           /* '<S272>/Delay' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S253>/Delay Input1' */
  boolean_T Delay_DSTATE_c;            /* '<S271>/Delay' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S255>/Delay Input1' */
  boolean_T Delay_DSTATE_ng;           /* '<S259>/Delay' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S264>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_hg;     /* '<S269>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ch;     /* '<S276>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S281>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S219>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S210>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S190>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pr;     /* '<S117>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mm;     /* '<S124>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S90>/Delay Input1' */
  boolean_T Delay_DSTATE_bn;           /* '<S12>/Delay' */
  boolean_T Delay_DSTATE_cx;           /* '<S15>/Delay' */
  boolean_T Delay_DSTATE_l0;           /* '<S17>/Delay' */
  boolean_T Delay_DSTATE_cn;           /* '<S11>/Delay' */
  boolean_T Delay_DSTATE_p;            /* '<S13>/Delay' */
  boolean_T Delay_DSTATE_db;           /* '<S14>/Delay' */
  boolean_T Delay_DSTATE_ly;           /* '<S16>/Delay' */
  boolean_T DelayInput1_DSTATE_dx;     /* '<S21>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mu;     /* '<S26>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dq;     /* '<S31>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f4;     /* '<S36>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S41>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dql;    /* '<S46>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_fq;     /* '<S51>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S333>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S333>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_j;/* '<S316>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_j;/* '<S316>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S260>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_l;/* '<S272>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S271>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S259>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_bk;/* '<S97>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S88>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S88>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_o;/* '<S95>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S95>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S91>/Integrator' */
  int8_T Integrator1_PrevResetState;   /* '<S91>/Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevR_nf;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_dj;/* '<S17>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S11>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ar;/* '<S16>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S333>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_e;/* '<S316>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S215>/h_delay' */
  uint8_T icLoad_f;                    /* '<S215>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S206>/x_delay' */
  uint8_T icLoad_o;                    /* '<S185>/x_delay' */
  uint8_T icLoad_i;                    /* '<S185>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S185>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S185>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;/* '<S165>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_LO_n;/* '<S163>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator5_IC_L_ns;/* '<S164>/Discrete-Time Integrator5' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S97>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_i;/* '<S88>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_l;/* '<S95>/Discrete-Time Integrator1' */
  uint8_T Integrator1_IC_LOADING;      /* '<S91>/Integrator1' */
  boolean_T Relay_Mode;                /* '<S241>/Relay' */
  boolean_T Relay1_Mode;               /* '<S241>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S241>/Relay2' */
  boolean_T Relay_Mode_n;              /* '<S114>/Relay' */
  boolean_T Relay_Mode_nf;             /* '<S92>/Relay' */
  boolean_T Relay1_Mode_l;             /* '<S71>/Relay1' */
  boolean_T Relay1_Mode_j;             /* '<S9>/Relay1' */
  boolean_T Reference_Height_MODE;     /* '<S288>/Reference_Height' */
  boolean_T GPS_Correct_MODE;          /* '<S201>/GPS_Correct' */
  boolean_T Baro_Correct_MODE;         /* '<S200>/Baro_Correct' */
  boolean_T GPS_Correct_MODE_o;        /* '<S179>/GPS_Correct' */
  boolean_T GPS_Meas_Acc_MODE;         /* '<S87>/GPS_Meas_Acc' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S284>/WGS84_Model' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S215>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S215>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S206>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S185>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S185>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S185>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S185>/vn_delay1' */
} PrevZCSigStates_INS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  IMU_Bus IMU;                         /* '<Root>/IMU' */
  MAG_Bus MAG;                         /* '<Root>/MAG' */
  Barometer_Bus Barometer;             /* '<Root>/Barometer' */
  GPS_uBlox_Bus GPS_uBlox;             /* '<Root>/GPS_uBlox' */
  Rangefinder_Bus Rangefinder;         /* '<Root>/Rangefinder' */
  Optical_Flow_Bus Optical_Flow;       /* '<Root>/Optical_Flow' */
} ExternalInputs_INS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExternalOutputs_INS_T;

/* Parameters (default storage) */
struct Parameters_INS_T_ {
  struct_Gsh1YUlqR57cYRpVuxG74E INS_CONST;/* Variable: INS_CONST
                                           * Referenced by:
                                           *   '<S329>/Declination_Lookup_Table'
                                           *   '<S329>/Inclination_Lookup_Table'
                                           *   '<S329>/Magnitude_Lookup_Table'
                                           *   '<S69>/Constant'
                                           *   '<S221>/Constant1'
                                           */
  real_T WMM_LUT_resolution;           /* Mask Parameter: WMM_LUT_resolution
                                        * Referenced by: '<S329>/rad_to_index'
                                        */
  int32_T valid_samples_const;         /* Mask Parameter: valid_samples_const
                                        * Referenced by: '<S313>/Constant'
                                        */
  real32_T Sensor_Valid_acc_max;       /* Mask Parameter: Sensor_Valid_acc_max
                                        * Referenced by: '<S322>/Upper Limit'
                                        */
  real32_T Sensor_Valid_acc_min;       /* Mask Parameter: Sensor_Valid_acc_min
                                        * Referenced by: '<S322>/Lower Limit'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S44>/Constant'
                                        */
  real32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S45>/Constant'
                                        */
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S94>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S115>/Constant'
                                        */
  real32_T CompareToConstant1_const_o; /* Mask Parameter: CompareToConstant1_const_o
                                        * Referenced by: '<S116>/Constant'
                                        */
  real32_T Sensor_Valid_gyr_max;       /* Mask Parameter: Sensor_Valid_gyr_max
                                        * Referenced by: '<S323>/Upper Limit'
                                        */
  real32_T Sensor_Valid_gyr_min;       /* Mask Parameter: Sensor_Valid_gyr_min
                                        * Referenced by: '<S323>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S118>/Lower Limit'
                                        */
  real32_T Sensor_Valid_mag_max;       /* Mask Parameter: Sensor_Valid_mag_max
                                        * Referenced by: '<S341>/Upper Limit'
                                        */
  real32_T Sensor_Valid_mag_min;       /* Mask Parameter: Sensor_Valid_mag_min
                                        * Referenced by: '<S341>/Lower Limit'
                                        */
  real32_T Sensor_Valid_max_pressure;  /* Mask Parameter: Sensor_Valid_max_pressure
                                        * Referenced by: '<S297>/Upper Limit'
                                        */
  real32_T Sensor_Valid_max_temp;      /* Mask Parameter: Sensor_Valid_max_temp
                                        * Referenced by: '<S298>/Upper Limit'
                                        */
  real32_T Sensor_Valid_min_pressure;  /* Mask Parameter: Sensor_Valid_min_pressure
                                        * Referenced by: '<S297>/Lower Limit'
                                        */
  real32_T Sensor_Valid_min_temp;      /* Mask Parameter: Sensor_Valid_min_temp
                                        * Referenced by: '<S298>/Lower Limit'
                                        */
  real32_T valid_check2_time_out;      /* Mask Parameter: valid_check2_time_out
                                        * Referenced by: '<S23>/Constant'
                                        */
  real32_T valid_check5_time_out;      /* Mask Parameter: valid_check5_time_out
                                        * Referenced by: '<S38>/Constant'
                                        */
  real32_T valid_check8_time_out;      /* Mask Parameter: valid_check8_time_out
                                        * Referenced by: '<S48>/Constant'
                                        */
  real32_T valid_check1_time_out;      /* Mask Parameter: valid_check1_time_out
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T valid_check3_time_out;      /* Mask Parameter: valid_check3_time_out
                                        * Referenced by: '<S28>/Constant'
                                        */
  real32_T valid_check4_time_out;      /* Mask Parameter: valid_check4_time_out
                                        * Referenced by: '<S33>/Constant'
                                        */
  real32_T valid_check6_time_out;      /* Mask Parameter: valid_check6_time_out
                                        * Referenced by: '<S43>/Constant'
                                        */
  real32_T valid_hold1_time_out;       /* Mask Parameter: valid_hold1_time_out
                                        * Referenced by: '<S266>/Constant'
                                        */
  real32_T valid_hold1_time_out_m;     /* Mask Parameter: valid_hold1_time_out_m
                                        * Referenced by: '<S278>/Constant'
                                        */
  real32_T valid_hold_time_out;        /* Mask Parameter: valid_hold_time_out
                                        * Referenced by: '<S273>/Constant'
                                        */
  real32_T valid_hold_time_out_f;      /* Mask Parameter: valid_hold_time_out_f
                                        * Referenced by: '<S261>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S118>/Upper Limit'
                                        */
  uint32_T valid_samples_const_k;      /* Mask Parameter: valid_samples_const_k
                                        * Referenced by: '<S126>/Constant'
                                        */
  uint32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S292>/Constant'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S314>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S310>/Constant'
                                        */
  uint32_T IntervalTest3_lowlimit;     /* Mask Parameter: IntervalTest3_lowlimit
                                        * Referenced by: '<S294>/Lower Limit'
                                        */
  uint32_T Sensor_Valid_timeout;       /* Mask Parameter: Sensor_Valid_timeout
                                        * Referenced by: '<S295>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_a;     /* Mask Parameter: Sensor_Valid_timeout_a
                                        * Referenced by: '<S320>/Constant'
                                        */
  uint32_T Sensor_Valid_timeout_b;     /* Mask Parameter: Sensor_Valid_timeout_b
                                        * Referenced by: '<S339>/Constant'
                                        */
  uint32_T IntervalTest3_uplimit;      /* Mask Parameter: IntervalTest3_uplimit
                                        * Referenced by: '<S294>/Upper Limit'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S182>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S203>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S212>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S293>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_n;       /* Mask Parameter: DetectChange_vinit_n
                                        * Referenced by: '<S296>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S315>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S321>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S340>/Delay Input1'
                                        */
  boolean_T CompareToConstant1_const_m;/* Mask Parameter: CompareToConstant1_const_m
                                        * Referenced by: '<S24>/Constant'
                                        */
  boolean_T CompareToConstant1_const_j;/* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S39>/Constant'
                                        */
  boolean_T CompareToConstant1_const_g;/* Mask Parameter: CompareToConstant1_const_g
                                        * Referenced by: '<S49>/Constant'
                                        */
  boolean_T CompareToConstant1_const_e;/* Mask Parameter: CompareToConstant1_const_e
                                        * Referenced by: '<S19>/Constant'
                                        */
  boolean_T CompareToConstant1_const_ei;/* Mask Parameter: CompareToConstant1_const_ei
                                         * Referenced by: '<S29>/Constant'
                                         */
  boolean_T CompareToConstant1_const_ec;/* Mask Parameter: CompareToConstant1_const_ec
                                         * Referenced by: '<S34>/Constant'
                                         */
  boolean_T CompareToConstant2_const_p;/* Mask Parameter: CompareToConstant2_const_p
                                        * Referenced by: '<S20>/Constant'
                                        */
  boolean_T CompareToConstant2_const_c;/* Mask Parameter: CompareToConstant2_const_c
                                        * Referenced by: '<S25>/Constant'
                                        */
  boolean_T CompareToConstant2_const_n;/* Mask Parameter: CompareToConstant2_const_n
                                        * Referenced by: '<S30>/Constant'
                                        */
  boolean_T CompareToConstant2_const_b;/* Mask Parameter: CompareToConstant2_const_b
                                        * Referenced by: '<S35>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i;/* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S40>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i1;/* Mask Parameter: CompareToConstant2_const_i1
                                         * Referenced by: '<S50>/Constant'
                                         */
  boolean_T CompareToConstant1_const_i;/* Mask Parameter: CompareToConstant1_const_i
                                        * Referenced by: '<S267>/Constant'
                                        */
  boolean_T CompareToConstant1_const_a;/* Mask Parameter: CompareToConstant1_const_a
                                        * Referenced by: '<S279>/Constant'
                                        */
  boolean_T CompareToConstant1_const_h;/* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S274>/Constant'
                                        */
  boolean_T CompareToConstant1_const_hh;/* Mask Parameter: CompareToConstant1_const_hh
                                         * Referenced by: '<S262>/Constant'
                                         */
  boolean_T CompareToConstant2_const_a;/* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S263>/Constant'
                                        */
  boolean_T CompareToConstant2_const_j;/* Mask Parameter: CompareToConstant2_const_j
                                        * Referenced by: '<S268>/Constant'
                                        */
  boolean_T CompareToConstant2_const_d;/* Mask Parameter: CompareToConstant2_const_d
                                        * Referenced by: '<S275>/Constant'
                                        */
  boolean_T CompareToConstant2_const_d2;/* Mask Parameter: CompareToConstant2_const_d2
                                         * Referenced by: '<S280>/Constant'
                                         */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S21>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_c;/* Mask Parameter: DetectRisePositive_vinit_c
                                        * Referenced by: '<S26>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_m;/* Mask Parameter: DetectRisePositive_vinit_m
                                        * Referenced by: '<S31>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_k;/* Mask Parameter: DetectRisePositive_vinit_k
                                        * Referenced by: '<S36>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_a;/* Mask Parameter: DetectRisePositive_vinit_a
                                        * Referenced by: '<S41>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_f;/* Mask Parameter: DetectRisePositive_vinit_f
                                        * Referenced by: '<S46>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_l;/* Mask Parameter: DetectRisePositive_vinit_l
                                        * Referenced by: '<S51>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S90>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_fc;/* Mask Parameter: DetectRisePositive_vinit_fc
                                         * Referenced by: '<S117>/Delay Input1'
                                         */
  boolean_T DetectRisePositive1_vinit; /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S124>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S190>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S210>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S219>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_me;/* Mask Parameter: DetectRisePositive_vinit_me
                                         * Referenced by: '<S245>/Delay Input1'
                                         */
  boolean_T DetectRisePositive1_vinit_h;/* Mask Parameter: DetectRisePositive1_vinit_h
                                         * Referenced by: '<S246>/Delay Input1'
                                         */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S253>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S255>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_d;/* Mask Parameter: DetectRisePositive_vinit_d
                                        * Referenced by: '<S264>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_o;/* Mask Parameter: DetectRisePositive_vinit_o
                                        * Referenced by: '<S269>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_dn;/* Mask Parameter: DetectRisePositive_vinit_dn
                                         * Referenced by: '<S276>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S281>/Delay Input1'
                                        */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S311>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S299>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S300>/Constant'
                                        */
  uint8_T CompareToConstant2_const_bv; /* Mask Parameter: CompareToConstant2_const_bv
                                        * Referenced by: '<S304>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S178>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1e-6
                                        * Referenced by: '<S178>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S178>/Constant'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S251>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S252>/Delay'
                                        */
  real_T Delay1_InitialCondition_e;    /* Expression: 0.0
                                        * Referenced by: '<S252>/Delay1'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S303>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S303>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S303>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S303>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S303>/dz_dh'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S317>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S317>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S317>/Constant2'
                                        */
  real_T R_Value;                      /* Expression: 6378137
                                        * Referenced by: '<S317>/R'
                                        */
  real_T f_Value;                      /* Expression: 1/298.257223563
                                        * Referenced by: '<S317>/f'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S312>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S312>/Saturation'
                                        */
  int32_T Saturation_LowerSat_f;       /* Computed Parameter: Saturation_LowerSat_f
                                        * Referenced by: '<S312>/Saturation'
                                        */
  int32_T offset_Value[2];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S329>/offset'
                                        */
  int32_T Saturation1_UpperSat[2];     /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S329>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S329>/Saturation1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S301>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S301>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S301>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S301>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain;           /* Computed Parameter: Scalefactor1_Gain
                                        * Referenced by: '<S301>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S301>/Scalefactor2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S12>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T Gain10_Gain;                /* Computed Parameter: Gain10_Gain
                                        * Referenced by: '<S8>/Gain10'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_i;/* Computed Parameter: DiscreteTimeIntegrator_IC_i
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_g;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_g
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_j;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_j
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T Relay1_OnVal;               /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<S9>/Relay1'
                                        */
  real32_T Relay1_OffVal;              /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<S9>/Relay1'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_o;/* Computed Parameter: DiscreteTimeIntegrator_IC_o
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_d;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_d
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_n;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_n
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                            * Referenced by: '<S11>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_n;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_n
                                            * Referenced by: '<S11>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_l;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_l
                                            * Referenced by: '<S11>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_j;/* Computed Parameter: DiscreteTimeIntegrator_IC_j
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_f;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_f
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_f;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_f
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_me;/* Computed Parameter: DiscreteTimeIntegrator_gainv_me
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ig;/* Computed Parameter: DiscreteTimeIntegrator_IC_ig
                                         * Referenced by: '<S14>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_m;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_m
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_i;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_i
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_my;/* Computed Parameter: DiscreteTimeIntegrator_gainv_my
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_e;/* Computed Parameter: DiscreteTimeIntegrator_IC_e
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_ml;/* Computed Parameter: DiscreteTimeIntegrator_Upper_ml
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_g;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_g
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S53>/Constant'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S64>/Constant'
                                        */
  real32_T Saturation_UpperSat_h;      /* Computed Parameter: Saturation_UpperSat_h
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real32_T Saturation_LowerSat_m;      /* Computed Parameter: Saturation_LowerSat_m
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S64>/Constant1'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S64>/Constant2'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S63>/Gain'
                                        */
  real32_T Constant_Value_j1;          /* Computed Parameter: Constant_Value_j1
                                        * Referenced by: '<S67>/Constant'
                                        */
  real32_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S67>/Constant1'
                                        */
  real32_T Constant2_Value_a;          /* Computed Parameter: Constant2_Value_a
                                        * Referenced by: '<S67>/Constant2'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S67>/Constant3'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S67>/Constant4'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S67>/Gain'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S81>/Constant'
                                        */
  real32_T Constant_Value_jy;          /* Computed Parameter: Constant_Value_jy
                                        * Referenced by: '<S82>/Constant'
                                        */
  real32_T gps_acc_O_mPs2_Y0;          /* Computed Parameter: gps_acc_O_mPs2_Y0
                                        * Referenced by: '<S91>/gps_acc_O_mPs2'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S91>/Integrator'
                                        */
  real32_T Integrator_IC;              /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S91>/Integrator'
                                        */
  real32_T Integrator1_gainval;        /* Computed Parameter: Integrator1_gainval
                                        * Referenced by: '<S91>/Integrator1'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S91>/gain'
                                        */
  real32_T gain1_Gain;                 /* Computed Parameter: gain1_Gain
                                        * Referenced by: '<S91>/gain1'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S88>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S88>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S92>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S92>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S92>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S92>/Relay'
                                        */
  real32_T Delay_InitialCondition_m;   /* Computed Parameter: Delay_InitialCondition_m
                                        * Referenced by: '<S86>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Expression: [0;0;-INS_CONST.g]
                                        * Referenced by: '<S73>/gravity'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S74>/Gain2'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S74>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S74>/Dead Zone2'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S74>/Gain'
                                        */
  real32_T Saturation_UpperSat_k;      /* Computed Parameter: Saturation_UpperSat_k
                                        * Referenced by: '<S74>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S74>/Saturation'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S81>/Switch'
                                        */
  real32_T Switch_Threshold_m;         /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S82>/Switch'
                                        */
  real32_T max_Value;                  /* Computed Parameter: max_Value
                                        * Referenced by: '<S80>/max'
                                        */
  real32_T Saturation_UpperSat_e;      /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S80>/Saturation'
                                        */
  real32_T Saturation_LowerSat_fo;     /* Computed Parameter: Saturation_LowerSat_fo
                                        * Referenced by: '<S80>/Saturation'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real32_T Gain_Gain_ok[3];            /* Computed Parameter: Gain_Gain_ok
                                        * Referenced by: '<S75>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                            * Referenced by: '<S88>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S88>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S88>/Gain'
                                        */
  real32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S88>/Gain1'
                                        */
  real32_T Relay1_OnVal_i;             /* Computed Parameter: Relay1_OnVal_i
                                        * Referenced by: '<S71>/Relay1'
                                        */
  real32_T Relay1_OffVal_o;            /* Computed Parameter: Relay1_OffVal_o
                                        * Referenced by: '<S71>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S71>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S71>/Relay1'
                                        */
  real32_T mag_correct_gain_Gain;      /* Computed Parameter: mag_correct_gain_Gain
                                        * Referenced by: '<S71>/mag_correct_gain'
                                        */
  real32_T Constant_Value_no;          /* Computed Parameter: Constant_Value_no
                                        * Referenced by: '<S95>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_j
                                            * Referenced by: '<S95>/Discrete-Time Integrator1'
                                            */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S69>/Gain1'
                                        */
  real32_T Saturation2_UpperSat;       /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat;       /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_kw;/* Computed Parameter: DiscreteTimeIntegrator_gainv_kw
                                            * Referenced by: '<S95>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_m;/* Computed Parameter: DiscreteTimeIntegrator_IC_m
                                        * Referenced by: '<S95>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S95>/Gain'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S95>/Gain1'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S97>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S97>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S98>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S98>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S98>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S98>/Discrete-Time Integrator2'
                                            */
  real32_T Gain2_Gain_i4;              /* Computed Parameter: Gain2_Gain_i4
                                        * Referenced by: '<S97>/Gain2'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S108>/Gain'
                                        */
  real32_T Gain1_Gain_pl;              /* Computed Parameter: Gain1_Gain_pl
                                        * Referenced by: '<S108>/Gain1'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S109>/Gain'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S109>/Gain1'
                                        */
  real32_T Gain_Gain_oz;               /* Computed Parameter: Gain_Gain_oz
                                        * Referenced by: '<S110>/Gain'
                                        */
  real32_T Gain1_Gain_f;               /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S110>/Gain1'
                                        */
  real32_T Delay_7_InitialCondition;   /* Computed Parameter: Delay_7_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_8_InitialCondition;   /* Computed Parameter: Delay_8_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Constant_Value_c0;          /* Computed Parameter: Constant_Value_c0
                                        * Referenced by: '<S139>/Constant'
                                        */
  real32_T Gain_Gain_eu;               /* Computed Parameter: Gain_Gain_eu
                                        * Referenced by: '<S139>/Gain'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S139>/Gain1'
                                        */
  real32_T Constant2_Value_az[2];      /* Computed Parameter: Constant2_Value_az
                                        * Referenced by: '<S152>/Constant2'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S152>/Constant1'
                                        */
  real32_T Constant_Value_ae;          /* Computed Parameter: Constant_Value_ae
                                        * Referenced by: '<S153>/Constant'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S141>/Gain'
                                        */
  real32_T Gain1_Gain_g;               /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S141>/Gain1'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S141>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S141>/Gain4'
                                        */
  real32_T Constant2_Value_o[2];       /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S157>/Constant2'
                                        */
  real32_T Constant1_Value_l;          /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S157>/Constant1'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S158>/Constant'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S142>/Gain'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S142>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S142>/Gain2'
                                        */
  real32_T Gain3_Gain_e;               /* Computed Parameter: Gain3_Gain_e
                                        * Referenced by: '<S142>/Gain3'
                                        */
  real32_T Constant2_Value_m[2];       /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S147>/Constant2'
                                        */
  real32_T Constant1_Value_a;          /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S147>/Constant1'
                                        */
  real32_T Constant_Value_hd;          /* Computed Parameter: Constant_Value_hd
                                        * Referenced by: '<S148>/Constant'
                                        */
  real32_T Gain_Gain_g;                /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S140>/Gain'
                                        */
  real32_T Gain1_Gain_ig;              /* Computed Parameter: Gain1_Gain_ig
                                        * Referenced by: '<S140>/Gain1'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S140>/Gain2'
                                        */
  real32_T Gain3_Gain_ea;              /* Computed Parameter: Gain3_Gain_ea
                                        * Referenced by: '<S140>/Gain3'
                                        */
  real32_T Constant_Value_h1;          /* Computed Parameter: Constant_Value_h1
                                        * Referenced by: '<S130>/Constant'
                                        */
  real32_T Constant_Value_aee;         /* Computed Parameter: Constant_Value_aee
                                        * Referenced by: '<S131>/Constant'
                                        */
  real32_T Constant_Value_hp;          /* Computed Parameter: Constant_Value_hp
                                        * Referenced by: '<S132>/Constant'
                                        */
  real32_T quat_0_Y0[4];               /* Computed Parameter: quat_0_Y0
                                        * Referenced by: '<S113>/quat_0'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S113>/Gain'
                                        */
  real32_T Switch_Threshold_a;         /* Computed Parameter: Switch_Threshold_a
                                        * Referenced by: '<S130>/Switch'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S131>/Switch'
                                        */
  real32_T Switch_Threshold_mm;        /* Computed Parameter: Switch_Threshold_mm
                                        * Referenced by: '<S132>/Switch'
                                        */
  real32_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S129>/Merge'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<S165>/Discrete-Time Integrator5'
                                            */
  real32_T Gain_Gain_fr;               /* Computed Parameter: Gain_Gain_fr
                                        * Referenced by: '<S165>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_n;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_n
                                            * Referenced by: '<S163>/Discrete-Time Integrator5'
                                            */
  real32_T Gain_Gain_je;               /* Computed Parameter: Gain_Gain_je
                                        * Referenced by: '<S163>/Gain'
                                        */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S114>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S114>/Saturation2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_m
                                            * Referenced by: '<S164>/Discrete-Time Integrator5'
                                            */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S164>/Gain'
                                        */
  real32_T Relay_OnVal_g;              /* Computed Parameter: Relay_OnVal_g
                                        * Referenced by: '<S114>/Relay'
                                        */
  real32_T Relay_OffVal_f;             /* Computed Parameter: Relay_OffVal_f
                                        * Referenced by: '<S114>/Relay'
                                        */
  real32_T Relay_YOn_k;                /* Computed Parameter: Relay_YOn_k
                                        * Referenced by: '<S114>/Relay'
                                        */
  real32_T Relay_YOff_f;               /* Computed Parameter: Relay_YOff_f
                                        * Referenced by: '<S114>/Relay'
                                        */
  real32_T Gain3_Gain_j;               /* Computed Parameter: Gain3_Gain_j
                                        * Referenced by: '<S184>/Gain3'
                                        */
  real32_T Gain_Gain_o0;               /* Computed Parameter: Gain_Gain_o0
                                        * Referenced by: '<S184>/Gain'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S184>/Gain2'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S181>/X_Next'
                                        */
  real32_T Memory_InitialCondition[2]; /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S188>/Memory'
                                        */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S183>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S183>/Gain3'
                                        */
  real32_T Constant_Value_b[2];        /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S193>/Constant'
                                        */
  real32_T X_0_Y0;                     /* Computed Parameter: X_0_Y0
                                        * Referenced by: '<S196>/X_0'
                                        */
  real32_T Vel_NE_0_Y0;                /* Computed Parameter: Vel_NE_0_Y0
                                        * Referenced by: '<S197>/Vel_NE_0'
                                        */
  real32_T Saturation_UpperSat_b;      /* Computed Parameter: Saturation_UpperSat_b
                                        * Referenced by: '<S205>/Saturation'
                                        */
  real32_T Saturation_LowerSat_c;      /* Computed Parameter: Saturation_LowerSat_c
                                        * Referenced by: '<S205>/Saturation'
                                        */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S205>/Gain2'
                                        */
  real32_T Gain1_Gain_o;               /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S205>/Gain1'
                                        */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S205>/Gain'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S202>/X_Next'
                                        */
  real32_T Delay_InitialCondition_j;   /* Computed Parameter: Delay_InitialCondition_j
                                        * Referenced by: '<S204>/Delay'
                                        */
  real32_T Delay_InitialCondition_mk;  /* Computed Parameter: Delay_InitialCondition_mk
                                        * Referenced by: '<S208>/Delay'
                                        */
  real32_T Gain_Gain_pl;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S204>/Gain'
                                        */
  real32_T Saturation_UpperSat_as;     /* Computed Parameter: Saturation_UpperSat_as
                                        * Referenced by: '<S202>/Saturation'
                                        */
  real32_T Saturation_LowerSat_e;      /* Computed Parameter: Saturation_LowerSat_e
                                        * Referenced by: '<S202>/Saturation'
                                        */
  real32_T Gain1_Gain_ml;              /* Computed Parameter: Gain1_Gain_ml
                                        * Referenced by: '<S214>/Gain1'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S214>/Gain'
                                        */
  real32_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S214>/Gain2'
                                        */
  real32_T X_Next_Y0_i;                /* Computed Parameter: X_Next_Y0_i
                                        * Referenced by: '<S211>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S217>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S213>/Memory'
                                        */
  real32_T Gain3_Gain_k;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S213>/Gain3'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S222>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S225>/Constant'
                                        */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S191>/Delay'
                                        */
  real32_T Constant_Value_l[2];        /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S192>/Constant'
                                        */
  real32_T Gain_Gain_ic;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S192>/Gain'
                                        */
  real32_T Merge_InitialOutput_j;      /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S222>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S222>/Merge1'
                                        */
  real32_T Delay_InitialCondition_mt;  /* Computed Parameter: Delay_InitialCondition_mt
                                        * Referenced by: '<S220>/Delay'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S221>/Gain1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S221>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S221>/Gain'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S171>/Constant1'
                                        */
  real32_T Relay_OnVal_l;              /* Computed Parameter: Relay_OnVal_l
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay_OffVal_p;             /* Computed Parameter: Relay_OffVal_p
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay_YOn_b;                /* Computed Parameter: Relay_YOn_b
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay_YOff_d;               /* Computed Parameter: Relay_YOff_d
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay1_OnVal_b;             /* Computed Parameter: Relay1_OnVal_b
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay1_OffVal_n;            /* Computed Parameter: Relay1_OffVal_n
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay1_YOn_b;               /* Computed Parameter: Relay1_YOn_b
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay1_YOff_a;              /* Computed Parameter: Relay1_YOff_a
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay2_OnVal;               /* Computed Parameter: Relay2_OnVal
                                        * Referenced by: '<S241>/Relay2'
                                        */
  real32_T Relay2_OffVal;              /* Computed Parameter: Relay2_OffVal
                                        * Referenced by: '<S241>/Relay2'
                                        */
  real32_T Relay2_YOn;                 /* Computed Parameter: Relay2_YOn
                                        * Referenced by: '<S241>/Relay2'
                                        */
  real32_T Relay2_YOff;                /* Computed Parameter: Relay2_YOff
                                        * Referenced by: '<S241>/Relay2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                            * Referenced by: '<S260>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S260>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_p;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_p
                                            * Referenced by: '<S260>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_p;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_p
                                            * Referenced by: '<S260>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_jo;/* Computed Parameter: DiscreteTimeIntegrator_gainv_jo
                                            * Referenced by: '<S272>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_lb;/* Computed Parameter: DiscreteTimeIntegrator_IC_lb
                                         * Referenced by: '<S272>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_j;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_j
                                            * Referenced by: '<S272>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_Lower_f2;/* Computed Parameter: DiscreteTimeIntegrator_Lower_f2
                                            * Referenced by: '<S272>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                            * Referenced by: '<S271>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_h;/* Computed Parameter: DiscreteTimeIntegrator_IC_h
                                        * Referenced by: '<S271>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_fv;/* Computed Parameter: DiscreteTimeIntegrator_Upper_fv
                                            * Referenced by: '<S271>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_b;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_b
                                            * Referenced by: '<S271>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_iy;/* Computed Parameter: DiscreteTimeIntegrator_gainv_iy
                                            * Referenced by: '<S259>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S259>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_jm;/* Computed Parameter: DiscreteTimeIntegrator_Upper_jm
                                            * Referenced by: '<S259>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_d;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_d
                                            * Referenced by: '<S259>/Discrete-Time Integrator'
                                            */
  real32_T Delay_4_InitialCondition;   /* Computed Parameter: Delay_4_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_5_InitialCondition;   /* Computed Parameter: Delay_5_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_6_InitialCondition;   /* Computed Parameter: Delay_6_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T h_R_m_Y0;                   /* Computed Parameter: h_R_m_Y0
                                        * Referenced by: '<S290>/h_R_m'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S290>/Delay'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S287>/Gain1'
                                        */
  real32_T p1_Value;                   /* Computed Parameter: p1_Value
                                        * Referenced by: '<S287>/p1'
                                        */
  real32_T aR_g_Value;                 /* Computed Parameter: aR_g_Value
                                        * Referenced by: '<S287>/aR_g'
                                        */
  real32_T T1_Value;                   /* Computed Parameter: T1_Value
                                        * Referenced by: '<S287>/T1'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S287>/a'
                                        */
  real32_T Constant1_Value_g;          /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S307>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S307>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S307>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S307>/Saturation1'
                                        */
  real32_T Constant1_Value_gm;         /* Computed Parameter: Constant1_Value_gm
                                        * Referenced by: '<S309>/Constant1'
                                        */
  real32_T Gain2_Gain_h;               /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S309>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_f;     /* Computed Parameter: Saturation1_UpperSat_f
                                        * Referenced by: '<S309>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_o;     /* Computed Parameter: Saturation1_LowerSat_o
                                        * Referenced by: '<S309>/Saturation1'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S316>/Constant'
                                        */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S308>/Constant7'
                                        */
  real32_T Gain3_Gain_l;               /* Computed Parameter: Gain3_Gain_l
                                        * Referenced by: '<S308>/Gain3'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_e;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_e
                                            * Referenced by: '<S316>/Discrete-Time Integrator1'
                                            */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_mf;/* Computed Parameter: DiscreteTimeIntegrator_gainv_mf
                                            * Referenced by: '<S316>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_f;/* Computed Parameter: DiscreteTimeIntegrator_IC_f
                                        * Referenced by: '<S316>/Discrete-Time Integrator'
                                        */
  real32_T Gain_Gain_gh;               /* Computed Parameter: Gain_Gain_gh
                                        * Referenced by: '<S316>/Gain'
                                        */
  real32_T Gain1_Gain_c;               /* Computed Parameter: Gain1_Gain_c
                                        * Referenced by: '<S316>/Gain1'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S327>/default_mag_quality'
                                        */
  real32_T Constant_Value_hy;          /* Computed Parameter: Constant_Value_hy
                                        * Referenced by: '<S337>/Constant'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S337>/Switch'
                                        */
  real32_T Constant1_Value_l1;         /* Computed Parameter: Constant1_Value_l1
                                        * Referenced by: '<S338>/Constant1'
                                        */
  real32_T Constant_Value_a1;          /* Computed Parameter: Constant_Value_a1
                                        * Referenced by: '<S336>/Constant'
                                        */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S336>/Constant1'
                                        */
  real32_T Constant2_Value_mb;         /* Computed Parameter: Constant2_Value_mb
                                        * Referenced by: '<S336>/Constant2'
                                        */
  real32_T Constant4_Value_c;          /* Computed Parameter: Constant4_Value_c
                                        * Referenced by: '<S336>/Constant4'
                                        */
  real32_T Gain_Gain_gg;               /* Computed Parameter: Gain_Gain_gg
                                        * Referenced by: '<S328>/Gain'
                                        */
  real32_T Gain_Gain_bo;               /* Computed Parameter: Gain_Gain_bo
                                        * Referenced by: '<S336>/Gain'
                                        */
  real32_T Constant3_Value_f;          /* Computed Parameter: Constant3_Value_f
                                        * Referenced by: '<S336>/Constant3'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S286>/Gauss_to_uT'
                                        */
  real32_T Gain1_Gain_od;              /* Computed Parameter: Gain1_Gain_od
                                        * Referenced by: '<S331>/Gain1'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S331>/Constant2'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S331>/gain'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S331>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S331>/Saturation'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S332>/Nominal_Magnitude'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S332>/Constant1'
                                        */
  real32_T gain_Gain_m;                /* Computed Parameter: gain_Gain_m
                                        * Referenced by: '<S332>/gain'
                                        */
  real32_T Saturation_UpperSat_gv;     /* Computed Parameter: Saturation_UpperSat_gv
                                        * Referenced by: '<S332>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S332>/Saturation'
                                        */
  real32_T Constant_Value_fn;          /* Computed Parameter: Constant_Value_fn
                                        * Referenced by: '<S333>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_bm;/* Computed Parameter: DiscreteTimeIntegrator_gainv_bm
                                            * Referenced by: '<S333>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_mb;/* Computed Parameter: DiscreteTimeIntegrator_IC_mb
                                         * Referenced by: '<S333>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator1_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                                            * Referenced by: '<S333>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_cw;               /* Computed Parameter: Gain_Gain_cw
                                        * Referenced by: '<S333>/Gain'
                                        */
  real32_T Gain1_Gain_bn;              /* Computed Parameter: Gain1_Gain_bn
                                        * Referenced by: '<S333>/Gain1'
                                        */
  real32_T Delay_8_InitialCondition_m; /* Computed Parameter: Delay_8_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Gain1_Gain_ap;              /* Computed Parameter: Gain1_Gain_ap
                                        * Referenced by: '<S10>/Gain1'
                                        */
  uint32_T Gain9_Gain;                 /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S8>/Gain9'
                                        */
  uint32_T Gain1_Gain_po;              /* Computed Parameter: Gain1_Gain_po
                                        * Referenced by: '<S307>/Gain1'
                                        */
  uint32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S309>/Gain1'
                                        */
  uint32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S308>/Gain5'
                                        */
  uint32_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
  uint32_T Constant_Value_pt;          /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S15>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S17>/Delay'
                                        */
  uint32_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S11>/Delay'
                                        */
  uint32_T Delay_DelayLength_lg;       /* Computed Parameter: Delay_DelayLength_lg
                                        * Referenced by: '<S13>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S14>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S16>/Delay'
                                        */
  uint32_T Constant_Value_lm;          /* Computed Parameter: Constant_Value_lm
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint32_T Delay_7_DelayLength;        /* Computed Parameter: Delay_7_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_8_DelayLength;        /* Computed Parameter: Delay_8_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_DelayLength_fi;       /* Computed Parameter: Delay_DelayLength_fi
                                        * Referenced by: '<S122>/Delay'
                                        */
  uint32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S122>/Delay'
                                        */
  uint32_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S122>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S122>/Saturation'
                                        */
  uint32_T Delay_DelayLength_md;       /* Computed Parameter: Delay_DelayLength_md
                                        * Referenced by: '<S119>/Delay'
                                        */
  uint32_T Delay_InitialCondition_i;   /* Computed Parameter: Delay_InitialCondition_i
                                        * Referenced by: '<S119>/Delay'
                                        */
  uint32_T Saturation_UpperSat_p;      /* Computed Parameter: Saturation_UpperSat_p
                                        * Referenced by: '<S119>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_mo;     /* Computed Parameter: Saturation_LowerSat_mo
                                        * Referenced by: '<S119>/Saturation'
                                        */
  uint32_T Constant_Value_mo;          /* Computed Parameter: Constant_Value_mo
                                        * Referenced by: '<S125>/Constant'
                                        */
  uint32_T x_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S185>/x_delay'
                                        */
  uint32_T x_delay1_DelayLength;       /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S185>/x_delay1'
                                        */
  uint32_T vn_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S185>/vn_delay'
                                        */
  uint32_T vn_delay1_DelayLength;      /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S185>/vn_delay1'
                                        */
  uint32_T Delay_DelayLength_fx;       /* Computed Parameter: Delay_DelayLength_fx
                                        * Referenced by: '<S204>/Delay'
                                        */
  uint32_T x_delay_DelayLength_m;      /* Expression: 10/INS_EXPORT_VALUE.period
                                        * Referenced by: '<S206>/x_delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S208>/Delay'
                                        */
  uint32_T h_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S215>/h_delay'
                                        */
  uint32_T vd_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S215>/vd_delay'
                                        */
  uint32_T Delay_DelayLength_ly;       /* Computed Parameter: Delay_DelayLength_ly
                                        * Referenced by: '<S191>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S220>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S260>/Delay'
                                        */
  uint32_T Delay_DelayLength_g;        /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S272>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S251>/Delay1'
                                        */
  uint32_T Delay_DelayLength_d0;       /* Computed Parameter: Delay_DelayLength_d0
                                        * Referenced by: '<S271>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S252>/Delay'
                                        */
  uint32_T Delay1_DelayLength_o;       /* Computed Parameter: Delay1_DelayLength_o
                                        * Referenced by: '<S252>/Delay1'
                                        */
  uint32_T Delay_DelayLength_cp;       /* Computed Parameter: Delay_DelayLength_cp
                                        * Referenced by: '<S259>/Delay'
                                        */
  uint32_T Delay_4_DelayLength;        /* Computed Parameter: Delay_4_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_5_DelayLength;        /* Computed Parameter: Delay_5_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_6_DelayLength;        /* Computed Parameter: Delay_6_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Constant1_Value_f5;         /* Computed Parameter: Constant1_Value_f5
                                        * Referenced by: '<S290>/Constant1'
                                        */
  uint32_T Delay_DelayLength_jx;       /* Computed Parameter: Delay_DelayLength_jx
                                        * Referenced by: '<S290>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S290>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition_k;  /* Computed Parameter: Delay1_InitialCondition_k
                                        * Referenced by: '<S290>/Delay1'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S290>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S290>/Saturation1'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_iu;/* Computed Parameter: DiscreteTimeIntegrator_IC_iu
                                         * Referenced by: '<S289>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_dn;       /* Computed Parameter: Delay_DelayLength_dn
                                        * Referenced by: '<S291>/Delay'
                                        */
  uint32_T Delay_InitialCondition_nt;  /* Computed Parameter: Delay_InitialCondition_nt
                                        * Referenced by: '<S291>/Delay'
                                        */
  uint32_T Saturation_UpperSat_f;      /* Computed Parameter: Saturation_UpperSat_f
                                        * Referenced by: '<S291>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_pw;     /* Computed Parameter: Saturation_LowerSat_pw
                                        * Referenced by: '<S291>/Saturation'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S306>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_ba;/* Computed Parameter: DiscreteTimeIntegrator_IC_ba
                                         * Referenced by: '<S319>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S326>/Discrete-Time Integrator'
                                        */
  uint32_T Delay_8_DelayLength_g;      /* Computed Parameter: Delay_8_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint16_T Gain1_Gain_kq;              /* Computed Parameter: Gain1_Gain_kq
                                        * Referenced by: '<S8>/Gain1'
                                        */
  uint16_T Gain13_Gain;                /* Computed Parameter: Gain13_Gain
                                        * Referenced by: '<S8>/Gain13'
                                        */
  uint16_T Gain12_Gain;                /* Computed Parameter: Gain12_Gain
                                        * Referenced by: '<S8>/Gain12'
                                        */
  uint16_T Gain11_Gain;                /* Computed Parameter: Gain11_Gain
                                        * Referenced by: '<S8>/Gain11'
                                        */
  uint16_T Gain5_Gain_e;               /* Computed Parameter: Gain5_Gain_e
                                        * Referenced by: '<S8>/Gain5'
                                        */
  uint16_T Gain4_Gain_a;               /* Computed Parameter: Gain4_Gain_a
                                        * Referenced by: '<S8>/Gain4'
                                        */
  uint16_T Gain2_Gain_o5;              /* Computed Parameter: Gain2_Gain_o5
                                        * Referenced by: '<S8>/Gain2'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S86>/GPS_Delay'
                                        */
  uint16_T Constant_Value_gn;          /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S247>/Constant'
                                        */
  uint16_T Constant_Value_bt;          /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S248>/Constant'
                                        */
  uint16_T Constant_Value_m3;          /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S254>/Constant'
                                        */
  uint16_T Constant_Value_pti;         /* Computed Parameter: Constant_Value_pti
                                        * Referenced by: '<S256>/Constant'
                                        */
  boolean_T Delay_InitialCondition_go; /* Computed Parameter: Delay_InitialCondition_go
                                        * Referenced by: '<S12>/Delay'
                                        */
  boolean_T Delay_InitialCondition_mz; /* Computed Parameter: Delay_InitialCondition_mz
                                        * Referenced by: '<S15>/Delay'
                                        */
  boolean_T Relay1_YOn_i;              /* Computed Parameter: Relay1_YOn_i
                                        * Referenced by: '<S9>/Relay1'
                                        */
  boolean_T Relay1_YOff_k;             /* Computed Parameter: Relay1_YOff_k
                                        * Referenced by: '<S9>/Relay1'
                                        */
  boolean_T Delay_InitialCondition_a;  /* Computed Parameter: Delay_InitialCondition_a
                                        * Referenced by: '<S17>/Delay'
                                        */
  boolean_T Delay_InitialCondition_c;  /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S11>/Delay'
                                        */
  boolean_T Delay_InitialCondition_cj; /* Computed Parameter: Delay_InitialCondition_cj
                                        * Referenced by: '<S13>/Delay'
                                        */
  boolean_T Delay_InitialCondition_ae; /* Computed Parameter: Delay_InitialCondition_ae
                                        * Referenced by: '<S14>/Delay'
                                        */
  boolean_T Delay_InitialCondition_e;  /* Computed Parameter: Delay_InitialCondition_e
                                        * Referenced by: '<S16>/Delay'
                                        */
  boolean_T Constant_Value_mt;         /* Computed Parameter: Constant_Value_mt
                                        * Referenced by: '<S22>/Constant'
                                        */
  boolean_T Constant_Value_m2;         /* Computed Parameter: Constant_Value_m2
                                        * Referenced by: '<S27>/Constant'
                                        */
  boolean_T Constant_Value_o;          /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S32>/Constant'
                                        */
  boolean_T Constant_Value_hk;         /* Computed Parameter: Constant_Value_hk
                                        * Referenced by: '<S37>/Constant'
                                        */
  boolean_T Constant_Value_l1;         /* Computed Parameter: Constant_Value_l1
                                        * Referenced by: '<S42>/Constant'
                                        */
  boolean_T Constant_Value_m2n;        /* Computed Parameter: Constant_Value_m2n
                                        * Referenced by: '<S47>/Constant'
                                        */
  boolean_T Constant_Value_ao;         /* Computed Parameter: Constant_Value_ao
                                        * Referenced by: '<S52>/Constant'
                                        */
  boolean_T Constant_Value_af;         /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S123>/Constant'
                                        */
  boolean_T Constant_Value_ej;         /* Computed Parameter: Constant_Value_ej
                                        * Referenced by: '<S234>/Constant'
                                        */
  boolean_T Constant_Value_pf;         /* Computed Parameter: Constant_Value_pf
                                        * Referenced by: '<S235>/Constant'
                                        */
  boolean_T Delay_InitialCondition_in; /* Computed Parameter: Delay_InitialCondition_in
                                        * Referenced by: '<S260>/Delay'
                                        */
  boolean_T Delay_InitialCondition_ns; /* Computed Parameter: Delay_InitialCondition_ns
                                        * Referenced by: '<S272>/Delay'
                                        */
  boolean_T Delay_InitialCondition_d;  /* Computed Parameter: Delay_InitialCondition_d
                                        * Referenced by: '<S271>/Delay'
                                        */
  boolean_T Delay_InitialCondition_k;  /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S259>/Delay'
                                        */
  boolean_T Constant_Value_nm;         /* Computed Parameter: Constant_Value_nm
                                        * Referenced by: '<S265>/Constant'
                                        */
  boolean_T Constant_Value_dc;         /* Computed Parameter: Constant_Value_dc
                                        * Referenced by: '<S270>/Constant'
                                        */
  boolean_T Constant_Value_ej0;        /* Computed Parameter: Constant_Value_ej0
                                        * Referenced by: '<S277>/Constant'
                                        */
  boolean_T Constant_Value_jo;         /* Computed Parameter: Constant_Value_jo
                                        * Referenced by: '<S282>/Constant'
                                        */
  int8_T Saturation_UpperSat_gx;       /* Computed Parameter: Saturation_UpperSat_gx
                                        * Referenced by: '<S233>/Saturation'
                                        */
  int8_T Saturation_LowerSat_co;       /* Computed Parameter: Saturation_LowerSat_co
                                        * Referenced by: '<S233>/Saturation'
                                        */
  int8_T Constant_Value_lc;            /* Computed Parameter: Constant_Value_lc
                                        * Referenced by: '<S236>/Constant'
                                        */
  int8_T Saturation1_UpperSat_i;       /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S233>/Saturation1'
                                        */
  int8_T Saturation1_LowerSat_g;       /* Computed Parameter: Saturation1_LowerSat_g
                                        * Referenced by: '<S233>/Saturation1'
                                        */
  int8_T Constant_Value_kt;            /* Computed Parameter: Constant_Value_kt
                                        * Referenced by: '<S237>/Constant'
                                        */
  uint8_T Gain4_Gain_p;                /* Computed Parameter: Gain4_Gain_p
                                        * Referenced by: '<S10>/Gain4'
                                        */
  uint8_T Gain3_Gain_f;                /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S10>/Gain3'
                                        */
  uint8_T Gain2_Gain_ha;               /* Computed Parameter: Gain2_Gain_ha
                                        * Referenced by: '<S10>/Gain2'
                                        */
};

/* Parameters (default storage) */
typedef struct Parameters_INS_T_ Parameters_INS_T;

/* Real-time Model Data Structure */
struct tag_RTM_INS_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_INS_T INS_P;

/* Block signals (default storage) */
extern BlockIO_INS_T INS_B;

/* Block states (default storage) */
extern D_Work_INS_T INS_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_INS_T INS_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_INS_T INS_Y;

/* External data declarations for dependent source files */
extern const INS_Out_Bus INS_rtZINS_Out_Bus;/* INS_Out_Bus ground */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_TYt7YeNdxIDXfczXumtXXB INS_EXPORT;/* Variable: INS_EXPORT
                                                 * Referenced by:
                                                 *   '<S4>/Constant'
                                                 *   '<S289>/Constant'
                                                 *   '<S319>/Constant'
                                                 *   '<S326>/Constant'
                                                 *   '<S11>/Constant'
                                                 *   '<S12>/Constant'
                                                 *   '<S13>/Constant'
                                                 *   '<S14>/Constant'
                                                 *   '<S15>/Constant'
                                                 *   '<S16>/Constant'
                                                 *   '<S17>/Constant'
                                                 *   '<S306>/Constant'
                                                 *   '<S259>/Constant'
                                                 *   '<S260>/Constant'
                                                 *   '<S271>/Constant'
                                                 *   '<S272>/Constant'
                                                 */

/* Model entry point functions */
extern void INS_init(void);
extern void INS_step(void);

/* Real-time Model object */
extern RT_MODEL_INS_T *const INS_M;

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
 * '<Root>' : 'INS'
 * '<S1>'   : 'INS/Bus_Constructor'
 * '<S2>'   : 'INS/Data_Fusion'
 * '<S3>'   : 'INS/Sensor_PreProcess'
 * '<S4>'   : 'INS/Bus_Constructor/Counter'
 * '<S5>'   : 'INS/Bus_Constructor/Rotation_Output'
 * '<S6>'   : 'INS/Bus_Constructor/Status_Output'
 * '<S7>'   : 'INS/Bus_Constructor/Translation_Output'
 * '<S8>'   : 'INS/Bus_Constructor/Status_Output/INS_Flag'
 * '<S9>'   : 'INS/Bus_Constructor/Status_Output/INS_Quality'
 * '<S10>'  : 'INS/Bus_Constructor/Status_Output/Sensor_Status'
 * '<S11>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1'
 * '<S12>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2'
 * '<S13>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3'
 * '<S14>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4'
 * '<S15>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5'
 * '<S16>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6'
 * '<S17>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8'
 * '<S18>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Compare To Constant'
 * '<S19>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Compare To Constant1'
 * '<S20>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Compare To Constant2'
 * '<S21>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Detect Rise Positive'
 * '<S22>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check1/Detect Rise Positive/Positive'
 * '<S23>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Compare To Constant'
 * '<S24>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Compare To Constant1'
 * '<S25>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Compare To Constant2'
 * '<S26>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Detect Rise Positive'
 * '<S27>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check2/Detect Rise Positive/Positive'
 * '<S28>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Compare To Constant'
 * '<S29>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Compare To Constant1'
 * '<S30>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Compare To Constant2'
 * '<S31>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Detect Rise Positive'
 * '<S32>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check3/Detect Rise Positive/Positive'
 * '<S33>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Compare To Constant'
 * '<S34>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Compare To Constant1'
 * '<S35>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Compare To Constant2'
 * '<S36>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Detect Rise Positive'
 * '<S37>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check4/Detect Rise Positive/Positive'
 * '<S38>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Compare To Constant'
 * '<S39>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Compare To Constant1'
 * '<S40>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Compare To Constant2'
 * '<S41>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Detect Rise Positive'
 * '<S42>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check5/Detect Rise Positive/Positive'
 * '<S43>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Compare To Constant'
 * '<S44>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Compare To Constant1'
 * '<S45>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Compare To Constant2'
 * '<S46>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Detect Rise Positive'
 * '<S47>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check6/Detect Rise Positive/Positive'
 * '<S48>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Compare To Constant'
 * '<S49>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Compare To Constant1'
 * '<S50>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Compare To Constant2'
 * '<S51>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Detect Rise Positive'
 * '<S52>'  : 'INS/Bus_Constructor/Status_Output/INS_Flag/valid_check8/Detect Rise Positive/Positive'
 * '<S53>'  : 'INS/Bus_Constructor/Status_Output/Sensor_Status/Compare To Zero'
 * '<S54>'  : 'INS/Bus_Constructor/Status_Output/Sensor_Status/Compare To Zero1'
 * '<S55>'  : 'INS/Data_Fusion/Rotation_Filter'
 * '<S56>'  : 'INS/Data_Fusion/Translation_Filter'
 * '<S57>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS'
 * '<S58>'  : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess'
 * '<S59>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor'
 * '<S60>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct'
 * '<S61>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update'
 * '<S62>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle'
 * '<S63>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Psi To DCM'
 * '<S64>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle/Quaternion To Euler'
 * '<S65>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle/Quaternion To Euler/Quaternion Normalize'
 * '<S66>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Euler_Angle/Quaternion To Euler/Quaternion Normalize/Quaternion Modulus'
 * '<S67>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Bus_Constructor/Psi To DCM/Rotation Matrix Z'
 * '<S68>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction'
 * '<S69>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction'
 * '<S70>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct'
 * '<S71>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct'
 * '<S72>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct'
 * '<S73>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator'
 * '<S74>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct'
 * '<S75>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct'
 * '<S76>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Cross Product'
 * '<S77>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Cross Product/Subsystem'
 * '<S78>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Cross Product/Subsystem1'
 * '<S79>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross Product'
 * '<S80>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation'
 * '<S81>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Vector Normalize'
 * '<S82>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Vector Normalize1'
 * '<S83>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross Product/Subsystem'
 * '<S84>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross Product/Subsystem1'
 * '<S85>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation/Vector Modulus'
 * '<S86>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Estimate_Acc'
 * '<S87>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc'
 * '<S88>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Estimate_Acc/Second Order LPF'
 * '<S89>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Bus_Selection'
 * '<S90>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Detect Increase'
 * '<S91>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/GPS_Meas_Acc'
 * '<S92>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Valid_Check'
 * '<S93>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Attitude_Correction/Mag_Correct/Subsystem'
 * '<S94>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction/Compare To Constant'
 * '<S95>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction/Second Order LPF'
 * '<S96>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Correct/Gyro_Bias_Correction/Vector Modulus'
 * '<S97>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update'
 * '<S98>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Gyro_Bias_Update'
 * '<S99>'  : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply'
 * '<S100>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Normalize'
 * '<S101>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM'
 * '<S102>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply/q_0'
 * '<S103>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply/q_1'
 * '<S104>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply/q_2'
 * '<S105>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Multiply/q_4'
 * '<S106>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion Normalize/Quaternion Modulus'
 * '<S107>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/Quaternion Normalize'
 * '<S108>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/column_1'
 * '<S109>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/column_2'
 * '<S110>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/column_3'
 * '<S111>' : 'INS/Data_Fusion/Rotation_Filter/AHRS/Update/Attitude_Update/Quaternion To DCM/Quaternion Normalize/Quaternion Modulus'
 * '<S112>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset'
 * '<S113>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude'
 * '<S114>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill'
 * '<S115>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Compare To Constant'
 * '<S116>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Compare To Constant1'
 * '<S117>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Detect Rise Positive'
 * '<S118>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Interval Test'
 * '<S119>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Reset Heading'
 * '<S120>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Vector Modulus'
 * '<S121>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Vector Modulus1'
 * '<S122>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/sample_valid'
 * '<S123>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Detect Rise Positive/Positive'
 * '<S124>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Reset Heading/Detect Rise Positive1'
 * '<S125>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/Reset Heading/Detect Rise Positive1/Positive'
 * '<S126>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Attitude_Reset/sample_valid/valid_samples'
 * '<S127>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product'
 * '<S128>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product1'
 * '<S129>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion'
 * '<S130>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Vector Normalize'
 * '<S131>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Vector Normalize1'
 * '<S132>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Vector Normalize2'
 * '<S133>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product/Subsystem'
 * '<S134>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product/Subsystem1'
 * '<S135>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product1/Subsystem'
 * '<S136>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/Cross Product1/Subsystem1'
 * '<S137>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/DCM Trace'
 * '<S138>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace'
 * '<S139>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace'
 * '<S140>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S141>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S142>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S143>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/diag(DCM)'
 * '<S144>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S145>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S146>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S147>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S148>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S149>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S150>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S151>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S152>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S153>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S154>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S155>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S156>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S157>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S158>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S159>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S160>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S161>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Initial_Attitude/DCM To Quaternion/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S162>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order HPF'
 * '<S163>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order LPF'
 * '<S164>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order LPF1'
 * '<S165>' : 'INS/Data_Fusion/Rotation_Filter/RF_Data_PreProcess/Standstill/First Order HPF/First Order LPF'
 * '<S166>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S167>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess'
 * '<S168>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor'
 * '<S169>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S170>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S171>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select'
 * '<S172>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Bus_Select'
 * '<S173>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Local_Position'
 * '<S174>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/Velocity'
 * '<S175>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position'
 * '<S176>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position/WGS84_Position'
 * '<S177>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position/WGS84_Position/safe_divide'
 * '<S178>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Constructor/Bus_Select/WGS84_Position/WGS84_Position/safe_divide/Zero_Value_Exclusion'
 * '<S179>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S180>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S181>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S182>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S183>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Error_Integrate'
 * '<S184>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Error_Scaling'
 * '<S185>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Estimate_State'
 * '<S186>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S187>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S188>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S189>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Bias_Update'
 * '<S190>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Detect Increase'
 * '<S191>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S192>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S193>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S194>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S195>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S196>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S197>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S198>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S199>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S200>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S201>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S202>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct'
 * '<S203>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S204>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Error_Hold'
 * '<S205>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Error_Scaling'
 * '<S206>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Estimate_States'
 * '<S207>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S208>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation'
 * '<S209>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Bias'
 * '<S210>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S211>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S212>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S213>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Hold'
 * '<S214>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Scaling'
 * '<S215>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Estimate_State'
 * '<S216>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S217>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S218>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S219>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Horizontal_Sensor_Select/Compare To Zero2'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero1'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero4'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/Sensor_Select/Vertical_Sensor_Select/Compare To Zero6'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/Barometer_Meas'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Measures/GPS_Meas'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/Barometer_Status'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Sensor_Process/TF_Sensor_Status/GPS_Status'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive1'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive/Positive'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Filter_Reset/Detect Rise Positive1/Positive'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Bus_Constructor'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Bus_Select'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Height_Ref'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Position_Ref'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Height_Ref/Detect Rise Positive3'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Height_Ref/Detect Rise Positive3/Positive'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Position_Ref/Detect Rise Positive3'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Position_Reference/Position_Ref/Detect Rise Positive3/Positive'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Compare To Constant'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Compare To Constant1'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Compare To Constant2'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Detect Rise Positive'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Compare To Constant'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Compare To Constant1'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Compare To Constant2'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Detect Rise Positive'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Horizon_Sensor_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold'
 * '<S272>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1'
 * '<S273>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Compare To Constant'
 * '<S274>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Compare To Constant1'
 * '<S275>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Compare To Constant2'
 * '<S276>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Detect Rise Positive'
 * '<S277>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S278>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Compare To Constant'
 * '<S279>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Compare To Constant1'
 * '<S280>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Compare To Constant2'
 * '<S281>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Detect Rise Positive'
 * '<S282>' : 'INS/Data_Fusion/Translation_Filter/TF_Data_PreProcess/Transfer_Filter_Control/Sensor_Valid/Vertical_Sensor_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S283>' : 'INS/Sensor_PreProcess/Baro_Process'
 * '<S284>' : 'INS/Sensor_PreProcess/GPS_PreProcess'
 * '<S285>' : 'INS/Sensor_PreProcess/IMU_PreProcess'
 * '<S286>' : 'INS/Sensor_PreProcess/MAG_PreProcess'
 * '<S287>' : 'INS/Sensor_PreProcess/Baro_Process/Pressure_Height'
 * '<S288>' : 'INS/Sensor_PreProcess/Baro_Process/Relative_Height'
 * '<S289>' : 'INS/Sensor_PreProcess/Baro_Process/Sensor_Valid'
 * '<S290>' : 'INS/Sensor_PreProcess/Baro_Process/Relative_Height/Reference_Height'
 * '<S291>' : 'INS/Sensor_PreProcess/Baro_Process/Relative_Height/Sampling'
 * '<S292>' : 'INS/Sensor_PreProcess/Baro_Process/Relative_Height/Sampling/Compare To Constant'
 * '<S293>' : 'INS/Sensor_PreProcess/Baro_Process/Relative_Height/Sampling/Detect Change'
 * '<S294>' : 'INS/Sensor_PreProcess/Baro_Process/Relative_Height/Sampling/Interval Test3'
 * '<S295>' : 'INS/Sensor_PreProcess/Baro_Process/Sensor_Valid/Compare To Constant4'
 * '<S296>' : 'INS/Sensor_PreProcess/Baro_Process/Sensor_Valid/Detect Change'
 * '<S297>' : 'INS/Sensor_PreProcess/Baro_Process/Sensor_Valid/Interval Test1'
 * '<S298>' : 'INS/Sensor_PreProcess/Baro_Process/Sensor_Valid/Interval Test2'
 * '<S299>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Compare To Constant'
 * '<S300>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Compare To Constant1'
 * '<S301>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Data_Scalling'
 * '<S302>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality'
 * '<S303>' : 'INS/Sensor_PreProcess/GPS_PreProcess/WGS84_Model'
 * '<S304>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/Compare To Constant2'
 * '<S305>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status'
 * '<S306>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/check_timeout'
 * '<S307>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/horizontal_quality'
 * '<S308>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/speed_acc'
 * '<S309>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/vertical_quality'
 * '<S310>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Compare To Constant'
 * '<S311>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Compare To Constant1'
 * '<S312>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Ready'
 * '<S313>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/GPS_Status/Ready/valid_samples'
 * '<S314>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/check_timeout/Compare To Constant4'
 * '<S315>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/check_timeout/Detect Change'
 * '<S316>' : 'INS/Sensor_PreProcess/GPS_PreProcess/Status_Quality/speed_acc/Second Order LPF'
 * '<S317>' : 'INS/Sensor_PreProcess/GPS_PreProcess/WGS84_Model/LAT2FLAT Curve'
 * '<S318>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Data_Select'
 * '<S319>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid'
 * '<S320>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S321>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Detect Change'
 * '<S322>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Interval Test1'
 * '<S323>' : 'INS/Sensor_PreProcess/IMU_PreProcess/Sensor_Valid/Interval Test3'
 * '<S324>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Bus_Select'
 * '<S325>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process'
 * '<S326>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid'
 * '<S327>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate'
 * '<S328>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation'
 * '<S329>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_LUT'
 * '<S330>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality'
 * '<S331>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Inclination_Quality_Estimate'
 * '<S332>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Intensity_Quality_Estimate'
 * '<S333>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Second Order LPF'
 * '<S334>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Inclination_Quality_Estimate/Vector Modulus'
 * '<S335>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/Mag_Quality_Estimate/Mag_Quality/Intensity_Quality_Estimate/Vector Modulus'
 * '<S336>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation/Rotation Matrix Z'
 * '<S337>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation/Vector Normalize'
 * '<S338>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Mag_Data_Process/WMM_Compensation/safe_divide'
 * '<S339>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Compare To Constant4'
 * '<S340>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Detect Change'
 * '<S341>' : 'INS/Sensor_PreProcess/MAG_PreProcess/Sensor_Valid/Interval Test1'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
