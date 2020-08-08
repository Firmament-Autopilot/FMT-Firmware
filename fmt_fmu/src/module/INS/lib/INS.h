/*
 * File: INS.h
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.2379
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug  5 16:22:09 2020
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

#ifndef DEFINED_TYPEDEF_FOR_struct_4XfCoaAMTej5uH3d8u88xB_
#define DEFINED_TYPEDEF_FOR_struct_4XfCoaAMTej5uH3d8u88xB_

typedef struct {
  uint32_T period;
} struct_4XfCoaAMTej5uH3d8u88xB;

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
  real_T Scalefactor;                  /* '<S160>/Scalefactor' */
  real_T dz_dh;                        /* '<S160>/WGS84_Derivatives' */
  real_T Scalefactor1;                 /* '<S160>/Scalefactor1' */
  real_T Add;                          /* '<S172>/Add' */
  real_T Product4;                     /* '<S172>/Product4' */
  real32_T h_0;                        /* '<S278>/Merge' */
  real32_T vel_D_0;                    /* '<S278>/Merge1' */
  real32_T Sum1[3];                    /* '<S267>/Sum1' */
  real32_T Sum1_p[3];                  /* '<S258>/Sum1' */
  real32_T DataTypeConversion[2];      /* '<S251>/Data Type Conversion' */
  real32_T Sum1_o[6];                  /* '<S236>/Sum1' */
  real32_T Divide;                     /* '<S146>/Divide' */
  real32_T g_M_d_R;                    /* '<S146>/g_M_d_R' */
  real32_T OutportBufferForOptFlow_acc_O_m[3];
  real32_T DiscreteTimeIntegrator[3];  /* '<S62>/Discrete-Time Integrator' */
  real32_T OutportBufferForquaternion_0[4];/* '<S8>/M to Quat' */
} BlockIO_INS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T memory3_PreviousInput[2];     /* '<S302>/memory3' */
  real_T memory2_PreviousInput[2];     /* '<S302>/memory2' */
  real_T memory2_PreviousInput_j;      /* '<S301>/memory2' */
  real32_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S195>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[4];/* '<S72>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE[3];/* '<S73>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTAT_a[3];/* '<S194>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S27>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S96>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S93>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_o;/* '<S92>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_j;/* '<S94>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S95>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S97>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_e;/* '<S98>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator5_DSTAT_g[2];/* '<S28>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator5_DSTAT_n;/* '<S26>/Discrete-Time Integrator5' */
  real32_T DiscreteTimeIntegrator1_DSTAT_n[3];/* '<S56>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE[600];          /* '<S43>/Delay' */
  real32_T DiscreteFIRFilter_states[29];/* '<S45>/Discrete FIR Filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];/* '<S56>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_n[3];/* '<S194>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_cu[3];/* '<S195>/Discrete-Time Integrator' */
  real32_T h_delay_DSTATE[75];         /* '<S271>/h_delay' */
  real32_T vd_delay_DSTATE[50];        /* '<S271>/vd_delay' */
  real32_T x_delay_DSTATE[5];          /* '<S262>/x_delay' */
  real32_T x_delay_DSTATE_k[75];       /* '<S240>/x_delay' */
  real32_T x_delay1_DSTATE[75];        /* '<S240>/x_delay1' */
  real32_T vn_delay_DSTATE[50];        /* '<S240>/vn_delay' */
  real32_T vn_delay1_DSTATE[50];       /* '<S240>/vn_delay1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S63>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_jh;/* '<S63>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_m;/* '<S64>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_cn;/* '<S64>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l[3];/* '<S62>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTAT_or[3];/* '<S62>/Discrete-Time Integrator' */
  int32_T UnitDelay_DSTATE;            /* '<S163>/Unit Delay' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S45>/Discrete FIR Filter' */
  uint32_T Output_DSTATE;              /* '<S84>/Output' */
  uint32_T DelayInput1_DSTATE;         /* '<S181>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S174>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_h;       /* '<S187>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S176>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_i;       /* '<S171>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S166>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_l;       /* '<S218>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_nz;/* '<S216>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_c;       /* '<S222>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTATE_k;/* '<S219>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_g;       /* '<S153>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_ev;/* '<S145>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_n;       /* '<S201>/Delay Input1' */
  uint32_T DiscreteTimeIntegrator_DSTAT_lg;/* '<S197>/Discrete-Time Integrator' */
  uint32_T DelayInput1_DSTATE_d;       /* '<S268>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_lg;      /* '<S259>/Delay Input1' */
  uint32_T DelayInput1_DSTATE_d0;      /* '<S237>/Delay Input1' */
  real32_T Memory1_PreviousInput[3];   /* '<S5>/Memory1' */
  real32_T Memory_9_PreviousInput;     /* '<S4>/Memory' */
  real32_T Memory_10_PreviousInput;    /* '<S4>/Memory' */
  real32_T Memory_PreviousInput[6];    /* '<S246>/Memory' */
  real32_T Memory_11_PreviousInput;    /* '<S4>/Memory' */
  real32_T Memory_PreviousInput_p[3];  /* '<S276>/Memory' */
  real32_T PrevY;                      /* '<S67>/Rate Limiter' */
  real32_T Memory_PreviousInput_b;     /* '<S273>/Memory' */
  real32_T Memory_PreviousInput_e[3];  /* '<S269>/Memory' */
  real32_T Memory_PreviousInput_j;     /* '<S264>/Memory' */
  real32_T Memory_PreviousInput_i[3];  /* '<S260>/Memory' */
  real32_T Memory_PreviousInput_d[2];  /* '<S243>/Memory' */
  real32_T Memory_PreviousInput_h[6];  /* '<S238>/Memory' */
  real32_T Memory_PreviousInput_f;     /* '<S146>/Memory' */
  real32_T Memory1_PreviousInput_a;    /* '<S146>/Memory1' */
  uint32_T Memory2_PreviousInput;      /* '<S145>/Memory2' */
  uint32_T Memory2_PreviousInput_b;    /* '<S146>/Memory2' */
  uint16_T Delay_DSTATE_i;             /* '<S31>/Delay' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S34>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S298>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S305>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S296>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dp;     /* '<S303>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dy;     /* '<S75>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S58>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_b;      /* '<S102>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_of;     /* '<S107>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o1;     /* '<S112>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S117>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ng;     /* '<S122>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_cr;     /* '<S127>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_dt;     /* '<S132>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ib;     /* '<S275>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_fw;     /* '<S266>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_gn;     /* '<S245>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S72>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S96>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S93>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S92>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_or;/* '<S94>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ow;/* '<S95>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_mt;/* '<S97>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S98>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S62>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S62>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S195>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S72>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_k;/* '<S194>/Discrete-Time Integrator1' */
  uint8_T Memory_PreviousInput_ph;     /* '<S219>/Memory' */
  uint8_T Memory_PreviousInput_l;      /* '<S71>/Memory' */
  uint8_T DiscreteTimeIntegrator1_IC_LO_o;/* '<S56>/Discrete-Time Integrator1' */
  uint8_T icLoad;                      /* '<S271>/h_delay' */
  uint8_T icLoad_f;                    /* '<S271>/vd_delay' */
  uint8_T icLoad_a;                    /* '<S262>/x_delay' */
  uint8_T icLoad_o;                    /* '<S240>/x_delay' */
  uint8_T icLoad_i;                    /* '<S240>/x_delay1' */
  uint8_T icLoad_m;                    /* '<S240>/vn_delay' */
  uint8_T icLoad_j;                    /* '<S240>/vn_delay1' */
  uint8_T DiscreteTimeIntegrator_IC_LOA_k;/* '<S63>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LO_kr;/* '<S64>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_IC_L_oi;/* '<S62>/Discrete-Time Integrator1' */
  boolean_T Memory2_PreviousInput_l;   /* '<S5>/Memory2' */
  boolean_T Relay2_Mode;               /* '<S10>/Relay2' */
  boolean_T Memory_PreviousInput_dc;   /* '<S96>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S93>/Memory' */
  boolean_T Memory_PreviousInput_ej;   /* '<S92>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S94>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S95>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S97>/Memory' */
  boolean_T Memory_PreviousInput_hx;   /* '<S98>/Memory' */
  boolean_T Relay_Mode;                /* '<S57>/Relay' */
  boolean_T Relay1_Mode;               /* '<S68>/Relay1' */
  boolean_T Reference_and_Gradient_MODE;/* '<S143>/Reference_and_Gradient' */
  boolean_T VIsionFlow_Observer_MODE;  /* '<S44>/VIsionFlow_Observer' */
  boolean_T GPS_Observer_MODE;         /* '<S44>/GPS_Observer' */
} D_Work_INS_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState h_delay_Reset_ZCE;        /* '<S271>/h_delay' */
  ZCSigState vd_delay_Reset_ZCE;       /* '<S271>/vd_delay' */
  ZCSigState x_delay_Reset_ZCE;        /* '<S262>/x_delay' */
  ZCSigState x_delay_Reset_ZCE_b;      /* '<S240>/x_delay' */
  ZCSigState x_delay1_Reset_ZCE;       /* '<S240>/x_delay1' */
  ZCSigState vn_delay_Reset_ZCE;       /* '<S240>/vn_delay' */
  ZCSigState vn_delay1_Reset_ZCE;      /* '<S240>/vn_delay1' */
  ZCSigState WGS_Derivative_Trig_ZCE;  /* '<S137>/WGS_Derivative' */
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
                                        * Referenced by: '<S232>/Constant'
                                        */
  real_T wmm_lookup_res;               /* Mask Parameter: wmm_lookup_res
                                        * Referenced by:
                                        *   '<S206>/Gain'
                                        *   '<S206>/Gain6'
                                        */
  real_T Zero_Value_Exclusion_thr;     /* Mask Parameter: Zero_Value_Exclusion_thr
                                        * Referenced by: '<S233>/Saturation'
                                        */
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S170>/Constant'
                                        */
  real32_T IMU1_Valid_Check_acc_max;   /* Mask Parameter: IMU1_Valid_Check_acc_max
                                        * Referenced by: '<S182>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_max;   /* Mask Parameter: IMU2_Valid_Check_acc_max
                                        * Referenced by: '<S188>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_acc_min;   /* Mask Parameter: IMU1_Valid_Check_acc_min
                                        * Referenced by: '<S182>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_acc_min;   /* Mask Parameter: IMU2_Valid_Check_acc_min
                                        * Referenced by: '<S188>/Lower Limit'
                                        */
  real32_T CompareToConstant_const_p;  /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S29>/Constant'
                                        */
  real32_T CompareToConstant_const_f;  /* Mask Parameter: CompareToConstant_const_f
                                        * Referenced by: '<S220>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S105>/Constant'
                                        */
  real32_T CompareToConstant1_const_p; /* Mask Parameter: CompareToConstant1_const_p
                                        * Referenced by: '<S100>/Constant'
                                        */
  real32_T CompareToConstant1_const_g; /* Mask Parameter: CompareToConstant1_const_g
                                        * Referenced by: '<S110>/Constant'
                                        */
  real32_T CompareToConstant1_const_i; /* Mask Parameter: CompareToConstant1_const_i
                                        * Referenced by: '<S115>/Constant'
                                        */
  real32_T CompareToConstant1_const_d; /* Mask Parameter: CompareToConstant1_const_d
                                        * Referenced by: '<S125>/Constant'
                                        */
  real32_T CompareToConstant1_const_f; /* Mask Parameter: CompareToConstant1_const_f
                                        * Referenced by: '<S130>/Constant'
                                        */
  real32_T CompareToConstant_const_g;  /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T CompareToConstant_const_n;  /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S65>/Constant'
                                        */
  real32_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S101>/Constant'
                                        */
  real32_T CompareToConstant2_const_j; /* Mask Parameter: CompareToConstant2_const_j
                                        * Referenced by: '<S106>/Constant'
                                        */
  real32_T CompareToConstant2_const_e; /* Mask Parameter: CompareToConstant2_const_e
                                        * Referenced by: '<S111>/Constant'
                                        */
  real32_T CompareToConstant2_const_m; /* Mask Parameter: CompareToConstant2_const_m
                                        * Referenced by: '<S116>/Constant'
                                        */
  real32_T CompareToConstant2_const_k; /* Mask Parameter: CompareToConstant2_const_k
                                        * Referenced by: '<S126>/Constant'
                                        */
  real32_T CompareToConstant2_const_g; /* Mask Parameter: CompareToConstant2_const_g
                                        * Referenced by: '<S131>/Constant'
                                        */
  real32_T IMU1_Valid_Check_gyr_max;   /* Mask Parameter: IMU1_Valid_Check_gyr_max
                                        * Referenced by: '<S183>/Upper Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_max;   /* Mask Parameter: IMU2_Valid_Check_gyr_max
                                        * Referenced by: '<S189>/Upper Limit'
                                        */
  real32_T IMU1_Valid_Check_gyr_min;   /* Mask Parameter: IMU1_Valid_Check_gyr_min
                                        * Referenced by: '<S183>/Lower Limit'
                                        */
  real32_T IMU2_Valid_Check_gyr_min;   /* Mask Parameter: IMU2_Valid_Check_gyr_min
                                        * Referenced by: '<S189>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit;      /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S30>/Lower Limit'
                                        */
  real32_T IntervalTest_lowlimit_d;    /* Mask Parameter: IntervalTest_lowlimit_d
                                        * Referenced by: '<S223>/Lower Limit'
                                        */
  real32_T Mag_Valid_Check_mag_max;    /* Mask Parameter: Mag_Valid_Check_mag_max
                                        * Referenced by: '<S202>/Upper Limit'
                                        */
  real32_T Mag_Valid_Check_mag_min;    /* Mask Parameter: Mag_Valid_Check_mag_min
                                        * Referenced by: '<S202>/Lower Limit'
                                        */
  real32_T Relative_Height_pressure_max;/* Mask Parameter: Relative_Height_pressure_max
                                         * Referenced by: '<S154>/Upper Limit'
                                         */
  real32_T Relative_Height_pressure_min;/* Mask Parameter: Relative_Height_pressure_min
                                         * Referenced by: '<S154>/Lower Limit'
                                         */
  real32_T Relative_Height_temp_max;   /* Mask Parameter: Relative_Height_temp_max
                                        * Referenced by: '<S155>/Upper Limit'
                                        */
  real32_T Relative_Height_temp_min;   /* Mask Parameter: Relative_Height_temp_min
                                        * Referenced by: '<S155>/Lower Limit'
                                        */
  real32_T valid_check5_time_out;      /* Mask Parameter: valid_check5_time_out
                                        * Referenced by: '<S119>/Constant'
                                        */
  real32_T valid_check2_time_out;      /* Mask Parameter: valid_check2_time_out
                                        * Referenced by: '<S104>/Constant'
                                        */
  real32_T valid_check1_time_out;      /* Mask Parameter: valid_check1_time_out
                                        * Referenced by: '<S99>/Constant'
                                        */
  real32_T valid_check3_time_out;      /* Mask Parameter: valid_check3_time_out
                                        * Referenced by: '<S109>/Constant'
                                        */
  real32_T valid_check4_time_out;      /* Mask Parameter: valid_check4_time_out
                                        * Referenced by: '<S114>/Constant'
                                        */
  real32_T valid_check6_time_out;      /* Mask Parameter: valid_check6_time_out
                                        * Referenced by: '<S124>/Constant'
                                        */
  real32_T valid_check7_time_out;      /* Mask Parameter: valid_check7_time_out
                                        * Referenced by: '<S129>/Constant'
                                        */
  real32_T IntervalTest_uplimit;       /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S30>/Upper Limit'
                                        */
  real32_T IntervalTest_uplimit_a;     /* Mask Parameter: IntervalTest_uplimit_a
                                        * Referenced by: '<S223>/Upper Limit'
                                        */
  uint32_T CompareToConstant2_const_a; /* Mask Parameter: CompareToConstant2_const_a
                                        * Referenced by: '<S169>/Constant'
                                        */
  uint32_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S162>/Constant'
                                        */
  uint32_T CompareToConstant4_const_k; /* Mask Parameter: CompareToConstant4_const_k
                                        * Referenced by: '<S217>/Constant'
                                        */
  uint32_T CompareToConstant4_const_h; /* Mask Parameter: CompareToConstant4_const_h
                                        * Referenced by: '<S221>/Constant'
                                        */
  uint32_T CompareToConstant_const_pt; /* Mask Parameter: CompareToConstant_const_pt
                                        * Referenced by: '<S147>/Constant'
                                        */
  uint32_T CompareToConstant4_const_i; /* Mask Parameter: CompareToConstant4_const_i
                                        * Referenced by: '<S151>/Constant'
                                        */
  uint32_T CompareToConstant_const_d;  /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S167>/Constant'
                                        */
  uint32_T Relative_Height_s_first;    /* Mask Parameter: Relative_Height_s_first
                                        * Referenced by: '<S148>/Constant'
                                        */
  uint32_T Relative_Height_s_last;     /* Mask Parameter: Relative_Height_s_last
                                        * Referenced by:
                                        *   '<S149>/Constant'
                                        *   '<S150>/Constant'
                                        */
  uint32_T IMU1_Valid_Check_timeout;   /* Mask Parameter: IMU1_Valid_Check_timeout
                                        * Referenced by: '<S180>/Constant'
                                        */
  uint32_T IMU2_Valid_Check_timeout;   /* Mask Parameter: IMU2_Valid_Check_timeout
                                        * Referenced by: '<S186>/Constant'
                                        */
  uint32_T Mag_Valid_Check_timeout;    /* Mask Parameter: Mag_Valid_Check_timeout
                                        * Referenced by: '<S200>/Constant'
                                        */
  uint32_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S237>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_m;       /* Mask Parameter: DetectChange_vinit_m
                                        * Referenced by: '<S259>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_h;       /* Mask Parameter: DetectChange_vinit_h
                                        * Referenced by: '<S268>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_md;      /* Mask Parameter: DetectChange_vinit_md
                                        * Referenced by: '<S181>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_j;       /* Mask Parameter: DetectChange_vinit_j
                                        * Referenced by: '<S187>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_e;       /* Mask Parameter: DetectChange_vinit_e
                                        * Referenced by: '<S171>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_i;       /* Mask Parameter: DetectChange_vinit_i
                                        * Referenced by: '<S218>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_k;       /* Mask Parameter: DetectChange_vinit_k
                                        * Referenced by: '<S222>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_d;       /* Mask Parameter: DetectChange_vinit_d
                                        * Referenced by: '<S153>/Delay Input1'
                                        */
  uint32_T DetectChange_vinit_l;       /* Mask Parameter: DetectChange_vinit_l
                                        * Referenced by: '<S201>/Delay Input1'
                                        */
  int16_T wmm_lookup_wmm_declination[629];/* Mask Parameter: wmm_lookup_wmm_declination
                                           * Referenced by: '<S206>/Declination Lookup'
                                           */
  uint16_T Initwith50validsamples_const;/* Mask Parameter: Initwith50validsamples_const
                                         * Referenced by: '<S35>/Constant'
                                         */
  boolean_T CompareToConstant1_const_j;/* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S120>/Constant'
                                        */
  boolean_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S203>/Constant'
                                        */
  boolean_T CompareToConstant2_const_i;/* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S121>/Constant'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S245>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_c;    /* Mask Parameter: DetectIncrease_vinit_c
                                        * Referenced by: '<S266>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_j;    /* Mask Parameter: DetectIncrease_vinit_j
                                        * Referenced by: '<S275>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S34>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_m;/* Mask Parameter: DetectRisePositive_vinit_m
                                        * Referenced by: '<S298>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S305>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_h;/* Mask Parameter: DetectRisePositive_vinit_h
                                        * Referenced by: '<S296>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit_a;/* Mask Parameter: DetectRisePositive3_vinit_a
                                         * Referenced by: '<S303>/Delay Input1'
                                         */
  boolean_T DetectIncrease_vinit_d;    /* Mask Parameter: DetectIncrease_vinit_d
                                        * Referenced by: '<S75>/Delay Input1'
                                        */
  boolean_T DetectIncrease_vinit_b;    /* Mask Parameter: DetectIncrease_vinit_b
                                        * Referenced by: '<S58>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_a;/* Mask Parameter: DetectRisePositive_vinit_a
                                        * Referenced by: '<S102>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_k;/* Mask Parameter: DetectRisePositive_vinit_k
                                        * Referenced by: '<S107>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_n;/* Mask Parameter: DetectRisePositive_vinit_n
                                        * Referenced by: '<S112>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_d;/* Mask Parameter: DetectRisePositive_vinit_d
                                        * Referenced by: '<S117>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_aw;/* Mask Parameter: DetectRisePositive_vinit_aw
                                         * Referenced by: '<S122>/Delay Input1'
                                         */
  boolean_T DetectRisePositive_vinit_b;/* Mask Parameter: DetectRisePositive_vinit_b
                                        * Referenced by: '<S127>/Delay Input1'
                                        */
  boolean_T DetectRisePositive_vinit_c;/* Mask Parameter: DetectRisePositive_vinit_c
                                        * Referenced by: '<S132>/Delay Input1'
                                        */
  int8_T wmm_lookup_wmm_inclination[629];/* Mask Parameter: wmm_lookup_wmm_inclination
                                          * Referenced by: '<S206>/Inclination Lookup'
                                          */
  uint8_T CompareToConstant1_const_n;  /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S168>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S157>/Constant'
                                        */
  uint8_T CompareToConstant2_const_b;  /* Mask Parameter: CompareToConstant2_const_b
                                        * Referenced by: '<S161>/Constant'
                                        */
  uint8_T CompareToConstant_const_i;   /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S156>/Constant'
                                        */
  uint8_T wmm_lookup_wmm_magnitude[629];/* Mask Parameter: wmm_lookup_wmm_magnitude
                                         * Referenced by: '<S206>/Magnitude Lookup'
                                         */
  real_T lon_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S160>/lon_0_rad'
                                        */
  real_T lat_0_rad_Y0;                 /* Expression: 0
                                        * Referenced by: '<S160>/lat_0_rad'
                                        */
  real_T dx_dlat_Y0;                   /* Expression: 1
                                        * Referenced by: '<S160>/dx_dlat'
                                        */
  real_T dy_dlon_Y0;                   /* Expression: 1
                                        * Referenced by: '<S160>/dy_dlon'
                                        */
  real_T dz_dh_Y0;                     /* Expression: 1
                                        * Referenced by: '<S160>/dz_dh'
                                        */
  real_T Scalefactor_Gain;             /* Expression: 1
                                        * Referenced by: '<S160>/Scalefactor'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S172>/constant1'
                                        */
  real_T Scalefactor1_Gain;            /* Expression: 1
                                        * Referenced by: '<S160>/Scalefactor1'
                                        */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S172>/constant2'
                                        */
  real_T f_Value;                      /* Expression: 1/298.257
                                        * Referenced by: '<S172>/f'
                                        */
  real_T constant_Value;               /* Expression: 2
                                        * Referenced by: '<S172>/constant'
                                        */
  real_T a_Value;                      /* Expression: 6378137
                                        * Referenced by: '<S172>/a'
                                        */
  real_T a1_Value;                     /* Expression: 1
                                        * Referenced by: '<S172>/a1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S233>/Constant'
                                        */
  real_T Constant_Value_i[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S231>/Constant'
                                        */
  real_T memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S302>/memory3'
                                        */
  real_T memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S302>/memory2'
                                        */
  real_T memory2_InitialCondition_e;   /* Expression: 0
                                        * Referenced by: '<S301>/memory2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10e7
                                        * Referenced by: '<S233>/Saturation'
                                        */
  int32_T UnitDelay_InitialCondition;  /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<S163>/Unit Delay'
                                        */
  int32_T offset_lat_Value;            /* Computed Parameter: offset_lat_Value
                                        * Referenced by: '<S206>/offset_lat'
                                        */
  int32_T Saturation1_UpperSat;        /* Computed Parameter: Saturation1_UpperSat
                                        * Referenced by: '<S206>/Saturation1'
                                        */
  int32_T Saturation1_LowerSat;        /* Computed Parameter: Saturation1_LowerSat
                                        * Referenced by: '<S206>/Saturation1'
                                        */
  int32_T offset_lon_Value;            /* Computed Parameter: offset_lon_Value
                                        * Referenced by: '<S206>/offset_lon'
                                        */
  int32_T Saturation2_UpperSat;        /* Computed Parameter: Saturation2_UpperSat
                                        * Referenced by: '<S206>/Saturation2'
                                        */
  int32_T Saturation2_LowerSat;        /* Computed Parameter: Saturation2_LowerSat
                                        * Referenced by: '<S206>/Saturation2'
                                        */
  int32_T Saturation_UpperSat_a;       /* Computed Parameter: Saturation_UpperSat_a
                                        * Referenced by: '<S163>/Saturation'
                                        */
  int32_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S163>/Saturation'
                                        */
  int32_T Scalefactor3_Gain;           /* Computed Parameter: Scalefactor3_Gain
                                        * Referenced by: '<S159>/Scalefactor3'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S159>/Gain'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S159>/Gain1'
                                        */
  int32_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S159>/Gain2'
                                        */
  int32_T Scalefactor1_Gain_d;         /* Computed Parameter: Scalefactor1_Gain_d
                                        * Referenced by: '<S159>/Scalefactor1'
                                        */
  int32_T Scalefactor2_Gain;           /* Computed Parameter: Scalefactor2_Gain
                                        * Referenced by: '<S159>/Scalefactor2'
                                        */
  real32_T Constant_Value_i1;          /* Computed Parameter: Constant_Value_i1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real32_T Protection_Value;           /* Computed Parameter: Protection_Value
                                        * Referenced by: '<S18>/Protection'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T Gain1_Gain_l;               /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real32_T Gain2_Gain_j;               /* Computed Parameter: Gain2_Gain_j
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S19>/Constant'
                                        */
  real32_T Protection_Value_j;         /* Computed Parameter: Protection_Value_j
                                        * Referenced by: '<S19>/Protection'
                                        */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S19>/Gain'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real32_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real32_T Gain3_Gain_j;               /* Computed Parameter: Gain3_Gain_j
                                        * Referenced by: '<S19>/Gain3'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S20>/Constant'
                                        */
  real32_T Protection_Value_i;         /* Computed Parameter: Protection_Value_i
                                        * Referenced by: '<S20>/Protection'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S20>/Gain4'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real32_T Gain2_Gain_l;               /* Computed Parameter: Gain2_Gain_l
                                        * Referenced by: '<S20>/Gain2'
                                        */
  real32_T Gain3_Gain_c;               /* Computed Parameter: Gain3_Gain_c
                                        * Referenced by: '<S20>/Gain3'
                                        */
  real32_T Constant_Value_i0;          /* Computed Parameter: Constant_Value_i0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real32_T Protection_Value_a;         /* Computed Parameter: Protection_Value_a
                                        * Referenced by: '<S21>/Protection'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S21>/Gain'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real32_T Gain2_Gain_ju;              /* Computed Parameter: Gain2_Gain_ju
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real32_T Gain3_Gain_h;               /* Computed Parameter: Gain3_Gain_h
                                        * Referenced by: '<S21>/Gain3'
                                        */
  real32_T quaternion_0_Y0[4];         /* Computed Parameter: quaternion_0_Y0
                                        * Referenced by: '<S8>/quaternion_0'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real32_T Constant2_Value_m;          /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real32_T Constant2_Value_g;          /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S53>/Constant'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T GPS_acc_O_mPs2_Y0;          /* Computed Parameter: GPS_acc_O_mPs2_Y0
                                        * Referenced by: '<S59>/GPS_acc_O_mPs2'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S62>/Discrete-Time Integrator1'
                                            */
  real32_T Gain2_Gain_a;               /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S62>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S62>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  real32_T Gain3_Gain_p;               /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S62>/Gain3'
                                        */
  real32_T OptFlow_acc_O_mPs2_Y0;      /* Computed Parameter: OptFlow_acc_O_mPs2_Y0
                                        * Referenced by: '<S61>/OptFlow_acc_O_mPs2'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S61>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                                            * Referenced by: '<S63>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC; /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<S63>/Discrete-Time Integrator1'
                                        */
  real32_T Gain2_Gain_b;               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S63>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                            * Referenced by: '<S63>/Discrete-Time Integrator'
                                            */
  real32_T Gain3_Gain_i;               /* Computed Parameter: Gain3_Gain_i
                                        * Referenced by: '<S63>/Gain3'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_l;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_l
                                            * Referenced by: '<S64>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC_l;/* Computed Parameter: DiscreteTimeIntegrator1_IC_l
                                         * Referenced by: '<S64>/Discrete-Time Integrator1'
                                         */
  real32_T Gain2_Gain_l3;              /* Computed Parameter: Gain2_Gain_l3
                                        * Referenced by: '<S64>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                            * Referenced by: '<S64>/Discrete-Time Integrator'
                                            */
  real32_T Gain3_Gain_ih;              /* Computed Parameter: Gain3_Gain_ih
                                        * Referenced by: '<S64>/Gain3'
                                        */
  real32_T p_ref_Y0;                   /* Computed Parameter: p_ref_Y0
                                        * Referenced by: '<S146>/p_ref'
                                        */
  real32_T dh_dp_Y0;                   /* Computed Parameter: dh_dp_Y0
                                        * Referenced by: '<S146>/dh_dp'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S146>/Constant2'
                                        */
  real32_T Memory_InitialCondition;    /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<S146>/Memory'
                                        */
  real32_T Memory1_InitialCondition;   /* Computed Parameter: Memory1_InitialCondition
                                        * Referenced by: '<S146>/Memory1'
                                        */
  real32_T Saturation_UpperSat_m;      /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S146>/Saturation'
                                        */
  real32_T Saturation_LowerSat_h;      /* Computed Parameter: Saturation_LowerSat_h
                                        * Referenced by: '<S146>/Saturation'
                                        */
  real32_T g_M_d_R_Gain;               /* Computed Parameter: g_M_d_R_Gain
                                        * Referenced by: '<S146>/g_M_d_R'
                                        */
  real32_T default_mag_quality_Value;  /* Computed Parameter: default_mag_quality_Value
                                        * Referenced by: '<S204>/default_mag_quality'
                                        */
  real32_T Nominal_Magnitude_Value;    /* Computed Parameter: Nominal_Magnitude_Value
                                        * Referenced by: '<S209>/Nominal_Magnitude'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S209>/Constant1'
                                        */
  real32_T Saturation_UpperSat_g;      /* Computed Parameter: Saturation_UpperSat_g
                                        * Referenced by: '<S209>/Saturation'
                                        */
  real32_T Saturation_LowerSat_p;      /* Computed Parameter: Saturation_LowerSat_p
                                        * Referenced by: '<S209>/Saturation'
                                        */
  real32_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S208>/Gain2'
                                        */
  real32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S208>/Constant2'
                                        */
  real32_T Saturation_UpperSat_gg;     /* Computed Parameter: Saturation_UpperSat_gg
                                        * Referenced by: '<S208>/Saturation'
                                        */
  real32_T Saturation_LowerSat_a;      /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S208>/Saturation'
                                        */
  real32_T Constant_Value_g2;          /* Computed Parameter: Constant_Value_g2
                                        * Referenced by: '<S215>/Constant'
                                        */
  real32_T Constant_Value_dt;          /* Computed Parameter: Constant_Value_dt
                                        * Referenced by: '<S230>/Constant'
                                        */
  real32_T Constant_Value_aq;          /* Computed Parameter: Constant_Value_aq
                                        * Referenced by: '<S224>/Constant'
                                        */
  real32_T Gain1_Gain_e;               /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S241>/Gain1'
                                        */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S241>/Gain'
                                        */
  real32_T Gain2_Gain_gd;              /* Computed Parameter: Gain2_Gain_gd
                                        * Referenced by: '<S241>/Gain2'
                                        */
  real32_T X_Next_Y0;                  /* Computed Parameter: X_Next_Y0
                                        * Referenced by: '<S236>/X_Next'
                                        */
  real32_T Memory_InitialCondition_l[2];/* Computed Parameter: Memory_InitialCondition_l
                                         * Referenced by: '<S243>/Memory'
                                         */
  real32_T Memory_InitialCondition_o;  /* Computed Parameter: Memory_InitialCondition_o
                                        * Referenced by: '<S238>/Memory'
                                        */
  real32_T Gain3_Gain_o;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S238>/Gain3'
                                        */
  real32_T Constant_Value_b[2];        /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S248>/Constant'
                                        */
  real32_T X_0_Y0;                     /* Computed Parameter: X_0_Y0
                                        * Referenced by: '<S251>/X_0'
                                        */
  real32_T Gain1_Gain_en;              /* Computed Parameter: Gain1_Gain_en
                                        * Referenced by: '<S263>/Gain1'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S263>/Gain'
                                        */
  real32_T X_Next_Y0_m;                /* Computed Parameter: X_Next_Y0_m
                                        * Referenced by: '<S258>/X_Next'
                                        */
  real32_T Memory_InitialCondition_m;  /* Computed Parameter: Memory_InitialCondition_m
                                        * Referenced by: '<S264>/Memory'
                                        */
  real32_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S263>/Gain2'
                                        */
  real32_T Memory_InitialCondition_j;  /* Computed Parameter: Memory_InitialCondition_j
                                        * Referenced by: '<S260>/Memory'
                                        */
  real32_T Gain_Gain_pl;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S260>/Gain'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S272>/Gain1'
                                        */
  real32_T Gain_Gain_cc;               /* Computed Parameter: Gain_Gain_cc
                                        * Referenced by: '<S272>/Gain'
                                        */
  real32_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S272>/Gain2'
                                        */
  real32_T X_Next_Y0_i;                /* Computed Parameter: X_Next_Y0_i
                                        * Referenced by: '<S267>/X_Next'
                                        */
  real32_T Memory_InitialCondition_p;  /* Computed Parameter: Memory_InitialCondition_p
                                        * Referenced by: '<S273>/Memory'
                                        */
  real32_T Memory_InitialCondition_c;  /* Computed Parameter: Memory_InitialCondition_c
                                        * Referenced by: '<S269>/Memory'
                                        */
  real32_T Gain3_Gain_k;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S269>/Gain3'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S278>/Constant'
                                        */
  real32_T Constant_Value_aa;          /* Computed Parameter: Constant_Value_aa
                                        * Referenced by: '<S282>/Constant'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S284>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_p;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_p
                                            * Referenced by: '<S195>/Discrete-Time Integrator1'
                                            */
  real32_T Memory1_InitialCondition_p; /* Computed Parameter: Memory1_InitialCondition_p
                                        * Referenced by: '<S5>/Memory1'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_ji;/* Computed Parameter: DiscreteTimeIntegrator_gainv_ji
                                            * Referenced by: '<S72>/Discrete-Time Integrator'
                                            */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S77>/Gain'
                                        */
  real32_T Gain1_Gain_kf;              /* Computed Parameter: Gain1_Gain_kf
                                        * Referenced by: '<S77>/Gain1'
                                        */
  real32_T Gain2_Gain_oj;              /* Computed Parameter: Gain2_Gain_oj
                                        * Referenced by: '<S77>/Gain2'
                                        */
  real32_T Gain3_Gain_d;               /* Computed Parameter: Gain3_Gain_d
                                        * Referenced by: '<S77>/Gain3'
                                        */
  real32_T Gain4_Gain_o;               /* Computed Parameter: Gain4_Gain_o
                                        * Referenced by: '<S77>/Gain4'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S77>/Gain5'
                                        */
  real32_T Gain5_Gain_d;               /* Computed Parameter: Gain5_Gain_d
                                        * Referenced by: '<S81>/Gain5'
                                        */
  real32_T Saturation1_UpperSat_o;     /* Computed Parameter: Saturation1_UpperSat_o
                                        * Referenced by: '<S81>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_b;     /* Computed Parameter: Saturation1_LowerSat_b
                                        * Referenced by: '<S81>/Saturation1'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S83>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S73>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S73>/Discrete-Time Integrator2'
                                        */
  real32_T DiscreteTimeIntegrator2_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                                            * Referenced by: '<S73>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                                            * Referenced by: '<S73>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator1_gainv_i;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_i
                                            * Referenced by: '<S194>/Discrete-Time Integrator1'
                                            */
  real32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S165>/Constant7'
                                        */
  real32_T Gain3_Gain_l;               /* Computed Parameter: Gain3_Gain_l
                                        * Referenced by: '<S165>/Gain3'
                                        */
  real32_T Saturation_UpperSat_l;      /* Computed Parameter: Saturation_UpperSat_l
                                        * Referenced by: '<S158>/Saturation'
                                        */
  real32_T Saturation_LowerSat_k;      /* Computed Parameter: Saturation_LowerSat_k
                                        * Referenced by: '<S158>/Saturation'
                                        */
  real32_T Constant_Value_ab;          /* Computed Parameter: Constant_Value_ab
                                        * Referenced by: '<S310>/Constant'
                                        */
  real32_T Constant1_Value_g;          /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S164>/Constant1'
                                        */
  real32_T Gain2_Gain_p;               /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S164>/Gain2'
                                        */
  real32_T Saturation1_UpperSat_m;     /* Computed Parameter: Saturation1_UpperSat_m
                                        * Referenced by: '<S158>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_d;     /* Computed Parameter: Saturation1_LowerSat_d
                                        * Referenced by: '<S158>/Saturation1'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S309>/Constant'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S322>/Constant'
                                        */
  real32_T Memory_9_InitialCondition;  /* Computed Parameter: Memory_9_InitialCondition
                                        * Referenced by: '<S4>/Memory'
                                        */
  real32_T Memory_10_InitialCondition; /* Computed Parameter: Memory_10_InitialCondition
                                        * Referenced by: '<S4>/Memory'
                                        */
  real32_T Gain_Gain_i;                /* Expression: single(-1)
                                        * Referenced by: '<S82>/Gain'
                                        */
  real32_T Constant1_Value_gl;         /* Expression: single(0)
                                        * Referenced by: '<S82>/Constant1'
                                        */
  real32_T Constant_Value_ev;          /* Expression: single(1)
                                        * Referenced by: '<S82>/Constant'
                                        */
  real32_T Constant_Value_bg;          /* Computed Parameter: Constant_Value_bg
                                        * Referenced by: '<S140>/Constant'
                                        */
  real32_T Memory_InitialCondition_e[6];/* Computed Parameter: Memory_InitialCondition_e
                                         * Referenced by: '<S246>/Memory'
                                         */
  real32_T Constant_Value_l[2];        /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S247>/Constant'
                                        */
  real32_T Gain_Gain_ic;               /* Expression: INS_CONST.dt
                                        * Referenced by: '<S247>/Gain'
                                        */
  real32_T Constant_Value_ek;          /* Computed Parameter: Constant_Value_ek
                                        * Referenced by: '<S315>/Constant'
                                        */
  real32_T Constant_Value_ao;          /* Computed Parameter: Constant_Value_ao
                                        * Referenced by: '<S314>/Constant'
                                        */
  real32_T Saturation_UpperSat_c;      /* Computed Parameter: Saturation_UpperSat_c
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real32_T Saturation_LowerSat_pk;     /* Computed Parameter: Saturation_LowerSat_pk
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S316>/Constant'
                                        */
  real32_T Constant_Value_be;          /* Computed Parameter: Constant_Value_be
                                        * Referenced by: '<S323>/Constant'
                                        */
  real32_T Memory_11_InitialCondition; /* Computed Parameter: Memory_11_InitialCondition
                                        * Referenced by: '<S4>/Memory'
                                        */
  real32_T Saturation1_UpperSat_i;     /* Computed Parameter: Saturation1_UpperSat_i
                                        * Referenced by: '<S308>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_j;     /* Computed Parameter: Saturation1_LowerSat_j
                                        * Referenced by: '<S308>/Saturation1'
                                        */
  real32_T Constant_Value_iw;          /* Computed Parameter: Constant_Value_iw
                                        * Referenced by: '<S318>/Constant'
                                        */
  real32_T Constant_Value_h4;          /* Computed Parameter: Constant_Value_h4
                                        * Referenced by: '<S317>/Constant'
                                        */
  real32_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S278>/Merge'
                                        */
  real32_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S278>/Merge1'
                                        */
  real32_T Memory_InitialCondition_mn[3];/* Computed Parameter: Memory_InitialCondition_mn
                                          * Referenced by: '<S276>/Memory'
                                          */
  real32_T Gain1_Gain_kw;              /* Computed Parameter: Gain1_Gain_kw
                                        * Referenced by: '<S277>/Gain1'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S277>/Constant1'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S277>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Expression: INS_CONST.dt
                                        * Referenced by: '<S277>/Gain'
                                        */
  real32_T Constant_Value_ny;          /* Computed Parameter: Constant_Value_ny
                                        * Referenced by: '<S87>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator5_gainval;/* Computed Parameter: DiscreteTimeIntegrator5_gainval
                                            * Referenced by: '<S27>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC; /* Computed Parameter: DiscreteTimeIntegrator5_IC
                                        * Referenced by: '<S27>/Discrete-Time Integrator5'
                                        */
  real32_T Relay2_OnVal;               /* Computed Parameter: Relay2_OnVal
                                        * Referenced by: '<S10>/Relay2'
                                        */
  real32_T Relay2_OffVal;              /* Computed Parameter: Relay2_OffVal
                                        * Referenced by: '<S10>/Relay2'
                                        */
  real32_T Relay2_YOn;                 /* Computed Parameter: Relay2_YOn
                                        * Referenced by: '<S10>/Relay2'
                                        */
  real32_T Relay2_YOff;                /* Computed Parameter: Relay2_YOff
                                        * Referenced by: '<S10>/Relay2'
                                        */
  real32_T Gain10_Gain;                /* Computed Parameter: Gain10_Gain
                                        * Referenced by: '<S88>/Gain10'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                            * Referenced by: '<S96>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_i;/* Computed Parameter: DiscreteTimeIntegrator_IC_i
                                        * Referenced by: '<S96>/Discrete-Time Integrator'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S214>/Constant3'
                                        */
  real32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S214>/Gain'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S214>/Constant4'
                                        */
  real32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S214>/Constant2'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S214>/Constant1'
                                        */
  real32_T Constant_Value_dm;          /* Computed Parameter: Constant_Value_dm
                                        * Referenced by: '<S214>/Constant'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S205>/Constant1'
                                        */
  real32_T Gauss_to_uT_Gain;           /* Computed Parameter: Gauss_to_uT_Gain
                                        * Referenced by: '<S196>/Gauss_to_uT'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S215>/Switch'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                            * Referenced by: '<S93>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_il;/* Computed Parameter: DiscreteTimeIntegrator_IC_il
                                         * Referenced by: '<S93>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                            * Referenced by: '<S92>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S92>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_lt;/* Computed Parameter: DiscreteTimeIntegrator_gainv_lt
                                            * Referenced by: '<S94>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_d;/* Computed Parameter: DiscreteTimeIntegrator_IC_d
                                        * Referenced by: '<S94>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainv_pi;/* Computed Parameter: DiscreteTimeIntegrator_gainv_pi
                                            * Referenced by: '<S95>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_c;/* Computed Parameter: DiscreteTimeIntegrator_IC_c
                                        * Referenced by: '<S95>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                            * Referenced by: '<S97>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_cj;/* Computed Parameter: DiscreteTimeIntegrator_IC_cj
                                         * Referenced by: '<S97>/Discrete-Time Integrator'
                                         */
  real32_T DiscreteTimeIntegrator_gainv_e3;/* Computed Parameter: DiscreteTimeIntegrator_gainv_e3
                                            * Referenced by: '<S98>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_n;/* Computed Parameter: DiscreteTimeIntegrator_IC_n
                                        * Referenced by: '<S98>/Discrete-Time Integrator'
                                        */
  real32_T Constant_Value_h5;          /* Computed Parameter: Constant_Value_h5
                                        * Referenced by: '<S134>/Constant'
                                        */
  real32_T Constant_Value_jj;          /* Computed Parameter: Constant_Value_jj
                                        * Referenced by: '<S135>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator5_gainv_j;/* Computed Parameter: DiscreteTimeIntegrator5_gainv_j
                                            * Referenced by: '<S28>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_k;/* Computed Parameter: DiscreteTimeIntegrator5_IC_k
                                         * Referenced by: '<S28>/Discrete-Time Integrator5'
                                         */
  real32_T Gain2_Gain_n;               /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S28>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator5_gain_jf;/* Computed Parameter: DiscreteTimeIntegrator5_gain_jf
                                            * Referenced by: '<S26>/Discrete-Time Integrator5'
                                            */
  real32_T DiscreteTimeIntegrator5_IC_c;/* Computed Parameter: DiscreteTimeIntegrator5_IC_c
                                         * Referenced by: '<S26>/Discrete-Time Integrator5'
                                         */
  real32_T Gain2_Gain_o1;              /* Computed Parameter: Gain2_Gain_o1
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real32_T Saturation2_UpperSat_i;     /* Computed Parameter: Saturation2_UpperSat_i
                                        * Referenced by: '<S10>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_g;     /* Computed Parameter: Saturation2_LowerSat_g
                                        * Referenced by: '<S10>/Saturation2'
                                        */
  real32_T Gain2_Gain_ae;              /* Computed Parameter: Gain2_Gain_ae
                                        * Referenced by: '<S27>/Gain2'
                                        */
  real32_T Constant_Value_m0;          /* Computed Parameter: Constant_Value_m0
                                        * Referenced by: '<S45>/Constant'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                            * Referenced by: '<S56>/Discrete-Time Integrator1'
                                            */
  real32_T Relay_OnVal;                /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<S57>/Relay'
                                        */
  real32_T Relay_OffVal;               /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<S57>/Relay'
                                        */
  real32_T Relay_YOn;                  /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<S57>/Relay'
                                        */
  real32_T Relay_YOff;                 /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<S57>/Relay'
                                        */
  real32_T Delay_InitialCondition;     /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S43>/Delay'
                                        */
  real32_T gravity_Value[3];           /* Computed Parameter: gravity_Value
                                        * Referenced by: '<S39>/gravity'
                                        */
  real32_T DeadZone2_Start;            /* Computed Parameter: DeadZone2_Start
                                        * Referenced by: '<S45>/Dead Zone2'
                                        */
  real32_T DeadZone2_End;              /* Computed Parameter: DeadZone2_End
                                        * Referenced by: '<S45>/Dead Zone2'
                                        */
  real32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real32_T Constant_Value_ew;          /* Computed Parameter: Constant_Value_ew
                                        * Referenced by: '<S48>/Constant'
                                        */
  real32_T Gain_Gain_a5;               /* Computed Parameter: Gain_Gain_a5
                                        * Referenced by: '<S48>/Gain'
                                        */
  real32_T Saturation_UpperSat_g4;     /* Computed Parameter: Saturation_UpperSat_g4
                                        * Referenced by: '<S48>/Saturation'
                                        */
  real32_T Saturation_LowerSat_n;      /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S48>/Saturation'
                                        */
  real32_T DiscreteFIRFilter_InitialStates;/* Computed Parameter: DiscreteFIRFilter_InitialStates
                                            * Referenced by: '<S45>/Discrete FIR Filter'
                                            */
  real32_T DiscreteFIRFilter_Coefficients[30];/* Computed Parameter: DiscreteFIRFilter_Coefficients
                                               * Referenced by: '<S45>/Discrete FIR Filter'
                                               */
  real32_T Saturation_UpperSat_k;      /* Computed Parameter: Saturation_UpperSat_k
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real32_T Saturation_LowerSat_kf;     /* Computed Parameter: Saturation_LowerSat_kf
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real32_T Gain_Gain_oh;               /* Computed Parameter: Gain_Gain_oh
                                        * Referenced by: '<S45>/Gain'
                                        */
  real32_T Switch_Threshold_d;         /* Computed Parameter: Switch_Threshold_d
                                        * Referenced by: '<S53>/Switch'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S54>/Switch'
                                        */
  real32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S46>/Constant8'
                                        */
  real32_T Saturation_UpperSat_e;      /* Computed Parameter: Saturation_UpperSat_e
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real32_T Saturation_LowerSat_f;      /* Computed Parameter: Saturation_LowerSat_f
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real32_T Constant1_Value_n;          /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real32_T Gain_Gain_ok[3];            /* Computed Parameter: Gain_Gain_ok
                                        * Referenced by: '<S46>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                            * Referenced by: '<S56>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_df;/* Computed Parameter: DiscreteTimeIntegrator_IC_df
                                         * Referenced by: '<S56>/Discrete-Time Integrator'
                                         */
  real32_T Gain1_Gain_mk;              /* Computed Parameter: Gain1_Gain_mk
                                        * Referenced by: '<S56>/Gain1'
                                        */
  real32_T Gain_Gain_lc;               /* Computed Parameter: Gain_Gain_lc
                                        * Referenced by: '<S56>/Gain'
                                        */
  real32_T Constant_Value_n2;          /* Computed Parameter: Constant_Value_n2
                                        * Referenced by: '<S40>/Constant'
                                        */
  real32_T mag_correct_gain_Gain;      /* Computed Parameter: mag_correct_gain_Gain
                                        * Referenced by: '<S69>/mag_correct_gain'
                                        */
  real32_T Relay1_OnVal;               /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<S68>/Relay1'
                                        */
  real32_T Relay1_OffVal;              /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<S68>/Relay1'
                                        */
  real32_T Relay1_YOn;                 /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<S68>/Relay1'
                                        */
  real32_T Relay1_YOff;                /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<S68>/Relay1'
                                        */
  real32_T Gain3_Gain_ke;              /* Computed Parameter: Gain3_Gain_ke
                                        * Referenced by: '<S40>/Gain3'
                                        */
  real32_T Saturation1_UpperSat_p;     /* Computed Parameter: Saturation1_UpperSat_p
                                        * Referenced by: '<S67>/Saturation1'
                                        */
  real32_T Saturation1_LowerSat_jl;    /* Computed Parameter: Saturation1_LowerSat_jl
                                        * Referenced by: '<S67>/Saturation1'
                                        */
  real32_T RateLimiter_RisingLim;      /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S67>/Rate Limiter'
                                        */
  real32_T RateLimiter_FallingLim;     /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S67>/Rate Limiter'
                                        */
  real32_T RateLimiter_IC;             /* Computed Parameter: RateLimiter_IC
                                        * Referenced by: '<S67>/Rate Limiter'
                                        */
  real32_T Saturation_UpperSat_ky;     /* Computed Parameter: Saturation_UpperSat_ky
                                        * Referenced by: '<S67>/Saturation'
                                        */
  real32_T Saturation_LowerSat_f3;     /* Computed Parameter: Saturation_LowerSat_f3
                                        * Referenced by: '<S67>/Saturation'
                                        */
  real32_T Gain4_Gain_d;               /* Computed Parameter: Gain4_Gain_d
                                        * Referenced by: '<S40>/Gain4'
                                        */
  real32_T Saturation2_UpperSat_h;     /* Computed Parameter: Saturation2_UpperSat_h
                                        * Referenced by: '<S40>/Saturation2'
                                        */
  real32_T Saturation2_LowerSat_o;     /* Computed Parameter: Saturation2_LowerSat_o
                                        * Referenced by: '<S40>/Saturation2'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S72>/Constant'
                                        */
  real32_T Gain2_Gain_i;               /* Computed Parameter: Gain2_Gain_i
                                        * Referenced by: '<S72>/Gain2'
                                        */
  real32_T Constant_Value_lp;          /* Computed Parameter: Constant_Value_lp
                                        * Referenced by: '<S92>/Constant'
                                        */
  real32_T Constant_Value_mh;          /* Computed Parameter: Constant_Value_mh
                                        * Referenced by: '<S93>/Constant'
                                        */
  real32_T Constant_Value_pz;          /* Computed Parameter: Constant_Value_pz
                                        * Referenced by: '<S94>/Constant'
                                        */
  real32_T Constant_Value_kt;          /* Computed Parameter: Constant_Value_kt
                                        * Referenced by: '<S95>/Constant'
                                        */
  real32_T Constant_Value_kn;          /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S96>/Constant'
                                        */
  real32_T Constant_Value_ow;          /* Computed Parameter: Constant_Value_ow
                                        * Referenced by: '<S97>/Constant'
                                        */
  real32_T Constant_Value_k1;          /* Computed Parameter: Constant_Value_k1
                                        * Referenced by: '<S98>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                            * Referenced by: '<S194>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_ck;/* Computed Parameter: DiscreteTimeIntegrator_IC_ck
                                         * Referenced by: '<S194>/Discrete-Time Integrator'
                                         */
  real32_T Gain1_Gain_kl;              /* Computed Parameter: Gain1_Gain_kl
                                        * Referenced by: '<S194>/Gain1'
                                        */
  real32_T Gain_Gain_mz;               /* Computed Parameter: Gain_Gain_mz
                                        * Referenced by: '<S194>/Gain'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                            * Referenced by: '<S195>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_n5;/* Computed Parameter: DiscreteTimeIntegrator_IC_n5
                                         * Referenced by: '<S195>/Discrete-Time Integrator'
                                         */
  real32_T Gain1_Gain_e1;              /* Computed Parameter: Gain1_Gain_e1
                                        * Referenced by: '<S195>/Gain1'
                                        */
  real32_T Gain_Gain_m2;               /* Computed Parameter: Gain_Gain_m2
                                        * Referenced by: '<S195>/Gain'
                                        */
  real32_T Constant_Value_jp;          /* Computed Parameter: Constant_Value_jp
                                        * Referenced by: '<S216>/Constant'
                                        */
  uint32_T Gain5_Gain_a;               /* Computed Parameter: Gain5_Gain_a
                                        * Referenced by: '<S165>/Gain5'
                                        */
  uint32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S164>/Gain1'
                                        */
  uint32_T Constant1_Value_f5;         /* Computed Parameter: Constant1_Value_f5
                                        * Referenced by: '<S146>/Constant1'
                                        */
  uint32_T Memory2_InitialCondition;   /* Computed Parameter: Memory2_InitialCondition
                                        * Referenced by: '<S146>/Memory2'
                                        */
  uint32_T Saturation1_UpperSat_n;     /* Computed Parameter: Saturation1_UpperSat_n
                                        * Referenced by: '<S146>/Saturation1'
                                        */
  uint32_T Saturation1_LowerSat_m;     /* Computed Parameter: Saturation1_LowerSat_m
                                        * Referenced by: '<S146>/Saturation1'
                                        */
  uint32_T x_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S240>/x_delay'
                                        */
  uint32_T x_delay1_DelayLength;       /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S240>/x_delay1'
                                        */
  uint32_T vn_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S240>/vn_delay'
                                        */
  uint32_T vn_delay1_DelayLength;      /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S240>/vn_delay1'
                                        */
  uint32_T x_delay_DelayLength_m;      /* Expression: 10/INS_EXPORT.period
                                        * Referenced by: '<S262>/x_delay'
                                        */
  uint32_T h_delay_DelayLength;        /* Expression: 150/INS_EXPORT.period
                                        * Referenced by: '<S271>/h_delay'
                                        */
  uint32_T vd_delay_DelayLength;       /* Expression: 100/INS_EXPORT.period
                                        * Referenced by: '<S271>/vd_delay'
                                        */
  uint32_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S84>/Output'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_b;/* Computed Parameter: DiscreteTimeIntegrator_IC_b
                                        * Referenced by: '<S174>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_p;/* Computed Parameter: DiscreteTimeIntegrator_IC_p
                                        * Referenced by: '<S176>/Discrete-Time Integrator'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S31>/Delay'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_po;/* Computed Parameter: DiscreteTimeIntegrator_IC_po
                                         * Referenced by: '<S166>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_g;/* Computed Parameter: DiscreteTimeIntegrator_IC_g
                                        * Referenced by: '<S216>/Discrete-Time Integrator'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_pt;/* Computed Parameter: DiscreteTimeIntegrator_IC_pt
                                         * Referenced by: '<S219>/Discrete-Time Integrator'
                                         */
  uint32_T Memory2_InitialCondition_a; /* Computed Parameter: Memory2_InitialCondition_a
                                        * Referenced by: '<S145>/Memory2'
                                        */
  uint32_T Constant_Value_in;          /* Computed Parameter: Constant_Value_in
                                        * Referenced by: '<S152>/Constant'
                                        */
  uint32_T DiscreteTimeIntegrator_IC_dv;/* Computed Parameter: DiscreteTimeIntegrator_IC_dv
                                         * Referenced by: '<S145>/Discrete-Time Integrator'
                                         */
  uint32_T DiscreteTimeIntegrator_IC_k;/* Computed Parameter: DiscreteTimeIntegrator_IC_k
                                        * Referenced by: '<S197>/Discrete-Time Integrator'
                                        */
  int16_T Gain_Gain_fs;                /* Computed Parameter: Gain_Gain_fs
                                        * Referenced by: '<S205>/Gain'
                                        */
  uint16_T Gain1_Gain_kq;              /* Computed Parameter: Gain1_Gain_kq
                                        * Referenced by: '<S88>/Gain1'
                                        */
  uint16_T Gain13_Gain;                /* Computed Parameter: Gain13_Gain
                                        * Referenced by: '<S88>/Gain13'
                                        */
  uint16_T Gain12_Gain;                /* Computed Parameter: Gain12_Gain
                                        * Referenced by: '<S88>/Gain12'
                                        */
  uint16_T Gain11_Gain;                /* Computed Parameter: Gain11_Gain
                                        * Referenced by: '<S88>/Gain11'
                                        */
  uint16_T Gain5_Gain_e;               /* Computed Parameter: Gain5_Gain_e
                                        * Referenced by: '<S88>/Gain5'
                                        */
  uint16_T Gain4_Gain_a;               /* Computed Parameter: Gain4_Gain_a
                                        * Referenced by: '<S88>/Gain4'
                                        */
  uint16_T Gain2_Gain_o5;              /* Computed Parameter: Gain2_Gain_o5
                                        * Referenced by: '<S88>/Gain2'
                                        */
  uint16_T Delay_InitialCondition_n;   /* Computed Parameter: Delay_InitialCondition_n
                                        * Referenced by: '<S31>/Delay'
                                        */
  uint16_T Saturation_UpperSat_k5;     /* Computed Parameter: Saturation_UpperSat_k5
                                        * Referenced by: '<S31>/Saturation'
                                        */
  uint16_T Saturation_LowerSat_hb;     /* Computed Parameter: Saturation_LowerSat_hb
                                        * Referenced by: '<S31>/Saturation'
                                        */
  uint16_T GPS_Delay_Value;            /* Computed Parameter: GPS_Delay_Value
                                        * Referenced by: '<S60>/GPS_Delay'
                                        */
  uint16_T OptFlow_Delay_Value;        /* Computed Parameter: OptFlow_Delay_Value
                                        * Referenced by: '<S60>/OptFlow_Delay'
                                        */
  boolean_T Memory2_InitialCondition_ar;/* Computed Parameter: Memory2_InitialCondition_ar
                                         * Referenced by: '<S5>/Memory2'
                                         */
  boolean_T Constant_Value_af;         /* Computed Parameter: Constant_Value_af
                                        * Referenced by: '<S36>/Constant'
                                        */
  boolean_T Constant_Value_c;          /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S311>/Constant'
                                        */
  boolean_T Constant_Value_gn;         /* Computed Parameter: Constant_Value_gn
                                        * Referenced by: '<S299>/Constant'
                                        */
  boolean_T Constant_Value_pt;         /* Computed Parameter: Constant_Value_pt
                                        * Referenced by: '<S306>/Constant'
                                        */
  boolean_T Constant_Value_p2;         /* Computed Parameter: Constant_Value_p2
                                        * Referenced by: '<S312>/Constant'
                                        */
  boolean_T Constant_Value_bt;         /* Computed Parameter: Constant_Value_bt
                                        * Referenced by: '<S297>/Constant'
                                        */
  boolean_T Constant_Value_m3;         /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S304>/Constant'
                                        */
  boolean_T Constant_Value_hv;         /* Computed Parameter: Constant_Value_hv
                                        * Referenced by: '<S313>/Constant'
                                        */
  boolean_T Memory_InitialCondition_g; /* Computed Parameter: Memory_InitialCondition_g
                                        * Referenced by: '<S96>/Memory'
                                        */
  boolean_T Memory_InitialCondition_b; /* Computed Parameter: Memory_InitialCondition_b
                                        * Referenced by: '<S93>/Memory'
                                        */
  boolean_T Memory_InitialCondition_jp;/* Computed Parameter: Memory_InitialCondition_jp
                                        * Referenced by: '<S92>/Memory'
                                        */
  boolean_T Memory_InitialCondition_mr;/* Computed Parameter: Memory_InitialCondition_mr
                                        * Referenced by: '<S94>/Memory'
                                        */
  boolean_T Memory_InitialCondition_f; /* Computed Parameter: Memory_InitialCondition_f
                                        * Referenced by: '<S95>/Memory'
                                        */
  boolean_T Memory_InitialCondition_h; /* Computed Parameter: Memory_InitialCondition_h
                                        * Referenced by: '<S97>/Memory'
                                        */
  boolean_T Memory_InitialCondition_d; /* Computed Parameter: Memory_InitialCondition_d
                                        * Referenced by: '<S98>/Memory'
                                        */
  boolean_T Constant_Value_f4;         /* Computed Parameter: Constant_Value_f4
                                        * Referenced by: '<S103>/Constant'
                                        */
  boolean_T Constant_Value_nl;         /* Computed Parameter: Constant_Value_nl
                                        * Referenced by: '<S108>/Constant'
                                        */
  boolean_T Constant_Value_pn;         /* Computed Parameter: Constant_Value_pn
                                        * Referenced by: '<S113>/Constant'
                                        */
  boolean_T Constant_Value_pv;         /* Computed Parameter: Constant_Value_pv
                                        * Referenced by: '<S118>/Constant'
                                        */
  boolean_T Constant_Value_l1;         /* Computed Parameter: Constant_Value_l1
                                        * Referenced by: '<S123>/Constant'
                                        */
  boolean_T Constant_Value_d0;         /* Computed Parameter: Constant_Value_d0
                                        * Referenced by: '<S128>/Constant'
                                        */
  boolean_T Constant_Value_ng;         /* Computed Parameter: Constant_Value_ng
                                        * Referenced by: '<S133>/Constant'
                                        */
  int8_T Gain1_Gain_o;                 /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S208>/Gain1'
                                        */
  uint8_T Gain7_Gain;                  /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S91>/Gain7'
                                        */
  uint8_T Gain5_Gain_o;                /* Computed Parameter: Gain5_Gain_o
                                        * Referenced by: '<S91>/Gain5'
                                        */
  uint8_T Gain4_Gain_p;                /* Computed Parameter: Gain4_Gain_p
                                        * Referenced by: '<S91>/Gain4'
                                        */
  uint8_T Gain3_Gain_f;                /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S91>/Gain3'
                                        */
  uint8_T Gain2_Gain_h;                /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S91>/Gain2'
                                        */
  uint8_T Gain_Gain_od;                /* Computed Parameter: Gain_Gain_od
                                        * Referenced by: '<S193>/Gain'
                                        */
  uint8_T Gain_Gain_g;                 /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S67>/Gain'
                                        */
  uint8_T Gain9_Gain;                  /* Computed Parameter: Gain9_Gain
                                        * Referenced by: '<S88>/Gain9'
                                        */
  uint8_T Constant_Value_mm;           /* Computed Parameter: Constant_Value_mm
                                        * Referenced by: '<S71>/Constant'
                                        */
  uint8_T Constant1_Value_l;           /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S219>/Constant1'
                                        */
  uint8_T Constant_Value_jn;           /* Computed Parameter: Constant_Value_jn
                                        * Referenced by: '<S191>/Constant'
                                        */
  uint8_T Memory_InitialCondition_ll;  /* Computed Parameter: Memory_InitialCondition_ll
                                        * Referenced by: '<S219>/Memory'
                                        */
  uint8_T Constant_Value_jz;           /* Computed Parameter: Constant_Value_jz
                                        * Referenced by: '<S226>/Constant'
                                        */
  uint8_T Memory_InitialCondition_gc;  /* Computed Parameter: Memory_InitialCondition_gc
                                        * Referenced by: '<S71>/Memory'
                                        */
  uint8_T Saturation_UpperSat_d;       /* Computed Parameter: Saturation_UpperSat_d
                                        * Referenced by: '<S57>/Saturation'
                                        */
  uint8_T Saturation_LowerSat_b;       /* Computed Parameter: Saturation_LowerSat_b
                                        * Referenced by: '<S57>/Saturation'
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
                                                *   '<S178>/Acc_Bias'
                                                *   '<S178>/Acc_RotMatrix'
                                                *   '<S179>/Gyr_RotMatrix'
                                                *   '<S179>/Gyro_Bias'
                                                *   '<S184>/Acc_Bias'
                                                *   '<S184>/Acc_RotMatrix'
                                                *   '<S185>/Gyr_RotMatrix'
                                                *   '<S185>/Gyro_Bias'
                                                *   '<S199>/Mag_Bias'
                                                *   '<S199>/Mag_RotMatrix'
                                                */
extern struct_4XfCoaAMTej5uH3d8u88xB INS_EXPORT;/* Variable: INS_EXPORT
                                                 * Referenced by:
                                                 *   '<S84>/Constant'
                                                 *   '<S174>/Constant'
                                                 *   '<S176>/Constant'
                                                 *   '<S197>/Constant'
                                                 *   '<S219>/Constant'
                                                 *   '<S145>/Constant'
                                                 *   '<S166>/Constant'
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
 * '<S1>'   : 'INS/AHRS'
 * '<S2>'   : 'INS/Bus_Assignment'
 * '<S3>'   : 'INS/Sensor_Process'
 * '<S4>'   : 'INS/Translation_Filter'
 * '<S5>'   : 'INS/AHRS/Attitude_Init'
 * '<S6>'   : 'INS/AHRS/Correct'
 * '<S7>'   : 'INS/AHRS/Integrate'
 * '<S8>'   : 'INS/AHRS/Attitude_Init/Attitude_Init'
 * '<S9>'   : 'INS/AHRS/Attitude_Init/Compare To Constant'
 * '<S10>'  : 'INS/AHRS/Attitude_Init/Onground_Detect'
 * '<S11>'  : 'INS/AHRS/Attitude_Init/Reset_Condition'
 * '<S12>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/Cross_Product1'
 * '<S13>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/Cross_Product2'
 * '<S14>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/M to Quat'
 * '<S15>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/safe_norm'
 * '<S16>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/safe_norm1'
 * '<S17>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/safe_norm2'
 * '<S18>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/M to Quat/If Action Subsystem'
 * '<S19>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/M to Quat/If Action Subsystem1'
 * '<S20>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/M to Quat/If Action Subsystem2'
 * '<S21>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/M to Quat/If Action Subsystem3'
 * '<S22>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/safe_norm/Euclidean_Norm2'
 * '<S23>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/safe_norm1/Euclidean_Norm2'
 * '<S24>'  : 'INS/AHRS/Attitude_Init/Attitude_Init/safe_norm2/Euclidean_Norm2'
 * '<S25>'  : 'INS/AHRS/Attitude_Init/Onground_Detect/HPF'
 * '<S26>'  : 'INS/AHRS/Attitude_Init/Onground_Detect/Lowpass2'
 * '<S27>'  : 'INS/AHRS/Attitude_Init/Onground_Detect/Lowpass4'
 * '<S28>'  : 'INS/AHRS/Attitude_Init/Onground_Detect/HPF/Lowpass1'
 * '<S29>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/Compare To Constant'
 * '<S30>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/Interval Test'
 * '<S31>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/Subsystem'
 * '<S32>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/vec_modulus'
 * '<S33>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/vec_modulus1'
 * '<S34>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/Subsystem/Detect Rise Positive'
 * '<S35>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/Subsystem/Init with 50 valid samples'
 * '<S36>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/Subsystem/Detect Rise Positive/Positive'
 * '<S37>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/vec_modulus/vec_norm'
 * '<S38>'  : 'INS/AHRS/Attitude_Init/Reset_Condition/vec_modulus1/vec_norm'
 * '<S39>'  : 'INS/AHRS/Correct/Attitude_Correct'
 * '<S40>'  : 'INS/AHRS/Correct/Bias_Correction'
 * '<S41>'  : 'INS/AHRS/Correct/Heading_Correction'
 * '<S42>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct'
 * '<S43>'  : 'INS/AHRS/Correct/Attitude_Correct/Estimated_Acc'
 * '<S44>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc'
 * '<S45>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Heading_Correct'
 * '<S46>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Verticle_Correct'
 * '<S47>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Heading_Correct/Cross_Product1'
 * '<S48>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Heading_Correct/Match_Level'
 * '<S49>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Heading_Correct/Modulus'
 * '<S50>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Heading_Correct/Modulus1'
 * '<S51>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Verticle_Correct/Cross_Product2'
 * '<S52>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Verticle_Correct/Soft_Vector_Saturation'
 * '<S53>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize'
 * '<S54>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Verticle_Correct/vec_normalize1'
 * '<S55>'  : 'INS/AHRS/Correct/Attitude_Correct/Acc_Correct/Verticle_Correct/Soft_Vector_Saturation/Euclidean_Norm'
 * '<S56>'  : 'INS/AHRS/Correct/Attitude_Correct/Estimated_Acc/2_Order_Butter_LPF'
 * '<S57>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/Data_Processing'
 * '<S58>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/Detect Increase'
 * '<S59>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/GPS_Observer'
 * '<S60>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/Signal_Routing'
 * '<S61>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/VIsionFlow_Observer'
 * '<S62>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/GPS_Observer/Continuous Linear Observer'
 * '<S63>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/VIsionFlow_Observer/Continuous Linear Observer'
 * '<S64>'  : 'INS/AHRS/Correct/Attitude_Correct/Measured_Acc/VIsionFlow_Observer/Continuous Linear Observer1'
 * '<S65>'  : 'INS/AHRS/Correct/Bias_Correction/Compare To Constant'
 * '<S66>'  : 'INS/AHRS/Correct/Bias_Correction/Euclidean_Norm1'
 * '<S67>'  : 'INS/AHRS/Correct/Bias_Correction/Standstill Gyro Correction'
 * '<S68>'  : 'INS/AHRS/Correct/Heading_Correction/Enable'
 * '<S69>'  : 'INS/AHRS/Correct/Heading_Correction/Magetic_Correction'
 * '<S70>'  : 'INS/AHRS/Correct/Heading_Correction/Magetic_Correction/Subsystem'
 * '<S71>'  : 'INS/AHRS/Integrate/Att_Init_Done'
 * '<S72>'  : 'INS/AHRS/Integrate/Attitude_Integration'
 * '<S73>'  : 'INS/AHRS/Integrate/Bias_Integration'
 * '<S74>'  : 'INS/AHRS/Integrate/Euler_Angle'
 * '<S75>'  : 'INS/AHRS/Integrate/Att_Init_Done/Detect Increase'
 * '<S76>'  : 'INS/AHRS/Integrate/Attitude_Integration/Quat Multiply1'
 * '<S77>'  : 'INS/AHRS/Integrate/Attitude_Integration/Quat_to_M_OB'
 * '<S78>'  : 'INS/AHRS/Integrate/Attitude_Integration/quat normalize'
 * '<S79>'  : 'INS/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus'
 * '<S80>'  : 'INS/AHRS/Integrate/Attitude_Integration/quat normalize/quat modulus/quat norm'
 * '<S81>'  : 'INS/AHRS/Integrate/Euler_Angle/Euler_Transformations'
 * '<S82>'  : 'INS/AHRS/Integrate/Euler_Angle/M_CO1'
 * '<S83>'  : 'INS/AHRS/Integrate/Euler_Angle/Euler_Transformations/quat_to_psi'
 * '<S84>'  : 'INS/Bus_Assignment/Counter'
 * '<S85>'  : 'INS/Bus_Assignment/Rotation_Output'
 * '<S86>'  : 'INS/Bus_Assignment/Status_Output'
 * '<S87>'  : 'INS/Bus_Assignment/Translation_Output'
 * '<S88>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag'
 * '<S89>'  : 'INS/Bus_Assignment/Status_Output/INS_Quality'
 * '<S90>'  : 'INS/Bus_Assignment/Status_Output/INS_Ready'
 * '<S91>'  : 'INS/Bus_Assignment/Status_Output/INS_Status'
 * '<S92>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1'
 * '<S93>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2'
 * '<S94>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3'
 * '<S95>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4'
 * '<S96>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5'
 * '<S97>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6'
 * '<S98>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7'
 * '<S99>'  : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Compare To Constant'
 * '<S100>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Compare To Constant1'
 * '<S101>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Compare To Constant2'
 * '<S102>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Detect Rise Positive'
 * '<S103>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check1/Detect Rise Positive/Positive'
 * '<S104>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Compare To Constant'
 * '<S105>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Compare To Constant1'
 * '<S106>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Compare To Constant2'
 * '<S107>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Detect Rise Positive'
 * '<S108>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check2/Detect Rise Positive/Positive'
 * '<S109>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Compare To Constant'
 * '<S110>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Compare To Constant1'
 * '<S111>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Compare To Constant2'
 * '<S112>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Detect Rise Positive'
 * '<S113>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check3/Detect Rise Positive/Positive'
 * '<S114>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Compare To Constant'
 * '<S115>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Compare To Constant1'
 * '<S116>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Compare To Constant2'
 * '<S117>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Detect Rise Positive'
 * '<S118>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check4/Detect Rise Positive/Positive'
 * '<S119>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Compare To Constant'
 * '<S120>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Compare To Constant1'
 * '<S121>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Compare To Constant2'
 * '<S122>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Detect Rise Positive'
 * '<S123>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check5/Detect Rise Positive/Positive'
 * '<S124>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Compare To Constant'
 * '<S125>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Compare To Constant1'
 * '<S126>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Compare To Constant2'
 * '<S127>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Detect Rise Positive'
 * '<S128>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check6/Detect Rise Positive/Positive'
 * '<S129>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Compare To Constant'
 * '<S130>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Compare To Constant1'
 * '<S131>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Compare To Constant2'
 * '<S132>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Detect Rise Positive'
 * '<S133>' : 'INS/Bus_Assignment/Status_Output/INS_Flag/valid_check7/Detect Rise Positive/Positive'
 * '<S134>' : 'INS/Bus_Assignment/Status_Output/INS_Status/Compare To Zero'
 * '<S135>' : 'INS/Bus_Assignment/Status_Output/INS_Status/Compare To Zero1'
 * '<S136>' : 'INS/Sensor_Process/Baro_Process'
 * '<S137>' : 'INS/Sensor_Process/GPS_Process'
 * '<S138>' : 'INS/Sensor_Process/IMU_Process'
 * '<S139>' : 'INS/Sensor_Process/Mag_Process'
 * '<S140>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing'
 * '<S141>' : 'INS/Sensor_Process/Sonar_Process'
 * '<S142>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height'
 * '<S143>' : 'INS/Sensor_Process/Baro_Process/Relative_Height'
 * '<S144>' : 'INS/Sensor_Process/Baro_Process/Pressure_Height/Interval Test1'
 * '<S145>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value'
 * '<S146>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Reference_and_Gradient'
 * '<S147>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Compare To Constant'
 * '<S148>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Compare To Constant1'
 * '<S149>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Compare To Constant2'
 * '<S150>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Compare To Constant3'
 * '<S151>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Compare To Constant4'
 * '<S152>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Compare To Zero'
 * '<S153>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Detect Change'
 * '<S154>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Interval Test1'
 * '<S155>' : 'INS/Sensor_Process/Baro_Process/Relative_Height/Init_Value/Interval Test2'
 * '<S156>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant'
 * '<S157>' : 'INS/Sensor_Process/GPS_Process/Compare To Constant1'
 * '<S158>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality'
 * '<S159>' : 'INS/Sensor_Process/GPS_Process/Scaling'
 * '<S160>' : 'INS/Sensor_Process/GPS_Process/WGS_Derivative'
 * '<S161>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant2'
 * '<S162>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Compare To Constant4'
 * '<S163>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Status'
 * '<S164>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/horizontal_acc'
 * '<S165>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/speed_acc'
 * '<S166>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check'
 * '<S167>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Status/Compare To Constant'
 * '<S168>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Status/Compare To Constant1'
 * '<S169>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Status/Compare To Constant2'
 * '<S170>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/Status/Compare To Constant3'
 * '<S171>' : 'INS/Sensor_Process/GPS_Process/GPS_Status_and_Quality/timestamp_check/Detect Change'
 * '<S172>' : 'INS/Sensor_Process/GPS_Process/WGS_Derivative/WGS84_Derivatives'
 * '<S173>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling'
 * '<S174>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check'
 * '<S175>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling'
 * '<S176>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check'
 * '<S177>' : 'INS/Sensor_Process/IMU_Process/Subsystem'
 * '<S178>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling/Acc_Calibrate'
 * '<S179>' : 'INS/Sensor_Process/IMU_Process/IMU1_Scaling/Gyro_Calibrate'
 * '<S180>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Compare To Constant4'
 * '<S181>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Detect Change'
 * '<S182>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test1'
 * '<S183>' : 'INS/Sensor_Process/IMU_Process/IMU1_Valid_Check/Interval Test3'
 * '<S184>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling/Acc_Calibrate'
 * '<S185>' : 'INS/Sensor_Process/IMU_Process/IMU2_Scaling/Gyro_Calibrate'
 * '<S186>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Compare To Constant4'
 * '<S187>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Detect Change'
 * '<S188>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test1'
 * '<S189>' : 'INS/Sensor_Process/IMU_Process/IMU2_Valid_Check/Interval Test3'
 * '<S190>' : 'INS/Sensor_Process/IMU_Process/Subsystem/2_order_butter_LPF'
 * '<S191>' : 'INS/Sensor_Process/IMU_Process/Subsystem/Compare To Zero'
 * '<S192>' : 'INS/Sensor_Process/IMU_Process/Subsystem/IMU_Select'
 * '<S193>' : 'INS/Sensor_Process/IMU_Process/Subsystem/IMU_Status'
 * '<S194>' : 'INS/Sensor_Process/IMU_Process/Subsystem/IMU_Select/2_Order_Butter_LPF'
 * '<S195>' : 'INS/Sensor_Process/IMU_Process/Subsystem/IMU_Select/2_Order_Butter_LPF1'
 * '<S196>' : 'INS/Sensor_Process/Mag_Process/Mag_Scaling'
 * '<S197>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check'
 * '<S198>' : 'INS/Sensor_Process/Mag_Process/Magnetometer'
 * '<S199>' : 'INS/Sensor_Process/Mag_Process/Mag_Scaling/Mag_Calibrate'
 * '<S200>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Compare To Constant4'
 * '<S201>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Detect Change'
 * '<S202>' : 'INS/Sensor_Process/Mag_Process/Mag_Valid_Check/Interval Test1'
 * '<S203>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Compare To Constant'
 * '<S204>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication'
 * '<S205>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation'
 * '<S206>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/wmm_lookup'
 * '<S207>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate'
 * '<S208>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate'
 * '<S209>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate'
 * '<S210>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus'
 * '<S211>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Inclination_Quality_Estimate/vec_modulus/vec_norm'
 * '<S212>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus'
 * '<S213>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/Quality_Indication/Mag_Quality_Estimate/Intensity_Quality_Estimate/vec_modulus/vec_norm'
 * '<S214>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/Rot_z to M'
 * '<S215>' : 'INS/Sensor_Process/Mag_Process/Magnetometer/WMM_Compensation/vec_normalize'
 * '<S216>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect'
 * '<S217>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Compare To Constant4'
 * '<S218>' : 'INS/Sensor_Process/Optical_Flow_Preprocessing/Valid_Detect/Detect Change'
 * '<S219>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check'
 * '<S220>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Compare To Constant'
 * '<S221>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Compare To Constant4'
 * '<S222>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Detect Change'
 * '<S223>' : 'INS/Sensor_Process/Sonar_Process/Valid_Check/Interval Test'
 * '<S224>' : 'INS/Translation_Filter/CF'
 * '<S225>' : 'INS/Translation_Filter/Data_Process'
 * '<S226>' : 'INS/Translation_Filter/CF/Bus_Assignment'
 * '<S227>' : 'INS/Translation_Filter/CF/Horizontal_Filter'
 * '<S228>' : 'INS/Translation_Filter/CF/Verticle_Filter'
 * '<S229>' : 'INS/Translation_Filter/CF/Bus_Assignment/Signal_Rounting'
 * '<S230>' : 'INS/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Height_Above_Ground'
 * '<S231>' : 'INS/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon'
 * '<S232>' : 'INS/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon/Compare To Constant'
 * '<S233>' : 'INS/Translation_Filter/CF/Bus_Assignment/Signal_Rounting/Meter_to_LatLon/Zero_Value_Exclusion'
 * '<S234>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct'
 * '<S235>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict'
 * '<S236>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct'
 * '<S237>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Detect Change'
 * '<S238>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Holder'
 * '<S239>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement'
 * '<S240>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Observation'
 * '<S241>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Scaling'
 * '<S242>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias'
 * '<S243>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias'
 * '<S244>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias/Bias_Update'
 * '<S245>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Correct/GPS_Correct/Measurement/Remove_Bias/Pos_Error_Bias/Detect Increase'
 * '<S246>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate'
 * '<S247>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Update'
 * '<S248>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init'
 * '<S249>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init'
 * '<S250>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init'
 * '<S251>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Pos_Init/GPS_Pos_Init'
 * '<S252>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/GPS_Vel_Init'
 * '<S253>' : 'INS/Translation_Filter/CF/Horizontal_Filter/Predict/Propagate/States_Init/Vel_Init/OptFlow_Vel_Init'
 * '<S254>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct'
 * '<S255>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict'
 * '<S256>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct'
 * '<S257>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct'
 * '<S258>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct'
 * '<S259>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Detect Change'
 * '<S260>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Holder'
 * '<S261>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement'
 * '<S262>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Observation'
 * '<S263>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Scaling'
 * '<S264>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate'
 * '<S265>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate/Bias_Update'
 * '<S266>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/Baro_Correct/Baro_Correct/Measurement/Bias_Estimate/Detect Increase'
 * '<S267>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct'
 * '<S268>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Detect Change'
 * '<S269>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Holder'
 * '<S270>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement'
 * '<S271>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Observation'
 * '<S272>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Scaling'
 * '<S273>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias'
 * '<S274>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias/Bias_Update'
 * '<S275>' : 'INS/Translation_Filter/CF/Verticle_Filter/Correct/GPS_Correct/GPS_Correct/Measurement/Pos_Error_Bias/Detect Increase'
 * '<S276>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate'
 * '<S277>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Update'
 * '<S278>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init'
 * '<S279>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init'
 * '<S280>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init'
 * '<S281>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init'
 * '<S282>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Baro_Height_Init/Reference_Height'
 * '<S283>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/GPS_Height_Init/Reference_Height'
 * '<S284>' : 'INS/Translation_Filter/CF/Verticle_Filter/Predict/Propagate/States_Init/Sonar_Height_Init/Reference_Height'
 * '<S285>' : 'INS/Translation_Filter/Data_Process/Data_Process'
 * '<S286>' : 'INS/Translation_Filter/Data_Process/Sensor_Meas'
 * '<S287>' : 'INS/Translation_Filter/Data_Process/Sensor_Status'
 * '<S288>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition'
 * '<S289>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select'
 * '<S290>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Valid'
 * '<S291>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Bus_Selection'
 * '<S292>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset'
 * '<S293>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference'
 * '<S294>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset/Height_Reset'
 * '<S295>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset/Position_Reset'
 * '<S296>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset/Height_Reset/Detect Rise Positive'
 * '<S297>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset/Height_Reset/Detect Rise Positive/Positive'
 * '<S298>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset/Position_Reset/Detect Rise Positive'
 * '<S299>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/Pos_Reset/Position_Reset/Detect Rise Positive/Positive'
 * '<S300>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/Bus_Assignment'
 * '<S301>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/WGS84_Height_Ref'
 * '<S302>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/WGS84_Position_Ref'
 * '<S303>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3'
 * '<S304>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/WGS84_Height_Ref/Detect Rise Positive3/Positive'
 * '<S305>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3'
 * '<S306>' : 'INS/Translation_Filter/Data_Process/Data_Process/Init_Condition/WGS84_Reference/WGS84_Position_Ref/Detect Rise Positive3/Positive'
 * '<S307>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Horizontal_Select'
 * '<S308>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select'
 * '<S309>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero'
 * '<S310>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero1'
 * '<S311>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Horizontal_Select/Compare To Zero2'
 * '<S312>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero'
 * '<S313>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero1'
 * '<S314>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero2'
 * '<S315>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero3'
 * '<S316>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero4'
 * '<S317>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero5'
 * '<S318>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Select/Sensor_Vertical_Select/Compare To Zero6'
 * '<S319>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Valid/Position_Validity'
 * '<S320>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Valid/Position_Validity/Horizontal_Validity'
 * '<S321>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Valid/Position_Validity/Vertical_Validity'
 * '<S322>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Valid/Position_Validity/Horizontal_Validity/Compare To Zero'
 * '<S323>' : 'INS/Translation_Filter/Data_Process/Data_Process/Sensor_Valid/Position_Validity/Vertical_Validity/Compare To Zero'
 * '<S324>' : 'INS/Translation_Filter/Data_Process/Sensor_Meas/Baro_Process'
 * '<S325>' : 'INS/Translation_Filter/Data_Process/Sensor_Meas/GPS_Process'
 * '<S326>' : 'INS/Translation_Filter/Data_Process/Sensor_Meas/OpticalFlow_Process'
 * '<S327>' : 'INS/Translation_Filter/Data_Process/Sensor_Meas/Sonar_Process'
 * '<S328>' : 'INS/Translation_Filter/Data_Process/Sensor_Status/Baro_Status'
 * '<S329>' : 'INS/Translation_Filter/Data_Process/Sensor_Status/GPS_Status'
 * '<S330>' : 'INS/Translation_Filter/Data_Process/Sensor_Status/OpticalFlow_Status'
 * '<S331>' : 'INS/Translation_Filter/Data_Process/Sensor_Status/Sonar_Status'
 */
#endif                                 /* RTW_HEADER_INS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
