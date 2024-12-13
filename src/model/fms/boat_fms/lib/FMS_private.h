/*
 * File: FMS_private.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2038
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec 12 10:12:05 2024
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
extern void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs);
extern void FMS_MoveControl(real32_T rtu_FMS_In, real32_T
  *rty_psi_rate_cmd_radPs);
extern void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW);
extern void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW);
extern void FMS_MotionState(boolean_T rtu_motion_req, MotionState *rty_state,
  DW_MotionState_FMS_T *localDW);

#endif                                 /* RTW_HEADER_FMS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
