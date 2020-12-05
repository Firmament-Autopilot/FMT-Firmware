/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.2868
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Dec  4 20:22:46 2020
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
  real_T DataTypeConversion;           /* '<S310>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S310>/Data Type Conversion1' */
  real_T OutportBufferFordz_dh;        /* '<S310>/WGS84_Derivatives' */
  real_T Add;                          /* '<S323>/Add' */
  real_T Product4;                     /* '<S323>/Product4' */
  real32_T Divide;                     /* '<S299>/Divide' */
  real32_T gain;                       /* '<S299>/gain' */
  real32_T h_0;                        /* '<S239>/Merge' */
  real32_T vel_D_0;                    /* '<S239>/Merge1' */
  real32_T Sum1[3];                    /* '<S227>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S218>/Sum1' */
  real32_T Sum1_pu[3];                 /* '<S208>/Sum1' */
  real32_T Saturation;                 /* '<S208>/Saturation' */
  real32_T DataTypeConversion_n[2];    /* '<S200>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S185>/Sum1' */
  real32_T Reshape[3];                 /* '<S146>/Reshape' */
  real32_T DiscreteTimeIntegrator[3];  /* '<S148>/Discrete-Time Integrator' */
  real32_T Merge[4];                   /* '<S65>/Merge' */
  real32_T OutportBufferForquaternion_0[4];/* '<S61>/DCM_to_quat' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S270>/Delay1' */
  real_T Delay_DSTATE[2];              /* '<S271>/Delay' */
  real_T Delay1_DSTATE_o[2];           /* '<S271>/Delay1' */
  real32_T Delay_6_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_8_DSTATE[9];          /* '<Root>/Delay' */
  real32_T Delay_DSTATE_d;             /* '<S299>/Delay' */
  real32_T Delay2_DSTATE;              /* '<S299>/Delay2' */
  real32_T Delay_8_DSTATE_l[9];        /* '<S56>/Delay' */
  real32_T Delay_9_DSTATE[9];          /* '<S56>/Delay' */
  real32_T Delay_9_DSTATE_m;           /* '<S57>/Delay' */
  real32_T Delay_10_DSTATE;            /* '<S57>/Delay' */
  real32_T Delay_11_DSTATE;            /* '<S57>/Delay' */
  real32_T Delay_DSTATE_b[3];          /* '<S237>/Delay' */
  real32_T Delay_DSTATE_l[6];          /* '<S195>/Delay' */
  real32_T Delay_DSTATE_p[3];          /* '<S229>/Delay' */
  real32_T x_delay_DSTATE[5];          /* '<S231>/x_delay' */
  real32_T Delay_DSTATE_k;             /* '<S234>/Delay' */
  real32_T h_delay_DSTATE[75];         /* '<S222>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S222>/vd_delay' */
  real32_T Delay_DSTATE_dr[3];         /* '<S210>/Delay' */
  real32_T x_delay_DSTATE_b[5];        /* '<S212>/x_delay' */
  real32_T Delay_DSTATE_h;             /* '<S215>/Delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S189>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S189>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S189>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S189>/vn_delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S157>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S158>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S141>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_lv[600];       /* '<S123>/Delay' */
  real32_T DiscreteFIRFilter_states[29];/* '<S125>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S141>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n[2];/* '<S149>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_a[2];/* '<S149>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_o[3];/* '<S148>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l[3];/* '<S148>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S116>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_o;/* '<S114>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S115>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S16>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_b3;/* '<S18>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_k;/* '<S15>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S17>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S320>/Unit Delay' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S125>/Discrete FIR Filter' */
  uint32_T DelayInput1_DSTATE;         /* '<S363>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_bo;/* '<S361>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S360>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nz;/* '<S358>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S343>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S340>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S333>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lp;/* '<S326>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_ht;      /* '<S337>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S328>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S322>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S316>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S302>/Delay Input1' */
  uint32_T Delay_DSTATE_f;             /* '<S298>/Delay' */
  uint32_T DiscreteTimeIntegrator_DSTAT_ev;/* '<S298>/Discrete-Time Integrator' */
  uint32_T Delay1_DSTATE_i;            /* '<S299>/Delay1' */
  uint32_T DelayInput1_DSTATE_nb;      /* '<S228>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S219>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S209>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S186>/Delay Input1' */
  uint32_T Output_DSTATE;              /* '<S4>/Output' */
  real32_T Memory_PreviousInput;       /* '<S224>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S220>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S192>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S187>/Memory' */
  uint16_T Delay_DSTATE_i;             /* '<S105>/Delay' */
  uint8_T Delay_DSTATE_k3;             /* '<S361>/Delay' */
  uint8_T Delay_DSTATE_f0;             /* '<S156>/Delay' */
  uint8_T DelayInput1_DSTATE_j;        /* '<S143>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_jy;     /* '<S265>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S267>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S272>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S274>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_db;     /* '<S236>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S226>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S217>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S194>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dy;     /* '<S160>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ff;     /* '<S142>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S108>/Delay Input1' */
  boolean_T Delay_DSTATE_bn;           /* '<S13>/Delay' */
  boolean_T Delay_DSTATE_c;            /* '<S16>/Delay' */
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
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S157>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S149>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S149>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S148>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevR_i;/* '<S148>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S13>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S16>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S18>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ou;/* '<S15>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ar;/* '<S17>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S231>/x_delay' */
  uint8_T icLoad_o;                    /* '<S222>/h_delay' */
  uint8_T icLoad_f;                    /* '<S222>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S212>/x_delay' */
  uint8_T icLoad_op;                   /* '<S189>/x_delay' */
  uint8_T icLoad_i;                    /* '<S189>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S189>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S189>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S157>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S141>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_o;/* '<S149>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_L_oi;/* '<S148>/Discrete-Time Integrator1' */
  boolean_T Relay_Mode;                /* '<S276>/Relay' */
  boolean_T Relay1_Mode;               /* '<S276>/Relay1' */
  boolean_T Relay_Mode_g;              /* '<S277>/Relay' */
  boolean_T Relay1_Mode_h;             /* '<S277>/Relay1' */
  boolean_T Relay_Mode_n;              /* '<S145>/Relay' */
  boolean_T Relay1_Mode_l;             /* '<S150>/Relay1' */
  boolean_T Relay2_Mode;               /* '<S64>/Relay2' */
  boolean_T Relay1_Mode_j;             /* '<S10>/Relay1' */
  boolean_T Reference_and_Derivative_MODE;/* '<S296>/Reference_and_Derivative' */
  boolean_T Rangefinder_Correct_MODE;  /* '<S207>/Rangefinder_Correct' */
  boolean_T GPS_Correct_MODE;          /* '<S206>/GPS_Correct' */
  boolean_T Baro_Correct_MODE;         /* '<S205>/Baro_Correct' */
  boolean_T GPS_Correct_MODE_o;        /* '<S183>/GPS_Correct' */
  boolean_T OpticalFlow_Acc_MODE;      /* '<S124>/OpticalFlow_Acc' */
  boolean_T GPS_Acc_MODE;              /* '<S124>/GPS_Acc' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState WGS84_Model_Trig_ZCE;     /* '<S290>/WGS84_Model' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S231>/x_delay' */
  ZCSigState h_delay_Reset_ZCE;        /* '<S222>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S222>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE_l;      /* '<S212>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S189>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S189>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S189>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S189>/vn_delay1' */
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
                                          *   '<S118>/Constant'
                                          *   '<S238>/Constant1'
                                          */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S181>/Constant'
                                        */
  real_T wmm_lookup_resolution;        /* Mask Parameter: wmm_lookup_resolution
                                        * Referenced by:
                                        *   '<S348>/Gain'
                                        *   '<S348>/Gain6'
                                        */
  real_T Zero_Value_Exclusion_thr;     /* Mask Parameter: Zero_Value_Exclusion_thr
                                        * Referenced by: '<S182>/Saturation'
                                        */
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S321>/Constant'
                                        */
  real32_T IMU1_Valid_Check_acc_max;   /* Mask Parameter: IMU1_Valid_Check_acc_max
                                        * Referenced by: '<S334>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_max;   /* Mask Parameter: IMU2_Valid_Check_acc_max
                                        * Referenced by: '<S338>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_acc_min;   /* Mask Parameter: IMU1_Valid_Check_acc_min
                                        * Referenced by: '<S334>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_min;   /* Mask Parameter: IMU2_Valid_Check_acc_min
                                        * Referenced by: '<S338>/Lower Limit'
                                        */
  real32_T CompareToConstant_const_g;  /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S63>/Constant'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S103>/Constant'
                                        */
  real32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S153>/Constant'
                                        */
  real32_T IMU1_Valid_Check_gyr_max;   /* Mask Parameter: IMU1_Valid_Check_gyr_max
                                        * Referenced by: '<S335>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_max;   /* Mask Parameter: IMU2_Valid_Check_gyr_max
                                        * Referenced by: '<S339>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_gyr_min;   /* Mask Parameter: IMU1_Valid_Check_gyr_min
                                        * Referenced by: '<S335>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_min;   /* Mask Parameter: IMU2_Valid_Check_gyr_min
                                        * Referenced by: '<S339>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S104>/Lower Limit'
                                        */
  real32_T IntervalTest1_lowlimit;     /* Mask Parameter: IntervalTest1_lowlimit
                                        * Referenced by: '<S303>/Lower Limit'
                                        */
  real32_T IntervalTest2_lowlimit;     /* Mask Parameter: IntervalTest2_lowlimit
                                        * Referenced by: '<S304>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit_m;    /* Mask Parameter: IntervalTest_lowlimit_m
                                        * Referenced by: '<S364>/Lower Limit'
                                        */
  real32_T Mag_Valid_mag_max;          /* Mask Parameter: Mag_Valid_mag_max
                                        * Referenced by: '<S344>/Upper Limit'
                                        */
  real32_T Mag_Valid_mag_min;          /* Mask Parameter: Mag_Valid_mag_min
                                        * Referenced by: '<S344>/Lower Limit'
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
                                        * Referenced by: '<S104>/Upper Limit'
                                        */
  real32_T IntervalTest1_uplimit;      /* Mask Parameter: IntervalTest1_uplimit
                                        * Referenced by: '<S303>/Upper Limit'
                                        */
  real32_T IntervalTest2_uplimit;      /* Mask Parameter: IntervalTest2_uplimit
                                        * Referenced by: '<S304>/Upper Limit'
                                        */
  real32_T IntervalTest_uplimit_d;     /* Mask Parameter: IntervalTest_uplimit_d
                                        * Referenced by: '<S364>/Upper Limit'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S301>/Constant'
                                        */
  uint32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S319>/Constant'
                                        */
  uint32_T CompareToConstant4_const_e; /* Mask Parameter: CompareToConstant4_const_e
                                        * Referenced by: '<S312>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S317>/Constant'
                                        */
  uint32_T CompareToConstant4_const_k; /* Mask Parameter: CompareToConstant4_const_k
                                        * Referenced by: '<S359>/Constant'
                                        */
  uint32_T CompareToConstant4_const_o; /* Mask Parameter: CompareToConstant4_const_o
                                        * Referenced by: '<S362>/Constant'
                                        */
  uint32_T Initialization_first_sample;/* Mask Parameter: Initialization_first_sample
                                        * Referenced by: '<S305>/Lower Limit'
                                        */
  uint32_T Initialization_last_sample; /* Mask Parameter: Initialization_last_sample
                                        * Referenced by:
                                        *   '<S300>/Constant'
                                        *   '<S305>/Upper Limit'
                                        */
  uint32_T IMU1_Valid_Check_timeout;   /* Mask Parameter: IMU1_Valid_Check_timeout
                                        * Referenced by: '<S332>/Constant'
                                        */
  uint32_T IMU2_Valid_Check_timeout;   /* Mask Parameter: IMU2_Valid_Check_timeout
                                        * Referenced by: '<S336>/Constant'
                                        */
  uint32_T Mag_Valid_timeout;          /* Mask Parameter: Mag_Valid_timeout
                                        * Referenced by: '<S342>/Constant'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S186>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S209>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S219>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_k;       /* Mask Parameter: DetectChange_vinit_k
                                        * Referenced by: '<S228>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S302>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S322>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S333>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_j;       /* Mask Parameter: DetectChange_vinit_j
                                        * Referenced by: '<S337>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S343>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S360>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_p;       /* Mask Parameter: DetectChange_vinit_p
                                        * Referenced by: '<S363>/Delay Input1'
                                        */
  int16_T wmm_lookup_wmm_declination[629];/* Mask Parameter: wmm_lookup_wmm_declination
                                           * Referenced by: '<S348>/Declination Lookup'
                                           */
  uint16_T valid_samples_const;        /* Mask Parameter: valid_samples_const
                                        * Referenced by: '<S109>/Constant'
                                        */
  boolean_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
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
  boolean_T CompareToConstant2_const_p;/* Mask Parameter: CompareToConstant2_const_p
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
  boolean_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S345>/Constant'
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
                                         * Referenced by: '<S108>/Delay Input1'
                                         */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S142>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_d;    /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S160>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_p;    /* Mask Parameter: DetectIncrease_vinit_p
                                        * Referenced by: '<S194>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S217>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S226>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_f;    /* Mask Parameter: DetectIncrease_vinit_f
                                        * Referenced by: '<S236>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S265>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_me;/* Mask Parameter: DetectRisePositive_vinit_me
                                         * Referenced by: '<S267>/Delay Input1'
                                         */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S272>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_h;/* Mask Parameter: DetectRisePositive3_vinit_h
                                         * Referenced by: '<S274>/Delay Input1'
                                         */
  int8_T wmm_lookup_wmm_inclination[629];/* Mask Parameter: wmm_lookup_wmm_inclination
                                          * Referenced by: '<S348>/Inclination Lookup'
                                          */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S318>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S306>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S307>/Constant'
                                        */
  uint8_T CompareToConstant2_const_bv; /* Mask Parameter: CompareToConstant2_const_bv
                                        * Referenced by: '<S311>/Constant'
                                        */
  uint8_T DetectIncrease1_vinit;       /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S143>/Delay Input1'
                                        */
  uint8_T wmm_lookup_wmm_magnitude[629];/* Mask Parameter: wmm_lookup_wmm_magnitude
                                         * Referenced by: '<S348>/Magnitude Lookup'
                                         */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S182>/Constant'
                                        */
  real_T Constant_Value_i[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S180>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S182>/Saturation'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S270>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S271>/Delay'
                                        */
  real_T Delay1_InitialCondition_e;    /* Expression: 0.0
                                        * Referenced by: '<S271>/Delay1'
                                        */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S310>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S310>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S310>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S310>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S310>/dz_dh'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S323>/constant1'
                                        */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S323>/constant2'
                                        */
  real_T b_Value;                      /* Expression: 1/298.257
                                        * Referenced by: '<S323>/b'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S323>/constant'
                                        */
  real_T a_Value;                      /* Expression: 6378137
                                        * Referenced by: '<S323>/a'
                                        */
  real_T c_Value;                      /* Expression: 1
                                        * Referenced by: '<S323>/c'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S320>/Unit Delay'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S320>/Saturation'
                                        */
  int32_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S320>/Saturation'
                                        */
  int32_T lat_offset_Value;            /* Computed Parameter: lat_offset_Value
                                        * Referenced by: '<S348>/lat_offset'
                                        */
  int32_T Saturation1_UpperSat;        /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S348>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S348>/Saturation1'
                                        */
  int32_T lon_offset_Value;            /* Computed Parameter: lon_offset_Value
                                        * Referenced by: '<S348>/lon_offset'
                                        */
  int32_T Saturation2_UpperSat;        /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S348>/Saturation2'
                                        */
  int32_T Saturation2_LowerSat;        /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S348>/Saturation2'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S309>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S309>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S309>/Gain2'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S309>/Scalefactor3'
                                        */
  int32_T Scalefactor1_Gain;           /* Computed Parameter: Scalefactor1_Gain
                                        * Referenced by: '<S309>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S309>/Scalefactor2'
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
                                            * Referenced by: '<S116>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC; /* Computed Parameter: DiscreteTimeIntegrator5_IC
                                        * Referenced by: '<S116>/Discrete-Time Integrator5'
                                        */
  real32_T Gain2_Gain_h;               /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S116>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_o;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_o
                                            * Referenced by: '<S114>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_m;/* Computed Parameter: DiscreteTimeIntegrator5_IC_m
                                         * Referenced by: '<S114>/Discrete-Time Integrator5'
                                         */
  real32_T Gain2_Gain_c;               /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S114>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_b;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_b
                                            * Referenced by: '<S115>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_a;/* Computed Parameter: DiscreteTimeIntegrator5_IC_a
                                         * Referenced by: '<S115>/Discrete-Time Integrator5'
                                         */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S64>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S64>/Saturation2'
                                        */
  real32_T Gain2_Gain_f;               /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S115>/Gain2'
                                        */
  real32_T Relay2_OnVal;               /* Computed Parameter: Relay2_OnVal
                                        * Referenced by: '<S64>/Relay2'
                                        */
  real32_T Relay2_OffVal;              /* Computed Parameter: Relay2_OffVal
                                        * Referenced by: '<S64>/Relay2'
                                        */
  real32_T Relay2_YOn;                 /* Computed Parameter: Relay2_YOn
                                        * Referenced by: '<S64>/Relay2'
                                        */
  real32_T Relay2_YOff;                /* Computed Parameter: Relay2_YOff
                                        * Referenced by: '<S64>/Relay2'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S135>/Constant'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S136>/Constant'
                                        */
  real32_T GPS_acc_O_mPs2_Y0;          /* Computed Parameter: GPS_acc_O_mPs2_Y0
                                        * Referenced by: '<S144>/GPS_acc_O_mPs2'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_i0;/* Computed Parameter: DiscreteTimeIntegrator_gainv_i0
                                            * Referenced by: '<S148>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_a;/* Computed Parameter: DiscreteTimeIntegrator_IC_a
                                        * Referenced by: '<S148>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S148>/Discrete-Time Integrator1'
                                            */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S148>/Gain2'
                                        */
  real32_T Gain3_Gain_p;               /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S148>/Gain3'
                                        */
  real32_T OptFlow_acc_O_mPs2_Y0;      /* Computed Parameter: OptFlow_acc_O_mPs2_Y0
                                        * Referenced by: '<S146>/OptFlow_acc_O_mPs2'
                                        */
  real32_T Constant_Value_gi;          /* Computed Parameter: Constant_Value_gi
                                        * Referenced by: '<S146>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                            * Referenced by: '<S149>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_h;/* Computed Parameter: DiscreteTimeIntegrator_IC_h
                                        * Referenced by: '<S149>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_p;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_p
                                            * Referenced by: '<S149>/Discrete-Time Integrator1'
                                            */
  real32_T Gain2_Gain_l;               /* Computed Parameter: Gain2_Gain_l
                                        * Referenced by: '<S149>/Gain2'
                                        */
  real32_T Gain3_Gain_n;               /* Computed Parameter: Gain3_Gain_n
                                        * Referenced by: '<S149>/Gain3'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                            * Referenced by: '<S141>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S145>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S145>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S145>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S145>/Relay'
                                        */
  real32_T Delay_InitialCondition_m;   /* Computed Parameter: Delay_InitialCondition_m
                                        * Referenced by: '<S123>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Expression: [0;0;-INS_CONST.g]
                                        * Referenced by: '<S147>/gravity'
                                        */
  real32_T Constant_Value_ew;          /* Computed Parameter: Constant_Value_ew
                                        * Referenced by: '<S127>/Constant'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S127>/Constant1'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S127>/Gain'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S127>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S127>/Saturation'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S125>/Constant'
                                        */
  real32_T Constant1_Value_cx;         /* Computed Parameter: Constant1_Value_cx
                                        * Referenced by: '<S125>/Constant1'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S125>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S125>/Dead Zone2'
                                        */
  real32_T DiscreteFIRFilter_InitialStates;/* Computed Parameter: DiscreteFIRFilter_InitialStates
                                            * Referenced by: '<S125>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficients[30];/* Computed Parameter: DiscreteFIRFilter_Coefficients
                                               * Referenced by: '<S125>/Discrete FIR Filter'
                                               */
  real32_T Gain_Gain_oh;               /* Computed Parameter: Gain_Gain_oh
                                        * Referenced by: '<S125>/Gain'
                                        */
  real32_T Saturation_UpperSat_k;      /* Computed Parameter: Saturation_UpperSat_k
                                        * Referenced by: '<S125>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S125>/Saturation'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S135>/Switch'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S136>/Switch'
                                        */
  real32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S126>/Constant8'
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
                                        * Referenced by: '<S126>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                            * Referenced by: '<S141>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_d;/* Computed Parameter: DiscreteTimeIntegrator_IC_d
                                        * Referenced by: '<S141>/Discrete-Time Integrator'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S141>/Gain1'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S141>/Gain'
                                        */
  real32_T Relay1_OnVal_i;             /* Computed Parameter: Relay1_OnVal_i
                                        * Referenced by: '<S150>/Relay1'
                                        */
  real32_T Relay1_OffVal_o;            /* Computed Parameter: Relay1_OffVal_o
                                        * Referenced by: '<S150>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S150>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S150>/Relay1'
                                        */
  real32_T mag_correct_gain_Gain;      /* Computed Parameter: mag_correct_gain_Gain
                                        * Referenced by: '<S151>/mag_correct_gain'
                                        */
  real32_T Gain3_Gain_k;               /* Computed Parameter: Gain3_Gain_k
                                        * Referenced by: '<S118>/Gain3'
                                        */
  real32_T Saturation2_UpperSat_h;     /* Computed Parameter: Saturation2_UpperSat_h
                                        * Referenced by: '<S118>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_o;     /* Computed Parameter: Saturation2_LowerSat_o
                                        * Referenced by: '<S118>/Saturation2'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S157>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S157>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S158>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S158>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S158>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S158>/Discrete-Time Integrator2'
                                            */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S157>/Gain2'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S161>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S161>/Gain1'
                                        */
  real32_T Gain2_Gain_oj;              /* Computed Parameter: Gain2_Gain_oj
                                        * Referenced by: '<S161>/Gain2'
                                        */
  real32_T Gain3_Gain_dx;              /* Computed Parameter: Gain3_Gain_dx
                                        * Referenced by: '<S161>/Gain3'
                                        */
  real32_T Gain4_Gain_o;               /* Computed Parameter: Gain4_Gain_o
                                        * Referenced by: '<S161>/Gain4'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S161>/Gain5'
                                        */
  real32_T Gain5_Gain_d;               /* Computed Parameter: Gain5_Gain_d
                                        * Referenced by: '<S170>/Gain5'
                                        */
  real32_T Saturation1_UpperSat_o;     /* Computed Parameter: Saturation1_UpperSat_o
                                        * Referenced by: '<S170>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_b;     /* Computed Parameter: Saturation1_LowerSat_b
                                        * Referenced by: '<S170>/Saturation1'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S172>/Gain'
                                        */
  real32_T Constant1_Value_g;          /* Expression: single(0)
                                        * Referenced by: '<S171>/Constant1'
                                        */
  real32_T Constant_Value_ev;          /* Expression: single(1)
                                        * Referenced by: '<S171>/Constant'
                                        */
  real32_T Gain_Gain_i;                /* Expression: single(-1)
                                        * Referenced by: '<S171>/Gain'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S179>/Constant'
                                        */
  real32_T Constant_Value_aq;          /* Computed Parameter: Constant_Value_aq
                                        * Referenced by: '<S173>/Constant'
                                        */
  real32_T Gain3_Gain_j;               /* Computed Parameter: Gain3_Gain_j
                                        * Referenced by: '<S190>/Gain3'
                                        */
  real32_T Gain_Gain_o0;               /* Computed Parameter: Gain_Gain_o0
                                        * Referenced by: '<S190>/Gain'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S190>/Gain2'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S185>/X_Next'
                                        */
  real32_T Memory_InitialCondition[2]; /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S192>/Memory'
                                        */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S187>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S187>/Gain3'
                                        */
  real32_T Constant_Value_b[2];        /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S197>/Constant'
                                        */
  real32_T X_0_Y0;                     /* Computed Parameter: X_0_Y0
                                        * Referenced by: '<S200>/X_0'
                                        */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S213>/Gain1'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S213>/Gain'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S208>/X_Next'
                                        */
  real32_T Delay_InitialCondition_j;   /* Computed Parameter: Delay_InitialCondition_j
                                        * Referenced by: '<S210>/Delay'
                                        */
  real32_T Delay_InitialCondition_mk;  /* Computed Parameter: Delay_InitialCondition_mk
                                        * Referenced by: '<S215>/Delay'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S213>/Gain2'
                                        */
  real32_T Gain_Gain_p;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S210>/Gain'
                                        */
  real32_T Saturation_UpperSat_as;     /* Computed Parameter: Saturation_UpperSat_as
                                        * Referenced by: '<S208>/Saturation'
                                        */
  real32_T Saturation_LowerSat_e;      /* Computed Parameter: Saturation_LowerSat_e
                                        * Referenced by: '<S208>/Saturation'
                                        */
  real32_T Gain1_Gain_ml;              /* Computed Parameter: Gain1_Gain_ml
                                        * Referenced by: '<S223>/Gain1'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S223>/Gain'
                                        */
  real32_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S223>/Gain2'
                                        */
  real32_T X_Next_Y0_i;                /* Computed Parameter: X_Next_Y0_i
                                        * Referenced by: '<S218>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S224>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S220>/Memory'
                                        */
  real32_T Gain3_Gain_kn;              /* Expression: INS_CONST.dt
                                        * Referenced by: '<S220>/Gain3'
                                        */
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S232>/Gain1'
                                        */
  real32_T Gain_Gain_lp;               /* Computed Parameter: Gain_Gain_lp
                                        * Referenced by: '<S232>/Gain'
                                        */
  real32_T X_Next_Y0_h;                /* Computed Parameter: X_Next_Y0_h
                                        * Referenced by: '<S227>/X_Next'
                                        */
  real32_T Delay_InitialCondition_k;   /* Computed Parameter: Delay_InitialCondition_k
                                        * Referenced by: '<S229>/Delay'
                                        */
  real32_T Delay_InitialCondition_l;   /* Computed Parameter: Delay_InitialCondition_l
                                        * Referenced by: '<S234>/Delay'
                                        */
  real32_T Gain2_Gain_m4;              /* Computed Parameter: Gain2_Gain_m4
                                        * Referenced by: '<S232>/Gain2'
                                        */
  real32_T Gain_Gain_b;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S229>/Gain'
                                        */
  real32_T Constant_Value_eq;          /* Computed Parameter: Constant_Value_eq
                                        * Referenced by: '<S239>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S243>/Constant'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S245>/Constant'
                                        */
  real32_T Merge_InitialOutput_j;      /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S239>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S239>/Merge1'
                                        */
  real32_T Delay_InitialCondition_mt;  /* Computed Parameter: Delay_InitialCondition_mt
                                        * Referenced by: '<S237>/Delay'
                                        */
  real32_T Gain1_Gain_kw;              /* Computed Parameter: Gain1_Gain_kw
                                        * Referenced by: '<S238>/Gain1'
                                        */
  real32_T Constant_Value_nn;          /* Computed Parameter: Constant_Value_nn
                                        * Referenced by: '<S238>/Constant'
                                        */
  real32_T Gain_Gain_mr;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S238>/Gain'
                                        */
  real32_T Delay_InitialCondition_g;   /* Computed Parameter: Delay_InitialCondition_g
                                        * Referenced by: '<S195>/Delay'
                                        */
  real32_T Constant_Value_l[2];        /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S196>/Constant'
                                        */
  real32_T Gain_Gain_ic;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S196>/Gain'
                                        */
  real32_T Constant_Value_be;          /* Computed Parameter: Constant_Value_be
                                        * Referenced by: '<S288>/Constant'
                                        */
  real32_T Constant_Value_o0;          /* Computed Parameter: Constant_Value_o0
                                        * Referenced by: '<S287>/Constant'
                                        */
  real32_T Relay_OnVal_e;              /* Computed Parameter: Relay_OnVal_e
                                        * Referenced by: '<S276>/Relay'
                                        */
  real32_T Relay_OffVal_k;             /* Computed Parameter: Relay_OffVal_k
                                        * Referenced by: '<S276>/Relay'
                                        */
  real32_T Relay_YOn_k;                /* Computed Parameter: Relay_YOn_k
                                        * Referenced by: '<S276>/Relay'
                                        */
  real32_T Relay_YOff_k;               /* Computed Parameter: Relay_YOff_k
                                        * Referenced by: '<S276>/Relay'
                                        */
  real32_T Relay1_OnVal_n;             /* Computed Parameter: Relay1_OnVal_n
                                        * Referenced by: '<S276>/Relay1'
                                        */
  real32_T Relay1_OffVal_h;            /* Computed Parameter: Relay1_OffVal_h
                                        * Referenced by: '<S276>/Relay1'
                                        */
  real32_T Relay1_YOn_p;               /* Computed Parameter: Relay1_YOn_p
                                        * Referenced by: '<S276>/Relay1'
                                        */
  real32_T Relay1_YOff_e;              /* Computed Parameter: Relay1_YOff_e
                                        * Referenced by: '<S276>/Relay1'
                                        */
  real32_T Relay_OnVal_e0;             /* Computed Parameter: Relay_OnVal_e0
                                        * Referenced by: '<S277>/Relay'
                                        */
  real32_T Relay_OffVal_p;             /* Computed Parameter: Relay_OffVal_p
                                        * Referenced by: '<S277>/Relay'
                                        */
  real32_T Relay_YOn_l;                /* Computed Parameter: Relay_YOn_l
                                        * Referenced by: '<S277>/Relay'
                                        */
  real32_T Relay_YOff_m;               /* Computed Parameter: Relay_YOff_m
                                        * Referenced by: '<S277>/Relay'
                                        */
  real32_T Relay1_OnVal_c;             /* Computed Parameter: Relay1_OnVal_c
                                        * Referenced by: '<S277>/Relay1'
                                        */
  real32_T Relay1_OffVal_hg;           /* Computed Parameter: Relay1_OffVal_hg
                                        * Referenced by: '<S277>/Relay1'
                                        */
  real32_T Relay1_YOn_e;               /* Computed Parameter: Relay1_YOn_e
                                        * Referenced by: '<S277>/Relay1'
                                        */
  real32_T Relay1_YOff_d;              /* Computed Parameter: Relay1_YOff_d
                                        * Referenced by: '<S277>/Relay1'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S277>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S277>/Saturation'
                                        */
  real32_T Constant_Value_hv;          /* Computed Parameter: Constant_Value_hv
                                        * Referenced by: '<S281>/Constant'
                                        */
  real32_T Constant_Value_h4;          /* Computed Parameter: Constant_Value_h4
                                        * Referenced by: '<S282>/Constant'
                                        */
  real32_T Saturation1_UpperSat_i;     /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S277>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_j;     /* Computed Parameter: Saturation1_LowerSat_j
                                        * Referenced by: '<S277>/Saturation1'
                                        */
  real32_T Constant_Value_iw;          /* Computed Parameter: Constant_Value_iw
                                        * Referenced by: '<S283>/Constant'
                                        */
  real32_T Delay_8_InitialCondition;   /* Computed Parameter: Delay_8_InitialCondition
                                        * Referenced by: '<S56>/Delay'
                                        */
  real32_T Delay_9_InitialCondition;   /* Computed Parameter: Delay_9_InitialCondition
                                        * Referenced by: '<S56>/Delay'
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
  real32_T pressure_R_Y0;              /* Computed Parameter: pressure_R_Y0
                                        * Referenced by: '<S299>/pressure_R'
                                        */
  real32_T dh_dp_Y0;                   /* Computed Parameter: dh_dp_Y0
                                        * Referenced by: '<S299>/dh_dp'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S299>/Constant2'
                                        */
  real32_T Delay_InitialCondition_p;   /* Computed Parameter: Delay_InitialCondition_p
                                        * Referenced by: '<S299>/Delay'
                                        */
  real32_T Delay2_InitialCondition;    /* Computed Parameter: Delay2_InitialCondition
                                        * Referenced by: '<S299>/Delay2'
                                        */
  real32_T Saturation_UpperSat_m;      /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S299>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S299>/Saturation'
                                        */
  real32_T gain_Gain;                  /* Computed Parameter: gain_Gain
                                        * Referenced by: '<S299>/gain'
                                        */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S315>/Constant7'
                                        */
  real32_T Gain3_Gain_lx;              /* Computed Parameter: Gain3_Gain_lx
                                        * Referenced by: '<S315>/Gain3'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real32_T Saturation_LowerSat_ku;     /* Computed Parameter: Saturation_LowerSat_ku
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real32_T Constant1_Value_g5;         /* Computed Parameter: Constant1_Value_g5
                                        * Referenced by: '<S314>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S314>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S308>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S308>/Saturation1'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S346>/default_mag_quality'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S351>/Nominal_Magnitude'
                                        */
  real32_T gain_Gain_m;                /* Computed Parameter: gain_Gain_m
                                        * Referenced by: '<S351>/gain'
                                        */
  real32_T Constant1_Value_cq;         /* Computed Parameter: Constant1_Value_cq
                                        * Referenced by: '<S351>/Constant1'
                                        */
  real32_T Saturation_UpperSat_gv;     /* Computed Parameter: Saturation_UpperSat_gv
                                        * Referenced by: '<S351>/Saturation'
                                        */
  real32_T Saturation_LowerSat_pf;     /* Computed Parameter: Saturation_LowerSat_pf
                                        * Referenced by: '<S351>/Saturation'
                                        */
  real32_T gain_Gain_g;                /* Computed Parameter: gain_Gain_g
                                        * Referenced by: '<S350>/gain'
                                        */
  real32_T Constant2_Value_hh;         /* Computed Parameter: Constant2_Value_hh
                                        * Referenced by: '<S350>/Constant2'
                                        */
  real32_T Saturation_UpperSat_gg;     /* Computed Parameter: Saturation_UpperSat_gg
                                        * Referenced by: '<S350>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S350>/Saturation'
                                        */
  real32_T Constant_Value_g2;          /* Computed Parameter: Constant_Value_g2
                                        * Referenced by: '<S357>/Constant'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S292>/Gauss_to_uT'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S356>/Constant3'
                                        */
  real32_T Gain_Gain_b5;               /* Computed Parameter: Gain_Gain_b5
                                        * Referenced by: '<S356>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S356>/Constant4'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S356>/Constant2'
                                        */
  real32_T Constant1_Value_c2;         /* Computed Parameter: Constant1_Value_c2
                                        * Referenced by: '<S356>/Constant1'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S356>/Constant'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S347>/Constant1'
                                        */
  real32_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S357>/Switch'
                                        */
  real32_T Constant_Value_bg;          /* Computed Parameter: Constant_Value_bg
                                        * Referenced by: '<S293>/Constant'
                                        */
  real32_T Constant_Value_jp;          /* Computed Parameter: Constant_Value_jp
                                        * Referenced by: '<S358>/Constant'
                                        */
  real32_T Delay_6_InitialCondition;   /* Computed Parameter: Delay_6_InitialCondition
                                        * Referenced by: '<Root>/Delay'
                                        */
  real32_T Delay_8_InitialCondition_m; /* Computed Parameter: Delay_8_InitialCondition_m
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Gain5_Gain_a;               /* Computed Parameter: Gain5_Gain_a
                                        * Referenced by: '<S315>/Gain5'
                                        */
  uint32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S314>/Gain1'
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
                                        * Referenced by: '<S105>/Delay'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S156>/Delay'
                                        */
  uint32_T x_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S189>/x_delay'
                                        */
  uint32_T x_delay1_DelayLength;       /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S189>/x_delay1'
                                        */
  uint32_T vn_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S189>/vn_delay'
                                        */
  uint32_T vn_delay1_DelayLength;      /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S189>/vn_delay1'
                                        */
  uint32_T Delay_DelayLength_fx;       /* Computed Parameter: Delay_DelayLength_fx
                                        * Referenced by: '<S210>/Delay'
                                        */
  uint32_T x_delay_DelayLength_m;      /* Expression: 10/INS_EXPORT_VALUE.period
                                        * Referenced by: '<S212>/x_delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S215>/Delay'
                                        */
  uint32_T h_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S222>/h_delay'
                                        */
  uint32_T vd_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S222>/vd_delay'
                                        */
  uint32_T Delay_DelayLength_o;        /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S229>/Delay'
                                        */
  uint32_T x_delay_DelayLength_l;      /* Expression: 10/INS_EXPORT_VALUE.period
                                        * Referenced by: '<S231>/x_delay'
                                        */
  uint32_T Delay_DelayLength_kz;       /* Computed Parameter: Delay_DelayLength_kz
                                        * Referenced by: '<S234>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S237>/Delay'
                                        */
  uint32_T Delay_DelayLength_ly;       /* Computed Parameter: Delay_DelayLength_ly
                                        * Referenced by: '<S195>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S270>/Delay1'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S271>/Delay'
                                        */
  uint32_T Delay1_DelayLength_o;       /* Computed Parameter: Delay1_DelayLength_o
                                        * Referenced by: '<S271>/Delay1'
                                        */
  uint32_T Delay_8_DelayLength;        /* Computed Parameter: Delay_8_DelayLength
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_9_DelayLength;        /* Computed Parameter: Delay_9_DelayLength
                                        * Referenced by: '<S56>/Delay'
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
                                        * Referenced by: '<S299>/Constant1'
                                        */
  uint32_T Delay_DelayLength_jx;       /* Computed Parameter: Delay_DelayLength_jx
                                        * Referenced by: '<S299>/Delay'
                                        */
  uint32_T Delay1_DelayLength_p;       /* Computed Parameter: Delay1_DelayLength_p
                                        * Referenced by: '<S299>/Delay1'
                                        */
  uint32_T Delay1_InitialCondition_k;  /* Computed Parameter: Delay1_InitialCondition_k
                                        * Referenced by: '<S299>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S299>/Delay2'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S299>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S299>/Saturation1'
                                        */
  uint32_T Delay_DelayLength_dn;       /* Computed Parameter: Delay_DelayLength_dn
                                        * Referenced by: '<S298>/Delay'
                                        */
  uint32_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S298>/Delay'
                                        */
  uint32_T Saturation_UpperSat_f;      /* Computed Parameter: Saturation_UpperSat_f
                                        * Referenced by: '<S298>/Saturation'
                                        */
  uint32_T Saturation_LowerSat_pw;     /* Computed Parameter: Saturation_LowerSat_pw
                                        * Referenced by: '<S298>/Saturation'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_dv;/* Computed Parameter: DiscreteTimeIntegrator_IC_dv
                                         * Referenced by: '<S298>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S316>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S326>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_pw;/* Computed Parameter: DiscreteTimeIntegrator_IC_pw
                                         * Referenced by: '<S328>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S340>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S358>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_ov;/* Computed Parameter: DiscreteTimeIntegrator_IC_ov
                                         * Referenced by: '<S361>/Discrete-Time Integrator'
                                         */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S361>/Delay'
                                        */
  uint32_T Delay_6_DelayLength;        /* Computed Parameter: Delay_6_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint32_T Delay_8_DelayLength_g;      /* Computed Parameter: Delay_8_DelayLength_g
                                        * Referenced by: '<Root>/Delay'
                                        */
  int16_T Gain_Gain_fs;                /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S347>/Gain'
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
                                        * Referenced by: '<S105>/Delay'
                                        */
  uint16_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S105>/Saturation'
                                        */
  uint16_T Saturation_LowerSat_hb;     /* Computed Parameter: Saturation_LowerSat_hb
                                        * Referenced by: '<S105>/Saturation'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S147>/GPS_Delay'
                                        */
  uint16_T OptFlow_Delay_Value;        /* Computed Parameter: OptFlow_Delay_Value
                                        * Referenced by: '<S147>/OptFlow_Delay'
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
  boolean_T Relay1_YOff_k;             /* Computed Parameter: Relay1_YOff_k
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
                                        * Referenced by: '<S110>/Constant'
                                        */
  boolean_T Constant_Value_bt;         /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S266>/Constant'
                                        */
  boolean_T Constant_Value_gn;         /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S268>/Constant'
                                        */
  boolean_T Constant_Value_m3;         /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S273>/Constant'
                                        */
  boolean_T Constant_Value_pt;         /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S275>/Constant'
                                        */
  boolean_T Constant_Value_cz;         /* Computed Parameter: Constant_Value_cz
                                        * Referenced by: '<S278>/Constant'
                                        */
  boolean_T Constant_Value_p2;         /* Computed Parameter: Constant_Value_p2
                                        * Referenced by: '<S279>/Constant'
                                        */
  boolean_T Constant_Value_hvm;        /* Computed Parameter: Constant_Value_hvm
                                        * Referenced by: '<S280>/Constant'
                                        */
  int8_T Gain1_Gain_o;                 /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S350>/Gain1'
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
                                        * Referenced by: '<S331>/Gain'
                                        */
  uint8_T Gain9_Gain;                  /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S8>/Gain9'
                                        */
  uint8_T Saturation_UpperSat_d;       /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S145>/Saturation'
                                        */
  uint8_T Saturation_LowerSat_b;       /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S145>/Saturation'
                                        */
  uint8_T Constant_Value_mm;           /* Computed Parameter: Constant_Value_mm
                                        * Referenced by: '<S156>/Constant'
                                        */
  uint8_T Delay_InitialCondition_k5;   /* Computed Parameter: Delay_InitialCondition_k5
                                        * Referenced by: '<S156>/Delay'
                                        */
  uint8_T Constant_Value_jz;           /* Computed Parameter: Constant_Value_jz
                                        * Referenced by: '<S175>/Constant'
                                        */
  uint8_T Constant_Value_jn;           /* Computed Parameter: Constant_Value_jn
                                        * Referenced by: '<S329>/Constant'
                                        */
  uint8_T Constant2_Value_b;           /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S361>/Constant2'
                                        */
  uint8_T Delay_InitialCondition_f;    /* Computed Parameter: Delay_InitialCondition_f
                                        * Referenced by: '<S361>/Delay'
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
                                                 *   '<S326>/Constant'
                                                 *   '<S328>/Constant'
                                                 *   '<S340>/Constant'
                                                 *   '<S361>/Constant1'
                                                 *   '<S12>/Constant'
                                                 *   '<S13>/Constant'
                                                 *   '<S14>/Constant'
                                                 *   '<S15>/Constant'
                                                 *   '<S16>/Constant'
                                                 *   '<S17>/Constant'
                                                 *   '<S18>/Constant'
                                                 *   '<S298>/Constant'
                                                 *   '<S316>/Constant'
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
 * '<S58>'  : 'INS/Data_Fusion/AHRS/Attitude_Init'
 * '<S59>'  : 'INS/Data_Fusion/AHRS/Correct'
 * '<S60>'  : 'INS/Data_Fusion/AHRS/Integrate'
 * '<S61>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization'
 * '<S62>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset'
 * '<S63>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Compare To Constant'
 * '<S64>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Standstill_Condition'
 * '<S65>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat'
 * '<S66>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/cross_product'
 * '<S67>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/cross_product1'
 * '<S68>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/safe_norm'
 * '<S69>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/safe_norm1'
 * '<S70>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/safe_norm2'
 * '<S71>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace'
 * '<S72>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/PositiveTrace'
 * '<S73>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/trace(DCM)'
 * '<S74>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)'
 * '<S75>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)'
 * '<S76>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)'
 * '<S77>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/diag(DCM)'
 * '<S78>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S79>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S80>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S81>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S82>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S83>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S84>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S85>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S86>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S87>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S88>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S89>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S90>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S91>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S92>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/NegativeTrace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S93>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/PositiveTrace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S94>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/PositiveTrace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S95>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/DCM_to_quat/PositiveTrace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S96>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/cross_product/Subsystem'
 * '<S97>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/cross_product/Subsystem1'
 * '<S98>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/cross_product1/Subsystem'
 * '<S99>'  : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/cross_product1/Subsystem1'
 * '<S100>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/safe_norm/Euclidean_Norm2'
 * '<S101>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/safe_norm1/Euclidean_Norm2'
 * '<S102>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Initialization/safe_norm2/Euclidean_Norm2'
 * '<S103>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/Compare To Constant'
 * '<S104>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/Interval Test'
 * '<S105>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/reset_condition'
 * '<S106>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/vec_modulus'
 * '<S107>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/vec_modulus1'
 * '<S108>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/reset_condition/Detect Rise Positive'
 * '<S109>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/reset_condition/valid_samples'
 * '<S110>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/reset_condition/Detect Rise Positive/Positive'
 * '<S111>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/vec_modulus/vec_norm'
 * '<S112>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Attitude_Reset/vec_modulus1/vec_norm'
 * '<S113>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Standstill_Condition/HPF'
 * '<S114>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Standstill_Condition/LPF'
 * '<S115>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Standstill_Condition/LPF1'
 * '<S116>' : 'INS/Data_Fusion/AHRS/Attitude_Init/Standstill_Condition/HPF/LPF'
 * '<S117>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction'
 * '<S118>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction'
 * '<S119>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct'
 * '<S120>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Heading_Correction'
 * '<S121>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Output'
 * '<S122>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct'
 * '<S123>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Estimated_Acc'
 * '<S124>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc'
 * '<S125>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct'
 * '<S126>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct'
 * '<S127>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/Compare'
 * '<S128>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product'
 * '<S129>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/magnitude'
 * '<S130>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/magnitude1'
 * '<S131>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem'
 * '<S132>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Heading_Correct/cross_product/Subsystem1'
 * '<S133>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/NonlinerSaturation'
 * '<S134>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/cross_product'
 * '<S135>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize'
 * '<S136>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize1'
 * '<S137>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/NonlinerSaturation/vec_modulus'
 * '<S138>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/NonlinerSaturation/vec_modulus/vec_norm'
 * '<S139>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/cross_product/Subsystem'
 * '<S140>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Acc_Correct/Verticle_Correct/cross_product/Subsystem1'
 * '<S141>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Estimated_Acc/Butter_LPF'
 * '<S142>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Detect Increase'
 * '<S143>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Detect Increase1'
 * '<S144>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/GPS_Acc'
 * '<S145>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Measurement_Sensor'
 * '<S146>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/OpticalFlow_Acc'
 * '<S147>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/Output_Selection'
 * '<S148>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/GPS_Acc/LinearObserver'
 * '<S149>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Attitude_Correct/Measured_Acc/OpticalFlow_Acc/LinearObserver'
 * '<S150>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Heading_Correction/Enable'
 * '<S151>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Heading_Correction/Mag_Correction'
 * '<S152>' : 'INS/Data_Fusion/AHRS/Correct/Attitude_Correction/Heading_Correction/Subsystem'
 * '<S153>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/Compare To Constant'
 * '<S154>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/vec_modulus'
 * '<S155>' : 'INS/Data_Fusion/AHRS/Correct/Bias_Correction/vec_modulus/vec_norm'
 * '<S156>' : 'INS/Data_Fusion/AHRS/Integrate/Att_Init_Done'
 * '<S157>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration'
 * '<S158>' : 'INS/Data_Fusion/AHRS/Integrate/Bias_Integration'
 * '<S159>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle'
 * '<S160>' : 'INS/Data_Fusion/AHRS/Integrate/Att_Init_Done/Detect Increase'
 * '<S161>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/Quat_to_M_OB'
 * '<S162>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat mult'
 * '<S163>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize'
 * '<S164>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat mult/q(0)'
 * '<S165>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat mult/q(1)'
 * '<S166>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat mult/q(2)'
 * '<S167>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat mult/q(3)'
 * '<S168>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus'
 * '<S169>' : 'INS/Data_Fusion/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus/quat norm'
 * '<S170>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/Euler_Angle'
 * '<S171>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/M_CO1'
 * '<S172>' : 'INS/Data_Fusion/AHRS/Integrate/Euler_Angle/Euler_Angle/quat_to_psi'
 * '<S173>' : 'INS/Data_Fusion/Translation_Filter/CF'
 * '<S174>' : 'INS/Data_Fusion/Translation_Filter/TF_Data'
 * '<S175>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment'
 * '<S176>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter'
 * '<S177>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter'
 * '<S178>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting'
 * '<S179>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Height_Above_Ground'
 * '<S180>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/WGS_Pos'
 * '<S181>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/WGS_Pos/Compare To Constant'
 * '<S182>' : 'INS/Data_Fusion/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/WGS_Pos/Zero_Value_Exclusion'
 * '<S183>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S184>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S185>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S186>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S187>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Error_Hold'
 * '<S188>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S189>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Observation'
 * '<S190>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Scaling'
 * '<S191>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S192>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S193>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Bias_Update'
 * '<S194>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Bias_Estimation/Bias/Detect Increase'
 * '<S195>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S196>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S197>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S198>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S199>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S200>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S201>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S202>' : 'INS/Data_Fusion/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/OptFlow_Vel_Init'
 * '<S203>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S204>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S205>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S206>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S207>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct'
 * '<S208>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct'
 * '<S209>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S210>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Error_Hold'
 * '<S211>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S212>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Observation'
 * '<S213>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling'
 * '<S214>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling1'
 * '<S215>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation'
 * '<S216>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Bias'
 * '<S217>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S218>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S219>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S220>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Error_Hold'
 * '<S221>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S222>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Observation'
 * '<S223>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Scaling'
 * '<S224>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation'
 * '<S225>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Bias'
 * '<S226>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S227>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct'
 * '<S228>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Detect Change'
 * '<S229>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Error_Hold'
 * '<S230>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement'
 * '<S231>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Observation'
 * '<S232>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Scaling'
 * '<S233>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Scaling1'
 * '<S234>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation'
 * '<S235>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Bias'
 * '<S236>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Correct/Rangefinder_Correct/Rangefinder_Correct/Measurement/Bias_Estimation/Detect Increase'
 * '<S237>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S238>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S239>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S240>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S241>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S242>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init'
 * '<S243>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S244>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S245>' : 'INS/Data_Fusion/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init/Reference_Height'
 * '<S246>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Measurement'
 * '<S247>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Status'
 * '<S248>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process'
 * '<S249>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Measurement/Baro_Meas'
 * '<S250>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Measurement/GPS_Meas'
 * '<S251>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Measurement/OpticalFlow_Meas'
 * '<S252>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Measurement/Sonar_Meas'
 * '<S253>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Status/Baro_Status'
 * '<S254>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Status/GPS_Status'
 * '<S255>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Status/OpticalFlow_Status'
 * '<S256>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/Sensor_Status/Sonar_Status'
 * '<S257>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init'
 * '<S258>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable'
 * '<S259>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Valid'
 * '<S260>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Bus_Selection'
 * '<S261>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset'
 * '<S262>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference'
 * '<S263>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset/Height_Reset'
 * '<S264>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset/Position_Reset'
 * '<S265>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset/Height_Reset/Detect Rise Positive'
 * '<S266>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset/Height_Reset/Detect Rise Positive/Positive'
 * '<S267>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset/Position_Reset/Detect Rise Positive'
 * '<S268>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/Pos_Reset/Position_Reset/Detect Rise Positive/Positive'
 * '<S269>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/Bus_Assignment'
 * '<S270>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/WGS84_Height_Ref'
 * '<S271>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/WGS84_Position_Ref'
 * '<S272>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3'
 * '<S273>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3/Positive'
 * '<S274>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3'
 * '<S275>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Filter_Init/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3/Positive'
 * '<S276>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Horizontal_Select'
 * '<S277>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Vertical_Select'
 * '<S278>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Horizontal_Select/Compare To Zero2'
 * '<S279>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero'
 * '<S280>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero1'
 * '<S281>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero4'
 * '<S282>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero5'
 * '<S283>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Enable/Sensor_Vertical_Select/Compare To Zero6'
 * '<S284>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Valid/Position_Validity'
 * '<S285>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Valid/Position_Validity/Horizontal_Validity'
 * '<S286>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Valid/Position_Validity/Vertical_Validity'
 * '<S287>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Valid/Position_Validity/Horizontal_Validity/Compare To Zero'
 * '<S288>' : 'INS/Data_Fusion/Translation_Filter/TF_Data/TF_Data_Process/Sensor_Valid/Position_Validity/Vertical_Validity/Compare To Zero'
 * '<S289>' : 'INS/Sensor_Process/Baro_Process'
 * '<S290>' : 'INS/Sensor_Process/GPS_Process'
 * '<S291>' : 'INS/Sensor_Process/IMU_Process'
 * '<S292>' : 'INS/Sensor_Process/Mag_Process'
 * '<S293>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing'
 * '<S294>' : 'INS/Sensor_Process/Rangefinder_Process'
 * '<S295>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height'
 * '<S296>' : 'INS/Sensor_Process/Baro_Process/Relative_Height'
 * '<S297>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height/Interval Test1'
 * '<S298>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization'
 * '<S299>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Reference_and_Derivative'
 * '<S300>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization/Compare To Constant2'
 * '<S301>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization/Compare To Constant4'
 * '<S302>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization/Detect Change'
 * '<S303>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization/Interval Test1'
 * '<S304>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization/Interval Test2'
 * '<S305>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Initialization/Interval Test3'
 * '<S306>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant'
 * '<S307>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant1'
 * '<S308>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality'
 * '<S309>' : 'INS/Sensor_Process/GPS_Process/Scaling'
 * '<S310>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model'
 * '<S311>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant2'
 * '<S312>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant4'
 * '<S313>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status'
 * '<S314>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/horizontal_acc'
 * '<S315>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/speed_acc'
 * '<S316>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check'
 * '<S317>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant'
 * '<S318>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant1'
 * '<S319>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Compare To Constant2'
 * '<S320>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Initialization'
 * '<S321>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/GPS_Status/Initialization/Compare To Constant3'
 * '<S322>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check/Detect Change'
 * '<S323>' : 'INS/Sensor_Process/GPS_Process/WGS84_Model/WGS84_Derivatives'
 * '<S324>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment'
 * '<S325>' : 'INS/Sensor_Process/IMU_Process/IMU1_Select'
 * '<S326>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check'
 * '<S327>' : 'INS/Sensor_Process/IMU_Process/IMU2_Select'
 * '<S328>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check'
 * '<S329>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/Compare To Zero'
 * '<S330>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Select'
 * '<S331>' : 'INS/Sensor_Process/IMU_Process/Bus_Assignment/IMU_Status'
 * '<S332>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Compare To Constant4'
 * '<S333>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Detect Change'
 * '<S334>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test1'
 * '<S335>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test3'
 * '<S336>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Compare To Constant4'
 * '<S337>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Detect Change'
 * '<S338>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test1'
 * '<S339>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test3'
 * '<S340>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid'
 * '<S341>' : 'INS/Sensor_Process/Mag_Process/Magnetometer'
 * '<S342>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid/Compare To Constant4'
 * '<S343>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid/Detect Change'
 * '<S344>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid/Interval Test1'
 * '<S345>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Compare To Constant'
 * '<S346>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication'
 * '<S347>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation'
 * '<S348>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/wmm_lookup'
 * '<S349>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate'
 * '<S350>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate'
 * '<S351>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate'
 * '<S352>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus'
 * '<S353>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus/vec_norm'
 * '<S354>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus'
 * '<S355>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus/vec_norm'
 * '<S356>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/psi_to_Mz'
 * '<S357>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/vec_normalize'
 * '<S358>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect'
 * '<S359>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Compare To Constant4'
 * '<S360>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Detect Change'
 * '<S361>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check'
 * '<S362>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Compare To Constant4'
 * '<S363>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Detect Change'
 * '<S364>' : 'INS/Sensor_Process/Rangefinder_Process/Valid_Check/Interval Test'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
