/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.3352
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan 16 09:22:21 2021
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

#ifndef DEFINED_TYPEDEF_FOR_struct_TYt7YeNdxIDXfczXumtXXB_
#define DEFINED_TYPEDEF_FOR_struct_TYt7YeNdxIDXfczXumtXXB_

typedef struct {
  uint32_T period;
  int8_T model_info[16];
} struct_TYt7YeNdxIDXfczXumtXXB;

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

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion;           /* '<S324>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S324>/Data Type Conversion1' */
  real_T Add;                          /* '<S337>/Add' */
  real_T Product4;                     /* '<S337>/Product4' */
  real32_T Divide;                     /* '<S315>/Divide' */
  real32_T h_0;                        /* '<S231>/Merge' */
  real32_T vel_D_0;                    /* '<S231>/Merge1' */
  real32_T vel_NE_0[2];                /* '<S193>/Merge1' */
  real32_T Sum1[3];                    /* '<S220>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S211>/Sum1' */
  real32_T Sum1_pu[3];                 /* '<S202>/Sum1' */
  real32_T Saturation;                 /* '<S202>/Saturation' */
  real32_T DataTypeConversion_n[2];    /* '<S194>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S179>/Sum1' */
  real32_T Merge[4];                   /* '<S114>/Merge' */
  real32_T OutportBufferForquat_0[4];  /* '<S111>/DCM_to_quat' */
  real32_T Integrator[3];              /* '<S93>/Integrator' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S260>/Delay1' */
  real_T Delay_DSTATE[2];              /* '<S261>/Delay' */
  real_T Delay1_DSTATE_o[2];           /* '<S261>/Delay1' */
  real32_T Delay_6_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_9_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_DSTATE_d;             /* '<S315>/Delay' */
  real32_T Delay_4_DSTATE;             /* '<S57>/Delay' */
  real32_T Delay_5_DSTATE;             /* '<S57>/Delay' */
  real32_T Delay_6_DSTATE_h;           /* '<S57>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S269>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S281>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S268>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S280>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_b[3];          /* '<S229>/Delay' */
  real32_T Delay_DSTATE_l[6];          /* '<S189>/Delay' */
  real32_T Delay_DSTATE_p[3];          /* '<S222>/Delay' */
  real32_T x_delay_DSTATE[5];          /* '<S224>/x_delay' */
  real32_T Delay_DSTATE_k;             /* '<S226>/Delay' */
  real32_T h_delay_DSTATE[75];         /* '<S215>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S215>/vd_delay' */
  real32_T Delay_DSTATE_dr[3];         /* '<S204>/Delay' */
  real32_T x_delay_DSTATE_b[5];        /* '<S206>/x_delay' */
  real32_T Delay_DSTATE_h;             /* '<S208>/Delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S183>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S183>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S183>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S183>/vn_delay1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S163>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S161>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S162>/Discrete-Time Integrator5' */
  real32_T Delay_8_DSTATE[9];          /* '<S58>/Delay' */
  real32_T Delay_9_DSTATE_d[9];        /* '<S58>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S100>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S101>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S90>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S88>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S90>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_gx[3];/* '<S96>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_k[3];/* '<S96>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE[3];       /* '<S93>/Integrator' */
  real32_T Integrator1_DSTATE[3];      /* '<S93>/Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_bo;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_hi;/* '<S16>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_b3;/* '<S18>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_kg;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S17>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S333>/Unit Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S379>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTA_bor;/* '<S377>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S376>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nz;/* '<S374>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S372>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S357>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S347>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S344>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S353>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S350>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S336>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_il;/* '<S327>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_cj;      /* '<S312>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nm;/* '<S308>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S318>/Delay Input1' */
  uint32_T Delay_DSTATE_f;             /* '<S316>/Delay' */
  uint32_T Delay1_DSTATE_i;            /* '<S315>/Delay1' */
  uint32_T DelayInput1_DSTATE_nb;      /* '<S221>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S212>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S203>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S180>/Delay Input1' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S217>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S213>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S186>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S181>/Memory' */
  uint16_T Delay_DSTATE_i;             /* '<S152>/Delay' */
  uint8_T Delay_DSTATE_k3;             /* '<S377>/Delay' */
  uint8_T Delay_DSTATE_hp;             /* '<S63>/Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S254>/Delay Input1' */
  boolean_T Delay_DSTATE_k4;           /* '<S269>/Delay' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S256>/Delay Input1' */
  boolean_T Delay_DSTATE_kh;           /* '<S281>/Delay' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S262>/Delay Input1' */
  boolean_T Delay_DSTATE_c;            /* '<S268>/Delay' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S264>/Delay Input1' */
  boolean_T Delay_DSTATE_n;            /* '<S280>/Delay' */
  boolean_T DelayInput1_DSTATE_ch;     /* '<S273>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S278>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S285>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_hg;     /* '<S290>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_db;     /* '<S228>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S219>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S210>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S188>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pr;     /* '<S155>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S92>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_jy;     /* '<S66>/Delay Input1' */
  boolean_T Delay_DSTATE_bn;           /* '<S13>/Delay' */
  boolean_T Delay_DSTATE_cx;           /* '<S16>/Delay' */
  boolean_T Delay_DSTATE_l0;           /* '<S18>/Delay' */
  boolean_T Delay_DSTATE_cn;           /* '<S12>/Delay' */
  boolean_T Delay_DSTATE_pk;           /* '<S14>/Delay' */
  boolean_T Delay_DSTATE_db;           /* '<S15>/Delay' */
  boolean_T Delay_DSTATE_ly;           /* '<S17>/Delay' */
  boolean_T DelayInput1_DSTATE_dx;     /* '<S22>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_mu;     /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dq;     /* '<S32>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f4;     /* '<S37>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ng;     /* '<S42>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dql;    /* '<S47>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_fq;     /* '<S52>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S269>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S281>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S268>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S280>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_bk;/* '<S100>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S93>/Integrator' */
  int8_T Integrator1_PrevResetState;   /* '<S93>/Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S16>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_dj;/* '<S18>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ar;/* '<S17>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S224>/x_delay' */
  uint8_T icLoad_o;                    /* '<S215>/h_delay' */
  uint8_T icLoad_f;                    /* '<S215>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S206>/x_delay' */
  uint8_T icLoad_op;                   /* '<S183>/x_delay' */
  uint8_T icLoad_i;                    /* '<S183>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S183>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S183>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S100>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S90>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_c;/* '<S96>/Discrete-Time Integrator1' */
  uint8_T Integrator1_IC_LOADING;      /* '<S93>/Integrator1' */
  boolean_T Relay_Mode;                /* '<S241>/Relay' */
  boolean_T Relay1_Mode;               /* '<S241>/Relay1' */
  boolean_T Relay_Mode_b;              /* '<S242>/Relay' */
  boolean_T Relay1_Mode_o;             /* '<S242>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S113>/Relay2' */
  boolean_T Relay_Mode_n;              /* '<S94>/Relay' */
  boolean_T Relay1_Mode_l;             /* '<S72>/Relay1' */
  boolean_T Relay1_Mode_j;             /* '<S10>/Relay1' */
  boolean_T Reference_Height_MODE;     /* '<S310>/Reference_Height' */
  boolean_T Rangefinder_Correct_MODE;  /* '<S201>/Rangefinder_Correct' */
  boolean_T GPS_Correct_MODE;          /* '<S200>/GPS_Correct' */
  boolean_T Baro_Correct_MODE;         /* '<S199>/Baro_Correct' */
  boolean_T GPS_Correct_MODE_o;        /* '<S177>/GPS_Correct' */
  boolean_T GPS_Meas_Acc_MODE;         /* '<S89>/GPS_Meas_Acc' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S303>/WGS84_Model' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S224>/x_delay' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S215>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S215>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE_l;      /* '<S206>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S183>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S183>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S183>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S183>/vn_delay1' */
} PrevZCSigStates_INS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  IMU_Bus IMU1;                        /* '<Root>/IMU1' */
  IMU_Bus IMU2;                        /* '<Root>/IMU2' */
  MAG_Bus MAG;                         /* '<Root>/MAG' */
  Barometer_Bus Barometer;             /* '<Root>/Barometer' */
  GPS_uBlox_Bus GPS_uBlox;             /* '<Root>/GPS_uBlox' */
  Rangefinder_Bus Rangefinder;         /* '<Root>/Rangefinder' */
  Optical_Flow_Bus Optical_Flow;       /* '<Root>/Optical_Flow' */
  uint8_T reset;                       /* '<Root>/reset' */
} ExternalInputs_INS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExternalOutputs_INS_T;

