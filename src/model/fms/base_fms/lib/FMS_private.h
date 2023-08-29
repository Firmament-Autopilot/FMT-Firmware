/*
 * File: FMS_private.h
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2022
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 29 14:19:44 2023
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
extern real32_T rt_remf(real32_T u0, real32_T u1);

/* Exported functions */
extern int32_T FMS_emplace(Queue_FMS_Cmd *q, const FMS_Cmd *dataIn);
extern int32_T FMS_pop(Queue_FMS_Cmd *q, Msg_FMS_Cmd *elementOut);
extern void FMS_initQueue(Queue_FMS_Cmd *q, QueuePolicy_T policy, int32_T
  capacity, Msg_FMS_Cmd *qPool);
extern void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW);
extern void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW);
extern void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_T *localDW);
extern void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs);
extern void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW);
extern void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW);
extern void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T *localDW);
extern void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW);
extern void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW);
extern void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_T *localDW);
extern void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW);
extern void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW);
extern void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_p,
  real32_T rtu_FMS_In_b, real32_T rty_uv_cmd_mPs[2], const
  ConstB_HoldControl_FMS_k_T *localC, DW_HoldControl_FMS_l_T *localDW);
extern void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2]);
extern void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW);
extern void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW);
extern void FMS_MoveControl_o(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g,
  real32_T rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_k_T *localC,
  DW_MoveControl_FMS_d_T *localDW);
extern void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW);
extern void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW);
extern void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionState_FMS_T *localDW);
extern void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
  rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T *rty_d);
extern void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW);
extern void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW);
extern void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T
  *rty_psi_rate_cmd_radPs, DW_HoldControl_FMS_g_T *localDW);
extern void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW);
extern void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW);
extern void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T
  *rty_psi_rate_cmd_radPs, const ConstB_MoveControl_FMS_f_T *localC,
  DW_MoveControl_FMS_c_T *localDW);
extern void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T
  *localC);
extern void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW);
extern void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW);
extern void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionState_FMS_g_T *localDW);
extern void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l,
  uint32_T rtu_FMS_In_i, real32_T *rty_w_cmd_mPs);
extern void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW);
extern void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW);
extern void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW);
extern void F_VehicleArmAutoMissionLLA2FLAT(const real_T rtu_lla[3], const
  real_T rtu_llo[2], real_T rtu_href, real_T rtu_psio, real32_T rty_pos[3],
  const ConstB_VehicleArmAutoMissionL_T *localC);

#endif                                 /* RTW_HEADER_FMS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
