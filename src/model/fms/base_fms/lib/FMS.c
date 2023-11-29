/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2077
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Nov 29 09:57:09 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S411>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S421>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S133>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S50>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S348>/Motion State' */
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
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Loiter_p                ((uint8_T)3U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)4U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)5U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)6U)
#define FMS_IN_Waypoint                ((uint8_T)7U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
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
struct_C5XIQzgZOXj5pNdNFngVXC FMS_PARAM = {
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
  0.52359879F,
  10.0F,
  5.0F,
  5.0F,
  1.5F,
  1.0F,
  0.5F,
  0.3F,
  0.6F,
  120U,
  1U,
  1300U
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S6>/Land_Lock_Thro'
                                        *   '<S26>/Constant'
                                        *   '<S464>/Constant'
                                        *   '<S331>/L1'
                                        *   '<S47>/Gain'
                                        *   '<S47>/Gain1'
                                        *   '<S123>/Gain'
                                        *   '<S123>/Gain1'
                                        *   '<S125>/Constant'
                                        *   '<S149>/L1'
                                        *   '<S227>/Saturation'
                                        *   '<S228>/Saturation1'
                                        *   '<S228>/Saturation2'
                                        *   '<S228>/Saturation3'
                                        *   '<S372>/Land_Speed'
                                        *   '<S373>/Saturation1'
                                        *   '<S452>/Takeoff_Speed'
                                        *   '<S453>/Gain2'
                                        *   '<S453>/Saturation1'
                                        *   '<S49>/Saturation1'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S62>/Dead Zone'
                                        *   '<S62>/Gain'
                                        *   '<S67>/Saturation'
                                        *   '<S83>/Saturation1'
                                        *   '<S95>/Saturation'
                                        *   '<S108>/Saturation1'
                                        *   '<S126>/Dead Zone'
                                        *   '<S126>/Gain'
                                        *   '<S127>/Dead Zone'
                                        *   '<S127>/Gain'
                                        *   '<S132>/Saturation'
                                        *   '<S281>/Gain2'
                                        *   '<S288>/Gain1'
                                        *   '<S288>/Gain2'
                                        *   '<S337>/Saturation1'
                                        *   '<S347>/Saturation'
                                        *   '<S359>/Saturation1'
                                        *   '<S374>/Constant'
                                        *   '<S377>/Gain2'
                                        *   '<S401>/Constant'
                                        *   '<S401>/vel'
                                        *   '<S401>/Acceleration_Speed'
                                        *   '<S401>/Saturation'
                                        *   '<S401>/Switch'
                                        *   '<S405>/Constant'
                                        *   '<S52>/Gain2'
                                        *   '<S53>/Gain1'
                                        *   '<S59>/Constant'
                                        *   '<S70>/Gain2'
                                        *   '<S71>/Gain1'
                                        *   '<S78>/Constant'
                                        *   '<S86>/Gain2'
                                        *   '<S87>/Gain1'
                                        *   '<S93>/Constant'
                                        *   '<S98>/Gain2'
                                        *   '<S99>/Gain1'
                                        *   '<S106>/Constant'
                                        *   '<S111>/Gain2'
                                        *   '<S112>/Gain6'
                                        *   '<S120>/Constant'
                                        *   '<S121>/Constant'
                                        *   '<S135>/Gain2'
                                        *   '<S136>/Gain1'
                                        *   '<S143>/Constant'
                                        *   '<S168>/Gain'
                                        *   '<S168>/Saturation1'
                                        *   '<S171>/Constant'
                                        *   '<S171>/vel'
                                        *   '<S171>/Acceleration_Speed'
                                        *   '<S171>/Saturation'
                                        *   '<S171>/Switch'
                                        *   '<S175>/Constant'
                                        *   '<S340>/Gain2'
                                        *   '<S341>/Gain1'
                                        *   '<S350>/Gain2'
                                        *   '<S351>/Gain1'
                                        *   '<S362>/Gain2'
                                        *   '<S363>/Gain6'
                                        *   '<S386>/Gain2'
                                        *   '<S386>/Saturation'
                                        *   '<S387>/Integrator'
                                        *   '<S55>/Land_Speed'
                                        *   '<S56>/Constant'
                                        *   '<S58>/Dead Zone'
                                        *   '<S58>/Gain'
                                        *   '<S75>/Dead Zone'
                                        *   '<S75>/Gain'
                                        *   '<S89>/Land_Speed'
                                        *   '<S90>/Constant'
                                        *   '<S92>/Dead Zone'
                                        *   '<S92>/Gain'
                                        *   '<S103>/Dead Zone'
                                        *   '<S103>/Gain'
                                        *   '<S116>/Dead Zone'
                                        *   '<S116>/Gain'
                                        *   '<S117>/Dead Zone'
                                        *   '<S117>/Gain'
                                        *   '<S140>/Dead Zone'
                                        *   '<S140>/Gain'
                                        *   '<S155>/Gain2'
                                        *   '<S155>/Saturation'
                                        *   '<S156>/Integrator'
                                        *   '<S343>/Dead Zone'
                                        *   '<S343>/Gain'
                                        *   '<S355>/Dead Zone'
                                        *   '<S355>/Gain'
                                        *   '<S367>/Dead Zone'
                                        *   '<S367>/Gain'
                                        *   '<S368>/Dead Zone'
                                        *   '<S368>/Gain'
                                        *   '<S410>/Saturation1'
                                        *   '<S420>/Saturation1'
                                        *   '<S183>/Saturation1'
                                        *   '<S193>/Saturation1'
                                        *   '<S413>/Gain2'
                                        *   '<S414>/Gain1'
                                        *   '<S423>/Gain2'
                                        *   '<S424>/Gain6'
                                        *   '<S186>/Gain2'
                                        *   '<S187>/Gain1'
                                        *   '<S196>/Gain2'
                                        *   '<S197>/Gain6'
                                        *   '<S416>/Dead Zone'
                                        *   '<S416>/Gain'
                                        *   '<S428>/Dead Zone'
                                        *   '<S428>/Gain'
                                        *   '<S429>/Dead Zone'
                                        *   '<S429>/Gain'
                                        *   '<S189>/Dead Zone'
                                        *   '<S189>/Gain'
                                        *   '<S201>/Dead Zone'
                                        *   '<S201>/Gain'
                                        *   '<S202>/Dead Zone'
                                        *   '<S202>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S12>/Constant1'
                                        *   '<S462>/Constant'
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
static void FMS_Altitude(void);
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_exit_internal_Auto(void);
static void FMS_Auto(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Assist(void);
static void FMS_enter_internal_Auto(void);
static void FMS_enter_internal_Arm(void);
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
 *    '<S410>/Hold Control'
 *    '<S337>/Hold Control'
 *    '<S183>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S83>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S413>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S410>/Hold Control'
 *    '<S337>/Hold Control'
 *    '<S183>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S83>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S413>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S410>/Hold Control'
 *    '<S337>/Hold Control'
 *    '<S183>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S83>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S413>/Delay' incorporates:
   *  Gain: '<S415>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S413>/Gain2' incorporates:
   *  Delay: '<S413>/Delay'
   *  Gain: '<S415>/Gain'
   *  Sum: '<S413>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S413>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S410>/Brake Control'
 *    '<S337>/Brake Control'
 *    '<S347>/Brake Control'
 *    '<S183>/Brake Control'
 *    '<S132>/Brake Control'
 *    '<S49>/Brake Control'
 *    '<S67>/Brake Control'
 *    '<S83>/Brake Control'
 *    '<S95>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S412>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S412>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S410>/Move Control'
 *    '<S337>/Move Control'
 *    '<S183>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S410>/Move Control'
 *    '<S337>/Move Control'
 *    '<S183>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S410>/Move Control'
 *    '<S337>/Move Control'
 *    '<S183>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_c;
  real32_T rtb_Subtract3_dn;
  real32_T rtb_a_c;
  real32_T rtb_Add4_g;
  real32_T rtb_a_b;

  /* Product: '<S418>/Multiply1' incorporates:
   *  Constant: '<S418>/const1'
   *  DiscreteIntegrator: '<S417>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S416>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_c = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_c = 0.0F;
  } else {
    rtb_a_c = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S416>/Dead Zone' */

  /* Sum: '<S418>/Add' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator1'
   *  Gain: '<S414>/Gain1'
   *  Gain: '<S416>/Gain'
   *  Sum: '<S417>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_c * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S418>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_c = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_c = 1.0F;
  } else {
    rtb_a_c = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S418>/Sign' */

  /* Sum: '<S418>/Add2' incorporates:
   *  Abs: '<S418>/Abs'
   *  Gain: '<S418>/Gain'
   *  Gain: '<S418>/Gain1'
   *  Product: '<S418>/Multiply2'
   *  Product: '<S418>/Multiply3'
   *  Sqrt: '<S418>/Sqrt'
   *  Sum: '<S418>/Add1'
   *  Sum: '<S418>/Subtract'
   */
  rtb_a_c = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_c + rtb_Add3_c;

  /* Sum: '<S418>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_c) + rtb_Add3_c;

  /* Sum: '<S418>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S418>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S418>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S418>/Sign1' */

  /* Signum: '<S418>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S418>/Sign2' */

  /* Sum: '<S418>/Add5' incorporates:
   *  Gain: '<S418>/Gain2'
   *  Product: '<S418>/Multiply4'
   *  Sum: '<S418>/Subtract2'
   */
  rtb_a_c += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S414>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S417>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S418>/Add6' */
  rtb_Add3_c = rtb_a_c + localC->d;

  /* Sum: '<S418>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_c - localC->d;

  /* Signum: '<S418>/Sign5' */
  if (rtb_a_c < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_c > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_c;
  }

  /* End of Signum: '<S418>/Sign5' */

  /* Signum: '<S418>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S418>/Sign3' */

  /* Signum: '<S418>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S418>/Sign4' */

  /* Signum: '<S418>/Sign6' */
  if (rtb_a_c < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_c > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_c;
  }

  /* End of Signum: '<S418>/Sign6' */

  /* Update for DiscreteIntegrator: '<S417>/Integrator' incorporates:
   *  Constant: '<S418>/const'
   *  Gain: '<S418>/Gain3'
   *  Product: '<S418>/Divide'
   *  Product: '<S418>/Multiply5'
   *  Product: '<S418>/Multiply6'
   *  Sum: '<S418>/Subtract4'
   *  Sum: '<S418>/Subtract5'
   *  Sum: '<S418>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_c / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S411>/Motion Status'
 *    '<S338>/Motion Status'
 *    '<S184>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S411>/Motion Status'
 *    '<S338>/Motion Status'
 *    '<S184>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S411>/Motion Status'
 *    '<S338>/Motion Status'
 *    '<S184>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S411>/Motion Status' */
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

  /* End of Chart: '<S411>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S420>/Hold Control'
 *    '<S359>/Hold Control'
 *    '<S193>/Hold Control'
 *    '<S108>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S423>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S420>/Hold Control'
 *    '<S359>/Hold Control'
 *    '<S193>/Hold Control'
 *    '<S108>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S423>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S420>/Hold Control'
 *    '<S359>/Hold Control'
 *    '<S193>/Hold Control'
 *    '<S108>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_p, real32_T
  rtu_FMS_In_b, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_l_T *localDW)
{
  real32_T rtb_VectorConcatenate_k[9];
  real32_T rtb_VectorConcatenate_bl[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_bl_tmp;
  real32_T rtb_VectorConcatenate_bl_tmp_0;

  /* Delay: '<S423>/Delay' incorporates:
   *  SignalConversion: '<S423>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S427>/Trigonometric Function1' incorporates:
   *  Gain: '<S426>/Gain'
   *  Trigonometry: '<S427>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bl_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_bl_tmp_0;

  /* Trigonometry: '<S427>/Trigonometric Function' incorporates:
   *  Gain: '<S426>/Gain'
   *  Trigonometry: '<S427>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bl_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_bl_tmp;

  /* SignalConversion: '<S427>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S427>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S427>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_bl_tmp;

  /* Trigonometry: '<S427>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_bl_tmp_0;

  /* SignalConversion: '<S427>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S427>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S427>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S423>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S423>/Delay'
   *  SignalConversion: '<S423>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S423>/Sum'
   */
  rtb_VectorConcatenate_bl_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bl_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S423>/Multiply' incorporates:
   *  SignalConversion: '<S423>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_bl_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_bl_tmp_0;
  }

  /* End of Product: '<S423>/Multiply' */

  /* Gain: '<S423>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[1];

  /* Update for Delay: '<S423>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S420>/Brake Control'
 *    '<S359>/Brake Control'
 *    '<S193>/Brake Control'
 *    '<S108>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S422>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S420>/Move Control'
 *    '<S359>/Move Control'
 *    '<S193>/Move Control'
 *    '<S108>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S420>/Move Control'
 *    '<S359>/Move Control'
 *    '<S193>/Move Control'
 *    '<S108>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S420>/Move Control'
 *    '<S359>/Move Control'
 *    '<S193>/Move Control'
 *    '<S108>/Move Control'
 */
void FMS_MoveControl_o(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_k_T *localC,
  DW_MoveControl_FMS_d_T *localDW)
{
  real32_T rtb_Subtract3_nv;
  real32_T rtb_Add3_e1t_idx_0;
  real32_T rtb_Subtract3_h_idx_0;
  real32_T rtb_Add3_e1t_idx_1;
  real32_T rtb_Subtract3_h_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_h_idx_0_0;

  /* SignalConversion: '<S424>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S430>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S431>/Multiply1' incorporates:
   *  Constant: '<S431>/const1'
   *  DiscreteIntegrator: '<S430>/Integrator'
   */
  rtb_Add3_e1t_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S424>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S430>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S431>/Multiply1' incorporates:
   *  Constant: '<S431>/const1'
   *  DiscreteIntegrator: '<S430>/Integrator'
   */
  rtb_Add3_e1t_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S428>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S428>/Dead Zone' */

  /* Sum: '<S431>/Add' incorporates:
   *  DiscreteIntegrator: '<S430>/Integrator1'
   *  Gain: '<S424>/Gain6'
   *  Gain: '<S428>/Gain'
   *  Sum: '<S430>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1t_idx_0;

  /* DeadZone: '<S429>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S429>/Dead Zone' */

  /* Sum: '<S431>/Add' incorporates:
   *  DiscreteIntegrator: '<S430>/Integrator1'
   *  Gain: '<S424>/Gain6'
   *  Gain: '<S429>/Gain'
   *  Sum: '<S430>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1t_idx_1;

  /* Signum: '<S431>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S431>/Add2' incorporates:
   *  Abs: '<S431>/Abs'
   *  Gain: '<S431>/Gain'
   *  Gain: '<S431>/Gain1'
   *  Product: '<S431>/Multiply2'
   *  Product: '<S431>/Multiply3'
   *  Signum: '<S431>/Sign'
   *  Sqrt: '<S431>/Sqrt'
   *  Sum: '<S431>/Add1'
   *  Sum: '<S431>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e1t_idx_0;

  /* Sum: '<S431>/Add3' incorporates:
   *  Signum: '<S431>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S431>/Subtract1' incorporates:
   *  Signum: '<S431>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S431>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S431>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S431>/Add5' incorporates:
   *  Gain: '<S431>/Gain2'
   *  Product: '<S431>/Multiply4'
   *  Signum: '<S431>/Sign'
   *  Sum: '<S431>/Add2'
   *  Sum: '<S431>/Add4'
   *  Sum: '<S431>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1t_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S430>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S430>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S431>/Sign3' incorporates:
   *  Sum: '<S431>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S431>/Sign4' incorporates:
   *  Sum: '<S431>/Subtract3'
   */
  rtb_Add3_e1t_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S431>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S431>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S431>/Sign4' */
  if (rtb_Add3_e1t_idx_0 < 0.0F) {
    rtb_Add3_e1t_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1t_idx_0 > 0.0F) {
      rtb_Add3_e1t_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S431>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S430>/Integrator' incorporates:
   *  Constant: '<S431>/const'
   *  Gain: '<S431>/Gain3'
   *  Product: '<S431>/Divide'
   *  Product: '<S431>/Multiply5'
   *  Product: '<S431>/Multiply6'
   *  Sum: '<S431>/Subtract4'
   *  Sum: '<S431>/Subtract5'
   *  Sum: '<S431>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1t_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S431>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e1t_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e1t_idx_0 = 1.0F;
  } else {
    rtb_Add3_e1t_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S431>/Add2' incorporates:
   *  Abs: '<S431>/Abs'
   *  Gain: '<S431>/Gain'
   *  Gain: '<S431>/Gain1'
   *  Product: '<S431>/Multiply2'
   *  Product: '<S431>/Multiply3'
   *  Signum: '<S431>/Sign'
   *  Sqrt: '<S431>/Sqrt'
   *  Sum: '<S431>/Add1'
   *  Sum: '<S431>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e1t_idx_0 +
    rtb_Add3_e1t_idx_1;

  /* Sum: '<S431>/Add3' incorporates:
   *  Signum: '<S431>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S431>/Subtract1' incorporates:
   *  Signum: '<S431>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S431>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S431>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S431>/Add5' incorporates:
   *  Gain: '<S431>/Gain2'
   *  Product: '<S431>/Multiply4'
   *  Signum: '<S431>/Sign'
   *  Sum: '<S431>/Add2'
   *  Sum: '<S431>/Add4'
   *  Sum: '<S431>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1t_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S430>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S430>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S431>/Sign3' incorporates:
   *  Sum: '<S431>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S431>/Sign4' incorporates:
   *  Sum: '<S431>/Subtract3'
   */
  rtb_Add3_e1t_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S431>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S431>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S431>/Sign4' */
  if (rtb_Add3_e1t_idx_0 < 0.0F) {
    rtb_Add3_e1t_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1t_idx_0 > 0.0F) {
      rtb_Add3_e1t_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S431>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S430>/Integrator' incorporates:
   *  Constant: '<S431>/const'
   *  Gain: '<S431>/Gain3'
   *  Product: '<S431>/Divide'
   *  Product: '<S431>/Multiply5'
   *  Product: '<S431>/Multiply6'
   *  Sum: '<S431>/Subtract4'
   *  Sum: '<S431>/Subtract5'
   *  Sum: '<S431>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1t_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S421>/Motion State'
 *    '<S360>/Motion State'
 *    '<S194>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S421>/Motion State'
 *    '<S360>/Motion State'
 *    '<S194>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S421>/Motion State'
 *    '<S360>/Motion State'
 *    '<S194>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S421>/Motion State' */
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

  /* End of Chart: '<S421>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S403>/NearbyRefWP'
 *    '<S173>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S435>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_g;
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
 *    '<S347>/Hold Control'
 *    '<S132>/Hold Control'
 *    '<S67>/Hold Control'
 *    '<S95>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S350>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S347>/Hold Control'
 *    '<S132>/Hold Control'
 *    '<S67>/Hold Control'
 *    '<S95>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S350>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S347>/Hold Control'
 *    '<S132>/Hold Control'
 *    '<S67>/Hold Control'
 *    '<S95>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S350>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S350>/Sum' incorporates:
   *  Delay: '<S350>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S353>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S353>/Switch' incorporates:
   *  Constant: '<S353>/Constant'
   *  Constant: '<S354>/Constant'
   *  Product: '<S353>/Multiply'
   *  RelationalOperator: '<S354>/Compare'
   *  Sum: '<S353>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S353>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S353>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S353>/Switch' */

  /* Gain: '<S350>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S350>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S347>/Move Control'
 *    '<S132>/Move Control'
 *    '<S67>/Move Control'
 *    '<S95>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S356>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S356>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S347>/Move Control'
 *    '<S132>/Move Control'
 *    '<S67>/Move Control'
 *    '<S95>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S356>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S356>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S347>/Move Control'
 *    '<S132>/Move Control'
 *    '<S67>/Move Control'
 *    '<S95>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_m;
  real32_T rtb_Add4_b;
  real32_T rtb_a_p4;

  /* Product: '<S357>/Multiply1' incorporates:
   *  Constant: '<S357>/const1'
   *  DiscreteIntegrator: '<S356>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S355>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S355>/Dead Zone' */

  /* Sum: '<S357>/Add' incorporates:
   *  DiscreteIntegrator: '<S356>/Integrator1'
   *  Gain: '<S351>/Gain1'
   *  Gain: '<S355>/Gain'
   *  Sum: '<S356>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_a;

  /* Signum: '<S357>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_i;
  }

  /* End of Signum: '<S357>/Sign' */

  /* Sum: '<S357>/Add2' incorporates:
   *  Abs: '<S357>/Abs'
   *  Gain: '<S357>/Gain'
   *  Gain: '<S357>/Gain1'
   *  Product: '<S357>/Multiply2'
   *  Product: '<S357>/Multiply3'
   *  Sqrt: '<S357>/Sqrt'
   *  Sum: '<S357>/Add1'
   *  Sum: '<S357>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_a;

  /* Sum: '<S357>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_i - rtb_a_m) + rtb_Add3_a;

  /* Sum: '<S357>/Add3' */
  rtb_Add3_a = rtb_Subtract3_i + localC->d;

  /* Sum: '<S357>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S357>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S357>/Sign1' */

  /* Signum: '<S357>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S357>/Sign2' */

  /* Sum: '<S357>/Add5' incorporates:
   *  Gain: '<S357>/Gain2'
   *  Product: '<S357>/Multiply4'
   *  Sum: '<S357>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_a - rtb_Subtract3_i) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S351>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S356>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S356>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S356>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S357>/Add6' */
  rtb_Add3_a = rtb_a_m + localC->d;

  /* Sum: '<S357>/Subtract3' */
  rtb_Subtract3_i = rtb_a_m - localC->d;

  /* Signum: '<S357>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S357>/Sign5' */

  /* Signum: '<S357>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S357>/Sign3' */

  /* Signum: '<S357>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S357>/Sign4' */

  /* Signum: '<S357>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S357>/Sign6' */

  /* Update for DiscreteIntegrator: '<S356>/Integrator' incorporates:
   *  Constant: '<S357>/const'
   *  Gain: '<S357>/Gain3'
   *  Product: '<S357>/Divide'
   *  Product: '<S357>/Multiply5'
   *  Product: '<S357>/Multiply6'
   *  Sum: '<S357>/Subtract4'
   *  Sum: '<S357>/Subtract5'
   *  Sum: '<S357>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_b) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_i) * 0.5F) - rtb_a_p4 *
    15.707963F) * 0.004F;
}

/*
 * Output and update for action system:
 *    '<S37>/Unknown'
 *    '<S35>/Unknown'
 *    '<S34>/Unknown'
 *    '<S30>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S333>/Bus Assignment' incorporates:
   *  Constant: '<S333>/Constant'
   *  Constant: '<S333>/Constant2'
   *  SignalConversion: '<S333>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S333>/Bus Assignment' */
}

/*
 * System initialize for atomic system:
 *    '<S133>/Motion State'
 *    '<S68>/Motion State'
 *    '<S96>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S133>/Motion State'
 *    '<S68>/Motion State'
 *    '<S96>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S133>/Motion State'
 *    '<S68>/Motion State'
 *    '<S96>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S133>/Motion State' */
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

  /* End of Chart: '<S133>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S49>/Move Control'
 *    '<S83>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l, uint32_T
  rtu_FMS_In_i, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_kl;

  /* DeadZone: '<S58>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_kl = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_kl = 0.0F;
  } else {
    rtb_Gain1_kl = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S58>/Dead Zone' */

  /* Gain: '<S53>/Gain1' incorporates:
   *  Gain: '<S58>/Gain'
   */
  rtb_Gain1_kl = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_kl *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S55>/Land_Speed'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  Gain: '<S55>/Gain'
   *  Logic: '<S53>/Logical Operator'
   *  MinMax: '<S55>/Min'
   *  RelationalOperator: '<S56>/Compare'
   *  RelationalOperator: '<S57>/Compare'
   *  S-Function (sfix_bitop): '<S53>/cmd_p valid'
   */
  if ((rtb_Gain1_kl > 0.0F) && ((rtu_FMS_In_i & 256U) != 0U) && (rtu_FMS_In_l <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_kl);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_kl;
  }

  /* End of Switch: '<S53>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S50>/Motion Status'
 *    '<S84>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S50>/Motion Status'
 *    '<S84>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S50>/Motion Status'
 *    '<S84>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S50>/Motion Status' */
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

  /* End of Chart: '<S50>/Motion Status' */
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
  real_T rtb_Gain_lq;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S466>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S467>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S467>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S467>/Multiply1' incorporates:
   *  Product: '<S467>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S467>/Divide' incorporates:
   *  Constant: '<S467>/Constant'
   *  Constant: '<S467>/R'
   *  Sqrt: '<S467>/Sqrt'
   *  Sum: '<S467>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S467>/Product3' incorporates:
   *  Constant: '<S467>/Constant1'
   *  Product: '<S467>/Multiply1'
   *  Sum: '<S467>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S467>/Multiply2' incorporates:
   *  Trigonometry: '<S467>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S466>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S471>/Abs' incorporates:
   *  Abs: '<S474>/Abs1'
   *  Switch: '<S471>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S471>/Switch1' incorporates:
   *  Abs: '<S471>/Abs'
   *  Bias: '<S471>/Bias2'
   *  Bias: '<S471>/Bias3'
   *  Constant: '<S468>/Constant'
   *  Constant: '<S468>/Constant1'
   *  Constant: '<S473>/Constant'
   *  Gain: '<S471>/Gain1'
   *  Product: '<S471>/Multiply'
   *  RelationalOperator: '<S473>/Compare'
   *  Switch: '<S468>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S474>/Switch1' incorporates:
     *  Bias: '<S474>/Bias2'
     *  Bias: '<S474>/Bias3'
     *  Constant: '<S474>/Constant'
     *  Constant: '<S475>/Constant'
     *  Math: '<S474>/Math Function'
     *  RelationalOperator: '<S475>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S474>/Switch1' */

    /* Signum: '<S471>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S471>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S468>/Sum' incorporates:
   *  Sum: '<S466>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S466>/Multiply' incorporates:
   *  Gain: '<S466>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S470>/Switch1' incorporates:
   *  Abs: '<S470>/Abs1'
   *  Bias: '<S470>/Bias2'
   *  Bias: '<S470>/Bias3'
   *  Constant: '<S470>/Constant'
   *  Constant: '<S472>/Constant'
   *  Math: '<S470>/Math Function'
   *  RelationalOperator: '<S472>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S470>/Switch1' */

  /* Product: '<S466>/Multiply' incorporates:
   *  Gain: '<S466>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S466>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S469>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S469>/Sum2' incorporates:
   *  Product: '<S469>/Multiply1'
   *  Product: '<S469>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S469>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S469>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S469>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S463>/Data Type Conversion' incorporates:
   *  Gain: '<S466>/Gain'
   *  Sum: '<S466>/Sum1'
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

    /* Delay: '<S14>/Delay' */
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

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S14>/Delay' */
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

    /* Delay: '<S14>/Delay' */
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

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S14>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Altitude(void)
{
  /* Inport: '<Root>/INS_Out' */
  if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
  {
    FMS_B.target_mode = PilotMode_Altitude;

    /* Delay: '<S14>/Delay' */
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

     case PilotMode_Offboard:
      FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
      break;

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S14>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
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
static void FMS_Auto(void)
{
  boolean_T sf_internal_predicateOutput;
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    FMS_exit_internal_Auto();
    FMS_DW.is_Arm = FMS_IN_SubMode;
    FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
    FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
    FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
    FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
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

         case FMS_IN_Land:
          if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_1 >= 500) {
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
            FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] *
              1.0E-7;
            FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] *
              1.0E-7;
            FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                             FMS_DW.home[2]);
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
            FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] *
              1.0E-7;
            FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] *
              1.0E-7;
            FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                             FMS_DW.home[2]);
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
          } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) {
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_Mission = FMS_IN_Land;
            FMS_B.Cmd_In.sp_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.sp_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
            FMS_B.state = VehicleState_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
          } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
            FMS_DW.is_Mission = FMS_IN_Return_h;
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
            FMS_B.Cmd_In.sp_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_B.state = VehicleState_Return;
          } else if (FMS_B.on_ground) {
            FMS_DW.is_Mission = FMS_IN_Disarming;
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
            FMS_DW.is_Mission = FMS_IN_Land;
            FMS_B.Cmd_In.sp_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.sp_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
            FMS_B.state = VehicleState_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
          }
          break;

         case FMS_IN_Takeoff_d:
          if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
              FMS_B.Cmd_In.sp_waypoint[2]) {
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

          /* End of Constant: '<Root>/ACCEPT_R' */
          break;
        }
      }
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
  switch (FMS_B.target_mode) {
   case PilotMode_Acro:
    FMS_DW.is_Assist = FMS_IN_Acro;
    FMS_B.state = VehicleState_Acro;
    break;

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
static void FMS_enter_internal_Arm(void)
{
  real_T tmp;
  tmp = FMS_getArmMode(FMS_B.target_mode);
  if (tmp == 3.0) {
    FMS_DW.is_Arm = FMS_IN_Auto;
    FMS_enter_internal_Auto();
  } else if (tmp == 2.0) {
    FMS_DW.is_Arm = FMS_IN_Assist;
    FMS_enter_internal_Assist();
  } else if (tmp == 1.0) {
    FMS_DW.is_Arm = FMS_IN_Manual;
    if (FMS_B.target_mode == PilotMode_Manual) {
      FMS_DW.is_Manual = FMS_IN_Manual_g;
      FMS_B.state = VehicleState_Manual;
    } else {
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
    }
  } else {
    FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
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
  /* RelationalOperator: '<S476>/Compare' incorporates:
   *  Abs: '<S465>/Abs'
   *  Constant: '<S476>/Constant'
   *  MinMax: '<S465>/Max'
   *  Sum: '<S465>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S5>/Vehicle.StickMoved' */
  if ((FMS_B.Compare_k || ((FMS_B.BusConversion_InsertedFor_FMSSt.flag & 221U)
        != 221U)) && (FMS_B.target_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
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
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_B.on_ground;
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
          FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_B.on_ground;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            tmp = FMS_getArmMode(FMS_B.target_mode);
            if (tmp == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Auto;
              FMS_enter_internal_Auto();
            } else if (tmp == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Assist;
              FMS_enter_internal_Assist();
            } else if (tmp == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_g;
                FMS_B.state = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              }
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
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
    FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_B.on_ground;
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
      FMS_enter_internal_Assist();
    } else if (tmp == 1.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
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
      FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_B.on_ground;
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
                                 221U) == 221)) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.durationLastReferenceTick_1_n5 =
              FMS_DW.chartAbsoluteTimeCounter;
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
          FMS_Auto();
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
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
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
      /* Reshape: '<S464>/Reshape' incorporates:
       *  Constant: '<S464>/Constant'
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
      FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_B.on_ground;
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
      FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_B.on_ground;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_b = (FMS_DW.prep_takeoff == 1.0);
          guard4 = true;
        } else {
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
      } else {
        guard4 = true;
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
  real32_T rtb_DiscreteTimeIntegrator_n;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_o[3];
  uint16_T rtb_Divide_b;
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_m;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_Add4_e5;
  boolean_T rtb_Compare_lh;
  MotionState rtb_state_a;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  real32_T rtb_VectorConcatenate_bl[9];
  real32_T rtb_Sqrt_i;
  boolean_T rtb_LogicalOperator_es;
  real32_T rtb_TmpSignalConversionAtMat_hq[3];
  real32_T rtb_Sum_k[2];
  real32_T rtb_Transpose_0[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  int32_T rtb_Compare_bv_0;
  real32_T rtb_MathFunction_iq_idx_1;
  real32_T rtb_MathFunction_iq_idx_0;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_TmpSignalConversionAtMath_1;
  real32_T rtb_MathFunction_crm_idx_2;
  real32_T rtb_P_d_idx_0;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* Sqrt: '<S486>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S486>/Square'
   *  Sum: '<S486>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S482>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3_c = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_Sqrt_i = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S483>/Square' incorporates:
   *  Math: '<S484>/Square'
   *  Math: '<S485>/Square'
   */
  rtb_DiscreteTimeIntegrator_n = rtb_Add3_c * rtb_Add3_c;

  /* Math: '<S483>/Square2' incorporates:
   *  Math: '<S484>/Square2'
   *  Math: '<S485>/Square2'
   */
  rtb_Add4_e5 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S483>/Square1' incorporates:
   *  Math: '<S484>/Square1'
   *  Math: '<S485>/Square1'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S483>/Square3' incorporates:
   *  Math: '<S484>/Square3'
   *  Math: '<S485>/Square3'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Sqrt_i * rtb_Sqrt_i;

  /* Sum: '<S483>/Subtract' incorporates:
   *  Math: '<S483>/Square'
   *  Math: '<S483>/Square1'
   *  Math: '<S483>/Square2'
   *  Math: '<S483>/Square3'
   *  Sum: '<S483>/Add'
   *  Sum: '<S483>/Add1'
   */
  rtb_Transpose[0] = (rtb_DiscreteTimeIntegrator_n + rtb_MathFunction_iq_idx_0)
    - (rtb_Add4_e5 + rtb_MathFunction_iq_idx_1);

  /* Product: '<S483>/Multiply' incorporates:
   *  Product: '<S484>/Multiply'
   */
  rtb_MathFunction_crm_idx_2 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S483>/Multiply1' incorporates:
   *  Product: '<S484>/Multiply1'
   */
  rtb_TmpSignalConversionAtMath_1 = rtb_Add3_c * rtb_Sqrt_i;

  /* Gain: '<S483>/Gain' incorporates:
   *  Product: '<S483>/Multiply'
   *  Product: '<S483>/Multiply1'
   *  Sum: '<S483>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_crm_idx_2 -
                      rtb_TmpSignalConversionAtMath_1) * 2.0F;

  /* Product: '<S483>/Multiply2' incorporates:
   *  Product: '<S485>/Multiply'
   */
  rtb_TmpSignalConversionAtMath_0 = rtb_Divide_l_idx_1 * rtb_Sqrt_i;

  /* Product: '<S483>/Multiply3' incorporates:
   *  Product: '<S485>/Multiply1'
   */
  rtb_P_d_idx_0 = rtb_Add3_c * rtb_Divide_l_idx_2;

  /* Gain: '<S483>/Gain1' incorporates:
   *  Product: '<S483>/Multiply2'
   *  Product: '<S483>/Multiply3'
   *  Sum: '<S483>/Add2'
   */
  rtb_Transpose[2] = (rtb_TmpSignalConversionAtMath_0 + rtb_P_d_idx_0) * 2.0F;

  /* Gain: '<S484>/Gain' incorporates:
   *  Sum: '<S484>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_crm_idx_2 +
                      rtb_TmpSignalConversionAtMath_1) * 2.0F;

  /* Sum: '<S484>/Subtract' incorporates:
   *  Sum: '<S484>/Add'
   *  Sum: '<S484>/Add1'
   */
  rtb_Transpose[4] = (rtb_DiscreteTimeIntegrator_n + rtb_Add4_e5) -
    (rtb_MathFunction_iq_idx_0 + rtb_MathFunction_iq_idx_1);

  /* Product: '<S484>/Multiply2' incorporates:
   *  Product: '<S485>/Multiply2'
   */
  rtb_MathFunction_crm_idx_2 = rtb_Divide_l_idx_2 * rtb_Sqrt_i;

  /* Product: '<S484>/Multiply3' incorporates:
   *  Product: '<S485>/Multiply3'
   */
  rtb_TmpSignalConversionAtMath_1 = rtb_Add3_c * rtb_Divide_l_idx_1;

  /* Gain: '<S484>/Gain1' incorporates:
   *  Product: '<S484>/Multiply2'
   *  Product: '<S484>/Multiply3'
   *  Sum: '<S484>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_crm_idx_2 -
                      rtb_TmpSignalConversionAtMath_1) * 2.0F;

  /* Gain: '<S485>/Gain' incorporates:
   *  Sum: '<S485>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_TmpSignalConversionAtMath_0 - rtb_P_d_idx_0) * 2.0F;

  /* Gain: '<S485>/Gain1' incorporates:
   *  Sum: '<S485>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_crm_idx_2 +
                      rtb_TmpSignalConversionAtMath_1) * 2.0F;

  /* Sum: '<S485>/Subtract' incorporates:
   *  Sum: '<S485>/Add'
   *  Sum: '<S485>/Add1'
   */
  rtb_Transpose[8] = (rtb_DiscreteTimeIntegrator_n + rtb_MathFunction_iq_idx_1)
    - (rtb_MathFunction_iq_idx_0 + rtb_Add4_e5);

  /* Math: '<S6>/Transpose' */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_VectorConcatenate_bl[3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0];
    rtb_VectorConcatenate_bl[1 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 3];
    rtb_VectorConcatenate_bl[2 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 6];
  }

  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 9; rtb_Compare_bv_0++) {
    rtb_Transpose[rtb_Compare_bv_0] = rtb_VectorConcatenate_bl[rtb_Compare_bv_0];
  }

  /* End of Math: '<S6>/Transpose' */

  /* Product: '<S6>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_Multiply_o[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 6] *
      FMS_U.INS_Out.az + (rtb_Transpose[rtb_Compare_bv_0 + 3] * FMS_U.INS_Out.ay
                          + rtb_Transpose[rtb_Compare_bv_0] * FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S6>/Multiply' */

  /* DiscreteIntegrator: '<S477>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_o[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_o[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_o[2];
  }

  /* Product: '<S6>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S6>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S479>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S479>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Product: '<S6>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S6>/Cos'
   *  Trigonometry: '<S6>/Cos1'
   */
  rtb_Sqrt_i = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Sqrt_i > 1.0F) {
    rtb_Sqrt_i = 1.0F;
  } else {
    if (rtb_Sqrt_i < 0.9F) {
      rtb_Sqrt_i = 0.9F;
    }
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Product: '<S6>/Divide1' incorporates:
   *  Constant: '<S6>/Land_Lock_Thro'
   */
  rtb_Divide_l_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Sqrt_i;

  /* DiscreteIntegrator: '<S478>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S477>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S478>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S479>/Discrete-Time Integrator5'
   *  Logic: '<S480>/AND'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S480>/Lower Test'
   *  RelationalOperator: '<S480>/Upper Test'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  FMS_B.on_ground = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) &&
                     ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) &&
                     ((-10.306F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d <
                      FMS_DW.DiscreteTimeIntegrator5_DSTAT_k));

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  DataTypeConversion: '<S14>/Data Type Conversion2'
   *  Delay: '<S14>/Delay'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S14>/Logical Operator'
   *  Logic: '<S14>/Logical Operator1'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/FixPt Relational Operator'
   *  Switch: '<S14>/Switch1'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S14>/Switch1' incorporates:
       *  DataTypeConversion: '<S14>/Data Type Conversion1'
       *  Delay: '<S14>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S14>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S14>/Delay'
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

     case FMS_IN_Altitude:
      FMS_Altitude();
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
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
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
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
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
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
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
          && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude;
      }
      break;

     default:
      FMS_Stabilize();
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant1'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S18>/FixPt Relational Operator'
   *  RelationalOperator: '<S19>/FixPt Relational Operator'
   *  Switch: '<S13>/Switch2'
   *  UnitDelay: '<S18>/Delay Input1'
   *  UnitDelay: '<S19>/Delay Input1'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S13>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
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
   *  RelationalOperator: '<S24>/FixPt Relational Operator'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
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
   *  Constant: '<S26>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S26>/Compare'
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

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Delay: '<S10>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S9>/FixPt Relational Operator'
   *  Switch: '<S10>/Switch'
   *  UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S9>/Delay Input1':
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
   *  Constant: '<S11>/Upper Limit'
   *  Constant: '<S8>/Constant'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S11>/Upper Test'
   *  RelationalOperator: '<S8>/Compare'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_m != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_B.on_ground;
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
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
    FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_B.on_ground;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h0)) {
    FMS_DW.durationLastReferenceTick_1_b = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h0 = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_b)) {
    FMS_DW.durationLastReferenceTick_2_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_b = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < 4095U) {
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
  /* SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

  /* SwitchCase: '<S28>/Switch Case' incorporates:
   *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S30>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S420>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S410>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S359>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S337>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S347>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S35>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S145>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S193>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S183>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S145>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S34>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S132>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S49>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S67>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S83>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S108>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S95>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S30>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S28>/Disarm' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S31>/Bus Assignment'
     *  BusAssignment: '<S32>/Bus Assignment'
     *  Constant: '<S32>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S32>/Bus Assignment' incorporates:
     *  BusAssignment: '<S31>/Bus Assignment'
     *  Constant: '<S32>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;

    /* End of Outputs for SubSystem: '<S28>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S28>/Standby' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S31>/Bus Assignment'
     *  BusAssignment: '<S33>/Bus Assignment'
     *  Constant: '<S33>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S33>/Bus Assignment' incorporates:
     *  BusAssignment: '<S31>/Bus Assignment'
     *  Constant: '<S33>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

    /* End of Outputs for SubSystem: '<S28>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S28>/Arm' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* SwitchCase: '<S30>/Switch Case' */
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
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S420>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S410>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S359>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S337>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S347>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S35>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S145>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S193>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S183>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S145>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S34>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S132>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S49>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S67>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S83>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S108>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S95>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
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
      /* Outputs for IfAction SubSystem: '<S30>/SubMode' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* SwitchCase: '<S37>/Switch Case' incorporates:
       *  Math: '<S442>/Math Function'
       *  Product: '<S444>/Divide'
       *  Sum: '<S404>/Subtract'
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
          /* Disable for SwitchCase: '<S420>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S410>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S359>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S337>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S347>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Takeoff' incorporates:
           *  ActionPort: '<S332>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S460>/cur_waypoint'
           *  DiscreteIntegrator: '<S456>/Integrator'
           *  DiscreteIntegrator: '<S456>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Takeoff' incorporates:
         *  ActionPort: '<S332>/Action Port'
         */
        /* Delay: '<S460>/cur_waypoint' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j1 != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
          FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Product: '<S460>/Divide' incorporates:
         *  Delay: '<S460>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S460>/Sum1'
         *  Sum: '<S460>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Saturate: '<S460>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S460>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S461>/Trigonometric Function1' incorporates:
         *  Gain: '<S459>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S461>/Trigonometric Function3'
         */
        rtb_DiscreteTimeIntegrator_n = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[0] = rtb_DiscreteTimeIntegrator_n;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S461>/Trigonometric Function' incorporates:
         *  Gain: '<S459>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S461>/Trigonometric Function2'
         */
        rtb_Add4_e5 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[1] = rtb_Add4_e5;

        /* SignalConversion: '<S461>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S461>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S461>/Gain' */
        rtb_Transpose[3] = -rtb_Add4_e5;

        /* Trigonometry: '<S461>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_DiscreteTimeIntegrator_n;

        /* SignalConversion: '<S461>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S461>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S461>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S453>/Saturation1' */
        rtb_Add4_e5 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_iq_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S453>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S460>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S460>/Multiply'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S453>/Sum'
         *  Sum: '<S460>/Sum3'
         *  Sum: '<S460>/Sum4'
         */
        rtb_Divide_l_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
                              FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_DiscreteTimeIntegrator_n = ((FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
          FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S453>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_l_idx_1;
        }

        /* Saturate: '<S453>/Saturation1' incorporates:
         *  Gain: '<S453>/Gain2'
         *  Product: '<S453>/Multiply'
         */
        rtb_Sqrt_i = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S332>/Bus Assignment1'
         *  Constant: '<S332>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S332>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S453>/Saturation1' */
        if (rtb_Sqrt_i > rtb_Add4_e5) {
          /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_e5;
        } else if (rtb_Sqrt_i < rtb_MathFunction_iq_idx_0) {
          /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_iq_idx_0;
        } else {
          /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_i;
        }

        if (rtb_Add3_c > rtb_Add4_e5) {
          /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_e5;
        } else if (rtb_Add3_c < rtb_MathFunction_iq_idx_0) {
          /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_iq_idx_0;
        } else {
          /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S332>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S456>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S457>/Multiply1' incorporates:
         *  Constant: '<S457>/const1'
         *  DiscreteIntegrator: '<S456>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S452>/Switch' incorporates:
         *  Abs: '<S452>/Abs'
         *  Abs: '<S452>/Abs1'
         *  Constant: '<S452>/Takeoff_Speed'
         *  Constant: '<S454>/Constant'
         *  Constant: '<S455>/Constant'
         *  Gain: '<S452>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S452>/Logical Operator'
         *  RelationalOperator: '<S454>/Compare'
         *  RelationalOperator: '<S455>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S452>/Sum'
         *  Sum: '<S452>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_DiscreteTimeIntegrator_n = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_DiscreteTimeIntegrator_n = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S452>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S457>/Add' incorporates:
         *  DiscreteIntegrator: '<S456>/Integrator1'
         *  Sum: '<S456>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_a -
                              rtb_DiscreteTimeIntegrator_n) + rtb_Add3_c;

        /* Signum: '<S457>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S457>/Sign' */

        /* Sum: '<S457>/Add2' incorporates:
         *  Abs: '<S457>/Abs'
         *  Gain: '<S457>/Gain'
         *  Gain: '<S457>/Gain1'
         *  Product: '<S457>/Multiply2'
         *  Product: '<S457>/Multiply3'
         *  Sqrt: '<S457>/Sqrt'
         *  Sum: '<S457>/Add1'
         *  Sum: '<S457>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1)
          + FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_Add3_c;

        /* Sum: '<S457>/Add4' */
        rtb_Add4_e5 = (rtb_Divide_l_idx_1 - rtb_DiscreteTimeIntegrator_n) +
          rtb_Add3_c;

        /* Sum: '<S457>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d_m;

        /* Sum: '<S457>/Subtract1' */
        rtb_Divide_l_idx_1 -= FMS_ConstB.d_m;

        /* Signum: '<S457>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S457>/Sign1' */

        /* Signum: '<S457>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S457>/Sign2' */

        /* Sum: '<S457>/Add5' incorporates:
         *  Gain: '<S457>/Gain2'
         *  Product: '<S457>/Multiply4'
         *  Sum: '<S457>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_Add3_c - rtb_Divide_l_idx_1) * 0.5F
          * rtb_Add4_e5;

        /* Update for Delay: '<S460>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S456>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S456>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S457>/Add6' */
        rtb_Add3_c = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_m;

        /* Sum: '<S457>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_m;

        /* Signum: '<S457>/Sign5' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S457>/Sign5' */

        /* Signum: '<S457>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S457>/Sign3' */

        /* Signum: '<S457>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S457>/Sign4' */

        /* Signum: '<S457>/Sign6' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Sqrt_i = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Sqrt_i = 1.0F;
        } else {
          rtb_Sqrt_i = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S457>/Sign6' */

        /* Update for DiscreteIntegrator: '<S456>/Integrator' incorporates:
         *  Constant: '<S457>/const'
         *  Gain: '<S457>/Gain3'
         *  Product: '<S457>/Divide'
         *  Product: '<S457>/Multiply5'
         *  Product: '<S457>/Multiply6'
         *  Sum: '<S457>/Subtract4'
         *  Sum: '<S457>/Subtract5'
         *  Sum: '<S457>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_m - rtb_Add4_e5) * FMS_ConstB.Gain4_a * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_Sqrt_i * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S37>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Land' incorporates:
           *  ActionPort: '<S330>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S375>/Integrator'
           *  DiscreteIntegrator: '<S375>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Land' incorporates:
         *  ActionPort: '<S330>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S380>/Trigonometric Function1' incorporates:
         *  Gain: '<S379>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S380>/Trigonometric Function' incorporates:
         *  Gain: '<S379>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S380>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S380>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S380>/Gain' incorporates:
         *  Gain: '<S379>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S380>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S380>/Trigonometric Function3' incorporates:
         *  Gain: '<S379>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S380>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S380>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S380>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S373>/Saturation1' */
        rtb_Add4_e5 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_iq_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S377>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S377>/Sum'
         */
        rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S377>/Multiply' incorporates:
         *  SignalConversion: '<S377>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_l_idx_1;
        }

        /* End of Product: '<S377>/Multiply' */

        /* Saturate: '<S373>/Saturation1' incorporates:
         *  Gain: '<S377>/Gain2'
         */
        rtb_Sqrt_i = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S330>/Bus Assignment1'
         *  Constant: '<S330>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S330>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S373>/Saturation1' */
        if (rtb_Sqrt_i > rtb_Add4_e5) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_e5;
        } else if (rtb_Sqrt_i < rtb_MathFunction_iq_idx_0) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_iq_idx_0;
        } else {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_i;
        }

        if (rtb_Add3_c > rtb_Add4_e5) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_e5;
        } else if (rtb_Add3_c < rtb_MathFunction_iq_idx_0) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_iq_idx_0;
        } else {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S375>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S376>/Multiply1' incorporates:
         *  Constant: '<S376>/const1'
         *  DiscreteIntegrator: '<S375>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S372>/Switch' incorporates:
         *  Constant: '<S372>/Land_Speed'
         *  Constant: '<S374>/Constant'
         *  Gain: '<S372>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S372>/Logical Operator'
         *  RelationalOperator: '<S374>/Compare'
         *  S-Function (sfix_bitop): '<S372>/cmd_p valid'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_DiscreteTimeIntegrator_n = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S372>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S376>/Add' incorporates:
         *  DiscreteIntegrator: '<S375>/Integrator1'
         *  Sum: '<S375>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_j -
                              rtb_DiscreteTimeIntegrator_n) + rtb_Add3_c;

        /* Signum: '<S376>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S376>/Sign' */

        /* Sum: '<S376>/Add2' incorporates:
         *  Abs: '<S376>/Abs'
         *  Gain: '<S376>/Gain'
         *  Gain: '<S376>/Gain1'
         *  Product: '<S376>/Multiply2'
         *  Product: '<S376>/Multiply3'
         *  Sqrt: '<S376>/Sqrt'
         *  Sum: '<S376>/Add1'
         *  Sum: '<S376>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1)
          + FMS_ConstB.d_p) * FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_Add3_c;

        /* Sum: '<S376>/Add4' */
        rtb_Add4_e5 = (rtb_Divide_l_idx_1 - rtb_DiscreteTimeIntegrator_n) +
          rtb_Add3_c;

        /* Sum: '<S376>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d_p;

        /* Sum: '<S376>/Subtract1' */
        rtb_Divide_l_idx_1 -= FMS_ConstB.d_p;

        /* Signum: '<S376>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S376>/Sign1' */

        /* Signum: '<S376>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S376>/Sign2' */

        /* Sum: '<S376>/Add5' incorporates:
         *  Gain: '<S376>/Gain2'
         *  Product: '<S376>/Multiply4'
         *  Sum: '<S376>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_Add3_c - rtb_Divide_l_idx_1) * 0.5F
          * rtb_Add4_e5;

        /* Update for DiscreteIntegrator: '<S375>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S375>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S376>/Add6' */
        rtb_Add3_c = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_p;

        /* Sum: '<S376>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_p;

        /* Signum: '<S376>/Sign5' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S376>/Sign5' */

        /* Signum: '<S376>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S376>/Sign3' */

        /* Signum: '<S376>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S376>/Sign4' */

        /* Signum: '<S376>/Sign6' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Sqrt_i = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Sqrt_i = 1.0F;
        } else {
          rtb_Sqrt_i = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S376>/Sign6' */

        /* Update for DiscreteIntegrator: '<S375>/Integrator' incorporates:
         *  Constant: '<S376>/const'
         *  Gain: '<S376>/Gain3'
         *  Product: '<S376>/Divide'
         *  Product: '<S376>/Multiply5'
         *  Product: '<S376>/Multiply6'
         *  Sum: '<S376>/Subtract4'
         *  Sum: '<S376>/Subtract5'
         *  Sum: '<S376>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_p - rtb_Add4_e5) * FMS_ConstB.Gain4_e * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_Sqrt_i * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S37>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S331>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S383>/Delay'
           *  Delay: '<S384>/Delay'
           *  Delay: '<S405>/Delay'
           *  DiscreteIntegrator: '<S387>/Integrator'
           *  DiscreteIntegrator: '<S387>/Integrator1'
           *  DiscreteIntegrator: '<S401>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S406>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S447>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_d = 0U;
          FMS_DW.Acceleration_Speed_DSTATE_k = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetS_g = 0;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Return' */

          /* SystemReset for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S331>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S411>/Motion Status'
           *  Chart: '<S421>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S37>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Return' incorporates:
         *  ActionPort: '<S331>/Action Port'
         */
        /* Delay: '<S405>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* RelationalOperator: '<S400>/Compare' incorporates:
         *  Constant: '<S451>/Constant'
         *  DiscreteIntegrator: '<S406>/Discrete-Time Integrator'
         *  RelationalOperator: '<S451>/Compare'
         */
        rtb_Compare_lh = (FMS_DW.DiscreteTimeIntegrator_DSTATE_d <= 3);

        /* DiscreteIntegrator: '<S401>/Acceleration_Speed' */
        if (rtb_Compare_lh || (FMS_DW.Acceleration_Speed_PrevResetS_g != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_k = 0.0F;
        }

        if (FMS_DW.Acceleration_Speed_DSTATE_k >= FMS_PARAM.CRUISE_SPEED) {
          FMS_DW.Acceleration_Speed_DSTATE_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          if (FMS_DW.Acceleration_Speed_DSTATE_k <= 0.0F) {
            FMS_DW.Acceleration_Speed_DSTATE_k = 0.0F;
          }
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S421>/Motion State' incorporates:
         *  Constant: '<S421>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S421>/Square'
         *  Math: '<S421>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S421>/Sqrt'
         *  Sum: '<S421>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S420>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S420>/Hold Control' incorporates:
             *  ActionPort: '<S423>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S420>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S420>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S420>/Hold Control' incorporates:
           *  ActionPort: '<S423>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S420>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S420>/Brake Control' incorporates:
           *  ActionPort: '<S422>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S420>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S420>/Move Control' incorporates:
             *  ActionPort: '<S424>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S420>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S420>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S420>/Move Control' incorporates:
           *  ActionPort: '<S424>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S420>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S420>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S411>/Motion Status' incorporates:
         *  Abs: '<S411>/Abs'
         *  Constant: '<S411>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S410>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S410>/Hold Control' incorporates:
             *  ActionPort: '<S413>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S410>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S410>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S410>/Hold Control' incorporates:
           *  ActionPort: '<S413>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S410>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S410>/Brake Control' incorporates:
           *  ActionPort: '<S412>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S410>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S410>/Move Control' incorporates:
             *  ActionPort: '<S414>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S410>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S410>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S410>/Move Control' incorporates:
           *  ActionPort: '<S414>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S410>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S410>/Switch Case' */

        /* Switch: '<S382>/Switch' incorporates:
         *  Product: '<S405>/Multiply'
         *  Sum: '<S405>/Sum'
         */
        if (rtb_Compare_lh) {
          /* Saturate: '<S420>/Saturation1' */
          if (FMS_B.Merge_mv[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[0] = FMS_B.Merge_mv[0];
          }

          if (FMS_B.Merge_mv[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[1] = FMS_B.Merge_mv[1];
          }

          /* End of Saturate: '<S420>/Saturation1' */

          /* Saturate: '<S410>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMat_hq[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMat_hq[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S410>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S405>/Sum' incorporates:
           *  Delay: '<S405>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S448>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMat_hq[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S401>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_d_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Add3_c = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S405>/Sum' incorporates:
           *  Delay: '<S405>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S401>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S407>/Sqrt' incorporates:
           *  Math: '<S407>/Square'
           *  Sum: '<S401>/Sum'
           *  Sum: '<S407>/Sum of Elements'
           */
          rtb_Sqrt_i = sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
                             rtb_TmpSignalConversionAtMath_0 *
                             rtb_TmpSignalConversionAtMath_0);

          /* SignalConversion: '<S450>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* SignalConversion: '<S450>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S450>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S449>/Gain' incorporates:
           *  DiscreteIntegrator: '<S447>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S447>/Add'
           */
          rtb_Add4_e5 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S450>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S450>/Trigonometric Function1'
           */
          rtb_DiscreteTimeIntegrator_n = arm_cos_f32(rtb_Add4_e5);
          rtb_Transpose[4] = rtb_DiscreteTimeIntegrator_n;

          /* Trigonometry: '<S450>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S450>/Trigonometric Function'
           */
          rtb_Add4_e5 = arm_sin_f32(rtb_Add4_e5);

          /* Gain: '<S450>/Gain' incorporates:
           *  Trigonometry: '<S450>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Add4_e5;

          /* SignalConversion: '<S450>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S450>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S450>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Add4_e5;

          /* Trigonometry: '<S450>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_DiscreteTimeIntegrator_n;

          /* Switch: '<S401>/Switch' incorporates:
           *  Constant: '<S401>/vel'
           */
          if (rtb_Sqrt_i > FMS_PARAM.L1) {
            rtb_Add4_e5 = FMS_PARAM.CRUISE_SPEED;
          } else {
            /* Gain: '<S401>/Gain' */
            rtb_Add4_e5 = 0.5F * rtb_Sqrt_i;

            /* Saturate: '<S401>/Saturation' */
            if (rtb_Add4_e5 > FMS_PARAM.CRUISE_SPEED) {
              rtb_Add4_e5 = FMS_PARAM.CRUISE_SPEED;
            } else {
              if (rtb_Add4_e5 < 0.5F) {
                rtb_Add4_e5 = 0.5F;
              }
            }

            /* End of Saturate: '<S401>/Saturation' */
          }

          /* End of Switch: '<S401>/Switch' */

          /* Switch: '<S401>/Switch1' incorporates:
           *  DiscreteIntegrator: '<S401>/Acceleration_Speed'
           *  Sum: '<S401>/Sum1'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_k - rtb_Add4_e5 < 0.0F) {
            rtb_Add4_e5 = FMS_DW.Acceleration_Speed_DSTATE_k;
          }

          /* End of Switch: '<S401>/Switch1' */

          /* Sum: '<S448>/Sum of Elements' incorporates:
           *  Math: '<S448>/Math Function'
           */
          rtb_DiscreteTimeIntegrator_n = rtb_TmpSignalConversionAtMat_hq[0] *
            rtb_TmpSignalConversionAtMat_hq[0] + rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_1;

          /* Math: '<S448>/Math Function1' incorporates:
           *  Sum: '<S448>/Sum of Elements'
           *
           * About '<S448>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
            rtb_Sqrt_i = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
          } else {
            rtb_Sqrt_i = sqrtf(rtb_DiscreteTimeIntegrator_n);
          }

          /* End of Math: '<S448>/Math Function1' */

          /* Switch: '<S448>/Switch' incorporates:
           *  Constant: '<S448>/Constant'
           *  Product: '<S448>/Product'
           */
          if (rtb_Sqrt_i <= 0.0F) {
            rtb_Add3_c = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Sqrt_i = 1.0F;
          }

          /* End of Switch: '<S448>/Switch' */

          /* Product: '<S446>/Multiply2' incorporates:
           *  Product: '<S448>/Divide'
           */
          rtb_Add3_c = rtb_Add3_c / rtb_Sqrt_i * rtb_Add4_e5;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Sqrt_i * rtb_Add4_e5;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMat_hq[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[rtb_Compare_bv_0] * rtb_Add3_c;
          }
        }

        /* End of Switch: '<S382>/Switch' */

        /* Delay: '<S384>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S387>/Integrator1' incorporates:
         *  Delay: '<S384>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S391>/Rem' incorporates:
         *  Constant: '<S391>/Constant1'
         *  DiscreteIntegrator: '<S387>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S386>/Sum'
         */
        rtb_Add3_c = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S391>/Switch' incorporates:
         *  Abs: '<S391>/Abs'
         *  Constant: '<S391>/Constant'
         *  Constant: '<S392>/Constant'
         *  Product: '<S391>/Multiply'
         *  RelationalOperator: '<S392>/Compare'
         *  Sum: '<S391>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S391>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S391>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S391>/Switch' */

        /* Gain: '<S386>/Gain2' */
        rtb_Add3_c *= FMS_PARAM.YAW_P;

        /* Saturate: '<S386>/Saturation' */
        if (rtb_Add3_c > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Add3_c = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Add3_c < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add3_c = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S386>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S331>/Bus Assignment1'
         *  Constant: '<S331>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S331>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMat_hq[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMat_hq[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMat_hq[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add3_c;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S441>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S441>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S439>/Sum of Elements'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S441>/Math Function1' incorporates:
         *  Sum: '<S441>/Sum of Elements'
         *
         * About '<S441>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_Add3_c = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S441>/Math Function1' */

        /* Switch: '<S441>/Switch' incorporates:
         *  Constant: '<S441>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S441>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Add3_c > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMat_hq[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMat_hq[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMat_hq[2] = rtb_Add3_c;
        } else {
          rtb_TmpSignalConversionAtMat_hq[0] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[1] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[2] = 1.0F;
        }

        /* End of Switch: '<S441>/Switch' */

        /* Delay: '<S383>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S331>/Sum' incorporates:
         *  Delay: '<S383>/Delay'
         *  MATLAB Function: '<S403>/OutRegionRegWP'
         *  MATLAB Function: '<S403>/SearchL1RefWP'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S398>/Sum of Elements' incorporates:
         *  Math: '<S398>/Math Function'
         *  Sum: '<S331>/Sum'
         */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S398>/Math Function1' incorporates:
         *  Sum: '<S398>/Sum of Elements'
         *
         * About '<S398>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S398>/Math Function1' */

        /* Switch: '<S398>/Switch' incorporates:
         *  Constant: '<S398>/Constant'
         *  Product: '<S398>/Product'
         *  Sum: '<S331>/Sum'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_Add4_e5 = rtb_TmpSignalConversionAtMath_0;
          rtb_Sqrt_i = rtb_P_d_idx_0;
          rtb_MathFunction_crm_idx_2 = rtb_Add3_c;
        } else {
          rtb_Add4_e5 = 0.0F;
          rtb_Sqrt_i = 0.0F;
          rtb_MathFunction_crm_idx_2 = 1.0F;
        }

        /* End of Switch: '<S398>/Switch' */

        /* Product: '<S441>/Divide' */
        rtb_Sum_k[0] = rtb_TmpSignalConversionAtMat_hq[0] /
          rtb_TmpSignalConversionAtMat_hq[2];
        rtb_Sum_k[1] = rtb_TmpSignalConversionAtMat_hq[1] /
          rtb_TmpSignalConversionAtMat_hq[2];

        /* Sum: '<S444>/Sum of Elements' incorporates:
         *  Math: '<S444>/Math Function'
         *  SignalConversion: '<S444>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] *
          rtb_Sum_k[0];

        /* Math: '<S444>/Math Function1' incorporates:
         *  Sum: '<S444>/Sum of Elements'
         *
         * About '<S444>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S444>/Math Function1' */

        /* Switch: '<S444>/Switch' incorporates:
         *  Constant: '<S444>/Constant'
         *  Product: '<S444>/Product'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_TmpSignalConversionAtMat_hq[0] = rtb_Sum_k[1];
          rtb_TmpSignalConversionAtMat_hq[1] = rtb_Sum_k[0];
          rtb_TmpSignalConversionAtMat_hq[2] = rtb_Add3_c;
        } else {
          rtb_TmpSignalConversionAtMat_hq[0] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[1] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[2] = 1.0F;
        }

        /* End of Switch: '<S444>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S403>/NearbyRefWP' incorporates:
         *  Constant: '<S331>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_k,
                        &rtb_TmpSignalConversionAtMath_1);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S403>/SearchL1RefWP' incorporates:
         *  Constant: '<S331>/L1'
         *  Delay: '<S383>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_P_d_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
             rtb_TmpSignalConversionAtMath_0 * (FMS_DW.Delay_DSTATE_p[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Divide_l_idx_1);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_MathFunction_iq_idx_0 = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Divide_l_idx_1);
          rtb_Divide_l_idx_1 = (-B - u1_tmp) / (2.0F * rtb_Divide_l_idx_1);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Divide_l_idx_1 >= 0.0F) &&
              (rtb_Divide_l_idx_1 <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Divide_l_idx_1);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Divide_l_idx_1 >= 0.0F) && (rtb_Divide_l_idx_1 <= 1.0F)) {
              rtb_Add3_c = rtb_Divide_l_idx_1;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Divide_l_idx_1);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_iq_idx_0 = rtb_P_d_idx_0 * rtb_Add3_c +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_iq_idx_1 = rtb_TmpSignalConversionAtMath_0 *
            rtb_Add3_c + FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S403>/OutRegionRegWP' incorporates:
         *  Delay: '<S383>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_l_idx_1 = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                              rtb_TmpSignalConversionAtMath_0 +
                              (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0]) *
                              rtb_P_d_idx_0) / (rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_l_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_d_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          rtb_P_d_idx_0 = rtb_Divide_l_idx_1 * rtb_P_d_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S403>/Switch1' incorporates:
         *  Constant: '<S434>/Constant'
         *  RelationalOperator: '<S434>/Compare'
         */
        if (rtb_TmpSignalConversionAtMath_1 <= 0.0F) {
          /* Switch: '<S403>/Switch' incorporates:
           *  Constant: '<S433>/Constant'
           *  MATLAB Function: '<S403>/SearchL1RefWP'
           *  RelationalOperator: '<S433>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_k[0] = rtb_MathFunction_iq_idx_0;
            rtb_Sum_k[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Sum_k[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S403>/OutRegionRegWP' incorporates:
             *  Delay: '<S383>/Delay'
             *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_k[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Sum_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Sum_k[1] = rtb_Divide_l_idx_1 *
                rtb_TmpSignalConversionAtMath_0 + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S403>/Switch' */
        }

        /* End of Switch: '<S403>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S404>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_P_d_idx_0 = rtb_Sum_k[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Sum_k[0] = rtb_P_d_idx_0;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S404>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S442>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_P_d_idx_0 = rtb_Sum_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S442>/Math Function' incorporates:
         *  Math: '<S440>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Sum: '<S442>/Sum of Elements' incorporates:
         *  Math: '<S442>/Math Function'
         */
        rtb_Add3_c = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S442>/Math Function1' incorporates:
         *  Sum: '<S442>/Sum of Elements'
         *
         * About '<S442>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S442>/Math Function1' */

        /* Switch: '<S442>/Switch' incorporates:
         *  Constant: '<S442>/Constant'
         *  Product: '<S442>/Product'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_k[0];
          rtb_MatrixConcatenate3[1] = rtb_P_d_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Add3_c;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S442>/Switch' */

        /* Product: '<S442>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S445>/Sum of Elements' incorporates:
         *  Math: '<S445>/Math Function'
         *  SignalConversion: '<S445>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtMath_1 *
          rtb_TmpSignalConversionAtMath_1;

        /* Math: '<S445>/Math Function1' incorporates:
         *  Sum: '<S445>/Sum of Elements'
         *
         * About '<S445>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S445>/Math Function1' */

        /* Switch: '<S445>/Switch' incorporates:
         *  Constant: '<S445>/Constant'
         *  Product: '<S445>/Product'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_MatrixConcatenate3[1] = rtb_TmpSignalConversionAtMath_1;
          rtb_MatrixConcatenate3[2] = rtb_Add3_c;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S445>/Switch' */

        /* Product: '<S445>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S440>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sum_k[0] * rtb_Sum_k[0];

        /* Product: '<S398>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_Add4_e5 / rtb_MathFunction_crm_idx_2;
        rtb_Sum_k[0] = rtb_TmpSignalConversionAtMat_hq[0] /
          rtb_TmpSignalConversionAtMat_hq[2];

        /* Product: '<S445>/Divide' incorporates:
         *  Product: '<S444>/Divide'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S444>/Divide' */
        rtb_P_d_idx_0 = rtb_TmpSignalConversionAtMat_hq[1] /
          rtb_TmpSignalConversionAtMat_hq[2];

        /* Product: '<S398>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Sqrt_i / rtb_MathFunction_crm_idx_2;

        /* Sqrt: '<S439>/Sqrt' */
        rtb_Add3_c = sqrtf(rtb_DiscreteTimeIntegrator_n);

        /* Gain: '<S404>/Gain' incorporates:
         *  Math: '<S404>/Square'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_Add3_c * rtb_Add3_c * 2.0F;

        /* Sum: '<S443>/Subtract' incorporates:
         *  Product: '<S443>/Multiply'
         *  Product: '<S443>/Multiply1'
         */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_1 * rtb_P_d_idx_0 -
          rtb_TmpSignalConversionAtMath_0 * rtb_Sum_k[0];

        /* Signum: '<S438>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S438>/Sign1' */

        /* Switch: '<S438>/Switch2' incorporates:
         *  Constant: '<S438>/Constant4'
         */
        if (rtb_Add3_c == 0.0F) {
          rtb_Add3_c = 1.0F;
        }

        /* End of Switch: '<S438>/Switch2' */

        /* DotProduct: '<S438>/Dot Product' */
        rtb_P_d_idx_0 = rtb_Sum_k[0] * rtb_TmpSignalConversionAtMath_1 +
          rtb_P_d_idx_0 * rtb_TmpSignalConversionAtMath_0;

        /* Trigonometry: '<S438>/Acos' incorporates:
         *  DotProduct: '<S438>/Dot Product'
         */
        if (rtb_P_d_idx_0 > 1.0F) {
          rtb_P_d_idx_0 = 1.0F;
        } else {
          if (rtb_P_d_idx_0 < -1.0F) {
            rtb_P_d_idx_0 = -1.0F;
          }
        }

        /* Product: '<S438>/Multiply' incorporates:
         *  Trigonometry: '<S438>/Acos'
         */
        rtb_Add3_c *= acosf(rtb_P_d_idx_0);

        /* Saturate: '<S404>/Saturation' */
        if (rtb_Add3_c > 1.57079637F) {
          rtb_Add3_c = 1.57079637F;
        } else {
          if (rtb_Add3_c < -1.57079637F) {
            rtb_Add3_c = -1.57079637F;
          }
        }

        /* End of Saturate: '<S404>/Saturation' */

        /* Product: '<S404>/Divide' incorporates:
         *  Constant: '<S331>/L1'
         *  Constant: '<S404>/Constant'
         *  MinMax: '<S404>/Max'
         *  MinMax: '<S404>/Min'
         *  Product: '<S404>/Multiply1'
         *  Sqrt: '<S440>/Sqrt'
         *  Sum: '<S440>/Sum of Elements'
         *  Trigonometry: '<S404>/Sin'
         */
        rtb_DiscreteTimeIntegrator_n = arm_sin_f32(rtb_Add3_c) *
          rtb_DiscreteTimeIntegrator_n / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S396>/Subtract' incorporates:
         *  Product: '<S396>/Multiply'
         *  Product: '<S396>/Multiply1'
         */
        rtb_MathFunction_crm_idx_2 = rtb_MathFunction_iq_idx_0 *
          FMS_ConstB.Divide_d[1] - rtb_MathFunction_iq_idx_1 *
          FMS_ConstB.Divide_d[0];

        /* Signum: '<S385>/Sign1' */
        if (rtb_MathFunction_crm_idx_2 < 0.0F) {
          rtb_MathFunction_crm_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_crm_idx_2 > 0.0F) {
            rtb_MathFunction_crm_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S385>/Sign1' */

        /* Switch: '<S385>/Switch2' incorporates:
         *  Constant: '<S385>/Constant4'
         */
        if (rtb_MathFunction_crm_idx_2 == 0.0F) {
          rtb_MathFunction_crm_idx_2 = 1.0F;
        }

        /* End of Switch: '<S385>/Switch2' */

        /* DotProduct: '<S385>/Dot Product' */
        rtb_Sqrt_i = FMS_ConstB.Divide_d[0] * rtb_MathFunction_iq_idx_0 +
          FMS_ConstB.Divide_d[1] * rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S385>/Acos' incorporates:
         *  DotProduct: '<S385>/Dot Product'
         */
        if (rtb_Sqrt_i > 1.0F) {
          rtb_Sqrt_i = 1.0F;
        } else {
          if (rtb_Sqrt_i < -1.0F) {
            rtb_Sqrt_i = -1.0F;
          }
        }

        /* Product: '<S385>/Multiply' incorporates:
         *  Trigonometry: '<S385>/Acos'
         */
        rtb_MathFunction_crm_idx_2 *= acosf(rtb_Sqrt_i);

        /* Math: '<S388>/Rem' incorporates:
         *  Constant: '<S388>/Constant1'
         *  Delay: '<S384>/Delay'
         *  Sum: '<S384>/Sum2'
         */
        rtb_Add3_c = rt_remf(rtb_MathFunction_crm_idx_2 - FMS_DW.Delay_DSTATE_a,
                             6.28318548F);

        /* Switch: '<S388>/Switch' incorporates:
         *  Abs: '<S388>/Abs'
         *  Constant: '<S388>/Constant'
         *  Constant: '<S394>/Constant'
         *  Product: '<S388>/Multiply'
         *  RelationalOperator: '<S394>/Compare'
         *  Sum: '<S388>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S388>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S388>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S388>/Switch' */

        /* Sum: '<S384>/Sum' incorporates:
         *  Delay: '<S384>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Add3_c + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S393>/Multiply1' incorporates:
         *  Constant: '<S393>/const1'
         *  DiscreteIntegrator: '<S387>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S393>/Add' incorporates:
         *  DiscreteIntegrator: '<S387>/Integrator1'
         *  Sum: '<S387>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1)
          + rtb_Add3_c;

        /* Signum: '<S393>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S393>/Sign' */

        /* Sum: '<S393>/Add2' incorporates:
         *  Abs: '<S393>/Abs'
         *  Gain: '<S393>/Gain'
         *  Gain: '<S393>/Gain1'
         *  Product: '<S393>/Multiply2'
         *  Product: '<S393>/Multiply3'
         *  Sqrt: '<S393>/Sqrt'
         *  Sum: '<S393>/Add1'
         *  Sum: '<S393>/Subtract'
         */
        rtb_TmpSignalConversionAtMath_1 = (sqrtf((8.0F * fabsf
          (rtb_Divide_l_idx_1) + FMS_ConstB.d_le) * FMS_ConstB.d_le) -
          FMS_ConstB.d_le) * 0.5F * rtb_Add4_e5 + rtb_Add3_c;

        /* Sum: '<S393>/Add4' */
        rtb_Add4_e5 = (rtb_Divide_l_idx_1 - rtb_TmpSignalConversionAtMath_1) +
          rtb_Add3_c;

        /* Sum: '<S393>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d_le;

        /* Sum: '<S393>/Subtract1' */
        rtb_Divide_l_idx_1 -= FMS_ConstB.d_le;

        /* Signum: '<S393>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S393>/Sign1' */

        /* Signum: '<S393>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S393>/Sign2' */

        /* Sum: '<S393>/Add5' incorporates:
         *  Gain: '<S393>/Gain2'
         *  Product: '<S393>/Multiply4'
         *  Sum: '<S393>/Subtract2'
         */
        rtb_TmpSignalConversionAtMath_1 += (rtb_Add3_c - rtb_Divide_l_idx_1) *
          0.5F * rtb_Add4_e5;

        /* Sum: '<S393>/Subtract3' */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_1 - FMS_ConstB.d_le;

        /* Sum: '<S393>/Add6' */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_1 + FMS_ConstB.d_le;

        /* Product: '<S393>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtMath_1 /
          FMS_ConstB.d_le;

        /* Signum: '<S393>/Sign5' incorporates:
         *  Signum: '<S393>/Sign6'
         */
        if (rtb_TmpSignalConversionAtMath_1 < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_TmpSignalConversionAtMath_1 > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_TmpSignalConversionAtMath_1;
          rtb_Add4_e5 = rtb_TmpSignalConversionAtMath_1;
        }

        /* End of Signum: '<S393>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S384>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_crm_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S389>/Rem' incorporates:
         *  Constant: '<S389>/Constant1'
         */
        rtb_TmpSignalConversionAtMath_1 = rt_remf(rtb_MathFunction_crm_idx_2,
          6.28318548F);

        /* Switch: '<S389>/Switch' incorporates:
         *  Abs: '<S389>/Abs'
         *  Constant: '<S389>/Constant'
         *  Constant: '<S395>/Constant'
         *  Product: '<S389>/Multiply'
         *  RelationalOperator: '<S395>/Compare'
         *  Sum: '<S389>/Add'
         */
        if (fabsf(rtb_TmpSignalConversionAtMath_1) > 3.14159274F) {
          /* Signum: '<S389>/Sign' */
          if (rtb_TmpSignalConversionAtMath_1 < 0.0F) {
            rtb_Sqrt_i = -1.0F;
          } else if (rtb_TmpSignalConversionAtMath_1 > 0.0F) {
            rtb_Sqrt_i = 1.0F;
          } else {
            rtb_Sqrt_i = rtb_TmpSignalConversionAtMath_1;
          }

          /* End of Signum: '<S389>/Sign' */
          rtb_TmpSignalConversionAtMath_1 -= 6.28318548F * rtb_Sqrt_i;
        }

        /* End of Switch: '<S389>/Switch' */

        /* Abs: '<S382>/Abs' */
        rtb_TmpSignalConversionAtMath_1 = fabsf(rtb_TmpSignalConversionAtMath_1);

        /* Update for Delay: '<S405>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S406>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S399>/Constant'
         *  RelationalOperator: '<S399>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_d = (uint8_T)((uint32_T)
          (rtb_TmpSignalConversionAtMath_1 <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_d);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_d >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_d = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_d <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_d = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S406>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S401>/Acceleration_Speed' incorporates:
         *  Constant: '<S401>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_k += 0.004F * FMS_PARAM.CRUISE_ACC;
        if (FMS_DW.Acceleration_Speed_DSTATE_k >= FMS_PARAM.CRUISE_SPEED) {
          FMS_DW.Acceleration_Speed_DSTATE_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          if (FMS_DW.Acceleration_Speed_DSTATE_k <= 0.0F) {
            FMS_DW.Acceleration_Speed_DSTATE_k = 0.0F;
          }
        }

        FMS_DW.Acceleration_Speed_PrevResetS_g = (int8_T)rtb_Compare_lh;

        /* End of Update for DiscreteIntegrator: '<S401>/Acceleration_Speed' */

        /* Product: '<S405>/Divide1' incorporates:
         *  Constant: '<S405>/Constant'
         */
        rtb_Sqrt_i = rtb_DiscreteTimeIntegrator_n / FMS_PARAM.CRUISE_SPEED;

        /* Saturate: '<S405>/Saturation' */
        if (rtb_Sqrt_i > 0.314159274F) {
          rtb_Sqrt_i = 0.314159274F;
        } else {
          if (rtb_Sqrt_i < -0.314159274F) {
            rtb_Sqrt_i = -0.314159274F;
          }
        }

        /* End of Saturate: '<S405>/Saturation' */

        /* Update for DiscreteIntegrator: '<S447>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_p += 0.004F * rtb_Sqrt_i;

        /* Update for Delay: '<S384>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S387>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S387>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S383>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S393>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S393>/Sign3' */

        /* Signum: '<S393>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S393>/Sign4' */

        /* Update for DiscreteIntegrator: '<S387>/Integrator' incorporates:
         *  Constant: '<S393>/const'
         *  Gain: '<S393>/Gain3'
         *  Product: '<S393>/Multiply5'
         *  Product: '<S393>/Multiply6'
         *  Sum: '<S393>/Subtract4'
         *  Sum: '<S393>/Subtract5'
         *  Sum: '<S393>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_MathFunction_iq_idx_0 -
          rtb_MathFunction_iq_idx_1) * FMS_ConstB.Gain4_np *
          ((rtb_Divide_l_idx_1 - rtb_Add3_c) * 0.5F) - rtb_Add4_e5 * 1.04719758F)
          * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S387>/Integrator' */
        /* End of Outputs for SubSystem: '<S37>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S37>/Hold' incorporates:
           *  ActionPort: '<S329>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S338>/Motion Status'
           *  Chart: '<S348>/Motion State'
           *  Chart: '<S360>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S37>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Hold' incorporates:
         *  ActionPort: '<S329>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S338>/Motion Status' incorporates:
         *  Abs: '<S338>/Abs'
         *  Constant: '<S338>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S348>/Motion State' incorporates:
         *  Abs: '<S348>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
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

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
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
            FMS_DW.temporalCounter_i1_a = 0U;
            rtb_state_ki = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S348>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S360>/Motion State' incorporates:
         *  Constant: '<S360>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S360>/Square'
         *  Math: '<S360>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S360>/Sqrt'
         *  Sum: '<S360>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S359>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S359>/Hold Control' incorporates:
             *  ActionPort: '<S362>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S359>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S359>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S359>/Hold Control' incorporates:
           *  ActionPort: '<S362>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S359>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S359>/Brake Control' incorporates:
           *  ActionPort: '<S361>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S359>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S359>/Move Control' incorporates:
             *  ActionPort: '<S363>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S359>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S359>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S359>/Move Control' incorporates:
           *  ActionPort: '<S363>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S359>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S359>/Switch Case' */

        /* SwitchCase: '<S337>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S337>/Hold Control' incorporates:
             *  ActionPort: '<S340>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S337>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S337>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S337>/Hold Control' incorporates:
           *  ActionPort: '<S340>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S337>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S337>/Brake Control' incorporates:
           *  ActionPort: '<S339>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S337>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S337>/Move Control' incorporates:
             *  ActionPort: '<S341>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S337>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S337>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S337>/Move Control' incorporates:
           *  ActionPort: '<S341>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S337>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S337>/Switch Case' */

        /* SwitchCase: '<S347>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S347>/Hold Control' incorporates:
             *  ActionPort: '<S350>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S347>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S347>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S347>/Hold Control' incorporates:
           *  ActionPort: '<S350>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S347>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S347>/Brake Control' incorporates:
           *  ActionPort: '<S349>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S347>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S347>/Move Control' incorporates:
             *  ActionPort: '<S351>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S347>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S347>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S347>/Move Control' incorporates:
           *  ActionPort: '<S351>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S347>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S347>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S329>/Bus Assignment'
         *  Constant: '<S329>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S329>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S347>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S347>/Saturation' */

        /* Saturate: '<S359>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S359>/Saturation1' */

        /* Saturate: '<S337>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S329>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S337>/Saturation1' */
        /* End of Outputs for SubSystem: '<S37>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S333>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S37>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S37>/Switch Case' */
      /* End of Outputs for SubSystem: '<S30>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S30>/Auto' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* SwitchCase: '<S35>/Switch Case' incorporates:
       *  Math: '<S213>/Square'
       *  Math: '<S215>/Math Function'
       *  Sum: '<S174>/Subtract'
       *  Sum: '<S228>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S145>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S193>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S183>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S145>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S35>/Offboard' incorporates:
         *  ActionPort: '<S146>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S307>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S310>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S311>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S311>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S311>/Multiply1' incorporates:
         *  Product: '<S311>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S311>/Divide' incorporates:
         *  Constant: '<S311>/Constant'
         *  Constant: '<S311>/R'
         *  Sqrt: '<S311>/Sqrt'
         *  Sum: '<S311>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S311>/Product3' incorporates:
         *  Constant: '<S311>/Constant1'
         *  Product: '<S311>/Multiply1'
         *  Sum: '<S311>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S311>/Multiply2' incorporates:
         *  Trigonometry: '<S311>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S310>/Sum' incorporates:
         *  Gain: '<S307>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S315>/Abs' incorporates:
         *  Abs: '<S318>/Abs1'
         *  Switch: '<S315>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S315>/Switch1' incorporates:
         *  Abs: '<S315>/Abs'
         *  Bias: '<S315>/Bias2'
         *  Bias: '<S315>/Bias3'
         *  Constant: '<S312>/Constant'
         *  Constant: '<S312>/Constant1'
         *  Constant: '<S317>/Constant'
         *  Gain: '<S315>/Gain1'
         *  Product: '<S315>/Multiply'
         *  RelationalOperator: '<S317>/Compare'
         *  Switch: '<S312>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S318>/Switch1' incorporates:
           *  Bias: '<S318>/Bias2'
           *  Bias: '<S318>/Bias3'
           *  Constant: '<S318>/Constant'
           *  Constant: '<S319>/Constant'
           *  Math: '<S318>/Math Function'
           *  RelationalOperator: '<S319>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S318>/Switch1' */

          /* Signum: '<S315>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S315>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S312>/Sum' incorporates:
         *  Gain: '<S307>/Gain1'
         *  Gain: '<S307>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S310>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S310>/Multiply' incorporates:
         *  Gain: '<S310>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S314>/Switch1' incorporates:
         *  Abs: '<S314>/Abs1'
         *  Bias: '<S314>/Bias2'
         *  Bias: '<S314>/Bias3'
         *  Constant: '<S314>/Constant'
         *  Constant: '<S316>/Constant'
         *  Math: '<S314>/Math Function'
         *  RelationalOperator: '<S316>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S314>/Switch1' */

        /* Product: '<S310>/Multiply' incorporates:
         *  Gain: '<S310>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S288>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S292>/Multiply1'
         *  Product: '<S293>/Multiply3'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S301>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S301>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S301>/Trigonometric Function3' incorporates:
           *  Gain: '<S300>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S301>/Gain' incorporates:
           *  Gain: '<S300>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S301>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S301>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S301>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S301>/Trigonometric Function' incorporates:
           *  Gain: '<S300>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S301>/Trigonometric Function1' incorporates:
           *  Gain: '<S300>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S301>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S292>/Saturation' incorporates:
           *  Constant: '<S298>/Constant'
           *  Constant: '<S299>/Constant'
           *  Constant: '<S309>/Constant'
           *  DataTypeConversion: '<S307>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S291>/Logical Operator'
           *  Product: '<S292>/Multiply'
           *  Product: '<S313>/Multiply1'
           *  Product: '<S313>/Multiply2'
           *  RelationalOperator: '<S298>/Compare'
           *  RelationalOperator: '<S299>/Compare'
           *  RelationalOperator: '<S309>/Compare'
           *  S-Function (sfix_bitop): '<S291>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/lat_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S292>/Sum1'
           *  Sum: '<S313>/Sum2'
           *  Switch: '<S294>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_DiscreteTimeIntegrator_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_DiscreteTimeIntegrator_n = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Sqrt_i = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ?
            rtb_DiscreteTimeIntegrator_n - FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Sqrt_i > 4.0F) {
            rtb_Sqrt_i = 4.0F;
          } else {
            if (rtb_Sqrt_i < -4.0F) {
              rtb_Sqrt_i = -4.0F;
            }
          }

          /* SignalConversion: '<S301>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S292>/Saturation' incorporates:
           *  Constant: '<S298>/Constant'
           *  Constant: '<S299>/Constant'
           *  Constant: '<S309>/Constant'
           *  DataTypeConversion: '<S307>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S291>/Logical Operator'
           *  Product: '<S292>/Multiply'
           *  Product: '<S313>/Multiply3'
           *  Product: '<S313>/Multiply4'
           *  RelationalOperator: '<S298>/Compare'
           *  RelationalOperator: '<S299>/Compare'
           *  RelationalOperator: '<S309>/Compare'
           *  S-Function (sfix_bitop): '<S291>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/lon_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S292>/Sum1'
           *  Sum: '<S313>/Sum3'
           *  Switch: '<S294>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_DiscreteTimeIntegrator_n = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o1);
          } else {
            rtb_DiscreteTimeIntegrator_n = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ?
            rtb_DiscreteTimeIntegrator_n - FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Add3_c > 4.0F) {
            rtb_Add3_c = 4.0F;
          } else {
            if (rtb_Add3_c < -4.0F) {
              rtb_Add3_c = -4.0F;
            }
          }

          /* SignalConversion: '<S301>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S292>/Saturation' incorporates:
           *  Constant: '<S298>/Constant'
           *  Constant: '<S299>/Constant'
           *  Constant: '<S309>/Constant'
           *  DataTypeConversion: '<S307>/Data Type Conversion'
           *  DataTypeConversion: '<S307>/Data Type Conversion1'
           *  Gain: '<S295>/Gain'
           *  Gain: '<S307>/Gain2'
           *  Gain: '<S310>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S291>/Logical Operator'
           *  Product: '<S292>/Multiply'
           *  RelationalOperator: '<S298>/Compare'
           *  RelationalOperator: '<S299>/Compare'
           *  RelationalOperator: '<S309>/Compare'
           *  S-Function (sfix_bitop): '<S291>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/alt_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S292>/Sum1'
           *  Sum: '<S310>/Sum1'
           *  Switch: '<S294>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_DiscreteTimeIntegrator_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_DiscreteTimeIntegrator_n = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ?
            rtb_DiscreteTimeIntegrator_n - (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_Divide_l_idx_1 > 2.0F) {
            rtb_Divide_l_idx_1 = 2.0F;
          } else {
            if (rtb_Divide_l_idx_1 < -2.0F) {
              rtb_Divide_l_idx_1 = -2.0F;
            }
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Add3_c +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Sqrt_i);
          }

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S235>/Constant4'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  Product: '<S292>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function3' incorporates:
           *  Gain: '<S234>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S235>/Gain' incorporates:
           *  Gain: '<S234>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S235>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S235>/Constant3'
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function' incorporates:
           *  Gain: '<S234>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S235>/Trigonometric Function1' incorporates:
           *  Gain: '<S234>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S225>/Multiply' incorporates:
           *  Constant: '<S233>/Constant'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/ax_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S225>/Multiply' incorporates:
           *  Constant: '<S233>/Constant'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/ay_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S225>/Multiply' incorporates:
           *  Constant: '<S233>/Constant'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/az_cmd valid'
           */
          rtb_MathFunction_iq_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S225>/Index Vector' incorporates:
           *  Product: '<S231>/Multiply'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMat_hq[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_iq_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S305>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S305>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S303>/Gain' incorporates:
           *  Gain: '<S236>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S293>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S305>/Trigonometric Function3' incorporates:
           *  Gain: '<S303>/Gain'
           *  Trigonometry: '<S305>/Trigonometric Function1'
           */
          rtb_DiscreteTimeIntegrator_n = arm_cos_f32(rtb_Add3_c);
          rtb_Transpose[4] = rtb_DiscreteTimeIntegrator_n;

          /* Trigonometry: '<S305>/Trigonometric Function2' incorporates:
           *  Gain: '<S303>/Gain'
           *  Trigonometry: '<S305>/Trigonometric Function'
           */
          rtb_Add4_e5 = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S305>/Gain' incorporates:
           *  Trigonometry: '<S305>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Add4_e5;

          /* SignalConversion: '<S305>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S305>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S305>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Add4_e5;

          /* Trigonometry: '<S305>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_DiscreteTimeIntegrator_n;

          /* SignalConversion: '<S305>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S305>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S305>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S304>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S304>/Constant4'
           */
          rtb_VectorConcatenate_bl[5] = 0.0F;

          /* Trigonometry: '<S304>/Trigonometric Function3' incorporates:
           *  Gain: '<S302>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S304>/Trigonometric Function1'
           */
          rtb_Divide_l_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_bl[4] = rtb_Divide_l_idx_1;

          /* Trigonometry: '<S304>/Trigonometric Function2' incorporates:
           *  Gain: '<S302>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S304>/Trigonometric Function'
           */
          rtb_DiscreteTimeIntegrator_n = arm_sin_f32
            (-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S304>/Gain' incorporates:
           *  Trigonometry: '<S304>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_bl[3] = -rtb_DiscreteTimeIntegrator_n;

          /* SignalConversion: '<S304>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S304>/Constant3'
           */
          rtb_VectorConcatenate_bl[2] = 0.0F;

          /* Trigonometry: '<S304>/Trigonometric Function' */
          rtb_VectorConcatenate_bl[1] = rtb_DiscreteTimeIntegrator_n;

          /* Trigonometry: '<S304>/Trigonometric Function1' */
          rtb_VectorConcatenate_bl[0] = rtb_Divide_l_idx_1;

          /* RelationalOperator: '<S309>/Compare' incorporates:
           *  Constant: '<S309>/Constant'
           *  S-Function (sfix_bitop): '<S306>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S307>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S307>/Data Type Conversion'
           *  Gain: '<S307>/Gain2'
           *  Gain: '<S310>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S313>/Multiply1'
           *  Product: '<S313>/Multiply2'
           *  Product: '<S313>/Multiply3'
           *  Product: '<S313>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S310>/Sum1'
           *  Sum: '<S313>/Sum2'
           *  Sum: '<S313>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S294>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S298>/Compare' incorporates:
           *  Constant: '<S298>/Constant'
           *  S-Function (sfix_bitop): '<S291>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S299>/Compare' incorporates:
           *  Constant: '<S299>/Constant'
           *  S-Function (sfix_bitop): '<S291>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S293>/Sum2' incorporates:
             *  Product: '<S293>/Multiply2'
             *  Switch: '<S294>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_DiscreteTimeIntegrator_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_DiscreteTimeIntegrator_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S293>/Saturation1' incorporates:
             *  Gain: '<S295>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S291>/Logical Operator'
             *  Product: '<S293>/Multiply'
             *  Product: '<S293>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             *  Sum: '<S293>/Sum2'
             */
            rtb_Sqrt_i = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_DiscreteTimeIntegrator_n -
              ((rtb_VectorConcatenate_bl[rtb_Compare_bv_0 + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_bl[rtb_Compare_bv_0] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_bl[rtb_Compare_bv_0 +
               6] * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Sqrt_i > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMat_hq[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Sqrt_i < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMat_hq[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_TmpSignalConversionAtMat_hq[rtb_Compare_bv_0] = rtb_Sqrt_i;
            }

            /* End of Saturate: '<S293>/Saturation1' */
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] *
              rtb_TmpSignalConversionAtMat_hq[2] +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_TmpSignalConversionAtMat_hq[1] +
               rtb_Transpose[rtb_Compare_bv_0] *
               rtb_TmpSignalConversionAtMat_hq[0]);
          }

          /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S237>/Constant4'
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  Product: '<S293>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S237>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S237>/Gain' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           *  Trigonometry: '<S237>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S237>/Constant3'
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S237>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S237>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S225>/Multiply' incorporates:
           *  Constant: '<S233>/Constant'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/ax_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S225>/Multiply' incorporates:
           *  Constant: '<S233>/Constant'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/ay_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S225>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S225>/Multiply' incorporates:
           *  Constant: '<S233>/Constant'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/az_cmd valid'
           */
          rtb_MathFunction_iq_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S225>/Index Vector' incorporates:
           *  Product: '<S232>/Multiply3'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMat_hq[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_iq_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         default:
          /* SignalConversion: '<S297>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S297>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S297>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S297>/Trigonometric Function3' incorporates:
           *  Gain: '<S296>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S297>/Gain' incorporates:
           *  Gain: '<S296>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S297>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S297>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S297>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S297>/Trigonometric Function' incorporates:
           *  Gain: '<S296>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S297>/Trigonometric Function1' incorporates:
           *  Gain: '<S296>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S306>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S291>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S309>/Compare' incorporates:
           *  Constant: '<S309>/Constant'
           *  S-Function (sfix_bitop): '<S306>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S306>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S291>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S309>/Compare' incorporates:
           *  Constant: '<S309>/Constant'
           *  S-Function (sfix_bitop): '<S306>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S306>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S291>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S309>/Compare' incorporates:
           *  Constant: '<S309>/Constant'
           *  S-Function (sfix_bitop): '<S306>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S307>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S307>/Data Type Conversion'
           *  Gain: '<S307>/Gain2'
           *  Gain: '<S310>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S313>/Multiply1'
           *  Product: '<S313>/Multiply2'
           *  Product: '<S313>/Multiply3'
           *  Product: '<S313>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S310>/Sum1'
           *  Sum: '<S313>/Sum2'
           *  Sum: '<S313>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S294>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S298>/Compare' incorporates:
           *  Constant: '<S298>/Constant'
           *  S-Function (sfix_bitop): '<S291>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S291>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S299>/Compare' incorporates:
           *  Constant: '<S299>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S290>/Sum2' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S294>/Switch' incorporates:
             *  Product: '<S290>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_DiscreteTimeIntegrator_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_DiscreteTimeIntegrator_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S290>/Saturation1' incorporates:
             *  Gain: '<S295>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S291>/Logical Operator'
             *  Product: '<S290>/Multiply'
             *  Product: '<S290>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             */
            rtb_Sqrt_i = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_DiscreteTimeIntegrator_n - ((rtb_Transpose[rtb_Compare_bv_0 +
              3] * FMS_U.INS_Out.y_R + rtb_Transpose[rtb_Compare_bv_0] *
              FMS_U.INS_Out.x_R) + rtb_Transpose[rtb_Compare_bv_0 + 6] *
              -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Sqrt_i > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Sqrt_i < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] = rtb_Sqrt_i;
            }

            /* End of Saturate: '<S290>/Saturation1' */
          }

          /* End of Sum: '<S290>/Sum2' */

          /* MultiPortSwitch: '<S225>/Index Vector' incorporates:
           *  Constant: '<S233>/Constant'
           *  Product: '<S225>/Multiply'
           *  RelationalOperator: '<S233>/Compare'
           *  S-Function (sfix_bitop): '<S230>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S230>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S230>/az_cmd valid'
           */
          rtb_TmpSignalConversionAtMat_hq[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMat_hq[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMat_hq[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S288>/Index Vector' */

        /* Sum: '<S284>/Sum1' incorporates:
         *  Constant: '<S284>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S284>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Add4_e5 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S285>/Abs' */
        rtb_Add3_c = fabsf(rtb_Add4_e5);

        /* Switch: '<S285>/Switch' incorporates:
         *  Constant: '<S285>/Constant'
         *  Constant: '<S286>/Constant'
         *  Product: '<S285>/Multiply'
         *  RelationalOperator: '<S286>/Compare'
         *  Sum: '<S285>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S285>/Sign' */
          if (rtb_Add4_e5 < 0.0F) {
            rtb_Add4_e5 = -1.0F;
          } else {
            if (rtb_Add4_e5 > 0.0F) {
              rtb_Add4_e5 = 1.0F;
            }
          }

          /* End of Signum: '<S285>/Sign' */
          rtb_Add4_e5 *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S285>/Switch' */

        /* Saturate: '<S284>/Saturation' */
        if (rtb_Add4_e5 > 0.314159274F) {
          rtb_Add4_e5 = 0.314159274F;
        } else {
          if (rtb_Add4_e5 < -0.314159274F) {
            rtb_Add4_e5 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S284>/Saturation' */

        /* Gain: '<S281>/Gain2' */
        rtb_Add4_e5 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S227>/Sum' incorporates:
         *  Constant: '<S283>/Constant'
         *  Constant: '<S287>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S281>/Multiply2'
         *  Product: '<S282>/Multiply1'
         *  RelationalOperator: '<S283>/Compare'
         *  RelationalOperator: '<S287>/Compare'
         *  S-Function (sfix_bitop): '<S281>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S282>/psi_rate_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Sqrt_i = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Add4_e5 : 0.0F)
          + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S288>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_MathFunction_iq_idx_0 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S288>/Gain2' */
        rtb_Add4_e5 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S289>/Index Vector' incorporates:
         *  Constant: '<S324>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S289>/Multiply'
         *  Product: '<S322>/Multiply'
         *  Product: '<S323>/Multiply3'
         *  RelationalOperator: '<S324>/Compare'
         *  S-Function (sfix_bitop): '<S321>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S321>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S321>/w_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S326>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S326>/Trigonometric Function3' incorporates:
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S326>/Gain' incorporates:
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S326>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S326>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S326>/Trigonometric Function' incorporates:
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S289>/Multiply' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S321>/u_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S289>/Multiply' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S321>/v_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U
            ? FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S289>/Multiply' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S321>/w_cmd valid'
           */
          rtb_MathFunction_iq_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_iq_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S328>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S328>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S327>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S323>/Subtract'
           */
          rtb_Divide_l_idx_1 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S328>/Trigonometric Function3' incorporates:
           *  Gain: '<S327>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Divide_l_idx_1);

          /* Gain: '<S328>/Gain' incorporates:
           *  Gain: '<S327>/Gain'
           *  Trigonometry: '<S328>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_l_idx_1);

          /* SignalConversion: '<S328>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S328>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S328>/Trigonometric Function' incorporates:
           *  Gain: '<S327>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Divide_l_idx_1);

          /* Trigonometry: '<S328>/Trigonometric Function1' incorporates:
           *  Gain: '<S327>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Divide_l_idx_1);

          /* SignalConversion: '<S328>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S289>/Multiply' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S321>/u_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S328>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S289>/Multiply' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S321>/v_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U
            ? FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S328>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S289>/Multiply' incorporates:
           *  Constant: '<S324>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S321>/w_cmd valid'
           */
          rtb_MathFunction_iq_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_iq_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         default:
          rtb_MatrixConcatenate3[0] = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_MatrixConcatenate3[1] = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_MatrixConcatenate3[2] = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S289>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_MathFunction_iq_idx_0;

        /* Sum: '<S228>/Sum1' */
        rtb_Add3_c = rtb_Add4_e5 + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S245>/Switch' incorporates:
         *  Constant: '<S260>/Constant'
         *  Constant: '<S261>/Constant'
         *  Constant: '<S262>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S260>/Compare'
         *  RelationalOperator: '<S261>/Compare'
         *  RelationalOperator: '<S262>/Compare'
         *  S-Function (sfix_bitop): '<S245>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S245>/y_v_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S245>/Logical Operator' incorporates:
           *  Constant: '<S261>/Constant'
           *  Constant: '<S262>/Constant'
           *  RelationalOperator: '<S261>/Compare'
           *  RelationalOperator: '<S262>/Compare'
           *  S-Function (sfix_bitop): '<S245>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S245>/y_v_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S245>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S226>/u_cmd_valid' */
        /* MATLAB Function: '<S257>/bit_shift' incorporates:
         *  DataTypeConversion: '<S226>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_es << 6);

        /* End of Outputs for SubSystem: '<S226>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S226>/v_cmd_valid' */
        /* MATLAB Function: '<S258>/bit_shift' incorporates:
         *  DataTypeConversion: '<S226>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S226>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S246>/Switch' incorporates:
         *  Constant: '<S264>/Constant'
         *  Constant: '<S265>/Constant'
         *  Constant: '<S267>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S264>/Compare'
         *  RelationalOperator: '<S265>/Compare'
         *  RelationalOperator: '<S267>/Compare'
         *  S-Function (sfix_bitop): '<S246>/ax_cmd'
         *  S-Function (sfix_bitop): '<S246>/ay_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S246>/Logical Operator' incorporates:
           *  Constant: '<S265>/Constant'
           *  Constant: '<S267>/Constant'
           *  RelationalOperator: '<S265>/Compare'
           *  RelationalOperator: '<S267>/Compare'
           *  S-Function (sfix_bitop): '<S246>/ax_cmd'
           *  S-Function (sfix_bitop): '<S246>/ay_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S246>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S146>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S146>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S146>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S29>/Signal Copy'
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
        FMS_Y.FMS_Out.ax_cmd = rtb_TmpSignalConversionAtMat_hq[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_TmpSignalConversionAtMat_hq[1];
        FMS_Y.FMS_Out.az_cmd = rtb_TmpSignalConversionAtMat_hq[2];

        /* Saturate: '<S227>/Saturation' */
        if (rtb_Sqrt_i > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Sqrt_i < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Sqrt_i;
        }

        /* End of Saturate: '<S227>/Saturation' */

        /* Saturate: '<S228>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S228>/Saturation2' */

        /* Saturate: '<S228>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S228>/Saturation1' */

        /* Saturate: '<S228>/Saturation3' */
        if (rtb_Add3_c > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S228>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S226>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S226>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S226>/throttle_cmd_valid' */
        /* BusAssignment: '<S146>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S238>/Constant'
         *  Constant: '<S239>/Constant'
         *  Constant: '<S240>/Constant'
         *  Constant: '<S241>/Constant'
         *  Constant: '<S242>/Constant'
         *  Constant: '<S243>/Constant'
         *  Constant: '<S244>/Constant'
         *  Constant: '<S263>/Constant'
         *  Constant: '<S266>/Constant'
         *  DataTypeConversion: '<S226>/Data Type Conversion10'
         *  DataTypeConversion: '<S226>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S247>/bit_shift'
         *  MATLAB Function: '<S248>/bit_shift'
         *  MATLAB Function: '<S249>/bit_shift'
         *  MATLAB Function: '<S251>/bit_shift'
         *  MATLAB Function: '<S252>/bit_shift'
         *  MATLAB Function: '<S253>/bit_shift'
         *  MATLAB Function: '<S254>/bit_shift'
         *  MATLAB Function: '<S255>/bit_shift'
         *  MATLAB Function: '<S256>/bit_shift'
         *  MATLAB Function: '<S259>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S238>/Compare'
         *  RelationalOperator: '<S239>/Compare'
         *  RelationalOperator: '<S240>/Compare'
         *  RelationalOperator: '<S241>/Compare'
         *  RelationalOperator: '<S242>/Compare'
         *  RelationalOperator: '<S243>/Compare'
         *  RelationalOperator: '<S244>/Compare'
         *  RelationalOperator: '<S263>/Compare'
         *  RelationalOperator: '<S266>/Compare'
         *  S-Function (sfix_bitop): '<S226>/p_cmd'
         *  S-Function (sfix_bitop): '<S226>/phi_cmd'
         *  S-Function (sfix_bitop): '<S226>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S226>/q_cmd'
         *  S-Function (sfix_bitop): '<S226>/r_cmd'
         *  S-Function (sfix_bitop): '<S226>/theta_cmd'
         *  S-Function (sfix_bitop): '<S226>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S245>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S246>/az_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         *  Sum: '<S226>/Add'
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

        /* End of Outputs for SubSystem: '<S226>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S226>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S226>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S35>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S35>/Mission' incorporates:
           *  ActionPort: '<S145>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S35>/Switch Case' incorporates:
           *  UnitDelay: '<S148>/Delay Input1'
           *
           * Block description for '<S148>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S35>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S35>/Mission' incorporates:
           *  ActionPort: '<S145>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S145>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S35>/Switch Case' incorporates:
           *  Chart: '<S184>/Motion Status'
           *  Chart: '<S194>/Motion State'
           *  Delay: '<S153>/Delay'
           *  Delay: '<S175>/Delay'
           *  DiscreteIntegrator: '<S156>/Integrator'
           *  DiscreteIntegrator: '<S156>/Integrator1'
           *  DiscreteIntegrator: '<S171>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S220>/Discrete-Time Integrator'
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

          /* End of SystemReset for SubSystem: '<S145>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S35>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S35>/Mission' incorporates:
         *  ActionPort: '<S145>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S148>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S148>/Delay Input1'
         *
         * Block description for '<S148>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S145>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S149>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S193>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S183>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S175>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S171>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S153>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S194>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S184>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* Delay: '<S175>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S148>/Delay Input1'
         *
         * Block description for '<S148>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S170>/Compare' incorporates:
         *  Constant: '<S224>/Constant'
         *  RelationalOperator: '<S224>/Compare'
         *  UnitDelay: '<S148>/Delay Input1'
         *
         * Block description for '<S148>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_lh = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S171>/Acceleration_Speed' */
        if (rtb_Compare_lh || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        if (FMS_DW.Acceleration_Speed_DSTATE >= FMS_PARAM.CRUISE_SPEED) {
          FMS_DW.Acceleration_Speed_DSTATE = FMS_PARAM.CRUISE_SPEED;
        } else {
          if (FMS_DW.Acceleration_Speed_DSTATE <= 0.0F) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S194>/Motion State' incorporates:
         *  Constant: '<S194>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S194>/Square'
         *  Math: '<S194>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S194>/Sqrt'
         *  Sum: '<S194>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S193>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S193>/Hold Control' incorporates:
             *  ActionPort: '<S196>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S193>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S193>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S193>/Hold Control' incorporates:
           *  ActionPort: '<S196>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S193>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S193>/Brake Control' incorporates:
           *  ActionPort: '<S195>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S193>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S193>/Move Control' incorporates:
             *  ActionPort: '<S197>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S193>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S193>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S193>/Move Control' incorporates:
           *  ActionPort: '<S197>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S193>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S193>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S184>/Motion Status' incorporates:
         *  Abs: '<S184>/Abs'
         *  Constant: '<S184>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S183>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_e;
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S183>/Hold Control' incorporates:
             *  ActionPort: '<S186>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S183>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S183>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S183>/Hold Control' incorporates:
           *  ActionPort: '<S186>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S183>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S183>/Brake Control' incorporates:
           *  ActionPort: '<S185>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S183>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S183>/Move Control' incorporates:
             *  ActionPort: '<S187>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S183>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S183>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S183>/Move Control' incorporates:
           *  ActionPort: '<S187>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S183>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S183>/Switch Case' */

        /* Switch: '<S151>/Switch' incorporates:
         *  Product: '<S175>/Multiply'
         *  Sum: '<S175>/Sum'
         */
        if (rtb_Compare_lh) {
          /* Saturate: '<S193>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[0] = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMat_hq[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[1] = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S193>/Saturation1' */

          /* Saturate: '<S183>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMat_hq[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMat_hq[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S183>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S175>/Sum' incorporates:
           *  Delay: '<S175>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S221>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMat_hq[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S171>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_e5 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Sum_k[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S175>/Sum' incorporates:
           *  Delay: '<S175>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* Sum: '<S171>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S180>/Sqrt' incorporates:
           *  Math: '<S180>/Square'
           *  Sum: '<S171>/Sum'
           *  Sum: '<S180>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_Add4_e5 * rtb_Add4_e5 + rtb_Add3_c * rtb_Add3_c);

          /* SignalConversion: '<S223>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S223>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S223>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S222>/Gain' incorporates:
           *  DiscreteIntegrator: '<S220>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S220>/Add'
           */
          rtb_MathFunction_iq_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S223>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_MathFunction_iq_idx_0);

          /* Gain: '<S223>/Gain' incorporates:
           *  Trigonometry: '<S223>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_MathFunction_iq_idx_0);

          /* SignalConversion: '<S223>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S223>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S223>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_MathFunction_iq_idx_0);

          /* Trigonometry: '<S223>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_MathFunction_iq_idx_0);

          /* Switch: '<S171>/Switch' incorporates:
           *  Constant: '<S171>/vel'
           */
          if (rtb_Add3_c > FMS_PARAM.L1) {
            rtb_MathFunction_iq_idx_0 = FMS_PARAM.CRUISE_SPEED;
          } else {
            /* Gain: '<S171>/Gain' */
            rtb_MathFunction_iq_idx_0 = 0.5F * rtb_Add3_c;

            /* Saturate: '<S171>/Saturation' */
            if (rtb_MathFunction_iq_idx_0 > FMS_PARAM.CRUISE_SPEED) {
              rtb_MathFunction_iq_idx_0 = FMS_PARAM.CRUISE_SPEED;
            } else {
              if (rtb_MathFunction_iq_idx_0 < 0.5F) {
                rtb_MathFunction_iq_idx_0 = 0.5F;
              }
            }

            /* End of Saturate: '<S171>/Saturation' */
          }

          /* End of Switch: '<S171>/Switch' */

          /* Switch: '<S171>/Switch1' incorporates:
           *  DiscreteIntegrator: '<S171>/Acceleration_Speed'
           *  Sum: '<S171>/Sum1'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE - rtb_MathFunction_iq_idx_0 <
              0.0F) {
            rtb_MathFunction_iq_idx_0 = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S171>/Switch1' */

          /* Sum: '<S221>/Sum of Elements' incorporates:
           *  Math: '<S221>/Math Function'
           */
          rtb_DiscreteTimeIntegrator_n = rtb_TmpSignalConversionAtMat_hq[0] *
            rtb_TmpSignalConversionAtMat_hq[0] + rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_1;

          /* Math: '<S221>/Math Function1' incorporates:
           *  Sum: '<S221>/Sum of Elements'
           *
           * About '<S221>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
            rtb_Sqrt_i = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
          } else {
            rtb_Sqrt_i = sqrtf(rtb_DiscreteTimeIntegrator_n);
          }

          /* End of Math: '<S221>/Math Function1' */

          /* Switch: '<S221>/Switch' incorporates:
           *  Constant: '<S221>/Constant'
           *  Product: '<S221>/Product'
           */
          if (rtb_Sqrt_i > 0.0F) {
            rtb_Add3_c = rtb_Sum_k[0];
          } else {
            rtb_Add3_c = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Sqrt_i = 1.0F;
          }

          /* End of Switch: '<S221>/Switch' */

          /* Product: '<S219>/Multiply2' incorporates:
           *  Product: '<S221>/Divide'
           */
          rtb_Add4_e5 = rtb_Add3_c / rtb_Sqrt_i * rtb_MathFunction_iq_idx_0;
          rtb_Sqrt_i = rtb_Divide_l_idx_1 / rtb_Sqrt_i *
            rtb_MathFunction_iq_idx_0;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S177>/Sum1' incorporates:
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S177>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S177>/Divide' incorporates:
           *  Math: '<S178>/Square'
           *  Math: '<S179>/Square'
           *  Sqrt: '<S178>/Sqrt'
           *  Sqrt: '<S179>/Sqrt'
           *  Sum: '<S177>/Sum'
           *  Sum: '<S177>/Sum1'
           *  Sum: '<S178>/Sum of Elements'
           *  Sum: '<S179>/Sum of Elements'
           */
          rtb_MathFunction_iq_idx_0 = sqrtf(rtb_Add3_c * rtb_Add3_c +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1) / sqrtf(rtb_P_d_idx_0 *
            rtb_P_d_idx_0 + rtb_TmpSignalConversionAtMath_0 *
            rtb_TmpSignalConversionAtMath_0);

          /* Saturate: '<S177>/Saturation' */
          if (rtb_MathFunction_iq_idx_0 > 1.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          } else {
            if (rtb_MathFunction_iq_idx_0 < 0.0F) {
              rtb_MathFunction_iq_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S177>/Saturation' */

          /* Product: '<S175>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Sqrt_i + rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_e5;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S168>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S177>/Multiply'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S168>/Sum2'
           *  Sum: '<S177>/Add'
           *  Sum: '<S177>/Subtract'
           */
          rtb_Sqrt_i = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_MathFunction_iq_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMat_hq[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMat_hq[1] = rtb_Transpose_0[1];

          /* Saturate: '<S168>/Saturation1' incorporates:
           *  Product: '<S175>/Multiply'
           */
          if (rtb_Sqrt_i > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMat_hq[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Sqrt_i < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMat_hq[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMat_hq[2] = rtb_Sqrt_i;
          }

          /* End of Saturate: '<S168>/Saturation1' */
        }

        /* End of Switch: '<S151>/Switch' */

        /* Delay: '<S153>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S156>/Integrator1' incorporates:
         *  Delay: '<S153>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S160>/Rem' incorporates:
         *  Constant: '<S160>/Constant1'
         *  DiscreteIntegrator: '<S156>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S155>/Sum'
         */
        rtb_Divide_l_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_p -
          FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Abs: '<S160>/Abs'
         *  Constant: '<S160>/Constant'
         *  Constant: '<S161>/Constant'
         *  Product: '<S160>/Multiply'
         *  RelationalOperator: '<S161>/Compare'
         *  Sum: '<S160>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S160>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S160>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S160>/Switch' */

        /* Gain: '<S155>/Gain2' */
        rtb_Divide_l_idx_1 *= FMS_PARAM.YAW_P;

        /* Saturate: '<S155>/Saturation' */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Divide_l_idx_1 = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Divide_l_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_l_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S155>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S149>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S149>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S149>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMat_hq[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMat_hq[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMat_hq[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_l_idx_1;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S214>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S214>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S214>/Math Function1' incorporates:
         *  Sum: '<S214>/Sum of Elements'
         *
         * About '<S214>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S214>/Math Function1' */

        /* Switch: '<S214>/Switch' incorporates:
         *  Constant: '<S214>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S214>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMat_hq[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMat_hq[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMat_hq[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_TmpSignalConversionAtMat_hq[0] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[1] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[2] = 1.0F;
        }

        /* End of Switch: '<S214>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S149>/Sum' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sqrt_i = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_TmpSignalConversionAtDela_a[0] = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Add4_e5 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S167>/Sum of Elements' incorporates:
         *  Math: '<S167>/Math Function'
         *  Sum: '<S149>/Sum'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_Add4_e5 * rtb_Add4_e5 + rtb_Sqrt_i *
          rtb_Sqrt_i;

        /* Math: '<S167>/Math Function1' incorporates:
         *  Sum: '<S167>/Sum of Elements'
         *
         * About '<S167>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S167>/Math Function1' */

        /* Switch: '<S167>/Switch' incorporates:
         *  Constant: '<S167>/Constant'
         *  Product: '<S167>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_MathFunction_crm_idx_2 = rtb_Divide_l_idx_1;
        } else {
          rtb_Add4_e5 = 0.0F;
          rtb_Sqrt_i = 0.0F;
          rtb_MathFunction_crm_idx_2 = 1.0F;
        }

        /* End of Switch: '<S167>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S173>/NearbyRefWP' incorporates:
         *  Constant: '<S149>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a,
                        &rtb_DiscreteTimeIntegrator_n);

        /* MATLAB Function: '<S173>/SearchL1RefWP' incorporates:
         *  Constant: '<S149>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Divide_l_idx_1 = rtb_Add3_c * rtb_Add3_c + rtb_Divide_l_idx_1 *
          rtb_Divide_l_idx_1;

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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Divide_l_idx_1);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_MathFunction_iq_idx_0 = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Divide_l_idx_1);
          rtb_Divide_l_idx_1 = (-B - u1_tmp) / (2.0F * rtb_Divide_l_idx_1);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Divide_l_idx_1 >= 0.0F) &&
              (rtb_Divide_l_idx_1 <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Divide_l_idx_1);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Divide_l_idx_1 >= 0.0F) && (rtb_Divide_l_idx_1 <= 1.0F)) {
              rtb_Add3_c = rtb_Divide_l_idx_1;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Divide_l_idx_1);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_MathFunction_iq_idx_0 = (FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_iq_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S173>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_TmpSignalConversionAtMath_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Divide_l_idx_1 = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
                              * rtb_TmpSignalConversionAtMath_1 +
                              (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0])
                              * rtb_TmpSignalConversionAtMath_0) /
          (rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0 +
           rtb_TmpSignalConversionAtMath_1 * rtb_TmpSignalConversionAtMath_1);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_l_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = rtb_Divide_l_idx_1 * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S173>/Switch1' incorporates:
         *  Constant: '<S207>/Constant'
         *  RelationalOperator: '<S207>/Compare'
         */
        if (rtb_DiscreteTimeIntegrator_n <= 0.0F) {
          /* Switch: '<S173>/Switch' incorporates:
           *  Constant: '<S206>/Constant'
           *  MATLAB Function: '<S173>/SearchL1RefWP'
           *  RelationalOperator: '<S206>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_iq_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S173>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = rtb_Divide_l_idx_1 *
                rtb_TmpSignalConversionAtMath_1 + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }
          }

          /* End of Switch: '<S173>/Switch' */
        }

        /* End of Switch: '<S173>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S174>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtDela_a[0] -
          FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;
        rtb_Add3_c = rtb_MathFunction_iq_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S174>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S215>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtDela_a[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S215>/Math Function' incorporates:
         *  Math: '<S213>/Square'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Sum: '<S215>/Sum of Elements' incorporates:
         *  Math: '<S215>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n +
          rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S215>/Math Function1' incorporates:
         *  Sum: '<S215>/Sum of Elements'
         *
         * About '<S215>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S215>/Math Function1' */

        /* Switch: '<S215>/Switch' incorporates:
         *  Constant: '<S215>/Constant'
         *  Product: '<S215>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Add3_c;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_iq_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S215>/Switch' */

        /* Product: '<S214>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_TmpSignalConversionAtMat_hq[0] /
          rtb_TmpSignalConversionAtMat_hq[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMat_hq[1] /
          rtb_TmpSignalConversionAtMat_hq[2];

        /* Sum: '<S217>/Sum of Elements' incorporates:
         *  Math: '<S217>/Math Function'
         *  SignalConversion: '<S217>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtMath_1 *
          rtb_TmpSignalConversionAtMath_1;

        /* Math: '<S217>/Math Function1' incorporates:
         *  Sum: '<S217>/Sum of Elements'
         *
         * About '<S217>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S217>/Math Function1' */

        /* Switch: '<S217>/Switch' incorporates:
         *  Constant: '<S217>/Constant'
         *  Product: '<S217>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_TmpSignalConversionAtMat_hq[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_TmpSignalConversionAtMat_hq[1] = rtb_TmpSignalConversionAtMath_1;
          rtb_TmpSignalConversionAtMat_hq[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_TmpSignalConversionAtMat_hq[0] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[1] = 0.0F;
          rtb_TmpSignalConversionAtMat_hq[2] = 1.0F;
        }

        /* End of Switch: '<S217>/Switch' */

        /* Product: '<S215>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S218>/Sum of Elements' incorporates:
         *  Math: '<S218>/Math Function'
         *  SignalConversion: '<S218>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtMath_1 *
          rtb_TmpSignalConversionAtMath_1;

        /* Math: '<S218>/Math Function1' incorporates:
         *  Sum: '<S218>/Sum of Elements'
         *
         * About '<S218>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S218>/Math Function1' */

        /* Switch: '<S218>/Switch' incorporates:
         *  Constant: '<S218>/Constant'
         *  Product: '<S218>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_TmpSignalConversionAtMath_0;
          rtb_MatrixConcatenate3[1] = rtb_TmpSignalConversionAtMath_1;
          rtb_MatrixConcatenate3[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S218>/Switch' */

        /* Product: '<S218>/Divide' */
        rtb_TmpSignalConversionAtMath_1 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S217>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_TmpSignalConversionAtMat_hq[0] /
          rtb_TmpSignalConversionAtMat_hq[2];

        /* Product: '<S167>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_Add4_e5 / rtb_MathFunction_crm_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S218>/Divide' incorporates:
         *  Math: '<S213>/Square'
         */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S217>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_TmpSignalConversionAtMat_hq[1] /
          rtb_TmpSignalConversionAtMat_hq[2];

        /* Product: '<S167>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Sqrt_i / rtb_MathFunction_crm_idx_2;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S212>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S212>/Square'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S212>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S174>/Gain' incorporates:
         *  Math: '<S174>/Square'
         */
        rtb_Sqrt_i = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1 * 2.0F;

        /* Sum: '<S216>/Subtract' incorporates:
         *  Product: '<S216>/Multiply'
         *  Product: '<S216>/Multiply1'
         */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_1 *
          rtb_TmpSignalConversionAtDela_a[1] - rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S211>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S211>/Sign1' */

        /* Switch: '<S211>/Switch2' incorporates:
         *  Constant: '<S211>/Constant4'
         */
        if (rtb_Divide_l_idx_1 == 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        }

        /* End of Switch: '<S211>/Switch2' */

        /* DotProduct: '<S211>/Dot Product' */
        rtb_Add4_e5 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_TmpSignalConversionAtMath_1 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_TmpSignalConversionAtMath_0;

        /* Trigonometry: '<S211>/Acos' incorporates:
         *  DotProduct: '<S211>/Dot Product'
         */
        if (rtb_Add4_e5 > 1.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          if (rtb_Add4_e5 < -1.0F) {
            rtb_Add4_e5 = -1.0F;
          }
        }

        /* Product: '<S211>/Multiply' incorporates:
         *  Trigonometry: '<S211>/Acos'
         */
        rtb_Divide_l_idx_1 *= acosf(rtb_Add4_e5);

        /* Saturate: '<S174>/Saturation' */
        if (rtb_Divide_l_idx_1 > 1.57079637F) {
          rtb_Divide_l_idx_1 = 1.57079637F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.57079637F) {
            rtb_Divide_l_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S174>/Saturation' */

        /* Product: '<S174>/Divide' incorporates:
         *  Constant: '<S149>/L1'
         *  Constant: '<S174>/Constant'
         *  MinMax: '<S174>/Max'
         *  MinMax: '<S174>/Min'
         *  Product: '<S174>/Multiply1'
         *  Sqrt: '<S213>/Sqrt'
         *  Sum: '<S213>/Sum of Elements'
         *  Trigonometry: '<S174>/Sin'
         */
        rtb_MathFunction_crm_idx_2 = arm_sin_f32(rtb_Divide_l_idx_1) *
          rtb_Sqrt_i / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_DiscreteTimeIntegrator_n + rtb_Add3_c), 0.5F));

        /* Sum: '<S165>/Subtract' incorporates:
         *  Product: '<S165>/Multiply'
         *  Product: '<S165>/Multiply1'
         */
        rtb_TmpSignalConversionAtMath_1 = rtb_MathFunction_iq_idx_0 *
          FMS_ConstB.Divide[1] - rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S154>/Sign1' */
        if (rtb_TmpSignalConversionAtMath_1 < 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = -1.0F;
        } else {
          if (rtb_TmpSignalConversionAtMath_1 > 0.0F) {
            rtb_TmpSignalConversionAtMath_1 = 1.0F;
          }
        }

        /* End of Signum: '<S154>/Sign1' */

        /* Switch: '<S154>/Switch2' incorporates:
         *  Constant: '<S154>/Constant4'
         */
        if (rtb_TmpSignalConversionAtMath_1 == 0.0F) {
          rtb_TmpSignalConversionAtMath_1 = 1.0F;
        }

        /* End of Switch: '<S154>/Switch2' */

        /* DotProduct: '<S154>/Dot Product' */
        rtb_Sqrt_i = FMS_ConstB.Divide[0] * rtb_MathFunction_iq_idx_0 +
          FMS_ConstB.Divide[1] * rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S154>/Acos' incorporates:
         *  DotProduct: '<S154>/Dot Product'
         */
        if (rtb_Sqrt_i > 1.0F) {
          rtb_Sqrt_i = 1.0F;
        } else {
          if (rtb_Sqrt_i < -1.0F) {
            rtb_Sqrt_i = -1.0F;
          }
        }

        /* Product: '<S154>/Multiply' incorporates:
         *  Trigonometry: '<S154>/Acos'
         */
        rtb_TmpSignalConversionAtMath_1 *= acosf(rtb_Sqrt_i);

        /* Math: '<S157>/Rem' incorporates:
         *  Constant: '<S157>/Constant1'
         *  Delay: '<S153>/Delay'
         *  Sum: '<S153>/Sum2'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_TmpSignalConversionAtMath_1 -
          FMS_DW.Delay_DSTATE_h, 6.28318548F);

        /* Switch: '<S157>/Switch' incorporates:
         *  Abs: '<S157>/Abs'
         *  Constant: '<S157>/Constant'
         *  Constant: '<S163>/Constant'
         *  Product: '<S157>/Multiply'
         *  RelationalOperator: '<S163>/Compare'
         *  Sum: '<S157>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S157>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S157>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S157>/Switch' */

        /* Sum: '<S153>/Sum' incorporates:
         *  Delay: '<S153>/Delay'
         */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S162>/Multiply1' incorporates:
         *  Constant: '<S162>/const1'
         *  DiscreteIntegrator: '<S156>/Integrator'
         */
        rtb_Divide_l_idx_1 = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S162>/Add' incorporates:
         *  DiscreteIntegrator: '<S156>/Integrator1'
         *  Sum: '<S156>/Subtract'
         */
        rtb_Add4_e5 = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) +
          rtb_Divide_l_idx_1;

        /* Signum: '<S162>/Sign' */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Add4_e5;
        }

        /* End of Signum: '<S162>/Sign' */

        /* Sum: '<S162>/Add2' incorporates:
         *  Abs: '<S162>/Abs'
         *  Gain: '<S162>/Gain'
         *  Gain: '<S162>/Gain1'
         *  Product: '<S162>/Multiply2'
         *  Product: '<S162>/Multiply3'
         *  Sqrt: '<S162>/Sqrt'
         *  Sum: '<S162>/Add1'
         *  Sum: '<S162>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_Add4_e5) +
          FMS_ConstB.d_j) * FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F *
          rtb_Add3_c + rtb_Divide_l_idx_1;

        /* Sum: '<S162>/Add4' */
        rtb_Divide_l_idx_1 += rtb_Add4_e5 - rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S162>/Add3' */
        rtb_Add3_c = rtb_Add4_e5 + FMS_ConstB.d_j;

        /* Sum: '<S162>/Subtract1' */
        rtb_Add4_e5 -= FMS_ConstB.d_j;

        /* Signum: '<S162>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S162>/Sign1' */

        /* Signum: '<S162>/Sign2' */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else {
          if (rtb_Add4_e5 > 0.0F) {
            rtb_Add4_e5 = 1.0F;
          }
        }

        /* End of Signum: '<S162>/Sign2' */

        /* Sum: '<S162>/Add5' incorporates:
         *  Gain: '<S162>/Gain2'
         *  Product: '<S162>/Multiply4'
         *  Sum: '<S162>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_Add3_c - rtb_Add4_e5) * 0.5F *
          rtb_Divide_l_idx_1;

        /* Sum: '<S162>/Subtract3' */
        rtb_Add3_c = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_j;

        /* Sum: '<S162>/Add6' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_j;

        /* Product: '<S162>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_j;

        /* Signum: '<S162>/Sign5' incorporates:
         *  Signum: '<S162>/Sign6'
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_DiscreteTimeIntegrator_n;
          rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S162>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S153>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtMath_1 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S158>/Rem' incorporates:
         *  Constant: '<S158>/Constant1'
         */
        rtb_DiscreteTimeIntegrator_n = rt_remf(rtb_TmpSignalConversionAtMath_1,
          6.28318548F);

        /* Switch: '<S158>/Switch' incorporates:
         *  Abs: '<S158>/Abs'
         *  Constant: '<S158>/Constant'
         *  Constant: '<S164>/Constant'
         *  Product: '<S158>/Multiply'
         *  RelationalOperator: '<S164>/Compare'
         *  Sum: '<S158>/Add'
         */
        if (fabsf(rtb_DiscreteTimeIntegrator_n) > 3.14159274F) {
          /* Signum: '<S158>/Sign' */
          if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
            rtb_Sqrt_i = -1.0F;
          } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_Sqrt_i = 1.0F;
          } else {
            rtb_Sqrt_i = rtb_DiscreteTimeIntegrator_n;
          }

          /* End of Signum: '<S158>/Sign' */
          rtb_DiscreteTimeIntegrator_n -= 6.28318548F * rtb_Sqrt_i;
        }

        /* End of Switch: '<S158>/Switch' */

        /* Abs: '<S151>/Abs' */
        rtb_DiscreteTimeIntegrator_n = fabsf(rtb_DiscreteTimeIntegrator_n);

        /* Update for Delay: '<S175>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S169>/Constant'
         *  RelationalOperator: '<S169>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_DiscreteTimeIntegrator_n <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S171>/Acceleration_Speed' incorporates:
         *  Constant: '<S171>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        if (FMS_DW.Acceleration_Speed_DSTATE >= FMS_PARAM.CRUISE_SPEED) {
          FMS_DW.Acceleration_Speed_DSTATE = FMS_PARAM.CRUISE_SPEED;
        } else {
          if (FMS_DW.Acceleration_Speed_DSTATE <= 0.0F) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }
        }

        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_lh;

        /* End of Update for DiscreteIntegrator: '<S171>/Acceleration_Speed' */

        /* Product: '<S175>/Divide1' incorporates:
         *  Constant: '<S175>/Constant'
         */
        rtb_Sqrt_i = rtb_MathFunction_crm_idx_2 / FMS_PARAM.CRUISE_SPEED;

        /* Saturate: '<S175>/Saturation' */
        if (rtb_Sqrt_i > 0.314159274F) {
          rtb_Sqrt_i = 0.314159274F;
        } else {
          if (rtb_Sqrt_i < -0.314159274F) {
            rtb_Sqrt_i = -0.314159274F;
          }
        }

        /* End of Saturate: '<S175>/Saturation' */

        /* Update for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Sqrt_i;

        /* Update for Delay: '<S153>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S156>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S156>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Signum: '<S162>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S162>/Sign3' */

        /* Signum: '<S162>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S162>/Sign4' */

        /* Update for DiscreteIntegrator: '<S156>/Integrator' incorporates:
         *  Constant: '<S162>/const'
         *  Gain: '<S162>/Gain3'
         *  Product: '<S162>/Multiply5'
         *  Product: '<S162>/Multiply6'
         *  Sum: '<S162>/Subtract4'
         *  Sum: '<S162>/Subtract5'
         *  Sum: '<S162>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_MathFunction_iq_idx_0 -
          rtb_MathFunction_iq_idx_1) * FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_Add4_e5 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S156>/Integrator' */
        /* End of Outputs for SubSystem: '<S145>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Update for UnitDelay: '<S148>/Delay Input1' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S148>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S35>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S35>/Unknown' incorporates:
         *  ActionPort: '<S147>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S35>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S35>/Switch Case' */
      /* End of Outputs for SubSystem: '<S30>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S30>/Assist' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* SwitchCase: '<S34>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
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

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S132>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S49>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S67>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S83>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S108>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S95>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S34>/Acro' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S39>/Bus Assignment'
         *  Constant: '<S39>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Gain: '<S44>/Gain'
         *  Gain: '<S44>/Gain1'
         *  Gain: '<S44>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S45>/Saturation' incorporates:
         *  Constant: '<S45>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         *  Sum: '<S45>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_DiscreteTimeIntegrator_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S45>/Saturation' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S45>/Constant5'
         *  Gain: '<S45>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S45>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_DiscreteTimeIntegrator_n), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S34>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Stabilize' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S128>/Integrator'
           *  DiscreteIntegrator: '<S128>/Integrator1'
           *  DiscreteIntegrator: '<S129>/Integrator'
           *  DiscreteIntegrator: '<S129>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_l = 0.0F;
          FMS_DW.Integrator1_DSTATE_h = 0.0F;
          FMS_DW.Integrator_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S34>/Stabilize' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S133>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S34>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Stabilize' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Logic: '<S123>/Logical Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* Chart: '<S133>/Motion State' incorporates:
         *  Abs: '<S133>/Abs'
         *  Abs: '<S133>/Abs1'
         *  Constant: '<S143>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S143>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S132>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S132>/Hold Control' incorporates:
             *  ActionPort: '<S135>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S132>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S132>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S132>/Hold Control' incorporates:
           *  ActionPort: '<S135>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S132>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S132>/Brake Control' incorporates:
           *  ActionPort: '<S134>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S132>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S132>/Move Control' incorporates:
             *  ActionPort: '<S136>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S132>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S132>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S132>/Move Control' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S132>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S132>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S125>/Switch' incorporates:
         *  Constant: '<S125>/Constant'
         *  Constant: '<S125>/Constant4'
         *  Constant: '<S125>/Constant5'
         *  Gain: '<S125>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Saturate: '<S125>/Saturation'
         *  SignalConversion: '<S29>/Signal Copy2'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         *  Sum: '<S125>/Add'
         *  Sum: '<S125>/Sum'
         */
        if (FMS_B.Compare) {
          rtb_y_md = FMS_PARAM.LAND_LOCK_THRO;
        } else {
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            /* Saturate: '<S125>/Saturation' */
            rtb_DiscreteTimeIntegrator_n = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S125>/Saturation' */
            rtb_DiscreteTimeIntegrator_n = 0.0F;
          } else {
            /* Saturate: '<S125>/Saturation' incorporates:
             *  Constant: '<S125>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S29>/Signal Copy2'
             *  Sum: '<S125>/Sum'
             */
            rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_DiscreteTimeIntegrator_n), 65536.0F) + 1000U);
        }

        /* End of Switch: '<S125>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S42>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DataTypeConversion: '<S123>/Data Type Conversion'
         *  DiscreteIntegrator: '<S128>/Integrator1'
         *  DiscreteIntegrator: '<S129>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S123>/Multiply'
         *  Product: '<S123>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_l;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_h;

        /* Saturate: '<S132>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S132>/Saturation' */

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.throttle_cmd = rtb_y_md;

        /* Product: '<S131>/Multiply1' incorporates:
         *  Constant: '<S131>/const1'
         *  DiscreteIntegrator: '<S129>/Integrator'
         */
        rtb_TmpSignalConversionAtMath_1 = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S127>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S127>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S131>/Add' incorporates:
         *  DiscreteIntegrator: '<S129>/Integrator1'
         *  Gain: '<S123>/Gain1'
         *  Gain: '<S127>/Gain'
         *  Sum: '<S129>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F
          - FMS_PARAM.PITCH_DZ) * rtb_DiscreteTimeIntegrator_n *
          -FMS_PARAM.ROLL_PITCH_LIM) + rtb_TmpSignalConversionAtMath_1;

        /* Signum: '<S131>/Sign' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S131>/Sign' */

        /* Sum: '<S131>/Add2' incorporates:
         *  Abs: '<S131>/Abs'
         *  Gain: '<S131>/Gain'
         *  Gain: '<S131>/Gain1'
         *  Product: '<S131>/Multiply2'
         *  Product: '<S131>/Multiply3'
         *  Sqrt: '<S131>/Sqrt'
         *  Sum: '<S131>/Add1'
         *  Sum: '<S131>/Subtract'
         */
        rtb_Sqrt_i = (sqrtf((8.0F * fabsf(rtb_MathFunction_iq_idx_0) +
                             FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l)
          * 0.5F * rtb_DiscreteTimeIntegrator_n +
          rtb_TmpSignalConversionAtMath_1;

        /* Sum: '<S131>/Add4' */
        rtb_Divide_l_idx_1 = (rtb_MathFunction_iq_idx_0 - rtb_Sqrt_i) +
          rtb_TmpSignalConversionAtMath_1;

        /* Sum: '<S131>/Add3' */
        rtb_Add3_c = rtb_MathFunction_iq_idx_0 + FMS_ConstB.d_l;

        /* Sum: '<S131>/Subtract1' */
        rtb_MathFunction_iq_idx_0 -= FMS_ConstB.d_l;

        /* Signum: '<S131>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S131>/Sign1' */

        /* Signum: '<S131>/Sign2' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 > 0.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S131>/Sign2' */

        /* Sum: '<S131>/Add5' incorporates:
         *  Gain: '<S131>/Gain2'
         *  Product: '<S131>/Multiply4'
         *  Sum: '<S131>/Subtract2'
         */
        rtb_Sqrt_i += (rtb_Add3_c - rtb_MathFunction_iq_idx_0) * 0.5F *
          rtb_Divide_l_idx_1;

        /* Sum: '<S131>/Subtract3' */
        rtb_Add3_c = rtb_Sqrt_i - FMS_ConstB.d_l;

        /* Sum: '<S131>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Sqrt_i + FMS_ConstB.d_l;

        /* Product: '<S131>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Sqrt_i / FMS_ConstB.d_l;

        /* Signum: '<S131>/Sign5' incorporates:
         *  Signum: '<S131>/Sign6'
         */
        if (rtb_Sqrt_i < 0.0F) {
          rtb_MathFunction_crm_idx_2 = -1.0F;
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Sqrt_i > 0.0F) {
          rtb_MathFunction_crm_idx_2 = 1.0F;
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_MathFunction_crm_idx_2 = rtb_Sqrt_i;
          rtb_Add4_e5 = rtb_Sqrt_i;
        }

        /* End of Signum: '<S131>/Sign5' */

        /* Product: '<S130>/Multiply1' incorporates:
         *  Constant: '<S130>/const1'
         *  DiscreteIntegrator: '<S128>/Integrator'
         */
        rtb_TmpSignalConversionAtMath_1 = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S126>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S126>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S130>/Add' incorporates:
         *  DiscreteIntegrator: '<S128>/Integrator1'
         *  Gain: '<S123>/Gain'
         *  Gain: '<S126>/Gain'
         *  Sum: '<S128>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F
          - FMS_PARAM.ROLL_DZ) * rtb_DiscreteTimeIntegrator_n *
          FMS_PARAM.ROLL_PITCH_LIM) + rtb_TmpSignalConversionAtMath_1;

        /* Signum: '<S130>/Sign' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S130>/Sign' */

        /* Sum: '<S130>/Add2' incorporates:
         *  Abs: '<S130>/Abs'
         *  Gain: '<S130>/Gain'
         *  Gain: '<S130>/Gain1'
         *  Product: '<S130>/Multiply2'
         *  Product: '<S130>/Multiply3'
         *  Sqrt: '<S130>/Sqrt'
         *  Sum: '<S130>/Add1'
         *  Sum: '<S130>/Subtract'
         */
        rtb_Sqrt_i = (sqrtf((8.0F * fabsf(rtb_MathFunction_iq_idx_0) +
                             FMS_ConstB.d_h) * FMS_ConstB.d_h) - FMS_ConstB.d_h)
          * 0.5F * rtb_DiscreteTimeIntegrator_n +
          rtb_TmpSignalConversionAtMath_1;

        /* Sum: '<S130>/Add4' */
        rtb_TmpSignalConversionAtMath_1 += rtb_MathFunction_iq_idx_0 -
          rtb_Sqrt_i;

        /* Sum: '<S130>/Add3' */
        rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0 +
          FMS_ConstB.d_h;

        /* Sum: '<S130>/Subtract1' */
        rtb_MathFunction_iq_idx_0 -= FMS_ConstB.d_h;

        /* Signum: '<S130>/Sign1' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else {
          if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }
        }

        /* End of Signum: '<S130>/Sign1' */

        /* Signum: '<S130>/Sign2' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 > 0.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S130>/Sign2' */

        /* Sum: '<S130>/Add5' incorporates:
         *  Gain: '<S130>/Gain2'
         *  Product: '<S130>/Multiply4'
         *  Sum: '<S130>/Subtract2'
         */
        rtb_Sqrt_i += (rtb_DiscreteTimeIntegrator_n - rtb_MathFunction_iq_idx_0)
          * 0.5F * rtb_TmpSignalConversionAtMath_1;

        /* Update for DiscreteIntegrator: '<S128>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S128>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S129>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S129>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Signum: '<S131>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S131>/Sign3' */

        /* Signum: '<S131>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S131>/Sign4' */

        /* Update for DiscreteIntegrator: '<S129>/Integrator' incorporates:
         *  Constant: '<S131>/const'
         *  Gain: '<S131>/Gain3'
         *  Product: '<S131>/Multiply5'
         *  Product: '<S131>/Multiply6'
         *  Sum: '<S131>/Subtract4'
         *  Sum: '<S131>/Subtract5'
         *  Sum: '<S131>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += ((rtb_MathFunction_iq_idx_1 -
          rtb_MathFunction_crm_idx_2) * FMS_ConstB.Gain4_j *
          ((rtb_Divide_l_idx_1 - rtb_Add3_c) * 0.5F) - rtb_Add4_e5 * 12.566371F)
          * 0.004F;

        /* Sum: '<S130>/Add6' */
        rtb_Add3_c = rtb_Sqrt_i + FMS_ConstB.d_h;

        /* Sum: '<S130>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_Sqrt_i - FMS_ConstB.d_h;

        /* Signum: '<S130>/Sign5' */
        if (rtb_Sqrt_i < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Sqrt_i > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Sqrt_i;
        }

        /* End of Signum: '<S130>/Sign5' */

        /* Signum: '<S130>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S130>/Sign3' */

        /* Signum: '<S130>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S130>/Sign4' */

        /* Signum: '<S130>/Sign6' */
        if (rtb_Sqrt_i < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Sqrt_i > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Sqrt_i;
        }

        /* End of Signum: '<S130>/Sign6' */

        /* Update for DiscreteIntegrator: '<S128>/Integrator' incorporates:
         *  Constant: '<S130>/const'
         *  Gain: '<S130>/Gain3'
         *  Product: '<S130>/Divide'
         *  Product: '<S130>/Multiply5'
         *  Product: '<S130>/Multiply6'
         *  Sum: '<S130>/Subtract4'
         *  Sum: '<S130>/Subtract5'
         *  Sum: '<S130>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Sqrt_i / FMS_ConstB.d_h -
          rtb_DiscreteTimeIntegrator_n) * FMS_ConstB.Gain4_n * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_Add4_e5 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S34>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Altitude' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S63>/Integrator'
           *  DiscreteIntegrator: '<S63>/Integrator1'
           *  DiscreteIntegrator: '<S64>/Integrator'
           *  DiscreteIntegrator: '<S64>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S34>/Altitude' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S50>/Motion Status'
           *  Chart: '<S68>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S34>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Altitude' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S50>/Motion Status' incorporates:
         *  Abs: '<S50>/Abs'
         *  Abs: '<S50>/Abs1'
         *  Constant: '<S59>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S59>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S49>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S49>/Hold Control' incorporates:
             *  ActionPort: '<S52>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S49>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S49>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S49>/Hold Control' incorporates:
           *  ActionPort: '<S52>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S49>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S49>/Brake Control' incorporates:
           *  ActionPort: '<S51>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S49>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S49>/Move Control' incorporates:
           *  ActionPort: '<S53>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S49>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S49>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S46>/Switch' incorporates:
         *  Constant: '<S46>/Constant'
         *  Saturate: '<S49>/Saturation1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        if (FMS_B.Compare) {
          rtb_Add3_c = 0.5F;
        } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S49>/Saturation1' */
          rtb_Add3_c = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S49>/Saturation1' */
          rtb_Add3_c = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S49>/Saturation1' */
          rtb_Add3_c = FMS_B.Merge_l;
        }

        /* End of Switch: '<S46>/Switch' */

        /* Logic: '<S47>/Logical Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* Chart: '<S68>/Motion State' incorporates:
         *  Abs: '<S68>/Abs'
         *  Abs: '<S68>/Abs1'
         *  Constant: '<S78>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S78>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S67>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S67>/Hold Control' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S67>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S67>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S67>/Hold Control' incorporates:
           *  ActionPort: '<S70>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S67>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S67>/Brake Control' incorporates:
           *  ActionPort: '<S69>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S67>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S67>/Move Control' incorporates:
             *  ActionPort: '<S71>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S67>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S67>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S67>/Move Control' incorporates:
           *  ActionPort: '<S71>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S67>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S67>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S40>/Bus Assignment'
         *  Constant: '<S40>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DataTypeConversion: '<S47>/Data Type Conversion'
         *  DiscreteIntegrator: '<S63>/Integrator1'
         *  DiscreteIntegrator: '<S64>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S47>/Multiply'
         *  Product: '<S47>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S67>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S40>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S40>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S40>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S67>/Saturation' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;

        /* Product: '<S66>/Multiply1' incorporates:
         *  Constant: '<S66>/const1'
         *  DiscreteIntegrator: '<S64>/Integrator'
         */
        rtb_TmpSignalConversionAtMath_1 = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S62>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S62>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S66>/Add' incorporates:
         *  DiscreteIntegrator: '<S64>/Integrator1'
         *  Gain: '<S47>/Gain1'
         *  Gain: '<S62>/Gain'
         *  Sum: '<S64>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F
          - FMS_PARAM.PITCH_DZ) * rtb_DiscreteTimeIntegrator_n *
          -FMS_PARAM.ROLL_PITCH_LIM) + rtb_TmpSignalConversionAtMath_1;

        /* Signum: '<S66>/Sign' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S66>/Sign' */

        /* Sum: '<S66>/Add2' incorporates:
         *  Abs: '<S66>/Abs'
         *  Gain: '<S66>/Gain'
         *  Gain: '<S66>/Gain1'
         *  Product: '<S66>/Multiply2'
         *  Product: '<S66>/Multiply3'
         *  Sqrt: '<S66>/Sqrt'
         *  Sum: '<S66>/Add1'
         *  Sum: '<S66>/Subtract'
         */
        rtb_Sqrt_i = (sqrtf((8.0F * fabsf(rtb_MathFunction_iq_idx_0) +
                             FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) *
          0.5F * rtb_DiscreteTimeIntegrator_n + rtb_TmpSignalConversionAtMath_1;

        /* Sum: '<S66>/Add4' */
        rtb_Divide_l_idx_1 = (rtb_MathFunction_iq_idx_0 - rtb_Sqrt_i) +
          rtb_TmpSignalConversionAtMath_1;

        /* Sum: '<S66>/Add3' */
        rtb_Add3_c = rtb_MathFunction_iq_idx_0 + FMS_ConstB.d;

        /* Sum: '<S66>/Subtract1' */
        rtb_MathFunction_iq_idx_0 -= FMS_ConstB.d;

        /* Signum: '<S66>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S66>/Sign1' */

        /* Signum: '<S66>/Sign2' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 > 0.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S66>/Sign2' */

        /* Sum: '<S66>/Add5' incorporates:
         *  Gain: '<S66>/Gain2'
         *  Product: '<S66>/Multiply4'
         *  Sum: '<S66>/Subtract2'
         */
        rtb_Sqrt_i += (rtb_Add3_c - rtb_MathFunction_iq_idx_0) * 0.5F *
          rtb_Divide_l_idx_1;

        /* Sum: '<S66>/Subtract3' */
        rtb_Add3_c = rtb_Sqrt_i - FMS_ConstB.d;

        /* Sum: '<S66>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Sqrt_i + FMS_ConstB.d;

        /* Product: '<S66>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Sqrt_i / FMS_ConstB.d;

        /* Signum: '<S66>/Sign5' incorporates:
         *  Signum: '<S66>/Sign6'
         */
        if (rtb_Sqrt_i < 0.0F) {
          rtb_MathFunction_crm_idx_2 = -1.0F;
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Sqrt_i > 0.0F) {
          rtb_MathFunction_crm_idx_2 = 1.0F;
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_MathFunction_crm_idx_2 = rtb_Sqrt_i;
          rtb_Add4_e5 = rtb_Sqrt_i;
        }

        /* End of Signum: '<S66>/Sign5' */

        /* Product: '<S65>/Multiply1' incorporates:
         *  Constant: '<S65>/const1'
         *  DiscreteIntegrator: '<S63>/Integrator'
         */
        rtb_TmpSignalConversionAtMath_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S61>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S61>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S65>/Add' incorporates:
         *  DiscreteIntegrator: '<S63>/Integrator1'
         *  Gain: '<S47>/Gain'
         *  Gain: '<S61>/Gain'
         *  Sum: '<S63>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_DiscreteTimeIntegrator_n *
          FMS_PARAM.ROLL_PITCH_LIM) + rtb_TmpSignalConversionAtMath_1;

        /* Signum: '<S65>/Sign' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S65>/Sign' */

        /* Sum: '<S65>/Add2' incorporates:
         *  Abs: '<S65>/Abs'
         *  Gain: '<S65>/Gain'
         *  Gain: '<S65>/Gain1'
         *  Product: '<S65>/Multiply2'
         *  Product: '<S65>/Multiply3'
         *  Sqrt: '<S65>/Sqrt'
         *  Sum: '<S65>/Add1'
         *  Sum: '<S65>/Subtract'
         */
        rtb_Sqrt_i = (sqrtf((8.0F * fabsf(rtb_MathFunction_iq_idx_0) +
                             FMS_ConstB.d_e) * FMS_ConstB.d_e) - FMS_ConstB.d_e)
          * 0.5F * rtb_DiscreteTimeIntegrator_n +
          rtb_TmpSignalConversionAtMath_1;

        /* Sum: '<S65>/Add4' */
        rtb_TmpSignalConversionAtMath_1 += rtb_MathFunction_iq_idx_0 -
          rtb_Sqrt_i;

        /* Sum: '<S65>/Add3' */
        rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0 +
          FMS_ConstB.d_e;

        /* Sum: '<S65>/Subtract1' */
        rtb_MathFunction_iq_idx_0 -= FMS_ConstB.d_e;

        /* Signum: '<S65>/Sign1' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else {
          if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign1' */

        /* Signum: '<S65>/Sign2' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 > 0.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign2' */

        /* Sum: '<S65>/Add5' incorporates:
         *  Gain: '<S65>/Gain2'
         *  Product: '<S65>/Multiply4'
         *  Sum: '<S65>/Subtract2'
         */
        rtb_Sqrt_i += (rtb_DiscreteTimeIntegrator_n - rtb_MathFunction_iq_idx_0)
          * 0.5F * rtb_TmpSignalConversionAtMath_1;

        /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S63>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Update for DiscreteIntegrator: '<S64>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S64>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S66>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S66>/Sign3' */

        /* Signum: '<S66>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S66>/Sign4' */

        /* Update for DiscreteIntegrator: '<S64>/Integrator' incorporates:
         *  Constant: '<S66>/const'
         *  Gain: '<S66>/Gain3'
         *  Product: '<S66>/Multiply5'
         *  Product: '<S66>/Multiply6'
         *  Sum: '<S66>/Subtract4'
         *  Sum: '<S66>/Subtract5'
         *  Sum: '<S66>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_MathFunction_iq_idx_1 -
          rtb_MathFunction_crm_idx_2) * FMS_ConstB.Gain4 * ((rtb_Divide_l_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_Add4_e5 * 12.566371F) * 0.004F;

        /* Sum: '<S65>/Add6' */
        rtb_Add3_c = rtb_Sqrt_i + FMS_ConstB.d_e;

        /* Sum: '<S65>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_Sqrt_i - FMS_ConstB.d_e;

        /* Signum: '<S65>/Sign5' */
        if (rtb_Sqrt_i < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Sqrt_i > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Sqrt_i;
        }

        /* End of Signum: '<S65>/Sign5' */

        /* Signum: '<S65>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign3' */

        /* Signum: '<S65>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign4' */

        /* Signum: '<S65>/Sign6' */
        if (rtb_Sqrt_i < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Sqrt_i > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Sqrt_i;
        }

        /* End of Signum: '<S65>/Sign6' */

        /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
         *  Constant: '<S65>/const'
         *  Gain: '<S65>/Gain3'
         *  Product: '<S65>/Divide'
         *  Product: '<S65>/Multiply5'
         *  Product: '<S65>/Multiply6'
         *  Sum: '<S65>/Subtract4'
         *  Sum: '<S65>/Subtract5'
         *  Sum: '<S65>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Sqrt_i / FMS_ConstB.d_e -
          rtb_DiscreteTimeIntegrator_n) * FMS_ConstB.Gain4_d * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_Add4_e5 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S34>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S34>/Position' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S109>/Motion State'
           *  Chart: '<S84>/Motion Status'
           *  Chart: '<S96>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S34>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Position' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S84>/Motion Status' incorporates:
         *  Abs: '<S84>/Abs'
         *  Abs: '<S84>/Abs1'
         *  Constant: '<S93>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S93>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S83>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S83>/Hold Control' incorporates:
             *  ActionPort: '<S86>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S83>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S83>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S83>/Hold Control' incorporates:
           *  ActionPort: '<S86>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S83>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S83>/Brake Control' incorporates:
           *  ActionPort: '<S85>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S83>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S83>/Move Control' incorporates:
           *  ActionPort: '<S87>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S83>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S83>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S96>/Motion State' incorporates:
         *  Abs: '<S96>/Abs'
         *  Abs: '<S96>/Abs1'
         *  Constant: '<S106>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S106>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S109>/Logical Operator' incorporates:
         *  Abs: '<S109>/Abs1'
         *  Abs: '<S109>/Abs2'
         *  Constant: '<S120>/Constant'
         *  Constant: '<S121>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S120>/Compare'
         *  RelationalOperator: '<S121>/Compare'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S109>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S109>/Square'
         *  Math: '<S109>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S109>/Sqrt'
         *  Sum: '<S109>/Add'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_n;
          rtb_state_ki = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_ki = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_ki = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_ki = MotionState_Hold;
            if (rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_ki = MotionState_Move;
            }
            break;

           default:
            rtb_state_ki = MotionState_Move;
            if (!rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_ki = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S109>/Motion State' */

        /* SwitchCase: '<S108>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_ki) {
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
            /* SystemReset for IfAction SubSystem: '<S108>/Hold Control' incorporates:
             *  ActionPort: '<S111>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S108>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S108>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S108>/Hold Control' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S108>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S108>/Brake Control' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S108>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S108>/Move Control' incorporates:
             *  ActionPort: '<S112>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S108>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S108>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S108>/Move Control' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S108>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S108>/Switch Case' */

        /* SwitchCase: '<S95>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_j;
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S95>/Hold Control' incorporates:
             *  ActionPort: '<S98>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S95>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S95>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S95>/Hold Control' incorporates:
           *  ActionPort: '<S98>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S95>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S95>/Brake Control' incorporates:
           *  ActionPort: '<S97>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S95>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S95>/Move Control' incorporates:
             *  ActionPort: '<S99>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S95>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S95>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S95>/Move Control' incorporates:
           *  ActionPort: '<S99>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S95>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S95>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S41>/Bus Assignment'
         *  Constant: '<S41>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S41>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S95>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S95>/Saturation' */

        /* Saturate: '<S108>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S108>/Saturation1' */

        /* Saturate: '<S83>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S41>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S83>/Saturation1' */
        /* End of Outputs for SubSystem: '<S34>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S34>/Unknown' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S34>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S34>/Switch Case' */
      /* End of Outputs for SubSystem: '<S30>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S30>/Manual' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S31>/Bus Assignment'
       *  BusAssignment: '<S36>/Bus Assignment'
       *  Constant: '<S36>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S36>/Bus Assignment' incorporates:
       *  BusAssignment: '<S31>/Bus Assignment'
       *  Constant: '<S36>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S30>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S30>/Unknown' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S31>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S30>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S30>/Switch Case' */
    /* End of Outputs for SubSystem: '<S28>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S28>/Switch Case' */

  /* BusAssignment: '<S31>/Bus Assignment' incorporates:
   *  Constant: '<S31>/Constant'
   *  DataStoreRead: '<S31>/Data Store Read'
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   *  DiscreteIntegrator: '<S462>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S31>/Sum'
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

  /* Update for DiscreteIntegrator: '<S462>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S462>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S13>/SetHome' incorporates:
   *  TriggerPort: '<S20>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S20>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S13>/SetHome' */

  /* Update for DiscreteIntegrator: '<S477>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S477>/Gain'
   *  Sum: '<S477>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S479>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S479>/Gain'
   *  Sum: '<S479>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S478>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S478>/Gain'
   *  Sum: '<S478>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_l_idx_2 -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  rtb_DiscreteTimeIntegrator_n = (real32_T)
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)FMS_EXPORT.period;
  if (rtb_DiscreteTimeIntegrator_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)
      rtb_DiscreteTimeIntegrator_n;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S18>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S19>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S25>/Delay Input1':
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

  /* Update for UnitDelay: '<S9>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_DiscreteTimeIntegrator_n = (real32_T)
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)FMS_EXPORT.period;
  if (rtb_DiscreteTimeIntegrator_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)
      rtb_DiscreteTimeIntegrator_n;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S10>/Delay' */
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
  /* Start for SwitchCase: '<S28>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S28>/Arm' */
  /* Start for SwitchCase: '<S30>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S30>/SubMode' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S37>/Return' */
  /* Start for SwitchCase: '<S420>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S410>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S37>/Return' */

  /* Start for IfAction SubSystem: '<S37>/Hold' */
  /* Start for SwitchCase: '<S359>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S337>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S347>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S37>/Hold' */
  /* End of Start for SubSystem: '<S30>/SubMode' */

  /* Start for IfAction SubSystem: '<S30>/Auto' */
  /* Start for SwitchCase: '<S35>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S35>/Mission' */
  /* Start for Resettable SubSystem: '<S145>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S193>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S183>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S145>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S35>/Mission' */
  /* End of Start for SubSystem: '<S30>/Auto' */

  /* Start for IfAction SubSystem: '<S30>/Assist' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S34>/Stabilize' */
  /* Start for SwitchCase: '<S132>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S34>/Stabilize' */

  /* Start for IfAction SubSystem: '<S34>/Altitude' */
  /* Start for SwitchCase: '<S49>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S67>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S34>/Altitude' */

  /* Start for IfAction SubSystem: '<S34>/Position' */
  /* Start for SwitchCase: '<S83>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S108>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S95>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S34>/Position' */
  /* End of Start for SubSystem: '<S30>/Assist' */
  /* End of Start for SubSystem: '<S28>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S477>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S478>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

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
  /* SystemInitialize for IfAction SubSystem: '<S28>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S30>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S37>/Takeoff' */
  /* InitializeConditions for Delay: '<S460>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S456>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S456>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Return' */
  /* InitializeConditions for Delay: '<S405>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S406>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_d = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S401>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_k = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_g = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S447>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S384>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S387>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S383>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S387>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S421>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S420>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S420>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S420>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S420>/Move Control' */

  /* SystemInitialize for Merge: '<S420>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S411>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S410>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S410>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S410>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S410>/Move Control' */

  /* SystemInitialize for Merge: '<S410>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold' */
  /* SystemInitialize for Chart: '<S338>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S348>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S360>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S359>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S359>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S359>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S359>/Move Control' */

  /* SystemInitialize for Merge: '<S359>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S337>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S337>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S337>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S337>/Move Control' */

  /* SystemInitialize for Merge: '<S337>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S347>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S347>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S347>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S347>/Move Control' */

  /* SystemInitialize for Merge: '<S347>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S30>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S35>/Mission' */
  /* InitializeConditions for UnitDelay: '<S148>/Delay Input1'
   *
   * Block description for '<S148>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S145>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S175>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S171>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S153>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S194>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S193>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S193>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S193>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S193>/Move Control' */

  /* SystemInitialize for Merge: '<S193>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S184>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S183>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S183>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S183>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S183>/Move Control' */

  /* SystemInitialize for Merge: '<S183>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S145>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S35>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S30>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S34>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S128>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S128>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* SystemInitialize for Chart: '<S133>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S132>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S132>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S132>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S132>/Move Control' */

  /* SystemInitialize for Merge: '<S132>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S64>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S64>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S50>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S49>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S49>/Hold Control' */

  /* SystemInitialize for Merge: '<S49>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S68>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S67>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S67>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S67>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S67>/Move Control' */

  /* SystemInitialize for Merge: '<S67>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Position' */
  /* SystemInitialize for Chart: '<S84>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for IfAction SubSystem: '<S83>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S83>/Hold Control' */

  /* SystemInitialize for Chart: '<S96>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S109>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S108>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S108>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S108>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S108>/Move Control' */

  /* SystemInitialize for Merge: '<S108>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S83>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S95>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S95>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S95>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S95>/Move Control' */

  /* SystemInitialize for Merge: '<S95>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Position' */
  /* End of SystemInitialize for SubSystem: '<S30>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S28>/Arm' */
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
