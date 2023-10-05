/*
 * File: Plant_private.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.1160
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Oct  5 16:32:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Plant_private_h_
#define RTW_HEADER_Plant_private_h_
#include "rtwtypes.h"
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

extern void rt_mldivide_U1f3x3_U2f3_Yf3x1(const real32_T u0[9], const real32_T
  u1[3], real32_T y[3]);
extern void RandSrc_GZ_R(real32_T y[], const real32_T mean[], int32_T meanLen,
  const real32_T xstd[], int32_T xstdLen, uint32_T state[], int32_T nChans,
  int32_T nSamps);
extern void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T
  nChans);
extern void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[],
  int32_T nChans);
extern void RandSrc_U_R(real32_T y[], const real32_T minVec[], int32_T minLen,
  const real32_T maxVec[], int32_T maxLen, real32_T state[], int32_T nChans,
  int32_T nSamps);
extern void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[],
  int32_T numSeeds);

#endif                                 /* RTW_HEADER_Plant_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
