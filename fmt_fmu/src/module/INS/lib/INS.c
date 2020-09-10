/*
 * File: INS.c
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 1.2573
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 10 23:13:42 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "INS.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

const INS_Out_Bus INS_rtZINS_Out_Bus = {
  0U,                                  /* timestamp */
  0.0F,                                /* phi */
  0.0F,                                /* theta */
  0.0F,                                /* psi */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* quat */
  0.0F,                                /* p */
  0.0F,                                /* q */
  0.0F,                                /* r */
  0.0F,                                /* ax */
  0.0F,                                /* ay */
  0.0F,                                /* az */
  0.0F,                                /* vn */
  0.0F,                                /* ve */
  0.0F,                                /* vd */
  0.0F,                                /* reserved */
  0.0,                                 /* lon */
  0.0,                                 /* lat */
  0.0,                                 /* alt */
  0.0F,                                /* x_R */
  0.0F,                                /* y_R */
  0.0F,                                /* h_R */
  0.0F,                                /* h_AGL */
  0U,                                  /* flag */
  0U                                   /* status */
} ;                                    /* INS_Out_Bus ground */

/* Exported block parameters */
struct_yEHaAuRwDY8DKCecxPQa0D INS_PARAM = {
  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  0U
} ;                                    /* Variable: INS_PARAM
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

struct_i7E80ZuatMf603HOn7rPOE INS_EXPORT = {
  2U,

  { 66, 97, 115, 101, 32, 73, 78, 83, 0 }
} ;                                    /* Variable: INS_EXPORT
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S314>/Constant'
                                        *   '<S316>/Constant'
                                        *   '<S335>/Constant'
                                        *   '<S357>/Constant'
                                        *   '<S283>/Constant'
                                        *   '<S304>/Constant'
                                        */

/* Block parameters (default storage) */
Parameters_INS_T INS_P = {
  1.0E-6,
  10.0,
  1.0E-6,
  1000,
  98.055F,
  98.055F,
  -98.055F,
  -98.055F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.2F,
  0.01F,
  1.0F,
  5.0F,
  38.3972435F,
  38.3972435F,
  -38.3972435F,
  -38.3972435F,
  9.3055F,
  0.0F,
  30000.0F,
  -30000.0F,
  110000.0F,
  30000.0F,
  80.0F,
  -30.0F,
  1000.0F,
  100.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  200.0F,
  100.0F,
  10.3055F,
  2.5F,
  1000000U,
  200U,
  500U,
  1000U,
  5000U,
  100U,
  100U,
  500U,
  1000U,
  100U,
  100U,
  1000U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,

  { 130, 86, 48, 31, 22, 17, 13, 11, 10, 9, 8, 6, 5, 3, 2, 2, 0, 118, 78, 46, 31,
    23, 17, 13, 11, 9, 9, 9, 9, 8, 7, 7, 7, 5, 106, 71, 45, 31, 23, 18, 14, 11,
    9, 9, 9, 10, 11, 11, 12, 12, 10, 96, 66, 43, 31, 23, 18, 14, 11, 9, 9, 10,
    11, 13, 14, 16, 17, 14, 87, 61, 42, 30, 23, 17, 14, 11, 9, 9, 10, 12, 14, 17,
    19, 20, 16, 78, 56, 41, 30, 22, 17, 13, 11, 9, 9, 10, 12, 15, 17, 20, 22, 15,
    69, 51, 39, 30, 23, 17, 13, 10, 9, 9, 10, 11, 14, 16, 18, 20, 6, 61, 46, 37,
    29, 23, 17, 12, 10, 8, 8, 8, 9, 11, 12, 14, 13, -13, 53, 41, 33, 27, 22, 16,
    11, 8, 7, 5, 5, 5, 5, 5, 5, -1, -35, 46, 35, 29, 24, 19, 13, 9, 5, 3, 1, 0,
    -1, -2, -3, -7, -18, -47, 38, 29, 23, 18, 13, 8, 3, 0, -3, -4, -6, -7, -9,
    -12, -17, -29, -50, 31, 23, 16, 11, 5, -1, -5, -8, -10, -11, -12, -13, -14,
    -17, -23, -34, -48, 23, 16, 10, 3, -4, -10, -14, -16, -16, -16, -15, -15,
    -16, -19, -25, -34, -44, 16, 10, 4, -4, -12, -18, -20, -21, -20, -18, -16,
    -15, -16, -18, -23, -31, -38, 8, 5, -1, -9, -17, -22, -24, -23, -20, -17,
    -15, -13, -13, -15, -20, -26, -32, 1, -1, -6, -13, -20, -25, -25, -22, -17,
    -14, -11, -10, -10, -12, -15, -21, -25, -7, -7, -10, -15, -21, -25, -24, -19,
    -13, -9, -7, -6, -6, -8, -11, -15, -17, -15, -13, -14, -17, -22, -24, -21,
    -14, -9, -5, -3, -2, -2, -4, -6, -8, -9, -23, -20, -20, -21, -23, -22, -16,
    -9, -5, -2, -1, 0, 1, 0, -1, -2, -2, -31, -28, -27, -27, -25, -20, -11, -5,
    -2, 0, 1, 2, 3, 3, 3, 4, 6, -40, -35, -34, -33, -30, -22, -9, -2, 1, 2, 3, 4,
    4, 5, 7, 10, 13, -49, -44, -42, -41, -36, -25, -11, -2, 2, 3, 4, 4, 6, 8, 11,
    16, 21, -58, -52, -49, -47, -42, -30, -14, -4, 0, 2, 3, 4, 6, 9, 14, 21, 28,
    -67, -60, -56, -52, -45, -32, -17, -7, -2, 0, 2, 4, 6, 10, 17, 25, 34, -76,
    -68, -62, -56, -46, -32, -18, -9, -4, -1, 1, 3, 6, 11, 18, 27, 40, -86, -76,
    -68, -57, -44, -28, -16, -8, -4, -2, 0, 2, 5, 10, 17, 28, 45, -96, -84, -72,
    -57, -39, -23, -12, -7, -3, -2, 0, 1, 4, 7, 13, 25, 47, -107, -93, -75, -52,
    -31, -16, -8, -4, -2, -1, -1, 0, 1, 3, 7, 17, 45, -118, -102, -76, -44, -21,
    -9, -3, -1, 0, 0, -1, -1, -2, -2, -1, 5, 35, -130, -113, -73, -30, -11, -3,
    0, 1, 0, -1, -2, -3, -5, -7, -8, -7, 16, -143, -127, -61, -14, -3, 1, 2, 1,
    0, -1, -3, -6, -8, -11, -13, -15, -3, -157, -148, -22, 2, 4, 4, 3, 2, 1, -1,
    -4, -6, -9, -13, -15, -18, -13, -172, 178, 26, 14, 10, 7, 6, 4, 3, 1, -2, -6,
    -9, -12, -14, -17, -16, 173, 139, 42, 22, 15, 11, 8, 7, 5, 3, 0, -3, -7, -9,
    -12, -13, -14, 158, 112, 47, 27, 19, 14, 11, 9, 7, 6, 3, 0, -3, -6, -7, -9,
    -10, 143, 96, 48, 30, 21, 16, 12, 10, 9, 8, 6, 3, 1, -1, -3, -4, -6, 130, 86,
    48, 31, 22, 17, 13, 11, 10, 9, 8, 6, 5, 3, 2, 2, 0 },
  50U,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,

  { -78, -81, -78, -72, -64, -55, -42, -25, -5, 15, 31, 43, 53, 62, 71, 79, 86,
    -78, -79, -76, -70, -62, -53, -40, -22, -2, 18, 34, 45, 54, 63, 71, 79, 86,
    -77, -77, -74, -68, -61, -51, -38, -20, 1, 20, 36, 47, 56, 64, 72, 80, 86,
    -76, -75, -72, -66, -59, -49, -35, -18, 3, 22, 38, 49, 57, 65, 73, 81, 87,
    -75, -74, -70, -64, -57, -46, -33, -15, 5, 24, 39, 51, 59, 67, 75, 82, 87,
    -73, -72, -68, -62, -55, -44, -30, -12, 8, 26, 41, 53, 61, 69, 77, 83, 88,
    -72, -70, -65, -60, -53, -42, -28, -10, 10, 29, 43, 55, 64, 71, 78, 84, 88,
    -71, -67, -63, -57, -50, -40, -25, -7, 13, 31, 46, 57, 66, 73, 80, 85, 88,
    -70, -65, -60, -54, -47, -37, -22, -3, 16, 34, 48, 58, 67, 75, 81, 86, 88,
    -69, -64, -57, -51, -44, -33, -18, 1, 20, 36, 49, 59, 68, 75, 81, 86, 88,
    -68, -62, -55, -49, -41, -31, -15, 3, 21, 36, 49, 58, 67, 74, 80, 85, 87,
    -67, -61, -54, -48, -41, -31, -16, 1, 19, 34, 46, 56, 65, 72, 79, 84, 86,
    -67, -60, -54, -49, -43, -35, -22, -6, 12, 28, 42, 53, 62, 70, 77, 82, 86,
    -66, -60, -55, -51, -48, -41, -31, -17, 1, 19, 35, 49, 59, 68, 76, 81, 85,
    -66, -60, -56, -55, -53, -49, -41, -28, -11, 10, 29, 45, 57, 67, 74, 80, 84,
    -66, -60, -57, -58, -58, -55, -49, -38, -20, 1, 24, 42, 55, 66, 73, 79, 84,
    -65, -60, -58, -60, -62, -60, -55, -44, -27, -4, 20, 40, 54, 65, 73, 79, 83,
    -65, -60, -59, -61, -65, -65, -60, -48, -30, -5, 19, 40, 54, 65, 73, 78, 83,
    -66, -60, -59, -61, -66, -67, -63, -50, -30, -5, 20, 40, 55, 65, 73, 78, 83,
    -66, -61, -59, -60, -65, -68, -63, -50, -29, -4, 21, 41, 56, 66, 73, 78, 83,
    -66, -61, -59, -60, -63, -66, -61, -48, -27, -2, 23, 43, 57, 66, 73, 78, 83,
    -67, -62, -60, -59, -61, -63, -58, -44, -23, 2, 26, 44, 58, 67, 74, 79, 84,
    -68, -64, -61, -61, -61, -61, -55, -40, -19, 6, 28, 46, 59, 68, 74, 79, 84,
    -69, -66, -63, -63, -63, -61, -53, -38, -17, 8, 30, 47, 59, 68, 75, 80, 84,
    -70, -68, -66, -66, -65, -62, -53, -38, -16, 8, 30, 47, 60, 69, 76, 81, 85,
    -71, -70, -69, -69, -68, -64, -54, -38, -17, 8, 30, 47, 60, 70, 77, 82, 86,
    -73, -73, -73, -73, -71, -65, -55, -39, -18, 7, 30, 47, 60, 70, 78, 83, 87,
    -74, -75, -76, -76, -73, -66, -55, -39, -18, 6, 29, 47, 61, 71, 78, 84, 87,
    -75, -78, -80, -78, -74, -66, -54, -38, -17, 7, 29, 47, 61, 71, 79, 84, 88,
    -76, -80, -83, -80, -74, -65, -53, -37, -16, 7, 29, 47, 60, 70, 78, 84, 88,
    -77, -83, -86, -81, -73, -64, -51, -36, -15, 7, 28, 46, 59, 69, 77, 83, 88,
    -78, -85, -87, -80, -72, -63, -51, -35, -16, 6, 27, 44, 57, 67, 75, 82, 88,
    -79, -86, -86, -79, -71, -62, -50, -35, -16, 5, 25, 42, 55, 65, 73, 81, 87,
    -79, -86, -84, -77, -70, -61, -49, -34, -15, 5, 25, 41, 53, 63, 72, 80, 87,
    -79, -85, -82, -76, -68, -59, -47, -31, -13, 7, 26, 40, 52, 62, 71, 79, 86,
    -79, -83, -80, -74, -66, -57, -45, -28, -9, 11, 28, 41, 52, 62, 71, 79, 86,
    -78, -81, -78, -72, -64, -55, -42, -25, -5, 15, 31, 43, 53, 62, 71, 79, 86 },
  3U,
  0U,
  2U,
  1U,

  { 61U, 63U, 62U, 59U, 54U, 49U, 43U, 38U, 34U, 33U, 34U, 37U, 42U, 48U, 54U,
    57U, 58U, 60U, 62U, 60U, 56U, 52U, 46U, 41U, 36U, 33U, 33U, 34U, 37U, 42U,
    48U, 54U, 57U, 58U, 59U, 60U, 58U, 54U, 49U, 44U, 39U, 35U, 32U, 32U, 34U,
    38U, 43U, 49U, 54U, 57U, 58U, 58U, 59U, 56U, 52U, 47U, 42U, 37U, 33U, 32U,
    32U, 35U, 39U, 44U, 50U, 55U, 57U, 58U, 57U, 57U, 54U, 49U, 45U, 40U, 35U,
    32U, 31U, 33U, 36U, 40U, 46U, 52U, 56U, 58U, 57U, 56U, 55U, 52U, 47U, 42U,
    37U, 33U, 31U, 31U, 33U, 37U, 42U, 48U, 53U, 57U, 58U, 57U, 55U, 53U, 49U,
    44U, 40U, 35U, 32U, 30U, 31U, 34U, 38U, 44U, 50U, 55U, 58U, 58U, 57U, 54U,
    51U, 46U, 41U, 37U, 33U, 30U, 29U, 30U, 34U, 40U, 46U, 51U, 56U, 58U, 58U,
    57U, 53U, 49U, 43U, 38U, 34U, 30U, 28U, 28U, 30U, 35U, 41U, 47U, 52U, 57U,
    59U, 58U, 57U, 52U, 47U, 41U, 35U, 30U, 28U, 26U, 27U, 30U, 35U, 41U, 47U,
    53U, 57U, 58U, 58U, 57U, 50U, 45U, 38U, 32U, 27U, 25U, 24U, 26U, 29U, 34U,
    40U, 46U, 52U, 56U, 58U, 58U, 56U, 49U, 43U, 35U, 29U, 25U, 23U, 23U, 25U,
    28U, 33U, 39U, 45U, 51U, 55U, 57U, 57U, 56U, 48U, 41U, 34U, 28U, 24U, 22U,
    23U, 24U, 27U, 32U, 37U, 43U, 49U, 53U, 56U, 56U, 56U, 48U, 40U, 32U, 27U,
    24U, 23U, 23U, 24U, 27U, 30U, 35U, 41U, 47U, 51U, 54U, 55U, 56U, 47U, 39U,
    31U, 26U, 24U, 23U, 24U, 25U, 27U, 30U, 34U, 40U, 45U, 50U, 53U, 55U, 55U,
    47U, 38U, 31U, 26U, 24U, 24U, 25U, 26U, 28U, 30U, 34U, 39U, 45U, 49U, 52U,
    54U, 55U, 46U, 38U, 30U, 26U, 24U, 25U, 26U, 28U, 29U, 31U, 35U, 39U, 44U,
    48U, 51U, 53U, 55U, 46U, 37U, 30U, 25U, 24U, 25U, 28U, 30U, 31U, 32U, 35U,
    40U, 44U, 48U, 51U, 53U, 55U, 46U, 38U, 30U, 25U, 24U, 26U, 28U, 31U, 32U,
    33U, 36U, 41U, 45U, 48U, 51U, 53U, 55U, 47U, 38U, 31U, 26U, 24U, 26U, 29U,
    32U, 33U, 34U, 37U, 42U, 46U, 49U, 51U, 53U, 55U, 48U, 40U, 33U, 28U, 25U,
    26U, 29U, 32U, 33U, 35U, 38U, 42U, 47U, 50U, 52U, 54U, 55U, 48U, 41U, 35U,
    30U, 28U, 28U, 30U, 32U, 33U, 35U, 39U, 44U, 47U, 50U, 53U, 54U, 56U, 50U,
    44U, 38U, 34U, 32U, 31U, 32U, 33U, 34U, 36U, 40U, 45U, 49U, 52U, 54U, 55U,
    56U, 51U, 46U, 42U, 39U, 37U, 36U, 36U, 35U, 35U, 37U, 41U, 46U, 50U, 53U,
    55U, 56U, 57U, 52U, 49U, 46U, 44U, 42U, 41U, 40U, 39U, 37U, 39U, 42U, 47U,
    51U, 55U, 57U, 57U, 57U, 54U, 52U, 51U, 49U, 48U, 46U, 45U, 42U, 40U, 40U,
    43U, 48U, 53U, 57U, 59U, 59U, 58U, 55U, 55U, 55U, 54U, 52U, 51U, 48U, 44U,
    41U, 41U, 44U, 49U, 55U, 58U, 60U, 60U, 58U, 57U, 58U, 59U, 58U, 56U, 54U,
    51U, 46U, 42U, 42U, 45U, 50U, 56U, 60U, 61U, 60U, 58U, 58U, 61U, 62U, 61U,
    59U, 56U, 52U, 47U, 43U, 42U, 45U, 51U, 56U, 60U, 62U, 61U, 59U, 59U, 63U,
    64U, 64U, 61U, 57U, 52U, 46U, 42U, 41U, 45U, 50U, 56U, 60U, 61U, 61U, 59U,
    60U, 64U, 66U, 65U, 62U, 57U, 51U, 45U, 41U, 40U, 43U, 49U, 54U, 58U, 61U,
    61U, 59U, 61U, 65U, 67U, 66U, 62U, 57U, 51U, 45U, 40U, 39U, 41U, 46U, 52U,
    56U, 59U, 60U, 59U, 61U, 66U, 67U, 65U, 62U, 56U, 50U, 44U, 39U, 37U, 39U,
    43U, 49U, 54U, 58U, 59U, 59U, 61U, 66U, 66U, 64U, 60U, 55U, 49U, 43U, 38U,
    36U, 37U, 41U, 46U, 52U, 56U, 59U, 58U, 61U, 65U, 65U, 63U, 59U, 53U, 47U,
    41U, 36U, 34U, 35U, 39U, 44U, 50U, 55U, 58U, 58U, 61U, 64U, 64U, 61U, 56U,
    51U, 45U, 40U, 35U, 33U, 34U, 38U, 43U, 49U, 54U, 58U, 58U, 61U, 63U, 62U,
    59U, 54U, 49U, 43U, 38U, 34U, 33U, 34U, 37U, 42U, 48U, 54U, 57U, 58U },
  1.0,

  { 0.0, 0.0, 0.0 },
  1.0E+8,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  1.0,
  1.0,
  1.0,
  1.0,
  1.0,
  1.0,
  1.0,
  0.0033528131778969143,
  2.0,
  6.378137E+6,
  1.0,
  0,
  2000,
  0,
  8,
  16,
  0,
  18,
  36,
  0,
  1099511628,
  1099511628,
  1099511628,
  1099511628,
  2012227627,
  2012227627,
  1.0F,
  0.0F,
  2.0F,
  1.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  0.5F,
  2.0F,

  { 0.0F, 1.0F },
  0.5F,
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,

  { 0.0F, 1.0F },
  0.5F,
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,

  { 0.0F, 1.0F },
  0.5F,
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,

  { 1.0F, 0.0F, 0.0F, 0.0F },
  -1.0F,
  0.001F,
  0.001F,
  0.001F,

  { 1.0F, 0.0F, 0.0F, 0.0F },
  0.002F,
  0.0F,
  4.0F,
  0.002F,
  0.0F,
  2.0F,
  0.002F,
  0.0F,
  1.0F,
  0.0F,
  20.0F,
  0.01F,
  0.003F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.002F,
  14.14F,
  0.002F,
  0.0F,
  100.0F,
  0.0F,
  0.0F,
  0.002F,
  0.0F,
  14.14F,
  0.002F,
  100.0F,
  0.0F,
  0.0F,
  0.002F,
  0.2F,
  0.1F,
  1.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0F, -9.8055F },
  -0.2F,
  0.2F,
  1.0F,
  0.1F,
  2.0F,
  1.0F,
  0.0F,
  0.0F,

  { 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F },
  10.0F,
  -10.0F,
  0.05F,
  0.0F,
  0.0F,
  0.17453292F,
  1.57079637F,
  -1.57079637F,
  0.001F,

  { 0.2F, 0.2F, 0.0F },
  0.002F,
  0.0F,
  -266.532715F,
  35530.5742F,
  0.3F,
  0.2F,
  1.0F,
  0.0F,
  -0.1F,
  9.806F,
  0.5F,
  0.052359879F,
  -0.052359879F,
  3.33333332E-6F,
  -0.00066666666F,
  2.0F,
  1.0F,
  0.05F,
  1.0F,
  0.00174532924F,
  -0.00174532924F,
  0.0F,
  0.002F,
  0.002F,
  0.0F,
  0.87266463F,
  -0.87266463F,
  0.5F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  -1.0F,
  0.999F,
  -0.999F,
  2.0F,
  0.0F,
  1.0F,
  -1.0F,
  -1.0F,
  0.0F,
  1.5F,
  2.0F,
  -1.0F,
  0.0F,

  { 0.0F, 0.0F },
  0.0F,
  0.002F,

  { 0.0F, 0.0F },
  0.0F,
  -1.499547F,
  0.353393257F,
  0.0F,
  0.0F,
  2.121F,
  0.0F,
  0.002F,
  1.5F,
  2.0F,
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.002F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  9.806F,
  0.0F,
  0.002F,
  0.0F,

  { 0.0F, 0.0F },
  0.002F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  273.15F,
  0.0F,
  0.0F,
  120000.0F,
  500.0F,
  -29.2692909F,
  0.7F,
  2.5F,
  1.0F,
  0.0F,
  3.0F,
  0.4F,
  1.0F,
  0.0F,
  0.002F,
  0.0F,
  -266.532715F,
  0.002F,
  35530.5742F,
  0.002F,
  0.0F,
  -266.532715F,
  0.002F,
  35530.5742F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  2.0F,
  1.0F,
  1.0F,
  0.0F,
  1.0F,
  100.0F,
  0.0F,
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  2199023256U,
  2199023256U,
  0U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  75U,
  75U,
  50U,
  50U,
  5U,
  75U,
  50U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  0U,
  1U,
  4294967295U,
  1U,
  1U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  1U,
  1U,
  1U,
  1U,
  1U,
  -18301,
  32768U,
  32768U,
  32768U,
  32768U,
  32768U,
  32768U,
  32768U,
  0U,
  1000U,
  0U,
  125U,
  25U,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  71,
  128U,
  128U,
  128U,
  128U,
  128U,
  128U,
  128U,
  128U,
  1U,
  0U,
  1U,
  0U,
  1U,
  0U,
  0U,
  0U,
  0U,
  0U,
  1U,
  0U
};

/* Block signals (default storage) */
BlockIO_INS_T INS_B;

/* Block states (default storage) */
D_Work_INS_T INS_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_INS_T INS_PrevZCSigState;

/* External inputs (root inport signals with default storage) */
ExternalInputs_INS_T INS_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_INS_T INS_Y;

/* Real-time model */
RT_MODEL_INS_T INS_M_;
RT_MODEL_INS_T *const INS_M = &INS_M_;

