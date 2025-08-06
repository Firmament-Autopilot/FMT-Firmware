/*
 * File: FMS_private.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2086
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug  6 11:38:45 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FMS_private_h_
#define RTW_HEADER_FMS_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "zero_crossing_types.h"
#include "FMS.h"
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

extern real_T rt_modd(real_T u0, real_T u1);

/* Exported functions */
extern int32_T FMS_emplace(Queue_FMS_Cmd *q, const FMS_Cmd *dataIn);
extern int32_T FMS_pop(Queue_FMS_Cmd *q, Msg_FMS_Cmd *elementOut);
extern void FMS_initQueue(Queue_FMS_Cmd *q, QueuePolicy_T policy, int32_T
  capacity, Msg_FMS_Cmd *qPool);
extern void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
  rtu_P3_k, real32_T rtu_L1, real32_T rty_P[2], real32_T *rty_d);
extern void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T
  *localC);

#endif                                 /* RTW_HEADER_FMS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
