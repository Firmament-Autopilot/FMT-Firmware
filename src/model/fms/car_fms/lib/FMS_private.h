/*
 * File: FMS_private.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1975
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 15:43:07 2024
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
