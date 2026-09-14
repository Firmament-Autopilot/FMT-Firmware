/*
 * File: Controller_private.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1044
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 16:51:41 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_private_h_
#define RTW_HEADER_Controller_private_h_
#include "rtwtypes.h"
#include "Controller.h"
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

#if (AIRFRAME == 3) || (AIRFRAME == 7) || (AIRFRAME == 8)

extern void Controller_R_Remix(real32_T rtu_up_lim, real32_T rtu_lo_lim, const
  real32_T rtu_r_column[8], const real32_T rtu_motor_out[8], real32_T
  rty_floating_yaw[8]);

#endif

#if (AIRFRAME == 4) || (AIRFRAME == 5)

extern void Controller_R_Remix_h(real32_T rtu_up_lim, real32_T rtu_lo_lim, const
  real32_T rtu_r_column[6], const real32_T rtu_motor_out[6], real32_T
  rty_floating_yaw[6]);

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

extern void Controller_R_Remix_k(real32_T rtu_up_lim, real32_T rtu_lo_lim, const
  real32_T rtu_r_column[4], const real32_T rtu_motor_out[4], real32_T
  rty_floating_yaw[4]);

#endif
#endif                                 /* RTW_HEADER_Controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
