/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.2531
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug 14 22:59:51 2020
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

#ifndef DEFINED_TYPEDEF_FOR_struct_Ql5UyHVjtSbWmZyqe5lwlE_
#define DEFINED_TYPEDEF_FOR_struct_Ql5UyHVjtSbWmZyqe5lwlE_

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
} struct_Ql5UyHVjtSbWmZyqe5lwlE;

#endif

/* Block signals (default storage) */
typedef struct {
  real_T Scalefactor;                  /* '<S296>/Scalefactor' */
  real_T OutportBufferFordz_dh;        /* '<S296>/WGS84_Derivatives' */
  real_T Scalefactor1;                 /* '<S296>/Scalefactor1' */
  real_T Add;                          /* '<S309>/Add' */
  real_T Product4;                     /* '<S309>/Product4' */
  real32_T Divide;                     /* '<S282>/Divide' */
  real32_T gain;                       /* '<S282>/gain' */
  real32_T h_0;                        /* '<S218>/Merge' */
  real32_T vel_D_0;                    /* '<S218>/Merge1' */
  real32_T Sum1[3];                    /* '<S207>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S198>/Sum1' */
  real32_T DataTypeConversion[2];      /* '<S191>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S176>/Sum1' */
  real32_T Reshape[3];                 /* '<S140>/Reshape' */
  real32_T DiscreteTimeIntegrator[3];  /* '<S143>/Discrete-Time Integrator' */
  real32_T Merge[4];                   /* '<S65>/Merge' */
  real32_T OutportBufferForquaternion_0[4];/* '<S61>/DCM_to_quat' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T memory2_PreviousInput;        /* '<S241>/memory2' */
  real_T memory2_PreviousInput_c[2];   /* '<S242>/memory2' */
  real_T memory3_PreviousInput[2];     /* '<S242>/memory3' */
  real32_T Delay1_4_DSTATE;            /* '<Root>/Delay1' */
  real32_T Delay1_5_DSTATE;            /* '<Root>/Delay1' */
  real32_T Delay_6_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_8_DSTATE[9];          /* '<Root>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S318>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S318>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_c[3];/* '<S319>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j[3];/* '<S319>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE;               /* '<S282>/Delay' */
  real32_T Delay2_DSTATE;              /* '<S282>/Delay2' */
  real32_T Delay_8_DSTATE_l[9];        /* '<S56>/Delay' */
  real32_T Delay_9_DSTATE[9];          /* '<S56>/Delay' */
  real32_T Delay_10_DSTATE[3];         /* '<S56>/Delay' */
  real32_T Delay_9_DSTATE_m;           /* '<S57>/Delay' */
  real32_T Delay_10_DSTATE_a;          /* '<S57>/Delay' */
  real32_T Delay_11_DSTATE;            /* '<S57>/Delay' */
  real32_T Delay_DSTATE_b[3];          /* '<S216>/Delay' */
  real32_T Delay_DSTATE_l[6];          /* '<S186>/Delay' */
  real32_T h_delay_DSTATE[75];         /* '<S211>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S211>/vd_delay' */
  real32_T x_delay_DSTATE[5];          /* '<S202>/x_delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S180>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S180>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S180>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S180>/vn_delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S152>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S153>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S137>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S122>/Delay' */
  real32_T DiscreteFIRFilter_states[29];/* '<S124>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S137>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b[2];/* '<S144>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_j[2];/* '<S144>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l[3];/* '<S143>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S143>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S106>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S104>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S105>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTAT_jj;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S16>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_cn;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_oz;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S17>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S18>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S306>/Unit Delay' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S124>/Discrete FIR Filter' */
  uint32_T DelayInput1_DSTATE;         /* '<S358>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_kn;/* '<S355>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S354>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S352>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S337>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S333>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S323>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S312>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_ht;      /* '<S329>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S314>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S308>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S302>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S289>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_ev;/* '<S281>/Discrete-Time Integrator' */
  uint32_T Delay1_DSTATE;              /* '<S282>/Delay1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S208>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S199>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S177>/Delay Input1' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S213>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S209>/Memory' */
  real32_T Memory_PreviousInput_j;     /* '<S204>/Memory' */
  real32_T Memory_PreviousInput_i[3];  /* '<S200>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S183>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S178>/Memory' */
  real32_T PrevY;                      /* '<S150>/Rate Limiter' */
  uint32_T Memory2_PreviousInput;      /* '<S281>/Memory2' */
  uint16_T Delay_DSTATE_i;             /* '<S109>/Delay' */
  uint8_T Delay_DSTATE_d;              /* '<S355>/Delay' */
  uint8_T Delay_DSTATE_f;              /* '<S151>/Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S236>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S238>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S243>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S245>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S215>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S206>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S185>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dy;     /* '<S155>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S138>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S112>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_b;      /* '<S22>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_of;     /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o1;     /* '<S32>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S37>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ng;     /* '<S42>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S47>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dt;     /* '<S52>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S152>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S143>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S143>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S16>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_os;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ow;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_mt;/* '<S17>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S18>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S318>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_a;/* '<S319>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S211>/h_delay' */
  uint8_T icLoad_f;                    /* '<S211>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S202>/x_delay' */
  uint8_T icLoad_o;                    /* '<S180>/x_delay' */
  uint8_T icLoad_i;                    /* '<S180>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S180>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S180>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S152>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_o;/* '<S137>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOA_k;/* '<S144>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_L_oi;/* '<S143>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S142>/Relay' */
  boolean_T Relay1_Mode;               /* '<S145>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S63>/Relay2' */
  boolean_T Memory_PreviousInput_c;    /* '<S14>/Memory' */
  boolean_T Memory_PreviousInput_dc;   /* '<S16>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S13>/Memory' */
  boolean_T Memory_PreviousInput_ej;   /* '<S12>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S15>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S17>/Memory' */
  boolean_T Memory_PreviousInput_hx;   /* '<S18>/Memory' */
  boolean_T Reference_and_Derivative_MODE;/* '<S279>/Reference_and_Derivative' */
  boolean_T OpticalFlow_Acc_Observer_MODE;/* '<S123>/OpticalFlow_Acc_Observer' */
  boolean_T GPS_Acc_Observer_MODE;     /* '<S123>/GPS_Acc_Observer' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S273>/WGS84_Model' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S211>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S211>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S202>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S180>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S180>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S180>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S180>/vn_delay1' */
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
                                        * Referenced by: '<S172>/Constant'
                                        */
  real_T wmm_lookup_res;               /* Mask Parameter: wmm_lookup_res
                                        * Referenced by:
                                        *   '<S342>/Gain'
                                        *   '<S342>/Gain6'
                                        */
  real_T Zero_Value_Exclusion_thr;     /* Mask Parameter: Zero_Value_Exclusion_thr
                                        * Referenced by: '<S173>/Saturation'
                                        */
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S307>/Constant'
                                        */
  real32_T IMU1_Valid_Check_acc_max;   /* Mask Parameter: IMU1_Valid_Check_acc_max
                                        * Referenced by: '<S324>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_max;   /* Mask Parameter: IMU2_Valid_Check_acc_max
                                        * Referenced by: '<S330>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_acc_min;   /* Mask Parameter: IMU1_Valid_Check_acc_min
                                        * Referenced by: '<S324>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_min;   /* Mask Parameter: IMU2_Valid_Check_acc_min
                                        * Referenced by: '<S330>/Lower Limit'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S30>/Constant'
                                        */
  real32_T CompareToConstant1_const_n; /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S25>/Constant'
                                        */
  real32_T CompareToConstant1_const_p; /* Mask Parameter: CompareToConstant1_const_p
                                        * Referenced by: '<S20>/Constant'
                                        */
  real32_T CompareToConstant1_const_i; /* Mask Parameter: CompareToConstant1_const_i
                                        * Referenced by: '<S35>/Constant'
                                        */
  real32_T CompareToConstant1_const_d; /* Mask Parameter: CompareToConstant1_const_d
                                        * Referenced by: '<S45>/Constant'
                                        */
  real32_T CompareToConstant1_const_f; /* Mask Parameter: CompareToConstant1_const_f
                                        * Referenced by: '<S50>/Constant'
                                        */
  real32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S21>/Constant'
                                        */
  real32_T CompareToConstant2_const_j; /* Mask Parameter: CompareToConstant2_const_j
                                        * Referenced by: '<S26>/Constant'
                                        */
  real32_T CompareToConstant2_const_e; /* Mask Parameter: CompareToConstant2_const_e
                                        * Referenced by: '<S31>/Constant'
                                        */
  real32_T CompareToConstant2_const_m; /* Mask Parameter: CompareToConstant2_const_m
                                        * Referenced by: '<S36>/Constant'
                                        */
  real32_T CompareToConstant2_const_k; /* Mask Parameter: CompareToConstant2_const_k
                                        * Referenced by: '<S46>/Constant'
                                        */
  real32_T CompareToConstant2_const_g; /* Mask Parameter: CompareToConstant2_const_g
                                        * Referenced by: '<S51>/Constant'
                                        */
  real32_T CompareToConstant_const_g;  /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S62>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S107>/Constant'
                                        */
  real32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S148>/Constant'
                                        */
  real32_T CompareToConstant_const_f;  /* Mask Parameter: CompareToConstant_const_f
                                        * Referenced by: '<S356>/Constant'
                                        */
  real32_T IMU1_Valid_Check_gyr_max;   /* Mask Parameter: IMU1_Valid_Check_gyr_max
                                        * Referenced by: '<S325>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_max;   /* Mask Parameter: IMU2_Valid_Check_gyr_max
                                        * Referenced by: '<S331>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_gyr_min;   /* Mask Parameter: IMU1_Valid_Check_gyr_min
                                        * Referenced by: '<S325>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_min;   /* Mask Parameter: IMU2_Valid_Check_gyr_min
                                        * Referenced by: '<S331>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S108>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit_d;    /* Mask Parameter: IntervalTest_lowlimit_d
                                        * Referenced by: '<S359>/Lower Limit'
                                        */
  real32_T Mag_Valid_Check_mag_max;    /* Mask Parameter: Mag_Valid_Check_mag_max
                                        * Referenced by: '<S338>/Upper Limit'
                                        */
  real32_T Mag_Valid_Check_mag_min;    /* Mask Parameter: Mag_Valid_Check_mag_min
                                        * Referenced by: '<S338>/Lower Limit'
                                        */
  real32_T Relative_Height_pressure_max;/* Mask Parameter: Relative_Height_pressure_max
                                         * Referenced by: '<S290>/Upper Limit'
                                         */
  real32_T Relative_Height_pressure_min;/* Mask Parameter: Relative_Height_pressure_min
                                         * Referenced by: '<S290>/Lower Limit'
                                         */
  real32_T Relative_Height_temp_max;   /* Mask Parameter: Relative_Height_temp_max
                                        * Referenced by: '<S291>/Upper Limit'
                                        */
  real32_T Relative_Height_temp_min;   /* Mask Parameter: Relative_Height_temp_min
                                        * Referenced by: '<S291>/Lower Limit'
                                        */
  real32_T valid_check3_time_out;      /* Mask Parameter: valid_check3_time_out
                                        * Referenced by: '<S29>/Constant'
                                        */
  real32_T valid_check5_time_out;      /* Mask Parameter: valid_check5_time_out
                                        * Referenced by: '<S39>/Constant'
                                        */
  real32_T valid_check2_time_out;      /* Mask Parameter: valid_check2_time_out
                                        * Referenced by: '<S24>/Constant'
                                        */
  real32_T valid_check1_time_out;      /* Mask Parameter: valid_check1_time_out
                                        * Referenced by: '<S19>/Constant'
                                        */
  real32_T valid_check4_time_out;      /* Mask Parameter: valid_check4_time_out
                                        * Referenced by: '<S34>/Constant'
                                        */
  real32_T valid_check6_time_out;      /* Mask Parameter: valid_check6_time_out
                                        * Referenced by: '<S44>/Constant'
                                        */
  real32_T valid_check7_time_out;      /* Mask Parameter: valid_check7_time_out
                                        * Referenced by: '<S49>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S108>/Upper Limit'
                                        */
  real32_T IntervalTest_uplimit_a;     /* Mask Parameter: IntervalTest_uplimit_a
                                        * Referenced by: '<S359>/Upper Limit'
                                        */
  uint32_T CompareToConstant_const_pt; /* Mask Parameter: CompareToConstant_const_pt
                                        * Referenced by: '<S283>/Constant'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S287>/Constant'
                                        */
  uint32_T CompareToConstant2_const_a; /* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S305>/Constant'
                                        */
  uint32_T CompareToConstant4_const_e; /* Mask Parameter: CompareToConstant4_const_e
                                        * Referenced by: '<S298>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S303>/Constant'
                                        */
  uint32_T CompareToConstant4_const_k; /* Mask Parameter: CompareToConstant4_const_k
                                        * Referenced by: '<S353>/Constant'
                                        */
  uint32_T CompareToConstant4_const_h; /* Mask Parameter: CompareToConstant4_const_h
                                        * Referenced by: '<S357>/Constant'
                                        */
  uint32_T Relative_Height_s_first;    /* Mask Parameter: Relative_Height_s_first
                                        * Referenced by: '<S284>/Constant'
                                        */
  uint32_T Relative_Height_s_last;     /* Mask Parameter: Relative_Height_s_last
                                        * Referenced by:
                                        *   '<S285>/Constant'
                                        *   '<S286>/Constant'
                                        */
  uint32_T IMU1_Valid_Check_timeout;   /* Mask Parameter: IMU1_Valid_Check_timeout
                                        * Referenced by: '<S322>/Constant'
                                        */
  uint32_T IMU2_Valid_Check_timeout;   /* Mask Parameter: IMU2_Valid_Check_timeout
                                        * Referenced by: '<S328>/Constant'
                                        */
  uint32_T Mag_Valid_Check_timeout;    /* Mask Parameter: Mag_Valid_Check_timeout
                                        * Referenced by: '<S336>/Constant'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S177>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S199>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S208>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S289>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S308>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S323>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_j;       /* Mask Parameter: DetectChange_vinit_j
                                        * Referenced by: '<S329>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S337>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S354>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_k;       /* Mask Parameter: DetectChange_vinit_k
                                        * Referenced by: '<S358>/Delay Input1'
                                        */
  int16_T wmm_lookup_wmm_declination[629];/* Mask Parameter: wmm_lookup_wmm_declination
                                           * Referenced by: '<S342>/Declination Lookup'
                                           */
  uint16_T Initwith50validsamples_const;/* Mask Parameter: Initwith50validsamples_const
                                         * Referenced by: '<S113>/Constant'
                                         */
  boolean_T CompareToConstant1_const_j;/* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S40>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i;/* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S41>/Constant'
                                        */
  boolean_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S339>/Constant'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S22>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_k;/* Mask Parameter: DetectRisePositive_vinit_k
                                        * Referenced by: '<S27>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_n;/* Mask Parameter: DetectRisePositive_vinit_n
                                        * Referenced by: '<S32>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_d;/* Mask Parameter: DetectRisePositive_vinit_d
                                        * Referenced by: '<S37>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_a;/* Mask Parameter: DetectRisePositive_vinit_a
                                        * Referenced by: '<S42>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_b;/* Mask Parameter: DetectRisePositive_vinit_b
                                        * Referenced by: '<S47>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_c;/* Mask Parameter: DetectRisePositive_vinit_c
                                        * Referenced by: '<S52>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_f;/* Mask Parameter: DetectRisePositive_vinit_f
                                        * Referenced by: '<S112>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S138>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_d;    /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S155>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S185>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S206>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S215>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S236>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_m;/* Mask Parameter: DetectRisePositive_vinit_m
                                        * Referenced by: '<S238>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S243>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S245>/Delay Input1'
                                         */
  int8_T wmm_lookup_wmm_inclination[629];/* Mask Parameter: wmm_lookup_wmm_inclination
                                          * Referenced by: '<S342>/Inclination Lookup'
                                          */
  uint8_T CompareToConstant1_const_n4; /* Mask Parameter: CompareToConstant1_const_n4
                                        * Referenced by: '<S304>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S292>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S293>/Constant'
                                        */
  uint8_T CompareToConstant2_const_b;  /* Mask Parameter: CompareToConstant2_const_b
                                        * Referenced by: '<S297>/Constant'
                                        */
  uint8_T wmm_lookup_wmm_magnitude[629];/* Mask Parameter: wmm_lookup_wmm_magnitude
                                         * Referenced by: '<S342>/Magnitude Lookup'
                                         */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S173>/Constant'
                                        */
  real_T Constant_Value_i[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S171>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S173>/Saturation'
                                        */
  real_T memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S241>/memory2'
                                        */
  real_T memory2_InitialCondition_f;   /* Expression: 0
                                        * Referenced by: '<S242>/memory2'
                                        */
  real_T memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S242>/memory3'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S296>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S296>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S296>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S296>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S296>/dz_dh'
                                        */
  real_T Scalefactor_Gain;             /* Expression: 1
                                        * Referenced by: '<S296>/Scalefactor'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S309>/constant1'
                                        */
  real_T Scalefactor1_Gain;            /* Expression: 1
                                        * Referenced by: '<S296>/Scalefactor1'
                                        */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S309>/constant2'
                                        */
  real_T f_Value;                      /* Expression: 1/298.257
                                        * Referenced by: '<S309>/f'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S309>/constant'
                                        */
  real_T a_Value;                      /* Expression: 6378137
                                        * Referenced by: '<S309>/a'
                                        */
  real_T a1_Value;                     /* Expression: 1
                                        * Referenced by: '<S309>/a1'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S306>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S306>/Saturation'
                                        */
  int32_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S306>/Saturation'
                                        */
  int32_T offset_lat_Value;            /* Computed Parameter: offset_lat_Value
                                        * Referenced by: '<S342>/offset_lat'
                                        */
  int32_T Saturation1_UpperSat;        /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S342>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S342>/Saturation1'
                                        */
  int32_T offset_lon_Value;            /* Computed Parameter: offset_lon_Value
                                        * Referenced by: '<S342>/offset_lon'
                                        */
  int32_T Saturation2_UpperSat;        /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S342>/Saturation2'
                                        */
  int32_T Saturation2_LowerSat;        /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S342>/Saturation2'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S295>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S295>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S295>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S295>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain_d;         /* Computed Parameter: Scalefactor1_Gain_d
                                        * Referenced by: '<S295>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S295>/Scalefactor2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S14>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
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
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_il;/* Computed Parameter: DiscreteTimeIntegrator_IC_il
                                         * Referenced by: '<S13>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_pi;/* Computed Parameter: DiscreteTimeIntegrator_gainv_pi
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_c;/* Computed Parameter: DiscreteTimeIntegrator_IC_c
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_cj;/* Computed Parameter: DiscreteTimeIntegrator_IC_cj
                                         * Referenced by: '<S17>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_gainv_e3;/* Computed Parameter: DiscreteTimeIntegrator_gainv_e3
                                            * Referenced by: '<S18>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_n;/* Computed Parameter: DiscreteTimeIntegrator_IC_n
                                        * Referenced by: '<S18>/Discrete-Time Integrator'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S12>/Constant'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S13>/Constant'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S14>/Constant'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S15>/Constant'
                                        */
  real32_T Constant_Value_kn;          /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S16>/Constant'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S17>/Constant'
                                        */
  real32_T Constant_Value_k1;          /* Computed Parameter: Constant_Value_k1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
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
  real32_T Constant_Value_oh;          /* Computed Parameter: Constant_Value_oh
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
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S134>/Constant'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S135>/Constant'
                                        */
  real32_T GPS_acc_O_mPs2_Y0;          /* Computed Parameter: GPS_acc_O_mPs2_Y0
                                        * Referenced by: '<S139>/GPS_acc_O_mPs2'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S143>/Discrete-Time Integrator1'
                                            */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S143>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_i0;/* Computed Parameter: DiscreteTimeIntegrator_gainv_i0
                                            * Referenced by: '<S143>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S143>/Discrete-Time Integrator'
                                        */
  real32_T Gain3_Gain_p;               /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S143>/Gain3'
                                        */
  real32_T OptFlow_acc_O_mPs2_Y0;      /* Computed Parameter: OptFlow_acc_O_mPs2_Y0
                                        * Referenced by: '<S140>/OptFlow_acc_O_mPs2'
                                        */
  real32_T Constant_Value_gi;          /* Computed Parameter: Constant_Value_gi
                                        * Referenced by: '<S140>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                                            * Referenced by: '<S144>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC; /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<S144>/Discrete-Time Integrator1'
                                        */
  real32_T Gain2_Gain_b;               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S144>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                            * Referenced by: '<S144>/Discrete-Time Integrator'
                                            */
  real32_T Gain3_Gain_i;               /* Computed Parameter: Gain3_Gain_i
                                        * Referenced by: '<S144>/Gain3'
                                        */
  real32_T Constant_Value_m0;          /* Computed Parameter: Constant_Value_m0
                                        * Referenced by: '<S124>/Constant'
                                        */
  real32_T Constant1_Value_cx;         /* Computed Parameter: Constant1_Value_cx
                                        * Referenced by: '<S124>/Constant1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                            * Referenced by: '<S137>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S142>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S142>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S142>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S142>/Relay'
                                        */
  real32_T Delay_InitialCondition;     /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S122>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Expression: [0;0;-INS_CONST.g]
                                        * Referenced by: '<S141>/gravity'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S124>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S124>/Dead Zone2'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S126>/Constant1'
                                        */
  real32_T Constant_Value_ew;          /* Computed Parameter: Constant_Value_ew
                                        * Referenced by: '<S126>/Constant'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S126>/Gain'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S126>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S126>/Saturation'
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
                                            * Referenced by: '<S137>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_d;/* Computed Parameter: DiscreteTimeIntegrator_IC_d
                                        * Referenced by: '<S137>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S137>/Gain1'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S137>/Gain'
                                        */
  real32_T Relay1_OnVal;               /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<S145>/Relay1'
                                        */
  real32_T Relay1_OffVal;              /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<S145>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S145>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S145>/Relay1'
                                        */
  real32_T mag_correct_gain_Gain;      /* Computed Parameter: mag_correct_gain_Gain
                                        * Referenced by: '<S146>/mag_correct_gain'
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
                                        * Referenced by: '<S152>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S152>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S153>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S153>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S153>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S153>/Discrete-Time Integrator2'
                                            */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S152>/Gain2'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S157>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S157>/Gain1'
                                        */
  real32_T Gain2_Gain_oj;              /* Computed Parameter: Gain2_Gain_oj
                                        * Referenced by: '<S157>/Gain2'
                                        */
  real32_T Gain3_Gain_dx;              /* Computed Parameter: Gain3_Gain_dx
                                        * Referenced by: '<S157>/Gain3'
                                        */
  real32_T Gain4_Gain_o;               /* Computed Parameter: Gain4_Gain_o
                                        * Referenced by: '<S157>/Gain4'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S157>/Gain5'
                                        */
  real32_T Gain5_Gain_d;               /* Computed Parameter: Gain5_Gain_d
                                        * Referenced by: '<S161>/Gain5'
                                        */
  real32_T Saturation1_UpperSat_o;     /* Computed Parameter: Saturation1_UpperSat_o
                                        * Referenced by: '<S161>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_b;     /* Computed Parameter: Saturation1_LowerSat_b
                                        * Referenced by: '<S161>/Saturation1'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S163>/Gain'
                                        */
  real32_T Constant1_Value_g;          /* Expression: single(0)
                                        * Referenced by: '<S162>/Constant1'
                                        */
  real32_T Constant_Value_ev;          /* Expression: single(1)
                                        * Referenced by: '<S162>/Constant'
                                        */
  real32_T Gain_Gain_i;                /* Expression: single(-1)
                                        * Referenced by: '<S162>/Gain'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S170>/Constant'
                                        */
  real32_T Constant_Value_aq;          /* Computed Parameter: Constant_Value_aq
                                        * Referenced by: '<S164>/Constant'
                                        */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S181>/Gain1'
                                        */
  real32_T Gain_Gain_o0;               /* Computed Parameter: Gain_Gain_o0
                                        * Referenced by: '<S181>/Gain'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S181>/Gain2'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S176>/X_Next'
                                        */
  real32_T Memory_InitialCondition[2]; /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S183>/Memory'
                                        */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S178>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S178>/Gain3'
                                        */
  real32_T Constant_Value_b[2];        /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S188>/Constant'
                                        */
  real32_T X_0_Y0;                     /* Computed Parameter: X_0_Y0
                                        * Referenced by: '<S191>/X_0'
                                        */
  real32_T Gain1_Gain_en;              /* Computed Parameter: Gain1_Gain_en
                                        * Referenced by: '<S203>/Gain1'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S203>/Gain'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S198>/X_Next'
                                        */
  real32_T Memory_InitialCondition_m;  /* Computed Parameter: Memory_InitialCondition_m
                                        * Referenced by: '<S204>/Memory'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S203>/Gain2'
                                        */
  real32_T Memory_InitialCondition_j;  /* Computed Parameter: Memory_InitialCondition_j
                                        * Referenced by: '<S200>/Memory'
                                        */
  real32_T Gain_Gain_p;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S200>/Gain'
                                        */
  real32_T Gain1_Gain_ml;              /* Computed Parameter: Gain1_Gain_ml
                                        * Referenced by: '<S212>/Gain1'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S212>/Gain'
                                        */
  real32_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S212>/Gain2'
                                        */
  real32_T X_Next_Y0_i;                /* Computed Parameter: X_Next_Y0_i
                                        * Referenced by: '<S207>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S213>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S209>/Memory'
                                        */
  real32_T Gain3_Gain_kn;              /* Expression: INS_CONST.dt
                                        * Referenced by: '<S209>/Gain3'
                                        */
  real32_T Constant_Value_eq;          /* Computed Parameter: Constant_Value_eq
                                        * Referenced by: '<S218>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S222>/Constant'
                                        */
  real32_T Constant_Value_km;          /* Computed Parameter: Constant_Value_km
                                        * Referenced by: '<S224>/Constant'
                                        */
  real32_T Merge_InitialOutput_j;      /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S218>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S218>/Merge1'
                                        */
  real32_T Delay_InitialCondition_m;   /* Computed Parameter: Delay_InitialCondition_m
                                        * Referenced by: '<S216>/Delay'
                                        */
  real32_T Gain1_Gain_kw;              /* Computed Parameter: Gain1_Gain_kw
                                        * Referenced by: '<S217>/Gain1'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S217>/Constant1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S217>/Constant'
                                        */
  real32_T Gain_Gain_mr;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S217>/Gain'
                                        */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S186>/Delay'
                                        */
  real32_T Constant_Value_lx[2];       /* Computed Parameter: Constant_Value_lx
                                        * Referenced by: '<S187>/Constant'
                                        */
  real32_T Gain_Gain_ic;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S187>/Gain'
                                        */
  real32_T Constant_Value_be;          /* Computed Parameter: Constant_Value_be
                                        * Referenced by: '<S263>/Constant'
                                        */
  real32_T Constant_Value_o0;          /* Computed Parameter: Constant_Value_o0
                                        * Referenced by: '<S262>/Constant'
                                        */
  real32_T Constant_Value_mi;          /* Computed Parameter: Constant_Value_mi
                                        * Referenced by: '<S249>/Constant'
                                        */
  real32_T Constant_Value_ab;          /* Computed Parameter: Constant_Value_ab
                                        * Referenced by: '<S250>/Constant'
                                        */
  real32_T Constant_Value_ao;          /* Computed Parameter: Constant_Value_ao
                                        * Referenced by: '<S254>/Constant'
                                        */
  real32_T Constant_Value_ek;          /* Computed Parameter: Constant_Value_ek
                                        * Referenced by: '<S255>/Constant'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S248>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S248>/Saturation'
                                        */
  real32_T Constant_Value_hv;          /* Computed Parameter: Constant_Value_hv
                                        * Referenced by: '<S256>/Constant'
                                        */
  real32_T Constant_Value_h4;          /* Computed Parameter: Constant_Value_h4
                                        * Referenced by: '<S257>/Constant'
                                        */
  real32_T Saturation1_UpperSat_i;     /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S248>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_jb;    /* Computed Parameter: Saturation1_LowerSat_jb
                                        * Referenced by: '<S248>/Saturation1'
                                        */
  real32_T Constant_Value_iw;          /* Computed Parameter: Constant_Value_iw
                                        * Referenced by: '<S258>/Constant'
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
                                        * Referenced by: '<S282>/pressure_R'
                                        */
  real32_T dh_dp_Y0;                   /* Computed Parameter: dh_dp_Y0
                                        * Referenced by: '<S282>/dh_dp'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S282>/Constant2'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S282>/Delay'
                                        */
  real32_T Delay2_InitialCondition;    /* Computed Parameter: Delay2_InitialCondition
                                        * Referenced by: '<S282>/Delay2'
                                        */
  real32_T Saturation_UpperSat_m;      /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S282>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S282>/Saturation'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S282>/gain'
                                        */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S301>/Constant7'
                                        */
  real32_T Gain3_Gain_lx;              /* Computed Parameter: Gain3_Gain_lx
                                        * Referenced by: '<S301>/Gain3'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S294>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S294>/Saturation'
                                        */
  real32_T Constant1_Value_g5;         /* Computed Parameter: Constant1_Value_g5
                                        * Referenced by: '<S300>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S300>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S294>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S294>/Saturation1'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                            * Referenced by: '<S318>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ck;/* Computed Parameter: DiscreteTimeIntegrator_IC_ck
                                         * Referenced by: '<S318>/Discrete-Time Integrator'
                                         */
  real32_T Gain1_Gain_kl;              /* Computed Parameter: Gain1_Gain_kl
                                        * Referenced by: '<S318>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_i;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_i
                                            * Referenced by: '<S318>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_mz;               /* Computed Parameter: Gain_Gain_mz
                                        * Referenced by: '<S318>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                            * Referenced by: '<S319>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_n5;/* Computed Parameter: DiscreteTimeIntegrator_IC_n5
                                         * Referenced by: '<S319>/Discrete-Time Integrator'
                                         */
  real32_T Gain1_Gain_e1;              /* Computed Parameter: Gain1_Gain_e1
                                        * Referenced by: '<S319>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_p;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_p
                                            * Referenced by: '<S319>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_m2;               /* Computed Parameter: Gain_Gain_m2
                                        * Referenced by: '<S319>/Gain'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S340>/default_mag_quality'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S345>/Nominal_Magnitude'
                                        */
  real32_T gain_Gain_m;                /* Computed Parameter: gain_Gain_m
                                        * Referenced by: '<S345>/gain'
                                        */
  real32_T Constant1_Value_cq;         /* Computed Parameter: Constant1_Value_cq
                                        * Referenced by: '<S345>/Constant1'
                                        */
  real32_T Saturation_UpperSat_gv;     /* Computed Parameter: Saturation_UpperSat_gv
                                        * Referenced by: '<S345>/Saturation'
                                        */
  real32_T Saturation_LowerSat_pf;     /* Computed Parameter: Saturation_LowerSat_pf
                                        * Referenced by: '<S345>/Saturation'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S344>/gain'
                                        */
  real32_T Constant2_Value_hh;         /* Computed Parameter: Constant2_Value_hh
                                        * Referenced by: '<S344>/Constant2'
                                        */
  real32_T Saturation_UpperSat_gg;     /* Computed Parameter: Saturation_UpperSat_gg
                                        * Referenced by: '<S344>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S344>/Saturation'
                                        */
  real32_T Constant_Value_g2;          /* Computed Parameter: Constant_Value_g2
                                        * Referenced by: '<S351>/Constant'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S332>/Gauss_to_uT'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S350>/Constant3'
                                        */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S350>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S350>/Constant4'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S350>/Constant2'
                                        */
  real32_T Constant1_Value_c2;         /* Computed Parameter: Constant1_Value_c2
                                        * Referenced by: '<S350>/Constant1'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S350>/Constant'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S341>/Constant1'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S351>/Switch'
                                        */
  real32_T Constant_Value_bg;          /* Computed Parameter: Constant_Value_bg
                                        * Referenced by: '<S276>/Constant'
                                        */
  real32_T Constant_Value_jp;          /* Computed Parameter: Constant_Value_jp
                                        * Referenced by: '<S352>/Constant'
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
                                        * Referenced by: '<S301>/Gain5'
                                        */
  uint32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S300>/Gain1'
                                        */
  uint32_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S109>/Delay'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S151>/Delay'
                                        */
  uint32_T x_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S180>/x_delay'
                                        */
  uint32_T x_delay1_DelayLength;       /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S180>/x_delay1'
                                        */
  uint32_T vn_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S180>/vn_delay'
                                        */
  uint32_T vn_delay1_DelayLength;      /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S180>/vn_delay1'
                                        */
  uint32_T x_delay_DelayLength_m;      /* Expression: 10/INS_EXPORT.period
                                        * Referenced by: '<S202>/x_delay'
                                        */
  uint32_T h_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S211>/h_delay'
                                        */
  uint32_T vd_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S211>/vd_delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S216>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S186>/Delay'
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
                                        * Referenced by: '<S282>/Constant1'
                                        */
  uint32_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S282>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S282>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition;    /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S282>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S282>/Delay2'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S282>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S282>/Saturation1'
                                        */
  uint32_T Memory2_InitialCondition;   /* Computed Parameter: Memory2_InitialCondition
                                        * Referenced by: '<S281>/Memory2'
                                        */
  uint32_T Constant_Value_in;          /* Computed Parameter: Constant_Value_in
                                        * Referenced by: '<S288>/Constant'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_dv;/* Computed Parameter: DiscreteTimeIntegrator_IC_dv
                                         * Referenced by: '<S281>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S302>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S312>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_pw;/* Computed Parameter: DiscreteTimeIntegrator_IC_pw
                                         * Referenced by: '<S314>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S333>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S352>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_pt;/* Computed Parameter: DiscreteTimeIntegrator_IC_pt
                                         * Referenced by: '<S355>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S355>/Delay'
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
                                        * Referenced by: '<S341>/Gain'
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
  uint16_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S109>/Delay'
                                        */
  uint16_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S109>/Saturation'
                                        */
  uint16_T Saturation_LowerSat_hb;     /* Computed Parameter: Saturation_LowerSat_hb
                                        * Referenced by: '<S109>/Saturation'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S141>/GPS_Delay'
                                        */
  uint16_T OptFlow_Delay_Value;        /* Computed Parameter: OptFlow_Delay_Value
                                        * Referenced by: '<S141>/OptFlow_Delay'
                                        */
  boolean_T Memory_InitialCondition_mr;/* Computed Parameter: Memory_InitialCondition_mr
                                        * Referenced by: '<S14>/Memory'
                                        */
  boolean_T Memory_InitialCondition_g; /* Computed Parameter: Memory_InitialCondition_g
                                        * Referenced by: '<S16>/Memory'
                                        */
  boolean_T Memory_InitialCondition_b; /* Computed Parameter: Memory_InitialCondition_b
                                        * Referenced by: '<S13>/Memory'
                                        */
  boolean_T Memory_InitialCondition_jp;/* Computed Parameter: Memory_InitialCondition_jp
                                        * Referenced by: '<S12>/Memory'
                                        */
  boolean_T Memory_InitialCondition_f; /* Computed Parameter: Memory_InitialCondition_f
                                        * Referenced by: '<S15>/Memory'
                                        */
  boolean_T Memory_InitialCondition_h; /* Computed Parameter: Memory_InitialCondition_h
                                        * Referenced by: '<S17>/Memory'
                                        */
  boolean_T Memory_InitialCondition_d; /* Computed Parameter: Memory_InitialCondition_d
                                        * Referenced by: '<S18>/Memory'
                                        */
  boolean_T Constant_Value_f4;         /* Computed Parameter: Constant_Value_f4
                                        * Referenced by: '<S23>/Constant'
                                        */
  boolean_T Constant_Value_nl;         /* Computed Parameter: Constant_Value_nl
                                        * Referenced by: '<S28>/Constant'
                                        */
  boolean_T Constant_Value_pn;         /* Computed Parameter: Constant_Value_pn
                                        * Referenced by: '<S33>/Constant'
                                        */
  boolean_T Constant_Value_pv;         /* Computed Parameter: Constant_Value_pv
                                        * Referenced by: '<S38>/Constant'
                                        */
  boolean_T Constant_Value_l1;         /* Computed Parameter: Constant_Value_l1
                                        * Referenced by: '<S43>/Constant'
                                        */
  boolean_T Constant_Value_d0;         /* Computed Parameter: Constant_Value_d0
                                        * Referenced by: '<S48>/Constant'
                                        */
  boolean_T Constant_Value_ng;         /* Computed Parameter: Constant_Value_ng
                                        * Referenced by: '<S53>/Constant'
                                        */
  boolean_T Constant_Value_af;         /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S114>/Constant'
                                        */
  boolean_T Constant_Value_bt;         /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S237>/Constant'
                                        */
  boolean_T Constant_Value_gn;         /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S239>/Constant'
                                        */
  boolean_T Constant_Value_m3;         /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S244>/Constant'
                                        */
  boolean_T Constant_Value_pt;         /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S246>/Constant'
                                        */
  boolean_T Constant_Value_cz;         /* Computed Parameter: Constant_Value_cz
                                        * Referenced by: '<S251>/Constant'
                                        */
  boolean_T Constant_Value_p2;         /* Computed Parameter: Constant_Value_p2
                                        * Referenced by: '<S252>/Constant'
                                        */
  boolean_T Constant_Value_hvm;        /* Computed Parameter: Constant_Value_hvm
                                        * Referenced by: '<S253>/Constant'
                                        */
  int8_T Gain1_Gain_o;                 /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S344>/Gain1'
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
                                        * Referenced by: '<S317>/Gain'
                                        */
  uint8_T Gain9_Gain;                  /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S8>/Gain9'
                                        */
  uint8_T Saturation_UpperSat_d;       /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S142>/Saturation'
                                        */
  uint8_T Saturation_LowerSat_b;       /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S142>/Saturation'
                                        */
  uint8_T Constant_Value_mm;           /* Computed Parameter: Constant_Value_mm
                                        * Referenced by: '<S151>/Constant'
                                        */
  uint8_T Delay_InitialCondition_k;    /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S151>/Delay'
                                        */
  uint8_T Constant_Value_jz;           /* Computed Parameter: Constant_Value_jz
                                        * Referenced by: '<S166>/Constant'
                                        */
  uint8_T Constant_Value_jn;           /* Computed Parameter: Constant_Value_jn
                                        * Referenced by: '<S315>/Constant'
                                        */
  uint8_T Constant1_Value_l;           /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S355>/Constant1'
                                        */
  uint8_T Delay_InitialCondition_c;    /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S355>/Delay'
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
extern struct_Ql5UyHVjtSbWmZyqe5lwlE INS_PARAM;/* Variable: INS_PARAM
                                                * Referenced by:
                                                *   '<S320>/Acc_Bias'
                                                *   '<S320>/Acc_RotMatrix'
                                                *   '<S321>/Gyr_RotMatrix'
                                                *   '<S321>/Gyro_Bias'
                                                *   '<S326>/Acc_Bias'
                                                *   '<S326>/Acc_RotMatrix'
                                                *   '<S327>/Gyr_RotMatrix'
                                                *   '<S327>/Gyro_Bias'
                                                *   '<S335>/Mag_Bias'
                                                *   '<S335>/Mag_RotMatrix'
                                                */
extern struct_4XfCoaAMTej5uH3d8u88xB INS_EXPORT;/* Variable: INS_EXPORT
                                                 * Referenced by:
                                                 *   '<S4>/Constant'
                                                 *   '<S312>/Constant'
                                                 *   '<S314>/Constant'
                                                 *   '<S333>/Constant'
                                                 *   '<S355>/Constant'
                                                 *   '<S281>/Constant'
                                                 *   '<S302>/Constant'
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
 * '<S18>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7'
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
 * '<S49>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Compare To Constant'
 * '<S50>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Compare To Constant1'
 * '<S51>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Compare To Constant2'
 * '<S52>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Detect Rise Positive'
 * '<S53>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Detect Rise Positive/Positive'
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
 * '<S113>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Reset_Condition/reset/Init with 50 valid samples'
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
 * '<S126>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Match_Level'
 * '<S127>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Modulus'
 * '<S128>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Modulus1'
 * '<S129>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product'
 * '<S130>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem'
 * '<S131>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem1'
 * '<S132>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross_Product2'
 * '<S133>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Soft_Saturation'
 * '<S134>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize'
 * '<S135>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize1'
 * '<S136>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Soft_Saturation/Euclidean_Norm'
 * '<S137>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Estimated_Acc/2_Order_Butter_LPF'
 * '<S138>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/Detect Increase'
 * '<S139>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/GPS_Acc_Observer'
 * '<S140>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/OpticalFlow_Acc_Observer'
 * '<S141>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/Routing'
 * '<S142>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/Sensor_Choose'
 * '<S143>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/GPS_Acc_Observer/ContinueLinearObserver'
 * '<S144>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Attitude_Correct/Measured_Acc/OpticalFlow_Acc_Observer/ContinueLinearObserver'
 * '<S145>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction/Enable'
 * '<S146>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction/Mag_Correction'
 * '<S147>' : 'INS/Data_Fusion/AHRS/Correct/Att_Correction/Heading_Correction/Mag_Correction/Subsystem'
 * '<S148>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/Compare To Constant'
 * '<S149>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/Euclidean_Norm1'
 * '<S150>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/Standstill Gyro Correction'
 * '<S151>' : 'INS/Data_Fusion/AHRS/Integrate/Att_Init_Done'
 * '<S152>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration'
 * '<S153>' : 'INS/Data_Fusion/AHRS/Integrate/Bias_Integration'
 * '<S154>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle'
 * '<S155>' : 'INS/Data_Fusion/AHRS/Integrate/Att_Init_Done/Detect Increase'
 * '<S156>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/Quat Multiply1'
 * '<S157>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/Quat_to_M_OB'
 * '<S158>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize'
 * '<S159>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus'
 * '<S160>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus/quat norm'
 * '<S161>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/Euler_Transformations'
 * '<S162>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/M_CO1'
 * '<S163>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/Euler_Transformations/quat_to_psi'
 * '<S164>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S165>' : 'INS/Data_Fusion/Translation_Filter/Process'
 * '<S166>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment'
 * '<S167>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S168>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S169>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting'
 * '<S170>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Height_Above_Ground'
 * '<S171>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon'
 * '<S172>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon/Compare To Constant'
 * '<S173>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon/Zero_Value_Exclusion'
 * '<S174>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S175>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S176>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S177>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S178>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Holder'
 * '<S179>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S180>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Observation'
 * '<S181>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Scaling'
 * '<S182>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias'
 * '<S183>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias'
 * '<S184>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias/Bias_Update'
 * '<S185>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias/Detect Increase'
 * '<S186>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S187>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S188>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S189>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S190>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S191>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S192>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S193>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/OptFlow_Vel_Init'
 * '<S194>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S195>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S196>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S197>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S198>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct'
 * '<S199>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S200>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Holder'
 * '<S201>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S202>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Observation'
 * '<S203>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling'
 * '<S204>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate'
 * '<S205>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate/Bias_Update'
 * '<S206>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate/Detect Increase'
 * '<S207>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S208>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S209>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Holder'
 * '<S210>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S211>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Observation'
 * '<S212>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Scaling'
 * '<S213>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias'
 * '<S214>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias/Bias_Update'
 * '<S215>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias/Detect Increase'
 * '<S216>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S217>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S218>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S219>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init/Reference_Height'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Bus_Selection'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Height_Reset'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Position_Reset'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Height_Reset/Detect Rise Positive'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Height_Reset/Detect Rise Positive/Positive'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Position_Reset/Detect Rise Positive'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/Pos_Reset/Position_Reset/Detect Rise Positive/Positive'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/Bus_Assignment'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Height_Ref'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Position_Ref'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3/Positive'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Init_Condition/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3/Positive'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Horizontal_Select'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero1'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero2'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero1'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero2'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero3'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero4'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero5'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero6'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Horizontal_Validity'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Vertical_Validity'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Horizontal_Validity/Compare To Zero'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/Process/Process_Data/Sensor_Valid/Position_Validity/Vertical_Validity/Compare To Zero'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/Baro_Process'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/GPS_Process'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/OpticalFlow_Process'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Meas/Sonar_Process'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/Baro_Status'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/GPS_Status'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/OpticalFlow_Status'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/Process/Sensor_Status/Sonar_Status'
 * '<S272>' : 'INS/Sensor_Process/Baro_Process'
 * '<S273>' : 'INS/Sensor_Process/GPS_Process'
 * '<S274>' : 'INS/Sensor_Process/IMU_Process'
 * '<S275>' : 'INS/Sensor_Process/Mag_Process'
 * '<S276>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing'
 * '<S277>' : 'INS/Sensor_Process/Sonar_Process'
 * '<S278>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height'
 * '<S279>' : 'INS/Sensor_Process/Baro_Process/Relative_Height'
 * '<S280>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height/Interval Test1'
 * '<S281>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status'
 * '<S282>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Reference_and_Derivative'
 * '<S283>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant'
 * '<S284>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant1'
 * '<S285>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant2'
 * '<S286>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant3'
 * '<S287>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Constant4'
 * '<S288>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Compare To Zero'
 * '<S289>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Detect Change'
 * '<S290>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Interval Test1'
 * '<S291>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Status/Interval Test2'
 * '<S292>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant'
 * '<S293>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant1'
 * '<S294>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality'
 * '<S295>' : 'INS/Sensor_Process/GPS_Process/Scaling'
 * '<S296>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model'
 * '<S297>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant2'
 * '<S298>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant4'
 * '<S299>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status'
 * '<S300>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/horizontal_acc'
 * '<S301>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/speed_acc'
 * '<S302>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check'
 * '<S303>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant'
 * '<S304>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant1'
 * '<S305>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant2'
 * '<S306>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Init_Condition'
 * '<S307>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Init_Condition/Compare To Constant3'
 * '<S308>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check/Detect Change'
 * '<S309>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model/WGS84_Derivatives'
 * '<S310>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment'
 * '<S311>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling'
 * '<S312>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check'
 * '<S313>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling'
 * '<S314>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check'
 * '<S315>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/Compare To Zero'
 * '<S316>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select'
 * '<S317>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Status'
 * '<S318>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select/2_Order_Butter_LPF'
 * '<S319>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select/2_Order_Butter_LPF1'
 * '<S320>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling/Acc_Calibrate'
 * '<S321>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling/Gyro_Calibrate'
 * '<S322>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Compare To Constant4'
 * '<S323>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Detect Change'
 * '<S324>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test1'
 * '<S325>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test3'
 * '<S326>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling/Acc_Calibrate'
 * '<S327>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling/Gyro_Calibrate'
 * '<S328>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Compare To Constant4'
 * '<S329>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Detect Change'
 * '<S330>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test1'
 * '<S331>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test3'
 * '<S332>' : 'INS/Sensor_Process/Mag_Process/Mag_Scaling'
 * '<S333>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check'
 * '<S334>' : 'INS/Sensor_Process/Mag_Process/Magnetometer'
 * '<S335>' : 'INS/Sensor_Process/Mag_Process/Mag_Scaling/Mag_Calibrate'
 * '<S336>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Compare To Constant4'
 * '<S337>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Detect Change'
 * '<S338>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Interval Test1'
 * '<S339>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Compare To Constant'
 * '<S340>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication'
 * '<S341>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation'
 * '<S342>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/wmm_lookup'
 * '<S343>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate'
 * '<S344>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate'
 * '<S345>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate'
 * '<S346>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus'
 * '<S347>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus/vec_norm'
 * '<S348>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus'
 * '<S349>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus/vec_norm'
 * '<S350>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/psi_to_Mz'
 * '<S351>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/vec_normalize'
 * '<S352>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect'
 * '<S353>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Compare To Constant4'
 * '<S354>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Detect Change'
 * '<S355>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check'
 * '<S356>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Compare To Constant'
 * '<S357>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Compare To Constant4'
 * '<S358>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Detect Change'
 * '<S359>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
