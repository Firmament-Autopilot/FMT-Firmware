/*
 * File: INS.c
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
struct_Ql5UyHVjtSbWmZyqe5lwlE INS_PARAM = {
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

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F }
} ;                                    /* Variable: INS_PARAM
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

struct_4XfCoaAMTej5uH3d8u88xB INS_EXPORT = {
  2U
} ;                                    /* Variable: INS_EXPORT
                                        * Referenced by:
                                        *   '<S84>/Constant'
                                        *   '<S174>/Constant'
                                        *   '<S176>/Constant'
                                        *   '<S197>/Constant'
                                        *   '<S219>/Constant'
                                        *   '<S145>/Constant'
                                        *   '<S166>/Constant'
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
  0.01F,
  5.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.2F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
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
  100.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  200.0F,
  100.0F,
  10.3055F,
  2.5F,
  500U,
  1000U,
  100U,
  100U,
  1000000U,
  200U,
  5000U,
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
  2U,
  1U,
  0U,

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
  1.0,

  { 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  0.0,
  1.0E+8,
  0,
  8,
  16,
  0,
  18,
  36,
  0,
  2000,
  0,
  1099511628,
  1099511628,
  1099511628,
  1099511628,
  2012227627,
  2012227627,
  1.0F,
  1.0E-6F,
  0.25F,
  0.25F,
  0.25F,
  0.25F,
  1.0F,
  1.0E-6F,
  0.25F,
  0.25F,
  0.25F,
  0.25F,
  1.0F,
  1.0E-6F,
  0.25F,
  0.25F,
  0.25F,
  0.25F,
  1.0F,
  1.0E-6F,
  0.25F,
  0.25F,
  0.25F,
  0.25F,

  { 1.0F, 0.0F, 0.0F, 0.0F },
  -1.0F,
  0.001F,
  0.001F,
  0.001F,
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
  0.002F,
  0.0F,
  14.14F,
  0.002F,
  100.0F,
  0.0F,
  0.0F,
  273.15F,
  0.0F,
  0.0F,
  120000.0F,
  500.0F,
  -29.2692909F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  2.0F,
  1.0F,
  1.0F,
  0.0F,
  1.0F,
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
  0.002F,
  0.0F,
  0.002F,
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
  0.002F,
  0.0F,
  0.87266463F,
  -0.87266463F,
  0.002F,
  0.7F,
  2.5F,
  1.0F,
  0.0F,
  0.0F,
  3.0F,
  0.4F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  0.0F,
  1.0F,
  0.0F,

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 0.0F, 0.0F },
  0.002F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0F, 0.0F },
  -1.0F,
  9.806F,
  0.0F,
  0.002F,
  0.0F,
  0.002F,
  0.01F,
  0.01F,
  0.003F,
  0.0F,
  1.0F,
  2.0F,
  1.0F,
  0.0F,
  0.0F,
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  100.0F,
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
  0.0F,
  0.0F,
  0.0F,
  0.002F,
  0.0F,
  4.0F,
  0.002F,
  0.0F,
  2.0F,
  1.0F,
  0.0F,
  20.0F,
  0.0F,
  0.0F,
  0.002F,
  0.2F,
  0.1F,
  1.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0F, -9.805F },
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
  9.806F,
  -0.1F,
  0.3F,
  0.2F,
  1.0F,
  0.0F,
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
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.002F,
  0.0F,
  -266.532715F,
  35530.5742F,
  0.002F,
  0.0F,
  -266.532715F,
  35530.5742F,
  1.0F,
  2199023256U,
  2199023256U,
  1U,
  0U,
  4294967295U,
  1U,
  75U,
  75U,
  50U,
  50U,
  5U,
  75U,
  50U,
  0U,
  0U,
  0U,
  1U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
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
  1U,
  0U,
  0U,
  1U,
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
  real32_T rtb_VectorConcatenate[3];
  boolean_T rtb_Memory_ph;
  real32_T rtb_VectorConcatenate_o[3];
  uint8_T rtb_Sum_na;
  boolean_T rtb_Compare_h2;
  boolean_T rtb_Compare_p1;
  real32_T rtb_Product3_eb;
  boolean_T rtb_LowerTest_b;
  boolean_T rtb_UpperTest_g;
  uint16_T rtb_Add_kz;
  real32_T rtb_Product12_k;
  real32_T rtb_Product15;
  real32_T rtb_DiscreteTimeIntegrator1_g[3];
  real32_T rtb_Product3_p;
  real32_T rtb_Product1_l5;
  uint8_T rtb_Compare_ou;
  uint8_T rtb_Compare_iu;
  uint8_T rtb_Compare_hd;
  boolean_T rtb_GPS_vaid;
  boolean_T rtb_LogicalOperator_mt;
  real32_T rtb_Double;
  boolean_T rtb_LogicalOperator_l4;
  real32_T rtb_Double1;
  boolean_T rtb_Compare_nt;
  boolean_T rtb_Compare_e;
  real_T rtb_Scalefactor1;
  real_T rtb_Scalefactor2;
  real_T rtb_Scalefactor3;
  boolean_T rtb_Compare_a;
  real32_T rtb_vel_E;
  real32_T rtb_VectorConcatenate_l[9];
  real32_T rtb_Relay2;
  real32_T rtb_Sum2_g[3];
  real32_T rtb_Multiply[3];
  real32_T rtb_Switch_er[6];
  boolean_T rtb_Compare_f3;
  boolean_T rtb_LogicalOperator_b3;
  boolean_T rtb_LogicalOperator2_m;
  real_T rtb_Gain6;
  real32_T rtb_vel_D;
  boolean_T rtb_Compare_bg;
  real32_T rtb_bias_g_correction_f[3];
  int32_T rtb_Saturation1_b;
  int32_T rtb_Sum_ly;
  boolean_T rtb_Compare_ju;
  boolean_T rtb_Compare_pq;
  real32_T rtb_h_R_quality;
  boolean_T rtb_Compare_et;
  boolean_T rtb_pos_ever_valid_n;
  boolean_T rtb_Compare_hp;
  uint32_T rtb_Sum_nb;
  boolean_T rtb_LogicalOperator1_o;
  real32_T rtb_Product9_g;
  real32_T rtb_Product8_n;
  boolean_T rtb_Compare_an;
  real32_T rtb_Max_c;
  real_T rtb_N;
  real32_T rtb_baro_height_bias;
  real32_T rtb_Sum_mt[6];
  real32_T rtb_Inclination;
  boolean_T rtb_AND[3];
  boolean_T rtb_AND_lx[3];
  real32_T rtb_M_OB[9];
  real32_T rtb_Gauss_to_uT[3];
  real32_T rtb_Product3_i[3];
  real32_T rtb_MathFunction[3];
  real32_T rtb_Transpose2_tmp[9];
  real32_T rtb_M_OB_0[3];
  real32_T tmp[6];
  int32_T i;
  real32_T rtb_Sum_j_idx_3;
  real_T rtb_WGS84_pos_ref_idx_1;
  real32_T rtb_vel_NE_0_idx_0;
  real32_T rtb_vel_NE_0_idx_1;
  real_T rtb_WGS84_derivatives_ref_idx_0;
  real32_T rtb_gps_pos_bias_idx_1;
  real32_T rtb_MathFunction_e_idx_2;
  real_T rtb_Switch_idx_2;
  real32_T rtb_delay_acc_O_idx_1;
  real32_T rtb_delay_acc_O_idx_0;
  real32_T rtb_DiscreteTimeIntegrator1_o_i;
  real32_T rtb_DiscreteTimeIntegrator1_o_0;
  real32_T rtb_DiscreteTimeIntegrator1_o_1;
  real32_T rtb_delay_acc_O_idx_2;
  real_T tmp_0;
  uint32_T qY;
  uint32_T qY_0;
  uint16_T rtb_Add_i;
  real32_T tmp_1;
  int32_T rtb_Saturation1_j;
  real32_T rtb_Product8_j_tmp;
  real32_T rtb_Product3_j_tmp;

  /* Sum: '<S179>/Subtract' incorporates:
   *  Constant: '<S179>/Gyro_Bias'
   *  Inport: '<Root>/IMU1'
   *  SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn3'
   */
  rtb_Product3_eb = INS_U.IMU1.gyr_x - INS_PARAM.GyroBias[0];
  rtb_Max_c = INS_U.IMU1.gyr_y - INS_PARAM.GyroBias[1];
  rtb_Product15 = INS_U.IMU1.gyr_z - INS_PARAM.GyroBias[2];

  /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In1' incorporates:
   *  Inport: '<Root>/IMU1'
   */
  rtb_VectorConcatenate[0] = INS_U.IMU1.acc_x;

  /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Inport: '<Root>/IMU1'
   */
  rtb_VectorConcatenate[1] = INS_U.IMU1.acc_y;

  /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Inport: '<Root>/IMU1'
   */
  rtb_VectorConcatenate[2] = INS_U.IMU1.acc_z;
  for (i = 0; i < 3; i++) {
    /* Product: '<S179>/Product1' incorporates:
     *  Constant: '<S179>/Gyr_RotMatrix'
     */
    rtb_Product12_k = INS_PARAM.GyroRotMat[i + 6] * rtb_Product15 +
      (INS_PARAM.GyroRotMat[i + 3] * rtb_Max_c + INS_PARAM.GyroRotMat[i] *
       rtb_Product3_eb);

    /* Logic: '<S183>/AND' incorporates:
     *  Constant: '<S183>/Lower Limit'
     *  Constant: '<S183>/Upper Limit'
     *  RelationalOperator: '<S183>/Lower Test'
     *  RelationalOperator: '<S183>/Upper Test'
     */
    rtb_AND[i] = ((INS_P.IMU1_Valid_Check_gyr_min < rtb_Product12_k) &&
                  (rtb_Product12_k < INS_P.IMU1_Valid_Check_gyr_max));

    /* Sum: '<S178>/Subtract1' incorporates:
     *  Constant: '<S178>/Acc_Bias'
     */
    rtb_VectorConcatenate_o[i] = rtb_VectorConcatenate[i] - INS_PARAM.AccBias[i];

    /* Product: '<S179>/Product1' incorporates:
     *  Constant: '<S179>/Gyr_RotMatrix'
     */
    rtb_bias_g_correction_f[i] = rtb_Product12_k;
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S178>/Product5' incorporates:
     *  Constant: '<S178>/Acc_RotMatrix'
     */
    rtb_Product9_g = INS_PARAM.AccRotMat[i + 6] * rtb_VectorConcatenate_o[2] +
      (INS_PARAM.AccRotMat[i + 3] * rtb_VectorConcatenate_o[1] +
       INS_PARAM.AccRotMat[i] * rtb_VectorConcatenate_o[0]);

    /* Logic: '<S182>/AND' incorporates:
     *  Constant: '<S182>/Lower Limit'
     *  Constant: '<S182>/Upper Limit'
     *  RelationalOperator: '<S182>/Lower Test'
     *  RelationalOperator: '<S182>/Upper Test'
     */
    rtb_AND_lx[i] = ((INS_P.IMU1_Valid_Check_acc_min < rtb_Product9_g) &&
                     (rtb_Product9_g < INS_P.IMU1_Valid_Check_acc_max));

    /* Product: '<S178>/Product5' incorporates:
     *  Constant: '<S178>/Acc_RotMatrix'
     */
    rtb_Sum2_g[i] = rtb_Product9_g;
  }

  /* DiscreteIntegrator: '<S174>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/IMU1'
   *  RelationalOperator: '<S181>/FixPt Relational Operator'
   *  UnitDelay: '<S181>/Delay Input1'
   */
  if (INS_U.IMU1.timestamp != INS_DWork.DelayInput1_DSTATE) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l =
      INS_P.DiscreteTimeIntegrator_IC_b;
  }

  /* Logic: '<S174>/Logical Operator4' incorporates:
   *  Constant: '<S180>/Constant'
   *  DiscreteIntegrator: '<S174>/Discrete-Time Integrator'
   *  Logic: '<S174>/Logical Operator'
   *  Logic: '<S174>/Logical Operator1'
   *  Logic: '<S174>/Logical Operator2'
   *  RelationalOperator: '<S180>/Compare'
   */
  rtb_Memory_ph = (rtb_AND[0] && rtb_AND[1] && rtb_AND[2] && (rtb_AND_lx[0] &&
    rtb_AND_lx[1] && rtb_AND_lx[2]) &&
                   (INS_DWork.DiscreteTimeIntegrator_DSTATE_l <
                    INS_P.IMU1_Valid_Check_timeout));

  /* Sum: '<S185>/Subtract' incorporates:
   *  Constant: '<S185>/Gyro_Bias'
   *  Inport: '<Root>/IMU2'
   *  SignalConversion: '<S175>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S175>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S175>/ConcatBufferAtVector ConcatenateIn3'
   */
  rtb_Max_c = INS_U.IMU2.gyr_x - INS_PARAM.GyroBias2[0];
  rtb_Product15 = INS_U.IMU2.gyr_y - INS_PARAM.GyroBias2[1];
  rtb_Product12_k = INS_U.IMU2.gyr_z - INS_PARAM.GyroBias2[2];

  /* SignalConversion: '<S175>/ConcatBufferAtVector Concatenate1In1' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  rtb_VectorConcatenate_o[0] = INS_U.IMU2.acc_x;

  /* SignalConversion: '<S175>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  rtb_VectorConcatenate_o[1] = INS_U.IMU2.acc_y;

  /* SignalConversion: '<S175>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  rtb_VectorConcatenate_o[2] = INS_U.IMU2.acc_z;
  for (i = 0; i < 3; i++) {
    /* Product: '<S185>/Product1' incorporates:
     *  Constant: '<S185>/Gyr_RotMatrix'
     */
    rtb_Product3_eb = INS_PARAM.GyroRotMat2[i + 6] * rtb_Product12_k +
      (INS_PARAM.GyroRotMat2[i + 3] * rtb_Product15 + INS_PARAM.GyroRotMat2[i] *
       rtb_Max_c);

    /* Logic: '<S189>/AND' incorporates:
     *  Constant: '<S189>/Lower Limit'
     *  Constant: '<S189>/Upper Limit'
     *  RelationalOperator: '<S189>/Lower Test'
     *  RelationalOperator: '<S189>/Upper Test'
     */
    rtb_AND[i] = ((INS_P.IMU2_Valid_Check_gyr_min < rtb_Product3_eb) &&
                  (rtb_Product3_eb < INS_P.IMU2_Valid_Check_gyr_max));

    /* Sum: '<S184>/Subtract1' incorporates:
     *  Constant: '<S184>/Acc_Bias'
     */
    rtb_Multiply[i] = rtb_VectorConcatenate_o[i] - INS_PARAM.AccBias2[i];

    /* Product: '<S185>/Product1' incorporates:
     *  Constant: '<S185>/Gyr_RotMatrix'
     */
    rtb_VectorConcatenate[i] = rtb_Product3_eb;
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S184>/Product5' incorporates:
     *  Constant: '<S184>/Acc_RotMatrix'
     */
    rtb_Product3_eb = INS_PARAM.AccRotMat2[i + 6] * rtb_Multiply[2] +
      (INS_PARAM.AccRotMat2[i + 3] * rtb_Multiply[1] + INS_PARAM.AccRotMat2[i] *
       rtb_Multiply[0]);

    /* Logic: '<S188>/AND' incorporates:
     *  Constant: '<S188>/Lower Limit'
     *  Constant: '<S188>/Upper Limit'
     *  RelationalOperator: '<S188>/Lower Test'
     *  RelationalOperator: '<S188>/Upper Test'
     */
    rtb_AND_lx[i] = ((INS_P.IMU2_Valid_Check_acc_min < rtb_Product3_eb) &&
                     (rtb_Product3_eb < INS_P.IMU2_Valid_Check_acc_max));

    /* Product: '<S184>/Product5' incorporates:
     *  Constant: '<S184>/Acc_RotMatrix'
     */
    rtb_DiscreteTimeIntegrator1_g[i] = rtb_Product3_eb;
  }

  /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/IMU2'
   *  RelationalOperator: '<S187>/FixPt Relational Operator'
   *  UnitDelay: '<S187>/Delay Input1'
   */
  if (INS_U.IMU2.timestamp != INS_DWork.DelayInput1_DSTATE_h) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_IC_p;
  }

  /* Sum: '<S193>/Sum' incorporates:
   *  Constant: '<S186>/Constant'
   *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator'
   *  Gain: '<S193>/Gain'
   *  Logic: '<S176>/Logical Operator'
   *  Logic: '<S176>/Logical Operator1'
   *  Logic: '<S176>/Logical Operator2'
   *  Logic: '<S176>/Logical Operator4'
   *  RelationalOperator: '<S186>/Compare'
   */
  rtb_Sum_na = (uint8_T)((uint32_T)(rtb_AND[0] && rtb_AND[1] && rtb_AND[2] &&
    (rtb_AND_lx[0] && rtb_AND_lx[1] && rtb_AND_lx[2]) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_d < INS_P.IMU2_Valid_Check_timeout)
    ? (int32_T)((uint32_T)INS_P.Gain_Gain_od >> 6) : 0) + rtb_Memory_ph);

  /* RelationalOperator: '<S191>/Compare' incorporates:
   *  Constant: '<S191>/Constant'
   */
  rtb_Compare_h2 = (rtb_Sum_na > INS_P.Constant_Value_jn);

  /* Switch: '<S192>/Switch1' */
  if (rtb_Memory_ph) {
    rtb_VectorConcatenate_o[0] = rtb_Sum2_g[0];
    rtb_VectorConcatenate_o[1] = rtb_Sum2_g[1];
    rtb_VectorConcatenate_o[2] = rtb_Sum2_g[2];
  } else {
    rtb_VectorConcatenate_o[0] = rtb_DiscreteTimeIntegrator1_g[0];
    rtb_VectorConcatenate_o[1] = rtb_DiscreteTimeIntegrator1_g[1];
    rtb_VectorConcatenate_o[2] = rtb_DiscreteTimeIntegrator1_g[2];
  }

  /* End of Switch: '<S192>/Switch1' */

  /* DiscreteIntegrator: '<S195>/Discrete-Time Integrator1' */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] = rtb_VectorConcatenate_o[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] = rtb_VectorConcatenate_o[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] = rtb_VectorConcatenate_o[2];
  }

  /* Sqrt: '<S32>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
   *  Math: '<S37>/Square'
   *  Sqrt: '<S66>/Sqrt'
   *  Sum: '<S37>/Sum of Elements'
   */
  rtb_Product3_j_tmp = sqrtf((INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] *
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] +
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] *
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1]) +
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] *
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2]);

  /* Sum: '<S31>/Add' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Lower Limit'
   *  Constant: '<S30>/Upper Limit'
   *  Delay: '<S31>/Delay'
   *  Logic: '<S11>/Logical Operator1'
   *  Logic: '<S30>/AND'
   *  Math: '<S38>/Square'
   *  Memory: '<S5>/Memory1'
   *  Memory: '<S5>/Memory2'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S30>/Lower Test'
   *  RelationalOperator: '<S30>/Upper Test'
   *  Sqrt: '<S32>/Sqrt'
   *  Sqrt: '<S33>/Sqrt'
   *  Sum: '<S38>/Sum of Elements'
   */
  rtb_Add_kz = (uint16_T)((uint32_T)(rtb_Compare_h2 &&
    INS_DWork.Memory2_PreviousInput_l && ((INS_P.IntervalTest_lowlimit <=
    rtb_Product3_j_tmp) && (rtb_Product3_j_tmp <= INS_P.IntervalTest_uplimit)) &&
    (sqrtf((INS_DWork.Memory1_PreviousInput[0] *
            INS_DWork.Memory1_PreviousInput[0] +
            INS_DWork.Memory1_PreviousInput[1] *
            INS_DWork.Memory1_PreviousInput[1]) +
           INS_DWork.Memory1_PreviousInput[2] * INS_DWork.Memory1_PreviousInput
           [2]) > INS_P.CompareToConstant_const_p)) + INS_DWork.Delay_DSTATE_i);

  /* Saturate: '<S31>/Saturation' */
  if (rtb_Add_kz > INS_P.Saturation_UpperSat_k5) {
    rtb_Add_i = INS_P.Saturation_UpperSat_k5;
  } else if (rtb_Add_kz < INS_P.Saturation_LowerSat_hb) {
    rtb_Add_i = INS_P.Saturation_LowerSat_hb;
  } else {
    rtb_Add_i = rtb_Add_kz;
  }

  /* End of Saturate: '<S31>/Saturation' */

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S35>/Compare'
   */
  rtb_LowerTest_b = ((rtb_Add_i > INS_P.Initwith50validsamples_const) > (int32_T)
                     INS_P.Constant_Value_af);

  /* Logic: '<S11>/Logical Operator' incorporates:
   *  Inport: '<Root>/reset'
   *  RelationalOperator: '<S34>/FixPt Relational Operator'
   *  UnitDelay: '<S34>/Delay Input1'
   */
  rtb_UpperTest_g = (((int32_T)rtb_LowerTest_b > (int32_T)
                      INS_DWork.DelayInput1_DSTATE_p) || (INS_U.reset != 0));

  /* Outputs for Enabled SubSystem: '<S5>/Attitude_Init' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtb_UpperTest_g) {
    /* Gain: '<S8>/Gain' incorporates:
     *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
     */
    rtb_DiscreteTimeIntegrator1_g[0] = INS_P.Gain_Gain_d *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[0];
    rtb_DiscreteTimeIntegrator1_g[1] = INS_P.Gain_Gain_d *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[1];
    rtb_DiscreteTimeIntegrator1_g[2] = INS_P.Gain_Gain_d *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[2];

    /* Sum: '<S13>/Subtract1' incorporates:
     *  Memory: '<S5>/Memory1'
     *  Product: '<S13>/Product2'
     *  Product: '<S13>/Product3'
     */
    rtb_Product8_n = rtb_DiscreteTimeIntegrator1_g[2] *
      INS_DWork.Memory1_PreviousInput[0] - rtb_DiscreteTimeIntegrator1_g[0] *
      INS_DWork.Memory1_PreviousInput[2];

    /* Sum: '<S13>/Subtract2' incorporates:
     *  Memory: '<S5>/Memory1'
     *  Product: '<S13>/Product4'
     *  Product: '<S13>/Product5'
     */
    rtb_Product3_eb = rtb_DiscreteTimeIntegrator1_g[0] *
      INS_DWork.Memory1_PreviousInput[1] - rtb_DiscreteTimeIntegrator1_g[1] *
      INS_DWork.Memory1_PreviousInput[0];

    /* Sum: '<S13>/Subtract' incorporates:
     *  Memory: '<S5>/Memory1'
     *  Product: '<S13>/Product'
     *  Product: '<S13>/Product1'
     */
    rtb_h_R_quality = rtb_DiscreteTimeIntegrator1_g[1] *
      INS_DWork.Memory1_PreviousInput[2] - rtb_DiscreteTimeIntegrator1_g[2] *
      INS_DWork.Memory1_PreviousInput[1];

    /* SignalConversion: '<S22>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
     *  Product: '<S12>/Product'
     *  Product: '<S12>/Product1'
     *  Product: '<S12>/Product2'
     *  Product: '<S12>/Product3'
     *  Product: '<S12>/Product4'
     *  Product: '<S12>/Product5'
     *  Sum: '<S12>/Subtract'
     *  Sum: '<S12>/Subtract1'
     *  Sum: '<S12>/Subtract2'
     */
    rtb_Sum2_g[0] = rtb_Product8_n * rtb_DiscreteTimeIntegrator1_g[2] -
      rtb_Product3_eb * rtb_DiscreteTimeIntegrator1_g[1];
    rtb_Sum2_g[1] = rtb_Product3_eb * rtb_DiscreteTimeIntegrator1_g[0] -
      rtb_h_R_quality * rtb_DiscreteTimeIntegrator1_g[2];
    rtb_Sum2_g[2] = rtb_h_R_quality * rtb_DiscreteTimeIntegrator1_g[1] -
      rtb_Product8_n * rtb_DiscreteTimeIntegrator1_g[0];

    /* MinMax: '<S15>/Max' incorporates:
     *  Constant: '<S15>/Constant2'
     *  Math: '<S22>/Math Function'
     *  Sqrt: '<S22>/Sqrt'
     *  Sum: '<S22>/Sum of Elements'
     */
    rtb_Max_c = fmaxf(sqrtf((rtb_Sum2_g[0] * rtb_Sum2_g[0] + rtb_Sum2_g[1] *
      rtb_Sum2_g[1]) + rtb_Sum2_g[2] * rtb_Sum2_g[2]), INS_P.Constant2_Value);

    /* Product: '<S15>/Divide' */
    rtb_VectorConcatenate_l[0] = rtb_Sum2_g[0] / rtb_Max_c;
    rtb_VectorConcatenate_l[1] = rtb_Sum2_g[1] / rtb_Max_c;
    rtb_VectorConcatenate_l[2] = rtb_Sum2_g[2] / rtb_Max_c;

    /* SignalConversion: '<S23>/TmpSignal ConversionAtMath FunctionInport1' */
    rtb_Sum2_g[2] = rtb_Product3_eb;

    /* MinMax: '<S16>/Max' incorporates:
     *  Constant: '<S16>/Constant2'
     *  Math: '<S23>/Math Function'
     *  SignalConversion: '<S23>/TmpSignal ConversionAtMath FunctionInport1'
     *  Sqrt: '<S23>/Sqrt'
     *  Sum: '<S23>/Sum of Elements'
     */
    rtb_Product3_eb = fmaxf(sqrtf((rtb_h_R_quality * rtb_h_R_quality +
      rtb_Product8_n * rtb_Product8_n) + rtb_Product3_eb * rtb_Product3_eb),
      INS_P.Constant2_Value_m);

    /* Product: '<S16>/Divide' incorporates:
     *  SignalConversion: '<S23>/TmpSignal ConversionAtMath FunctionInport1'
     */
    rtb_VectorConcatenate_l[3] = rtb_h_R_quality / rtb_Product3_eb;
    rtb_VectorConcatenate_l[4] = rtb_Product8_n / rtb_Product3_eb;
    rtb_VectorConcatenate_l[5] = rtb_Sum2_g[2] / rtb_Product3_eb;

    /* MinMax: '<S17>/Max' incorporates:
     *  Constant: '<S17>/Constant2'
     *  Math: '<S24>/Math Function'
     *  Sqrt: '<S24>/Sqrt'
     *  Sum: '<S24>/Sum of Elements'
     */
    rtb_Product3_eb = fmaxf(sqrtf((rtb_DiscreteTimeIntegrator1_g[0] *
      rtb_DiscreteTimeIntegrator1_g[0] + rtb_DiscreteTimeIntegrator1_g[1] *
      rtb_DiscreteTimeIntegrator1_g[1]) + rtb_DiscreteTimeIntegrator1_g[2] *
      rtb_DiscreteTimeIntegrator1_g[2]), INS_P.Constant2_Value_g);

    /* Product: '<S17>/Divide' */
    rtb_VectorConcatenate_l[6] = rtb_DiscreteTimeIntegrator1_g[0] /
      rtb_Product3_eb;
    rtb_VectorConcatenate_l[7] = rtb_DiscreteTimeIntegrator1_g[1] /
      rtb_Product3_eb;
    rtb_VectorConcatenate_l[8] = rtb_DiscreteTimeIntegrator1_g[2] /
      rtb_Product3_eb;

    /* Math: '<S8>/Math Function' */
    for (i = 0; i < 3; i++) {
      rtb_M_OB[3 * i] = rtb_VectorConcatenate_l[i];
      rtb_M_OB[1 + 3 * i] = rtb_VectorConcatenate_l[i + 3];
      rtb_M_OB[2 + 3 * i] = rtb_VectorConcatenate_l[i + 6];
    }

    /* End of Math: '<S8>/Math Function' */

    /* If: '<S14>/If' incorporates:
     *  Selector: '<S14>/Selector'
     *  Selector: '<S14>/Selector1'
     *  Selector: '<S14>/Selector2'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S14>/Sum1'
     *  Sum: '<S14>/Sum2'
     */
    if ((rtb_M_OB[0] + rtb_M_OB[4]) + rtb_M_OB[8] >= 0.0F) {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Sqrt: '<S18>/Sqrt' incorporates:
       *  Constant: '<S18>/Constant'
       *  Constant: '<S18>/Protection'
       *  Gain: '<S18>/Gain'
       *  MinMax: '<S18>/MinMax'
       *  Selector: '<S18>/Selector'
       *  Selector: '<S18>/Selector1'
       *  Selector: '<S18>/Selector2'
       *  Sum: '<S18>/Add'
       */
      rtb_Product3_eb = sqrtf(fmaxf(INS_P.Protection_Value,
        (((INS_P.Constant_Value_i1 + rtb_M_OB[0]) + rtb_M_OB[4]) + rtb_M_OB[8]) *
        INS_P.Gain_Gain_a));

      /* SignalConversion: '<S18>/ConcatBufferAtVector ConcatenateIn1' incorporates:
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       */
      INS_B.OutportBufferForquaternion_0[0] = rtb_Product3_eb;

      /* Product: '<S18>/Divide' incorporates:
       *  Gain: '<S18>/Gain1'
       *  Selector: '<S18>/Selector3'
       *  Selector: '<S18>/Selector4'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S18>/Add1'
       */
      INS_B.OutportBufferForquaternion_0[3] = (rtb_M_OB[1] - rtb_M_OB[3]) *
        INS_P.Gain1_Gain_l / rtb_Product3_eb;

      /* Product: '<S18>/Divide1' incorporates:
       *  Gain: '<S18>/Gain2'
       *  Selector: '<S18>/Selector5'
       *  Selector: '<S18>/Selector6'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S18>/Add2'
       */
      INS_B.OutportBufferForquaternion_0[1] = (rtb_M_OB[5] - rtb_M_OB[7]) *
        INS_P.Gain2_Gain_j / rtb_Product3_eb;

      /* Product: '<S18>/Divide2' incorporates:
       *  Gain: '<S18>/Gain3'
       *  Selector: '<S18>/Selector7'
       *  Selector: '<S18>/Selector8'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S18>/Add3'
       */
      INS_B.OutportBufferForquaternion_0[2] = (rtb_M_OB[6] - rtb_M_OB[2]) *
        INS_P.Gain3_Gain / rtb_Product3_eb;

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
    } else if ((rtb_M_OB[0] - rtb_M_OB[4]) - rtb_M_OB[8] >= 0.0F) {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Sqrt: '<S19>/Sqrt' incorporates:
       *  Constant: '<S19>/Constant'
       *  Constant: '<S19>/Protection'
       *  Gain: '<S19>/Gain'
       *  MinMax: '<S19>/MinMax'
       *  Selector: '<S19>/Selector'
       *  Selector: '<S19>/Selector1'
       *  Selector: '<S19>/Selector2'
       *  Sum: '<S19>/Add'
       */
      rtb_Product3_eb = sqrtf(fmaxf(INS_P.Protection_Value_j,
        (((INS_P.Constant_Value_d + rtb_M_OB[0]) - rtb_M_OB[4]) - rtb_M_OB[8]) *
        INS_P.Gain_Gain_p));

      /* SignalConversion: '<S19>/ConcatBufferAtVector ConcatenateIn2' incorporates:
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       */
      INS_B.OutportBufferForquaternion_0[1] = rtb_Product3_eb;

      /* Product: '<S19>/Divide' incorporates:
       *  Gain: '<S19>/Gain1'
       *  Selector: '<S19>/Selector3'
       *  Selector: '<S19>/Selector4'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S19>/Add1'
       */
      INS_B.OutportBufferForquaternion_0[2] = (rtb_M_OB[3] + rtb_M_OB[1]) *
        INS_P.Gain1_Gain_h / rtb_Product3_eb;

      /* Product: '<S19>/Divide1' incorporates:
       *  Gain: '<S19>/Gain2'
       *  Selector: '<S19>/Selector5'
       *  Selector: '<S19>/Selector6'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S19>/Add2'
       */
      INS_B.OutportBufferForquaternion_0[0] = (rtb_M_OB[5] - rtb_M_OB[7]) *
        INS_P.Gain2_Gain_o / rtb_Product3_eb;

      /* Product: '<S19>/Divide2' incorporates:
       *  Gain: '<S19>/Gain3'
       *  Selector: '<S19>/Selector7'
       *  Selector: '<S19>/Selector8'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S19>/Add3'
       */
      INS_B.OutportBufferForquaternion_0[3] = (rtb_M_OB[6] + rtb_M_OB[2]) *
        INS_P.Gain3_Gain_j / rtb_Product3_eb;

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
    } else if ((rtb_M_OB[4] - rtb_M_OB[0]) - rtb_M_OB[8] >= 0.0F) {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Sqrt: '<S20>/Sqrt1' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Protection'
       *  Gain: '<S20>/Gain4'
       *  MinMax: '<S20>/MinMax1'
       *  Selector: '<S20>/Selector'
       *  Selector: '<S20>/Selector1'
       *  Selector: '<S20>/Selector2'
       *  Sum: '<S20>/Add'
       */
      rtb_Product3_eb = sqrtf(fmaxf(INS_P.Protection_Value_i,
        (((INS_P.Constant_Value_j - rtb_M_OB[0]) + rtb_M_OB[4]) - rtb_M_OB[8]) *
        INS_P.Gain4_Gain));

      /* SignalConversion: '<S20>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       */
      INS_B.OutportBufferForquaternion_0[2] = rtb_Product3_eb;

      /* Product: '<S20>/Divide' incorporates:
       *  Gain: '<S20>/Gain1'
       *  Selector: '<S20>/Selector3'
       *  Selector: '<S20>/Selector4'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S20>/Add1'
       */
      INS_B.OutportBufferForquaternion_0[1] = (rtb_M_OB[3] + rtb_M_OB[1]) *
        INS_P.Gain1_Gain_j / rtb_Product3_eb;

      /* Product: '<S20>/Divide1' incorporates:
       *  Gain: '<S20>/Gain2'
       *  Selector: '<S20>/Selector5'
       *  Selector: '<S20>/Selector6'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S20>/Add2'
       */
      INS_B.OutportBufferForquaternion_0[3] = (rtb_M_OB[7] + rtb_M_OB[5]) *
        INS_P.Gain2_Gain_l / rtb_Product3_eb;

      /* Product: '<S20>/Divide2' incorporates:
       *  Gain: '<S20>/Gain3'
       *  Selector: '<S20>/Selector7'
       *  Selector: '<S20>/Selector8'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S20>/Add3'
       */
      INS_B.OutportBufferForquaternion_0[0] = (rtb_M_OB[6] - rtb_M_OB[2]) *
        INS_P.Gain3_Gain_c / rtb_Product3_eb;

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Sqrt: '<S21>/Sqrt' incorporates:
       *  Constant: '<S21>/Constant'
       *  Constant: '<S21>/Protection'
       *  Gain: '<S21>/Gain'
       *  MinMax: '<S21>/MinMax'
       *  Selector: '<S21>/Selector'
       *  Selector: '<S21>/Selector1'
       *  Selector: '<S21>/Selector2'
       *  Sum: '<S21>/Add'
       */
      rtb_Product3_eb = sqrtf(fmaxf(INS_P.Protection_Value_a,
        (((INS_P.Constant_Value_i0 - rtb_M_OB[0]) - rtb_M_OB[4]) + rtb_M_OB[8]) *
        INS_P.Gain_Gain_c));

      /* SignalConversion: '<S21>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       */
      INS_B.OutportBufferForquaternion_0[3] = rtb_Product3_eb;

      /* Product: '<S21>/Divide' incorporates:
       *  Gain: '<S21>/Gain1'
       *  Selector: '<S21>/Selector3'
       *  Selector: '<S21>/Selector4'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S21>/Add1'
       */
      INS_B.OutportBufferForquaternion_0[0] = (rtb_M_OB[1] - rtb_M_OB[3]) *
        INS_P.Gain1_Gain_k / rtb_Product3_eb;

      /* Product: '<S21>/Divide1' incorporates:
       *  Gain: '<S21>/Gain2'
       *  Selector: '<S21>/Selector5'
       *  Selector: '<S21>/Selector6'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S21>/Add2'
       */
      INS_B.OutportBufferForquaternion_0[2] = (rtb_M_OB[7] + rtb_M_OB[5]) *
        INS_P.Gain2_Gain_ju / rtb_Product3_eb;

      /* Product: '<S21>/Divide2' incorporates:
       *  Gain: '<S21>/Gain3'
       *  Selector: '<S21>/Selector7'
       *  Selector: '<S21>/Selector8'
       *  SignalConversion: '<S8>/OutportBufferForquaternion_0'
       *  Sum: '<S21>/Add3'
       */
      INS_B.OutportBufferForquaternion_0[1] = (rtb_M_OB[6] + rtb_M_OB[2]) *
        INS_P.Gain3_Gain_h / rtb_Product3_eb;

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem3' */
    }

    /* End of If: '<S14>/If' */
  }

  /* End of Outputs for SubSystem: '<S5>/Attitude_Init' */

  /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
  if (INS_DWork.DiscreteTimeIntegrator_IC_LOADI != 0) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      INS_B.OutportBufferForquaternion_0[0];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      INS_B.OutportBufferForquaternion_0[1];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] =
      INS_B.OutportBufferForquaternion_0[2];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3] =
      INS_B.OutportBufferForquaternion_0[3];
  }

  if (rtb_UpperTest_g || (INS_DWork.DiscreteTimeIntegrator_PrevRese != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      INS_B.OutportBufferForquaternion_0[0];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      INS_B.OutportBufferForquaternion_0[1];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] =
      INS_B.OutportBufferForquaternion_0[2];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3] =
      INS_B.OutportBufferForquaternion_0[3];
  }

  /* Sqrt: '<S79>/sqrt' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   *  Product: '<S80>/Product'
   *  Product: '<S80>/Product1'
   *  Product: '<S80>/Product2'
   *  Product: '<S80>/Product3'
   *  Sum: '<S80>/Sum'
   */
  rtb_Product3_eb = sqrtf(((INS_DWork.DiscreteTimeIntegrator_DSTATE[0] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] +
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1]) +
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2]) +
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3]);

  /* Product: '<S78>/Product' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   */
  rtb_Max_c = INS_DWork.DiscreteTimeIntegrator_DSTATE[0] / rtb_Product3_eb;

  /* Product: '<S78>/Product1' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   */
  rtb_Product15 = INS_DWork.DiscreteTimeIntegrator_DSTATE[1] / rtb_Product3_eb;

  /* Product: '<S78>/Product2' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   */
  rtb_Product12_k = INS_DWork.DiscreteTimeIntegrator_DSTATE[2] / rtb_Product3_eb;

  /* Product: '<S78>/Product3' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   */
  rtb_Product3_eb = INS_DWork.DiscreteTimeIntegrator_DSTATE[3] / rtb_Product3_eb;

  /* Product: '<S77>/Product' incorporates:
   *  Product: '<S83>/Product'
   *  SignalConversion: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0'
   */
  rtb_delay_acc_O_idx_0 = rtb_Max_c * rtb_Max_c;
  rtb_delay_acc_O_idx_1 = rtb_Product15 * rtb_Product15;
  rtb_delay_acc_O_idx_2 = rtb_Product12_k * rtb_Product12_k;
  rtb_Sum_j_idx_3 = rtb_Product3_eb * rtb_Product3_eb;

  /* Sum: '<S77>/Add' incorporates:
   *  Product: '<S77>/Product'
   *  Sum: '<S83>/Add'
   */
  rtb_vel_E = ((rtb_delay_acc_O_idx_0 + rtb_delay_acc_O_idx_1) -
               rtb_delay_acc_O_idx_2) - rtb_Sum_j_idx_3;
  rtb_M_OB[0] = rtb_vel_E;

  /* Product: '<S77>/Product1' incorporates:
   *  Product: '<S77>/Product5'
   */
  rtb_Product8_n = rtb_Product15 * rtb_Product12_k;

  /* Product: '<S77>/Product2' incorporates:
   *  Product: '<S77>/Product6'
   */
  rtb_Double1 = rtb_Max_c * rtb_Product3_eb;

  /* Sum: '<S77>/Add1' incorporates:
   *  Product: '<S77>/Product1'
   *  Product: '<S77>/Product2'
   *  Sum: '<S83>/Add1'
   */
  rtb_Double = rtb_Product8_n + rtb_Double1;

  /* Gain: '<S77>/Gain' incorporates:
   *  Sum: '<S77>/Add1'
   */
  rtb_M_OB[1] = rtb_Double * INS_P.Gain_Gain_f;

  /* Product: '<S77>/Product3' incorporates:
   *  Product: '<S77>/Product9'
   */
  rtb_Relay2 = rtb_Product15 * rtb_Product3_eb;

  /* Product: '<S77>/Product4' incorporates:
   *  Product: '<S77>/Product10'
   */
  rtb_Product9_g = rtb_Max_c * rtb_Product12_k;

  /* Gain: '<S77>/Gain1' incorporates:
   *  Product: '<S77>/Product3'
   *  Product: '<S77>/Product4'
   *  Sum: '<S77>/Add2'
   */
  rtb_M_OB[2] = (rtb_Relay2 - rtb_Product9_g) * INS_P.Gain1_Gain_kf;

  /* Gain: '<S77>/Gain2' incorporates:
   *  Sum: '<S77>/Add3'
   */
  rtb_M_OB[3] = (rtb_Product8_n - rtb_Double1) * INS_P.Gain2_Gain_oj;

  /* Sum: '<S77>/Add5' incorporates:
   *  Product: '<S77>/Product'
   *  Sum: '<S77>/Add8'
   */
  rtb_Product8_n = rtb_delay_acc_O_idx_0 - rtb_delay_acc_O_idx_1;
  rtb_M_OB[4] = (rtb_Product8_n + rtb_delay_acc_O_idx_2) - rtb_Sum_j_idx_3;

  /* Product: '<S77>/Product7' incorporates:
   *  Product: '<S77>/Product12'
   */
  rtb_Double1 = rtb_Product12_k * rtb_Product3_eb;

  /* Product: '<S77>/Product8' incorporates:
   *  Product: '<S77>/Product11'
   */
  rtb_gps_pos_bias_idx_1 = rtb_Max_c * rtb_Product15;

  /* Gain: '<S77>/Gain3' incorporates:
   *  Product: '<S77>/Product7'
   *  Product: '<S77>/Product8'
   *  Sum: '<S77>/Add4'
   */
  rtb_M_OB[5] = (rtb_Double1 + rtb_gps_pos_bias_idx_1) * INS_P.Gain3_Gain_d;

  /* Gain: '<S77>/Gain4' incorporates:
   *  Sum: '<S77>/Add6'
   */
  rtb_M_OB[6] = (rtb_Relay2 + rtb_Product9_g) * INS_P.Gain4_Gain_o;

  /* Gain: '<S77>/Gain5' incorporates:
   *  Sum: '<S77>/Add7'
   */
  rtb_M_OB[7] = (rtb_Double1 - rtb_gps_pos_bias_idx_1) * INS_P.Gain5_Gain;

  /* Sum: '<S77>/Add8' incorporates:
   *  Product: '<S77>/Product'
   */
  rtb_M_OB[8] = (rtb_Product8_n - rtb_delay_acc_O_idx_2) + rtb_Sum_j_idx_3;
  for (i = 0; i < 3; i++) {
    /* Math: '<S72>/Transpose2' incorporates:
     *  Math: '<S205>/Math Function1'
     *  Switch: '<S205>/Switch'
     */
    rtb_Transpose2_tmp[3 * i] = rtb_M_OB[i];
    rtb_Transpose2_tmp[1 + 3 * i] = rtb_M_OB[i + 3];
    rtb_Transpose2_tmp[2 + 3 * i] = rtb_M_OB[i + 6];

    /* Switch: '<S192>/Switch' */
    if (rtb_Memory_ph) {
      rtb_DiscreteTimeIntegrator1_g[i] = rtb_bias_g_correction_f[i];
    } else {
      rtb_DiscreteTimeIntegrator1_g[i] = rtb_VectorConcatenate[i];
    }

    /* End of Switch: '<S192>/Switch' */
  }

  /* Trigonometry: '<S81>/Trigonometric Function1' incorporates:
   *  Math: '<S72>/Transpose2'
   */
  rtb_Product3_p = atan2f(rtb_Transpose2_tmp[7], rtb_Transpose2_tmp[8]);

  /* Gain: '<S81>/Gain5' incorporates:
   *  Math: '<S72>/Transpose2'
   */
  rtb_delay_acc_O_idx_2 = INS_P.Gain5_Gain_d * rtb_Transpose2_tmp[6];

  /* Saturate: '<S81>/Saturation1' */
  if (rtb_delay_acc_O_idx_2 > INS_P.Saturation1_UpperSat_o) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation1_UpperSat_o;
  } else {
    if (rtb_delay_acc_O_idx_2 < INS_P.Saturation1_LowerSat_b) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation1_LowerSat_b;
    }
  }

  /* End of Saturate: '<S81>/Saturation1' */

  /* Trigonometry: '<S81>/Trigonometric Function' */
  if (rtb_delay_acc_O_idx_2 > 1.0F) {
    rtb_delay_acc_O_idx_2 = 1.0F;
  } else {
    if (rtb_delay_acc_O_idx_2 < -1.0F) {
      rtb_delay_acc_O_idx_2 = -1.0F;
    }
  }

  rtb_Product8_n = asinf(rtb_delay_acc_O_idx_2);

  /* End of Trigonometry: '<S81>/Trigonometric Function' */

  /* Trigonometry: '<S83>/Trigonometric Function1' incorporates:
   *  Gain: '<S83>/Gain'
   */
  rtb_Product1_l5 = atan2f(rtb_Double * INS_P.Gain_Gain_h, rtb_vel_E);

  /* DiscreteIntegrator: '<S194>/Discrete-Time Integrator1' */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[0] =
      rtb_DiscreteTimeIntegrator1_g[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[1] =
      rtb_DiscreteTimeIntegrator1_g[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[2] =
      rtb_DiscreteTimeIntegrator1_g[2];
  }

  /* Sum: '<S73>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S194>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   */
  rtb_VectorConcatenate[0] = INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] +
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[0];
  rtb_VectorConcatenate[1] = INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] +
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[1];
  rtb_VectorConcatenate[2] = INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] +
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[2];

  /* RelationalOperator: '<S170>/Compare' incorporates:
   *  Constant: '<S170>/Constant'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  rtb_Compare_p1 = (INS_DWork.UnitDelay_DSTATE >= INS_P.CompareToConstant3_const);

  /* RelationalOperator: '<S168>/Compare' incorporates:
   *  Constant: '<S168>/Constant'
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Compare_ou = (uint8_T)(INS_U.GPS_uBlox.fixType ==
    INS_P.CompareToConstant1_const_n);

  /* DiscreteIntegrator: '<S166>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   *  RelationalOperator: '<S171>/FixPt Relational Operator'
   *  UnitDelay: '<S171>/Delay Input1'
   */
  if (INS_U.GPS_uBlox.timestamp != INS_DWork.DelayInput1_DSTATE_i) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_po;
  }

  /* RelationalOperator: '<S169>/Compare' incorporates:
   *  Constant: '<S169>/Constant'
   *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator'
   */
  rtb_Compare_iu = (uint8_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
    INS_P.CompareToConstant2_const_a);

  /* Sum: '<S163>/Sum1' incorporates:
   *  Logic: '<S163>/Logical Operator1'
   */
  rtb_Compare_hd = (uint8_T)((uint32_T)(rtb_Compare_p1 && (rtb_Compare_ou != 0) &&
    (rtb_Compare_iu != 0)) + rtb_Compare_p1);

  /* RelationalOperator: '<S157>/Compare' incorporates:
   *  Constant: '<S157>/Constant'
   */
  rtb_Compare_p1 = (rtb_Compare_hd < INS_P.CompareToConstant1_const_l);

  /* Logic: '<S329>/Logical Operator' */
  rtb_GPS_vaid = !rtb_Compare_p1;

  /* RelationalOperator: '<S162>/Compare' incorporates:
   *  Constant: '<S162>/Constant'
   *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator'
   */
  rtb_Memory_ph = (INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
                   INS_P.CompareToConstant4_const);

  /* RelationalOperator: '<S161>/Compare' incorporates:
   *  Constant: '<S161>/Constant'
   */
  rtb_LogicalOperator_mt = (rtb_Compare_hd > INS_P.CompareToConstant2_const_b);

  /* Gain: '<S165>/Gain3' incorporates:
   *  Constant: '<S165>/Constant7'
   *  Gain: '<S165>/Gain5'
   *  Inport: '<Root>/GPS_uBlox'
   *  Sum: '<S165>/Sum'
   */
  rtb_delay_acc_O_idx_2 = (INS_P.Constant7_Value - (real32_T)INS_P.Gain5_Gain_a *
    4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.sAcc) * INS_P.Gain3_Gain_l;

  /* Product: '<S158>/Double' incorporates:
   *  Saturate: '<S158>/Saturation'
   */
  rtb_Double = rtb_LogicalOperator_mt ? rtb_Memory_ph ? rtb_delay_acc_O_idx_2 >
    INS_P.Saturation_UpperSat_l ? INS_P.Saturation_UpperSat_l :
    rtb_delay_acc_O_idx_2 < INS_P.Saturation_LowerSat_k ?
    INS_P.Saturation_LowerSat_k : rtb_delay_acc_O_idx_2 : 0.0F : 0.0F;

  /* Gain: '<S164>/Gain2' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Gain: '<S164>/Gain1'
   *  Inport: '<Root>/GPS_uBlox'
   *  Sum: '<S164>/Sum1'
   */
  rtb_delay_acc_O_idx_2 = (INS_P.Constant1_Value_g - (real32_T)
    INS_P.Gain1_Gain_p * 4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.hAcc) *
    INS_P.Gain2_Gain_p;

  /* Product: '<S158>/Double1' incorporates:
   *  Saturate: '<S158>/Saturation1'
   */
  rtb_Double1 = rtb_LogicalOperator_mt ? rtb_Memory_ph ? rtb_delay_acc_O_idx_2 >
    INS_P.Saturation1_UpperSat_m ? INS_P.Saturation1_UpperSat_m :
    rtb_delay_acc_O_idx_2 < INS_P.Saturation1_LowerSat_d ?
    INS_P.Saturation1_LowerSat_d : rtb_delay_acc_O_idx_2 : 0.0F : 0.0F;

  /* RelationalOperator: '<S311>/Compare' incorporates:
   *  Constant: '<S309>/Constant'
   *  Constant: '<S310>/Constant'
   *  Constant: '<S311>/Constant'
   *  Logic: '<S307>/Logical Operator'
   *  MinMax: '<S307>/Max'
   *  RelationalOperator: '<S309>/Compare'
   *  RelationalOperator: '<S310>/Compare'
   */
  rtb_Compare_nt = ((rtb_GPS_vaid && ((rtb_Double > INS_P.Constant_Value_ab) ||
    (rtb_Double1 > INS_P.Constant_Value_m))) > (int32_T)INS_P.Constant_Value_c);

  /* Logic: '<S320>/Logical Operator' incorporates:
   *  Constant: '<S322>/Constant'
   *  RelationalOperator: '<S322>/Compare'
   */
  rtb_LogicalOperator_l4 = (rtb_GPS_vaid && (rtb_Double1 >
    INS_P.Constant_Value_o));

  /* DiscreteIntegrator: '<S216>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   *  RelationalOperator: '<S218>/FixPt Relational Operator'
   *  UnitDelay: '<S218>/Delay Input1'
   */
  if (INS_U.Optical_Flow.timestamp_ms != INS_DWork.DelayInput1_DSTATE_l) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nz =
      INS_P.DiscreteTimeIntegrator_IC_g;
  }

  /* Logic: '<S216>/Logical Operator' incorporates:
   *  Constant: '<S217>/Constant'
   *  DiscreteIntegrator: '<S216>/Discrete-Time Integrator'
   *  Inport: '<Root>/Optical_Flow'
   *  RelationalOperator: '<S217>/Compare'
   */
  rtb_LogicalOperator_mt = ((INS_DWork.DiscreteTimeIntegrator_DSTAT_nz <
    INS_P.CompareToConstant4_const_k) && (INS_U.Optical_Flow.valid != 0U));

  /* RelationalOperator: '<S299>/Compare' incorporates:
   *  Constant: '<S299>/Constant'
   *  Logic: '<S320>/Logical Operator1'
   */
  rtb_Compare_e = ((rtb_LogicalOperator_l4 || rtb_LogicalOperator_mt) > (int32_T)
                   INS_P.Constant_Value_gn);

  /* Logic: '<S295>/Logical Operator2' incorporates:
   *  Inport: '<Root>/reset'
   *  RelationalOperator: '<S298>/FixPt Relational Operator'
   *  UnitDelay: '<S298>/Delay Input1'
   */
  rtb_Memory_ph = (((int32_T)rtb_Compare_e > (int32_T)
                    INS_DWork.DelayInput1_DSTATE_o) || (INS_U.reset != 0));

  /* Gain: '<S159>/Scalefactor1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor1 = (real_T)INS_P.Scalefactor1_Gain_d * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lat;

  /* Gain: '<S159>/Scalefactor2' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor2 = (real_T)INS_P.Scalefactor2_Gain * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lon;

  /* Gain: '<S159>/Scalefactor3' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor3 = (real_T)INS_P.Scalefactor3_Gain * 9.0949470177292824E-13 *
    (real_T)INS_U.GPS_uBlox.height;

  /* RelationalOperator: '<S156>/Compare' incorporates:
   *  Constant: '<S156>/Constant'
   */
  rtb_Compare_a = (rtb_Compare_hd > INS_P.CompareToConstant_const_i);

  /* Outputs for Triggered SubSystem: '<S137>/WGS_Derivative' incorporates:
   *  TriggerPort: '<S160>/Trigger'
   */
  if (rtb_Compare_a && (INS_PrevZCSigState.WGS_Derivative_Trig_ZCE != POS_ZCSIG))
  {
    /* Gain: '<S160>/Scalefactor' */
    INS_B.Scalefactor = INS_P.Scalefactor_Gain * rtb_Scalefactor2;

    /* SignalConversion: '<S160>/OutportBufferFordz_dh' incorporates:
     *  Constant: '<S172>/constant1'
     */
    INS_B.dz_dh = INS_P.constant1_Value;

    /* Gain: '<S160>/Scalefactor1' */
    INS_B.Scalefactor1 = INS_P.Scalefactor1_Gain * rtb_Scalefactor1;

    /* Trigonometry: '<S172>/Trigonometric Function1' incorporates:
     *  Trigonometry: '<S172>/Trigonometric Function2'
     */
    rtb_WGS84_derivatives_ref_idx_0 = cos(INS_B.Scalefactor1);

    /* Product: '<S172>/Product1' incorporates:
     *  Constant: '<S172>/constant'
     *  Constant: '<S172>/f'
     *  Sum: '<S172>/Subtract1'
     */
    rtb_Gain6 = (INS_P.constant_Value - INS_P.f_Value) * INS_P.f_Value;

    /* Trigonometry: '<S172>/Trigonometric Function' */
    rtb_N = sin(INS_B.Scalefactor1);

    /* Sum: '<S172>/Subtract' incorporates:
     *  Constant: '<S172>/a1'
     *  Math: '<S172>/u^2'
     *  Product: '<S172>/Product'
     */
    rtb_N = INS_P.a1_Value - rtb_N * rtb_N * rtb_Gain6;

    /* Math: '<S172>/sqrt'
     *
     * About '<S172>/sqrt':
     *  Operator: sqrt
     */
    if (rtb_N < 0.0) {
      rtb_N = -sqrt(fabs(rtb_N));
    } else {
      rtb_N = sqrt(rtb_N);
    }

    /* End of Math: '<S172>/sqrt' */

    /* Product: '<S172>/Divide' incorporates:
     *  Constant: '<S172>/a'
     */
    rtb_N = INS_P.a_Value / rtb_N;

    /* Sum: '<S172>/Add' incorporates:
     *  Constant: '<S172>/constant2'
     *  Math: '<S172>/u^1'
     *  Product: '<S172>/Product2'
     *  Product: '<S172>/Product3'
     *  Sum: '<S172>/Subtract2'
     *  Trigonometry: '<S172>/Trigonometric Function1'
     */
    INS_B.Add = (INS_P.constant2_Value - rtb_WGS84_derivatives_ref_idx_0 *
                 rtb_WGS84_derivatives_ref_idx_0 * rtb_Gain6) * rtb_N +
      rtb_Scalefactor3;

    /* Product: '<S172>/Product4' incorporates:
     *  Sum: '<S172>/Add1'
     */
    INS_B.Product4 = (rtb_N + rtb_Scalefactor3) *
      rtb_WGS84_derivatives_ref_idx_0;
  }

  INS_PrevZCSigState.WGS_Derivative_Trig_ZCE = rtb_Compare_a;

  /* End of Outputs for SubSystem: '<S137>/WGS_Derivative' */

  /* RelationalOperator: '<S306>/Compare' incorporates:
   *  Constant: '<S306>/Constant'
   */
  rtb_Compare_a = ((int32_T)rtb_LogicalOperator_l4 > (int32_T)
                   INS_P.Constant_Value_pt);

  /* Switch: '<S302>/Switch5' incorporates:
   *  Memory: '<S302>/memory2'
   *  Memory: '<S302>/memory3'
   *  Memory: '<S4>/Memory'
   *  Product: '<S302>/Divide'
   *  RelationalOperator: '<S305>/FixPt Relational Operator'
   *  Sum: '<S302>/Sum'
   *  Switch: '<S302>/Switch4'
   *  UnitDelay: '<S305>/Delay Input1'
   */
  if ((int32_T)rtb_Compare_a > (int32_T)INS_DWork.DelayInput1_DSTATE_m) {
    rtb_WGS84_derivatives_ref_idx_0 = INS_B.Add;
    rtb_Gain6 = INS_B.Product4;
    rtb_N = rtb_Scalefactor1 - INS_DWork.Memory_9_PreviousInput / INS_B.Add;
    rtb_WGS84_pos_ref_idx_1 = rtb_Scalefactor2 -
      INS_DWork.Memory_10_PreviousInput / INS_B.Product4;
  } else {
    rtb_WGS84_derivatives_ref_idx_0 = INS_DWork.memory3_PreviousInput[0];
    rtb_Gain6 = INS_DWork.memory3_PreviousInput[1];
    rtb_N = INS_DWork.memory2_PreviousInput[0];
    rtb_WGS84_pos_ref_idx_1 = INS_DWork.memory2_PreviousInput[1];
  }

  /* End of Switch: '<S302>/Switch5' */

  /* Gain: '<S159>/Gain' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Product9_g = (real32_T)INS_P.Gain_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velN;

  /* Gain: '<S159>/Gain1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_vel_E = (real32_T)INS_P.Gain1_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velE;

  /* Outputs for Enabled SubSystem: '<S250>/GPS_Vel_Init' incorporates:
   *  EnablePort: '<S252>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S249>/GPS_Pos_Init' incorporates:
   *  EnablePort: '<S251>/Enable'
   */
  if (rtb_GPS_vaid) {
    /* DataTypeConversion: '<S251>/Data Type Conversion' incorporates:
     *  Product: '<S251>/Multiply'
     *  Sum: '<S251>/Sum'
     */
    INS_B.DataTypeConversion[0] = (real32_T)((rtb_Scalefactor1 - rtb_N) *
      rtb_WGS84_derivatives_ref_idx_0);
    INS_B.DataTypeConversion[1] = (real32_T)((rtb_Scalefactor2 -
      rtb_WGS84_pos_ref_idx_1) * rtb_Gain6);

    /* Reshape: '<S252>/Reshape' */
    rtb_vel_NE_0_idx_0 = rtb_Product9_g;
    rtb_vel_NE_0_idx_1 = rtb_vel_E;
  }

  /* End of Outputs for SubSystem: '<S249>/GPS_Pos_Init' */
  /* End of Outputs for SubSystem: '<S250>/GPS_Vel_Init' */

  /* Trigonometry: '<S82>/TrigoFcn1' */
  rtb_h_R_quality = arm_cos_f32(rtb_Product1_l5);

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentateIn1' */
  rtb_VectorConcatenate_l[0] = rtb_h_R_quality;

  /* Trigonometry: '<S82>/TrigoFcn' */
  rtb_Relay2 = arm_sin_f32(rtb_Product1_l5);

  /* Gain: '<S82>/Gain' */
  rtb_VectorConcatenate_l[1] = INS_P.Gain_Gain_i * rtb_Relay2;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_VectorConcatenate_l[2] = INS_P.Constant1_Value_gl;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate2In1' */
  rtb_VectorConcatenate_l[3] = rtb_Relay2;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate2In2' */
  rtb_VectorConcatenate_l[4] = rtb_h_R_quality;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_VectorConcatenate_l[5] = INS_P.Constant1_Value_gl;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate3In1' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_VectorConcatenate_l[6] = INS_P.Constant1_Value_gl;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate3In2' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_VectorConcatenate_l[7] = INS_P.Constant1_Value_gl;

  /* Constant: '<S82>/Constant' */
  rtb_VectorConcatenate_l[8] = INS_P.Constant_Value_ev;

  /* Product: '<S140>/Multiply' incorporates:
   *  Constant: '<S140>/Constant'
   *  Inport: '<Root>/Optical_Flow'
   *  SignalConversion: '<S140>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply[i] = rtb_VectorConcatenate_l[i + 6] * INS_P.Constant_Value_bg +
      (rtb_VectorConcatenate_l[i + 3] * INS_U.Optical_Flow.vel_y_mPs +
       rtb_VectorConcatenate_l[i] * INS_U.Optical_Flow.vel_x_mPs);
  }

  /* End of Product: '<S140>/Multiply' */

  /* Outputs for Enabled SubSystem: '<S250>/OptFlow_Vel_Init' incorporates:
   *  EnablePort: '<S253>/Enable'
   */
  /* Logic: '<S250>/Logical Operator' */
  if (!rtb_GPS_vaid) {
    /* Reshape: '<S253>/Reshape' */
    rtb_vel_NE_0_idx_0 = rtb_Multiply[0];
    rtb_vel_NE_0_idx_1 = rtb_Multiply[1];
  }

  /* End of Logic: '<S250>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S250>/OptFlow_Vel_Init' */

  /* Switch: '<S246>/Switch' incorporates:
   *  Constant: '<S248>/Constant'
   *  Memory: '<S246>/Memory'
   */
  if (rtb_Memory_ph) {
    rtb_Switch_er[0] = INS_B.DataTypeConversion[0];
    rtb_Switch_er[2] = rtb_vel_NE_0_idx_0;
    rtb_Switch_er[4] = INS_P.Constant_Value_b[0];
    rtb_Switch_er[1] = INS_B.DataTypeConversion[1];
    rtb_Switch_er[3] = rtb_vel_NE_0_idx_1;
    rtb_Switch_er[5] = INS_P.Constant_Value_b[1];
  } else {
    rtb_Switch_er[0] = INS_DWork.Memory_PreviousInput[0];
    rtb_Switch_er[2] = INS_DWork.Memory_PreviousInput[2];
    rtb_Switch_er[4] = INS_DWork.Memory_PreviousInput[4];
    rtb_Switch_er[1] = INS_DWork.Memory_PreviousInput[1];
    rtb_Switch_er[3] = INS_DWork.Memory_PreviousInput[3];
    rtb_Switch_er[5] = INS_DWork.Memory_PreviousInput[5];
  }

  /* End of Switch: '<S246>/Switch' */

  /* Product: '<S247>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
   */
  for (i = 0; i < 3; i++) {
    rtb_M_OB_0[i] = rtb_M_OB[i + 6] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[2]
      + (rtb_M_OB[i + 3] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] +
         rtb_M_OB[i] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]);
  }

  /* Gain: '<S247>/Gain' incorporates:
   *  Constant: '<S247>/Constant'
   *  Product: '<S247>/Multiply'
   *  Sum: '<S247>/Add'
   */
  tmp[0] = INS_P.Gain_Gain_ic * rtb_Switch_er[2];
  tmp[2] = (rtb_M_OB_0[0] - rtb_Switch_er[4]) * INS_P.Gain_Gain_ic;
  tmp[4] = INS_P.Gain_Gain_ic * INS_P.Constant_Value_l[0];
  tmp[1] = INS_P.Gain_Gain_ic * rtb_Switch_er[3];
  tmp[3] = (rtb_M_OB_0[1] - rtb_Switch_er[5]) * INS_P.Gain_Gain_ic;
  tmp[5] = INS_P.Gain_Gain_ic * INS_P.Constant_Value_l[1];

  /* Sum: '<S247>/Sum' */
  for (i = 0; i < 6; i++) {
    rtb_Sum_mt[i] = rtb_Switch_er[i] + tmp[i];
  }

  /* End of Sum: '<S247>/Sum' */

  /* Outputs for Enabled SubSystem: '<S234>/GPS_Correct' incorporates:
   *  EnablePort: '<S236>/Enable'
   */
  if (rtb_Compare_nt) {
    /* Delay: '<S240>/x_delay' */
    if (rtb_Memory_ph && (INS_PrevZCSigState.x_delay_Reset_ZCE_b != POS_ZCSIG))
    {
      INS_DWork.icLoad_o = 1U;
    }

    INS_PrevZCSigState.x_delay_Reset_ZCE_b = rtb_Memory_ph;
    if (INS_DWork.icLoad_o != 0) {
      for (i = 0; i < 75; i++) {
        INS_DWork.x_delay_DSTATE_k[i] = rtb_Sum_mt[0];
      }
    }

    /* Delay: '<S240>/x_delay1' */
    if (rtb_Memory_ph && (INS_PrevZCSigState.x_delay1_Reset_ZCE != POS_ZCSIG)) {
      INS_DWork.icLoad_i = 1U;
    }

    INS_PrevZCSigState.x_delay1_Reset_ZCE = rtb_Memory_ph;
    if (INS_DWork.icLoad_i != 0) {
      for (i = 0; i < 75; i++) {
        INS_DWork.x_delay1_DSTATE[i] = rtb_Sum_mt[1];
      }
    }

    /* Delay: '<S240>/vn_delay' */
    if (rtb_Memory_ph && (INS_PrevZCSigState.vn_delay_Reset_ZCE != POS_ZCSIG)) {
      INS_DWork.icLoad_m = 1U;
    }

    INS_PrevZCSigState.vn_delay_Reset_ZCE = rtb_Memory_ph;
    if (INS_DWork.icLoad_m != 0) {
      for (i = 0; i < 50; i++) {
        INS_DWork.vn_delay_DSTATE[i] = rtb_Sum_mt[2];
      }
    }

    /* Delay: '<S240>/vn_delay1' */
    if (rtb_Memory_ph && (INS_PrevZCSigState.vn_delay1_Reset_ZCE != POS_ZCSIG))
    {
      INS_DWork.icLoad_j = 1U;
    }

    INS_PrevZCSigState.vn_delay1_Reset_ZCE = rtb_Memory_ph;
    if (INS_DWork.icLoad_j != 0) {
      for (i = 0; i < 50; i++) {
        INS_DWork.vn_delay1_DSTATE[i] = rtb_Sum_mt[3];
      }
    }

    /* DataTypeConversion: '<S239>/Data Type Conversion' incorporates:
     *  Product: '<S239>/Multiply'
     *  Sum: '<S239>/Sum'
     */
    rtb_vel_NE_0_idx_0 = (real32_T)((rtb_Scalefactor1 - rtb_N) *
      rtb_WGS84_derivatives_ref_idx_0);
    rtb_vel_NE_0_idx_1 = (real32_T)((rtb_Scalefactor2 - rtb_WGS84_pos_ref_idx_1)
      * rtb_Gain6);

    /* RelationalOperator: '<S245>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S245>/Delay Input1'
     */
    rtb_pos_ever_valid_n = (1 > (int32_T)INS_DWork.DelayInput1_DSTATE_gn);

    /* Switch: '<S243>/Switch' incorporates:
     *  DataTypeConversion: '<S239>/Data Type Conversion'
     *  Memory: '<S243>/Memory'
     *  Sum: '<S244>/Sum'
     */
    if (rtb_pos_ever_valid_n) {
      rtb_Relay2 = rtb_Sum_mt[0] - rtb_vel_NE_0_idx_0;
      rtb_gps_pos_bias_idx_1 = rtb_Sum_mt[1] - rtb_vel_NE_0_idx_1;
    } else {
      rtb_Relay2 = INS_DWork.Memory_PreviousInput_d[0];
      rtb_gps_pos_bias_idx_1 = INS_DWork.Memory_PreviousInput_d[1];
    }

    /* End of Switch: '<S243>/Switch' */

    /* Logic: '<S236>/Logical Operator' incorporates:
     *  Inport: '<Root>/GPS_uBlox'
     *  RelationalOperator: '<S237>/FixPt Relational Operator'
     *  UnitDelay: '<S237>/Delay Input1'
     */
    rtb_pos_ever_valid_n = (rtb_pos_ever_valid_n || (INS_U.GPS_uBlox.timestamp
      != INS_DWork.DelayInput1_DSTATE_d0));

    /* Switch: '<S238>/Switch' incorporates:
     *  DataTypeConversion: '<S239>/Data Type Conversion'
     *  Delay: '<S240>/x_delay'
     *  Delay: '<S240>/x_delay1'
     *  Gain: '<S241>/Gain'
     *  Gain: '<S241>/Gain1'
     *  Gain: '<S241>/Gain2'
     *  Memory: '<S238>/Memory'
     *  Sum: '<S236>/Sum'
     *  Sum: '<S242>/Sum1'
     */
    if (rtb_pos_ever_valid_n) {
      /* Sum: '<S236>/Sum' incorporates:
       *  Delay: '<S240>/vn_delay'
       *  Delay: '<S240>/vn_delay1'
       */
      rtb_delay_acc_O_idx_2 = rtb_Product9_g - INS_DWork.vn_delay_DSTATE[0U];
      rtb_Sum_j_idx_3 = rtb_vel_E - INS_DWork.vn_delay1_DSTATE[0U];
      rtb_Switch_er[0] = ((rtb_vel_NE_0_idx_0 + rtb_Relay2) -
                          INS_DWork.x_delay_DSTATE_k[0U]) * INS_P.Gain1_Gain_e;
      rtb_Switch_er[2] = INS_P.Gain_Gain_o * rtb_delay_acc_O_idx_2;
      rtb_Switch_er[4] = INS_P.Gain2_Gain_gd * rtb_delay_acc_O_idx_2;
      rtb_Switch_er[1] = ((rtb_vel_NE_0_idx_1 + rtb_gps_pos_bias_idx_1) -
                          INS_DWork.x_delay1_DSTATE[0U]) * INS_P.Gain1_Gain_e;
      rtb_Switch_er[3] = INS_P.Gain_Gain_o * rtb_Sum_j_idx_3;
      rtb_Switch_er[5] = INS_P.Gain2_Gain_gd * rtb_Sum_j_idx_3;
    } else {
      for (i = 0; i < 6; i++) {
        rtb_Switch_er[i] = INS_DWork.Memory_PreviousInput_h[i];
      }
    }

    /* End of Switch: '<S238>/Switch' */

    /* Sum: '<S236>/Sum1' incorporates:
     *  Gain: '<S238>/Gain3'
     */
    for (i = 0; i < 6; i++) {
      INS_B.Sum1_o[i] = INS_P.Gain3_Gain_o * rtb_Switch_er[i] + rtb_Sum_mt[i];
    }

    /* End of Sum: '<S236>/Sum1' */

    /* Update for UnitDelay: '<S237>/Delay Input1' incorporates:
     *  Inport: '<Root>/GPS_uBlox'
     */
    INS_DWork.DelayInput1_DSTATE_d0 = INS_U.GPS_uBlox.timestamp;

    /* Update for Delay: '<S240>/x_delay' */
    INS_DWork.icLoad_o = 0U;
    for (i = 0; i < 74; i++) {
      INS_DWork.x_delay_DSTATE_k[i] = INS_DWork.x_delay_DSTATE_k[i + 1];

      /* Update for Delay: '<S240>/x_delay1' */
      INS_DWork.x_delay1_DSTATE[i] = INS_DWork.x_delay1_DSTATE[i + 1];
    }

    INS_DWork.x_delay_DSTATE_k[74] = rtb_Sum_mt[0];

    /* End of Update for Delay: '<S240>/x_delay' */

    /* Update for Delay: '<S240>/x_delay1' */
    INS_DWork.icLoad_i = 0U;
    INS_DWork.x_delay1_DSTATE[74] = rtb_Sum_mt[1];

    /* Update for Delay: '<S240>/vn_delay' */
    INS_DWork.icLoad_m = 0U;
    for (i = 0; i < 49; i++) {
      INS_DWork.vn_delay_DSTATE[i] = INS_DWork.vn_delay_DSTATE[i + 1];

      /* Update for Delay: '<S240>/vn_delay1' */
      INS_DWork.vn_delay1_DSTATE[i] = INS_DWork.vn_delay1_DSTATE[i + 1];
    }

    INS_DWork.vn_delay_DSTATE[49] = rtb_Sum_mt[2];

    /* End of Update for Delay: '<S240>/vn_delay' */

    /* Update for Delay: '<S240>/vn_delay1' */
    INS_DWork.icLoad_j = 0U;
    INS_DWork.vn_delay1_DSTATE[49] = rtb_Sum_mt[3];

    /* Update for UnitDelay: '<S245>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_gn = true;

    /* Update for Memory: '<S243>/Memory' */
    INS_DWork.Memory_PreviousInput_d[0] = rtb_Relay2;
    INS_DWork.Memory_PreviousInput_d[1] = rtb_gps_pos_bias_idx_1;

    /* Update for Memory: '<S238>/Memory' */
    for (i = 0; i < 6; i++) {
      INS_DWork.Memory_PreviousInput_h[i] = rtb_Switch_er[i];
    }

    /* End of Update for Memory: '<S238>/Memory' */
  }

  /* End of Outputs for SubSystem: '<S234>/GPS_Correct' */

  /* Switch: '<S234>/Switch' */
  for (i = 0; i < 6; i++) {
    rtb_Relay2 = rtb_Sum_mt[i];
    if (rtb_Compare_nt) {
      rtb_Relay2 = INS_B.Sum1_o[i];
    }

    rtb_Sum_mt[i] = rtb_Relay2;
  }

  /* End of Switch: '<S234>/Switch' */

  /* RelationalOperator: '<S222>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Sonar'
   *  UnitDelay: '<S222>/Delay Input1'
   */
  rtb_Compare_nt = (INS_U.Sonar.timestamp_ms != INS_DWork.DelayInput1_DSTATE_c);

  /* DiscreteIntegrator: '<S219>/Discrete-Time Integrator' */
  if (rtb_Compare_nt) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k =
      INS_P.DiscreteTimeIntegrator_IC_pt;
  }

  /* Logic: '<S219>/Logical Operator' incorporates:
   *  Constant: '<S220>/Constant'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S223>/Lower Limit'
   *  Constant: '<S223>/Upper Limit'
   *  DiscreteIntegrator: '<S219>/Discrete-Time Integrator'
   *  Inport: '<Root>/Sonar'
   *  Logic: '<S223>/AND'
   *  Math: '<S219>/Square'
   *  Math: '<S219>/Square1'
   *  Memory: '<S219>/Memory'
   *  RelationalOperator: '<S220>/Compare'
   *  RelationalOperator: '<S221>/Compare'
   *  RelationalOperator: '<S223>/Lower Test'
   *  RelationalOperator: '<S223>/Upper Test'
   *  Sqrt: '<S219>/Sqrt'
   *  Sum: '<S219>/Add'
   */
  rtb_LogicalOperator_l4 = ((INS_DWork.DiscreteTimeIntegrator_DSTATE_k <
    INS_P.CompareToConstant4_const_h) && (INS_DWork.Memory_PreviousInput_ph != 0)
    && ((INS_P.IntervalTest_lowlimit_d < INS_U.Sonar.distance_m) &&
        (INS_U.Sonar.distance_m <= INS_P.IntervalTest_uplimit_a)) && (sqrtf
    (rtb_Sum_mt[2] * rtb_Sum_mt[2] + rtb_Sum_mt[3] * rtb_Sum_mt[3]) <
    INS_P.CompareToConstant_const_f));

  /* DataTypeConversion: '<S308>/Data Type Conversion1' incorporates:
   *  Constant: '<S312>/Constant'
   *  RelationalOperator: '<S312>/Compare'
   */
  rtb_Sum_j_idx_3 = (real32_T)((int32_T)rtb_LogicalOperator_l4 > (int32_T)
    INS_P.Constant_Value_p2);

  /* Sum: '<S308>/Sum' incorporates:
   *  Constant: '<S312>/Constant'
   *  Constant: '<S314>/Constant'
   *  Constant: '<S315>/Constant'
   *  Logic: '<S308>/Logical Operator'
   *  MinMax: '<S308>/Max'
   *  RelationalOperator: '<S312>/Compare'
   *  RelationalOperator: '<S314>/Compare'
   *  RelationalOperator: '<S315>/Compare'
   */
  rtb_Sum_ly = (rtb_GPS_vaid && ((rtb_Double1 > INS_P.Constant_Value_ek) ||
    (rtb_Double > INS_P.Constant_Value_ao))) - ((int32_T)rtb_LogicalOperator_l4 >
    (int32_T)INS_P.Constant_Value_p2);

  /* Saturate: '<S308>/Saturation' */
  if (rtb_Sum_ly > INS_P.Saturation_UpperSat_c) {
    rtb_Relay2 = INS_P.Saturation_UpperSat_c;
  } else if (rtb_Sum_ly < INS_P.Saturation_LowerSat_pk) {
    rtb_Relay2 = INS_P.Saturation_LowerSat_pk;
  } else {
    rtb_Relay2 = (real32_T)rtb_Sum_ly;
  }

  /* End of Saturate: '<S308>/Saturation' */

  /* RelationalOperator: '<S316>/Compare' incorporates:
   *  Constant: '<S316>/Constant'
   */
  rtb_Compare_f3 = (rtb_Relay2 > INS_P.Constant_Value_h);

  /* Logic: '<S321>/Logical Operator' incorporates:
   *  Constant: '<S323>/Constant'
   *  RelationalOperator: '<S323>/Compare'
   */
  rtb_Memory_ph = (rtb_GPS_vaid && (rtb_Double1 > INS_P.Constant_Value_be));

  /* Logic: '<S145>/Logical Operator' incorporates:
   *  Constant: '<S154>/Lower Limit'
   *  Constant: '<S154>/Upper Limit'
   *  Constant: '<S155>/Lower Limit'
   *  Constant: '<S155>/Upper Limit'
   *  Inport: '<Root>/Barometer'
   *  Logic: '<S154>/AND'
   *  Logic: '<S155>/AND'
   *  RelationalOperator: '<S154>/Lower Test'
   *  RelationalOperator: '<S154>/Upper Test'
   *  RelationalOperator: '<S155>/Lower Test'
   *  RelationalOperator: '<S155>/Upper Test'
   */
  rtb_LogicalOperator_b3 = ((INS_P.Relative_Height_pressure_min <
    INS_U.Barometer.pressure) && (INS_U.Barometer.pressure <
    INS_P.Relative_Height_pressure_max) && ((INS_P.Relative_Height_temp_min <
    INS_U.Barometer.temperature) && (INS_U.Barometer.temperature <
    INS_P.Relative_Height_temp_max)));

  /* RelationalOperator: '<S153>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Barometer'
   *  UnitDelay: '<S153>/Delay Input1'
   */
  rtb_GPS_vaid = (INS_U.Barometer.timestamp != INS_DWork.DelayInput1_DSTATE_g);

  /* Sum: '<S145>/Sum1' incorporates:
   *  Constant: '<S147>/Constant'
   *  Constant: '<S152>/Constant'
   *  Logic: '<S145>/Logical Operator1'
   *  Logic: '<S145>/Logical Operator2'
   *  Logic: '<S145>/Logical Operator5'
   *  Memory: '<S145>/Memory2'
   *  RelationalOperator: '<S147>/Compare'
   *  RelationalOperator: '<S152>/Compare'
   */
  rtb_Sum_ly = (((rtb_LogicalOperator_b3 && rtb_GPS_vaid) ||
                 (INS_DWork.Memory2_PreviousInput > INS_P.Constant_Value_in)) &&
                (INS_DWork.Memory2_PreviousInput <
                 INS_P.CompareToConstant_const_pt));
  qY_0 = rtb_Sum_ly + INS_DWork.Memory2_PreviousInput;
  if (qY_0 < (uint32_T)rtb_Sum_ly) {
    qY_0 = MAX_uint32_T;
  }

  /* DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
  if (rtb_GPS_vaid) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev =
      INS_P.DiscreteTimeIntegrator_IC_dv;
  }

  /* Logic: '<S145>/Logical Operator4' incorporates:
   *  Constant: '<S149>/Constant'
   *  Constant: '<S151>/Constant'
   *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
   *  RelationalOperator: '<S149>/Compare'
   *  RelationalOperator: '<S151>/Compare'
   *  Sum: '<S145>/Sum1'
   */
  rtb_LogicalOperator_b3 = ((qY_0 > INS_P.Relative_Height_s_last) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_ev <
     INS_P.CompareToConstant4_const_i) && rtb_LogicalOperator_b3);

  /* RelationalOperator: '<S297>/Compare' incorporates:
   *  Constant: '<S297>/Constant'
   *  Logic: '<S321>/Logical Operator2'
   */
  rtb_GPS_vaid = ((rtb_Memory_ph || rtb_LogicalOperator_l4 ||
                   rtb_LogicalOperator_b3) > (int32_T)INS_P.Constant_Value_bt);

  /* Logic: '<S294>/Logical Operator2' incorporates:
   *  Inport: '<Root>/reset'
   *  RelationalOperator: '<S296>/FixPt Relational Operator'
   *  UnitDelay: '<S296>/Delay Input1'
   */
  rtb_LogicalOperator2_m = (((int32_T)rtb_GPS_vaid > (int32_T)
    INS_DWork.DelayInput1_DSTATE_j) || (INS_U.reset != 0));

  /* RelationalOperator: '<S304>/Compare' incorporates:
   *  Constant: '<S304>/Constant'
   */
  rtb_Memory_ph = ((int32_T)rtb_Memory_ph > (int32_T)INS_P.Constant_Value_m3);

  /* Switch: '<S301>/Switch4' incorporates:
   *  Memory: '<S301>/memory2'
   *  Memory: '<S4>/Memory'
   *  Product: '<S301>/Divide'
   *  RelationalOperator: '<S303>/FixPt Relational Operator'
   *  Sum: '<S301>/Sum'
   *  UnitDelay: '<S303>/Delay Input1'
   */
  if ((int32_T)rtb_Memory_ph > (int32_T)INS_DWork.DelayInput1_DSTATE_dp) {
    rtb_Scalefactor1 = rtb_Scalefactor3 - INS_DWork.Memory_11_PreviousInput /
      INS_B.dz_dh;
  } else {
    rtb_Scalefactor1 = INS_DWork.memory2_PreviousInput_j;
  }

  /* End of Switch: '<S301>/Switch4' */

  /* Gain: '<S159>/Gain2' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_vel_D = (real32_T)INS_P.Gain2_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velD;

  /* Sum: '<S308>/Subtract' incorporates:
   *  Constant: '<S313>/Constant'
   *  DataTypeConversion: '<S308>/Data Type Conversion2'
   *  RelationalOperator: '<S313>/Compare'
   */
  rtb_Relay2 = ((real32_T)((int32_T)rtb_LogicalOperator_b3 > (int32_T)
    INS_P.Constant_Value_hv) - rtb_Relay2) - rtb_Sum_j_idx_3;

  /* Saturate: '<S308>/Saturation1' */
  if (rtb_Relay2 > INS_P.Saturation1_UpperSat_i) {
    rtb_Relay2 = INS_P.Saturation1_UpperSat_i;
  } else {
    if (rtb_Relay2 < INS_P.Saturation1_LowerSat_j) {
      rtb_Relay2 = INS_P.Saturation1_LowerSat_j;
    }
  }

  /* End of Saturate: '<S308>/Saturation1' */

  /* RelationalOperator: '<S318>/Compare' incorporates:
   *  Constant: '<S318>/Constant'
   */
  rtb_Compare_bg = (rtb_Relay2 > INS_P.Constant_Value_iw);

  /* Logic: '<S145>/Logical Operator3' incorporates:
   *  Constant: '<S148>/Constant'
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S148>/Compare'
   *  RelationalOperator: '<S150>/Compare'
   *  Sum: '<S145>/Sum1'
   */
  rtb_pos_ever_valid_n = ((qY_0 >= INS_P.Relative_Height_s_first) && (qY_0 <=
    INS_P.Relative_Height_s_last));

  /* Outputs for Enabled SubSystem: '<S143>/Reference_and_Gradient' incorporates:
   *  EnablePort: '<S146>/Enable'
   */
  if (rtb_pos_ever_valid_n) {
    if (!INS_DWork.Reference_and_Gradient_MODE) {
      /* InitializeConditions for Memory: '<S146>/Memory' */
      INS_DWork.Memory_PreviousInput_f = INS_P.Memory_InitialCondition;

      /* InitializeConditions for Memory: '<S146>/Memory2' */
      INS_DWork.Memory2_PreviousInput_b = INS_P.Memory2_InitialCondition;

      /* InitializeConditions for Memory: '<S146>/Memory1' */
      INS_DWork.Memory1_PreviousInput_a = INS_P.Memory1_InitialCondition;
      INS_DWork.Reference_and_Gradient_MODE = true;
    }

    /* Sum: '<S146>/Sum2' incorporates:
     *  Inport: '<Root>/Barometer'
     *  Memory: '<S146>/Memory'
     */
    rtb_Relay2 = INS_U.Barometer.pressure + INS_DWork.Memory_PreviousInput_f;

    /* Sum: '<S146>/Sum1' incorporates:
     *  Constant: '<S146>/Constant1'
     *  Memory: '<S146>/Memory2'
     */
    qY = INS_P.Constant1_Value_f5 + INS_DWork.Memory2_PreviousInput_b;
    if (qY < INS_P.Constant1_Value_f5) {
      qY = MAX_uint32_T;
    }

    /* Saturate: '<S146>/Saturation1' incorporates:
     *  Sum: '<S146>/Sum1'
     */
    if (qY > INS_P.Saturation1_UpperSat_n) {
      rtb_Sum_nb = INS_P.Saturation1_UpperSat_n;
    } else if (qY < INS_P.Saturation1_LowerSat_m) {
      rtb_Sum_nb = INS_P.Saturation1_LowerSat_m;
    } else {
      rtb_Sum_nb = qY;
    }

    /* End of Saturate: '<S146>/Saturation1' */

    /* Product: '<S146>/Divide' */
    INS_B.Divide = rtb_Relay2 / (real32_T)rtb_Sum_nb;

    /* Sum: '<S146>/Sum4' incorporates:
     *  Constant: '<S146>/Constant2'
     *  Inport: '<Root>/Barometer'
     *  Memory: '<S146>/Memory1'
     *  Sum: '<S146>/Sum3'
     */
    rtb_h_R_quality = (INS_P.Constant2_Value_p + INS_U.Barometer.temperature) +
      INS_DWork.Memory1_PreviousInput_a;

    /* Saturate: '<S146>/Saturation' */
    if (INS_B.Divide > INS_P.Saturation_UpperSat_m) {
      tmp_1 = INS_P.Saturation_UpperSat_m;
    } else if (INS_B.Divide < INS_P.Saturation_LowerSat_h) {
      tmp_1 = INS_P.Saturation_LowerSat_h;
    } else {
      tmp_1 = INS_B.Divide;
    }

    /* End of Saturate: '<S146>/Saturation' */

    /* Gain: '<S146>/g_M_d_R' incorporates:
     *  Product: '<S146>/Divide1'
     *  Product: '<S146>/Product'
     */
    INS_B.g_M_d_R = rtb_h_R_quality / (real32_T)rtb_Sum_nb / tmp_1 *
      INS_P.g_M_d_R_Gain;

    /* Update for Memory: '<S146>/Memory' */
    INS_DWork.Memory_PreviousInput_f = rtb_Relay2;

    /* Update for Memory: '<S146>/Memory2' incorporates:
     *  Sum: '<S146>/Sum1'
     */
    INS_DWork.Memory2_PreviousInput_b = qY;

    /* Update for Memory: '<S146>/Memory1' */
    INS_DWork.Memory1_PreviousInput_a = rtb_h_R_quality;
  } else {
    if (INS_DWork.Reference_and_Gradient_MODE) {
      INS_DWork.Reference_and_Gradient_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S143>/Reference_and_Gradient' */

  /* Switch: '<S143>/Switch' incorporates:
   *  Inport: '<Root>/Barometer'
   *  Logic: '<S143>/Logical Operator1'
   *  Logic: '<S143>/Logical Operator2'
   */
  if (rtb_pos_ever_valid_n || (!rtb_LogicalOperator_b3)) {
    rtb_Relay2 = INS_U.Barometer.pressure;
  } else {
    rtb_Relay2 = INS_B.Divide;
  }

  /* End of Switch: '<S143>/Switch' */

  /* Product: '<S143>/Product1' incorporates:
   *  Inport: '<Root>/Barometer'
   *  Sum: '<S143>/Sum2'
   */
  rtb_h_R_quality = (INS_U.Barometer.pressure - rtb_Relay2) * INS_B.g_M_d_R;

  /* Outputs for Enabled SubSystem: '<S280>/Reference_Height' incorporates:
   *  EnablePort: '<S283>/Enable'
   */
  if (rtb_Compare_f3) {
    /* DataTypeConversion: '<S283>/Data Type Conversion' incorporates:
     *  Sum: '<S283>/Sum'
     */
    INS_B.h_0 = (real32_T)(rtb_Scalefactor3 - rtb_Scalefactor1);

    /* DataTypeConversion: '<S283>/Data Type Conversion1' */
    INS_B.vel_D_0 = rtb_vel_D;
  }

  /* End of Outputs for SubSystem: '<S280>/Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S281>/Reference_Height' incorporates:
   *  EnablePort: '<S284>/Enable'
   */
  /* RelationalOperator: '<S317>/Compare' incorporates:
   *  Constant: '<S317>/Constant'
   */
  if (rtb_Sum_j_idx_3 > INS_P.Constant_Value_h4) {
    /* DataTypeConversion: '<S284>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/Sonar'
     *  Product: '<S327>/Multiply'
     *  Trigonometry: '<S327>/Cos'
     *  Trigonometry: '<S327>/Cos1'
     */
    INS_B.h_0 = INS_U.Sonar.distance_m * arm_cos_f32(rtb_Product3_p) *
      arm_cos_f32(rtb_Product8_n);

    /* SignalConversion: '<S284>/OutportBuffer_InsertedFor_vel_D_mDs_at_inport_0' incorporates:
     *  Constant: '<S284>/Constant'
     */
    INS_B.vel_D_0 = INS_P.Constant_Value_k;
  }

  /* End of RelationalOperator: '<S317>/Compare' */
  /* End of Outputs for SubSystem: '<S281>/Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S279>/Reference_Height' incorporates:
   *  EnablePort: '<S282>/Enable'
   */
  if (rtb_Compare_bg) {
    /* DataTypeConversion: '<S282>/Data Type Conversion' */
    INS_B.h_0 = rtb_h_R_quality;

    /* SignalConversion: '<S282>/OutportBuffer_InsertedFor_vel_D_mDs_at_inport_0' incorporates:
     *  Constant: '<S282>/Constant'
     */
    INS_B.vel_D_0 = INS_P.Constant_Value_aa;
  }

  /* End of Outputs for SubSystem: '<S279>/Reference_Height' */

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S278>/Constant'
   *  Memory: '<S276>/Memory'
   */
  if (rtb_LogicalOperator2_m) {
    rtb_Sum2_g[0] = INS_B.h_0;
    rtb_Sum2_g[1] = INS_B.vel_D_0;
    rtb_Sum2_g[2] = INS_P.Constant_Value_e;
  } else {
    rtb_Sum2_g[0] = INS_DWork.Memory_PreviousInput_p[0];
    rtb_Sum2_g[1] = INS_DWork.Memory_PreviousInput_p[1];
    rtb_Sum2_g[2] = INS_DWork.Memory_PreviousInput_p[2];
  }

  /* End of Switch: '<S276>/Switch' */

  /* Product: '<S277>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
   */
  for (i = 0; i < 3; i++) {
    rtb_M_OB_0[i] = rtb_M_OB[i + 6] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[2]
      + (rtb_M_OB[i + 3] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] +
         rtb_M_OB[i] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]);
  }

  /* Sum: '<S277>/Sum' incorporates:
   *  Constant: '<S277>/Constant'
   *  Constant: '<S277>/Constant1'
   *  Gain: '<S277>/Gain'
   *  Gain: '<S277>/Gain1'
   *  Product: '<S277>/Multiply'
   *  Sum: '<S277>/Add'
   */
  rtb_vel_NE_0_idx_0 = INS_P.Gain1_Gain_kw * rtb_Sum2_g[1] * INS_P.Gain_Gain_m +
    rtb_Sum2_g[0];
  rtb_gps_pos_bias_idx_1 = ((rtb_M_OB_0[2] - rtb_Sum2_g[2]) +
    INS_P.Constant1_Value_f) * INS_P.Gain_Gain_m + rtb_Sum2_g[1];
  rtb_MathFunction_e_idx_2 = INS_P.Gain_Gain_m * INS_P.Constant_Value_n +
    rtb_Sum2_g[2];

  /* Outputs for Enabled SubSystem: '<S256>/Baro_Correct' incorporates:
   *  EnablePort: '<S258>/Enable'
   */
  /* Switch: '<S256>/Switch' */
  if (rtb_Compare_bg) {
    /* Delay: '<S262>/x_delay' */
    if (rtb_LogicalOperator2_m && (INS_PrevZCSigState.x_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_a = 1U;
    }

    INS_PrevZCSigState.x_delay_Reset_ZCE = rtb_LogicalOperator2_m;
    if (INS_DWork.icLoad_a != 0) {
      for (i = 0; i < 5; i++) {
        INS_DWork.x_delay_DSTATE[i] = rtb_vel_NE_0_idx_0;
      }
    }

    /* RelationalOperator: '<S266>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S266>/Delay Input1'
     */
    rtb_pos_ever_valid_n = (1 > (int32_T)INS_DWork.DelayInput1_DSTATE_fw);

    /* Switch: '<S264>/Switch' incorporates:
     *  Memory: '<S264>/Memory'
     *  Sum: '<S265>/Sum'
     */
    if (rtb_pos_ever_valid_n) {
      rtb_baro_height_bias = rtb_vel_NE_0_idx_0 - rtb_h_R_quality;
    } else {
      rtb_baro_height_bias = INS_DWork.Memory_PreviousInput_j;
    }

    /* End of Switch: '<S264>/Switch' */

    /* Sum: '<S258>/Sum' incorporates:
     *  Delay: '<S262>/x_delay'
     *  Sum: '<S261>/Sum1'
     */
    rtb_h_R_quality = (rtb_h_R_quality + rtb_baro_height_bias) -
      INS_DWork.x_delay_DSTATE[0];

    /* Logic: '<S258>/Logical Operator' incorporates:
     *  Inport: '<Root>/Barometer'
     *  RelationalOperator: '<S259>/FixPt Relational Operator'
     *  UnitDelay: '<S259>/Delay Input1'
     */
    rtb_pos_ever_valid_n = (rtb_pos_ever_valid_n || (INS_U.Barometer.timestamp
      != INS_DWork.DelayInput1_DSTATE_lg));

    /* Switch: '<S260>/Switch' incorporates:
     *  Gain: '<S263>/Gain'
     *  Gain: '<S263>/Gain1'
     *  Gain: '<S263>/Gain2'
     *  Memory: '<S260>/Memory'
     */
    if (rtb_pos_ever_valid_n) {
      rtb_bias_g_correction_f[0] = INS_P.Gain2_Gain_m * rtb_h_R_quality;
      rtb_bias_g_correction_f[1] = INS_P.Gain1_Gain_en * rtb_h_R_quality;
      rtb_bias_g_correction_f[2] = INS_P.Gain_Gain_n * rtb_h_R_quality;
    } else {
      rtb_bias_g_correction_f[0] = INS_DWork.Memory_PreviousInput_i[0];
      rtb_bias_g_correction_f[1] = INS_DWork.Memory_PreviousInput_i[1];
      rtb_bias_g_correction_f[2] = INS_DWork.Memory_PreviousInput_i[2];
    }

    /* End of Switch: '<S260>/Switch' */

    /* Sum: '<S258>/Sum1' incorporates:
     *  Gain: '<S260>/Gain'
     */
    INS_B.Sum1_p[0] = INS_P.Gain_Gain_pl * rtb_bias_g_correction_f[0] +
      rtb_vel_NE_0_idx_0;
    INS_B.Sum1_p[1] = INS_P.Gain_Gain_pl * rtb_bias_g_correction_f[1] +
      rtb_gps_pos_bias_idx_1;
    INS_B.Sum1_p[2] = INS_P.Gain_Gain_pl * rtb_bias_g_correction_f[2] +
      rtb_MathFunction_e_idx_2;

    /* Update for UnitDelay: '<S259>/Delay Input1' incorporates:
     *  Inport: '<Root>/Barometer'
     */
    INS_DWork.DelayInput1_DSTATE_lg = INS_U.Barometer.timestamp;

    /* Update for Delay: '<S262>/x_delay' */
    INS_DWork.icLoad_a = 0U;
    INS_DWork.x_delay_DSTATE[0] = INS_DWork.x_delay_DSTATE[1];
    INS_DWork.x_delay_DSTATE[1] = INS_DWork.x_delay_DSTATE[2];
    INS_DWork.x_delay_DSTATE[2] = INS_DWork.x_delay_DSTATE[3];
    INS_DWork.x_delay_DSTATE[3] = INS_DWork.x_delay_DSTATE[4];
    INS_DWork.x_delay_DSTATE[4] = rtb_vel_NE_0_idx_0;

    /* Update for UnitDelay: '<S266>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_fw = true;

    /* Update for Memory: '<S264>/Memory' */
    INS_DWork.Memory_PreviousInput_j = rtb_baro_height_bias;

    /* Update for Memory: '<S260>/Memory' */
    INS_DWork.Memory_PreviousInput_i[0] = rtb_bias_g_correction_f[0];
    INS_DWork.Memory_PreviousInput_i[1] = rtb_bias_g_correction_f[1];
    INS_DWork.Memory_PreviousInput_i[2] = rtb_bias_g_correction_f[2];
    rtb_vel_NE_0_idx_0 = INS_B.Sum1_p[0];
    rtb_gps_pos_bias_idx_1 = INS_B.Sum1_p[1];
    rtb_MathFunction_e_idx_2 = INS_B.Sum1_p[2];
  }

  /* End of Switch: '<S256>/Switch' */
  /* End of Outputs for SubSystem: '<S256>/Baro_Correct' */

  /* Outputs for Enabled SubSystem: '<S257>/GPS_Correct' incorporates:
   *  EnablePort: '<S267>/Enable'
   */
  /* Switch: '<S257>/Switch' */
  if (rtb_Compare_f3) {
    /* Delay: '<S271>/h_delay' */
    if (rtb_LogicalOperator2_m && (INS_PrevZCSigState.h_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad = 1U;
    }

    INS_PrevZCSigState.h_delay_Reset_ZCE = rtb_LogicalOperator2_m;
    if (INS_DWork.icLoad != 0) {
      for (i = 0; i < 75; i++) {
        INS_DWork.h_delay_DSTATE[i] = rtb_vel_NE_0_idx_0;
      }
    }

    /* Delay: '<S271>/vd_delay' */
    if (rtb_LogicalOperator2_m && (INS_PrevZCSigState.vd_delay_Reset_ZCE !=
         POS_ZCSIG)) {
      INS_DWork.icLoad_f = 1U;
    }

    INS_PrevZCSigState.vd_delay_Reset_ZCE = rtb_LogicalOperator2_m;
    if (INS_DWork.icLoad_f != 0) {
      for (i = 0; i < 50; i++) {
        INS_DWork.vd_delay_DSTATE[i] = rtb_gps_pos_bias_idx_1;
      }
    }

    /* DataTypeConversion: '<S270>/Data Type Conversion' incorporates:
     *  Sum: '<S270>/Sum'
     */
    rtb_h_R_quality = (real32_T)(rtb_Scalefactor3 - rtb_Scalefactor1);

    /* RelationalOperator: '<S275>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S275>/Delay Input1'
     */
    rtb_pos_ever_valid_n = (1 > (int32_T)INS_DWork.DelayInput1_DSTATE_ib);

    /* Switch: '<S273>/Switch' incorporates:
     *  DataTypeConversion: '<S270>/Data Type Conversion'
     *  Memory: '<S273>/Memory'
     *  Sum: '<S274>/Sum'
     */
    if (rtb_pos_ever_valid_n) {
      rtb_baro_height_bias = rtb_vel_NE_0_idx_0 - rtb_h_R_quality;
    } else {
      rtb_baro_height_bias = INS_DWork.Memory_PreviousInput_b;
    }

    /* End of Switch: '<S273>/Switch' */

    /* Logic: '<S267>/Logical Operator' incorporates:
     *  Inport: '<Root>/Barometer'
     *  RelationalOperator: '<S268>/FixPt Relational Operator'
     *  UnitDelay: '<S268>/Delay Input1'
     */
    rtb_pos_ever_valid_n = (rtb_pos_ever_valid_n || (INS_U.Barometer.timestamp
      != INS_DWork.DelayInput1_DSTATE_d));

    /* Switch: '<S269>/Switch' incorporates:
     *  DataTypeConversion: '<S270>/Data Type Conversion'
     *  Delay: '<S271>/h_delay'
     *  Gain: '<S272>/Gain'
     *  Gain: '<S272>/Gain1'
     *  Gain: '<S272>/Gain2'
     *  Memory: '<S269>/Memory'
     *  Sum: '<S267>/Sum'
     *  Sum: '<S270>/Sum1'
     */
    if (rtb_pos_ever_valid_n) {
      /* Sum: '<S267>/Sum' incorporates:
       *  Delay: '<S271>/vd_delay'
       */
      rtb_vel_NE_0_idx_1 = rtb_vel_D - INS_DWork.vd_delay_DSTATE[0U];
      rtb_bias_g_correction_f[0] = ((rtb_h_R_quality + rtb_baro_height_bias) -
        INS_DWork.h_delay_DSTATE[0U]) * INS_P.Gain1_Gain_m;
      rtb_bias_g_correction_f[1] = INS_P.Gain_Gain_cc * rtb_vel_NE_0_idx_1;
      rtb_bias_g_correction_f[2] = INS_P.Gain2_Gain_k * rtb_vel_NE_0_idx_1;
    } else {
      rtb_bias_g_correction_f[0] = INS_DWork.Memory_PreviousInput_e[0];
      rtb_bias_g_correction_f[1] = INS_DWork.Memory_PreviousInput_e[1];
      rtb_bias_g_correction_f[2] = INS_DWork.Memory_PreviousInput_e[2];
    }

    /* End of Switch: '<S269>/Switch' */

    /* Sum: '<S267>/Sum1' incorporates:
     *  Gain: '<S269>/Gain3'
     */
    INS_B.Sum1[0] = INS_P.Gain3_Gain_k * rtb_bias_g_correction_f[0] +
      rtb_vel_NE_0_idx_0;
    INS_B.Sum1[1] = INS_P.Gain3_Gain_k * rtb_bias_g_correction_f[1] +
      rtb_gps_pos_bias_idx_1;
    INS_B.Sum1[2] = INS_P.Gain3_Gain_k * rtb_bias_g_correction_f[2] +
      rtb_MathFunction_e_idx_2;

    /* Update for UnitDelay: '<S268>/Delay Input1' incorporates:
     *  Inport: '<Root>/Barometer'
     */
    INS_DWork.DelayInput1_DSTATE_d = INS_U.Barometer.timestamp;

    /* Update for Delay: '<S271>/h_delay' */
    INS_DWork.icLoad = 0U;
    for (i = 0; i < 74; i++) {
      INS_DWork.h_delay_DSTATE[i] = INS_DWork.h_delay_DSTATE[i + 1];
    }

    INS_DWork.h_delay_DSTATE[74] = rtb_vel_NE_0_idx_0;

    /* End of Update for Delay: '<S271>/h_delay' */

    /* Update for Delay: '<S271>/vd_delay' */
    INS_DWork.icLoad_f = 0U;
    for (i = 0; i < 49; i++) {
      INS_DWork.vd_delay_DSTATE[i] = INS_DWork.vd_delay_DSTATE[i + 1];
    }

    INS_DWork.vd_delay_DSTATE[49] = rtb_gps_pos_bias_idx_1;

    /* End of Update for Delay: '<S271>/vd_delay' */

    /* Update for UnitDelay: '<S275>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ib = true;

    /* Update for Memory: '<S273>/Memory' */
    INS_DWork.Memory_PreviousInput_b = rtb_baro_height_bias;

    /* Update for Memory: '<S269>/Memory' */
    INS_DWork.Memory_PreviousInput_e[0] = rtb_bias_g_correction_f[0];
    INS_DWork.Memory_PreviousInput_e[1] = rtb_bias_g_correction_f[1];
    INS_DWork.Memory_PreviousInput_e[2] = rtb_bias_g_correction_f[2];
    rtb_vel_NE_0_idx_0 = INS_B.Sum1[0];
    rtb_gps_pos_bias_idx_1 = INS_B.Sum1[1];
    rtb_MathFunction_e_idx_2 = INS_B.Sum1[2];
  }

  /* End of Switch: '<S257>/Switch' */
  /* End of Outputs for SubSystem: '<S257>/GPS_Correct' */

  /* Sum: '<S85>/Sum' incorporates:
   *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
   *  Math: '<S72>/Transpose2'
   *  SignalConversion: '<S85>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_bias_g_correction_f[i] = INS_DWork.DiscreteTimeIntegrator1_DSTATE[i] -
      ((rtb_Transpose2_tmp[i + 3] * rtb_Sum_mt[5] + rtb_Transpose2_tmp[i] *
        rtb_Sum_mt[4]) + rtb_Transpose2_tmp[i + 6] * rtb_MathFunction_e_idx_2);
  }

  /* End of Sum: '<S85>/Sum' */

  /* Abs: '<S231>/Abs' incorporates:
   *  Abs: '<S233>/Abs'
   */
  rtb_Scalefactor2 = fabs(rtb_WGS84_derivatives_ref_idx_0);
  rtb_Scalefactor3 = fabs(rtb_Gain6);

  /* Switch: '<S231>/Switch' incorporates:
   *  Abs: '<S231>/Abs'
   *  Constant: '<S231>/Constant'
   *  Constant: '<S232>/Constant'
   *  DataTypeConversion: '<S231>/Data Type Conversion'
   *  DataTypeConversion: '<S231>/Data Type Conversion1'
   *  MinMax: '<S231>/Min'
   *  Product: '<S231>/Divide'
   *  Product: '<S233>/Product'
   *  RelationalOperator: '<S232>/Compare'
   *  Signum: '<S233>/Sign'
   *  Sum: '<S231>/Sum'
   */
  if (fmin(rtb_Scalefactor2, rtb_Scalefactor3) < INS_P.CompareToConstant_const)
  {
    rtb_Scalefactor2 = INS_P.Constant_Value_i[0];
    rtb_Scalefactor3 = INS_P.Constant_Value_i[1];
    rtb_Switch_idx_2 = INS_P.Constant_Value_i[2];
  } else {
    if (rtb_WGS84_derivatives_ref_idx_0 < 0.0) {
      /* Signum: '<S233>/Sign' */
      rtb_Switch_idx_2 = -1.0;
    } else if (rtb_WGS84_derivatives_ref_idx_0 > 0.0) {
      /* Signum: '<S233>/Sign' */
      rtb_Switch_idx_2 = 1.0;
    } else {
      /* Signum: '<S233>/Sign' */
      rtb_Switch_idx_2 = rtb_WGS84_derivatives_ref_idx_0;
    }

    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S233>/Constant'
     *  Signum: '<S233>/Sign'
     */
    if (rtb_Switch_idx_2 == 0.0) {
      rtb_Switch_idx_2 = INS_P.Constant_Value;
    }

    /* Saturate: '<S233>/Saturation' */
    if (rtb_Scalefactor2 > INS_P.Saturation_UpperSat) {
      rtb_Scalefactor2 = INS_P.Saturation_UpperSat;
    } else {
      if (rtb_Scalefactor2 < INS_P.Zero_Value_Exclusion_thr) {
        rtb_Scalefactor2 = INS_P.Zero_Value_Exclusion_thr;
      }
    }

    rtb_Scalefactor2 = rtb_Sum_mt[0] / (rtb_Scalefactor2 * rtb_Switch_idx_2) +
      rtb_N;

    /* Signum: '<S233>/Sign' incorporates:
     *  DataTypeConversion: '<S231>/Data Type Conversion'
     *  Product: '<S231>/Divide'
     *  Product: '<S233>/Product'
     *  Sum: '<S231>/Sum'
     */
    if (rtb_Gain6 < 0.0) {
      rtb_Switch_idx_2 = -1.0;
    } else if (rtb_Gain6 > 0.0) {
      rtb_Switch_idx_2 = 1.0;
    } else {
      rtb_Switch_idx_2 = rtb_Gain6;
    }

    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S233>/Constant'
     */
    if (rtb_Switch_idx_2 == 0.0) {
      rtb_Switch_idx_2 = INS_P.Constant_Value;
    }

    /* Saturate: '<S233>/Saturation' */
    if (rtb_Scalefactor3 > INS_P.Saturation_UpperSat) {
      rtb_Scalefactor3 = INS_P.Saturation_UpperSat;
    } else {
      if (rtb_Scalefactor3 < INS_P.Zero_Value_Exclusion_thr) {
        rtb_Scalefactor3 = INS_P.Zero_Value_Exclusion_thr;
      }
    }

    rtb_Scalefactor3 = rtb_Sum_mt[1] / (rtb_Scalefactor3 * rtb_Switch_idx_2) +
      rtb_WGS84_pos_ref_idx_1;
    rtb_Switch_idx_2 = rtb_vel_NE_0_idx_0 + rtb_Scalefactor1;
  }

  /* End of Switch: '<S231>/Switch' */

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant'
   *  Memory: '<S71>/Memory'
   *  RelationalOperator: '<S75>/FixPt Relational Operator'
   *  UnitDelay: '<S75>/Delay Input1'
   */
  if ((int32_T)rtb_UpperTest_g > (int32_T)INS_DWork.DelayInput1_DSTATE_dy) {
    rtb_Compare_hd = INS_P.Constant_Value_mm;
  } else {
    rtb_Compare_hd = INS_DWork.Memory_PreviousInput_l;
  }

  /* End of Switch: '<S71>/Switch' */

  /* Relay: '<S10>/Relay2' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator5'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTATE >= INS_P.Relay2_OnVal) {
    INS_DWork.Relay2_Mode = true;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator5_DSTATE <= INS_P.Relay2_OffVal) {
      INS_DWork.Relay2_Mode = false;
    }
  }

  if (INS_DWork.Relay2_Mode) {
    rtb_Relay2 = INS_P.Relay2_YOn;
  } else {
    rtb_Relay2 = INS_P.Relay2_YOff;
  }

  /* End of Relay: '<S10>/Relay2' */

  /* RelationalOperator: '<S120>/Compare' incorporates:
   *  Constant: '<S120>/Constant'
   */
  rtb_Compare_f3 = ((int32_T)rtb_Compare_h2 > (int32_T)
                    INS_P.CompareToConstant1_const_j);

  /* DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  if (rtb_Compare_f3 || (INS_DWork.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_i;
  }

  /* DataTypeConversion: '<S206>/Data Type Conversion1' incorporates:
   *  Gain: '<S206>/Gain'
   */
  tmp_0 = fmod(trunc(57.295779513082323 / INS_P.wmm_lookup_res *
                     INS_B.Scalefactor1), 4.294967296E+9);

  /* Sum: '<S206>/Sum' incorporates:
   *  Constant: '<S206>/offset_lat'
   *  DataTypeConversion: '<S206>/Data Type Conversion1'
   */
  rtb_Saturation1_b = (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)
                       (uint32_T)tmp_0) + INS_P.offset_lat_Value;

  /* Saturate: '<S206>/Saturation1' */
  if (rtb_Saturation1_b > INS_P.Saturation1_UpperSat) {
    rtb_Saturation1_b = INS_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1_b < INS_P.Saturation1_LowerSat) {
      rtb_Saturation1_b = INS_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S206>/Saturation1' */

  /* DataTypeConversion: '<S206>/Data Type Conversion2' incorporates:
   *  Gain: '<S206>/Gain6'
   */
  tmp_0 = fmod(trunc(57.295779513082323 / INS_P.wmm_lookup_res *
                     INS_B.Scalefactor), 4.294967296E+9);

  /* Sum: '<S206>/Sum1' incorporates:
   *  Constant: '<S206>/offset_lon'
   *  DataTypeConversion: '<S206>/Data Type Conversion2'
   */
  rtb_Sum_ly = (tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)
                tmp_0) + INS_P.offset_lon_Value;

  /* Saturate: '<S206>/Saturation2' */
  if (rtb_Sum_ly > INS_P.Saturation2_UpperSat) {
    rtb_Sum_ly = INS_P.Saturation2_UpperSat;
  } else {
    if (rtb_Sum_ly < INS_P.Saturation2_LowerSat) {
      rtb_Sum_ly = INS_P.Saturation2_LowerSat;
    }
  }

  /* End of Saturate: '<S206>/Saturation2' */

  /* LookupNDDirect: '<S206>/Declination Lookup'
   *
   * About '<S206>/Declination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  if (rtb_Sum_ly > 36) {
    i = 36;
  } else if (rtb_Sum_ly < 0) {
    i = 0;
  } else {
    i = rtb_Sum_ly;
  }

  if (rtb_Saturation1_b > 16) {
    rtb_Saturation1_j = 16;
  } else if (rtb_Saturation1_b < 0) {
    rtb_Saturation1_j = 0;
  } else {
    rtb_Saturation1_j = rtb_Saturation1_b;
  }

  /* Gain: '<S205>/Gain' incorporates:
   *  LookupNDDirect: '<S206>/Declination Lookup'
   *
   * About '<S206>/Declination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_baro_height_bias = (real32_T)INS_P.wmm_lookup_wmm_declination[i * 17 +
    rtb_Saturation1_j] * ((real32_T)INS_P.Gain_Gain_fs * 9.53674316E-7F);

  /* Trigonometry: '<S214>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S214>/Trigonometric Function3'
   */
  rtb_delay_acc_O_idx_2 = arm_cos_f32(rtb_baro_height_bias);
  rtb_VectorConcatenate_l[0] = rtb_delay_acc_O_idx_2;

  /* Trigonometry: '<S214>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S214>/Trigonometric Function2'
   */
  rtb_vel_NE_0_idx_1 = arm_sin_f32(rtb_baro_height_bias);
  rtb_VectorConcatenate_l[1] = rtb_vel_NE_0_idx_1;

  /* Constant: '<S214>/Constant3' */
  rtb_VectorConcatenate_l[2] = INS_P.Constant3_Value;

  /* Gain: '<S214>/Gain' */
  rtb_VectorConcatenate_l[3] = INS_P.Gain_Gain_l * rtb_vel_NE_0_idx_1;

  /* Trigonometry: '<S214>/Trigonometric Function3' */
  rtb_VectorConcatenate_l[4] = rtb_delay_acc_O_idx_2;

  /* Constant: '<S214>/Constant4' */
  rtb_VectorConcatenate_l[5] = INS_P.Constant4_Value;

  /* Constant: '<S214>/Constant2' */
  rtb_VectorConcatenate_l[6] = INS_P.Constant2_Value_d;

  /* Constant: '<S214>/Constant1' */
  rtb_VectorConcatenate_l[7] = INS_P.Constant1_Value_k;

  /* Constant: '<S214>/Constant' */
  rtb_VectorConcatenate_l[8] = INS_P.Constant_Value_dm;

  /* Sum: '<S199>/Subtract' incorporates:
   *  Constant: '<S199>/Mag_Bias'
   *  Inport: '<Root>/MAG'
   *  SignalConversion: '<S139>/ConcatBufferAtVector Concatenate2In1'
   *  SignalConversion: '<S139>/ConcatBufferAtVector Concatenate2In2'
   *  SignalConversion: '<S139>/ConcatBufferAtVector Concatenate2In3'
   */
  rtb_delay_acc_O_idx_2 = INS_U.MAG.mag_x - INS_PARAM.MagBias[0];
  rtb_vel_NE_0_idx_1 = INS_U.MAG.mag_y - INS_PARAM.MagBias[1];
  rtb_h_R_quality = INS_U.MAG.mag_z - INS_PARAM.MagBias[2];
  for (i = 0; i < 3; i++) {
    /* Gain: '<S196>/Gauss_to_uT' incorporates:
     *  Constant: '<S199>/Mag_RotMatrix'
     *  Product: '<S199>/Product1'
     */
    rtb_Gauss_to_uT[i] = INS_P.Gauss_to_uT_Gain * (INS_PARAM.MagRotMat[i + 6] *
      rtb_h_R_quality + (INS_PARAM.MagRotMat[i + 3] * rtb_vel_NE_0_idx_1 +
                         INS_PARAM.MagRotMat[i] * rtb_delay_acc_O_idx_2));
  }

  /* LookupNDDirect: '<S206>/Magnitude Lookup'
   *
   * About '<S206>/Magnitude Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  if (rtb_Sum_ly > 36) {
    i = 36;
  } else if (rtb_Sum_ly < 0) {
    i = 0;
  } else {
    i = rtb_Sum_ly;
  }

  if (rtb_Saturation1_b > 16) {
    rtb_Saturation1_j = 16;
  } else if (rtb_Saturation1_b < 0) {
    rtb_Saturation1_j = 0;
  } else {
    rtb_Saturation1_j = rtb_Saturation1_b;
  }

  /* Product: '<S205>/Divide1' incorporates:
   *  Constant: '<S205>/Constant1'
   *  LookupNDDirect: '<S206>/Magnitude Lookup'
   *  MinMax: '<S205>/MinMax'
   *
   * About '<S206>/Magnitude Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  tmp_1 = 1.0F / fmaxf(INS_P.Constant1_Value_b, INS_P.wmm_lookup_wmm_magnitude[i
                       * 17 + rtb_Saturation1_j]);

  /* Product: '<S205>/Product1' incorporates:
   *  Product: '<S205>/Divide1'
   */
  for (i = 0; i < 3; i++) {
    rtb_M_OB_0[i] = rtb_M_OB[i + 6] * (tmp_1 * rtb_Gauss_to_uT[2]) + (rtb_M_OB[i
      + 3] * (tmp_1 * rtb_Gauss_to_uT[1]) + tmp_1 * rtb_Gauss_to_uT[0] *
      rtb_M_OB[i]);
  }

  /* End of Product: '<S205>/Product1' */

  /* RelationalOperator: '<S203>/Compare' incorporates:
   *  Constant: '<S203>/Constant'
   */
  rtb_Compare_ju = (rtb_Compare_p1 == INS_P.CompareToConstant_const_h);
  for (i = 0; i < 3; i++) {
    /* Math: '<S215>/Math Function' */
    rtb_MathFunction[i] = rtb_Gauss_to_uT[i] * rtb_Gauss_to_uT[i];

    /* Product: '<S205>/Product3' */
    rtb_Product3_i[i] = rtb_VectorConcatenate_l[i + 6] * rtb_M_OB_0[2] +
      (rtb_VectorConcatenate_l[i + 3] * rtb_M_OB_0[1] +
       rtb_VectorConcatenate_l[i] * rtb_M_OB_0[0]);
  }

  /* Sum: '<S215>/Sum of Elements' */
  rtb_baro_height_bias = (rtb_MathFunction[0] + rtb_MathFunction[1]) +
    rtb_MathFunction[2];

  /* Math: '<S215>/Math Function1'
   *
   * About '<S215>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_baro_height_bias < 0.0F) {
    rtb_baro_height_bias = -sqrtf(fabsf(rtb_baro_height_bias));
  } else {
    rtb_baro_height_bias = sqrtf(rtb_baro_height_bias);
  }

  /* End of Math: '<S215>/Math Function1' */

  /* Switch: '<S215>/Switch' incorporates:
   *  Constant: '<S215>/Constant'
   *  Product: '<S215>/Product'
   */
  if (rtb_baro_height_bias > INS_P.Switch_Threshold) {
    rtb_delay_acc_O_idx_0 = rtb_Gauss_to_uT[0];
    rtb_delay_acc_O_idx_1 = rtb_Gauss_to_uT[1];
    rtb_delay_acc_O_idx_2 = rtb_Gauss_to_uT[2];
    rtb_Sum_j_idx_3 = rtb_baro_height_bias;
  } else {
    rtb_delay_acc_O_idx_0 = 0.0F;
    rtb_delay_acc_O_idx_1 = 0.0F;
    rtb_delay_acc_O_idx_2 = 0.0F;
    rtb_Sum_j_idx_3 = INS_P.Constant_Value_g2;
  }

  /* End of Switch: '<S215>/Switch' */

  /* Product: '<S215>/Divide1' */
  rtb_Gauss_to_uT[0] = rtb_delay_acc_O_idx_0 / rtb_Sum_j_idx_3;
  rtb_Gauss_to_uT[1] = rtb_delay_acc_O_idx_1 / rtb_Sum_j_idx_3;
  rtb_Gauss_to_uT[2] = rtb_delay_acc_O_idx_2 / rtb_Sum_j_idx_3;

  /* Switch: '<S205>/Switch1' incorporates:
   *  Constant: '<S204>/default_mag_quality'
   *  MinMax: '<S207>/MinMax'
   *  Switch: '<S204>/Switch'
   */
  if (rtb_Compare_ju) {
    /* Math: '<S213>/Square' incorporates:
     *  Math: '<S211>/Square'
     */
    rtb_delay_acc_O_idx_2 = rtb_Product3_i[0] * rtb_Product3_i[0];
    rtb_h_R_quality = rtb_Product3_i[1] * rtb_Product3_i[1];

    /* Sum: '<S209>/Subtract1' incorporates:
     *  Abs: '<S209>/Abs'
     *  Constant: '<S209>/Constant1'
     *  Constant: '<S209>/Nominal_Magnitude'
     *  Math: '<S213>/Square'
     *  Sqrt: '<S212>/Sqrt'
     *  Sum: '<S209>/Subtract'
     *  Sum: '<S213>/Sum of Elements'
     */
    rtb_vel_NE_0_idx_1 = INS_P.Constant1_Value - fabsf
      (INS_P.Nominal_Magnitude_Value - sqrtf((rtb_delay_acc_O_idx_2 +
         rtb_h_R_quality) + rtb_Product3_i[2] * rtb_Product3_i[2]));

    /* Saturate: '<S209>/Saturation' */
    if (rtb_vel_NE_0_idx_1 > INS_P.Saturation_UpperSat_g) {
      rtb_vel_NE_0_idx_1 = INS_P.Saturation_UpperSat_g;
    } else {
      if (rtb_vel_NE_0_idx_1 < INS_P.Saturation_LowerSat_p) {
        rtb_vel_NE_0_idx_1 = INS_P.Saturation_LowerSat_p;
      }
    }

    /* End of Saturate: '<S209>/Saturation' */

    /* LookupNDDirect: '<S206>/Inclination Lookup'
     *
     * About '<S206>/Inclination Lookup':
     *  2-dimensional Direct Look-Up returning a Scalar,
     */
    if (rtb_Sum_ly > 36) {
      rtb_Sum_ly = 36;
    } else {
      if (rtb_Sum_ly < 0) {
        rtb_Sum_ly = 0;
      }
    }

    if (rtb_Saturation1_b > 16) {
      rtb_Saturation1_b = 16;
    } else {
      if (rtb_Saturation1_b < 0) {
        rtb_Saturation1_b = 0;
      }
    }

    /* Sum: '<S208>/Sum3' incorporates:
     *  Abs: '<S208>/Abs1'
     *  Constant: '<S208>/Constant2'
     *  Gain: '<S208>/Gain1'
     *  Gain: '<S208>/Gain2'
     *  LookupNDDirect: '<S206>/Inclination Lookup'
     *  Sqrt: '<S210>/Sqrt'
     *  Sum: '<S208>/Sum2'
     *  Sum: '<S211>/Sum of Elements'
     *  Trigonometry: '<S208>/Trigonometric Function'
     *
     * About '<S206>/Inclination Lookup':
     *  2-dimensional Direct Look-Up returning a Scalar,
     */
    rtb_delay_acc_O_idx_2 = INS_P.Constant2_Value_h - fabsf((real32_T)
      (INS_P.wmm_lookup_wmm_inclination[rtb_Sum_ly * 17 + rtb_Saturation1_b] *
       INS_P.Gain1_Gain_o) * 0.000244140625F - atan2f(rtb_Product3_i[2], sqrtf
      (rtb_delay_acc_O_idx_2 + rtb_h_R_quality))) * INS_P.Gain2_Gain_g;

    /* Saturate: '<S208>/Saturation' */
    if (rtb_delay_acc_O_idx_2 > INS_P.Saturation_UpperSat_gg) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation_UpperSat_gg;
    } else {
      if (rtb_delay_acc_O_idx_2 < INS_P.Saturation_LowerSat_a) {
        rtb_delay_acc_O_idx_2 = INS_P.Saturation_LowerSat_a;
      }
    }

    /* End of Saturate: '<S208>/Saturation' */
    rtb_baro_height_bias = fminf(rtb_delay_acc_O_idx_2, rtb_vel_NE_0_idx_1);
  } else {
    rtb_baro_height_bias = INS_P.default_mag_quality_Value;
  }

  /* End of Switch: '<S205>/Switch1' */

  /* DiscreteIntegrator: '<S197>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/MAG'
   *  RelationalOperator: '<S201>/FixPt Relational Operator'
   *  UnitDelay: '<S201>/Delay Input1'
   */
  if (INS_U.MAG.timestamp != INS_DWork.DelayInput1_DSTATE_n) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg =
      INS_P.DiscreteTimeIntegrator_IC_k;
  }

  /* Product: '<S204>/Multiply' incorporates:
   *  Constant: '<S200>/Constant'
   *  Constant: '<S202>/Lower Limit'
   *  Constant: '<S202>/Upper Limit'
   *  DiscreteIntegrator: '<S197>/Discrete-Time Integrator'
   *  Inport: '<Root>/MAG'
   *  Logic: '<S197>/Logical Operator1'
   *  Logic: '<S197>/Logical Operator4'
   *  Logic: '<S202>/AND'
   *  RelationalOperator: '<S200>/Compare'
   *  RelationalOperator: '<S202>/Lower Test'
   *  RelationalOperator: '<S202>/Upper Test'
   *  SignalConversion: '<S139>/ConcatBufferAtVector Concatenate2In1'
   *  SignalConversion: '<S139>/ConcatBufferAtVector Concatenate2In2'
   *  SignalConversion: '<S139>/ConcatBufferAtVector Concatenate2In3'
   */
  rtb_Inclination = (INS_P.Mag_Valid_Check_mag_min < INS_U.MAG.mag_x) &&
    (INS_U.MAG.mag_x < INS_P.Mag_Valid_Check_mag_max) &&
    ((INS_P.Mag_Valid_Check_mag_min < INS_U.MAG.mag_y) && (INS_U.MAG.mag_y <
      INS_P.Mag_Valid_Check_mag_max)) && ((INS_P.Mag_Valid_Check_mag_min <
    INS_U.MAG.mag_z) && (INS_U.MAG.mag_z < INS_P.Mag_Valid_Check_mag_max)) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_lg < INS_P.Mag_Valid_Check_timeout) ?
    rtb_baro_height_bias : 0.0F;

  /* MinMax: '<S89>/Max' */
  rtb_baro_height_bias = fmaxf(rtb_Double, rtb_Inclination);

  /* RelationalOperator: '<S105>/Compare' incorporates:
   *  Constant: '<S105>/Constant'
   */
  rtb_pos_ever_valid_n = (rtb_baro_height_bias > INS_P.CompareToConstant1_const);

  /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
  if (rtb_pos_ever_valid_n || (INS_DWork.DiscreteTimeIntegrator_PrevRe_o != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_IC_il;
  }

  /* RelationalOperator: '<S100>/Compare' incorporates:
   *  Constant: '<S100>/Constant'
   */
  rtb_LogicalOperator2_m = (rtb_Double > INS_P.CompareToConstant1_const_p);

  /* DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator2_m || (INS_DWork.DiscreteTimeIntegrator_PrevRe_e != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o =
      INS_P.DiscreteTimeIntegrator_IC_l;
  }

  /* RelationalOperator: '<S110>/Compare' incorporates:
   *  Constant: '<S110>/Constant'
   */
  rtb_Compare_bg = (rtb_Double1 > INS_P.CompareToConstant1_const_g);

  /* DiscreteIntegrator: '<S94>/Discrete-Time Integrator' */
  if (rtb_Compare_bg || (INS_DWork.DiscreteTimeIntegrator_PrevR_or != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j =
      INS_P.DiscreteTimeIntegrator_IC_d;
  }

  /* MinMax: '<S89>/Max1' incorporates:
   *  DataTypeConversion: '<S89>/Data Type Conversion'
   */
  rtb_vel_NE_0_idx_1 = fmaxf(rtb_Double1, rtb_LogicalOperator_mt);

  /* RelationalOperator: '<S115>/Compare' incorporates:
   *  Constant: '<S115>/Constant'
   */
  rtb_Compare_pq = (rtb_vel_NE_0_idx_1 > INS_P.CompareToConstant1_const_i);

  /* DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
  if (rtb_Compare_pq || (INS_DWork.DiscreteTimeIntegrator_PrevR_ow != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_m =
      INS_P.DiscreteTimeIntegrator_IC_c;
  }

  /* MinMax: '<S89>/Max2' incorporates:
   *  DataTypeConversion: '<S89>/Data Type Conversion1'
   *  DataTypeConversion: '<S89>/Data Type Conversion2'
   */
  rtb_h_R_quality = fmaxf(fmaxf(rtb_Double1, rtb_LogicalOperator_b3),
    rtb_LogicalOperator_l4);

  /* RelationalOperator: '<S125>/Compare' incorporates:
   *  Constant: '<S125>/Constant'
   */
  rtb_Compare_et = (rtb_h_R_quality > INS_P.CompareToConstant1_const_d);

  /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  if (rtb_Compare_et || (INS_DWork.DiscreteTimeIntegrator_PrevR_mt != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_f =
      INS_P.DiscreteTimeIntegrator_IC_cj;
  }

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   *  DataTypeConversion: '<S89>/Data Type Conversion2'
   */
  rtb_Compare_hp = ((real32_T)rtb_LogicalOperator_l4 >
                    INS_P.CompareToConstant1_const_f);

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  if (rtb_Compare_hp || (INS_DWork.DiscreteTimeIntegrator_PrevRe_b != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_n;
  }

  /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
   *  Constant: '<S87>/Constant'
   *  Outport: '<Root>/INS_Out'
   *  UnitDelay: '<S84>/Output'
   */
  INS_Y.INS_Out.timestamp = INS_DWork.Output_DSTATE;
  INS_Y.INS_Out.phi = rtb_Product3_p;
  INS_Y.INS_Out.theta = rtb_Product8_n;
  INS_Y.INS_Out.psi = rtb_Product1_l5;
  INS_Y.INS_Out.quat[0] = rtb_Max_c;
  INS_Y.INS_Out.quat[1] = rtb_Product15;
  INS_Y.INS_Out.quat[2] = rtb_Product12_k;
  INS_Y.INS_Out.quat[3] = rtb_Product3_eb;
  INS_Y.INS_Out.p = rtb_VectorConcatenate[0];
  INS_Y.INS_Out.q = rtb_VectorConcatenate[1];
  INS_Y.INS_Out.r = rtb_VectorConcatenate[2];
  INS_Y.INS_Out.ax = rtb_bias_g_correction_f[0];
  INS_Y.INS_Out.ay = rtb_bias_g_correction_f[1];
  INS_Y.INS_Out.az = rtb_bias_g_correction_f[2];
  INS_Y.INS_Out.vn = rtb_Sum_mt[2];
  INS_Y.INS_Out.ve = rtb_Sum_mt[3];
  INS_Y.INS_Out.vd = rtb_gps_pos_bias_idx_1;
  INS_Y.INS_Out.reserved = INS_P.Constant_Value_ny;
  INS_Y.INS_Out.lon = rtb_Scalefactor3;
  INS_Y.INS_Out.lat = rtb_Scalefactor2;
  INS_Y.INS_Out.alt = rtb_Switch_idx_2;
  INS_Y.INS_Out.x_R = rtb_Sum_mt[0];
  INS_Y.INS_Out.y_R = rtb_Sum_mt[1];
  INS_Y.INS_Out.h_R = rtb_vel_NE_0_idx_0;

  /* Switch: '<S230>/Switch' */
  if (rtb_LogicalOperator_l4) {
    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  Constant: '<S224>/Constant'
     *  Outport: '<Root>/INS_Out'
     *  Sum: '<S230>/Sum'
     */
    INS_Y.INS_Out.h_AGL = rtb_vel_NE_0_idx_0 - INS_P.Constant_Value_aq;
  } else {
    /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
     *  Constant: '<S230>/Constant'
     *  Outport: '<Root>/INS_Out'
     */
    INS_Y.INS_Out.h_AGL = INS_P.Constant_Value_dt;
  }

  /* End of Switch: '<S230>/Switch' */

  /* Gain: '<S88>/Gain10' */
  tmp_1 = fmodf(floorf(INS_P.Gain10_Gain * rtb_Relay2), 4.2949673E+9F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
   *  Constant: '<S104>/Constant'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S114>/Constant'
   *  Constant: '<S119>/Constant'
   *  Constant: '<S124>/Constant'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S134>/Constant'
   *  Constant: '<S135>/Constant'
   *  Constant: '<S226>/Constant'
   *  Constant: '<S99>/Constant'
   *  DataTypeConversion: '<S91>/Data Type Conversion'
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator'
   *  Gain: '<S88>/Gain1'
   *  Gain: '<S88>/Gain10'
   *  Gain: '<S88>/Gain11'
   *  Gain: '<S88>/Gain12'
   *  Gain: '<S88>/Gain13'
   *  Gain: '<S88>/Gain2'
   *  Gain: '<S88>/Gain4'
   *  Gain: '<S88>/Gain5'
   *  Gain: '<S88>/Gain9'
   *  Gain: '<S91>/Gain2'
   *  Gain: '<S91>/Gain3'
   *  Gain: '<S91>/Gain4'
   *  Gain: '<S91>/Gain5'
   *  Gain: '<S91>/Gain7'
   *  Logic: '<S90>/Logical Operator'
   *  Logic: '<S92>/Logical Operator'
   *  Logic: '<S93>/Logical Operator'
   *  Logic: '<S94>/Logical Operator'
   *  Logic: '<S95>/Logical Operator'
   *  Logic: '<S96>/Logical Operator'
   *  Logic: '<S97>/Logical Operator'
   *  Logic: '<S98>/Logical Operator'
   *  Memory: '<S92>/Memory'
   *  Memory: '<S93>/Memory'
   *  Memory: '<S94>/Memory'
   *  Memory: '<S95>/Memory'
   *  Memory: '<S96>/Memory'
   *  Memory: '<S97>/Memory'
   *  Memory: '<S98>/Memory'
   *  MinMax: '<S91>/Max'
   *  Outport: '<Root>/INS_Out'
   *  Product: '<S92>/Multiply'
   *  Product: '<S93>/Multiply'
   *  Product: '<S94>/Multiply'
   *  Product: '<S95>/Multiply'
   *  Product: '<S96>/Multiply'
   *  Product: '<S97>/Multiply'
   *  Product: '<S98>/Multiply'
   *  RelationalOperator: '<S104>/Compare'
   *  RelationalOperator: '<S109>/Compare'
   *  RelationalOperator: '<S114>/Compare'
   *  RelationalOperator: '<S119>/Compare'
   *  RelationalOperator: '<S124>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   *  RelationalOperator: '<S134>/Compare'
   *  RelationalOperator: '<S135>/Compare'
   *  RelationalOperator: '<S99>/Compare'
   *  Sum: '<S88>/Sum2'
   *  Sum: '<S91>/Sum'
   *  Sum: '<S91>/Sum2'
   */
  INS_Y.INS_Out.flag = (((((((((INS_P.Constant_Value_jz != 0) && (rtb_Compare_hd
    != 0) ? (uint32_T)INS_P.Gain9_Gain >> 7 : 0U) + (tmp_1 < 0.0F ? (uint32_T)
    -(int32_T)(uint32_T)-tmp_1 : (uint32_T)tmp_1)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_h < INS_P.valid_check5_time_out ?
     (int32_T)INS_DWork.Memory_PreviousInput_dc : 0) * INS_P.Gain11_Gain) >> 13))
    + (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_c <
                   INS_P.valid_check2_time_out ? (int32_T)
                   INS_DWork.Memory_PreviousInput_m : 0) * INS_P.Gain12_Gain) >>
       12)) + (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_o <
    INS_P.valid_check1_time_out ? (int32_T)INS_DWork.Memory_PreviousInput_ej : 0)
                * INS_P.Gain13_Gain) >> 11)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_j < INS_P.valid_check3_time_out ?
     (int32_T)INS_DWork.Memory_PreviousInput_c : 0) * INS_P.Gain1_Gain_kq) >> 10))
    + (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_m <
                   INS_P.valid_check4_time_out ? (int32_T)
                   INS_DWork.Memory_PreviousInput_n : 0) * INS_P.Gain2_Gain_o5) >>
       9)) + (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_f <
    INS_P.valid_check6_time_out ? (int32_T)INS_DWork.Memory_PreviousInput_o : 0)
               * INS_P.Gain4_Gain_a) >> 8)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_e < INS_P.valid_check7_time_out ?
     (int32_T)INS_DWork.Memory_PreviousInput_hx : 0) * INS_P.Gain5_Gain_e) >> 7);
  INS_Y.INS_Out.status = (((((rtb_Inclination > INS_P.Constant_Value_h5 ?
    (uint32_T)INS_P.Gain2_Gain_h >> 5 : 0U) + (rtb_LogicalOperator_b3 ?
    (uint32_T)INS_P.Gain3_Gain_f >> 4 : 0U)) + (fmaxf(rtb_Double, rtb_Double1) >
    INS_P.Constant_Value_jj ? (uint32_T)INS_P.Gain4_Gain_p >> 3 : 0U)) +
    (rtb_LogicalOperator_l4 ? (uint32_T)INS_P.Gain5_Gain_o >> 2 : 0U)) +
    rtb_Sum_na) + (rtb_LogicalOperator_mt ? (uint32_T)INS_P.Gain7_Gain >> 1 : 0U);

  /* Update for Memory: '<S5>/Memory2' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  INS_DWork.Memory2_PreviousInput_l = (rtb_Inclination >=
    INS_P.CompareToConstant_const_g);

  /* Sum: '<S25>/Sum4' incorporates:
   *  DiscreteIntegrator: '<S194>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator5'
   *  Sum: '<S28>/Sum9'
   */
  rtb_Product3_p = INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[0] -
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_g[0];
  rtb_Product1_l5 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[1] -
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_g[1];

  /* Product: '<S43>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
   */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction[i] = rtb_M_OB[i + 6] *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] + (rtb_M_OB[i + 3] *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] + rtb_M_OB[i] *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]);
  }

  /* End of Product: '<S43>/Multiply' */

  /* DiscreteIntegrator: '<S56>/Discrete-Time Integrator1' */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_o != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0] = rtb_MathFunction[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1] = rtb_MathFunction[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2] = rtb_MathFunction[2];
  }

  rtb_DiscreteTimeIntegrator1_o_i = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0];
  rtb_DiscreteTimeIntegrator1_o_0 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1];
  rtb_DiscreteTimeIntegrator1_o_1 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2];

  /* Relay: '<S57>/Relay' */
  if (rtb_Double >= INS_P.Relay_OnVal) {
    INS_DWork.Relay_Mode = true;
  } else {
    if (rtb_Double <= INS_P.Relay_OffVal) {
      INS_DWork.Relay_Mode = false;
    }
  }

  if (INS_DWork.Relay_Mode) {
    tmp_1 = INS_P.Relay_YOn;
  } else {
    tmp_1 = INS_P.Relay_YOff;
  }

  /* End of Relay: '<S57>/Relay' */

  /* Logic: '<S57>/Logical Operator1' incorporates:
   *  Logic: '<S57>/Logical Operator'
   */
  rtb_LogicalOperator1_o = ((!rtb_Compare_p1) && (tmp_1 != 0.0F));

  /* Sum: '<S57>/Sum' */
  rtb_Sum_na = (uint8_T)(rtb_LogicalOperator_mt - rtb_LogicalOperator1_o);

  /* Saturate: '<S57>/Saturation' */
  if (rtb_Sum_na > INS_P.Saturation_UpperSat_d) {
    rtb_Sum_na = INS_P.Saturation_UpperSat_d;
  } else {
    if (rtb_Sum_na < INS_P.Saturation_LowerSat_b) {
      rtb_Sum_na = INS_P.Saturation_LowerSat_b;
    }
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Sum: '<S60>/Sum1' incorporates:
   *  Constant: '<S60>/GPS_Delay'
   *  Constant: '<S60>/OptFlow_Delay'
   *  Product: '<S60>/Multiply2'
   *  Product: '<S60>/Multiply3'
   */
  rtb_Product8_n = (real32_T)(rtb_Sum_na * INS_P.OptFlow_Delay_Value +
    (rtb_LogicalOperator1_o ? (int32_T)INS_P.GPS_Delay_Value : 0));

  /* Delay: '<S43>/Delay' incorporates:
   *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator1'
   */
  if (rtb_Product8_n < 1.0F) {
    rtb_delay_acc_O_idx_0 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0];
    rtb_delay_acc_O_idx_1 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1];
    rtb_delay_acc_O_idx_2 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2];
  } else {
    if (rtb_Product8_n > 200.0F) {
      rtb_Sum_ly = 200;
    } else {
      rtb_Sum_ly = (int32_T)fmodf(rtb_Product8_n, 4.2949673E+9F);
    }

    rtb_Sum_ly = (int32_T)(200U - rtb_Sum_ly) * 3;
    rtb_delay_acc_O_idx_0 = INS_DWork.Delay_DSTATE[rtb_Sum_ly];
    rtb_delay_acc_O_idx_1 = INS_DWork.Delay_DSTATE[1 + rtb_Sum_ly];
    rtb_delay_acc_O_idx_2 = INS_DWork.Delay_DSTATE[2 + rtb_Sum_ly];
  }

  /* End of Delay: '<S43>/Delay' */

  /* RelationalOperator: '<S58>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S58>/Delay Input1'
   */
  rtb_LogicalOperator_mt = ((int32_T)rtb_LogicalOperator1_o > (int32_T)
    INS_DWork.DelayInput1_DSTATE_f);

  /* Outputs for Enabled SubSystem: '<S44>/GPS_Observer' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (rtb_LogicalOperator1_o) {
    if (!INS_DWork.GPS_Observer_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
      INS_DWork.DiscreteTimeIntegrator1_IC_L_oi = 1U;
      INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
      INS_DWork.DiscreteTimeIntegrator_DSTAT_or[0] =
        INS_P.DiscreteTimeIntegrator_IC;
      INS_DWork.DiscreteTimeIntegrator_DSTAT_or[1] =
        INS_P.DiscreteTimeIntegrator_IC;
      INS_DWork.DiscreteTimeIntegrator_DSTAT_or[2] =
        INS_P.DiscreteTimeIntegrator_IC;
      INS_DWork.DiscreteTimeIntegrator_PrevRe_c = 0;
      INS_DWork.GPS_Observer_MODE = true;
    }

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
    if (INS_DWork.DiscreteTimeIntegrator1_IC_L_oi != 0) {
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] = rtb_Product9_g;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] = rtb_vel_E;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] = rtb_vel_D;
    }

    if (rtb_LogicalOperator_mt || (INS_DWork.DiscreteTimeIntegrator1_PrevRes !=
         0)) {
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] = rtb_Product9_g;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] = rtb_vel_E;
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] = rtb_vel_D;
    }

    /* Sum: '<S62>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator1'
     */
    rtb_bias_g_correction_f[0] = rtb_Product9_g -
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0];
    rtb_bias_g_correction_f[1] = rtb_vel_E -
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1];
    rtb_bias_g_correction_f[2] = rtb_vel_D -
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2];

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_mt || (INS_DWork.DiscreteTimeIntegrator_PrevRe_c !=
         0)) {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_or[0] =
        INS_P.DiscreteTimeIntegrator_IC;
      INS_DWork.DiscreteTimeIntegrator_DSTAT_or[1] =
        INS_P.DiscreteTimeIntegrator_IC;
      INS_DWork.DiscreteTimeIntegrator_DSTAT_or[2] =
        INS_P.DiscreteTimeIntegrator_IC;
    }

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_L_oi = 0U;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_LogicalOperator_mt;

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_B.DiscreteTimeIntegrator[0] = INS_DWork.DiscreteTimeIntegrator_DSTAT_or
      [0];

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S62>/Gain2'
     *  Sum: '<S62>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] += (INS_P.Gain2_Gain_a *
      rtb_bias_g_correction_f[0] + INS_B.DiscreteTimeIntegrator[0]) *
      INS_P.DiscreteTimeIntegrator1_gainval;

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' incorporates:
     *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator1'
     *  Gain: '<S62>/Gain2'
     *  Gain: '<S62>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_or[0] += INS_P.Gain3_Gain_p *
      rtb_bias_g_correction_f[0] * INS_P.DiscreteTimeIntegrator_gainval;

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_B.DiscreteTimeIntegrator[1] = INS_DWork.DiscreteTimeIntegrator_DSTAT_or
      [1];

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S62>/Gain2'
     *  Sum: '<S62>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] += (INS_P.Gain2_Gain_a *
      rtb_bias_g_correction_f[1] + INS_B.DiscreteTimeIntegrator[1]) *
      INS_P.DiscreteTimeIntegrator1_gainval;

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' incorporates:
     *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator1'
     *  Gain: '<S62>/Gain2'
     *  Gain: '<S62>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_or[1] += INS_P.Gain3_Gain_p *
      rtb_bias_g_correction_f[1] * INS_P.DiscreteTimeIntegrator_gainval;

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_B.DiscreteTimeIntegrator[2] = INS_DWork.DiscreteTimeIntegrator_DSTAT_or
      [2];

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S62>/Gain2'
     *  Sum: '<S62>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] += (INS_P.Gain2_Gain_a *
      rtb_bias_g_correction_f[2] + INS_B.DiscreteTimeIntegrator[2]) *
      INS_P.DiscreteTimeIntegrator1_gainval;

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' incorporates:
     *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator1'
     *  Gain: '<S62>/Gain2'
     *  Gain: '<S62>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_or[2] += INS_P.Gain3_Gain_p *
      rtb_bias_g_correction_f[2] * INS_P.DiscreteTimeIntegrator_gainval;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_c = (int8_T)rtb_LogicalOperator_mt;
  } else {
    if (INS_DWork.GPS_Observer_MODE) {
      INS_DWork.GPS_Observer_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S44>/GPS_Observer' */

  /* Outputs for Enabled SubSystem: '<S44>/VIsionFlow_Observer' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (rtb_Sum_na > 0) {
    if (!INS_DWork.VIsionFlow_Observer_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S63>/Discrete-Time Integrator1' */
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_b =
        INS_P.DiscreteTimeIntegrator1_IC;

      /* InitializeConditions for DiscreteIntegrator: '<S63>/Discrete-Time Integrator' */
      INS_DWork.DiscreteTimeIntegrator_IC_LOA_k = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator1' */
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_m =
        INS_P.DiscreteTimeIntegrator1_IC_l;

      /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
      INS_DWork.DiscreteTimeIntegrator_IC_LO_kr = 1U;
      INS_DWork.VIsionFlow_Observer_MODE = true;
    }

    /* Sum: '<S63>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S63>/Discrete-Time Integrator1'
     */
    rtb_Product9_g = rtb_Multiply[0] - INS_DWork.DiscreteTimeIntegrator1_DSTAT_b;

    /* DiscreteIntegrator: '<S63>/Discrete-Time Integrator' */
    if (INS_DWork.DiscreteTimeIntegrator_IC_LOA_k != 0) {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_jh = rtb_Multiply[0];
    }

    /* Sum: '<S64>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator1'
     */
    rtb_Product8_n = rtb_Multiply[1] - INS_DWork.DiscreteTimeIntegrator1_DSTAT_m;

    /* DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
    if (INS_DWork.DiscreteTimeIntegrator_IC_LO_kr != 0) {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_cn = rtb_Multiply[1];
    }

    /* SignalConversion: '<S61>/OutportBufferForOptFlow_acc_O_mPs2' incorporates:
     *  Constant: '<S61>/Constant'
     *  DiscreteIntegrator: '<S63>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
     */
    INS_B.OutportBufferForOptFlow_acc_O_m[0] =
      INS_DWork.DiscreteTimeIntegrator_DSTAT_jh;
    INS_B.OutportBufferForOptFlow_acc_O_m[1] =
      INS_DWork.DiscreteTimeIntegrator_DSTAT_cn;
    INS_B.OutportBufferForOptFlow_acc_O_m[2] = INS_P.Constant_Value_g;

    /* Update for DiscreteIntegrator: '<S63>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S63>/Discrete-Time Integrator'
     *  Gain: '<S63>/Gain2'
     *  Sum: '<S63>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b += (INS_P.Gain2_Gain_b *
      rtb_Product9_g + INS_DWork.DiscreteTimeIntegrator_DSTAT_jh) *
      INS_P.DiscreteTimeIntegrator1_gainv_m;

    /* Update for DiscreteIntegrator: '<S63>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S63>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_IC_LOA_k = 0U;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_jh += INS_P.Gain3_Gain_i *
      rtb_Product9_g * INS_P.DiscreteTimeIntegrator_gainva_l;

    /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
     *  Gain: '<S64>/Gain2'
     *  Sum: '<S64>/Add'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_m += (INS_P.Gain2_Gain_l3 *
      rtb_Product8_n + INS_DWork.DiscreteTimeIntegrator_DSTAT_cn) *
      INS_P.DiscreteTimeIntegrator1_gainv_l;

    /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S64>/Gain3'
     */
    INS_DWork.DiscreteTimeIntegrator_IC_LO_kr = 0U;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cn += INS_P.Gain3_Gain_ih *
      rtb_Product8_n * INS_P.DiscreteTimeIntegrator_gainva_j;
  } else {
    if (INS_DWork.VIsionFlow_Observer_MODE) {
      INS_DWork.VIsionFlow_Observer_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S44>/VIsionFlow_Observer' */

  /* Sum: '<S39>/Sum' incorporates:
   *  Constant: '<S39>/gravity'
   *  Product: '<S60>/Multiply'
   *  Product: '<S60>/Multiply1'
   *  Sum: '<S60>/Sum'
   */
  rtb_Multiply[0] = ((real32_T)rtb_Sum_na *
                     INS_B.OutportBufferForOptFlow_acc_O_m[0] +
                     (rtb_LogicalOperator1_o ? INS_B.DiscreteTimeIntegrator[0] :
                      0.0F)) + INS_P.gravity_Value[0];
  rtb_Multiply[1] = ((real32_T)rtb_Sum_na *
                     INS_B.OutportBufferForOptFlow_acc_O_m[1] +
                     (rtb_LogicalOperator1_o ? INS_B.DiscreteTimeIntegrator[1] :
                      0.0F)) + INS_P.gravity_Value[1];
  rtb_Multiply[2] = ((real32_T)rtb_Sum_na *
                     INS_B.OutportBufferForOptFlow_acc_O_m[2] +
                     (rtb_LogicalOperator1_o ? INS_B.DiscreteTimeIntegrator[2] :
                      0.0F)) + INS_P.gravity_Value[2];

  /* Sum: '<S47>/Subtract' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant1'
   *  Product: '<S47>/Product'
   *  Product: '<S47>/Product1'
   */
  rtb_Sum_j_idx_3 = rtb_delay_acc_O_idx_1 * INS_P.Constant1_Value_c -
    INS_P.Constant_Value_m0 * rtb_Multiply[1];

  /* Sum: '<S47>/Subtract1' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant1'
   *  Product: '<S47>/Product2'
   *  Product: '<S47>/Product3'
   */
  rtb_Product8_n = INS_P.Constant_Value_m0 * rtb_Multiply[0] -
    rtb_delay_acc_O_idx_0 * INS_P.Constant1_Value_c;

  /* Sum: '<S47>/Subtract2' incorporates:
   *  Product: '<S47>/Product4'
   *  Product: '<S47>/Product5'
   */
  rtb_Product9_g = rtb_delay_acc_O_idx_0 * rtb_Multiply[1] -
    rtb_delay_acc_O_idx_1 * rtb_Multiply[0];

  /* DeadZone: '<S45>/Dead Zone2' */
  if (rtb_Sum_j_idx_3 > INS_P.DeadZone2_End) {
    rtb_Sum2_g[0] = rtb_Sum_j_idx_3 - INS_P.DeadZone2_End;
  } else if (rtb_Sum_j_idx_3 >= INS_P.DeadZone2_Start) {
    rtb_Sum2_g[0] = 0.0F;
  } else {
    rtb_Sum2_g[0] = rtb_Sum_j_idx_3 - INS_P.DeadZone2_Start;
  }

  if (rtb_Product8_n > INS_P.DeadZone2_End) {
    rtb_Sum2_g[1] = rtb_Product8_n - INS_P.DeadZone2_End;
  } else if (rtb_Product8_n >= INS_P.DeadZone2_Start) {
    rtb_Sum2_g[1] = 0.0F;
  } else {
    rtb_Sum2_g[1] = rtb_Product8_n - INS_P.DeadZone2_Start;
  }

  if (rtb_Product9_g > INS_P.DeadZone2_End) {
    rtb_Sum2_g[2] = rtb_Product9_g - INS_P.DeadZone2_End;
  } else if (rtb_Product9_g >= INS_P.DeadZone2_Start) {
    rtb_Sum2_g[2] = 0.0F;
  } else {
    rtb_Sum2_g[2] = rtb_Product9_g - INS_P.DeadZone2_Start;
  }

  /* DotProduct: '<S50>/Dot Product' incorporates:
   *  Sum: '<S53>/Sum of Elements'
   */
  rtb_Product8_j_tmp = rtb_delay_acc_O_idx_0 * rtb_delay_acc_O_idx_0 +
    rtb_delay_acc_O_idx_1 * rtb_delay_acc_O_idx_1;

  /* Sqrt: '<S50>/Sqrt' incorporates:
   *  DotProduct: '<S50>/Dot Product'
   */
  rtb_Product8_n = sqrtf(rtb_Product8_j_tmp);

  /* DotProduct: '<S49>/Dot Product' incorporates:
   *  Sum: '<S54>/Sum of Elements'
   */
  rtb_vel_D = rtb_Multiply[0] * rtb_Multiply[0] + rtb_Multiply[1] *
    rtb_Multiply[1];

  /* Sqrt: '<S49>/Sqrt' incorporates:
   *  DotProduct: '<S49>/Dot Product'
   */
  rtb_Product9_g = sqrtf(rtb_vel_D);

  /* MinMax: '<S48>/Max1' incorporates:
   *  Constant: '<S48>/Constant'
   *  MinMax: '<S48>/Max'
   */
  rtb_vel_E = fmaxf(INS_P.Constant_Value_ew, fmaxf(rtb_Product8_n,
    rtb_Product9_g));

  /* Sum: '<S48>/Subtract' */
  rtb_Product8_n -= rtb_Product9_g;

  /* Abs: '<S48>/Abs' */
  rtb_Product8_n = fabsf(rtb_Product8_n);

  /* Sum: '<S48>/Subtract1' incorporates:
   *  Constant: '<S48>/Constant1'
   *  Gain: '<S48>/Gain'
   *  Product: '<S48>/Divide'
   */
  rtb_Product8_n = INS_P.Constant1_Value_o - 1.0F / rtb_vel_E *
    (INS_P.Gain_Gain_a5 * rtb_Product8_n);

  /* Saturate: '<S48>/Saturation' */
  if (rtb_Product8_n > INS_P.Saturation_UpperSat_g4) {
    rtb_vel_E = INS_P.Saturation_UpperSat_g4;
  } else if (rtb_Product8_n < INS_P.Saturation_LowerSat_n) {
    rtb_vel_E = INS_P.Saturation_LowerSat_n;
  } else {
    rtb_vel_E = rtb_Product8_n;
  }

  /* End of Saturate: '<S48>/Saturation' */

  /* DiscreteFir: '<S45>/Discrete FIR Filter' */
  rtb_Product8_n = rtb_vel_E * INS_P.DiscreteFIRFilter_Coefficients[0];
  rtb_Sum_ly = 1;
  for (rtb_Saturation1_b = INS_DWork.DiscreteFIRFilter_circBuf;
       rtb_Saturation1_b < 29; rtb_Saturation1_b++) {
    rtb_Product8_n += INS_DWork.DiscreteFIRFilter_states[rtb_Saturation1_b] *
      INS_P.DiscreteFIRFilter_Coefficients[rtb_Sum_ly];
    rtb_Sum_ly++;
  }

  for (rtb_Saturation1_b = 0; rtb_Saturation1_b <
       INS_DWork.DiscreteFIRFilter_circBuf; rtb_Saturation1_b++) {
    rtb_Product8_n += INS_DWork.DiscreteFIRFilter_states[rtb_Saturation1_b] *
      INS_P.DiscreteFIRFilter_Coefficients[rtb_Sum_ly];
    rtb_Sum_ly++;
  }

  /* End of DiscreteFir: '<S45>/Discrete FIR Filter' */

  /* Logic: '<S60>/Logical Operator' */
  rtb_LogicalOperator_b3 = (rtb_LogicalOperator1_o || (rtb_Sum_na != 0));

  /* DeadZone: '<S45>/Dead Zone2' */
  if (rtb_Sum_j_idx_3 > INS_P.DeadZone2_End) {
    rtb_Product9_g = rtb_Sum_j_idx_3 - INS_P.DeadZone2_End;
  } else if (rtb_Sum_j_idx_3 >= INS_P.DeadZone2_Start) {
    rtb_Product9_g = 0.0F;
  } else {
    rtb_Product9_g = rtb_Sum_j_idx_3 - INS_P.DeadZone2_Start;
  }

  /* Saturate: '<S45>/Saturation' */
  if (rtb_Sum2_g[0] > INS_P.Saturation_UpperSat_k) {
    rtb_Product9_g = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Sum2_g[0] < INS_P.Saturation_LowerSat_kf) {
      rtb_Product9_g = INS_P.Saturation_LowerSat_kf;
    }
  }

  /* Product: '<S45>/Multiply' incorporates:
   *  Gain: '<S45>/Gain'
   *  Product: '<S45>/Multiply1'
   */
  rtb_bias_g_correction_f[0] = rtb_LogicalOperator_b3 ? INS_P.Gain_Gain_oh *
    rtb_Product9_g * rtb_Product8_n : 0.0F;

  /* Saturate: '<S45>/Saturation' */
  rtb_Product9_g = rtb_Sum2_g[1];
  if (rtb_Sum2_g[1] > INS_P.Saturation_UpperSat_k) {
    rtb_Product9_g = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Sum2_g[1] < INS_P.Saturation_LowerSat_kf) {
      rtb_Product9_g = INS_P.Saturation_LowerSat_kf;
    }
  }

  /* Product: '<S45>/Multiply' incorporates:
   *  Gain: '<S45>/Gain'
   *  Product: '<S45>/Multiply1'
   */
  rtb_bias_g_correction_f[1] = rtb_LogicalOperator_b3 ? INS_P.Gain_Gain_oh *
    rtb_Product9_g * rtb_Product8_n : 0.0F;

  /* Saturate: '<S45>/Saturation' */
  rtb_Product9_g = rtb_Sum2_g[2];
  if (rtb_Sum2_g[2] > INS_P.Saturation_UpperSat_k) {
    rtb_Product9_g = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Sum2_g[2] < INS_P.Saturation_LowerSat_kf) {
      rtb_Product9_g = INS_P.Saturation_LowerSat_kf;
    }
  }

  /* Product: '<S45>/Multiply' incorporates:
   *  Gain: '<S45>/Gain'
   *  Product: '<S45>/Multiply1'
   */
  rtb_bias_g_correction_f[2] = rtb_LogicalOperator_b3 ? INS_P.Gain_Gain_oh *
    rtb_Product9_g * rtb_Product8_n : 0.0F;

  /* Sum: '<S53>/Sum of Elements' incorporates:
   *  Math: '<S53>/Math Function'
   */
  rtb_Product8_n = rtb_Product8_j_tmp + rtb_delay_acc_O_idx_2 *
    rtb_delay_acc_O_idx_2;

  /* Math: '<S53>/Math Function1'
   *
   * About '<S53>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product8_n < 0.0F) {
    rtb_Product8_n = -sqrtf(fabsf(rtb_Product8_n));
  } else {
    rtb_Product8_n = sqrtf(rtb_Product8_n);
  }

  /* End of Math: '<S53>/Math Function1' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Constant'
   *  Product: '<S53>/Product'
   */
  if (rtb_Product8_n > INS_P.Switch_Threshold_d) {
    rtb_Sum_j_idx_3 = rtb_Product8_n;
  } else {
    rtb_delay_acc_O_idx_0 = 0.0F;
    rtb_delay_acc_O_idx_1 = 0.0F;
    rtb_delay_acc_O_idx_2 = 0.0F;
    rtb_Sum_j_idx_3 = INS_P.Constant_Value_f;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Product: '<S53>/Divide1' */
  rtb_Sum2_g[0] = rtb_delay_acc_O_idx_0 / rtb_Sum_j_idx_3;
  rtb_Sum2_g[1] = rtb_delay_acc_O_idx_1 / rtb_Sum_j_idx_3;
  rtb_Sum2_g[2] = rtb_delay_acc_O_idx_2 / rtb_Sum_j_idx_3;

  /* Sum: '<S54>/Sum of Elements' incorporates:
   *  Math: '<S54>/Math Function'
   */
  rtb_Product8_n = rtb_vel_D + rtb_Multiply[2] * rtb_Multiply[2];

  /* Math: '<S54>/Math Function1'
   *
   * About '<S54>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product8_n < 0.0F) {
    rtb_Product8_n = -sqrtf(fabsf(rtb_Product8_n));
  } else {
    rtb_Product8_n = sqrtf(rtb_Product8_n);
  }

  /* End of Math: '<S54>/Math Function1' */

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S54>/Constant'
   *  Product: '<S54>/Product'
   */
  if (rtb_Product8_n > INS_P.Switch_Threshold_b) {
    rtb_delay_acc_O_idx_0 = rtb_Multiply[0];
    rtb_delay_acc_O_idx_1 = rtb_Multiply[1];
    rtb_delay_acc_O_idx_2 = rtb_Multiply[2];
    rtb_Sum_j_idx_3 = rtb_Product8_n;
  } else {
    rtb_delay_acc_O_idx_0 = 0.0F;
    rtb_delay_acc_O_idx_1 = 0.0F;
    rtb_delay_acc_O_idx_2 = 0.0F;
    rtb_Sum_j_idx_3 = INS_P.Constant_Value_a;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Product: '<S54>/Divide1' */
  rtb_Multiply[0] = rtb_delay_acc_O_idx_0 / rtb_Sum_j_idx_3;
  rtb_Multiply[1] = rtb_delay_acc_O_idx_1 / rtb_Sum_j_idx_3;
  rtb_Multiply[2] = rtb_delay_acc_O_idx_2 / rtb_Sum_j_idx_3;

  /* Product: '<S51>/Product4' */
  rtb_Product8_n = rtb_Sum2_g[0] * rtb_Multiply[1];

  /* Product: '<S51>/Product3' */
  tmp_1 = rtb_Sum2_g[0];

  /* Product: '<S51>/Product5' */
  rtb_Product9_g = rtb_Sum2_g[1];

  /* SignalConversion: '<S55>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   *  Product: '<S51>/Product2'
   *  Product: '<S51>/Product3'
   *  Product: '<S51>/Product5'
   *  Sum: '<S51>/Subtract'
   *  Sum: '<S51>/Subtract1'
   *  Sum: '<S51>/Subtract2'
   */
  rtb_Sum2_g[0] = rtb_Sum2_g[1] * rtb_Multiply[2] - rtb_Sum2_g[2] *
    rtb_Multiply[1];
  rtb_Sum2_g[1] = rtb_Sum2_g[2] * rtb_Multiply[0] - tmp_1 * rtb_Multiply[2];
  rtb_Sum2_g[2] = rtb_Product8_n - rtb_Product9_g * rtb_Multiply[0];

  /* Gain: '<S56>/Gain' incorporates:
   *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator1'
   *  Sum: '<S56>/Sum'
   */
  rtb_MathFunction[0] = (rtb_MathFunction[0] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0]) * INS_P.Gain_Gain_lc;
  rtb_MathFunction[1] = (rtb_MathFunction[1] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1]) * INS_P.Gain_Gain_lc;
  rtb_Product8_j_tmp = (rtb_MathFunction[2] -
                        INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2]) *
    INS_P.Gain_Gain_lc;

  /* Sqrt: '<S55>/Sqrt' incorporates:
   *  Math: '<S55>/Math Function'
   *  Sum: '<S55>/Sum of Elements'
   */
  rtb_Product8_n = sqrtf((rtb_Sum2_g[0] * rtb_Sum2_g[0] + rtb_Sum2_g[1] *
    rtb_Sum2_g[1]) + rtb_Sum2_g[2] * rtb_Sum2_g[2]);

  /* Product: '<S52>/Divide1' incorporates:
   *  Constant: '<S46>/Constant8'
   */
  rtb_delay_acc_O_idx_2 = rtb_Product8_n / INS_P.Constant8_Value;

  /* Saturate: '<S52>/Saturation' */
  if (rtb_delay_acc_O_idx_2 > INS_P.Saturation_UpperSat_e) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation_UpperSat_e;
  } else {
    if (rtb_delay_acc_O_idx_2 < INS_P.Saturation_LowerSat_f) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation_LowerSat_f;
    }
  }

  /* End of Saturate: '<S52>/Saturation' */

  /* Product: '<S52>/Divide2' incorporates:
   *  Constant: '<S46>/Constant8'
   *  Trigonometry: '<S52>/Trigonometric Function'
   */
  rtb_vel_D = arm_sin_f32(rtb_delay_acc_O_idx_2) * INS_P.Constant8_Value;

  /* MinMax: '<S52>/MinMax' incorporates:
   *  Constant: '<S52>/Constant1'
   */
  rtb_Sum_j_idx_3 = fmaxf(rtb_Product8_n, INS_P.Constant1_Value_n);

  /* DataTypeConversion: '<S40>/Data Type Conversion' incorporates:
   *  Abs: '<S40>/Abs'
   *  Constant: '<S40>/Constant'
   *  Constant: '<S65>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   *  Sum: '<S40>/Subtract'
   */
  rtb_Product8_n = (real32_T)(fabsf(rtb_Product3_j_tmp - INS_P.Constant_Value_n2)
    <= INS_P.CompareToConstant_const_n);

  /* Switch: '<S205>/Switch' incorporates:
   *  Math: '<S205>/Math Function1'
   *  Product: '<S205>/Product2'
   */
  if (rtb_Compare_ju) {
    for (i = 0; i < 3; i++) {
      rtb_Gauss_to_uT[i] = rtb_Transpose2_tmp[i + 6] * rtb_Product3_i[2] +
        (rtb_Transpose2_tmp[i + 3] * rtb_Product3_i[1] + rtb_Transpose2_tmp[i] *
         rtb_Product3_i[0]);
    }
  }

  /* Gain: '<S69>/mag_correct_gain' incorporates:
   *  Product: '<S69>/MX Product4'
   *  Selector: '<S69>/Selector4'
   */
  rtb_Product9_g = ((rtb_M_OB[1] * rtb_Gauss_to_uT[0] + rtb_M_OB[4] *
                     rtb_Gauss_to_uT[1]) + rtb_M_OB[7] * rtb_Gauss_to_uT[2]) *
    INS_P.mag_correct_gain_Gain;

  /* Relay: '<S68>/Relay1' */
  if (rtb_Inclination >= INS_P.Relay1_OnVal) {
    INS_DWork.Relay1_Mode = true;
  } else {
    if (rtb_Inclination <= INS_P.Relay1_OffVal) {
      INS_DWork.Relay1_Mode = false;
    }
  }

  if (INS_DWork.Relay1_Mode) {
    tmp_1 = INS_P.Relay1_YOn;
  } else {
    tmp_1 = INS_P.Relay1_YOff;
  }

  /* End of Relay: '<S68>/Relay1' */

  /* Logic: '<S68>/Logical Operator' incorporates:
   *  Logic: '<S41>/Logical Operator'
   */
  rtb_LogicalOperator_b3 = (((rtb_Relay2 != 0.0F) || rtb_Compare_p1) && (tmp_1
    != 0.0F));

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S46>/Gain'
   *  Product: '<S52>/Divide'
   *  Product: '<S69>/MX Product3'
   *  Selector: '<S69>/Selector2'
   *  Sum: '<S42>/Sum'
   */
  rtb_Product3_j_tmp = (rtb_Sum2_g[0] * rtb_vel_D / rtb_Sum_j_idx_3 *
                        INS_P.Gain_Gain_ok[0] + rtb_bias_g_correction_f[0]) +
    (rtb_LogicalOperator_b3 ? rtb_M_OB[2] * rtb_Product9_g : 0.0F);
  rtb_delay_acc_O_idx_2 = (rtb_Sum2_g[1] * rtb_vel_D / rtb_Sum_j_idx_3 *
    INS_P.Gain_Gain_ok[1] + rtb_bias_g_correction_f[1]) +
    (rtb_LogicalOperator_b3 ? rtb_M_OB[5] * rtb_Product9_g : 0.0F);
  rtb_vel_D = (rtb_Sum2_g[2] * rtb_vel_D / rtb_Sum_j_idx_3 * INS_P.Gain_Gain_ok
               [2] + rtb_bias_g_correction_f[2]) + (rtb_LogicalOperator_b3 ?
    rtb_M_OB[8] * rtb_Product9_g : 0.0F);
  for (i = 0; i < 3; i++) {
    /* Product: '<S6>/Multiply' incorporates:
     *  Math: '<S72>/Transpose2'
     */
    rtb_Product9_g = rtb_Transpose2_tmp[i + 6] * rtb_vel_D +
      (rtb_Transpose2_tmp[i + 3] * rtb_delay_acc_O_idx_2 + rtb_Transpose2_tmp[i]
       * rtb_Product3_j_tmp);

    /* Product: '<S40>/MX Product1' */
    rtb_bias_g_correction_f[i] = rtb_Product9_g * rtb_Product8_n;

    /* Sum: '<S7>/Sum2' */
    rtb_Product9_g += rtb_VectorConcatenate[i];

    /* Gain: '<S195>/Gain' incorporates:
     *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator1'
     *  Sum: '<S195>/Sum'
     */
    rtb_delay_acc_O_idx_0 = (rtb_VectorConcatenate_o[i] -
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[i]) * INS_P.Gain_Gain_m2;

    /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator'
     */
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[i] +=
      INS_P.DiscreteTimeIntegrator1_gainv_p *
      INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[i];

    /* Update for Memory: '<S5>/Memory1' */
    INS_DWork.Memory1_PreviousInput[i] = rtb_Gauss_to_uT[i];

    /* Product: '<S6>/Multiply' incorporates:
     *  Math: '<S72>/Transpose2'
     */
    rtb_Sum2_g[i] = rtb_Product9_g;

    /* Gain: '<S195>/Gain' incorporates:
     *  Sum: '<S195>/Sum'
     */
    rtb_VectorConcatenate_o[i] = rtb_delay_acc_O_idx_0;

    /* Gain: '<S194>/Gain' incorporates:
     *  DiscreteIntegrator: '<S194>/Discrete-Time Integrator1'
     *  Sum: '<S194>/Sum'
     */
    rtb_DiscreteTimeIntegrator1_g[i] = (rtb_DiscreteTimeIntegrator1_g[i] -
      INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[i]) * INS_P.Gain_Gain_mz;
  }

  /* Gain: '<S67>/Gain' incorporates:
   *  Logic: '<S67>/Logical Operator'
   */
  rtb_Product8_n = rtb_Relay2 == 0.0F ? (real32_T)INS_P.Gain_Gain_g * 0.015625F :
    0.0F;

  /* RateLimiter: '<S67>/Rate Limiter' */
  rtb_Inclination = rtb_Product8_n - INS_DWork.PrevY;
  if (rtb_Inclination > INS_P.RateLimiter_RisingLim) {
    rtb_Product8_n = INS_DWork.PrevY + INS_P.RateLimiter_RisingLim;
  } else {
    if (rtb_Inclination < INS_P.RateLimiter_FallingLim) {
      rtb_Product8_n = INS_DWork.PrevY + INS_P.RateLimiter_FallingLim;
    }
  }

  INS_DWork.PrevY = rtb_Product8_n;

  /* End of RateLimiter: '<S67>/Rate Limiter' */

  /* Saturate: '<S67>/Saturation' */
  if (rtb_Product8_n > INS_P.Saturation_UpperSat_ky) {
    rtb_Product8_n = INS_P.Saturation_UpperSat_ky;
  } else {
    if (rtb_Product8_n < INS_P.Saturation_LowerSat_f3) {
      rtb_Product8_n = INS_P.Saturation_LowerSat_f3;
    }
  }

  /* End of Saturate: '<S67>/Saturation' */

  /* Sum: '<S76>/Add' incorporates:
   *  Constant: '<S72>/Constant'
   *  Product: '<S76>/Product'
   *  Product: '<S76>/Product1'
   *  Product: '<S76>/Product2'
   *  Product: '<S76>/Product3'
   */
  rtb_delay_acc_O_idx_0 = ((rtb_Max_c * INS_P.Constant_Value_p - rtb_Product15 *
    rtb_Sum2_g[0]) - rtb_Product12_k * rtb_Sum2_g[1]) - rtb_Product3_eb *
    rtb_Sum2_g[2];

  /* Sum: '<S76>/Add1' incorporates:
   *  Constant: '<S72>/Constant'
   *  Product: '<S76>/Product4'
   *  Product: '<S76>/Product5'
   *  Product: '<S76>/Product6'
   *  Product: '<S76>/Product7'
   */
  rtb_delay_acc_O_idx_1 = ((rtb_Max_c * rtb_Sum2_g[0] + rtb_Product15 *
    INS_P.Constant_Value_p) + rtb_Product12_k * rtb_Sum2_g[2]) - rtb_Product3_eb
    * rtb_Sum2_g[1];

  /* Sum: '<S76>/Add2' incorporates:
   *  Constant: '<S72>/Constant'
   *  Product: '<S76>/Product10'
   *  Product: '<S76>/Product11'
   *  Product: '<S76>/Product8'
   *  Product: '<S76>/Product9'
   */
  rtb_delay_acc_O_idx_2 = ((rtb_Max_c * rtb_Sum2_g[1] - rtb_Product15 *
    rtb_Sum2_g[2]) + rtb_Product12_k * INS_P.Constant_Value_p) + rtb_Product3_eb
    * rtb_Sum2_g[0];

  /* Product: '<S76>/Product14' */
  rtb_Max_c *= rtb_Sum2_g[2];

  /* Product: '<S76>/Product15' */
  rtb_Product15 *= rtb_Sum2_g[1];

  /* Product: '<S76>/Product12' */
  rtb_Product12_k *= rtb_Sum2_g[0];

  /* RelationalOperator: '<S103>/Compare' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S103>/Constant'
   *  RelationalOperator: '<S101>/Compare'
   */
  rtb_Compare_p1 = ((rtb_Double > INS_P.CompareToConstant2_const) > (int32_T)
                    INS_P.Constant_Value_f4);

  /* RelationalOperator: '<S108>/Compare' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S108>/Constant'
   *  RelationalOperator: '<S106>/Compare'
   */
  rtb_LogicalOperator_mt = ((rtb_baro_height_bias >
    INS_P.CompareToConstant2_const_j) > (int32_T)INS_P.Constant_Value_nl);

  /* RelationalOperator: '<S113>/Compare' incorporates:
   *  Constant: '<S111>/Constant'
   *  Constant: '<S113>/Constant'
   *  RelationalOperator: '<S111>/Compare'
   */
  rtb_LogicalOperator_b3 = ((rtb_Double1 > INS_P.CompareToConstant2_const_e) >
    (int32_T)INS_P.Constant_Value_pn);

  /* RelationalOperator: '<S118>/Compare' incorporates:
   *  Constant: '<S116>/Constant'
   *  Constant: '<S118>/Constant'
   *  RelationalOperator: '<S116>/Compare'
   */
  rtb_Compare_ju = ((rtb_vel_NE_0_idx_1 > INS_P.CompareToConstant2_const_m) >
                    (int32_T)INS_P.Constant_Value_pv);

  /* RelationalOperator: '<S123>/Compare' incorporates:
   *  Constant: '<S121>/Constant'
   *  Constant: '<S123>/Constant'
   *  RelationalOperator: '<S121>/Compare'
   */
  rtb_Compare_h2 = (((int32_T)rtb_Compare_h2 > (int32_T)
                     INS_P.CompareToConstant2_const_i) > (int32_T)
                    INS_P.Constant_Value_l1);

  /* RelationalOperator: '<S128>/Compare' incorporates:
   *  Constant: '<S126>/Constant'
   *  Constant: '<S128>/Constant'
   *  RelationalOperator: '<S126>/Compare'
   */
  rtb_Compare_an = ((rtb_h_R_quality > INS_P.CompareToConstant2_const_k) >
                    (int32_T)INS_P.Constant_Value_d0);

  /* RelationalOperator: '<S133>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   *  Constant: '<S133>/Constant'
   *  DataTypeConversion: '<S89>/Data Type Conversion2'
   *  RelationalOperator: '<S131>/Compare'
   */
  rtb_LogicalOperator_l4 = (((real32_T)rtb_LogicalOperator_l4 >
    INS_P.CompareToConstant2_const_g) > (int32_T)INS_P.Constant_Value_ng);

  /* Update for UnitDelay: '<S84>/Output' incorporates:
   *  Constant: '<S84>/Constant'
   *  Sum: '<S84>/Add'
   */
  INS_DWork.Output_DSTATE += INS_EXPORT.period;

  /* Update for UnitDelay: '<S181>/Delay Input1' incorporates:
   *  Inport: '<Root>/IMU1'
   */
  INS_DWork.DelayInput1_DSTATE = INS_U.IMU1.timestamp;

  /* Update for DiscreteIntegrator: '<S174>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S174>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_l + (real32_T)
    INS_EXPORT.period;
  if (tmp_1 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l = (uint32_T)tmp_1;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S174>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S187>/Delay Input1' incorporates:
   *  Inport: '<Root>/IMU2'
   */
  INS_DWork.DelayInput1_DSTATE_h = INS_U.IMU2.timestamp;

  /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S176>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_d + (real32_T)
    INS_EXPORT.period;
  if (tmp_1 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d = (uint32_T)tmp_1;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for Delay: '<S31>/Delay' */
  INS_DWork.Delay_DSTATE_i = rtb_Add_kz;

  /* Update for UnitDelay: '<S34>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_p = rtb_LowerTest_b;

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S72>/Constant'
   *  Gain: '<S72>/Gain2'
   *  Product: '<S76>/Product13'
   *  Sum: '<S76>/Add3'
   */
  INS_DWork.DiscreteTimeIntegrator_IC_LOADI = 0U;
  INS_DWork.DiscreteTimeIntegrator_DSTATE[0] += INS_P.Gain2_Gain_i *
    rtb_delay_acc_O_idx_0 * INS_P.DiscreteTimeIntegrator_gainv_ji;
  INS_DWork.DiscreteTimeIntegrator_DSTATE[1] += INS_P.Gain2_Gain_i *
    rtb_delay_acc_O_idx_1 * INS_P.DiscreteTimeIntegrator_gainv_ji;
  INS_DWork.DiscreteTimeIntegrator_DSTATE[2] += INS_P.Gain2_Gain_i *
    rtb_delay_acc_O_idx_2 * INS_P.DiscreteTimeIntegrator_gainv_ji;
  INS_DWork.DiscreteTimeIntegrator_DSTATE[3] += (((rtb_Max_c + rtb_Product15) -
    rtb_Product12_k) + rtb_Product3_eb * INS_P.Constant_Value_p) *
    INS_P.Gain2_Gain_i * INS_P.DiscreteTimeIntegrator_gainv_ji;
  INS_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UpperTest_g;

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_k = 0U;

  /* Saturate: '<S40>/Saturation2' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   *  Gain: '<S40>/Gain3'
   */
  rtb_delay_acc_O_idx_2 = INS_P.Gain3_Gain_ke * rtb_bias_g_correction_f[0];
  if (rtb_delay_acc_O_idx_2 > INS_P.Saturation2_UpperSat_h) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation2_UpperSat_h;
  } else {
    if (rtb_delay_acc_O_idx_2 < INS_P.Saturation2_LowerSat_o) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation2_LowerSat_o;
    }
  }

  /* Saturate: '<S67>/Saturation1' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   */
  if (rtb_VectorConcatenate[0] > INS_P.Saturation1_UpperSat_p) {
    rtb_Product3_eb = INS_P.Saturation1_UpperSat_p;
  } else if (rtb_VectorConcatenate[0] < INS_P.Saturation1_LowerSat_jl) {
    rtb_Product3_eb = INS_P.Saturation1_LowerSat_jl;
  } else {
    rtb_Product3_eb = rtb_VectorConcatenate[0];
  }

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator2' incorporates:
   *  Gain: '<S40>/Gain4'
   *  Product: '<S67>/Product'
   *  Sum: '<S40>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] += (rtb_delay_acc_O_idx_2 -
    rtb_Product3_eb * rtb_Relay2 * rtb_Product8_n * INS_P.Gain4_Gain_d) *
    INS_P.DiscreteTimeIntegrator2_gainval;
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

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S194>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_i *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0];

  /* Saturate: '<S40>/Saturation2' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   *  Gain: '<S40>/Gain3'
   */
  rtb_delay_acc_O_idx_2 = INS_P.Gain3_Gain_ke * rtb_bias_g_correction_f[1];
  if (rtb_delay_acc_O_idx_2 > INS_P.Saturation2_UpperSat_h) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation2_UpperSat_h;
  } else {
    if (rtb_delay_acc_O_idx_2 < INS_P.Saturation2_LowerSat_o) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation2_LowerSat_o;
    }
  }

  /* Saturate: '<S67>/Saturation1' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   */
  if (rtb_VectorConcatenate[1] > INS_P.Saturation1_UpperSat_p) {
    rtb_Product3_eb = INS_P.Saturation1_UpperSat_p;
  } else if (rtb_VectorConcatenate[1] < INS_P.Saturation1_LowerSat_jl) {
    rtb_Product3_eb = INS_P.Saturation1_LowerSat_jl;
  } else {
    rtb_Product3_eb = rtb_VectorConcatenate[1];
  }

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator2' incorporates:
   *  Gain: '<S40>/Gain4'
   *  Product: '<S67>/Product'
   *  Sum: '<S40>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] += (rtb_delay_acc_O_idx_2 -
    rtb_Product3_eb * rtb_Relay2 * rtb_Product8_n * INS_P.Gain4_Gain_d) *
    INS_P.DiscreteTimeIntegrator2_gainval;
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

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S194>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_i *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1];

  /* Saturate: '<S40>/Saturation2' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   *  Gain: '<S40>/Gain3'
   */
  rtb_delay_acc_O_idx_2 = INS_P.Gain3_Gain_ke * rtb_bias_g_correction_f[2];
  if (rtb_delay_acc_O_idx_2 > INS_P.Saturation2_UpperSat_h) {
    rtb_delay_acc_O_idx_2 = INS_P.Saturation2_UpperSat_h;
  } else {
    if (rtb_delay_acc_O_idx_2 < INS_P.Saturation2_LowerSat_o) {
      rtb_delay_acc_O_idx_2 = INS_P.Saturation2_LowerSat_o;
    }
  }

  /* Saturate: '<S67>/Saturation1' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator2'
   */
  if (rtb_VectorConcatenate[2] > INS_P.Saturation1_UpperSat_p) {
    rtb_Product3_eb = INS_P.Saturation1_UpperSat_p;
  } else if (rtb_VectorConcatenate[2] < INS_P.Saturation1_LowerSat_jl) {
    rtb_Product3_eb = INS_P.Saturation1_LowerSat_jl;
  } else {
    rtb_Product3_eb = rtb_VectorConcatenate[2];
  }

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator2' incorporates:
   *  Gain: '<S40>/Gain4'
   *  Product: '<S67>/Product'
   *  Sum: '<S40>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] += (rtb_delay_acc_O_idx_2 -
    rtb_Product3_eb * rtb_Relay2 * rtb_Product8_n * INS_P.Gain4_Gain_d) *
    INS_P.DiscreteTimeIntegrator2_gainval;
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

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S194>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_a[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_i *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Sum: '<S163>/Sum' incorporates:
   *  Constant: '<S167>/Constant'
   *  Inport: '<Root>/GPS_uBlox'
   *  Logic: '<S163>/Logical Operator'
   *  RelationalOperator: '<S167>/Compare'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  rtb_Sum_ly = ((INS_U.GPS_uBlox.hAcc < INS_P.CompareToConstant_const_d) &&
                (rtb_Compare_ou != 0) && (rtb_Compare_iu != 0)) +
    INS_DWork.UnitDelay_DSTATE;

  /* Saturate: '<S163>/Saturation' */
  if (rtb_Sum_ly > INS_P.Saturation_UpperSat_a) {
    /* Update for UnitDelay: '<S163>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_UpperSat_a;
  } else if (rtb_Sum_ly < INS_P.Saturation_LowerSat) {
    /* Update for UnitDelay: '<S163>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_LowerSat;
  } else {
    /* Update for UnitDelay: '<S163>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = rtb_Sum_ly;
  }

  /* End of Saturate: '<S163>/Saturation' */

  /* Update for UnitDelay: '<S171>/Delay Input1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  INS_DWork.DelayInput1_DSTATE_i = INS_U.GPS_uBlox.timestamp;

  /* Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S166>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_i + (real32_T)
    INS_EXPORT.period;
  if (tmp_1 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i = (uint32_T)tmp_1;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S218>/Delay Input1' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   */
  INS_DWork.DelayInput1_DSTATE_l = INS_U.Optical_Flow.timestamp_ms;

  /* Update for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S216>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_nz +
    INS_P.Constant_Value_jp;
  if (tmp_1 < 4.2949673E+9F) {
    if (tmp_1 >= 0.0F) {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_nz = (uint32_T)tmp_1;
    } else {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_nz = 0U;
    }
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nz = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S298>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_o = rtb_Compare_e;

  /* Update for UnitDelay: '<S305>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_m = rtb_Compare_a;

  /* Update for Memory: '<S4>/Memory' */
  INS_DWork.Memory_9_PreviousInput = rtb_Sum_mt[0];
  INS_DWork.Memory_10_PreviousInput = rtb_Sum_mt[1];

  /* Update for Memory: '<S302>/memory3' */
  INS_DWork.memory3_PreviousInput[0] = rtb_WGS84_derivatives_ref_idx_0;

  /* Update for Memory: '<S302>/memory2' */
  INS_DWork.memory2_PreviousInput[0] = rtb_N;

  /* Update for Memory: '<S302>/memory3' */
  INS_DWork.memory3_PreviousInput[1] = rtb_Gain6;

  /* Update for Memory: '<S302>/memory2' */
  INS_DWork.memory2_PreviousInput[1] = rtb_WGS84_pos_ref_idx_1;

  /* Update for Memory: '<S246>/Memory' */
  for (i = 0; i < 6; i++) {
    INS_DWork.Memory_PreviousInput[i] = rtb_Sum_mt[i];
  }

  /* End of Update for Memory: '<S246>/Memory' */

  /* Update for UnitDelay: '<S222>/Delay Input1' incorporates:
   *  Inport: '<Root>/Sonar'
   */
  INS_DWork.DelayInput1_DSTATE_c = INS_U.Sonar.timestamp_ms;

  /* Update for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S219>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_k + (real32_T)
    INS_EXPORT.period;
  if (tmp_1 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k = (uint32_T)tmp_1;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' */

  /* Switch: '<S219>/Switch' */
  if (rtb_Compare_nt) {
    /* Update for Memory: '<S219>/Memory' incorporates:
     *  Constant: '<S219>/Constant1'
     */
    INS_DWork.Memory_PreviousInput_ph = INS_P.Constant1_Value_l;
  }

  /* End of Switch: '<S219>/Switch' */

  /* Update for UnitDelay: '<S153>/Delay Input1' incorporates:
   *  Inport: '<Root>/Barometer'
   */
  INS_DWork.DelayInput1_DSTATE_g = INS_U.Barometer.timestamp;

  /* Update for Memory: '<S145>/Memory2' incorporates:
   *  Sum: '<S145>/Sum1'
   */
  INS_DWork.Memory2_PreviousInput = qY_0;

  /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S145>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_ev + (real32_T)
    INS_EXPORT.period;
  if (tmp_1 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev = (uint32_T)tmp_1;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S296>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_j = rtb_GPS_vaid;

  /* Update for Memory: '<S4>/Memory' */
  INS_DWork.Memory_11_PreviousInput = rtb_vel_NE_0_idx_0;

  /* Update for UnitDelay: '<S303>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dp = rtb_Memory_ph;

  /* Update for Memory: '<S301>/memory2' */
  INS_DWork.memory2_PreviousInput_j = rtb_Scalefactor1;

  /* Update for Memory: '<S276>/Memory' */
  INS_DWork.Memory_PreviousInput_p[0] = rtb_vel_NE_0_idx_0;
  INS_DWork.Memory_PreviousInput_p[1] = rtb_gps_pos_bias_idx_1;
  INS_DWork.Memory_PreviousInput_p[2] = rtb_MathFunction_e_idx_2;

  /* Update for UnitDelay: '<S75>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dy = rtb_UpperTest_g;

  /* Update for Memory: '<S71>/Memory' */
  INS_DWork.Memory_PreviousInput_l = rtb_Compare_hd;

  /* Saturate: '<S10>/Saturation2' */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_n > INS_P.Saturation2_UpperSat_i)
  {
    tmp_1 = INS_P.Saturation2_UpperSat_i;
  } else if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_n <
             INS_P.Saturation2_LowerSat_g) {
    tmp_1 = INS_P.Saturation2_LowerSat_g;
  } else {
    tmp_1 = INS_DWork.DiscreteTimeIntegrator5_DSTAT_n;
  }

  /* End of Saturate: '<S10>/Saturation2' */

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S27>/Gain2'
   *  Sum: '<S27>/Sum9'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTATE += (tmp_1 -
    INS_DWork.DiscreteTimeIntegrator5_DSTATE) * INS_P.Gain2_Gain_ae *
    INS_P.DiscreteTimeIntegrator5_gainval;

  /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S96>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_h +=
    INS_P.DiscreteTimeIntegrator_gainva_i * INS_P.Constant_Value_kn;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_m = (int8_T)rtb_Compare_f3;

  /* Update for Memory: '<S96>/Memory' incorporates:
   *  Logic: '<S96>/Logical Operator1'
   *  RelationalOperator: '<S122>/FixPt Relational Operator'
   *  UnitDelay: '<S122>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_dc = (((int32_T)rtb_Compare_h2 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_ng) || INS_DWork.Memory_PreviousInput_dc);

  /* Update for UnitDelay: '<S201>/Delay Input1' incorporates:
   *  Inport: '<Root>/MAG'
   */
  INS_DWork.DelayInput1_DSTATE_n = INS_U.MAG.timestamp;

  /* Update for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S197>/Constant'
   */
  tmp_1 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_lg + (real32_T)
    INS_EXPORT.period;
  if (tmp_1 < 4.2949673E+9F) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg = (uint32_T)tmp_1;
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S93>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_c +=
    INS_P.DiscreteTimeIntegrator_gainva_p * INS_P.Constant_Value_mh;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_o = (int8_T)rtb_pos_ever_valid_n;

  /* Update for Memory: '<S93>/Memory' incorporates:
   *  Logic: '<S93>/Logical Operator1'
   *  RelationalOperator: '<S107>/FixPt Relational Operator'
   *  UnitDelay: '<S107>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_m = (((int32_T)rtb_LogicalOperator_mt >
    (int32_T)INS_DWork.DelayInput1_DSTATE_of) ||
    INS_DWork.Memory_PreviousInput_m);

  /* Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S92>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_o +=
    INS_P.DiscreteTimeIntegrator_gainva_b * INS_P.Constant_Value_lp;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_LogicalOperator2_m;

  /* Update for Memory: '<S92>/Memory' incorporates:
   *  Logic: '<S92>/Logical Operator1'
   *  RelationalOperator: '<S102>/FixPt Relational Operator'
   *  UnitDelay: '<S102>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_ej = (((int32_T)rtb_Compare_p1 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_b) || INS_DWork.Memory_PreviousInput_ej);

  /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S94>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_j +=
    INS_P.DiscreteTimeIntegrator_gainv_lt * INS_P.Constant_Value_pz;
  INS_DWork.DiscreteTimeIntegrator_PrevR_or = (int8_T)rtb_Compare_bg;

  /* Update for Memory: '<S94>/Memory' incorporates:
   *  Logic: '<S94>/Logical Operator1'
   *  RelationalOperator: '<S112>/FixPt Relational Operator'
   *  UnitDelay: '<S112>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_c = (((int32_T)rtb_LogicalOperator_b3 >
    (int32_T)INS_DWork.DelayInput1_DSTATE_o1) ||
    INS_DWork.Memory_PreviousInput_c);

  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S95>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_m +=
    INS_P.DiscreteTimeIntegrator_gainv_pi * INS_P.Constant_Value_kt;
  INS_DWork.DiscreteTimeIntegrator_PrevR_ow = (int8_T)rtb_Compare_pq;

  /* Update for Memory: '<S95>/Memory' incorporates:
   *  Logic: '<S95>/Logical Operator1'
   *  RelationalOperator: '<S117>/FixPt Relational Operator'
   *  UnitDelay: '<S117>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_n = (((int32_T)rtb_Compare_ju > (int32_T)
    INS_DWork.DelayInput1_DSTATE_a) || INS_DWork.Memory_PreviousInput_n);

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S97>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_f +=
    INS_P.DiscreteTimeIntegrator_gainva_e * INS_P.Constant_Value_ow;
  INS_DWork.DiscreteTimeIntegrator_PrevR_mt = (int8_T)rtb_Compare_et;

  /* Update for Memory: '<S97>/Memory' incorporates:
   *  Logic: '<S97>/Logical Operator1'
   *  RelationalOperator: '<S127>/FixPt Relational Operator'
   *  UnitDelay: '<S127>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_o = (((int32_T)rtb_Compare_an > (int32_T)
    INS_DWork.DelayInput1_DSTATE_cr) || INS_DWork.Memory_PreviousInput_o);

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S98>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_e +=
    INS_P.DiscreteTimeIntegrator_gainv_e3 * INS_P.Constant_Value_k1;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_b = (int8_T)rtb_Compare_hp;

  /* Update for Memory: '<S98>/Memory' incorporates:
   *  Logic: '<S98>/Logical Operator1'
   *  RelationalOperator: '<S132>/FixPt Relational Operator'
   *  UnitDelay: '<S132>/Delay Input1'
   */
  INS_DWork.Memory_PreviousInput_hx = (((int32_T)rtb_LogicalOperator_l4 >
    (int32_T)INS_DWork.DelayInput1_DSTATE_dt) ||
    INS_DWork.Memory_PreviousInput_hx);

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S28>/Gain2'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_g[0] += INS_P.Gain2_Gain_n *
    rtb_Product3_p * INS_P.DiscreteTimeIntegrator5_gainv_j;
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_g[1] += INS_P.Gain2_Gain_n *
    rtb_Product1_l5 * INS_P.DiscreteTimeIntegrator5_gainv_j;

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator5' incorporates:
   *  Abs: '<S10>/Abs'
   *  Gain: '<S26>/Gain2'
   *  MinMax: '<S10>/MinMax1'
   *  Sum: '<S25>/Sum4'
   *  Sum: '<S26>/Sum9'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_n += (fmaxf(fabsf(rtb_Product3_p),
    fabsf(rtb_Product1_l5)) - INS_DWork.DiscreteTimeIntegrator5_DSTAT_n) *
    INS_P.Gain2_Gain_o1 * INS_P.DiscreteTimeIntegrator5_gain_jf;

  /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_o = 0U;
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_d *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0];
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_d *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1];
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_n[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_d *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2];

  /* Update for Delay: '<S43>/Delay' */
  for (i = 0; i < 199; i++) {
    rtb_Sum_ly = (i + 1) * 3;
    INS_DWork.Delay_DSTATE[i * 3] = INS_DWork.Delay_DSTATE[rtb_Sum_ly];
    INS_DWork.Delay_DSTATE[i * 3 + 1] = INS_DWork.Delay_DSTATE[rtb_Sum_ly + 1];
    INS_DWork.Delay_DSTATE[i * 3 + 2] = INS_DWork.Delay_DSTATE[rtb_Sum_ly + 2];
  }

  INS_DWork.Delay_DSTATE[597] = rtb_DiscreteTimeIntegrator1_o_i;
  INS_DWork.Delay_DSTATE[598] = rtb_DiscreteTimeIntegrator1_o_0;
  INS_DWork.Delay_DSTATE[599] = rtb_DiscreteTimeIntegrator1_o_1;

  /* End of Update for Delay: '<S43>/Delay' */

  /* Update for UnitDelay: '<S58>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_f = rtb_LogicalOperator1_o;

  /* Update for DiscreteFir: '<S45>/Discrete FIR Filter' */
  /* Update circular buffer index */
  INS_DWork.DiscreteFIRFilter_circBuf--;
  if (INS_DWork.DiscreteFIRFilter_circBuf < 0) {
    INS_DWork.DiscreteFIRFilter_circBuf = 28;
  }

  /* Update circular buffer */
  INS_DWork.DiscreteFIRFilter_states[INS_DWork.DiscreteFIRFilter_circBuf] =
    rtb_vel_E;

  /* End of Update for DiscreteFir: '<S45>/Discrete FIR Filter' */

  /* Update for UnitDelay: '<S102>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_b = rtb_Compare_p1;

  /* Update for UnitDelay: '<S107>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_of = rtb_LogicalOperator_mt;

  /* Update for UnitDelay: '<S112>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_o1 = rtb_LogicalOperator_b3;

  /* Update for UnitDelay: '<S117>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_a = rtb_Compare_ju;

  /* Update for UnitDelay: '<S122>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ng = rtb_Compare_h2;

  /* Update for UnitDelay: '<S127>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_cr = rtb_Compare_an;

  /* Update for UnitDelay: '<S132>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dt = rtb_LogicalOperator_l4;

  /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S56>/Gain1'
   *  Sum: '<S56>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0] += (INS_P.Gain1_Gain_mk *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0] + rtb_MathFunction[0]) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S194>/Gain1'
   *  Sum: '<S194>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] += (INS_P.Gain1_Gain_kl *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] +
    rtb_DiscreteTimeIntegrator1_g[0]) * INS_P.DiscreteTimeIntegrator_gainva_k;

  /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S195>/Gain1'
   *  Sum: '<S195>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[0] += (INS_P.Gain1_Gain_e1 *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[0] + rtb_VectorConcatenate_o[0]) *
    INS_P.DiscreteTimeIntegrator_gainva_m;

  /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S56>/Gain1'
   *  Sum: '<S56>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1] += (INS_P.Gain1_Gain_mk *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1] + rtb_MathFunction[1]) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S194>/Gain1'
   *  Sum: '<S194>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] += (INS_P.Gain1_Gain_kl *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] +
    rtb_DiscreteTimeIntegrator1_g[1]) * INS_P.DiscreteTimeIntegrator_gainva_k;

  /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S195>/Gain1'
   *  Sum: '<S195>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[1] += (INS_P.Gain1_Gain_e1 *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[1] + rtb_VectorConcatenate_o[1]) *
    INS_P.DiscreteTimeIntegrator_gainva_m;

  /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S56>/Gain1'
   *  Sum: '<S56>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2] += (INS_P.Gain1_Gain_mk *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2] + rtb_Product8_j_tmp) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  /* Update for DiscreteIntegrator: '<S194>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S194>/Gain1'
   *  Sum: '<S194>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_n[2] += (INS_P.Gain1_Gain_kl *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[2] +
    rtb_DiscreteTimeIntegrator1_g[2]) * INS_P.DiscreteTimeIntegrator_gainva_k;

  /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S195>/Gain1'
   *  Sum: '<S195>/Add'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[2] += (INS_P.Gain1_Gain_e1 *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[2] + rtb_VectorConcatenate_o[2]) *
    INS_P.DiscreteTimeIntegrator_gainva_m;
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
    INS_PrevZCSigState.WGS_Derivative_Trig_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.x_delay_Reset_ZCE_b = POS_ZCSIG;
    INS_PrevZCSigState.x_delay1_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay1_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.x_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.h_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vd_delay_Reset_ZCE = POS_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S84>/Output' */
    INS_DWork.Output_DSTATE = INS_P.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S181>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE = INS_P.DetectChange_vinit_md;

    /* InitializeConditions for DiscreteIntegrator: '<S174>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l =
      INS_P.DiscreteTimeIntegrator_IC_b;

    /* InitializeConditions for UnitDelay: '<S187>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_h = INS_P.DetectChange_vinit_j;

    /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_IC_p;

    /* InitializeConditions for Memory: '<S5>/Memory2' */
    INS_DWork.Memory2_PreviousInput_l = INS_P.Memory2_InitialCondition_ar;

    /* InitializeConditions for DiscreteIntegrator: '<S195>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    /* InitializeConditions for Delay: '<S31>/Delay' */
    INS_DWork.Delay_DSTATE_i = INS_P.Delay_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S34>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_p = INS_P.DetectRisePositive_vinit;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_IC_LOADI = 1U;
    INS_DWork.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for Memory: '<S5>/Memory1' */
    INS_DWork.Memory1_PreviousInput[0] = INS_P.Memory1_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for Memory: '<S5>/Memory1' */
    INS_DWork.Memory1_PreviousInput[1] = INS_P.Memory1_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for Memory: '<S5>/Memory1' */
    INS_DWork.Memory1_PreviousInput[2] = INS_P.Memory1_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_k = 1U;

    /* InitializeConditions for UnitDelay: '<S163>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S171>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_i = INS_P.DetectChange_vinit_e;

    /* InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_po;

    /* InitializeConditions for UnitDelay: '<S218>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_l = INS_P.DetectChange_vinit_i;

    /* InitializeConditions for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nz =
      INS_P.DiscreteTimeIntegrator_IC_g;

    /* InitializeConditions for UnitDelay: '<S298>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_o = INS_P.DetectRisePositive_vinit_m;

    /* InitializeConditions for UnitDelay: '<S305>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_m = INS_P.DetectRisePositive3_vinit;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    INS_DWork.Memory_9_PreviousInput = INS_P.Memory_9_InitialCondition;
    INS_DWork.Memory_10_PreviousInput = INS_P.Memory_10_InitialCondition;

    /* InitializeConditions for Memory: '<S302>/memory3' */
    INS_DWork.memory3_PreviousInput[0] = INS_P.memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S302>/memory2' */
    INS_DWork.memory2_PreviousInput[0] = INS_P.memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S302>/memory3' */
    INS_DWork.memory3_PreviousInput[1] = INS_P.memory3_InitialCondition;

    /* InitializeConditions for Memory: '<S302>/memory2' */
    INS_DWork.memory2_PreviousInput[1] = INS_P.memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S246>/Memory' */
    for (i = 0; i < 6; i++) {
      INS_DWork.Memory_PreviousInput[i] = INS_P.Memory_InitialCondition_e[i];
    }

    /* End of InitializeConditions for Memory: '<S246>/Memory' */

    /* InitializeConditions for UnitDelay: '<S222>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_c = INS_P.DetectChange_vinit_k;

    /* InitializeConditions for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k =
      INS_P.DiscreteTimeIntegrator_IC_pt;

    /* InitializeConditions for Memory: '<S219>/Memory' */
    INS_DWork.Memory_PreviousInput_ph = INS_P.Memory_InitialCondition_ll;

    /* InitializeConditions for UnitDelay: '<S153>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_g = INS_P.DetectChange_vinit_d;

    /* InitializeConditions for Memory: '<S145>/Memory2' */
    INS_DWork.Memory2_PreviousInput = INS_P.Memory2_InitialCondition_a;

    /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ev =
      INS_P.DiscreteTimeIntegrator_IC_dv;

    /* InitializeConditions for UnitDelay: '<S296>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_j = INS_P.DetectRisePositive_vinit_h;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    INS_DWork.Memory_11_PreviousInput = INS_P.Memory_11_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S303>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dp = INS_P.DetectRisePositive3_vinit_a;

    /* InitializeConditions for Memory: '<S301>/memory2' */
    INS_DWork.memory2_PreviousInput_j = INS_P.memory2_InitialCondition_e;

    /* InitializeConditions for Memory: '<S276>/Memory' */
    INS_DWork.Memory_PreviousInput_p[0] = INS_P.Memory_InitialCondition_mn[0];
    INS_DWork.Memory_PreviousInput_p[1] = INS_P.Memory_InitialCondition_mn[1];
    INS_DWork.Memory_PreviousInput_p[2] = INS_P.Memory_InitialCondition_mn[2];

    /* InitializeConditions for UnitDelay: '<S75>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dy = INS_P.DetectIncrease_vinit_d;

    /* InitializeConditions for Memory: '<S71>/Memory' */
    INS_DWork.Memory_PreviousInput_l = INS_P.Memory_InitialCondition_gc;

    /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_DSTATE = INS_P.DiscreteTimeIntegrator5_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_i;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_m = 0;

    /* InitializeConditions for Memory: '<S96>/Memory' */
    INS_DWork.Memory_PreviousInput_dc = INS_P.Memory_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S201>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_n = INS_P.DetectChange_vinit_l;

    /* InitializeConditions for DiscreteIntegrator: '<S197>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg =
      INS_P.DiscreteTimeIntegrator_IC_k;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_IC_il;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_o = 0;

    /* InitializeConditions for Memory: '<S93>/Memory' */
    INS_DWork.Memory_PreviousInput_m = INS_P.Memory_InitialCondition_b;

    /* InitializeConditions for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o =
      INS_P.DiscreteTimeIntegrator_IC_l;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = 0;

    /* InitializeConditions for Memory: '<S92>/Memory' */
    INS_DWork.Memory_PreviousInput_ej = INS_P.Memory_InitialCondition_jp;

    /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j =
      INS_P.DiscreteTimeIntegrator_IC_d;
    INS_DWork.DiscreteTimeIntegrator_PrevR_or = 0;

    /* InitializeConditions for Memory: '<S94>/Memory' */
    INS_DWork.Memory_PreviousInput_c = INS_P.Memory_InitialCondition_mr;

    /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_m =
      INS_P.DiscreteTimeIntegrator_IC_c;
    INS_DWork.DiscreteTimeIntegrator_PrevR_ow = 0;

    /* InitializeConditions for Memory: '<S95>/Memory' */
    INS_DWork.Memory_PreviousInput_n = INS_P.Memory_InitialCondition_f;

    /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_f =
      INS_P.DiscreteTimeIntegrator_IC_cj;
    INS_DWork.DiscreteTimeIntegrator_PrevR_mt = 0;

    /* InitializeConditions for Memory: '<S97>/Memory' */
    INS_DWork.Memory_PreviousInput_o = INS_P.Memory_InitialCondition_h;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_n;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_b = 0;

    /* InitializeConditions for Memory: '<S98>/Memory' */
    INS_DWork.Memory_PreviousInput_hx = INS_P.Memory_InitialCondition_d;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_g[0] =
      INS_P.DiscreteTimeIntegrator5_IC_k;
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_g[1] =
      INS_P.DiscreteTimeIntegrator5_IC_k;

    /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_n =
      INS_P.DiscreteTimeIntegrator5_IC_c;

    /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_o = 1U;

    /* InitializeConditions for Delay: '<S43>/Delay' */
    for (i = 0; i < 600; i++) {
      INS_DWork.Delay_DSTATE[i] = INS_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S43>/Delay' */

    /* InitializeConditions for UnitDelay: '<S58>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f = INS_P.DetectIncrease_vinit_b;

    /* InitializeConditions for DiscreteFir: '<S45>/Discrete FIR Filter' */
    INS_DWork.DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 29; i++) {
      INS_DWork.DiscreteFIRFilter_states[i] =
        INS_P.DiscreteFIRFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S45>/Discrete FIR Filter' */

    /* InitializeConditions for RateLimiter: '<S67>/Rate Limiter' */
    INS_DWork.PrevY = INS_P.RateLimiter_IC;

    /* InitializeConditions for UnitDelay: '<S102>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_b = INS_P.DetectRisePositive_vinit_a;

    /* InitializeConditions for UnitDelay: '<S107>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_of = INS_P.DetectRisePositive_vinit_k;

    /* InitializeConditions for UnitDelay: '<S112>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_o1 = INS_P.DetectRisePositive_vinit_n;

    /* InitializeConditions for UnitDelay: '<S117>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_a = INS_P.DetectRisePositive_vinit_d;

    /* InitializeConditions for UnitDelay: '<S122>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ng = INS_P.DetectRisePositive_vinit_aw;

    /* InitializeConditions for UnitDelay: '<S127>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_cr = INS_P.DetectRisePositive_vinit_b;

    /* InitializeConditions for UnitDelay: '<S132>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dt = INS_P.DetectRisePositive_vinit_c;

    /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[0] =
      INS_P.DiscreteTimeIntegrator_IC_df;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] =
      INS_P.DiscreteTimeIntegrator_IC_ck;

    /* InitializeConditions for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[0] =
      INS_P.DiscreteTimeIntegrator_IC_n5;

    /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[1] =
      INS_P.DiscreteTimeIntegrator_IC_df;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] =
      INS_P.DiscreteTimeIntegrator_IC_ck;

    /* InitializeConditions for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[1] =
      INS_P.DiscreteTimeIntegrator_IC_n5;

    /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g[2] =
      INS_P.DiscreteTimeIntegrator_IC_df;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[2] =
      INS_P.DiscreteTimeIntegrator_IC_ck;

    /* InitializeConditions for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cu[2] =
      INS_P.DiscreteTimeIntegrator_IC_n5;

    /* SystemInitialize for Enabled SubSystem: '<S5>/Attitude_Init' */
    /* SystemInitialize for Outport: '<S8>/quaternion_0' */
    INS_B.OutportBufferForquaternion_0[0] = INS_P.quaternion_0_Y0[0];
    INS_B.OutportBufferForquaternion_0[1] = INS_P.quaternion_0_Y0[1];
    INS_B.OutportBufferForquaternion_0[2] = INS_P.quaternion_0_Y0[2];
    INS_B.OutportBufferForquaternion_0[3] = INS_P.quaternion_0_Y0[3];

    /* End of SystemInitialize for SubSystem: '<S5>/Attitude_Init' */

    /* SystemInitialize for Triggered SubSystem: '<S137>/WGS_Derivative' */
    /* SystemInitialize for Outport: '<S160>/lon_0_rad' */
    INS_B.Scalefactor = INS_P.lon_0_rad_Y0;

    /* SystemInitialize for Outport: '<S160>/lat_0_rad' */
    INS_B.Scalefactor1 = INS_P.lat_0_rad_Y0;

    /* SystemInitialize for Outport: '<S160>/dx_dlat' */
    INS_B.Add = INS_P.dx_dlat_Y0;

    /* SystemInitialize for Outport: '<S160>/dy_dlon' */
    INS_B.Product4 = INS_P.dy_dlon_Y0;

    /* SystemInitialize for Outport: '<S160>/dz_dh' */
    INS_B.dz_dh = INS_P.dz_dh_Y0;

    /* End of SystemInitialize for SubSystem: '<S137>/WGS_Derivative' */

    /* SystemInitialize for Enabled SubSystem: '<S234>/GPS_Correct' */
    /* InitializeConditions for UnitDelay: '<S237>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d0 = INS_P.DetectChange_vinit;

    /* InitializeConditions for Delay: '<S240>/x_delay' */
    INS_DWork.icLoad_o = 1U;

    /* InitializeConditions for Delay: '<S240>/x_delay1' */
    INS_DWork.icLoad_i = 1U;

    /* InitializeConditions for Delay: '<S240>/vn_delay' */
    INS_DWork.icLoad_m = 1U;

    /* InitializeConditions for Delay: '<S240>/vn_delay1' */
    INS_DWork.icLoad_j = 1U;

    /* InitializeConditions for UnitDelay: '<S245>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_gn = INS_P.DetectIncrease_vinit;

    /* End of SystemInitialize for SubSystem: '<S234>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S249>/GPS_Pos_Init' */
    /* SystemInitialize for Outport: '<S251>/X_0' */
    INS_B.DataTypeConversion[0] = INS_P.X_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S249>/GPS_Pos_Init' */

    /* SystemInitialize for Enabled SubSystem: '<S234>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S243>/Memory' */
    INS_DWork.Memory_PreviousInput_d[0] = INS_P.Memory_InitialCondition_l[0];

    /* End of SystemInitialize for SubSystem: '<S234>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S249>/GPS_Pos_Init' */
    /* SystemInitialize for Outport: '<S251>/X_0' */
    INS_B.DataTypeConversion[1] = INS_P.X_0_Y0;

    /* End of SystemInitialize for SubSystem: '<S249>/GPS_Pos_Init' */

    /* SystemInitialize for Enabled SubSystem: '<S234>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S243>/Memory' */
    INS_DWork.Memory_PreviousInput_d[1] = INS_P.Memory_InitialCondition_l[1];
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for Memory: '<S238>/Memory' */
      INS_DWork.Memory_PreviousInput_h[i] = INS_P.Memory_InitialCondition_o;

      /* SystemInitialize for Outport: '<S236>/X_Next' */
      INS_B.Sum1_o[i] = INS_P.X_Next_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S234>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S143>/Reference_and_Gradient' */
    /* InitializeConditions for Memory: '<S146>/Memory' */
    INS_DWork.Memory_PreviousInput_f = INS_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S146>/Memory2' */
    INS_DWork.Memory2_PreviousInput_b = INS_P.Memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S146>/Memory1' */
    INS_DWork.Memory1_PreviousInput_a = INS_P.Memory1_InitialCondition;

    /* SystemInitialize for Outport: '<S146>/p_ref' */
    INS_B.Divide = INS_P.p_ref_Y0;

    /* SystemInitialize for Outport: '<S146>/dh_dp' */
    INS_B.g_M_d_R = INS_P.dh_dp_Y0;

    /* End of SystemInitialize for SubSystem: '<S143>/Reference_and_Gradient' */

    /* SystemInitialize for Merge: '<S278>/Merge' */
    INS_B.h_0 = INS_P.Merge_InitialOutput;

    /* SystemInitialize for Merge: '<S278>/Merge1' */
    INS_B.vel_D_0 = INS_P.Merge1_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S256>/Baro_Correct' */
    /* InitializeConditions for UnitDelay: '<S259>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_lg = INS_P.DetectChange_vinit_m;

    /* InitializeConditions for Delay: '<S262>/x_delay' */
    INS_DWork.icLoad_a = 1U;

    /* InitializeConditions for UnitDelay: '<S266>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_fw = INS_P.DetectIncrease_vinit_c;

    /* InitializeConditions for Memory: '<S264>/Memory' */
    INS_DWork.Memory_PreviousInput_j = INS_P.Memory_InitialCondition_m;

    /* End of SystemInitialize for SubSystem: '<S256>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S257>/GPS_Correct' */
    /* InitializeConditions for UnitDelay: '<S268>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d = INS_P.DetectChange_vinit_h;

    /* InitializeConditions for Delay: '<S271>/h_delay' */
    INS_DWork.icLoad = 1U;

    /* InitializeConditions for Delay: '<S271>/vd_delay' */
    INS_DWork.icLoad_f = 1U;

    /* InitializeConditions for UnitDelay: '<S275>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ib = INS_P.DetectIncrease_vinit_j;

    /* InitializeConditions for Memory: '<S273>/Memory' */
    INS_DWork.Memory_PreviousInput_b = INS_P.Memory_InitialCondition_p;

    /* End of SystemInitialize for SubSystem: '<S257>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/GPS_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_IC_L_oi = 1U;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_PrevRe_c = 0;

    /* End of SystemInitialize for SubSystem: '<S44>/GPS_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/VIsionFlow_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S63>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b = INS_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S63>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_IC_LOA_k = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_m =
      INS_P.DiscreteTimeIntegrator1_IC_l;

    /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_IC_LO_kr = 1U;

    /* End of SystemInitialize for SubSystem: '<S44>/VIsionFlow_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S256>/Baro_Correct' */
    /* InitializeConditions for Memory: '<S260>/Memory' */
    INS_DWork.Memory_PreviousInput_i[0] = INS_P.Memory_InitialCondition_j;

    /* SystemInitialize for Outport: '<S258>/X_Next' */
    INS_B.Sum1_p[0] = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S256>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S257>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S269>/Memory' */
    INS_DWork.Memory_PreviousInput_e[0] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Outport: '<S267>/X_Next' */
    INS_B.Sum1[0] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S257>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/GPS_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_or[0] =
      INS_P.DiscreteTimeIntegrator_IC;

    /* SystemInitialize for Outport: '<S59>/GPS_acc_O_mPs2' */
    INS_B.DiscreteTimeIntegrator[0] = INS_P.GPS_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S44>/GPS_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/VIsionFlow_Observer' */
    /* SystemInitialize for Outport: '<S61>/OptFlow_acc_O_mPs2' */
    INS_B.OutportBufferForOptFlow_acc_O_m[0] = INS_P.OptFlow_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S44>/VIsionFlow_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S256>/Baro_Correct' */
    /* InitializeConditions for Memory: '<S260>/Memory' */
    INS_DWork.Memory_PreviousInput_i[1] = INS_P.Memory_InitialCondition_j;

    /* SystemInitialize for Outport: '<S258>/X_Next' */
    INS_B.Sum1_p[1] = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S256>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S257>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S269>/Memory' */
    INS_DWork.Memory_PreviousInput_e[1] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Outport: '<S267>/X_Next' */
    INS_B.Sum1[1] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S257>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/GPS_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_or[1] =
      INS_P.DiscreteTimeIntegrator_IC;

    /* SystemInitialize for Outport: '<S59>/GPS_acc_O_mPs2' */
    INS_B.DiscreteTimeIntegrator[1] = INS_P.GPS_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S44>/GPS_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/VIsionFlow_Observer' */
    /* SystemInitialize for Outport: '<S61>/OptFlow_acc_O_mPs2' */
    INS_B.OutportBufferForOptFlow_acc_O_m[1] = INS_P.OptFlow_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S44>/VIsionFlow_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S256>/Baro_Correct' */
    /* InitializeConditions for Memory: '<S260>/Memory' */
    INS_DWork.Memory_PreviousInput_i[2] = INS_P.Memory_InitialCondition_j;

    /* SystemInitialize for Outport: '<S258>/X_Next' */
    INS_B.Sum1_p[2] = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S256>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S257>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S269>/Memory' */
    INS_DWork.Memory_PreviousInput_e[2] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Outport: '<S267>/X_Next' */
    INS_B.Sum1[2] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S257>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/GPS_Observer' */
    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_or[2] =
      INS_P.DiscreteTimeIntegrator_IC;

    /* SystemInitialize for Outport: '<S59>/GPS_acc_O_mPs2' */
    INS_B.DiscreteTimeIntegrator[2] = INS_P.GPS_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S44>/GPS_Observer' */

    /* SystemInitialize for Enabled SubSystem: '<S44>/VIsionFlow_Observer' */
    /* SystemInitialize for Outport: '<S61>/OptFlow_acc_O_mPs2' */
    INS_B.OutportBufferForOptFlow_acc_O_m[2] = INS_P.OptFlow_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S44>/VIsionFlow_Observer' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
