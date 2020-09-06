/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.2573
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep  6 15:02:14 2020
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
  int32_T headMot;
  uint32_T sAcc;
  uint32_T headAcc;
  uint16_T pDOP;
  uint16_T reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sonar_Bus_
#define DEFINED_TYPEDEF_FOR_Sonar_Bus_

typedef struct {
  uint32_T timestamp_ms;
  real32_T distance_m;
} Sonar_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_
#define DEFINED_TYPEDEF_FOR_Optical_Flow_Bus_

typedef struct {
  uint32_T timestamp_ms;
  real32_T vel_x_mPs;
  real32_T vel_y_mPs;
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
  real_T lon;
  real_T lat;
  real_T alt;
  real32_T x_R;
  real32_T y_R;
  real32_T h_R;
  real32_T h_AGL;
  uint32_T flag;
  uint32_T status;
} INS_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4XfCoaAMTej5uH3d8u88xB_
#define DEFINED_TYPEDEF_FOR_struct_4XfCoaAMTej5uH3d8u88xB_

typedef struct {
  uint32_T period;
} struct_4XfCoaAMTej5uH3d8u88xB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lhdUdNWnbTDz28W0g5GGc_
#define DEFINED_TYPEDEF_FOR_struct_lhdUdNWnbTDz28W0g5GGc_

typedef struct {
  real_T dt;
  real32_T g;
  real_T wmm_mag[629];
  real_T wmm_dec[629];
  real_T wmm_inc[629];
} struct_lhdUdNWnbTDz28W0g5GGc;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_yEHaAuRwDY8DKCecxPQa0D_
#define DEFINED_TYPEDEF_FOR_struct_yEHaAuRwDY8DKCecxPQa0D_

typedef struct {
  real32_T GyroBias[3];
  real32_T GyroRotMat[9];
  real32_T AccBias[3];
  real32_T AccRotMat[9];
  real32_T MagBias[3];
  real32_T MagRotMat[9];
  real32_T GyroBias2[3];
  real32_T GyroRotMat2[9];
  real32_T AccBias2[3];
  real32_T AccRotMat2[9];
  real32_T MagBias2[3];
  real32_T MagRotMat2[9];
  uint8_T USE_EXTERN_FILTER;
} struct_yEHaAuRwDY8DKCecxPQa0D;

#endif

/* Block signals (default storage) */
typedef struct {
  real_T Scalefactor;                  /* '<S298>/Scalefactor' */
  real_T OutportBufferFordz_dh;        /* '<S298>/WGS84_Derivatives' */
  real_T Scalefactor1;                 /* '<S298>/Scalefactor1' */
  real_T Add;                          /* '<S311>/Add' */
  real_T Product4;                     /* '<S311>/Product4' */
  real32_T Divide;                     /* '<S284>/Divide' */
  real32_T gain;                       /* '<S284>/gain' */
  real32_T h_0;                        /* '<S220>/Merge' */
  real32_T vel_D_0;                    /* '<S220>/Merge1' */
  real32_T Sum1[3];                    /* '<S209>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S200>/Sum1' */
  real32_T DataTypeConversion[2];      /* '<S193>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S178>/Sum1' */
  real32_T Reshape[3];                 /* '<S142>/Reshape' */
  real32_T DiscreteTimeIntegrator[3];  /* '<S144>/Discrete-Time Integrator' */
  real32_T Merge[4];                   /* '<S65>/Merge' */
  real32_T OutportBufferForquaternion_0[4];/* '<S61>/DCM_to_quat' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S243>/Delay1' */
  real_T Delay_DSTATE[2];              /* '<S244>/Delay' */
  real_T Delay1_DSTATE_o[2];           /* '<S244>/Delay1' */
  real32_T Delay1_4_DSTATE;            /* '<Root>/Delay1' */
  real32_T Delay1_5_DSTATE;            /* '<Root>/Delay1' */
  real32_T Delay_6_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_8_DSTATE[9];          /* '<Root>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S320>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S320>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_c[3];/* '<S321>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j[3];/* '<S321>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_d;             /* '<S284>/Delay' */
  real32_T Delay2_DSTATE;              /* '<S284>/Delay2' */
  real32_T Delay_8_DSTATE_l[9];        /* '<S56>/Delay' */
  real32_T Delay_9_DSTATE[9];          /* '<S56>/Delay' */
  real32_T Delay_10_DSTATE[3];         /* '<S56>/Delay' */
  real32_T Delay_9_DSTATE_m;           /* '<S57>/Delay' */
  real32_T Delay_10_DSTATE_a;          /* '<S57>/Delay' */
  real32_T Delay_11_DSTATE;            /* '<S57>/Delay' */
  real32_T Delay_DSTATE_b[3];          /* '<S218>/Delay' */
  real32_T Delay_DSTATE_l[6];          /* '<S188>/Delay' */
  real32_T h_delay_DSTATE[75];         /* '<S213>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S213>/vd_delay' */
  real32_T x_delay_DSTATE[5];          /* '<S204>/x_delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S182>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S182>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S182>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S182>/vn_delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S154>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S155>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S138>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S122>/Delay' */
  real32_T DiscreteFIRFilter_states[29];/* '<S124>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S138>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b[2];/* '<S145>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_j[2];/* '<S145>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l[3];/* '<S144>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S144>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S106>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S104>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S105>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S16>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_b3;/* '<S18>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_ca;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_kg;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S17>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S308>/Unit Delay' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S124>/Discrete FIR Filter' */
  uint32_T DelayInput1_DSTATE;         /* '<S360>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_kn;/* '<S357>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S356>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S354>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S339>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S335>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S325>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S314>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_ht;      /* '<S331>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S316>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S310>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S304>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_f;             /* '<S283>/Delay' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S291>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_ev;/* '<S283>/Discrete-Time Integrator' */
  uint32_T Delay1_DSTATE_i;            /* '<S284>/Delay1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S210>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S201>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S179>/Delay Input1' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S215>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S211>/Memory' */
  real32_T Memory_PreviousInput_j;     /* '<S206>/Memory' */
  real32_T Memory_PreviousInput_i[3];  /* '<S202>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S185>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S180>/Memory' */
  real32_T PrevY;                      /* '<S150>/Rate Limiter' */
  uint16_T Delay_DSTATE_i;             /* '<S109>/Delay' */
  uint8_T Delay_DSTATE_dz;             /* '<S357>/Delay' */
  uint8_T Delay_DSTATE_f0;             /* '<S153>/Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S238>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S240>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S245>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S247>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S217>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S208>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S187>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dy;     /* '<S157>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S139>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S112>/Delay Input1' */
  boolean_T Delay_DSTATE_bn;           /* '<S13>/Delay' */
  boolean_T Delay_DSTATE_c;            /* '<S16>/Delay' */
  boolean_T Delay_DSTATE_l0;           /* '<S18>/Delay' */
  boolean_T Delay_DSTATE_cn;           /* '<S12>/Delay' */
  boolean_T Delay_DSTATE_p;            /* '<S14>/Delay' */
  boolean_T Delay_DSTATE_db;           /* '<S15>/Delay' */
  boolean_T Delay_DSTATE_ly;           /* '<S17>/Delay' */
  boolean_T DelayInput1_DSTATE_dx;     /* '<S22>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mu;     /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dq;     /* '<S32>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f4;     /* '<S37>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ng;     /* '<S42>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dql;    /* '<S47>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_fq;     /* '<S52>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S154>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S144>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S144>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S16>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S18>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ar;/* '<S17>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S320>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_a;/* '<S321>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S213>/h_delay' */
  uint8_T icLoad_f;                    /* '<S213>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S204>/x_delay' */
  uint8_T icLoad_o;                    /* '<S182>/x_delay' */
  uint8_T icLoad_i;                    /* '<S182>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S182>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S182>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S154>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_o;/* '<S138>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOA_k;/* '<S145>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_L_oi;/* '<S144>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S141>/Relay' */
  boolean_T Relay1_Mode;               /* '<S146>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S63>/Relay2' */
  boolean_T Reference_and_Derivative_MODE;/* '<S281>/Reference_and_Derivative' */
  boolean_T OpticalFlow_Acc_Observer_MODE;/* '<S123>/OpticalFlow_Acc_Observer' */
  boolean_T GPS_Acc_Observer_MODE;     /* '<S123>/GPS_Acc_Observer' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S275>/WGS84_Model' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S213>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S213>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S204>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S182>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S182>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S182>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S182>/vn_delay1' */
} PrevZCSigStates_INS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  IMU_Bus IMU1;                        /* '<Root>/IMU1' */
  IMU_Bus IMU2;                        /* '<Root>/IMU2' */
  MAG_Bus MAG;                         /* '<Root>/MAG' */
  Barometer_Bus Barometer;             /* '<Root>/Barometer' */
  GPS_uBlox_Bus GPS_uBlox;             /* '<Root>/GPS_uBlox' */
  Sonar_Bus Sonar;                     /* '<Root>/Sonar' */
  Optical_Flow_Bus Optical_Flow;       /* '<Root>/Optical_Flow' */
  uint8_T reset;                       /* '<Root>/reset' */
} ExternalInputs_INS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExternalOutputs_INS_T;