/* Model step function */
void INS_step(void)
{
  boolean_T rtb_Delay_d;
  boolean_T rtb_Delay_h;
  uint32_T rtb_DiscreteTimeIntegrator;
  boolean_T rtb_FixPtRelationalOperator_if;
  boolean_T rtb_LogicalOperator3;
  real32_T rtb_Product1_g0;
  int32_T rtb_Saturation2;
  uint8_T rtb_Delay_pa;
  uint8_T rtb_Compare_cl;
  uint8_T rtb_Delay_ci;
  boolean_T rtb_Compare_cio;
  int32_T rtb_Saturation1;
  real32_T rtb_vel_N;
  real32_T rtb_vel_E;
  real32_T rtb_vel_D;
  real_T rtb_Scalefactor1;
  real_T rtb_Scalefactor2;
  real_T rtb_Scalefactor3;
  real32_T rtb_Multiply_j[3];
  boolean_T rtb_Compare_fz;
  real_T rtb_Gain6;
  real32_T rtb_VectorConcatenate_m[9];
  real32_T rtb_DiscreteTimeIntegrator_pm;
  boolean_T rtb_UpperTest_cv;
  uint16_T rtb_Add_kz;
  boolean_T rtb_LogicalOperator1_o;
  real32_T rtb_Divide1_m[3];
  real32_T rtb_ba_O_mDs2[3];
  real32_T rtb_Relay2;
  real32_T rtb_Product3_eb;
  real32_T rtb_TrigonometricFunction1;
  boolean_T rtb_Delay_a;
  boolean_T rtb_Compare_gt;
  boolean_T rtb_LogicalOperator2_o;
  boolean_T rtb_Compare_e;
  boolean_T rtb_Compare_nt;
  boolean_T rtb_Compare_f5;
  boolean_T rtb_Compare_bo;
  real_T rtb_Min;
  real32_T rtb_Switch_er[6];
  boolean_T rtb_Compare_hu;
  boolean_T rtb_Compare_l0;
  real32_T rtb_Sum2_j;
  real32_T rtb_Sum4_k;
  real32_T rtb_MatrixConcatenate[3];
  real32_T rtb_Add_m;
  real32_T rtb_Sum_g0[6];
  real32_T rtb_Saturation_ad;
  real32_T rtb_Inclination;
  real32_T rtb_uT[3];
  boolean_T rtb_AND_e[3];
  real32_T rtb_Product1_n[3];
  boolean_T rtb_AND_ej[3];
  real32_T rtb_DiscreteTimeIntegrator_g[3];
  real32_T rtb_Switch3[3];
  real32_T rtb_Transpose2[9];
  real32_T rtb_Multiply_j_0[3];
  real32_T tmp[6];
  int32_T i;
  real32_T rtb_Multiply_g1;
  real_T rtb_WGS84_pos_ref_j_idx_0;
  real32_T rtb_vel_NE_0_idx_0;
  real32_T rtb_vel_NE_0_idx_1;
  real32_T rtb_Square_l_idx_0;
  real32_T rtb_Square_l_idx_1;
  real32_T rtb_delay_acc_O_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_c_id;
  real32_T rtb_DiscreteTimeIntegrator_c__0;
  real_T rtb_WGS84_derivatives_ref_idx_0;
  real_T rtb_WGS84_derivatives_ref_idx_1;
  real32_T rtb_VectorConcatenate_idx_0;
  real32_T rtb_VectorConcatenate_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_c__1;
  real32_T rtb_delay_acc_O_idx_2;
  uint32_T qY;
  uint32_T qY_0;
  int32_T rtb_Saturation1_0;
  uint16_T rtb_Add_i;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
  /* Outputs for Atomic SubSystem: '<S3>/Baro_Process' */
  /* Logic: '<S283>/Logical Operator' incorporates:
   *  Constant: '<S292>/Lower Limit'
   *  Constant: '<S292>/Upper Limit'
   *  Constant: '<S293>/Lower Limit'
   *  Constant: '<S293>/Upper Limit'
   *  Inport: '<Root>/Barometer'
   *  Logic: '<S292>/AND'
   *  Logic: '<S293>/AND'
   *  RelationalOperator: '<S292>/Lower Test'
   *  RelationalOperator: '<S292>/Upper Test'
   *  RelationalOperator: '<S293>/Lower Test'
   *  RelationalOperator: '<S293>/Upper Test'
   */
  rtb_Delay_d = ((INS_P.Relative_Height_pressure_min < INS_U.Barometer.pressure)
                 && (INS_U.Barometer.pressure <
                     INS_P.Relative_Height_pressure_max) &&
                 ((INS_P.Relative_Height_temp_min < INS_U.Barometer.temperature)
                  && (INS_U.Barometer.temperature <
                      INS_P.Relative_Height_temp_max)));

  /* RelationalOperator: '<S291>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Barometer'
   *  UnitDelay: '<S291>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_if = (INS_U.Barometer.timestamp !=
    INS_DWork.DelayInput1_DSTATE_g);

  /* Sum: '<S283>/Sum1' incorporates:
   *  Constant: '<S285>/Constant'
   *  Constant: '<S290>/Constant'
   *  Delay: '<S283>/Delay'
   *  Logic: '<S283>/Logical Operator1'
   *  Logic: '<S283>/Logical Operator2'
   *  Logic: '<S283>/Logical Operator5'
   *  RelationalOperator: '<S285>/Compare'
   *  RelationalOperator: '<S290>/Compare'
   */
  rtb_Saturation1 = (((rtb_Delay_d && rtb_FixPtRelationalOperator_if) ||
                      (INS_DWork.Delay_DSTATE_f > INS_P.Constant_Value_in)) &&
                     (INS_DWork.Delay_DSTATE_f <
                      INS_P.CompareToConstant_const_pt));
  qY_0 = rtb_Saturation1 + INS_DWork.Delay_DSTATE_f;
  if (qY_0 < (uint32_T)rtb_Saturation1) {
    qY_0 = MAX_uint32_T;
  }

  /* DiscreteIntegrator: '<S283>/Discrete-Time Integrator' */
  if (rtb_FixPtRelationalOperator_if) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev =
      INS_P.DiscreteTimeIntegrator_IC_dv;
  }

  /* Logic: '<S283>/Logical Operator3' incorporates:
   *  Constant: '<S286>/Constant'
   *  Constant: '<S288>/Constant'
   *  RelationalOperator: '<S286>/Compare'
   *  RelationalOperator: '<S288>/Compare'
   *  Sum: '<S283>/Sum1'
   */
  rtb_LogicalOperator3 = ((qY_0 >= INS_P.Relative_Height_s_first) && (qY_0 <=
    INS_P.Relative_Height_s_last));

  /* Logic: '<S283>/Logical Operator4' incorporates:
   *  Constant: '<S287>/Constant'
   *  Constant: '<S289>/Constant'
   *  DiscreteIntegrator: '<S283>/Discrete-Time Integrator'
   *  RelationalOperator: '<S287>/Compare'
   *  RelationalOperator: '<S289>/Compare'
   *  Sum: '<S283>/Sum1'
   */
  rtb_FixPtRelationalOperator_if = ((qY_0 > INS_P.Relative_Height_s_last) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_ev < INS_P.CompareToConstant4_const)
    && rtb_Delay_d);

  /* Outputs for Enabled SubSystem: '<S281>/Reference_and_Derivative' incorporates:
   *  EnablePort: '<S284>/Enable'
   */
  if (rtb_LogicalOperator3) {
    if (!INS_DWork.Reference_and_Derivative_MODE) {
      /* InitializeConditions for Delay: '<S284>/Delay' */
      INS_DWork.Delay_DSTATE_d = INS_P.Delay_InitialCondition_p;

      /* InitializeConditions for Delay: '<S284>/Delay1' */
      INS_DWork.Delay1_DSTATE_i = INS_P.Delay1_InitialCondition_k;

      /* InitializeConditions for Delay: '<S284>/Delay2' */
      INS_DWork.Delay2_DSTATE = INS_P.Delay2_InitialCondition;
      INS_DWork.Reference_and_Derivative_MODE = true;
    }

    /* Sum: '<S284>/Sum2' incorporates:
     *  Delay: '<S284>/Delay'
     *  Inport: '<Root>/Barometer'
     */
    rtb_Sum2_j = INS_U.Barometer.pressure + INS_DWork.Delay_DSTATE_d;

    /* Sum: '<S284>/Sum1' incorporates:
     *  Constant: '<S284>/Constant1'
     *  Delay: '<S284>/Delay1'
     */
    qY = INS_P.Constant1_Value_f5 + INS_DWork.Delay1_DSTATE_i;
    if (qY < INS_P.Constant1_Value_f5) {
      qY = MAX_uint32_T;
    }

    /* Saturate: '<S284>/Saturation1' incorporates:
     *  Sum: '<S284>/Sum1'
     */
    if (qY > INS_P.Saturation1_UpperSat_n) {
      rtb_DiscreteTimeIntegrator = INS_P.Saturation1_UpperSat_n;
    } else if (qY < INS_P.Saturation1_LowerSat_m) {
      rtb_DiscreteTimeIntegrator = INS_P.Saturation1_LowerSat_m;
    } else {
      rtb_DiscreteTimeIntegrator = qY;
    }

    /* End of Saturate: '<S284>/Saturation1' */

    /* Product: '<S284>/Divide' */
    INS_B.Divide = rtb_Sum2_j / (real32_T)rtb_DiscreteTimeIntegrator;

    /* Sum: '<S284>/Sum4' incorporates:
     *  Constant: '<S284>/Constant2'
     *  Delay: '<S284>/Delay2'
     *  Inport: '<Root>/Barometer'
     *  Sum: '<S284>/Sum3'
     */
    rtb_Sum4_k = (INS_P.Constant2_Value_p + INS_U.Barometer.temperature) +
      INS_DWork.Delay2_DSTATE;

    /* Saturate: '<S284>/Saturation' */
    if (INS_B.Divide > INS_P.Saturation_UpperSat_m) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation_UpperSat_m;
    } else if (INS_B.Divide < INS_P.Saturation_LowerSat_h) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation_LowerSat_h;
    } else {
      rtb_delay_acc_O_idx_2 = INS_B.Divide;
    }

    /* End of Saturate: '<S284>/Saturation' */

    /* Gain: '<S284>/gain' incorporates:
     *  Product: '<S284>/Divide1'
     *  Product: '<S284>/Product'
     */
    INS_B.gain = 1.0F / rtb_delay_acc_O_idx_2 * (rtb_Sum4_k / (real32_T)
      rtb_DiscreteTimeIntegrator) * INS_P.gain_Gain;

    /* Update for Delay: '<S284>/Delay' */
    INS_DWork.Delay_DSTATE_d = rtb_Sum2_j;

    /* Update for Delay: '<S284>/Delay1' incorporates:
     *  Sum: '<S284>/Sum1'
     */
    INS_DWork.Delay1_DSTATE_i = qY;

    /* Update for Delay: '<S284>/Delay2' */
    INS_DWork.Delay2_DSTATE = rtb_Sum4_k;
  } else {
    if (INS_DWork.Reference_and_Derivative_MODE) {
      INS_DWork.Reference_and_Derivative_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S281>/Reference_and_Derivative' */

  /* Switch: '<S281>/Switch' incorporates:
   *  Inport: '<Root>/Barometer'
   *  Logic: '<S281>/Logical Operator1'
   *  Logic: '<S281>/Logical Operator2'
   */
  if (rtb_LogicalOperator3 || (!rtb_FixPtRelationalOperator_if)) {
    rtb_Sum2_j = INS_U.Barometer.pressure;
  } else {
    rtb_Sum2_j = INS_B.Divide;
  }

  /* End of Switch: '<S281>/Switch' */

  /* Product: '<S281>/Product1' incorporates:
   *  Inport: '<Root>/Barometer'
   *  Sum: '<S281>/Sum2'
   */
  rtb_Product1_g0 = (INS_U.Barometer.pressure - rtb_Sum2_j) * INS_B.gain;

  /* Update for Delay: '<S283>/Delay' incorporates:
   *  Sum: '<S283>/Sum1'
   */
  INS_DWork.Delay_DSTATE_f = qY_0;

  /* Update for UnitDelay: '<S291>/Delay Input1' incorporates:
   *  Inport: '<Root>/Barometer'
   */
  INS_DWork.DelayInput1_DSTATE_g = INS_U.Barometer.timestamp;

  /* Update for DiscreteIntegrator: '<S283>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S283>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_ev +
    (real32_T)INS_EXPORT.period;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev = (uint32_T)rtb_delay_acc_O_idx_2;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S283>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/Baro_Process' */

  /* Outputs for Atomic SubSystem: '<S3>/GPS_Process' */
  /* RelationalOperator: '<S309>/Compare' incorporates:
   *  Constant: '<S309>/Constant'
   *  UnitDelay: '<S308>/Unit Delay'
   */
  rtb_Delay_d = (INS_DWork.UnitDelay_DSTATE >= INS_P.CompareToConstant3_const);

  /* RelationalOperator: '<S306>/Compare' incorporates:
   *  Constant: '<S306>/Constant'
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Delay_pa = (uint8_T)(INS_U.GPS_uBlox.fixType ==
    INS_P.CompareToConstant1_const_n);

  /* DiscreteIntegrator: '<S304>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   *  RelationalOperator: '<S310>/FixPt Relational Operator'
   *  UnitDelay: '<S310>/Delay Input1'
   */
  if (INS_U.GPS_uBlox.timestamp != INS_DWork.DelayInput1_DSTATE_i) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_p;
  }

  /* RelationalOperator: '<S307>/Compare' incorporates:
   *  Constant: '<S307>/Constant'
   *  DiscreteIntegrator: '<S304>/Discrete-Time Integrator'
   */
  rtb_Compare_cl = (uint8_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
    INS_P.CompareToConstant2_const_a);

  /* Sum: '<S301>/Sum1' incorporates:
   *  Logic: '<S301>/Logical Operator1'
   */
  rtb_Delay_ci = (uint8_T)((uint32_T)(rtb_Delay_d && (rtb_Delay_pa != 0) &&
    (rtb_Compare_cl != 0)) + rtb_Delay_d);

  /* RelationalOperator: '<S294>/Compare' incorporates:
   *  Constant: '<S294>/Constant'
   */
  rtb_LogicalOperator3 = (rtb_Delay_ci > INS_P.CompareToConstant_const_i);

  /* RelationalOperator: '<S295>/Compare' incorporates:
   *  Constant: '<S295>/Constant'
   */
  rtb_Compare_cio = (rtb_Delay_ci < INS_P.CompareToConstant1_const_l);

  /* RelationalOperator: '<S299>/Compare' incorporates:
   *  Constant: '<S299>/Constant'
   */
  rtb_Delay_d = (rtb_Delay_ci > INS_P.CompareToConstant2_const_bv);

  /* RelationalOperator: '<S300>/Compare' incorporates:
   *  Constant: '<S300>/Constant'
   *  DiscreteIntegrator: '<S304>/Discrete-Time Integrator'
   */
  rtb_Delay_h = (INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
                 INS_P.CompareToConstant4_const_e);

  /* Gain: '<S303>/Gain3' incorporates:
   *  Constant: '<S303>/Constant7'
   *  Gain: '<S303>/Gain5'
   *  Inport: '<Root>/GPS_uBlox'
   *  Sum: '<S303>/Sum'
   */
  rtb_Square_l_idx_1 = (INS_P.Constant7_Value - (real32_T)INS_P.Gain5_Gain_a *
                        4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.sAcc) *
    INS_P.Gain3_Gain_lx;

  /* Product: '<S296>/Double' incorporates:
   *  Saturate: '<S296>/Saturation'
   */
  rtb_Sum2_j = rtb_Delay_d ? rtb_Delay_h ? rtb_Square_l_idx_1 >
    INS_P.Saturation_UpperSat_l ? INS_P.Saturation_UpperSat_l :
    rtb_Square_l_idx_1 < INS_P.Saturation_LowerSat_ku ?
    INS_P.Saturation_LowerSat_ku : rtb_Square_l_idx_1 : 0.0F : 0.0F;

  /* Gain: '<S302>/Gain2' incorporates:
   *  Constant: '<S302>/Constant1'
   *  Gain: '<S302>/Gain1'
   *  Inport: '<Root>/GPS_uBlox'
   *  Sum: '<S302>/Sum1'
   */
  rtb_Square_l_idx_1 = (INS_P.Constant1_Value_g5 - (real32_T)INS_P.Gain1_Gain_p *
                        4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.hAcc) *
    INS_P.Gain2_Gain_p;

  /* Product: '<S296>/Double1' incorporates:
   *  Saturate: '<S296>/Saturation1'
   */
  rtb_Sum4_k = rtb_Delay_d ? rtb_Delay_h ? rtb_Square_l_idx_1 >
    INS_P.Saturation1_UpperSat_m ? INS_P.Saturation1_UpperSat_m :
    rtb_Square_l_idx_1 < INS_P.Saturation1_LowerSat_d ?
    INS_P.Saturation1_LowerSat_d : rtb_Square_l_idx_1 : 0.0F : 0.0F;

  /* Gain: '<S297>/Gain' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_vel_N = (real32_T)INS_P.Gain_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velN;

  /* Gain: '<S297>/Gain1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_vel_E = (real32_T)INS_P.Gain1_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velE;

  /* Gain: '<S297>/Gain2' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_vel_D = (real32_T)INS_P.Gain2_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velD;

  /* Gain: '<S297>/Scalefactor1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor1 = (real_T)INS_P.Scalefactor1_Gain_d * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lat;

  /* Gain: '<S297>/Scalefactor2' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor2 = (real_T)INS_P.Scalefactor2_Gain * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lon;

  /* Gain: '<S297>/Scalefactor3' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor3 = (real_T)INS_P.Scalefactor3_Gain * 9.0949470177292824E-13 *
    (real_T)INS_U.GPS_uBlox.height;

  /* Outputs for Triggered SubSystem: '<S275>/WGS84_Model' incorporates:
   *  TriggerPort: '<S298>/Trigger'
   */
  if (rtb_LogicalOperator3 && (INS_PrevZCSigState.WGS84_Model_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Gain: '<S298>/Scalefactor' */
    INS_B.Scalefactor = INS_P.Scalefactor_Gain * rtb_Scalefactor2;

    /* SignalConversion: '<S298>/OutportBufferFordz_dh' incorporates:
     *  Constant: '<S311>/constant1'
     */
    INS_B.OutportBufferFordz_dh = INS_P.constant1_Value;

    /* Gain: '<S298>/Scalefactor1' */
    INS_B.Scalefactor1 = INS_P.Scalefactor1_Gain * rtb_Scalefactor1;

    /* Trigonometry: '<S311>/Trigonometric Function1' incorporates:
     *  Trigonometry: '<S311>/Trigonometric Function2'
     */
    rtb_WGS84_pos_ref_j_idx_0 = cos(INS_B.Scalefactor1);

    /* Product: '<S311>/Product1' incorporates:
     *  Constant: '<S311>/constant'
     *  Constant: '<S311>/f'
     *  Sum: '<S311>/Subtract1'
     */
    rtb_Gain6 = (INS_P.constant_Value - INS_P.f_Value) * INS_P.f_Value;

    /* Trigonometry: '<S311>/Trigonometric Function' */
    rtb_Min = sin(INS_B.Scalefactor1);

    /* Sum: '<S311>/Subtract' incorporates:
     *  Constant: '<S311>/a1'
     *  Math: '<S311>/u^2'
     *  Product: '<S311>/Product'
     */
    rtb_Min = INS_P.a1_Value - rtb_Min * rtb_Min * rtb_Gain6;

    /* Math: '<S311>/sqrt'
     *
     * About '<S311>/sqrt':
     *  Operator: sqrt
     */
    if (rtb_Min < 0.0) {
      rtb_Min = -sqrt(fabs(rtb_Min));
    } else {
      rtb_Min = sqrt(rtb_Min);
    }

    /* End of Math: '<S311>/sqrt' */

    /* Product: '<S311>/Divide' incorporates:
     *  Constant: '<S311>/a'
     */
    rtb_Min = INS_P.a_Value / rtb_Min;

    /* Sum: '<S311>/Add' incorporates:
     *  Constant: '<S311>/constant2'
     *  Math: '<S311>/u^1'
     *  Product: '<S311>/Product2'
     *  Product: '<S311>/Product3'
     *  Sum: '<S311>/Subtract2'
     *  Trigonometry: '<S311>/Trigonometric Function1'
     */
    INS_B.Add = (INS_P.constant2_Value - rtb_WGS84_pos_ref_j_idx_0 *
                 rtb_WGS84_pos_ref_j_idx_0 * rtb_Gain6) * rtb_Min +
      rtb_Scalefactor3;

    /* Product: '<S311>/Product4' incorporates:
     *  Sum: '<S311>/Add1'
     */
    INS_B.Product4 = (rtb_Scalefactor3 + rtb_Min) * rtb_WGS84_pos_ref_j_idx_0;
  }

  INS_PrevZCSigState.WGS84_Model_Trig_ZCE = rtb_LogicalOperator3;

  /* End of Outputs for SubSystem: '<S275>/WGS84_Model' */

  /* Sum: '<S308>/Sum' incorporates:
   *  Constant: '<S305>/Constant'
   *  Inport: '<Root>/GPS_uBlox'
   *  Logic: '<S301>/Logical Operator'
   *  RelationalOperator: '<S305>/Compare'
   *  UnitDelay: '<S308>/Unit Delay'
   */
  rtb_Saturation1 = ((INS_U.GPS_uBlox.hAcc < INS_P.CompareToConstant_const_d) &&
                     (rtb_Delay_pa != 0) && (rtb_Compare_cl != 0)) +
    INS_DWork.UnitDelay_DSTATE;

  /* Saturate: '<S308>/Saturation' */
  if (rtb_Saturation1 > INS_P.Saturation_UpperSat_a) {
    /* Update for UnitDelay: '<S308>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_UpperSat_a;
  } else if (rtb_Saturation1 < INS_P.Saturation_LowerSat) {
    /* Update for UnitDelay: '<S308>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_LowerSat;
  } else {
    /* Update for UnitDelay: '<S308>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = rtb_Saturation1;
  }

  /* End of Saturate: '<S308>/Saturation' */

  /* Update for UnitDelay: '<S310>/Delay Input1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  INS_DWork.DelayInput1_DSTATE_i = INS_U.GPS_uBlox.timestamp;

  /* Update for DiscreteIntegrator: '<S304>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S304>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_i +
    (real32_T)INS_EXPORT.period;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i = (uint32_T)rtb_delay_acc_O_idx_2;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S304>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/GPS_Process' */

  /* Outputs for Atomic SubSystem: '<S3>/IMU_Process' */
  /* Switch: '<S323>/Switch' incorporates:
   *  Constant: '<S323>/Constant'
   *  Constant: '<S323>/Gyr_RotMatrix'
   *  Inport: '<Root>/IMU1'
   *  Product: '<S323>/Product1'
   *  SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn3'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch_Threshold_c) {
    rtb_uT[0] = INS_U.IMU1.gyr_x;
    rtb_uT[1] = INS_U.IMU1.gyr_y;
    rtb_uT[2] = INS_U.IMU1.gyr_z;
  } else {
    /* Sum: '<S323>/Subtract' incorporates:
     *  Constant: '<S323>/Gyro_Bias'
     *  Inport: '<Root>/IMU1'
     *  SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn1'
     *  SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn2'
     *  SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn3'
     */
    rtb_VectorConcatenate_idx_0 = INS_U.IMU1.gyr_x - INS_PARAM.GyroBias[0];
    rtb_VectorConcatenate_idx_1 = INS_U.IMU1.gyr_y - INS_PARAM.GyroBias[1];
    rtb_Product3_eb = INS_U.IMU1.gyr_z - INS_PARAM.GyroBias[2];
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
      rtb_uT[rtb_Saturation1] = INS_PARAM.GyroRotMat[rtb_Saturation1 + 6] *
        rtb_Product3_eb + (INS_PARAM.GyroRotMat[rtb_Saturation1 + 3] *
                           rtb_VectorConcatenate_idx_1 +
                           INS_PARAM.GyroRotMat[rtb_Saturation1] *
                           rtb_VectorConcatenate_idx_0);
    }
  }

  /* End of Switch: '<S323>/Switch' */

  /* Switch: '<S322>/Switch' incorporates:
   *  Constant: '<S322>/Acc_RotMatrix'
   *  Constant: '<S322>/Constant'
   *  Inport: '<Root>/IMU1'
   *  Product: '<S322>/Product5'
   *  SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In3'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch_Threshold_k) {
    rtb_Product1_n[0] = INS_U.IMU1.acc_x;
    rtb_Product1_n[1] = INS_U.IMU1.acc_y;
    rtb_Product1_n[2] = INS_U.IMU1.acc_z;
  } else {
    /* Sum: '<S322>/Subtract1' incorporates:
     *  Constant: '<S322>/Acc_Bias'
     *  Inport: '<Root>/IMU1'
     *  SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In1'
     *  SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In2'
     *  SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In3'
     */
    rtb_VectorConcatenate_idx_0 = INS_U.IMU1.acc_x - INS_PARAM.AccBias[0];
    rtb_VectorConcatenate_idx_1 = INS_U.IMU1.acc_y - INS_PARAM.AccBias[1];
    rtb_Product3_eb = INS_U.IMU1.acc_z - INS_PARAM.AccBias[2];
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
      rtb_Product1_n[rtb_Saturation1] = INS_PARAM.AccRotMat[rtb_Saturation1 + 6]
        * rtb_Product3_eb + (INS_PARAM.AccRotMat[rtb_Saturation1 + 3] *
        rtb_VectorConcatenate_idx_1 + INS_PARAM.AccRotMat[rtb_Saturation1] *
        rtb_VectorConcatenate_idx_0);
    }
  }

  /* End of Switch: '<S322>/Switch' */

  /* DiscreteIntegrator: '<S314>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/IMU1'
   *  RelationalOperator: '<S325>/FixPt Relational Operator'
   *  UnitDelay: '<S325>/Delay Input1'
   */
  if (INS_U.IMU1.timestamp != INS_DWork.DelayInput1_DSTATE_h) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lp =
      INS_P.DiscreteTimeIntegrator_IC_b;
  }

  /* Logic: '<S314>/Logical Operator4' incorporates:
   *  Constant: '<S324>/Constant'
   *  Constant: '<S326>/Lower Limit'
   *  Constant: '<S326>/Upper Limit'
   *  Constant: '<S327>/Lower Limit'
   *  Constant: '<S327>/Upper Limit'
   *  DiscreteIntegrator: '<S314>/Discrete-Time Integrator'
   *  Logic: '<S314>/Logical Operator'
   *  Logic: '<S314>/Logical Operator1'
   *  Logic: '<S314>/Logical Operator2'
   *  Logic: '<S326>/AND'
   *  Logic: '<S327>/AND'
   *  RelationalOperator: '<S324>/Compare'
   *  RelationalOperator: '<S326>/Lower Test'
   *  RelationalOperator: '<S326>/Upper Test'
   *  RelationalOperator: '<S327>/Lower Test'
   *  RelationalOperator: '<S327>/Upper Test'
   */
  rtb_Delay_d = ((INS_P.IMU1_Valid_Check_gyr_min < rtb_uT[0]) && (rtb_uT[0] <
    INS_P.IMU1_Valid_Check_gyr_max) && ((INS_P.IMU1_Valid_Check_gyr_min <
    rtb_uT[1]) && (rtb_uT[1] < INS_P.IMU1_Valid_Check_gyr_max)) &&
                 ((INS_P.IMU1_Valid_Check_gyr_min < rtb_uT[2]) && (rtb_uT[2] <
    INS_P.IMU1_Valid_Check_gyr_max)) && ((INS_P.IMU1_Valid_Check_acc_min <
    rtb_Product1_n[0]) && (rtb_Product1_n[0] < INS_P.IMU1_Valid_Check_acc_max) &&
    ((INS_P.IMU1_Valid_Check_acc_min < rtb_Product1_n[1]) && (rtb_Product1_n[1] <
    INS_P.IMU1_Valid_Check_acc_max)) && ((INS_P.IMU1_Valid_Check_acc_min <
    rtb_Product1_n[2]) && (rtb_Product1_n[2] < INS_P.IMU1_Valid_Check_acc_max)))
                 && (INS_DWork.DiscreteTimeIntegrator_DSTAT_lp <
                     INS_P.IMU1_Valid_Check_timeout));

  /* Sum: '<S329>/Subtract' incorporates:
   *  Constant: '<S329>/Gyro_Bias'
   *  Inport: '<Root>/IMU2'
   *  SignalConversion: '<S315>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S315>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S315>/ConcatBufferAtVector ConcatenateIn3'
   */
  rtb_VectorConcatenate_idx_0 = INS_U.IMU2.gyr_x - INS_PARAM.GyroBias2[0];
  rtb_VectorConcatenate_idx_1 = INS_U.IMU2.gyr_y - INS_PARAM.GyroBias2[1];
  rtb_Product3_eb = INS_U.IMU2.gyr_z - INS_PARAM.GyroBias2[2];

  /* SignalConversion: '<S315>/ConcatBufferAtVector Concatenate1In1' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  rtb_Multiply_j[0] = INS_U.IMU2.acc_x;

  /* SignalConversion: '<S315>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  rtb_Multiply_j[1] = INS_U.IMU2.acc_y;

  /* SignalConversion: '<S315>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  rtb_Multiply_j[2] = INS_U.IMU2.acc_z;
  for (i = 0; i < 3; i++) {
    /* Product: '<S329>/Product1' incorporates:
     *  Constant: '<S329>/Gyr_RotMatrix'
     */
    rtb_Square_l_idx_0 = INS_PARAM.GyroRotMat2[i + 6] * rtb_Product3_eb +
      (INS_PARAM.GyroRotMat2[i + 3] * rtb_VectorConcatenate_idx_1 +
       INS_PARAM.GyroRotMat2[i] * rtb_VectorConcatenate_idx_0);

    /* Logic: '<S333>/AND' incorporates:
     *  Constant: '<S333>/Lower Limit'
     *  Constant: '<S333>/Upper Limit'
     *  RelationalOperator: '<S333>/Lower Test'
     *  RelationalOperator: '<S333>/Upper Test'
     */
    rtb_AND_e[i] = ((INS_P.IMU2_Valid_Check_gyr_min < rtb_Square_l_idx_0) &&
                    (rtb_Square_l_idx_0 < INS_P.IMU2_Valid_Check_gyr_max));

    /* Sum: '<S328>/Subtract1' incorporates:
     *  Constant: '<S328>/Acc_Bias'
     */
    rtb_Multiply_j_0[i] = rtb_Multiply_j[i] - INS_PARAM.AccBias2[i];

    /* Product: '<S329>/Product1' incorporates:
     *  Constant: '<S329>/Gyr_RotMatrix'
     */
    rtb_Divide1_m[i] = rtb_Square_l_idx_0;
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S328>/Product5' incorporates:
     *  Constant: '<S328>/Acc_RotMatrix'
     */
    rtb_VectorConcatenate_idx_0 = INS_PARAM.AccRotMat2[i + 6] *
      rtb_Multiply_j_0[2] + (INS_PARAM.AccRotMat2[i + 3] * rtb_Multiply_j_0[1] +
      INS_PARAM.AccRotMat2[i] * rtb_Multiply_j_0[0]);

    /* Logic: '<S332>/AND' incorporates:
     *  Constant: '<S332>/Lower Limit'
     *  Constant: '<S332>/Upper Limit'
     *  RelationalOperator: '<S332>/Lower Test'
     *  RelationalOperator: '<S332>/Upper Test'
     */
    rtb_AND_ej[i] = ((INS_P.IMU2_Valid_Check_acc_min <
                      rtb_VectorConcatenate_idx_0) &&
                     (rtb_VectorConcatenate_idx_0 <
                      INS_P.IMU2_Valid_Check_acc_max));

    /* Product: '<S328>/Product5' incorporates:
     *  Constant: '<S328>/Acc_RotMatrix'
     */
    rtb_ba_O_mDs2[i] = rtb_VectorConcatenate_idx_0;
  }

  /* DiscreteIntegrator: '<S316>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/IMU2'
   *  RelationalOperator: '<S331>/FixPt Relational Operator'
   *  UnitDelay: '<S331>/Delay Input1'
   */
  if (INS_U.IMU2.timestamp != INS_DWork.DelayInput1_DSTATE_ht) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_IC_pw;
  }

  /* Sum: '<S319>/Sum' incorporates:
   *  Constant: '<S330>/Constant'
   *  DiscreteIntegrator: '<S316>/Discrete-Time Integrator'
   *  Gain: '<S319>/Gain'
   *  Logic: '<S316>/Logical Operator'
   *  Logic: '<S316>/Logical Operator1'
   *  Logic: '<S316>/Logical Operator2'
   *  Logic: '<S316>/Logical Operator4'
   *  RelationalOperator: '<S330>/Compare'
   */
  rtb_Delay_pa = (uint8_T)((uint32_T)(rtb_AND_e[0] && rtb_AND_e[1] && rtb_AND_e
    [2] && (rtb_AND_ej[0] && rtb_AND_ej[1] && rtb_AND_ej[2]) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_d < INS_P.IMU2_Valid_Check_timeout)
    ? (int32_T)((uint32_T)INS_P.Gain_Gain_od >> 6) : 0) + rtb_Delay_d);

  /* RelationalOperator: '<S317>/Compare' incorporates:
   *  Constant: '<S317>/Constant'
   */
  rtb_Compare_fz = (rtb_Delay_pa > INS_P.Constant_Value_jn);

  /* DiscreteIntegrator: '<S320>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_g[0] = INS_DWork.DiscreteTimeIntegrator_DSTATE[0];

  /* Switch: '<S318>/Switch' */
  if (!rtb_Delay_d) {
    rtb_uT[0] = rtb_Divide1_m[0];
    rtb_uT[1] = rtb_Divide1_m[1];
  }

  /* DiscreteIntegrator: '<S320>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_g[1] = INS_DWork.DiscreteTimeIntegrator_DSTATE[1];

  /* Switch: '<S318>/Switch' */
  rtb_Saturation_ad = rtb_uT[2];

  /* DiscreteIntegrator: '<S320>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_g[2] = INS_DWork.DiscreteTimeIntegrator_DSTATE[2];

  /* Switch: '<S318>/Switch' */
  if (!rtb_Delay_d) {
    rtb_Saturation_ad = rtb_Divide1_m[2];
  }

  /* DiscreteIntegrator: '<S320>/Discrete-Time Integrator1' */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uT[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uT[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] = rtb_Saturation_ad;
  }

  /* DiscreteIntegrator: '<S321>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_c_id = INS_DWork.DiscreteTimeIntegrator_DSTATE_c[0];

  /* Switch: '<S318>/Switch1' */
  if (!rtb_Delay_d) {
    rtb_Product1_n[0] = rtb_ba_O_mDs2[0];
    rtb_Product1_n[1] = rtb_ba_O_mDs2[1];
  }

  /* DiscreteIntegrator: '<S321>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_c__0 = INS_DWork.DiscreteTimeIntegrator_DSTATE_c[1];

  /* Switch: '<S318>/Switch1' */
  rtb_Relay2 = rtb_Product1_n[2];

  /* DiscreteIntegrator: '<S321>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_c__1 = INS_DWork.DiscreteTimeIntegrator_DSTATE_c[2];

  /* Switch: '<S318>/Switch1' */
  if (!rtb_Delay_d) {
    rtb_Relay2 = rtb_ba_O_mDs2[2];
  }

  /* DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_a != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[0] = rtb_Product1_n[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[1] = rtb_Product1_n[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[2] = rtb_Relay2;
  }

  /* Update for UnitDelay: '<S325>/Delay Input1' incorporates:
   *  Inport: '<Root>/IMU1'
   */
  INS_DWork.DelayInput1_DSTATE_h = INS_U.IMU1.timestamp;

  /* Update for DiscreteIntegrator: '<S314>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S314>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_lp +
    (real32_T)INS_EXPORT.period;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lp = (uint32_T)rtb_delay_acc_O_idx_2;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lp = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S314>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S331>/Delay Input1' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  INS_DWork.DelayInput1_DSTATE_ht = INS_U.IMU2.timestamp;

  /* Update for DiscreteIntegrator: '<S316>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S316>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_d +
    (real32_T)INS_EXPORT.period;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d = (uint32_T)rtb_delay_acc_O_idx_2;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S316>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_a = 0U;

  /* Switch: '<S318>/Switch2' incorporates:
   *  Constant: '<S318>/Constant'
   *  DiscreteIntegrator: '<S320>/Discrete-Time Integrator1'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch2_Threshold) {
    rtb_VectorConcatenate_idx_0 = rtb_uT[0];
  } else {
    rtb_VectorConcatenate_idx_0 = INS_DWork.DiscreteTimeIntegrator1_DSTATE[0];
  }

  /* Switch: '<S318>/Switch3' incorporates:
   *  Constant: '<S318>/Constant'
   *  DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch3_Threshold) {
    rtb_Switch3[0] = rtb_Product1_n[0];
  } else {
    rtb_Switch3[0] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[0];
  }

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S320>/Discrete-Time Integrator1'
   *  Gain: '<S320>/Gain'
   *  Gain: '<S320>/Gain1'
   *  Sum: '<S320>/Add'
   *  Sum: '<S320>/Sum'
   *  Switch: '<S318>/Switch2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE[0] += ((rtb_uT[0] -
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]) * INS_P.Gain_Gain_mz +
    INS_P.Gain1_Gain_kl * INS_DWork.DiscreteTimeIntegrator_DSTATE[0]) *
    INS_P.DiscreteTimeIntegrator_gainv_kc;

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_i * rtb_DiscreteTimeIntegrator_g[0];

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
   *  Gain: '<S321>/Gain'
   *  Gain: '<S321>/Gain1'
   *  Sum: '<S321>/Add'
   *  Sum: '<S321>/Sum'
   *  Switch: '<S318>/Switch3'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_c[0] += ((rtb_Product1_n[0] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[0]) * INS_P.Gain_Gain_m2 +
    INS_P.Gain1_Gain_e1 * INS_DWork.DiscreteTimeIntegrator_DSTATE_c[0]) *
    INS_P.DiscreteTimeIntegrator_gainv_mk;

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_p * rtb_DiscreteTimeIntegrator_c_id;

  /* Switch: '<S318>/Switch2' incorporates:
   *  Constant: '<S318>/Constant'
   *  DiscreteIntegrator: '<S320>/Discrete-Time Integrator1'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch2_Threshold) {
    rtb_VectorConcatenate_idx_1 = rtb_uT[1];
  } else {
    rtb_VectorConcatenate_idx_1 = INS_DWork.DiscreteTimeIntegrator1_DSTATE[1];
  }

  /* Switch: '<S318>/Switch3' incorporates:
   *  Constant: '<S318>/Constant'
   *  DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch3_Threshold) {
    rtb_Switch3[1] = rtb_Product1_n[1];
  } else {
    rtb_Switch3[1] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[1];
  }

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S320>/Discrete-Time Integrator1'
   *  Gain: '<S320>/Gain'
   *  Gain: '<S320>/Gain1'
   *  Sum: '<S320>/Add'
   *  Sum: '<S320>/Sum'
   *  Switch: '<S318>/Switch2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE[1] += ((rtb_uT[1] -
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1]) * INS_P.Gain_Gain_mz +
    INS_P.Gain1_Gain_kl * INS_DWork.DiscreteTimeIntegrator_DSTATE[1]) *
    INS_P.DiscreteTimeIntegrator_gainv_kc;

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_i * rtb_DiscreteTimeIntegrator_g[1];

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
   *  Gain: '<S321>/Gain'
   *  Gain: '<S321>/Gain1'
   *  Sum: '<S321>/Add'
   *  Sum: '<S321>/Sum'
   *  Switch: '<S318>/Switch3'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_c[1] += ((rtb_Product1_n[1] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[1]) * INS_P.Gain_Gain_m2 +
    INS_P.Gain1_Gain_e1 * INS_DWork.DiscreteTimeIntegrator_DSTATE_c[1]) *
    INS_P.DiscreteTimeIntegrator_gainv_mk;

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_p * rtb_DiscreteTimeIntegrator_c__0;

  /* Switch: '<S318>/Switch2' incorporates:
   *  Constant: '<S318>/Constant'
   *  DiscreteIntegrator: '<S320>/Discrete-Time Integrator1'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch2_Threshold) {
    rtb_Product3_eb = rtb_Saturation_ad;
  } else {
    rtb_Product3_eb = INS_DWork.DiscreteTimeIntegrator1_DSTATE[2];
  }

  /* Switch: '<S318>/Switch3' incorporates:
   *  Constant: '<S318>/Constant'
   *  DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
   */
  if (INS_PARAM.USE_EXTERN_FILTER > INS_P.Switch3_Threshold) {
    rtb_Switch3[2] = rtb_Relay2;
  } else {
    rtb_Switch3[2] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[2];
  }

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S320>/Discrete-Time Integrator1'
   *  Gain: '<S320>/Gain'
   *  Gain: '<S320>/Gain1'
   *  Sum: '<S320>/Add'
   *  Sum: '<S320>/Sum'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE[2] += ((rtb_Saturation_ad -
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2]) * INS_P.Gain_Gain_mz +
    INS_P.Gain1_Gain_kl * INS_DWork.DiscreteTimeIntegrator_DSTATE[2]) *
    INS_P.DiscreteTimeIntegrator_gainv_kc;

  /* Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_i * rtb_DiscreteTimeIntegrator_g[2];

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
   *  Gain: '<S321>/Gain'
   *  Gain: '<S321>/Gain1'
   *  Sum: '<S321>/Add'
   *  Sum: '<S321>/Sum'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_c[2] += ((rtb_Relay2 -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[2]) * INS_P.Gain_Gain_m2 +
    INS_P.Gain1_Gain_e1 * INS_DWork.DiscreteTimeIntegrator_DSTATE_c[2]) *
    INS_P.DiscreteTimeIntegrator_gainv_mk;

  /* Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_j[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_p * rtb_DiscreteTimeIntegrator_c__1;

  /* End of Outputs for SubSystem: '<S3>/IMU_Process' */

  /* Outputs for Atomic SubSystem: '<S3>/Mag_Process' */
  /* SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In1' incorporates:
   *  Inport: '<Root>/MAG'
   */
  rtb_uT[0] = INS_U.MAG.mag_x;

  /* SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Inport: '<Root>/MAG'
   */
  rtb_uT[1] = INS_U.MAG.mag_y;

  /* SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Inport: '<Root>/MAG'
   */
  rtb_uT[2] = INS_U.MAG.mag_z;

  /* Sum: '<S337>/Subtract' incorporates:
   *  Constant: '<S337>/Mag_Bias'
   *  Inport: '<Root>/MAG'
   *  SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In1'
   *  SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In2'
   *  SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In3'
   */
  rtb_Saturation_ad = INS_U.MAG.mag_x - INS_PARAM.MagBias[0];
  rtb_Relay2 = INS_U.MAG.mag_y - INS_PARAM.MagBias[1];
  rtb_Add_m = INS_U.MAG.mag_z - INS_PARAM.MagBias[2];
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    /* Gain: '<S334>/Gauss_to_uT' incorporates:
     *  Constant: '<S337>/Mag_RotMatrix'
     *  Product: '<S337>/Product1'
     */
    rtb_Product1_n[rtb_Saturation1] = INS_P.Gauss_to_uT_Gain *
      (INS_PARAM.MagRotMat[rtb_Saturation1 + 6] * rtb_Add_m +
       (INS_PARAM.MagRotMat[rtb_Saturation1 + 3] * rtb_Relay2 +
        INS_PARAM.MagRotMat[rtb_Saturation1] * rtb_Saturation_ad));
  }

  /* DiscreteIntegrator: '<S335>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/MAG'
   *  RelationalOperator: '<S339>/FixPt Relational Operator'
   *  UnitDelay: '<S339>/Delay Input1'
   */
  if (INS_U.MAG.timestamp != INS_DWork.DelayInput1_DSTATE_n) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l =
      INS_P.DiscreteTimeIntegrator_IC_k;
  }

  /* RelationalOperator: '<S341>/Compare' incorporates:
   *  Constant: '<S341>/Constant'
   */
  rtb_Delay_d = (rtb_Compare_cio == INS_P.CompareToConstant_const_h);

  /* DataTypeConversion: '<S344>/Data Type Conversion1' incorporates:
   *  Gain: '<S344>/Gain'
   */
  rtb_Gain6 = fmod(trunc(57.295779513082323 / INS_P.wmm_lookup_res *
    INS_B.Scalefactor1), 4.294967296E+9);

  /* Sum: '<S344>/Sum' incorporates:
   *  Constant: '<S344>/offset_lat'
   *  DataTypeConversion: '<S344>/Data Type Conversion1'
   */
  rtb_Saturation1 = (rtb_Gain6 < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain6 : (int32_T)
                     (uint32_T)rtb_Gain6) + INS_P.offset_lat_Value;

  /* Saturate: '<S344>/Saturation1' */
  if (rtb_Saturation1 > INS_P.Saturation1_UpperSat) {
    rtb_Saturation1 = INS_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < INS_P.Saturation1_LowerSat) {
      rtb_Saturation1 = INS_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S344>/Saturation1' */

  /* DataTypeConversion: '<S344>/Data Type Conversion2' incorporates:
   *  Gain: '<S344>/Gain6'
   */
  rtb_Gain6 = fmod(trunc(57.295779513082323 / INS_P.wmm_lookup_res *
    INS_B.Scalefactor), 4.294967296E+9);

  /* Sum: '<S344>/Sum1' incorporates:
   *  Constant: '<S344>/offset_lon'
   *  DataTypeConversion: '<S344>/Data Type Conversion2'
   */
  rtb_Saturation2 = (rtb_Gain6 < 0.0 ? -(int32_T)(uint32_T)-rtb_Gain6 : (int32_T)
                     (uint32_T)rtb_Gain6) + INS_P.offset_lon_Value;

  /* Saturate: '<S344>/Saturation2' */
  if (rtb_Saturation2 > INS_P.Saturation2_UpperSat) {
    rtb_Saturation2 = INS_P.Saturation2_UpperSat;
  } else {
    if (rtb_Saturation2 < INS_P.Saturation2_LowerSat) {
      rtb_Saturation2 = INS_P.Saturation2_LowerSat;
    }
  }

  /* End of Saturate: '<S344>/Saturation2' */

  /* LookupNDDirect: '<S344>/Declination Lookup'
   *
   * About '<S344>/Declination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  if (rtb_Saturation2 > 36) {
    i = 36;
  } else if (rtb_Saturation2 < 0) {
    i = 0;
  } else {
    i = rtb_Saturation2;
  }

  if (rtb_Saturation1 > 16) {
    rtb_Saturation1_0 = 16;
  } else if (rtb_Saturation1 < 0) {
    rtb_Saturation1_0 = 0;
  } else {
    rtb_Saturation1_0 = rtb_Saturation1;
  }

  /* Gain: '<S343>/Gain' incorporates:
   *  LookupNDDirect: '<S344>/Declination Lookup'
   *
   * About '<S344>/Declination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_c_id = (real32_T)INS_P.wmm_lookup_wmm_declination[i
    * 17 + rtb_Saturation1_0] * ((real32_T)INS_P.Gain_Gain_fs * 9.53674316E-7F);

  /* Trigonometry: '<S352>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S352>/Trigonometric Function3'
   */
  rtb_DiscreteTimeIntegrator_pm = arm_cos_f32(rtb_DiscreteTimeIntegrator_c_id);
  rtb_VectorConcatenate_m[0] = rtb_DiscreteTimeIntegrator_pm;

  /* Trigonometry: '<S352>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S352>/Trigonometric Function2'
   */
  rtb_delay_acc_O_idx_2 = arm_sin_f32(rtb_DiscreteTimeIntegrator_c_id);
  rtb_VectorConcatenate_m[1] = rtb_delay_acc_O_idx_2;

  /* Constant: '<S352>/Constant3' */
  rtb_VectorConcatenate_m[2] = INS_P.Constant3_Value;

  /* Gain: '<S352>/Gain' */
  rtb_VectorConcatenate_m[3] = INS_P.Gain_Gain_b * rtb_delay_acc_O_idx_2;

  /* Trigonometry: '<S352>/Trigonometric Function3' */
  rtb_VectorConcatenate_m[4] = rtb_DiscreteTimeIntegrator_pm;

  /* Constant: '<S352>/Constant4' */
  rtb_VectorConcatenate_m[5] = INS_P.Constant4_Value;

  /* Constant: '<S352>/Constant2' */
  rtb_VectorConcatenate_m[6] = INS_P.Constant2_Value_d;

  /* Constant: '<S352>/Constant1' */
  rtb_VectorConcatenate_m[7] = INS_P.Constant1_Value_c2;

  /* Constant: '<S352>/Constant' */
  rtb_VectorConcatenate_m[8] = INS_P.Constant_Value_cl;

  /* LookupNDDirect: '<S344>/Magnitude Lookup'
   *
   * About '<S344>/Magnitude Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  if (rtb_Saturation2 > 36) {
    i = 36;
  } else if (rtb_Saturation2 < 0) {
    i = 0;
  } else {
    i = rtb_Saturation2;
  }

  if (rtb_Saturation1 > 16) {
    rtb_Saturation1_0 = 16;
  } else if (rtb_Saturation1 < 0) {
    rtb_Saturation1_0 = 0;
  } else {
    rtb_Saturation1_0 = rtb_Saturation1;
  }

  /* Product: '<S343>/Divide1' incorporates:
   *  Constant: '<S343>/Constant1'
   *  LookupNDDirect: '<S344>/Magnitude Lookup'
   *  MinMax: '<S343>/MinMax'
   *
   * About '<S344>/Magnitude Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_delay_acc_O_idx_2 = 1.0F / fmaxf(INS_P.Constant1_Value_b,
    INS_P.wmm_lookup_wmm_magnitude[i * 17 + rtb_Saturation1_0]);
  for (i = 0; i < 3; i++) {
    /* Logic: '<S340>/AND' incorporates:
     *  Constant: '<S340>/Lower Limit'
     *  Constant: '<S340>/Upper Limit'
     *  RelationalOperator: '<S340>/Lower Test'
     *  RelationalOperator: '<S340>/Upper Test'
     */
    rtb_AND_e[i] = ((INS_P.Mag_Valid_Check_mag_min < rtb_uT[i]) && (rtb_uT[i] <
      INS_P.Mag_Valid_Check_mag_max));

    /* Product: '<S343>/Product1' incorporates:
     *  Delay: '<Root>/Delay'
     *  Product: '<S343>/Divide1'
     */
    rtb_Multiply_j_0[i] = INS_DWork.Delay_8_DSTATE[i + 6] *
      (rtb_delay_acc_O_idx_2 * rtb_Product1_n[2]) + (INS_DWork.Delay_8_DSTATE[i
      + 3] * (rtb_delay_acc_O_idx_2 * rtb_Product1_n[1]) + rtb_delay_acc_O_idx_2
      * rtb_Product1_n[0] * INS_DWork.Delay_8_DSTATE[i]);
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S353>/Math Function' */
    rtb_DiscreteTimeIntegrator_g[i] = rtb_Product1_n[i] * rtb_Product1_n[i];

    /* Product: '<S343>/Product3' */
    rtb_uT[i] = rtb_VectorConcatenate_m[i + 6] * rtb_Multiply_j_0[2] +
      (rtb_VectorConcatenate_m[i + 3] * rtb_Multiply_j_0[1] +
       rtb_VectorConcatenate_m[i] * rtb_Multiply_j_0[0]);
  }

  /* Sum: '<S353>/Sum of Elements' */
  i = 1;
  rtb_DiscreteTimeIntegrator_c_id = (rtb_DiscreteTimeIntegrator_g[0] +
    rtb_DiscreteTimeIntegrator_g[1]) + rtb_DiscreteTimeIntegrator_g[2];

  /* Math: '<S353>/Math Function1'
   *
   * About '<S353>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_DiscreteTimeIntegrator_c_id < 0.0F) {
    rtb_DiscreteTimeIntegrator_c_id = -sqrtf(fabsf
      (rtb_DiscreteTimeIntegrator_c_id));
  } else {
    rtb_DiscreteTimeIntegrator_c_id = sqrtf(rtb_DiscreteTimeIntegrator_c_id);
  }

  /* End of Math: '<S353>/Math Function1' */

  /* Switch: '<S353>/Switch' incorporates:
   *  Constant: '<S353>/Constant'
   *  Product: '<S353>/Product'
   */
  if (rtb_DiscreteTimeIntegrator_c_id > INS_P.Switch_Threshold_f) {
    rtb_Inclination = rtb_Product1_n[0];
    rtb_delay_acc_O_idx_1 = rtb_Product1_n[1];
    rtb_delay_acc_O_idx_2 = rtb_Product1_n[2];
    rtb_DiscreteTimeIntegrator_pm = rtb_DiscreteTimeIntegrator_c_id;
  } else {
    rtb_Inclination = 0.0F;
    rtb_delay_acc_O_idx_1 = 0.0F;
    rtb_delay_acc_O_idx_2 = 0.0F;
    rtb_DiscreteTimeIntegrator_pm = INS_P.Constant_Value_g2;
  }

  /* End of Switch: '<S353>/Switch' */

  /* Switch: '<S343>/Switch1' incorporates:
   *  Constant: '<S342>/default_mag_quality'
   *  Delay: '<Root>/Delay'
   *  Math: '<S343>/Math Function1'
   *  MinMax: '<S345>/MinMax'
   *  Product: '<S343>/Product2'
   *  Product: '<S353>/Divide1'
   *  Switch: '<S342>/Switch'
   *  Switch: '<S343>/Switch'
   */
  if (rtb_Delay_d) {
    /* Math: '<S351>/Square' incorporates:
     *  Math: '<S349>/Square'
     */
    rtb_Saturation_ad = rtb_uT[0] * rtb_uT[0];
    rtb_Relay2 = rtb_uT[1] * rtb_uT[1];

    /* LookupNDDirect: '<S344>/Inclination Lookup'
     *
     * About '<S344>/Inclination Lookup':
     *  2-dimensional Direct Look-Up returning a Scalar,
     */
    if (rtb_Saturation2 > 36) {
      rtb_Saturation2 = 36;
    } else {
      if (rtb_Saturation2 < 0) {
        rtb_Saturation2 = 0;
      }
    }

    if (rtb_Saturation1 > 16) {
      rtb_Saturation1 = 16;
    } else {
      if (rtb_Saturation1 < 0) {
        rtb_Saturation1 = 0;
      }
    }

    /* Sum: '<S346>/Sum3' incorporates:
     *  Abs: '<S346>/Abs1'
     *  Constant: '<S346>/Constant2'
     *  Gain: '<S346>/Gain1'
     *  Gain: '<S346>/gain'
     *  LookupNDDirect: '<S344>/Inclination Lookup'
     *  Sqrt: '<S348>/Sqrt'
     *  Sum: '<S346>/Subtract'
     *  Sum: '<S349>/Sum of Elements'
     *  Trigonometry: '<S346>/Trigonometric Function'
     *
     * About '<S344>/Inclination Lookup':
     *  2-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_Square_l_idx_1 = INS_P.Constant2_Value_hh - fabsf((real32_T)
      (INS_P.wmm_lookup_wmm_inclination[rtb_Saturation2 * 17 + rtb_Saturation1] *
       INS_P.Gain1_Gain_o) * 0.000244140625F - atan2f(rtb_uT[2], sqrtf
      (rtb_Saturation_ad + rtb_Relay2))) * INS_P.gain_Gain_g;

    /* Sum: '<S347>/Sum' incorporates:
     *  Abs: '<S347>/Abs'
     *  Constant: '<S347>/Constant1'
     *  Constant: '<S347>/Nominal_Magnitude'
     *  Gain: '<S347>/gain'
     *  Math: '<S351>/Square'
     *  Sqrt: '<S350>/Sqrt'
     *  Sum: '<S347>/Subtract'
     *  Sum: '<S351>/Sum of Elements'
     */
    rtb_Saturation_ad = INS_P.Constant1_Value_cq - fabsf
      (INS_P.Nominal_Magnitude_Value - sqrtf((rtb_Saturation_ad + rtb_Relay2) +
        rtb_uT[2] * rtb_uT[2])) * INS_P.gain_Gain_m;

    /* Saturate: '<S346>/Saturation' */
    if (rtb_Square_l_idx_1 > INS_P.Saturation_UpperSat_gg) {
      rtb_Square_l_idx_1 = INS_P.Saturation_UpperSat_gg;
    } else {
      if (rtb_Square_l_idx_1 < INS_P.Saturation_LowerSat_a) {
        rtb_Square_l_idx_1 = INS_P.Saturation_LowerSat_a;
      }
    }

    /* End of Saturate: '<S346>/Saturation' */

    /* Saturate: '<S347>/Saturation' */
    if (rtb_Saturation_ad > INS_P.Saturation_UpperSat_gv) {
      rtb_Saturation_ad = INS_P.Saturation_UpperSat_gv;
    } else {
      if (rtb_Saturation_ad < INS_P.Saturation_LowerSat_pf) {
        rtb_Saturation_ad = INS_P.Saturation_LowerSat_pf;
      }
    }

    /* End of Saturate: '<S347>/Saturation' */
    rtb_DiscreteTimeIntegrator_c_id = fminf(rtb_Square_l_idx_1,
      rtb_Saturation_ad);
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
      rtb_Product1_n[rtb_Saturation1] = INS_DWork.Delay_8_DSTATE[3 *
        rtb_Saturation1 + 2] * rtb_uT[2] + (INS_DWork.Delay_8_DSTATE[3 *
        rtb_Saturation1 + 1] * rtb_uT[1] + INS_DWork.Delay_8_DSTATE[3 *
        rtb_Saturation1] * rtb_uT[0]);
    }
  } else {
    rtb_DiscreteTimeIntegrator_c_id = INS_P.default_mag_quality_Value;
    rtb_Product1_n[0] = rtb_Inclination / rtb_DiscreteTimeIntegrator_pm;
    rtb_Product1_n[1] = rtb_delay_acc_O_idx_1 / rtb_DiscreteTimeIntegrator_pm;
    rtb_Product1_n[2] = rtb_delay_acc_O_idx_2 / rtb_DiscreteTimeIntegrator_pm;
  }

  /* End of Switch: '<S343>/Switch1' */

  /* Product: '<S342>/Multiply' incorporates:
   *  Constant: '<S338>/Constant'
   *  DiscreteIntegrator: '<S335>/Discrete-Time Integrator'
   *  Logic: '<S335>/Logical Operator1'
   *  Logic: '<S335>/Logical Operator4'
   *  RelationalOperator: '<S338>/Compare'
   */
  rtb_Saturation_ad = rtb_AND_e[0] && rtb_AND_e[1] && rtb_AND_e[2] &&
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_l < INS_P.Mag_Valid_Check_timeout) ?
    rtb_DiscreteTimeIntegrator_c_id : 0.0F;

  /* Update for UnitDelay: '<S339>/Delay Input1' incorporates:
   *  Inport: '<Root>/MAG'
   */
  INS_DWork.DelayInput1_DSTATE_n = INS_U.MAG.timestamp;

  /* Update for DiscreteIntegrator: '<S335>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S335>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_l +
    (real32_T)INS_EXPORT.period;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l = (uint32_T)rtb_delay_acc_O_idx_2;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S335>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/Mag_Process' */

  /* Outputs for Atomic SubSystem: '<S3>/Optical_Flow_Preprocessing' */
  /* Product: '<S278>/Multiply' incorporates:
   *  Constant: '<S278>/Constant'
   *  Delay: '<Root>/Delay'
   *  Inport: '<Root>/Optical_Flow'
   *  SignalConversion: '<S278>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    rtb_uT[rtb_Saturation1] = INS_DWork.Delay_6_DSTATE[rtb_Saturation1 + 6] *
      INS_P.Constant_Value_bg + (INS_DWork.Delay_6_DSTATE[rtb_Saturation1 + 3] *
      INS_U.Optical_Flow.vel_y_mPs + INS_DWork.Delay_6_DSTATE[rtb_Saturation1] *
      INS_U.Optical_Flow.vel_x_mPs);
  }

  /* End of Product: '<S278>/Multiply' */

  /* DiscreteIntegrator: '<S354>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   *  RelationalOperator: '<S356>/FixPt Relational Operator'
   *  UnitDelay: '<S356>/Delay Input1'
   */
  if (INS_U.Optical_Flow.timestamp_ms != INS_DWork.DelayInput1_DSTATE_l) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n =
      INS_P.DiscreteTimeIntegrator_IC_g;
  }

  /* Logic: '<S354>/Logical Operator' incorporates:
   *  Constant: '<S355>/Constant'
   *  DiscreteIntegrator: '<S354>/Discrete-Time Integrator'
   *  Inport: '<Root>/Optical_Flow'
   *  RelationalOperator: '<S355>/Compare'
   */
  rtb_Delay_d = ((INS_DWork.DiscreteTimeIntegrator_DSTATE_n <
                  INS_P.CompareToConstant4_const_k) && (INS_U.Optical_Flow.valid
    != 0U));

  /* Update for UnitDelay: '<S356>/Delay Input1' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   */
  INS_DWork.DelayInput1_DSTATE_l = INS_U.Optical_Flow.timestamp_ms;

  /* Update for DiscreteIntegrator: '<S354>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S354>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_n +
    INS_P.Constant_Value_jp;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    if (rtb_delay_acc_O_idx_2 >= 0.0F) {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_n = (uint32_T)
        rtb_delay_acc_O_idx_2;
    } else {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_n = 0U;
    }
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S354>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/Optical_Flow_Preprocessing' */

  /* Outputs for Atomic SubSystem: '<S3>/Sonar_Process' */
  /* RelationalOperator: '<S360>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Sonar'
   *  UnitDelay: '<S360>/Delay Input1'
   */
  rtb_Delay_h = (INS_U.Sonar.timestamp_ms != INS_DWork.DelayInput1_DSTATE);

  /* DiscreteIntegrator: '<S357>/Discrete-Time Integrator' */
  if (rtb_Delay_h) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kn =
      INS_P.DiscreteTimeIntegrator_IC_pt;
  }

  /* Logic: '<S357>/Logical Operator' incorporates:
   *  Constant: '<S358>/Constant'
   *  Constant: '<S359>/Constant'
   *  Constant: '<S361>/Lower Limit'
   *  Constant: '<S361>/Upper Limit'
   *  Delay: '<Root>/Delay1'
   *  Delay: '<S357>/Delay'
   *  DiscreteIntegrator: '<S357>/Discrete-Time Integrator'
   *  Inport: '<Root>/Sonar'
   *  Logic: '<S361>/AND'
   *  Math: '<S357>/Square'
   *  Math: '<S357>/Square1'
   *  RelationalOperator: '<S358>/Compare'
   *  RelationalOperator: '<S359>/Compare'
   *  RelationalOperator: '<S361>/Lower Test'
   *  RelationalOperator: '<S361>/Upper Test'
   *  Sqrt: '<S357>/Sqrt'
   *  Sum: '<S357>/Add'
   */
  rtb_LogicalOperator3 = ((INS_DWork.DiscreteTimeIntegrator_DSTAT_kn <
    INS_P.CompareToConstant4_const_h) && (INS_DWork.Delay_DSTATE_dz != 0) &&
    ((INS_P.IntervalTest_lowlimit_d < INS_U.Sonar.distance_m) &&
     (INS_U.Sonar.distance_m <= INS_P.IntervalTest_uplimit_a)) && (sqrtf
    (INS_DWork.Delay1_4_DSTATE * INS_DWork.Delay1_4_DSTATE +
     INS_DWork.Delay1_5_DSTATE * INS_DWork.Delay1_5_DSTATE) <
    INS_P.CompareToConstant_const_f));

  /* Update for UnitDelay: '<S360>/Delay Input1' incorporates:
   *  Inport: '<Root>/Sonar'
   */
  INS_DWork.DelayInput1_DSTATE = INS_U.Sonar.timestamp_ms;

  /* Update for DiscreteIntegrator: '<S357>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S357>/Constant'
   */
  rtb_delay_acc_O_idx_2 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_kn +
    (real32_T)INS_EXPORT.period;
  if (rtb_delay_acc_O_idx_2 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kn = (uint32_T)rtb_delay_acc_O_idx_2;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kn = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S357>/Discrete-Time Integrator' */

  /* Switch: '<S357>/Switch' */
  if (rtb_Delay_h) {
    /* Update for Delay: '<S357>/Delay' incorporates:
     *  Constant: '<S357>/Constant1'
     */
    INS_DWork.Delay_DSTATE_dz = INS_P.Constant1_Value_l;
  }

  /* End of Switch: '<S357>/Switch' */
  /* End of Outputs for SubSystem: '<S3>/Sonar_Process' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/Attitude_Init' */
  /* Sqrt: '<S110>/Sqrt' incorporates:
   *  Math: '<S115>/Square'
   *  Sum: '<S115>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_pm = sqrtf((rtb_Switch3[0] * rtb_Switch3[0] +
    rtb_Switch3[1] * rtb_Switch3[1]) + rtb_Switch3[2] * rtb_Switch3[2]);

  /* Sum: '<S109>/Add' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Lower Limit'
   *  Constant: '<S108>/Upper Limit'
   *  Constant: '<S62>/Constant'
   *  Delay: '<S109>/Delay'
   *  Logic: '<S108>/AND'
   *  Logic: '<S64>/Logical Operator1'
   *  Math: '<S116>/Square'
   *  RelationalOperator: '<S107>/Compare'
   *  RelationalOperator: '<S108>/Lower Test'
   *  RelationalOperator: '<S108>/Upper Test'
   *  RelationalOperator: '<S62>/Compare'
   *  Sqrt: '<S111>/Sqrt'
   *  Sum: '<S116>/Sum of Elements'
   */
  rtb_Add_kz = (uint16_T)((uint32_T)(rtb_Compare_fz && (rtb_Saturation_ad >=
    INS_P.CompareToConstant_const_g) && ((INS_P.IntervalTest_lowlimit <=
    rtb_DiscreteTimeIntegrator_pm) && (rtb_DiscreteTimeIntegrator_pm <=
    INS_P.IntervalTest_uplimit)) && (sqrtf((rtb_Product1_n[0] * rtb_Product1_n[0]
    + rtb_Product1_n[1] * rtb_Product1_n[1]) + rtb_Product1_n[2] *
    rtb_Product1_n[2]) > INS_P.CompareToConstant_const_p)) +
    INS_DWork.Delay_DSTATE_i);

  /* Saturate: '<S109>/Saturation' */
  if (rtb_Add_kz > INS_P.Saturation_UpperSat_k5) {
    rtb_Add_i = INS_P.Saturation_UpperSat_k5;
  } else if (rtb_Add_kz < INS_P.Saturation_LowerSat_hb) {
    rtb_Add_i = INS_P.Saturation_LowerSat_hb;
  } else {
    rtb_Add_i = rtb_Add_kz;
  }

  /* End of Saturate: '<S109>/Saturation' */

  /* RelationalOperator: '<S114>/Compare' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S114>/Constant'
   *  RelationalOperator: '<S113>/Compare'
   */
  rtb_Delay_h = ((rtb_Add_i > INS_P.valid_samples_const) > (int32_T)
                 INS_P.Constant_Value_af);

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
  /* Logic: '<S64>/Logical Operator' incorporates:
   *  Inport: '<Root>/reset'
   *  RelationalOperator: '<S112>/FixPt Relational Operator'
   *  UnitDelay: '<S112>/Delay Input1'
   */
  rtb_UpperTest_cv = (((int32_T)rtb_Delay_h > (int32_T)
                       INS_DWork.DelayInput1_DSTATE_p) || (INS_U.reset != 0));

  /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

  /* Outputs for Enabled SubSystem: '<S58>/Attitude_Init' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (rtb_UpperTest_cv) {
    /* Gain: '<S61>/Gain' */
    rtb_ba_O_mDs2[0] = INS_P.Gain_Gain_d * rtb_Switch3[0];
    rtb_ba_O_mDs2[1] = INS_P.Gain_Gain_d * rtb_Switch3[1];
    rtb_ba_O_mDs2[2] = INS_P.Gain_Gain_d * rtb_Switch3[2];

    /* Sum: '<S66>/Sum' incorporates:
     *  Product: '<S96>/Multiply'
     *  Product: '<S96>/Multiply1'
     *  Product: '<S96>/Multiply2'
     *  Product: '<S97>/Multiply'
     *  Product: '<S97>/Multiply1'
     *  Product: '<S97>/Multiply2'
     */
    rtb_Multiply_j[0] = rtb_ba_O_mDs2[1] * rtb_Product1_n[2] - rtb_ba_O_mDs2[2] *
      rtb_Product1_n[1];
    rtb_Multiply_j[1] = rtb_ba_O_mDs2[2] * rtb_Product1_n[0] - rtb_ba_O_mDs2[0] *
      rtb_Product1_n[2];
    rtb_Multiply_g1 = rtb_ba_O_mDs2[0] * rtb_Product1_n[1] - rtb_ba_O_mDs2[1] *
      rtb_Product1_n[0];

    /* Sum: '<S67>/Sum' incorporates:
     *  Product: '<S98>/Multiply'
     *  Product: '<S99>/Multiply'
     */
    rtb_Square_l_idx_0 = rtb_Multiply_j[1] * rtb_ba_O_mDs2[2] - rtb_Multiply_g1 *
      rtb_ba_O_mDs2[1];
    rtb_Divide1_m[0] = rtb_Square_l_idx_0;

    /* Math: '<S100>/Math Function' */
    rtb_MatrixConcatenate[0] = rtb_Square_l_idx_0 * rtb_Square_l_idx_0;

    /* Sum: '<S67>/Sum' incorporates:
     *  Product: '<S98>/Multiply1'
     *  Product: '<S99>/Multiply1'
     */
    rtb_Square_l_idx_0 = rtb_Multiply_g1 * rtb_ba_O_mDs2[0] - rtb_Multiply_j[0] *
      rtb_ba_O_mDs2[2];
    rtb_Divide1_m[1] = rtb_Square_l_idx_0;

    /* Math: '<S100>/Math Function' */
    rtb_MatrixConcatenate[1] = rtb_Square_l_idx_0 * rtb_Square_l_idx_0;

    /* Sum: '<S67>/Sum' incorporates:
     *  Product: '<S98>/Multiply2'
     *  Product: '<S99>/Multiply2'
     */
    rtb_Square_l_idx_0 = rtb_Multiply_j[0] * rtb_ba_O_mDs2[1] - rtb_Multiply_j[1]
      * rtb_ba_O_mDs2[0];

    /* MinMax: '<S68>/Max' incorporates:
     *  Constant: '<S68>/Constant2'
     *  Math: '<S100>/Math Function'
     *  Sqrt: '<S100>/Sqrt'
     *  Sum: '<S100>/Sum of Elements'
     */
    rtb_Inclination = fmaxf(sqrtf((rtb_MatrixConcatenate[0] +
      rtb_MatrixConcatenate[1]) + rtb_Square_l_idx_0 * rtb_Square_l_idx_0),
      INS_P.Constant2_Value_h);

    /* Product: '<S68>/Divide' */
    rtb_VectorConcatenate_m[0] = rtb_Divide1_m[0] / rtb_Inclination;
    rtb_VectorConcatenate_m[1] = rtb_Divide1_m[1] / rtb_Inclination;
    rtb_VectorConcatenate_m[2] = rtb_Square_l_idx_0 / rtb_Inclination;

    /* MinMax: '<S69>/Max' incorporates:
     *  Constant: '<S69>/Constant2'
     *  Math: '<S101>/Math Function'
     *  Sqrt: '<S101>/Sqrt'
     *  Sum: '<S101>/Sum of Elements'
     */
    rtb_Inclination = fmaxf(sqrtf((rtb_Multiply_j[0] * rtb_Multiply_j[0] +
      rtb_Multiply_j[1] * rtb_Multiply_j[1]) + rtb_Multiply_g1 * rtb_Multiply_g1),
      INS_P.Constant2_Value_m);

    /* Product: '<S69>/Divide' */
    rtb_VectorConcatenate_m[3] = rtb_Multiply_j[0] / rtb_Inclination;
    rtb_VectorConcatenate_m[4] = rtb_Multiply_j[1] / rtb_Inclination;
    rtb_VectorConcatenate_m[5] = rtb_Multiply_g1 / rtb_Inclination;

    /* MinMax: '<S70>/Max' incorporates:
     *  Constant: '<S70>/Constant2'
     *  Math: '<S102>/Math Function'
     *  Sqrt: '<S102>/Sqrt'
     *  Sum: '<S102>/Sum of Elements'
     */
    rtb_DiscreteTimeIntegrator_pm = fmaxf(sqrtf((rtb_ba_O_mDs2[0] *
      rtb_ba_O_mDs2[0] + rtb_ba_O_mDs2[1] * rtb_ba_O_mDs2[1]) + rtb_ba_O_mDs2[2]
      * rtb_ba_O_mDs2[2]), INS_P.Constant2_Value_gc);

    /* Product: '<S70>/Divide' */
    rtb_VectorConcatenate_m[6] = rtb_ba_O_mDs2[0] /
      rtb_DiscreteTimeIntegrator_pm;
    rtb_VectorConcatenate_m[7] = rtb_ba_O_mDs2[1] /
      rtb_DiscreteTimeIntegrator_pm;
    rtb_VectorConcatenate_m[8] = rtb_ba_O_mDs2[2] /
      rtb_DiscreteTimeIntegrator_pm;

    /* Sum: '<S73>/Add' */
    rtb_Add_m = (rtb_VectorConcatenate_m[0] + rtb_VectorConcatenate_m[4]) +
      rtb_VectorConcatenate_m[8];

    /* If: '<S65>/If' incorporates:
     *  If: '<S71>/Find Maximum Diagonal Value'
     */
    if (rtb_Add_m > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S65>/PositiveTrace' incorporates:
       *  ActionPort: '<S72>/Action Port'
       */
      /* Sqrt: '<S72>/sqrt' incorporates:
       *  Constant: '<S72>/Constant'
       *  Sum: '<S72>/Sum'
       */
      rtb_DiscreteTimeIntegrator_pm = sqrtf(rtb_Add_m + INS_P.Constant_Value_e);

      /* Gain: '<S72>/Gain' */
      INS_B.Merge[0] = INS_P.Gain_Gain_o * rtb_DiscreteTimeIntegrator_pm;

      /* Gain: '<S72>/Gain1' */
      rtb_DiscreteTimeIntegrator_pm *= INS_P.Gain1_Gain_h;

      /* Product: '<S72>/Product' incorporates:
       *  Sum: '<S93>/Add'
       *  Sum: '<S94>/Add'
       *  Sum: '<S95>/Add'
       */
      INS_B.Merge[1] = (rtb_VectorConcatenate_m[7] - rtb_VectorConcatenate_m[5])
        / rtb_DiscreteTimeIntegrator_pm;
      INS_B.Merge[2] = (rtb_VectorConcatenate_m[2] - rtb_VectorConcatenate_m[6])
        / rtb_DiscreteTimeIntegrator_pm;
      INS_B.Merge[3] = (rtb_VectorConcatenate_m[3] - rtb_VectorConcatenate_m[1])
        / rtb_DiscreteTimeIntegrator_pm;

      /* End of Outputs for SubSystem: '<S65>/PositiveTrace' */
    } else {
      /* Outputs for IfAction SubSystem: '<S65>/NegativeTrace' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      if ((rtb_VectorConcatenate_m[4] > rtb_VectorConcatenate_m[0]) &&
          (rtb_VectorConcatenate_m[4] > rtb_VectorConcatenate_m[8])) {
        /* Outputs for IfAction SubSystem: '<S71>/Maximum Value at DCM(2,2)' incorporates:
         *  ActionPort: '<S75>/Action Port'
         */
        /* If: '<S71>/Find Maximum Diagonal Value' incorporates:
         *  Constant: '<S86>/Constant1'
         *  Constant: '<S86>/Constant2'
         *  Constant: '<S87>/Constant'
         *  Gain: '<S75>/Gain'
         *  Gain: '<S75>/Gain1'
         *  Gain: '<S75>/Gain3'
         *  Gain: '<S75>/Gain4'
         *  Product: '<S75>/Product'
         *  Product: '<S86>/Product'
         *  Sqrt: '<S75>/sqrt'
         *  Sum: '<S83>/Add'
         *  Sum: '<S84>/Add'
         *  Sum: '<S85>/Add'
         *  Sum: '<S87>/Add'
         *  Switch: '<S86>/Switch'
         */
        rtb_DiscreteTimeIntegrator_pm = sqrtf(((rtb_VectorConcatenate_m[4] -
          rtb_VectorConcatenate_m[0]) - rtb_VectorConcatenate_m[8]) +
          INS_P.Constant_Value_o);
        INS_B.Merge[2] = INS_P.Gain_Gain_e * rtb_DiscreteTimeIntegrator_pm;
        if (rtb_DiscreteTimeIntegrator_pm != 0.0F) {
          rtb_Square_l_idx_0 = INS_P.Constant1_Value;
          rtb_Square_l_idx_1 = rtb_DiscreteTimeIntegrator_pm;
        } else {
          rtb_Square_l_idx_0 = INS_P.Constant2_Value[0];
          rtb_Square_l_idx_1 = INS_P.Constant2_Value[1];
        }

        rtb_DiscreteTimeIntegrator_pm = rtb_Square_l_idx_0 / rtb_Square_l_idx_1;
        INS_B.Merge[1] = (rtb_VectorConcatenate_m[1] + rtb_VectorConcatenate_m[3])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain1_Gain_j;
        INS_B.Merge[3] = (rtb_VectorConcatenate_m[5] + rtb_VectorConcatenate_m[7])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain3_Gain;
        INS_B.Merge[0] = (rtb_VectorConcatenate_m[2] - rtb_VectorConcatenate_m[6])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain4_Gain;

        /* End of Outputs for SubSystem: '<S71>/Maximum Value at DCM(2,2)' */
      } else if (rtb_VectorConcatenate_m[8] > rtb_VectorConcatenate_m[0]) {
        /* Outputs for IfAction SubSystem: '<S71>/Maximum Value at DCM(3,3)' incorporates:
         *  ActionPort: '<S76>/Action Port'
         */
        /* If: '<S71>/Find Maximum Diagonal Value' incorporates:
         *  Constant: '<S91>/Constant1'
         *  Constant: '<S91>/Constant2'
         *  Constant: '<S92>/Constant'
         *  Gain: '<S76>/Gain'
         *  Gain: '<S76>/Gain1'
         *  Gain: '<S76>/Gain2'
         *  Gain: '<S76>/Gain3'
         *  Product: '<S76>/Product'
         *  Product: '<S91>/Product'
         *  Sqrt: '<S76>/sqrt'
         *  Sum: '<S88>/Add'
         *  Sum: '<S89>/Add'
         *  Sum: '<S90>/Add'
         *  Sum: '<S92>/Add'
         *  Switch: '<S91>/Switch'
         */
        rtb_DiscreteTimeIntegrator_pm = sqrtf(((rtb_VectorConcatenate_m[8] -
          rtb_VectorConcatenate_m[0]) - rtb_VectorConcatenate_m[4]) +
          INS_P.Constant_Value_jf);
        INS_B.Merge[3] = INS_P.Gain_Gain_j * rtb_DiscreteTimeIntegrator_pm;
        if (rtb_DiscreteTimeIntegrator_pm != 0.0F) {
          rtb_Square_l_idx_0 = INS_P.Constant1_Value_n;
          rtb_Square_l_idx_1 = rtb_DiscreteTimeIntegrator_pm;
        } else {
          rtb_Square_l_idx_0 = INS_P.Constant2_Value_i[0];
          rtb_Square_l_idx_1 = INS_P.Constant2_Value_i[1];
        }

        rtb_DiscreteTimeIntegrator_pm = rtb_Square_l_idx_0 / rtb_Square_l_idx_1;
        INS_B.Merge[1] = (rtb_VectorConcatenate_m[2] + rtb_VectorConcatenate_m[6])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain1_Gain_l;
        INS_B.Merge[2] = (rtb_VectorConcatenate_m[5] + rtb_VectorConcatenate_m[7])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain2_Gain_d;
        INS_B.Merge[0] = (rtb_VectorConcatenate_m[3] - rtb_VectorConcatenate_m[1])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain3_Gain_l;

        /* End of Outputs for SubSystem: '<S71>/Maximum Value at DCM(3,3)' */
      } else {
        /* Outputs for IfAction SubSystem: '<S71>/Maximum Value at DCM(1,1)' incorporates:
         *  ActionPort: '<S74>/Action Port'
         */
        /* If: '<S71>/Find Maximum Diagonal Value' incorporates:
         *  Constant: '<S81>/Constant1'
         *  Constant: '<S81>/Constant2'
         *  Constant: '<S82>/Constant'
         *  Gain: '<S74>/Gain'
         *  Gain: '<S74>/Gain1'
         *  Gain: '<S74>/Gain2'
         *  Gain: '<S74>/Gain3'
         *  Product: '<S74>/Product'
         *  Product: '<S81>/Product'
         *  Sqrt: '<S74>/sqrt'
         *  Sum: '<S78>/Add'
         *  Sum: '<S79>/Add'
         *  Sum: '<S80>/Add'
         *  Sum: '<S82>/Add'
         *  Switch: '<S81>/Switch'
         */
        rtb_DiscreteTimeIntegrator_pm = sqrtf(((rtb_VectorConcatenate_m[0] -
          rtb_VectorConcatenate_m[4]) - rtb_VectorConcatenate_m[8]) +
          INS_P.Constant_Value_g);
        INS_B.Merge[1] = INS_P.Gain_Gain_m * rtb_DiscreteTimeIntegrator_pm;
        if (rtb_DiscreteTimeIntegrator_pm != 0.0F) {
          rtb_Square_l_idx_0 = INS_P.Constant1_Value_c;
          rtb_Square_l_idx_1 = rtb_DiscreteTimeIntegrator_pm;
        } else {
          rtb_Square_l_idx_0 = INS_P.Constant2_Value_g[0];
          rtb_Square_l_idx_1 = INS_P.Constant2_Value_g[1];
        }

        rtb_DiscreteTimeIntegrator_pm = rtb_Square_l_idx_0 / rtb_Square_l_idx_1;
        INS_B.Merge[2] = (rtb_VectorConcatenate_m[1] + rtb_VectorConcatenate_m[3])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain1_Gain_b;
        INS_B.Merge[3] = (rtb_VectorConcatenate_m[2] + rtb_VectorConcatenate_m[6])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain2_Gain_o;
        INS_B.Merge[0] = (rtb_VectorConcatenate_m[7] - rtb_VectorConcatenate_m[5])
          * rtb_DiscreteTimeIntegrator_pm * INS_P.Gain3_Gain_d;

        /* End of Outputs for SubSystem: '<S71>/Maximum Value at DCM(1,1)' */
      }

      /* End of Outputs for SubSystem: '<S65>/NegativeTrace' */
    }

    /* End of If: '<S65>/If' */

    /* SignalConversion: '<S61>/OutportBufferForquaternion_0' */
    INS_B.OutportBufferForquaternion_0[0] = INS_B.Merge[0];
    INS_B.OutportBufferForquaternion_0[1] = INS_B.Merge[1];
    INS_B.OutportBufferForquaternion_0[2] = INS_B.Merge[2];
    INS_B.OutportBufferForquaternion_0[3] = INS_B.Merge[3];
  }

  /* End of Outputs for SubSystem: '<S58>/Attitude_Init' */

  /* Sum: '<S103>/Sum4' incorporates:
   *  DiscreteIntegrator: '<S106>/Discrete-Time Integrator5'
   *  Sum: '<S106>/Sum9'
   */
  rtb_Add_m = rtb_VectorConcatenate_idx_0 -
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[0];

  /* Abs: '<S63>/Abs' incorporates:
   *  DiscreteIntegrator: '<S106>/Discrete-Time Integrator5'
   *  Sum: '<S103>/Sum4'
   */
  rtb_Square_l_idx_1 = fabsf(rtb_VectorConcatenate_idx_1 -
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[1]);

  /* Saturate: '<S63>/Saturation2' */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_o > INS_P.Saturation2_UpperSat_i)
  {
    rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation2_UpperSat_i;
  } else if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_o <
             INS_P.Saturation2_LowerSat_g) {
    rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation2_LowerSat_g;
  } else {
    rtb_DiscreteTimeIntegrator_pm = INS_DWork.DiscreteTimeIntegrator5_DSTAT_o;
  }

  /* End of Saturate: '<S63>/Saturation2' */

  /* Relay: '<S63>/Relay2' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator5'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_n >= INS_P.Relay2_OnVal) {
    INS_DWork.Relay2_Mode = true;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_n <= INS_P.Relay2_OffVal) {
      INS_DWork.Relay2_Mode = false;
    }
  }

  if (INS_DWork.Relay2_Mode) {
    rtb_Relay2 = INS_P.Relay2_YOn;
  } else {
    rtb_Relay2 = INS_P.Relay2_YOff;
  }

  /* End of Relay: '<S63>/Relay2' */

  /* Update for Delay: '<S109>/Delay' */
  INS_DWork.Delay_DSTATE_i = rtb_Add_kz;

  /* Update for UnitDelay: '<S112>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_p = rtb_Delay_h;

  /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S106>/Gain2'
   *  Sum: '<S106>/Sum9'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] += rtb_Add_m * INS_P.Gain2_Gain_h *
    INS_P.DiscreteTimeIntegrator5_gainval;
  INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_VectorConcatenate_idx_1 -
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[1]) * INS_P.Gain2_Gain_h *
    INS_P.DiscreteTimeIntegrator5_gainval;

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator5' incorporates:
   *  Abs: '<S63>/Abs'
   *  Gain: '<S104>/Gain2'
   *  MinMax: '<S63>/MinMax1'
   *  Sum: '<S103>/Sum4'
   *  Sum: '<S104>/Sum9'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_o += (fmaxf(fabsf(rtb_Add_m),
    rtb_Square_l_idx_1) - INS_DWork.DiscreteTimeIntegrator5_DSTAT_o) *
    INS_P.Gain2_Gain_c * INS_P.DiscreteTimeIntegrator5_gainv_o;

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S105>/Gain2'
   *  Sum: '<S105>/Sum9'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_n += (rtb_DiscreteTimeIntegrator_pm -
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_n) * INS_P.Gain2_Gain_f *
    INS_P.DiscreteTimeIntegrator5_gainv_b;

  /* End of Outputs for SubSystem: '<S56>/Attitude_Init' */

  /* Outputs for Atomic SubSystem: '<S56>/Correct' */
  /* Product: '<S122>/Multiply' incorporates:
   *  Delay: '<S56>/Delay'
   */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    rtb_MatrixConcatenate[rtb_Saturation1] =
      INS_DWork.Delay_8_DSTATE_l[rtb_Saturation1 + 6] * rtb_Switch3[2] +
      (INS_DWork.Delay_8_DSTATE_l[rtb_Saturation1 + 3] * rtb_Switch3[1] +
       INS_DWork.Delay_8_DSTATE_l[rtb_Saturation1] * rtb_Switch3[0]);
  }

  /* End of Product: '<S122>/Multiply' */

  /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_o != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0] = rtb_MatrixConcatenate[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1] = rtb_MatrixConcatenate[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2] = rtb_MatrixConcatenate[2];
  }

  rtb_DiscreteTimeIntegrator_g[0] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0];
  rtb_DiscreteTimeIntegrator_g[1] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1];
  rtb_DiscreteTimeIntegrator_g[2] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2];

  /* Relay: '<S141>/Relay' */
  if (rtb_Sum2_j >= INS_P.Relay_OnVal) {
    INS_DWork.Relay_Mode = true;
  } else {
    if (rtb_Sum2_j <= INS_P.Relay_OffVal) {
      INS_DWork.Relay_Mode = false;
    }
  }

  if (INS_DWork.Relay_Mode) {
    rtb_delay_acc_O_idx_2 = INS_P.Relay_YOn;
  } else {
    rtb_delay_acc_O_idx_2 = INS_P.Relay_YOff;
  }

  /* End of Relay: '<S141>/Relay' */

  /* Logic: '<S141>/Logical Operator1' incorporates:
   *  Logic: '<S141>/Logical Operator'
   */
  rtb_LogicalOperator1_o = ((!rtb_Compare_cio) && (rtb_delay_acc_O_idx_2 != 0.0F));

  /* Sum: '<S141>/Sum' */
  rtb_Compare_cl = (uint8_T)(rtb_Delay_d - rtb_LogicalOperator1_o);

  /* Saturate: '<S141>/Saturation' */
  if (rtb_Compare_cl > INS_P.Saturation_UpperSat_d) {
    rtb_Compare_cl = INS_P.Saturation_UpperSat_d;
  } else {
    if (rtb_Compare_cl < INS_P.Saturation_LowerSat_b) {
      rtb_Compare_cl = INS_P.Saturation_LowerSat_b;
    }
  }

  /* End of Saturate: '<S141>/Saturation' */

  /* Sum: '<S143>/Sum1' incorporates:
   *  Constant: '<S143>/GPS_Delay'
   *  Constant: '<S143>/OptFlow_Delay'
   *  Product: '<S143>/Multiply2'
   *  Product: '<S143>/Multiply3'
   */
  rtb_DiscreteTimeIntegrator_pm = (real32_T)(rtb_Compare_cl *
    INS_P.OptFlow_Delay_Value + (rtb_LogicalOperator1_o ? (int32_T)
    INS_P.GPS_Delay_Value : 0));

  /* Delay: '<S122>/Delay' incorporates:
   *  DiscreteIntegrator: '<S138>/Discrete-Time Integrator1'
   */
  if (rtb_DiscreteTimeIntegrator_pm < 1.0F) {
    rtb_Inclination = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0];
    rtb_delay_acc_O_idx_1 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1];
    rtb_delay_acc_O_idx_2 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2];
  } else {
    if (rtb_DiscreteTimeIntegrator_pm > 200.0F) {
      rtb_Saturation1 = 200;
    } else {
      rtb_Saturation1 = (int32_T)fmodf(rtb_DiscreteTimeIntegrator_pm,
        4.2949673E+9F);
    }

    rtb_Saturation1 = (int32_T)(200U - rtb_Saturation1) * 3;
    rtb_Inclination = INS_DWork.Delay_DSTATE_lv[rtb_Saturation1];
    rtb_delay_acc_O_idx_1 = INS_DWork.Delay_DSTATE_lv[1 + rtb_Saturation1];
    rtb_delay_acc_O_idx_2 = INS_DWork.Delay_DSTATE_lv[2 + rtb_Saturation1];
  }

  /* End of Delay: '<S122>/Delay' */

  /* RelationalOperator: '<S139>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S139>/Delay Input1'
   */
  rtb_Delay_h = ((int32_T)rtb_LogicalOperator1_o > (int32_T)
                 INS_DWork.DelayInput1_DSTATE_ff);

  /* Outputs for Enabled SubSystem: '<S123>/GPS_Acc_Observer' incorporates:
   *  EnablePort: '<S140>/Enable'
   */
  if (rtb_LogicalOperator1_o) {
    if (!INS_DWork.GPS_Acc_Observer_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' */
      INS_DWork.DiscreteTimeIntegrator1_IC_L_oi = 1U;
      INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
      INS_DWork.DiscreteTimeIntegrator_DSTATE_o[0] =
        INS_P.DiscreteTimeIntegrator_IC_a;
      INS_DWork.DiscreteTimeIntegrator_DSTATE_o[1] =
        INS_P.DiscreteTimeIntegrator_IC_a;
      INS_DWork.DiscreteTimeIntegrator_DSTATE_o[2] =
        INS_P.DiscreteTimeIntegrator_IC_a;
      INS_DWork.DiscreteTimeIntegrator_PrevRe_c = 0;
      INS_DWork.GPS_Acc_Observer_MODE = true;
    }

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' */
    if (INS_DWork.DiscreteTimeIntegrator1_IC_L_oi != 0) {
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] = rtb_vel_N;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] = rtb_vel_E;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] = rtb_vel_D;
    }

    if (rtb_Delay_h || (INS_DWork.DiscreteTimeIntegrator1_PrevRes != 0)) {
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] = rtb_vel_N;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] = rtb_vel_E;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] = rtb_vel_D;
    }

    /* Sum: '<S144>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator1'
     */
    rtb_Multiply_j[0] = rtb_vel_N - INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0];
    rtb_Multiply_j[1] = rtb_vel_E - INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1];
    rtb_Multiply_j[2] = rtb_vel_D - INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2];

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    if (rtb_Delay_h || (INS_DWork.DiscreteTimeIntegrator_PrevRe_c != 0)) {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_o[0] =
        INS_P.DiscreteTimeIntegrator_IC_a;
      INS_DWork.DiscreteTimeIntegrator_DSTATE_o[1] =
        INS_P.DiscreteTimeIntegrator_IC_a;
      INS_DWork.DiscreteTimeIntegrator_DSTATE_o[2] =
        INS_P.DiscreteTimeIntegrator_IC_a;
    }

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_L_oi = 0U;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Delay_h;

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_B.DiscreteTimeIntegrator[0] = INS_DWork.DiscreteTimeIntegrator_DSTATE_o
      [0];

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S144>/Gain2'
     *  Sum: '<S144>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] += (INS_P.Gain2_Gain_a *
      rtb_Multiply_j[0] + INS_B.DiscreteTimeIntegrator[0]) *
      INS_P.DiscreteTimeIntegrator1_gainval;

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator1'
     *  Gain: '<S144>/Gain2'
     *  Gain: '<S144>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o[0] += INS_P.Gain3_Gain_p *
      rtb_Multiply_j[0] * INS_P.DiscreteTimeIntegrator_gainv_i0;

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_B.DiscreteTimeIntegrator[1] = INS_DWork.DiscreteTimeIntegrator_DSTATE_o
      [1];

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S144>/Gain2'
     *  Sum: '<S144>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] += (INS_P.Gain2_Gain_a *
      rtb_Multiply_j[1] + INS_B.DiscreteTimeIntegrator[1]) *
      INS_P.DiscreteTimeIntegrator1_gainval;

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator1'
     *  Gain: '<S144>/Gain2'
     *  Gain: '<S144>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o[1] += INS_P.Gain3_Gain_p *
      rtb_Multiply_j[1] * INS_P.DiscreteTimeIntegrator_gainv_i0;

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_B.DiscreteTimeIntegrator[2] = INS_DWork.DiscreteTimeIntegrator_DSTATE_o
      [2];

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S144>/Gain2'
     *  Sum: '<S144>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] += (INS_P.Gain2_Gain_a *
      rtb_Multiply_j[2] + INS_B.DiscreteTimeIntegrator[2]) *
      INS_P.DiscreteTimeIntegrator1_gainval;

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator1'
     *  Gain: '<S144>/Gain2'
     *  Gain: '<S144>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o[2] += INS_P.Gain3_Gain_p *
      rtb_Multiply_j[2] * INS_P.DiscreteTimeIntegrator_gainv_i0;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_c = (int8_T)rtb_Delay_h;
  } else {
    if (INS_DWork.GPS_Acc_Observer_MODE) {
      INS_DWork.GPS_Acc_Observer_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S123>/GPS_Acc_Observer' */

  /* Outputs for Enabled SubSystem: '<S123>/OpticalFlow_Acc_Observer' incorporates:
   *  EnablePort: '<S142>/Enable'
   */
  if (rtb_Compare_cl > 0) {
    if (!INS_DWork.OpticalFlow_Acc_Observer_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator1' */
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0] =
        INS_P.DiscreteTimeIntegrator1_IC;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1] =
        INS_P.DiscreteTimeIntegrator1_IC;

      /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
      INS_DWork.DiscreteTimeIntegrator_IC_LOA_k = 1U;
      INS_DWork.OpticalFlow_Acc_Observer_MODE = true;
    }

    /* Sum: '<S145>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator1'
     */
    rtb_Square_l_idx_0 = rtb_uT[0] - INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0];
    rtb_Square_l_idx_1 = rtb_uT[1] - INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1];

    /* DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
    if (INS_DWork.DiscreteTimeIntegrator_IC_LOA_k != 0) {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0] = rtb_uT[0];
      INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1] = rtb_uT[1];
    }

    /* Reshape: '<S142>/Reshape' incorporates:
     *  Constant: '<S142>/Constant'
     */
    INS_B.Reshape[2] = INS_P.Constant_Value_gi;

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_IC_LOA_k = 0U;

    /* Reshape: '<S142>/Reshape' incorporates:
     *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
     */
    INS_B.Reshape[0] = INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0];

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
     *  Gain: '<S145>/Gain2'
     *  Sum: '<S145>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0] += (INS_P.Gain2_Gain_b *
      rtb_Square_l_idx_0 + INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0]) *
      INS_P.DiscreteTimeIntegrator1_gainv_m;

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S145>/Gain2'
     *  Gain: '<S145>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0] += INS_P.Gain3_Gain_i *
      rtb_Square_l_idx_0 * INS_P.DiscreteTimeIntegrator_gainva_l;

    /* Reshape: '<S142>/Reshape' incorporates:
     *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
     */
    INS_B.Reshape[1] = INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1];

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
     *  Gain: '<S145>/Gain2'
     *  Sum: '<S145>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1] += (INS_P.Gain2_Gain_b *
      rtb_Square_l_idx_1 + INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1]) *
      INS_P.DiscreteTimeIntegrator1_gainv_m;

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S145>/Gain2'
     *  Gain: '<S145>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1] += INS_P.Gain3_Gain_i *
      rtb_Square_l_idx_1 * INS_P.DiscreteTimeIntegrator_gainva_l;
  } else {
    if (INS_DWork.OpticalFlow_Acc_Observer_MODE) {
      INS_DWork.OpticalFlow_Acc_Observer_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S123>/OpticalFlow_Acc_Observer' */

  /* Sum: '<S143>/Sum2' incorporates:
   *  Constant: '<S143>/gravity'
   *  Product: '<S143>/Multiply'
   *  Product: '<S143>/Multiply1'
   *  Sum: '<S143>/Sum'
   */
  rtb_DiscreteTimeIntegrator_c_id = ((real32_T)rtb_Compare_cl * INS_B.Reshape[0]
    + (rtb_LogicalOperator1_o ? INS_B.DiscreteTimeIntegrator[0] : 0.0F)) +
    INS_P.gravity_Value[0];
  rtb_DiscreteTimeIntegrator_c__0 = ((real32_T)rtb_Compare_cl * INS_B.Reshape[1]
    + (rtb_LogicalOperator1_o ? INS_B.DiscreteTimeIntegrator[1] : 0.0F)) +
    INS_P.gravity_Value[1];
  rtb_DiscreteTimeIntegrator_c__1 = ((real32_T)rtb_Compare_cl * INS_B.Reshape[2]
    + (rtb_LogicalOperator1_o ? INS_B.DiscreteTimeIntegrator[2] : 0.0F)) +
    INS_P.gravity_Value[2];

  /* Sum: '<S129>/Sum' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Product: '<S130>/Multiply'
   *  Product: '<S131>/Multiply'
   */
  rtb_Square_l_idx_0 = rtb_delay_acc_O_idx_1 * INS_P.Constant1_Value_cx -
    INS_P.Constant_Value_m * rtb_DiscreteTimeIntegrator_c__0;

  /* DeadZone: '<S124>/Dead Zone2' */
  if (rtb_Square_l_idx_0 > INS_P.DeadZone2_End) {
    /* Sum: '<S129>/Sum' */
    rtb_Divide1_m[0] = rtb_Square_l_idx_0 - INS_P.DeadZone2_End;
  } else if (rtb_Square_l_idx_0 >= INS_P.DeadZone2_Start) {
    /* Sum: '<S129>/Sum' */
    rtb_Divide1_m[0] = 0.0F;
  } else {
    /* Sum: '<S129>/Sum' */
    rtb_Divide1_m[0] = rtb_Square_l_idx_0 - INS_P.DeadZone2_Start;
  }

  /* Sum: '<S129>/Sum' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Product: '<S130>/Multiply1'
   *  Product: '<S131>/Multiply1'
   */
  rtb_Square_l_idx_0 = INS_P.Constant_Value_m * rtb_DiscreteTimeIntegrator_c_id
    - rtb_Inclination * INS_P.Constant1_Value_cx;

  /* DeadZone: '<S124>/Dead Zone2' */
  if (rtb_Square_l_idx_0 > INS_P.DeadZone2_End) {
    /* Sum: '<S129>/Sum' */
    rtb_Divide1_m[1] = rtb_Square_l_idx_0 - INS_P.DeadZone2_End;
  } else if (rtb_Square_l_idx_0 >= INS_P.DeadZone2_Start) {
    /* Sum: '<S129>/Sum' */
    rtb_Divide1_m[1] = 0.0F;
  } else {
    /* Sum: '<S129>/Sum' */
    rtb_Divide1_m[1] = rtb_Square_l_idx_0 - INS_P.DeadZone2_Start;
  }

  /* Sum: '<S129>/Sum' incorporates:
   *  Product: '<S130>/Multiply2'
   *  Product: '<S131>/Multiply2'
   */
  rtb_Square_l_idx_0 = rtb_Inclination * rtb_DiscreteTimeIntegrator_c__0 -
    rtb_delay_acc_O_idx_1 * rtb_DiscreteTimeIntegrator_c_id;

  /* DeadZone: '<S124>/Dead Zone2' */
  if (rtb_Square_l_idx_0 > INS_P.DeadZone2_End) {
    rtb_Square_l_idx_0 -= INS_P.DeadZone2_End;
  } else if (rtb_Square_l_idx_0 >= INS_P.DeadZone2_Start) {
    rtb_Square_l_idx_0 = 0.0F;
  } else {
    rtb_Square_l_idx_0 -= INS_P.DeadZone2_Start;
  }

  /* DotProduct: '<S127>/Dot Product' incorporates:
   *  Sum: '<S134>/Sum of Elements'
   */
  rtb_Multiply_g1 = rtb_Inclination * rtb_Inclination + rtb_delay_acc_O_idx_1 *
    rtb_delay_acc_O_idx_1;

  /* Sqrt: '<S127>/Sqrt' incorporates:
   *  DotProduct: '<S127>/Dot Product'
   */
  rtb_DiscreteTimeIntegrator_pm = sqrtf(rtb_Multiply_g1);

  /* Sqrt: '<S126>/Sqrt' incorporates:
   *  DotProduct: '<S126>/Dot Product'
   */
  rtb_Square_l_idx_1 = sqrtf(rtb_DiscreteTimeIntegrator_c_id *
    rtb_DiscreteTimeIntegrator_c_id + rtb_DiscreteTimeIntegrator_c__0 *
    rtb_DiscreteTimeIntegrator_c__0);

  /* MinMax: '<S128>/Max1' incorporates:
   *  Constant: '<S128>/Constant'
   *  MinMax: '<S128>/Max'
   */
  rtb_Add_m = fmaxf(INS_P.Constant_Value_ew, fmaxf(rtb_DiscreteTimeIntegrator_pm,
    rtb_Square_l_idx_1));

  /* Sum: '<S128>/Subtract' */
  rtb_DiscreteTimeIntegrator_pm -= rtb_Square_l_idx_1;

  /* Abs: '<S128>/Abs' */
  rtb_DiscreteTimeIntegrator_pm = fabsf(rtb_DiscreteTimeIntegrator_pm);

  /* Sum: '<S128>/Subtract1' incorporates:
   *  Constant: '<S128>/Constant1'
   *  Gain: '<S128>/Gain'
   *  Product: '<S128>/Divide'
   */
  rtb_DiscreteTimeIntegrator_pm = INS_P.Constant1_Value_o - 1.0F / rtb_Add_m *
    (INS_P.Gain_Gain_a * rtb_DiscreteTimeIntegrator_pm);

  /* Saturate: '<S128>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_pm > INS_P.Saturation_UpperSat_g) {
    rtb_Add_m = INS_P.Saturation_UpperSat_g;
  } else if (rtb_DiscreteTimeIntegrator_pm < INS_P.Saturation_LowerSat_n) {
    rtb_Add_m = INS_P.Saturation_LowerSat_n;
  } else {
    rtb_Add_m = rtb_DiscreteTimeIntegrator_pm;
  }

  /* End of Saturate: '<S128>/Saturation' */

  /* DiscreteFir: '<S124>/Discrete FIR Filter' */
  rtb_DiscreteTimeIntegrator_pm = rtb_Add_m *
    INS_P.DiscreteFIRFilter_Coefficients[0];
  for (rtb_Saturation1 = INS_DWork.DiscreteFIRFilter_circBuf; rtb_Saturation1 <
       29; rtb_Saturation1++) {
    rtb_DiscreteTimeIntegrator_pm +=
      INS_DWork.DiscreteFIRFilter_states[rtb_Saturation1] *
      INS_P.DiscreteFIRFilter_Coefficients[i];
    i++;
  }

  for (rtb_Saturation1 = 0; rtb_Saturation1 <
       INS_DWork.DiscreteFIRFilter_circBuf; rtb_Saturation1++) {
    rtb_DiscreteTimeIntegrator_pm +=
      INS_DWork.DiscreteFIRFilter_states[rtb_Saturation1] *
      INS_P.DiscreteFIRFilter_Coefficients[i];
    i++;
  }

  /* End of DiscreteFir: '<S124>/Discrete FIR Filter' */

  /* Logic: '<S143>/Logical Operator' */
  rtb_Delay_h = (rtb_LogicalOperator1_o || (rtb_Compare_cl != 0));

  /* Saturate: '<S124>/Saturation' */
  rtb_Square_l_idx_1 = rtb_Divide1_m[0];
  if (rtb_Divide1_m[0] > INS_P.Saturation_UpperSat_k) {
    rtb_Square_l_idx_1 = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Divide1_m[0] < INS_P.Saturation_LowerSat_k) {
      rtb_Square_l_idx_1 = INS_P.Saturation_LowerSat_k;
    }
  }

  /* Product: '<S124>/Multiply' incorporates:
   *  Gain: '<S124>/Gain'
   *  Product: '<S124>/Multiply1'
   */
  rtb_Multiply_j[0] = rtb_Delay_h ? INS_P.Gain_Gain_oh * rtb_Square_l_idx_1 *
    rtb_DiscreteTimeIntegrator_pm : 0.0F;

  /* Saturate: '<S124>/Saturation' */
  rtb_Square_l_idx_1 = rtb_Divide1_m[1];
  if (rtb_Divide1_m[1] > INS_P.Saturation_UpperSat_k) {
    rtb_Square_l_idx_1 = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Divide1_m[1] < INS_P.Saturation_LowerSat_k) {
      rtb_Square_l_idx_1 = INS_P.Saturation_LowerSat_k;
    }
  }

  /* Product: '<S124>/Multiply' incorporates:
   *  Gain: '<S124>/Gain'
   *  Product: '<S124>/Multiply1'
   */
  rtb_Multiply_j[1] = rtb_Delay_h ? INS_P.Gain_Gain_oh * rtb_Square_l_idx_1 *
    rtb_DiscreteTimeIntegrator_pm : 0.0F;

  /* End of Outputs for SubSystem: '<S56>/Correct' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_Square_l_idx_1 = rtb_Square_l_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/Correct' */
  /* Saturate: '<S124>/Saturation' */
  if (rtb_Square_l_idx_0 > INS_P.Saturation_UpperSat_k) {
    rtb_Square_l_idx_1 = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Square_l_idx_0 < INS_P.Saturation_LowerSat_k) {
      rtb_Square_l_idx_1 = INS_P.Saturation_LowerSat_k;
    }
  }

  /* Product: '<S124>/Multiply' incorporates:
   *  Gain: '<S124>/Gain'
   *  Product: '<S124>/Multiply1'
   */
  rtb_Multiply_j[2] = rtb_Delay_h ? INS_P.Gain_Gain_oh * rtb_Square_l_idx_1 *
    rtb_DiscreteTimeIntegrator_pm : 0.0F;

  /* Sum: '<S134>/Sum of Elements' incorporates:
   *  Math: '<S134>/Math Function'
   */
  rtb_DiscreteTimeIntegrator_pm = rtb_Multiply_g1 + rtb_delay_acc_O_idx_2 *
    rtb_delay_acc_O_idx_2;

  /* Math: '<S134>/Math Function1'
   *
   * About '<S134>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_DiscreteTimeIntegrator_pm < 0.0F) {
    rtb_DiscreteTimeIntegrator_pm = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_pm));
  } else {
    rtb_DiscreteTimeIntegrator_pm = sqrtf(rtb_DiscreteTimeIntegrator_pm);
  }

  /* End of Math: '<S134>/Math Function1' */

  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S134>/Constant'
   *  Product: '<S134>/Product'
   */
  if (rtb_DiscreteTimeIntegrator_pm <= INS_P.Switch_Threshold) {
    rtb_Inclination = 0.0F;
    rtb_delay_acc_O_idx_1 = 0.0F;
    rtb_delay_acc_O_idx_2 = 0.0F;
    rtb_DiscreteTimeIntegrator_pm = INS_P.Constant_Value_fk;
  }

  /* End of Switch: '<S134>/Switch' */

  /* Product: '<S134>/Divide1' */
  rtb_ba_O_mDs2[0] = rtb_Inclination / rtb_DiscreteTimeIntegrator_pm;
  rtb_ba_O_mDs2[1] = rtb_delay_acc_O_idx_1 / rtb_DiscreteTimeIntegrator_pm;
  rtb_ba_O_mDs2[2] = rtb_delay_acc_O_idx_2 / rtb_DiscreteTimeIntegrator_pm;

  /* Sum: '<S135>/Sum of Elements' incorporates:
   *  Math: '<S135>/Math Function'
   */
  rtb_DiscreteTimeIntegrator_pm = (rtb_DiscreteTimeIntegrator_c_id *
    rtb_DiscreteTimeIntegrator_c_id + rtb_DiscreteTimeIntegrator_c__0 *
    rtb_DiscreteTimeIntegrator_c__0) + rtb_DiscreteTimeIntegrator_c__1 *
    rtb_DiscreteTimeIntegrator_c__1;

  /* Math: '<S135>/Math Function1'
   *
   * About '<S135>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_DiscreteTimeIntegrator_pm < 0.0F) {
    rtb_DiscreteTimeIntegrator_pm = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_pm));
  } else {
    rtb_DiscreteTimeIntegrator_pm = sqrtf(rtb_DiscreteTimeIntegrator_pm);
  }

  /* End of Math: '<S135>/Math Function1' */

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S135>/Constant'
   *  Product: '<S135>/Product'
   */
  if (rtb_DiscreteTimeIntegrator_pm > INS_P.Switch_Threshold_b) {
    rtb_Inclination = rtb_DiscreteTimeIntegrator_c_id;
    rtb_delay_acc_O_idx_1 = rtb_DiscreteTimeIntegrator_c__0;
    rtb_delay_acc_O_idx_2 = rtb_DiscreteTimeIntegrator_c__1;
  } else {
    rtb_Inclination = 0.0F;
    rtb_delay_acc_O_idx_1 = 0.0F;
    rtb_delay_acc_O_idx_2 = 0.0F;
    rtb_DiscreteTimeIntegrator_pm = INS_P.Constant_Value_a;
  }

  /* End of Switch: '<S135>/Switch' */

  /* Product: '<S135>/Divide1' */
  rtb_Divide1_m[0] = rtb_Inclination / rtb_DiscreteTimeIntegrator_pm;
  rtb_Divide1_m[1] = rtb_delay_acc_O_idx_1 / rtb_DiscreteTimeIntegrator_pm;
  rtb_Divide1_m[2] = rtb_delay_acc_O_idx_2 / rtb_DiscreteTimeIntegrator_pm;

  /* Product: '<S132>/Product4' */
  rtb_DiscreteTimeIntegrator_pm = rtb_ba_O_mDs2[0] * rtb_Divide1_m[1];

  /* Product: '<S132>/Product3' */
  rtb_delay_acc_O_idx_2 = rtb_ba_O_mDs2[0];

  /* Product: '<S132>/Product5' */
  rtb_DiscreteTimeIntegrator_c_id = rtb_ba_O_mDs2[1];

  /* SignalConversion: '<S137>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S132>/Product'
   *  Product: '<S132>/Product1'
   *  Product: '<S132>/Product2'
   *  Product: '<S132>/Product3'
   *  Product: '<S132>/Product5'
   *  Sum: '<S132>/Subtract'
   *  Sum: '<S132>/Subtract1'
   *  Sum: '<S132>/Subtract2'
   */
  rtb_ba_O_mDs2[0] = rtb_ba_O_mDs2[1] * rtb_Divide1_m[2] - rtb_ba_O_mDs2[2] *
    rtb_Divide1_m[1];
  rtb_ba_O_mDs2[1] = rtb_ba_O_mDs2[2] * rtb_Divide1_m[0] - rtb_delay_acc_O_idx_2
    * rtb_Divide1_m[2];
  rtb_ba_O_mDs2[2] = rtb_DiscreteTimeIntegrator_pm -
    rtb_DiscreteTimeIntegrator_c_id * rtb_Divide1_m[0];

  /* Gain: '<S138>/Gain' incorporates:
   *  DiscreteIntegrator: '<S138>/Discrete-Time Integrator1'
   *  Sum: '<S138>/Sum'
   */
  rtb_MatrixConcatenate[0] = (rtb_MatrixConcatenate[0] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0]) * INS_P.Gain_Gain_l;
  rtb_MatrixConcatenate[1] = (rtb_MatrixConcatenate[1] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1]) * INS_P.Gain_Gain_l;
  rtb_delay_acc_O_idx_1 = (rtb_MatrixConcatenate[2] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2]) * INS_P.Gain_Gain_l;

  /* Sqrt: '<S136>/Sqrt' incorporates:
   *  Math: '<S137>/Square'
   *  Sum: '<S137>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_pm = sqrtf((rtb_ba_O_mDs2[0] * rtb_ba_O_mDs2[0] +
    rtb_ba_O_mDs2[1] * rtb_ba_O_mDs2[1]) + rtb_ba_O_mDs2[2] * rtb_ba_O_mDs2[2]);

  /* Product: '<S133>/Divide1' incorporates:
   *  Constant: '<S125>/Constant8'
   */
  rtb_Square_l_idx_1 = rtb_DiscreteTimeIntegrator_pm / INS_P.Constant8_Value;

  /* Saturate: '<S133>/Saturation' */
  if (rtb_Square_l_idx_1 > INS_P.Saturation_UpperSat_e) {
    rtb_Square_l_idx_1 = INS_P.Saturation_UpperSat_e;
  } else {
    if (rtb_Square_l_idx_1 < INS_P.Saturation_LowerSat_f) {
      rtb_Square_l_idx_1 = INS_P.Saturation_LowerSat_f;
    }
  }

  /* End of Saturate: '<S133>/Saturation' */

  /* Product: '<S133>/Divide2' incorporates:
   *  Constant: '<S125>/Constant8'
   *  Trigonometry: '<S133>/Trigonometric Function'
   */
  rtb_Inclination = arm_sin_f32(rtb_Square_l_idx_1) * INS_P.Constant8_Value;

  /* MinMax: '<S133>/MinMax' incorporates:
   *  Constant: '<S133>/Constant1'
   */
  rtb_DiscreteTimeIntegrator_c_id = fmaxf(rtb_DiscreteTimeIntegrator_pm,
    INS_P.Constant1_Value_nm);

  /* Relay: '<S146>/Relay1' */
  if (rtb_Saturation_ad >= INS_P.Relay1_OnVal) {
    INS_DWork.Relay1_Mode = true;
  } else {
    if (rtb_Saturation_ad <= INS_P.Relay1_OffVal) {
      INS_DWork.Relay1_Mode = false;
    }
  }

  if (INS_DWork.Relay1_Mode) {
    rtb_delay_acc_O_idx_2 = INS_P.Relay1_YOn;
  } else {
    rtb_delay_acc_O_idx_2 = INS_P.Relay1_YOff;
  }

  /* End of Relay: '<S146>/Relay1' */

  /* Logic: '<S146>/Logical Operator' incorporates:
   *  Logic: '<S120>/Logical Operator'
   */
  rtb_Delay_h = (((rtb_Relay2 != 0.0F) || rtb_Compare_cio) &&
                 (rtb_delay_acc_O_idx_2 != 0.0F));

  /* Gain: '<S147>/mag_correct_gain' incorporates:
   *  Delay: '<S56>/Delay'
   *  Product: '<S147>/MX Product4'
   *  Selector: '<S147>/Selector4'
   */
  rtb_DiscreteTimeIntegrator_pm = ((INS_DWork.Delay_8_DSTATE_l[1] *
    rtb_Product1_n[0] + INS_DWork.Delay_8_DSTATE_l[4] * rtb_Product1_n[1]) +
    INS_DWork.Delay_8_DSTATE_l[7] * rtb_Product1_n[2]) *
    INS_P.mag_correct_gain_Gain;

  /* Sum: '<S117>/Sum' incorporates:
   *  Delay: '<S56>/Delay'
   *  Gain: '<S125>/Gain'
   *  Product: '<S133>/Divide'
   *  Product: '<S147>/MX Product3'
   *  Selector: '<S147>/Selector2'
   *  Sum: '<S121>/Sum'
   */
  rtb_delay_acc_O_idx_2 = (rtb_ba_O_mDs2[0] * rtb_Inclination /
    rtb_DiscreteTimeIntegrator_c_id * INS_P.Gain_Gain_ok[0] + rtb_Multiply_j[0])
    + (rtb_Delay_h ? INS_DWork.Delay_8_DSTATE_l[2] *
       rtb_DiscreteTimeIntegrator_pm : 0.0F);
  rtb_Square_l_idx_1 = (rtb_ba_O_mDs2[1] * rtb_Inclination /
                        rtb_DiscreteTimeIntegrator_c_id * INS_P.Gain_Gain_ok[1]
                        + rtb_Multiply_j[1]) + (rtb_Delay_h ?
    INS_DWork.Delay_8_DSTATE_l[5] * rtb_DiscreteTimeIntegrator_pm : 0.0F);
  rtb_DiscreteTimeIntegrator_c_id = (rtb_ba_O_mDs2[2] * rtb_Inclination /
    rtb_DiscreteTimeIntegrator_c_id * INS_P.Gain_Gain_ok[2] + rtb_Multiply_j[2])
    + (rtb_Delay_h ? INS_DWork.Delay_8_DSTATE_l[8] *
       rtb_DiscreteTimeIntegrator_pm : 0.0F);
  for (i = 0; i < 3; i++) {
    /* Math: '<S152>/Square' */
    rtb_ba_O_mDs2[i] = rtb_Switch3[i] * rtb_Switch3[i];

    /* Product: '<S117>/Multiply' incorporates:
     *  Delay: '<S56>/Delay'
     */
    rtb_Divide1_m[i] = INS_DWork.Delay_9_DSTATE[i + 6] *
      rtb_DiscreteTimeIntegrator_c_id + (INS_DWork.Delay_9_DSTATE[i + 3] *
      rtb_Square_l_idx_1 + INS_DWork.Delay_9_DSTATE[i] * rtb_delay_acc_O_idx_2);
  }

  /* RelationalOperator: '<S149>/Compare' incorporates:
   *  Abs: '<S118>/Abs'
   *  Constant: '<S118>/Constant'
   *  Constant: '<S149>/Constant'
   *  Sqrt: '<S151>/Sqrt'
   *  Sum: '<S118>/Subtract'
   *  Sum: '<S152>/Sum of Elements'
   */
  rtb_Delay_h = (fabsf(sqrtf((rtb_ba_O_mDs2[0] + rtb_ba_O_mDs2[1]) +
    rtb_ba_O_mDs2[2]) - INS_P.Constant_Value_n2) <=
                 INS_P.CompareToConstant_const_n);

  /* Gain: '<S150>/Gain' incorporates:
   *  Logic: '<S150>/Logical Operator'
   */
  rtb_DiscreteTimeIntegrator_pm = rtb_Relay2 == 0.0F ? (real32_T)
    INS_P.Gain_Gain_g * 0.015625F : 0.0F;

  /* RateLimiter: '<S150>/Rate Limiter' */
  rtb_Inclination = rtb_DiscreteTimeIntegrator_pm - INS_DWork.PrevY;
  if (rtb_Inclination > INS_P.RateLimiter_RisingLim) {
    rtb_DiscreteTimeIntegrator_pm = INS_DWork.PrevY +
      INS_P.RateLimiter_RisingLim;
  } else {
    if (rtb_Inclination < INS_P.RateLimiter_FallingLim) {
      rtb_DiscreteTimeIntegrator_pm = INS_DWork.PrevY +
        INS_P.RateLimiter_FallingLim;
    }
  }

  INS_DWork.PrevY = rtb_DiscreteTimeIntegrator_pm;

  /* End of RateLimiter: '<S150>/Rate Limiter' */

  /* Saturate: '<S150>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_pm > INS_P.Saturation_UpperSat_ky) {
    rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation_UpperSat_ky;
  } else {
    if (rtb_DiscreteTimeIntegrator_pm < INS_P.Saturation_LowerSat_f3) {
      rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation_LowerSat_f3;
    }
  }

  /* End of Saturate: '<S150>/Saturation' */

  /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_o = 0U;

  /* Gain: '<S118>/Gain3' incorporates:
   *  DataTypeConversion: '<S118>/Data Type Conversion'
   *  Product: '<S118>/MX Product1'
   */
  rtb_Square_l_idx_1 = rtb_Divide1_m[0] * (real32_T)rtb_Delay_h *
    INS_P.Gain3_Gain_k;

  /* Saturate: '<S118>/Saturation2' */
  if (rtb_Square_l_idx_1 > INS_P.Saturation2_UpperSat_h) {
    rtb_Square_l_idx_1 = INS_P.Saturation2_UpperSat_h;
  } else {
    if (rtb_Square_l_idx_1 < INS_P.Saturation2_LowerSat_o) {
      rtb_Square_l_idx_1 = INS_P.Saturation2_LowerSat_o;
    }
  }

  /* Saturate: '<S150>/Saturation1' incorporates:
   *  Delay: '<S56>/Delay'
   */
  if (INS_DWork.Delay_10_DSTATE[0] > INS_P.Saturation1_UpperSat_p) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_UpperSat_p;
  } else if (INS_DWork.Delay_10_DSTATE[0] < INS_P.Saturation1_LowerSat_j) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_LowerSat_j;
  } else {
    rtb_delay_acc_O_idx_2 = INS_DWork.Delay_10_DSTATE[0];
  }

  /* Sum: '<S118>/Sum2' incorporates:
   *  Gain: '<S118>/Gain4'
   *  Product: '<S150>/Product'
   */
  rtb_Multiply_j[0] = rtb_Square_l_idx_1 - rtb_delay_acc_O_idx_2 * rtb_Relay2 *
    rtb_DiscreteTimeIntegrator_pm * INS_P.Gain4_Gain_d;

  /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S138>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_d *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0];

  /* Gain: '<S118>/Gain3' incorporates:
   *  DataTypeConversion: '<S118>/Data Type Conversion'
   *  Product: '<S118>/MX Product1'
   */
  rtb_Square_l_idx_1 = rtb_Divide1_m[1] * (real32_T)rtb_Delay_h *
    INS_P.Gain3_Gain_k;

  /* Saturate: '<S118>/Saturation2' */
  if (rtb_Square_l_idx_1 > INS_P.Saturation2_UpperSat_h) {
    rtb_Square_l_idx_1 = INS_P.Saturation2_UpperSat_h;
  } else {
    if (rtb_Square_l_idx_1 < INS_P.Saturation2_LowerSat_o) {
      rtb_Square_l_idx_1 = INS_P.Saturation2_LowerSat_o;
    }
  }

  /* Saturate: '<S150>/Saturation1' incorporates:
   *  Delay: '<S56>/Delay'
   */
  if (INS_DWork.Delay_10_DSTATE[1] > INS_P.Saturation1_UpperSat_p) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_UpperSat_p;
  } else if (INS_DWork.Delay_10_DSTATE[1] < INS_P.Saturation1_LowerSat_j) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_LowerSat_j;
  } else {
    rtb_delay_acc_O_idx_2 = INS_DWork.Delay_10_DSTATE[1];
  }

  /* Sum: '<S118>/Sum2' incorporates:
   *  Gain: '<S118>/Gain4'
   *  Product: '<S150>/Product'
   */
  rtb_Multiply_j[1] = rtb_Square_l_idx_1 - rtb_delay_acc_O_idx_2 * rtb_Relay2 *
    rtb_DiscreteTimeIntegrator_pm * INS_P.Gain4_Gain_d;

  /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S138>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_d *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1];

  /* Gain: '<S118>/Gain3' incorporates:
   *  DataTypeConversion: '<S118>/Data Type Conversion'
   *  Product: '<S118>/MX Product1'
   */
  rtb_Square_l_idx_1 = rtb_Divide1_m[2] * (real32_T)rtb_Delay_h *
    INS_P.Gain3_Gain_k;

  /* Saturate: '<S118>/Saturation2' */
  if (rtb_Square_l_idx_1 > INS_P.Saturation2_UpperSat_h) {
    rtb_Square_l_idx_1 = INS_P.Saturation2_UpperSat_h;
  } else {
    if (rtb_Square_l_idx_1 < INS_P.Saturation2_LowerSat_o) {
      rtb_Square_l_idx_1 = INS_P.Saturation2_LowerSat_o;
    }
  }

  /* Saturate: '<S150>/Saturation1' incorporates:
   *  Delay: '<S56>/Delay'
   */
  if (INS_DWork.Delay_10_DSTATE[2] > INS_P.Saturation1_UpperSat_p) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_UpperSat_p;
  } else if (INS_DWork.Delay_10_DSTATE[2] < INS_P.Saturation1_LowerSat_j) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_LowerSat_j;
  } else {
    rtb_delay_acc_O_idx_2 = INS_DWork.Delay_10_DSTATE[2];
  }

  /* Sum: '<S118>/Sum2' incorporates:
   *  Gain: '<S118>/Gain4'
   *  Product: '<S150>/Product'
   */
  rtb_Multiply_j[2] = rtb_Square_l_idx_1 - rtb_delay_acc_O_idx_2 * rtb_Relay2 *
    rtb_DiscreteTimeIntegrator_pm * INS_P.Gain4_Gain_d;

  /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S138>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_d *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2];

  /* Update for Delay: '<S122>/Delay' */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 199; rtb_Saturation1++) {
    i = (rtb_Saturation1 + 1) * 3;
    INS_DWork.Delay_DSTATE_lv[rtb_Saturation1 * 3] = INS_DWork.Delay_DSTATE_lv[i];
    INS_DWork.Delay_DSTATE_lv[rtb_Saturation1 * 3 + 1] =
      INS_DWork.Delay_DSTATE_lv[i + 1];
    INS_DWork.Delay_DSTATE_lv[rtb_Saturation1 * 3 + 2] =
      INS_DWork.Delay_DSTATE_lv[i + 2];
  }

  INS_DWork.Delay_DSTATE_lv[597] = rtb_DiscreteTimeIntegrator_g[0];
  INS_DWork.Delay_DSTATE_lv[598] = rtb_DiscreteTimeIntegrator_g[1];
  INS_DWork.Delay_DSTATE_lv[599] = rtb_DiscreteTimeIntegrator_g[2];

  /* End of Update for Delay: '<S122>/Delay' */

  /* Update for UnitDelay: '<S139>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ff = rtb_LogicalOperator1_o;

  /* Update for DiscreteFir: '<S124>/Discrete FIR Filter' */
  /* Update circular buffer index */
  INS_DWork.DiscreteFIRFilter_circBuf--;
  if (INS_DWork.DiscreteFIRFilter_circBuf < 0) {
    INS_DWork.DiscreteFIRFilter_circBuf = 28;
  }

  /* Update circular buffer */
  INS_DWork.DiscreteFIRFilter_states[INS_DWork.DiscreteFIRFilter_circBuf] =
    rtb_Add_m;

  /* End of Update for DiscreteFir: '<S124>/Discrete FIR Filter' */

  /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S138>/Gain1'
   *  Sum: '<S138>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0] += (INS_P.Gain1_Gain_m *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0] + rtb_MatrixConcatenate[0]) *
    INS_P.DiscreteTimeIntegrator_gainva_o;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1] += (INS_P.Gain1_Gain_m *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1] + rtb_MatrixConcatenate[1]) *
    INS_P.DiscreteTimeIntegrator_gainva_o;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2] += (INS_P.Gain1_Gain_m *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2] + rtb_delay_acc_O_idx_1) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  /* End of Outputs for SubSystem: '<S56>/Correct' */

  /* Outputs for Atomic SubSystem: '<S56>/Integrate' */
  /* Switch: '<S153>/Switch' incorporates:
   *  Constant: '<S153>/Constant'
   *  Delay: '<S153>/Delay'
   *  RelationalOperator: '<S157>/FixPt Relational Operator'
   *  UnitDelay: '<S157>/Delay Input1'
   */
  if ((int32_T)rtb_UpperTest_cv > (int32_T)INS_DWork.DelayInput1_DSTATE_dy) {
    rtb_Compare_cl = INS_P.Constant_Value_mm;
  } else {
    rtb_Compare_cl = INS_DWork.Delay_DSTATE_f0;
  }

  /* End of Switch: '<S153>/Switch' */

  /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator' */
  if (INS_DWork.DiscreteTimeIntegrator_IC_LOADI != 0) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] =
      INS_B.OutportBufferForquaternion_0[0];
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] =
      INS_B.OutportBufferForquaternion_0[1];
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] =
      INS_B.OutportBufferForquaternion_0[2];
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[3] =
      INS_B.OutportBufferForquaternion_0[3];
  }

  if (rtb_UpperTest_cv || (INS_DWork.DiscreteTimeIntegrator_PrevRese != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] =
      INS_B.OutportBufferForquaternion_0[0];
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] =
      INS_B.OutportBufferForquaternion_0[1];
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] =
      INS_B.OutportBufferForquaternion_0[2];
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[3] =
      INS_B.OutportBufferForquaternion_0[3];
  }

  /* Sqrt: '<S161>/sqrt' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   *  Product: '<S162>/Product'
   *  Product: '<S162>/Product1'
   *  Product: '<S162>/Product2'
   *  Product: '<S162>/Product3'
   *  Sum: '<S162>/Sum'
   */
  rtb_Square_l_idx_1 = sqrtf(((INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] +
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1]) +
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2]) +
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[3] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[3]);

  /* Product: '<S160>/Product' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   */
  rtb_Add_m = INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] / rtb_Square_l_idx_1;

  /* Product: '<S160>/Product1' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   */
  rtb_Inclination = INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Square_l_idx_1;

  /* Sum: '<S155>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator2'
   */
  rtb_delay_acc_O_idx_1 = INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] +
    rtb_VectorConcatenate_idx_0;

  /* Sum: '<S60>/Sum2' */
  rtb_ba_O_mDs2[0] = rtb_Divide1_m[0] + rtb_delay_acc_O_idx_1;

  /* Sum: '<S155>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator2'
   */
  rtb_VectorConcatenate_idx_0 = rtb_delay_acc_O_idx_1;
  rtb_delay_acc_O_idx_1 = INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] +
    rtb_VectorConcatenate_idx_1;

  /* Sum: '<S60>/Sum2' */
  rtb_ba_O_mDs2[1] = rtb_Divide1_m[1] + rtb_delay_acc_O_idx_1;

  /* Sum: '<S155>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator2'
   */
  rtb_VectorConcatenate_idx_1 = rtb_delay_acc_O_idx_1;
  rtb_delay_acc_O_idx_1 = INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] +
    rtb_Product3_eb;

  /* Sum: '<S60>/Sum2' */
  rtb_ba_O_mDs2[2] = rtb_Divide1_m[2] + rtb_delay_acc_O_idx_1;

  /* Product: '<S160>/Product2' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_c_id = INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2]
    / rtb_Square_l_idx_1;

  /* Product: '<S160>/Product3' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   */
  rtb_Product3_eb = INS_DWork.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Square_l_idx_1;

  /* Product: '<S159>/Product' incorporates:
   *  Product: '<S165>/Product'
   */
  rtb_delay_acc_O_idx_2 = rtb_Add_m * rtb_Add_m;
  rtb_DiscreteTimeIntegrator_c__1 = rtb_Inclination * rtb_Inclination;
  rtb_Square_l_idx_1 = rtb_DiscreteTimeIntegrator_c_id *
    rtb_DiscreteTimeIntegrator_c_id;
  rtb_DiscreteTimeIntegrator_c__0 = rtb_Product3_eb * rtb_Product3_eb;

  /* Sum: '<S159>/Add' incorporates:
   *  Product: '<S159>/Product'
   *  Sum: '<S165>/Add'
   */
  rtb_DiscreteTimeIntegrator_pm = ((rtb_delay_acc_O_idx_2 +
    rtb_DiscreteTimeIntegrator_c__1) - rtb_Square_l_idx_1) -
    rtb_DiscreteTimeIntegrator_c__0;
  rtb_VectorConcatenate_m[0] = rtb_DiscreteTimeIntegrator_pm;

  /* Sum: '<S159>/Add5' incorporates:
   *  Product: '<S159>/Product'
   *  Sum: '<S159>/Add8'
   */
  rtb_delay_acc_O_idx_2 -= rtb_DiscreteTimeIntegrator_c__1;
  rtb_VectorConcatenate_m[4] = (rtb_delay_acc_O_idx_2 + rtb_Square_l_idx_1) -
    rtb_DiscreteTimeIntegrator_c__0;

  /* Sum: '<S159>/Add8' incorporates:
   *  Product: '<S159>/Product'
   */
  rtb_VectorConcatenate_m[8] = (rtb_delay_acc_O_idx_2 - rtb_Square_l_idx_1) +
    rtb_DiscreteTimeIntegrator_c__0;

  /* Product: '<S159>/Product1' incorporates:
   *  Product: '<S159>/Product5'
   */
  rtb_delay_acc_O_idx_2 = rtb_Inclination * rtb_DiscreteTimeIntegrator_c_id;

  /* Product: '<S159>/Product2' incorporates:
   *  Product: '<S159>/Product6'
   */
  rtb_Square_l_idx_1 = rtb_Add_m * rtb_Product3_eb;

  /* Sum: '<S159>/Add1' incorporates:
   *  Product: '<S159>/Product1'
   *  Product: '<S159>/Product2'
   *  Sum: '<S165>/Add1'
   */
  rtb_Multiply_g1 = rtb_delay_acc_O_idx_2 + rtb_Square_l_idx_1;

  /* Gain: '<S159>/Gain' incorporates:
   *  Sum: '<S159>/Add1'
   */
  rtb_VectorConcatenate_m[1] = rtb_Multiply_g1 * INS_P.Gain_Gain_f;

  /* Product: '<S159>/Product3' incorporates:
   *  Product: '<S159>/Product9'
   */
  rtb_DiscreteTimeIntegrator_c__0 = rtb_Inclination * rtb_Product3_eb;

  /* Product: '<S159>/Product4' incorporates:
   *  Product: '<S159>/Product10'
   */
  rtb_DiscreteTimeIntegrator_c__1 = rtb_Add_m * rtb_DiscreteTimeIntegrator_c_id;

  /* Gain: '<S159>/Gain1' incorporates:
   *  Product: '<S159>/Product3'
   *  Product: '<S159>/Product4'
   *  Sum: '<S159>/Add2'
   */
  rtb_VectorConcatenate_m[2] = (rtb_DiscreteTimeIntegrator_c__0 -
    rtb_DiscreteTimeIntegrator_c__1) * INS_P.Gain1_Gain_k;

  /* Gain: '<S159>/Gain2' incorporates:
   *  Sum: '<S159>/Add3'
   */
  rtb_VectorConcatenate_m[3] = (rtb_delay_acc_O_idx_2 - rtb_Square_l_idx_1) *
    INS_P.Gain2_Gain_oj;

  /* Product: '<S159>/Product7' incorporates:
   *  Product: '<S159>/Product12'
   */
  rtb_delay_acc_O_idx_2 = rtb_DiscreteTimeIntegrator_c_id * rtb_Product3_eb;

  /* Product: '<S159>/Product8' incorporates:
   *  Product: '<S159>/Product11'
   */
  rtb_Square_l_idx_1 = rtb_Add_m * rtb_Inclination;

  /* Gain: '<S159>/Gain3' incorporates:
   *  Product: '<S159>/Product7'
   *  Product: '<S159>/Product8'
   *  Sum: '<S159>/Add4'
   */
  rtb_VectorConcatenate_m[5] = (rtb_delay_acc_O_idx_2 + rtb_Square_l_idx_1) *
    INS_P.Gain3_Gain_dx;

  /* Gain: '<S159>/Gain4' incorporates:
   *  Sum: '<S159>/Add6'
   */
  rtb_VectorConcatenate_m[6] = (rtb_DiscreteTimeIntegrator_c__0 +
    rtb_DiscreteTimeIntegrator_c__1) * INS_P.Gain4_Gain_o;

  /* Gain: '<S159>/Gain5' incorporates:
   *  Sum: '<S159>/Add7'
   */
  rtb_VectorConcatenate_m[7] = (rtb_delay_acc_O_idx_2 - rtb_Square_l_idx_1) *
    INS_P.Gain5_Gain;

  /* Math: '<S154>/Transpose2' */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    rtb_Transpose2[3 * rtb_Saturation1] =
      rtb_VectorConcatenate_m[rtb_Saturation1];
    rtb_Transpose2[1 + 3 * rtb_Saturation1] =
      rtb_VectorConcatenate_m[rtb_Saturation1 + 3];
    rtb_Transpose2[2 + 3 * rtb_Saturation1] =
      rtb_VectorConcatenate_m[rtb_Saturation1 + 6];
  }

  /* End of Math: '<S154>/Transpose2' */

  /* Gain: '<S163>/Gain5' incorporates:
   *  Selector: '<S156>/Selector2'
   */
  rtb_Square_l_idx_1 = INS_P.Gain5_Gain_d * rtb_Transpose2[6];

  /* Saturate: '<S163>/Saturation1' */
  if (rtb_Square_l_idx_1 > INS_P.Saturation1_UpperSat_o) {
    rtb_Square_l_idx_1 = INS_P.Saturation1_UpperSat_o;
  } else {
    if (rtb_Square_l_idx_1 < INS_P.Saturation1_LowerSat_b) {
      rtb_Square_l_idx_1 = INS_P.Saturation1_LowerSat_b;
    }
  }

  /* End of Saturate: '<S163>/Saturation1' */

  /* Trigonometry: '<S163>/Trigonometric Function' */
  if (rtb_Square_l_idx_1 > 1.0F) {
    rtb_Square_l_idx_1 = 1.0F;
  } else {
    if (rtb_Square_l_idx_1 < -1.0F) {
      rtb_Square_l_idx_1 = -1.0F;
    }
  }

  rtb_DiscreteTimeIntegrator_c__0 = asinf(rtb_Square_l_idx_1);

  /* End of Trigonometry: '<S163>/Trigonometric Function' */

  /* Trigonometry: '<S163>/Trigonometric Function1' incorporates:
   *  Selector: '<S156>/Selector2'
   */
  rtb_DiscreteTimeIntegrator_c__1 = atan2f(rtb_Transpose2[7], rtb_Transpose2[8]);

  /* Trigonometry: '<S165>/Trigonometric Function1' incorporates:
   *  Gain: '<S165>/Gain'
   */
  rtb_TrigonometricFunction1 = atan2f(rtb_Multiply_g1 * INS_P.Gain_Gain_h,
    rtb_DiscreteTimeIntegrator_pm);

  /* Trigonometry: '<S164>/TrigoFcn' */
  rtb_DiscreteTimeIntegrator_pm = arm_sin_f32(rtb_TrigonometricFunction1);

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentate2In1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[3] = rtb_DiscreteTimeIntegrator_pm;

  /* Trigonometry: '<S164>/TrigoFcn1' */
  rtb_Square_l_idx_1 = arm_cos_f32(rtb_TrigonometricFunction1);

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentate2In2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[4] = rtb_Square_l_idx_1;

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[5] = INS_P.Constant1_Value_g;

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentate3In1' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[6] = INS_P.Constant1_Value_g;

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentate3In2' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[7] = INS_P.Constant1_Value_g;

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentateIn1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[0] = rtb_Square_l_idx_1;

  /* SignalConversion: '<S164>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[2] = INS_P.Constant1_Value_g;

  /* Constant: '<S164>/Constant' incorporates:
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[8] = INS_P.Constant_Value_ev;

  /* Gain: '<S164>/Gain' incorporates:
   *  Delay: '<Root>/Delay'
   */
  INS_DWork.Delay_6_DSTATE[1] = INS_P.Gain_Gain_i *
    rtb_DiscreteTimeIntegrator_pm;

  /* Update for Delay: '<S153>/Delay' */
  INS_DWork.Delay_DSTATE_f0 = rtb_Compare_cl;

  /* Update for UnitDelay: '<S157>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dy = rtb_UpperTest_cv;

  /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S154>/Constant'
   *  Gain: '<S154>/Gain2'
   *  Product: '<S158>/Product'
   *  Product: '<S158>/Product1'
   *  Product: '<S158>/Product10'
   *  Product: '<S158>/Product11'
   *  Product: '<S158>/Product12'
   *  Product: '<S158>/Product13'
   *  Product: '<S158>/Product14'
   *  Product: '<S158>/Product15'
   *  Product: '<S158>/Product2'
   *  Product: '<S158>/Product3'
   *  Product: '<S158>/Product4'
   *  Product: '<S158>/Product5'
   *  Product: '<S158>/Product6'
   *  Product: '<S158>/Product7'
   *  Product: '<S158>/Product8'
   *  Product: '<S158>/Product9'
   *  Sum: '<S158>/Add'
   *  Sum: '<S158>/Add1'
   *  Sum: '<S158>/Add2'
   *  Sum: '<S158>/Add3'
   */
  INS_DWork.DiscreteTimeIntegrator_IC_LOADI = 0U;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] += (((rtb_Add_m *
    INS_P.Constant_Value_pu - rtb_Inclination * rtb_ba_O_mDs2[0]) -
    rtb_DiscreteTimeIntegrator_c_id * rtb_ba_O_mDs2[1]) - rtb_Product3_eb *
    rtb_ba_O_mDs2[2]) * INS_P.Gain2_Gain_i *
    INS_P.DiscreteTimeIntegrator_gainva_j;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] += (((rtb_Add_m * rtb_ba_O_mDs2[0]
    + rtb_Inclination * INS_P.Constant_Value_pu) +
    rtb_DiscreteTimeIntegrator_c_id * rtb_ba_O_mDs2[2]) - rtb_Product3_eb *
    rtb_ba_O_mDs2[1]) * INS_P.Gain2_Gain_i *
    INS_P.DiscreteTimeIntegrator_gainva_j;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] += (((rtb_Add_m * rtb_ba_O_mDs2[1]
    - rtb_Inclination * rtb_ba_O_mDs2[2]) + rtb_DiscreteTimeIntegrator_c_id *
    INS_P.Constant_Value_pu) + rtb_Product3_eb * rtb_ba_O_mDs2[0]) *
    INS_P.Gain2_Gain_i * INS_P.DiscreteTimeIntegrator_gainva_j;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[3] += (((rtb_Add_m * rtb_ba_O_mDs2[2]
    + rtb_Inclination * rtb_ba_O_mDs2[1]) - rtb_DiscreteTimeIntegrator_c_id *
    rtb_ba_O_mDs2[0]) + rtb_Product3_eb * INS_P.Constant_Value_pu) *
    INS_P.Gain2_Gain_i * INS_P.DiscreteTimeIntegrator_gainva_j;
  INS_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UpperTest_cv;

  /* Update for DiscreteIntegrator: '<S155>/Discrete-Time Integrator2' */
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] +=
    INS_P.DiscreteTimeIntegrator2_gainval * rtb_Multiply_j[0];
  if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] >=
      INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] <=
        INS_P.DiscreteTimeIntegrator2_LowerSa) {
      INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
        INS_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] +=
    INS_P.DiscreteTimeIntegrator2_gainval * rtb_Multiply_j[1];
  if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] >=
      INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] <=
        INS_P.DiscreteTimeIntegrator2_LowerSa) {
      INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
        INS_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] +=
    INS_P.DiscreteTimeIntegrator2_gainval * rtb_Multiply_j[2];
  if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] >=
      INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] <=
        INS_P.DiscreteTimeIntegrator2_LowerSa) {
      INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
        INS_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S155>/Discrete-Time Integrator2' */
  /* End of Outputs for SubSystem: '<S56>/Integrate' */

  /* Outputs for Atomic SubSystem: '<S57>/Process' */
  /* Logic: '<S271>/Logical Operator' */
  rtb_Compare_cio = !rtb_Compare_cio;

  /* Logic: '<S263>/Logical Operator' incorporates:
   *  Constant: '<S265>/Constant'
   *  RelationalOperator: '<S265>/Compare'
   *  SignalConversion: '<S271>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_Delay_h = (rtb_Compare_cio && (rtb_Sum4_k > INS_P.Constant_Value_be));

  /* RelationalOperator: '<S239>/Compare' incorporates:
   *  Constant: '<S239>/Constant'
   *  Logic: '<S263>/Logical Operator2'
   *  SignalConversion: '<S270>/TmpSignal ConversionAtSignal Conversion1Inport1'
   *  SignalConversion: '<S273>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_UpperTest_cv = ((rtb_Delay_h || rtb_LogicalOperator3 ||
                       rtb_FixPtRelationalOperator_if) > (int32_T)
                      INS_P.Constant_Value_bt);

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
  /* Logic: '<S236>/Logical Operator2' incorporates:
   *  Inport: '<Root>/reset'
   *  RelationalOperator: '<S238>/FixPt Relational Operator'
   *  UnitDelay: '<S238>/Delay Input1'
   */
  rtb_LogicalOperator1_o = (((int32_T)rtb_UpperTest_cv > (int32_T)
    INS_DWork.DelayInput1_DSTATE_j) || (INS_U.reset != 0));

  /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

  /* Logic: '<S262>/Logical Operator' incorporates:
   *  Constant: '<S264>/Constant'
   *  RelationalOperator: '<S264>/Compare'
   *  SignalConversion: '<S271>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_Delay_a = (rtb_Compare_cio && (rtb_Sum4_k > INS_P.Constant_Value_o0));

  /* RelationalOperator: '<S241>/Compare' incorporates:
   *  Constant: '<S241>/Constant'
   *  Logic: '<S262>/Logical Operator1'
   *  SignalConversion: '<S272>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_Compare_gt = ((rtb_Delay_a || rtb_Delay_d) > (int32_T)
                    INS_P.Constant_Value_gn);

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
  /* Logic: '<S237>/Logical Operator2' incorporates:
   *  Inport: '<Root>/reset'
   *  RelationalOperator: '<S240>/FixPt Relational Operator'
   *  UnitDelay: '<S240>/Delay Input1'
   */
  rtb_LogicalOperator2_o = (((int32_T)rtb_Compare_gt > (int32_T)
    INS_DWork.DelayInput1_DSTATE_o) || (INS_U.reset != 0));

  /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

  /* RelationalOperator: '<S246>/Compare' incorporates:
   *  Constant: '<S246>/Constant'
   */
  rtb_Compare_e = ((int32_T)rtb_Delay_h > (int32_T)INS_P.Constant_Value_m3);

  /* Switch: '<S243>/Switch4' incorporates:
   *  Delay: '<S243>/Delay1'
   *  Delay: '<S57>/Delay'
   *  Product: '<S243>/Divide'
   *  RelationalOperator: '<S245>/FixPt Relational Operator'
   *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion2Inport1'
   *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion5Inport1'
   *  Sum: '<S243>/Sum'
   *  UnitDelay: '<S245>/Delay Input1'
   */
  if ((int32_T)rtb_Compare_e > (int32_T)INS_DWork.DelayInput1_DSTATE_dp) {
    rtb_Gain6 = rtb_Scalefactor3 - INS_DWork.Delay_11_DSTATE /
      INS_B.OutportBufferFordz_dh;
  } else {
    rtb_Gain6 = INS_DWork.Delay1_DSTATE;
  }

  /* End of Switch: '<S243>/Switch4' */

  /* RelationalOperator: '<S248>/Compare' incorporates:
   *  Constant: '<S248>/Constant'
   */
  rtb_Delay_a = ((int32_T)rtb_Delay_a > (int32_T)INS_P.Constant_Value_pt);

  /* Switch: '<S244>/Switch4' incorporates:
   *  Delay: '<S244>/Delay'
   *  Delay: '<S244>/Delay1'
   *  Delay: '<S57>/Delay'
   *  Product: '<S244>/Divide'
   *  RelationalOperator: '<S247>/FixPt Relational Operator'
   *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion1Inport1'
   *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion3Inport1'
   *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion4Inport1'
   *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal ConversionInport1'
   *  Sum: '<S244>/Sum'
   *  Switch: '<S244>/Switch5'
   *  UnitDelay: '<S247>/Delay Input1'
   */
  if ((int32_T)rtb_Delay_a > (int32_T)INS_DWork.DelayInput1_DSTATE_m) {
    rtb_WGS84_pos_ref_j_idx_0 = rtb_Scalefactor1 - INS_DWork.Delay_9_DSTATE_m /
      INS_B.Add;
    rtb_Min = rtb_Scalefactor2 - INS_DWork.Delay_10_DSTATE_a / INS_B.Product4;
    rtb_WGS84_derivatives_ref_idx_0 = INS_B.Add;
    rtb_WGS84_derivatives_ref_idx_1 = INS_B.Product4;
  } else {
    rtb_WGS84_pos_ref_j_idx_0 = INS_DWork.Delay_DSTATE[0];
    rtb_Min = INS_DWork.Delay_DSTATE[1];
    rtb_WGS84_derivatives_ref_idx_0 = INS_DWork.Delay1_DSTATE_o[0];
    rtb_WGS84_derivatives_ref_idx_1 = INS_DWork.Delay1_DSTATE_o[1];
  }

  /* End of Switch: '<S244>/Switch4' */

  /* RelationalOperator: '<S253>/Compare' incorporates:
   *  Constant: '<S251>/Constant'
   *  Constant: '<S252>/Constant'
   *  Constant: '<S253>/Constant'
   *  Logic: '<S249>/Logical Operator'
   *  MinMax: '<S249>/Max'
   *  RelationalOperator: '<S251>/Compare'
   *  RelationalOperator: '<S252>/Compare'
   *  SignalConversion: '<S271>/TmpSignal ConversionAtSignal Conversion1Inport1'
   *  SignalConversion: '<S271>/TmpSignal ConversionAtSignal ConversionInport1'
   */
  rtb_Compare_nt = ((rtb_Compare_cio && ((rtb_Sum2_j > INS_P.Constant_Value_ab) ||
    (rtb_Sum4_k > INS_P.Constant_Value_mi))) > (int32_T)INS_P.Constant_Value_cz);

  /* RelationalOperator: '<S254>/Compare' incorporates:
   *  Constant: '<S254>/Constant'
   *  SignalConversion: '<S273>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_Delay_h = ((int32_T)rtb_LogicalOperator3 > (int32_T)
                 INS_P.Constant_Value_p2);

  /* Sum: '<S250>/Sum' incorporates:
   *  Constant: '<S256>/Constant'
   *  Constant: '<S257>/Constant'
   *  DataTypeConversion: '<S250>/Data Type Conversion1'
   *  Logic: '<S250>/Logical Operator'
   *  MinMax: '<S250>/Max'
   *  RelationalOperator: '<S256>/Compare'
   *  RelationalOperator: '<S257>/Compare'
   *  SignalConversion: '<S271>/TmpSignal ConversionAtSignal Conversion1Inport1'
   *  SignalConversion: '<S271>/TmpSignal ConversionAtSignal ConversionInport1'
   */
  rtb_Saturation1 = (rtb_Compare_cio && ((rtb_Sum4_k > INS_P.Constant_Value_ek) ||
    (rtb_Sum2_j > INS_P.Constant_Value_ao))) - rtb_Delay_h;

  /* Saturate: '<S250>/Saturation' */
  if (rtb_Saturation1 > INS_P.Saturation_UpperSat_c) {
    rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation_UpperSat_c;
  } else if (rtb_Saturation1 < INS_P.Saturation_LowerSat_p) {
    rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation_LowerSat_p;
  } else {
    rtb_DiscreteTimeIntegrator_pm = (real32_T)rtb_Saturation1;
  }

  /* End of Saturate: '<S250>/Saturation' */

  /* RelationalOperator: '<S258>/Compare' incorporates:
   *  Constant: '<S258>/Constant'
   */
  rtb_Compare_f5 = (rtb_DiscreteTimeIntegrator_pm > INS_P.Constant_Value_hv);

  /* Sum: '<S250>/Subtract' incorporates:
   *  Constant: '<S255>/Constant'
   *  DataTypeConversion: '<S250>/Data Type Conversion1'
   *  DataTypeConversion: '<S250>/Data Type Conversion2'
   *  RelationalOperator: '<S255>/Compare'
   *  SignalConversion: '<S270>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_DiscreteTimeIntegrator_pm = ((real32_T)((int32_T)
    rtb_FixPtRelationalOperator_if > (int32_T)INS_P.Constant_Value_hvm) -
    rtb_DiscreteTimeIntegrator_pm) - (real32_T)rtb_Delay_h;

  /* Saturate: '<S250>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_pm > INS_P.Saturation1_UpperSat_i) {
    rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation1_UpperSat_i;
  } else {
    if (rtb_DiscreteTimeIntegrator_pm < INS_P.Saturation1_LowerSat_jb) {
      rtb_DiscreteTimeIntegrator_pm = INS_P.Saturation1_LowerSat_jb;
    }
  }

  /* End of Saturate: '<S250>/Saturation1' */

  /* RelationalOperator: '<S260>/Compare' incorporates:
   *  Constant: '<S260>/Constant'
   */
  rtb_Compare_bo = (rtb_DiscreteTimeIntegrator_pm > INS_P.Constant_Value_iw);

  /* Update for UnitDelay: '<S238>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_j = rtb_UpperTest_cv;

  /* Update for UnitDelay: '<S240>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_o = rtb_Compare_gt;

  /* Update for Delay: '<S243>/Delay1' */
  INS_DWork.Delay1_DSTATE = rtb_Gain6;

  /* Update for UnitDelay: '<S245>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dp = rtb_Compare_e;

  /* Update for Delay: '<S244>/Delay' */
  INS_DWork.Delay_DSTATE[0] = rtb_WGS84_pos_ref_j_idx_0;

  /* Update for Delay: '<S244>/Delay1' */
  INS_DWork.Delay1_DSTATE_o[0] = rtb_WGS84_derivatives_ref_idx_0;

  /* Update for Delay: '<S244>/Delay' */
  INS_DWork.Delay_DSTATE[1] = rtb_Min;

  /* Update for Delay: '<S244>/Delay1' */
  INS_DWork.Delay1_DSTATE_o[1] = rtb_WGS84_derivatives_ref_idx_1;

  /* Update for UnitDelay: '<S247>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_m = rtb_Delay_a;

  /* End of Outputs for SubSystem: '<S57>/Process' */

  /* Outputs for Atomic SubSystem: '<S57>/CF' */
  /* Outputs for Enabled SubSystem: '<S222>/Reference_Height' incorporates:
   *  EnablePort: '<S225>/Enable'
   */
  if (rtb_Compare_f5) {
    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* DataTypeConversion: '<S225>/Data Type Conversion' incorporates:
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion5Inport1'
     *  Sum: '<S225>/Sum'
     */
    INS_B.h_0 = (real32_T)(rtb_Scalefactor3 - rtb_Gain6);

    /* DataTypeConversion: '<S225>/Data Type Conversion1' incorporates:
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion8Inport1'
     */
    INS_B.vel_D_0 = rtb_vel_D;

    /* End of Outputs for SubSystem: '<S57>/Process' */
  }

  /* End of Outputs for SubSystem: '<S222>/Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S223>/Reference_Height' incorporates:
   *  EnablePort: '<S226>/Enable'
   */
  /* Outputs for Atomic SubSystem: '<S57>/Process' */
  /* RelationalOperator: '<S259>/Compare' incorporates:
   *  Constant: '<S254>/Constant'
   *  Constant: '<S259>/Constant'
   *  DataTypeConversion: '<S250>/Data Type Conversion1'
   *  RelationalOperator: '<S254>/Compare'
   *  SignalConversion: '<S273>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  if (((int32_T)rtb_LogicalOperator3 > (int32_T)INS_P.Constant_Value_p2) >
      INS_P.Constant_Value_h4) {
    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/Sonar_Process' */
    /* DataTypeConversion: '<S226>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/Sonar'
     *  Product: '<S269>/Multiply'
     *  SignalConversion: '<S279>/TmpSignal ConversionAtSignal ConversionInport1'
     *  Trigonometry: '<S269>/Cos'
     *  Trigonometry: '<S269>/Cos1'
     */
    INS_B.h_0 = INS_U.Sonar.distance_m * arm_cos_f32
      (rtb_DiscreteTimeIntegrator_c__1) * arm_cos_f32
      (rtb_DiscreteTimeIntegrator_c__0);

    /* End of Outputs for SubSystem: '<S3>/Sonar_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* SignalConversion: '<S226>/OutportBuffer_InsertedFor_vel_D_mDs_at_inport_0' incorporates:
     *  Constant: '<S226>/Constant'
     */
    INS_B.vel_D_0 = INS_P.Constant_Value_km;
  }

  /* End of RelationalOperator: '<S259>/Compare' */
  /* End of Outputs for SubSystem: '<S57>/Process' */
  /* End of Outputs for SubSystem: '<S223>/Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S221>/Reference_Height' incorporates:
   *  EnablePort: '<S224>/Enable'
   */
  if (rtb_Compare_bo) {
    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* DataTypeConversion: '<S224>/Data Type Conversion' incorporates:
     *  SignalConversion: '<S266>/TmpSignal ConversionAtSignal Copy1Inport1'
     */
    INS_B.h_0 = rtb_Product1_g0;

    /* End of Outputs for SubSystem: '<S57>/Process' */

    /* SignalConversion: '<S224>/OutportBuffer_InsertedFor_vel_D_mDs_at_inport_0' incorporates:
     *  Constant: '<S224>/Constant'
     */
    INS_B.vel_D_0 = INS_P.Constant_Value_aa;
  }

  /* End of Outputs for SubSystem: '<S221>/Reference_Height' */

  /* Switch: '<S218>/Switch' incorporates:
   *  Constant: '<S220>/Constant'
   *  Delay: '<S218>/Delay'
   */
  if (rtb_LogicalOperator1_o) {
    rtb_ba_O_mDs2[0] = INS_B.h_0;
    rtb_ba_O_mDs2[1] = INS_B.vel_D_0;
    rtb_ba_O_mDs2[2] = INS_P.Constant_Value_eq;
  } else {
    rtb_ba_O_mDs2[0] = INS_DWork.Delay_DSTATE_b[0];
    rtb_ba_O_mDs2[1] = INS_DWork.Delay_DSTATE_b[1];
    rtb_ba_O_mDs2[2] = INS_DWork.Delay_DSTATE_b[2];
  }

  /* End of Switch: '<S218>/Switch' */

  /* Product: '<S219>/Multiply' incorporates:
   *  SignalConversion: '<S60>/TmpSignal ConversionAtSignal ConversionInport1'
   */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    /* Outputs for Atomic SubSystem: '<S56>/Integrate' */
    rtb_Product1_n[rtb_Saturation1] = rtb_VectorConcatenate_m[rtb_Saturation1 +
      6] * rtb_Switch3[2] + (rtb_VectorConcatenate_m[rtb_Saturation1 + 3] *
      rtb_Switch3[1] + rtb_VectorConcatenate_m[rtb_Saturation1] * rtb_Switch3[0]);

    /* End of Outputs for SubSystem: '<S56>/Integrate' */
  }

  /* Sum: '<S219>/Sum' incorporates:
   *  Constant: '<S219>/Constant'
   *  Constant: '<S219>/Constant1'
   *  Gain: '<S219>/Gain'
   *  Gain: '<S219>/Gain1'
   *  Product: '<S219>/Multiply'
   *  Sum: '<S219>/Add'
   */
  rtb_Multiply_j[0] = INS_P.Gain1_Gain_kw * rtb_ba_O_mDs2[1] *
    INS_P.Gain_Gain_mr + rtb_ba_O_mDs2[0];
  rtb_Multiply_j[1] = ((rtb_Product1_n[2] - rtb_ba_O_mDs2[2]) +
                       INS_P.Constant1_Value_f) * INS_P.Gain_Gain_mr +
    rtb_ba_O_mDs2[1];
  rtb_Multiply_j[2] = INS_P.Gain_Gain_mr * INS_P.Constant_Value_nn +
    rtb_ba_O_mDs2[2];

  /* Outputs for Enabled SubSystem: '<S198>/Baro_Correct' incorporates:
   *  EnablePort: '<S200>/Enable'
   */
  /* Switch: '<S198>/Switch' */
  if (rtb_Compare_bo) {
    /* Delay: '<S204>/x_delay' */
    if (rtb_LogicalOperator1_o && (INS_PrevZCSigState.x_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_a = 1U;
    }

    INS_PrevZCSigState.x_delay_Reset_ZCE = rtb_LogicalOperator1_o;
    if (INS_DWork.icLoad_a != 0) {
      for (i = 0; i < 5; i++) {
        INS_DWork.x_delay_DSTATE[i] = rtb_Multiply_j[0];
      }
    }

    /* RelationalOperator: '<S208>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S208>/Delay Input1'
     */
    rtb_Delay_h = (1 > (int32_T)INS_DWork.DelayInput1_DSTATE_f);

    /* Switch: '<S206>/Switch' incorporates:
     *  Memory: '<S206>/Memory'
     *  SignalConversion: '<S266>/TmpSignal ConversionAtSignal Copy1Inport1'
     *  Sum: '<S207>/Sum'
     */
    if (rtb_Delay_h) {
      /* Outputs for Atomic SubSystem: '<S57>/Process' */
      rtb_DiscreteTimeIntegrator_pm = rtb_Multiply_j[0] - rtb_Product1_g0;

      /* End of Outputs for SubSystem: '<S57>/Process' */
    } else {
      rtb_DiscreteTimeIntegrator_pm = INS_DWork.Memory_PreviousInput_j;
    }

    /* End of Switch: '<S206>/Switch' */

    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* Sum: '<S200>/Sum' incorporates:
     *  Delay: '<S204>/x_delay'
     *  SignalConversion: '<S266>/TmpSignal ConversionAtSignal Copy1Inport1'
     *  Sum: '<S203>/Sum1'
     */
    rtb_Product1_g0 = (rtb_Product1_g0 + rtb_DiscreteTimeIntegrator_pm) -
      INS_DWork.x_delay_DSTATE[0];

    /* End of Outputs for SubSystem: '<S57>/Process' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_Process' */
    /* Logic: '<S200>/Logical Operator' incorporates:
     *  Inport: '<Root>/Barometer'
     *  RelationalOperator: '<S201>/FixPt Relational Operator'
     *  SignalConversion: '<S274>/BusConversion_InsertedFor_Baro_Data_at_inport_0'
     *  UnitDelay: '<S201>/Delay Input1'
     */
    rtb_Delay_h = (rtb_Delay_h || (INS_U.Barometer.timestamp !=
      INS_DWork.DelayInput1_DSTATE_lg));

    /* End of Outputs for SubSystem: '<S3>/Baro_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* Switch: '<S202>/Switch' incorporates:
     *  Gain: '<S205>/Gain'
     *  Gain: '<S205>/Gain1'
     *  Gain: '<S205>/Gain2'
     *  Memory: '<S202>/Memory'
     */
    if (rtb_Delay_h) {
      rtb_ba_O_mDs2[0] = INS_P.Gain2_Gain_m * rtb_Product1_g0;
      rtb_ba_O_mDs2[1] = INS_P.Gain1_Gain_en * rtb_Product1_g0;
      rtb_ba_O_mDs2[2] = INS_P.Gain_Gain_n * rtb_Product1_g0;
    } else {
      rtb_ba_O_mDs2[0] = INS_DWork.Memory_PreviousInput_i[0];
      rtb_ba_O_mDs2[1] = INS_DWork.Memory_PreviousInput_i[1];
      rtb_ba_O_mDs2[2] = INS_DWork.Memory_PreviousInput_i[2];
    }

    /* End of Switch: '<S202>/Switch' */

    /* Sum: '<S200>/Sum1' incorporates:
     *  Gain: '<S202>/Gain'
     */
    INS_B.Sum1_p[0] = INS_P.Gain_Gain_p * rtb_ba_O_mDs2[0] + rtb_Multiply_j[0];
    INS_B.Sum1_p[1] = INS_P.Gain_Gain_p * rtb_ba_O_mDs2[1] + rtb_Multiply_j[1];
    INS_B.Sum1_p[2] = INS_P.Gain_Gain_p * rtb_ba_O_mDs2[2] + rtb_Multiply_j[2];

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_Process' */
    /* Update for UnitDelay: '<S201>/Delay Input1' incorporates:
     *  Inport: '<Root>/Barometer'
     *  SignalConversion: '<S274>/BusConversion_InsertedFor_Baro_Data_at_inport_0'
     */
    INS_DWork.DelayInput1_DSTATE_lg = INS_U.Barometer.timestamp;

    /* End of Outputs for SubSystem: '<S3>/Baro_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* Update for Delay: '<S204>/x_delay' */
    INS_DWork.icLoad_a = 0U;
    INS_DWork.x_delay_DSTATE[0] = INS_DWork.x_delay_DSTATE[1];
    INS_DWork.x_delay_DSTATE[1] = INS_DWork.x_delay_DSTATE[2];
    INS_DWork.x_delay_DSTATE[2] = INS_DWork.x_delay_DSTATE[3];
    INS_DWork.x_delay_DSTATE[3] = INS_DWork.x_delay_DSTATE[4];
    INS_DWork.x_delay_DSTATE[4] = rtb_Multiply_j[0];

    /* Update for UnitDelay: '<S208>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f = true;

    /* Update for Memory: '<S206>/Memory' */
    INS_DWork.Memory_PreviousInput_j = rtb_DiscreteTimeIntegrator_pm;

    /* Update for Memory: '<S202>/Memory' */
    INS_DWork.Memory_PreviousInput_i[0] = rtb_ba_O_mDs2[0];
    INS_DWork.Memory_PreviousInput_i[1] = rtb_ba_O_mDs2[1];
    INS_DWork.Memory_PreviousInput_i[2] = rtb_ba_O_mDs2[2];
    rtb_Multiply_j[0] = INS_B.Sum1_p[0];
    rtb_Multiply_j[1] = INS_B.Sum1_p[1];
  }

  /* End of Outputs for SubSystem: '<S198>/Baro_Correct' */
  rtb_Multiply_g1 = rtb_Multiply_j[2];
  if (rtb_Compare_bo) {
    rtb_Multiply_g1 = INS_B.Sum1_p[2];
  }

  /* End of Switch: '<S198>/Switch' */

  /* Outputs for Enabled SubSystem: '<S199>/GPS_Correct' incorporates:
   *  EnablePort: '<S209>/Enable'
   */
  /* Switch: '<S199>/Switch' */
  if (rtb_Compare_f5) {
    /* Delay: '<S213>/h_delay' */
    if (rtb_LogicalOperator1_o && (INS_PrevZCSigState.h_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad = 1U;
    }

    INS_PrevZCSigState.h_delay_Reset_ZCE = rtb_LogicalOperator1_o;
    if (INS_DWork.icLoad != 0) {
      for (i = 0; i < 75; i++) {
        INS_DWork.h_delay_DSTATE[i] = rtb_Multiply_j[0];
      }
    }

    /* Delay: '<S213>/vd_delay' */
    if (rtb_LogicalOperator1_o && (INS_PrevZCSigState.vd_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_f = 1U;
    }

    INS_PrevZCSigState.vd_delay_Reset_ZCE = rtb_LogicalOperator1_o;
    if (INS_DWork.icLoad_f != 0) {
      for (i = 0; i < 50; i++) {
        INS_DWork.vd_delay_DSTATE[i] = rtb_Multiply_j[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* DataTypeConversion: '<S212>/Data Type Conversion' incorporates:
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion5Inport1'
     *  Sum: '<S212>/Sum'
     */
    rtb_Product1_g0 = (real32_T)(rtb_Scalefactor3 - rtb_Gain6);

    /* End of Outputs for SubSystem: '<S57>/Process' */

    /* RelationalOperator: '<S217>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S217>/Delay Input1'
     */
    rtb_Delay_h = (1 > (int32_T)INS_DWork.DelayInput1_DSTATE_ib);

    /* Switch: '<S215>/Switch' incorporates:
     *  DataTypeConversion: '<S212>/Data Type Conversion'
     *  Memory: '<S215>/Memory'
     *  Sum: '<S216>/Sum'
     */
    if (rtb_Delay_h) {
      rtb_DiscreteTimeIntegrator_pm = rtb_Multiply_j[0] - rtb_Product1_g0;
    } else {
      rtb_DiscreteTimeIntegrator_pm = INS_DWork.Memory_PreviousInput;
    }

    /* End of Switch: '<S215>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_Process' */
    /* Logic: '<S209>/Logical Operator' incorporates:
     *  Inport: '<Root>/Barometer'
     *  RelationalOperator: '<S210>/FixPt Relational Operator'
     *  SignalConversion: '<S274>/BusConversion_InsertedFor_Baro_Data_at_inport_0'
     *  UnitDelay: '<S210>/Delay Input1'
     */
    rtb_Delay_h = (rtb_Delay_h || (INS_U.Barometer.timestamp !=
      INS_DWork.DelayInput1_DSTATE_d));

    /* End of Outputs for SubSystem: '<S3>/Baro_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* Switch: '<S211>/Switch' incorporates:
     *  DataTypeConversion: '<S212>/Data Type Conversion'
     *  Delay: '<S213>/h_delay'
     *  Gain: '<S214>/Gain'
     *  Gain: '<S214>/Gain1'
     *  Gain: '<S214>/Gain2'
     *  Memory: '<S211>/Memory'
     *  Sum: '<S209>/Sum'
     *  Sum: '<S212>/Sum1'
     */
    if (rtb_Delay_h) {
      /* Outputs for Atomic SubSystem: '<S57>/Process' */
      /* Sum: '<S209>/Sum' incorporates:
       *  Delay: '<S213>/vd_delay'
       *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion8Inport1'
       */
      rtb_Square_l_idx_1 = rtb_vel_D - INS_DWork.vd_delay_DSTATE[0U];

      /* End of Outputs for SubSystem: '<S57>/Process' */
      rtb_ba_O_mDs2[0] = ((rtb_Product1_g0 + rtb_DiscreteTimeIntegrator_pm) -
                          INS_DWork.h_delay_DSTATE[0U]) * INS_P.Gain1_Gain_ml;
      rtb_ba_O_mDs2[1] = INS_P.Gain_Gain_c * rtb_Square_l_idx_1;
      rtb_ba_O_mDs2[2] = INS_P.Gain2_Gain_k * rtb_Square_l_idx_1;
    } else {
      rtb_ba_O_mDs2[0] = INS_DWork.Memory_PreviousInput_e[0];
      rtb_ba_O_mDs2[1] = INS_DWork.Memory_PreviousInput_e[1];
      rtb_ba_O_mDs2[2] = INS_DWork.Memory_PreviousInput_e[2];
    }

    /* End of Switch: '<S211>/Switch' */

    /* Sum: '<S209>/Sum1' incorporates:
     *  Gain: '<S211>/Gain3'
     */
    INS_B.Sum1[0] = INS_P.Gain3_Gain_kn * rtb_ba_O_mDs2[0] + rtb_Multiply_j[0];
    INS_B.Sum1[1] = INS_P.Gain3_Gain_kn * rtb_ba_O_mDs2[1] + rtb_Multiply_j[1];
    INS_B.Sum1[2] = INS_P.Gain3_Gain_kn * rtb_ba_O_mDs2[2] + rtb_Multiply_g1;

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_Process' */
    /* Update for UnitDelay: '<S210>/Delay Input1' incorporates:
     *  Inport: '<Root>/Barometer'
     *  SignalConversion: '<S274>/BusConversion_InsertedFor_Baro_Data_at_inport_0'
     */
    INS_DWork.DelayInput1_DSTATE_d = INS_U.Barometer.timestamp;

    /* End of Outputs for SubSystem: '<S3>/Baro_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* Update for Delay: '<S213>/h_delay' */
    INS_DWork.icLoad = 0U;
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 74; rtb_Saturation1++) {
      INS_DWork.h_delay_DSTATE[rtb_Saturation1] =
        INS_DWork.h_delay_DSTATE[rtb_Saturation1 + 1];
    }

    INS_DWork.h_delay_DSTATE[74] = rtb_Multiply_j[0];

    /* End of Update for Delay: '<S213>/h_delay' */

    /* Update for Delay: '<S213>/vd_delay' */
    INS_DWork.icLoad_f = 0U;
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 49; rtb_Saturation1++) {
      INS_DWork.vd_delay_DSTATE[rtb_Saturation1] =
        INS_DWork.vd_delay_DSTATE[rtb_Saturation1 + 1];
    }

    INS_DWork.vd_delay_DSTATE[49] = rtb_Multiply_j[1];

    /* End of Update for Delay: '<S213>/vd_delay' */

    /* Update for UnitDelay: '<S217>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ib = true;

    /* Update for Memory: '<S215>/Memory' */
    INS_DWork.Memory_PreviousInput = rtb_DiscreteTimeIntegrator_pm;

    /* Update for Memory: '<S211>/Memory' */
    INS_DWork.Memory_PreviousInput_e[0] = rtb_ba_O_mDs2[0];
    INS_DWork.Memory_PreviousInput_e[1] = rtb_ba_O_mDs2[1];
    INS_DWork.Memory_PreviousInput_e[2] = rtb_ba_O_mDs2[2];
    rtb_Multiply_j[0] = INS_B.Sum1[0];
    rtb_Multiply_j[1] = INS_B.Sum1[1];
    rtb_Multiply_g1 = INS_B.Sum1[2];
  }

  /* End of Switch: '<S199>/Switch' */
  /* End of Outputs for SubSystem: '<S199>/GPS_Correct' */

  /* Outputs for Atomic SubSystem: '<S57>/Process' */
  /* Switch: '<S172>/Switch' incorporates:
   *  SignalConversion: '<S273>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  if (rtb_LogicalOperator3) {
    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  Constant: '<S166>/Constant'
     *  Outport: '<Root>/INS_Out'
     *  Sum: '<S172>/Sum'
     */
    INS_Y.INS_Out.h_AGL = rtb_Multiply_j[0] - INS_P.Constant_Value_aq;
  } else {
    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  Constant: '<S172>/Constant'
     *  Outport: '<Root>/INS_Out'
     */
    INS_Y.INS_Out.h_AGL = INS_P.Constant_Value_d;
  }

  /* End of Switch: '<S172>/Switch' */
  /* End of Outputs for SubSystem: '<S57>/Process' */

  /* Outputs for Enabled SubSystem: '<S192>/GPS_Vel_Init' incorporates:
   *  EnablePort: '<S194>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S191>/GPS_Pos_Init' incorporates:
   *  EnablePort: '<S193>/Enable'
   */
  if (rtb_Compare_cio) {
    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* DataTypeConversion: '<S193>/Data Type Conversion' incorporates:
     *  Product: '<S193>/Multiply'
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion3Inport1'
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion4Inport1'
     *  Sum: '<S193>/Sum'
     */
    INS_B.DataTypeConversion[0] = (real32_T)((rtb_Scalefactor1 -
      rtb_WGS84_pos_ref_j_idx_0) * rtb_WGS84_derivatives_ref_idx_0);
    INS_B.DataTypeConversion[1] = (real32_T)((rtb_Scalefactor2 - rtb_Min) *
      rtb_WGS84_derivatives_ref_idx_1);

    /* Reshape: '<S194>/Reshape' incorporates:
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion6Inport1'
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion7Inport1'
     */
    rtb_vel_NE_0_idx_0 = rtb_vel_N;
    rtb_vel_NE_0_idx_1 = rtb_vel_E;

    /* End of Outputs for SubSystem: '<S57>/Process' */
  }

  /* End of Outputs for SubSystem: '<S191>/GPS_Pos_Init' */
  /* End of Outputs for SubSystem: '<S192>/GPS_Vel_Init' */

  /* Outputs for Enabled SubSystem: '<S192>/OptFlow_Vel_Init' incorporates:
   *  EnablePort: '<S195>/Enable'
   */
  /* Logic: '<S192>/Logical Operator' */
  if (!rtb_Compare_cio) {
    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* Reshape: '<S195>/Reshape' incorporates:
     *  SignalConversion: '<S268>/TmpSignal ConversionAtSignal Copy1Inport1'
     *  SignalConversion: '<S268>/TmpSignal ConversionAtSignal Copy2Inport1'
     */
    rtb_vel_NE_0_idx_0 = rtb_uT[0];
    rtb_vel_NE_0_idx_1 = rtb_uT[1];

    /* End of Outputs for SubSystem: '<S57>/Process' */
  }

  /* End of Logic: '<S192>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S192>/OptFlow_Vel_Init' */

  /* Switch: '<S188>/Switch' incorporates:
   *  Constant: '<S190>/Constant'
   *  Delay: '<S188>/Delay'
   */
  if (rtb_LogicalOperator2_o) {
    rtb_Switch_er[0] = INS_B.DataTypeConversion[0];
    rtb_Switch_er[2] = rtb_vel_NE_0_idx_0;
    rtb_Switch_er[4] = INS_P.Constant_Value_b[0];
    rtb_Switch_er[1] = INS_B.DataTypeConversion[1];
    rtb_Switch_er[3] = rtb_vel_NE_0_idx_1;
    rtb_Switch_er[5] = INS_P.Constant_Value_b[1];
  } else {
    rtb_Switch_er[0] = INS_DWork.Delay_DSTATE_l[0];
    rtb_Switch_er[2] = INS_DWork.Delay_DSTATE_l[2];
    rtb_Switch_er[4] = INS_DWork.Delay_DSTATE_l[4];
    rtb_Switch_er[1] = INS_DWork.Delay_DSTATE_l[1];
    rtb_Switch_er[3] = INS_DWork.Delay_DSTATE_l[3];
    rtb_Switch_er[5] = INS_DWork.Delay_DSTATE_l[5];
  }

  /* End of Switch: '<S188>/Switch' */

  /* Product: '<S189>/Multiply' incorporates:
   *  SignalConversion: '<S60>/TmpSignal ConversionAtSignal ConversionInport1'
   */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    /* Outputs for Atomic SubSystem: '<S56>/Integrate' */
    rtb_Product1_n[rtb_Saturation1] = rtb_VectorConcatenate_m[rtb_Saturation1 +
      6] * rtb_Switch3[2] + (rtb_VectorConcatenate_m[rtb_Saturation1 + 3] *
      rtb_Switch3[1] + rtb_VectorConcatenate_m[rtb_Saturation1] * rtb_Switch3[0]);

    /* End of Outputs for SubSystem: '<S56>/Integrate' */
  }

  /* Gain: '<S189>/Gain' incorporates:
   *  Constant: '<S189>/Constant'
   *  Product: '<S189>/Multiply'
   *  Sum: '<S189>/Add'
   */
  tmp[0] = INS_P.Gain_Gain_ic * rtb_Switch_er[2];
  tmp[2] = (rtb_Product1_n[0] - rtb_Switch_er[4]) * INS_P.Gain_Gain_ic;
  tmp[4] = INS_P.Gain_Gain_ic * INS_P.Constant_Value_l[0];
  tmp[1] = INS_P.Gain_Gain_ic * rtb_Switch_er[3];
  tmp[3] = (rtb_Product1_n[1] - rtb_Switch_er[5]) * INS_P.Gain_Gain_ic;
  tmp[5] = INS_P.Gain_Gain_ic * INS_P.Constant_Value_l[1];

  /* Sum: '<S189>/Sum' */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 6; rtb_Saturation1++) {
    rtb_Sum_g0[rtb_Saturation1] = rtb_Switch_er[rtb_Saturation1] +
      tmp[rtb_Saturation1];
  }

  /* End of Sum: '<S189>/Sum' */

  /* Outputs for Enabled SubSystem: '<S176>/GPS_Correct' incorporates:
   *  EnablePort: '<S178>/Enable'
   */
  if (rtb_Compare_nt) {
    /* Delay: '<S182>/x_delay' */
    if (rtb_LogicalOperator2_o && (INS_PrevZCSigState.x_delay_Reset_ZCE_b !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_o = 1U;
    }

    INS_PrevZCSigState.x_delay_Reset_ZCE_b = rtb_LogicalOperator2_o;
    if (INS_DWork.icLoad_o != 0) {
      for (i = 0; i < 75; i++) {
        INS_DWork.x_delay_DSTATE_k[i] = rtb_Sum_g0[0];
      }
    }

    /* Delay: '<S182>/x_delay1' */
    if (rtb_LogicalOperator2_o && (INS_PrevZCSigState.x_delay1_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_i = 1U;
    }

    INS_PrevZCSigState.x_delay1_Reset_ZCE = rtb_LogicalOperator2_o;
    if (INS_DWork.icLoad_i != 0) {
      for (i = 0; i < 75; i++) {
        INS_DWork.x_delay1_DSTATE[i] = rtb_Sum_g0[1];
      }
    }

    /* Delay: '<S182>/vn_delay' */
    if (rtb_LogicalOperator2_o && (INS_PrevZCSigState.vn_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_m = 1U;
    }

    INS_PrevZCSigState.vn_delay_Reset_ZCE = rtb_LogicalOperator2_o;
    if (INS_DWork.icLoad_m != 0) {
      for (i = 0; i < 50; i++) {
        INS_DWork.vn_delay_DSTATE[i] = rtb_Sum_g0[2];
      }
    }

    /* Delay: '<S182>/vn_delay1' */
    if (rtb_LogicalOperator2_o && (INS_PrevZCSigState.vn_delay1_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_j = 1U;
    }

    INS_PrevZCSigState.vn_delay1_Reset_ZCE = rtb_LogicalOperator2_o;
    if (INS_DWork.icLoad_j != 0) {
      for (i = 0; i < 50; i++) {
        INS_DWork.vn_delay1_DSTATE[i] = rtb_Sum_g0[3];
      }
    }

    /* Outputs for Atomic SubSystem: '<S57>/Process' */
    /* DataTypeConversion: '<S181>/Data Type Conversion' incorporates:
     *  Product: '<S181>/Multiply'
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion3Inport1'
     *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion4Inport1'
     *  Sum: '<S181>/Sum'
     */
    rtb_vel_NE_0_idx_0 = (real32_T)((rtb_Scalefactor1 -
      rtb_WGS84_pos_ref_j_idx_0) * rtb_WGS84_derivatives_ref_idx_0);
    rtb_vel_NE_0_idx_1 = (real32_T)((rtb_Scalefactor2 - rtb_Min) *
      rtb_WGS84_derivatives_ref_idx_1);

    /* End of Outputs for SubSystem: '<S57>/Process' */

    /* RelationalOperator: '<S187>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S187>/Delay Input1'
     */
    rtb_Delay_h = (1 > (int32_T)INS_DWork.DelayInput1_DSTATE_gn);

    /* Switch: '<S185>/Switch' incorporates:
     *  DataTypeConversion: '<S181>/Data Type Conversion'
     *  Memory: '<S185>/Memory'
     *  Sum: '<S186>/Sum'
     */
    if (rtb_Delay_h) {
      rtb_Square_l_idx_0 = rtb_Sum_g0[0] - rtb_vel_NE_0_idx_0;
      rtb_Square_l_idx_1 = rtb_Sum_g0[1] - rtb_vel_NE_0_idx_1;
    } else {
      rtb_Square_l_idx_0 = INS_DWork.Memory_PreviousInput_d[0];
      rtb_Square_l_idx_1 = INS_DWork.Memory_PreviousInput_d[1];
    }

    /* End of Switch: '<S185>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/GPS_Process' */
    /* Logic: '<S178>/Logical Operator' incorporates:
     *  Inport: '<Root>/GPS_uBlox'
     *  RelationalOperator: '<S179>/FixPt Relational Operator'
     *  SignalConversion: '<S275>/BusConversion_InsertedFor_GPS_Data_at_inport_0'
     *  UnitDelay: '<S179>/Delay Input1'
     */
    rtb_Delay_h = (rtb_Delay_h || (INS_U.GPS_uBlox.timestamp !=
      INS_DWork.DelayInput1_DSTATE_d0));

    /* End of Outputs for SubSystem: '<S3>/GPS_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* Switch: '<S180>/Switch' incorporates:
     *  DataTypeConversion: '<S181>/Data Type Conversion'
     *  Delay: '<S182>/x_delay'
     *  Delay: '<S182>/x_delay1'
     *  Gain: '<S183>/Gain'
     *  Gain: '<S183>/Gain1'
     *  Gain: '<S183>/Gain2'
     *  Memory: '<S180>/Memory'
     *  Sum: '<S178>/Sum'
     *  Sum: '<S184>/Sum1'
     */
    if (rtb_Delay_h) {
      /* Outputs for Atomic SubSystem: '<S57>/Process' */
      /* Sum: '<S178>/Sum' incorporates:
       *  Delay: '<S182>/vn_delay'
       *  Delay: '<S182>/vn_delay1'
       *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion6Inport1'
       *  SignalConversion: '<S267>/TmpSignal ConversionAtSignal Conversion7Inport1'
       */
      rtb_delay_acc_O_idx_2 = rtb_vel_N - INS_DWork.vn_delay_DSTATE[0U];
      rtb_DiscreteTimeIntegrator_pm = rtb_vel_E - INS_DWork.vn_delay1_DSTATE[0U];

      /* End of Outputs for SubSystem: '<S57>/Process' */
      rtb_Switch_er[0] = ((rtb_vel_NE_0_idx_0 + rtb_Square_l_idx_0) -
                          INS_DWork.x_delay_DSTATE_k[0U]) * INS_P.Gain1_Gain_e;
      rtb_Switch_er[2] = INS_P.Gain_Gain_o0 * rtb_delay_acc_O_idx_2;
      rtb_Switch_er[4] = INS_P.Gain2_Gain_g * rtb_delay_acc_O_idx_2;
      rtb_Switch_er[1] = ((rtb_vel_NE_0_idx_1 + rtb_Square_l_idx_1) -
                          INS_DWork.x_delay1_DSTATE[0U]) * INS_P.Gain1_Gain_e;
      rtb_Switch_er[3] = INS_P.Gain_Gain_o0 * rtb_DiscreteTimeIntegrator_pm;
      rtb_Switch_er[5] = INS_P.Gain2_Gain_g * rtb_DiscreteTimeIntegrator_pm;
    } else {
      for (i = 0; i < 6; i++) {
        rtb_Switch_er[i] = INS_DWork.Memory_PreviousInput_h[i];
      }
    }

    /* End of Switch: '<S180>/Switch' */

    /* Sum: '<S178>/Sum1' incorporates:
     *  Gain: '<S180>/Gain3'
     */
    for (i = 0; i < 6; i++) {
      INS_B.Sum1_o[i] = INS_P.Gain3_Gain_o * rtb_Switch_er[i] + rtb_Sum_g0[i];
    }

    /* End of Sum: '<S178>/Sum1' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* Outputs for Atomic SubSystem: '<S3>/GPS_Process' */
    /* Update for UnitDelay: '<S179>/Delay Input1' incorporates:
     *  Inport: '<Root>/GPS_uBlox'
     *  SignalConversion: '<S275>/BusConversion_InsertedFor_GPS_Data_at_inport_0'
     */
    INS_DWork.DelayInput1_DSTATE_d0 = INS_U.GPS_uBlox.timestamp;

    /* End of Outputs for SubSystem: '<S3>/GPS_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_Process' */

    /* Update for Delay: '<S182>/x_delay' */
    INS_DWork.icLoad_o = 0U;
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 74; rtb_Saturation1++) {
      INS_DWork.x_delay_DSTATE_k[rtb_Saturation1] =
        INS_DWork.x_delay_DSTATE_k[rtb_Saturation1 + 1];

      /* Update for Delay: '<S182>/x_delay1' */
      INS_DWork.x_delay1_DSTATE[rtb_Saturation1] =
        INS_DWork.x_delay1_DSTATE[rtb_Saturation1 + 1];
    }

    INS_DWork.x_delay_DSTATE_k[74] = rtb_Sum_g0[0];

    /* End of Update for Delay: '<S182>/x_delay' */

    /* Update for Delay: '<S182>/x_delay1' */
    INS_DWork.icLoad_i = 0U;
    INS_DWork.x_delay1_DSTATE[74] = rtb_Sum_g0[1];

    /* Update for Delay: '<S182>/vn_delay' */
    INS_DWork.icLoad_m = 0U;
    for (rtb_Saturation1 = 0; rtb_Saturation1 < 49; rtb_Saturation1++) {
      INS_DWork.vn_delay_DSTATE[rtb_Saturation1] =
        INS_DWork.vn_delay_DSTATE[rtb_Saturation1 + 1];

      /* Update for Delay: '<S182>/vn_delay1' */
      INS_DWork.vn_delay1_DSTATE[rtb_Saturation1] =
        INS_DWork.vn_delay1_DSTATE[rtb_Saturation1 + 1];
    }

    INS_DWork.vn_delay_DSTATE[49] = rtb_Sum_g0[2];

    /* End of Update for Delay: '<S182>/vn_delay' */

    /* Update for Delay: '<S182>/vn_delay1' */
    INS_DWork.icLoad_j = 0U;
    INS_DWork.vn_delay1_DSTATE[49] = rtb_Sum_g0[3];

    /* Update for UnitDelay: '<S187>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_gn = true;

    /* Update for Memory: '<S185>/Memory' */
    INS_DWork.Memory_PreviousInput_d[0] = rtb_Square_l_idx_0;
    INS_DWork.Memory_PreviousInput_d[1] = rtb_Square_l_idx_1;

    /* Update for Memory: '<S180>/Memory' */
    for (i = 0; i < 6; i++) {
      INS_DWork.Memory_PreviousInput_h[i] = rtb_Switch_er[i];
    }

    /* End of Update for Memory: '<S180>/Memory' */
  }

  /* End of Outputs for SubSystem: '<S176>/GPS_Correct' */

  /* Switch: '<S176>/Switch' */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 6; rtb_Saturation1++) {
    rtb_vel_NE_0_idx_0 = rtb_Sum_g0[rtb_Saturation1];
    if (rtb_Compare_nt) {
      rtb_vel_NE_0_idx_0 = INS_B.Sum1_o[rtb_Saturation1];
    }

    rtb_Sum_g0[rtb_Saturation1] = rtb_vel_NE_0_idx_0;
  }

  /* End of Switch: '<S176>/Switch' */

  /* Abs: '<S173>/Abs' incorporates:
   *  Abs: '<S175>/Abs'
   */
  rtb_Scalefactor1 = fabs(rtb_WGS84_derivatives_ref_idx_0);
  rtb_Scalefactor2 = fabs(rtb_WGS84_derivatives_ref_idx_1);

  /* Switch: '<S173>/Switch' incorporates:
   *  Abs: '<S173>/Abs'
   *  Constant: '<S174>/Constant'
   *  MinMax: '<S173>/Min'
   *  RelationalOperator: '<S174>/Compare'
   *  Signum: '<S175>/Sign'
   */
  if (fmin(rtb_Scalefactor1, rtb_Scalefactor2) < INS_P.CompareToConstant_const)
  {
    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  Constant: '<S173>/Constant'
     *  Outport: '<Root>/INS_Out'
     */
    INS_Y.INS_Out.lat = INS_P.Constant_Value_i[0];
    INS_Y.INS_Out.lon = INS_P.Constant_Value_i[1];
    INS_Y.INS_Out.alt = INS_P.Constant_Value_i[2];
  } else {
    if (rtb_WGS84_derivatives_ref_idx_0 < 0.0) {
      /* Signum: '<S175>/Sign' */
      rtb_WGS84_derivatives_ref_idx_0 = -1.0;
    } else {
      if (rtb_WGS84_derivatives_ref_idx_0 > 0.0) {
        /* Signum: '<S175>/Sign' */
        rtb_WGS84_derivatives_ref_idx_0 = 1.0;
      }
    }

    /* Switch: '<S175>/Switch' incorporates:
     *  Constant: '<S175>/Constant'
     *  Signum: '<S175>/Sign'
     */
    if (rtb_WGS84_derivatives_ref_idx_0 == 0.0) {
      rtb_WGS84_derivatives_ref_idx_0 = INS_P.Constant_Value;
    }

    /* Saturate: '<S175>/Saturation' */
    if (rtb_Scalefactor1 > INS_P.Saturation_UpperSat) {
      rtb_Scalefactor1 = INS_P.Saturation_UpperSat;
    } else {
      if (rtb_Scalefactor1 < INS_P.Zero_Value_Exclusion_thr) {
        rtb_Scalefactor1 = INS_P.Zero_Value_Exclusion_thr;
      }
    }

    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  DataTypeConversion: '<S173>/Data Type Conversion'
     *  Outport: '<Root>/INS_Out'
     *  Product: '<S173>/Divide'
     *  Product: '<S175>/Product'
     *  Sum: '<S173>/Sum'
     */
    INS_Y.INS_Out.lat = rtb_Sum_g0[0] / (rtb_Scalefactor1 *
      rtb_WGS84_derivatives_ref_idx_0) + rtb_WGS84_pos_ref_j_idx_0;

    /* Signum: '<S175>/Sign' */
    if (rtb_WGS84_derivatives_ref_idx_1 < 0.0) {
      rtb_WGS84_derivatives_ref_idx_0 = -1.0;
    } else if (rtb_WGS84_derivatives_ref_idx_1 > 0.0) {
      rtb_WGS84_derivatives_ref_idx_0 = 1.0;
    } else {
      rtb_WGS84_derivatives_ref_idx_0 = rtb_WGS84_derivatives_ref_idx_1;
    }

    /* Switch: '<S175>/Switch' incorporates:
     *  Constant: '<S175>/Constant'
     */
    if (rtb_WGS84_derivatives_ref_idx_0 == 0.0) {
      rtb_WGS84_derivatives_ref_idx_0 = INS_P.Constant_Value;
    }

    /* Saturate: '<S175>/Saturation' */
    if (rtb_Scalefactor2 > INS_P.Saturation_UpperSat) {
      rtb_Scalefactor2 = INS_P.Saturation_UpperSat;
    } else {
      if (rtb_Scalefactor2 < INS_P.Zero_Value_Exclusion_thr) {
        rtb_Scalefactor2 = INS_P.Zero_Value_Exclusion_thr;
      }
    }

    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  DataTypeConversion: '<S173>/Data Type Conversion'
     *  DataTypeConversion: '<S173>/Data Type Conversion1'
     *  Outport: '<Root>/INS_Out'
     *  Product: '<S173>/Divide'
     *  Product: '<S175>/Product'
     *  Sum: '<S173>/Sum'
     */
    INS_Y.INS_Out.lon = rtb_Sum_g0[1] / (rtb_Scalefactor2 *
      rtb_WGS84_derivatives_ref_idx_0) + rtb_Min;
    INS_Y.INS_Out.alt = rtb_Multiply_j[0] + rtb_Gain6;
  }

  /* End of Switch: '<S173>/Switch' */

  /* Update for Delay: '<S218>/Delay' */
  INS_DWork.Delay_DSTATE_b[0] = rtb_Multiply_j[0];
  INS_DWork.Delay_DSTATE_b[1] = rtb_Multiply_j[1];
  INS_DWork.Delay_DSTATE_b[2] = rtb_Multiply_g1;

  /* Update for Delay: '<S188>/Delay' */
  for (i = 0; i < 6; i++) {
    INS_DWork.Delay_DSTATE_l[i] = rtb_Sum_g0[i];
  }

  /* End of Update for Delay: '<S188>/Delay' */
  /* End of Outputs for SubSystem: '<S57>/CF' */

  /* Update for Delay: '<S56>/Delay' */
  for (i = 0; i < 9; i++) {
    INS_DWork.Delay_8_DSTATE_l[i] = rtb_VectorConcatenate_m[i];
    INS_DWork.Delay_9_DSTATE[i] = rtb_Transpose2[i];
  }

  INS_DWork.Delay_10_DSTATE[0] = rtb_VectorConcatenate_idx_0;
  INS_DWork.Delay_10_DSTATE[1] = rtb_VectorConcatenate_idx_1;
  INS_DWork.Delay_10_DSTATE[2] = rtb_delay_acc_O_idx_1;

  /* End of Update for Delay: '<S56>/Delay' */

  /* Update for Delay: '<S57>/Delay' */
  INS_DWork.Delay_9_DSTATE_m = rtb_Sum_g0[0];
  INS_DWork.Delay_10_DSTATE_a = rtb_Sum_g0[1];
  INS_DWork.Delay_11_DSTATE = rtb_Multiply_j[0];

  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Assignment' */
  /* Outputs for Atomic SubSystem: '<S1>/Counter' */
  /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
   *  Outport: '<Root>/INS_Out'
   *  UnitDelay: '<S4>/Output'
   */
  INS_Y.INS_Out.timestamp = INS_DWork.Output_DSTATE;

  /* Update for UnitDelay: '<S4>/Output' incorporates:
   *  Constant: '<S4>/Constant'
   *  Sum: '<S4>/Add'
   */
  INS_DWork.Output_DSTATE += INS_EXPORT.period;

  /* End of Outputs for SubSystem: '<S1>/Counter' */

  /* Outputs for Atomic SubSystem: '<S1>/Rotation_Output' */
  /* Sum: '<S5>/Sum' incorporates:
   *  Product: '<S5>/Multiply'
   *  SignalConversion: '<S5>/TmpSignal ConversionAtMultiplyInport2'
   *  SignalConversion: '<S60>/TmpSignal ConversionAtSignal ConversionInport1'
   */
  for (rtb_Saturation1 = 0; rtb_Saturation1 < 3; rtb_Saturation1++) {
    /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
    /* Outputs for Atomic SubSystem: '<S56>/Integrate' */
    rtb_ba_O_mDs2[rtb_Saturation1] = rtb_Switch3[rtb_Saturation1] -
      ((rtb_Transpose2[rtb_Saturation1 + 3] * rtb_Sum_g0[5] +
        rtb_Transpose2[rtb_Saturation1] * rtb_Sum_g0[4]) +
       rtb_Transpose2[rtb_Saturation1 + 6] * rtb_Multiply_g1);

    /* End of Outputs for SubSystem: '<S56>/Integrate' */
    /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  }

  /* End of Sum: '<S5>/Sum' */
  /* End of Outputs for SubSystem: '<S1>/Rotation_Output' */

  /* Outputs for Atomic SubSystem: '<S1>/Status_Output' */
  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_Delay_h = (rtb_Sum4_k > INS_P.CompareToConstant1_const);

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  if (rtb_Delay_h || (INS_DWork.DiscreteTimeIntegrator_PrevRe_n != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_b = INS_P.DiscreteTimeIntegrator_IC;
  }

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  rtb_Compare_cio = ((int32_T)rtb_Compare_fz > (int32_T)
                     INS_P.CompareToConstant1_const_j);

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  if (rtb_Compare_cio || (INS_DWork.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_i;
  }

  /* MinMax: '<S9>/Max' */
  rtb_DiscreteTimeIntegrator_pm = fmaxf(rtb_Sum2_j, rtb_Saturation_ad);

  /* RelationalOperator: '<S50>/Compare' incorporates:
   *  Constant: '<S50>/Constant'
   */
  rtb_UpperTest_cv = (rtb_DiscreteTimeIntegrator_pm >
                      INS_P.CompareToConstant1_const_g);

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  if (rtb_UpperTest_cv || (INS_DWork.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 =
      INS_P.DiscreteTimeIntegrator_IC_o;
  }

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  rtb_LogicalOperator1_o = (rtb_Sum2_j > INS_P.CompareToConstant1_const_e);

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator1_o || (INS_DWork.DiscreteTimeIntegrator_PrevRe_h != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_IC_l;
  }

  /* MinMax: '<S9>/Max1' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  rtb_vel_N = fmaxf(rtb_Sum4_k, rtb_Delay_d);

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   */
  rtb_Compare_gt = (rtb_vel_N > INS_P.CompareToConstant1_const_ei);

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if (rtb_Compare_gt || (INS_DWork.DiscreteTimeIntegrator_PrevRe_a != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_j;
  }

  /* MinMax: '<S9>/Max2' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   */
  rtb_vel_E = fmaxf(fmaxf(rtb_Sum4_k, rtb_FixPtRelationalOperator_if),
                    rtb_LogicalOperator3);

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   */
  rtb_LogicalOperator2_o = (rtb_vel_E > INS_P.CompareToConstant1_const_ec);

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator2_o || (INS_DWork.DiscreteTimeIntegrator_PrevRe_o != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kg =
      INS_P.DiscreteTimeIntegrator_IC_ig;
  }

  /* RelationalOperator: '<S45>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   */
  rtb_Compare_e = ((real32_T)rtb_LogicalOperator3 >
                   INS_P.CompareToConstant1_const_em);

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  if (rtb_Compare_e || (INS_DWork.DiscreteTimeIntegrator_PrevR_ar != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_a =
      INS_P.DiscreteTimeIntegrator_IC_e;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/Integrate' */
  /* Gain: '<S8>/Gain10' incorporates:
   *  SignalConversion: '<S60>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  rtb_delay_acc_O_idx_2 = fmodf(floorf(INS_P.Gain10_Gain * rtb_Relay2),
    4.2949673E+9F);

  /* End of Outputs for SubSystem: '<S56>/Integrate' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */

  /* Sum: '<S8>/Sum2' incorporates:
   *  Constant: '<S168>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S34>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S49>/Constant'
   *  Delay: '<S12>/Delay'
   *  Delay: '<S13>/Delay'
   *  Delay: '<S14>/Delay'
   *  Delay: '<S15>/Delay'
   *  Delay: '<S16>/Delay'
   *  Delay: '<S17>/Delay'
   *  Delay: '<S18>/Delay'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain10'
   *  Gain: '<S8>/Gain11'
   *  Gain: '<S8>/Gain12'
   *  Gain: '<S8>/Gain13'
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain4'
   *  Gain: '<S8>/Gain5'
   *  Gain: '<S8>/Gain9'
   *  Logic: '<S10>/Logical Operator'
   *  Logic: '<S12>/Logical Operator'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S14>/Logical Operator'
   *  Logic: '<S15>/Logical Operator'
   *  Logic: '<S16>/Logical Operator'
   *  Logic: '<S17>/Logical Operator'
   *  Logic: '<S18>/Logical Operator'
   *  Product: '<S12>/Multiply'
   *  Product: '<S13>/Multiply'
   *  Product: '<S14>/Multiply'
   *  Product: '<S15>/Multiply'
   *  Product: '<S16>/Multiply'
   *  Product: '<S17>/Multiply'
   *  Product: '<S18>/Multiply'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S34>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S49>/Compare'
   */
  INS_Y.INS_Out.flag = (((((((((INS_P.Constant_Value_jz != 0) && (rtb_Compare_cl
    != 0) ? (uint32_T)INS_P.Gain9_Gain >> 7 : 0U) + (rtb_delay_acc_O_idx_2 <
    0.0F ? (uint32_T)-(int32_T)(uint32_T)-rtb_delay_acc_O_idx_2 : (uint32_T)
    rtb_delay_acc_O_idx_2)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_h < INS_P.valid_check5_time_out ?
     (int32_T)INS_DWork.Delay_DSTATE_c : 0) * INS_P.Gain11_Gain) >> 13)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 <
                 INS_P.valid_check8_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_l0 : 0) * INS_P.Gain12_Gain) >> 12)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_ca <
                 INS_P.valid_check1_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_cn : 0) * INS_P.Gain13_Gain) >> 11)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_b <
                 INS_P.valid_check2_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_bn : 0) * INS_P.Gain1_Gain_kq) >> 10)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_e <
                 INS_P.valid_check3_time_out ? (int32_T)INS_DWork.Delay_DSTATE_p
                 : 0) * INS_P.Gain2_Gain_o5) >> 9)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_kg < INS_P.valid_check4_time_out ?
     (int32_T)INS_DWork.Delay_DSTATE_db : 0) * INS_P.Gain4_Gain_a) >> 8)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_a <
                 INS_P.valid_check6_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_ly : 0) * INS_P.Gain5_Gain_e) >> 7);

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S23>/Constant'
   *  RelationalOperator: '<S21>/Compare'
   */
  rtb_Delay_a = ((rtb_Sum2_j > INS_P.CompareToConstant2_const) > (int32_T)
                 INS_P.Constant_Value_mt);

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S28>/Constant'
   *  RelationalOperator: '<S26>/Compare'
   */
  rtb_Compare_nt = ((rtb_Sum4_k > INS_P.CompareToConstant2_const_c) > (int32_T)
                    INS_P.Constant_Value_m2);

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S33>/Constant'
   *  RelationalOperator: '<S31>/Compare'
   */
  rtb_Compare_f5 = ((rtb_vel_N > INS_P.CompareToConstant2_const_n) > (int32_T)
                    INS_P.Constant_Value_o2);

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S36>/Compare'
   */
  rtb_Compare_bo = ((rtb_vel_E > INS_P.CompareToConstant2_const_b) > (int32_T)
                    INS_P.Constant_Value_hk);

  /* RelationalOperator: '<S43>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S43>/Constant'
   *  RelationalOperator: '<S41>/Compare'
   */
  rtb_Compare_fz = (((int32_T)rtb_Compare_fz > (int32_T)
                     INS_P.CompareToConstant2_const_io) > (int32_T)
                    INS_P.Constant_Value_l1);

  /* RelationalOperator: '<S48>/Compare' incorporates:
   *  Constant: '<S46>/Constant'
   *  Constant: '<S48>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  RelationalOperator: '<S46>/Compare'
   */
  rtb_Compare_hu = (((real32_T)rtb_LogicalOperator3 >
                     INS_P.CompareToConstant2_const_l) > (int32_T)
                    INS_P.Constant_Value_m2n);

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   *  Constant: '<S53>/Constant'
   *  RelationalOperator: '<S51>/Compare'
   */
  rtb_Compare_l0 = ((rtb_DiscreteTimeIntegrator_pm >
                     INS_P.CompareToConstant2_const_i) > (int32_T)
                    INS_P.Constant_Value_aoo);

  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S11>/Gain5'
   *  Gain: '<S11>/Gain7'
   *  MinMax: '<S11>/Max'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S55>/Compare'
   *  Sum: '<S11>/Sum2'
   */
  INS_Y.INS_Out.status = (((((rtb_Saturation_ad > INS_P.Constant_Value_h ?
    (uint32_T)INS_P.Gain2_Gain_ha >> 5 : 0U) + (rtb_FixPtRelationalOperator_if ?
    (uint32_T)INS_P.Gain3_Gain_f >> 4 : 0U)) + (fmaxf(rtb_Sum2_j, rtb_Sum4_k) >
    INS_P.Constant_Value_jj ? (uint32_T)INS_P.Gain4_Gain_p >> 3 : 0U)) +
    (rtb_LogicalOperator3 ? (uint32_T)INS_P.Gain5_Gain_o >> 2 : 0U)) +
    rtb_Delay_pa) + (rtb_Delay_d ? (uint32_T)INS_P.Gain7_Gain >> 1 : 0U);

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S13>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_b +=
    INS_P.DiscreteTimeIntegrator_gainval * INS_P.Constant_Value_p;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_n = (int8_T)rtb_Delay_h;

  /* Update for Delay: '<S13>/Delay' incorporates:
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S27>/FixPt Relational Operator'
   *  UnitDelay: '<S27>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_bn = (((int32_T)rtb_Compare_nt > (int32_T)
    INS_DWork.DelayInput1_DSTATE_mu) || INS_DWork.Delay_DSTATE_bn);

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_h +=
    INS_P.DiscreteTimeIntegrator_gainva_i * INS_P.Constant_Value_kn;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_m = (int8_T)rtb_Compare_cio;

  /* Update for Delay: '<S16>/Delay' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   *  RelationalOperator: '<S42>/FixPt Relational Operator'
   *  UnitDelay: '<S42>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_c = (((int32_T)rtb_Compare_fz > (int32_T)
    INS_DWork.DelayInput1_DSTATE_ng) || INS_DWork.Delay_DSTATE_c);

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S18>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 +=
    INS_P.DiscreteTimeIntegrator_gainva_m * INS_P.Constant_Value_j;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_d = (int8_T)rtb_UpperTest_cv;

  /* Update for Delay: '<S18>/Delay' incorporates:
   *  Logic: '<S18>/Logical Operator1'
   *  RelationalOperator: '<S52>/FixPt Relational Operator'
   *  UnitDelay: '<S52>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_l0 = (((int32_T)rtb_Compare_l0 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_fq) || INS_DWork.Delay_DSTATE_l0);

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S12>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_ca +=
    INS_P.DiscreteTimeIntegrator_gainva_k * INS_P.Constant_Value_f;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_h = (int8_T)rtb_LogicalOperator1_o;

  /* Update for Delay: '<S12>/Delay' incorporates:
   *  Logic: '<S12>/Logical Operator1'
   *  RelationalOperator: '<S22>/FixPt Relational Operator'
   *  UnitDelay: '<S22>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_cn = (((int32_T)rtb_Delay_a > (int32_T)
    INS_DWork.DelayInput1_DSTATE_dx) || INS_DWork.Delay_DSTATE_cn);

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S14>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_e +=
    INS_P.DiscreteTimeIntegrator_gainva_p * INS_P.Constant_Value_k;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_a = (int8_T)rtb_Compare_gt;

  /* Update for Delay: '<S14>/Delay' incorporates:
   *  Logic: '<S14>/Logical Operator1'
   *  RelationalOperator: '<S32>/FixPt Relational Operator'
   *  UnitDelay: '<S32>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_p = (((int32_T)rtb_Compare_f5 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_dq) || INS_DWork.Delay_DSTATE_p);

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S15>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_kg +=
    INS_P.DiscreteTimeIntegrator_gainv_me * INS_P.Constant_Value_ih;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_o = (int8_T)rtb_LogicalOperator2_o;

  /* Update for Delay: '<S15>/Delay' incorporates:
   *  Logic: '<S15>/Logical Operator1'
   *  RelationalOperator: '<S37>/FixPt Relational Operator'
   *  UnitDelay: '<S37>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_db = (((int32_T)rtb_Compare_bo > (int32_T)
    INS_DWork.DelayInput1_DSTATE_f4) || INS_DWork.Delay_DSTATE_db);

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S17>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_a +=
    INS_P.DiscreteTimeIntegrator_gainv_my * INS_P.Constant_Value_c;
  INS_DWork.DiscreteTimeIntegrator_PrevR_ar = (int8_T)rtb_Compare_e;

  /* Update for Delay: '<S17>/Delay' incorporates:
   *  Logic: '<S17>/Logical Operator1'
   *  RelationalOperator: '<S47>/FixPt Relational Operator'
   *  UnitDelay: '<S47>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_ly = (((int32_T)rtb_Compare_hu > (int32_T)
    INS_DWork.DelayInput1_DSTATE_dql) || INS_DWork.Delay_DSTATE_ly);

  /* Update for UnitDelay: '<S22>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dx = rtb_Delay_a;

  /* Update for UnitDelay: '<S27>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_mu = rtb_Compare_nt;

  /* Update for UnitDelay: '<S32>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dq = rtb_Compare_f5;

  /* Update for UnitDelay: '<S37>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_f4 = rtb_Compare_bo;

  /* Update for UnitDelay: '<S42>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ng = rtb_Compare_fz;

  /* Update for UnitDelay: '<S47>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dql = rtb_Compare_hu;

  /* Update for UnitDelay: '<S52>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_fq = rtb_Compare_l0;

  /* End of Outputs for SubSystem: '<S1>/Status_Output' */

  /* Outputs for Atomic SubSystem: '<S1>/Rotation_Output' */
  /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
   *  Constant: '<S7>/Constant'
   *  Outport: '<Root>/INS_Out'
   *  SignalConversion: '<S5>/Signal Copy'
   *  SignalConversion: '<S7>/Signal Copy'
   */
  INS_Y.INS_Out.phi = rtb_DiscreteTimeIntegrator_c__1;
  INS_Y.INS_Out.theta = rtb_DiscreteTimeIntegrator_c__0;
  INS_Y.INS_Out.psi = rtb_TrigonometricFunction1;
  INS_Y.INS_Out.quat[0] = rtb_Add_m;
  INS_Y.INS_Out.quat[1] = rtb_Inclination;
  INS_Y.INS_Out.quat[2] = rtb_DiscreteTimeIntegrator_c_id;
  INS_Y.INS_Out.quat[3] = rtb_Product3_eb;
  INS_Y.INS_Out.p = rtb_VectorConcatenate_idx_0;
  INS_Y.INS_Out.q = rtb_VectorConcatenate_idx_1;

  /* End of Outputs for SubSystem: '<S1>/Rotation_Output' */
  /* End of Outputs for SubSystem: '<Root>/Bus_Assignment' */
  INS_Y.INS_Out.r = rtb_delay_acc_O_idx_1;
  INS_Y.INS_Out.ax = rtb_ba_O_mDs2[0];
  INS_Y.INS_Out.ay = rtb_ba_O_mDs2[1];
  INS_Y.INS_Out.az = rtb_ba_O_mDs2[2];

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Assignment' */
  /* Outputs for Atomic SubSystem: '<S1>/Translation_Output' */
  INS_Y.INS_Out.vn = rtb_Sum_g0[2];
  INS_Y.INS_Out.ve = rtb_Sum_g0[3];
  INS_Y.INS_Out.vd = rtb_Multiply_j[1];

  /* End of Outputs for SubSystem: '<S1>/Translation_Output' */
  /* End of Outputs for SubSystem: '<Root>/Bus_Assignment' */
  INS_Y.INS_Out.reserved = INS_P.Constant_Value_n;

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Assignment' */
  /* Outputs for Atomic SubSystem: '<S1>/Translation_Output' */
  INS_Y.INS_Out.x_R = rtb_Sum_g0[0];
  INS_Y.INS_Out.y_R = rtb_Sum_g0[1];
  INS_Y.INS_Out.h_R = rtb_Multiply_j[0];

  /* End of Outputs for SubSystem: '<S1>/Translation_Output' */
  /* End of Outputs for SubSystem: '<Root>/Bus_Assignment' */

  /* Update for Delay: '<Root>/Delay1' */
  INS_DWork.Delay1_4_DSTATE = rtb_Sum_g0[2];
  INS_DWork.Delay1_5_DSTATE = rtb_Sum_g0[3];

  /* Update for Delay: '<Root>/Delay' */
  for (i = 0; i < 9; i++) {
    INS_DWork.Delay_8_DSTATE[i] = rtb_VectorConcatenate_m[i];
  }
}