/* Parameters (default storage) */
struct Parameters_INS_T_ {
  struct_lhdUdNWnbTDz28W0g5GGc INS_CONST;/* Variable: INS_CONST
                                          * Referenced by:
                                          *   '<S70>/Constant'
                                          *   '<S230>/Constant1'
                                          */
  real_T WMM_Lookup_Table_resolution;  /* Mask Parameter: WMM_Lookup_Table_resolution
                                        * Referenced by: '<S360>/rad_to_index'
                                        */
  int32_T valid_samples_const;         /* Mask Parameter: valid_samples_const
                                        * Referenced by: '<S334>/Constant'
                                        */
  real32_T Check_Valid_acc_max;        /* Mask Parameter: Check_Valid_acc_max
                                        * Referenced by: '<S348>/Upper Limit'
                                        */
  real32_T Check_Valid_acc_max_k;      /* Mask Parameter: Check_Valid_acc_max_k
                                        * Referenced by: '<S354>/Upper Limit'
                                        */
  real32_T Check_Valid_acc_min;        /* Mask Parameter: Check_Valid_acc_min
                                        * Referenced by: '<S348>/Lower Limit'
                                        */
  real32_T Check_Valid_acc_min_k;      /* Mask Parameter: Check_Valid_acc_min_k
                                        * Referenced by: '<S354>/Lower Limit'
                                        */
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S97>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S150>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S149>/Constant'
                                        */
  real32_T Check_Valid_gyr_max;        /* Mask Parameter: Check_Valid_gyr_max
                                        * Referenced by: '<S349>/Upper Limit'
                                        */
  real32_T Check_Valid_gyr_max_e;      /* Mask Parameter: Check_Valid_gyr_max_e
                                        * Referenced by: '<S355>/Upper Limit'
                                        */
  real32_T Check_Valid_gyr_min;        /* Mask Parameter: Check_Valid_gyr_min
                                        * Referenced by: '<S349>/Lower Limit'
                                        */
  real32_T Check_Valid_gyr_min_f;      /* Mask Parameter: Check_Valid_gyr_min_f
                                        * Referenced by: '<S355>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S151>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit_m;    /* Mask Parameter: IntervalTest_lowlimit_m
                                        * Referenced by: '<S380>/Lower Limit'
                                        */
  real32_T Check_Valid_mag_max;        /* Mask Parameter: Check_Valid_mag_max
                                        * Referenced by: '<S373>/Upper Limit'
                                        */
  real32_T Check_Valid_mag_min;        /* Mask Parameter: Check_Valid_mag_min
                                        * Referenced by: '<S373>/Lower Limit'
                                        */
  real32_T Check_Valid_max_pressure;   /* Mask Parameter: Check_Valid_max_pressure
                                        * Referenced by: '<S313>/Upper Limit'
                                        */
  real32_T Check_Valid_max_temp;       /* Mask Parameter: Check_Valid_max_temp
                                        * Referenced by: '<S314>/Upper Limit'
                                        */
  real32_T Check_Valid_min_pressure;   /* Mask Parameter: Check_Valid_min_pressure
                                        * Referenced by: '<S313>/Lower Limit'
                                        */
  real32_T Check_Valid_min_temp;       /* Mask Parameter: Check_Valid_min_temp
                                        * Referenced by: '<S314>/Lower Limit'
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
  real32_T valid_hold1_time_out;       /* Mask Parameter: valid_hold1_time_out
                                        * Referenced by: '<S275>/Constant'
                                        */
  real32_T valid_hold1_time_out_o;     /* Mask Parameter: valid_hold1_time_out_o
                                        * Referenced by: '<S287>/Constant'
                                        */
  real32_T valid_hold_time_out;        /* Mask Parameter: valid_hold_time_out
                                        * Referenced by: '<S270>/Constant'
                                        */
  real32_T valid_hold_time_out_f;      /* Mask Parameter: valid_hold_time_out_f
                                        * Referenced by: '<S282>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S151>/Upper Limit'
                                        */
  real32_T IntervalTest_uplimit_d;     /* Mask Parameter: IntervalTest_uplimit_d
                                        * Referenced by: '<S380>/Upper Limit'
                                        */
  uint32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S317>/Constant'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S335>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S331>/Constant'
                                        */
  uint32_T CompareToConstant4_const_k; /* Mask Parameter: CompareToConstant4_const_k
                                        * Referenced by: '<S375>/Constant'
                                        */
  uint32_T CompareToConstant4_const_o; /* Mask Parameter: CompareToConstant4_const_o
                                        * Referenced by: '<S378>/Constant'
                                        */
  uint32_T IntervalTest3_lowlimit;     /* Mask Parameter: IntervalTest3_lowlimit
                                        * Referenced by: '<S319>/Lower Limit'
                                        */
  uint32_T Check_Valid_timeout;        /* Mask Parameter: Check_Valid_timeout
                                        * Referenced by: '<S311>/Constant'
                                        */
  uint32_T Check_Valid_timeout_a;      /* Mask Parameter: Check_Valid_timeout_a
                                        * Referenced by: '<S346>/Constant'
                                        */
  uint32_T Check_Valid_timeout_e;      /* Mask Parameter: Check_Valid_timeout_e
                                        * Referenced by: '<S352>/Constant'
                                        */
  uint32_T Check_Valid_timeout_b;      /* Mask Parameter: Check_Valid_timeout_b
                                        * Referenced by: '<S371>/Constant'
                                        */
  uint32_T IntervalTest3_uplimit;      /* Mask Parameter: IntervalTest3_uplimit
                                        * Referenced by: '<S319>/Upper Limit'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S180>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S203>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S212>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_k;       /* Mask Parameter: DetectChange_vinit_k
                                        * Referenced by: '<S221>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_n;       /* Mask Parameter: DetectChange_vinit_n
                                        * Referenced by: '<S312>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S318>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S336>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S347>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d0;      /* Mask Parameter: DetectChange_vinit_d0
                                        * Referenced by: '<S353>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S372>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S376>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_p;       /* Mask Parameter: DetectChange_vinit_p
                                        * Referenced by: '<S379>/Delay Input1'
                                        */
  int16_T WMM_Lookup_Table_wmm_declinatio[629];/* Mask Parameter: WMM_Lookup_Table_wmm_declinatio
                                                * Referenced by: '<S360>/Declination_Lookup_Table'
                                                */
  uint16_T valid_samples_const_k;      /* Mask Parameter: valid_samples_const_k
                                        * Referenced by: '<S156>/Constant'
                                        */
  boolean_T CompareToConstant1_const_m;/* Mask Parameter: CompareToConstant1_const_m
                                        * Referenced by: '<S25>/Constant'
                                        */
  boolean_T CompareToConstant1_const_j;/* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S40>/Constant'
                                        */
  boolean_T CompareToConstant1_const_g;/* Mask Parameter: CompareToConstant1_const_g
                                        * Referenced by: '<S50>/Constant'
                                        */
  boolean_T CompareToConstant1_const_e;/* Mask Parameter: CompareToConstant1_const_e
                                        * Referenced by: '<S20>/Constant'
                                        */
  boolean_T CompareToConstant1_const_ei;/* Mask Parameter: CompareToConstant1_const_ei
                                         * Referenced by: '<S30>/Constant'
                                         */
  boolean_T CompareToConstant1_const_ec;/* Mask Parameter: CompareToConstant1_const_ec
                                         * Referenced by: '<S35>/Constant'
                                         */
  boolean_T CompareToConstant1_const_em;/* Mask Parameter: CompareToConstant1_const_em
                                         * Referenced by: '<S45>/Constant'
                                         */
  boolean_T CompareToConstant2_const;  /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S21>/Constant'
                                        */
  boolean_T CompareToConstant2_const_c;/* Mask Parameter: CompareToConstant2_const_c
                                        * Referenced by: '<S26>/Constant'
                                        */
  boolean_T CompareToConstant2_const_n;/* Mask Parameter: CompareToConstant2_const_n
                                        * Referenced by: '<S31>/Constant'
                                        */
  boolean_T CompareToConstant2_const_b;/* Mask Parameter: CompareToConstant2_const_b
                                        * Referenced by: '<S36>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i;/* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S41>/Constant'
                                        */
  boolean_T CompareToConstant2_const_l;/* Mask Parameter: CompareToConstant2_const_l
                                        * Referenced by: '<S46>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i1;/* Mask Parameter: CompareToConstant2_const_i1
                                         * Referenced by: '<S51>/Constant'
                                         */
  boolean_T CompareToConstant1_const_a;/* Mask Parameter: CompareToConstant1_const_a
                                        * Referenced by: '<S276>/Constant'
                                        */
  boolean_T CompareToConstant1_const_i;/* Mask Parameter: CompareToConstant1_const_i
                                        * Referenced by: '<S288>/Constant'
                                        */
  boolean_T CompareToConstant1_const_h;/* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S271>/Constant'
                                        */
  boolean_T CompareToConstant1_const_hh;/* Mask Parameter: CompareToConstant1_const_hh
                                         * Referenced by: '<S283>/Constant'
                                         */
  boolean_T CompareToConstant2_const_d;/* Mask Parameter: CompareToConstant2_const_d
                                        * Referenced by: '<S272>/Constant'
                                        */
  boolean_T CompareToConstant2_const_d2;/* Mask Parameter: CompareToConstant2_const_d2
                                         * Referenced by: '<S277>/Constant'
                                         */
  boolean_T CompareToConstant2_const_a;/* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S284>/Constant'
                                        */
  boolean_T CompareToConstant2_const_j;/* Mask Parameter: CompareToConstant2_const_j
                                        * Referenced by: '<S289>/Constant'
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
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S66>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_b;    /* Mask Parameter: DetectIncrease_vinit_b
                                        * Referenced by: '<S92>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_fc;/* Mask Parameter: DetectRisePositive_vinit_fc
                                         * Referenced by: '<S155>/Delay Input1'
                                         */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S188>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S210>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S219>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_f;    /* Mask Parameter: DetectIncrease_vinit_f
                                        * Referenced by: '<S228>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S254>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_me;/* Mask Parameter: DetectRisePositive_vinit_me
                                         * Referenced by: '<S256>/Delay Input1'
                                         */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S262>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S264>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_d;/* Mask Parameter: DetectRisePositive_vinit_d
                                        * Referenced by: '<S273>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_ho;/* Mask Parameter: DetectRisePositive_vinit_ho
                                         * Referenced by: '<S278>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_di;/* Mask Parameter: DetectRisePositive_vinit_di
                                         * Referenced by: '<S285>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_o;/* Mask Parameter: DetectRisePositive_vinit_o
                                        * Referenced by: '<S290>/Delay Input1'
                                        */
  int8_T WMM_Lookup_Table_wmm_inclinatio[629];/* Mask Parameter: WMM_Lookup_Table_wmm_inclinatio
                                               * Referenced by: '<S360>/Inclination_Lookup_Table'
                                               */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S332>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S320>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S321>/Constant'
                                        */
  uint8_T CompareToConstant2_const_bv; /* Mask Parameter: CompareToConstant2_const_bv
                                        * Referenced by: '<S325>/Constant'
                                        */
  uint8_T WMM_Lookup_Table_wmm_magnitude[629];/* Mask Parameter: WMM_Lookup_Table_wmm_magnitude
                                               * Referenced by: '<S360>/Magnitude_Lookup_Table'
                                               */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S176>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1e-6
                                        * Referenced by: '<S176>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S176>/Constant'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S260>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S261>/Delay'
                                        */
  real_T Delay1_InitialCondition_e;    /* Expression: 0.0
                                        * Referenced by: '<S261>/Delay1'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S324>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S324>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S324>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S324>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S324>/dz_dh'
                                        */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S337>/constant2'
                                        */
  real_T b_Value;                      /* Expression: 1/298.257
                                        * Referenced by: '<S337>/b'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S337>/constant'
                                        */
  real_T earth_radius_Value;           /* Expression: 6378137
                                        * Referenced by: '<S337>/earth_radius'
                                        */
  real_T c_Value;                      /* Expression: 1
                                        * Referenced by: '<S337>/c'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S333>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S333>/Saturation'
                                        */
  int32_T Saturation_LowerSat_f;       /* Computed Parameter: Saturation_LowerSat_f
                                        * Referenced by: '<S333>/Saturation'
                                        */
  int32_T lat_offset_Value[2];         /* Computed Parameter: lat_offset_Value
                                        * Referenced by: '<S360>/lat_offset'
                                        */
  int32_T Saturation1_UpperSat[2];     /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S360>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S360>/Saturation1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S322>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S322>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S322>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S322>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain;           /* Computed Parameter: Scalefactor1_Gain
                                        * Referenced by: '<S322>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S322>/Scalefactor2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S13>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                            * Referenced by: '<S13>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
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
  real32_T DiscreteTimeIntegrator_UpperS_g;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_g
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_j;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_j
                                            * Referenced by: '<S16>/Discrete-Time Integrator'
                                            */
  real32_T Relay1_OnVal;               /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<S10>/Relay1'
                                        */
  real32_T Relay1_OffVal;              /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<S10>/Relay1'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                            * Referenced by: '<S18>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_o;/* Computed Parameter: DiscreteTimeIntegrator_IC_o
                                        * Referenced by: '<S18>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_d;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_d
                                            * Referenced by: '<S18>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_n;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_n
                                            * Referenced by: '<S18>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_n;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_n
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_l;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_l
                                            * Referenced by: '<S12>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_j;/* Computed Parameter: DiscreteTimeIntegrator_IC_j
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_UpperS_f;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_f
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_f;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_f
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_me;/* Computed Parameter: DiscreteTimeIntegrator_gainv_me
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ig;/* Computed Parameter: DiscreteTimeIntegrator_IC_ig
                                         * Referenced by: '<S15>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_m;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_m
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_i;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_i
                                            * Referenced by: '<S15>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_my;/* Computed Parameter: DiscreteTimeIntegrator_gainv_my
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_e;/* Computed Parameter: DiscreteTimeIntegrator_IC_e
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_ml;/* Computed Parameter: DiscreteTimeIntegrator_Upper_ml
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_g;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_g
                                            * Referenced by: '<S17>/Discrete-Time Integrator'
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
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S67>/Gain5'
                                        */
  real32_T Saturation1_UpperSat_a;     /* Computed Parameter: Saturation1_UpperSat_a
                                        * Referenced by: '<S67>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_b;     /* Computed Parameter: Saturation1_LowerSat_b
                                        * Referenced by: '<S67>/Saturation1'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S68>/Gain'
                                        */
  real32_T Constant1_Value;            /* Expression: single(0)
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real32_T Constant_Value_b;           /* Expression: single(1)
                                        * Referenced by: '<S65>/Constant'
                                        */
  real32_T Gain_Gain_b;                /* Expression: single(-1)
                                        * Referenced by: '<S65>/Gain'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S82>/Constant'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S83>/Constant'
                                        */
  real32_T gps_acc_O_mPs2_Y0;          /* Computed Parameter: gps_acc_O_mPs2_Y0
                                        * Referenced by: '<S93>/gps_acc_O_mPs2'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S93>/Integrator'
                                        */
  real32_T Integrator_IC;              /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S93>/Integrator'
                                        */
  real32_T Integrator1_gainval;        /* Computed Parameter: Integrator1_gainval
                                        * Referenced by: '<S93>/Integrator1'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S93>/gain'
                                        */
  real32_T gain1_Gain;                 /* Computed Parameter: gain1_Gain
                                        * Referenced by: '<S93>/gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S90>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S94>/Relay'
                                        */
  real32_T Delay_InitialCondition_m;   /* Computed Parameter: Delay_InitialCondition_m
                                        * Referenced by: '<S88>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Expression: [0;0;-INS_CONST.g]
                                        * Referenced by: '<S74>/gravity'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S75>/Gain1'
                                        */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S75>/Gain2'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S75>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S75>/Dead Zone2'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S75>/Gain'
                                        */
  real32_T Saturation_UpperSat_k;      /* Computed Parameter: Saturation_UpperSat_k
                                        * Referenced by: '<S75>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S75>/Saturation'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S82>/Switch'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S83>/Switch'
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
                                        * Referenced by: '<S76>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                            * Referenced by: '<S90>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_d;/* Computed Parameter: DiscreteTimeIntegrator_IC_d
                                        * Referenced by: '<S90>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S90>/Gain1'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S90>/Gain'
                                        */
  real32_T Relay1_OnVal_i;             /* Computed Parameter: Relay1_OnVal_i
                                        * Referenced by: '<S72>/Relay1'
                                        */
  real32_T Relay1_OffVal_o;            /* Computed Parameter: Relay1_OffVal_o
                                        * Referenced by: '<S72>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S72>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S72>/Relay1'
                                        */
  real32_T mag_correct_gain_Gain;      /* Computed Parameter: mag_correct_gain_Gain
                                        * Referenced by: '<S72>/mag_correct_gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_mt;/* Computed Parameter: DiscreteTimeIntegrator_gainv_mt
                                            * Referenced by: '<S96>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S96>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_lq;              /* Computed Parameter: Gain1_Gain_lq
                                        * Referenced by: '<S96>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_c;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_c
                                            * Referenced by: '<S96>/Discrete-Time Integrator1'
                                            */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S96>/Gain'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S70>/Gain1'
                                        */
  real32_T Saturation2_UpperSat;       /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S70>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat;       /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S70>/Saturation2'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S100>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S100>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S101>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S101>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S101>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S101>/Discrete-Time Integrator2'
                                            */
  real32_T Gain2_Gain_i4;              /* Computed Parameter: Gain2_Gain_i4
                                        * Referenced by: '<S100>/Gain2'
                                        */
  real32_T Gain_Gain_f5;               /* Computed Parameter: Gain_Gain_f5
                                        * Referenced by: '<S102>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S102>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S102>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S102>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S102>/Gain4'
                                        */
  real32_T Gain5_Gain_e;               /* Computed Parameter: Gain5_Gain_e
                                        * Referenced by: '<S102>/Gain5'
                                        */
  real32_T Delay_8_InitialCondition;   /* Computed Parameter: Delay_8_InitialCondition
                                        * Referenced by: '<S58>/Delay'
                                        */
  real32_T Delay_9_InitialCondition;   /* Computed Parameter: Delay_9_InitialCondition
                                        * Referenced by: '<S58>/Delay'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S121>/Constant'
                                        */
  real32_T Gain_Gain_ob;               /* Computed Parameter: Gain_Gain_ob
                                        * Referenced by: '<S121>/Gain'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S121>/Gain1'
                                        */
  real32_T Constant2_Value[2];         /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S135>/Constant2'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S135>/Constant1'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S136>/Constant'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S124>/Gain'
                                        */
  real32_T Gain1_Gain_jb;              /* Computed Parameter: Gain1_Gain_jb
                                        * Referenced by: '<S124>/Gain1'
                                        */
  real32_T Gain3_Gain_e;               /* Computed Parameter: Gain3_Gain_e
                                        * Referenced by: '<S124>/Gain3'
                                        */
  real32_T Gain4_Gain_h;               /* Computed Parameter: Gain4_Gain_h
                                        * Referenced by: '<S124>/Gain4'
                                        */
  real32_T Constant2_Value_i[2];       /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S140>/Constant2'
                                        */
  real32_T Constant1_Value_nt;         /* Computed Parameter: Constant1_Value_nt
                                        * Referenced by: '<S140>/Constant1'
                                        */
  real32_T Constant_Value_jf;          /* Computed Parameter: Constant_Value_jf
                                        * Referenced by: '<S141>/Constant'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S125>/Gain'
                                        */
  real32_T Gain1_Gain_l2;              /* Computed Parameter: Gain1_Gain_l2
                                        * Referenced by: '<S125>/Gain1'
                                        */
  real32_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S125>/Gain2'
                                        */
  real32_T Gain3_Gain_l;               /* Computed Parameter: Gain3_Gain_l
                                        * Referenced by: '<S125>/Gain3'
                                        */
  real32_T Constant2_Value_g[2];       /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S130>/Constant2'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S130>/Constant1'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S131>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S123>/Gain'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S123>/Gain1'
                                        */
  real32_T Gain2_Gain_os;              /* Computed Parameter: Gain2_Gain_os
                                        * Referenced by: '<S123>/Gain2'
                                        */
  real32_T Gain3_Gain_d;               /* Computed Parameter: Gain3_Gain_d
                                        * Referenced by: '<S123>/Gain3'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S117>/Constant'
                                        */
  real32_T Constant_Value_af;          /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S118>/Constant'
                                        */
  real32_T Constant_Value_fk;          /* Computed Parameter: Constant_Value_fk
                                        * Referenced by: '<S119>/Constant'
                                        */
  real32_T quat_0_Y0[4];               /* Computed Parameter: quat_0_Y0
                                        * Referenced by: '<S111>/quat_0'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S111>/Gain'
                                        */
  real32_T Switch_Threshold_i;         /* Computed Parameter: Switch_Threshold_i
                                        * Referenced by: '<S117>/Switch'
                                        */
  real32_T Switch_Threshold_o;         /* Computed Parameter: Switch_Threshold_o
                                        * Referenced by: '<S118>/Switch'
                                        */
  real32_T Switch_Threshold_j;         /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S119>/Switch'
                                        */
  real32_T Merge_InitialOutput[4];     /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S114>/Merge'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<S163>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC; /* Computed Parameter: DiscreteTimeIntegrator5_IC
                                        * Referenced by: '<S163>/Discrete-Time Integrator5'
                                        */
  real32_T Gain2_Gain_h;               /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S163>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_o;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_o
                                            * Referenced by: '<S161>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_m;/* Computed Parameter: DiscreteTimeIntegrator5_IC_m
                                         * Referenced by: '<S161>/Discrete-Time Integrator5'
                                         */
  real32_T Gain2_Gain_c;               /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S161>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_b;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_b
                                            * Referenced by: '<S162>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_a;/* Computed Parameter: DiscreteTimeIntegrator5_IC_a
                                         * Referenced by: '<S162>/Discrete-Time Integrator5'
                                         */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S113>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S113>/Saturation2'
                                        */
  real32_T Gain2_Gain_f;               /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S162>/Gain2'
                                        */
  real32_T Relay2_OnVal;               /* Computed Parameter: Relay2_OnVal
                                        * Referenced by: '<S113>/Relay2'
                                        */
  real32_T Relay2_OffVal;              /* Computed Parameter: Relay2_OffVal
                                        * Referenced by: '<S113>/Relay2'
                                        */
  real32_T Relay2_YOn;                 /* Computed Parameter: Relay2_YOn
                                        * Referenced by: '<S113>/Relay2'
                                        */
  real32_T Relay2_YOff;                /* Computed Parameter: Relay2_YOff
                                        * Referenced by: '<S113>/Relay2'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S173>/Constant'
                                        */
  real32_T Gain3_Gain_j;               /* Computed Parameter: Gain3_Gain_j
                                        * Referenced by: '<S182>/Gain3'
                                        */
  real32_T Gain_Gain_o0;               /* Computed Parameter: Gain_Gain_o0
                                        * Referenced by: '<S182>/Gain'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S182>/Gain2'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S179>/X_Next'
                                        */
  real32_T Memory_InitialCondition[2]; /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S186>/Memory'
                                        */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S181>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S181>/Gain3'
                                        */
  real32_T Constant_Value_bj[2];       /* Computed Parameter: Constant_Value_bj
                                        * Referenced by: '<S191>/Constant'
                                        */
  real32_T X_0_Y0;                     /* Computed Parameter: X_0_Y0
                                        * Referenced by: '<S194>/X_0'
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
  real32_T Gain_Gain_by;               /* Computed Parameter: Gain_Gain_by
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
  real32_T Gain_Gain_p;                /* Expression: INS_CONST.dt
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
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S223>/Gain1'
                                        */
  real32_T Gain_Gain_lp;               /* Computed Parameter: Gain_Gain_lp
                                        * Referenced by: '<S223>/Gain'
                                        */
  real32_T X_Next_Y0_h;                /* Computed Parameter: X_Next_Y0_h
                                        * Referenced by: '<S220>/X_Next'
                                        */
  real32_T Delay_InitialCondition_k;   /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S222>/Delay'
                                        */
  real32_T Delay_InitialCondition_l;   /* Computed Parameter: Delay_InitialCondition_l
                                        * Referenced by: '<S226>/Delay'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S223>/Gain2'
                                        */
  real32_T Gain_Gain_bd;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S222>/Gain'
                                        */
  real32_T Constant_Value_eq;          /* Computed Parameter: Constant_Value_eq
                                        * Referenced by: '<S231>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S235>/Constant'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S237>/Constant'
                                        */
  real32_T Merge_InitialOutput_j;      /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S231>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S231>/Merge1'
                                        */
  real32_T Delay_InitialCondition_mt;  /* Computed Parameter: Delay_InitialCondition_mt
                                        * Referenced by: '<S229>/Delay'
                                        */
  real32_T Gain1_Gain_kw;              /* Computed Parameter: Gain1_Gain_kw
                                        * Referenced by: '<S230>/Gain1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S230>/Constant'
                                        */
  real32_T Gain_Gain_mr;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S230>/Gain'
                                        */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S189>/Delay'
                                        */
  real32_T Constant_Value_l[2];        /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S190>/Constant'
                                        */
  real32_T Gain_Gain_i;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S190>/Gain'
                                        */
  real32_T Relay_OnVal_d;              /* Computed Parameter: Relay_OnVal_d
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay_OffVal_i;             /* Computed Parameter: Relay_OffVal_i
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay_YOn_c;                /* Computed Parameter: Relay_YOn_c
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay_YOff_j;               /* Computed Parameter: Relay_YOff_j
                                        * Referenced by: '<S241>/Relay'
                                        */
  real32_T Relay1_OnVal_j;             /* Computed Parameter: Relay1_OnVal_j
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay1_OffVal_a;            /* Computed Parameter: Relay1_OffVal_a
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay1_YOn_o;               /* Computed Parameter: Relay1_YOn_o
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay1_YOff_k;              /* Computed Parameter: Relay1_YOff_k
                                        * Referenced by: '<S241>/Relay1'
                                        */
  real32_T Relay_OnVal_a;              /* Computed Parameter: Relay_OnVal_a
                                        * Referenced by: '<S242>/Relay'
                                        */
  real32_T Relay_OffVal_h;             /* Computed Parameter: Relay_OffVal_h
                                        * Referenced by: '<S242>/Relay'
                                        */
  real32_T Relay_YOn_i;                /* Computed Parameter: Relay_YOn_i
                                        * Referenced by: '<S242>/Relay'
                                        */
  real32_T Relay_YOff_g;               /* Computed Parameter: Relay_YOff_g
                                        * Referenced by: '<S242>/Relay'
                                        */
  real32_T Relay1_OnVal_m;             /* Computed Parameter: Relay1_OnVal_m
                                        * Referenced by: '<S242>/Relay1'
                                        */
  real32_T Relay1_OffVal_o5;           /* Computed Parameter: Relay1_OffVal_o5
                                        * Referenced by: '<S242>/Relay1'
                                        */
  real32_T Relay1_YOn_e;               /* Computed Parameter: Relay1_YOn_e
                                        * Referenced by: '<S242>/Relay1'
                                        */
  real32_T Relay1_YOff_m;              /* Computed Parameter: Relay1_YOff_m
                                        * Referenced by: '<S242>/Relay1'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_jo;/* Computed Parameter: DiscreteTimeIntegrator_gainv_jo
                                            * Referenced by: '<S269>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_lb;/* Computed Parameter: DiscreteTimeIntegrator_IC_lb
                                         * Referenced by: '<S269>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_j;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_j
                                            * Referenced by: '<S269>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_Lower_f2;/* Computed Parameter: DiscreteTimeIntegrator_Lower_f2
                                            * Referenced by: '<S269>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                            * Referenced by: '<S281>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_gv;/* Computed Parameter: DiscreteTimeIntegrator_IC_gv
                                         * Referenced by: '<S281>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_p;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_p
                                            * Referenced by: '<S281>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_p;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_p
                                            * Referenced by: '<S281>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                            * Referenced by: '<S268>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_h;/* Computed Parameter: DiscreteTimeIntegrator_IC_h
                                        * Referenced by: '<S268>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_fv;/* Computed Parameter: DiscreteTimeIntegrator_Upper_fv
                                            * Referenced by: '<S268>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_b;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_b
                                            * Referenced by: '<S268>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_iy;/* Computed Parameter: DiscreteTimeIntegrator_gainv_iy
                                            * Referenced by: '<S280>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S280>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_jm;/* Computed Parameter: DiscreteTimeIntegrator_Upper_jm
                                            * Referenced by: '<S280>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_d;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_d
                                            * Referenced by: '<S280>/Discrete-Time Integrator'
                                            */
  real32_T Delay_4_InitialCondition;   /* Computed Parameter: Delay_4_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_5_InitialCondition;   /* Computed Parameter: Delay_5_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_6_InitialCondition;   /* Computed Parameter: Delay_6_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T h_R_m_Y0;                   /* Computed Parameter: h_R_m_Y0
                                        * Referenced by: '<S315>/h_R_m'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S315>/Delay'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S309>/Gain1'
                                        */
  real32_T p1_Value;                   /* Computed Parameter: p1_Value
                                        * Referenced by: '<S309>/p1'
                                        */
  real32_T aR_g_Value;                 /* Computed Parameter: aR_g_Value
                                        * Referenced by: '<S309>/aR_g'
                                        */
  real32_T T1_Value;                   /* Computed Parameter: T1_Value
                                        * Referenced by: '<S309>/T1'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S309>/a'
                                        */
  real32_T Constant1_Value_g;          /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S328>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S328>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S328>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S328>/Saturation1'
                                        */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S329>/Constant7'
                                        */
  real32_T Gain3_Gain_lx;              /* Computed Parameter: Gain3_Gain_lx
                                        * Referenced by: '<S329>/Gain3'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S329>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S329>/Saturation'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S358>/default_mag_quality'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S363>/Nominal_Magnitude'
                                        */
  real32_T gain_Gain_m;                /* Computed Parameter: gain_Gain_m
                                        * Referenced by: '<S363>/gain'
                                        */
  real32_T Constant1_Value_cq;         /* Computed Parameter: Constant1_Value_cq
                                        * Referenced by: '<S363>/Constant1'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S363>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S363>/Saturation'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S362>/gain'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S362>/Constant2'
                                        */
  real32_T Saturation_UpperSat_gg;     /* Computed Parameter: Saturation_UpperSat_gg
                                        * Referenced by: '<S362>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S362>/Saturation'
                                        */
  real32_T Constant_Value_g2;          /* Computed Parameter: Constant_Value_g2
                                        * Referenced by: '<S370>/Constant'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S368>/Constant3'
                                        */
  real32_T Gain_Gain_fl;               /* Computed Parameter: Gain_Gain_fl
                                        * Referenced by: '<S368>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S368>/Constant4'
                                        */
  real32_T Constant2_Value_l;          /* Computed Parameter: Constant2_Value_l
                                        * Referenced by: '<S368>/Constant2'
                                        */
  real32_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S368>/Constant1'
                                        */
  real32_T Constant_Value_pf;          /* Computed Parameter: Constant_Value_pf
                                        * Referenced by: '<S368>/Constant'
                                        */
  real32_T Constant1_Value_be;         /* Computed Parameter: Constant1_Value_be
                                        * Referenced by: '<S369>/Constant1'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S305>/Gauss_to_uT'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S370>/Switch'
                                        */
  real32_T Constant_Value_bg;          /* Computed Parameter: Constant_Value_bg
                                        * Referenced by: '<S306>/Constant'
                                        */
  real32_T Constant_Value_jp;          /* Computed Parameter: Constant_Value_jp
                                        * Referenced by: '<S374>/Constant'
                                        */
  real32_T Delay_6_InitialCondition_m; /* Computed Parameter: Delay_6_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  real32_T Delay_9_InitialCondition_m; /* Computed Parameter: Delay_9_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S328>/Gain1'
                                        */
  uint32_T Gain5_Gain_a;               /* Computed Parameter: Gain5_Gain_a
                                        * Referenced by: '<S329>/Gain5'
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
  uint32_T Delay_DelayLength_o;        /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S63>/Delay'
                                        */
  uint32_T Delay_8_DelayLength;        /* Computed Parameter: Delay_8_DelayLength
                                        * Referenced by: '<S58>/Delay'
                                        */
  uint32_T Delay_9_DelayLength;        /* Computed Parameter: Delay_9_DelayLength
                                        * Referenced by: '<S58>/Delay'
                                        */
  uint32_T Delay_DelayLength_fi;       /* Computed Parameter: Delay_DelayLength_fi
                                        * Referenced by: '<S152>/Delay'
                                        */
  uint32_T x_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S183>/x_delay'
                                        */
  uint32_T x_delay1_DelayLength;       /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S183>/x_delay1'
                                        */
  uint32_T vn_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S183>/vn_delay'
                                        */
  uint32_T vn_delay1_DelayLength;      /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S183>/vn_delay1'
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
  uint32_T Delay_DelayLength_op;       /* Computed Parameter: Delay_DelayLength_op
                                        * Referenced by: '<S222>/Delay'
                                        */
  uint32_T x_delay_DelayLength_l;      /* Expression: 10/INS_EXPORT_VALUE.period
                                        * Referenced by: '<S224>/x_delay'
                                        */
  uint32_T Delay_DelayLength_kz;       /* Computed Parameter: Delay_DelayLength_kz
                                        * Referenced by: '<S226>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S229>/Delay'
                                        */
  uint32_T Delay_DelayLength_ly;       /* Computed Parameter: Delay_DelayLength_ly
                                        * Referenced by: '<S189>/Delay'
                                        */
  uint32_T Delay_DelayLength_g;        /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S269>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S281>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S260>/Delay1'
                                        */
  uint32_T Delay_DelayLength_d0;       /* Computed Parameter: Delay_DelayLength_d0
                                        * Referenced by: '<S268>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S261>/Delay'
                                        */
  uint32_T Delay1_DelayLength_o;       /* Computed Parameter: Delay1_DelayLength_o
                                        * Referenced by: '<S261>/Delay1'
                                        */
  uint32_T Delay_DelayLength_cp;       /* Computed Parameter: Delay_DelayLength_cp
                                        * Referenced by: '<S280>/Delay'
                                        */
  uint32_T Delay_4_DelayLength;        /* Computed Parameter: Delay_4_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_5_DelayLength;        /* Computed Parameter: Delay_5_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_6_DelayLength;        /* Computed Parameter: Delay_6_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S315>/Constant1'
                                        */
  uint32_T Delay_DelayLength_jx;       /* Computed Parameter: Delay_DelayLength_jx
                                        * Referenced by: '<S315>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S315>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition_k;  /* Computed Parameter: Delay1_InitialCondition_k
                                        * Referenced by: '<S315>/Delay1'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S315>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S315>/Saturation1'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_iu;/* Computed Parameter: DiscreteTimeIntegrator_IC_iu
                                         * Referenced by: '<S308>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_dn;       /* Computed Parameter: Delay_DelayLength_dn
                                        * Referenced by: '<S316>/Delay'
                                        */
  uint32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S316>/Delay'
                                        */
  uint32_T Saturation_UpperSat_f;      /* Computed Parameter: Saturation_UpperSat_f
                                        * Referenced by: '<S316>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_pw;     /* Computed Parameter: Saturation_LowerSat_pw
                                        * Referenced by: '<S316>/Saturation'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S327>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_ba;/* Computed Parameter: DiscreteTimeIntegrator_IC_ba
                                         * Referenced by: '<S344>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S350>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_kz;/* Computed Parameter: DiscreteTimeIntegrator_IC_kz
                                         * Referenced by: '<S357>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_gf;/* Computed Parameter: DiscreteTimeIntegrator_IC_gf
                                         * Referenced by: '<S374>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_ov;/* Computed Parameter: DiscreteTimeIntegrator_IC_ov
                                         * Referenced by: '<S377>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S377>/Delay'
                                        */
  uint32_T Delay_6_DelayLength_g;      /* Computed Parameter: Delay_6_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay_9_DelayLength_g;      /* Computed Parameter: Delay_9_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  int16_T Gain_Gain_fs;                /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S359>/Gain'
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
  uint16_T Gain5_Gain_en;              /* Computed Parameter: Gain5_Gain_en
                                        * Referenced by: '<S8>/Gain5'
                                        */
  uint16_T Gain4_Gain_a;               /* Computed Parameter: Gain4_Gain_a
                                        * Referenced by: '<S8>/Gain4'
                                        */
  uint16_T Gain2_Gain_o5;              /* Computed Parameter: Gain2_Gain_o5
                                        * Referenced by: '<S8>/Gain2'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S88>/GPS_Delay'
                                        */
  uint16_T Delay_InitialCondition_n0;  /* Computed Parameter: Delay_InitialCondition_n0
                                        * Referenced by: '<S152>/Delay'
                                        */
  uint16_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S152>/Saturation'
                                        */
  uint16_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S152>/Saturation'
                                        */
  uint16_T Constant_Value_bt;          /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S255>/Constant'
                                        */
  uint16_T Constant_Value_gn;          /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S257>/Constant'
                                        */
  uint16_T Constant_Value_m3;          /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S263>/Constant'
                                        */
  uint16_T Constant_Value_pt;          /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S265>/Constant'
                                        */
  boolean_T Delay_InitialCondition_go; /* Computed Parameter: Delay_InitialCondition_go
                                        * Referenced by: '<S13>/Delay'
                                        */
  boolean_T Delay_InitialCondition_mz; /* Computed Parameter: Delay_InitialCondition_mz
                                        * Referenced by: '<S16>/Delay'
                                        */
  boolean_T Relay1_YOn_i;              /* Computed Parameter: Relay1_YOn_i
                                        * Referenced by: '<S10>/Relay1'
                                        */
  boolean_T Relay1_YOff_kl;            /* Computed Parameter: Relay1_YOff_kl
                                        * Referenced by: '<S10>/Relay1'
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
  boolean_T Constant_Value_ao;         /* Computed Parameter: Constant_Value_ao
                                        * Referenced by: '<S53>/Constant'
                                        */
  boolean_T Constant_Value_afo;        /* Computed Parameter: Constant_Value_afo
                                        * Referenced by: '<S157>/Constant'
                                        */
  boolean_T Constant_Value_ej;         /* Computed Parameter: Constant_Value_ej
                                        * Referenced by: '<S243>/Constant'
                                        */
  boolean_T Constant_Value_ez;         /* Computed Parameter: Constant_Value_ez
                                        * Referenced by: '<S244>/Constant'
                                        */
  boolean_T Constant_Value_pfd;        /* Computed Parameter: Constant_Value_pfd
                                        * Referenced by: '<S245>/Constant'
                                        */
  boolean_T Delay_InitialCondition_ns; /* Computed Parameter: Delay_InitialCondition_ns
                                        * Referenced by: '<S269>/Delay'
                                        */
  boolean_T Delay_InitialCondition_i;  /* Computed Parameter: Delay_InitialCondition_i
                                        * Referenced by: '<S281>/Delay'
                                        */
  boolean_T Delay_InitialCondition_d;  /* Computed Parameter: Delay_InitialCondition_d
                                        * Referenced by: '<S268>/Delay'
                                        */
  boolean_T Delay_InitialCondition_kd; /* Computed Parameter: Delay_InitialCondition_kd
                                        * Referenced by: '<S280>/Delay'
                                        */
  boolean_T Constant_Value_ej0;        /* Computed Parameter: Constant_Value_ej0
                                        * Referenced by: '<S274>/Constant'
                                        */
  boolean_T Constant_Value_jo;         /* Computed Parameter: Constant_Value_jo
                                        * Referenced by: '<S279>/Constant'
                                        */
  boolean_T Constant_Value_nm;         /* Computed Parameter: Constant_Value_nm
                                        * Referenced by: '<S286>/Constant'
                                        */
  boolean_T Constant_Value_dc;         /* Computed Parameter: Constant_Value_dc
                                        * Referenced by: '<S291>/Constant'
                                        */
  int8_T Saturation_UpperSat_gx;       /* Computed Parameter: Saturation_UpperSat_gx
                                        * Referenced by: '<S242>/Saturation'
                                        */
  int8_T Saturation_LowerSat_co;       /* Computed Parameter: Saturation_LowerSat_co
                                        * Referenced by: '<S242>/Saturation'
                                        */
  int8_T Constant_Value_lc;            /* Computed Parameter: Constant_Value_lc
                                        * Referenced by: '<S246>/Constant'
                                        */
  int8_T Constant_Value_h5;            /* Computed Parameter: Constant_Value_h5
                                        * Referenced by: '<S247>/Constant'
                                        */
  int8_T Saturation1_UpperSat_i;       /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S242>/Saturation1'
                                        */
  int8_T Saturation1_LowerSat_g;       /* Computed Parameter: Saturation1_LowerSat_g
                                        * Referenced by: '<S242>/Saturation1'
                                        */
  int8_T Constant_Value_kt;            /* Computed Parameter: Constant_Value_kt
                                        * Referenced by: '<S248>/Constant'
                                        */
  int8_T Gain1_Gain_od;                /* Computed Parameter: Gain1_Gain_od
                                        * Referenced by: '<S362>/Gain1'
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
  uint8_T Gain_Gain_od;                /* Computed Parameter: Gain_Gain_od
                                        * Referenced by: '<S343>/Gain'
                                        */
  uint8_T Gain9_Gain;                  /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S8>/Gain9'
                                        */
  uint8_T Constant_Value_hm;           /* Computed Parameter: Constant_Value_hm
                                        * Referenced by: '<S63>/Constant'
                                        */
  uint8_T Delay_InitialCondition_o;    /* Computed Parameter: Delay_InitialCondition_o
                                        * Referenced by: '<S63>/Delay'
                                        */
  uint8_T Constant_Value_jz;           /* Computed Parameter: Constant_Value_jz
                                        * Referenced by: '<S166>/Constant'
                                        */
  uint8_T Constant_Value_jn;           /* Computed Parameter: Constant_Value_jn
                                        * Referenced by: '<S341>/Constant'
                                        */
  uint8_T Constant2_Value_b;           /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S377>/Constant2'
                                        */
  uint8_T Delay_InitialCondition_f;    /* Computed Parameter: Delay_InitialCondition_f
                                        * Referenced by: '<S377>/Delay'
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
                                                 *   '<S308>/Constant'
                                                 *   '<S357>/Constant'
                                                 *   '<S377>/Constant1'
                                                 *   '<S12>/Constant'
                                                 *   '<S13>/Constant'
                                                 *   '<S14>/Constant'
                                                 *   '<S15>/Constant'
                                                 *   '<S16>/Constant'
                                                 *   '<S17>/Constant'
                                                 *   '<S18>/Constant'
                                                 *   '<S327>/Constant'
                                                 *   '<S344>/Constant'
                                                 *   '<S350>/Constant'
                                                 *   '<S268>/Constant'
                                                 *   '<S269>/Constant'
                                                 *   '<S280>/Constant'
                                                 *   '<S281>/Constant'
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
 * '<S9>'   : 'INS/Bus_Assignment/Status_Output/INS_Ready'
 * '<S10>'  : 'INS/Bus_Assignment/Status_Output/INS_Valid'
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
 * '<S58>'  : 'INS/Data_Fusion/AHRS/AHRS'
 * '<S59>'  : 'INS/Data_Fusion/AHRS/RF_Data'
 * '<S60>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment'
 * '<S61>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct'
 * '<S62>'  : 'INS/Data_Fusion/AHRS/AHRS/Update'
 * '<S63>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Att_Init_Done'
 * '<S64>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Euler_Angle'
 * '<S65>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/M_CO'
 * '<S66>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Att_Init_Done/Detect Increase'
 * '<S67>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Euler_Angle/Euler_Angle'
 * '<S68>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Euler_Angle/Euler_Angle/quat_to_psi'
 * '<S69>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction'
 * '<S70>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction'
 * '<S71>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct'
 * '<S72>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Mag_Correct'
 * '<S73>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct'
 * '<S74>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator'
 * '<S75>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct'
 * '<S76>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct'
 * '<S77>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product'
 * '<S78>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem'
 * '<S79>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem1'
 * '<S80>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation'
 * '<S81>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/cross_product'
 * '<S82>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize'
 * '<S83>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize1'
 * '<S84>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation/vec_modulus'
 * '<S85>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/Saturation/vec_modulus/vec_norm'
 * '<S86>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/cross_product/Subsystem'
 * '<S87>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/cross_product/Subsystem1'
 * '<S88>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Estimate_Acc'
 * '<S89>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc'
 * '<S90>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Estimate_Acc/Butter_LPF'
 * '<S91>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Bus_Selection'
 * '<S92>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Detect Increase'
 * '<S93>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/GPS_Meas_Acc'
 * '<S94>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Estimator/Measure_Acc/Valid_Check'
 * '<S95>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Mag_Correct/Subsystem'
 * '<S96>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/Butter_LPF'
 * '<S97>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/Compare To Constant'
 * '<S98>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/vec_modulus'
 * '<S99>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/vec_modulus/vec_norm'
 * '<S100>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update'
 * '<S101>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Gyro_Bias_Update'
 * '<S102>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/Quat_to_DCM_OB'
 * '<S103>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat mult'
 * '<S104>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat normalize'
 * '<S105>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat mult/q(0)'
 * '<S106>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat mult/q(1)'
 * '<S107>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat mult/q(2)'
 * '<S108>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat mult/q(3)'
 * '<S109>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat normalize/quat modulus'
 * '<S110>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/quat normalize/quat modulus/quat norm'
 * '<S111>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude'
 * '<S112>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition'
 * '<S113>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition'
 * '<S114>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat'
 * '<S115>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/cross_product'
 * '<S116>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/cross_product1'
 * '<S117>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/vec_normalize'
 * '<S118>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/vec_normalize1'
 * '<S119>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/vec_normalize2'
 * '<S120>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace'
 * '<S121>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/PositiveTrace'
 * '<S122>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/trace(DCM)'
 * '<S123>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)'
 * '<S124>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)'
 * '<S125>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)'
 * '<S126>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/diag(DCM)'
 * '<S127>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S128>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S129>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S130>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S131>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S132>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S133>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S134>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S135>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S136>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S137>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S138>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S139>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S140>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S141>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S142>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/PositiveTrace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S143>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/PositiveTrace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S144>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/DCM_to_quat/PositiveTrace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S145>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/cross_product/Subsystem'
 * '<S146>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/cross_product/Subsystem1'
 * '<S147>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/cross_product1/Subsystem'
 * '<S148>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/cross_product1/Subsystem1'
 * '<S149>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/Compare To Constant'
 * '<S150>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/Compare To Constant1'
 * '<S151>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/Interval Test'
 * '<S152>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition'
 * '<S153>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus'
 * '<S154>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus1'
 * '<S155>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition/Detect Rise Positive'
 * '<S156>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition/valid_samples'
 * '<S157>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition/Detect Rise Positive/Positive'
 * '<S158>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus/vec_norm'
 * '<S159>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus1/vec_norm'
 * '<S160>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/HPF'
 * '<S161>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/LPF'
 * '<S162>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/LPF1'
 * '<S163>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/HPF/LPF'
 * '<S164>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S165>' : 'INS/Data_Fusion/Translation_Filter/TF_Data'
 * '<S166>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment'
 * '<S167>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S168>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S169>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select'
 * '<S170>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/Bus_Select'
 * '<S171>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/Local_Position'
 * '<S172>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/WGS84_Position'
 * '<S173>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/Local_Position/Height_Above_Ground'
 * '<S174>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/WGS84_Position/WGS84_Position'
 * '<S175>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/WGS84_Position/WGS84_Position/safe_divide'
 * '<S176>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Bus_Select/WGS84_Position/WGS84_Position/safe_divide/Zero_Value_Exclusion'
 * '<S177>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S178>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S179>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S180>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S181>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Error_Integrate'
 * '<S182>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Error_Scaling'
 * '<S183>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Estimate_State'
 * '<S184>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S185>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S186>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S187>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Bias_Update'
 * '<S188>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Detect Increase'
 * '<S189>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S190>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S191>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S192>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S193>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S194>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S195>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S196>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/OptFlow_Vel_Init'
 * '<S197>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S198>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S199>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S200>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S201>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct'
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
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Detect Change'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Error_Hold'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Error_Scaling'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Estimate_State'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Bias'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init/Reference_Height'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Horizontal_Select'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero2'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero1'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero4'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero5'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero6'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Height_Reset'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Position_Reset'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Height_Reset/Detect Rise Positive'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Height_Reset/Detect Rise Positive/Positive'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Position_Reset/Detect Rise Positive'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Position_Reset/Detect Rise Positive/Positive'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Bus_Assignment'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Bus_Select'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Height_Ref'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Position_Ref'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Height_Ref/Detect Rise Positive3'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Height_Ref/Detect Rise Positive3/Positive'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Position_Ref/Detect Rise Positive3'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Position_Ref/Detect Rise Positive3/Positive'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold1'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold/Compare To Constant'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold/Compare To Constant1'
 * '<S272>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold/Compare To Constant2'
 * '<S273>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold/Detect Rise Positive'
 * '<S274>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S275>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold1/Compare To Constant'
 * '<S276>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold1/Compare To Constant1'
 * '<S277>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold1/Compare To Constant2'
 * '<S278>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold1/Detect Rise Positive'
 * '<S279>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Altitude_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S280>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold'
 * '<S281>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold1'
 * '<S282>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold/Compare To Constant'
 * '<S283>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold/Compare To Constant1'
 * '<S284>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold/Compare To Constant2'
 * '<S285>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold/Detect Rise Positive'
 * '<S286>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S287>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold1/Compare To Constant'
 * '<S288>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold1/Compare To Constant1'
 * '<S289>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold1/Compare To Constant2'
 * '<S290>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold1/Detect Rise Positive'
 * '<S291>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Positon_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S292>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures'
 * '<S293>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status'
 * '<S294>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/Barometer_Meas'
 * '<S295>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/GPS_Meas'
 * '<S296>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/OpticalFlow_Meas'
 * '<S297>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/Sonar_Meas'
 * '<S298>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/Barometer_Status'
 * '<S299>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/GPS_Status'
 * '<S300>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/OpticalFlow_Status'
 * '<S301>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/Sonar_Status'
 * '<S302>' : 'INS/Sensor_Process/Baro_Process'
 * '<S303>' : 'INS/Sensor_Process/GPS_Process'
 * '<S304>' : 'INS/Sensor_Process/IMU_Process'
 * '<S305>' : 'INS/Sensor_Process/MAG_Process'
 * '<S306>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing'
 * '<S307>' : 'INS/Sensor_Process/Rangefinder_Process'
 * '<S308>' : 'INS/Sensor_Process/Baro_Process/Check_Valid'
 * '<S309>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height'
 * '<S310>' : 'INS/Sensor_Process/Baro_Process/Relative_Height'
 * '<S311>' : 'INS/Sensor_Process/Baro_Process/Check_Valid/Compare To Constant4'
 * '<S312>' : 'INS/Sensor_Process/Baro_Process/Check_Valid/Detect Change'
 * '<S313>' : 'INS/Sensor_Process/Baro_Process/Check_Valid/Interval Test1'
 * '<S314>' : 'INS/Sensor_Process/Baro_Process/Check_Valid/Interval Test2'
 * '<S315>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Reference_Height'
 * '<S316>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling'
 * '<S317>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling/Compare To Constant'
 * '<S318>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling/Detect Change'
 * '<S319>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling/Interval Test3'
 * '<S320>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant'
 * '<S321>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant1'
 * '<S322>' : 'INS/Sensor_Process/GPS_Process/Data_Scalling'
 * '<S323>' : 'INS/Sensor_Process/GPS_Process/Status_Quality'
 * '<S324>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model'
 * '<S325>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/Compare To Constant2'
 * '<S326>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status'
 * '<S327>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/check_timeout'
 * '<S328>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/horizontal_quality'
 * '<S329>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/speed_acc'
 * '<S330>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/vertical_quality'
 * '<S331>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Compare To Constant'
 * '<S332>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Compare To Constant1'
 * '<S333>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Ready'
 * '<S334>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Ready/valid_samples'
 * '<S335>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/check_timeout/Compare To Constant4'
 * '<S336>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/check_timeout/Detect Change'
 * '<S337>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model/WGS84_Derivative'
 * '<S338>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment'
 * '<S339>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process'
 * '<S340>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process'
 * '<S341>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/Compare To Zero'
 * '<S342>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select'
 * '<S343>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Status'
 * '<S344>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Check_Valid'
 * '<S345>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Data_Select'
 * '<S346>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Check_Valid/Compare To Constant4'
 * '<S347>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Check_Valid/Detect Change'
 * '<S348>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Check_Valid/Interval Test1'
 * '<S349>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Check_Valid/Interval Test3'
 * '<S350>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Check_Valid'
 * '<S351>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Data_Select'
 * '<S352>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Check_Valid/Compare To Constant4'
 * '<S353>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Check_Valid/Detect Change'
 * '<S354>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Check_Valid/Interval Test1'
 * '<S355>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Check_Valid/Interval Test3'
 * '<S356>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment'
 * '<S357>' : 'INS/Sensor_Process/MAG_Process/Check_Valid'
 * '<S358>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate'
 * '<S359>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation'
 * '<S360>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Lookup_Table'
 * '<S361>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate'
 * '<S362>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Inclination_Quality_Estimate'
 * '<S363>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Intensity_Quality_Estimate'
 * '<S364>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus'
 * '<S365>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus/vec_norm'
 * '<S366>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus'
 * '<S367>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus/vec_norm'
 * '<S368>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation/DCMz'
 * '<S369>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation/safe_devide'
 * '<S370>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation/vec_normalize'
 * '<S371>' : 'INS/Sensor_Process/MAG_Process/Check_Valid/Compare To Constant4'
 * '<S372>' : 'INS/Sensor_Process/MAG_Process/Check_Valid/Detect Change'
 * '<S373>' : 'INS/Sensor_Process/MAG_Process/Check_Valid/Interval Test1'
 * '<S374>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect'
 * '<S375>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Compare To Constant4'
 * '<S376>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Detect Change'
 * '<S377>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check'
 * '<S378>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Compare To Constant4'
 * '<S379>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Detect Change'
 * '<S380>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
