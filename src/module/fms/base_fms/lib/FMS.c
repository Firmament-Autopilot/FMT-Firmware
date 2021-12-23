/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1129
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec 23 16:25:01 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S204>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S214>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S116>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S35>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S150>/Motion State' */
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
  0U,                                  /* mode */
  0U,                                  /* ctrl_mode */
  0U                                   /* reset */
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
                                        *   '<S32>/Gain'
                                        *   '<S32>/Gain1'
                                        *   '<S106>/Gain'
                                        *   '<S106>/Gain1'
                                        *   '<S174>/Saturation1'
                                        *   '<S243>/Gain2'
                                        *   '<S243>/Saturation1'
                                        *   '<S34>/Saturation1'
                                        *   '<S45>/Dead Zone'
                                        *   '<S45>/Gain'
                                        *   '<S46>/Dead Zone'
                                        *   '<S46>/Gain'
                                        *   '<S51>/Saturation'
                                        *   '<S67>/Saturation1'
                                        *   '<S78>/Saturation'
                                        *   '<S91>/Saturation1'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S110>/Dead Zone'
                                        *   '<S110>/Gain'
                                        *   '<S115>/Saturation'
                                        *   '<S139>/Saturation1'
                                        *   '<S149>/Saturation'
                                        *   '<S161>/Saturation1'
                                        *   '<S175>/Gain2'
                                        *   '<S37>/Gain2'
                                        *   '<S38>/Gain1'
                                        *   '<S43>/Constant'
                                        *   '<S54>/Gain2'
                                        *   '<S55>/Gain1'
                                        *   '<S62>/Constant'
                                        *   '<S70>/Gain2'
                                        *   '<S71>/Gain1'
                                        *   '<S76>/Constant'
                                        *   '<S81>/Gain2'
                                        *   '<S82>/Gain1'
                                        *   '<S89>/Constant'
                                        *   '<S94>/Gain2'
                                        *   '<S95>/Gain6'
                                        *   '<S103>/Constant'
                                        *   '<S104>/Constant'
                                        *   '<S118>/Gain2'
                                        *   '<S119>/Gain1'
                                        *   '<S126>/Constant'
                                        *   '<S142>/Gain2'
                                        *   '<S143>/Gain1'
                                        *   '<S152>/Gain2'
                                        *   '<S153>/Gain1'
                                        *   '<S164>/Gain2'
                                        *   '<S165>/Gain6'
                                        *   '<S184>/Gain2'
                                        *   '<S184>/Saturation'
                                        *   '<S185>/Integrator'
                                        *   '<S40>/Dead Zone'
                                        *   '<S40>/Gain'
                                        *   '<S59>/Dead Zone'
                                        *   '<S59>/Gain'
                                        *   '<S73>/Dead Zone'
                                        *   '<S73>/Gain'
                                        *   '<S86>/Dead Zone'
                                        *   '<S86>/Gain'
                                        *   '<S99>/Dead Zone'
                                        *   '<S99>/Gain'
                                        *   '<S100>/Dead Zone'
                                        *   '<S100>/Gain'
                                        *   '<S123>/Dead Zone'
                                        *   '<S123>/Gain'
                                        *   '<S145>/Dead Zone'
                                        *   '<S145>/Gain'
                                        *   '<S157>/Dead Zone'
                                        *   '<S157>/Gain'
                                        *   '<S169>/Dead Zone'
                                        *   '<S169>/Gain'
                                        *   '<S170>/Dead Zone'
                                        *   '<S170>/Gain'
                                        *   '<S203>/Saturation1'
                                        *   '<S213>/Saturation1'
                                        *   '<S206>/Gain2'
                                        *   '<S207>/Gain1'
                                        *   '<S216>/Gain2'
                                        *   '<S217>/Gain6'
                                        *   '<S209>/Dead Zone'
                                        *   '<S209>/Gain'
                                        *   '<S221>/Dead Zone'
                                        *   '<S221>/Gain'
                                        *   '<S222>/Dead Zone'
                                        *   '<S222>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 50, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S18>/Constant'
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
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Standby(void);
static void FMS_Vehicle(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for action system:
 *    '<S2>/Disarm'
 *    '<S22>/Unknown'
 *    '<S20>/Unknown'
 *    '<S19>/Unknown'
 *    '<S15>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S16>/Bus Assignment' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S16>/Constant2'
   *  SignalConversion: '<S16>/TmpHiddenBufferAtBus AssignmentInport1'
   */
  *rty_FMS_Out = FMS_rtZFMS_Out_Bus;
  rty_FMS_Out->reset = 1U;
  rty_FMS_Out->status = localC->DataTypeConversion;
  rty_FMS_Out->mode = localC->DataTypeConversion1;
  rty_FMS_Out->actuator_cmd[0] = 1000U;
  rty_FMS_Out->actuator_cmd[1] = 1000U;
  rty_FMS_Out->actuator_cmd[2] = 1000U;
  rty_FMS_Out->actuator_cmd[3] = 1000U;
  for (i = 0; i < 12; i++) {
    rty_FMS_Out->actuator_cmd[i + 4] = 0U;
  }

  /* End of BusAssignment: '<S16>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S203>/Hold Control'
 *    '<S139>/Hold Control'
 *    '<S34>/Hold Control'
 *    '<S67>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S206>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S203>/Hold Control'
 *    '<S139>/Hold Control'
 *    '<S34>/Hold Control'
 *    '<S67>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S206>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S203>/Hold Control'
 *    '<S139>/Hold Control'
 *    '<S34>/Hold Control'
 *    '<S67>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S206>/Delay' incorporates:
   *  Gain: '<S208>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S206>/Gain2' incorporates:
   *  Delay: '<S206>/Delay'
   *  Gain: '<S208>/Gain'
   *  Sum: '<S206>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S206>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S203>/Brake Control'
 *    '<S139>/Brake Control'
 *    '<S149>/Brake Control'
 *    '<S115>/Brake Control'
 *    '<S34>/Brake Control'
 *    '<S51>/Brake Control'
 *    '<S67>/Brake Control'
 *    '<S78>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S205>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S205>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S203>/Move Control'
 *    '<S139>/Move Control'
 *    '<S34>/Move Control'
 *    '<S67>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S203>/Move Control'
 *    '<S139>/Move Control'
 *    '<S34>/Move Control'
 *    '<S67>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S203>/Move Control'
 *    '<S139>/Move Control'
 *    '<S34>/Move Control'
 *    '<S67>/Move Control'
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

  /* Product: '<S211>/Multiply1' incorporates:
   *  Constant: '<S211>/const1'
   *  DiscreteIntegrator: '<S210>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S209>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_c = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_c = 0.0F;
  } else {
    rtb_a_c = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S209>/Dead Zone' */

  /* Sum: '<S211>/Add' incorporates:
   *  DiscreteIntegrator: '<S210>/Integrator1'
   *  Gain: '<S207>/Gain1'
   *  Gain: '<S209>/Gain'
   *  Sum: '<S210>/Subtract'
   */
  rtb_Subtract3_m = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_c * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3;

  /* Signum: '<S211>/Sign' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_a_c = -1.0F;
  } else if (rtb_Subtract3_m > 0.0F) {
    rtb_a_c = 1.0F;
  } else {
    rtb_a_c = rtb_Subtract3_m;
  }

  /* End of Signum: '<S211>/Sign' */

  /* Sum: '<S211>/Add2' incorporates:
   *  Abs: '<S211>/Abs'
   *  Gain: '<S211>/Gain'
   *  Gain: '<S211>/Gain1'
   *  Product: '<S211>/Multiply2'
   *  Product: '<S211>/Multiply3'
   *  Sqrt: '<S211>/Sqrt'
   *  Sum: '<S211>/Add1'
   *  Sum: '<S211>/Subtract'
   */
  rtb_a_c = (sqrtf((8.0F * fabsf(rtb_Subtract3_m) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_c + rtb_Add3;

  /* Sum: '<S211>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_m - rtb_a_c) + rtb_Add3;

  /* Sum: '<S211>/Add3' */
  rtb_Add3 = rtb_Subtract3_m + localC->d;

  /* Sum: '<S211>/Subtract1' */
  rtb_Subtract3_m -= localC->d;

  /* Signum: '<S211>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S211>/Sign1' */

  /* Signum: '<S211>/Sign2' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S211>/Sign2' */

  /* Sum: '<S211>/Add5' incorporates:
   *  Gain: '<S211>/Gain2'
   *  Product: '<S211>/Multiply4'
   *  Sum: '<S211>/Subtract2'
   */
  rtb_a_c += (rtb_Add3 - rtb_Subtract3_m) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S207>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S210>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S210>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S210>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S211>/Add6' */
  rtb_Add3 = rtb_a_c + localC->d;

  /* Sum: '<S211>/Subtract3' */
  rtb_Subtract3_m = rtb_a_c - localC->d;

  /* Signum: '<S211>/Sign5' */
  if (rtb_a_c < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_c > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_c;
  }

  /* End of Signum: '<S211>/Sign5' */

  /* Signum: '<S211>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S211>/Sign3' */

  /* Signum: '<S211>/Sign4' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S211>/Sign4' */

  /* Signum: '<S211>/Sign6' */
  if (rtb_a_c < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_c > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_c;
  }

  /* End of Signum: '<S211>/Sign6' */

  /* Update for DiscreteIntegrator: '<S210>/Integrator' incorporates:
   *  Constant: '<S211>/const'
   *  Gain: '<S211>/Gain3'
   *  Product: '<S211>/Divide'
   *  Product: '<S211>/Multiply5'
   *  Product: '<S211>/Multiply6'
   *  Sum: '<S211>/Subtract4'
   *  Sum: '<S211>/Subtract5'
   *  Sum: '<S211>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_c / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_m) * 0.5F) - rtb_a_b * 78.448F) *
    0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S204>/Motion Status'
 *    '<S140>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S204>/Motion Status'
 *    '<S140>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S204>/Motion Status'
 *    '<S140>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S204>/Motion Status' */
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

  /* End of Chart: '<S204>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S213>/Hold Control'
 *    '<S161>/Hold Control'
 *    '<S91>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S216>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S213>/Hold Control'
 *    '<S161>/Hold Control'
 *    '<S91>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S216>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S213>/Hold Control'
 *    '<S161>/Hold Control'
 *    '<S91>/Hold Control'
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

  /* Delay: '<S216>/Delay' incorporates:
   *  SignalConversion: '<S216>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S220>/Trigonometric Function1' incorporates:
   *  Gain: '<S219>/Gain'
   *  Trigonometry: '<S220>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_b_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_b_tmp_0;

  /* Trigonometry: '<S220>/Trigonometric Function' incorporates:
   *  Gain: '<S219>/Gain'
   *  Trigonometry: '<S220>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_b_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_b_tmp;

  /* SignalConversion: '<S220>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S220>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S220>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_b_tmp;

  /* Trigonometry: '<S220>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_b_tmp_0;

  /* SignalConversion: '<S220>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S220>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S220>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S216>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S216>/Delay'
   *  SignalConversion: '<S216>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S216>/Sum'
   */
  rtb_VectorConcatenate_b_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_b_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S216>/Multiply' incorporates:
   *  SignalConversion: '<S216>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_b[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_b_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_b_tmp_0;
  }

  /* End of Product: '<S216>/Multiply' */

  /* Gain: '<S216>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[1];

  /* Update for Delay: '<S216>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S213>/Brake Control'
 *    '<S161>/Brake Control'
 *    '<S91>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S215>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S213>/Move Control'
 *    '<S161>/Move Control'
 *    '<S91>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S213>/Move Control'
 *    '<S161>/Move Control'
 *    '<S91>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S213>/Move Control'
 *    '<S161>/Move Control'
 *    '<S91>/Move Control'
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

  /* SignalConversion: '<S217>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S223>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S224>/Multiply1' incorporates:
   *  Constant: '<S224>/const1'
   *  DiscreteIntegrator: '<S223>/Integrator'
   */
  rtb_Add3_e_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S217>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S223>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S224>/Multiply1' incorporates:
   *  Constant: '<S224>/const1'
   *  DiscreteIntegrator: '<S223>/Integrator'
   */
  rtb_Add3_e_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S221>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S221>/Dead Zone' */

  /* Sum: '<S224>/Add' incorporates:
   *  DiscreteIntegrator: '<S223>/Integrator1'
   *  Gain: '<S217>/Gain6'
   *  Gain: '<S221>/Gain'
   *  Sum: '<S223>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e_idx_0;

  /* DeadZone: '<S222>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S222>/Dead Zone' */

  /* Sum: '<S224>/Add' incorporates:
   *  DiscreteIntegrator: '<S223>/Integrator1'
   *  Gain: '<S217>/Gain6'
   *  Gain: '<S222>/Gain'
   *  Sum: '<S223>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e_idx_1;

  /* Signum: '<S224>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S224>/Add2' incorporates:
   *  Abs: '<S224>/Abs'
   *  Gain: '<S224>/Gain'
   *  Gain: '<S224>/Gain1'
   *  Product: '<S224>/Multiply2'
   *  Product: '<S224>/Multiply3'
   *  Signum: '<S224>/Sign'
   *  Sqrt: '<S224>/Sqrt'
   *  Sum: '<S224>/Add1'
   *  Sum: '<S224>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e_idx_0;

  /* Sum: '<S224>/Add3' incorporates:
   *  Signum: '<S224>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S224>/Subtract1' incorporates:
   *  Signum: '<S224>/Sign'
   */
  rtb_Subtract3_o = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S224>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S224>/Sign2' */
  if (rtb_Subtract3_o < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else {
    if (rtb_Subtract3_o > 0.0F) {
      rtb_Subtract3_o = 1.0F;
    }
  }

  /* Sum: '<S224>/Add5' incorporates:
   *  Gain: '<S224>/Gain2'
   *  Product: '<S224>/Multiply4'
   *  Signum: '<S224>/Sign'
   *  Sum: '<S224>/Add2'
   *  Sum: '<S224>/Add4'
   *  Sum: '<S224>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e_idx_0) * ((u - rtb_Subtract3_o) * 0.5F);

  /* Update for DiscreteIntegrator: '<S223>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S223>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S224>/Sign3' incorporates:
   *  Sum: '<S224>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S224>/Sign4' incorporates:
   *  Sum: '<S224>/Subtract3'
   */
  rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S224>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S224>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S224>/Sign4' */
  if (rtb_Add3_e_idx_0 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e_idx_0 > 0.0F) {
      rtb_Add3_e_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S224>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_o = 1.0F;
  } else {
    rtb_Subtract3_o = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S223>/Integrator' incorporates:
   *  Constant: '<S224>/const'
   *  Gain: '<S224>/Gain3'
   *  Product: '<S224>/Divide'
   *  Product: '<S224>/Multiply5'
   *  Product: '<S224>/Multiply6'
   *  Sum: '<S224>/Subtract4'
   *  Sum: '<S224>/Subtract5'
   *  Sum: '<S224>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e_idx_0) * 0.5F) -
    rtb_Subtract3_o * 58.836F) * 0.004F;

  /* Signum: '<S224>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e_idx_0 = 1.0F;
  } else {
    rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S224>/Add2' incorporates:
   *  Abs: '<S224>/Abs'
   *  Gain: '<S224>/Gain'
   *  Gain: '<S224>/Gain1'
   *  Product: '<S224>/Multiply2'
   *  Product: '<S224>/Multiply3'
   *  Signum: '<S224>/Sign'
   *  Sqrt: '<S224>/Sqrt'
   *  Sum: '<S224>/Add1'
   *  Sum: '<S224>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e_idx_0 +
    rtb_Add3_e_idx_1;

  /* Sum: '<S224>/Add3' incorporates:
   *  Signum: '<S224>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S224>/Subtract1' incorporates:
   *  Signum: '<S224>/Sign'
   */
  rtb_Subtract3_o = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S224>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S224>/Sign2' */
  if (rtb_Subtract3_o < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else {
    if (rtb_Subtract3_o > 0.0F) {
      rtb_Subtract3_o = 1.0F;
    }
  }

  /* Sum: '<S224>/Add5' incorporates:
   *  Gain: '<S224>/Gain2'
   *  Product: '<S224>/Multiply4'
   *  Signum: '<S224>/Sign'
   *  Sum: '<S224>/Add2'
   *  Sum: '<S224>/Add4'
   *  Sum: '<S224>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e_idx_1) * ((u - rtb_Subtract3_o) * 0.5F);

  /* Update for DiscreteIntegrator: '<S223>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S223>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S224>/Sign3' incorporates:
   *  Sum: '<S224>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S224>/Sign4' incorporates:
   *  Sum: '<S224>/Subtract3'
   */
  rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S224>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S224>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S224>/Sign4' */
  if (rtb_Add3_e_idx_0 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e_idx_0 > 0.0F) {
      rtb_Add3_e_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S224>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_o = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_o = 1.0F;
  } else {
    rtb_Subtract3_o = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S223>/Integrator' incorporates:
   *  Constant: '<S224>/const'
   *  Gain: '<S224>/Gain3'
   *  Product: '<S224>/Divide'
   *  Product: '<S224>/Multiply5'
   *  Product: '<S224>/Multiply6'
   *  Sum: '<S224>/Subtract4'
   *  Sum: '<S224>/Subtract5'
   *  Sum: '<S224>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e_idx_0) * 0.5F) -
    rtb_Subtract3_o * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S214>/Motion State'
 *    '<S162>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S214>/Motion State'
 *    '<S162>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S214>/Motion State'
 *    '<S162>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S214>/Motion State' */
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

  /* End of Chart: '<S214>/Motion State' */
}

/*
 * System initialize for action system:
 *    '<S149>/Hold Control'
 *    '<S115>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S78>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S152>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S149>/Hold Control'
 *    '<S115>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S78>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S152>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S149>/Hold Control'
 *    '<S115>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S78>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad_o;
  real32_T rtb_Abs_l;

  /* Delay: '<S152>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S152>/Sum' incorporates:
   *  Delay: '<S152>/Delay'
   */
  rtb_psi_error_rad_o = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S155>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad_o);

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S155>/Constant'
   *  Constant: '<S156>/Constant'
   *  Product: '<S155>/Multiply'
   *  RelationalOperator: '<S156>/Compare'
   *  Sum: '<S155>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S155>/Sign' */
    if (rtb_psi_error_rad_o < 0.0F) {
      rtb_psi_error_rad_o = -1.0F;
    } else {
      if (rtb_psi_error_rad_o > 0.0F) {
        rtb_psi_error_rad_o = 1.0F;
      }
    }

    /* End of Signum: '<S155>/Sign' */
    rtb_psi_error_rad_o *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S155>/Switch' */

  /* Gain: '<S152>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad_o;

  /* Update for Delay: '<S152>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S149>/Move Control'
 *    '<S115>/Move Control'
 *    '<S51>/Move Control'
 *    '<S78>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S149>/Move Control'
 *    '<S115>/Move Control'
 *    '<S51>/Move Control'
 *    '<S78>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S149>/Move Control'
 *    '<S115>/Move Control'
 *    '<S51>/Move Control'
 *    '<S78>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S159>/Multiply1' incorporates:
   *  Constant: '<S159>/const1'
   *  DiscreteIntegrator: '<S158>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S157>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S157>/Dead Zone' */

  /* Sum: '<S159>/Add' incorporates:
   *  DiscreteIntegrator: '<S158>/Integrator1'
   *  Gain: '<S153>/Gain1'
   *  Gain: '<S157>/Gain'
   *  Sum: '<S158>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3;

  /* Signum: '<S159>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S159>/Sign' */

  /* Sum: '<S159>/Add2' incorporates:
   *  Abs: '<S159>/Abs'
   *  Gain: '<S159>/Gain'
   *  Gain: '<S159>/Gain1'
   *  Product: '<S159>/Multiply2'
   *  Product: '<S159>/Multiply3'
   *  Sqrt: '<S159>/Sqrt'
   *  Sum: '<S159>/Add1'
   *  Sum: '<S159>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3;

  /* Sum: '<S159>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3;

  /* Sum: '<S159>/Add3' */
  rtb_Add3 = rtb_Subtract3_l + localC->d;

  /* Sum: '<S159>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S159>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S159>/Sign1' */

  /* Signum: '<S159>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S159>/Sign2' */

  /* Sum: '<S159>/Add5' incorporates:
   *  Gain: '<S159>/Gain2'
   *  Product: '<S159>/Multiply4'
   *  Sum: '<S159>/Subtract2'
   */
  rtb_a_m += (rtb_Add3 - rtb_Subtract3_l) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S153>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S158>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S158>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S158>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S159>/Add6' */
  rtb_Add3 = rtb_a_m + localC->d;

  /* Sum: '<S159>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S159>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_m;
  }

  /* End of Signum: '<S159>/Sign5' */

  /* Signum: '<S159>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S159>/Sign3' */

  /* Signum: '<S159>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S159>/Sign4' */

  /* Signum: '<S159>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_m;
  }

  /* End of Signum: '<S159>/Sign6' */

  /* Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
   *  Constant: '<S159>/const'
   *  Gain: '<S159>/Gain3'
   *  Product: '<S159>/Divide'
   *  Product: '<S159>/Multiply5'
   *  Product: '<S159>/Multiply6'
   *  Sum: '<S159>/Subtract4'
   *  Sum: '<S159>/Subtract5'
   *  Sum: '<S159>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_l) * 0.5F) - rtb_a_p * 15.707963F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S116>/Motion State'
 *    '<S52>/Motion State'
 *    '<S79>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S116>/Motion State'
 *    '<S52>/Motion State'
 *    '<S79>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S116>/Motion State'
 *    '<S52>/Motion State'
 *    '<S79>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S116>/Motion State' */
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

  /* End of Chart: '<S116>/Motion State' */
}

/*
 * System initialize for atomic system:
 *    '<S35>/Motion Status'
 *    '<S68>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S35>/Motion Status'
 *    '<S68>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S35>/Motion Status'
 *    '<S68>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S35>/Motion Status' */
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

  /* End of Chart: '<S35>/Motion Status' */
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
  switch (cmd_in) {
   case CMD_Takeoff:
   case CMD_Land:
   case CMD_Return:
   case CMD_Pause:
    if (((ins_flag & 4U) == 0U) || ((ins_flag & 8U) == 0U) || ((ins_flag & 64U) ==
         0U) || ((ins_flag & 128U) == 0U)) {
      valid = false;
    }
    break;

   case CMD_PreArm:
    switch (mode_in) {
     case PilotMode_Mission:
     case PilotMode_Position:
      if (((ins_flag & 4U) == 0U) || ((ins_flag & 8U) == 0U) || ((ins_flag & 64U)
           == 0U) || ((ins_flag & 128U) == 0U)) {
        valid = false;
      }
      break;

     case PilotMode_Altitude:
      if (((ins_flag & 4U) == 0U) || ((ins_flag & 8U) == 0U) || ((ins_flag &
            128U) == 0U)) {
        valid = false;
      }
      break;

     case PilotMode_Stabilize:
     case PilotMode_Acro:
      if (((ins_flag & 4U) == 0U) || ((ins_flag & 8U) == 0U)) {
        valid = false;
      }
      break;
    }
    break;
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
static void FMS_SubMode(void)
{
  boolean_T sf_internal_predicateOutput;
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
  /* RelationalOperator: '<S248>/Compare' incorporates:
   *  Abs: '<S247>/Abs'
   *  Constant: '<S248>/Constant'
   *  MinMax: '<S247>/Max'
   *  Sum: '<S247>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S4>/Vehicle.StickMoved' */
  if (FMS_B.Compare) {
    if (FMS_getArmMode(FMS_B.safe_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Auto;
      switch (FMS_B.safe_mode) {
       case PilotMode_Offboard:
        FMS_DW.is_Auto = FMS_IN_Offboard;
        FMS_B.VehicleMode_e = VehicleMode_Offboard;
        break;

       case PilotMode_Mission:
        FMS_DW.is_Auto = FMS_IN_Mission;
        FMS_B.VehicleMode_e = VehicleMode_Mission;
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
        break;
      }
    } else if (FMS_getArmMode(FMS_B.safe_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.safe_mode) {
       case PilotMode_Acro:
        FMS_DW.is_Assist = FMS_IN_Acro;
        FMS_B.VehicleMode_e = VehicleMode_Acro;
        break;

       case PilotMode_Stabilize:
        FMS_DW.is_Assist = FMS_IN_Stabilize;
        FMS_B.VehicleMode_e = VehicleMode_Stabilize;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_Assist = FMS_IN_Altitude;
        FMS_B.VehicleMode_e = VehicleMode_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_Assist = FMS_IN_Position;
        FMS_B.VehicleMode_e = VehicleMode_Position;
        break;

       default:
        FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
        FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
        break;
      }
    } else if (FMS_getArmMode(FMS_B.safe_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.safe_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_b;
        FMS_B.VehicleMode_e = VehicleMode_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
        FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
      FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Pause);
    } else {
      sf_internal_predicateOutput = false;
    }

    if (sf_internal_predicateOutput) {
      FMS_DW.is_SubMode = FMS_IN_Hold_b;
      FMS_B.VehicleMode_e = VehicleMode_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold_b:
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            CMD_Continue);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          tmp = FMS_getArmMode(FMS_B.safe_mode);
          if (tmp == 3.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Auto;
            switch (FMS_B.safe_mode) {
             case PilotMode_Offboard:
              FMS_DW.is_Auto = FMS_IN_Offboard;
              FMS_B.VehicleMode_e = VehicleMode_Offboard;
              break;

             case PilotMode_Mission:
              FMS_DW.is_Auto = FMS_IN_Mission;
              FMS_B.VehicleMode_e = VehicleMode_Mission;
              break;

             default:
              FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
              FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
              break;
            }
          } else if (tmp == 2.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Assist;
            switch (FMS_B.safe_mode) {
             case PilotMode_Acro:
              FMS_DW.is_Assist = FMS_IN_Acro;
              FMS_B.VehicleMode_e = VehicleMode_Acro;
              break;

             case PilotMode_Stabilize:
              FMS_DW.is_Assist = FMS_IN_Stabilize;
              FMS_B.VehicleMode_e = VehicleMode_Stabilize;
              break;

             case PilotMode_Altitude:
              FMS_DW.is_Assist = FMS_IN_Altitude;
              FMS_B.VehicleMode_e = VehicleMode_Altitude;
              break;

             case PilotMode_Position:
              FMS_DW.is_Assist = FMS_IN_Position;
              FMS_B.VehicleMode_e = VehicleMode_Position;
              break;

             default:
              FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
              FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
              break;
            }
          } else if (tmp == 1.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Manual;
            if (FMS_B.safe_mode == PilotMode_Manual) {
              FMS_DW.is_Manual = FMS_IN_Manual_b;
              FMS_B.VehicleMode_e = VehicleMode_Manual;
            } else {
              FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
          }
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
          FMS_B.VehicleMode_e = VehicleMode_Disarm;
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
          FMS_B.VehicleMode_e = VehicleMode_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
        }
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R - FMS_DW.home[2] > 1.5F) {
          if (FMS_getArmMode(FMS_B.safe_mode) == 3.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Auto;
            switch (FMS_B.safe_mode) {
             case PilotMode_Offboard:
              FMS_DW.is_Auto = FMS_IN_Offboard;
              FMS_B.VehicleMode_e = VehicleMode_Offboard;
              break;

             case PilotMode_Mission:
              FMS_DW.is_Auto = FMS_IN_Mission;
              FMS_B.VehicleMode_e = VehicleMode_Mission;
              break;

             default:
              FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
              FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
              break;
            }
          } else if (FMS_getArmMode(FMS_B.safe_mode) == 2.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Assist;
            switch (FMS_B.safe_mode) {
             case PilotMode_Acro:
              FMS_DW.is_Assist = FMS_IN_Acro;
              FMS_B.VehicleMode_e = VehicleMode_Acro;
              break;

             case PilotMode_Stabilize:
              FMS_DW.is_Assist = FMS_IN_Stabilize;
              FMS_B.VehicleMode_e = VehicleMode_Stabilize;
              break;

             case PilotMode_Altitude:
              FMS_DW.is_Assist = FMS_IN_Altitude;
              FMS_B.VehicleMode_e = VehicleMode_Altitude;
              break;

             case PilotMode_Position:
              FMS_DW.is_Assist = FMS_IN_Position;
              FMS_B.VehicleMode_e = VehicleMode_Position;
              break;

             default:
              FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
              FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
              break;
            }
          } else if (FMS_getArmMode(FMS_B.safe_mode) == 1.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Manual;
            if (FMS_B.safe_mode == PilotMode_Manual) {
              FMS_DW.is_Manual = FMS_IN_Manual_b;
              FMS_B.VehicleMode_e = VehicleMode_Manual;
            } else {
              FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
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
static void FMS_Standby(void)
{
  boolean_T condIsTrue;
  real_T tmp;
  boolean_T guard1 = false;
  if ((FMS_ManualArmEvent(FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
                          FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
      (FMS_DW.prep_takeoff == 0.0)) {
    FMS_DW.prep_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
      FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_i = condIsTrue;
    FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Vehicle = FMS_IN_Arm;
    FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
    tmp = FMS_getArmMode(FMS_B.safe_mode);
    if (tmp == 3.0) {
      FMS_DW.is_Arm = FMS_IN_Auto;
      switch (FMS_B.safe_mode) {
       case PilotMode_Offboard:
        FMS_DW.is_Auto = FMS_IN_Offboard;
        FMS_B.VehicleMode_e = VehicleMode_Offboard;
        break;

       case PilotMode_Mission:
        FMS_DW.is_Auto = FMS_IN_Mission;
        FMS_B.VehicleMode_e = VehicleMode_Mission;
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
        break;
      }
    } else if (tmp == 2.0) {
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.safe_mode) {
       case PilotMode_Acro:
        FMS_DW.is_Assist = FMS_IN_Acro;
        FMS_B.VehicleMode_e = VehicleMode_Acro;
        break;

       case PilotMode_Stabilize:
        FMS_DW.is_Assist = FMS_IN_Stabilize;
        FMS_B.VehicleMode_e = VehicleMode_Stabilize;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_Assist = FMS_IN_Altitude;
        FMS_B.VehicleMode_e = VehicleMode_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_Assist = FMS_IN_Position;
        FMS_B.VehicleMode_e = VehicleMode_Position;
        break;

       default:
        FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
        FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
        break;
      }
    } else if (tmp == 1.0) {
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.safe_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_b;
        FMS_B.VehicleMode_e = VehicleMode_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
        FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
      }
    } else {
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
      FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
    }
  } else {
    condIsTrue = (FMS_DW.prep_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
      FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_i = condIsTrue;
    guard1 = false;
    if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_d >
        500) {
      guard1 = true;
    } else {
      if (FMS_sf_msg_pop_M()) {
        condIsTrue = (FMS_DW.M_msgReservedData == CMD_Takeoff);
      } else {
        condIsTrue = false;
      }

      if (condIsTrue) {
        guard1 = true;
      } else {
        if ((FMS_DW.temporalCounter_i1 >= 7500U) || (FMS_DW.sfEvent ==
             FMS_event_DisarmEvent)) {
          FMS_DW.prep_takeoff = 0.0;
          condIsTrue = (FMS_DW.prep_takeoff == 1.0);
          if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
            FMS_DW.durationLastReferenceTick_1_d =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_i = condIsTrue;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.VehicleMode_e = VehicleMode_Disarm;
        }
      }
    }

    if (guard1) {
      FMS_B.Cmd_In.p_takeoff[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.p_takeoff[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.prep_takeoff = 0.0;
      condIsTrue = (FMS_DW.prep_takeoff == 1.0);
      if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
        FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_i = condIsTrue;
      FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Takeoff;
      FMS_B.VehicleMode_e = VehicleMode_Takeoff;
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Vehicle(void)
{
  boolean_T sf_internal_predicateOutput;
  real_T tmp;
  boolean_T guard1 = false;
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
    FMS_B.VehicleMode_e = VehicleMode_Disarm;
  } else {
    guard1 = false;
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j))
      {
        FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_l
          >= 500) {
        FMS_exit_internal_Arm();
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.VehicleMode_e = VehicleMode_Disarm;
      } else if (FMS_DW.mode_prev != FMS_DW.mode_start) {
        tmp = FMS_getArmMode(FMS_B.safe_mode);
        if (tmp == 3.0) {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_Auto;
          switch (FMS_B.safe_mode) {
           case PilotMode_Offboard:
            FMS_DW.is_Auto = FMS_IN_Offboard;
            FMS_B.VehicleMode_e = VehicleMode_Offboard;
            break;

           case PilotMode_Mission:
            FMS_DW.is_Auto = FMS_IN_Mission;
            FMS_B.VehicleMode_e = VehicleMode_Mission;
            break;

           default:
            FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
            break;
          }
        } else if (tmp == 2.0) {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_Assist;
          switch (FMS_B.safe_mode) {
           case PilotMode_Acro:
            FMS_DW.is_Assist = FMS_IN_Acro;
            FMS_B.VehicleMode_e = VehicleMode_Acro;
            break;

           case PilotMode_Stabilize:
            FMS_DW.is_Assist = FMS_IN_Stabilize;
            FMS_B.VehicleMode_e = VehicleMode_Stabilize;
            break;

           case PilotMode_Altitude:
            FMS_DW.is_Assist = FMS_IN_Altitude;
            FMS_B.VehicleMode_e = VehicleMode_Altitude;
            break;

           case PilotMode_Position:
            FMS_DW.is_Assist = FMS_IN_Position;
            FMS_B.VehicleMode_e = VehicleMode_Position;
            break;

           default:
            FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
            break;
          }
        } else if (tmp == 1.0) {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_Manual;
          if (FMS_B.safe_mode == PilotMode_Manual) {
            FMS_DW.is_Manual = FMS_IN_Manual_b;
            FMS_B.VehicleMode_e = VehicleMode_Manual;
          } else {
            FMS_DW.is_Manual = FMS_IN_InValidManualMode;
            FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
          }
        } else {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
          FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
        }
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Return);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_B.Cmd_In.p_return[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.p_return[1] = FMS_DW.home[1];
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
          FMS_DW.is_SubMode = FMS_IN_Return;
          FMS_B.VehicleMode_e = VehicleMode_Return;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Land);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            FMS_B.Cmd_In.p_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.p_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_exit_internal_Arm();
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_SubMode = FMS_IN_Land;
            FMS_B.VehicleMode_e = VehicleMode_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
          } else {
            switch (FMS_DW.is_Arm) {
             case FMS_IN_Assist:
              if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
                FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
                FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
                FMS_DW.is_Vehicle = FMS_IN_Disarm;
                FMS_B.VehicleMode_e = VehicleMode_Disarm;
              }
              break;

             case FMS_IN_Auto:
              if (FMS_sf_msg_pop_M()) {
                sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
                  CMD_Pause);
              } else {
                sf_internal_predicateOutput = false;
              }

              if (sf_internal_predicateOutput) {
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
                FMS_B.VehicleMode_e = VehicleMode_Hold;
              } else {
                if (FMS_DW.is_Auto == FMS_IN_InvalidAutoMode) {
                  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
                  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
                  FMS_DW.is_Vehicle = FMS_IN_Disarm;
                  FMS_B.VehicleMode_e = VehicleMode_Disarm;
                }
              }
              break;

             case FMS_IN_InvalidArmMode:
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.VehicleMode_e = VehicleMode_Disarm;
              break;

             case FMS_IN_Manual:
              if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
                FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
                FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
                FMS_DW.is_Vehicle = FMS_IN_Disarm;
                FMS_B.VehicleMode_e = VehicleMode_Disarm;
              }
              break;

             case FMS_IN_SubMode:
              FMS_SubMode();
              break;
            }
          }
        }
      }
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
      FMS_Standby();
      break;
    }

    if (guard1) {
      FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      FMS_B.VehicleMode_e = VehicleMode_Standby;
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
  real32_T rtb_Integrator1_a;
  real32_T rtb_Sqrt_d;
  MotionState rtb_state_a;
  real32_T rtb_Switch_l[3];
  real32_T rtb_Sum1;
  real32_T rtb_Switch;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  boolean_T rtb_LogicalOperator_n;
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

  /* Saturate: '<S7>/Saturation' incorporates:
   *  Delay: '<S7>/Delay'
   */
  if (FMS_DW.Delay_DSTATE_g > 1) {
    rtb_Saturation_g = 1;
  } else if (FMS_DW.Delay_DSTATE_g < 0) {
    rtb_Saturation_g = 0;
  } else {
    rtb_Saturation_g = FMS_DW.Delay_DSTATE_g;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Switch: '<S7>/Switch' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Inport: '<Root>/Auto_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (rtb_Saturation_g > 0) {
    FMS_B.Switch = (FMS_Cmd)FMS_U.Auto_Cmd.cmd_1;
  } else {
    FMS_B.Switch = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion1 = (PilotMode)FMS_U.Pilot_Cmd.mode;

  /* Chart: '<Root>/Mode Degrade' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    switch (FMS_B.DataTypeConversion1) {
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.safe_mode = PilotMode_Acro;
        switch (FMS_B.DataTypeConversion1) {
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
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      }
      break;

     case FMS_IN_Altitude:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_B.safe_mode = PilotMode_Altitude;
        switch (FMS_B.DataTypeConversion1) {
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
      switch (FMS_B.DataTypeConversion1) {
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
        switch (FMS_B.DataTypeConversion1) {
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
      FMS_B.safe_mode = FMS_B.DataTypeConversion1;
      switch (FMS_B.DataTypeConversion1) {
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
        switch (FMS_B.DataTypeConversion1) {
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.safe_mode = PilotMode_Stabilize;
        switch (FMS_B.DataTypeConversion1) {
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
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Mode Degrade' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S250>/Discrete-Time Integrator5' incorporates:
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

  /* DiscreteIntegrator: '<S251>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S251>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S249>/Constant'
   *  DiscreteIntegrator: '<S250>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S251>/Discrete-Time Integrator5'
   *  Logic: '<S252>/AND'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S249>/Compare'
   *  RelationalOperator: '<S252>/Lower Test'
   *  RelationalOperator: '<S252>/Upper Test'
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
  rtb_LogicalOperator_n = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_LogicalOperator_n) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
    FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_i = rtb_LogicalOperator_n;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
    FMS_DW.durationLastReferenceTick_1_l = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_j = FMS_B.LogicalOperator1;
  rtb_LogicalOperator_n = !FMS_DW.br;
  if (rtb_LogicalOperator_n || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
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
  FMS_DW.cmd_start = FMS_B.Switch;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.safe_mode;
  FMS_DW.M_isValid = false;
  if (FMS_DW.is_active_c11_FMS == 0U) {
    FMS_DW.cmd_prev = FMS_B.Switch;
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
    FMS_B.VehicleMode_e = VehicleMode_Disarm;
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      switch (FMS_DW.is_Command_Listener) {
       case FMS_IN_Check:
        if (FMS_DW.valid_cmd) {
          FMS_DW.is_Command_Listener = FMS_IN_Send;
          FMS_DW.M_msgReservedData = FMS_B.Switch;
          FMS_sf_msg_send_M();
        } else {
          FMS_DW.is_Command_Listener = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.Switch != CMD_None))
        {
          FMS_DW.is_Command_Listener = FMS_IN_Check;
          FMS_DW.valid_cmd = FMS_CheckCmdValid(FMS_B.Switch, FMS_B.safe_mode,
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
        if (rtb_LogicalOperator_n || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
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
  switch (FMS_B.VehicleMode_e) {
   case VehicleMode_Disarm:
   case VehicleMode_None:
    FMS_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case VehicleMode_Standby:
    FMS_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 2;
    break;
  }

  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S15>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S22>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S213>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S203>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S161>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S139>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S149>/Switch Case' */
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
      /* Disable for SwitchCase: '<S19>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S115>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S34>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S51>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S91>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S67>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S78>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S15>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Disarm' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S2>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Standby' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S17>/Bus Assignment'
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S17>/Constant'
     *  SignalConversion: '<S17>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S17>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S17>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_f;
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
     *  ActionPort: '<S15>/Action Port'
     */
    /* SwitchCase: '<S15>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;
    switch (FMS_B.VehicleMode_e) {
     case VehicleMode_Land:
     case VehicleMode_Return:
     case VehicleMode_Takeoff:
     case VehicleMode_Hold:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 0;
      break;

     case VehicleMode_Offboard:
     case VehicleMode_Mission:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 1;
      break;

     case VehicleMode_Acro:
     case VehicleMode_Stabilize:
     case VehicleMode_Altitude:
     case VehicleMode_Position:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 2;
      break;

     case VehicleMode_Manual:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 3;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 4;
      break;
    }

    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S22>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S213>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S203>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S161>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S139>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S149>/Switch Case' */
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
        /* Disable for SwitchCase: '<S19>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S115>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S34>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S91>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S67>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S78>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S15>/SubMode' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* SwitchCase: '<S22>/Switch Case' incorporates:
       *  Math: '<S234>/Math Function'
       *  Sum: '<S198>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
      switch (FMS_B.VehicleMode_e) {
       case VehicleMode_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleMode_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       case VehicleMode_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;

       case VehicleMode_Hold:
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
          /* Disable for SwitchCase: '<S213>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S203>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S161>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S139>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S149>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S22>/Takeoff' incorporates:
         *  ActionPort: '<S134>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S246>/Trigonometric Function1' incorporates:
         *  Gain: '<S245>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S246>/Trigonometric Function3'
         */
        rtb_TmpSignalConversionAtMath_1 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[0] = rtb_TmpSignalConversionAtMath_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S246>/Trigonometric Function' incorporates:
         *  Gain: '<S245>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S246>/Trigonometric Function2'
         */
        rtb_Integrator1_a = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[1] = rtb_Integrator1_a;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S246>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Gain: '<S246>/Gain' */
        rtb_VectorConcatenate_m[3] = -rtb_Integrator1_a;

        /* Trigonometry: '<S246>/Trigonometric Function3' */
        rtb_VectorConcatenate_m[4] = rtb_TmpSignalConversionAtMath_1;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S246>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S243>/Saturation1' */
        rtb_Sqrt_d = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S243>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S243>/Sum'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.p_takeoff[0] - FMS_U.INS_Out.x_R;
        rtb_Sum1 = FMS_B.Cmd_In.p_takeoff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S243>/Multiply' */
        for (b_previousEvent = 0; b_previousEvent < 3; b_previousEvent++) {
          rtb_Switch_l[b_previousEvent] =
            rtb_VectorConcatenate_m[b_previousEvent + 3] * rtb_Sum1 +
            rtb_VectorConcatenate_m[b_previousEvent] * rtb_Switch_b_idx_1;
        }

        /* Saturate: '<S243>/Saturation1' incorporates:
         *  Gain: '<S243>/Gain2'
         *  Product: '<S243>/Multiply'
         */
        rtb_Sum1 = FMS_PARAM.XY_P * rtb_Switch_l[0];
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
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S243>/Saturation1' */
        if (rtb_Sum1 > rtb_Sqrt_d) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_d;
        } else if (rtb_Sum1 < rtb_Switch) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch;
        } else {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sum1;
        }

        if (rtb_Switch_b_idx_1 > rtb_Sqrt_d) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_d;
        } else if (rtb_Switch_b_idx_1 < rtb_Switch) {
          /* BusAssignment: '<S134>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch;
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
        FMS_Y.FMS_Out.w_cmd = -0.5F;

        /* End of Outputs for SubSystem: '<S22>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S22>/Land' incorporates:
         *  ActionPort: '<S132>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S178>/Trigonometric Function1' incorporates:
         *  Gain: '<S177>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S178>/Trigonometric Function' incorporates:
         *  Gain: '<S177>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S178>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S178>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Gain: '<S178>/Gain' incorporates:
         *  Gain: '<S177>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S178>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_m[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S178>/Trigonometric Function3' incorporates:
         *  Gain: '<S177>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S178>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S178>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S178>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S174>/Saturation1' */
        rtb_Switch = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Sqrt_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S175>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S175>/Sum'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.p_land[0] - FMS_U.INS_Out.x_R;
        rtb_Sum1 = FMS_B.Cmd_In.p_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S175>/Multiply' */
        for (b_previousEvent = 0; b_previousEvent < 3; b_previousEvent++) {
          rtb_Switch_l[b_previousEvent] =
            rtb_VectorConcatenate_m[b_previousEvent + 3] * rtb_Sum1 +
            rtb_VectorConcatenate_m[b_previousEvent] * rtb_Switch_b_idx_1;
        }

        /* Saturate: '<S174>/Saturation1' incorporates:
         *  Gain: '<S175>/Gain2'
         *  Product: '<S175>/Multiply'
         */
        rtb_Sum1 = FMS_PARAM.XY_P * rtb_Switch_l[0];
        rtb_Switch_b_idx_1 = FMS_PARAM.XY_P * rtb_Switch_l[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S132>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S132>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S132>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S174>/Saturation1' */
        if (rtb_Sum1 > rtb_Switch) {
          /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch;
        } else if (rtb_Sum1 < rtb_Sqrt_d) {
          /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_d;
        } else {
          /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sum1;
        }

        if (rtb_Switch_b_idx_1 > rtb_Switch) {
          /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch;
        } else if (rtb_Switch_b_idx_1 < rtb_Sqrt_d) {
          /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_d;
        } else {
          /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_b_idx_1;
        }

        /* BusAssignment: '<S132>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S132>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S22>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S22>/Return' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Delay: '<S181>/Delay'
           *  DiscreteIntegrator: '<S185>/Integrator'
           *  DiscreteIntegrator: '<S185>/Integrator1'
           *  DiscreteIntegrator: '<S239>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S22>/Return' */

          /* SystemReset for IfAction SubSystem: '<S22>/Return' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Chart: '<S204>/Motion Status'
           *  Chart: '<S214>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S22>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Return' incorporates:
         *  ActionPort: '<S133>/Action Port'
         */
        /* Delay: '<S181>/Delay' incorporates:
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
        /* Sum: '<S195>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S200>/Square'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sqrt_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.p_return[0];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Sqrt_d * rtb_Sqrt_d;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.p_return[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S200>/Square' */
        rtb_Sqrt_d *= rtb_Sqrt_d;

        /* Sqrt: '<S200>/Sqrt' incorporates:
         *  Sum: '<S200>/Sum of Elements'
         */
        rtb_Sqrt_d = sqrtf(rtb_TmpSignalConversionAtMath_1 + rtb_Sqrt_d);

        /* Switch: '<S195>/Switch' incorporates:
         *  Constant: '<S195>/vel'
         */
        if (rtb_Sqrt_d > 10.0F) {
          rtb_Switch = 5.0F;
        } else {
          /* Gain: '<S195>/Gain' */
          rtb_Switch = 0.5F * rtb_Sqrt_d;

          /* Saturate: '<S195>/Saturation' */
          if (rtb_Switch < 0.5F) {
            rtb_Switch = 0.5F;
          }

          /* End of Saturate: '<S195>/Saturation' */
        }

        /* End of Switch: '<S195>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S214>/Motion State' incorporates:
         *  Constant: '<S214>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S214>/Square'
         *  Math: '<S214>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S214>/Sqrt'
         *  Sum: '<S214>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S213>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S213>/Hold Control' incorporates:
             *  ActionPort: '<S216>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S213>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S213>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S213>/Hold Control' incorporates:
           *  ActionPort: '<S216>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S213>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S213>/Brake Control' incorporates:
           *  ActionPort: '<S215>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S213>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S213>/Move Control' incorporates:
             *  ActionPort: '<S217>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S213>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S213>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S213>/Move Control' incorporates:
           *  ActionPort: '<S217>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S213>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S213>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S204>/Motion Status' incorporates:
         *  Abs: '<S204>/Abs'
         *  Constant: '<S204>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S203>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S203>/Hold Control' incorporates:
             *  ActionPort: '<S206>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S203>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S203>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S203>/Hold Control' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S203>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S203>/Brake Control' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S203>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S203>/Move Control' incorporates:
             *  ActionPort: '<S207>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S203>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S203>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S203>/Move Control' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S203>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S203>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S133>/Sum' incorporates:
         *  Delay: '<S181>/Delay'
         *  MATLAB Function: '<S197>/OutRegionRegWP'
         *  MATLAB Function: '<S197>/SearchL1RefWP'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.p_return[0] -
          FMS_DW.Delay_DSTATE[0];
        rtb_MathFunction_hf_idx_1 = FMS_B.Cmd_In.p_return[1] -
          FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S194>/Math Function' incorporates:
         *  Math: '<S240>/Math Function'
         *  Sum: '<S133>/Sum'
         *  Switch: '<S180>/Switch'
         */
        rtb_Switch_b_idx_1 = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;
        rtb_Sqrt_d = rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Sum: '<S194>/Sum of Elements' incorporates:
         *  Math: '<S194>/Math Function'
         */
        rtb_Sum1 = rtb_Sqrt_d + rtb_Switch_b_idx_1;

        /* Math: '<S194>/Math Function1' incorporates:
         *  Sum: '<S194>/Sum of Elements'
         *
         * About '<S194>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sum1 < 0.0F) {
          rtb_Integrator1_a = -sqrtf(fabsf(rtb_Sum1));
        } else {
          rtb_Integrator1_a = sqrtf(rtb_Sum1);
        }

        /* End of Math: '<S194>/Math Function1' */

        /* Switch: '<S194>/Switch' incorporates:
         *  Constant: '<S194>/Constant'
         *  Product: '<S194>/Product'
         *  Sum: '<S133>/Sum'
         */
        if (rtb_Integrator1_a > 0.0F) {
          rtb_Switch_l[0] = rtb_MathFunction_hf_idx_1;
          rtb_Switch_l[1] = rtb_MathFunction_h_idx_0;
          rtb_Switch_l[2] = rtb_Integrator1_a;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S194>/Switch' */

        /* Product: '<S194>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S192>/Subtract' incorporates:
         *  Product: '<S192>/Multiply'
         *  Product: '<S192>/Multiply1'
         */
        rtb_Integrator1_a = rtb_TmpSignalConversionAtMath_1 * FMS_ConstB.Divide
          [1] - rtb_TmpSignalConversionAtMath_0 * FMS_ConstB.Divide[0];

        /* Signum: '<S183>/Sign1' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S183>/Sign1' */

        /* Switch: '<S183>/Switch2' incorporates:
         *  Constant: '<S183>/Constant4'
         */
        if (rtb_Integrator1_a == 0.0F) {
          rtb_Integrator1_a = 1.0F;
        }

        /* End of Switch: '<S183>/Switch2' */

        /* DotProduct: '<S183>/Dot Product' */
        rtb_Sum1 = FMS_ConstB.Divide[0] * rtb_TmpSignalConversionAtMath_1 +
          FMS_ConstB.Divide[1] * rtb_TmpSignalConversionAtMath_0;

        /* Trigonometry: '<S183>/Acos' incorporates:
         *  DotProduct: '<S183>/Dot Product'
         */
        if (rtb_Sum1 > 1.0F) {
          rtb_Sum1 = 1.0F;
        } else {
          if (rtb_Sum1 < -1.0F) {
            rtb_Sum1 = -1.0F;
          }
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S182>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S183>/Multiply'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S183>/Acos'
         */
        rtb_Sum1 = acosf(rtb_Sum1) * rtb_Integrator1_a - FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Abs: '<S186>/Abs' */
        rtb_Integrator1_a = fabsf(rtb_Sum1);

        /* Switch: '<S186>/Switch' incorporates:
         *  Constant: '<S186>/Constant'
         *  Constant: '<S191>/Constant'
         *  Product: '<S186>/Multiply'
         *  RelationalOperator: '<S191>/Compare'
         *  Sum: '<S186>/Subtract'
         */
        if (rtb_Integrator1_a > 3.14159274F) {
          /* Signum: '<S186>/Sign' */
          if (rtb_Sum1 < 0.0F) {
            rtb_Sum1 = -1.0F;
          } else {
            if (rtb_Sum1 > 0.0F) {
              rtb_Sum1 = 1.0F;
            }
          }

          /* End of Signum: '<S186>/Sign' */
          rtb_Sum1 *= rtb_Integrator1_a - 6.28318548F;
        }

        /* End of Switch: '<S186>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S182>/Sum2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Sum1 += FMS_U.INS_Out.psi;

        /* Switch: '<S180>/Switch' incorporates:
         *  Abs: '<S180>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S199>/Multiply'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S182>/Sum'
         */
        if (fabsf(rtb_Sum1 - FMS_U.INS_Out.psi) > 0.261799395F) {
          /* Saturate: '<S213>/Saturation1' */
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

          /* End of Saturate: '<S213>/Saturation1' */

          /* Saturate: '<S203>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_l[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S203>/Saturation1' */
        } else {
          /* SignalConversion: '<S242>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S242>/Constant4'
           */
          rtb_VectorConcatenate_m[5] = 0.0F;

          /* Gain: '<S241>/Gain' incorporates:
           *  DiscreteIntegrator: '<S239>/Discrete-Time Integrator'
           *  Sum: '<S239>/Add'
           */
          rtb_Integrator1_a = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* Trigonometry: '<S242>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S242>/Trigonometric Function1'
           */
          rtb_TmpSignalConversionAtMath_1 = arm_cos_f32(rtb_Integrator1_a);
          rtb_VectorConcatenate_m[4] = rtb_TmpSignalConversionAtMath_1;

          /* Trigonometry: '<S242>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S242>/Trigonometric Function'
           */
          rtb_Integrator1_a = arm_sin_f32(rtb_Integrator1_a);

          /* Gain: '<S242>/Gain' incorporates:
           *  Trigonometry: '<S242>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_m[3] = -rtb_Integrator1_a;

          /* SignalConversion: '<S242>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S242>/Constant3'
           */
          rtb_VectorConcatenate_m[2] = 0.0F;

          /* Trigonometry: '<S242>/Trigonometric Function' */
          rtb_VectorConcatenate_m[1] = rtb_Integrator1_a;

          /* Trigonometry: '<S242>/Trigonometric Function1' */
          rtb_VectorConcatenate_m[0] = rtb_TmpSignalConversionAtMath_1;

          /* SignalConversion: '<S242>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S240>/Sum of Elements' */
          rtb_Switch_b_idx_1 += rtb_Sqrt_d;

          /* Math: '<S240>/Math Function1' incorporates:
           *  Sum: '<S240>/Sum of Elements'
           *
           * About '<S240>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_b_idx_1 < 0.0F) {
            rtb_Integrator1_a = -sqrtf(fabsf(rtb_Switch_b_idx_1));
          } else {
            rtb_Integrator1_a = sqrtf(rtb_Switch_b_idx_1);
          }

          /* End of Math: '<S240>/Math Function1' */

          /* Switch: '<S240>/Switch' incorporates:
           *  Constant: '<S240>/Constant'
           *  Product: '<S240>/Product'
           *  Sum: '<S133>/Sum'
           */
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Sqrt_d = rtb_MathFunction_h_idx_0;
            rtb_Switch_b_idx_1 = rtb_MathFunction_hf_idx_1;
          } else {
            rtb_Sqrt_d = 0.0F;
            rtb_Switch_b_idx_1 = 0.0F;
            rtb_Integrator1_a = 1.0F;
          }

          /* End of Switch: '<S240>/Switch' */

          /* Product: '<S238>/Multiply2' incorporates:
           *  Product: '<S240>/Divide'
           */
          rtb_Sqrt_d = rtb_Sqrt_d / rtb_Integrator1_a * rtb_Switch;
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_1 / rtb_Integrator1_a *
            rtb_Switch;
          for (b_previousEvent = 0; b_previousEvent < 3; b_previousEvent++) {
            rtb_Switch_l[b_previousEvent] =
              rtb_VectorConcatenate_m[b_previousEvent + 3] * rtb_Switch_b_idx_1
              + rtb_VectorConcatenate_m[b_previousEvent] * rtb_Sqrt_d;
          }
        }

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* DiscreteIntegrator: '<S185>/Integrator1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Integrator1_DSTATE_e = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S184>/Sum' incorporates:
         *  DiscreteIntegrator: '<S185>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Integrator1_a = FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Abs: '<S188>/Abs' */
        rtb_Sqrt_d = fabsf(rtb_Integrator1_a);

        /* Switch: '<S188>/Switch' incorporates:
         *  Constant: '<S188>/Constant'
         *  Constant: '<S189>/Constant'
         *  Product: '<S188>/Multiply'
         *  RelationalOperator: '<S189>/Compare'
         *  Sum: '<S188>/Subtract'
         */
        if (rtb_Sqrt_d > 3.14159274F) {
          /* Signum: '<S188>/Sign' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else {
            if (rtb_Integrator1_a > 0.0F) {
              rtb_Integrator1_a = 1.0F;
            }
          }

          /* End of Signum: '<S188>/Sign' */
          rtb_Integrator1_a *= rtb_Sqrt_d - 6.28318548F;
        }

        /* End of Switch: '<S188>/Switch' */

        /* Gain: '<S184>/Gain2' */
        rtb_Integrator1_a *= FMS_PARAM.YAW_P;

        /* Saturate: '<S184>/Saturation' */
        if (rtb_Integrator1_a > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Integrator1_a = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Integrator1_a < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Integrator1_a = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S184>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S133>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S133>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S133>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_l[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_l[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_l[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Integrator1_a;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S233>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S233>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S232>/Sum of Elements'
         */
        rtb_Switch_b_idx_1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S233>/Math Function1' incorporates:
         *  Sum: '<S233>/Sum of Elements'
         *
         * About '<S233>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Integrator1_a = -sqrtf(fabsf(rtb_Switch_b_idx_1));
        } else {
          rtb_Integrator1_a = sqrtf(rtb_Switch_b_idx_1);
        }

        /* End of Math: '<S233>/Math Function1' */

        /* Switch: '<S233>/Switch' incorporates:
         *  Constant: '<S233>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S233>/Product'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (rtb_Integrator1_a > 0.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          rtb_Switch_l[2] = rtb_Integrator1_a;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S233>/Switch' */

        /* Product: '<S233>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S236>/Sum of Elements' incorporates:
         *  Math: '<S236>/Math Function'
         *  SignalConversion: '<S236>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_d = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtMath_1 *
          rtb_TmpSignalConversionAtMath_1;

        /* Math: '<S236>/Math Function1' incorporates:
         *  Sum: '<S236>/Sum of Elements'
         *
         * About '<S236>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Integrator1_a = -sqrtf(fabsf(rtb_Sqrt_d));
        } else {
          rtb_Integrator1_a = sqrtf(rtb_Sqrt_d);
        }

        /* End of Math: '<S236>/Math Function1' */

        /* Switch: '<S236>/Switch' incorporates:
         *  Constant: '<S236>/Constant'
         *  Product: '<S236>/Product'
         */
        if (rtb_Integrator1_a > 0.0F) {
          rtb_Switch_l[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_Switch_l[1] = rtb_TmpSignalConversionAtMath_1;
          rtb_Switch_l[2] = rtb_Integrator1_a;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S236>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S197>/NearbyRefWP' incorporates:
         *  Constant: '<S133>/L1'
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

        /* End of MATLAB Function: '<S197>/NearbyRefWP' */

        /* MATLAB Function: '<S197>/SearchL1RefWP' incorporates:
         *  Constant: '<S133>/L1'
         *  Delay: '<S181>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Integrator1_a = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0
          + rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

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
                     100.0F) * (4.0F * rtb_Integrator1_a);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_d = -1.0F;
        rtb_MathFunction_idx_0 = 0.0F;
        rtb_MathFunction_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Integrator1_a);
          rtb_Integrator1_a = (-B - u1_tmp) / (2.0F * rtb_Integrator1_a);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Integrator1_a >= 0.0F) &&
              (rtb_Integrator1_a <= 1.0F)) {
            rtb_Sqrt_d = fmaxf(D, rtb_Integrator1_a);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Sqrt_d = D;
            guard1 = true;
          } else {
            if ((rtb_Integrator1_a >= 0.0F) && (rtb_Integrator1_a <= 1.0F)) {
              rtb_Sqrt_d = rtb_Integrator1_a;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Integrator1_a);
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
        /* MATLAB Function: '<S197>/OutRegionRegWP' incorporates:
         *  Delay: '<S181>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Integrator1_a = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) *
                             rtb_MathFunction_hf_idx_1 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE[0]) * rtb_MathFunction_h_idx_0) /
          (rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 +
           rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_LogicalOperator_n = (rtb_Integrator1_a <= 0.0F);
        u = (rtb_Integrator1_a >= 1.0F);
        if (rtb_LogicalOperator_n) {
          rtb_MathFunction_h_idx_0 = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.p_return[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          rtb_MathFunction_h_idx_0 = rtb_Integrator1_a *
            rtb_MathFunction_h_idx_0 + FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S197>/Switch1' incorporates:
         *  Constant: '<S227>/Constant'
         *  RelationalOperator: '<S227>/Compare'
         */
        if (dis <= 0.0F) {
          /* Switch: '<S197>/Switch' incorporates:
           *  Constant: '<S226>/Constant'
           *  MATLAB Function: '<S197>/SearchL1RefWP'
           *  RelationalOperator: '<S226>/Compare'
           */
          if (rtb_Sqrt_d >= 0.0F) {
            rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_idx_0;
            rtb_TmpSignalConversionAtMath_0 = rtb_MathFunction_idx_1;
          } else {
            rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_h_idx_0;

            /* MATLAB Function: '<S197>/OutRegionRegWP' incorporates:
             *  Delay: '<S181>/Delay'
             *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_LogicalOperator_n) {
              rtb_TmpSignalConversionAtMath_0 = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.p_return[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            } else {
              rtb_TmpSignalConversionAtMath_0 = rtb_Integrator1_a *
                rtb_MathFunction_hf_idx_1 + FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S197>/Switch' */
        }

        /* End of Switch: '<S197>/Switch1' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S198>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_MathFunction_hf_idx_1 = rtb_TmpSignalConversionAtMath_1 -
          FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_hf_idx_1;
        rtb_Sqrt_d = rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S198>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S234>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_MathFunction_hf_idx_1 = rtb_TmpSignalConversionAtMath_0 -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S234>/Sum of Elements' incorporates:
         *  Math: '<S234>/Math Function'
         */
        rtb_Sqrt_d += rtb_MathFunction_hf_idx_1 * rtb_MathFunction_hf_idx_1;

        /* Math: '<S234>/Math Function1' incorporates:
         *  Sum: '<S234>/Sum of Elements'
         *
         * About '<S234>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Integrator1_a = -sqrtf(fabsf(rtb_Sqrt_d));
        } else {
          rtb_Integrator1_a = sqrtf(rtb_Sqrt_d);
        }

        /* End of Math: '<S234>/Math Function1' */

        /* Switch: '<S234>/Switch' incorporates:
         *  Constant: '<S234>/Constant'
         *  Product: '<S234>/Product'
         */
        if (rtb_Integrator1_a <= 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = 0.0F;
          rtb_MathFunction_hf_idx_1 = 0.0F;
          rtb_Integrator1_a = 1.0F;
        }

        /* End of Switch: '<S234>/Switch' */

        /* Product: '<S234>/Divide' */
        rtb_MathFunction_idx_0 = rtb_TmpSignalConversionAtMath_1 /
          rtb_Integrator1_a;
        rtb_MathFunction_idx_1 = rtb_MathFunction_hf_idx_1 / rtb_Integrator1_a;

        /* Sum: '<S237>/Sum of Elements' incorporates:
         *  Math: '<S237>/Math Function'
         *  SignalConversion: '<S237>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_d = rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1 +
          rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0;

        /* Math: '<S237>/Math Function1' incorporates:
         *  Sum: '<S237>/Sum of Elements'
         *
         * About '<S237>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Integrator1_a = -sqrtf(fabsf(rtb_Sqrt_d));
        } else {
          rtb_Integrator1_a = sqrtf(rtb_Sqrt_d);
        }

        /* End of Math: '<S237>/Math Function1' */

        /* Switch: '<S237>/Switch' incorporates:
         *  Constant: '<S237>/Constant'
         *  Product: '<S237>/Product'
         */
        if (rtb_Integrator1_a > 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_idx_1;
          rtb_MathFunction_hf_idx_1 = rtb_MathFunction_idx_0;
        } else {
          rtb_TmpSignalConversionAtMath_1 = 0.0F;
          rtb_MathFunction_hf_idx_1 = 0.0F;
          rtb_Integrator1_a = 1.0F;
        }

        /* End of Switch: '<S237>/Switch' */

        /* Product: '<S237>/Divide' */
        rtb_MathFunction_idx_0 = rtb_TmpSignalConversionAtMath_1 /
          rtb_Integrator1_a;

        /* Product: '<S236>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S237>/Divide' */
        rtb_MathFunction_idx_1 = rtb_MathFunction_hf_idx_1 / rtb_Integrator1_a;

        /* Product: '<S236>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sqrt: '<S232>/Sqrt' */
        rtb_Integrator1_a = sqrtf(rtb_Switch_b_idx_1);

        /* Gain: '<S198>/Gain' incorporates:
         *  Math: '<S198>/Square'
         */
        rtb_Switch_b_idx_1 = rtb_Integrator1_a * rtb_Integrator1_a * 2.0F;

        /* Sum: '<S235>/Subtract' incorporates:
         *  Product: '<S235>/Multiply'
         *  Product: '<S235>/Multiply1'
         */
        rtb_Integrator1_a = rtb_MathFunction_idx_0 *
          rtb_TmpSignalConversionAtMath_0 - rtb_MathFunction_idx_1 *
          rtb_TmpSignalConversionAtMath_1;

        /* Signum: '<S231>/Sign1' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S231>/Sign1' */

        /* Switch: '<S231>/Switch2' incorporates:
         *  Constant: '<S231>/Constant4'
         */
        if (rtb_Integrator1_a == 0.0F) {
          rtb_Integrator1_a = 1.0F;
        }

        /* End of Switch: '<S231>/Switch2' */

        /* DotProduct: '<S231>/Dot Product' */
        rtb_Sqrt_d = rtb_TmpSignalConversionAtMath_1 * rtb_MathFunction_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_MathFunction_idx_1;

        /* Trigonometry: '<S231>/Acos' incorporates:
         *  DotProduct: '<S231>/Dot Product'
         */
        if (rtb_Sqrt_d > 1.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          if (rtb_Sqrt_d < -1.0F) {
            rtb_Sqrt_d = -1.0F;
          }
        }

        /* Product: '<S231>/Multiply' incorporates:
         *  Trigonometry: '<S231>/Acos'
         */
        rtb_Integrator1_a *= acosf(rtb_Sqrt_d);

        /* Saturate: '<S198>/Saturation' */
        if (rtb_Integrator1_a > 1.57079637F) {
          rtb_Integrator1_a = 1.57079637F;
        } else {
          if (rtb_Integrator1_a < -1.57079637F) {
            rtb_Integrator1_a = -1.57079637F;
          }
        }

        /* End of Saturate: '<S198>/Saturation' */

        /* Trigonometry: '<S198>/Sin' */
        rtb_MathFunction_hf_idx_1 = arm_sin_f32(rtb_Integrator1_a);

        /* Sum: '<S190>/Add' incorporates:
         *  DiscreteIntegrator: '<S185>/Integrator'
         *  DiscreteIntegrator: '<S185>/Integrator1'
         *  Sum: '<S185>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_e - rtb_Sum1) +
          FMS_DW.Integrator_DSTATE_bs;

        /* Signum: '<S190>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Integrator1_a;
        }

        /* End of Signum: '<S190>/Sign' */

        /* Sum: '<S190>/Add2' incorporates:
         *  Abs: '<S190>/Abs'
         *  DiscreteIntegrator: '<S185>/Integrator'
         *  Gain: '<S190>/Gain'
         *  Gain: '<S190>/Gain1'
         *  Product: '<S190>/Multiply2'
         *  Product: '<S190>/Multiply3'
         *  Sqrt: '<S190>/Sqrt'
         *  Sum: '<S190>/Add1'
         *  Sum: '<S190>/Subtract'
         */
        rtb_Sum1 = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) + FMS_ConstB.d_l) *
                          FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Sqrt_d
          + FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S190>/Add4' incorporates:
         *  DiscreteIntegrator: '<S185>/Integrator'
         */
        rtb_MathFunction_h_idx_0 = (rtb_Integrator1_a - rtb_Sum1) +
          FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S190>/Add3' */
        rtb_Sqrt_d = rtb_Integrator1_a + FMS_ConstB.d_l;

        /* Sum: '<S190>/Subtract1' */
        rtb_Integrator1_a -= FMS_ConstB.d_l;

        /* Signum: '<S190>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S190>/Sign1' */

        /* Signum: '<S190>/Sign2' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S190>/Sign2' */

        /* Sum: '<S190>/Add5' incorporates:
         *  Gain: '<S190>/Gain2'
         *  Product: '<S190>/Multiply4'
         *  Sum: '<S190>/Subtract2'
         */
        rtb_Sum1 += (rtb_Sqrt_d - rtb_Integrator1_a) * 0.5F *
          rtb_MathFunction_h_idx_0;

        /* Update for Delay: '<S181>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S239>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S133>/L1'
         *  Product: '<S198>/Divide'
         *  Product: '<S198>/Multiply1'
         *  Product: '<S199>/Divide1'
         */
        FMS_DW.l1_heading += rtb_MathFunction_hf_idx_1 * rtb_Switch_b_idx_1 /
          10.0F / rtb_Switch * 0.004F;

        /* Update for DiscreteIntegrator: '<S185>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S185>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S190>/Add6' */
        rtb_Sqrt_d = rtb_Sum1 + FMS_ConstB.d_l;

        /* Sum: '<S190>/Subtract3' */
        rtb_Integrator1_a = rtb_Sum1 - FMS_ConstB.d_l;

        /* Signum: '<S190>/Sign5' */
        if (rtb_Sum1 < 0.0F) {
          rtb_Switch = -1.0F;
        } else if (rtb_Sum1 > 0.0F) {
          rtb_Switch = 1.0F;
        } else {
          rtb_Switch = rtb_Sum1;
        }

        /* End of Signum: '<S190>/Sign5' */

        /* Signum: '<S190>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S190>/Sign3' */

        /* Signum: '<S190>/Sign4' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S190>/Sign4' */

        /* Signum: '<S190>/Sign6' */
        if (rtb_Sum1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else if (rtb_Sum1 > 0.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          rtb_Switch_b_idx_1 = rtb_Sum1;
        }

        /* End of Signum: '<S190>/Sign6' */

        /* Update for DiscreteIntegrator: '<S185>/Integrator' incorporates:
         *  Constant: '<S190>/const'
         *  Gain: '<S190>/Gain3'
         *  Product: '<S190>/Divide'
         *  Product: '<S190>/Multiply5'
         *  Product: '<S190>/Multiply6'
         *  Sum: '<S190>/Subtract4'
         *  Sum: '<S190>/Subtract5'
         *  Sum: '<S190>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Sum1 / FMS_ConstB.d_l - rtb_Switch)
          * FMS_ConstB.Gain4_np * ((rtb_Sqrt_d - rtb_Integrator1_a) * 0.5F) -
          rtb_Switch_b_idx_1 * 0.785398185F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S185>/Integrator' */
        /* End of Outputs for SubSystem: '<S22>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S22>/Hold' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Chart: '<S140>/Motion Status'
           *  Chart: '<S150>/Motion State'
           *  Chart: '<S162>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S22>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Hold' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S140>/Motion Status' incorporates:
         *  Abs: '<S140>/Abs'
         *  Constant: '<S140>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S150>/Motion State' incorporates:
         *  Abs: '<S150>/Abs'
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

        /* End of Chart: '<S150>/Motion State' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S162>/Motion State' incorporates:
         *  Constant: '<S162>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S162>/Square'
         *  Math: '<S162>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S162>/Sqrt'
         *  Sum: '<S162>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S161>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S161>/Hold Control' incorporates:
             *  ActionPort: '<S164>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S161>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S161>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S161>/Hold Control' incorporates:
           *  ActionPort: '<S164>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S161>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S161>/Brake Control' incorporates:
           *  ActionPort: '<S163>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S161>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S161>/Move Control' incorporates:
             *  ActionPort: '<S165>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S161>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S161>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S161>/Move Control' incorporates:
           *  ActionPort: '<S165>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S161>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S161>/Switch Case' */

        /* SwitchCase: '<S139>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S139>/Hold Control' incorporates:
             *  ActionPort: '<S142>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S139>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S139>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S139>/Hold Control' incorporates:
           *  ActionPort: '<S142>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S139>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S139>/Brake Control' incorporates:
           *  ActionPort: '<S141>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S139>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S139>/Move Control' incorporates:
             *  ActionPort: '<S143>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S139>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S139>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S139>/Move Control' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S139>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S139>/Switch Case' */

        /* SwitchCase: '<S149>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S149>/Hold Control' incorporates:
             *  ActionPort: '<S152>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S149>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S149>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S149>/Hold Control' incorporates:
           *  ActionPort: '<S152>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S149>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S149>/Brake Control' incorporates:
           *  ActionPort: '<S151>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S149>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S149>/Move Control' incorporates:
             *  ActionPort: '<S153>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S149>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S149>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S149>/Move Control' incorporates:
           *  ActionPort: '<S153>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S149>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S149>/Switch Case' */

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
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S149>/Saturation' */
        if (FMS_B.Merge_n > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n;
        }

        /* End of Saturate: '<S149>/Saturation' */

        /* Saturate: '<S161>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S161>/Saturation1' */

        /* Saturate: '<S139>/Saturation1' */
        if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S139>/Saturation1' */
        /* End of Outputs for SubSystem: '<S22>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S135>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S22>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S22>/Switch Case' */
      /* End of Outputs for SubSystem: '<S15>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S15>/Auto' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* SwitchCase: '<S20>/Switch Case' */
      switch (FMS_B.VehicleMode_e) {
       case VehicleMode_Offboard:
        /* Outputs for IfAction SubSystem: '<S20>/Offboard' incorporates:
         *  ActionPort: '<S129>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S129>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S129>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S129>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S20>/Offboard' */
        break;

       case VehicleMode_Mission:
        /* Outputs for IfAction SubSystem: '<S20>/Mission' incorporates:
         *  ActionPort: '<S128>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S128>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S128>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S128>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_b;

        /* End of Outputs for SubSystem: '<S20>/Mission' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S20>/Unknown' incorporates:
         *  ActionPort: '<S130>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S20>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S20>/Switch Case' */
      /* End of Outputs for SubSystem: '<S15>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S15>/Assist' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* SwitchCase: '<S19>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;
      switch (FMS_B.VehicleMode_e) {
       case VehicleMode_Acro:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleMode_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleMode_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       case VehicleMode_Position:
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
          /* Disable for SwitchCase: '<S115>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S34>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S91>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S67>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S78>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S19>/Acro' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S24>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S24>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Gain: '<S29>/Gain'
         *  Gain: '<S29>/Gain1'
         *  Gain: '<S29>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S30>/Saturation' incorporates:
         *  Constant: '<S30>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S30>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch_b_idx_1 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S30>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S24>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S30>/Constant5'
         *  Gain: '<S30>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S30>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_Switch_b_idx_1), 4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S19>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S19>/Stabilize' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S19>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S111>/Integrator'
           *  DiscreteIntegrator: '<S111>/Integrator1'
           *  DiscreteIntegrator: '<S112>/Integrator'
           *  DiscreteIntegrator: '<S112>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S19>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S19>/Stabilize' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S19>/Switch Case' incorporates:
           *  Chart: '<S116>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S19>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S19>/Stabilize' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Product: '<S113>/Multiply1' incorporates:
         *  Constant: '<S113>/const1'
         *  DiscreteIntegrator: '<S111>/Integrator'
         */
        rtb_Sum1 = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S109>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S109>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S113>/Add' incorporates:
         *  DiscreteIntegrator: '<S111>/Integrator1'
         *  Gain: '<S106>/Gain'
         *  Gain: '<S109>/Gain'
         *  Sum: '<S111>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Switch_b_idx_1 * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Sum1;

        /* Signum: '<S113>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Integrator1_a;
        }

        /* End of Signum: '<S113>/Sign' */

        /* Sum: '<S113>/Add2' incorporates:
         *  Abs: '<S113>/Abs'
         *  Gain: '<S113>/Gain'
         *  Gain: '<S113>/Gain1'
         *  Product: '<S113>/Multiply2'
         *  Product: '<S113>/Multiply3'
         *  Sqrt: '<S113>/Sqrt'
         *  Sum: '<S113>/Add1'
         *  Sum: '<S113>/Subtract'
         */
        rtb_Switch = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) + FMS_ConstB.d_d) *
                            FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Sqrt_d + rtb_Sum1;

        /* Sum: '<S113>/Add4' */
        rtb_Switch_b_idx_1 = (rtb_Integrator1_a - rtb_Switch) + rtb_Sum1;

        /* Sum: '<S113>/Add3' */
        rtb_Sqrt_d = rtb_Integrator1_a + FMS_ConstB.d_d;

        /* Sum: '<S113>/Subtract1' */
        rtb_Integrator1_a -= FMS_ConstB.d_d;

        /* Signum: '<S113>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S113>/Sign1' */

        /* Signum: '<S113>/Sign2' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S113>/Sign2' */

        /* Sum: '<S113>/Add5' incorporates:
         *  Gain: '<S113>/Gain2'
         *  Product: '<S113>/Multiply4'
         *  Sum: '<S113>/Subtract2'
         */
        rtb_Switch += (rtb_Sqrt_d - rtb_Integrator1_a) * 0.5F *
          rtb_Switch_b_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S116>/Motion State' incorporates:
         *  Abs: '<S116>/Abs'
         *  Abs: '<S116>/Abs1'
         *  Constant: '<S126>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S126>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S115>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S115>/Hold Control' incorporates:
             *  ActionPort: '<S118>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S115>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S115>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S115>/Hold Control' incorporates:
           *  ActionPort: '<S118>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S115>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S115>/Brake Control' incorporates:
           *  ActionPort: '<S117>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S115>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S115>/Move Control' incorporates:
             *  ActionPort: '<S119>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S115>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S115>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S115>/Move Control' incorporates:
           *  ActionPort: '<S119>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S115>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S115>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S27>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S111>/Integrator1'
         *  DiscreteIntegrator: '<S112>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S115>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
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
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S115>/Saturation' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Saturate: '<S108>/Saturation' incorporates:
         *  Constant: '<S108>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S108>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch_b_idx_1 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch_b_idx_1 = 0.0F;
        } else {
          rtb_Switch_b_idx_1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S108>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S108>/Constant5'
         *  Gain: '<S108>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S108>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_Switch_b_idx_1), 4.2949673E+9F) + 1000U;

        /* Product: '<S114>/Multiply1' incorporates:
         *  Constant: '<S114>/const1'
         *  DiscreteIntegrator: '<S112>/Integrator'
         */
        rtb_Integrator1_a = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S110>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S110>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S114>/Add' incorporates:
         *  DiscreteIntegrator: '<S112>/Integrator1'
         *  Gain: '<S106>/Gain1'
         *  Gain: '<S110>/Gain'
         *  Sum: '<S112>/Subtract'
         */
        rtb_Sum1 = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Switch_b_idx_1 * -FMS_PARAM.ROLL_PITCH_LIM)
          + rtb_Integrator1_a;

        /* Signum: '<S114>/Sign' */
        if (rtb_Sum1 < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Sum1 > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Sum1;
        }

        /* End of Signum: '<S114>/Sign' */

        /* Sum: '<S114>/Add2' incorporates:
         *  Abs: '<S114>/Abs'
         *  Gain: '<S114>/Gain'
         *  Gain: '<S114>/Gain1'
         *  Product: '<S114>/Multiply2'
         *  Product: '<S114>/Multiply3'
         *  Sqrt: '<S114>/Sqrt'
         *  Sum: '<S114>/Add1'
         *  Sum: '<S114>/Subtract'
         */
        rtb_Switch_b_idx_1 = (sqrtf((8.0F * fabsf(rtb_Sum1) + FMS_ConstB.d_o) *
          FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * rtb_Sqrt_d +
          rtb_Integrator1_a;

        /* Sum: '<S114>/Add4' */
        rtb_Integrator1_a += rtb_Sum1 - rtb_Switch_b_idx_1;

        /* Sum: '<S114>/Add3' */
        rtb_Sqrt_d = rtb_Sum1 + FMS_ConstB.d_o;

        /* Sum: '<S114>/Subtract1' */
        rtb_Sum1 -= FMS_ConstB.d_o;

        /* Signum: '<S114>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S114>/Sign1' */

        /* Signum: '<S114>/Sign2' */
        if (rtb_Sum1 < 0.0F) {
          rtb_Sum1 = -1.0F;
        } else {
          if (rtb_Sum1 > 0.0F) {
            rtb_Sum1 = 1.0F;
          }
        }

        /* End of Signum: '<S114>/Sign2' */

        /* Sum: '<S114>/Add5' incorporates:
         *  Gain: '<S114>/Gain2'
         *  Product: '<S114>/Multiply4'
         *  Sum: '<S114>/Subtract2'
         */
        rtb_Switch_b_idx_1 += (rtb_Sqrt_d - rtb_Sum1) * 0.5F * rtb_Integrator1_a;

        /* Update for DiscreteIntegrator: '<S111>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S111>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S113>/Add6' */
        rtb_Sqrt_d = rtb_Switch + FMS_ConstB.d_d;

        /* Sum: '<S113>/Subtract3' */
        rtb_Integrator1_a = rtb_Switch - FMS_ConstB.d_d;

        /* Signum: '<S113>/Sign5' */
        if (rtb_Switch < 0.0F) {
          rtb_Sum1 = -1.0F;
        } else if (rtb_Switch > 0.0F) {
          rtb_Sum1 = 1.0F;
        } else {
          rtb_Sum1 = rtb_Switch;
        }

        /* End of Signum: '<S113>/Sign5' */

        /* Signum: '<S113>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S113>/Sign3' */

        /* Signum: '<S113>/Sign4' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S113>/Sign4' */

        /* Signum: '<S113>/Sign6' */
        if (rtb_Switch < 0.0F) {
          rtb_MathFunction_hf_idx_1 = -1.0F;
        } else if (rtb_Switch > 0.0F) {
          rtb_MathFunction_hf_idx_1 = 1.0F;
        } else {
          rtb_MathFunction_hf_idx_1 = rtb_Switch;
        }

        /* End of Signum: '<S113>/Sign6' */

        /* Update for DiscreteIntegrator: '<S111>/Integrator' incorporates:
         *  Constant: '<S113>/const'
         *  Gain: '<S113>/Gain3'
         *  Product: '<S113>/Divide'
         *  Product: '<S113>/Multiply5'
         *  Product: '<S113>/Multiply6'
         *  Sum: '<S113>/Subtract4'
         *  Sum: '<S113>/Subtract5'
         *  Sum: '<S113>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Switch / FMS_ConstB.d_d - rtb_Sum1) *
          FMS_ConstB.Gain4_n * ((rtb_Sqrt_d - rtb_Integrator1_a) * 0.5F) -
          rtb_MathFunction_hf_idx_1 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S112>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S112>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S114>/Add6' */
        rtb_Sqrt_d = rtb_Switch_b_idx_1 + FMS_ConstB.d_o;

        /* Sum: '<S114>/Subtract3' */
        rtb_Integrator1_a = rtb_Switch_b_idx_1 - FMS_ConstB.d_o;

        /* Signum: '<S114>/Sign5' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch = 1.0F;
        } else {
          rtb_Switch = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S114>/Sign5' */

        /* Signum: '<S114>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S114>/Sign3' */

        /* Signum: '<S114>/Sign4' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S114>/Sign4' */

        /* Signum: '<S114>/Sign6' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Sum1 = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Sum1 = 1.0F;
        } else {
          rtb_Sum1 = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S114>/Sign6' */

        /* Update for DiscreteIntegrator: '<S112>/Integrator' incorporates:
         *  Constant: '<S114>/const'
         *  Gain: '<S114>/Gain3'
         *  Product: '<S114>/Divide'
         *  Product: '<S114>/Multiply5'
         *  Product: '<S114>/Multiply6'
         *  Sum: '<S114>/Subtract4'
         *  Sum: '<S114>/Subtract5'
         *  Sum: '<S114>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((rtb_Switch_b_idx_1 / FMS_ConstB.d_o -
          rtb_Switch) * FMS_ConstB.Gain4_n3 * ((rtb_Sqrt_d - rtb_Integrator1_a) *
          0.5F) - rtb_Sum1 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S19>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S19>/Altitude' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S19>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S47>/Integrator'
           *  DiscreteIntegrator: '<S47>/Integrator1'
           *  DiscreteIntegrator: '<S48>/Integrator'
           *  DiscreteIntegrator: '<S48>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S19>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S19>/Altitude' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S19>/Switch Case' incorporates:
           *  Chart: '<S35>/Motion Status'
           *  Chart: '<S52>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S19>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S19>/Altitude' incorporates:
         *  ActionPort: '<S25>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S35>/Motion Status' incorporates:
         *  Abs: '<S35>/Abs'
         *  Abs: '<S35>/Abs1'
         *  Constant: '<S43>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S43>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S34>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S34>/Hold Control' incorporates:
             *  ActionPort: '<S37>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S34>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S34>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S34>/Hold Control' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S34>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S34>/Brake Control' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S34>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S34>/Move Control' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S34>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S34>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S34>/Move Control' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S34>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S34>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S52>/Motion State' incorporates:
         *  Abs: '<S52>/Abs'
         *  Abs: '<S52>/Abs1'
         *  Constant: '<S62>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S62>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S51>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S51>/Hold Control' incorporates:
             *  ActionPort: '<S54>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S51>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S51>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S51>/Hold Control' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S51>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S51>/Brake Control' incorporates:
           *  ActionPort: '<S53>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S51>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S51>/Move Control' incorporates:
             *  ActionPort: '<S55>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S51>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S51>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S51>/Move Control' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S51>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S51>/Switch Case' */

        /* Product: '<S49>/Multiply1' incorporates:
         *  Constant: '<S49>/const1'
         *  DiscreteIntegrator: '<S47>/Integrator'
         */
        rtb_Sum1 = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S45>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S45>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S49>/Add' incorporates:
         *  DiscreteIntegrator: '<S47>/Integrator1'
         *  Gain: '<S32>/Gain'
         *  Gain: '<S45>/Gain'
         *  Sum: '<S47>/Subtract'
         */
        rtb_Switch = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Switch_b_idx_1 * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Sum1;

        /* Signum: '<S49>/Sign' */
        if (rtb_Switch < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else if (rtb_Switch > 0.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_Switch;
        }

        /* End of Signum: '<S49>/Sign' */

        /* Sum: '<S49>/Add2' incorporates:
         *  Abs: '<S49>/Abs'
         *  Gain: '<S49>/Gain'
         *  Gain: '<S49>/Gain1'
         *  Product: '<S49>/Multiply2'
         *  Product: '<S49>/Multiply3'
         *  Sqrt: '<S49>/Sqrt'
         *  Sum: '<S49>/Add1'
         *  Sum: '<S49>/Subtract'
         */
        rtb_MathFunction_hf_idx_1 = (sqrtf((8.0F * fabsf(rtb_Switch) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Sqrt_d +
          rtb_Sum1;

        /* Sum: '<S49>/Add4' */
        rtb_Switch_b_idx_1 = (rtb_Switch - rtb_MathFunction_hf_idx_1) + rtb_Sum1;

        /* Sum: '<S49>/Add3' */
        rtb_Sqrt_d = rtb_Switch + FMS_ConstB.d;

        /* Sum: '<S49>/Subtract1' */
        rtb_Switch -= FMS_ConstB.d;

        /* Signum: '<S49>/Sign1' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S49>/Sign1' */

        /* Signum: '<S49>/Sign2' */
        if (rtb_Switch < 0.0F) {
          rtb_Switch = -1.0F;
        } else {
          if (rtb_Switch > 0.0F) {
            rtb_Switch = 1.0F;
          }
        }

        /* End of Signum: '<S49>/Sign2' */

        /* Sum: '<S49>/Add5' incorporates:
         *  Gain: '<S49>/Gain2'
         *  Product: '<S49>/Multiply4'
         *  Sum: '<S49>/Subtract2'
         */
        rtb_MathFunction_hf_idx_1 += (rtb_Sqrt_d - rtb_Switch) * 0.5F *
          rtb_Switch_b_idx_1;

        /* Sum: '<S49>/Subtract3' */
        rtb_Sqrt_d = rtb_MathFunction_hf_idx_1 - FMS_ConstB.d;

        /* Sum: '<S49>/Add6' */
        rtb_Integrator1_a = rtb_MathFunction_hf_idx_1 + FMS_ConstB.d;

        /* Product: '<S49>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MathFunction_hf_idx_1 / FMS_ConstB.d;

        /* Signum: '<S49>/Sign5' incorporates:
         *  Signum: '<S49>/Sign6'
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

        /* End of Signum: '<S49>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S25>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S25>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S25>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S47>/Integrator1'
         *  DiscreteIntegrator: '<S48>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S51>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S25>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S25>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S25>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S51>/Saturation' */

        /* Saturate: '<S34>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S25>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S25>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S25>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S34>/Saturation1' */

        /* Product: '<S50>/Multiply1' incorporates:
         *  Constant: '<S50>/const1'
         *  DiscreteIntegrator: '<S48>/Integrator'
         */
        rtb_MathFunction_hf_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S46>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S46>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S50>/Add' incorporates:
         *  DiscreteIntegrator: '<S48>/Integrator1'
         *  Gain: '<S32>/Gain1'
         *  Gain: '<S46>/Gain'
         *  Sum: '<S48>/Subtract'
         */
        rtb_Sum1 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Switch_b_idx_1 * -FMS_PARAM.ROLL_PITCH_LIM)
          + rtb_MathFunction_hf_idx_1;

        /* Signum: '<S50>/Sign' */
        if (rtb_Sum1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else if (rtb_Sum1 > 0.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          rtb_Switch_b_idx_1 = rtb_Sum1;
        }

        /* End of Signum: '<S50>/Sign' */

        /* Sum: '<S50>/Add2' incorporates:
         *  Abs: '<S50>/Abs'
         *  Gain: '<S50>/Gain'
         *  Gain: '<S50>/Gain1'
         *  Product: '<S50>/Multiply2'
         *  Product: '<S50>/Multiply3'
         *  Sqrt: '<S50>/Sqrt'
         *  Sum: '<S50>/Add1'
         *  Sum: '<S50>/Subtract'
         */
        rtb_Switch_b_idx_1 = (sqrtf((8.0F * fabsf(rtb_Sum1) + FMS_ConstB.d_c) *
          FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * rtb_Switch_b_idx_1 +
          rtb_MathFunction_hf_idx_1;

        /* Sum: '<S50>/Add4' */
        rtb_MathFunction_hf_idx_1 += rtb_Sum1 - rtb_Switch_b_idx_1;

        /* Sum: '<S50>/Add3' */
        rtb_TmpSignalConversionAtMath_0 = rtb_Sum1 + FMS_ConstB.d_c;

        /* Sum: '<S50>/Subtract1' */
        rtb_Sum1 -= FMS_ConstB.d_c;

        /* Signum: '<S50>/Sign1' */
        if (rtb_TmpSignalConversionAtMath_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_0 > 0.0F) {
            rtb_TmpSignalConversionAtMath_0 = 1.0F;
          }
        }

        /* End of Signum: '<S50>/Sign1' */

        /* Signum: '<S50>/Sign2' */
        if (rtb_Sum1 < 0.0F) {
          rtb_Sum1 = -1.0F;
        } else {
          if (rtb_Sum1 > 0.0F) {
            rtb_Sum1 = 1.0F;
          }
        }

        /* End of Signum: '<S50>/Sign2' */

        /* Sum: '<S50>/Add5' incorporates:
         *  Gain: '<S50>/Gain2'
         *  Product: '<S50>/Multiply4'
         *  Sum: '<S50>/Subtract2'
         */
        rtb_Switch_b_idx_1 += (rtb_TmpSignalConversionAtMath_0 - rtb_Sum1) *
          0.5F * rtb_MathFunction_hf_idx_1;

        /* Update for DiscreteIntegrator: '<S47>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S47>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S49>/Sign3' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S49>/Sign3' */

        /* Signum: '<S49>/Sign4' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S49>/Sign4' */

        /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
         *  Constant: '<S49>/const'
         *  Gain: '<S49>/Gain3'
         *  Product: '<S49>/Multiply5'
         *  Product: '<S49>/Multiply6'
         *  Sum: '<S49>/Subtract4'
         *  Sum: '<S49>/Subtract5'
         *  Sum: '<S49>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_MathFunction_h_idx_0 -
          rtb_TmpSignalConversionAtMath_1) * FMS_ConstB.Gain4 *
          ((rtb_Integrator1_a - rtb_Sqrt_d) * 0.5F) - rtb_Switch * 12.566371F) *
          0.004F;

        /* Update for DiscreteIntegrator: '<S48>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S48>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S50>/Add6' */
        rtb_Sqrt_d = rtb_Switch_b_idx_1 + FMS_ConstB.d_c;

        /* Sum: '<S50>/Subtract3' */
        rtb_Integrator1_a = rtb_Switch_b_idx_1 - FMS_ConstB.d_c;

        /* Signum: '<S50>/Sign5' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch = 1.0F;
        } else {
          rtb_Switch = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S50>/Sign5' */

        /* Signum: '<S50>/Sign3' */
        if (rtb_Sqrt_d < 0.0F) {
          rtb_Sqrt_d = -1.0F;
        } else {
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }
        }

        /* End of Signum: '<S50>/Sign3' */

        /* Signum: '<S50>/Sign4' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S50>/Sign4' */

        /* Signum: '<S50>/Sign6' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Sum1 = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Sum1 = 1.0F;
        } else {
          rtb_Sum1 = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S50>/Sign6' */

        /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
         *  Constant: '<S50>/const'
         *  Gain: '<S50>/Gain3'
         *  Product: '<S50>/Divide'
         *  Product: '<S50>/Multiply5'
         *  Product: '<S50>/Multiply6'
         *  Sum: '<S50>/Subtract4'
         *  Sum: '<S50>/Subtract5'
         *  Sum: '<S50>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Switch_b_idx_1 / FMS_ConstB.d_c -
          rtb_Switch) * FMS_ConstB.Gain4_m * ((rtb_Sqrt_d - rtb_Integrator1_a) *
          0.5F) - rtb_Sum1 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S19>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S19>/Position' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S19>/Switch Case' incorporates:
           *  Chart: '<S68>/Motion Status'
           *  Chart: '<S79>/Motion State'
           *  Chart: '<S92>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S19>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S19>/Position' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S68>/Motion Status' incorporates:
         *  Abs: '<S68>/Abs'
         *  Abs: '<S68>/Abs1'
         *  Constant: '<S76>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S76>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S79>/Motion State' incorporates:
         *  Abs: '<S79>/Abs'
         *  Abs: '<S79>/Abs1'
         *  Constant: '<S89>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S89>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S92>/Logical Operator' incorporates:
         *  Abs: '<S92>/Abs1'
         *  Abs: '<S92>/Abs2'
         *  Constant: '<S103>/Constant'
         *  Constant: '<S104>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S103>/Compare'
         *  RelationalOperator: '<S104>/Compare'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtb_LogicalOperator_n = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S92>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S92>/Square'
         *  Math: '<S92>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S92>/Sqrt'
         *  Sum: '<S92>/Add'
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
              if (rtb_LogicalOperator_n) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_l = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_l = MotionState_Hold;
            if (rtb_LogicalOperator_n) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_l = MotionState_Move;
            }
            break;

           default:
            rtb_state_l = MotionState_Move;
            if (!rtb_LogicalOperator_n) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_l = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S92>/Motion State' */

        /* SwitchCase: '<S91>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S91>/Hold Control' incorporates:
             *  ActionPort: '<S94>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S91>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S91>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S91>/Hold Control' incorporates:
           *  ActionPort: '<S94>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_a, &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S91>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S91>/Brake Control' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S91>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S91>/Move Control' incorporates:
             *  ActionPort: '<S95>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S91>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S91>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S91>/Move Control' incorporates:
           *  ActionPort: '<S95>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S91>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S91>/Switch Case' */

        /* SwitchCase: '<S67>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S67>/Hold Control' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S67>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S67>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S67>/Hold Control' incorporates:
           *  ActionPort: '<S70>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S67>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S67>/Brake Control' incorporates:
           *  ActionPort: '<S69>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S67>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S67>/Move Control' incorporates:
             *  ActionPort: '<S71>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S67>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S67>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S67>/Move Control' incorporates:
           *  ActionPort: '<S71>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S67>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S67>/Switch Case' */

        /* SwitchCase: '<S78>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S78>/Hold Control' incorporates:
             *  ActionPort: '<S81>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S78>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S78>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S78>/Hold Control' incorporates:
           *  ActionPort: '<S81>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S78>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S78>/Brake Control' incorporates:
           *  ActionPort: '<S80>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S78>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S78>/Move Control' incorporates:
             *  ActionPort: '<S82>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S78>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S78>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S78>/Move Control' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S78>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S78>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S78>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S78>/Saturation' */

        /* Saturate: '<S91>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S91>/Saturation1' */

        /* Saturate: '<S67>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S26>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S67>/Saturation1' */
        /* End of Outputs for SubSystem: '<S19>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S19>/Unknown' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S19>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S19>/Switch Case' */
      /* End of Outputs for SubSystem: '<S15>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S15>/Manual' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S21>/Bus Assignment'
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S21>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S21>/Bus Assignment' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S21>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S15>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S15>/Unknown' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S15>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S15>/Switch Case' */
    /* End of Outputs for SubSystem: '<S2>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S18>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Sum: '<S7>/Sum' incorporates:
   *  Delay: '<S7>/Delay'
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/Auto_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  RelationalOperator: '<S9>/FixPt Relational Operator'
   *  UnitDelay: '<S10>/Delay Input1'
   *  UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.Delay_DSTATE_g = (int8_T)(((FMS_U.Auto_Cmd.cmd_1 !=
    FMS_DW.DelayInput1_DSTATE) + rtb_Saturation_g) + (FMS_U.Pilot_Cmd.cmd_1 !=
    FMS_DW.DelayInput1_DSTATE_m ? -1 : 0));

  /* Update for DiscreteIntegrator: '<S250>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S250>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In3'
   *  Sum: '<S250>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (FMS_U.INS_Out.ax -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (FMS_U.INS_Out.ay -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (FMS_U.INS_Out.az -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S251>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S251>/Gain'
   *  Sum: '<S251>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S9>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Auto_Cmd.cmd_1;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
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
    FMS_B.VehicleMode_e = VehicleMode_None;
    FMS_B.DataTypeConversion1 = PilotMode_None;
    FMS_B.safe_mode = PilotMode_None;
    FMS_B.Switch = CMD_None;
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
  /* Start for SwitchCase: '<S15>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S15>/SubMode' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S22>/Return' */
  /* Start for SwitchCase: '<S213>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S203>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S22>/Return' */

  /* Start for IfAction SubSystem: '<S22>/Hold' */
  /* Start for SwitchCase: '<S161>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S139>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S149>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S22>/Hold' */
  /* End of Start for SubSystem: '<S15>/SubMode' */

  /* Start for IfAction SubSystem: '<S15>/Assist' */
  /* Start for SwitchCase: '<S19>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S19>/Stabilize' */
  /* Start for SwitchCase: '<S115>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S19>/Stabilize' */

  /* Start for IfAction SubSystem: '<S19>/Altitude' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S51>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S19>/Altitude' */

  /* Start for IfAction SubSystem: '<S19>/Position' */
  /* Start for SwitchCase: '<S91>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S67>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S78>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S19>/Position' */
  /* End of Start for SubSystem: '<S15>/Assist' */
  /* End of Start for SubSystem: '<S2>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */

  /* InitializeConditions for DiscreteIntegrator: '<S250>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S251>/Discrete-Time Integrator5' */
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
  FMS_B.VehicleMode_e = VehicleMode_None;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S15>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Return' */
  /* InitializeConditions for Delay: '<S181>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S239>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S185>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S185>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S214>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S213>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S213>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S213>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S213>/Move Control' */

  /* SystemInitialize for Merge: '<S213>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S204>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S203>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S203>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S203>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S203>/Move Control' */

  /* SystemInitialize for Merge: '<S203>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S22>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Hold' */
  /* SystemInitialize for Chart: '<S140>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S150>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S162>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S161>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S161>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S161>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S161>/Move Control' */

  /* SystemInitialize for Merge: '<S161>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S139>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S139>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S139>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S139>/Move Control' */

  /* SystemInitialize for Merge: '<S139>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S149>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S149>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S149>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S149>/Move Control' */

  /* SystemInitialize for Merge: '<S149>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S22>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S15>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S15>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S19>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S111>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S112>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S112>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S116>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S115>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S115>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S115>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S115>/Move Control' */

  /* SystemInitialize for Merge: '<S115>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S19>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S19>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S47>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S35>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S34>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S34>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S34>/Move Control' */

  /* SystemInitialize for Chart: '<S52>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S51>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S51>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S51>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S51>/Move Control' */

  /* SystemInitialize for Merge: '<S34>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S51>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S19>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S19>/Position' */
  /* SystemInitialize for Chart: '<S68>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for Chart: '<S79>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S92>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S91>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S91>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S91>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S91>/Move Control' */

  /* SystemInitialize for Merge: '<S91>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S67>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S67>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S67>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S67>/Move Control' */

  /* SystemInitialize for Merge: '<S67>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S78>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S78>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S78>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S78>/Move Control' */

  /* SystemInitialize for Merge: '<S78>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S19>/Position' */
  /* End of SystemInitialize for SubSystem: '<S15>/Assist' */
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