/* Model initialize function */
void INS_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(INS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &INS_B), 0,
                sizeof(BlockIO_INS_T));

  /* states (dwork) */
  (void) memset((void *)&INS_DWork, 0,
                sizeof(D_Work_INS_T));

  /* external inputs */
  (void)memset(&INS_U, 0, sizeof(ExternalInputs_INS_T));

  /* external outputs */
  INS_Y.INS_Out = INS_rtZINS_Out_Bus;

  {
    int32_T i;
    INS_PrevZCSigState.x_delay_Reset_ZCE_b = POS_ZCSIG;
    INS_PrevZCSigState.x_delay1_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay1_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.x_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.h_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vd_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.WGS84_Model_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    INS_DWork.Delay1_4_DSTATE = INS_P.Delay1_4_InitialCondition;
    INS_DWork.Delay1_5_DSTATE = INS_P.Delay1_5_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Process' */
    /* SystemInitialize for Atomic SubSystem: '<S3>/Baro_Process' */
    /* InitializeConditions for Delay: '<S283>/Delay' */
    INS_DWork.Delay_DSTATE_f = INS_P.Delay_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S291>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_g = INS_P.DetectChange_vinit_d;

    /* InitializeConditions for DiscreteIntegrator: '<S283>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev =
      INS_P.DiscreteTimeIntegrator_IC_dv;

    /* SystemInitialize for Enabled SubSystem: '<S281>/Reference_and_Derivative' */
    /* InitializeConditions for Delay: '<S284>/Delay' */
    INS_DWork.Delay_DSTATE_d = INS_P.Delay_InitialCondition_p;

    /* InitializeConditions for Delay: '<S284>/Delay1' */
    INS_DWork.Delay1_DSTATE_i = INS_P.Delay1_InitialCondition_k;

    /* InitializeConditions for Delay: '<S284>/Delay2' */
    INS_DWork.Delay2_DSTATE = INS_P.Delay2_InitialCondition;

    /* SystemInitialize for Outport: '<S284>/pressure_R' */
    INS_B.Divide = INS_P.pressure_R_Y0;

    /* SystemInitialize for Outport: '<S284>/dh_dp' */
    INS_B.gain = INS_P.dh_dp_Y0;

    /* End of SystemInitialize for SubSystem: '<S281>/Reference_and_Derivative' */
    /* End of SystemInitialize for SubSystem: '<S3>/Baro_Process' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/GPS_Process' */
    /* InitializeConditions for UnitDelay: '<S308>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S310>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_i = INS_P.DetectChange_vinit_e;

    /* InitializeConditions for DiscreteIntegrator: '<S304>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_p;

    /* SystemInitialize for Triggered SubSystem: '<S275>/WGS84_Model' */
    /* SystemInitialize for Outport: '<S298>/lon_0_rad' */
    INS_B.Scalefactor = INS_P.lon_0_rad_Y0;

    /* SystemInitialize for Outport: '<S298>/lat_0_rad' */
    INS_B.Scalefactor1 = INS_P.lat_0_rad_Y0;

    /* SystemInitialize for Outport: '<S298>/dx_dlat' */
    INS_B.Add = INS_P.dx_dlat_Y0;

    /* SystemInitialize for Outport: '<S298>/dy_dlon' */
    INS_B.Product4 = INS_P.dy_dlon_Y0;

    /* SystemInitialize for Outport: '<S298>/dz_dh' */
    INS_B.OutportBufferFordz_dh = INS_P.dz_dh_Y0;

    /* End of SystemInitialize for SubSystem: '<S275>/WGS84_Model' */
    /* End of SystemInitialize for SubSystem: '<S3>/GPS_Process' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/IMU_Process' */
    /* InitializeConditions for UnitDelay: '<S325>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_h = INS_P.DetectChange_vinit_md;

    /* InitializeConditions for DiscreteIntegrator: '<S314>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lp =
      INS_P.DiscreteTimeIntegrator_IC_b;

    /* InitializeConditions for UnitDelay: '<S331>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ht = INS_P.DetectChange_vinit_j;

    /* InitializeConditions for DiscreteIntegrator: '<S316>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_IC_pw;

    /* InitializeConditions for DiscreteIntegrator: '<S320>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator_IC_c;

    /* InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c[0] =
      INS_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator_IC_c;

    /* InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c[1] =
      INS_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator_IC_c;

    /* InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c[2] =
      INS_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_a = 1U;

    /* End of SystemInitialize for SubSystem: '<S3>/IMU_Process' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/Mag_Process' */
    /* InitializeConditions for UnitDelay: '<S339>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_n = INS_P.DetectChange_vinit_l;

    /* InitializeConditions for DiscreteIntegrator: '<S335>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l =
      INS_P.DiscreteTimeIntegrator_IC_k;

    /* End of SystemInitialize for SubSystem: '<S3>/Mag_Process' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/Optical_Flow_Preprocessing' */
    /* InitializeConditions for UnitDelay: '<S356>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_l = INS_P.DetectChange_vinit_i;

    /* InitializeConditions for DiscreteIntegrator: '<S354>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n =
      INS_P.DiscreteTimeIntegrator_IC_g;

    /* End of SystemInitialize for SubSystem: '<S3>/Optical_Flow_Preprocessing' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/Sonar_Process' */
    /* InitializeConditions for UnitDelay: '<S360>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE = INS_P.DetectChange_vinit_k;

    /* InitializeConditions for DiscreteIntegrator: '<S357>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kn =
      INS_P.DiscreteTimeIntegrator_IC_pt;

    /* InitializeConditions for Delay: '<S357>/Delay' */
    INS_DWork.Delay_DSTATE_dz = INS_P.Delay_InitialCondition_cg;

    /* End of SystemInitialize for SubSystem: '<S3>/Sonar_Process' */
    /* End of SystemInitialize for SubSystem: '<Root>/Sensor_Process' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Data_Fusion' */
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for Delay: '<Root>/Delay' */
      INS_DWork.Delay_6_DSTATE[i] = INS_P.Delay_6_InitialCondition;
      INS_DWork.Delay_8_DSTATE[i] = INS_P.Delay_8_InitialCondition_m;

      /* InitializeConditions for Delay: '<S56>/Delay' */
      INS_DWork.Delay_8_DSTATE_l[i] = INS_P.Delay_8_InitialCondition;
      INS_DWork.Delay_9_DSTATE[i] = INS_P.Delay_9_InitialCondition;
    }

    /* InitializeConditions for Delay: '<S56>/Delay' */
    INS_DWork.Delay_10_DSTATE[0] = INS_P.Delay_10_InitialCondition;
    INS_DWork.Delay_10_DSTATE[1] = INS_P.Delay_10_InitialCondition;
    INS_DWork.Delay_10_DSTATE[2] = INS_P.Delay_10_InitialCondition;

    /* InitializeConditions for Delay: '<S57>/Delay' */
    INS_DWork.Delay_9_DSTATE_m = INS_P.Delay_9_InitialCondition_h;
    INS_DWork.Delay_10_DSTATE_a = INS_P.Delay_10_InitialCondition_h;
    INS_DWork.Delay_11_DSTATE = INS_P.Delay_11_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<S56>/Attitude_Init' */
    /* InitializeConditions for Delay: '<S109>/Delay' */
    INS_DWork.Delay_DSTATE_i = INS_P.Delay_InitialCondition_n0;

    /* InitializeConditions for UnitDelay: '<S112>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_p = INS_P.DetectRisePositive_vinit_fc;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator5_IC;
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator5_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_o =
      INS_P.DiscreteTimeIntegrator5_IC_m;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_n =
      INS_P.DiscreteTimeIntegrator5_IC_a;

    /* SystemInitialize for Enabled SubSystem: '<S58>/Attitude_Init' */
    /* SystemInitialize for Merge: '<S65>/Merge' */
    INS_B.Merge[0] = INS_P.Merge_InitialOutput[0];

    /* SystemInitialize for Outport: '<S61>/quaternion_0' */
    INS_B.OutportBufferForquaternion_0[0] = INS_P.quaternion_0_Y0[0];

    /* SystemInitialize for Merge: '<S65>/Merge' */
    INS_B.Merge[1] = INS_P.Merge_InitialOutput[1];

    /* SystemInitialize for Outport: '<S61>/quaternion_0' */
    INS_B.OutportBufferForquaternion_0[1] = INS_P.quaternion_0_Y0[1];

    /* SystemInitialize for Merge: '<S65>/Merge' */
    INS_B.Merge[2] = INS_P.Merge_InitialOutput[2];

    /* SystemInitialize for Outport: '<S61>/quaternion_0' */
    INS_B.OutportBufferForquaternion_0[2] = INS_P.quaternion_0_Y0[2];

    /* SystemInitialize for Merge: '<S65>/Merge' */
    INS_B.Merge[3] = INS_P.Merge_InitialOutput[3];

    /* SystemInitialize for Outport: '<S61>/quaternion_0' */
    INS_B.OutportBufferForquaternion_0[3] = INS_P.quaternion_0_Y0[3];

    /* End of SystemInitialize for SubSystem: '<S58>/Attitude_Init' */
    /* End of SystemInitialize for SubSystem: '<S56>/Attitude_Init' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Correct' */
    /* InitializeConditions for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_o = 1U;

    /* InitializeConditions for Delay: '<S122>/Delay' */
    for (i = 0; i < 600; i++) {
      INS_DWork.Delay_DSTATE_lv[i] = INS_P.Delay_InitialCondition_m;
    }

    /* End of InitializeConditions for Delay: '<S122>/Delay' */

    /* InitializeConditions for UnitDelay: '<S139>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ff = INS_P.DetectIncrease_vinit;

    /* InitializeConditions for DiscreteFir: '<S124>/Discrete FIR Filter' */
    INS_DWork.DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 29; i++) {
      INS_DWork.DiscreteFIRFilter_states[i] =
        INS_P.DiscreteFIRFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S124>/Discrete FIR Filter' */

    /* InitializeConditions for RateLimiter: '<S150>/Rate Limiter' */
    INS_DWork.PrevY = INS_P.RateLimiter_IC;

    /* SystemInitialize for Enabled SubSystem: '<S123>/GPS_Acc_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_L_oi = 1U;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_PrevRe_c = 0;

    /* End of SystemInitialize for SubSystem: '<S123>/GPS_Acc_Observer' */

    /* InitializeConditions for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0] =
      INS_P.DiscreteTimeIntegrator_IC_d;

    /* SystemInitialize for Enabled SubSystem: '<S123>/GPS_Acc_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o[0] =
      INS_P.DiscreteTimeIntegrator_IC_a;

    /* SystemInitialize for Outport: '<S140>/GPS_acc_O_mPs2' */
    INS_B.DiscreteTimeIntegrator[0] = INS_P.GPS_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S123>/GPS_Acc_Observer' */

    /* InitializeConditions for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1] =
      INS_P.DiscreteTimeIntegrator_IC_d;

    /* SystemInitialize for Enabled SubSystem: '<S123>/GPS_Acc_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o[1] =
      INS_P.DiscreteTimeIntegrator_IC_a;

    /* SystemInitialize for Outport: '<S140>/GPS_acc_O_mPs2' */
    INS_B.DiscreteTimeIntegrator[1] = INS_P.GPS_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S123>/GPS_Acc_Observer' */

    /* InitializeConditions for DiscreteIntegrator: '<S138>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2] =
      INS_P.DiscreteTimeIntegrator_IC_d;

    /* SystemInitialize for Enabled SubSystem: '<S123>/GPS_Acc_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o[2] =
      INS_P.DiscreteTimeIntegrator_IC_a;

    /* SystemInitialize for Outport: '<S140>/GPS_acc_O_mPs2' */
    INS_B.DiscreteTimeIntegrator[2] = INS_P.GPS_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S123>/GPS_Acc_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0] =
      INS_P.DiscreteTimeIntegrator1_IC;
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1] =
      INS_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_IC_LOA_k = 1U;

    /* End of SystemInitialize for SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* End of SystemInitialize for SubSystem: '<S56>/Correct' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Integrate' */
    /* InitializeConditions for Delay: '<S153>/Delay' */
    INS_DWork.Delay_DSTATE_f0 = INS_P.Delay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S157>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dy = INS_P.DetectIncrease_vinit_d;

    /* InitializeConditions for DiscreteIntegrator: '<S154>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_IC_LOADI = 1U;
    INS_DWork.DiscreteTimeIntegrator_PrevRese = 0;

    /* End of SystemInitialize for SubSystem: '<S56>/Integrate' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Correct' */
    /* SystemInitialize for Enabled SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* SystemInitialize for Outport: '<S142>/OptFlow_acc_O_mPs2' */
    INS_B.Reshape[0] = INS_P.OptFlow_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* End of SystemInitialize for SubSystem: '<S56>/Correct' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Integrate' */
    /* InitializeConditions for DiscreteIntegrator: '<S155>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* End of SystemInitialize for SubSystem: '<S56>/Integrate' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Correct' */
    /* SystemInitialize for Enabled SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* SystemInitialize for Outport: '<S142>/OptFlow_acc_O_mPs2' */
    INS_B.Reshape[1] = INS_P.OptFlow_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* End of SystemInitialize for SubSystem: '<S56>/Correct' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Integrate' */
    /* InitializeConditions for DiscreteIntegrator: '<S155>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* End of SystemInitialize for SubSystem: '<S56>/Integrate' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Correct' */
    /* SystemInitialize for Enabled SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* SystemInitialize for Outport: '<S142>/OptFlow_acc_O_mPs2' */
    INS_B.Reshape[2] = INS_P.OptFlow_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S123>/OpticalFlow_Acc_Observer' */
    /* End of SystemInitialize for SubSystem: '<S56>/Correct' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/Integrate' */
    /* InitializeConditions for DiscreteIntegrator: '<S155>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* End of SystemInitialize for SubSystem: '<S56>/Integrate' */

    /* SystemInitialize for Atomic SubSystem: '<S57>/Process' */
    /* InitializeConditions for UnitDelay: '<S238>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_j = INS_P.DetectRisePositive_vinit_h;

    /* InitializeConditions for UnitDelay: '<S240>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_o = INS_P.DetectRisePositive_vinit_me;

    /* InitializeConditions for Delay: '<S243>/Delay1' */
    INS_DWork.Delay1_DSTATE = INS_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S245>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dp = INS_P.DetectRisePositive3_vinit;

    /* InitializeConditions for Delay: '<S244>/Delay' */
    INS_DWork.Delay_DSTATE[0] = INS_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S244>/Delay1' */
    INS_DWork.Delay1_DSTATE_o[0] = INS_P.Delay1_InitialCondition_e;

    /* InitializeConditions for Delay: '<S244>/Delay' */
    INS_DWork.Delay_DSTATE[1] = INS_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S244>/Delay1' */
    INS_DWork.Delay1_DSTATE_o[1] = INS_P.Delay1_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S247>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_m = INS_P.DetectRisePositive3_vinit_h;

    /* End of SystemInitialize for SubSystem: '<S57>/Process' */

    /* SystemInitialize for Atomic SubSystem: '<S57>/CF' */
    /* InitializeConditions for Delay: '<S218>/Delay' */
    INS_DWork.Delay_DSTATE_b[0] = INS_P.Delay_InitialCondition_mt;
    INS_DWork.Delay_DSTATE_b[1] = INS_P.Delay_InitialCondition_mt;
    INS_DWork.Delay_DSTATE_b[2] = INS_P.Delay_InitialCondition_mt;

    /* SystemInitialize for Merge: '<S220>/Merge' */
    INS_B.h_0 = INS_P.Merge_InitialOutput_j;

    /* SystemInitialize for Merge: '<S220>/Merge1' */
    INS_B.vel_D_0 = INS_P.Merge1_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S198>/Baro_Correct' */
    /* InitializeConditions for UnitDelay: '<S201>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_lg = INS_P.DetectChange_vinit_m;

    /* InitializeConditions for Delay: '<S204>/x_delay' */
    INS_DWork.icLoad_a = 1U;

    /* InitializeConditions for UnitDelay: '<S208>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f = INS_P.DetectIncrease_vinit_c;

    /* InitializeConditions for Memory: '<S206>/Memory' */
    INS_DWork.Memory_PreviousInput_j = INS_P.Memory_InitialCondition_m;

    /* End of SystemInitialize for SubSystem: '<S198>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S199>/GPS_Correct' */
    /* InitializeConditions for UnitDelay: '<S210>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d = INS_P.DetectChange_vinit_h;

    /* InitializeConditions for Delay: '<S213>/h_delay' */
    INS_DWork.icLoad = 1U;

    /* InitializeConditions for Delay: '<S213>/vd_delay' */
    INS_DWork.icLoad_f = 1U;

    /* InitializeConditions for UnitDelay: '<S217>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ib = INS_P.DetectIncrease_vinit_j;

    /* InitializeConditions for Memory: '<S215>/Memory' */
    INS_DWork.Memory_PreviousInput = INS_P.Memory_InitialCondition_p;

    /* End of SystemInitialize for SubSystem: '<S199>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S198>/Baro_Correct' */
    /* InitializeConditions for Memory: '<S202>/Memory' */
    INS_DWork.Memory_PreviousInput_i[0] = INS_P.Memory_InitialCondition_j;

    /* SystemInitialize for Outport: '<S200>/X_Next' */
    INS_B.Sum1_p[0] = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S198>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S199>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S211>/Memory' */
    INS_DWork.Memory_PreviousInput_e[0] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Outport: '<S209>/X_Next' */
    INS_B.Sum1[0] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S199>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S198>/Baro_Correct' */
    /* InitializeConditions for Memory: '<S202>/Memory' */
    INS_DWork.Memory_PreviousInput_i[1] = INS_P.Memory_InitialCondition_j;

    /* SystemInitialize for Outport: '<S200>/X_Next' */
    INS_B.Sum1_p[1] = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S198>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S199>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S211>/Memory' */
    INS_DWork.Memory_PreviousInput_e[1] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Outport: '<S209>/X_Next' */
    INS_B.Sum1[1] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S199>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S198>/Baro_Correct' */
    /* InitializeConditions for Memory: '<S202>/Memory' */
    INS_DWork.Memory_PreviousInput_i[2] = INS_P.Memory_InitialCondition_j;

    /* SystemInitialize for Outport: '<S200>/X_Next' */
    INS_B.Sum1_p[2] = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S198>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S199>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S211>/Memory' */
    INS_DWork.Memory_PreviousInput_e[2] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Outport: '<S209>/X_Next' */
    INS_B.Sum1[2] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S199>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S176>/GPS_Correct' */
    /* InitializeConditions for UnitDelay: '<S179>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d0 = INS_P.DetectChange_vinit;

    /* InitializeConditions for Delay: '<S182>/x_delay' */
    INS_DWork.icLoad_o = 1U;

    /* InitializeConditions for Delay: '<S182>/x_delay1' */
    INS_DWork.icLoad_i = 1U;

    /* InitializeConditions for Delay: '<S182>/vn_delay' */
    INS_DWork.icLoad_m = 1U;

    /* InitializeConditions for Delay: '<S182>/vn_delay1' */
    INS_DWork.icLoad_j = 1U;

    /* InitializeConditions for UnitDelay: '<S187>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_gn = INS_P.DetectIncrease_vinit_p;

    /* End of SystemInitialize for SubSystem: '<S176>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S191>/GPS_Pos_Init' */
    /* SystemInitialize for Outport: '<S193>/X_0' */
    INS_B.DataTypeConversion[0] = INS_P.X_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S191>/GPS_Pos_Init' */

    /* SystemInitialize for Enabled SubSystem: '<S176>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S185>/Memory' */
    INS_DWork.Memory_PreviousInput_d[0] = INS_P.Memory_InitialCondition[0];

    /* End of SystemInitialize for SubSystem: '<S176>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S191>/GPS_Pos_Init' */
    /* SystemInitialize for Outport: '<S193>/X_0' */
    INS_B.DataTypeConversion[1] = INS_P.X_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S191>/GPS_Pos_Init' */

    /* SystemInitialize for Enabled SubSystem: '<S176>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S185>/Memory' */
    INS_DWork.Memory_PreviousInput_d[1] = INS_P.Memory_InitialCondition[1];
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for Delay: '<S188>/Delay' */
      INS_DWork.Delay_DSTATE_l[i] = INS_P.Delay_InitialCondition_g;

      /* InitializeConditions for Memory: '<S180>/Memory' */
      INS_DWork.Memory_PreviousInput_h[i] = INS_P.Memory_InitialCondition_o;

      /* SystemInitialize for Outport: '<S178>/X_Next' */
      INS_B.Sum1_o[i] = INS_P.X_Next_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S176>/GPS_Correct' */
    /* End of SystemInitialize for SubSystem: '<S57>/CF' */
    /* End of SystemInitialize for SubSystem: '<Root>/Data_Fusion' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Assignment' */
    /* SystemInitialize for Atomic SubSystem: '<S1>/Counter' */
    /* InitializeConditions for UnitDelay: '<S4>/Output' */
    INS_DWork.Output_DSTATE = INS_P.Output_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S1>/Counter' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/Status_Output' */
    /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_b = INS_P.DiscreteTimeIntegrator_IC;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_n = 0;

    /* InitializeConditions for Delay: '<S13>/Delay' */
    INS_DWork.Delay_DSTATE_bn = INS_P.Delay_InitialCondition_go;

    /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_i;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_m = 0;

    /* InitializeConditions for Delay: '<S16>/Delay' */
    INS_DWork.Delay_DSTATE_c = INS_P.Delay_InitialCondition_mz;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 =
      INS_P.DiscreteTimeIntegrator_IC_o;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for Delay: '<S18>/Delay' */
    INS_DWork.Delay_DSTATE_l0 = INS_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_IC_l;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = 0;

    /* InitializeConditions for Delay: '<S12>/Delay' */
    INS_DWork.Delay_DSTATE_cn = INS_P.Delay_InitialCondition_c;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_j;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_a = 0;

    /* InitializeConditions for Delay: '<S14>/Delay' */
    INS_DWork.Delay_DSTATE_p = INS_P.Delay_InitialCondition_cj;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kg =
      INS_P.DiscreteTimeIntegrator_IC_ig;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_o = 0;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    INS_DWork.Delay_DSTATE_db = INS_P.Delay_InitialCondition_ae;

    /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_a =
      INS_P.DiscreteTimeIntegrator_IC_e;
    INS_DWork.DiscreteTimeIntegrator_PrevR_ar = 0;

    /* InitializeConditions for Delay: '<S17>/Delay' */
    INS_DWork.Delay_DSTATE_ly = INS_P.Delay_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S22>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dx = INS_P.DetectRisePositive_vinit;

    /* InitializeConditions for UnitDelay: '<S27>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_mu = INS_P.DetectRisePositive_vinit_c;

    /* InitializeConditions for UnitDelay: '<S32>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dq = INS_P.DetectRisePositive_vinit_m;

    /* InitializeConditions for UnitDelay: '<S37>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f4 = INS_P.DetectRisePositive_vinit_k;

    /* InitializeConditions for UnitDelay: '<S42>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ng = INS_P.DetectRisePositive_vinit_a;

    /* InitializeConditions for UnitDelay: '<S47>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dql = INS_P.DetectRisePositive_vinit_f;

    /* InitializeConditions for UnitDelay: '<S52>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_fq = INS_P.DetectRisePositive_vinit_l;

    /* End of SystemInitialize for SubSystem: '<S1>/Status_Output' */
    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Assignment' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
