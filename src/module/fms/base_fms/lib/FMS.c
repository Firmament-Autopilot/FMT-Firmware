/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1213
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan  1 10:44:14 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S208>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S218>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S118>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S37>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S152>/Motion State' */
#define FMS_IN_Brake_o                 ((uint8_T)1U)
#define FMS_IN_Hold_d                  ((uint8_T)2U)
#define FMS_IN_Move_n                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Hold_b                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_b                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/Mode Degrade' */
#define FMS_IN_Manual_e                ((uint8_T)3U)
#define FMS_IN_Mission_g               ((uint8_T)4U)
#define FMS_IN_Other                   ((uint8_T)5U)
#define FMS_IN_Position_f              ((uint8_T)6U)
#define FMS_IN_Stabilize_j             ((uint8_T)7U)

const FMS_Out_Bus FMS_rtZFMS_Out_Bus = {
  0U,                                  /* timestamp */
  0.0F,                                /* p_cmd */
  0.0F,                                /* q_cmd */
  0.0F,                                /* r_cmd */
  0.0F,                                /* phi_cmd */
  0.0F,                                /* theta_cmd */
  0.0F,                                /* psi_rate_cmd */
  0.0F,                                /* u_cmd */
  0.0F,                                /* v_cmd */
  0.0F,                                /* w_cmd */
  0U,                                  /* throttle_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* status */
  0U,                                  /* state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* reset */
  0U,                                  /* mode */
  0U,                                  /* reserved1 */
  0U                                   /* reserved2 */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_5vUBwe4VfGkNikzOx8lYKF FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  5.0F,
  2.5F,
  2.5F,
  1.04719758F,
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S34>/Gain'
                                        *   '<S34>/Gain1'
                                        *   '<S108>/Gain'
                                        *   '<S108>/Gain1'
                                        *   '<S176>/Saturation1'
                                        *   '<S247>/Gain2'
                                        *   '<S247>/Saturation1'
                                        *   '<S36>/Saturation1'
                                        *   '<S47>/Dead Zone'
                                        *   '<S47>/Gain'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S53>/Saturation'
                                        *   '<S69>/Saturation1'
                                        *   '<S80>/Saturation'
                                        *   '<S93>/Saturation1'
                                        *   '<S111>/Dead Zone'
                                        *   '<S111>/Gain'
                                        *   '<S112>/Dead Zone'
                                        *   '<S112>/Gain'
                                        *   '<S117>/Saturation'
                                        *   '<S141>/Saturation1'
                                        *   '<S151>/Saturation'
                                        *   '<S163>/Saturation1'
                                        *   '<S177>/Gain2'
                                        *   '<S39>/Gain2'
                                        *   '<S40>/Gain1'
                                        *   '<S45>/Constant'
                                        *   '<S56>/Gain2'
                                        *   '<S57>/Gain1'
                                        *   '<S64>/Constant'
                                        *   '<S72>/Gain2'
                                        *   '<S73>/Gain1'
                                        *   '<S78>/Constant'
                                        *   '<S83>/Gain2'
                                        *   '<S84>/Gain1'
                                        *   '<S91>/Constant'
                                        *   '<S96>/Gain2'
                                        *   '<S97>/Gain6'
                                        *   '<S105>/Constant'
                                        *   '<S106>/Constant'
                                        *   '<S120>/Gain2'
                                        *   '<S121>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S144>/Gain2'
                                        *   '<S145>/Gain1'
                                        *   '<S154>/Gain2'
                                        *   '<S155>/Gain1'
                                        *   '<S166>/Gain2'
                                        *   '<S167>/Gain6'
                                        *   '<S186>/Gain2'
                                        *   '<S186>/Saturation'
                                        *   '<S187>/Integrator'
                                        *   '<S42>/Dead Zone'
                                        *   '<S42>/Gain'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S75>/Dead Zone'
                                        *   '<S75>/Gain'
                                        *   '<S88>/Dead Zone'
                                        *   '<S88>/Gain'
                                        *   '<S101>/Dead Zone'
                                        *   '<S101>/Gain'
                                        *   '<S102>/Dead Zone'
                                        *   '<S102>/Gain'
                                        *   '<S125>/Dead Zone'
                                        *   '<S125>/Gain'
                                        *   '<S147>/Dead Zone'
                                        *   '<S147>/Gain'
                                        *   '<S159>/Dead Zone'
                                        *   '<S159>/Gain'
                                        *   '<S171>/Dead Zone'
                                        *   '<S171>/Gain'
                                        *   '<S172>/Dead Zone'
                                        *   '<S172>/Gain'
                                        *   '<S207>/Saturation1'
                                        *   '<S217>/Saturation1'
                                        *   '<S210>/Gain2'
                                        *   '<S211>/Gain1'
                                        *   '<S220>/Gain2'
                                        *   '<S221>/Gain6'
                                        *   '<S213>/Dead Zone'
                                        *   '<S213>/Gain'
                                        *   '<S225>/Dead Zone'
                                        *   '<S225>/Gain'
                                        *   '<S226>/Dead Zone'
                                        *   '<S226>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 50, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S20>/Constant'
                                        */

/* Block signals (default storage) */
B_FMS_T FMS_B;

/* Block states (default storage) */
DW_FMS_T FMS_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FMS_T FMS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FMS_T FMS_Y;

/* Real-time model */
RT_MODEL_FMS_T FMS_M_;
RT_MODEL_FMS_T *const FMS_M = &FMS_M_;

/* Forward declaration for local functions */
static void FMS_Stabilize(void);
static void FMS_Acro(void);
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Assist(void);
static void FMS_enter_internal_Arm(void);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static void FMS_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Vehicle(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for action system:
 *    '<S2>/Disarm'
 *    '<S24>/Unknown'
 *    '<S22>/Unknown'
 *    '<S21>/Unknown'
 *    '<S17>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S18>/Bus Assignment' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant2'
   *  SignalConversion: '<S18>/TmpHiddenBufferAtBus AssignmentInport1'
   */
  *rty_FMS_Out = FMS_rtZFMS_Out_Bus;
  rty_FMS_Out->reset = 1U;
  rty_FMS_Out->status = localC->DataTypeConversion;
  rty_FMS_Out->state = localC->DataTypeConversion1;
  rty_FMS_Out->actuator_cmd[0] = 1000U;
  rty_FMS_Out->actuator_cmd[1] = 1000U;
  rty_FMS_Out->actuator_cmd[2] = 1000U;
  rty_FMS_Out->actuator_cmd[3] = 1000U;
  for (i = 0; i < 12; i++) {
    rty_FMS_Out->actuator_cmd[i + 4] = 0U;
  }

  /* End of BusAssignment: '<S18>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S207>/Hold Control'
 *    '<S141>/Hold Control'
 *    '<S36>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S210>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S207>/Hold Control'
 *    '<S141>/Hold Control'
 *    '<S36>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S210>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S207>/Hold Control'
 *    '<S141>/Hold Control'
 *    '<S36>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S210>/Delay' incorporates:
   *  Gain: '<S212>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S210>/Gain2' incorporates:
   *  Delay: '<S210>/Delay'
   *  Gain: '<S212>/Gain'
   *  Sum: '<S210>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S210>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S207>/Brake Control'
 *    '<S141>/Brake Control'
 *    '<S151>/Brake Control'
 *    '<S117>/Brake Control'
 *    '<S36>/Brake Control'
 *    '<S53>/Brake Control'
 *    '<S69>/Brake Control'
 *    '<S80>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S209>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S209>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S207>/Move Control'
 *    '<S141>/Move Control'
 *    '<S36>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S214>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S214>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S207>/Move Control'
 *    '<S141>/Move Control'
 *    '<S36>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S214>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S214>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S207>/Move Control'
 *    '<S141>/Move Control'
 *    '<S36>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_m;
  real32_T rtb_a_c;
  real32_T rtb_Add4_g;
  real32_T rtb_a_b;

  /* Product: '<S215>/Multiply1' incorporates:
   *  Constant: '<S215>/const1'
   *  DiscreteIntegrator: '<S214>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S213>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_c = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_c = 0.0F;
  } else {
    rtb_a_c = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S213>/Dead Zone' */

  /* Sum: '<S215>/Add' incorporates:
   *  DiscreteIntegrator: '<S214>/Integrator1'
   *  Gain: '<S211>/Gain1'
   *  Gain: '<S213>/Gain'
   *  Sum: '<S214>/Subtract'
   */
  rtb_Subtract3_m = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_c * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3;

  /* Signum: '<S215>/Sign' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_a_c = -1.0F;
  } else if (rtb_Subtract3_m > 0.0F) {
    rtb_a_c = 1.0F;
  } else {
    rtb_a_c = rtb_Subtract3_m;
  }

  /* End of Signum: '<S215>/Sign' */

  /* Sum: '<S215>/Add2' incorporates:
   *  Abs: '<S215>/Abs'
   *  Gain: '<S215>/Gain'
   *  Gain: '<S215>/Gain1'
   *  Product: '<S215>/Multiply2'
   *  Product: '<S215>/Multiply3'
   *  Sqrt: '<S215>/Sqrt'
   *  Sum: '<S215>/Add1'
   *  Sum: '<S215>/Subtract'
   */
  rtb_a_c = (sqrtf((8.0F * fabsf(rtb_Subtract3_m) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_c + rtb_Add3;

  /* Sum: '<S215>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_m - rtb_a_c) + rtb_Add3;

  /* Sum: '<S215>/Add3' */
  rtb_Add3 = rtb_Subtract3_m + localC->d;

  /* Sum: '<S215>/Subtract1' */
  rtb_Subtract3_m -= localC->d;

  /* Signum: '<S215>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S215>/Sign1' */

  /* Signum: '<S215>/Sign2' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S215>/Sign2' */

  /* Sum: '<S215>/Add5' incorporates:
   *  Gain: '<S215>/Gain2'
   *  Product: '<S215>/Multiply4'
   *  Sum: '<S215>/Subtract2'
   */
  rtb_a_c += (rtb_Add3 - rtb_Subtract3_m) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S211>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S214>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S214>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S214>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S215>/Add6' */
  rtb_Add3 = rtb_a_c + localC->d;

  /* Sum: '<S215>/Subtract3' */
  rtb_Subtract3_m = rtb_a_c - localC->d;

  /* Signum: '<S215>/Sign5' */
  if (rtb_a_c < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_c > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_c;
  }

  /* End of Signum: '<S215>/Sign5' */

  /* Signum: '<S215>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S215>/Sign3' */

  /* Signum: '<S215>/Sign4' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S215>/Sign4' */

  /* Signum: '<S215>/Sign6' */
  if (rtb_a_c < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_c > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_c;
  }

  /* End of Signum: '<S215>/Sign6' */

  /* Update for DiscreteIntegrator: '<S214>/Integrator' incorporates:
   *  Constant: '<S215>/const'
   *  Gain: '<S215>/Gain3'
   *  Product: '<S215>/Divide'
   *  Product: '<S215>/Multiply5'
   *  Product: '<S215>/Multiply6'
   *  Sum: '<S215>/Subtract4'
   *  Sum: '<S215>/Subtract5'
   *  Sum: '<S215>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_c / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_m) * 0.5F) - rtb_a_b * 78.448F) *
    0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S208>/Motion Status'
 *    '<S142>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S208>/Motion Status'
 *    '<S142>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S208>/Motion Status'
 *    '<S142>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S208>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c1_FMS == 0U) {
    localDW->is_active_c1_FMS = 1U;
    localDW->is_c1_FMS = FMS_IN_Move;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c1_FMS) {
     case FMS_IN_Brake:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c1_FMS = FMS_IN_Hold;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c1_FMS = FMS_IN_Move;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req == 1.0F) {
        localDW->is_c1_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (rtu_motion_req == 0.0F) {
        localDW->is_c1_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S208>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S217>/Hold Control'
 *    '<S163>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S220>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S217>/Hold Control'
 *    '<S163>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S220>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S217>/Hold Control'
 *    '<S163>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_p, real32_T
  rtu_FMS_In_b, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_l_T *localDW)
{
  real32_T rtb_VectorConcatenate_k[9];
  real32_T rtb_VectorConcatenate_b[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_b_tmp;
  real32_T rtb_VectorConcatenate_b_tmp_0;

  /* Delay: '<S220>/Delay' incorporates:
   *  SignalConversion: '<S220>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S224>/Trigonometric Function1' incorporates:
   *  Gain: '<S223>/Gain'
   *  Trigonometry: '<S224>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_b_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_b_tmp_0;

  /* Trigonometry: '<S224>/Trigonometric Function' incorporates:
   *  Gain: '<S223>/Gain'
   *  Trigonometry: '<S224>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_b_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_b_tmp;

  /* SignalConversion: '<S224>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S224>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S224>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_b_tmp;

  /* Trigonometry: '<S224>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_b_tmp_0;

  /* SignalConversion: '<S224>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S224>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S224>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S220>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S220>/Delay'
   *  SignalConversion: '<S220>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S220>/Sum'
   */
  rtb_VectorConcatenate_b_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_b_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S220>/Multiply' incorporates:
   *  SignalConversion: '<S220>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_b[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_b_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_b_tmp_0;
  }

  /* End of Product: '<S220>/Multiply' */

  /* Gain: '<S220>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[1];

  /* Update for Delay: '<S220>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S217>/Brake Control'
 *    '<S163>/Brake Control'
 *    '<S93>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S219>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S217>/Move Control'
 *    '<S163>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S217>/Move Control'
 *    '<S163>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S217>/Move Control'
 *    '<S163>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_o(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_k_T *localC,
  DW_MoveControl_FMS_d_T *localDW)
{
  real32_T rtb_Subtract3_o;
  real32_T rtb_Add3_e_idx_0;
  real32_T rtb_Subtract3_h_idx_0;
  real32_T rtb_Add3_e_idx_1;
  real32_T rtb_Subtract3_h_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_h_idx_0_0;

  /* SignalConversion: '<S221>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S227>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S228>/Multiply1' incorporates:
   *  Constant: '<S228>/const1'
   *  DiscreteIntegrator: '<S227>/Integrator'
   */
  rtb_Add3_e_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S221>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S227>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S228>/Multiply1' incorporates:
   *  Constant: '<S228>/const1'
   *  DiscreteIntegrator: '<S227>/Integrator'
   */
  rtb_Add3_e_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S225>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S225>/Dead Zone' */

  /* Sum: '<S228>/Add' incorporates:
   *  DiscreteIntegrator: '<S227>/Integrator1'
   *  Gain: '<S221>/Gain6'
   *  Gain: '<S225>/Gain'
   *  Sum: '<S227>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e_idx_0;

  /* DeadZone: '<S226>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S226>/Dead Zone' */

  /* Sum: '<S228>/Add' incorporates:
   *  DiscreteIntegrator: '<S227>/Integrator1'
   *  Gain: '<S221>/Gain6'
   *  Gain: '<S226>/Gain'
   *  Sum: '<S227>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e_idx_1;

  /* Signum: '<S228>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S228>/Add2' incorporates:
   *  Abs: '<S228>/Abs'
   *  Gain: '<S228>/Gain'
   *  Gain: '<S228>/Gain1'
   *  Product: '<S228>/Multiply2'
   *  Product: '<S228>/Multiply3'
   *  Signum: '<S228>/Sign'
   *  Sqrt: '<S228>/Sqrt'
   *  Sum: '<S228>/Add1'
   *  Sum: '<S228>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e_idx_0;

  /* Sum: '<S228>/Add3' incorporates:
   *  Signum: '<S228>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S228>/Subtract1' incorporates:
   *  Signum: '<S228>/Sign'
   */
  rtb_Subtract3_o = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S228>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S228>/Sign2' */
  if (rtb_Subtract3_o < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else {
    if (rtb_Subtract3_o > 0.0F) {
      rtb_Subtract3_o = 1.0F;
    }
  }

  /* Sum: '<S228>/Add5' incorporates:
   *  Gain: '<S228>/Gain2'
   *  Product: '<S228>/Multiply4'
   *  Signum: '<S228>/Sign'
   *  Sum: '<S228>/Add2'
   *  Sum: '<S228>/Add4'
   *  Sum: '<S228>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e_idx_0) * ((u - rtb_Subtract3_o) * 0.5F);

  /* Update for DiscreteIntegrator: '<S227>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S227>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S228>/Sign3' incorporates:
   *  Sum: '<S228>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S228>/Sign4' incorporates:
   *  Sum: '<S228>/Subtract3'
   */
  rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S228>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S228>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S228>/Sign4' */
  if (rtb_Add3_e_idx_0 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e_idx_0 > 0.0F) {
      rtb_Add3_e_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S228>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_o = 1.0F;
  } else {
    rtb_Subtract3_o = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S227>/Integrator' incorporates:
   *  Constant: '<S228>/const'
   *  Gain: '<S228>/Gain3'
   *  Product: '<S228>/Divide'
   *  Product: '<S228>/Multiply5'
   *  Product: '<S228>/Multiply6'
   *  Sum: '<S228>/Subtract4'
   *  Sum: '<S228>/Subtract5'
   *  Sum: '<S228>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e_idx_0) * 0.5F) -
    rtb_Subtract3_o * 58.836F) * 0.004F;

  /* Signum: '<S228>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e_idx_0 = 1.0F;
  } else {
    rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S228>/Add2' incorporates:
   *  Abs: '<S228>/Abs'
   *  Gain: '<S228>/Gain'
   *  Gain: '<S228>/Gain1'
   *  Product: '<S228>/Multiply2'
   *  Product: '<S228>/Multiply3'
   *  Signum: '<S228>/Sign'
   *  Sqrt: '<S228>/Sqrt'
   *  Sum: '<S228>/Add1'
   *  Sum: '<S228>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e_idx_0 +
    rtb_Add3_e_idx_1;

  /* Sum: '<S228>/Add3' incorporates:
   *  Signum: '<S228>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S228>/Subtract1' incorporates:
   *  Signum: '<S228>/Sign'
   */
  rtb_Subtract3_o = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S228>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S228>/Sign2' */
  if (rtb_Subtract3_o < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else {
    if (rtb_Subtract3_o > 0.0F) {
      rtb_Subtract3_o = 1.0F;
    }
  }

  /* Sum: '<S228>/Add5' incorporates:
   *  Gain: '<S228>/Gain2'
   *  Product: '<S228>/Multiply4'
   *  Signum: '<S228>/Sign'
   *  Sum: '<S228>/Add2'
   *  Sum: '<S228>/Add4'
   *  Sum: '<S228>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e_idx_1) * ((u - rtb_Subtract3_o) * 0.5F);

  /* Update for DiscreteIntegrator: '<S227>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S227>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S228>/Sign3' incorporates:
   *  Sum: '<S228>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S228>/Sign4' incorporates:
   *  Sum: '<S228>/Subtract3'
   */
  rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S228>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S228>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S228>/Sign4' */
  if (rtb_Add3_e_idx_0 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e_idx_0 > 0.0F) {
      rtb_Add3_e_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S228>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_o = 1.0F;
  } else {
    rtb_Subtract3_o = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S227>/Integrator' incorporates:
   *  Constant: '<S228>/const'
   *  Gain: '<S228>/Gain3'
   *  Product: '<S228>/Divide'
   *  Product: '<S228>/Multiply5'
   *  Product: '<S228>/Multiply6'
   *  Sum: '<S228>/Subtract4'
   *  Sum: '<S228>/Subtract5'
   *  Sum: '<S228>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e_idx_0) * 0.5F) -
    rtb_Subtract3_o * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S218>/Motion State'
 *    '<S164>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S218>/Motion State'
 *    '<S164>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S218>/Motion State'
 *    '<S164>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S218>/Motion State' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c2_FMS == 0U) {
    localDW->is_active_c2_FMS = 1U;
    localDW->is_c2_FMS = FMS_IN_Move_c;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c2_FMS) {
     case FMS_IN_Brake_b:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.2) || (localDW->temporalCounter_i1 >= 625U)) {
        localDW->is_c2_FMS = FMS_IN_Hold_m;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c2_FMS = FMS_IN_Move_c;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_m:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req == 1.0F) {
        localDW->is_c2_FMS = FMS_IN_Move_c;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (rtu_motion_req == 0.0F) {
        localDW->is_c2_FMS = FMS_IN_Brake_b;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S218>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S151>/Hold Control'
 *    '<S117>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S80>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S154>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S151>/Hold Control'
 *    '<S117>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S80>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S154>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S151>/Hold Control'
 *    '<S117>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S80>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S154>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S154>/Sum' incorporates:
   *  Delay: '<S154>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S157>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S157>/Switch' incorporates:
   *  Constant: '<S157>/Constant'
   *  Constant: '<S158>/Constant'
   *  Product: '<S157>/Multiply'
   *  RelationalOperator: '<S158>/Compare'
   *  Sum: '<S157>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S157>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S157>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S157>/Switch' */

  /* Gain: '<S154>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S154>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S151>/Move Control'
 *    '<S117>/Move Control'
 *    '<S53>/Move Control'
 *    '<S80>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S151>/Move Control'
 *    '<S117>/Move Control'
 *    '<S53>/Move Control'
 *    '<S80>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S151>/Move Control'
 *    '<S117>/Move Control'
 *    '<S53>/Move Control'
 *    '<S80>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S161>/Multiply1' incorporates:
   *  Constant: '<S161>/const1'
   *  DiscreteIntegrator: '<S160>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S159>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S159>/Dead Zone' */

  /* Sum: '<S161>/Add' incorporates:
   *  DiscreteIntegrator: '<S160>/Integrator1'
   *  Gain: '<S155>/Gain1'
   *  Gain: '<S159>/Gain'
   *  Sum: '<S160>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3;

  /* Signum: '<S161>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S161>/Sign' */

  /* Sum: '<S161>/Add2' incorporates:
   *  Abs: '<S161>/Abs'
   *  Gain: '<S161>/Gain'
   *  Gain: '<S161>/Gain1'
   *  Product: '<S161>/Multiply2'
   *  Product: '<S161>/Multiply3'
   *  Sqrt: '<S161>/Sqrt'
   *  Sum: '<S161>/Add1'
   *  Sum: '<S161>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3;

  /* Sum: '<S161>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3;

  /* Sum: '<S161>/Add3' */
  rtb_Add3 = rtb_Subtract3_l + localC->d;

  /* Sum: '<S161>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S161>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S161>/Sign1' */

  /* Signum: '<S161>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S161>/Sign2' */

  /* Sum: '<S161>/Add5' incorporates:
   *  Gain: '<S161>/Gain2'
   *  Product: '<S161>/Multiply4'
   *  Sum: '<S161>/Subtract2'
   */
  rtb_a_m += (rtb_Add3 - rtb_Subtract3_l) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S155>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S160>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S160>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S160>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S161>/Add6' */
  rtb_Add3 = rtb_a_m + localC->d;

  /* Sum: '<S161>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S161>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_m;
  }

  /* End of Signum: '<S161>/Sign5' */

  /* Signum: '<S161>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S161>/Sign3' */

  /* Signum: '<S161>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S161>/Sign4' */

  /* Signum: '<S161>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_m;
  }

  /* End of Signum: '<S161>/Sign6' */

  /* Update for DiscreteIntegrator: '<S160>/Integrator' incorporates:
   *  Constant: '<S161>/const'
   *  Gain: '<S161>/Gain3'
   *  Product: '<S161>/Divide'
   *  Product: '<S161>/Multiply5'
   *  Product: '<S161>/Multiply6'
   *  Sum: '<S161>/Subtract4'
   *  Sum: '<S161>/Subtract5'
   *  Sum: '<S161>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_l) * 0.5F) - rtb_a_p * 15.707963F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S118>/Motion State'
 *    '<S54>/Motion State'
 *    '<S81>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S118>/Motion State'
 *    '<S54>/Motion State'
 *    '<S81>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S118>/Motion State'
 *    '<S54>/Motion State'
 *    '<S81>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S118>/Motion State' */
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c19_FMS == 0U) {
    localDW->is_active_c19_FMS = 1U;
    localDW->is_c19_FMS = FMS_IN_Move_o;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c19_FMS) {
     case FMS_IN_Brake_f:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.1) || (localDW->temporalCounter_i1 >= 250U)) {
        localDW->is_c19_FMS = FMS_IN_Hold_j;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c19_FMS = FMS_IN_Move_o;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_j:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Move_o;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Brake_f;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S118>/Motion State' */
}

/*
 * System initialize for atomic system:
 *    '<S37>/Motion Status'
 *    '<S70>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S37>/Motion Status'
 *    '<S70>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S37>/Motion Status'
 *    '<S70>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S37>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c17_FMS == 0U) {
    localDW->is_active_c17_FMS = 1U;
    localDW->is_c17_FMS = FMS_IN_Move_f;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c17_FMS) {
     case FMS_IN_Brake_h:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c17_FMS = FMS_IN_Hold_n;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c17_FMS = FMS_IN_Move_f;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_n:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Move_f;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Brake_h;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S37>/Motion Status' */
}

/* Function for Chart: '<Root>/Mode Degrade' */
static void FMS_Stabilize(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.safe_mode = PilotMode_Stabilize;

    /* Delay: '<S9>/Delay' */
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Manual:
      FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      break;

     case PilotMode_Acro:
      FMS_DW.is_c3_FMS = FMS_IN_Acro;
      break;

     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Altitude:
      FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S9>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Acro;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/Mode Degrade' */
static void FMS_Acro(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.safe_mode = PilotMode_Acro;

    /* Delay: '<S9>/Delay' */
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Manual:
      FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      break;

     case PilotMode_Acro:
      FMS_DW.is_c3_FMS = FMS_IN_Acro;
      break;

     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Altitude:
      FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S9>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

int32_T FMS_emplace(Queue_FMS_Cmd *q, const FMS_Cmd *dataIn)
{
  int32_T isEmplaced;
  int32_T newTail;
  Msg_FMS_Cmd *msg;
  newTail = (q->fTail + 1) % q->fCapacity;
  if (q->fHead == newTail) {
    isEmplaced = 0;
  } else {
    q->fTail = newTail;
    msg = &q->fArray[newTail];
    msg->fData = *dataIn;
    if (q->fHead == -1) {
      q->fHead = q->fTail;
    }

    isEmplaced = 1;
  }

  return isEmplaced;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_send_M(void)
{
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_o, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = true;
  if (((ins_flag & 2U) == 0U) || ((ins_flag & 4U) == 0U)) {
    valid = false;
  } else {
    switch (cmd_in) {
     case CMD_Takeoff:
     case CMD_Land:
     case CMD_Return:
     case CMD_Pause:
      if (((ins_flag & 8U) == 0U) || ((ins_flag & 32U) == 0U) || ((ins_flag &
            64U) == 0U)) {
        valid = false;
      }
      break;

     case CMD_PreArm:
      switch (mode_in) {
       case PilotMode_Mission:
       case PilotMode_Position:
        if (((ins_flag & 8U) == 0U) || ((ins_flag & 32U) == 0U) || ((ins_flag &
              64U) == 0U)) {
          valid = false;
        }
        break;

       case PilotMode_Altitude:
        if (((ins_flag & 8U) == 0U) || ((ins_flag & 64U) == 0U)) {
          valid = false;
        }
        break;
      }
      break;
    }
  }

  return valid;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle)
{
  return (pilot_cmd_stick_throttle < -0.8) && (pilot_cmd_stick_yaw > 0.8);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle)
{
  return (pilot_cmd_stick_throttle < -0.8) && (pilot_cmd_stick_yaw < -0.8);
}

int32_T FMS_pop(Queue_FMS_Cmd *q, Msg_FMS_Cmd *elementOut)
{
  int32_T isPop;
  if (q->fHead == -1) {
    isPop = 0;
  } else {
    *elementOut = q->fArray[q->fHead];
    isPop = 1;
    if (q->fHead == q->fTail) {
      q->fHead = -1;
      q->fTail = -1;
    } else {
      q->fHead = (q->fHead + 1) % q->fCapacity;
    }
  }

  return isPop;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_sf_msg_pop_M(void)
{
  boolean_T isPresent;
  if (FMS_DW.M_isValid) {
    isPresent = true;
  } else {
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_o, &FMS_DW.Msg_FMS_Cmd_p
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_p[0] : NULL;
    if (FMS_DW.M_msgHandle != NULL) {
      FMS_DW.M_msgDataPtr = &((Msg_FMS_Cmd *)FMS_DW.M_msgHandle)->fData;
      isPresent = true;
      FMS_DW.M_msgReservedData = *(FMS_Cmd *)FMS_DW.M_msgDataPtr;
      FMS_DW.M_isValid = true;
    } else {
      isPresent = false;
      FMS_DW.M_isValid = false;
    }
  }

  return isPresent;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_getArmMode(PilotMode pilotMode)
{
  real_T armMode;
  switch (pilotMode) {
   case PilotMode_Manual:
    armMode = 1.0;
    break;

   case PilotMode_Acro:
    armMode = 2.0;
    break;

   case PilotMode_Stabilize:
    armMode = 2.0;
    break;

   case PilotMode_Altitude:
    armMode = 2.0;
    break;

   case PilotMode_Position:
    armMode = 2.0;
    break;

   case PilotMode_Mission:
    armMode = 3.0;
    break;

   case PilotMode_Offboard:
    armMode = 3.0;
    break;

   default:
    armMode = 0.0;
    break;
  }

  return armMode;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Assist(void)
{
  switch (FMS_B.safe_mode) {
   case PilotMode_Acro:
    FMS_DW.is_Assist = FMS_IN_Acro;
    FMS_B.VehicleState_f = VehicleState_Acro;
    break;

   case PilotMode_Stabilize:
    FMS_DW.is_Assist = FMS_IN_Stabilize;
    FMS_B.VehicleState_f = VehicleState_Stabilize;
    break;

   case PilotMode_Altitude:
    FMS_DW.is_Assist = FMS_IN_Altitude;
    FMS_B.VehicleState_f = VehicleState_Altitude;
    break;

   case PilotMode_Position:
    FMS_DW.is_Assist = FMS_IN_Position;
    FMS_B.VehicleState_f = VehicleState_Position;
    break;

   default:
    FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
    FMS_B.VehicleState_f = VehicleState_InvalidAssistMode;
    break;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Arm(void)
{
  real_T tmp;
  tmp = FMS_getArmMode(FMS_B.safe_mode);
  if (tmp == 3.0) {
    FMS_DW.is_Arm = FMS_IN_Auto;
    switch (FMS_B.safe_mode) {
     case PilotMode_Offboard:
      FMS_DW.is_Auto = FMS_IN_Offboard;
      FMS_B.VehicleState_f = VehicleState_Offboard;
      break;

     case PilotMode_Mission:
      FMS_DW.is_Auto = FMS_IN_Mission;
      FMS_B.VehicleState_f = VehicleState_Mission;
      break;

     default:
      FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
      FMS_B.VehicleState_f = VehicleState_InvalidAutoMode;
      break;
    }
  } else if (tmp == 2.0) {
    FMS_DW.is_Arm = FMS_IN_Assist;
    FMS_enter_internal_Assist();
  } else if (tmp == 1.0) {
    FMS_DW.is_Arm = FMS_IN_Manual;
    if (FMS_B.safe_mode == PilotMode_Manual) {
      FMS_DW.is_Manual = FMS_IN_Manual_b;
      FMS_B.VehicleState_f = VehicleState_Manual;
    } else {
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      FMS_B.VehicleState_f = VehicleState_InValidManualMode;
    }
  } else {
    FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    FMS_B.VehicleState_f = VehicleState_InvalidArmMode;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_SubMode(void)
{
  boolean_T b_sf_internal_predicateOutput;
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real_T tmp;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S252>/Compare' incorporates:
   *  Abs: '<S251>/Abs'
   *  Constant: '<S252>/Constant'
   *  MinMax: '<S251>/Max'
   *  Sum: '<S251>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S4>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.safe_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.safe_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Auto;
      switch (FMS_B.safe_mode) {
       case PilotMode_Offboard:
        FMS_DW.is_Auto = FMS_IN_Offboard;
        FMS_B.VehicleState_f = VehicleState_Offboard;
        break;

       case PilotMode_Mission:
        FMS_DW.is_Auto = FMS_IN_Mission;
        FMS_B.VehicleState_f = VehicleState_Mission;
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        FMS_B.VehicleState_f = VehicleState_InvalidAutoMode;
        break;
      }
    } else if (FMS_getArmMode(FMS_B.safe_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (FMS_getArmMode(FMS_B.safe_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.safe_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_b;
        FMS_B.VehicleState_f = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
        FMS_B.VehicleState_f = VehicleState_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
      FMS_B.VehicleState_f = VehicleState_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_DW.is_SubMode = FMS_IN_Hold_b;
      FMS_B.VehicleState_f = VehicleState_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold_b:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = ((FMS_DW.M_msgReservedData ==
            CMD_Continue) && (FMS_B.safe_mode != PilotMode_None));
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1))
        {
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.VehicleState_f = VehicleState_Disarm;
        }
        break;

       case FMS_IN_Return:
        scale = 1.29246971E-26F;
        absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0]);
        if (absxk > 1.29246971E-26F) {
          y = 1.0F;
          scale = absxk;
        } else {
          t = absxk / 1.29246971E-26F;
          y = t * t;
        }

        absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }

        y = scale * sqrtf(y);
        if (y < 1.0F) {
          FMS_B.Cmd_In.p_land[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.p_land[1] = FMS_DW.home[1];
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.VehicleState_f = VehicleState_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
        }
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R - FMS_DW.home[2] > 1.5F) {
          if (FMS_B.safe_mode != PilotMode_None) {
            tmp = FMS_getArmMode(FMS_B.safe_mode);
            if (tmp == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Auto;
              switch (FMS_B.safe_mode) {
               case PilotMode_Offboard:
                FMS_DW.is_Auto = FMS_IN_Offboard;
                FMS_B.VehicleState_f = VehicleState_Offboard;
                break;

               case PilotMode_Mission:
                FMS_DW.is_Auto = FMS_IN_Mission;
                FMS_B.VehicleState_f = VehicleState_Mission;
                break;

               default:
                FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
                FMS_B.VehicleState_f = VehicleState_InvalidAutoMode;
                break;
              }
            } else if (tmp == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Assist;
              FMS_enter_internal_Assist();
            } else if (tmp == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.safe_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_b;
                FMS_B.VehicleState_f = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
                FMS_B.VehicleState_f = VehicleState_InValidManualMode;
              }
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
              FMS_B.VehicleState_f = VehicleState_InvalidArmMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_Hold_b;
            FMS_B.VehicleState_f = VehicleState_Hold;
          }
        }
        break;
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Arm(void)
{
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T b_sf_internal_predicateOutput;
  real_T tmp;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
    FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
  if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_l >=
      500) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.VehicleState_f = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.safe_mode !=
              PilotMode_None)) {
    tmp = FMS_getArmMode(FMS_B.safe_mode);
    if (tmp == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
      switch (FMS_B.safe_mode) {
       case PilotMode_Offboard:
        FMS_DW.is_Auto = FMS_IN_Offboard;
        FMS_B.VehicleState_f = VehicleState_Offboard;
        break;

       case PilotMode_Mission:
        FMS_DW.is_Auto = FMS_IN_Mission;
        FMS_B.VehicleState_f = VehicleState_Mission;
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        FMS_B.VehicleState_f = VehicleState_InvalidAutoMode;
        break;
      }
    } else if (tmp == 2.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (tmp == 1.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.safe_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_b;
        FMS_B.VehicleState_f = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
        FMS_B.VehicleState_f = VehicleState_InValidManualMode;
      }
    } else {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
      FMS_B.VehicleState_f = VehicleState_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Land);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.p_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.p_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.VehicleState_f = VehicleState_Land;
      FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
    } else {
      if (FMS_sf_msg_pop_M()) {
        b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Return);
      } else {
        b_sf_internal_predicateOutput = false;
      }

      if (b_sf_internal_predicateOutput) {
        FMS_B.Cmd_In.p_return[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.p_return[1] = FMS_DW.home[1];
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_SubMode;
        FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
        FMS_DW.stick_val[1] =
          FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
        FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
        FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
        FMS_DW.is_SubMode = FMS_IN_Return;
        FMS_B.VehicleState_f = VehicleState_Return;
      } else {
        switch (FMS_DW.is_Arm) {
         case FMS_IN_Assist:
          if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.VehicleState_f = VehicleState_Disarm;
          }
          break;

         case FMS_IN_Auto:
          if (FMS_sf_msg_pop_M()) {
            b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              CMD_Pause);
          } else {
            b_sf_internal_predicateOutput = false;
          }

          if (b_sf_internal_predicateOutput) {
            FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.is_SubMode = FMS_IN_Hold_b;
            FMS_B.VehicleState_f = VehicleState_Hold;
          } else {
            if (FMS_DW.is_Auto == FMS_IN_InvalidAutoMode) {
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.VehicleState_f = VehicleState_Disarm;
            }
          }
          break;

         case FMS_IN_InvalidArmMode:
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.VehicleState_f = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.VehicleState_f = VehicleState_Disarm;
          }
          break;

         case FMS_IN_SubMode:
          FMS_SubMode();
          break;
        }
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode)
{
  real_T trigger;
  trigger = 0.0;
  switch (pilot_cmd_mode) {
   case PilotMode_Manual:
   case PilotMode_Acro:
   case PilotMode_Stabilize:
    if (pilot_cmd_stick_throttle > -0.7) {
      trigger = 1.0;
    }
    break;

   case PilotMode_Altitude:
   case PilotMode_Position:
    if (pilot_cmd_stick_throttle > 0.1) {
      trigger = 1.0;
    }
    break;
  }

  return trigger;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Vehicle(void)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Disarm);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
        FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_i = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
    } else {
      FMS_exit_internal_Arm();
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
    }

    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.VehicleState_f = VehicleState_Disarm;
  } else {
    guard1 = false;
    guard2 = false;
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_Arm();
      break;

     case FMS_IN_Disarm:
      if (FMS_sf_msg_pop_M()) {
        sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_PreArm);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        guard1 = true;
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Takeoff);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_DW.prep_takeoff = 1.0;
          sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
            FMS_DW.durationLastReferenceTick_1_d =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_i = sf_internal_predicateOutput;
          guard1 = true;
        }
      }
      break;

     case FMS_IN_Standby:
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.safe_mode != PilotMode_None)) {
        FMS_DW.prep_takeoff = 0.0;
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
          FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_i = sf_internal_predicateOutput;
        FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_Vehicle = FMS_IN_Arm;
        FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
        FMS_enter_internal_Arm();
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
          FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_i = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_d > 500) {
          guard2 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              CMD_Takeoff);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            guard2 = true;
          } else {
            if ((FMS_DW.temporalCounter_i1 >= 7500U) || (FMS_DW.sfEvent ==
                 FMS_event_DisarmEvent)) {
              FMS_DW.prep_takeoff = 0.0;
              sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
              if ((!sf_internal_predicateOutput) ||
                  (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
                FMS_DW.durationLastReferenceTick_1_d =
                  FMS_DW.chartAbsoluteTimeCounter;
              }

              FMS_DW.condWasTrueAtLastTimeStep_1_i = sf_internal_predicateOutput;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.VehicleState_f = VehicleState_Disarm;
            }
          }
        }
      }
      break;
    }

    if (guard2) {
      FMS_B.Cmd_In.p_takeoff[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.p_takeoff[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
        FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_i = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Takeoff;
      FMS_B.VehicleState_f = VehicleState_Takeoff;
    }

    if (guard1) {
      FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      FMS_B.VehicleState_f = VehicleState_Standby;
      FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.condWasTrueAtLastTimeStep_1_i = (FMS_DW.prep_takeoff == 1.0);
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_discard_M(void)
{
  if (FMS_DW.M_isValid) {
    FMS_DW.M_isValid = false;
  }
}

real32_T rt_remf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T q;
  if ((u1 != 0.0F) && (u1 != truncf(u1))) {
    q = fabsf(u0 / u1);
    if (fabsf(q - floorf(q + 0.5F)) <= FLT_EPSILON * q) {
      y = 0.0F;
    } else {
      y = fmodf(u0, u1);
    }
  } else {
    y = fmodf(u0, u1);
  }

  return y;
}

void FMS_initQueue(Queue_FMS_Cmd *q, QueuePolicy_T policy, int32_T capacity,
                   Msg_FMS_Cmd *qPool)
{
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void initialize_msg_local_queues_for(void)
{
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_o, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_p[1]);
}

/* Model step function */
void FMS_step(void)
{
  int32_T b_previousEvent;
  real32_T dis;
  real32_T B;
  real32_T D;
  int8_T rtb_Saturation_g;
  uint16_T rtb_Divide_b;
  int8_T rtPrevAction;
  real32_T rtb_VectorConcatenate_m[9];
  real32_T rtb_a_b;
  real32_T rtb_Sqrt_d;
  MotionState rtb_state_a;
  real32_T rtb_Switch_l[3];
  real32_T rtb_Rem;
  real32_T rtb_Switch;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  boolean_T rtb_LogicalOperator_at;
  boolean_T u;
  real32_T rtb_MathFunction_idx_1;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_MathFunction_idx_0;
  real32_T rtb_TmpSignalConversionAtMath_1;
  real32_T rtb_MathFunction_hf_idx_1;
  real32_T rtb_MathFunction_h_idx_0;
  real32_T rtb_Switch_b_idx_1;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  Delay: '<S9>/Delay'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S9>/Logical Operator'
   *  Logic: '<S9>/Logical Operator1'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  Switch: '<S9>/Switch1'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S9>/Switch1' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion1'
       *  Delay: '<S9>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<Root>/Mode Degrade' incorporates:
   *  Delay: '<S9>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    switch (FMS_DW.Delay_DSTATE_c) {
     case PilotMode_Manual:
      FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      break;

     case PilotMode_Acro:
      FMS_DW.is_c3_FMS = FMS_IN_Acro;
      break;

     case PilotMode_Stabilize:
      FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      break;

     case PilotMode_Altitude:
      FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Acro:
      FMS_Acro();
      break;

     case FMS_IN_Altitude:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_B.safe_mode = PilotMode_Altitude;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Manual:
          FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
          break;

         case PilotMode_Acro:
          FMS_DW.is_c3_FMS = FMS_IN_Acro;
          break;

         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
      break;

     case FMS_IN_Manual_e:
      FMS_B.safe_mode = PilotMode_Manual;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Manual:
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
        break;

       case PilotMode_Acro:
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
        break;

       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Mission_g:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_B.safe_mode = PilotMode_Mission;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Manual:
          FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
          break;

         case PilotMode_Acro:
          FMS_DW.is_c3_FMS = FMS_IN_Acro;
          break;

         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      }
      break;

     case FMS_IN_Other:
      FMS_B.safe_mode = FMS_DW.Delay_DSTATE_c;
      switch (FMS_DW.Delay_DSTATE_c) {
       case PilotMode_Manual:
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
        break;

       case PilotMode_Acro:
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
        break;

       case PilotMode_Stabilize:
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Position_f:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_B.safe_mode = PilotMode_Position;
        switch (FMS_DW.Delay_DSTATE_c) {
         case PilotMode_Manual:
          FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
          break;

         case PilotMode_Acro:
          FMS_DW.is_c3_FMS = FMS_IN_Acro;
          break;

         case PilotMode_Stabilize:
          FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      }
      break;

     default:
      FMS_Stabilize();
      break;
    }
  }

  /* End of Chart: '<Root>/Mode Degrade' */

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Delay: '<S8>/Delay'
   */
  if (FMS_DW.Delay_DSTATE_g > 1) {
    rtb_Saturation_g = 1;
  } else if (FMS_DW.Delay_DSTATE_g < 0) {
    rtb_Saturation_g = 0;
  } else {
    rtb_Saturation_g = FMS_DW.Delay_DSTATE_g;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S8>/Switch' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (rtb_Saturation_g > 0) {
    FMS_B.fms_cmd = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    FMS_B.fms_cmd = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  }

  /* End of Switch: '<S8>/Switch' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S254>/Discrete-Time Integrator5' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In3'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = FMS_U.INS_Out.ax;
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = FMS_U.INS_Out.ay;
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = FMS_U.INS_Out.az;
  }

  /* Product: '<S6>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S6>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S255>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S255>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S253>/Constant'
   *  DiscreteIntegrator: '<S254>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S255>/Discrete-Time Integrator5'
   *  Logic: '<S256>/AND'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S253>/Compare'
   *  RelationalOperator: '<S256>/Lower Test'
   *  RelationalOperator: '<S256>/Upper Test'
   */
  FMS_B.LogicalOperator1 = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) && ((-0.5F <=
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) && ((-10.306F <=
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d < 1200.0F));

  /* Chart: '<Root>/FMS State Machine' */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
  rtb_LogicalOperator_at = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_LogicalOperator_at) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
    FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_i = rtb_LogicalOperator_at;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
    FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
  rtb_LogicalOperator_at = !FMS_DW.br;
  if (rtb_LogicalOperator_at || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
    FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_l = FMS_DW.br;
  u = !FMS_DW.bl;
  if (u || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 8191U) {
    FMS_DW.temporalCounter_i1++;
  }

  FMS_DW.sfEvent = -1;
  FMS_DW.cmd_prev = FMS_DW.cmd_start;
  FMS_DW.cmd_start = FMS_B.fms_cmd;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.safe_mode;
  FMS_DW.M_isValid = false;
  if (FMS_DW.is_active_c11_FMS == 0U) {
    FMS_DW.cmd_prev = FMS_B.fms_cmd;
    FMS_DW.mode_prev = FMS_B.safe_mode;
    FMS_DW.chartAbsoluteTimeCounter = 0;
    FMS_DW.is_active_c11_FMS = 1U;
    FMS_DW.is_active_Command_Listener = 1U;
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    FMS_DW.is_active_Combo_Stick = 1U;
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.is_active_Vehicle = 1U;
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.VehicleState_f = VehicleState_Disarm;
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      switch (FMS_DW.is_Command_Listener) {
       case FMS_IN_Check:
        if (FMS_DW.valid_cmd) {
          FMS_DW.is_Command_Listener = FMS_IN_Send;
          FMS_DW.M_msgReservedData = FMS_B.fms_cmd;
          FMS_sf_msg_send_M();
        } else {
          FMS_DW.is_Command_Listener = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.fms_cmd != CMD_None))
        {
          FMS_DW.is_Command_Listener = FMS_IN_Check;
          FMS_DW.valid_cmd = FMS_CheckCmdValid(FMS_B.fms_cmd, FMS_B.safe_mode,
            FMS_B.BusConversion_InsertedFor_FMSSt.flag);
        }
        break;

       case FMS_IN_Send:
        FMS_DW.is_Command_Listener = FMS_IN_Listen;
        break;
      }
    }

    if (FMS_DW.is_active_Combo_Stick != 0U) {
      switch (FMS_DW.is_Combo_Stick) {
       case FMS_IN_Arm:
        if (!FMS_BottomRight(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
        }
        break;

       case FMS_IN_Idle:
        if (rtb_LogicalOperator_at || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
          FMS_DW.durationLastReferenceTick_1_m = FMS_DW.chartAbsoluteTimeCounter;
        }

        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_m > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = CMD_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if (u || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2 > 375) {
            FMS_DW.is_Combo_Stick = FMS_IN_Disarm;
            b_previousEvent = FMS_DW.sfEvent;
            FMS_DW.sfEvent = FMS_event_DisarmEvent;
            if (FMS_DW.is_active_Vehicle != 0U) {
              FMS_Vehicle();
            }

            FMS_DW.sfEvent = b_previousEvent;
          } else {
            FMS_DW.bl = FMS_BottomLeft
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
              FMS_DW.durationLastReferenceTick_1_m =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_l = FMS_DW.br;
          }
        }
        break;
      }
    }

    if (FMS_DW.is_active_Vehicle != 0U) {
      FMS_Vehicle();
    }
  }

  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SwitchCase: '<S2>/Switch Case' */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;
  switch (FMS_B.VehicleState_f) {
   case VehicleState_Disarm:
   case VehicleState_None:
    FMS_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case VehicleState_Standby:
    FMS_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 2;
    break;
  }

  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S17>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S24>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S217>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S207>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S163>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S141>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S151>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
     case 3:
     case 4:
      break;

     case 2:
      /* Disable for SwitchCase: '<S21>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S117>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S53>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S93>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S69>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S80>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S17>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Disarm' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S2>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Standby' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S19>/Bus Assignment'
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S19>/Constant'
     *  SignalConversion: '<S19>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S19>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S19>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    FMS_Y.FMS_Out.actuator_cmd[0] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[1] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[2] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[3] = 1150U;
    for (b_previousEvent = 0; b_previousEvent < 12; b_previousEvent++) {
      FMS_Y.FMS_Out.actuator_cmd[b_previousEvent + 4] = 0U;
    }

    /* End of Outputs for SubSystem: '<S2>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/Arm' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* SwitchCase: '<S17>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;
    switch (FMS_B.VehicleState_f) {
     case VehicleState_Land:
     case VehicleState_Return:
     case VehicleState_Takeoff:
     case VehicleState_Hold:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 0;
      break;

     case VehicleState_Offboard:
     case VehicleState_Mission:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 1;
      break;

     case VehicleState_Acro:
     case VehicleState_Stabilize:
     case VehicleState_Altitude:
     case VehicleState_Position:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 2;
      break;

     case VehicleState_Manual:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 3;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 4;
      break;
    }

    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S24>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S217>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S207>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S163>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S141>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S151>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
       case 3:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S21>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S117>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S36>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S53>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S93>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S80>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S17>/SubMode' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SwitchCase: '<S24>/Switch Case' incorporates:
       *  Math: '<S238>/Math Function'
       *  Sum: '<S202>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
      switch (FMS_B.VehicleState_f) {
       case VehicleState_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleState_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 4;
        break;
      }

      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_a) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S217>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S207>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S163>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S141>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S151>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S24>/Takeoff' incorporates:
         *  ActionPort: '<S136>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S250>/Trigonometric Function1' incorporates:
         *  Gain: '<S249>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S250>/Trigonometric Function3'
         */
        rtb_TmpSignalConversionAtMath_1 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[0] = rtb_TmpSignalConversionAtMath_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S250>/Trigonometric Function' incorporates:
         *  Gain: '<S249>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S250>/Trigonometric Function2'
         */
        rtb_Rem = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[1] = rtb_Rem;

        /* SignalConversion: '<S250>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S250>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Gain: '<S250>/Gain' */
        rtb_VectorConcatenate_m[3] = -rtb_Rem;

        /* Trigonometry: '<S250>/Trigonometric Function3' */
        rtb_VectorConcatenate_m[4] = rtb_TmpSignalConversionAtMath_1;

        /* SignalConversion: '<S250>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S250>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S250>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S247>/Saturation1' */
        rtb_Sqrt_d = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S247>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S247>/Sum'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.p_takeoff[0] - FMS_U.INS_Out.x_R;
        rtb_a_b = FMS_B.Cmd_In.p_takeoff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S247>/Multiply' */
        for (b_previousEvent = 0; b_previousEvent < 3; b_previousEvent++) {
          rtb_Switch_l[b_previousEvent] =
            rtb_VectorConcatenate_m[b_previousEvent + 3] * rtb_a_b +
            rtb_VectorConcatenate_m[b_previousEvent] * rtb_Switch_b_idx_1;
        }

        /* Saturate: '<S247>/Saturation1' incorporates:
         *  Gain: '<S247>/Gain2'
         *  Product: '<S247>/Multiply'
         */
        rtb_Rem = FMS_PARAM.XY_P * rtb_Switch_l[0];
        rtb_Switch_b_idx_1 = FMS_PARAM.XY_P * rtb_Switch_l[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S136>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S136>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S136>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S247>/Saturation1' */
        if (rtb_Rem > rtb_Sqrt_d) {
          /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_d;
        } else if (rtb_Rem < rtb_Switch) {
          /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch;
        } else {
          /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem;
        }

        if (rtb_Switch_b_idx_1 > rtb_Sqrt_d) {
          /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_d;
        } else if (rtb_Switch_b_idx_1 < rtb_Switch) {
          /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch;
        } else {
          /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_b_idx_1;
        }

        /* BusAssignment: '<S136>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S136>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = -0.5F;

        /* End of Outputs for SubSystem: '<S24>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Land' incorporates:
         *  ActionPort: '<S134>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S180>/Trigonometric Function1' incorporates:
         *  Gain: '<S179>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S180>/Trigonometric Function' incorporates:
         *  Gain: '<S179>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S180>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Gain: '<S180>/Gain' incorporates:
         *  Gain: '<S179>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S180>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_m[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S180>/Trigonometric Function3' incorporates:
         *  Gain: '<S179>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S180>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S180>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S176>/Saturation1' */
        rtb_Switch = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Sqrt_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S177>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S177>/Sum'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.p_land[0] - FMS_U.INS_Out.x_R;
        rtb_a_b = FMS_B.Cmd_In.p_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S177>/Multiply' */
        for (b_previousEvent = 0; b_previousEvent < 3; b_previousEvent++) {
          rtb_Switch_l[b_previousEvent] =
            rtb_VectorConcatenate_m[b_previousEvent + 3] * rtb_a_b +
            rtb_VectorConcatenate_m[b_previousEvent] * rtb_Switch_b_idx_1;
        }

        /* Saturate: '<S176>/Saturation1' incorporates:
         *  Gain: '<S177>/Gain2'
         *  Product: '<S177>/Multiply'
         */
        rtb_Rem = FMS_PARAM.XY_P * rtb_Switch_l[0];
        rtb_Switch_b_idx_1 = FMS_PARAM.XY_P * rtb_Switch_l[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S134>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S134>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S134>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S176>/Saturation1' */
        if (rtb_Rem > rtb_Switch) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch;
        } else if (rtb_Rem < rtb_Sqrt_d) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_d;
        } else {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem;
        }

        if (rtb_Switch_b_idx_1 > rtb_Switch) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch;
        } else if (rtb_Switch_b_idx_1 < rtb_Sqrt_d) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_d;
        } else {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_b_idx_1;
        }

        /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S134>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S24>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S135>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S183>/Delay'
           *  Delay: '<S184>/Delay'
           *  DiscreteIntegrator: '<S187>/Integrator'
           *  DiscreteIntegrator: '<S187>/Integrator1'
           *  DiscreteIntegrator: '<S243>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S24>/Return' */

          /* SystemReset for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S135>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S208>/Motion Status'
           *  Chart: '<S218>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S24>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S135>/Action Port'
         */
        /* Delay: '<S183>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S199>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S204>/Square'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sqrt_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.p_return[0];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Sqrt_d * rtb_Sqrt_d;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.p_return[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S204>/Square' */
        rtb_Sqrt_d *= rtb_Sqrt_d;

        /* Sqrt: '<S204>/Sqrt' incorporates:
         *  Sum: '<S204>/Sum of Elements'
         */
        rtb_Sqrt_d = sqrtf(rtb_TmpSignalConversionAtMath_1 + rtb_Sqrt_d);

        /* Switch: '<S199>/Switch' incorporates:
         *  Constant: '<S199>/vel'
         */
        if (rtb_Sqrt_d > 10.0F) {
          rtb_Switch = 5.0F;
        } else {
          /* Gain: '<S199>/Gain' */
          rtb_Switch = 0.5F * rtb_Sqrt_d;

          /* Saturate: '<S199>/Saturation' */
          if (rtb_Switch < 0.5F) {
            rtb_Switch = 0.5F;
          }

          /* End of Saturate: '<S199>/Saturation' */
        }

        /* End of Switch: '<S199>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S218>/Motion State' incorporates:
         *  Constant: '<S218>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S218>/Square'
         *  Math: '<S218>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S218>/Sqrt'
         *  Sum: '<S218>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S217>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k;
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_k = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_k = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_k = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S217>/Hold Control' incorporates:
             *  ActionPort: '<S220>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S217>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S217>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S217>/Hold Control' incorporates:
           *  ActionPort: '<S220>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S217>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S217>/Brake Control' incorporates:
           *  ActionPort: '<S219>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S217>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S217>/Move Control' incorporates:
             *  ActionPort: '<S221>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S217>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S217>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S217>/Move Control' incorporates:
           *  ActionPort: '<S221>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S217>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S217>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S208>/Motion Status' incorporates:
         *  Abs: '<S208>/Abs'
         *  Constant: '<S208>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S207>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_g = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_g) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S207>/Hold Control' incorporates:
             *  ActionPort: '<S210>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S207>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S207>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S207>/Hold Control' incorporates:
           *  ActionPort: '<S210>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S207>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S207>/Brake Control' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S207>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S207>/Move Control' incorporates:
             *  ActionPort: '<S211>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S207>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S207>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S207>/Move Control' incorporates:
           *  ActionPort: '<S211>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S207>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S207>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S135>/Sum' incorporates:
         *  Delay: '<S183>/Delay'
         *  MATLAB Function: '<S201>/OutRegionRegWP'
         *  MATLAB Function: '<S201>/SearchL1RefWP'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.p_return[0] -
          FMS_DW.Delay_DSTATE[0];
        rtb_MathFunction_hf_idx_1 = FMS_B.Cmd_In.p_return[1] -
          FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S198>/Math Function' incorporates:
         *  Math: '<S244>/Math Function'
         *  Sum: '<S135>/Sum'
         *  Switch: '<S182>/Switch'
         */
        rtb_Switch_b_idx_1 = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;
        rtb_Sqrt_d = rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Sum: '<S198>/Sum of Elements' incorporates:
         *  Math: '<S198>/Math Function'
         */
        rtb_a_b = rtb_Sqrt_d + rtb_Switch_b_idx_1;

        /* Math: '<S198>/Math Function1' incorporates:
         *  Sum: '<S198>/Sum of Elements'
         *
         * About '<S198>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_a_b < 0.0F) {
          rtb_a_b = -sqrtf(fabsf(rtb_a_b));
        } else {
          rtb_a_b = sqrtf(rtb_a_b);
        }

        /* End of Math: '<S198>/Math Function1' */

        /* Switch: '<S198>/Switch' incorporates:
         *  Constant: '<S198>/Constant'
         *  Product: '<S198>/Product'
         *  Sum: '<S135>/Sum'
         */
        if (rtb_a_b > 0.0F) {
          rtb_Switch_l[0] = rtb_MathFunction_hf_idx_1;
          rtb_Switch_l[1] = rtb_MathFunction_h_idx_0;
          rtb_Switch_l[2] = rtb_a_b;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S198>/Switch' */

        /* Product: '<S198>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S196>/Subtract' incorporates:
         *  Product: '<S196>/Multiply'
         *  Product: '<S196>/Multiply1'
         */
        rtb_a_b = rtb_TmpSignalConversionAtMath_1 * FMS_ConstB.Divide[1] -
          rtb_TmpSignalConversionAtMath_0 * FMS_ConstB.Divide[0];

        /* Signum: '<S185>/Sign1' */
        if (rtb_a_b < 0.0F) {
          rtb_a_b = -1.0F;
        } else {
          if (rtb_a_b > 0.0F) {
            rtb_a_b = 1.0F;
          }
        }

        /* End of Signum: '<S185>/Sign1' */

        /* Switch: '<S185>/Switch2' incorporates:
         *  Constant: '<S185>/Constant4'
         */
        if (rtb_a_b == 0.0F) {
          rtb_a_b = 1.0F;
        }

        /* End of Switch: '<S185>/Switch2' */

        /* DotProduct: '<S185>/Dot Product' */
        rtb_Rem = FMS_ConstB.Divide[0] * rtb_TmpSignalConversionAtMath_1 +
          FMS_ConstB.Divide[1] * rtb_TmpSignalConversionAtMath_0;

        /* Trigonometry: '<S185>/Acos' incorporates:
         *  DotProduct: '<S185>/Dot Product'
         */
        if (rtb_Rem > 1.0F) {
          rtb_Rem = 1.0F;
        } else {
          if (rtb_Rem < -1.0F) {
            rtb_Rem = -1.0F;
          }
        }

        /* Product: '<S185>/Multiply' incorporates:
         *  Trigonometry: '<S185>/Acos'
         */
        rtb_a_b *= acosf(rtb_Rem);

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S189>/Rem' incorporates:
         *  Constant: '<S189>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S184>/Sum1'
         */
        rtb_Rem = rt_remf(rtb_a_b - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Switch: '<S189>/Switch' incorporates:
         *  Abs: '<S189>/Abs'
         *  Constant: '<S189>/Constant'
         *  Constant: '<S195>/Constant'
         *  Product: '<S189>/Multiply'
         *  RelationalOperator: '<S195>/Compare'
         *  Sum: '<S189>/Add'
         */
        if (fabsf(rtb_Rem) > 3.14159274F) {
          /* Signum: '<S189>/Sign' */
          if (rtb_Rem < 0.0F) {
            rtb_TmpSignalConversionAtMath_1 = -1.0F;
          } else if (rtb_Rem > 0.0F) {
            rtb_TmpSignalConversionAtMath_1 = 1.0F;
          } else {
            rtb_TmpSignalConversionAtMath_1 = rtb_Rem;
          }

          /* End of Signum: '<S189>/Sign' */
          rtb_Rem -= 6.28318548F * rtb_TmpSignalConversionAtMath_1;
        }

        /* End of Switch: '<S189>/Switch' */

        /* Abs: '<S182>/Abs' */
        rtb_Rem = fabsf(rtb_Rem);

        /* Switch: '<S182>/Switch' incorporates:
         *  Product: '<S203>/Multiply'
         */
        if (rtb_Rem > 0.261799395F) {
          /* Saturate: '<S217>/Saturation1' */
          if (FMS_B.Merge_mv[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[0] = FMS_B.Merge_mv[0];
          }

          if (FMS_B.Merge_mv[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[1] = FMS_B.Merge_mv[1];
          }

          /* End of Saturate: '<S217>/Saturation1' */

          /* Saturate: '<S207>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_l[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S207>/Saturation1' */
        } else {
          /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S246>/Constant4'
           */
          rtb_VectorConcatenate_m[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Gain: '<S245>/Gain' incorporates:
           *  DiscreteIntegrator: '<S243>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S3>/Signal Copy1'
           *  Sum: '<S243>/Add'
           */
          rtb_Rem = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* Trigonometry: '<S246>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S246>/Trigonometric Function1'
           */
          rtb_TmpSignalConversionAtMath_1 = arm_cos_f32(rtb_Rem);
          rtb_VectorConcatenate_m[4] = rtb_TmpSignalConversionAtMath_1;

          /* Trigonometry: '<S246>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S246>/Trigonometric Function'
           */
          rtb_Rem = arm_sin_f32(rtb_Rem);

          /* Gain: '<S246>/Gain' incorporates:
           *  Trigonometry: '<S246>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_m[3] = -rtb_Rem;

          /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S246>/Constant3'
           */
          rtb_VectorConcatenate_m[2] = 0.0F;

          /* Trigonometry: '<S246>/Trigonometric Function' */
          rtb_VectorConcatenate_m[1] = rtb_Rem;

          /* Trigonometry: '<S246>/Trigonometric Function1' */
          rtb_VectorConcatenate_m[0] = rtb_TmpSignalConversionAtMath_1;

          /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S244>/Sum of Elements' */
          rtb_Switch_b_idx_1 += rtb_Sqrt_d;

          /* Math: '<S244>/Math Function1' incorporates:
           *  Sum: '<S244>/Sum of Elements'
           *
           * About '<S244>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_b_idx_1 < 0.0F) {
            rtb_Rem = -sqrtf(fabsf(rtb_Switch_b_idx_1));
          } else {
            rtb_Rem = sqrtf(rtb_Switch_b_idx_1);
          }

          /* End of Math: '<S244>/Math Function1' */

          /* Switch: '<S244>/Switch' incorporates:
           *  Constant: '<S244>/Constant'
           *  Product: '<S244>/Product'
           *  Sum: '<S135>/Sum'
           */
          if (rtb_Rem > 0.0F) {
            rtb_Sqrt_d = rtb_MathFunction_h_idx_0;
            rtb_Switch_b_idx_1 = rtb_MathFunction_hf_idx_1;
          } else {
            rtb_Sqrt_d = 0.0F;
            rtb_Switch_b_idx_1 = 0.0F;
            rtb_Rem = 1.0F;
          }

          /* End of Switch: '<S244>/Switch' */

          /* Product: '<S242>/Multiply2' incorporates:
           *  Product: '<S244>/Divide'
           */
          rtb_Sqrt_d = rtb_Sqrt_d / rtb_Rem * rtb_Switch;
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_1 / rtb_Rem * rtb_Switch;
          for (b_previousEvent = 0; b_previousEvent < 3; b_previousEvent++) {
            rtb_Switch_l[b_previousEvent] =
              rtb_VectorConcatenate_m[b_previousEvent + 3] * rtb_Switch_b_idx_1
              + rtb_VectorConcatenate_m[b_previousEvent] * rtb_Sqrt_d;
          }
        }

        /* Delay: '<S184>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* DiscreteIntegrator: '<S187>/Integrator1' incorporates:
         *  Delay: '<S184>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S191>/Rem' incorporates:
         *  Constant: '<S191>/Constant1'
         *  DiscreteIntegrator: '<S187>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S186>/Sum'
         */
        rtb_Rem = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                          6.28318548F);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Switch: '<S191>/Switch' incorporates:
         *  Abs: '<S191>/Abs'
         *  Constant: '<S191>/Constant'
         *  Constant: '<S192>/Constant'
         *  Product: '<S191>/Multiply'
         *  RelationalOperator: '<S192>/Compare'
         *  Sum: '<S191>/Add'
         */
        if (fabsf(rtb_Rem) > 3.14159274F) {
          /* Signum: '<S191>/Sign' */
          if (rtb_Rem < 0.0F) {
            rtb_Sqrt_d = -1.0F;
          } else if (rtb_Rem > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          } else {
            rtb_Sqrt_d = rtb_Rem;
          }

          /* End of Signum: '<S191>/Sign' */
          rtb_Rem -= 6.28318548F * rtb_Sqrt_d;
        }

        /* End of Switch: '<S191>/Switch' */

        /* Gain: '<S186>/Gain2' */
        rtb_Rem *= FMS_PARAM.YAW_P;

        /* Saturate: '<S186>/Saturation' */
        if (rtb_Rem > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S186>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S135>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S135>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S135>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_l[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_l[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_l[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S237>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S237>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S236>/Sum of Elements'
         */
        rtb_Switch_b_idx_1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S237>/Math Function1' incorporates:
         *  Sum: '<S237>/Sum of Elements'
         *
         * About '<S237>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Rem = -sqrtf(fabsf(rtb_Switch_b_idx_1));
        } else {
          rtb_Rem = sqrtf(rtb_Switch_b_idx_1);
        }

        /* End of Math: '<S237>/Math Function1' */

        /* Switch: '<S237>/Switch' incorporates:
         *  Constant: '<S237>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S237>/Product'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (rtb_Rem > 0.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          rtb_Switch_l[2] = rtb_Rem;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S237>/Switch' */

        /* Product: '<S237>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S240>/Sum of Elements' incorporates:
         *  Math: '<S240>/Math Function'
         *  SignalConversion: '<S240>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_d = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtMath_1 *
          rtb_TmpSignalConversionAtMath_1;

        /* Math: '<S240>/Math Function1' incorporates:
         *  Sum: '<S240>/Sum of Elements'
         *
         * About '<S240>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Rem = -sqrtf(fabsf(rtb_Sqrt_d));
        } else {
          rtb_Rem = sqrtf(rtb_Sqrt_d);
        }

        /* End of Math: '<S240>/Math Function1' */

        /* Switch: '<S240>/Switch' incorporates:
         *  Constant: '<S240>/Constant'
         *  Product: '<S240>/Product'
         */
        if (rtb_Rem > 0.0F) {
          rtb_Switch_l[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_l[1] = rtb_TmpSignalConversionAtMath_1;
          rtb_Switch_l[2] = rtb_Rem;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S240>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S201>/NearbyRefWP' incorporates:
         *  Constant: '<S135>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_TmpSignalConversionAtMath_1 = FMS_B.Cmd_In.p_return[0] -
          FMS_U.INS_Out.x_R;
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.p_return[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        dis = sqrtf(rtb_TmpSignalConversionAtMath_1 *
                    rtb_TmpSignalConversionAtMath_1 +
                    rtb_TmpSignalConversionAtMath_0 *
                    rtb_TmpSignalConversionAtMath_0);
        if (dis <= 10.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_TmpSignalConversionAtMath_1 = FMS_B.Cmd_In.p_return[0];
          rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.p_return[1];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          dis = -1.0F;
          rtb_TmpSignalConversionAtMath_1 = 0.0F;
          rtb_TmpSignalConversionAtMath_0 = 0.0F;
        }

        /* End of MATLAB Function: '<S201>/NearbyRefWP' */

        /* MATLAB Function: '<S201>/SearchL1RefWP' incorporates:
         *  Constant: '<S135>/L1'
         *  Delay: '<S183>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Rem = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 +
          rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        B = (rtb_MathFunction_h_idx_0 * (FMS_DW.Delay_DSTATE[0] -
              FMS_U.INS_Out.x_R) + rtb_MathFunction_hf_idx_1 *
             (FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE[0] * FMS_DW.Delay_DSTATE[0]) +
                       FMS_DW.Delay_DSTATE[1] * FMS_DW.Delay_DSTATE[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE[1]) * 2.0F) -
                     100.0F) * (4.0F * rtb_Rem);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_d = -1.0F;
        rtb_MathFunction_idx_0 = 0.0F;
        rtb_MathFunction_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Rem);
          rtb_Rem = (-B - u1_tmp) / (2.0F * rtb_Rem);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Rem >= 0.0F) && (rtb_Rem <=
               1.0F)) {
            rtb_Sqrt_d = fmaxf(D, rtb_Rem);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Sqrt_d = D;
            guard1 = true;
          } else {
            if ((rtb_Rem >= 0.0F) && (rtb_Rem <= 1.0F)) {
              rtb_Sqrt_d = rtb_Rem;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Rem);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Sqrt_d = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_idx_0 = rtb_MathFunction_h_idx_0 * rtb_Sqrt_d +
            FMS_DW.Delay_DSTATE[0];
          rtb_MathFunction_idx_1 = rtb_MathFunction_hf_idx_1 * rtb_Sqrt_d +
            FMS_DW.Delay_DSTATE[1];
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S201>/OutRegionRegWP' incorporates:
         *  Delay: '<S183>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) *
                   rtb_MathFunction_hf_idx_1 + (FMS_U.INS_Out.x_R -
                    FMS_DW.Delay_DSTATE[0]) * rtb_MathFunction_h_idx_0) /
          (rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 +
           rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_LogicalOperator_at = (rtb_Rem <= 0.0F);
        u = (rtb_Rem >= 1.0F);
        if (rtb_LogicalOperator_at) {
          rtb_MathFunction_h_idx_0 = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.p_return[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          rtb_MathFunction_h_idx_0 = rtb_Rem * rtb_MathFunction_h_idx_0 +
            FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S201>/Switch1' incorporates:
         *  Constant: '<S231>/Constant'
         *  RelationalOperator: '<S231>/Compare'
         */
        if (dis <= 0.0F) {
          /* Switch: '<S201>/Switch' incorporates:
           *  Constant: '<S230>/Constant'
           *  MATLAB Function: '<S201>/SearchL1RefWP'
           *  RelationalOperator: '<S230>/Compare'
           */
          if (rtb_Sqrt_d >= 0.0F) {
            rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_idx_0;
            rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_idx_1;
          } else {
            rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_h_idx_0;

            /* MATLAB Function: '<S201>/OutRegionRegWP' incorporates:
             *  Delay: '<S183>/Delay'
             *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_LogicalOperator_at) {
              rtb_TmpSignalConversionAtMath_0 = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.p_return[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            } else {
              rtb_TmpSignalConversionAtMath_0 = rtb_Rem *
                rtb_MathFunction_hf_idx_1 + FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S201>/Switch' */
        }

        /* End of Switch: '<S201>/Switch1' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S202>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_MathFunction_hf_idx_1 = rtb_TmpSignalConversionAtMath_1 -
          FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_hf_idx_1;
        rtb_Sqrt_d = rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S202>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S238>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_MathFunction_hf_idx_1 = rtb_TmpSignalConversionAtMath_0 -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S238>/Sum of Elements' incorporates:
         *  Math: '<S238>/Math Function'
         */
        rtb_Sqrt_d += rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Math: '<S238>/Math Function1' incorporates:
         *  Sum: '<S238>/Sum of Elements'
         *
         * About '<S238>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Rem = -sqrtf(fabsf(rtb_Sqrt_d));
        } else {
          rtb_Rem = sqrtf(rtb_Sqrt_d);
        }

        /* End of Math: '<S238>/Math Function1' */

        /* Switch: '<S238>/Switch' incorporates:
         *  Constant: '<S238>/Constant'
         *  Product: '<S238>/Product'
         */
        if (rtb_Rem <= 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = 0.0F;
          rtb_MathFunction_hf_idx_1 = 0.0F;
          rtb_Rem = 1.0F;
        }

        /* End of Switch: '<S238>/Switch' */

        /* Product: '<S238>/Divide' */
        rtb_MathFunction_idx_0 = rtb_TmpSignalConversionAtMath_1 / rtb_Rem;
        rtb_MathFunction_idx_1 = rtb_MathFunction_hf_idx_1 / rtb_Rem;

        /* Sum: '<S241>/Sum of Elements' incorporates:
         *  Math: '<S241>/Math Function'
         *  SignalConversion: '<S241>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_d = rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1 +
          rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0;

        /* Math: '<S241>/Math Function1' incorporates:
         *  Sum: '<S241>/Sum of Elements'
         *
         * About '<S241>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Rem = -sqrtf(fabsf(rtb_Sqrt_d));
        } else {
          rtb_Rem = sqrtf(rtb_Sqrt_d);
        }

        /* End of Math: '<S241>/Math Function1' */

        /* Switch: '<S241>/Switch' incorporates:
         *  Constant: '<S241>/Constant'
         *  Product: '<S241>/Product'
         */
        if (rtb_Rem > 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_idx_1;
          rtb_MathFunction_hf_idx_1 = rtb_MathFunction_idx_0;
        } else {
          rtb_TmpSignalConversionAtMath_1 = 0.0F;
          rtb_MathFunction_hf_idx_1 = 0.0F;
          rtb_Rem = 1.0F;
        }

        /* End of Switch: '<S241>/Switch' */

        /* Product: '<S241>/Divide' */
        rtb_MathFunction_idx_0 = rtb_TmpSignalConversionAtMath_1 / rtb_Rem;

        /* Product: '<S240>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S241>/Divide' */
        rtb_MathFunction_idx_1 = rtb_MathFunction_hf_idx_1 / rtb_Rem;

        /* Product: '<S240>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sqrt: '<S236>/Sqrt' */
        rtb_Rem = sqrtf(rtb_Switch_b_idx_1);

        /* Gain: '<S202>/Gain' incorporates:
         *  Math: '<S202>/Square'
         */
        rtb_Switch_b_idx_1 = rtb_Rem * rtb_Rem * 2.0F;

        /* Sum: '<S239>/Subtract' incorporates:
         *  Product: '<S239>/Multiply'
         *  Product: '<S239>/Multiply1'
         */
        rtb_Rem = rtb_MathFunction_idx_0 * rtb_TmpSignalConversionAtMath_0 -
          rtb_MathFunction_idx_1 * rtb_TmpSignalConversionAtMath_1;

        /* Signum: '<S235>/Sign1' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S235>/Sign1' */

        /* Switch: '<S235>/Switch2' incorporates:
         *  Constant: '<S235>/Constant4'
         */
        if (rtb_Rem == 0.0F) {
          rtb_Rem = 1.0F;
        }

        /* End of Switch: '<S235>/Switch2' */

        /* DotProduct: '<S235>/Dot Product' */
        rtb_Sqrt_d = rtb_TmpSignalConversionAtMath_1 * rtb_MathFunction_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_MathFunction_idx_1;

        /* Trigonometry: '<S235>/Acos' incorporates:
         *  DotProduct: '<S235>/Dot Product'
         */
        if (rtb_Sqrt_d > 1.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          if (rtb_Sqrt_d < -1.0F) {
            rtb_Sqrt_d = -1.0F;
          }
        }

        /* Product: '<S235>/Multiply' incorporates:
         *  Trigonometry: '<S235>/Acos'
         */
        rtb_Rem *= acosf(rtb_Sqrt_d);

        /* Saturate: '<S202>/Saturation' */
        if (rtb_Rem > 1.57079637F) {
          rtb_Rem = 1.57079637F;
        } else {
          if (rtb_Rem < -1.57079637F) {
            rtb_Rem = -1.57079637F;
          }
        }

        /* End of Saturate: '<S202>/Saturation' */

        /* Trigonometry: '<S202>/Sin' */
        rtb_MathFunction_hf_idx_1 = arm_sin_f32(rtb_Rem);

        /* Sum: '<S184>/Sum2' incorporates:
         *  Delay: '<S184>/Delay'
         */
        rtb_a_b -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S188>/Rem' incorporates:
         *  Constant: '<S188>/Constant1'
         */
        rtb_Sqrt_d = rt_remf(rtb_a_b, 6.28318548F);

        /* Switch: '<S188>/Switch' incorporates:
         *  Abs: '<S188>/Abs'
         *  Constant: '<S188>/Constant'
         *  Constant: '<S194>/Constant'
         *  Product: '<S188>/Multiply'
         *  RelationalOperator: '<S194>/Compare'
         *  Sum: '<S188>/Add'
         */
        if (fabsf(rtb_Sqrt_d) > 3.14159274F) {
          /* Signum: '<S188>/Sign' */
          if (rtb_Sqrt_d < 0.0F) {
            rtb_a_b = -1.0F;
          } else if (rtb_Sqrt_d > 0.0F) {
            rtb_a_b = 1.0F;
          } else {
            rtb_a_b = rtb_Sqrt_d;
          }

          /* End of Signum: '<S188>/Sign' */
          rtb_Sqrt_d -= 6.28318548F * rtb_a_b;
        }

        /* End of Switch: '<S188>/Switch' */

        /* Sum: '<S193>/Add' incorporates:
         *  Delay: '<S184>/Delay'
         *  DiscreteIntegrator: '<S187>/Integrator'
         *  DiscreteIntegrator: '<S187>/Integrator1'
         *  Sum: '<S184>/Sum'
         *  Sum: '<S187>/Subtract'
         */
        rtb_Rem = (FMS_DW.Integrator1_DSTATE_e - (rtb_Sqrt_d +
                    FMS_DW.Delay_DSTATE_a)) + FMS_DW.Integrator_DSTATE_bs;

        /* Signum: '<S193>/Sign' */
        if (rtb_Rem < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Rem > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Rem;
        }

        /* End of Signum: '<S193>/Sign' */

        /* Sum: '<S193>/Add2' incorporates:
         *  Abs: '<S193>/Abs'
         *  DiscreteIntegrator: '<S187>/Integrator'
         *  Gain: '<S193>/Gain'
         *  Gain: '<S193>/Gain1'
         *  Product: '<S193>/Multiply2'
         *  Product: '<S193>/Multiply3'
         *  Sqrt: '<S193>/Sqrt'
         *  Sum: '<S193>/Add1'
         *  Sum: '<S193>/Subtract'
         */
        rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Rem) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Sqrt_d +
          FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S193>/Add4' incorporates:
         *  DiscreteIntegrator: '<S187>/Integrator'
         */
        rtb_MathFunction_h_idx_0 = (rtb_Rem - rtb_a_b) +
          FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S193>/Add3' */
        rtb_Sqrt_d = rtb_Rem + FMS_ConstB.d_l;

        /* Sum: '<S193>/Subtract1' */
        rtb_Rem -= FMS_ConstB.d_l;

        /* Signum: '<S193>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S193>/Sign1' */

        /* Signum: '<S193>/Sign2' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S193>/Sign2' */

        /* Sum: '<S193>/Add5' incorporates:
         *  Gain: '<S193>/Gain2'
         *  Product: '<S193>/Multiply4'
         *  Sum: '<S193>/Subtract2'
         */
        rtb_a_b += (rtb_Sqrt_d - rtb_Rem) * 0.5F * rtb_MathFunction_h_idx_0;

        /* Update for Delay: '<S183>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S243>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S135>/L1'
         *  Product: '<S202>/Divide'
         *  Product: '<S202>/Multiply1'
         *  Product: '<S203>/Divide1'
         */
        FMS_DW.l1_heading += rtb_MathFunction_hf_idx_1 * rtb_Switch_b_idx_1 /
          10.0F / rtb_Switch * 0.004F;

        /* Update for Delay: '<S184>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S187>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S187>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S193>/Add6' */
        rtb_Sqrt_d = rtb_a_b + FMS_ConstB.d_l;

        /* Sum: '<S193>/Subtract3' */
        rtb_Rem = rtb_a_b - FMS_ConstB.d_l;

        /* Signum: '<S193>/Sign5' */
        if (rtb_a_b < 0.0F) {
          rtb_Switch = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Switch = 1.0F;
        } else {
          rtb_Switch = rtb_a_b;
        }

        /* End of Signum: '<S193>/Sign5' */

        /* Signum: '<S193>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S193>/Sign3' */

        /* Signum: '<S193>/Sign4' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S193>/Sign4' */

        /* Signum: '<S193>/Sign6' */
        if (rtb_a_b < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          rtb_Switch_b_idx_1 = rtb_a_b;
        }

        /* End of Signum: '<S193>/Sign6' */

        /* Update for DiscreteIntegrator: '<S187>/Integrator' incorporates:
         *  Constant: '<S193>/const'
         *  Gain: '<S193>/Gain3'
         *  Product: '<S193>/Divide'
         *  Product: '<S193>/Multiply5'
         *  Product: '<S193>/Multiply6'
         *  Sum: '<S193>/Subtract4'
         *  Sum: '<S193>/Subtract5'
         *  Sum: '<S193>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_a_b / FMS_ConstB.d_l - rtb_Switch) *
          FMS_ConstB.Gain4_np * ((rtb_Sqrt_d - rtb_Rem) * 0.5F) -
          rtb_Switch_b_idx_1 * 0.785398185F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S187>/Integrator' */
        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S24>/Hold' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S142>/Motion Status'
           *  Chart: '<S152>/Motion State'
           *  Chart: '<S164>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S24>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S133>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S142>/Motion Status' incorporates:
         *  Abs: '<S142>/Abs'
         *  Constant: '<S142>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S152>/Motion State' incorporates:
         *  Abs: '<S152>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_a < 255U) {
          FMS_DW.temporalCounter_i1_a++;
        }

        if (FMS_DW.is_active_c15_FMS == 0U) {
          FMS_DW.is_active_c15_FMS = 1U;
          FMS_DW.is_c15_FMS = FMS_IN_Move_n;
          rtb_state_ki = MotionState_Move;
        } else {
          switch (FMS_DW.is_c15_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_ki = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_ki = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c15_FMS = FMS_IN_Brake_o;
            FMS_DW.temporalCounter_i1_a = 0U;
            rtb_state_ki = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S152>/Motion State' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S164>/Motion State' incorporates:
         *  Constant: '<S164>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S164>/Square'
         *  Math: '<S164>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S164>/Sqrt'
         *  Sum: '<S164>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S163>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        switch (rtb_state_l) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_p = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_p = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_p = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S163>/Hold Control' incorporates:
             *  ActionPort: '<S166>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S163>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S163>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S163>/Hold Control' incorporates:
           *  ActionPort: '<S166>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S163>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S163>/Brake Control' incorporates:
           *  ActionPort: '<S165>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S163>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S163>/Move Control' incorporates:
             *  ActionPort: '<S167>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S163>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S163>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S163>/Move Control' incorporates:
           *  ActionPort: '<S167>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S163>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S163>/Switch Case' */

        /* SwitchCase: '<S141>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pp;
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_pp = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_pp = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_pp = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_pp) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S141>/Hold Control' incorporates:
             *  ActionPort: '<S144>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S141>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S141>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S141>/Hold Control' incorporates:
           *  ActionPort: '<S144>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S141>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S141>/Brake Control' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S141>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S141>/Move Control' incorporates:
             *  ActionPort: '<S145>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S141>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S141>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S141>/Move Control' incorporates:
           *  ActionPort: '<S145>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S141>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S141>/Switch Case' */

        /* SwitchCase: '<S151>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bn;
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        switch (rtb_state_ki) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_bn = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_bn = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_bn = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_bn) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S151>/Hold Control' incorporates:
             *  ActionPort: '<S154>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S151>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S151>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S151>/Hold Control' incorporates:
           *  ActionPort: '<S154>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S151>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S151>/Brake Control' incorporates:
           *  ActionPort: '<S153>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S151>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S151>/Move Control' incorporates:
             *  ActionPort: '<S155>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S151>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S151>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S151>/Move Control' incorporates:
           *  ActionPort: '<S155>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S151>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S151>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S133>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S133>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S133>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S151>/Saturation' */
        if (FMS_B.Merge_n > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n;
        }

        /* End of Saturate: '<S151>/Saturation' */

        /* Saturate: '<S163>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S163>/Saturation1' */

        /* Saturate: '<S141>/Saturation1' */
        if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S133>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S141>/Saturation1' */
        /* End of Outputs for SubSystem: '<S24>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S137>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S24>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S24>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S17>/Auto' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* SwitchCase: '<S22>/Switch Case' */
      switch (FMS_B.VehicleState_f) {
       case VehicleState_Offboard:
        /* Outputs for IfAction SubSystem: '<S22>/Offboard' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S131>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S131>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S131>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S22>/Offboard' */
        break;

       case VehicleState_Mission:
        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S130>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S130>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S130>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S130>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;

        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S132>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S22>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S22>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S17>/Assist' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* SwitchCase: '<S21>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;
      switch (FMS_B.VehicleState_f) {
       case VehicleState_Acro:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleState_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 4;
        break;
      }

      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S117>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S36>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S53>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S93>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S80>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S21>/Acro' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Gain: '<S31>/Gain'
         *  Gain: '<S31>/Gain1'
         *  Gain: '<S31>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S32>/Saturation' incorporates:
         *  Constant: '<S32>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S32>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch_b_idx_1 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S32>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S32>/Constant5'
         *  Gain: '<S32>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S32>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_Switch_b_idx_1), 4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S21>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S21>/Stabilize' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S21>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S113>/Integrator'
           *  DiscreteIntegrator: '<S113>/Integrator1'
           *  DiscreteIntegrator: '<S114>/Integrator'
           *  DiscreteIntegrator: '<S114>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S21>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S21>/Stabilize' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S118>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S21>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Stabilize' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Product: '<S115>/Multiply1' incorporates:
         *  Constant: '<S115>/const1'
         *  DiscreteIntegrator: '<S113>/Integrator'
         */
        rtb_a_b = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S111>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S111>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S115>/Add' incorporates:
         *  DiscreteIntegrator: '<S113>/Integrator1'
         *  Gain: '<S108>/Gain'
         *  Gain: '<S111>/Gain'
         *  Sum: '<S113>/Subtract'
         */
        rtb_Rem = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
                    FMS_PARAM.ROLL_DZ) * rtb_Switch_b_idx_1 *
                   FMS_PARAM.ROLL_PITCH_LIM) + rtb_a_b;

        /* Signum: '<S115>/Sign' */
        if (rtb_Rem < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Rem > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Rem;
        }

        /* End of Signum: '<S115>/Sign' */

        /* Sum: '<S115>/Add2' incorporates:
         *  Abs: '<S115>/Abs'
         *  Gain: '<S115>/Gain'
         *  Gain: '<S115>/Gain1'
         *  Product: '<S115>/Multiply2'
         *  Product: '<S115>/Multiply3'
         *  Sqrt: '<S115>/Sqrt'
         *  Sum: '<S115>/Add1'
         *  Sum: '<S115>/Subtract'
         */
        rtb_Switch = (sqrtf((8.0F * fabsf(rtb_Rem) + FMS_ConstB.d_d) *
                            FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Sqrt_d + rtb_a_b;

        /* Sum: '<S115>/Add4' */
        rtb_Switch_b_idx_1 = (rtb_Rem - rtb_Switch) + rtb_a_b;

        /* Sum: '<S115>/Add3' */
        rtb_Sqrt_d = rtb_Rem + FMS_ConstB.d_d;

        /* Sum: '<S115>/Subtract1' */
        rtb_Rem -= FMS_ConstB.d_d;

        /* Signum: '<S115>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign1' */

        /* Signum: '<S115>/Sign2' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign2' */

        /* Sum: '<S115>/Add5' incorporates:
         *  Gain: '<S115>/Gain2'
         *  Product: '<S115>/Multiply4'
         *  Sum: '<S115>/Subtract2'
         */
        rtb_Switch += (rtb_Sqrt_d - rtb_Rem) * 0.5F * rtb_Switch_b_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S118>/Motion State' incorporates:
         *  Abs: '<S118>/Abs'
         *  Abs: '<S118>/Abs1'
         *  Constant: '<S128>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S128>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S117>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_fs;
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_fs) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S117>/Hold Control' incorporates:
             *  ActionPort: '<S120>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S117>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S117>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S117>/Hold Control' incorporates:
           *  ActionPort: '<S120>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S117>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S117>/Brake Control' incorporates:
           *  ActionPort: '<S119>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S117>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S117>/Move Control' incorporates:
             *  ActionPort: '<S121>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S117>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S117>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S117>/Move Control' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S117>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S117>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S29>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S29>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S113>/Integrator1'
         *  DiscreteIntegrator: '<S114>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S117>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S117>/Saturation' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Saturate: '<S110>/Saturation' incorporates:
         *  Constant: '<S110>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S110>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch_b_idx_1 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S110>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S110>/Constant5'
         *  Gain: '<S110>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S110>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_Switch_b_idx_1), 4.2949673E+9F) + 1000U;

        /* Product: '<S116>/Multiply1' incorporates:
         *  Constant: '<S116>/const1'
         *  DiscreteIntegrator: '<S114>/Integrator'
         */
        rtb_Rem = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S112>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S112>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S116>/Add' incorporates:
         *  DiscreteIntegrator: '<S114>/Integrator1'
         *  Gain: '<S108>/Gain1'
         *  Gain: '<S112>/Gain'
         *  Sum: '<S114>/Subtract'
         */
        rtb_a_b = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_Switch_b_idx_1 *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Rem;

        /* Signum: '<S116>/Sign' */
        if (rtb_a_b < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_a_b;
        }

        /* End of Signum: '<S116>/Sign' */

        /* Sum: '<S116>/Add2' incorporates:
         *  Abs: '<S116>/Abs'
         *  Gain: '<S116>/Gain'
         *  Gain: '<S116>/Gain1'
         *  Product: '<S116>/Multiply2'
         *  Product: '<S116>/Multiply3'
         *  Sqrt: '<S116>/Sqrt'
         *  Sum: '<S116>/Add1'
         *  Sum: '<S116>/Subtract'
         */
        rtb_Switch_b_idx_1 = (sqrtf((8.0F * fabsf(rtb_a_b) + FMS_ConstB.d_o) *
          FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * rtb_Sqrt_d + rtb_Rem;

        /* Sum: '<S116>/Add4' */
        rtb_Rem += rtb_a_b - rtb_Switch_b_idx_1;

        /* Sum: '<S116>/Add3' */
        rtb_Sqrt_d = rtb_a_b + FMS_ConstB.d_o;

        /* Sum: '<S116>/Subtract1' */
        rtb_a_b -= FMS_ConstB.d_o;

        /* Signum: '<S116>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign1' */

        /* Signum: '<S116>/Sign2' */
        if (rtb_a_b < 0.0F) {
          rtb_a_b = -1.0F;
        } else {
          if (rtb_a_b > 0.0F) {
            rtb_a_b = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign2' */

        /* Sum: '<S116>/Add5' incorporates:
         *  Gain: '<S116>/Gain2'
         *  Product: '<S116>/Multiply4'
         *  Sum: '<S116>/Subtract2'
         */
        rtb_Switch_b_idx_1 += (rtb_Sqrt_d - rtb_a_b) * 0.5F * rtb_Rem;

        /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S113>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S115>/Add6' */
        rtb_Sqrt_d = rtb_Switch + FMS_ConstB.d_d;

        /* Sum: '<S115>/Subtract3' */
        rtb_Rem = rtb_Switch - FMS_ConstB.d_d;

        /* Signum: '<S115>/Sign5' */
        if (rtb_Switch < 0.0F) {
          rtb_a_b = -1.0F;
        } else if (rtb_Switch > 0.0F) {
          rtb_a_b = 1.0F;
        } else {
          rtb_a_b = rtb_Switch;
        }

        /* End of Signum: '<S115>/Sign5' */

        /* Signum: '<S115>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign3' */

        /* Signum: '<S115>/Sign4' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign4' */

        /* Signum: '<S115>/Sign6' */
        if (rtb_Switch < 0.0F) {
          rtb_MathFunction_hf_idx_1 = -1.0F;
        } else if (rtb_Switch > 0.0F) {
          rtb_MathFunction_hf_idx_1 = 1.0F;
        } else {
          rtb_MathFunction_hf_idx_1 = rtb_Switch;
        }

        /* End of Signum: '<S115>/Sign6' */

        /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
         *  Constant: '<S115>/const'
         *  Gain: '<S115>/Gain3'
         *  Product: '<S115>/Divide'
         *  Product: '<S115>/Multiply5'
         *  Product: '<S115>/Multiply6'
         *  Sum: '<S115>/Subtract4'
         *  Sum: '<S115>/Subtract5'
         *  Sum: '<S115>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Switch / FMS_ConstB.d_d - rtb_a_b) *
          FMS_ConstB.Gain4_n * ((rtb_Sqrt_d - rtb_Rem) * 0.5F) -
          rtb_MathFunction_hf_idx_1 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S114>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S114>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S116>/Add6' */
        rtb_Sqrt_d = rtb_Switch_b_idx_1 + FMS_ConstB.d_o;

        /* Sum: '<S116>/Subtract3' */
        rtb_Rem = rtb_Switch_b_idx_1 - FMS_ConstB.d_o;

        /* Signum: '<S116>/Sign5' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch = 1.0F;
        } else {
          rtb_Switch = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S116>/Sign5' */

        /* Signum: '<S116>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign3' */

        /* Signum: '<S116>/Sign4' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign4' */

        /* Signum: '<S116>/Sign6' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_a_b = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_a_b = 1.0F;
        } else {
          rtb_a_b = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S116>/Sign6' */

        /* Update for DiscreteIntegrator: '<S114>/Integrator' incorporates:
         *  Constant: '<S116>/const'
         *  Gain: '<S116>/Gain3'
         *  Product: '<S116>/Divide'
         *  Product: '<S116>/Multiply5'
         *  Product: '<S116>/Multiply6'
         *  Sum: '<S116>/Subtract4'
         *  Sum: '<S116>/Subtract5'
         *  Sum: '<S116>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((rtb_Switch_b_idx_1 / FMS_ConstB.d_o -
          rtb_Switch) * FMS_ConstB.Gain4_n3 * ((rtb_Sqrt_d - rtb_Rem) * 0.5F) -
          rtb_a_b * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S21>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S49>/Integrator'
           *  DiscreteIntegrator: '<S49>/Integrator1'
           *  DiscreteIntegrator: '<S50>/Integrator'
           *  DiscreteIntegrator: '<S50>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S21>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S37>/Motion Status'
           *  Chart: '<S54>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S21>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Altitude' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S37>/Motion Status' incorporates:
         *  Abs: '<S37>/Abs'
         *  Abs: '<S37>/Abs1'
         *  Constant: '<S45>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S45>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S36>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_m) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S36>/Hold Control' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S36>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S36>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S36>/Hold Control' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S36>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S36>/Brake Control' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S36>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S36>/Move Control' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S36>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S36>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S36>/Move Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S36>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S36>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S54>/Motion State' incorporates:
         *  Abs: '<S54>/Abs'
         *  Abs: '<S54>/Abs1'
         *  Constant: '<S64>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S64>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S53>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_h = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_h = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_h = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_h) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S53>/Hold Control' incorporates:
             *  ActionPort: '<S56>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S53>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S53>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S53>/Hold Control' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S53>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S53>/Brake Control' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S53>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S53>/Move Control' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S53>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S53>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S53>/Move Control' incorporates:
           *  ActionPort: '<S57>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S53>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S53>/Switch Case' */

        /* Product: '<S51>/Multiply1' incorporates:
         *  Constant: '<S51>/const1'
         *  DiscreteIntegrator: '<S49>/Integrator'
         */
        rtb_a_b = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S47>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S47>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S51>/Add' incorporates:
         *  DiscreteIntegrator: '<S49>/Integrator1'
         *  Gain: '<S34>/Gain'
         *  Gain: '<S47>/Gain'
         *  Sum: '<S49>/Subtract'
         */
        rtb_Switch = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Switch_b_idx_1 * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_a_b;

        /* Signum: '<S51>/Sign' */
        if (rtb_Switch < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Switch > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Switch;
        }

        /* End of Signum: '<S51>/Sign' */

        /* Sum: '<S51>/Add2' incorporates:
         *  Abs: '<S51>/Abs'
         *  Gain: '<S51>/Gain'
         *  Gain: '<S51>/Gain1'
         *  Product: '<S51>/Multiply2'
         *  Product: '<S51>/Multiply3'
         *  Sqrt: '<S51>/Sqrt'
         *  Sum: '<S51>/Add1'
         *  Sum: '<S51>/Subtract'
         */
        rtb_MathFunction_hf_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Sqrt_d +
          rtb_a_b;

        /* Sum: '<S51>/Add4' */
        rtb_Switch_b_idx_1 = (rtb_Switch - rtb_MathFunction_hf_idx_1) + rtb_a_b;

        /* Sum: '<S51>/Add3' */
        rtb_Sqrt_d = rtb_Switch + FMS_ConstB.d;

        /* Sum: '<S51>/Subtract1' */
        rtb_Switch -= FMS_ConstB.d;

        /* Signum: '<S51>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign1' */

        /* Signum: '<S51>/Sign2' */
        if (rtb_Switch < 0.0F) {
          rtb_Switch = -1.0F;
        } else {
          if (rtb_Switch > 0.0F) {
            rtb_Switch = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign2' */

        /* Sum: '<S51>/Add5' incorporates:
         *  Gain: '<S51>/Gain2'
         *  Product: '<S51>/Multiply4'
         *  Sum: '<S51>/Subtract2'
         */
        rtb_MathFunction_hf_idx_1 += (rtb_Sqrt_d - rtb_Switch) * 0.5F *
          rtb_Switch_b_idx_1;

        /* Sum: '<S51>/Subtract3' */
        rtb_Sqrt_d = rtb_MathFunction_hf_idx_1 - FMS_ConstB.d;

        /* Sum: '<S51>/Add6' */
        rtb_Rem = rtb_MathFunction_hf_idx_1 + FMS_ConstB.d;

        /* Product: '<S51>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MathFunction_hf_idx_1 / FMS_ConstB.d;

        /* Signum: '<S51>/Sign5' incorporates:
         *  Signum: '<S51>/Sign6'
         */
        if (rtb_MathFunction_hf_idx_1 < 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = -1.0F;
          rtb_Switch = -1.0F;
        } else if (rtb_MathFunction_hf_idx_1 > 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = 1.0F;
          rtb_Switch = 1.0F;
        } else {
          rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_hf_idx_1;
          rtb_Switch = rtb_MathFunction_hf_idx_1;
        }

        /* End of Signum: '<S51>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S27>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S49>/Integrator1'
         *  DiscreteIntegrator: '<S50>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S53>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S53>/Saturation' */

        /* Saturate: '<S36>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S36>/Saturation1' */

        /* Product: '<S52>/Multiply1' incorporates:
         *  Constant: '<S52>/const1'
         *  DiscreteIntegrator: '<S50>/Integrator'
         */
        rtb_MathFunction_hf_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S48>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S48>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S52>/Add' incorporates:
         *  DiscreteIntegrator: '<S50>/Integrator1'
         *  Gain: '<S34>/Gain1'
         *  Gain: '<S48>/Gain'
         *  Sum: '<S50>/Subtract'
         */
        rtb_a_b = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_Switch_b_idx_1 *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_MathFunction_hf_idx_1;

        /* Signum: '<S52>/Sign' */
        if (rtb_a_b < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          rtb_Switch_b_idx_1 = rtb_a_b;
        }

        /* End of Signum: '<S52>/Sign' */

        /* Sum: '<S52>/Add2' incorporates:
         *  Abs: '<S52>/Abs'
         *  Gain: '<S52>/Gain'
         *  Gain: '<S52>/Gain1'
         *  Product: '<S52>/Multiply2'
         *  Product: '<S52>/Multiply3'
         *  Sqrt: '<S52>/Sqrt'
         *  Sum: '<S52>/Add1'
         *  Sum: '<S52>/Subtract'
         */
        rtb_Switch_b_idx_1 = (sqrtf((8.0F * fabsf(rtb_a_b) + FMS_ConstB.d_c) *
          FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * rtb_Switch_b_idx_1 +
          rtb_MathFunction_hf_idx_1;

        /* Sum: '<S52>/Add4' */
        rtb_MathFunction_hf_idx_1 += rtb_a_b - rtb_Switch_b_idx_1;

        /* Sum: '<S52>/Add3' */
        rtb_TmpSignalConversionAtMath_0 = rtb_a_b + FMS_ConstB.d_c;

        /* Sum: '<S52>/Subtract1' */
        rtb_a_b -= FMS_ConstB.d_c;

        /* Signum: '<S52>/Sign1' */
        if (rtb_TmpSignalConversionAtMath_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_0 > 0.0F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign1' */

        /* Signum: '<S52>/Sign2' */
        if (rtb_a_b < 0.0F) {
          rtb_a_b = -1.0F;
        } else {
          if (rtb_a_b > 0.0F) {
            rtb_a_b = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign2' */

        /* Sum: '<S52>/Add5' incorporates:
         *  Gain: '<S52>/Gain2'
         *  Product: '<S52>/Multiply4'
         *  Sum: '<S52>/Subtract2'
         */
        rtb_Switch_b_idx_1 += (rtb_TmpSignalConversionAtMath_0 - rtb_a_b) * 0.5F
          * rtb_MathFunction_hf_idx_1;

        /* Update for DiscreteIntegrator: '<S49>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S49>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S51>/Sign3' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign3' */

        /* Signum: '<S51>/Sign4' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign4' */

        /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
         *  Constant: '<S51>/const'
         *  Gain: '<S51>/Gain3'
         *  Product: '<S51>/Multiply5'
         *  Product: '<S51>/Multiply6'
         *  Sum: '<S51>/Subtract4'
         *  Sum: '<S51>/Subtract5'
         *  Sum: '<S51>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_MathFunction_h_idx_0 -
          rtb_TmpSignalConversionAtMath_1) * FMS_ConstB.Gain4 * ((rtb_Rem -
          rtb_Sqrt_d) * 0.5F) - rtb_Switch * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S50>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S50>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S52>/Add6' */
        rtb_Sqrt_d = rtb_Switch_b_idx_1 + FMS_ConstB.d_c;

        /* Sum: '<S52>/Subtract3' */
        rtb_Rem = rtb_Switch_b_idx_1 - FMS_ConstB.d_c;

        /* Signum: '<S52>/Sign5' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch = 1.0F;
        } else {
          rtb_Switch = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S52>/Sign5' */

        /* Signum: '<S52>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign3' */

        /* Signum: '<S52>/Sign4' */
        if (rtb_Rem < 0.0F) {
          rtb_Rem = -1.0F;
        } else {
          if (rtb_Rem > 0.0F) {
            rtb_Rem = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign4' */

        /* Signum: '<S52>/Sign6' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_a_b = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_a_b = 1.0F;
        } else {
          rtb_a_b = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S52>/Sign6' */

        /* Update for DiscreteIntegrator: '<S50>/Integrator' incorporates:
         *  Constant: '<S52>/const'
         *  Gain: '<S52>/Gain3'
         *  Product: '<S52>/Divide'
         *  Product: '<S52>/Multiply5'
         *  Product: '<S52>/Multiply6'
         *  Sum: '<S52>/Subtract4'
         *  Sum: '<S52>/Subtract5'
         *  Sum: '<S52>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Switch_b_idx_1 / FMS_ConstB.d_c -
          rtb_Switch) * FMS_ConstB.Gain4_m * ((rtb_Sqrt_d - rtb_Rem) * 0.5F) -
          rtb_a_b * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S21>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S70>/Motion Status'
           *  Chart: '<S81>/Motion State'
           *  Chart: '<S94>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S70>/Motion Status' incorporates:
         *  Abs: '<S70>/Abs'
         *  Abs: '<S70>/Abs1'
         *  Constant: '<S78>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S78>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S81>/Motion State' incorporates:
         *  Abs: '<S81>/Abs'
         *  Abs: '<S81>/Abs1'
         *  Constant: '<S91>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S91>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S94>/Logical Operator' incorporates:
         *  Abs: '<S94>/Abs1'
         *  Abs: '<S94>/Abs2'
         *  Constant: '<S105>/Constant'
         *  Constant: '<S106>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S105>/Compare'
         *  RelationalOperator: '<S106>/Compare'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtb_LogicalOperator_at = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S94>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S94>/Square'
         *  Math: '<S94>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S94>/Sqrt'
         *  Sum: '<S94>/Add'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_n;
          rtb_state_l = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_l = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_l = MotionState_Hold;
            } else {
              if (rtb_LogicalOperator_at) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_l = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_l = MotionState_Hold;
            if (rtb_LogicalOperator_at) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_l = MotionState_Move;
            }
            break;

           default:
            rtb_state_l = MotionState_Move;
            if (!rtb_LogicalOperator_at) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_l = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S94>/Motion State' */

        /* SwitchCase: '<S93>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_l) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_l) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S93>/Hold Control' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S93>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S93>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S93>/Hold Control' incorporates:
           *  ActionPort: '<S96>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_a, &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S93>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S93>/Brake Control' incorporates:
           *  ActionPort: '<S95>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S93>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S93>/Move Control' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S93>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S93>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S93>/Move Control' incorporates:
           *  ActionPort: '<S97>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S93>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S93>/Switch Case' */

        /* SwitchCase: '<S69>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_o;
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S69>/Hold Control' incorporates:
             *  ActionPort: '<S72>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S69>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S69>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Hold Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S69>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S69>/Brake Control' incorporates:
           *  ActionPort: '<S71>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S69>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S69>/Move Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S69>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S69>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Move Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S69>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S69>/Switch Case' */

        /* SwitchCase: '<S80>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_j;
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        switch (rtb_state_ki) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_j = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_j = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_j = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_j) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S80>/Hold Control' incorporates:
             *  ActionPort: '<S83>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S80>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S80>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S80>/Hold Control' incorporates:
           *  ActionPort: '<S83>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S80>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S80>/Brake Control' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S80>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S80>/Move Control' incorporates:
             *  ActionPort: '<S84>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S80>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S80>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S80>/Move Control' incorporates:
           *  ActionPort: '<S84>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S80>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S80>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S80>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S80>/Saturation' */

        /* Saturate: '<S93>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S93>/Saturation1' */

        /* Saturate: '<S69>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S69>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S21>/Unknown' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S21>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S21>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S17>/Manual' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S23>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S23>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S17>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S17>/Unknown' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S17>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S17>/Switch Case' */
    /* End of Outputs for SubSystem: '<S2>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.safe_mode;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Sum: '<S8>/Sum' incorporates:
   *  Delay: '<S8>/Delay'
   *  Gain: '<S8>/Gain1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  RelationalOperator: '<S13>/FixPt Relational Operator'
   *  UnitDelay: '<S12>/Delay Input1'
   *  UnitDelay: '<S13>/Delay Input1'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.Delay_DSTATE_g = (int8_T)(((FMS_U.GCS_Cmd.cmd_1 !=
    FMS_DW.DelayInput1_DSTATE_h) + rtb_Saturation_g) + (FMS_U.Pilot_Cmd.cmd_1 !=
    FMS_DW.DelayInput1_DSTATE_m ? -1 : 0));

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_Switch_b_idx_1 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Switch_b_idx_1 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Switch_b_idx_1;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for DiscreteIntegrator: '<S254>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S254>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In3'
   *  Sum: '<S254>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (FMS_U.INS_Out.ax -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (FMS_U.INS_Out.ay -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (FMS_U.INS_Out.az -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S255>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S255>/Gain'
   *  Sum: '<S255>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S12>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_h = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S13>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_m = FMS_U.Pilot_Cmd.cmd_1;
}

/* Model initialize function */
void FMS_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FMS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &FMS_B), 0,
                sizeof(B_FMS_T));

  {
    FMS_B.VehicleState_f = VehicleState_None;
    FMS_B.safe_mode = PilotMode_None;
    FMS_B.fms_cmd = CMD_None;
  }

  /* states (dwork) */
  (void) memset((void *)&FMS_DW, 0,
                sizeof(DW_FMS_T));

  /* external inputs */
  (void)memset(&FMS_U, 0, sizeof(ExtU_FMS_T));

  /* external outputs */
  FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

  /* Start for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Start for SwitchCase: '<S2>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/Arm' */
  /* Start for SwitchCase: '<S17>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S17>/SubMode' */
  /* Start for SwitchCase: '<S24>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S24>/Return' */
  /* Start for SwitchCase: '<S217>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S207>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S24>/Return' */

  /* Start for IfAction SubSystem: '<S24>/Hold' */
  /* Start for SwitchCase: '<S163>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S141>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S151>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S24>/Hold' */
  /* End of Start for SubSystem: '<S17>/SubMode' */

  /* Start for IfAction SubSystem: '<S17>/Assist' */
  /* Start for SwitchCase: '<S21>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S21>/Stabilize' */
  /* Start for SwitchCase: '<S117>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S21>/Stabilize' */

  /* Start for IfAction SubSystem: '<S21>/Altitude' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S53>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S21>/Altitude' */

  /* Start for IfAction SubSystem: '<S21>/Position' */
  /* Start for SwitchCase: '<S93>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S69>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S80>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S2>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */

  /* InitializeConditions for DiscreteIntegrator: '<S254>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S255>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* SystemInitialize for Chart: '<Root>/Mode Degrade' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = CMD_None;
  FMS_DW.prep_takeoff = 0.0;
  FMS_DW.bl = false;
  FMS_DW.br = false;
  FMS_B.VehicleState_f = VehicleState_None;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Return' */
  /* InitializeConditions for Delay: '<S183>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S243>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S184>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S218>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S217>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S217>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S217>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S217>/Move Control' */

  /* SystemInitialize for Merge: '<S217>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S208>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S207>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S207>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S207>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S207>/Move Control' */

  /* SystemInitialize for Merge: '<S207>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/Hold' */
  /* SystemInitialize for Chart: '<S142>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S152>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S164>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S163>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S163>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S163>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S163>/Move Control' */

  /* SystemInitialize for Merge: '<S163>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S141>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S141>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S141>/Move Control' */

  /* SystemInitialize for Merge: '<S141>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S151>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S151>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S151>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S151>/Move Control' */

  /* SystemInitialize for Merge: '<S151>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S17>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S118>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S117>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S117>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S117>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S117>/Move Control' */

  /* SystemInitialize for Merge: '<S117>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S49>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S37>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S36>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S36>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S36>/Move Control' */

  /* SystemInitialize for Chart: '<S54>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S53>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S53>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S53>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S53>/Move Control' */

  /* SystemInitialize for Merge: '<S36>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S53>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S70>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for Chart: '<S81>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S94>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S93>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S93>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S93>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S93>/Move Control' */

  /* SystemInitialize for Merge: '<S93>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S69>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S69>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S69>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S69>/Move Control' */

  /* SystemInitialize for Merge: '<S69>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S80>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S80>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S80>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S80>/Move Control' */

  /* SystemInitialize for Merge: '<S80>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Position' */
  /* End of SystemInitialize for SubSystem: '<S17>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S2>/Arm' */
  /* End of SystemInitialize for SubSystem: '<Root>/FMS Commander' */
}

/* Model terminate function */
void FMS_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
