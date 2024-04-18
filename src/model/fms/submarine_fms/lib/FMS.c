/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2122
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 17 17:26:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S364>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S374>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S294>/Motion State' */
#define FMS_IN_Brake_o                 ((uint8_T)1U)
#define FMS_IN_Hold_d                  ((uint8_T)2U)
#define FMS_IN_Move_n                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Altitude                ((uint8_T)1U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)2U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Land_j                  ((uint8_T)3U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Loiter_p                ((uint8_T)4U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)5U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)3U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)6U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_SetSpeed                ((uint8_T)7U)
#define FMS_IN_Stabilize               ((uint8_T)4U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)8U)
#define FMS_IN_Waypoint                ((uint8_T)9U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude_e              ((uint8_T)2U)
#define FMS_IN_Manual_e                ((uint8_T)3U)
#define FMS_IN_Mission_g               ((uint8_T)4U)
#define FMS_IN_Offboard_p              ((uint8_T)5U)
#define FMS_IN_Other                   ((uint8_T)6U)
#define FMS_IN_Position_f              ((uint8_T)7U)
#define FMS_IN_Stabilize_j             ((uint8_T)8U)

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
  0.0F,                                /* ax_cmd */
  0.0F,                                /* ay_cmd */
  0.0F,                                /* az_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* throttle_cmd */
  0U,                                  /* cmd_mask */
  0U,                                  /* status */
  0U,                                  /* state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* mode */
  0U,                                  /* reset */
  0U,                                  /* wp_consume */
  0U,                                  /* wp_current */
  0U,                                  /* reserved */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  /* home */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_NBjn9jnE53XzbTzYqi5PkH FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  8.0F,
  2.5F,
  2.5F,
  1.04719758F,
  0.52359879F,
  15.0F,
  5.0F,
  5.0F,
  1.5F,
  1.0F,
  0.5F,
  0.3F,
  0.6F,
  120U,
  1U,
  1300U,
  8.0F,
  5.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S25>/Constant'
                                        *   '<S417>/Constant'
                                        *   '<S277>/L1'
                                        *   '<S43>/Gain'
                                        *   '<S43>/Gain1'
                                        *   '<S76>/Gain6'
                                        *   '<S77>/Gain6'
                                        *   '<S78>/Gain6'
                                        *   '<S82>/Gain6'
                                        *   '<S83>/Gain6'
                                        *   '<S84>/Gain6'
                                        *   '<S92>/L1'
                                        *   '<S173>/Saturation'
                                        *   '<S174>/Saturation1'
                                        *   '<S174>/Saturation2'
                                        *   '<S174>/Saturation3'
                                        *   '<S318>/Land_Speed'
                                        *   '<S319>/Saturation1'
                                        *   '<S405>/Takeoff_Speed'
                                        *   '<S406>/Gain2'
                                        *   '<S406>/Saturation1'
                                        *   '<S45>/Saturation1'
                                        *   '<S57>/Dead Zone'
                                        *   '<S57>/Gain'
                                        *   '<S58>/Dead Zone'
                                        *   '<S58>/Gain'
                                        *   '<S63>/Saturation'
                                        *   '<S79>/Dead Zone'
                                        *   '<S79>/Gain'
                                        *   '<S80>/Dead Zone'
                                        *   '<S80>/Gain'
                                        *   '<S81>/Dead Zone'
                                        *   '<S81>/Gain'
                                        *   '<S85>/Dead Zone'
                                        *   '<S85>/Gain'
                                        *   '<S86>/Dead Zone'
                                        *   '<S86>/Gain'
                                        *   '<S87>/Dead Zone'
                                        *   '<S87>/Gain'
                                        *   '<S227>/Gain2'
                                        *   '<S234>/Gain1'
                                        *   '<S234>/Gain2'
                                        *   '<S283>/Saturation1'
                                        *   '<S293>/Saturation'
                                        *   '<S305>/Saturation1'
                                        *   '<S320>/Constant'
                                        *   '<S323>/Gain2'
                                        *   '<S345>/Gain'
                                        *   '<S345>/Saturation1'
                                        *   '<S348>/Constant'
                                        *   '<S348>/vel'
                                        *   '<S348>/Switch'
                                        *   '<S48>/Gain2'
                                        *   '<S49>/Gain1'
                                        *   '<S55>/Constant'
                                        *   '<S66>/Gain2'
                                        *   '<S67>/Gain1'
                                        *   '<S74>/Constant'
                                        *   '<S111>/Gain'
                                        *   '<S111>/Saturation1'
                                        *   '<S114>/Constant'
                                        *   '<S114>/vel'
                                        *   '<S114>/Switch'
                                        *   '<S286>/Gain2'
                                        *   '<S287>/Gain1'
                                        *   '<S296>/Gain2'
                                        *   '<S297>/Gain1'
                                        *   '<S308>/Gain2'
                                        *   '<S309>/Gain6'
                                        *   '<S332>/Gain2'
                                        *   '<S332>/Saturation'
                                        *   '<S333>/Integrator'
                                        *   '<S51>/Land_Speed'
                                        *   '<S52>/Constant'
                                        *   '<S54>/Dead Zone'
                                        *   '<S54>/Gain'
                                        *   '<S71>/Dead Zone'
                                        *   '<S71>/Gain'
                                        *   '<S98>/Gain2'
                                        *   '<S98>/Saturation'
                                        *   '<S99>/Integrator'
                                        *   '<S289>/Dead Zone'
                                        *   '<S289>/Gain'
                                        *   '<S301>/Dead Zone'
                                        *   '<S301>/Gain'
                                        *   '<S313>/Dead Zone'
                                        *   '<S313>/Gain'
                                        *   '<S314>/Dead Zone'
                                        *   '<S314>/Gain'
                                        *   '<S363>/Saturation1'
                                        *   '<S373>/Saturation1'
                                        *   '<S129>/Saturation1'
                                        *   '<S139>/Saturation1'
                                        *   '<S366>/Gain2'
                                        *   '<S367>/Gain1'
                                        *   '<S376>/Gain2'
                                        *   '<S377>/Gain6'
                                        *   '<S132>/Gain2'
                                        *   '<S133>/Gain1'
                                        *   '<S142>/Gain2'
                                        *   '<S143>/Gain6'
                                        *   '<S369>/Dead Zone'
                                        *   '<S369>/Gain'
                                        *   '<S381>/Dead Zone'
                                        *   '<S381>/Gain'
                                        *   '<S382>/Dead Zone'
                                        *   '<S382>/Gain'
                                        *   '<S135>/Dead Zone'
                                        *   '<S135>/Gain'
                                        *   '<S147>/Dead Zone'
                                        *   '<S147>/Gain'
                                        *   '<S148>/Dead Zone'
                                        *   '<S148>/Gain'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT = {
  4U,

  { 83, 117, 98, 109, 97, 114, 105, 110, 101, 32, 70, 77, 83, 32, 118, 48, 46,
    48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S11>/Constant1'
                                        *   '<S415>/Constant'
                                        */

/* Block signals (default storage) */
B_FMS_T FMS_B;

/* Block states (default storage) */
DW_FMS_T FMS_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_FMS_T FMS_PrevZCX;

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
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_Mission(void);
static void FMS_exit_internal_Auto(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Auto(void);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static void FMS_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Vehicle(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * System initialize for action system:
 *    '<S363>/Hold Control'
 *    '<S283>/Hold Control'
 *    '<S129>/Hold Control'
 *    '<S45>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S366>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S363>/Hold Control'
 *    '<S283>/Hold Control'
 *    '<S129>/Hold Control'
 *    '<S45>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S366>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S363>/Hold Control'
 *    '<S283>/Hold Control'
 *    '<S129>/Hold Control'
 *    '<S45>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S366>/Delay' incorporates:
   *  Gain: '<S368>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S366>/Gain2' incorporates:
   *  Delay: '<S366>/Delay'
   *  Gain: '<S368>/Gain'
   *  Sum: '<S366>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S366>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S363>/Brake Control'
 *    '<S283>/Brake Control'
 *    '<S293>/Brake Control'
 *    '<S129>/Brake Control'
 *    '<S45>/Brake Control'
 *    '<S63>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S365>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S365>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S363>/Move Control'
 *    '<S283>/Move Control'
 *    '<S129>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S363>/Move Control'
 *    '<S283>/Move Control'
 *    '<S129>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S363>/Move Control'
 *    '<S283>/Move Control'
 *    '<S129>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_mj;
  real32_T rtb_Subtract3_k;
  real32_T rtb_a_g;
  real32_T rtb_Add4_k;
  real32_T rtb_a_m;

  /* Product: '<S371>/Multiply1' incorporates:
   *  Constant: '<S371>/const1'
   *  DiscreteIntegrator: '<S370>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S369>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S369>/Dead Zone' */

  /* Sum: '<S371>/Add' incorporates:
   *  DiscreteIntegrator: '<S370>/Integrator1'
   *  Gain: '<S367>/Gain1'
   *  Gain: '<S369>/Gain'
   *  Sum: '<S370>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S371>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S371>/Sign' */

  /* Sum: '<S371>/Add2' incorporates:
   *  Abs: '<S371>/Abs'
   *  Gain: '<S371>/Gain'
   *  Gain: '<S371>/Gain1'
   *  Product: '<S371>/Multiply2'
   *  Product: '<S371>/Multiply3'
   *  Sqrt: '<S371>/Sqrt'
   *  Sum: '<S371>/Add1'
   *  Sum: '<S371>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S371>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S371>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S371>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S371>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign1' */

  /* Signum: '<S371>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign2' */

  /* Sum: '<S371>/Add5' incorporates:
   *  Gain: '<S371>/Gain2'
   *  Product: '<S371>/Multiply4'
   *  Sum: '<S371>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S367>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S370>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S370>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S370>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S371>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S371>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S371>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S371>/Sign5' */

  /* Signum: '<S371>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign3' */

  /* Signum: '<S371>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign4' */

  /* Signum: '<S371>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S371>/Sign6' */

  /* Update for DiscreteIntegrator: '<S370>/Integrator' incorporates:
   *  Constant: '<S371>/const'
   *  Gain: '<S371>/Gain3'
   *  Product: '<S371>/Divide'
   *  Product: '<S371>/Multiply5'
   *  Product: '<S371>/Multiply6'
   *  Sum: '<S371>/Subtract4'
   *  Sum: '<S371>/Subtract5'
   *  Sum: '<S371>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S364>/Motion Status'
 *    '<S284>/Motion Status'
 *    '<S130>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S364>/Motion Status'
 *    '<S284>/Motion Status'
 *    '<S130>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S364>/Motion Status'
 *    '<S284>/Motion Status'
 *    '<S130>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S364>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c10_FMS == 0U) {
    localDW->is_active_c10_FMS = 1U;
    localDW->is_c10_FMS = FMS_IN_Move;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c10_FMS) {
     case FMS_IN_Brake:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c10_FMS = FMS_IN_Hold;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c10_FMS = FMS_IN_Move;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req == 1.0F) {
        localDW->is_c10_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (rtu_motion_req == 0.0F) {
        localDW->is_c10_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S364>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S373>/Hold Control'
 *    '<S305>/Hold Control'
 *    '<S139>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S376>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S373>/Hold Control'
 *    '<S305>/Hold Control'
 *    '<S139>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S376>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S373>/Hold Control'
 *    '<S305>/Hold Control'
 *    '<S139>/Hold Control'
 */
void FMS_HoldControl_m(real32_T rtu_FMS_In, real32_T rtu_FMS_In_o, real32_T
  rtu_FMS_In_f, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_f_T
  *localC, DW_HoldControl_FMS_j_T *localDW)
{
  real32_T rtb_VectorConcatenate_d4[9];
  real32_T rtb_VectorConcatenate_bg[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_bg_tmp;
  real32_T rtb_VectorConcatenate_bg_tmp_0;

  /* Delay: '<S376>/Delay' incorporates:
   *  SignalConversion: '<S376>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S380>/Trigonometric Function1' incorporates:
   *  Gain: '<S379>/Gain'
   *  Trigonometry: '<S380>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S380>/Trigonometric Function' incorporates:
   *  Gain: '<S379>/Gain'
   *  Trigonometry: '<S380>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S380>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S380>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S380>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S380>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S380>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S380>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S380>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S376>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S376>/Delay'
   *  SignalConversion: '<S376>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S376>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S376>/Multiply' incorporates:
   *  SignalConversion: '<S376>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S376>/Multiply' */

  /* Gain: '<S376>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S376>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S373>/Brake Control'
 *    '<S305>/Brake Control'
 *    '<S139>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S375>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for atomic system:
 *    '<S374>/Motion State'
 *    '<S306>/Motion State'
 *    '<S140>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S374>/Motion State'
 *    '<S306>/Motion State'
 *    '<S140>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S374>/Motion State'
 *    '<S306>/Motion State'
 *    '<S140>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S374>/Motion State' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c23_FMS == 0U) {
    localDW->is_active_c23_FMS = 1U;
    localDW->is_c23_FMS = FMS_IN_Move_o;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c23_FMS) {
     case FMS_IN_Brake_c:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.2) || (localDW->temporalCounter_i1 >= 625U)) {
        localDW->is_c23_FMS = FMS_IN_Hold_c;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c23_FMS = FMS_IN_Move_o;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_c:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req == 1.0F) {
        localDW->is_c23_FMS = FMS_IN_Move_o;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (rtu_motion_req == 0.0F) {
        localDW->is_c23_FMS = FMS_IN_Brake_c;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S374>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S350>/NearbyRefWP'
 *    '<S116>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S388>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_d;
  P3P2_idx_0 = sqrtf(P3P2_idx_0 * P3P2_idx_0 + P3P2_idx_1 * P3P2_idx_1);
  if (P3P2_idx_0 <= rtu_L1) {
    *rty_d = P3P2_idx_0;
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    *rty_d = -1.0F;
    rty_P[0] = 0.0F;
    rty_P[1] = 0.0F;
  }
}

/*
 * System initialize for action system:
 *    '<S293>/Hold Control'
 *    '<S63>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S296>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S293>/Hold Control'
 *    '<S63>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S296>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S293>/Hold Control'
 *    '<S63>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S296>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S296>/Sum' incorporates:
   *  Delay: '<S296>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S299>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S299>/Switch' incorporates:
   *  Constant: '<S299>/Constant'
   *  Constant: '<S300>/Constant'
   *  Product: '<S299>/Multiply'
   *  RelationalOperator: '<S300>/Compare'
   *  Sum: '<S299>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S299>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S299>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S299>/Switch' */

  /* Gain: '<S296>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S296>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S293>/Move Control'
 *    '<S63>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S302>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S302>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S293>/Move Control'
 *    '<S63>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S302>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S302>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S293>/Move Control'
 *    '<S63>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_ig;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_m;
  real32_T rtb_Add4_b;
  real32_T rtb_a_p4;

  /* Product: '<S303>/Multiply1' incorporates:
   *  Constant: '<S303>/const1'
   *  DiscreteIntegrator: '<S302>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S301>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S301>/Dead Zone' */

  /* Sum: '<S303>/Add' incorporates:
   *  DiscreteIntegrator: '<S302>/Integrator1'
   *  Gain: '<S297>/Gain1'
   *  Gain: '<S301>/Gain'
   *  Sum: '<S302>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S303>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_e;
  }

  /* End of Signum: '<S303>/Sign' */

  /* Sum: '<S303>/Add2' incorporates:
   *  Abs: '<S303>/Abs'
   *  Gain: '<S303>/Gain'
   *  Gain: '<S303>/Gain1'
   *  Product: '<S303>/Multiply2'
   *  Product: '<S303>/Multiply3'
   *  Sqrt: '<S303>/Sqrt'
   *  Sum: '<S303>/Add1'
   *  Sum: '<S303>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S303>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_e - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S303>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_e + localC->d;

  /* Sum: '<S303>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S303>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S303>/Sign1' */

  /* Signum: '<S303>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S303>/Sign2' */

  /* Sum: '<S303>/Add5' incorporates:
   *  Gain: '<S303>/Gain2'
   *  Product: '<S303>/Multiply4'
   *  Sum: '<S303>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_e) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S297>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S302>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S302>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S302>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S303>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S303>/Subtract3' */
  rtb_Subtract3_e = rtb_a_m - localC->d;

  /* Signum: '<S303>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S303>/Sign5' */

  /* Signum: '<S303>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S303>/Sign3' */

  /* Signum: '<S303>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S303>/Sign4' */

  /* Signum: '<S303>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S303>/Sign6' */

  /* Update for DiscreteIntegrator: '<S302>/Integrator' incorporates:
   *  Constant: '<S303>/const'
   *  Gain: '<S303>/Gain3'
   *  Product: '<S303>/Divide'
   *  Product: '<S303>/Multiply5'
   *  Product: '<S303>/Multiply6'
   *  Sum: '<S303>/Subtract4'
   *  Sum: '<S303>/Subtract5'
   *  Sum: '<S303>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_b) *
    localC->Gain4 * ((rtb_Add3_ig - rtb_Subtract3_e) * 0.5F) - rtb_a_p4 *
    15.707963F) * 0.004F;
}

/*
 * System initialize for action system:
 *    '<S305>/Move Control'
 *    '<S139>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_k_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S305>/Move Control'
 *    '<S139>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_k_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S305>/Move Control'
 *    '<S139>/Move Control'
 */
void FMS_MoveControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_f, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_o_T *localC,
  DW_MoveControl_FMS_k_T *localDW)
{
  real32_T rtb_Subtract3_n;
  real32_T rtb_Add3_k_idx_0;
  real32_T rtb_Subtract3_ln_idx_0;
  real32_T rtb_Add3_k_idx_1;
  real32_T rtb_Subtract3_ln_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_ln_idx_0_0;

  /* SignalConversion: '<S309>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S315>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S316>/Multiply1' incorporates:
   *  Constant: '<S316>/const1'
   *  DiscreteIntegrator: '<S315>/Integrator'
   */
  rtb_Add3_k_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S309>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S315>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S316>/Multiply1' incorporates:
   *  Constant: '<S316>/const1'
   *  DiscreteIntegrator: '<S315>/Integrator'
   */
  rtb_Add3_k_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S313>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_ln_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S313>/Dead Zone' */

  /* Sum: '<S316>/Add' incorporates:
   *  DiscreteIntegrator: '<S315>/Integrator1'
   *  Gain: '<S309>/Gain6'
   *  Gain: '<S313>/Gain'
   *  Sum: '<S315>/Subtract'
   */
  rtb_Subtract3_ln_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_ln_idx_1 * FMS_PARAM.VEL_X_LIM) +
    rtb_Add3_k_idx_0;

  /* DeadZone: '<S314>/Dead Zone' */
  if (rtu_FMS_In_f > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In_f - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_f >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_ln_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In_f - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S314>/Dead Zone' */

  /* Sum: '<S316>/Add' incorporates:
   *  DiscreteIntegrator: '<S315>/Integrator1'
   *  Gain: '<S309>/Gain6'
   *  Gain: '<S314>/Gain'
   *  Sum: '<S315>/Subtract'
   */
  rtb_Subtract3_ln_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_ln_idx_1 * FMS_PARAM.VEL_X_LIM) +
    rtb_Add3_k_idx_1;

  /* Signum: '<S316>/Sign' */
  if (rtb_Subtract3_ln_idx_0 < 0.0F) {
    rtb_Subtract3_ln_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0 > 0.0F) {
    rtb_Subtract3_ln_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_ln_idx_0_0 = rtb_Subtract3_ln_idx_0;
  }

  /* Sum: '<S316>/Add2' incorporates:
   *  Abs: '<S316>/Abs'
   *  Gain: '<S316>/Gain'
   *  Gain: '<S316>/Gain1'
   *  Product: '<S316>/Multiply2'
   *  Product: '<S316>/Multiply3'
   *  Signum: '<S316>/Sign'
   *  Sqrt: '<S316>/Sqrt'
   *  Sum: '<S316>/Add1'
   *  Sum: '<S316>/Subtract'
   */
  rtb_Subtract3_ln_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_ln_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_ln_idx_0_0 +
    rtb_Add3_k_idx_0;

  /* Sum: '<S316>/Add3' incorporates:
   *  Signum: '<S316>/Sign'
   */
  u = rtb_Subtract3_ln_idx_0 + localC->d;

  /* Sum: '<S316>/Subtract1' incorporates:
   *  Signum: '<S316>/Sign'
   */
  rtb_Subtract3_n = rtb_Subtract3_ln_idx_0 - localC->d;

  /* Signum: '<S316>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S316>/Sign2' */
  if (rtb_Subtract3_n < 0.0F) {
    rtb_Subtract3_n = -1.0F;
  } else {
    if (rtb_Subtract3_n > 0.0F) {
      rtb_Subtract3_n = 1.0F;
    }
  }

  /* Sum: '<S316>/Add5' incorporates:
   *  Gain: '<S316>/Gain2'
   *  Product: '<S316>/Multiply4'
   *  Signum: '<S316>/Sign'
   *  Sum: '<S316>/Add2'
   *  Sum: '<S316>/Add4'
   *  Sum: '<S316>/Subtract2'
   */
  rtb_Subtract3_ln_idx_0_0 += ((rtb_Subtract3_ln_idx_0 -
    rtb_Subtract3_ln_idx_0_0) + rtb_Add3_k_idx_0) * ((u - rtb_Subtract3_n) *
    0.5F);

  /* Update for DiscreteIntegrator: '<S315>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S315>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S316>/Sign3' incorporates:
   *  Sum: '<S316>/Add6'
   */
  u = rtb_Subtract3_ln_idx_0_0 + localC->d;

  /* Signum: '<S316>/Sign4' incorporates:
   *  Sum: '<S316>/Subtract3'
   */
  rtb_Add3_k_idx_0 = rtb_Subtract3_ln_idx_0_0 - localC->d;

  /* Signum: '<S316>/Sign5' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_ln_idx_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_ln_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_ln_idx_0 = rtb_Subtract3_ln_idx_0_0;
  }

  /* Signum: '<S316>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S316>/Sign4' */
  if (rtb_Add3_k_idx_0 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_k_idx_0 > 0.0F) {
      rtb_Add3_k_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S316>/Sign6' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_n = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_n = 1.0F;
  } else {
    rtb_Subtract3_n = rtb_Subtract3_ln_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S315>/Integrator' incorporates:
   *  Constant: '<S316>/const'
   *  Gain: '<S316>/Gain3'
   *  Product: '<S316>/Divide'
   *  Product: '<S316>/Multiply5'
   *  Product: '<S316>/Multiply6'
   *  Sum: '<S316>/Subtract4'
   *  Sum: '<S316>/Subtract5'
   *  Sum: '<S316>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_ln_idx_0_0 / localC->d -
    rtb_Subtract3_ln_idx_0) * localC->Gain4 * ((u - rtb_Add3_k_idx_0) * 0.5F) -
    rtb_Subtract3_n * 58.836F) * 0.004F;

  /* Signum: '<S316>/Sign' */
  if (rtb_Subtract3_ln_idx_1 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_1 > 0.0F) {
    rtb_Add3_k_idx_0 = 1.0F;
  } else {
    rtb_Add3_k_idx_0 = rtb_Subtract3_ln_idx_1;
  }

  /* Sum: '<S316>/Add2' incorporates:
   *  Abs: '<S316>/Abs'
   *  Gain: '<S316>/Gain'
   *  Gain: '<S316>/Gain1'
   *  Product: '<S316>/Multiply2'
   *  Product: '<S316>/Multiply3'
   *  Signum: '<S316>/Sign'
   *  Sqrt: '<S316>/Sqrt'
   *  Sum: '<S316>/Add1'
   *  Sum: '<S316>/Subtract'
   */
  rtb_Subtract3_ln_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_ln_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_k_idx_0 +
    rtb_Add3_k_idx_1;

  /* Sum: '<S316>/Add3' incorporates:
   *  Signum: '<S316>/Sign'
   */
  u = rtb_Subtract3_ln_idx_1 + localC->d;

  /* Sum: '<S316>/Subtract1' incorporates:
   *  Signum: '<S316>/Sign'
   */
  rtb_Subtract3_n = rtb_Subtract3_ln_idx_1 - localC->d;

  /* Signum: '<S316>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S316>/Sign2' */
  if (rtb_Subtract3_n < 0.0F) {
    rtb_Subtract3_n = -1.0F;
  } else {
    if (rtb_Subtract3_n > 0.0F) {
      rtb_Subtract3_n = 1.0F;
    }
  }

  /* Sum: '<S316>/Add5' incorporates:
   *  Gain: '<S316>/Gain2'
   *  Product: '<S316>/Multiply4'
   *  Signum: '<S316>/Sign'
   *  Sum: '<S316>/Add2'
   *  Sum: '<S316>/Add4'
   *  Sum: '<S316>/Subtract2'
   */
  rtb_Subtract3_ln_idx_0_0 += ((rtb_Subtract3_ln_idx_1 -
    rtb_Subtract3_ln_idx_0_0) + rtb_Add3_k_idx_1) * ((u - rtb_Subtract3_n) *
    0.5F);

  /* Update for DiscreteIntegrator: '<S315>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S315>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S316>/Sign3' incorporates:
   *  Sum: '<S316>/Add6'
   */
  u = rtb_Subtract3_ln_idx_0_0 + localC->d;

  /* Signum: '<S316>/Sign4' incorporates:
   *  Sum: '<S316>/Subtract3'
   */
  rtb_Add3_k_idx_0 = rtb_Subtract3_ln_idx_0_0 - localC->d;

  /* Signum: '<S316>/Sign5' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_ln_idx_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_ln_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_ln_idx_0 = rtb_Subtract3_ln_idx_0_0;
  }

  /* Signum: '<S316>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S316>/Sign4' */
  if (rtb_Add3_k_idx_0 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_k_idx_0 > 0.0F) {
      rtb_Add3_k_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S316>/Sign6' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_n = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_n = 1.0F;
  } else {
    rtb_Subtract3_n = rtb_Subtract3_ln_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S315>/Integrator' incorporates:
   *  Constant: '<S316>/const'
   *  Gain: '<S316>/Gain3'
   *  Product: '<S316>/Divide'
   *  Product: '<S316>/Multiply5'
   *  Product: '<S316>/Multiply6'
   *  Sum: '<S316>/Subtract4'
   *  Sum: '<S316>/Subtract5'
   *  Sum: '<S316>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_ln_idx_0_0 / localC->d -
    rtb_Subtract3_ln_idx_0) * localC->Gain4 * ((u - rtb_Add3_k_idx_0) * 0.5F) -
    rtb_Subtract3_n * 58.836F) * 0.004F;
}

/*
 * Output and update for action system:
 *    '<S36>/Unknown'
 *    '<S34>/Unknown'
 *    '<S33>/Unknown'
 *    '<S29>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S279>/Bus Assignment' incorporates:
   *  Constant: '<S279>/Constant'
   *  Constant: '<S279>/Constant2'
   *  SignalConversion: '<S279>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S279>/Bus Assignment' */
}

real_T rt_modd(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u0 == 0.0) {
    y = 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Output and update for function-call system: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
void F_VehicleArmAutoMissionLLA2FLAT(const real_T rtu_lla[3], const real_T
  rtu_llo[2], real_T rtu_href, real_T rtu_psio, real32_T rty_pos[3], const
  ConstB_VehicleArmAutoMissionL_T *localC)
{
  real_T rtb_Sum2_ee;
  real_T rtb_Gain_d;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S419>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S420>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S420>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S420>/Multiply1' incorporates:
   *  Product: '<S420>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S420>/Divide' incorporates:
   *  Constant: '<S420>/Constant'
   *  Constant: '<S420>/R'
   *  Sqrt: '<S420>/Sqrt'
   *  Sum: '<S420>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S420>/Product3' incorporates:
   *  Constant: '<S420>/Constant1'
   *  Product: '<S420>/Multiply1'
   *  Sum: '<S420>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S420>/Multiply2' incorporates:
   *  Trigonometry: '<S420>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S419>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S424>/Abs' incorporates:
   *  Abs: '<S427>/Abs1'
   *  Switch: '<S424>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S424>/Switch1' incorporates:
   *  Abs: '<S424>/Abs'
   *  Bias: '<S424>/Bias2'
   *  Bias: '<S424>/Bias3'
   *  Constant: '<S421>/Constant'
   *  Constant: '<S421>/Constant1'
   *  Constant: '<S426>/Constant'
   *  Gain: '<S424>/Gain1'
   *  Product: '<S424>/Multiply'
   *  RelationalOperator: '<S426>/Compare'
   *  Switch: '<S421>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S427>/Switch1' incorporates:
     *  Bias: '<S427>/Bias2'
     *  Bias: '<S427>/Bias3'
     *  Constant: '<S427>/Constant'
     *  Constant: '<S428>/Constant'
     *  Math: '<S427>/Math Function'
     *  RelationalOperator: '<S428>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S427>/Switch1' */

    /* Signum: '<S424>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S424>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S421>/Sum' incorporates:
   *  Sum: '<S419>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S419>/Multiply' incorporates:
   *  Gain: '<S419>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S423>/Switch1' incorporates:
   *  Abs: '<S423>/Abs1'
   *  Bias: '<S423>/Bias2'
   *  Bias: '<S423>/Bias3'
   *  Constant: '<S423>/Constant'
   *  Constant: '<S425>/Constant'
   *  Math: '<S423>/Math Function'
   *  RelationalOperator: '<S425>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S423>/Switch1' */

  /* Product: '<S419>/Multiply' incorporates:
   *  Gain: '<S419>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S419>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S422>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S422>/Sum2' incorporates:
   *  Product: '<S422>/Multiply1'
   *  Product: '<S422>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S422>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S422>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S422>/Sum3' */
  rtb_Sum3_l = rtb_Gain_d - rtb_Sum3_l;

  /* DataTypeConversion: '<S416>/Data Type Conversion' incorporates:
   *  Gain: '<S419>/Gain'
   *  Sum: '<S419>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_ee;
  rty_pos[1] = (real32_T)rtb_Sum3_l;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Stabilize(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Stabilize;

    /* Delay: '<S13>/Delay' */
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S13>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Acro;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Acro(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Acro;

    /* Delay: '<S13>/Delay' */
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S13>/Delay' */
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_b, &FMS_DW.M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag)
{
  boolean_T valid;
  valid = false;
  if (!(mode_in == PilotMode_None)) {
    switch (cmd_in) {
     case FMS_Cmd_Takeoff:
     case FMS_Cmd_Land:
     case FMS_Cmd_Return:
     case FMS_Cmd_Pause:
      if (((ins_flag & 1U) != 0U) && ((ins_flag & 4U) != 0U) && ((ins_flag & 8U)
           != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) &&
          ((ins_flag & 128U) != 0U)) {
        valid = true;
      }
      break;

     case FMS_Cmd_PreArm:
      if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag & 8U)
           == 0U)) {
      } else {
        switch (mode_in) {
         case PilotMode_Position:
         case PilotMode_Mission:
         case PilotMode_Offboard:
          if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag
                & 128U) != 0U)) {
            valid = true;
          }
          break;

         case PilotMode_Altitude:
          if ((ins_flag & 128U) != 0U) {
            valid = true;
          }
          break;

         case PilotMode_Stabilize:
          valid = true;
          break;
        }
      }
      break;

     case FMS_Cmd_Continue:
      if ((mode_in == PilotMode_Offboard) || (mode_in == PilotMode_Mission)) {
        valid = true;
      }
      break;

     case FMS_Cmd_Disarm:
      valid = true;
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_b, &FMS_DW.Msg_FMS_Cmd_i
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_i[0] : NULL;
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
static real32_T FMS_norm(const real32_T x[2])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = fabsf(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = fabsf(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrtf(y);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Mission(void)
{
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_DW.is_Mission = FMS_IN_NextWP;

    /* Inport: '<Root>/Mission_Data' */
    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
    } else {
      FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
      qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
      if (qY > FMS_B.wp_index) {
        qY = 0U;
      }

      FMS_B.wp_consume = (uint8_T)qY;
    }
  } else {
    switch (FMS_DW.is_Mission) {
     case FMS_IN_Disarming:
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Vehicle = FMS_IN_Disarm;
      FMS_B.state = VehicleState_Disarm;
      break;

     case FMS_IN_Hold_d:
      /* Inport: '<Root>/Mission_Data' */
      if (FMS_DW.temporalCounter_i1 >= FMS_U.Mission_Data.param1[FMS_B.wp_index
          - 1] * 250.0F) {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Mission = FMS_IN_NextWP;
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY > FMS_B.wp_index) {
            qY = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY;
        }
      }
      break;

     case FMS_IN_Land_j:
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1 = false;
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1 >=
          500) {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Mission = FMS_IN_NextWP;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY > FMS_B.wp_index) {
            qY = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY;
        }
      }
      break;

     case FMS_IN_Loiter_p:
      break;

     case FMS_IN_NextWP:
      if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Takeoff) {
        FMS_DW.is_Mission = FMS_IN_Takeoff_d;

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] + FMS_DW.home
                         [2]);
        FMS_B.llo[0] = FMS_DW.llo[0];
        FMS_B.llo[1] = FMS_DW.llo[1];
        FMS_B.href = 0.0;
        FMS_B.psio = 0.0;

        /* Outputs for Function Call SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
          FMS_B.psio, FMS_B.DataTypeConversion,
          &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

        /* End of Outputs for SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
        FMS_B.state = VehicleState_Takeoff;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
        FMS_DW.is_Mission = FMS_IN_Waypoint;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] + FMS_DW.home
                         [2]);
        FMS_B.llo[0] = FMS_DW.llo[0];
        FMS_B.llo[1] = FMS_DW.llo[1];
        FMS_B.href = 0.0;
        FMS_B.psio = 0.0;

        /* Outputs for Function Call SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
          FMS_B.psio, FMS_B.DataTypeConversion,
          &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

        /* End of Outputs for SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
        FMS_B.state = VehicleState_Mission;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_SetSpeed) {
        FMS_DW.is_Mission = FMS_IN_SetSpeed;

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.Cmd_In.set_speed = FMS_U.Mission_Data.param2[FMS_B.wp_index - 1];
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_Mission = FMS_IN_Land_j;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
        FMS_B.state = VehicleState_Land;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
        FMS_DW.is_Mission = FMS_IN_Return_h;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.state = VehicleState_Return;
      } else {
        FMS_DW.is_Mission = FMS_IN_Loiter_p;
        FMS_B.state = VehicleState_Hold;
      }
      break;

     case FMS_IN_Return_h:
      tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];
      if (FMS_norm(tmp) < 0.5F) {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_Mission = FMS_IN_Land_j;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
        FMS_B.state = VehicleState_Land;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
      }
      break;

     case FMS_IN_SetSpeed:
      tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
      if ((uint32_T)tmp_0 > 255U) {
        tmp_0 = 255;
      }

      FMS_B.wp_index = (uint8_T)tmp_0;
      FMS_DW.is_Mission = FMS_IN_NextWP;

      /* Inport: '<Root>/Mission_Data' */
      if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
        FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
      } else {
        FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
        qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
        if (qY > FMS_B.wp_index) {
          qY = 0U;
        }

        FMS_B.wp_consume = (uint8_T)qY;
      }
      break;

     case FMS_IN_Takeoff_d:
      if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >= FMS_B.Cmd_In.sp_waypoint
          [2]) {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Mission = FMS_IN_NextWP;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY > FMS_B.wp_index) {
            qY = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY;
        }
      }
      break;

     case FMS_IN_Waypoint:
      tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];

      /* Constant: '<Root>/ACCEPT_R' */
      if (FMS_norm(tmp) <= FMS_PARAM.ACCEPT_R) {
        FMS_B.Cmd_In.set_speed = 0.0F;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] > 0.0F) {
          FMS_DW.is_Mission = FMS_IN_Hold_d;
          FMS_DW.temporalCounter_i1 = 0U;
          FMS_B.state = VehicleState_Hold;
        } else {
          tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          FMS_B.wp_index = (uint8_T)tmp_0;
          FMS_DW.is_Mission = FMS_IN_NextWP;
          if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
            FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
          } else {
            FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
            qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
            if (qY > FMS_B.wp_index) {
              qY = 0U;
            }

            FMS_B.wp_consume = (uint8_T)qY;
          }
        }
      }

      /* End of Constant: '<Root>/ACCEPT_R' */
      break;
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Auto(void)
{
  if (FMS_DW.is_Auto == FMS_IN_Mission) {
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_h;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
  } else {
    FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_h;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
  }
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
static void FMS_enter_internal_Auto(void)
{
  uint32_T qY;
  switch (FMS_B.target_mode) {
   case PilotMode_Offboard:
    FMS_DW.is_Auto = FMS_IN_Offboard;
    FMS_B.Cmd_In.offboard_psi_0 = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
    if (FMS_B.LogicalOperator) {
      FMS_DW.is_Offboard = FMS_IN_Run;
      FMS_B.state = VehicleState_Offboard;
    } else {
      FMS_DW.is_Offboard = FMS_IN_Loiter;
      FMS_B.state = VehicleState_Hold;
    }
    break;

   case PilotMode_Mission:
    FMS_DW.is_Auto = FMS_IN_Mission;
    FMS_DW.llo[0] = FMS_B.BusConversion_InsertedFor_FMSSt.lat_0 *
      57.295779513082323;
    FMS_DW.llo[1] = FMS_B.BusConversion_InsertedFor_FMSSt.lon_0 *
      57.295779513082323;
    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
    FMS_B.Cmd_In.set_speed = 0.0F;
    FMS_DW.is_Mission = FMS_IN_NextWP;

    /* Inport: '<Root>/Mission_Data' */
    if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
    } else {
      FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
      qY = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
      if (qY > FMS_B.wp_index) {
        qY = 0U;
      }

      FMS_B.wp_consume = (uint8_T)qY;
    }

    /* End of Inport: '<Root>/Mission_Data' */
    break;

   default:
    FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
    break;
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

  /* Outputs for Function Call SubSystem: '<S5>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S429>/Compare' incorporates:
   *  Abs: '<S418>/Abs'
   *  Constant: '<S429>/Constant'
   *  MinMax: '<S418>/Max'
   *  Sum: '<S418>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S5>/Vehicle.StickMoved' */
  if ((FMS_B.Compare_k || ((FMS_B.BusConversion_InsertedFor_FMSSt.flag & 212U)
        != 212U)) && (FMS_B.target_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.target_mode) {
       case PilotMode_Stabilize:
        FMS_DW.is_Assist = FMS_IN_Stabilize;
        FMS_B.state = VehicleState_Stabilize;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_Assist = FMS_IN_Altitude;
        FMS_B.state = VehicleState_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_Assist = FMS_IN_Position;
        FMS_B.state = VehicleState_Position;
        break;

       default:
        FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
        break;
      }
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Manual;
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_DW.is_SubMode = FMS_IN_Hold_h;
      FMS_B.state = VehicleState_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold_h:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = ((FMS_DW.M_msgReservedData ==
            FMS_Cmd_Continue) && (FMS_B.target_mode != PilotMode_None));
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
          tmp = FMS_getArmMode(FMS_B.target_mode);
          if (tmp == 3.0) {
            FMS_DW.is_Arm = FMS_IN_Auto;
            FMS_enter_internal_Auto();
          } else if (tmp == 2.0) {
            FMS_DW.is_Arm = FMS_IN_Assist;
            switch (FMS_B.target_mode) {
             case PilotMode_Stabilize:
              FMS_DW.is_Assist = FMS_IN_Stabilize;
              FMS_B.state = VehicleState_Stabilize;
              break;

             case PilotMode_Altitude:
              FMS_DW.is_Assist = FMS_IN_Altitude;
              FMS_B.state = VehicleState_Altitude;
              break;

             case PilotMode_Position:
              FMS_DW.is_Assist = FMS_IN_Position;
              FMS_B.state = VehicleState_Position;
              break;

             default:
              FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
              break;
            }
          } else if (tmp == 1.0) {
            FMS_DW.is_Arm = FMS_IN_Manual;
            FMS_DW.is_Manual = FMS_IN_InValidManualMode;
          } else {
            FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
          }
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_k >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
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

        /* Constant: '<Root>/ACCEPT_R' */
        if (y <= FMS_PARAM.ACCEPT_R) {
          FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
          FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Auto;
              FMS_enter_internal_Auto();
            } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Assist;
              switch (FMS_B.target_mode) {
               case PilotMode_Stabilize:
                FMS_DW.is_Assist = FMS_IN_Stabilize;
                FMS_B.state = VehicleState_Stabilize;
                break;

               case PilotMode_Altitude:
                FMS_DW.is_Assist = FMS_IN_Altitude;
                FMS_B.state = VehicleState_Altitude;
                break;

               case PilotMode_Position:
                FMS_DW.is_Assist = FMS_IN_Position;
                FMS_B.state = VehicleState_Position;
                break;

               default:
                FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
                break;
              }
            } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Manual;
              FMS_DW.is_Manual = FMS_IN_InValidManualMode;
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_B.state = VehicleState_Hold;
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
  if (FMS_DW.is_Arm == FMS_IN_Auto) {
    FMS_exit_internal_Auto();
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real_T tmp;
  FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_n5 >=
       500) && (FMS_B.target_mode != PilotMode_Mission)) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
              PilotMode_None)) {
    tmp = FMS_getArmMode(FMS_B.target_mode);
    if (tmp == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp == 2.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Assist;
      switch (FMS_B.target_mode) {
       case PilotMode_Stabilize:
        FMS_DW.is_Assist = FMS_IN_Stabilize;
        FMS_B.state = VehicleState_Stabilize;
        break;

       case PilotMode_Altitude:
        FMS_DW.is_Assist = FMS_IN_Altitude;
        FMS_B.state = VehicleState_Altitude;
        break;

       case PilotMode_Position:
        FMS_DW.is_Assist = FMS_IN_Position;
        FMS_B.state = VehicleState_Position;
        break;

       default:
        FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
        break;
      }
    } else if (tmp == 1.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Manual;
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
    } else {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Land);
    } else {
      c_sf_internal_predicateOutput = false;
    }

    if (c_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.state = VehicleState_Land;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
    } else {
      if (FMS_sf_msg_pop_M()) {
        c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_Return);
      } else {
        c_sf_internal_predicateOutput = false;
      }

      if (c_sf_internal_predicateOutput) {
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_SubMode;
        FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
        FMS_DW.stick_val[1] =
          FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
        FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
        FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
        FMS_DW.is_SubMode = FMS_IN_Return;
        FMS_B.state = VehicleState_Return;
      } else {
        switch (FMS_DW.is_Arm) {
         case FMS_IN_Assist:
          if (FMS_B.Compare && ((int32_T)
                                (FMS_B.BusConversion_InsertedFor_FMSSt.flag &
                                 212U) == 212)) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Vehicle = FMS_IN_Arm;
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_B.state = VehicleState_Hold;
          } else {
            if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
              FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
            }
          }
          break;

         case FMS_IN_Auto:
          if (FMS_sf_msg_pop_M()) {
            c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            c_sf_internal_predicateOutput = false;
          }

          if (c_sf_internal_predicateOutput) {
            FMS_exit_internal_Auto();
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_B.state = VehicleState_Hold;
          } else {
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
              break;

             case FMS_IN_Mission:
              FMS_Mission();
              break;

             case FMS_IN_Offboard:
              switch (FMS_DW.is_Offboard) {
               case FMS_IN_Loiter:
                if (FMS_B.LogicalOperator) {
                  FMS_DW.is_Offboard = FMS_IN_Run;
                  FMS_B.state = VehicleState_Offboard;
                }
                break;

               case FMS_IN_Run:
                if (!FMS_B.LogicalOperator) {
                  FMS_DW.is_Offboard = FMS_IN_Loiter;
                  FMS_B.state = VehicleState_Hold;
                }
                break;
              }
              break;
            }
          }
          break;

         case FMS_IN_InvalidArmMode:
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
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
  int32_T b_previousEvent;
  int32_T tmp;
  real_T tmp_0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_B.wp_consume = 0U;
    FMS_B.wp_index = 1U;
  }

  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Disarm);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_exit_internal_Arm();
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
        FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
      break;
    }

    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      FMS_Arm();
      break;

     case FMS_IN_Disarm:
      if (FMS_sf_msg_pop_M()) {
        sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_PreArm);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        guard1 = true;
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Takeoff);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_DW.prep_takeoff = 1.0;
          sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
            FMS_DW.durationLastReferenceTick_1_n =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
          guard1 = true;
        }
      }
      break;

     case FMS_IN_Standby:
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.target_mode != PilotMode_None)) {
        guard2 = true;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_n >= 500) {
          guard3 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Takeoff);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            guard3 = true;
          } else if ((FMS_DW.temporalCounter_i1 >= 2500U) || (FMS_DW.sfEvent ==
                      FMS_event_DisarmEvent)) {
            FMS_DW.prep_takeoff = 0.0;
            sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
            if ((!sf_internal_predicateOutput) ||
                (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
              FMS_DW.durationLastReferenceTick_1_n =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
            FMS_DW.prep_mission_takeoff = 0.0;
            sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
            if ((!sf_internal_predicateOutput) ||
                (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
          } else {
            sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
            if ((!sf_internal_predicateOutput) ||
                (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
              FMS_DW.durationLastReferenceTick_2 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
            if ((FMS_DW.chartAbsoluteTimeCounter -
                 FMS_DW.durationLastReferenceTick_2 >= 500) ||
                ((FMS_B.target_mode == PilotMode_Offboard) &&
                 FMS_B.LogicalOperator)) {
              guard2 = true;
            }
          }
        }
      }
      break;
    }

    if (guard3) {
      FMS_B.xy_R[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.xy_R[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;

      /* Outputs for Function Call SubSystem: '<S5>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S417>/Reshape' incorporates:
       *  Constant: '<S417>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S5>/Vehicle.PrepTakeoff' */
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.Reshape[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.Reshape[1];
      FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.Reshape[2];
      FMS_B.Cmd_In.sp_waypoint[2] += FMS_DW.home[2];
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
        FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Takeoff;
      FMS_B.state = VehicleState_Takeoff;
    }

    if (guard2) {
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
        FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
      tmp_0 = FMS_getArmMode(FMS_B.target_mode);
      if (tmp_0 == 3.0) {
        FMS_DW.is_Arm = FMS_IN_Auto;
        FMS_enter_internal_Auto();
      } else if (tmp_0 == 2.0) {
        FMS_DW.is_Arm = FMS_IN_Assist;
        switch (FMS_B.target_mode) {
         case PilotMode_Stabilize:
          FMS_DW.is_Assist = FMS_IN_Stabilize;
          FMS_B.state = VehicleState_Stabilize;
          break;

         case PilotMode_Altitude:
          FMS_DW.is_Assist = FMS_IN_Altitude;
          FMS_B.state = VehicleState_Altitude;
          break;

         case PilotMode_Position:
          FMS_DW.is_Assist = FMS_IN_Position;
          FMS_B.state = VehicleState_Position;
          break;

         default:
          FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
          break;
        }
      } else if (tmp_0 == 1.0) {
        FMS_DW.is_Arm = FMS_IN_Manual;
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      } else {
        FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
      }
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          guard6 = true;
        } else {
          b_previousEvent = (int32_T)(FMS_B.wp_index + 1U);
          tmp = b_previousEvent;
          if ((uint32_T)b_previousEvent > 255U) {
            tmp = 255;
          }

          if ((tmp <= FMS_U.Mission_Data.valid_items) &&
              (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
               NAV_Cmd_SetSpeed)) {
            if ((uint32_T)b_previousEvent > 255U) {
              b_previousEvent = 255;
            }

            if (FMS_U.Mission_Data.command[b_previousEvent - 1] == (int32_T)
                NAV_Cmd_Takeoff) {
              guard6 = true;
            } else {
              guard5 = true;
            }
          } else {
            guard5 = true;
          }
        }
      } else {
        guard4 = true;
      }

      if (guard6) {
        FMS_DW.prep_mission_takeoff = 1.0;
        FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff == 1.0);
        FMS_DW.prep_takeoff = 0.0;
        FMS_DW.condWasTrueAtLastTimeStep_1_b = (FMS_DW.prep_takeoff == 1.0);
        guard4 = true;
      }

      if (guard5) {
        b_previousEvent = FMS_DW.sfEvent;
        FMS_DW.sfEvent = FMS_event_DisarmEvent;

        /* Chart: '<Root>/FMS State Machine' */
        FMS_c11_FMS();
        FMS_DW.sfEvent = b_previousEvent;
        if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
        } else {
          guard4 = true;
        }
      }

      if (guard4) {
        FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
        FMS_B.state = VehicleState_Standby;
      }

      if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
        sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      }
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_c11_FMS(void)
{
  int32_T b_previousEvent;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  if (FMS_DW.is_active_c11_FMS == 0U) {
    FMS_DW.mission_timestamp_prev = FMS_U.Mission_Data.timestamp;
    FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
    FMS_DW.cmd_prev = FMS_B.Switch1;
    FMS_DW.cmd_start = FMS_B.Switch1;
    FMS_DW.mode_prev = FMS_B.target_mode;
    FMS_DW.mode_start = FMS_B.target_mode;
    FMS_DW.chartAbsoluteTimeCounter = 0;
    FMS_DW.is_active_c11_FMS = 1U;
    FMS_DW.is_active_Command_Listener = 1U;
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    FMS_DW.is_active_Combo_Stick = 1U;
    FMS_DW.durationLastReferenceTick_2_n = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_b = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
    FMS_DW.is_active_Lost_Return = 1U;
    FMS_DW.is_Lost_Return = FMS_IN_Connect;
    FMS_DW.is_active_Vehicle = 1U;
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      switch (FMS_DW.is_Command_Listener) {
       case FMS_IN_Check:
        if (FMS_DW.valid_cmd) {
          FMS_DW.is_Command_Listener = FMS_IN_Send;
          FMS_DW.M_msgReservedData = FMS_DW.save_cmd;
          FMS_sf_msg_send_M();
        } else {
          FMS_DW.is_Command_Listener = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.Switch1 !=
             FMS_Cmd_None)) {
          FMS_DW.save_cmd = FMS_B.Switch1;
          FMS_DW.is_Command_Listener = FMS_IN_Check;
          FMS_DW.valid_cmd = FMS_CheckCmdValid(FMS_DW.save_cmd,
            FMS_B.target_mode, FMS_B.BusConversion_InsertedFor_FMSSt.flag);
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
          FMS_DW.durationLastReferenceTick_2_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_b = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_b = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h0)) {
          FMS_DW.durationLastReferenceTick_1_b = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_b > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_b)) {
            FMS_DW.durationLastReferenceTick_2_n =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2_n > 375) {
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_b)) {
              FMS_DW.durationLastReferenceTick_2_n =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h0)) {
              FMS_DW.durationLastReferenceTick_1_b =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
          }
        }
        break;
      }
    }

    if (FMS_DW.is_active_Lost_Return != 0U) {
      switch (FMS_DW.is_Lost_Return) {
       case FMS_IN_Connect:
        if (FMS_B.LogicalOperator2) {
          FMS_DW.is_Lost_Return = FMS_IN_Lost;
          if ((FMS_B.BusConversion_InsertedFor_FMSSt.flag & 221U) != 0U) {
            FMS_DW.M_msgReservedData = FMS_Cmd_Return;
            FMS_sf_msg_send_M();
          }
        }
        break;

       case FMS_IN_Lost:
        if (!FMS_B.LogicalOperator2) {
          FMS_DW.is_Lost_Return = FMS_IN_Connect;
        }
        break;
      }
    }

    if (FMS_DW.is_active_Vehicle != 0U) {
      FMS_Vehicle();
    }
  }

  /* End of Chart: '<Root>/FMS State Machine' */
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_b, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_i[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T B;
  real32_T D;
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_m;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_VectorConcatenate_i[9];
  real32_T rtb_Subtract3_o;
  real32_T rtb_a_l;
  real32_T rtb_Add4_d;
  boolean_T rtb_Compare_on;
  MotionState rtb_state_c;
  real32_T rtb_Switch_dw[3];
  real32_T rtb_Rem_p;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_VectorConcatenate_k[9];
  real32_T rtb_Rem_n;
  boolean_T rtb_LogicalOperator_es;
  real32_T rtb_Gain_fj;
  real32_T rtb_Subtract3_lb[2];
  real32_T rtb_TmpSignalConversionAtMath_c[3];
  real32_T rtb_VectorConcatenate_ar[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  int32_T rtb_Compare_bv_0;
  real32_T rtb_Sign1_c_idx_1;
  real32_T rtb_Sign1_c_idx_0;
  real32_T rtb_a_idx_0;
  real32_T rtb_Add3_idx_1;
  real32_T rtb_MathFunction_f_idx_2;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  UnitDelay: '<S15>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Delay: '<S13>/Delay'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/FixPt Relational Operator'
   *  Switch: '<S13>/Switch1'
   *  UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S13>/Switch1' incorporates:
       *  DataTypeConversion: '<S13>/Data Type Conversion1'
       *  Delay: '<S13>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S13>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S13>/Delay'
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
      break;

     case PilotMode_Position:
      FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      break;

     case PilotMode_Mission:
      FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
      break;

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
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

     case FMS_IN_Altitude_e:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_B.target_mode = PilotMode_Altitude;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
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
      FMS_B.target_mode = PilotMode_Manual;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
        break;

       case PilotMode_Offboard:
        FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Mission_g:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 32U) != 0U) && ((FMS_U.INS_Out.flag & 64U)
           != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_B.target_mode = PilotMode_Mission;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
      }
      break;

     case FMS_IN_Offboard_p:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_B.target_mode = PilotMode_Offboard;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
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
      FMS_B.target_mode = FMS_DW.Delay_DSTATE_c;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
        break;

       case PilotMode_Position:
        FMS_DW.is_c3_FMS = FMS_IN_Position_f;
        break;

       case PilotMode_Mission:
        FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
        break;

       case PilotMode_Offboard:
        FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
        break;

       default:
        FMS_DW.is_c3_FMS = FMS_IN_Other;
        break;
      }
      break;

     case FMS_IN_Position_f:
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_B.target_mode = PilotMode_Position;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
          break;

         case PilotMode_Position:
          FMS_DW.is_c3_FMS = FMS_IN_Position_f;
          break;

         case PilotMode_Mission:
          FMS_DW.is_c3_FMS = FMS_IN_Mission_g;
          break;

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
          break;

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
      }
      break;

     default:
      FMS_Stabilize();
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  RelationalOperator: '<S18>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch2'
   *  UnitDelay: '<S17>/Delay Input1'
   *  UnitDelay: '<S18>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S12>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_me = (FMS_U.Pilot_Cmd.timestamp !=
    FMS_DW.DelayInput1_DSTATE_h);

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  RelationalOperator: '<S23>/FixPt Relational Operator'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.GCS_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_d) ||
      rtb_FixPtRelationalOperator_me || (FMS_PARAM.LOST_RETURN_EN == 0)) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* Logic: '<S3>/Logical Operator2' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S25>/Compare'
   */
  FMS_B.LogicalOperator2 = ((FMS_DW.DiscreteTimeIntegrator_DSTATE >=
    FMS_PARAM.LOST_RETURN_TIME) && (FMS_PARAM.LOST_RETURN_EN != 0));

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */
  if (rtb_FixPtRelationalOperator_me) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Delay: '<S9>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S8>/FixPt Relational Operator'
   *  Switch: '<S9>/Switch'
   *  UnitDelay: '<S8>/Delay Input1'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_c) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = 0U;
    rtb_Switch_m = 1U;
  } else {
    rtb_Switch_m = FMS_DW.Delay_DSTATE_o;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S10>/Upper Limit'
   *  Constant: '<S7>/Constant'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S10>/Upper Test'
   *  RelationalOperator: '<S7>/Compare'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_m != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) ||
      (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_b = rtb_FixPtRelationalOperator_me;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
  {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator_me;
  FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h0)) {
    FMS_DW.durationLastReferenceTick_1_b = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_b)) {
    FMS_DW.durationLastReferenceTick_2_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < MAX_uint32_T) {
    FMS_DW.temporalCounter_i1++;
  }

  FMS_DW.sfEvent = -1;
  FMS_DW.mission_timestamp_prev = FMS_DW.mission_timestamp_start;
  FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
  FMS_DW.cmd_prev = FMS_DW.cmd_start;
  FMS_DW.cmd_start = FMS_B.Switch1;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.target_mode;
  FMS_DW.M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  /* SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_dw[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_dw[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_dw[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

  /* SwitchCase: '<S27>/Switch Case' incorporates:
   *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  switch (FMS_B.state) {
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

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S29>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S36>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S373>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S363>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S305>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S283>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S293>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S34>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S88>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S139>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S129>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S88>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S33>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
        /* Disable for SwitchCase: '<S45>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S63>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S29>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S27>/Disarm' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  BusAssignment: '<S31>/Bus Assignment'
     *  Constant: '<S31>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S31>/Bus Assignment' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  Constant: '<S31>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;

    /* End of Outputs for SubSystem: '<S27>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S27>/Standby' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  BusAssignment: '<S32>/Bus Assignment'
     *  Constant: '<S32>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S32>/Bus Assignment' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  Constant: '<S32>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

    /* End of Outputs for SubSystem: '<S27>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S27>/Arm' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* SwitchCase: '<S29>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
    switch (FMS_B.state) {
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

    /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S363>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S305>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S283>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S293>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S34>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S88>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S139>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S129>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S88>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S33>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for SwitchCase: '<S45>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S63>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 3:
       case 4:
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S29>/SubMode' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* SwitchCase: '<S36>/Switch Case' incorporates:
       *  Math: '<S395>/Math Function'
       *  Product: '<S397>/Divide'
       *  Sum: '<S351>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_at;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_at = 0;
        break;

       case VehicleState_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_at = 1;
        break;

       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_at = 2;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_at = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_at = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_at) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S363>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S305>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S283>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S293>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Takeoff' incorporates:
           *  ActionPort: '<S278>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Delay: '<S413>/cur_waypoint'
           *  DiscreteIntegrator: '<S409>/Integrator'
           *  DiscreteIntegrator: '<S409>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Takeoff' incorporates:
         *  ActionPort: '<S278>/Action Port'
         */
        /* Delay: '<S413>/cur_waypoint' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j1 != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
          FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Product: '<S413>/Divide' incorporates:
         *  Delay: '<S413>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S413>/Sum1'
         *  Sum: '<S413>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Saturate: '<S413>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S413>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S414>/Trigonometric Function1' incorporates:
         *  Gain: '<S412>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Trigonometry: '<S414>/Trigonometric Function3'
         */
        rtb_Gain_fj = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_VectorConcatenate_i[0] = rtb_Gain_fj;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S414>/Trigonometric Function' incorporates:
         *  Gain: '<S412>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Trigonometry: '<S414>/Trigonometric Function2'
         */
        rtb_Add4_d = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_VectorConcatenate_i[1] = rtb_Add4_d;

        /* SignalConversion: '<S414>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S414>/Constant3'
         */
        rtb_VectorConcatenate_i[2] = 0.0F;

        /* Gain: '<S414>/Gain' */
        rtb_VectorConcatenate_i[3] = -rtb_Add4_d;

        /* Trigonometry: '<S414>/Trigonometric Function3' */
        rtb_VectorConcatenate_i[4] = rtb_Gain_fj;

        /* SignalConversion: '<S414>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S414>/Constant4'
         */
        rtb_VectorConcatenate_i[5] = 0.0F;

        /* SignalConversion: '<S414>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S406>/Saturation1' */
        rtb_Subtract3_o = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Gain_fj = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S406>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S413>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S413>/Multiply'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S406>/Sum'
         *  Sum: '<S413>/Sum3'
         *  Sum: '<S413>/Sum4'
         */
        rtb_a_l = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0])
                   * rtb_Add3_c + FMS_DW.cur_waypoint_DSTATE[0]) -
          FMS_U.INS_Out.x_R;
        rtb_Add4_d = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE
                       [1]) * rtb_Add3_c + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S406>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
            rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_d +
            rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_l;
        }

        /* Saturate: '<S406>/Saturation1' incorporates:
         *  Gain: '<S406>/Gain2'
         *  Product: '<S406>/Multiply'
         */
        rtb_Add3_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S278>/Bus Assignment1'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S278>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S278>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S406>/Saturation1' */
        if (rtb_Add3_idx_1 > rtb_Subtract3_o) {
          /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_o;
        } else if (rtb_Add3_idx_1 < rtb_Gain_fj) {
          /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        } else {
          /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add3_idx_1;
        }

        if (rtb_Add3_c > rtb_Subtract3_o) {
          /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Subtract3_o;
        } else if (rtb_Add3_c < rtb_Gain_fj) {
          /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Gain_fj;
        } else {
          /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S278>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  DiscreteIntegrator: '<S409>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S410>/Multiply1' incorporates:
         *  Constant: '<S410>/const1'
         *  DiscreteIntegrator: '<S409>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S405>/Switch' incorporates:
         *  Abs: '<S405>/Abs'
         *  Abs: '<S405>/Abs1'
         *  Constant: '<S405>/Takeoff_Speed'
         *  Constant: '<S407>/Constant'
         *  Constant: '<S408>/Constant'
         *  Gain: '<S405>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S405>/Logical Operator'
         *  RelationalOperator: '<S407>/Compare'
         *  RelationalOperator: '<S408>/Compare'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S405>/Sum'
         *  Sum: '<S405>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Add4_d = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Add4_d = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S405>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S410>/Add' incorporates:
         *  DiscreteIntegrator: '<S409>/Integrator1'
         *  Sum: '<S409>/Subtract'
         */
        rtb_Subtract3_o = (FMS_DW.Integrator1_DSTATE_a - rtb_Add4_d) +
          rtb_Add3_c;

        /* Signum: '<S410>/Sign' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_a_l = -1.0F;
        } else if (rtb_Subtract3_o > 0.0F) {
          rtb_a_l = 1.0F;
        } else {
          rtb_a_l = rtb_Subtract3_o;
        }

        /* End of Signum: '<S410>/Sign' */

        /* Sum: '<S410>/Add2' incorporates:
         *  Abs: '<S410>/Abs'
         *  Gain: '<S410>/Gain'
         *  Gain: '<S410>/Gain1'
         *  Product: '<S410>/Multiply2'
         *  Product: '<S410>/Multiply3'
         *  Sqrt: '<S410>/Sqrt'
         *  Sum: '<S410>/Add1'
         *  Sum: '<S410>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Subtract3_o) + FMS_ConstB.d_m) *
                         FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F * rtb_a_l +
          rtb_Add3_c;

        /* Sum: '<S410>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_o - rtb_a_l) + rtb_Add3_c;

        /* Sum: '<S410>/Add3' */
        rtb_Add3_c = rtb_Subtract3_o + FMS_ConstB.d_m;

        /* Sum: '<S410>/Subtract1' */
        rtb_Subtract3_o -= FMS_ConstB.d_m;

        /* Signum: '<S410>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S410>/Sign1' */

        /* Signum: '<S410>/Sign2' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_Subtract3_o = -1.0F;
        } else {
          if (rtb_Subtract3_o > 0.0F) {
            rtb_Subtract3_o = 1.0F;
          }
        }

        /* End of Signum: '<S410>/Sign2' */

        /* Sum: '<S410>/Add5' incorporates:
         *  Gain: '<S410>/Gain2'
         *  Product: '<S410>/Multiply4'
         *  Sum: '<S410>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Subtract3_o) * 0.5F * rtb_Add4_d;

        /* Update for Delay: '<S413>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S409>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S409>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S410>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_m;

        /* Sum: '<S410>/Add6' */
        rtb_Gain_fj = rtb_a_l + FMS_ConstB.d_m;

        /* Signum: '<S410>/Sign5' incorporates:
         *  Signum: '<S410>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Subtract3_o = -1.0F;

          /* Signum: '<S410>/Sign6' */
          rtb_Sign1_c_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Subtract3_o = 1.0F;

          /* Signum: '<S410>/Sign6' */
          rtb_Sign1_c_idx_0 = 1.0F;
        } else {
          rtb_Subtract3_o = rtb_a_l;

          /* Signum: '<S410>/Sign6' */
          rtb_Sign1_c_idx_0 = rtb_a_l;
        }

        /* End of Signum: '<S410>/Sign5' */

        /* Signum: '<S410>/Sign3' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S410>/Sign3' */

        /* Signum: '<S410>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S410>/Sign4' */

        /* Update for DiscreteIntegrator: '<S409>/Integrator' incorporates:
         *  Constant: '<S410>/const'
         *  Gain: '<S410>/Gain3'
         *  Product: '<S410>/Divide'
         *  Product: '<S410>/Multiply5'
         *  Product: '<S410>/Multiply6'
         *  Sum: '<S410>/Subtract4'
         *  Sum: '<S410>/Subtract5'
         *  Sum: '<S410>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_a_l / FMS_ConstB.d_m -
          rtb_Subtract3_o) * FMS_ConstB.Gain4_a * ((rtb_Gain_fj - rtb_Add3_c) *
          0.5F) - rtb_Sign1_c_idx_0 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S36>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Land' incorporates:
           *  ActionPort: '<S276>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S321>/Integrator'
           *  DiscreteIntegrator: '<S321>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Land' incorporates:
         *  ActionPort: '<S276>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
         *  Gain: '<S325>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S326>/Trigonometric Function' incorporates:
         *  Gain: '<S325>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S326>/Constant3'
         */
        rtb_VectorConcatenate_i[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S326>/Gain' incorporates:
         *  Gain: '<S325>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Trigonometry: '<S326>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S326>/Trigonometric Function3' incorporates:
         *  Gain: '<S325>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S326>/Constant4'
         */
        rtb_VectorConcatenate_i[5] = 0.0F;

        /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S319>/Saturation1' */
        rtb_Subtract3_o = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Sign1_c_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S323>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S323>/Sum'
         */
        rtb_a_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S323>/Multiply' incorporates:
         *  SignalConversion: '<S323>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
            rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_d +
            rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_l;
        }

        /* End of Product: '<S323>/Multiply' */

        /* Saturate: '<S319>/Saturation1' incorporates:
         *  Gain: '<S323>/Gain2'
         */
        rtb_Add3_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S276>/Bus Assignment1'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S276>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S276>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S319>/Saturation1' */
        if (rtb_Add3_idx_1 > rtb_Subtract3_o) {
          /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_o;
        } else if (rtb_Add3_idx_1 < rtb_Sign1_c_idx_0) {
          /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sign1_c_idx_0;
        } else {
          /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add3_idx_1;
        }

        if (rtb_Add3_c > rtb_Subtract3_o) {
          /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Subtract3_o;
        } else if (rtb_Add3_c < rtb_Sign1_c_idx_0) {
          /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sign1_c_idx_0;
        } else {
          /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S276>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  DiscreteIntegrator: '<S321>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S322>/Multiply1' incorporates:
         *  Constant: '<S322>/const1'
         *  DiscreteIntegrator: '<S321>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S318>/Switch' incorporates:
         *  Constant: '<S318>/Land_Speed'
         *  Constant: '<S320>/Constant'
         *  Gain: '<S318>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S318>/Logical Operator'
         *  RelationalOperator: '<S320>/Compare'
         *  S-Function (sfix_bitop): '<S318>/cmd_p valid'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Add4_d = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Add4_d = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S318>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S322>/Add' incorporates:
         *  DiscreteIntegrator: '<S321>/Integrator1'
         *  Sum: '<S321>/Subtract'
         */
        rtb_Subtract3_o = (FMS_DW.Integrator1_DSTATE_j - rtb_Add4_d) +
          rtb_Add3_c;

        /* Signum: '<S322>/Sign' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_a_l = -1.0F;
        } else if (rtb_Subtract3_o > 0.0F) {
          rtb_a_l = 1.0F;
        } else {
          rtb_a_l = rtb_Subtract3_o;
        }

        /* End of Signum: '<S322>/Sign' */

        /* Sum: '<S322>/Add2' incorporates:
         *  Abs: '<S322>/Abs'
         *  Gain: '<S322>/Gain'
         *  Gain: '<S322>/Gain1'
         *  Product: '<S322>/Multiply2'
         *  Product: '<S322>/Multiply3'
         *  Sqrt: '<S322>/Sqrt'
         *  Sum: '<S322>/Add1'
         *  Sum: '<S322>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Subtract3_o) + FMS_ConstB.d_p) *
                         FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F * rtb_a_l +
          rtb_Add3_c;

        /* Sum: '<S322>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_o - rtb_a_l) + rtb_Add3_c;

        /* Sum: '<S322>/Add3' */
        rtb_Add3_c = rtb_Subtract3_o + FMS_ConstB.d_p;

        /* Sum: '<S322>/Subtract1' */
        rtb_Subtract3_o -= FMS_ConstB.d_p;

        /* Signum: '<S322>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S322>/Sign1' */

        /* Signum: '<S322>/Sign2' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_Subtract3_o = -1.0F;
        } else {
          if (rtb_Subtract3_o > 0.0F) {
            rtb_Subtract3_o = 1.0F;
          }
        }

        /* End of Signum: '<S322>/Sign2' */

        /* Sum: '<S322>/Add5' incorporates:
         *  Gain: '<S322>/Gain2'
         *  Product: '<S322>/Multiply4'
         *  Sum: '<S322>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Subtract3_o) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S321>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S321>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S322>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_p;

        /* Sum: '<S322>/Add6' */
        rtb_Gain_fj = rtb_a_l + FMS_ConstB.d_p;

        /* Signum: '<S322>/Sign5' incorporates:
         *  Signum: '<S322>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Subtract3_o = -1.0F;

          /* Signum: '<S322>/Sign6' */
          rtb_Sign1_c_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Subtract3_o = 1.0F;

          /* Signum: '<S322>/Sign6' */
          rtb_Sign1_c_idx_0 = 1.0F;
        } else {
          rtb_Subtract3_o = rtb_a_l;

          /* Signum: '<S322>/Sign6' */
          rtb_Sign1_c_idx_0 = rtb_a_l;
        }

        /* End of Signum: '<S322>/Sign5' */

        /* Signum: '<S322>/Sign3' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S322>/Sign3' */

        /* Signum: '<S322>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S322>/Sign4' */

        /* Update for DiscreteIntegrator: '<S321>/Integrator' incorporates:
         *  Constant: '<S322>/const'
         *  Gain: '<S322>/Gain3'
         *  Product: '<S322>/Divide'
         *  Product: '<S322>/Multiply5'
         *  Product: '<S322>/Multiply6'
         *  Sum: '<S322>/Subtract4'
         *  Sum: '<S322>/Subtract5'
         *  Sum: '<S322>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_a_l / FMS_ConstB.d_p -
          rtb_Subtract3_o) * FMS_ConstB.Gain4_e * ((rtb_Gain_fj - rtb_Add3_c) *
          0.5F) - rtb_Sign1_c_idx_0 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S36>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Return' incorporates:
           *  ActionPort: '<S277>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Delay: '<S329>/Delay'
           *  Delay: '<S330>/Delay'
           *  Delay: '<S352>/Delay'
           *  DiscreteIntegrator: '<S333>/Integrator'
           *  DiscreteIntegrator: '<S333>/Integrator1'
           *  DiscreteIntegrator: '<S348>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S353>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S400>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_l = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
          FMS_DW.l1_heading_e = 0.0F;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Return' */

          /* SystemReset for IfAction SubSystem: '<S36>/Return' incorporates:
           *  ActionPort: '<S277>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S364>/Motion Status'
           *  Chart: '<S374>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S36>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Return' incorporates:
         *  ActionPort: '<S277>/Action Port'
         */
        /* Delay: '<S352>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_l != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S348>/Switch2' incorporates:
         *  Constant: '<S348>/vel'
         *  Constant: '<S357>/Constant'
         *  RelationalOperator: '<S357>/Compare'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_a_l = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_a_l = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S348>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* RelationalOperator: '<S347>/Compare' incorporates:
         *  Constant: '<S404>/Constant'
         *  DiscreteIntegrator: '<S353>/Discrete-Time Integrator'
         *  RelationalOperator: '<S404>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* DiscreteIntegrator: '<S348>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S374>/Motion State' incorporates:
         *  Constant: '<S374>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S374>/Square'
         *  Math: '<S374>/Square1'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sqrt: '<S374>/Sqrt'
         *  Sum: '<S374>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S373>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S383>/Integrator1'
         *  Gain: '<S377>/Gain6'
         *  Gain: '<S381>/Gain'
         *  Gain: '<S382>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S383>/Subtract'
         *  Sum: '<S384>/Add'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S373>/Hold Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S373>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S373>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S373>/Hold Control' incorporates:
           *  ActionPort: '<S376>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S373>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S373>/Brake Control' incorporates:
           *  ActionPort: '<S375>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S373>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S373>/Move Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S373>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S383>/Integrator'
             *  DiscreteIntegrator: '<S383>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m[0] = 0.0F;
            FMS_DW.Integrator_DSTATE_bz[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE_m[1] = 0.0F;
            FMS_DW.Integrator_DSTATE_bz[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S373>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S373>/Move Control' incorporates:
           *  ActionPort: '<S377>/Action Port'
           */
          /* SignalConversion: '<S377>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator1'
           */
          FMS_B.Merge_a[0] = FMS_DW.Integrator1_DSTATE_m[0];

          /* Product: '<S384>/Multiply1' incorporates:
           *  Constant: '<S384>/const1'
           *  DiscreteIntegrator: '<S383>/Integrator'
           */
          rtb_Subtract3_o = FMS_DW.Integrator_DSTATE_bz[0] * 0.05F;

          /* SignalConversion: '<S377>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator1'
           */
          FMS_B.Merge_a[1] = FMS_DW.Integrator1_DSTATE_m[1];

          /* Product: '<S384>/Multiply1' incorporates:
           *  Constant: '<S384>/const1'
           *  DiscreteIntegrator: '<S383>/Integrator'
           */
          rtb_Add3_idx_1 = FMS_DW.Integrator_DSTATE_bz[1] * 0.05F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S381>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S381>/Gain' */
          rtb_a_idx_0 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ);

          /* Sum: '<S384>/Add' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator1'
           *  Gain: '<S377>/Gain6'
           *  Gain: '<S381>/Gain'
           *  Sum: '<S383>/Subtract'
           */
          rtb_Subtract3_lb[0] = (FMS_DW.Integrator1_DSTATE_m[0] - rtb_a_idx_0 *
            rtb_Add4_d * FMS_PARAM.VEL_XY_LIM) + rtb_Subtract3_o;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S382>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S382>/Gain' */
          rtb_Rem_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ);

          /* Sum: '<S384>/Add' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator1'
           *  Gain: '<S377>/Gain6'
           *  Gain: '<S382>/Gain'
           *  Sum: '<S383>/Subtract'
           */
          rtb_Subtract3_lb[1] = (FMS_DW.Integrator1_DSTATE_m[1] - rtb_Rem_n *
            rtb_Add4_d * FMS_PARAM.VEL_XY_LIM) + rtb_Add3_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S381>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_m[0] - rtb_a_idx_0 *
                         rtb_Add4_d * FMS_PARAM.VEL_XY_LIM) + rtb_Subtract3_o;

          /* Signum: '<S384>/Sign' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator1'
           *  Gain: '<S377>/Gain6'
           *  Gain: '<S381>/Gain'
           *  Sum: '<S383>/Subtract'
           *  Sum: '<S384>/Add'
           */
          if (rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else {
            if (rtb_Gain_fj > 0.0F) {
              rtb_Gain_fj = 1.0F;
            }
          }

          /* Sum: '<S384>/Add2' incorporates:
           *  Abs: '<S384>/Abs'
           *  Gain: '<S384>/Gain'
           *  Gain: '<S384>/Gain1'
           *  Product: '<S384>/Multiply2'
           *  Product: '<S384>/Multiply3'
           *  Signum: '<S384>/Sign'
           *  Sqrt: '<S384>/Sqrt'
           *  Sum: '<S384>/Add1'
           *  Sum: '<S384>/Subtract'
           */
          rtb_Add4_d = (sqrtf((8.0F * fabsf(rtb_Subtract3_lb[0]) +
                               FMS_ConstB.d_a) * FMS_ConstB.d_a) -
                        FMS_ConstB.d_a) * 0.5F * rtb_Gain_fj + rtb_Subtract3_o;

          /* Sum: '<S384>/Add3' incorporates:
           *  Signum: '<S384>/Sign'
           */
          rtb_Add3_c = rtb_Subtract3_lb[0] + FMS_ConstB.d_a;

          /* Sum: '<S384>/Subtract1' incorporates:
           *  Signum: '<S384>/Sign'
           */
          rtb_Gain_fj = rtb_Subtract3_lb[0] - FMS_ConstB.d_a;

          /* Signum: '<S384>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S384>/Sign2' */
          if (rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else {
            if (rtb_Gain_fj > 0.0F) {
              rtb_Gain_fj = 1.0F;
            }
          }

          /* Sum: '<S384>/Add5' incorporates:
           *  Gain: '<S384>/Gain2'
           *  Product: '<S384>/Multiply4'
           *  Signum: '<S384>/Sign'
           *  Sum: '<S384>/Add2'
           *  Sum: '<S384>/Add4'
           *  Sum: '<S384>/Subtract2'
           */
          rtb_Add4_d += ((rtb_Subtract3_lb[0] - rtb_Add4_d) + rtb_Subtract3_o) *
            ((rtb_Add3_c - rtb_Gain_fj) * 0.5F);

          /* Update for DiscreteIntegrator: '<S383>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m[0] += 0.004F *
            FMS_DW.Integrator_DSTATE_bz[0];

          /* Signum: '<S384>/Sign4' incorporates:
           *  Sum: '<S384>/Subtract3'
           */
          rtb_Add3_c = rtb_Add4_d - FMS_ConstB.d_a;

          /* Signum: '<S384>/Sign3' incorporates:
           *  Sum: '<S384>/Add6'
           */
          rtb_Gain_fj = rtb_Add4_d + FMS_ConstB.d_a;

          /* Signum: '<S384>/Sign5' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Subtract3_o = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Subtract3_o = 1.0F;
          } else {
            rtb_Subtract3_o = rtb_Add4_d;
          }

          /* Signum: '<S384>/Sign3' */
          if (rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else {
            if (rtb_Gain_fj > 0.0F) {
              rtb_Gain_fj = 1.0F;
            }
          }

          /* Signum: '<S384>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S384>/Sign6' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Sign1_c_idx_0 = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Sign1_c_idx_0 = 1.0F;
          } else {
            rtb_Sign1_c_idx_0 = rtb_Add4_d;
          }

          /* Update for DiscreteIntegrator: '<S383>/Integrator' incorporates:
           *  Constant: '<S384>/const'
           *  Gain: '<S384>/Gain3'
           *  Product: '<S384>/Divide'
           *  Product: '<S384>/Multiply5'
           *  Product: '<S384>/Multiply6'
           *  Sum: '<S384>/Subtract4'
           *  Sum: '<S384>/Subtract5'
           *  Sum: '<S384>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_bz[0] += ((rtb_Add4_d / FMS_ConstB.d_a -
            rtb_Subtract3_o) * FMS_ConstB.Gain4_m * ((rtb_Gain_fj - rtb_Add3_c) *
            0.5F) - rtb_Sign1_c_idx_0 * 58.836F) * 0.004F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S382>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_m[1] - rtb_Rem_n * rtb_Add4_d
                         * FMS_PARAM.VEL_XY_LIM) + rtb_Add3_idx_1;

          /* Signum: '<S384>/Sign' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator1'
           *  Gain: '<S377>/Gain6'
           *  Gain: '<S382>/Gain'
           *  Sum: '<S383>/Subtract'
           *  Sum: '<S384>/Add'
           */
          if (rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else {
            if (rtb_Gain_fj > 0.0F) {
              rtb_Gain_fj = 1.0F;
            }
          }

          /* Sum: '<S384>/Add2' incorporates:
           *  Abs: '<S384>/Abs'
           *  Gain: '<S384>/Gain'
           *  Gain: '<S384>/Gain1'
           *  Product: '<S384>/Multiply2'
           *  Product: '<S384>/Multiply3'
           *  Signum: '<S384>/Sign'
           *  Sqrt: '<S384>/Sqrt'
           *  Sum: '<S384>/Add1'
           *  Sum: '<S384>/Subtract'
           */
          rtb_Add4_d = (sqrtf((8.0F * fabsf(rtb_Subtract3_lb[1]) +
                               FMS_ConstB.d_a) * FMS_ConstB.d_a) -
                        FMS_ConstB.d_a) * 0.5F * rtb_Gain_fj + rtb_Add3_idx_1;

          /* Sum: '<S384>/Add3' incorporates:
           *  Signum: '<S384>/Sign'
           */
          rtb_Add3_c = rtb_Subtract3_lb[1] + FMS_ConstB.d_a;

          /* Sum: '<S384>/Subtract1' incorporates:
           *  Signum: '<S384>/Sign'
           */
          rtb_Gain_fj = rtb_Subtract3_lb[1] - FMS_ConstB.d_a;

          /* Signum: '<S384>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S384>/Sign2' */
          if (rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else {
            if (rtb_Gain_fj > 0.0F) {
              rtb_Gain_fj = 1.0F;
            }
          }

          /* Sum: '<S384>/Add5' incorporates:
           *  Gain: '<S384>/Gain2'
           *  Product: '<S384>/Multiply4'
           *  Signum: '<S384>/Sign'
           *  Sum: '<S384>/Add2'
           *  Sum: '<S384>/Add4'
           *  Sum: '<S384>/Subtract2'
           */
          rtb_Add4_d += ((rtb_Subtract3_lb[1] - rtb_Add4_d) + rtb_Add3_idx_1) *
            ((rtb_Add3_c - rtb_Gain_fj) * 0.5F);

          /* Update for DiscreteIntegrator: '<S383>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S383>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m[1] += 0.004F *
            FMS_DW.Integrator_DSTATE_bz[1];

          /* Signum: '<S384>/Sign4' incorporates:
           *  Sum: '<S384>/Subtract3'
           */
          rtb_Add3_c = rtb_Add4_d - FMS_ConstB.d_a;

          /* Signum: '<S384>/Sign3' incorporates:
           *  Sum: '<S384>/Add6'
           */
          rtb_Gain_fj = rtb_Add4_d + FMS_ConstB.d_a;

          /* Signum: '<S384>/Sign5' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Subtract3_o = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Subtract3_o = 1.0F;
          } else {
            rtb_Subtract3_o = rtb_Add4_d;
          }

          /* Signum: '<S384>/Sign3' */
          if (rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else {
            if (rtb_Gain_fj > 0.0F) {
              rtb_Gain_fj = 1.0F;
            }
          }

          /* Signum: '<S384>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S384>/Sign6' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Sign1_c_idx_0 = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Sign1_c_idx_0 = 1.0F;
          } else {
            rtb_Sign1_c_idx_0 = rtb_Add4_d;
          }

          /* Update for DiscreteIntegrator: '<S383>/Integrator' incorporates:
           *  Constant: '<S384>/const'
           *  Gain: '<S384>/Gain3'
           *  Product: '<S384>/Divide'
           *  Product: '<S384>/Multiply5'
           *  Product: '<S384>/Multiply6'
           *  Sum: '<S384>/Subtract4'
           *  Sum: '<S384>/Subtract5'
           *  Sum: '<S384>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_bz[1] += ((rtb_Add4_d / FMS_ConstB.d_a -
            rtb_Subtract3_o) * FMS_ConstB.Gain4_m * ((rtb_Gain_fj - rtb_Add3_c) *
            0.5F) - rtb_Sign1_c_idx_0 * 58.836F) * 0.004F;

          /* End of Outputs for SubSystem: '<S373>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S373>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S364>/Motion Status' incorporates:
         *  Abs: '<S364>/Abs'
         *  Constant: '<S364>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S363>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S363>/Hold Control' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S363>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S363>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S363>/Hold Control' incorporates:
           *  ActionPort: '<S366>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S363>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S363>/Brake Control' incorporates:
           *  ActionPort: '<S365>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S363>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S363>/Move Control' incorporates:
             *  ActionPort: '<S367>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S363>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S363>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S363>/Move Control' incorporates:
           *  ActionPort: '<S367>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_j,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S363>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S363>/Switch Case' */

        /* Switch: '<S328>/Switch' incorporates:
         *  Product: '<S352>/Multiply'
         *  Sum: '<S352>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S373>/Saturation1' */
          if (FMS_B.Merge_a[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_a[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_B.Merge_a[0];
          }

          if (FMS_B.Merge_a[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_a[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_B.Merge_a[1];
          }

          /* End of Saturate: '<S373>/Saturation1' */

          /* Saturate: '<S363>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S363>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S352>/Sum' incorporates:
           *  Delay: '<S352>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S401>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S348>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Subtract3_o = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S352>/Sum' incorporates:
           *  Delay: '<S352>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S348>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_n = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S360>/Sqrt' incorporates:
           *  Math: '<S360>/Square'
           *  Sum: '<S348>/Sum'
           *  Sum: '<S360>/Sum of Elements'
           */
          rtb_Add3_idx_1 = sqrtf(rtb_a_idx_0 * rtb_a_idx_0 + rtb_Rem_n *
            rtb_Rem_n);

          /* SignalConversion: '<S403>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* SignalConversion: '<S403>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S403>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S402>/Gain' incorporates:
           *  DiscreteIntegrator: '<S400>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S400>/Add'
           */
          rtb_Add4_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S403>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S403>/Trigonometric Function1'
           */
          rtb_Gain_fj = arm_cos_f32(rtb_Add4_d);
          rtb_VectorConcatenate_i[4] = rtb_Gain_fj;

          /* Trigonometry: '<S403>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S403>/Trigonometric Function'
           */
          rtb_Add4_d = arm_sin_f32(rtb_Add4_d);

          /* Gain: '<S403>/Gain' incorporates:
           *  Trigonometry: '<S403>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -rtb_Add4_d;

          /* SignalConversion: '<S403>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S403>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S403>/Trigonometric Function' */
          rtb_VectorConcatenate_i[1] = rtb_Add4_d;

          /* Trigonometry: '<S403>/Trigonometric Function1' */
          rtb_VectorConcatenate_i[0] = rtb_Gain_fj;

          /* Switch: '<S359>/Switch2' incorporates:
           *  Constant: '<S348>/Constant2'
           *  DiscreteIntegrator: '<S348>/Acceleration_Speed'
           *  RelationalOperator: '<S359>/LowerRelop1'
           *  RelationalOperator: '<S359>/UpperRelop'
           *  Switch: '<S359>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_a_l) {
            rtb_Add4_d = rtb_a_l;
          } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
            /* Switch: '<S359>/Switch' incorporates:
             *  Constant: '<S348>/Constant2'
             */
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_DW.Acceleration_Speed_DSTATE_j;
          }

          /* End of Switch: '<S359>/Switch2' */

          /* Switch: '<S348>/Switch' */
          if (rtb_Add3_idx_1 > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_a_l;
          } else {
            /* Gain: '<S348>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Add3_idx_1;

            /* Switch: '<S358>/Switch2' incorporates:
             *  Constant: '<S348>/Constant1'
             *  RelationalOperator: '<S358>/LowerRelop1'
             *  RelationalOperator: '<S358>/UpperRelop'
             *  Switch: '<S358>/Switch'
             */
            if (rtb_Gain_fj > rtb_a_l) {
              rtb_Gain_fj = rtb_a_l;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S358>/Switch' incorporates:
                 *  Constant: '<S348>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S358>/Switch2' */
          }

          /* End of Switch: '<S348>/Switch' */

          /* Switch: '<S348>/Switch1' incorporates:
           *  Sum: '<S348>/Sum1'
           */
          if (rtb_Add4_d - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Add4_d;
          }

          /* End of Switch: '<S348>/Switch1' */

          /* Sum: '<S401>/Sum of Elements' incorporates:
           *  Math: '<S401>/Math Function'
           */
          rtb_Add4_d = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Add3_c * rtb_Add3_c;

          /* Math: '<S401>/Math Function1' incorporates:
           *  Sum: '<S401>/Sum of Elements'
           *
           * About '<S401>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add4_d = -sqrtf(fabsf(rtb_Add4_d));
          } else {
            rtb_Add4_d = sqrtf(rtb_Add4_d);
          }

          /* End of Math: '<S401>/Math Function1' */

          /* Switch: '<S401>/Switch' incorporates:
           *  Constant: '<S401>/Constant'
           *  Product: '<S401>/Product'
           */
          if (rtb_Add4_d <= 0.0F) {
            rtb_Subtract3_o = 0.0F;
            rtb_Add3_c = 0.0F;
            rtb_Add4_d = 1.0F;
          }

          /* End of Switch: '<S401>/Switch' */

          /* Product: '<S399>/Multiply2' incorporates:
           *  Product: '<S401>/Divide'
           */
          rtb_Subtract3_o = rtb_Subtract3_o / rtb_Add4_d * rtb_Gain_fj;
          rtb_Add3_idx_1 = rtb_Add3_c / rtb_Add4_d * rtb_Gain_fj;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S354>/Sum1' incorporates:
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S354>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Gain_fj = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign1_c_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S354>/Divide' incorporates:
           *  Math: '<S355>/Square'
           *  Math: '<S356>/Square'
           *  Sqrt: '<S355>/Sqrt'
           *  Sqrt: '<S356>/Sqrt'
           *  Sum: '<S354>/Sum'
           *  Sum: '<S354>/Sum1'
           *  Sum: '<S355>/Sum of Elements'
           *  Sum: '<S356>/Sum of Elements'
           */
          rtb_Add4_d = sqrtf(rtb_Gain_fj * rtb_Gain_fj + rtb_Sign1_c_idx_0 *
                             rtb_Sign1_c_idx_0) / sqrtf(rtb_Add3_c * rtb_Add3_c
            + rtb_Add4_d * rtb_Add4_d);

          /* Saturate: '<S354>/Saturation' */
          if (rtb_Add4_d > 1.0F) {
            rtb_Add4_d = 1.0F;
          } else {
            if (rtb_Add4_d < 0.0F) {
              rtb_Add4_d = 0.0F;
            }
          }

          /* End of Saturate: '<S354>/Saturation' */

          /* Product: '<S352>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add3_idx_1 +
              rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_Subtract3_o;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S345>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S354>/Multiply'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S345>/Sum2'
           *  Sum: '<S354>/Add'
           *  Sum: '<S354>/Subtract'
           */
          rtb_Add3_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Add4_d +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_VectorConcatenate_ar[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_VectorConcatenate_ar[1];

          /* Saturate: '<S345>/Saturation1' incorporates:
           *  Product: '<S352>/Multiply'
           */
          if (rtb_Add3_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Add3_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Add3_idx_1;
          }

          /* End of Saturate: '<S345>/Saturation1' */
        }

        /* End of Switch: '<S328>/Switch' */

        /* Delay: '<S330>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S333>/Integrator1' incorporates:
         *  Delay: '<S330>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S337>/Rem' incorporates:
         *  Constant: '<S337>/Constant1'
         *  DiscreteIntegrator: '<S333>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S332>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S337>/Switch' incorporates:
         *  Abs: '<S337>/Abs'
         *  Constant: '<S337>/Constant'
         *  Constant: '<S338>/Constant'
         *  Product: '<S337>/Multiply'
         *  RelationalOperator: '<S338>/Compare'
         *  Sum: '<S337>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S337>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S337>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S337>/Switch' */

        /* Gain: '<S332>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S332>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S332>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S277>/Bus Assignment1'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S277>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S277>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S394>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S394>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S392>/Sum of Elements'
         */
        rtb_Add4_d = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S394>/Math Function1' incorporates:
         *  Sum: '<S394>/Sum of Elements'
         *
         * About '<S394>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S394>/Math Function1' */

        /* Switch: '<S394>/Switch' incorporates:
         *  Constant: '<S394>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S394>/Product'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S394>/Switch' */

        /* Delay: '<S329>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S277>/Sum' incorporates:
         *  Delay: '<S329>/Delay'
         *  MATLAB Function: '<S350>/OutRegionRegWP'
         *  MATLAB Function: '<S350>/SearchL1RefWP'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_a_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_Rem_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S344>/Sum of Elements' incorporates:
         *  Math: '<S344>/Math Function'
         *  Sum: '<S277>/Sum'
         */
        rtb_Rem_p = rtb_Rem_n * rtb_Rem_n + rtb_a_idx_0 * rtb_a_idx_0;

        /* Math: '<S344>/Math Function1' incorporates:
         *  Sum: '<S344>/Sum of Elements'
         *
         * About '<S344>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S344>/Math Function1' */

        /* Switch: '<S344>/Switch' incorporates:
         *  Constant: '<S344>/Constant'
         *  Product: '<S344>/Product'
         *  Sum: '<S277>/Sum'
         */
        if (B > 0.0F) {
          rtb_Subtract3_o = rtb_Rem_n;
          rtb_Add3_idx_1 = rtb_a_idx_0;
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_Subtract3_o = 0.0F;
          rtb_Add3_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S344>/Switch' */

        /* Product: '<S394>/Divide' */
        rtb_Subtract3_lb[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Subtract3_lb[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S397>/Sum of Elements' incorporates:
         *  Math: '<S397>/Math Function'
         *  SignalConversion: '<S397>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = rtb_Subtract3_lb[1] * rtb_Subtract3_lb[1] +
          rtb_Subtract3_lb[0] * rtb_Subtract3_lb[0];

        /* Math: '<S397>/Math Function1' incorporates:
         *  Sum: '<S397>/Sum of Elements'
         *
         * About '<S397>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S397>/Math Function1' */

        /* Switch: '<S397>/Switch' incorporates:
         *  Constant: '<S397>/Constant'
         *  Product: '<S397>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Subtract3_lb[1];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Subtract3_lb[0];
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S397>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S350>/NearbyRefWP' incorporates:
         *  Constant: '<S277>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_dw[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Subtract3_lb, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S350>/SearchL1RefWP' incorporates:
         *  Constant: '<S277>/L1'
         *  Delay: '<S329>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Gain_fj = rtb_a_idx_0 * rtb_a_idx_0 + rtb_Rem_n * rtb_Rem_n;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_a_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
             rtb_Rem_n * (FMS_DW.Delay_DSTATE_p[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Gain_fj);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Sign1_c_idx_0 = 0.0F;
        rtb_Sign1_c_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Gain_fj);
          rtb_Gain_fj = (-B - u1_tmp) / (2.0F * rtb_Gain_fj);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Gain_fj >= 0.0F) &&
              (rtb_Gain_fj <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Gain_fj);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Gain_fj >= 0.0F) && (rtb_Gain_fj <= 1.0F)) {
              rtb_Add3_c = rtb_Gain_fj;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Gain_fj);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_Sign1_c_idx_0 = rtb_a_idx_0 * rtb_Add3_c + FMS_DW.Delay_DSTATE_p[0];
          rtb_Sign1_c_idx_1 = rtb_Rem_n * rtb_Add3_c + FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S350>/OutRegionRegWP' incorporates:
         *  Delay: '<S329>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Gain_fj = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                       rtb_Rem_n + (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0])
                       * rtb_a_idx_0) / (rtb_a_idx_0 * rtb_a_idx_0 + rtb_Rem_n *
          rtb_Rem_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Gain_fj <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Gain_fj >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          B = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          B = rtb_Gain_fj * rtb_a_idx_0 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S350>/Switch1' incorporates:
         *  Constant: '<S387>/Constant'
         *  RelationalOperator: '<S387>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S350>/Switch' incorporates:
           *  Constant: '<S386>/Constant'
           *  MATLAB Function: '<S350>/SearchL1RefWP'
           *  RelationalOperator: '<S386>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Subtract3_lb[0] = rtb_Sign1_c_idx_0;
            rtb_Subtract3_lb[1] = rtb_Sign1_c_idx_1;
          } else {
            rtb_Subtract3_lb[0] = B;

            /* MATLAB Function: '<S350>/OutRegionRegWP' incorporates:
             *  Delay: '<S329>/Delay'
             *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Subtract3_lb[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Subtract3_lb[1] = rtb_Gain_fj * rtb_Rem_n +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S350>/Switch' */
        }

        /* End of Switch: '<S350>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S351>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Gain_fj = rtb_Subtract3_lb[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Subtract3_lb[0] = rtb_Gain_fj;
        rtb_Add3_c = rtb_Gain_fj * rtb_Gain_fj;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S351>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S395>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Gain_fj = rtb_Subtract3_lb[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S395>/Math Function' incorporates:
         *  Math: '<S393>/Square'
         */
        rtb_Rem_p = rtb_Gain_fj * rtb_Gain_fj;

        /* Sum: '<S395>/Sum of Elements' incorporates:
         *  Math: '<S395>/Math Function'
         */
        rtb_Add3_c += rtb_Rem_p;

        /* Math: '<S395>/Math Function1' incorporates:
         *  Sum: '<S395>/Sum of Elements'
         *
         * About '<S395>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S395>/Math Function1' */

        /* Switch: '<S395>/Switch' incorporates:
         *  Constant: '<S395>/Constant'
         *  Product: '<S395>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_dw[0] = rtb_Subtract3_lb[0];
          rtb_Switch_dw[1] = rtb_Gain_fj;
          rtb_Switch_dw[2] = B;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S395>/Switch' */

        /* Product: '<S395>/Divide' */
        rtb_a_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Sum: '<S398>/Sum of Elements' incorporates:
         *  Math: '<S398>/Math Function'
         *  SignalConversion: '<S398>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = D * D + rtb_a_idx_0 * rtb_a_idx_0;

        /* Math: '<S398>/Math Function1' incorporates:
         *  Sum: '<S398>/Sum of Elements'
         *
         * About '<S398>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S398>/Math Function1' */

        /* Switch: '<S398>/Switch' incorporates:
         *  Constant: '<S398>/Constant'
         *  Product: '<S398>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_dw[0] = D;
          rtb_Switch_dw[1] = rtb_a_idx_0;
          rtb_Switch_dw[2] = B;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S398>/Switch' */

        /* Product: '<S398>/Divide' */
        rtb_a_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];

        /* Math: '<S393>/Square' */
        rtb_Add3_c = rtb_Subtract3_lb[0] * rtb_Subtract3_lb[0];

        /* Product: '<S344>/Divide' */
        rtb_Sign1_c_idx_0 = rtb_Subtract3_o / rtb_MathFunction_f_idx_2;
        rtb_Subtract3_lb[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S398>/Divide' incorporates:
         *  Product: '<S397>/Divide'
         */
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Product: '<S397>/Divide' */
        rtb_Gain_fj = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S344>/Divide' */
        rtb_Sign1_c_idx_1 = rtb_Add3_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sqrt: '<S392>/Sqrt' */
        B = sqrtf(rtb_Add4_d);

        /* Gain: '<S351>/Gain' incorporates:
         *  Math: '<S351>/Square'
         */
        rtb_Subtract3_o = B * B * 2.0F;

        /* Sum: '<S396>/Subtract' incorporates:
         *  Product: '<S396>/Multiply'
         *  Product: '<S396>/Multiply1'
         */
        B = rtb_a_idx_0 * rtb_Gain_fj - D * rtb_Subtract3_lb[0];

        /* Signum: '<S391>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S391>/Sign1' */

        /* Switch: '<S391>/Switch2' incorporates:
         *  Constant: '<S391>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S391>/Switch2' */

        /* DotProduct: '<S391>/Dot Product' */
        rtb_Gain_fj = rtb_Subtract3_lb[0] * rtb_a_idx_0 + rtb_Gain_fj * D;

        /* Trigonometry: '<S391>/Acos' incorporates:
         *  DotProduct: '<S391>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S391>/Multiply' incorporates:
         *  Trigonometry: '<S391>/Acos'
         */
        B *= acosf(rtb_Gain_fj);

        /* Saturate: '<S351>/Saturation' */
        if (B > 1.57079637F) {
          B = 1.57079637F;
        } else {
          if (B < -1.57079637F) {
            B = -1.57079637F;
          }
        }

        /* End of Saturate: '<S351>/Saturation' */

        /* Product: '<S351>/Divide' incorporates:
         *  Constant: '<S277>/L1'
         *  Constant: '<S351>/Constant'
         *  MinMax: '<S351>/Max'
         *  MinMax: '<S351>/Min'
         *  Product: '<S351>/Multiply1'
         *  Sqrt: '<S393>/Sqrt'
         *  Sum: '<S393>/Sum of Elements'
         *  Trigonometry: '<S351>/Sin'
         */
        rtb_Add4_d = arm_sin_f32(B) * rtb_Subtract3_o / fminf(FMS_PARAM.L1,
          fmaxf(sqrtf(rtb_Rem_p + rtb_Add3_c), 0.5F));

        /* Sum: '<S342>/Subtract' incorporates:
         *  Product: '<S342>/Multiply'
         *  Product: '<S342>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sign1_c_idx_0 * FMS_ConstB.Divide_d[1] -
          rtb_Sign1_c_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S331>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S331>/Sign1' */

        /* Switch: '<S331>/Switch2' incorporates:
         *  Constant: '<S331>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S331>/Switch2' */

        /* DotProduct: '<S331>/Dot Product' */
        rtb_Add3_idx_1 = FMS_ConstB.Divide_d[0] * rtb_Sign1_c_idx_0 +
          FMS_ConstB.Divide_d[1] * rtb_Sign1_c_idx_1;

        /* Trigonometry: '<S331>/Acos' incorporates:
         *  DotProduct: '<S331>/Dot Product'
         */
        if (rtb_Add3_idx_1 > 1.0F) {
          rtb_Add3_idx_1 = 1.0F;
        } else {
          if (rtb_Add3_idx_1 < -1.0F) {
            rtb_Add3_idx_1 = -1.0F;
          }
        }

        /* Product: '<S331>/Multiply' incorporates:
         *  Trigonometry: '<S331>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_Add3_idx_1);

        /* Math: '<S334>/Rem' incorporates:
         *  Constant: '<S334>/Constant1'
         *  Delay: '<S330>/Delay'
         *  Sum: '<S330>/Sum2'
         */
        B = rt_remf(rtb_MathFunction_f_idx_2 - FMS_DW.Delay_DSTATE_a,
                    6.28318548F);

        /* Switch: '<S334>/Switch' incorporates:
         *  Abs: '<S334>/Abs'
         *  Constant: '<S334>/Constant'
         *  Constant: '<S340>/Constant'
         *  Product: '<S334>/Multiply'
         *  RelationalOperator: '<S340>/Compare'
         *  Sum: '<S334>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S334>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S334>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S334>/Switch' */

        /* Sum: '<S330>/Sum' incorporates:
         *  Delay: '<S330>/Delay'
         */
        rtb_Add3_c = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S339>/Multiply1' incorporates:
         *  Constant: '<S339>/const1'
         *  DiscreteIntegrator: '<S333>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S339>/Add' incorporates:
         *  DiscreteIntegrator: '<S333>/Integrator1'
         *  Sum: '<S333>/Subtract'
         */
        rtb_Subtract3_o = (FMS_DW.Integrator1_DSTATE_e - rtb_Add3_c) + B;

        /* Signum: '<S339>/Sign' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Subtract3_o > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Subtract3_o;
        }

        /* End of Signum: '<S339>/Sign' */

        /* Sum: '<S339>/Add2' incorporates:
         *  Abs: '<S339>/Abs'
         *  Gain: '<S339>/Gain'
         *  Gain: '<S339>/Gain1'
         *  Product: '<S339>/Multiply2'
         *  Product: '<S339>/Multiply3'
         *  Sqrt: '<S339>/Sqrt'
         *  Sum: '<S339>/Add1'
         *  Sum: '<S339>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Subtract3_o) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Add3_c
          + B;

        /* Sum: '<S339>/Add4' */
        rtb_Gain_fj = (rtb_Subtract3_o - rtb_Rem_p) + B;

        /* Sum: '<S339>/Add3' */
        rtb_Add3_c = rtb_Subtract3_o + FMS_ConstB.d_l;

        /* Sum: '<S339>/Subtract1' */
        rtb_Subtract3_o -= FMS_ConstB.d_l;

        /* Signum: '<S339>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S339>/Sign1' */

        /* Signum: '<S339>/Sign2' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_Subtract3_o = -1.0F;
        } else {
          if (rtb_Subtract3_o > 0.0F) {
            rtb_Subtract3_o = 1.0F;
          }
        }

        /* End of Signum: '<S339>/Sign2' */

        /* Sum: '<S339>/Add5' incorporates:
         *  Gain: '<S339>/Gain2'
         *  Product: '<S339>/Multiply4'
         *  Sum: '<S339>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Subtract3_o) * 0.5F * rtb_Gain_fj;

        /* Sum: '<S339>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d_l;

        /* Sum: '<S339>/Subtract3' */
        rtb_Gain_fj = rtb_Rem_p - FMS_ConstB.d_l;

        /* Product: '<S339>/Divide' */
        rtb_Sign1_c_idx_0 = rtb_Rem_p / FMS_ConstB.d_l;

        /* Signum: '<S339>/Sign5' incorporates:
         *  Signum: '<S339>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Sign1_c_idx_1 = -1.0F;

          /* Signum: '<S339>/Sign6' */
          rtb_Subtract3_o = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_Sign1_c_idx_1 = 1.0F;

          /* Signum: '<S339>/Sign6' */
          rtb_Subtract3_o = 1.0F;
        } else {
          rtb_Sign1_c_idx_1 = rtb_Rem_p;

          /* Signum: '<S339>/Sign6' */
          rtb_Subtract3_o = rtb_Rem_p;
        }

        /* End of Signum: '<S339>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S330>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S335>/Rem' incorporates:
         *  Constant: '<S335>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S335>/Switch' incorporates:
         *  Abs: '<S335>/Abs'
         *  Constant: '<S335>/Constant'
         *  Constant: '<S341>/Constant'
         *  Product: '<S335>/Multiply'
         *  RelationalOperator: '<S341>/Compare'
         *  Sum: '<S335>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S335>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Add3_idx_1 = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Add3_idx_1 = 1.0F;
          } else {
            rtb_Add3_idx_1 = rtb_Rem_p;
          }

          /* End of Signum: '<S335>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Add3_idx_1;
        }

        /* End of Switch: '<S335>/Switch' */

        /* Abs: '<S328>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S352>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S353>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S346>/Constant'
         *  RelationalOperator: '<S346>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_m = (uint8_T)((uint32_T)(rtb_Rem_p <=
          0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_m);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S353>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S348>/Acceleration_Speed' incorporates:
         *  Constant: '<S348>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Product: '<S352>/Divide1' */
        rtb_Add3_idx_1 = rtb_Add4_d / rtb_a_l;

        /* Saturate: '<S352>/Saturation' */
        if (rtb_Add3_idx_1 > 0.314159274F) {
          rtb_Add3_idx_1 = 0.314159274F;
        } else {
          if (rtb_Add3_idx_1 < -0.314159274F) {
            rtb_Add3_idx_1 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S352>/Saturation' */

        /* Update for DiscreteIntegrator: '<S400>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Add3_idx_1;

        /* Update for Delay: '<S330>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S333>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S333>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S329>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S339>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S339>/Sign3' */

        /* Signum: '<S339>/Sign4' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S339>/Sign4' */

        /* Update for DiscreteIntegrator: '<S333>/Integrator' incorporates:
         *  Constant: '<S339>/const'
         *  Gain: '<S339>/Gain3'
         *  Product: '<S339>/Multiply5'
         *  Product: '<S339>/Multiply6'
         *  Sum: '<S339>/Subtract4'
         *  Sum: '<S339>/Subtract5'
         *  Sum: '<S339>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Sign1_c_idx_0 - rtb_Sign1_c_idx_1) *
          FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Gain_fj) * 0.5F) -
          rtb_Subtract3_o * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S333>/Integrator' */
        /* End of Outputs for SubSystem: '<S36>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S36>/Hold' incorporates:
           *  ActionPort: '<S275>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S284>/Motion Status'
           *  Chart: '<S294>/Motion State'
           *  Chart: '<S306>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_ai = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S36>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Hold' incorporates:
         *  ActionPort: '<S275>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S284>/Motion Status' incorporates:
         *  Abs: '<S284>/Abs'
         *  Constant: '<S284>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S294>/Motion State' incorporates:
         *  Abs: '<S294>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_ai < 255U) {
          FMS_DW.temporalCounter_i1_ai++;
        }

        if (FMS_DW.is_active_c15_FMS == 0U) {
          FMS_DW.is_active_c15_FMS = 1U;
          FMS_DW.is_c15_FMS = FMS_IN_Move_n;
          rtb_state_ki = MotionState_Move;
        } else {
          switch (FMS_DW.is_c15_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_ki = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_ai
                 >= 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_ki = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c15_FMS = FMS_IN_Brake_o;
            FMS_DW.temporalCounter_i1_ai = 0U;
            rtb_state_ki = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S294>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S306>/Motion State' incorporates:
         *  Constant: '<S306>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S306>/Square'
         *  Math: '<S306>/Square1'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sqrt: '<S306>/Sqrt'
         *  Sum: '<S306>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S305>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S305>/Hold Control' incorporates:
             *  ActionPort: '<S308>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S305>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S305>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S305>/Hold Control' incorporates:
           *  ActionPort: '<S308>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S305>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S305>/Brake Control' incorporates:
           *  ActionPort: '<S307>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S305>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S305>/Move Control' incorporates:
             *  ActionPort: '<S309>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S305>/Switch Case' */
            FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S305>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S305>/Move Control' incorporates:
           *  ActionPort: '<S309>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_i(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S305>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S305>/Switch Case' */

        /* SwitchCase: '<S283>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pp;
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S283>/Hold Control' incorporates:
             *  ActionPort: '<S286>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S283>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S283>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S283>/Hold Control' incorporates:
           *  ActionPort: '<S286>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S283>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S283>/Brake Control' incorporates:
           *  ActionPort: '<S285>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S283>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S283>/Move Control' incorporates:
             *  ActionPort: '<S287>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S283>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S283>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S283>/Move Control' incorporates:
           *  ActionPort: '<S287>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S283>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S283>/Switch Case' */

        /* SwitchCase: '<S293>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S293>/Hold Control' incorporates:
             *  ActionPort: '<S296>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S293>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S293>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S293>/Hold Control' incorporates:
           *  ActionPort: '<S296>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S293>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S293>/Brake Control' incorporates:
           *  ActionPort: '<S295>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S293>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S293>/Move Control' incorporates:
             *  ActionPort: '<S297>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S293>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S293>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S293>/Move Control' incorporates:
           *  ActionPort: '<S297>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S293>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S293>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S275>/Bus Assignment'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S275>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S275>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S293>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S293>/Saturation' */

        /* Saturate: '<S305>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S305>/Saturation1' */

        /* Saturate: '<S283>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S275>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S283>/Saturation1' */
        /* End of Outputs for SubSystem: '<S36>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S36>/Unknown' incorporates:
         *  ActionPort: '<S279>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S36>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S36>/Switch Case' */
      /* End of Outputs for SubSystem: '<S29>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S29>/Auto' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* SwitchCase: '<S34>/Switch Case' incorporates:
       *  Math: '<S159>/Square'
       *  Math: '<S161>/Math Function'
       *  Sum: '<S117>/Subtract'
       *  Sum: '<S174>/Sum1'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Offboard:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 0;
        break;

       case VehicleState_Mission:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 1;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_i = 2;
        break;
      }

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_i) && (rtPrevAction
           == 1)) {
        /* Disable for Resettable SubSystem: '<S88>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S139>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S129>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S88>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S34>/Offboard' incorporates:
         *  ActionPort: '<S89>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S253>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S256>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S257>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S257>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S257>/Multiply1' incorporates:
         *  Product: '<S257>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S257>/Divide' incorporates:
         *  Constant: '<S257>/Constant'
         *  Constant: '<S257>/R'
         *  Sqrt: '<S257>/Sqrt'
         *  Sum: '<S257>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S257>/Product3' incorporates:
         *  Constant: '<S257>/Constant1'
         *  Product: '<S257>/Multiply1'
         *  Sum: '<S257>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S257>/Multiply2' incorporates:
         *  Trigonometry: '<S257>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S256>/Sum' incorporates:
         *  Gain: '<S253>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S261>/Abs' incorporates:
         *  Abs: '<S264>/Abs1'
         *  Switch: '<S261>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S261>/Switch1' incorporates:
         *  Abs: '<S261>/Abs'
         *  Bias: '<S261>/Bias2'
         *  Bias: '<S261>/Bias3'
         *  Constant: '<S258>/Constant'
         *  Constant: '<S258>/Constant1'
         *  Constant: '<S263>/Constant'
         *  Gain: '<S261>/Gain1'
         *  Product: '<S261>/Multiply'
         *  RelationalOperator: '<S263>/Compare'
         *  Switch: '<S258>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S264>/Switch1' incorporates:
           *  Bias: '<S264>/Bias2'
           *  Bias: '<S264>/Bias3'
           *  Constant: '<S264>/Constant'
           *  Constant: '<S265>/Constant'
           *  Math: '<S264>/Math Function'
           *  RelationalOperator: '<S265>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S264>/Switch1' */

          /* Signum: '<S261>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S261>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S258>/Sum' incorporates:
         *  Gain: '<S253>/Gain1'
         *  Gain: '<S253>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S256>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S256>/Multiply' incorporates:
         *  Gain: '<S256>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S260>/Switch1' incorporates:
         *  Abs: '<S260>/Abs1'
         *  Bias: '<S260>/Bias2'
         *  Bias: '<S260>/Bias3'
         *  Constant: '<S260>/Constant'
         *  Constant: '<S262>/Constant'
         *  Math: '<S260>/Math Function'
         *  RelationalOperator: '<S262>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S260>/Switch1' */

        /* Product: '<S256>/Multiply' incorporates:
         *  Gain: '<S256>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S234>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S238>/Multiply1'
         *  Product: '<S239>/Multiply3'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S247>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S247>/Trigonometric Function3' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S247>/Gain' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S247>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S247>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S247>/Trigonometric Function' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S247>/Trigonometric Function1' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S238>/Saturation' incorporates:
           *  Constant: '<S244>/Constant'
           *  Constant: '<S245>/Constant'
           *  Constant: '<S255>/Constant'
           *  DataTypeConversion: '<S253>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S237>/Logical Operator'
           *  Product: '<S238>/Multiply'
           *  Product: '<S259>/Multiply1'
           *  Product: '<S259>/Multiply2'
           *  RelationalOperator: '<S244>/Compare'
           *  RelationalOperator: '<S245>/Compare'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S237>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/lat_cmd valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S238>/Sum1'
           *  Sum: '<S259>/Sum2'
           *  Switch: '<S240>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Add4_d = (real32_T)(rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o2
              + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Add4_d = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Add3_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Add4_d -
            FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Add3_idx_1 > 4.0F) {
            rtb_Add3_idx_1 = 4.0F;
          } else {
            if (rtb_Add3_idx_1 < -4.0F) {
              rtb_Add3_idx_1 = -4.0F;
            }
          }

          /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S238>/Saturation' incorporates:
           *  Constant: '<S244>/Constant'
           *  Constant: '<S245>/Constant'
           *  Constant: '<S255>/Constant'
           *  DataTypeConversion: '<S253>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S237>/Logical Operator'
           *  Product: '<S238>/Multiply'
           *  Product: '<S259>/Multiply3'
           *  Product: '<S259>/Multiply4'
           *  RelationalOperator: '<S244>/Compare'
           *  RelationalOperator: '<S245>/Compare'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S237>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/lon_cmd valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S238>/Sum1'
           *  Sum: '<S259>/Sum3'
           *  Switch: '<S240>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Add4_d = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Add4_d = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Add4_d -
            FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Add3_c > 4.0F) {
            rtb_Add3_c = 4.0F;
          } else {
            if (rtb_Add3_c < -4.0F) {
              rtb_Add3_c = -4.0F;
            }
          }

          /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S238>/Saturation' incorporates:
           *  Constant: '<S244>/Constant'
           *  Constant: '<S245>/Constant'
           *  Constant: '<S255>/Constant'
           *  DataTypeConversion: '<S253>/Data Type Conversion'
           *  DataTypeConversion: '<S253>/Data Type Conversion1'
           *  Gain: '<S241>/Gain'
           *  Gain: '<S253>/Gain2'
           *  Gain: '<S256>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S237>/Logical Operator'
           *  Product: '<S238>/Multiply'
           *  RelationalOperator: '<S244>/Compare'
           *  RelationalOperator: '<S245>/Compare'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S237>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/alt_cmd valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S238>/Sum1'
           *  Sum: '<S256>/Sum1'
           *  Switch: '<S240>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Add4_d = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Add4_d = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_a_l = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Add4_d -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_a_l > 2.0F) {
            rtb_a_l = 2.0F;
          } else {
            if (rtb_a_l < -2.0F) {
              rtb_a_l = -2.0F;
            }
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_a_l +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add3_c +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_Add3_idx_1);
          }

          /* SignalConversion: '<S181>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S181>/Constant4'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  Product: '<S238>/Multiply1'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S181>/Trigonometric Function3' incorporates:
           *  Gain: '<S180>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S181>/Gain' incorporates:
           *  Gain: '<S180>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S181>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S181>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S181>/Constant3'
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S181>/Trigonometric Function' incorporates:
           *  Gain: '<S180>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S181>/Trigonometric Function1' incorporates:
           *  Gain: '<S180>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S181>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S171>/Multiply' incorporates:
           *  Constant: '<S179>/Constant'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/ax_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S181>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S171>/Multiply' incorporates:
           *  Constant: '<S179>/Constant'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/ay_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S181>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S171>/Multiply' incorporates:
           *  Constant: '<S179>/Constant'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/az_cmd valid'
           */
          rtb_Sign1_c_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S171>/Index Vector' incorporates:
           *  Product: '<S177>/Multiply'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sign1_c_idx_0
              + (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_d +
                 rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 1:
          /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S251>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Gain: '<S249>/Gain' incorporates:
           *  Gain: '<S182>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S239>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S251>/Trigonometric Function3' incorporates:
           *  Gain: '<S249>/Gain'
           *  Trigonometry: '<S251>/Trigonometric Function1'
           */
          rtb_Gain_fj = arm_cos_f32(rtb_Add3_c);
          rtb_VectorConcatenate_i[4] = rtb_Gain_fj;

          /* Trigonometry: '<S251>/Trigonometric Function2' incorporates:
           *  Gain: '<S249>/Gain'
           *  Trigonometry: '<S251>/Trigonometric Function'
           */
          rtb_Add4_d = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S251>/Gain' incorporates:
           *  Trigonometry: '<S251>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -rtb_Add4_d;

          /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S251>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S251>/Trigonometric Function' */
          rtb_VectorConcatenate_i[1] = rtb_Add4_d;

          /* Trigonometry: '<S251>/Trigonometric Function1' */
          rtb_VectorConcatenate_i[0] = rtb_Gain_fj;

          /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S250>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_k[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S250>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_k[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S250>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_k[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S250>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S250>/Constant4'
           */
          rtb_VectorConcatenate_k[5] = 0.0F;

          /* Trigonometry: '<S250>/Trigonometric Function3' incorporates:
           *  Gain: '<S248>/Gain'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S250>/Trigonometric Function1'
           */
          rtb_a_l = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_k[4] = rtb_a_l;

          /* Trigonometry: '<S250>/Trigonometric Function2' incorporates:
           *  Gain: '<S248>/Gain'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S250>/Trigonometric Function'
           */
          rtb_Subtract3_o = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S250>/Gain' incorporates:
           *  Trigonometry: '<S250>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_k[3] = -rtb_Subtract3_o;

          /* SignalConversion: '<S250>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S250>/Constant3'
           */
          rtb_VectorConcatenate_k[2] = 0.0F;

          /* Trigonometry: '<S250>/Trigonometric Function' */
          rtb_VectorConcatenate_k[1] = rtb_Subtract3_o;

          /* Trigonometry: '<S250>/Trigonometric Function1' */
          rtb_VectorConcatenate_k[0] = rtb_a_l;

          /* RelationalOperator: '<S255>/Compare' incorporates:
           *  Constant: '<S255>/Constant'
           *  S-Function (sfix_bitop): '<S252>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S253>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S253>/Data Type Conversion'
           *  Gain: '<S253>/Gain2'
           *  Gain: '<S256>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S259>/Multiply1'
           *  Product: '<S259>/Multiply2'
           *  Product: '<S259>/Multiply3'
           *  Product: '<S259>/Multiply4'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S256>/Sum1'
           *  Sum: '<S259>/Sum2'
           *  Sum: '<S259>/Sum3'
           */
          rtb_VectorConcatenate_ar[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[1] = (real32_T)(rtb_Gain *
            FMS_ConstB.SinCos_o2 - rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S240>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S244>/Compare' incorporates:
           *  Constant: '<S244>/Constant'
           *  S-Function (sfix_bitop): '<S237>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S245>/Compare' incorporates:
           *  Constant: '<S245>/Constant'
           *  S-Function (sfix_bitop): '<S237>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S239>/Sum2' incorporates:
             *  Product: '<S239>/Multiply2'
             *  Switch: '<S240>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Add4_d = rtb_VectorConcatenate_ar[rtb_Compare_bv_0];
            } else {
              rtb_Add4_d = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S239>/Saturation1' incorporates:
             *  Gain: '<S241>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S237>/Logical Operator'
             *  Product: '<S239>/Multiply'
             *  Product: '<S239>/Multiply2'
             *  SignalConversion: '<S28>/Signal Copy1'
             *  Sum: '<S239>/Sum2'
             */
            rtb_Add3_idx_1 = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_Add4_d - ((rtb_VectorConcatenate_k[rtb_Compare_bv_0 + 3] *
                             FMS_U.INS_Out.y_R +
                             rtb_VectorConcatenate_k[rtb_Compare_bv_0] *
                             FMS_U.INS_Out.x_R) +
                            rtb_VectorConcatenate_k[rtb_Compare_bv_0 + 6] *
                            -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Add3_idx_1 > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Add3_idx_1 < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] = rtb_Add3_idx_1;
            }

            /* End of Saturate: '<S239>/Saturation1' */
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] *
              rtb_TmpSignalConversionAtMath_c[2] +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] *
               rtb_TmpSignalConversionAtMath_c[1] +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] *
               rtb_TmpSignalConversionAtMath_c[0]);
          }

          /* SignalConversion: '<S183>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S183>/Constant4'
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  Product: '<S239>/Multiply3'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S183>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S183>/Gain' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           *  Trigonometry: '<S183>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S183>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S183>/Constant3'
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S183>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S183>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S183>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S171>/Multiply' incorporates:
           *  Constant: '<S179>/Constant'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/ax_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S183>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S171>/Multiply' incorporates:
           *  Constant: '<S179>/Constant'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/ay_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S183>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S171>/Index Vector'
           */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S171>/Multiply' incorporates:
           *  Constant: '<S179>/Constant'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/az_cmd valid'
           */
          rtb_Sign1_c_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S171>/Index Vector' incorporates:
           *  Product: '<S178>/Multiply3'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sign1_c_idx_0
              + (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_d +
                 rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         default:
          /* SignalConversion: '<S243>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S243>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S243>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S243>/Trigonometric Function3' incorporates:
           *  Gain: '<S242>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S243>/Gain' incorporates:
           *  Gain: '<S242>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S243>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S243>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S243>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S243>/Trigonometric Function' incorporates:
           *  Gain: '<S242>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S243>/Trigonometric Function1' incorporates:
           *  Gain: '<S242>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S252>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S237>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S255>/Compare' incorporates:
           *  Constant: '<S255>/Constant'
           *  S-Function (sfix_bitop): '<S252>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S252>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S237>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S255>/Compare' incorporates:
           *  Constant: '<S255>/Constant'
           *  S-Function (sfix_bitop): '<S252>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S252>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S237>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S255>/Compare' incorporates:
           *  Constant: '<S255>/Constant'
           *  S-Function (sfix_bitop): '<S252>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S253>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S253>/Data Type Conversion'
           *  Gain: '<S253>/Gain2'
           *  Gain: '<S256>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S259>/Multiply1'
           *  Product: '<S259>/Multiply2'
           *  Product: '<S259>/Multiply3'
           *  Product: '<S259>/Multiply4'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S256>/Sum1'
           *  Sum: '<S259>/Sum2'
           *  Sum: '<S259>/Sum3'
           */
          rtb_VectorConcatenate_ar[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[1] = (real32_T)(rtb_Gain *
            FMS_ConstB.SinCos_o2 - rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S240>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S244>/Compare' incorporates:
           *  Constant: '<S244>/Constant'
           *  S-Function (sfix_bitop): '<S237>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S237>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S245>/Compare' incorporates:
           *  Constant: '<S245>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S236>/Sum2' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S240>/Switch' incorporates:
             *  Product: '<S236>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Add4_d = rtb_VectorConcatenate_ar[rtb_Compare_bv_0];
            } else {
              rtb_Add4_d = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S236>/Saturation1' incorporates:
             *  Gain: '<S241>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S237>/Logical Operator'
             *  Product: '<S236>/Multiply'
             *  Product: '<S236>/Multiply2'
             *  SignalConversion: '<S28>/Signal Copy1'
             */
            rtb_Add3_idx_1 = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_Add4_d - ((rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] *
                             FMS_U.INS_Out.y_R +
                             rtb_VectorConcatenate_i[rtb_Compare_bv_0] *
                             FMS_U.INS_Out.x_R) +
                            rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] *
                            -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Add3_idx_1 > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_Switch_dw[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Add3_idx_1 < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_Switch_dw[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_Switch_dw[rtb_Compare_bv_0] = rtb_Add3_idx_1;
            }

            /* End of Saturate: '<S236>/Saturation1' */
          }

          /* End of Sum: '<S236>/Sum2' */

          /* MultiPortSwitch: '<S171>/Index Vector' incorporates:
           *  Constant: '<S179>/Constant'
           *  Product: '<S171>/Multiply'
           *  RelationalOperator: '<S179>/Compare'
           *  S-Function (sfix_bitop): '<S176>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S176>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S176>/az_cmd valid'
           */
          rtb_TmpSignalConversionAtMath_c[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S234>/Index Vector' */

        /* Sum: '<S230>/Sum1' incorporates:
         *  Constant: '<S230>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S230>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Subtract3_o = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S231>/Abs' */
        rtb_Add3_c = fabsf(rtb_Subtract3_o);

        /* Switch: '<S231>/Switch' incorporates:
         *  Constant: '<S231>/Constant'
         *  Constant: '<S232>/Constant'
         *  Product: '<S231>/Multiply'
         *  RelationalOperator: '<S232>/Compare'
         *  Sum: '<S231>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S231>/Sign' */
          if (rtb_Subtract3_o < 0.0F) {
            rtb_Subtract3_o = -1.0F;
          } else {
            if (rtb_Subtract3_o > 0.0F) {
              rtb_Subtract3_o = 1.0F;
            }
          }

          /* End of Signum: '<S231>/Sign' */
          rtb_Subtract3_o *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S231>/Switch' */

        /* Saturate: '<S230>/Saturation' */
        if (rtb_Subtract3_o > 0.314159274F) {
          rtb_Subtract3_o = 0.314159274F;
        } else {
          if (rtb_Subtract3_o < -0.314159274F) {
            rtb_Subtract3_o = -0.314159274F;
          }
        }

        /* End of Saturate: '<S230>/Saturation' */

        /* Gain: '<S227>/Gain2' */
        rtb_Subtract3_o *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S173>/Sum' incorporates:
         *  Constant: '<S229>/Constant'
         *  Constant: '<S233>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S227>/Multiply2'
         *  Product: '<S228>/Multiply1'
         *  RelationalOperator: '<S229>/Compare'
         *  RelationalOperator: '<S233>/Compare'
         *  S-Function (sfix_bitop): '<S227>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S228>/psi_rate_cmd valid'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        rtb_Add3_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Subtract3_o
                          : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
          FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S234>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Switch_dw[0];
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Switch_dw[1];

        /* Gain: '<S234>/Gain2' */
        rtb_Subtract3_o = FMS_PARAM.Z_P * rtb_Switch_dw[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S235>/Index Vector' incorporates:
         *  Constant: '<S270>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S235>/Multiply'
         *  Product: '<S268>/Multiply'
         *  Product: '<S269>/Multiply3'
         *  RelationalOperator: '<S270>/Compare'
         *  S-Function (sfix_bitop): '<S267>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S267>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S267>/w_cmd valid'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S272>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S272>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S272>/Trigonometric Function3' incorporates:
           *  Gain: '<S271>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S272>/Gain' incorporates:
           *  Gain: '<S271>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S272>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S272>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S272>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S272>/Trigonometric Function' incorporates:
           *  Gain: '<S271>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S272>/Trigonometric Function1' incorporates:
           *  Gain: '<S271>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S272>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S235>/Multiply' incorporates:
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S267>/u_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S272>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S235>/Multiply' incorporates:
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S267>/v_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S272>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S235>/Multiply' incorporates:
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S267>/w_cmd valid'
           */
          rtb_Sign1_c_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sign1_c_idx_0
              + (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_d +
                 rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 1:
          /* SignalConversion: '<S274>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S274>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Gain: '<S273>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S269>/Subtract'
           */
          rtb_a_l = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S274>/Trigonometric Function3' incorporates:
           *  Gain: '<S273>/Gain'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(rtb_a_l);

          /* Gain: '<S274>/Gain' incorporates:
           *  Gain: '<S273>/Gain'
           *  Trigonometry: '<S274>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(rtb_a_l);

          /* SignalConversion: '<S274>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S274>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S274>/Trigonometric Function' incorporates:
           *  Gain: '<S273>/Gain'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(rtb_a_l);

          /* Trigonometry: '<S274>/Trigonometric Function1' incorporates:
           *  Gain: '<S273>/Gain'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(rtb_a_l);

          /* SignalConversion: '<S274>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S235>/Multiply' incorporates:
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S267>/u_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S274>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S235>/Multiply' incorporates:
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S267>/v_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S274>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S235>/Multiply' incorporates:
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S267>/w_cmd valid'
           */
          rtb_Sign1_c_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sign1_c_idx_0
              + (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_d +
                 rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         default:
          rtb_Switch_dw[0] = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Switch_dw[1] = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Switch_dw[2] = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S235>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Switch_dw[0] += rtb_Add3_c;
        rtb_Switch_dw[1] += rtb_Gain_fj;

        /* Sum: '<S174>/Sum1' */
        rtb_Add3_c = rtb_Subtract3_o + rtb_Switch_dw[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S191>/Switch' incorporates:
         *  Constant: '<S206>/Constant'
         *  Constant: '<S207>/Constant'
         *  Constant: '<S208>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S206>/Compare'
         *  RelationalOperator: '<S207>/Compare'
         *  RelationalOperator: '<S208>/Compare'
         *  S-Function (sfix_bitop): '<S191>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S191>/y_v_cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S191>/Logical Operator' incorporates:
           *  Constant: '<S207>/Constant'
           *  Constant: '<S208>/Constant'
           *  RelationalOperator: '<S207>/Compare'
           *  RelationalOperator: '<S208>/Compare'
           *  S-Function (sfix_bitop): '<S191>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S191>/y_v_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S191>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S172>/u_cmd_valid' */
        /* MATLAB Function: '<S203>/bit_shift' incorporates:
         *  DataTypeConversion: '<S172>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_es << 6);

        /* End of Outputs for SubSystem: '<S172>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S172>/v_cmd_valid' */
        /* MATLAB Function: '<S204>/bit_shift' incorporates:
         *  DataTypeConversion: '<S172>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S172>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S192>/Switch' incorporates:
         *  Constant: '<S210>/Constant'
         *  Constant: '<S211>/Constant'
         *  Constant: '<S213>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S210>/Compare'
         *  RelationalOperator: '<S211>/Compare'
         *  RelationalOperator: '<S213>/Compare'
         *  S-Function (sfix_bitop): '<S192>/ax_cmd'
         *  S-Function (sfix_bitop): '<S192>/ay_cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S192>/Logical Operator' incorporates:
           *  Constant: '<S211>/Constant'
           *  Constant: '<S213>/Constant'
           *  RelationalOperator: '<S211>/Compare'
           *  RelationalOperator: '<S213>/Compare'
           *  S-Function (sfix_bitop): '<S192>/ax_cmd'
           *  S-Function (sfix_bitop): '<S192>/ay_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S192>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S89>/Bus Assignment'
         *  Constant: '<S89>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S89>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = FMS_U.Auto_Cmd.p_cmd;
        FMS_Y.FMS_Out.q_cmd = FMS_U.Auto_Cmd.q_cmd;
        FMS_Y.FMS_Out.r_cmd = FMS_U.Auto_Cmd.r_cmd;
        FMS_Y.FMS_Out.phi_cmd = FMS_U.Auto_Cmd.phi_cmd;
        FMS_Y.FMS_Out.theta_cmd = FMS_U.Auto_Cmd.theta_cmd;
        FMS_Y.FMS_Out.throttle_cmd = FMS_U.Auto_Cmd.throttle_cmd;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        FMS_Y.FMS_Out.ax_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.az_cmd = rtb_TmpSignalConversionAtMath_c[2];

        /* Saturate: '<S173>/Saturation' */
        if (rtb_Add3_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Add3_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add3_idx_1;
        }

        /* End of Saturate: '<S173>/Saturation' */

        /* Saturate: '<S174>/Saturation2' */
        if (rtb_Switch_dw[0] > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (rtb_Switch_dw[0] < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_dw[0];
        }

        /* End of Saturate: '<S174>/Saturation2' */

        /* Saturate: '<S174>/Saturation1' */
        if (rtb_Switch_dw[1] > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (rtb_Switch_dw[1] < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_dw[1];
        }

        /* End of Saturate: '<S174>/Saturation1' */

        /* Saturate: '<S174>/Saturation3' */
        if (rtb_Add3_c > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S89>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S174>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S172>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S172>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S172>/throttle_cmd_valid' */
        /* BusAssignment: '<S89>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S184>/Constant'
         *  Constant: '<S185>/Constant'
         *  Constant: '<S186>/Constant'
         *  Constant: '<S187>/Constant'
         *  Constant: '<S188>/Constant'
         *  Constant: '<S189>/Constant'
         *  Constant: '<S190>/Constant'
         *  Constant: '<S209>/Constant'
         *  Constant: '<S212>/Constant'
         *  DataTypeConversion: '<S172>/Data Type Conversion10'
         *  DataTypeConversion: '<S172>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S193>/bit_shift'
         *  MATLAB Function: '<S194>/bit_shift'
         *  MATLAB Function: '<S195>/bit_shift'
         *  MATLAB Function: '<S197>/bit_shift'
         *  MATLAB Function: '<S198>/bit_shift'
         *  MATLAB Function: '<S199>/bit_shift'
         *  MATLAB Function: '<S200>/bit_shift'
         *  MATLAB Function: '<S201>/bit_shift'
         *  MATLAB Function: '<S202>/bit_shift'
         *  MATLAB Function: '<S205>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S184>/Compare'
         *  RelationalOperator: '<S185>/Compare'
         *  RelationalOperator: '<S186>/Compare'
         *  RelationalOperator: '<S187>/Compare'
         *  RelationalOperator: '<S188>/Compare'
         *  RelationalOperator: '<S189>/Compare'
         *  RelationalOperator: '<S190>/Compare'
         *  RelationalOperator: '<S209>/Compare'
         *  RelationalOperator: '<S212>/Compare'
         *  S-Function (sfix_bitop): '<S172>/p_cmd'
         *  S-Function (sfix_bitop): '<S172>/phi_cmd'
         *  S-Function (sfix_bitop): '<S172>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S172>/q_cmd'
         *  S-Function (sfix_bitop): '<S172>/r_cmd'
         *  S-Function (sfix_bitop): '<S172>/theta_cmd'
         *  S-Function (sfix_bitop): '<S172>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S191>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S192>/az_cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         *  Sum: '<S172>/Add'
         */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
          ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
           ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
          (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_md) + rtb_y_c1)
          + (((FMS_U.Auto_Cmd.cmd_mask & 33280U) > 0U) << 8)) +
          (rtb_LogicalOperator_es << 9)) + (rtb_FixPtRelationalOperator_me << 10))
          + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

        /* End of Outputs for SubSystem: '<S172>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S172>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S172>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S34>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Mission' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  UnitDelay: '<S91>/Delay Input1'
           *
           * Block description for '<S91>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S34>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S34>/Mission' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S88>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S130>/Motion Status'
           *  Chart: '<S140>/Motion State'
           *  Delay: '<S118>/Delay'
           *  Delay: '<S96>/Delay'
           *  DiscreteIntegrator: '<S114>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S99>/Integrator'
           *  DiscreteIntegrator: '<S99>/Integrator1'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S88>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S34>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Mission' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S91>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S91>/Delay Input1'
         *
         * Block description for '<S91>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S88>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S92>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S139>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S129>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S118>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S114>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S96>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S99>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S99>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S140>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S130>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* Delay: '<S118>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S114>/Switch2' incorporates:
         *  Constant: '<S114>/vel'
         *  Constant: '<S123>/Constant'
         *  RelationalOperator: '<S123>/Compare'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_a_l = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_a_l = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S114>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S91>/Delay Input1'
         *
         * Block description for '<S91>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S113>/Compare' incorporates:
         *  Constant: '<S170>/Constant'
         *  RelationalOperator: '<S170>/Compare'
         *  UnitDelay: '<S91>/Delay Input1'
         *
         * Block description for '<S91>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S114>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S140>/Motion State' incorporates:
         *  Constant: '<S140>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S140>/Square'
         *  Math: '<S140>/Square1'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sqrt: '<S140>/Sqrt'
         *  Sum: '<S140>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S139>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S139>/Hold Control' incorporates:
             *  ActionPort: '<S142>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S139>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S139>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S139>/Hold Control' incorporates:
           *  ActionPort: '<S142>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S139>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S139>/Brake Control' incorporates:
           *  ActionPort: '<S141>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S139>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S139>/Move Control' incorporates:
             *  ActionPort: '<S143>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S139>/Switch Case' */
            FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S139>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S139>/Move Control' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_i(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S139>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S139>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S130>/Motion Status' incorporates:
         *  Abs: '<S130>/Abs'
         *  Constant: '<S130>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S129>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_e;
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_e = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_e = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_e = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_e) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S129>/Hold Control' incorporates:
             *  ActionPort: '<S132>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S129>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S129>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S129>/Hold Control' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S129>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S129>/Brake Control' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S129>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S129>/Move Control' incorporates:
             *  ActionPort: '<S133>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S129>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S129>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S129>/Move Control' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S129>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S129>/Switch Case' */

        /* Switch: '<S94>/Switch' incorporates:
         *  Product: '<S118>/Multiply'
         *  Sum: '<S118>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S139>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_PARAM.VEL_X_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = -FMS_PARAM.VEL_X_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_PARAM.VEL_X_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = -FMS_PARAM.VEL_X_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S139>/Saturation1' */

          /* Saturate: '<S129>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S129>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S118>/Sum' incorporates:
           *  Delay: '<S118>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S167>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S114>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Gain_fj = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Subtract3_o = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S118>/Sum' incorporates:
           *  Delay: '<S118>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE[1];

          /* Sum: '<S114>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S126>/Sqrt' incorporates:
           *  Math: '<S126>/Square'
           *  Sum: '<S114>/Sum'
           *  Sum: '<S126>/Sum of Elements'
           */
          rtb_Gain_fj = sqrtf(rtb_Gain_fj * rtb_Gain_fj + rtb_Add4_d *
                              rtb_Add4_d);

          /* SignalConversion: '<S169>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S169>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S169>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S168>/Gain' incorporates:
           *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S166>/Add'
           */
          rtb_Add4_d = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S169>/Trigonometric Function3' */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(rtb_Add4_d);

          /* Gain: '<S169>/Gain' incorporates:
           *  Trigonometry: '<S169>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(rtb_Add4_d);

          /* SignalConversion: '<S169>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S169>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S169>/Trigonometric Function' */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(rtb_Add4_d);

          /* Trigonometry: '<S169>/Trigonometric Function1' */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(rtb_Add4_d);

          /* Switch: '<S125>/Switch2' incorporates:
           *  Constant: '<S114>/Constant2'
           *  DiscreteIntegrator: '<S114>/Acceleration_Speed'
           *  RelationalOperator: '<S125>/LowerRelop1'
           *  RelationalOperator: '<S125>/UpperRelop'
           *  Switch: '<S125>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE > rtb_a_l) {
            rtb_Add4_d = rtb_a_l;
          } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
            /* Switch: '<S125>/Switch' incorporates:
             *  Constant: '<S114>/Constant2'
             */
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S125>/Switch2' */

          /* Switch: '<S114>/Switch' */
          if (rtb_Gain_fj > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_a_l;
          } else {
            /* Gain: '<S114>/Gain' */
            rtb_Gain_fj *= 0.5F;

            /* Switch: '<S124>/Switch2' incorporates:
             *  Constant: '<S114>/Constant1'
             *  RelationalOperator: '<S124>/LowerRelop1'
             *  RelationalOperator: '<S124>/UpperRelop'
             *  Switch: '<S124>/Switch'
             */
            if (rtb_Gain_fj > rtb_a_l) {
              rtb_Gain_fj = rtb_a_l;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S124>/Switch' incorporates:
                 *  Constant: '<S114>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S124>/Switch2' */
          }

          /* End of Switch: '<S114>/Switch' */

          /* Switch: '<S114>/Switch1' incorporates:
           *  Sum: '<S114>/Sum1'
           */
          if (rtb_Add4_d - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Add4_d;
          }

          /* End of Switch: '<S114>/Switch1' */

          /* Sum: '<S167>/Sum of Elements' incorporates:
           *  Math: '<S167>/Math Function'
           */
          rtb_Add4_d = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Add3_c * rtb_Add3_c;

          /* Math: '<S167>/Math Function1' incorporates:
           *  Sum: '<S167>/Sum of Elements'
           *
           * About '<S167>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add4_d = -sqrtf(fabsf(rtb_Add4_d));
          } else {
            rtb_Add4_d = sqrtf(rtb_Add4_d);
          }

          /* End of Math: '<S167>/Math Function1' */

          /* Switch: '<S167>/Switch' incorporates:
           *  Constant: '<S167>/Constant'
           *  Product: '<S167>/Product'
           */
          if (rtb_Add4_d <= 0.0F) {
            rtb_Subtract3_o = 0.0F;
            rtb_Add3_c = 0.0F;
            rtb_Add4_d = 1.0F;
          }

          /* End of Switch: '<S167>/Switch' */

          /* Product: '<S165>/Multiply2' incorporates:
           *  Product: '<S167>/Divide'
           */
          rtb_Subtract3_o = rtb_Subtract3_o / rtb_Add4_d * rtb_Gain_fj;
          rtb_Add3_idx_1 = rtb_Add3_c / rtb_Add4_d * rtb_Gain_fj;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S120>/Sum1' incorporates:
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S120>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Gain_fj = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign1_c_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S120>/Divide' incorporates:
           *  Math: '<S121>/Square'
           *  Math: '<S122>/Square'
           *  Sqrt: '<S121>/Sqrt'
           *  Sqrt: '<S122>/Sqrt'
           *  Sum: '<S120>/Sum'
           *  Sum: '<S120>/Sum1'
           *  Sum: '<S121>/Sum of Elements'
           *  Sum: '<S122>/Sum of Elements'
           */
          rtb_Add4_d = sqrtf(rtb_Gain_fj * rtb_Gain_fj + rtb_Sign1_c_idx_0 *
                             rtb_Sign1_c_idx_0) / sqrtf(rtb_Add3_c * rtb_Add3_c
            + rtb_Add4_d * rtb_Add4_d);

          /* Saturate: '<S120>/Saturation' */
          if (rtb_Add4_d > 1.0F) {
            rtb_Add4_d = 1.0F;
          } else {
            if (rtb_Add4_d < 0.0F) {
              rtb_Add4_d = 0.0F;
            }
          }

          /* End of Saturate: '<S120>/Saturation' */

          /* Product: '<S118>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add3_idx_1 +
              rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_Subtract3_o;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S111>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S120>/Multiply'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S111>/Sum2'
           *  Sum: '<S120>/Add'
           *  Sum: '<S120>/Subtract'
           */
          rtb_Add3_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Add4_d +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_VectorConcatenate_ar[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_VectorConcatenate_ar[1];

          /* Saturate: '<S111>/Saturation1' incorporates:
           *  Product: '<S118>/Multiply'
           */
          if (rtb_Add3_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Add3_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Add3_idx_1;
          }

          /* End of Saturate: '<S111>/Saturation1' */
        }

        /* End of Switch: '<S94>/Switch' */

        /* Delay: '<S96>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S99>/Integrator1' incorporates:
         *  Delay: '<S96>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S103>/Rem' incorporates:
         *  Constant: '<S103>/Constant1'
         *  DiscreteIntegrator: '<S99>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S98>/Sum'
         */
        rtb_Rem_n = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S103>/Switch' incorporates:
         *  Abs: '<S103>/Abs'
         *  Constant: '<S103>/Constant'
         *  Constant: '<S104>/Constant'
         *  Product: '<S103>/Multiply'
         *  RelationalOperator: '<S104>/Compare'
         *  Sum: '<S103>/Add'
         */
        if (fabsf(rtb_Rem_n) > 3.14159274F) {
          /* Signum: '<S103>/Sign' */
          if (rtb_Rem_n < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Rem_n > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Rem_n;
          }

          /* End of Signum: '<S103>/Sign' */
          rtb_Rem_n -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S103>/Switch' */

        /* Gain: '<S98>/Gain2' */
        rtb_Rem_n *= FMS_PARAM.YAW_P;

        /* Saturate: '<S98>/Saturation' */
        if (rtb_Rem_n > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_n = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_n < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_n = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S98>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S92>/Bus Assignment'
         *  Constant: '<S92>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S92>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_n;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S160>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S160>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Add4_d = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S160>/Math Function1' incorporates:
         *  Sum: '<S160>/Sum of Elements'
         *
         * About '<S160>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          rtb_Rem_n = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S160>/Math Function1' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Constant: '<S160>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S160>/Product'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (rtb_Rem_n > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Rem_n;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S160>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S92>/Sum' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Subtract3_lb[0] = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Subtract3_o = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Subtract3_lb[1] = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S110>/Sum of Elements' incorporates:
         *  Math: '<S110>/Math Function'
         *  Sum: '<S92>/Sum'
         */
        rtb_Add4_d = rtb_Subtract3_o * rtb_Subtract3_o + rtb_Add3_idx_1 *
          rtb_Add3_idx_1;

        /* Math: '<S110>/Math Function1' incorporates:
         *  Sum: '<S110>/Sum of Elements'
         *
         * About '<S110>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          rtb_Rem_n = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S110>/Math Function1' */

        /* Switch: '<S110>/Switch' incorporates:
         *  Constant: '<S110>/Constant'
         *  Product: '<S110>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_MathFunction_f_idx_2 = rtb_Rem_n;
        } else {
          rtb_Subtract3_o = 0.0F;
          rtb_Add3_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S110>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S116>/NearbyRefWP' incorporates:
         *  Constant: '<S92>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_dw[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Subtract3_lb, &rtb_Add4_d);

        /* MATLAB Function: '<S116>/SearchL1RefWP' incorporates:
         *  Constant: '<S92>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Gain_fj = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Gain_fj = rtb_Add3_c * rtb_Add3_c + rtb_Gain_fj * rtb_Gain_fj;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0]) *
             (FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R) +
             (FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1]) *
             (FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_B.Cmd_In.cur_waypoint[0] *
                        FMS_B.Cmd_In.cur_waypoint[0]) +
                       FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint
                       [1]) - (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0]
          + FMS_U.INS_Out.y_R * FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Gain_fj);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Sign1_c_idx_0 = 0.0F;
        rtb_Sign1_c_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Gain_fj);
          rtb_Gain_fj = (-B - u1_tmp) / (2.0F * rtb_Gain_fj);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Gain_fj >= 0.0F) &&
              (rtb_Gain_fj <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Gain_fj);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Gain_fj >= 0.0F) && (rtb_Gain_fj <= 1.0F)) {
              rtb_Add3_c = rtb_Gain_fj;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Gain_fj);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Sign1_c_idx_0 = (FMS_B.Cmd_In.sp_waypoint[0] -
                               FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign1_c_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
                               FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S116>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Rem_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Gain_fj = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                       rtb_Rem_n + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Rem_p) / (rtb_Rem_p * rtb_Rem_p +
          rtb_Rem_n * rtb_Rem_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Gain_fj <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Gain_fj >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = rtb_Gain_fj * rtb_Rem_p + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S116>/Switch1' incorporates:
         *  Constant: '<S153>/Constant'
         *  RelationalOperator: '<S153>/Compare'
         */
        if (rtb_Add4_d <= 0.0F) {
          /* Switch: '<S116>/Switch' incorporates:
           *  Constant: '<S152>/Constant'
           *  MATLAB Function: '<S116>/SearchL1RefWP'
           *  RelationalOperator: '<S152>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Subtract3_lb[0] = rtb_Sign1_c_idx_0;
            rtb_Subtract3_lb[1] = rtb_Sign1_c_idx_1;
          } else {
            rtb_Subtract3_lb[0] = B;

            /* MATLAB Function: '<S116>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = rtb_Gain_fj * rtb_Rem_n +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }
          }

          /* End of Switch: '<S116>/Switch' */
        }

        /* End of Switch: '<S116>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S117>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Gain_fj = rtb_Subtract3_lb[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Subtract3_lb[0] = rtb_Gain_fj * rtb_Gain_fj;
        rtb_Add3_c = rtb_Gain_fj;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S117>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S161>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Gain_fj = rtb_Subtract3_lb[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S161>/Math Function' incorporates:
         *  Math: '<S159>/Square'
         */
        rtb_Add4_d = rtb_Gain_fj * rtb_Gain_fj;

        /* Sum: '<S161>/Sum of Elements' incorporates:
         *  Math: '<S161>/Math Function'
         */
        rtb_Rem_p = rtb_Add4_d + rtb_Subtract3_lb[0];

        /* Math: '<S161>/Math Function1' incorporates:
         *  Sum: '<S161>/Sum of Elements'
         *
         * About '<S161>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Rem_n = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S161>/Math Function1' */

        /* Switch: '<S161>/Switch' incorporates:
         *  Constant: '<S161>/Constant'
         *  Product: '<S161>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_Switch_dw[0] = rtb_Add3_c;
          rtb_Switch_dw[1] = rtb_Gain_fj;
          rtb_Switch_dw[2] = rtb_Rem_n;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S161>/Switch' */

        /* Product: '<S160>/Divide' */
        rtb_a_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        D = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S163>/Sum of Elements' incorporates:
         *  Math: '<S163>/Math Function'
         *  SignalConversion: '<S163>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = D * D + rtb_a_idx_0 * rtb_a_idx_0;

        /* Math: '<S163>/Math Function1' incorporates:
         *  Sum: '<S163>/Sum of Elements'
         *
         * About '<S163>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Rem_n = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S163>/Math Function1' */

        /* Switch: '<S163>/Switch' incorporates:
         *  Constant: '<S163>/Constant'
         *  Product: '<S163>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = D;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_a_idx_0;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Rem_n;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Product: '<S161>/Divide' */
        rtb_a_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Sum: '<S164>/Sum of Elements' incorporates:
         *  Math: '<S164>/Math Function'
         *  SignalConversion: '<S164>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = D * D + rtb_a_idx_0 * rtb_a_idx_0;

        /* Math: '<S164>/Math Function1' incorporates:
         *  Sum: '<S164>/Sum of Elements'
         *
         * About '<S164>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Rem_n = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S164>/Math Function1' */

        /* Switch: '<S164>/Switch' incorporates:
         *  Constant: '<S164>/Constant'
         *  Product: '<S164>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_Switch_dw[0] = D;
          rtb_Switch_dw[1] = rtb_a_idx_0;
          rtb_Switch_dw[2] = rtb_Rem_n;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S164>/Switch' */

        /* Product: '<S164>/Divide' */
        rtb_a_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];

        /* Product: '<S163>/Divide' */
        rtb_Subtract3_lb[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S110>/Divide' */
        rtb_Sign1_c_idx_0 = rtb_Subtract3_o / rtb_MathFunction_f_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S164>/Divide' incorporates:
         *  Math: '<S159>/Square'
         */
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Product: '<S163>/Divide' */
        rtb_Subtract3_lb[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S110>/Divide' */
        rtb_Sign1_c_idx_1 = rtb_Add3_idx_1 / rtb_MathFunction_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S158>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S158>/Square'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S158>/Sum of Elements'
         */
        rtb_Rem_n = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
                          * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S117>/Gain' incorporates:
         *  Math: '<S117>/Square'
         */
        rtb_Subtract3_o = rtb_Rem_n * rtb_Rem_n * 2.0F;

        /* Sum: '<S162>/Subtract' incorporates:
         *  Product: '<S162>/Multiply'
         *  Product: '<S162>/Multiply1'
         */
        rtb_Rem_n = rtb_a_idx_0 * rtb_Subtract3_lb[1] - D * rtb_Subtract3_lb[0];

        /* Signum: '<S157>/Sign1' */
        if (rtb_Rem_n < 0.0F) {
          rtb_Rem_n = -1.0F;
        } else {
          if (rtb_Rem_n > 0.0F) {
            rtb_Rem_n = 1.0F;
          }
        }

        /* End of Signum: '<S157>/Sign1' */

        /* Switch: '<S157>/Switch2' incorporates:
         *  Constant: '<S157>/Constant4'
         */
        if (rtb_Rem_n == 0.0F) {
          rtb_Rem_n = 1.0F;
        }

        /* End of Switch: '<S157>/Switch2' */

        /* DotProduct: '<S157>/Dot Product' */
        rtb_Gain_fj = rtb_Subtract3_lb[0] * rtb_a_idx_0 + rtb_Subtract3_lb[1] *
          D;

        /* Trigonometry: '<S157>/Acos' incorporates:
         *  DotProduct: '<S157>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S157>/Multiply' incorporates:
         *  Trigonometry: '<S157>/Acos'
         */
        rtb_Rem_n *= acosf(rtb_Gain_fj);

        /* Saturate: '<S117>/Saturation' */
        if (rtb_Rem_n > 1.57079637F) {
          rtb_Rem_n = 1.57079637F;
        } else {
          if (rtb_Rem_n < -1.57079637F) {
            rtb_Rem_n = -1.57079637F;
          }
        }

        /* End of Saturate: '<S117>/Saturation' */

        /* Product: '<S117>/Divide' incorporates:
         *  Constant: '<S117>/Constant'
         *  Constant: '<S92>/L1'
         *  MinMax: '<S117>/Max'
         *  MinMax: '<S117>/Min'
         *  Product: '<S117>/Multiply1'
         *  Sqrt: '<S159>/Sqrt'
         *  Sum: '<S159>/Sum of Elements'
         *  Trigonometry: '<S117>/Sin'
         */
        rtb_MathFunction_f_idx_2 = arm_sin_f32(rtb_Rem_n) * rtb_Subtract3_o /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Add4_d + rtb_Add3_c), 0.5F));

        /* Sum: '<S108>/Subtract' incorporates:
         *  Product: '<S108>/Multiply'
         *  Product: '<S108>/Multiply1'
         */
        rtb_Rem_p = rtb_Sign1_c_idx_0 * FMS_ConstB.Divide[1] - rtb_Sign1_c_idx_1
          * FMS_ConstB.Divide[0];

        /* Signum: '<S97>/Sign1' */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_p = -1.0F;
        } else {
          if (rtb_Rem_p > 0.0F) {
            rtb_Rem_p = 1.0F;
          }
        }

        /* End of Signum: '<S97>/Sign1' */

        /* Switch: '<S97>/Switch2' incorporates:
         *  Constant: '<S97>/Constant4'
         */
        if (rtb_Rem_p == 0.0F) {
          rtb_Rem_p = 1.0F;
        }

        /* End of Switch: '<S97>/Switch2' */

        /* DotProduct: '<S97>/Dot Product' */
        rtb_Add3_idx_1 = FMS_ConstB.Divide[0] * rtb_Sign1_c_idx_0 +
          FMS_ConstB.Divide[1] * rtb_Sign1_c_idx_1;

        /* Trigonometry: '<S97>/Acos' incorporates:
         *  DotProduct: '<S97>/Dot Product'
         */
        if (rtb_Add3_idx_1 > 1.0F) {
          rtb_Add3_idx_1 = 1.0F;
        } else {
          if (rtb_Add3_idx_1 < -1.0F) {
            rtb_Add3_idx_1 = -1.0F;
          }
        }

        /* Product: '<S97>/Multiply' incorporates:
         *  Trigonometry: '<S97>/Acos'
         */
        rtb_Rem_p *= acosf(rtb_Add3_idx_1);

        /* Math: '<S100>/Rem' incorporates:
         *  Constant: '<S100>/Constant1'
         *  Delay: '<S96>/Delay'
         *  Sum: '<S96>/Sum2'
         */
        rtb_Rem_n = rt_remf(rtb_Rem_p - FMS_DW.Delay_DSTATE_h, 6.28318548F);

        /* Switch: '<S100>/Switch' incorporates:
         *  Abs: '<S100>/Abs'
         *  Constant: '<S100>/Constant'
         *  Constant: '<S106>/Constant'
         *  Product: '<S100>/Multiply'
         *  RelationalOperator: '<S106>/Compare'
         *  Sum: '<S100>/Add'
         */
        if (fabsf(rtb_Rem_n) > 3.14159274F) {
          /* Signum: '<S100>/Sign' */
          if (rtb_Rem_n < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Rem_n > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Rem_n;
          }

          /* End of Signum: '<S100>/Sign' */
          rtb_Rem_n -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S100>/Switch' */

        /* Sum: '<S96>/Sum' incorporates:
         *  Delay: '<S96>/Delay'
         */
        rtb_Add3_c = rtb_Rem_n + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S105>/Multiply1' incorporates:
         *  Constant: '<S105>/const1'
         *  DiscreteIntegrator: '<S99>/Integrator'
         */
        rtb_Rem_n = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S105>/Add' incorporates:
         *  DiscreteIntegrator: '<S99>/Integrator1'
         *  Sum: '<S99>/Subtract'
         */
        rtb_Subtract3_o = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) + rtb_Rem_n;

        /* Signum: '<S105>/Sign' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Subtract3_o > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Subtract3_o;
        }

        /* End of Signum: '<S105>/Sign' */

        /* Sum: '<S105>/Add2' incorporates:
         *  Abs: '<S105>/Abs'
         *  Gain: '<S105>/Gain'
         *  Gain: '<S105>/Gain1'
         *  Product: '<S105>/Multiply2'
         *  Product: '<S105>/Multiply3'
         *  Sqrt: '<S105>/Sqrt'
         *  Sum: '<S105>/Add1'
         *  Sum: '<S105>/Subtract'
         */
        rtb_Add4_d = (sqrtf((8.0F * fabsf(rtb_Subtract3_o) + FMS_ConstB.d_j) *
                            FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F *
          rtb_Add3_c + rtb_Rem_n;

        /* Sum: '<S105>/Add4' */
        rtb_Gain_fj = (rtb_Subtract3_o - rtb_Add4_d) + rtb_Rem_n;

        /* Sum: '<S105>/Add3' */
        rtb_Add3_c = rtb_Subtract3_o + FMS_ConstB.d_j;

        /* Sum: '<S105>/Subtract1' */
        rtb_Subtract3_o -= FMS_ConstB.d_j;

        /* Signum: '<S105>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign1' */

        /* Signum: '<S105>/Sign2' */
        if (rtb_Subtract3_o < 0.0F) {
          rtb_Subtract3_o = -1.0F;
        } else {
          if (rtb_Subtract3_o > 0.0F) {
            rtb_Subtract3_o = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign2' */

        /* Sum: '<S105>/Add5' incorporates:
         *  Gain: '<S105>/Gain2'
         *  Product: '<S105>/Multiply4'
         *  Sum: '<S105>/Subtract2'
         */
        rtb_Add4_d += (rtb_Add3_c - rtb_Subtract3_o) * 0.5F * rtb_Gain_fj;

        /* Sum: '<S105>/Add6' */
        rtb_Add3_c = rtb_Add4_d + FMS_ConstB.d_j;

        /* Sum: '<S105>/Subtract3' */
        rtb_Gain_fj = rtb_Add4_d - FMS_ConstB.d_j;

        /* Product: '<S105>/Divide' */
        rtb_Sign1_c_idx_0 = rtb_Add4_d / FMS_ConstB.d_j;

        /* Signum: '<S105>/Sign5' incorporates:
         *  Signum: '<S105>/Sign6'
         */
        if (rtb_Add4_d < 0.0F) {
          rtb_Sign1_c_idx_1 = -1.0F;

          /* Signum: '<S105>/Sign6' */
          rtb_Subtract3_o = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Sign1_c_idx_1 = 1.0F;

          /* Signum: '<S105>/Sign6' */
          rtb_Subtract3_o = 1.0F;
        } else {
          rtb_Sign1_c_idx_1 = rtb_Add4_d;

          /* Signum: '<S105>/Sign6' */
          rtb_Subtract3_o = rtb_Add4_d;
        }

        /* End of Signum: '<S105>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S96>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Rem_p -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S101>/Rem' incorporates:
         *  Constant: '<S101>/Constant1'
         */
        rtb_Add4_d = rt_remf(rtb_Rem_p, 6.28318548F);

        /* Switch: '<S101>/Switch' incorporates:
         *  Abs: '<S101>/Abs'
         *  Constant: '<S101>/Constant'
         *  Constant: '<S107>/Constant'
         *  Product: '<S101>/Multiply'
         *  RelationalOperator: '<S107>/Compare'
         *  Sum: '<S101>/Add'
         */
        if (fabsf(rtb_Add4_d) > 3.14159274F) {
          /* Signum: '<S101>/Sign' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add3_idx_1 = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Add3_idx_1 = 1.0F;
          } else {
            rtb_Add3_idx_1 = rtb_Add4_d;
          }

          /* End of Signum: '<S101>/Sign' */
          rtb_Add4_d -= 6.28318548F * rtb_Add3_idx_1;
        }

        /* End of Switch: '<S101>/Switch' */

        /* Abs: '<S94>/Abs' */
        rtb_Add4_d = fabsf(rtb_Add4_d);

        /* Update for Delay: '<S118>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S112>/Constant'
         *  RelationalOperator: '<S112>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(rtb_Add4_d
          <= 0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S114>/Acceleration_Speed' incorporates:
         *  Constant: '<S114>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Product: '<S118>/Divide1' */
        rtb_Add3_idx_1 = rtb_MathFunction_f_idx_2 / rtb_a_l;

        /* Saturate: '<S118>/Saturation' */
        if (rtb_Add3_idx_1 > 0.314159274F) {
          rtb_Add3_idx_1 = 0.314159274F;
        } else {
          if (rtb_Add3_idx_1 < -0.314159274F) {
            rtb_Add3_idx_1 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S118>/Saturation' */

        /* Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Add3_idx_1;

        /* Update for Delay: '<S96>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S99>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S99>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Signum: '<S105>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign3' */

        /* Signum: '<S105>/Sign4' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign4' */

        /* Update for DiscreteIntegrator: '<S99>/Integrator' incorporates:
         *  Constant: '<S105>/const'
         *  Gain: '<S105>/Gain3'
         *  Product: '<S105>/Multiply5'
         *  Product: '<S105>/Multiply6'
         *  Sum: '<S105>/Subtract4'
         *  Sum: '<S105>/Subtract5'
         *  Sum: '<S105>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Sign1_c_idx_0 - rtb_Sign1_c_idx_1) *
          FMS_ConstB.Gain4_c * ((rtb_Add3_c - rtb_Gain_fj) * 0.5F) -
          rtb_Subtract3_o * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S99>/Integrator' */
        /* End of Outputs for SubSystem: '<S88>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Update for UnitDelay: '<S91>/Delay Input1' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S91>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S34>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S34>/Unknown' incorporates:
         *  ActionPort: '<S90>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S34>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S34>/Switch Case' */
      /* End of Outputs for SubSystem: '<S29>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S29>/Assist' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* SwitchCase: '<S33>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 3;
        break;
      }

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) && (rtPrevAction
           == 1)) {
        /* Disable for SwitchCase: '<S45>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S63>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S33>/Stabilize' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S40>/Bus Assignment'
         *  Constant: '<S40>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S40>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S87>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S87>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S84>/Gain6'
         *  Gain: '<S87>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Add4_d *
          FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S86>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S86>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S83>/Gain6'
         *  Gain: '<S86>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_Add4_d *
          FMS_PARAM.ACC_Y_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S85>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_throttle - (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S85>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S82>/Gain6'
         *  Gain: '<S85>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Add4_d
          * -FMS_PARAM.VEL_Z_LIM;

        /* End of Outputs for SubSystem: '<S33>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S33>/Altitude' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S33>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S59>/Integrator'
           *  DiscreteIntegrator: '<S59>/Integrator1'
           *  DiscreteIntegrator: '<S60>/Integrator'
           *  DiscreteIntegrator: '<S60>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S33>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S33>/Altitude' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S33>/Switch Case' incorporates:
           *  Chart: '<S46>/Motion Status'
           *  Chart: '<S64>/Motion State'
           */
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c17_FMS = 0U;
          FMS_DW.is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_DW.temporalCounter_i1_f = 0U;
          FMS_DW.is_active_c18_FMS = 0U;
          FMS_DW.is_c18_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S33>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S33>/Altitude' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S55>/Compare' incorporates:
         *  Abs: '<S46>/Abs1'
         *  Constant: '<S55>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = (fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
          FMS_PARAM.THROTTLE_DZ);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S46>/Motion Status' incorporates:
         *  Abs: '<S46>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_a < 511U) {
          FMS_DW.temporalCounter_i1_a++;
        }

        if (FMS_DW.is_active_c17_FMS == 0U) {
          FMS_DW.is_active_c17_FMS = 1U;
          FMS_DW.is_c17_FMS = FMS_IN_Move_n;
          rtb_state_c = MotionState_Move;
        } else {
          switch (FMS_DW.is_c17_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_c = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.vd) <= 0.15) ||
                (FMS_DW.temporalCounter_i1_a >= 375U)) {
              FMS_DW.is_c17_FMS = FMS_IN_Hold_d;
              rtb_state_c = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c17_FMS = FMS_IN_Move_n;
                rtb_state_c = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_c = MotionState_Hold;
            if (rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c17_FMS = FMS_IN_Move_n;
              rtb_state_c = MotionState_Move;
            }
            break;

           default:
            rtb_state_c = MotionState_Move;
            if (!rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c17_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_a = 0U;
              rtb_state_c = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S46>/Motion Status' */

        /* SwitchCase: '<S45>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S45>/Hold Control' incorporates:
             *  ActionPort: '<S48>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S45>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S45>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S45>/Hold Control' incorporates:
           *  ActionPort: '<S48>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S45>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S45>/Brake Control' incorporates:
           *  ActionPort: '<S47>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S45>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S45>/Move Control' incorporates:
           *  ActionPort: '<S49>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S54>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
            rtb_Add4_d = 0.0F;
          } else {
            rtb_Add4_d = FMS_U.Pilot_Cmd.stick_throttle -
              (-FMS_PARAM.THROTTLE_DZ);
          }

          /* End of DeadZone: '<S54>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S49>/Gain1' incorporates:
           *  Gain: '<S54>/Gain'
           */
          FMS_B.Merge = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Add4_d *
            -FMS_PARAM.VEL_Z_LIM;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S49>/Switch' incorporates:
           *  Constant: '<S51>/Land_Speed'
           *  Constant: '<S52>/Constant'
           *  Constant: '<S53>/Constant'
           *  Gain: '<S51>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S49>/Logical Operator'
           *  MinMax: '<S51>/Min'
           *  RelationalOperator: '<S52>/Compare'
           *  RelationalOperator: '<S53>/Compare'
           *  S-Function (sfix_bitop): '<S49>/cmd_p valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          if ((FMS_B.Merge > 0.0F) && ((FMS_U.INS_Out.flag & 256U) != 0U) &&
              (FMS_U.INS_Out.h_AGL <= FMS_PARAM.ASSIST_LAND_H)) {
            FMS_B.Merge = 0.5F * fminf(FMS_PARAM.LAND_SPEED, FMS_B.Merge);
          }

          /* End of Switch: '<S49>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S45>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S45>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S42>/Switch' incorporates:
         *  Constant: '<S42>/Constant'
         *  Saturate: '<S45>/Saturation1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        if (FMS_B.Compare) {
          rtb_Add3_c = 0.5F;
        } else if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S45>/Saturation1' */
          rtb_Add3_c = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S45>/Saturation1' */
          rtb_Add3_c = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S45>/Saturation1' */
          rtb_Add3_c = FMS_B.Merge;
        }

        /* End of Switch: '<S42>/Switch' */

        /* Logic: '<S43>/Logical Operator' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* RelationalOperator: '<S74>/Compare' incorporates:
         *  Abs: '<S64>/Abs1'
         *  Constant: '<S74>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtb_LogicalOperator_es = (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
          FMS_PARAM.YAW_DZ);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S64>/Motion State' incorporates:
         *  Abs: '<S64>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_f < 255U) {
          FMS_DW.temporalCounter_i1_f++;
        }

        if (FMS_DW.is_active_c18_FMS == 0U) {
          FMS_DW.is_active_c18_FMS = 1U;
          FMS_DW.is_c18_FMS = FMS_IN_Move_n;
          rtb_state_c = MotionState_Move;
        } else {
          switch (FMS_DW.is_c18_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_c = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_f >=
                 250U)) {
              FMS_DW.is_c18_FMS = FMS_IN_Hold_d;
              rtb_state_c = MotionState_Hold;
            } else {
              if (rtb_LogicalOperator_es) {
                FMS_DW.is_c18_FMS = FMS_IN_Move_n;
                rtb_state_c = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_c = MotionState_Hold;
            if (rtb_LogicalOperator_es) {
              FMS_DW.is_c18_FMS = FMS_IN_Move_n;
              rtb_state_c = MotionState_Move;
            }
            break;

           default:
            rtb_state_c = MotionState_Move;
            if (!rtb_LogicalOperator_es) {
              FMS_DW.is_c18_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_f = 0U;
              rtb_state_c = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S64>/Motion State' */

        /* SwitchCase: '<S63>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S63>/Hold Control' incorporates:
             *  ActionPort: '<S66>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S63>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S63>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S63>/Hold Control' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                            &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S63>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S63>/Brake Control' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S63>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S63>/Move Control' incorporates:
             *  ActionPort: '<S67>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S63>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S63>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S63>/Move Control' incorporates:
           *  ActionPort: '<S67>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S63>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S63>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S38>/Bus Assignment'
         *  Constant: '<S38>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S38>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  DataTypeConversion: '<S43>/Data Type Conversion'
         *  DiscreteIntegrator: '<S59>/Integrator1'
         *  DiscreteIntegrator: '<S60>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S43>/Multiply'
         *  Product: '<S43>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S63>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S38>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S38>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S38>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S63>/Saturation' */

        /* BusAssignment: '<S38>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;

        /* Product: '<S62>/Multiply1' incorporates:
         *  Constant: '<S62>/const1'
         *  DiscreteIntegrator: '<S60>/Integrator'
         */
        rtb_Sign1_c_idx_1 = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S58>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S58>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S62>/Add' incorporates:
         *  DiscreteIntegrator: '<S60>/Integrator1'
         *  Gain: '<S43>/Gain1'
         *  Gain: '<S58>/Gain'
         *  Sum: '<S60>/Subtract'
         */
        rtb_a_l = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_Add4_d * -FMS_PARAM.ROLL_PITCH_LIM)
          + rtb_Sign1_c_idx_1;

        /* Signum: '<S62>/Sign' */
        if (rtb_a_l < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_a_l;
        }

        /* End of Signum: '<S62>/Sign' */

        /* Sum: '<S62>/Add2' incorporates:
         *  Abs: '<S62>/Abs'
         *  Gain: '<S62>/Gain'
         *  Gain: '<S62>/Gain1'
         *  Product: '<S62>/Multiply2'
         *  Product: '<S62>/Multiply3'
         *  Sqrt: '<S62>/Sqrt'
         *  Sum: '<S62>/Add1'
         *  Sum: '<S62>/Subtract'
         */
        rtb_Add4_d = (sqrtf((8.0F * fabsf(rtb_a_l) + FMS_ConstB.d) *
                            FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add4_d +
          rtb_Sign1_c_idx_1;

        /* Sum: '<S62>/Add4' */
        rtb_Subtract3_o = (rtb_a_l - rtb_Add4_d) + rtb_Sign1_c_idx_1;

        /* Sum: '<S62>/Add3' */
        rtb_Add3_c = rtb_a_l + FMS_ConstB.d;

        /* Sum: '<S62>/Subtract1' */
        rtb_a_l -= FMS_ConstB.d;

        /* Signum: '<S62>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S62>/Sign1' */

        /* Signum: '<S62>/Sign2' */
        if (rtb_a_l < 0.0F) {
          rtb_a_l = -1.0F;
        } else {
          if (rtb_a_l > 0.0F) {
            rtb_a_l = 1.0F;
          }
        }

        /* End of Signum: '<S62>/Sign2' */

        /* Sum: '<S62>/Add5' incorporates:
         *  Gain: '<S62>/Gain2'
         *  Product: '<S62>/Multiply4'
         *  Sum: '<S62>/Subtract2'
         */
        rtb_Add4_d += (rtb_Add3_c - rtb_a_l) * 0.5F * rtb_Subtract3_o;

        /* Sum: '<S62>/Add6' */
        rtb_Add3_c = rtb_Add4_d + FMS_ConstB.d;

        /* Sum: '<S62>/Subtract3' */
        rtb_Gain_fj = rtb_Add4_d - FMS_ConstB.d;

        /* Product: '<S62>/Divide' */
        rtb_Add3_idx_1 = rtb_Add4_d / FMS_ConstB.d;

        /* Signum: '<S62>/Sign5' incorporates:
         *  Signum: '<S62>/Sign6'
         */
        if (rtb_Add4_d < 0.0F) {
          rtb_Sign1_c_idx_0 = -1.0F;

          /* Signum: '<S62>/Sign6' */
          rtb_Subtract3_o = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Sign1_c_idx_0 = 1.0F;

          /* Signum: '<S62>/Sign6' */
          rtb_Subtract3_o = 1.0F;
        } else {
          rtb_Sign1_c_idx_0 = rtb_Add4_d;

          /* Signum: '<S62>/Sign6' */
          rtb_Subtract3_o = rtb_Add4_d;
        }

        /* End of Signum: '<S62>/Sign5' */

        /* Product: '<S61>/Multiply1' incorporates:
         *  Constant: '<S61>/const1'
         *  DiscreteIntegrator: '<S59>/Integrator'
         */
        rtb_Sign1_c_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S57>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S57>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S61>/Add' incorporates:
         *  DiscreteIntegrator: '<S59>/Integrator1'
         *  Gain: '<S43>/Gain'
         *  Gain: '<S57>/Gain'
         *  Sum: '<S59>/Subtract'
         */
        rtb_a_l = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F - FMS_PARAM.ROLL_DZ)
                   * rtb_Add4_d * FMS_PARAM.ROLL_PITCH_LIM) + rtb_Sign1_c_idx_1;

        /* Signum: '<S61>/Sign' */
        if (rtb_a_l < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_a_l;
        }

        /* End of Signum: '<S61>/Sign' */

        /* Sum: '<S61>/Add2' incorporates:
         *  Abs: '<S61>/Abs'
         *  Gain: '<S61>/Gain'
         *  Gain: '<S61>/Gain1'
         *  Product: '<S61>/Multiply2'
         *  Product: '<S61>/Multiply3'
         *  Sqrt: '<S61>/Sqrt'
         *  Sum: '<S61>/Add1'
         *  Sum: '<S61>/Subtract'
         */
        rtb_Add4_d = (sqrtf((8.0F * fabsf(rtb_a_l) + FMS_ConstB.d_e) *
                            FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F *
          rtb_Add4_d + rtb_Sign1_c_idx_1;

        /* Sum: '<S61>/Add4' */
        rtb_Sign1_c_idx_1 += rtb_a_l - rtb_Add4_d;

        /* Sum: '<S61>/Add3' */
        rtb_MathFunction_f_idx_2 = rtb_a_l + FMS_ConstB.d_e;

        /* Sum: '<S61>/Subtract1' */
        rtb_a_l -= FMS_ConstB.d_e;

        /* Signum: '<S61>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S61>/Sign1' */

        /* Signum: '<S61>/Sign2' */
        if (rtb_a_l < 0.0F) {
          rtb_a_l = -1.0F;
        } else {
          if (rtb_a_l > 0.0F) {
            rtb_a_l = 1.0F;
          }
        }

        /* End of Signum: '<S61>/Sign2' */

        /* Sum: '<S61>/Add5' incorporates:
         *  Gain: '<S61>/Gain2'
         *  Product: '<S61>/Multiply4'
         *  Sum: '<S61>/Subtract2'
         */
        rtb_Add4_d += (rtb_MathFunction_f_idx_2 - rtb_a_l) * 0.5F *
          rtb_Sign1_c_idx_1;

        /* Update for DiscreteIntegrator: '<S59>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S59>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Update for DiscreteIntegrator: '<S60>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S60>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S62>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S62>/Sign3' */

        /* Signum: '<S62>/Sign4' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S62>/Sign4' */

        /* Update for DiscreteIntegrator: '<S60>/Integrator' incorporates:
         *  Constant: '<S62>/const'
         *  Gain: '<S62>/Gain3'
         *  Product: '<S62>/Multiply5'
         *  Product: '<S62>/Multiply6'
         *  Sum: '<S62>/Subtract4'
         *  Sum: '<S62>/Subtract5'
         *  Sum: '<S62>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Add3_idx_1 - rtb_Sign1_c_idx_0) *
          FMS_ConstB.Gain4 * ((rtb_Add3_c - rtb_Gain_fj) * 0.5F) -
          rtb_Subtract3_o * 12.566371F) * 0.004F;

        /* Sum: '<S61>/Subtract3' */
        rtb_Add3_c = rtb_Add4_d - FMS_ConstB.d_e;

        /* Sum: '<S61>/Add6' */
        rtb_Gain_fj = rtb_Add4_d + FMS_ConstB.d_e;

        /* Signum: '<S61>/Sign5' incorporates:
         *  Signum: '<S61>/Sign6'
         */
        if (rtb_Add4_d < 0.0F) {
          rtb_Subtract3_o = -1.0F;

          /* Signum: '<S61>/Sign6' */
          rtb_Sign1_c_idx_0 = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Subtract3_o = 1.0F;

          /* Signum: '<S61>/Sign6' */
          rtb_Sign1_c_idx_0 = 1.0F;
        } else {
          rtb_Subtract3_o = rtb_Add4_d;

          /* Signum: '<S61>/Sign6' */
          rtb_Sign1_c_idx_0 = rtb_Add4_d;
        }

        /* End of Signum: '<S61>/Sign5' */

        /* Signum: '<S61>/Sign3' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S61>/Sign3' */

        /* Signum: '<S61>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S61>/Sign4' */

        /* Update for DiscreteIntegrator: '<S59>/Integrator' incorporates:
         *  Constant: '<S61>/const'
         *  Gain: '<S61>/Gain3'
         *  Product: '<S61>/Divide'
         *  Product: '<S61>/Multiply5'
         *  Product: '<S61>/Multiply6'
         *  Sum: '<S61>/Subtract4'
         *  Sum: '<S61>/Subtract5'
         *  Sum: '<S61>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Add4_d / FMS_ConstB.d_e -
          rtb_Subtract3_o) * FMS_ConstB.Gain4_d * ((rtb_Gain_fj - rtb_Add3_c) *
          0.5F) - rtb_Sign1_c_idx_0 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S33>/Altitude' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S33>/Position' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S39>/Bus Assignment'
         *  Constant: '<S39>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S39>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S81>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S81>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S78>/Gain6'
         *  Gain: '<S81>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Add4_d *
          FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S80>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S80>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S77>/Gain6'
         *  Gain: '<S80>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_Add4_d *
          FMS_PARAM.ACC_Y_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S79>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_throttle - FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_Add4_d = 0.0F;
        } else {
          rtb_Add4_d = FMS_U.Pilot_Cmd.stick_throttle - (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S79>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S76>/Gain6'
         *  Gain: '<S79>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Add4_d
          * FMS_PARAM.VEL_Z_LIM;

        /* End of Outputs for SubSystem: '<S33>/Position' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S33>/Unknown' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S33>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S33>/Switch Case' */
      /* End of Outputs for SubSystem: '<S29>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S29>/Manual' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S30>/Bus Assignment'
       *  BusAssignment: '<S35>/Bus Assignment'
       *  Constant: '<S35>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S35>/Bus Assignment' incorporates:
       *  BusAssignment: '<S30>/Bus Assignment'
       *  Constant: '<S35>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S29>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S30>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S29>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S29>/Switch Case' */
    /* End of Outputs for SubSystem: '<S27>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S27>/Switch Case' */

  /* BusAssignment: '<S30>/Bus Assignment' incorporates:
   *  Constant: '<S30>/Constant'
   *  DataStoreRead: '<S30>/Data Store Read'
   *  DataTypeConversion: '<S30>/Data Type Conversion'
   *  DiscreteIntegrator: '<S415>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S30>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S415>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S415>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S12>/SetHome' incorporates:
   *  TriggerPort: '<S19>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S19>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S12>/SetHome' */

  /* Update for UnitDelay: '<S15>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  rtb_Add4_d = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Add4_d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Add4_d;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S22>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S18>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_h = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += 0.004F;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator1_DSTATE += 0.004F;
  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S8>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Add4_d = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Add4_d < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Add4_d;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S9>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_m;
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
    FMS_B.state = VehicleState_None;
    FMS_B.target_mode = PilotMode_None;
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* states (dwork) */
  (void) memset((void *)&FMS_DW, 0,
                sizeof(DW_FMS_T));

  /* external inputs */
  (void)memset(&FMS_U, 0, sizeof(ExtU_FMS_T));

  /* external outputs */
  FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

  /* Start for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Start for SwitchCase: '<S27>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S27>/Arm' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S29>/SubMode' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S36>/Return' */
  /* Start for SwitchCase: '<S373>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S363>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* End of Start for SubSystem: '<S36>/Return' */

  /* Start for IfAction SubSystem: '<S36>/Hold' */
  /* Start for SwitchCase: '<S305>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S283>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S293>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S36>/Hold' */
  /* End of Start for SubSystem: '<S29>/SubMode' */

  /* Start for IfAction SubSystem: '<S29>/Auto' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S34>/Mission' */
  /* Start for Resettable SubSystem: '<S88>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S139>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S129>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S88>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S34>/Mission' */
  /* End of Start for SubSystem: '<S29>/Auto' */

  /* Start for IfAction SubSystem: '<S29>/Assist' */
  /* Start for SwitchCase: '<S33>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S33>/Altitude' */
  /* Start for SwitchCase: '<S45>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S63>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S33>/Altitude' */
  /* End of Start for SubSystem: '<S29>/Assist' */
  /* End of Start for SubSystem: '<S27>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_active_Lost_Return = 0U;
  FMS_DW.is_Lost_Return = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = FMS_Cmd_None;
  FMS_DW.prep_takeoff = 0.0;
  FMS_DW.bl = false;
  FMS_DW.br = false;
  FMS_DW.prep_mission_takeoff = 0.0;
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S27>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S36>/Takeoff' */
  /* InitializeConditions for Delay: '<S413>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S409>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S409>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Return' */
  /* InitializeConditions for Delay: '<S352>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S353>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S348>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S400>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;

  /* InitializeConditions for Delay: '<S330>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S333>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S329>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S333>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S374>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S373>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S373>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S373>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S383>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S383>/Integrator' */
  FMS_DW.Integrator_DSTATE_bz[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S373>/Move Control' */

  /* SystemInitialize for Merge: '<S373>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S373>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S383>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S383>/Integrator' */
  FMS_DW.Integrator_DSTATE_bz[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S373>/Move Control' */

  /* SystemInitialize for Merge: '<S373>/Merge' */
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S364>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S363>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S363>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S363>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S363>/Move Control' */

  /* SystemInitialize for Merge: '<S363>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Hold' */
  /* SystemInitialize for Chart: '<S284>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S294>/Motion State' */
  FMS_DW.temporalCounter_i1_ai = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S306>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S305>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S305>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S305>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S305>/Move Control' */

  /* SystemInitialize for Merge: '<S305>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S283>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S283>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S283>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S283>/Move Control' */

  /* SystemInitialize for Merge: '<S283>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S293>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S293>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S293>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S293>/Move Control' */

  /* SystemInitialize for Merge: '<S293>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S29>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S29>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S34>/Mission' */
  /* InitializeConditions for UnitDelay: '<S91>/Delay Input1'
   *
   * Block description for '<S91>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S88>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S118>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S96>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S140>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S139>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S139>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S139>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S139>/Move Control' */

  /* SystemInitialize for Merge: '<S139>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S130>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S129>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S129>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S129>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S129>/Move Control' */

  /* SystemInitialize for Merge: '<S129>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S88>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S34>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S29>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S29>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S33>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S59>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S60>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S60>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S46>/Motion Status' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c17_FMS = 0U;
  FMS_DW.is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S45>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S45>/Hold Control' */

  /* SystemInitialize for Merge: '<S45>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Chart: '<S64>/Motion State' */
  FMS_DW.temporalCounter_i1_f = 0U;
  FMS_DW.is_active_c18_FMS = 0U;
  FMS_DW.is_c18_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S63>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S63>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S63>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S63>/Move Control' */

  /* SystemInitialize for Merge: '<S63>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S33>/Altitude' */
  /* End of SystemInitialize for SubSystem: '<S29>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S27>/Arm' */
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
