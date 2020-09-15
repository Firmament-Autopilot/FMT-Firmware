/*
 * File: FMS_private.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.710
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 08:38:14 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FMS_private_h_
#define RTW_HEADER_FMS_private_h_
#include "rtwtypes.h"
#include "FMS.h"

extern void FMS_Motion_State_Init(DW_Motion_State_FMS_T *localDW);
extern void FMS_Motion_State_Reset(DW_Motion_State_FMS_T *localDW);
extern void FMS_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_heading_rate,
  real_T *rty_state, DW_Motion_State_FMS_T *localDW);
extern void FMS_Z_Motion_State_Init(DW_Z_Motion_State_FMS_T *localDW);
extern void FMS_Z_Motion_State_Reset(DW_Z_Motion_State_FMS_T *localDW);
extern void FMS_Z_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_speed,
  real_T *rty_state, DW_Z_Motion_State_FMS_T *localDW);

#endif                                 /* RTW_HEADER_FMS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