/* Parameters (default storage) */
struct Parameters_INS_T_ {
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S174>/Constant'
                                        */
  real_T wmm_lookup_res;               /* Mask Parameter: wmm_lookup_res
                                        * Referenced by:
                                        *   '<S344>/Gain'
                                        *   '<S344>/Gain6'
                                        */
  real_T Zero_Value_Exclusion_thr;     /* Mask Parameter: Zero_Value_Exclusion_thr
                                        * Referenced by: '<S175>/Saturation'
                                        */
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S309>/Constant'
                                        */
  real32_T IMU1_Valid_Check_acc_max;   /* Mask Parameter: IMU1_Valid_Check_acc_max
                                        * Referenced by: '<S326>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_max;   /* Mask Parameter: IMU2_Valid_Check_acc_max
                                        * Referenced by: '<S332>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_acc_min;   /* Mask Parameter: IMU1_Valid_Check_acc_min
                                        * Referenced by: '<S326>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_min;   /* Mask Parameter: IMU2_Valid_Check_acc_min
                                        * Referenced by: '<S332>/Lower Limit'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S25>/Constant'
                                        */
  real32_T CompareToConstant1_const_g; /* Mask Parameter: CompareToConstant1_const_g
                                        * Referenced by: '<S50>/Constant'
                                        */
  real32_T CompareToConstant1_const_e; /* Mask Parameter: CompareToConstant1_const_e
                                        * Referenced by: '<S20>/Constant'
                                        */
  real32_T CompareToConstant1_const_ei;/* Mask Parameter: CompareToConstant1_const_ei
                                        * Referenced by: '<S30>/Constant'
                                        */
  real32_T CompareToConstant1_const_ec;/* Mask Parameter: CompareToConstant1_const_ec
                                        * Referenced by: '<S35>/Constant'
                                        */
  real32_T CompareToConstant1_const_em;/* Mask Parameter: CompareToConstant1_const_em
                                        * Referenced by: '<S45>/Constant'
                                        */
  real32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S21>/Constant'
                                        */
  real32_T CompareToConstant2_const_c; /* Mask Parameter: CompareToConstant2_const_c
                                        * Referenced by: '<S26>/Constant'
                                        */
  real32_T CompareToConstant2_const_n; /* Mask Parameter: CompareToConstant2_const_n
                                        * Referenced by: '<S31>/Constant'
                                        */
  real32_T CompareToConstant2_const_b; /* Mask Parameter: CompareToConstant2_const_b
                                        * Referenced by: '<S36>/Constant'
                                        */
  real32_T CompareToConstant2_const_l; /* Mask Parameter: CompareToConstant2_const_l
                                        * Referenced by: '<S46>/Constant'
                                        */
  real32_T CompareToConstant2_const_i; /* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S51>/Constant'
                                        */
  real32_T CompareToConstant_const_g;  /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S62>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S107>/Constant'
                                        */
  real32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S149>/Constant'
                                        */
  real32_T CompareToConstant_const_f;  /* Mask Parameter: CompareToConstant_const_f
                                        * Referenced by: '<S358>/Constant'
                                        */
  real32_T IMU1_Valid_Check_gyr_max;   /* Mask Parameter: IMU1_Valid_Check_gyr_max
                                        * Referenced by: '<S327>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_max;   /* Mask Parameter: IMU2_Valid_Check_gyr_max
                                        * Referenced by: '<S333>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_gyr_min;   /* Mask Parameter: IMU1_Valid_Check_gyr_min
                                        * Referenced by: '<S327>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_min;   /* Mask Parameter: IMU2_Valid_Check_gyr_min
                                        * Referenced by: '<S333>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S108>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit_d;    /* Mask Parameter: IntervalTest_lowlimit_d
                                        * Referenced by: '<S361>/Lower Limit'
                                        */
  real32_T Mag_Valid_Check_mag_max;    /* Mask Parameter: Mag_Valid_Check_mag_max
                                        * Referenced by: '<S340>/Upper Limit'
                                        */
  real32_T Mag_Valid_Check_mag_min;    /* Mask Parameter: Mag_Valid_Check_mag_min
                                        * Referenced by: '<S340>/Lower Limit'
                                        */
  real32_T Relative_Height_pressure_max;/* Mask Parameter: Relative_Height_pressure_max
                                         * Referenced by: '<S292>/Upper Limit'
                                         */
  real32_T Relative_Height_pressure_min;/* Mask Parameter: Relative_Height_pressure_min
                                         * Referenced by: '<S292>/Lower Limit'
                                         */
  real32_T Relative_Height_temp_max;   /* Mask Parameter: Relative_Height_temp_max
                                        * Referenced by: '<S293>/Upper Limit'
                                        */
  real32_T Relative_Height_temp_min;   /* Mask Parameter: Relative_Height_temp_min
                                        * Referenced by: '<S293>/Lower Limit'
                                        */
  real32_T valid_check2_time_out;      /* Mask Parameter: valid_check2_time_out
                                        * Referenced by: '<S24>/Constant'
                                        */
  real32_T valid_check5_time_out;      /* Mask Parameter: valid_check5_time_out
                                        * Referenced by: '<S39>/Constant'
                                        */
  real32_T valid_check8_time_out;      /* Mask Parameter: valid_check8_time_out
                                        * Referenced by: '<S49>/Constant'
                                        */
  real32_T valid_check1_time_out;      /* Mask Parameter: valid_check1_time_out
                                        * Referenced by: '<S19>/Constant'
                                        */
  real32_T valid_check3_time_out;      /* Mask Parameter: valid_check3_time_out
                                        * Referenced by: '<S29>/Constant'
                                        */
  real32_T valid_check4_time_out;      /* Mask Parameter: valid_check4_time_out
                                        * Referenced by: '<S34>/Constant'
                                        */
  real32_T valid_check6_time_out;      /* Mask Parameter: valid_check6_time_out
                                        * Referenced by: '<S44>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S108>/Upper Limit'
                                        */
  real32_T IntervalTest_uplimit_a;     /* Mask Parameter: IntervalTest_uplimit_a
                                        * Referenced by: '<S361>/Upper Limit'
                                        */
  uint32_T CompareToConstant_const_pt; /* Mask Parameter: CompareToConstant_const_pt
                                        * Referenced by: '<S285>/Constant'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S289>/Constant'
                                        */
  uint32_T CompareToConstant2_const_a; /* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S307>/Constant'
                                        */
  uint32_T CompareToConstant4_const_e; /* Mask Parameter: CompareToConstant4_const_e
                                        * Referenced by: '<S300>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S305>/Constant'
                                        */
  uint32_T CompareToConstant4_const_k; /* Mask Parameter: CompareToConstant4_const_k
                                        * Referenced by: '<S355>/Constant'
                                        */
  uint32_T CompareToConstant4_const_h; /* Mask Parameter: CompareToConstant4_const_h
                                        * Referenced by: '<S359>/Constant'
                                        */
  uint32_T Relative_Height_s_first;    /* Mask Parameter: Relative_Height_s_first
                                        * Referenced by: '<S286>/Constant'
                                        */
  uint32_T Relative_Height_s_last;     /* Mask Parameter: Relative_Height_s_last
                                        * Referenced by:
                                        *   '<S287>/Constant'
                                        *   '<S288>/Constant'
                                        */
  uint32_T IMU1_Valid_Check_timeout;   /* Mask Parameter: IMU1_Valid_Check_timeout
                                        * Referenced by: '<S324>/Constant'
                                        */
  uint32_T IMU2_Valid_Check_timeout;   /* Mask Parameter: IMU2_Valid_Check_timeout
                                        * Referenced by: '<S330>/Constant'
                                        */
  uint32_T Mag_Valid_Check_timeout;    /* Mask Parameter: Mag_Valid_Check_timeout
                                        * Referenced by: '<S338>/Constant'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S179>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S201>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S210>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S291>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S310>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S325>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_j;       /* Mask Parameter: DetectChange_vinit_j
                                        * Referenced by: '<S331>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S339>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S356>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_k;       /* Mask Parameter: DetectChange_vinit_k
                                        * Referenced by: '<S360>/Delay Input1'
                                        */
  int16_T wmm_lookup_wmm_declination[629];/* Mask Parameter: wmm_lookup_wmm_declination
                                           * Referenced by: '<S344>/Declination Lookup'
                                           */
  uint16_T valid_samples_const;        /* Mask Parameter: valid_samples_const
                                        * Referenced by: '<S113>/Constant'
                                        */
  boolean_T CompareToConstant1_const_j;/* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S40>/Constant'
                                        */
  boolean_T CompareToConstant2_const_io;/* Mask Parameter: CompareToConstant2_const_io
                                         * Referenced by: '<S41>/Constant'
                                         */
  boolean_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S341>/Constant'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S22>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_c;/* Mask Parameter: DetectRisePositive_vinit_c
                                        * Referenced by: '<S27>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_m;/* Mask Parameter: DetectRisePositive_vinit_m
                                        * Referenced by: '<S32>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_k;/* Mask Parameter: DetectRisePositive_vinit_k
                                        * Referenced by: '<S37>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_a;/* Mask Parameter: DetectRisePositive_vinit_a
                                        * Referenced by: '<S42>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_f;/* Mask Parameter: DetectRisePositive_vinit_f
                                        * Referenced by: '<S47>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_l;/* Mask Parameter: DetectRisePositive_vinit_l
                                        * Referenced by: '<S52>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_fc;/* Mask Parameter: DetectRisePositive_vinit_fc
                                         * Referenced by: '<S112>/Delay Input1'
                                         */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S139>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_d;    /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S157>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S187>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S208>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S217>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S238>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_me;/* Mask Parameter: DetectRisePositive_vinit_me
                                         * Referenced by: '<S240>/Delay Input1'
                                         */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S245>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S247>/Delay Input1'
                                         */
  int8_T wmm_lookup_wmm_inclination[629];/* Mask Parameter: wmm_lookup_wmm_inclination
                                          * Referenced by: '<S344>/Inclination Lookup'
                                          */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S306>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S294>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S295>/Constant'
                                        */
  uint8_T CompareToConstant2_const_bv; /* Mask Parameter: CompareToConstant2_const_bv
                                        * Referenced by: '<S299>/Constant'
                                        */
  uint8_T wmm_lookup_wmm_magnitude[629];/* Mask Parameter: wmm_lookup_wmm_magnitude
                                         * Referenced by: '<S344>/Magnitude Lookup'
                                         */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T Constant_Value_i[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S173>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S175>/Saturation'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S243>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S244>/Delay'
                                        */
  real_T Delay1_InitialCondition_e;    /* Expression: 0.0
                                        * Referenced by: '<S244>/Delay1'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S298>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S298>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S298>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S298>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S298>/dz_dh'
                                        */
  real_T Scalefactor_Gain;             /* Expression: 1
                                        * Referenced by: '<S298>/Scalefactor'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S311>/constant1'
                                        */
  real_T Scalefactor1_Gain;            /* Expression: 1
                                        * Referenced by: '<S298>/Scalefactor1'
                                        */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S311>/constant2'
                                        */
  real_T f_Value;                      /* Expression: 1/298.257
                                        * Referenced by: '<S311>/f'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S311>/constant'
                                        */
  real_T a_Value;                      /* Expression: 6378137
                                        * Referenced by: '<S311>/a'
                                        */
  real_T a1_Value;                     /* Expression: 1
                                        * Referenced by: '<S311>/a1'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S308>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S308>/Saturation'
                                        */
  int32_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S308>/Saturation'
                                        */
  int32_T offset_lat_Value;            /* Computed Parameter: offset_lat_Value
                                        * Referenced by: '<S344>/offset_lat'
                                        */
  int32_T Saturation1_UpperSat;        /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S344>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S344>/Saturation1'
                                        */
  int32_T offset_lon_Value;            /* Computed Parameter: offset_lon_Value
                                        * Referenced by: '<S344>/offset_lon'
                                        */
  int32_T Saturation2_UpperSat;        /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S344>/Saturation2'
                                        */
  int32_T Saturation2_LowerSat;        /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S344>/Saturation2'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S297>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S297>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S297>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S297>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain_d;         /* Computed Parameter: Scalefactor1_Gain_d
                                        * Referenced by: '<S297>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S297>/Scalefactor2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S13>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  real32_T Gain10_Gain;                /* Computed Parameter: Gain10_Gain
                                        * Referenced by: '<S8>/Gain10'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_i;/* Computed Parameter: DiscreteTimeIntegrator_IC_i
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                            * Referenced by: '<S18>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_o;/* Computed Parameter: DiscreteTimeIntegrator_IC_o
                                        * Referenced by: '<S18>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_j;/* Computed Parameter: DiscreteTimeIntegrator_IC_j
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_me;/* Computed Parameter: DiscreteTimeIntegrator_gainv_me
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ig;/* Computed Parameter: DiscreteTimeIntegrator_IC_ig
                                         * Referenced by: '<S15>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_gainv_my;/* Computed Parameter: DiscreteTimeIntegrator_gainv_my
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_e;/* Computed Parameter: DiscreteTimeIntegrator_IC_e
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S12>/Constant'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S13>/Constant'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S14>/Constant'
                                        */
  real32_T Constant_Value_ih;          /* Computed Parameter: Constant_Value_ih
                                        * Referenced by: '<S15>/Constant'
                                        */
  real32_T Constant_Value_kn;          /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S16>/Constant'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S17>/Constant'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T Constant_Value_jj;          /* Computed Parameter: Constant_Value_jj
                                        * Referenced by: '<S55>/Constant'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S72>/Constant'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S72>/Gain'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S72>/Gain1'
                                        */
  real32_T Constant2_Value[2];         /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S86>/Constant2'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S86>/Constant1'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S87>/Constant'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S75>/Gain'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S75>/Gain1'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S75>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S75>/Gain4'
                                        */
  real32_T Constant2_Value_i[2];       /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S91>/Constant2'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S91>/Constant1'
                                        */
  real32_T Constant_Value_jf;          /* Computed Parameter: Constant_Value_jf
                                        * Referenced by: '<S92>/Constant'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S76>/Gain'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real32_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S76>/Gain2'
                                        */
  real32_T Gain3_Gain_l;               /* Computed Parameter: Gain3_Gain_l
                                        * Referenced by: '<S76>/Gain3'
                                        */
  real32_T Constant2_Value_g[2];       /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S81>/Constant2'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S82>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S74>/Gain'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S74>/Gain2'
                                        */
  real32_T Gain3_Gain_d;               /* Computed Parameter: Gain3_Gain_d
                                        * Referenced by: '<S74>/Gain3'
                                        */
  real32_T quaternion_0_Y0[4];         /* Computed Parameter: quaternion_0_Y0
                                        * Referenced by: '<S61>/quaternion_0'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S61>/Gain'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S68>/Constant2'
                                        */
  real32_T Constant2_Value_m;          /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S69>/Constant2'
                                        */
  real32_T Constant2_Value_gc;         /* Computed Parameter: Constant2_Value_gc
                                        * Referenced by: '<S70>/Constant2'
                                        */
  real32_T Merge_InitialOutput[4];     /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S65>/Merge'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<S106>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC; /* Computed Parameter: DiscreteTimeIntegrator5_IC
                                        * Referenced by: '<S106>/Discrete-Time Integrator5'
                                        */
  real32_T Gain2_Gain_h;               /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S106>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_o;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_o
                                            * Referenced by: '<S104>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_m;/* Computed Parameter: DiscreteTimeIntegrator5_IC_m
                                         * Referenced by: '<S104>/Discrete-Time Integrator5'
                                         */
  real32_T Gain2_Gain_c;               /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S104>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_b;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_b
                                            * Referenced by: '<S105>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_a;/* Computed Parameter: DiscreteTimeIntegrator5_IC_a
                                         * Referenced by: '<S105>/Discrete-Time Integrator5'
                                         */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S63>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S63>/Saturation2'
                                        */
  real32_T Gain2_Gain_f;               /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S105>/Gain2'
                                        */
  real32_T Relay2_OnVal;               /* Computed Parameter: Relay2_OnVal
                                        * Referenced by: '<S63>/Relay2'
                                        */
  real32_T Relay2_OffVal;              /* Computed Parameter: Relay2_OffVal
                                        * Referenced by: '<S63>/Relay2'
                                        */
  real32_T Relay2_YOn;                 /* Computed Parameter: Relay2_YOn
                                        * Referenced by: '<S63>/Relay2'
                                        */
  real32_T Relay2_YOff;                /* Computed Parameter: Relay2_YOff
                                        * Referenced by: '<S63>/Relay2'
                                        */
  real32_T Constant_Value_fk;          /* Computed Parameter: Constant_Value_fk
                                        * Referenced by: '<S134>/Constant'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S135>/Constant'
                                        */
  real32_T GPS_acc_O_mPs2_Y0;          /* Computed Parameter: GPS_acc_O_mPs2_Y0
                                        * Referenced by: '<S140>/GPS_acc_O_mPs2'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S144>/Discrete-Time Integrator1'
                                            */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S144>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_i0;/* Computed Parameter: DiscreteTimeIntegrator_gainv_i0
                                            * Referenced by: '<S144>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S144>/Discrete-Time Integrator'
                                        */
  real32_T Gain3_Gain_p;               /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S144>/Gain3'
                                        */
  real32_T OptFlow_acc_O_mPs2_Y0;      /* Computed Parameter: OptFlow_acc_O_mPs2_Y0
                                        * Referenced by: '<S142>/OptFlow_acc_O_mPs2'
                                        */
  real32_T Constant_Value_gi;          /* Computed Parameter: Constant_Value_gi
                                        * Referenced by: '<S142>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                                            * Referenced by: '<S145>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC; /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<S145>/Discrete-Time Integrator1'
                                        */
  real32_T Gain2_Gain_b;               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S145>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                            * Referenced by: '<S145>/Discrete-Time Integrator'
                                            */
  real32_T Gain3_Gain_i;               /* Computed Parameter: Gain3_Gain_i
                                        * Referenced by: '<S145>/Gain3'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S124>/Constant'
                                        */
  real32_T Constant1_Value_cx;         /* Computed Parameter: Constant1_Value_cx
                                        * Referenced by: '<S124>/Constant1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                            * Referenced by: '<S138>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S141>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S141>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S141>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S141>/Relay'
                                        */
  real32_T Delay_InitialCondition_m;   /* Computed Parameter: Delay_InitialCondition_m
                                        * Referenced by: '<S122>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Expression: [0;0;-INS_CONST.g]
                                        * Referenced by: '<S143>/gravity'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S124>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S124>/Dead Zone2'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S128>/Constant1'
                                        */
  real32_T Constant_Value_ew;          /* Computed Parameter: Constant_Value_ew
                                        * Referenced by: '<S128>/Constant'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S128>/Gain'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S128>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S128>/Saturation'
                                        */
  real32_T DiscreteFIRFilter_InitialStates;/* Computed Parameter: DiscreteFIRFilter_InitialStates
                                            * Referenced by: '<S124>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficients[30];/* Computed Parameter: DiscreteFIRFilter_Coefficients
                                               * Referenced by: '<S124>/Discrete FIR Filter'
                                               */
  real32_T Saturation_UpperSat_k;      /* Computed Parameter: Saturation_UpperSat_k
                                        * Referenced by: '<S124>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S124>/Saturation'
                                        */
  real32_T Gain_Gain_oh;               /* Computed Parameter: Gain_Gain_oh
                                        * Referenced by: '<S124>/Gain'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S134>/Switch'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S135>/Switch'
                                        */
  real32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S125>/Constant8'
                                        */
  real32_T Saturation_UpperSat_e;      /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S133>/Saturation'
                                        */
  real32_T Saturation_LowerSat_f;      /* Computed Parameter: Saturation_LowerSat_f
                                        * Referenced by: '<S133>/Saturation'
                                        */
  real32_T Constant1_Value_nm;         /* Computed Parameter: Constant1_Value_nm
                                        * Referenced by: '<S133>/Constant1'
                                        */
  real32_T Gain_Gain_ok[3];            /* Computed Parameter: Gain_Gain_ok
                                        * Referenced by: '<S125>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                            * Referenced by: '<S138>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_d;/* Computed Parameter: DiscreteTimeIntegrator_IC_d
                                        * Referenced by: '<S138>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S138>/Gain1'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S138>/Gain'
                                        */
  real32_T Relay1_OnVal;               /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<S146>/Relay1'
                                        */
  real32_T Relay1_OffVal;              /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<S146>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S146>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S146>/Relay1'
                                        */
  real32_T mag_correct_gain_Gain;      /* Computed Parameter: mag_correct_gain_Gain
                                        * Referenced by: '<S147>/mag_correct_gain'
                                        */
  real32_T Constant_Value_n2;          /* Computed Parameter: Constant_Value_n2
                                        * Referenced by: '<S118>/Constant'
                                        */
  real32_T Gain3_Gain_k;               /* Computed Parameter: Gain3_Gain_k
                                        * Referenced by: '<S118>/Gain3'
                                        */
  real32_T Saturation1_UpperSat_p;     /* Computed Parameter: Saturation1_UpperSat_p
                                        * Referenced by: '<S150>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_j;     /* Computed Parameter: Saturation1_LowerSat_j
                                        * Referenced by: '<S150>/Saturation1'
                                        */
  real32_T RateLimiter_RisingLim;      /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S150>/Rate Limiter'
                                        */
  real32_T RateLimiter_FallingLim;     /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S150>/Rate Limiter'
                                        */
  real32_T RateLimiter_IC;             /* Computed Parameter: RateLimiter_IC
                                        * Referenced by: '<S150>/Rate Limiter'
                                        */
  real32_T Saturation_UpperSat_ky;     /* Computed Parameter: Saturation_UpperSat_ky
                                        * Referenced by: '<S150>/Saturation'
                                        */
  real32_T Saturation_LowerSat_f3;     /* Computed Parameter: Saturation_LowerSat_f3
                                        * Referenced by: '<S150>/Saturation'
                                        */
  real32_T Gain4_Gain_d;               /* Computed Parameter: Gain4_Gain_d
                                        * Referenced by: '<S118>/Gain4'
                                        */
  real32_T Saturation2_UpperSat_h;     /* Computed Parameter: Saturation2_UpperSat_h
                                        * Referenced by: '<S118>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_o;     /* Computed Parameter: Saturation2_LowerSat_o
                                        * Referenced by: '<S118>/Saturation2'
                                        */
  real32_T Constant_Value_pu;          /* Computed Parameter: Constant_Value_pu
                                        * Referenced by: '<S154>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S154>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S155>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S155>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S155>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S155>/Discrete-Time Integrator2'
                                            */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S154>/Gain2'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S159>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S159>/Gain1'
                                        */
  real32_T Gain2_Gain_oj;              /* Computed Parameter: Gain2_Gain_oj
                                        * Referenced by: '<S159>/Gain2'
                                        */
  real32_T Gain3_Gain_dx;              /* Computed Parameter: Gain3_Gain_dx
                                        * Referenced by: '<S159>/Gain3'
                                        */
  real32_T Gain4_Gain_o;               /* Computed Parameter: Gain4_Gain_o
                                        * Referenced by: '<S159>/Gain4'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S159>/Gain5'
                                        */
  real32_T Gain5_Gain_d;               /* Computed Parameter: Gain5_Gain_d
                                        * Referenced by: '<S163>/Gain5'
                                        */
  real32_T Saturation1_UpperSat_o;     /* Computed Parameter: Saturation1_UpperSat_o
                                        * Referenced by: '<S163>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_b;     /* Computed Parameter: Saturation1_LowerSat_b
                                        * Referenced by: '<S163>/Saturation1'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S165>/Gain'
                                        */
  real32_T Constant1_Value_g;          /* Expression: single(0)
                                        * Referenced by: '<S164>/Constant1'
                                        */
  real32_T Constant_Value_ev;          /* Expression: single(1)
                                        * Referenced by: '<S164>/Constant'
                                        */
  real32_T Gain_Gain_i;                /* Expression: single(-1)
                                        * Referenced by: '<S164>/Gain'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S172>/Constant'
                                        */
  real32_T Constant_Value_aq;          /* Computed Parameter: Constant_Value_aq
                                        * Referenced by: '<S166>/Constant'
                                        */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S183>/Gain1'
                                        */
  real32_T Gain_Gain_o0;               /* Computed Parameter: Gain_Gain_o0
                                        * Referenced by: '<S183>/Gain'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S183>/Gain2'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S178>/X_Next'
                                        */
  real32_T Memory_InitialCondition[2]; /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S185>/Memory'
                                        */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S180>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S180>/Gain3'
                                        */
  real32_T Constant_Value_b[2];        /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S190>/Constant'
                                        */
  real32_T X_0_Y0;                     /* Computed Parameter: X_0_Y0
                                        * Referenced by: '<S193>/X_0'
                                        */
  real32_T Gain1_Gain_en;              /* Computed Parameter: Gain1_Gain_en
                                        * Referenced by: '<S205>/Gain1'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S205>/Gain'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S200>/X_Next'
                                        */
  real32_T Memory_InitialCondition_m;  /* Computed Parameter: Memory_InitialCondition_m
                                        * Referenced by: '<S206>/Memory'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S205>/Gain2'
                                        */
  real32_T Memory_InitialCondition_j;  /* Computed Parameter: Memory_InitialCondition_j
                                        * Referenced by: '<S202>/Memory'
                                        */
  real32_T Gain_Gain_p;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S202>/Gain'
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
                                        * Referenced by: '<S209>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S215>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S211>/Memory'
                                        */
  real32_T Gain3_Gain_kn;              /* Expression: INS_CONST.dt
                                        * Referenced by: '<S211>/Gain3'
                                        */
  real32_T Constant_Value_eq;          /* Computed Parameter: Constant_Value_eq
                                        * Referenced by: '<S220>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S224>/Constant'
                                        */
  real32_T Constant_Value_km;          /* Computed Parameter: Constant_Value_km
                                        * Referenced by: '<S226>/Constant'
                                        */
  real32_T Merge_InitialOutput_j;      /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S220>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S220>/Merge1'
                                        */
  real32_T Delay_InitialCondition_mt;  /* Computed Parameter: Delay_InitialCondition_mt
                                        * Referenced by: '<S218>/Delay'
                                        */
  real32_T Gain1_Gain_kw;              /* Computed Parameter: Gain1_Gain_kw
                                        * Referenced by: '<S219>/Gain1'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S219>/Constant1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S219>/Constant'
                                        */
  real32_T Gain_Gain_mr;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S219>/Gain'
                                        */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S188>/Delay'
                                        */
  real32_T Constant_Value_l[2];        /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S189>/Constant'
                                        */
  real32_T Gain_Gain_ic;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S189>/Gain'
                                        */
  real32_T Constant_Value_be;          /* Computed Parameter: Constant_Value_be
                                        * Referenced by: '<S265>/Constant'
                                        */
  real32_T Constant_Value_o0;          /* Computed Parameter: Constant_Value_o0
                                        * Referenced by: '<S264>/Constant'
                                        */
  real32_T Constant_Value_mi;          /* Computed Parameter: Constant_Value_mi
                                        * Referenced by: '<S251>/Constant'
                                        */
  real32_T Constant_Value_ab;          /* Computed Parameter: Constant_Value_ab
                                        * Referenced by: '<S252>/Constant'
                                        */
  real32_T Constant_Value_ao;          /* Computed Parameter: Constant_Value_ao
                                        * Referenced by: '<S256>/Constant'
                                        */
  real32_T Constant_Value_ek;          /* Computed Parameter: Constant_Value_ek
                                        * Referenced by: '<S257>/Constant'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S250>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S250>/Saturation'
                                        */
  real32_T Constant_Value_hv;          /* Computed Parameter: Constant_Value_hv
                                        * Referenced by: '<S258>/Constant'
                                        */
  real32_T Constant_Value_h4;          /* Computed Parameter: Constant_Value_h4
                                        * Referenced by: '<S259>/Constant'
                                        */
  real32_T Saturation1_UpperSat_i;     /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S250>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_jb;    /* Computed Parameter: Saturation1_LowerSat_jb
                                        * Referenced by: '<S250>/Saturation1'
                                        */
  real32_T Constant_Value_iw;          /* Computed Parameter: Constant_Value_iw
                                        * Referenced by: '<S260>/Constant'
                                        */
  real32_T Delay_8_InitialCondition;   /* Computed Parameter: Delay_8_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_9_InitialCondition;   /* Computed Parameter: Delay_9_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_10_InitialCondition;  /* Computed Parameter: Delay_10_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_9_InitialCondition_h; /* Computed Parameter: Delay_9_InitialCondition_h
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_10_InitialCondition_h;/* Computed Parameter: Delay_10_InitialCondition_h
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_11_InitialCondition;  /* Computed Parameter: Delay_11_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T pressure_R_Y0;              /* Computed Parameter: pressure_R_Y0
                                        * Referenced by: '<S284>/pressure_R'
                                        */
  real32_T dh_dp_Y0;                   /* Computed Parameter: dh_dp_Y0
                                        * Referenced by: '<S284>/dh_dp'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S284>/Constant2'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S284>/Delay'
                                        */
  real32_T Delay2_InitialCondition;    /* Computed Parameter: Delay2_InitialCondition
                                        * Referenced by: '<S284>/Delay2'
                                        */
  real32_T Saturation_UpperSat_m;      /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S284>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S284>/Saturation'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S284>/gain'
                                        */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S303>/Constant7'
                                        */
  real32_T Gain3_Gain_lx;              /* Computed Parameter: Gain3_Gain_lx
                                        * Referenced by: '<S303>/Gain3'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S296>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S296>/Saturation'
                                        */
  real32_T Constant1_Value_g5;         /* Computed Parameter: Constant1_Value_g5
                                        * Referenced by: '<S302>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S302>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S296>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S296>/Saturation1'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_kc;/* Computed Parameter: DiscreteTimeIntegrator_gainv_kc
                                            * Referenced by: '<S320>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_c;/* Computed Parameter: DiscreteTimeIntegrator_IC_c
                                        * Referenced by: '<S320>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_kl;              /* Computed Parameter: Gain1_Gain_kl
                                        * Referenced by: '<S320>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_i;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_i
                                            * Referenced by: '<S320>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_mz;               /* Computed Parameter: Gain_Gain_mz
                                        * Referenced by: '<S320>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_mk;/* Computed Parameter: DiscreteTimeIntegrator_gainv_mk
                                            * Referenced by: '<S321>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_n;/* Computed Parameter: DiscreteTimeIntegrator_IC_n
                                        * Referenced by: '<S321>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_e1;              /* Computed Parameter: Gain1_Gain_e1
                                        * Referenced by: '<S321>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_p;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_p
                                            * Referenced by: '<S321>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_m2;               /* Computed Parameter: Gain_Gain_m2
                                        * Referenced by: '<S321>/Gain'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S342>/default_mag_quality'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S347>/Nominal_Magnitude'
                                        */
  real32_T gain_Gain_m;                /* Computed Parameter: gain_Gain_m
                                        * Referenced by: '<S347>/gain'
                                        */
  real32_T Constant1_Value_cq;         /* Computed Parameter: Constant1_Value_cq
                                        * Referenced by: '<S347>/Constant1'
                                        */
  real32_T Saturation_UpperSat_gv;     /* Computed Parameter: Saturation_UpperSat_gv
                                        * Referenced by: '<S347>/Saturation'
                                        */
  real32_T Saturation_LowerSat_pf;     /* Computed Parameter: Saturation_LowerSat_pf
                                        * Referenced by: '<S347>/Saturation'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S346>/gain'
                                        */
  real32_T Constant2_Value_hh;         /* Computed Parameter: Constant2_Value_hh
                                        * Referenced by: '<S346>/Constant2'
                                        */
  real32_T Saturation_UpperSat_gg;     /* Computed Parameter: Saturation_UpperSat_gg
                                        * Referenced by: '<S346>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S346>/Saturation'
                                        */
  real32_T Constant_Value_g2;          /* Computed Parameter: Constant_Value_g2
                                        * Referenced by: '<S353>/Constant'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S334>/Gauss_to_uT'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S352>/Constant3'
                                        */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S352>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S352>/Constant4'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S352>/Constant2'
                                        */
  real32_T Constant1_Value_c2;         /* Computed Parameter: Constant1_Value_c2
                                        * Referenced by: '<S352>/Constant1'
                                        */
  real32_T Constant_Value_cl;          /* Computed Parameter: Constant_Value_cl
                                        * Referenced by: '<S352>/Constant'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S343>/Constant1'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S353>/Switch'
                                        */
  real32_T Constant_Value_bg;          /* Computed Parameter: Constant_Value_bg
                                        * Referenced by: '<S278>/Constant'
                                        */
  real32_T Constant_Value_jp;          /* Computed Parameter: Constant_Value_jp
                                        * Referenced by: '<S354>/Constant'
                                        */
  real32_T Delay1_4_InitialCondition;  /* Computed Parameter: Delay1_4_InitialCondition
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real32_T Delay1_5_InitialCondition;  /* Computed Parameter: Delay1_5_InitialCondition
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real32_T Delay_6_InitialCondition;   /* Computed Parameter: Delay_6_InitialCondition
                                        * Referenced by: '<Root>/Delay'
                                        */
  real32_T Delay_8_InitialCondition_m; /* Computed Parameter: Delay_8_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Gain5_Gain_a;               /* Computed Parameter: Gain5_Gain_a
                                        * Referenced by: '<S303>/Gain5'
                                        */
  uint32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S302>/Gain1'
                                        */
  uint32_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S13>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S16>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S18>/Delay'
                                        */
  uint32_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint32_T Delay_DelayLength_lg;       /* Computed Parameter: Delay_DelayLength_lg
                                        * Referenced by: '<S14>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S15>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S17>/Delay'
                                        */
  uint32_T Delay_DelayLength_fi;       /* Computed Parameter: Delay_DelayLength_fi
                                        * Referenced by: '<S109>/Delay'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S153>/Delay'
                                        */
  uint32_T x_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S182>/x_delay'
                                        */
  uint32_T x_delay1_DelayLength;       /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S182>/x_delay1'
                                        */
  uint32_T vn_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S182>/vn_delay'
                                        */
  uint32_T vn_delay1_DelayLength;      /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S182>/vn_delay1'
                                        */
  uint32_T x_delay_DelayLength_m;      /* Expression: 10/INS_EXPORT.period
                                        * Referenced by: '<S204>/x_delay'
                                        */
  uint32_T h_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S213>/h_delay'
                                        */
  uint32_T vd_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S213>/vd_delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S218>/Delay'
                                        */
  uint32_T Delay_DelayLength_ly;       /* Computed Parameter: Delay_DelayLength_ly
                                        * Referenced by: '<S188>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S243>/Delay1'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S244>/Delay'
                                        */
  uint32_T Delay1_DelayLength_o;       /* Computed Parameter: Delay1_DelayLength_o
                                        * Referenced by: '<S244>/Delay1'
                                        */
  uint32_T Delay_8_DelayLength;        /* Computed Parameter: Delay_8_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_9_DelayLength;        /* Computed Parameter: Delay_9_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_10_DelayLength;       /* Computed Parameter: Delay_10_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_9_DelayLength_i;      /* Computed Parameter: Delay_9_DelayLength_i
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_10_DelayLength_i;     /* Computed Parameter: Delay_10_DelayLength_i
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_11_DelayLength;       /* Computed Parameter: Delay_11_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Constant1_Value_f5;         /* Computed Parameter: Constant1_Value_f5
                                        * Referenced by: '<S284>/Constant1'
                                        */
  uint32_T Delay_DelayLength_jx;       /* Computed Parameter: Delay_DelayLength_jx
                                        * Referenced by: '<S284>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S284>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition_k;  /* Computed Parameter: Delay1_InitialCondition_k
                                        * Referenced by: '<S284>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S284>/Delay2'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S284>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S284>/Saturation1'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S283>/Delay'
                                        */
  uint32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S283>/Delay'
                                        */
  uint32_T Constant_Value_in;          /* Computed Parameter: Constant_Value_in
                                        * Referenced by: '<S290>/Constant'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_dv;/* Computed Parameter: DiscreteTimeIntegrator_IC_dv
                                         * Referenced by: '<S283>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S304>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S314>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_pw;/* Computed Parameter: DiscreteTimeIntegrator_IC_pw
                                         * Referenced by: '<S316>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S335>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S354>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_pt;/* Computed Parameter: DiscreteTimeIntegrator_IC_pt
                                         * Referenced by: '<S357>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S357>/Delay'
                                        */
  uint32_T Delay1_4_DelayLength;       /* Computed Parameter: Delay1_4_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint32_T Delay1_5_DelayLength;       /* Computed Parameter: Delay1_5_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint32_T Delay_6_DelayLength;        /* Computed Parameter: Delay_6_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay_8_DelayLength_g;      /* Computed Parameter: Delay_8_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  int16_T Gain_Gain_fs;                /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S343>/Gain'
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
  uint16_T Delay_InitialCondition_n0;  /* Computed Parameter: Delay_InitialCondition_n0
                                        * Referenced by: '<S109>/Delay'
                                        */
  uint16_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S109>/Saturation'
                                        */
  uint16_T Saturation_LowerSat_hb;     /* Computed Parameter: Saturation_LowerSat_hb
                                        * Referenced by: '<S109>/Saturation'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S143>/GPS_Delay'
                                        */
  uint16_T OptFlow_Delay_Value;        /* Computed Parameter: OptFlow_Delay_Value
                                        * Referenced by: '<S143>/OptFlow_Delay'
                                        */
  boolean_T Delay_InitialCondition_go; /* Computed Parameter: Delay_InitialCondition_go
                                        * Referenced by: '<S13>/Delay'
                                        */
  boolean_T Delay_InitialCondition_mz; /* Computed Parameter: Delay_InitialCondition_mz
                                        * Referenced by: '<S16>/Delay'
                                        */
  boolean_T Delay_InitialCondition_a;  /* Computed Parameter: Delay_InitialCondition_a
                                        * Referenced by: '<S18>/Delay'
                                        */
  boolean_T Delay_InitialCondition_c;  /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S12>/Delay'
                                        */
  boolean_T Delay_InitialCondition_cj; /* Computed Parameter: Delay_InitialCondition_cj
                                        * Referenced by: '<S14>/Delay'
                                        */
  boolean_T Delay_InitialCondition_ae; /* Computed Parameter: Delay_InitialCondition_ae
                                        * Referenced by: '<S15>/Delay'
                                        */
  boolean_T Delay_InitialCondition_e;  /* Computed Parameter: Delay_InitialCondition_e
                                        * Referenced by: '<S17>/Delay'
                                        */
  boolean_T Constant_Value_mt;         /* Computed Parameter: Constant_Value_mt
                                        * Referenced by: '<S23>/Constant'
                                        */
  boolean_T Constant_Value_m2;         /* Computed Parameter: Constant_Value_m2
                                        * Referenced by: '<S28>/Constant'
                                        */
  boolean_T Constant_Value_o2;         /* Computed Parameter: Constant_Value_o2
                                        * Referenced by: '<S33>/Constant'
                                        */
  boolean_T Constant_Value_hk;         /* Computed Parameter: Constant_Value_hk
                                        * Referenced by: '<S38>/Constant'
                                        */
  boolean_T Constant_Value_l1;         /* Computed Parameter: Constant_Value_l1
                                        * Referenced by: '<S43>/Constant'
                                        */
  boolean_T Constant_Value_m2n;        /* Computed Parameter: Constant_Value_m2n
                                        * Referenced by: '<S48>/Constant'
                                        */
  boolean_T Constant_Value_aoo;        /* Computed Parameter: Constant_Value_aoo
                                        * Referenced by: '<S53>/Constant'
                                        */
  boolean_T Constant_Value_af;         /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S114>/Constant'
                                        */
  boolean_T Constant_Value_bt;         /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S239>/Constant'
                                        */
  boolean_T Constant_Value_gn;         /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S241>/Constant'
                                        */
  boolean_T Constant_Value_m3;         /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S246>/Constant'
                                        */
  boolean_T Constant_Value_pt;         /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S248>/Constant'
                                        */
  boolean_T Constant_Value_cz;         /* Computed Parameter: Constant_Value_cz
                                        * Referenced by: '<S253>/Constant'
                                        */
  boolean_T Constant_Value_p2;         /* Computed Parameter: Constant_Value_p2
                                        * Referenced by: '<S254>/Constant'
                                        */
  boolean_T Constant_Value_hvm;        /* Computed Parameter: Constant_Value_hvm
                                        * Referenced by: '<S255>/Constant'
                                        */
  int8_T Gain1_Gain_o;                 /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S346>/Gain1'
                                        */
  uint8_T Gain7_Gain;                  /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S11>/Gain7'
                                        */
  uint8_T Gain5_Gain_o;                /* Computed Parameter: Gain5_Gain_o
                                        * Referenced by: '<S11>/Gain5'
                                        */
  uint8_T Gain4_Gain_p;                /* Computed Parameter: Gain4_Gain_p
                                        * Referenced by: '<S11>/Gain4'
                                        */
  uint8_T Gain3_Gain_f;                /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S11>/Gain3'
                                        */
  uint8_T Gain2_Gain_ha;               /* Computed Parameter: Gain2_Gain_ha
                                        * Referenced by: '<S11>/Gain2'
                                        */
  uint8_T Gain_Gain_g;                 /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S150>/Gain'
                                        */
  uint8_T Gain_Gain_od;                /* Computed Parameter: Gain_Gain_od
                                        * Referenced by: '<S319>/Gain'
                                        */
  uint8_T Gain9_Gain;                  /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S8>/Gain9'
                                        */
  uint8_T Saturation_UpperSat_d;       /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S141>/Saturation'
                                        */
  uint8_T Saturation_LowerSat_b;       /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S141>/Saturation'
                                        */
  uint8_T Constant_Value_mm;           /* Computed Parameter: Constant_Value_mm
                                        * Referenced by: '<S153>/Constant'
                                        */
  uint8_T Delay_InitialCondition_k;    /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S153>/Delay'
                                        */
  uint8_T Constant_Value_jz;           /* Computed Parameter: Constant_Value_jz
                                        * Referenced by: '<S168>/Constant'
                                        */
  uint8_T Switch_Threshold_c;          /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S323>/Switch'
                                        */
  uint8_T Switch_Threshold_k;          /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S322>/Switch'
                                        */
  uint8_T Constant_Value_jn;           /* Computed Parameter: Constant_Value_jn
                                        * Referenced by: '<S317>/Constant'
                                        */
  uint8_T Switch2_Threshold;           /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S318>/Switch2'
                                        */
  uint8_T Switch3_Threshold;           /* Computed Parameter: Switch3_Threshold
                                        * Referenced by: '<S318>/Switch3'
                                        */
  uint8_T Constant1_Value_l;           /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S357>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_cg;   /* Computed Parameter: Delay_InitialCondition_cg
                                        * Referenced by: '<S357>/Delay'
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
extern struct_yEHaAuRwDY8DKCecxPQa0D INS_PARAM;/* Variable: INS_PARAM
                                                * Referenced by:
                                                *   '<S318>/Constant'
                                                *   '<S322>/Acc_Bias'
                                                *   '<S322>/Acc_RotMatrix'
                                                *   '<S322>/Constant'
                                                *   '<S323>/Constant'
                                                *   '<S323>/Gyr_RotMatrix'
                                                *   '<S323>/Gyro_Bias'
                                                *   '<S328>/Acc_Bias'
                                                *   '<S328>/Acc_RotMatrix'
                                                *   '<S329>/Gyr_RotMatrix'
                                                *   '<S329>/Gyro_Bias'
                                                *   '<S337>/Mag_Bias'
                                                *   '<S337>/Mag_RotMatrix'
                                                */
extern struct_4XfCoaAMTej5uH3d8u88xB INS_EXPORT;/* Variable: INS_EXPORT
                                                 * Referenced by:
                                                 *   '<S4>/Constant'
                                                 *   '<S314>/Constant'
                                                 *   '<S316>/Constant'
                                                 *   '<S335>/Constant'
                                                 *   '<S357>/Constant'
                                                 *   '<S283>/Constant'
                                                 *   '<S304>/Constant'
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
 * '<S1>'   : 'INS/Bus_Assignment'
 * '<S2>'   : 'INS/Data_Fusion'
 * '<S3>'   : 'INS/Sensor_Process'
 * '<S4>'   : 'INS/Bus_Assignment/Counter'
 * '<S5>'   : 'INS/Bus_Assignment/Rotation_Output'
 * '<S6>'   : 'INS/Bus_Assignment/Status_Output'
 * '<S7>'   : 'INS/Bus_Assignment/Translation_Output'
 * '<S8>'   : 'INS/Bus_Assignment/Status_Output/INS_Flag'
 * '<S9>'   : 'INS/Bus_Assignment/Status_Output/INS_Quality'
 * '<S10>'  : 'INS/Bus_Assignment/Status_Output/INS_Ready'
 * '<S11>'  : 'INS/Bus_Assignment/Status_Output/Sensor_Status'
 * '<S12>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1'
 * '<S13>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2'
 * '<S14>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3'
 * '<S15>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4'
 * '<S16>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5'
 * '<S17>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6'
 * '<S18>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check8'
 * '<S19>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Compare To Constant'
 * '<S20>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Compare To Constant1'
 * '<S21>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Compare To Constant2'
 * '<S22>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Detect Rise Positive'
 * '<S23>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Detect Rise Positive/Positive'
 * '<S24>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Compare To Constant'
 * '<S25>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Compare To Constant1'
 * '<S26>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Compare To Constant2'
 * '<S27>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Detect Rise Positive'
 * '<S28>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Detect Rise Positive/Positive'
 * '<S29>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Compare To Constant'
 * '<S30>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Compare To Constant1'
 * '<S31>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Compare To Constant2'
 * '<S32>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Detect Rise Positive'
 * '<S33>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Detect Rise Positive/Positive'
 * '<S34>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Compare To Constant'
 * '<S35>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Compare To Constant1'
 * '<S36>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Compare To Constant2'
 * '<S37>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Detect Rise Positive'
 * '<S38>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Detect Rise Positive/Positive'
 * '<S39>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Compare To Constant'
 * '<S40>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Compare To Constant1'
 * '<S41>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Compare To Constant2'
 * '<S42>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Detect Rise Positive'
 * '<S43>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Detect Rise Positive/Positive'
 * '<S44>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Compare To Constant'
 * '<S45>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Compare To Constant1'
 * '<S46>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Compare To Constant2'
 * '<S47>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Detect Rise Positive'
 * '<S48>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Detect Rise Positive/Positive'
 * '<S49>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check8/Compare To Constant'
 * '<S50>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check8/Compare To Constant1'
 * '<S51>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check8/Compare To Constant2'
 * '<S52>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check8/Detect Rise Positive'
 * '<S53>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check8/Detect Rise Positive/Positive'
 * '<S54>'  : 'INS/Bus_Assignment/Status_Output/Sensor_Status/Compare To Zero'
 * '<S55>'  : 'INS/Bus_Assignment/Status_Output/Sensor_Status/Compare To Zero1'
 * '<S56>'  : 'INS/Data_Fusion/AHRS'
 * '<S57>'  : 'INS/Data_Fusion/Translation_Filter'
 * '<S58>'  : 'INS/Data_Fusion/AHRS/Attitude_Init'
 * '<S59>'  : 'INS/Data_Fusion/AHRS/Correct'
 * '<S60>'  : 'INS/Data_Fusion/AHRS/Integrate'
 * '<S61>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init'
 * '<S62>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Compare To Constant'
 * '<S63>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Onground_Check'
 * '<S64>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition'
 * '<S65>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat'
 * '<S66>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/cross_product'
 * '<S67>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/cross_product1'
 * '<S68>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/safe_norm'
 * '<S69>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/safe_norm1'
 * '<S70>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/safe_norm2'
 * '<S71>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace'
 * '<S72>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/PositiveTrace'
 * '<S73>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/trace(DCM)'
 * '<S74>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)'
 * '<S75>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)'
 * '<S76>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)'
 * '<S77>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/diag(DCM)'
 * '<S78>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S79>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S80>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S81>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S82>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S83>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S84>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S85>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S86>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S87>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S88>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S89>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S90>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S91>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S92>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S93>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/PositiveTrace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S94>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/PositiveTrace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S95>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/DCM_to_quat/PositiveTrace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S96>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/cross_product/Subsystem'
 * '<S97>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/cross_product/Subsystem1'
 * '<S98>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/cross_product1/Subsystem'
 * '<S99>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/cross_product1/Subsystem1'
 * '<S100>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/safe_norm/Euclidean_Norm2'
 * '<S101>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/safe_norm1/Euclidean_Norm2'
 * '<S102>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Init/safe_norm2/Euclidean_Norm2'
 * '<S103>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Onground_Check/HPF'
 * '<S104>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Onground_Check/LPF'
 * '<S105>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Onground_Check/LPF1'
 * '<S106>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Onground_Check/HPF/LPF'
 * '<S107>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/Compare To Constant'
 * '<S108>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/Interval Test'
 * '<S109>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/reset'
 * '<S110>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/vec_modulus'
 * '<S111>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/vec_modulus1'
 * '<S112>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/reset/Detect Rise Positive'
 * '<S113>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/reset/valid_samples'
 * '<S114>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/reset/Detect Rise Positive/Positive'
 * '<S115>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/vec_modulus/vec_norm'
 * '<S116>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/vec_modulus1/vec_norm'
 * '<S117>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction'
 * '<S118>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction'
 * '<S119>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct'
 * '<S120>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction'
 * '<S121>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct'
 * '<S122>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Estimated_Acc'
 * '<S123>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc'
 * '<S124>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct'
 * '<S125>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct'
 * '<S126>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Modulus'
 * '<S127>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Modulus1'
 * '<S128>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Weight'
 * '<S129>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product'
 * '<S130>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem'
 * '<S131>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem1'
 * '<S132>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross_Product2'
 * '<S133>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/NonlinerSaturation'
 * '<S134>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize'
 * '<S135>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize1'
 * '<S136>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/NonlinerSaturation/vec_modulus'
 * '<S137>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/NonlinerSaturation/vec_modulus/vec_norm'
 * '<S138>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Estimated_Acc/2_Order_Butter_LPF'
 * '<S139>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/Detect Increase'
 * '<S140>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/GPS_Acc_Observer'
 * '<S141>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/Observer_Sensor'
 * '<S142>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/OpticalFlow_Acc_Observer'
 * '<S143>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/Routing'
 * '<S144>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/GPS_Acc_Observer/ContinueLinearObserver'
 * '<S145>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/OpticalFlow_Acc_Observer/ContinueLinearObserver'
 * '<S146>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction/Enable'
 * '<S147>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction/Mag_Correction'
 * '<S148>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction/Mag_Correction/Subsystem'
 * '<S149>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/Compare To Constant'
 * '<S150>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/Onground_Correction'
 * '<S151>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/vec_modulus'
 * '<S152>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/vec_modulus/vec_norm'
 * '<S153>' : 'INS/Data_Fusion/AHRS/Integrate/Att_Init_Done'
 * '<S154>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration'
 * '<S155>' : 'INS/Data_Fusion/AHRS/Integrate/Bias_Integration'
 * '<S156>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle'
 * '<S157>' : 'INS/Data_Fusion/AHRS/Integrate/Att_Init_Done/Detect Increase'
 * '<S158>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/Quat Multiply1'
 * '<S159>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/Quat_to_M_OB'
 * '<S160>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize'
 * '<S161>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus'
 * '<S162>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus/quat norm'
 * '<S163>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/Euler_Transformations'
 * '<S164>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/M_CO1'
 * '<S165>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/Euler_Transformations/quat_to_psi'
 * '<S166>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S167>' : 'INS/Data_Fusion/Translation_Filter/Process'
 * '<S168>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment'
 * '<S169>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S170>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S171>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting'
 * '<S172>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Height_Above_Ground'
 * '<S173>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon'
 * '<S174>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon/Compare To Constant'
 * '<S175>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon/Zero_Value_Exclusion'
 * '<S176>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S177>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S178>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S179>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S180>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Holder'
 * '<S181>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S182>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Observation'
 * '<S183>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Scaling'
 * '<S184>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias'
 * '<S185>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias'
 * '<S186>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias/Bias_Update'
 * '<S187>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias/Detect Increase'
 * '<S188>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S189>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S190>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S191>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S192>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S193>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S194>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S195>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/OptFlow_Vel_Init'
 * '<S196>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S197>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S198>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S199>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S200>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct'
 * '<S201>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S202>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Holder'
 * '<S203>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S204>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Observation'
 * '<S205>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling'
 * '<S206>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate'
 * '<S207>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate/Bias_Update'
 * '<S208>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate/Detect Increase'
 * '<S209>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S210>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S211>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Holder'
 * '<S212>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S213>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Observation'
 * '<S214>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Scaling'
 * '<S215>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias'
 * '<S216>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias/Bias_Update'
 * '<S217>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias/Detect Increase'
 * '<S218>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S219>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init/Reference_Height'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Bus_Selection'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Height_Reset'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Position_Reset'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Height_Reset/Detect Rise Positive'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Height_Reset/Detect Rise Positive/Positive'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Position_Reset/Detect Rise Positive'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Position_Reset/Detect Rise Positive/Positive'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/Bus_Assignment'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Height_Ref'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Position_Ref'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3/Positive'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3/Positive'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Horizontal_Select'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Horizontal_Select/Compare To Zero'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Horizontal_Select/Compare To Zero1'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Horizontal_Select/Compare To Zero2'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero1'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero2'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero3'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero4'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero5'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero6'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Horizontal_Validity'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Vertical_Validity'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Horizontal_Validity/Compare To Zero'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Vertical_Validity/Compare To Zero'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/Baro_Process'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/GPS_Process'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/OpticalFlow_Process'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/Sonar_Process'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/Baro_Status'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/GPS_Status'
 * '<S272>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/OpticalFlow_Status'
 * '<S273>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/Sonar_Status'
 * '<S274>' : 'INS/Sensor_Process/Baro_Process'
 * '<S275>' : 'INS/Sensor_Process/GPS_Process'
 * '<S276>' : 'INS/Sensor_Process/IMU_Process'
 * '<S277>' : 'INS/Sensor_Process/Mag_Process'
 * '<S278>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing'
 * '<S279>' : 'INS/Sensor_Process/Sonar_Process'
 * '<S280>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height'
 * '<S281>' : 'INS/Sensor_Process/Baro_Process/Relative_Height'
 * '<S282>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height/Interval Test1'
 * '<S283>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status'
 * '<S284>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Reference_and_Derivative'
 * '<S285>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant'
 * '<S286>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant1'
 * '<S287>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant2'
 * '<S288>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant3'
 * '<S289>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant4'
 * '<S290>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Zero'
 * '<S291>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Detect Change'
 * '<S292>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Interval Test1'
 * '<S293>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Interval Test2'
 * '<S294>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant'
 * '<S295>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant1'
 * '<S296>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality'
 * '<S297>' : 'INS/Sensor_Process/GPS_Process/Scaling'
 * '<S298>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model'
 * '<S299>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant2'
 * '<S300>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant4'
 * '<S301>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status'
 * '<S302>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/horizontal_acc'
 * '<S303>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/speed_acc'
 * '<S304>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check'
 * '<S305>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant'
 * '<S306>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant1'
 * '<S307>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant2'
 * '<S308>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Init_Condition'
 * '<S309>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Init_Condition/Compare To Constant3'
 * '<S310>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check/Detect Change'
 * '<S311>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model/WGS84_Derivatives'
 * '<S312>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment'
 * '<S313>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling'
 * '<S314>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check'
 * '<S315>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling'
 * '<S316>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check'
 * '<S317>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/Compare To Zero'
 * '<S318>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select'
 * '<S319>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Status'
 * '<S320>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select/2_Order_Butter_LPF'
 * '<S321>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select/2_Order_Butter_LPF1'
 * '<S322>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling/Acc_Calibrate'
 * '<S323>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling/Gyro_Calibrate'
 * '<S324>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Compare To Constant4'
 * '<S325>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Detect Change'
 * '<S326>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test1'
 * '<S327>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test3'
 * '<S328>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling/Acc_Calibrate'
 * '<S329>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling/Gyro_Calibrate'
 * '<S330>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Compare To Constant4'
 * '<S331>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Detect Change'
 * '<S332>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test1'
 * '<S333>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test3'
 * '<S334>' : 'INS/Sensor_Process/Mag_Process/Mag_Scaling'
 * '<S335>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check'
 * '<S336>' : 'INS/Sensor_Process/Mag_Process/Magnetometer'
 * '<S337>' : 'INS/Sensor_Process/Mag_Process/Mag_Scaling/Mag_Calibrate'
 * '<S338>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Compare To Constant4'
 * '<S339>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Detect Change'
 * '<S340>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Interval Test1'
 * '<S341>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Compare To Constant'
 * '<S342>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication'
 * '<S343>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation'
 * '<S344>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/wmm_lookup'
 * '<S345>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate'
 * '<S346>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate'
 * '<S347>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate'
 * '<S348>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus'
 * '<S349>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus/vec_norm'
 * '<S350>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus'
 * '<S351>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus/vec_norm'
 * '<S352>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/psi_to_Mz'
 * '<S353>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/vec_normalize'
 * '<S354>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect'
 * '<S355>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Compare To Constant4'
 * '<S356>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Detect Change'
 * '<S357>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check'
 * '<S358>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Compare To Constant'
 * '<S359>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Compare To Constant4'
 * '<S360>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Detect Change'
 * '<S361>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
