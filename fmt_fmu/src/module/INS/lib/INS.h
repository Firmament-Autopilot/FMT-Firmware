/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.3247
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan  2 09:35:42 2021
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
  real_T DataTypeConversion;           /* '<S334>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S334>/Data Type Conversion1' */
  real_T OutportBufferFordz_dh;        /* '<S334>/WGS84_Derivative' */
  real_T Add;                          /* '<S347>/Add' */
  real_T Product4;                     /* '<S347>/Product4' */
  real32_T Divide;                     /* '<S319>/Divide' */
  real32_T h_0;                        /* '<S237>/Merge' */
  real32_T vel_D_0;                    /* '<S237>/Merge1' */
  real32_T vel_NE_0[2];                /* '<S193>/Merge1' */
  real32_T Sum1[3];                    /* '<S225>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S216>/Sum1' */
  real32_T Sum1_pu[3];                 /* '<S202>/Sum1' */
  real32_T Saturation;                 /* '<S202>/Saturation' */
  real32_T DataTypeConversion_n[2];    /* '<S194>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S179>/Sum1' */
  real32_T Merge[4];                   /* '<S114>/Merge' */
  real32_T OutportBufferForquat_0[4];  /* '<S111>/DCM_to_quat' */
  real32_T DiscreteTimeIntegrator[3];  /* '<S94>/Discrete-Time Integrator' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S266>/Delay1' */
  real_T Delay_DSTATE[2];              /* '<S267>/Delay' */
  real_T Delay1_DSTATE_o[2];           /* '<S267>/Delay1' */
  real32_T Delay_6_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_9_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_DSTATE_d;             /* '<S319>/Delay' */
  real32_T Delay_9_DSTATE_m;           /* '<S57>/Delay' */
  real32_T Delay_10_DSTATE;            /* '<S57>/Delay' */
  real32_T Delay_11_DSTATE;            /* '<S57>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S287>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S275>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S286>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S274>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_b[3];          /* '<S235>/Delay' */
  real32_T Delay_DSTATE_l[6];          /* '<S189>/Delay' */
  real32_T Delay_DSTATE_p[3];          /* '<S227>/Delay' */
  real32_T x_delay_DSTATE[5];          /* '<S229>/x_delay' */
  real32_T Delay_DSTATE_k;             /* '<S232>/Delay' */
  real32_T h_delay_DSTATE[75];         /* '<S220>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S220>/vd_delay' */
  real32_T Delay_DSTATE_dr[3];         /* '<S206>/Delay' */
  real32_T x_delay_DSTATE_b[5];        /* '<S208>/x_delay' */
  real32_T Delay_DSTATE_h;             /* '<S213>/Delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S183>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S183>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S183>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S183>/vn_delay1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S166>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S164>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S165>/Discrete-Time Integrator5' */
  real32_T Delay_8_DSTATE[9];          /* '<S58>/Delay' */
  real32_T Delay_9_DSTATE_d[9];        /* '<S58>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S100>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S101>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S90>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S88>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S90>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_gx[3];/* '<S96>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_k[3];/* '<S96>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_d[3];/* '<S94>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_p[3];/* '<S94>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_bo;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_hi;/* '<S16>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_b3;/* '<S18>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_kg;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S17>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S343>/Unit Delay' */
  uint32_T DelayInput1_DSTATE;         /* '<S389>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTA_bor;/* '<S387>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S386>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nz;/* '<S384>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S382>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S367>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S357>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S355>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S363>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S361>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S346>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_il;/* '<S337>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S322>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_cj;      /* '<S327>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nm;/* '<S318>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_f;             /* '<S320>/Delay' */
  uint32_T Delay1_DSTATE_i;            /* '<S319>/Delay1' */
  uint32_T DelayInput1_DSTATE_nb;      /* '<S226>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S217>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S205>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S180>/Delay Input1' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S222>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S218>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S186>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S181>/Memory' */
  uint16_T Delay_DSTATE_i;             /* '<S155>/Delay' */
  uint8_T Delay_DSTATE_k3;             /* '<S387>/Delay' */
  uint8_T Delay_DSTATE_hp;             /* '<S63>/Delay' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S260>/Delay Input1' */
  boolean_T Delay_DSTATE_k4;           /* '<S287>/Delay' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S262>/Delay Input1' */
  boolean_T Delay_DSTATE_kh;           /* '<S275>/Delay' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S268>/Delay Input1' */
  boolean_T Delay_DSTATE_c;            /* '<S286>/Delay' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S270>/Delay Input1' */
  boolean_T Delay_DSTATE_n;            /* '<S274>/Delay' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S279>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_hg;     /* '<S284>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ch;     /* '<S291>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S296>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_db;     /* '<S234>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S224>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S215>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S188>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_pr;     /* '<S158>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S91>/Delay Input1' */
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
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S287>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S275>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S286>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S274>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_bk;/* '<S100>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S94>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S94>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S16>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_dj;/* '<S18>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ar;/* '<S17>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S229>/x_delay' */
  uint8_T icLoad_o;                    /* '<S220>/h_delay' */
  uint8_T icLoad_f;                    /* '<S220>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S208>/x_delay' */
  uint8_T icLoad_op;                   /* '<S183>/x_delay' */
  uint8_T icLoad_i;                    /* '<S183>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S183>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S183>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S100>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S90>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_c;/* '<S96>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_l;/* '<S94>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S247>/Relay' */
  boolean_T Relay1_Mode;               /* '<S247>/Relay1' */
  boolean_T Relay_Mode_b;              /* '<S248>/Relay' */
  boolean_T Relay1_Mode_o;             /* '<S248>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S113>/Relay2' */
  boolean_T Relay_Mode_n;              /* '<S93>/Relay' */
  boolean_T Relay1_Mode_l;             /* '<S72>/Relay1' */
  boolean_T Relay1_Mode_j;             /* '<S10>/Relay1' */
  boolean_T Reference_Height_MODE;     /* '<S316>/Reference_Height' */
  boolean_T Rangefinder_Correct_MODE;  /* '<S201>/Rangefinder_Correct' */
  boolean_T GPS_Correct_MODE;          /* '<S200>/GPS_Correct' */
  boolean_T Baro_Correct_MODE;         /* '<S199>/Baro_Correct' */
  boolean_T GPS_Correct_MODE_o;        /* '<S177>/GPS_Correct' */
  boolean_T GPS_Acc_MODE;              /* '<S89>/GPS_Acc' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S309>/WGS84_Model' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S229>/x_delay' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S220>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S220>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE_l;      /* '<S208>/x_delay' */
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
                                          *   '<S236>/Constant1'
                                          */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T WMM_Lookup_Table_resolution;  /* Mask Parameter: WMM_Lookup_Table_resolution
                                        * Referenced by: '<S370>/rad_to_index'
                                        */
  real_T Zero_Value_Exclusion_thr;     /* Mask Parameter: Zero_Value_Exclusion_thr
                                        * Referenced by: '<S176>/Saturation'
                                        */
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S344>/Constant'
                                        */
  real32_T Valid_Check_acc_max;        /* Mask Parameter: Valid_Check_acc_max
                                        * Referenced by: '<S358>/Upper Limit'
                                        */
  real32_T Valid_Check_acc_max_k;      /* Mask Parameter: Valid_Check_acc_max_k
                                        * Referenced by: '<S364>/Upper Limit'
                                        */
  real32_T Valid_Check_acc_min;        /* Mask Parameter: Valid_Check_acc_min
                                        * Referenced by: '<S358>/Lower Limit'
                                        */
  real32_T Valid_Check_acc_min_k;      /* Mask Parameter: Valid_Check_acc_min_k
                                        * Referenced by: '<S364>/Lower Limit'
                                        */
  real32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S97>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S153>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S152>/Constant'
                                        */
  real32_T Valid_Check_gyr_max;        /* Mask Parameter: Valid_Check_gyr_max
                                        * Referenced by: '<S359>/Upper Limit'
                                        */
  real32_T Valid_Check_gyr_max_e;      /* Mask Parameter: Valid_Check_gyr_max_e
                                        * Referenced by: '<S365>/Upper Limit'
                                        */
  real32_T Valid_Check_gyr_min;        /* Mask Parameter: Valid_Check_gyr_min
                                        * Referenced by: '<S359>/Lower Limit'
                                        */
  real32_T Valid_Check_gyr_min_f;      /* Mask Parameter: Valid_Check_gyr_min_f
                                        * Referenced by: '<S365>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S154>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit_m;    /* Mask Parameter: IntervalTest_lowlimit_m
                                        * Referenced by: '<S390>/Lower Limit'
                                        */
  real32_T Valid_Check_mag_max;        /* Mask Parameter: Valid_Check_mag_max
                                        * Referenced by: '<S383>/Upper Limit'
                                        */
  real32_T Valid_Check_mag_min;        /* Mask Parameter: Valid_Check_mag_min
                                        * Referenced by: '<S383>/Lower Limit'
                                        */
  real32_T valid_check_max_pressure;   /* Mask Parameter: valid_check_max_pressure
                                        * Referenced by: '<S328>/Upper Limit'
                                        */
  real32_T valid_check_max_temp;       /* Mask Parameter: valid_check_max_temp
                                        * Referenced by: '<S329>/Upper Limit'
                                        */
  real32_T valid_check_min_pressure;   /* Mask Parameter: valid_check_min_pressure
                                        * Referenced by: '<S328>/Lower Limit'
                                        */
  real32_T valid_check_min_temp;       /* Mask Parameter: valid_check_min_temp
                                        * Referenced by: '<S329>/Lower Limit'
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
                                        * Referenced by: '<S293>/Constant'
                                        */
  real32_T valid_hold1_time_out_o;     /* Mask Parameter: valid_hold1_time_out_o
                                        * Referenced by: '<S281>/Constant'
                                        */
  real32_T valid_hold_time_out;        /* Mask Parameter: valid_hold_time_out
                                        * Referenced by: '<S288>/Constant'
                                        */
  real32_T valid_hold_time_out_f;      /* Mask Parameter: valid_hold_time_out_f
                                        * Referenced by: '<S276>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S154>/Upper Limit'
                                        */
  real32_T IntervalTest_uplimit_d;     /* Mask Parameter: IntervalTest_uplimit_d
                                        * Referenced by: '<S390>/Upper Limit'
                                        */
  uint32_T CompareToConstant_const_nb; /* Mask Parameter: CompareToConstant_const_nb
                                        * Referenced by: '<S321>/Constant'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S345>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S341>/Constant'
                                        */
  uint32_T CompareToConstant4_const_k; /* Mask Parameter: CompareToConstant4_const_k
                                        * Referenced by: '<S385>/Constant'
                                        */
  uint32_T CompareToConstant4_const_o; /* Mask Parameter: CompareToConstant4_const_o
                                        * Referenced by: '<S388>/Constant'
                                        */
  uint32_T IntervalTest3_lowlimit;     /* Mask Parameter: IntervalTest3_lowlimit
                                        * Referenced by: '<S323>/Lower Limit'
                                        */
  uint32_T valid_check_timeout;        /* Mask Parameter: valid_check_timeout
                                        * Referenced by: '<S326>/Constant'
                                        */
  uint32_T Valid_Check_timeout;        /* Mask Parameter: Valid_Check_timeout
                                        * Referenced by: '<S356>/Constant'
                                        */
  uint32_T Valid_Check_timeout_e;      /* Mask Parameter: Valid_Check_timeout_e
                                        * Referenced by: '<S362>/Constant'
                                        */
  uint32_T Valid_Check_timeout_b;      /* Mask Parameter: Valid_Check_timeout_b
                                        * Referenced by: '<S381>/Constant'
                                        */
  uint32_T IntervalTest3_uplimit;      /* Mask Parameter: IntervalTest3_uplimit
                                        * Referenced by: '<S323>/Upper Limit'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S180>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S205>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S217>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_k;       /* Mask Parameter: DetectChange_vinit_k
                                        * Referenced by: '<S226>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S322>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_n;       /* Mask Parameter: DetectChange_vinit_n
                                        * Referenced by: '<S327>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S346>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S357>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d0;      /* Mask Parameter: DetectChange_vinit_d0
                                        * Referenced by: '<S363>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S382>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S386>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_p;       /* Mask Parameter: DetectChange_vinit_p
                                        * Referenced by: '<S389>/Delay Input1'
                                        */
  int16_T WMM_Lookup_Table_wmm_declinatio[629];/* Mask Parameter: WMM_Lookup_Table_wmm_declinatio
                                                * Referenced by: '<S370>/Declination_Lookup_Table'
                                                */
  uint16_T valid_samples_const;        /* Mask Parameter: valid_samples_const
                                        * Referenced by: '<S159>/Constant'
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
                                        * Referenced by: '<S294>/Constant'
                                        */
  boolean_T CompareToConstant1_const_i;/* Mask Parameter: CompareToConstant1_const_i
                                        * Referenced by: '<S282>/Constant'
                                        */
  boolean_T CompareToConstant1_const_h;/* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S289>/Constant'
                                        */
  boolean_T CompareToConstant1_const_hh;/* Mask Parameter: CompareToConstant1_const_hh
                                         * Referenced by: '<S277>/Constant'
                                         */
  boolean_T CompareToConstant2_const_a;/* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S278>/Constant'
                                        */
  boolean_T CompareToConstant2_const_j;/* Mask Parameter: CompareToConstant2_const_j
                                        * Referenced by: '<S283>/Constant'
                                        */
  boolean_T CompareToConstant2_const_d;/* Mask Parameter: CompareToConstant2_const_d
                                        * Referenced by: '<S290>/Constant'
                                        */
  boolean_T CompareToConstant2_const_d2;/* Mask Parameter: CompareToConstant2_const_d2
                                         * Referenced by: '<S295>/Constant'
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
                                        * Referenced by: '<S91>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_fc;/* Mask Parameter: DetectRisePositive_vinit_fc
                                         * Referenced by: '<S158>/Delay Input1'
                                         */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S188>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S215>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S224>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_f;    /* Mask Parameter: DetectIncrease_vinit_f
                                        * Referenced by: '<S234>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S260>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_me;/* Mask Parameter: DetectRisePositive_vinit_me
                                         * Referenced by: '<S262>/Delay Input1'
                                         */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S268>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S270>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_d;/* Mask Parameter: DetectRisePositive_vinit_d
                                        * Referenced by: '<S279>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_o;/* Mask Parameter: DetectRisePositive_vinit_o
                                        * Referenced by: '<S284>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_dn;/* Mask Parameter: DetectRisePositive_vinit_dn
                                         * Referenced by: '<S291>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_ho;/* Mask Parameter: DetectRisePositive_vinit_ho
                                         * Referenced by: '<S296>/Delay Input1'
                                         */
  int8_T WMM_Lookup_Table_wmm_inclinatio[629];/* Mask Parameter: WMM_Lookup_Table_wmm_inclinatio
                                               * Referenced by: '<S370>/Inclination_Lookup_Table'
                                               */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S342>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S330>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S331>/Constant'
                                        */
  uint8_T CompareToConstant2_const_bv; /* Mask Parameter: CompareToConstant2_const_bv
                                        * Referenced by: '<S335>/Constant'
                                        */
  uint8_T WMM_Lookup_Table_wmm_magnitude[629];/* Mask Parameter: WMM_Lookup_Table_wmm_magnitude
                                               * Referenced by: '<S370>/Magnitude_Lookup_Table'
                                               */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S176>/Constant'
                                        */
  real_T Constant_Value_i[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S174>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S176>/Saturation'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S266>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S267>/Delay'
                                        */
  real_T Delay1_InitialCondition_e;    /* Expression: 0.0
                                        * Referenced by: '<S267>/Delay1'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S334>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S334>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S334>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S334>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S334>/dz_dh'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S347>/constant1'
                                        */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S347>/constant2'
                                        */
  real_T b_Value;                      /* Expression: 1/298.257
                                        * Referenced by: '<S347>/b'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S347>/constant'
                                        */
  real_T earth_radius_Value;           /* Expression: 6378137
                                        * Referenced by: '<S347>/earth_radius'
                                        */
  real_T c_Value;                      /* Expression: 1
                                        * Referenced by: '<S347>/c'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S343>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S343>/Saturation'
                                        */
  int32_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S343>/Saturation'
                                        */
  int32_T lat_offset_Value[2];         /* Computed Parameter: lat_offset_Value
                                        * Referenced by: '<S370>/lat_offset'
                                        */
  int32_T Saturation1_UpperSat[2];     /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S370>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S370>/Saturation1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S332>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S332>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S332>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S332>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain;           /* Computed Parameter: Scalefactor1_Gain
                                        * Referenced by: '<S332>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S332>/Scalefactor2'
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
  real32_T GPS_acc_O_mPs2_Y0;          /* Computed Parameter: GPS_acc_O_mPs2_Y0
                                        * Referenced by: '<S92>/GPS_acc_O_mPs2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                            * Referenced by: '<S94>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S94>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S94>/Discrete-Time Integrator1'
                                            */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S94>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S94>/Gain3'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                            * Referenced by: '<S90>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S93>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S93>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S93>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S93>/Relay'
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
  real32_T Saturation_LowerSat_f;      /* Computed Parameter: Saturation_LowerSat_f
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
  real32_T Gain2_Gain_oj;              /* Computed Parameter: Gain2_Gain_oj
                                        * Referenced by: '<S102>/Gain2'
                                        */
  real32_T Gain3_Gain_d;               /* Computed Parameter: Gain3_Gain_d
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
  real32_T Gain3_Gain_da;              /* Computed Parameter: Gain3_Gain_da
                                        * Referenced by: '<S123>/Gain3'
                                        */
  real32_T quat_0_Y0[4];               /* Computed Parameter: quat_0_Y0
                                        * Referenced by: '<S111>/quat_0'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S111>/Gain'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S117>/Constant2'
                                        */
  real32_T Constant2_Value_m;          /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S118>/Constant2'
                                        */
  real32_T Constant2_Value_gc;         /* Computed Parameter: Constant2_Value_gc
                                        * Referenced by: '<S119>/Constant2'
                                        */
  real32_T Merge_InitialOutput[4];     /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S114>/Merge'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<S166>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC; /* Computed Parameter: DiscreteTimeIntegrator5_IC
                                        * Referenced by: '<S166>/Discrete-Time Integrator5'
                                        */
  real32_T Gain2_Gain_h;               /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S166>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_o;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_o
                                            * Referenced by: '<S164>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_m;/* Computed Parameter: DiscreteTimeIntegrator5_IC_m
                                         * Referenced by: '<S164>/Discrete-Time Integrator5'
                                         */
  real32_T Gain2_Gain_c;               /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S164>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_b;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_b
                                            * Referenced by: '<S165>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_a;/* Computed Parameter: DiscreteTimeIntegrator5_IC_a
                                         * Referenced by: '<S165>/Discrete-Time Integrator5'
                                         */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S113>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S113>/Saturation2'
                                        */
  real32_T Gain2_Gain_f;               /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S165>/Gain2'
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
  real32_T Constant_Value_aq;          /* Computed Parameter: Constant_Value_aq
                                        * Referenced by: '<S167>/Constant'
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
                                        * Referenced by: '<S211>/Saturation'
                                        */
  real32_T Saturation_LowerSat_c;      /* Computed Parameter: Saturation_LowerSat_c
                                        * Referenced by: '<S211>/Saturation'
                                        */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S211>/Gain2'
                                        */
  real32_T Gain1_Gain_o;               /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S211>/Gain1'
                                        */
  real32_T Gain_Gain_by;               /* Computed Parameter: Gain_Gain_by
                                        * Referenced by: '<S211>/Gain'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S202>/X_Next'
                                        */
  real32_T Delay_InitialCondition_j;   /* Computed Parameter: Delay_InitialCondition_j
                                        * Referenced by: '<S206>/Delay'
                                        */
  real32_T Delay_InitialCondition_mk;  /* Computed Parameter: Delay_InitialCondition_mk
                                        * Referenced by: '<S213>/Delay'
                                        */
  real32_T Gain_Gain_p;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S206>/Gain'
                                        */
  real32_T Saturation_UpperSat_as;     /* Computed Parameter: Saturation_UpperSat_as
                                        * Referenced by: '<S202>/Saturation'
                                        */
  real32_T Saturation_LowerSat_e;      /* Computed Parameter: Saturation_LowerSat_e
                                        * Referenced by: '<S202>/Saturation'
                                        */
  real32_T Gain1_Gain_ml;              /* Computed Parameter: Gain1_Gain_ml
                                        * Referenced by: '<S221>/Gain1'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S221>/Gain'
                                        */
  real32_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S221>/Gain2'
                                        */
  real32_T X_Next_Y0_i;                /* Computed Parameter: X_Next_Y0_i
                                        * Referenced by: '<S216>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S222>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S218>/Memory'
                                        */
  real32_T Gain3_Gain_k;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S218>/Gain3'
                                        */
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S230>/Gain1'
                                        */
  real32_T Gain_Gain_lp;               /* Computed Parameter: Gain_Gain_lp
                                        * Referenced by: '<S230>/Gain'
                                        */
  real32_T X_Next_Y0_h;                /* Computed Parameter: X_Next_Y0_h
                                        * Referenced by: '<S225>/X_Next'
                                        */
  real32_T Delay_InitialCondition_k;   /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S227>/Delay'
                                        */
  real32_T Delay_InitialCondition_l;   /* Computed Parameter: Delay_InitialCondition_l
                                        * Referenced by: '<S232>/Delay'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S230>/Gain2'
                                        */
  real32_T Gain_Gain_bd;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S227>/Gain'
                                        */
  real32_T Constant_Value_eq;          /* Computed Parameter: Constant_Value_eq
                                        * Referenced by: '<S237>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S241>/Constant'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S243>/Constant'
                                        */
  real32_T Merge_InitialOutput_j;      /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S237>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S237>/Merge1'
                                        */
  real32_T Delay_InitialCondition_mt;  /* Computed Parameter: Delay_InitialCondition_mt
                                        * Referenced by: '<S235>/Delay'
                                        */
  real32_T Gain1_Gain_kw;              /* Computed Parameter: Gain1_Gain_kw
                                        * Referenced by: '<S236>/Gain1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S236>/Constant'
                                        */
  real32_T Gain_Gain_mr;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S236>/Gain'
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
                                        * Referenced by: '<S247>/Relay'
                                        */
  real32_T Relay_OffVal_i;             /* Computed Parameter: Relay_OffVal_i
                                        * Referenced by: '<S247>/Relay'
                                        */
  real32_T Relay_YOn_c;                /* Computed Parameter: Relay_YOn_c
                                        * Referenced by: '<S247>/Relay'
                                        */
  real32_T Relay_YOff_j;               /* Computed Parameter: Relay_YOff_j
                                        * Referenced by: '<S247>/Relay'
                                        */
  real32_T Relay1_OnVal_j;             /* Computed Parameter: Relay1_OnVal_j
                                        * Referenced by: '<S247>/Relay1'
                                        */
  real32_T Relay1_OffVal_a;            /* Computed Parameter: Relay1_OffVal_a
                                        * Referenced by: '<S247>/Relay1'
                                        */
  real32_T Relay1_YOn_o;               /* Computed Parameter: Relay1_YOn_o
                                        * Referenced by: '<S247>/Relay1'
                                        */
  real32_T Relay1_YOff_k;              /* Computed Parameter: Relay1_YOff_k
                                        * Referenced by: '<S247>/Relay1'
                                        */
  real32_T Relay_OnVal_a;              /* Computed Parameter: Relay_OnVal_a
                                        * Referenced by: '<S248>/Relay'
                                        */
  real32_T Relay_OffVal_h;             /* Computed Parameter: Relay_OffVal_h
                                        * Referenced by: '<S248>/Relay'
                                        */
  real32_T Relay_YOn_i;                /* Computed Parameter: Relay_YOn_i
                                        * Referenced by: '<S248>/Relay'
                                        */
  real32_T Relay_YOff_g;               /* Computed Parameter: Relay_YOff_g
                                        * Referenced by: '<S248>/Relay'
                                        */
  real32_T Relay1_OnVal_m;             /* Computed Parameter: Relay1_OnVal_m
                                        * Referenced by: '<S248>/Relay1'
                                        */
  real32_T Relay1_OffVal_o5;           /* Computed Parameter: Relay1_OffVal_o5
                                        * Referenced by: '<S248>/Relay1'
                                        */
  real32_T Relay1_YOn_e;               /* Computed Parameter: Relay1_YOn_e
                                        * Referenced by: '<S248>/Relay1'
                                        */
  real32_T Relay1_YOff_m;              /* Computed Parameter: Relay1_YOff_m
                                        * Referenced by: '<S248>/Relay1'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_jo;/* Computed Parameter: DiscreteTimeIntegrator_gainv_jo
                                            * Referenced by: '<S287>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_lb;/* Computed Parameter: DiscreteTimeIntegrator_IC_lb
                                         * Referenced by: '<S287>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_j;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_j
                                            * Referenced by: '<S287>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_Lower_f2;/* Computed Parameter: DiscreteTimeIntegrator_Lower_f2
                                            * Referenced by: '<S287>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                            * Referenced by: '<S275>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_gv;/* Computed Parameter: DiscreteTimeIntegrator_IC_gv
                                         * Referenced by: '<S275>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_UpperS_p;/* Computed Parameter: DiscreteTimeIntegrator_UpperS_p
                                            * Referenced by: '<S275>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_p;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_p
                                            * Referenced by: '<S275>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                            * Referenced by: '<S286>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_h;/* Computed Parameter: DiscreteTimeIntegrator_IC_h
                                        * Referenced by: '<S286>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_fv;/* Computed Parameter: DiscreteTimeIntegrator_Upper_fv
                                            * Referenced by: '<S286>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_b;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_b
                                            * Referenced by: '<S286>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_gainv_iy;/* Computed Parameter: DiscreteTimeIntegrator_gainv_iy
                                            * Referenced by: '<S274>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S274>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_Upper_jm;/* Computed Parameter: DiscreteTimeIntegrator_Upper_jm
                                            * Referenced by: '<S274>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_LowerS_d;/* Computed Parameter: DiscreteTimeIntegrator_LowerS_d
                                            * Referenced by: '<S274>/Discrete-Time Integrator'
                                            */
  real32_T Delay_9_InitialCondition_h; /* Computed Parameter: Delay_9_InitialCondition_h
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_10_InitialCondition;  /* Computed Parameter: Delay_10_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T Delay_11_InitialCondition;  /* Computed Parameter: Delay_11_InitialCondition
                                        * Referenced by: '<S57>/Delay'
                                        */
  real32_T h_R_m_Y0;                   /* Computed Parameter: h_R_m_Y0
                                        * Referenced by: '<S319>/h_R_m'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S319>/Delay'
                                        */
  real32_T Gain1_Gain_a;               /* Computed Parameter: Gain1_Gain_a
                                        * Referenced by: '<S314>/Gain1'
                                        */
  real32_T p1_Value;                   /* Computed Parameter: p1_Value
                                        * Referenced by: '<S314>/p1'
                                        */
  real32_T aR_g_Value;                 /* Computed Parameter: aR_g_Value
                                        * Referenced by: '<S314>/aR_g'
                                        */
  real32_T T1_Value;                   /* Computed Parameter: T1_Value
                                        * Referenced by: '<S314>/T1'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S314>/a'
                                        */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S339>/Constant7'
                                        */
  real32_T Gain3_Gain_lx;              /* Computed Parameter: Gain3_Gain_lx
                                        * Referenced by: '<S339>/Gain3'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S339>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S339>/Saturation'
                                        */
  real32_T Constant1_Value_g;          /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S338>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S338>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S338>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S338>/Saturation1'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S368>/default_mag_quality'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S373>/Nominal_Magnitude'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S373>/gain'
                                        */
  real32_T Constant1_Value_cq;         /* Computed Parameter: Constant1_Value_cq
                                        * Referenced by: '<S373>/Constant1'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S373>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S373>/Saturation'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S372>/gain'
                                        */
  real32_T Constant2_Value_hh;         /* Computed Parameter: Constant2_Value_hh
                                        * Referenced by: '<S372>/Constant2'
                                        */
  real32_T Saturation_UpperSat_gg;     /* Computed Parameter: Saturation_UpperSat_gg
                                        * Referenced by: '<S372>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S372>/Saturation'
                                        */
  real32_T Constant_Value_g2;          /* Computed Parameter: Constant_Value_g2
                                        * Referenced by: '<S380>/Constant'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S378>/Constant3'
                                        */
  real32_T Gain_Gain_fl;               /* Computed Parameter: Gain_Gain_fl
                                        * Referenced by: '<S378>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S378>/Constant4'
                                        */
  real32_T Constant2_Value_l;          /* Computed Parameter: Constant2_Value_l
                                        * Referenced by: '<S378>/Constant2'
                                        */
  real32_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S378>/Constant1'
                                        */
  real32_T Constant_Value_pf;          /* Computed Parameter: Constant_Value_pf
                                        * Referenced by: '<S378>/Constant'
                                        */
  real32_T Constant1_Value_be;         /* Computed Parameter: Constant1_Value_be
                                        * Referenced by: '<S379>/Constant1'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S311>/Gauss_to_uT'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S380>/Switch'
                                        */
  real32_T Constant_Value_bg;          /* Computed Parameter: Constant_Value_bg
                                        * Referenced by: '<S312>/Constant'
                                        */
  real32_T Constant_Value_jp;          /* Computed Parameter: Constant_Value_jp
                                        * Referenced by: '<S384>/Constant'
                                        */
  real32_T Delay_6_InitialCondition;   /* Computed Parameter: Delay_6_InitialCondition
                                        * Referenced by: '<Root>/Delay'
                                        */
  real32_T Delay_9_InitialCondition_m; /* Computed Parameter: Delay_9_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Gain5_Gain_a;               /* Computed Parameter: Gain5_Gain_a
                                        * Referenced by: '<S339>/Gain5'
                                        */
  uint32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S338>/Gain1'
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
                                        * Referenced by: '<S155>/Delay'
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
                                        * Referenced by: '<S206>/Delay'
                                        */
  uint32_T x_delay_DelayLength_m;      /* Expression: 10/INS_EXPORT_VALUE.period
                                        * Referenced by: '<S208>/x_delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S213>/Delay'
                                        */
  uint32_T h_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S220>/h_delay'
                                        */
  uint32_T vd_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S220>/vd_delay'
                                        */
  uint32_T Delay_DelayLength_op;       /* Computed Parameter: Delay_DelayLength_op
                                        * Referenced by: '<S227>/Delay'
                                        */
  uint32_T x_delay_DelayLength_l;      /* Expression: 10/INS_EXPORT_VALUE.period
                                        * Referenced by: '<S229>/x_delay'
                                        */
  uint32_T Delay_DelayLength_kz;       /* Computed Parameter: Delay_DelayLength_kz
                                        * Referenced by: '<S232>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S235>/Delay'
                                        */
  uint32_T Delay_DelayLength_ly;       /* Computed Parameter: Delay_DelayLength_ly
                                        * Referenced by: '<S189>/Delay'
                                        */
  uint32_T Delay_DelayLength_g;        /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S287>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S275>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S266>/Delay1'
                                        */
  uint32_T Delay_DelayLength_d0;       /* Computed Parameter: Delay_DelayLength_d0
                                        * Referenced by: '<S286>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S267>/Delay'
                                        */
  uint32_T Delay1_DelayLength_o;       /* Computed Parameter: Delay1_DelayLength_o
                                        * Referenced by: '<S267>/Delay1'
                                        */
  uint32_T Delay_DelayLength_cp;       /* Computed Parameter: Delay_DelayLength_cp
                                        * Referenced by: '<S274>/Delay'
                                        */
  uint32_T Delay_9_DelayLength_i;      /* Computed Parameter: Delay_9_DelayLength_i
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_10_DelayLength;       /* Computed Parameter: Delay_10_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_11_DelayLength;       /* Computed Parameter: Delay_11_DelayLength
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S319>/Constant1'
                                        */
  uint32_T Delay_DelayLength_jx;       /* Computed Parameter: Delay_DelayLength_jx
                                        * Referenced by: '<S319>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S319>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition_k;  /* Computed Parameter: Delay1_InitialCondition_k
                                        * Referenced by: '<S319>/Delay1'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S319>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S319>/Saturation1'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_iu;/* Computed Parameter: DiscreteTimeIntegrator_IC_iu
                                         * Referenced by: '<S318>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_dn;       /* Computed Parameter: Delay_DelayLength_dn
                                        * Referenced by: '<S320>/Delay'
                                        */
  uint32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S320>/Delay'
                                        */
  uint32_T Saturation_UpperSat_f;      /* Computed Parameter: Saturation_UpperSat_f
                                        * Referenced by: '<S320>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_pw;     /* Computed Parameter: Saturation_LowerSat_pw
                                        * Referenced by: '<S320>/Saturation'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S337>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_ba;/* Computed Parameter: DiscreteTimeIntegrator_IC_ba
                                         * Referenced by: '<S355>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S361>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_kz;/* Computed Parameter: DiscreteTimeIntegrator_IC_kz
                                         * Referenced by: '<S367>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_gf;/* Computed Parameter: DiscreteTimeIntegrator_IC_gf
                                         * Referenced by: '<S384>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_ov;/* Computed Parameter: DiscreteTimeIntegrator_IC_ov
                                         * Referenced by: '<S387>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S387>/Delay'
                                        */
  uint32_T Delay_6_DelayLength;        /* Computed Parameter: Delay_6_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay_9_DelayLength_g;      /* Computed Parameter: Delay_9_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  int16_T Gain_Gain_fs;                /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S369>/Gain'
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
                                        * Referenced by: '<S155>/Delay'
                                        */
  uint16_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S155>/Saturation'
                                        */
  uint16_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S155>/Saturation'
                                        */
  uint16_T Constant_Value_bt;          /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S261>/Constant'
                                        */
  uint16_T Constant_Value_gn;          /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S263>/Constant'
                                        */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S269>/Constant'
                                        */
  uint16_T Constant_Value_pt;          /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S271>/Constant'
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
  boolean_T Constant_Value_af;         /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S160>/Constant'
                                        */
  boolean_T Constant_Value_ej;         /* Computed Parameter: Constant_Value_ej
                                        * Referenced by: '<S249>/Constant'
                                        */
  boolean_T Constant_Value_ez;         /* Computed Parameter: Constant_Value_ez
                                        * Referenced by: '<S250>/Constant'
                                        */
  boolean_T Constant_Value_pfd;        /* Computed Parameter: Constant_Value_pfd
                                        * Referenced by: '<S251>/Constant'
                                        */
  boolean_T Delay_InitialCondition_ns; /* Computed Parameter: Delay_InitialCondition_ns
                                        * Referenced by: '<S287>/Delay'
                                        */
  boolean_T Delay_InitialCondition_i;  /* Computed Parameter: Delay_InitialCondition_i
                                        * Referenced by: '<S275>/Delay'
                                        */
  boolean_T Delay_InitialCondition_d;  /* Computed Parameter: Delay_InitialCondition_d
                                        * Referenced by: '<S286>/Delay'
                                        */
  boolean_T Delay_InitialCondition_kd; /* Computed Parameter: Delay_InitialCondition_kd
                                        * Referenced by: '<S274>/Delay'
                                        */
  boolean_T Constant_Value_nm;         /* Computed Parameter: Constant_Value_nm
                                        * Referenced by: '<S280>/Constant'
                                        */
  boolean_T Constant_Value_dc;         /* Computed Parameter: Constant_Value_dc
                                        * Referenced by: '<S285>/Constant'
                                        */
  boolean_T Constant_Value_ej0;        /* Computed Parameter: Constant_Value_ej0
                                        * Referenced by: '<S292>/Constant'
                                        */
  boolean_T Constant_Value_jo;         /* Computed Parameter: Constant_Value_jo
                                        * Referenced by: '<S297>/Constant'
                                        */
  int8_T Saturation_UpperSat_gx;       /* Computed Parameter: Saturation_UpperSat_gx
                                        * Referenced by: '<S248>/Saturation'
                                        */
  int8_T Saturation_LowerSat_co;       /* Computed Parameter: Saturation_LowerSat_co
                                        * Referenced by: '<S248>/Saturation'
                                        */
  int8_T Constant_Value_lc;            /* Computed Parameter: Constant_Value_lc
                                        * Referenced by: '<S252>/Constant'
                                        */
  int8_T Constant_Value_h5;            /* Computed Parameter: Constant_Value_h5
                                        * Referenced by: '<S253>/Constant'
                                        */
  int8_T Saturation1_UpperSat_i;       /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S248>/Saturation1'
                                        */
  int8_T Saturation1_LowerSat_g;       /* Computed Parameter: Saturation1_LowerSat_g
                                        * Referenced by: '<S248>/Saturation1'
                                        */
  int8_T Constant_Value_kt;            /* Computed Parameter: Constant_Value_kt
                                        * Referenced by: '<S254>/Constant'
                                        */
  int8_T Gain1_Gain_od;                /* Computed Parameter: Gain1_Gain_od
                                        * Referenced by: '<S372>/Gain1'
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
                                        * Referenced by: '<S353>/Gain'
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
                                        * Referenced by: '<S169>/Constant'
                                        */
  uint8_T Constant_Value_jn;           /* Computed Parameter: Constant_Value_jn
                                        * Referenced by: '<S351>/Constant'
                                        */
  uint8_T Constant2_Value_b;           /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S387>/Constant2'
                                        */
  uint8_T Delay_InitialCondition_f;    /* Computed Parameter: Delay_InitialCondition_f
                                        * Referenced by: '<S387>/Delay'
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
                                                 *   '<S318>/Constant'
                                                 *   '<S367>/Constant'
                                                 *   '<S387>/Constant1'
                                                 *   '<S12>/Constant'
                                                 *   '<S13>/Constant'
                                                 *   '<S14>/Constant'
                                                 *   '<S15>/Constant'
                                                 *   '<S16>/Constant'
                                                 *   '<S17>/Constant'
                                                 *   '<S18>/Constant'
                                                 *   '<S337>/Constant'
                                                 *   '<S355>/Constant'
                                                 *   '<S361>/Constant'
                                                 *   '<S274>/Constant'
                                                 *   '<S275>/Constant'
                                                 *   '<S286>/Constant'
                                                 *   '<S287>/Constant'
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
 * '<S10>'  : 'INS/Bus_Assignment/Status_Output/INS_Valid_Flag'
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
 * '<S65>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/M_CO1'
 * '<S66>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Att_Init_Done/Detect Increase'
 * '<S67>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Euler_Angle/Euler_Angle'
 * '<S68>'  : 'INS/Data_Fusion/AHRS/AHRS/Bus_Assignment/Euler_Angle/Euler_Angle/quat_to_psi'
 * '<S69>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction'
 * '<S70>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction'
 * '<S71>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct'
 * '<S72>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Heading_Correct'
 * '<S73>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct'
 * '<S74>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc'
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
 * '<S88>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Est_Acc'
 * '<S89>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Meas_Acc'
 * '<S90>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Est_Acc/Butter_LPF'
 * '<S91>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Meas_Acc/Detect Increase'
 * '<S92>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Meas_Acc/GPS_Acc'
 * '<S93>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Meas_Acc/Measurement_Sensor'
 * '<S94>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Meas_Acc/GPS_Acc/Derivative'
 * '<S95>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Attitude_Correction/Heading_Correct/Subsystem'
 * '<S96>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/Butter_LPF'
 * '<S97>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/Compare To Constant'
 * '<S98>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/vec_modulus'
 * '<S99>'  : 'INS/Data_Fusion/AHRS/AHRS/Correct/Gyro_Bias_Correction/vec_modulus/vec_norm'
 * '<S100>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update'
 * '<S101>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Gyro_Bias_Update'
 * '<S102>' : 'INS/Data_Fusion/AHRS/AHRS/Update/Attitude_Update/Quat_to_M_OB'
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
 * '<S117>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/safe_norm'
 * '<S118>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/safe_norm1'
 * '<S119>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/safe_norm2'
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
 * '<S149>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/safe_norm/Euclidean_Norm2'
 * '<S150>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/safe_norm1/Euclidean_Norm2'
 * '<S151>' : 'INS/Data_Fusion/AHRS/RF_Data/Init_Attitude/safe_norm2/Euclidean_Norm2'
 * '<S152>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/Compare To Constant'
 * '<S153>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/Compare To Constant1'
 * '<S154>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/Interval Test'
 * '<S155>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition'
 * '<S156>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus'
 * '<S157>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus1'
 * '<S158>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition/Detect Rise Positive'
 * '<S159>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition/valid_samples'
 * '<S160>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/reset_condition/Detect Rise Positive/Positive'
 * '<S161>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus/vec_norm'
 * '<S162>' : 'INS/Data_Fusion/AHRS/RF_Data/Reset_Condition/vec_modulus1/vec_norm'
 * '<S163>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/HPF'
 * '<S164>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/LPF'
 * '<S165>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/LPF1'
 * '<S166>' : 'INS/Data_Fusion/AHRS/RF_Data/Standstill_Condition/HPF/LPF'
 * '<S167>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S168>' : 'INS/Data_Fusion/Translation_Filter/TF_Data'
 * '<S169>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment'
 * '<S170>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S171>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S172>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting'
 * '<S173>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Height_Above_Ground'
 * '<S174>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/WGS_Pos'
 * '<S175>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/WGS_Pos/Compare To Constant'
 * '<S176>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/WGS_Pos/Zero_Value_Exclusion'
 * '<S177>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S178>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S179>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S180>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S181>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Error_Hold'
 * '<S182>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S183>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Observation'
 * '<S184>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Scaling'
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
 * '<S203>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/DT1_Filter'
 * '<S204>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Derivative'
 * '<S205>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S206>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Error_Hold'
 * '<S207>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S208>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Observation'
 * '<S209>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling'
 * '<S210>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling1'
 * '<S211>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling2'
 * '<S212>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling3'
 * '<S213>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation'
 * '<S214>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Bias'
 * '<S215>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S216>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S217>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S218>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Hold'
 * '<S219>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Observation'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Scaling'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Detect Change'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Error_Hold'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Observation'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Scaling'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Scaling1'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Bias'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init/Reference_Height'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Horizontal_Select'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero2'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero1'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero4'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero5'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Select/Sensor_Vertical_Select/Compare To Zero6'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Height_Reset'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Position_Reset'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Height_Reset/Detect Rise Positive'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Height_Reset/Detect Rise Positive/Positive'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Position_Reset/Detect Rise Positive'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Filter_Reset/Position_Reset/Detect Rise Positive/Positive'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Bus_Assignment'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Bus_Select'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Height_Ref'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Position_Ref'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Height_Ref/Detect Rise Positive3'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Height_Ref/Detect Rise Positive3/Positive'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Position_Ref/Detect Rise Positive3'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Reference/Position_Ref/Detect Rise Positive3/Positive'
 * '<S272>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid'
 * '<S273>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid'
 * '<S274>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold'
 * '<S275>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold1'
 * '<S276>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold/Compare To Constant'
 * '<S277>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold/Compare To Constant1'
 * '<S278>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold/Compare To Constant2'
 * '<S279>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold/Detect Rise Positive'
 * '<S280>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S281>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold1/Compare To Constant'
 * '<S282>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold1/Compare To Constant1'
 * '<S283>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold1/Compare To Constant2'
 * '<S284>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold1/Detect Rise Positive'
 * '<S285>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Horizontal_Pos_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S286>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold'
 * '<S287>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold1'
 * '<S288>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold/Compare To Constant'
 * '<S289>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold/Compare To Constant1'
 * '<S290>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold/Compare To Constant2'
 * '<S291>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold/Detect Rise Positive'
 * '<S292>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold/Detect Rise Positive/Positive'
 * '<S293>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold1/Compare To Constant'
 * '<S294>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold1/Compare To Constant1'
 * '<S295>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold1/Compare To Constant2'
 * '<S296>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold1/Detect Rise Positive'
 * '<S297>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Control/Position_Valid/Vertical_Pos_Valid/valid_hold1/Detect Rise Positive/Positive'
 * '<S298>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures'
 * '<S299>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status'
 * '<S300>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/Barometer_Meas'
 * '<S301>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/GPS_Meas'
 * '<S302>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/OpticalFlow_Meas'
 * '<S303>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Measures/Sonar_Meas'
 * '<S304>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/Barometer_Status'
 * '<S305>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/GPS_Status'
 * '<S306>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/OpticalFlow_Status'
 * '<S307>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Sensor/TF_Sensor_Status/Sonar_Status'
 * '<S308>' : 'INS/Sensor_Process/Baro_Process'
 * '<S309>' : 'INS/Sensor_Process/GPS_Process'
 * '<S310>' : 'INS/Sensor_Process/IMU_Process'
 * '<S311>' : 'INS/Sensor_Process/MAG_Process'
 * '<S312>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing'
 * '<S313>' : 'INS/Sensor_Process/Rangefinder_Process'
 * '<S314>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height'
 * '<S315>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height1'
 * '<S316>' : 'INS/Sensor_Process/Baro_Process/Relative_Height'
 * '<S317>' : 'INS/Sensor_Process/Baro_Process/Relative_Height1'
 * '<S318>' : 'INS/Sensor_Process/Baro_Process/valid_check'
 * '<S319>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Reference_Height'
 * '<S320>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling'
 * '<S321>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling/Compare To Constant'
 * '<S322>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling/Detect Change'
 * '<S323>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Sampling/Interval Test3'
 * '<S324>' : 'INS/Sensor_Process/Baro_Process/Relative_Height1/Initialization'
 * '<S325>' : 'INS/Sensor_Process/Baro_Process/Relative_Height1/Reference_and_Derivative'
 * '<S326>' : 'INS/Sensor_Process/Baro_Process/valid_check/Compare To Constant4'
 * '<S327>' : 'INS/Sensor_Process/Baro_Process/valid_check/Detect Change'
 * '<S328>' : 'INS/Sensor_Process/Baro_Process/valid_check/Interval Test1'
 * '<S329>' : 'INS/Sensor_Process/Baro_Process/valid_check/Interval Test2'
 * '<S330>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant'
 * '<S331>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant1'
 * '<S332>' : 'INS/Sensor_Process/GPS_Process/Data_Scalling'
 * '<S333>' : 'INS/Sensor_Process/GPS_Process/Status_Quality'
 * '<S334>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model'
 * '<S335>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/Compare To Constant2'
 * '<S336>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status'
 * '<S337>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/check_timeout'
 * '<S338>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/horizontal_quality'
 * '<S339>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/speed_acc'
 * '<S340>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/vertical_quality'
 * '<S341>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Compare To Constant'
 * '<S342>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Compare To Constant1'
 * '<S343>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Ready'
 * '<S344>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/GPS_Status/Ready/Compare To Constant3'
 * '<S345>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/check_timeout/Compare To Constant4'
 * '<S346>' : 'INS/Sensor_Process/GPS_Process/Status_Quality/check_timeout/Detect Change'
 * '<S347>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model/WGS84_Derivative'
 * '<S348>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment'
 * '<S349>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process'
 * '<S350>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process'
 * '<S351>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/Compare To Zero'
 * '<S352>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select'
 * '<S353>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Status'
 * '<S354>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Data_Select'
 * '<S355>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Valid_Check'
 * '<S356>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Valid_Check/Compare To Constant4'
 * '<S357>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Valid_Check/Detect Change'
 * '<S358>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Valid_Check/Interval Test1'
 * '<S359>' : 'INS/Sensor_Process/IMU_Process/IMU1_Data_Process/Valid_Check/Interval Test3'
 * '<S360>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Data_Select'
 * '<S361>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Valid_Check'
 * '<S362>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Valid_Check/Compare To Constant4'
 * '<S363>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Valid_Check/Detect Change'
 * '<S364>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Valid_Check/Interval Test1'
 * '<S365>' : 'INS/Sensor_Process/IMU_Process/IMU2_Data_Process/Valid_Check/Interval Test3'
 * '<S366>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment'
 * '<S367>' : 'INS/Sensor_Process/MAG_Process/Valid_Check'
 * '<S368>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate'
 * '<S369>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation'
 * '<S370>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Lookup_Table'
 * '<S371>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate'
 * '<S372>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Inclination_Quality_Estimate'
 * '<S373>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Intensity_Quality_Estimate'
 * '<S374>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus'
 * '<S375>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus/vec_norm'
 * '<S376>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus'
 * '<S377>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/Quality_Estimate/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus/vec_norm'
 * '<S378>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation/DCMz'
 * '<S379>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation/safe_devide'
 * '<S380>' : 'INS/Sensor_Process/MAG_Process/Bus_Assignment/WMM_Compensation/vec_normalize'
 * '<S381>' : 'INS/Sensor_Process/MAG_Process/Valid_Check/Compare To Constant4'
 * '<S382>' : 'INS/Sensor_Process/MAG_Process/Valid_Check/Detect Change'
 * '<S383>' : 'INS/Sensor_Process/MAG_Process/Valid_Check/Interval Test1'
 * '<S384>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect'
 * '<S385>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Compare To Constant4'
 * '<S386>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Detect Change'
 * '<S387>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check'
 * '<S388>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Compare To Constant4'
 * '<S389>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Detect Change'
 * '<S390>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
