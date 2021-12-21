/*
 * File: FMS_private.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1018
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 21 14:39:40 2021
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
#include "FMS.h"

/* Exported functions */
extern int32_T FMS_emplace(Queue_FMS_Cmd *q, const FMS_Cmd *dataIn);
extern int32_T FMS_pop(Queue_FMS_Cmd *q, Msg_FMS_Cmd *elementOut);
extern void FMS_initQueue(Queue_FMS_Cmd *q, QueuePolicy_T policy, int32_T
  capacity, Msg_FMS_Cmd *qPool);
extern void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T
  *localC);
extern void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW);
extern void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW);
extern void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_T *localDW);
extern void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs);
extern void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW);
extern void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW);
extern void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T *localDW);
extern void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW);
extern void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_g_T *localDW);
extern void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T
  *rty_psi_rate_cmd_radPs, DW_HoldControl_FMS_g_T *localDW);
extern void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW);
extern void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW);
extern void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T
  *rty_psi_rate_cmd_radPs, const ConstB_MoveControl_FMS_f_T *localC,
  DW_MoveControl_FMS_c_T *localDW);
extern void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW);
extern void FMS_HoldControl_n_Reset(DW_HoldControl_FMS_f_T *localDW);
extern void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b,
  real32_T rtu_FMS_In_l, real32_T rty_uv_cmd_mPs[2], const
  ConstB_HoldControl_FMS_k_T *localC, DW_HoldControl_FMS_f_T *localDW);
extern void FMS_BrakeControl_b(real32_T rty_uv_cmd_mPs[2]);
extern void FMS_MoveControl_l_Init(DW_MoveControl_FMS_k_T *localDW);
extern void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_k_T *localDW);
extern void FMS_MoveControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_f,
  real32_T rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_o_T *localC,
  DW_MoveControl_FMS_k_T *localDW);
extern void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW);
extern void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW);
extern void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionState_FMS_T *localDW);
extern void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW);
extern void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW);
extern void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_T *localDW);

#endif                                 /* RTW_HEADER_FMS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
