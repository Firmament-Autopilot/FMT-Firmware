/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2104
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jan 31 09:13:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S460>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S470>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S133>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o4                 ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S50>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S351>/Motion State' */
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
#define FMS_IN_Land_j                  ((uint8_T)3U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Loiter_p                ((uint8_T)4U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)5U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)6U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_SetSpeed                ((uint8_T)7U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)8U)
#define FMS_IN_Waypoint                ((uint8_T)9U)
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
                                        *   '<S513>/Constant'
                                        *   '<S334>/L1'
                                        *   '<S47>/Gain'
                                        *   '<S47>/Gain1'
                                        *   '<S123>/Gain'
                                        *   '<S123>/Gain1'
                                        *   '<S125>/Constant'
                                        *   '<S149>/L1'
                                        *   '<S230>/Saturation'
                                        *   '<S231>/Saturation1'
                                        *   '<S231>/Saturation2'
                                        *   '<S231>/Saturation3'
                                        *   '<S375>/Land_Speed'
                                        *   '<S376>/Saturation1'
                                        *   '<S501>/Takeoff_Speed'
                                        *   '<S502>/Gain2'
                                        *   '<S502>/Saturation1'
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
                                        *   '<S284>/Gain2'
                                        *   '<S291>/Gain1'
                                        *   '<S291>/Gain2'
                                        *   '<S340>/Saturation1'
                                        *   '<S350>/Saturation'
                                        *   '<S362>/Saturation1'
                                        *   '<S377>/Constant'
                                        *   '<S380>/Gain2'
                                        *   '<S441>/Gain'
                                        *   '<S441>/Saturation1'
                                        *   '<S444>/Constant'
                                        *   '<S444>/vel'
                                        *   '<S444>/Switch'
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
                                        *   '<S171>/Switch'
                                        *   '<S343>/Gain2'
                                        *   '<S344>/Gain1'
                                        *   '<S353>/Gain2'
                                        *   '<S354>/Gain1'
                                        *   '<S365>/Gain2'
                                        *   '<S366>/Gain6'
                                        *   '<S390>/Gain2'
                                        *   '<S390>/Saturation'
                                        *   '<S391>/Integrator'
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
                                        *   '<S346>/Dead Zone'
                                        *   '<S346>/Gain'
                                        *   '<S358>/Dead Zone'
                                        *   '<S358>/Gain'
                                        *   '<S370>/Dead Zone'
                                        *   '<S370>/Gain'
                                        *   '<S371>/Dead Zone'
                                        *   '<S371>/Gain'
                                        *   '<S459>/Saturation1'
                                        *   '<S469>/Saturation1'
                                        *   '<S186>/Saturation1'
                                        *   '<S196>/Saturation1'
                                        *   '<S462>/Gain2'
                                        *   '<S463>/Gain1'
                                        *   '<S472>/Gain2'
                                        *   '<S473>/Gain6'
                                        *   '<S189>/Gain2'
                                        *   '<S190>/Gain1'
                                        *   '<S199>/Gain2'
                                        *   '<S200>/Gain6'
                                        *   '<S465>/Dead Zone'
                                        *   '<S465>/Gain'
                                        *   '<S477>/Dead Zone'
                                        *   '<S477>/Gain'
                                        *   '<S478>/Dead Zone'
                                        *   '<S478>/Gain'
                                        *   '<S192>/Dead Zone'
                                        *   '<S192>/Gain'
                                        *   '<S204>/Dead Zone'
                                        *   '<S204>/Gain'
                                        *   '<S205>/Dead Zone'
                                        *   '<S205>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S12>/Constant1'
                                        *   '<S511>/Constant'
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
static void FMS_Manual(void);
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
 *    '<S459>/Hold Control'
 *    '<S340>/Hold Control'
 *    '<S186>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S83>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S462>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S459>/Hold Control'
 *    '<S340>/Hold Control'
 *    '<S186>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S83>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S462>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S459>/Hold Control'
 *    '<S340>/Hold Control'
 *    '<S186>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S83>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S462>/Delay' incorporates:
   *  Gain: '<S464>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S462>/Gain2' incorporates:
   *  Delay: '<S462>/Delay'
   *  Gain: '<S464>/Gain'
   *  Sum: '<S462>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S462>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S459>/Brake Control'
 *    '<S340>/Brake Control'
 *    '<S350>/Brake Control'
 *    '<S186>/Brake Control'
 *    '<S132>/Brake Control'
 *    '<S49>/Brake Control'
 *    '<S67>/Brake Control'
 *    '<S83>/Brake Control'
 *    '<S95>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S461>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S461>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S459>/Move Control'
 *    '<S340>/Move Control'
 *    '<S186>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S459>/Move Control'
 *    '<S340>/Move Control'
 *    '<S186>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S459>/Move Control'
 *    '<S340>/Move Control'
 *    '<S186>/Move Control'
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

  /* Product: '<S467>/Multiply1' incorporates:
   *  Constant: '<S467>/const1'
   *  DiscreteIntegrator: '<S466>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S465>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S465>/Dead Zone' */

  /* Sum: '<S467>/Add' incorporates:
   *  DiscreteIntegrator: '<S466>/Integrator1'
   *  Gain: '<S463>/Gain1'
   *  Gain: '<S465>/Gain'
   *  Sum: '<S466>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S467>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S467>/Sign' */

  /* Sum: '<S467>/Add2' incorporates:
   *  Abs: '<S467>/Abs'
   *  Gain: '<S467>/Gain'
   *  Gain: '<S467>/Gain1'
   *  Product: '<S467>/Multiply2'
   *  Product: '<S467>/Multiply3'
   *  Sqrt: '<S467>/Sqrt'
   *  Sum: '<S467>/Add1'
   *  Sum: '<S467>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S467>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S467>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S467>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S467>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S467>/Sign1' */

  /* Signum: '<S467>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S467>/Sign2' */

  /* Sum: '<S467>/Add5' incorporates:
   *  Gain: '<S467>/Gain2'
   *  Product: '<S467>/Multiply4'
   *  Sum: '<S467>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S463>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S466>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S466>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S466>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S467>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S467>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S467>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S467>/Sign5' */

  /* Signum: '<S467>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S467>/Sign3' */

  /* Signum: '<S467>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S467>/Sign4' */

  /* Signum: '<S467>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S467>/Sign6' */

  /* Update for DiscreteIntegrator: '<S466>/Integrator' incorporates:
   *  Constant: '<S467>/const'
   *  Gain: '<S467>/Gain3'
   *  Product: '<S467>/Divide'
   *  Product: '<S467>/Multiply5'
   *  Product: '<S467>/Multiply6'
   *  Sum: '<S467>/Subtract4'
   *  Sum: '<S467>/Subtract5'
   *  Sum: '<S467>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S460>/Motion Status'
 *    '<S341>/Motion Status'
 *    '<S187>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S460>/Motion Status'
 *    '<S341>/Motion Status'
 *    '<S187>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S460>/Motion Status'
 *    '<S341>/Motion Status'
 *    '<S187>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S460>/Motion Status' */
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

  /* End of Chart: '<S460>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S469>/Hold Control'
 *    '<S362>/Hold Control'
 *    '<S196>/Hold Control'
 *    '<S108>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S472>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S469>/Hold Control'
 *    '<S362>/Hold Control'
 *    '<S196>/Hold Control'
 *    '<S108>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S472>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S469>/Hold Control'
 *    '<S362>/Hold Control'
 *    '<S196>/Hold Control'
 *    '<S108>/Hold Control'
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

  /* Delay: '<S472>/Delay' incorporates:
   *  SignalConversion: '<S472>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S476>/Trigonometric Function1' incorporates:
   *  Gain: '<S475>/Gain'
   *  Trigonometry: '<S476>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S476>/Trigonometric Function' incorporates:
   *  Gain: '<S475>/Gain'
   *  Trigonometry: '<S476>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S476>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S476>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S476>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S476>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S476>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S476>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S476>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S472>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S472>/Delay'
   *  SignalConversion: '<S472>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S472>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S472>/Multiply' incorporates:
   *  SignalConversion: '<S472>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S472>/Multiply' */

  /* Gain: '<S472>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S472>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S469>/Brake Control'
 *    '<S362>/Brake Control'
 *    '<S196>/Brake Control'
 *    '<S108>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S471>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S469>/Move Control'
 *    '<S362>/Move Control'
 *    '<S196>/Move Control'
 *    '<S108>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S469>/Move Control'
 *    '<S362>/Move Control'
 *    '<S196>/Move Control'
 *    '<S108>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S479>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S469>/Move Control'
 *    '<S362>/Move Control'
 *    '<S196>/Move Control'
 *    '<S108>/Move Control'
 */
void FMS_MoveControl_j(real32_T rtu_FMS_In, real32_T rtu_FMS_In_o, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_i_T *localC,
  DW_MoveControl_FMS_f_T *localDW)
{
  real32_T rtb_Subtract3_p;
  real32_T rtb_Add3_l_idx_0;
  real32_T rtb_Subtract3_l_idx_0;
  real32_T rtb_Add3_l_idx_1;
  real32_T rtb_Subtract3_l_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_l_idx_0_0;

  /* SignalConversion: '<S473>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S479>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S480>/Multiply1' incorporates:
   *  Constant: '<S480>/const1'
   *  DiscreteIntegrator: '<S479>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S473>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S479>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S480>/Multiply1' incorporates:
   *  Constant: '<S480>/const1'
   *  DiscreteIntegrator: '<S479>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S477>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S477>/Dead Zone' */

  /* Sum: '<S480>/Add' incorporates:
   *  DiscreteIntegrator: '<S479>/Integrator1'
   *  Gain: '<S473>/Gain6'
   *  Gain: '<S477>/Gain'
   *  Sum: '<S479>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S478>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S478>/Dead Zone' */

  /* Sum: '<S480>/Add' incorporates:
   *  DiscreteIntegrator: '<S479>/Integrator1'
   *  Gain: '<S473>/Gain6'
   *  Gain: '<S478>/Gain'
   *  Sum: '<S479>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S480>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S480>/Add2' incorporates:
   *  Abs: '<S480>/Abs'
   *  Gain: '<S480>/Gain'
   *  Gain: '<S480>/Gain1'
   *  Product: '<S480>/Multiply2'
   *  Product: '<S480>/Multiply3'
   *  Signum: '<S480>/Sign'
   *  Sqrt: '<S480>/Sqrt'
   *  Sum: '<S480>/Add1'
   *  Sum: '<S480>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S480>/Add3' incorporates:
   *  Signum: '<S480>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S480>/Subtract1' incorporates:
   *  Signum: '<S480>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S480>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S480>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S480>/Add5' incorporates:
   *  Gain: '<S480>/Gain2'
   *  Product: '<S480>/Multiply4'
   *  Signum: '<S480>/Sign'
   *  Sum: '<S480>/Add2'
   *  Sum: '<S480>/Add4'
   *  Sum: '<S480>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S479>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S479>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S480>/Sign3' incorporates:
   *  Sum: '<S480>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S480>/Sign4' incorporates:
   *  Sum: '<S480>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S480>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S480>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S480>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S480>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S479>/Integrator' incorporates:
   *  Constant: '<S480>/const'
   *  Gain: '<S480>/Gain3'
   *  Product: '<S480>/Divide'
   *  Product: '<S480>/Multiply5'
   *  Product: '<S480>/Multiply6'
   *  Sum: '<S480>/Subtract4'
   *  Sum: '<S480>/Subtract5'
   *  Sum: '<S480>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S480>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S480>/Add2' incorporates:
   *  Abs: '<S480>/Abs'
   *  Gain: '<S480>/Gain'
   *  Gain: '<S480>/Gain1'
   *  Product: '<S480>/Multiply2'
   *  Product: '<S480>/Multiply3'
   *  Signum: '<S480>/Sign'
   *  Sqrt: '<S480>/Sqrt'
   *  Sum: '<S480>/Add1'
   *  Sum: '<S480>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S480>/Add3' incorporates:
   *  Signum: '<S480>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S480>/Subtract1' incorporates:
   *  Signum: '<S480>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S480>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S480>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S480>/Add5' incorporates:
   *  Gain: '<S480>/Gain2'
   *  Product: '<S480>/Multiply4'
   *  Signum: '<S480>/Sign'
   *  Sum: '<S480>/Add2'
   *  Sum: '<S480>/Add4'
   *  Sum: '<S480>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S479>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S479>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S480>/Sign3' incorporates:
   *  Sum: '<S480>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S480>/Sign4' incorporates:
   *  Sum: '<S480>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S480>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S480>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S480>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S480>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S479>/Integrator' incorporates:
   *  Constant: '<S480>/const'
   *  Gain: '<S480>/Gain3'
   *  Product: '<S480>/Divide'
   *  Product: '<S480>/Multiply5'
   *  Product: '<S480>/Multiply6'
   *  Sum: '<S480>/Subtract4'
   *  Sum: '<S480>/Subtract5'
   *  Sum: '<S480>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S470>/Motion State'
 *    '<S363>/Motion State'
 *    '<S197>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S470>/Motion State'
 *    '<S363>/Motion State'
 *    '<S197>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S470>/Motion State'
 *    '<S363>/Motion State'
 *    '<S197>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S470>/Motion State' */
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

  /* End of Chart: '<S470>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S446>/NearbyRefWP'
 *    '<S173>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S484>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S350>/Hold Control'
 *    '<S132>/Hold Control'
 *    '<S67>/Hold Control'
 *    '<S95>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S353>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S350>/Hold Control'
 *    '<S132>/Hold Control'
 *    '<S67>/Hold Control'
 *    '<S95>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S353>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S350>/Hold Control'
 *    '<S132>/Hold Control'
 *    '<S67>/Hold Control'
 *    '<S95>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S353>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S353>/Sum' incorporates:
   *  Delay: '<S353>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S356>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S356>/Switch' incorporates:
   *  Constant: '<S356>/Constant'
   *  Constant: '<S357>/Constant'
   *  Product: '<S356>/Multiply'
   *  RelationalOperator: '<S357>/Compare'
   *  Sum: '<S356>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S356>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S356>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S356>/Switch' */

  /* Gain: '<S353>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S353>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S350>/Move Control'
 *    '<S132>/Move Control'
 *    '<S67>/Move Control'
 *    '<S95>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S359>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S359>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S350>/Move Control'
 *    '<S132>/Move Control'
 *    '<S67>/Move Control'
 *    '<S95>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S359>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S359>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S350>/Move Control'
 *    '<S132>/Move Control'
 *    '<S67>/Move Control'
 *    '<S95>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_ig;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_b;
  real32_T rtb_a_p4;

  /* Product: '<S360>/Multiply1' incorporates:
   *  Constant: '<S360>/const1'
   *  DiscreteIntegrator: '<S359>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S358>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S358>/Dead Zone' */

  /* Sum: '<S360>/Add' incorporates:
   *  DiscreteIntegrator: '<S359>/Integrator1'
   *  Gain: '<S354>/Gain1'
   *  Gain: '<S358>/Gain'
   *  Sum: '<S359>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S360>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S360>/Sign' */

  /* Sum: '<S360>/Add2' incorporates:
   *  Abs: '<S360>/Abs'
   *  Gain: '<S360>/Gain'
   *  Gain: '<S360>/Gain1'
   *  Product: '<S360>/Multiply2'
   *  Product: '<S360>/Multiply3'
   *  Sqrt: '<S360>/Sqrt'
   *  Sum: '<S360>/Add1'
   *  Sum: '<S360>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S360>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S360>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S360>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S360>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S360>/Sign1' */

  /* Signum: '<S360>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S360>/Sign2' */

  /* Sum: '<S360>/Add5' incorporates:
   *  Gain: '<S360>/Gain2'
   *  Product: '<S360>/Multiply4'
   *  Sum: '<S360>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S354>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S359>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S359>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S359>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S360>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S360>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S360>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S360>/Sign5' */

  /* Signum: '<S360>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S360>/Sign3' */

  /* Signum: '<S360>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S360>/Sign4' */

  /* Signum: '<S360>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S360>/Sign6' */

  /* Update for DiscreteIntegrator: '<S359>/Integrator' incorporates:
   *  Constant: '<S360>/const'
   *  Gain: '<S360>/Gain3'
   *  Product: '<S360>/Divide'
   *  Product: '<S360>/Multiply5'
   *  Product: '<S360>/Multiply6'
   *  Sum: '<S360>/Subtract4'
   *  Sum: '<S360>/Subtract5'
   *  Sum: '<S360>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_b) *
    localC->Gain4 * ((rtb_Add3_ig - rtb_Subtract3_l) * 0.5F) - rtb_a_p4 *
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

  /* BusAssignment: '<S336>/Bus Assignment' incorporates:
   *  Constant: '<S336>/Constant'
   *  Constant: '<S336>/Constant2'
   *  SignalConversion: '<S336>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S336>/Bus Assignment' */
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
    localDW->is_c19_FMS = FMS_IN_Move_o4;
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
          localDW->is_c19_FMS = FMS_IN_Move_o4;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_j:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Move_o4;
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

  /* Gain: '<S515>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S516>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S516>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S516>/Multiply1' incorporates:
   *  Product: '<S516>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S516>/Divide' incorporates:
   *  Constant: '<S516>/Constant'
   *  Constant: '<S516>/R'
   *  Sqrt: '<S516>/Sqrt'
   *  Sum: '<S516>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S516>/Product3' incorporates:
   *  Constant: '<S516>/Constant1'
   *  Product: '<S516>/Multiply1'
   *  Sum: '<S516>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S516>/Multiply2' incorporates:
   *  Trigonometry: '<S516>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S515>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S520>/Abs' incorporates:
   *  Abs: '<S523>/Abs1'
   *  Switch: '<S520>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S520>/Switch1' incorporates:
   *  Abs: '<S520>/Abs'
   *  Bias: '<S520>/Bias2'
   *  Bias: '<S520>/Bias3'
   *  Constant: '<S517>/Constant'
   *  Constant: '<S517>/Constant1'
   *  Constant: '<S522>/Constant'
   *  Gain: '<S520>/Gain1'
   *  Product: '<S520>/Multiply'
   *  RelationalOperator: '<S522>/Compare'
   *  Switch: '<S517>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S523>/Switch1' incorporates:
     *  Bias: '<S523>/Bias2'
     *  Bias: '<S523>/Bias3'
     *  Constant: '<S523>/Constant'
     *  Constant: '<S524>/Constant'
     *  Math: '<S523>/Math Function'
     *  RelationalOperator: '<S524>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S523>/Switch1' */

    /* Signum: '<S520>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S520>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S517>/Sum' incorporates:
   *  Sum: '<S515>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S515>/Multiply' incorporates:
   *  Gain: '<S515>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S519>/Switch1' incorporates:
   *  Abs: '<S519>/Abs1'
   *  Bias: '<S519>/Bias2'
   *  Bias: '<S519>/Bias3'
   *  Constant: '<S519>/Constant'
   *  Constant: '<S521>/Constant'
   *  Math: '<S519>/Math Function'
   *  RelationalOperator: '<S521>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S519>/Switch1' */

  /* Product: '<S515>/Multiply' incorporates:
   *  Gain: '<S515>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S515>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S518>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S518>/Sum2' incorporates:
   *  Product: '<S518>/Multiply1'
   *  Product: '<S518>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S518>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S518>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S518>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S512>/Data Type Conversion' incorporates:
   *  Gain: '<S515>/Gain'
   *  Sum: '<S515>/Sum1'
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

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

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
      if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
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
        FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
        FMS_DW.is_Mission = FMS_IN_Return_h;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
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
        FMS_DW.is_Mission = FMS_IN_Land_j;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
        FMS_B.state = VehicleState_Land;
        FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
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
  /* RelationalOperator: '<S525>/Compare' incorporates:
   *  Abs: '<S514>/Abs'
   *  Constant: '<S525>/Constant'
   *  MinMax: '<S514>/Max'
   *  Sum: '<S514>/Sum'
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
                                 212U) == 212)) {
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
      /* Reshape: '<S513>/Reshape' incorporates:
       *  Constant: '<S513>/Constant'
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
  boolean_T rtb_Compare_on;
  MotionState rtb_state_c;
  real32_T rtb_Rem_p;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  real32_T rtb_VectorConcatenate_e[9];
  real32_T rtb_Sqrt_b;
  boolean_T rtb_LogicalOperator_es;
  real32_T rtb_Gain_fj;
  real32_T rtb_TmpSignalConversionAtMath_c[3];
  real32_T rtb_Sum_ff[2];
  real32_T rtb_Transpose_0[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  int32_T rtb_Compare_bv_0;
  real32_T rtb_MathFunction_iq_idx_1;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_MathFunction_f_idx_2;
  real32_T rtb_MathFunction_f_idx_0;
  real32_T rtb_P_l_idx_0;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* Sqrt: '<S535>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S535>/Square'
   *  Sum: '<S535>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S531>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3_c = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_Add4_e5 = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S532>/Square' incorporates:
   *  Math: '<S533>/Square'
   *  Math: '<S534>/Square'
   */
  rtb_MathFunction_f_idx_0 = rtb_Add3_c * rtb_Add3_c;

  /* Math: '<S532>/Square2' incorporates:
   *  Math: '<S533>/Square2'
   *  Math: '<S534>/Square2'
   */
  rtb_Gain_fj = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S532>/Square1' incorporates:
   *  Math: '<S533>/Square1'
   *  Math: '<S534>/Square1'
   */
  rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S532>/Square3' incorporates:
   *  Math: '<S533>/Square3'
   *  Math: '<S534>/Square3'
   */
  rtb_Sqrt_b = rtb_Add4_e5 * rtb_Add4_e5;

  /* Sum: '<S532>/Subtract' incorporates:
   *  Math: '<S532>/Square'
   *  Math: '<S532>/Square1'
   *  Math: '<S532>/Square2'
   *  Math: '<S532>/Square3'
   *  Sum: '<S532>/Add'
   *  Sum: '<S532>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_f_idx_0 + rtb_DiscreteTimeIntegrator_n) -
    (rtb_Gain_fj + rtb_Sqrt_b);

  /* Product: '<S532>/Multiply' incorporates:
   *  Product: '<S533>/Multiply'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S532>/Multiply1' incorporates:
   *  Product: '<S533>/Multiply1'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Add4_e5;

  /* Gain: '<S532>/Gain' incorporates:
   *  Product: '<S532>/Multiply'
   *  Product: '<S532>/Multiply1'
   *  Sum: '<S532>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Product: '<S532>/Multiply2' incorporates:
   *  Product: '<S534>/Multiply'
   */
  rtb_Rem_p = rtb_Divide_l_idx_1 * rtb_Add4_e5;

  /* Product: '<S532>/Multiply3' incorporates:
   *  Product: '<S534>/Multiply1'
   */
  rtb_TmpSignalConversionAtMath_0 = rtb_Add3_c * rtb_Divide_l_idx_2;

  /* Gain: '<S532>/Gain1' incorporates:
   *  Product: '<S532>/Multiply2'
   *  Product: '<S532>/Multiply3'
   *  Sum: '<S532>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_p + rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S533>/Gain' incorporates:
   *  Sum: '<S533>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S533>/Subtract' incorporates:
   *  Sum: '<S533>/Add'
   *  Sum: '<S533>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_f_idx_0 + rtb_Gain_fj) -
    (rtb_DiscreteTimeIntegrator_n + rtb_Sqrt_b);

  /* Product: '<S533>/Multiply2' incorporates:
   *  Product: '<S534>/Multiply2'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_l_idx_2 * rtb_Add4_e5;

  /* Product: '<S533>/Multiply3' incorporates:
   *  Product: '<S534>/Multiply3'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Divide_l_idx_1;

  /* Gain: '<S533>/Gain1' incorporates:
   *  Product: '<S533>/Multiply2'
   *  Product: '<S533>/Multiply3'
   *  Sum: '<S533>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Gain: '<S534>/Gain' incorporates:
   *  Sum: '<S534>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_p - rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S534>/Gain1' incorporates:
   *  Sum: '<S534>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S534>/Subtract' incorporates:
   *  Sum: '<S534>/Add'
   *  Sum: '<S534>/Add1'
   */
  rtb_Transpose[8] = (rtb_MathFunction_f_idx_0 + rtb_Sqrt_b) -
    (rtb_DiscreteTimeIntegrator_n + rtb_Gain_fj);

  /* Math: '<S6>/Transpose' */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_VectorConcatenate_e[3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0];
    rtb_VectorConcatenate_e[1 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 3];
    rtb_VectorConcatenate_e[2 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 6];
  }

  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 9; rtb_Compare_bv_0++) {
    rtb_Transpose[rtb_Compare_bv_0] = rtb_VectorConcatenate_e[rtb_Compare_bv_0];
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

  /* DiscreteIntegrator: '<S526>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S528>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S528>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Product: '<S6>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S6>/Cos'
   *  Trigonometry: '<S6>/Cos1'
   */
  rtb_Gain_fj = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Gain_fj > 1.0F) {
    rtb_Gain_fj = 1.0F;
  } else {
    if (rtb_Gain_fj < 0.9F) {
      rtb_Gain_fj = 0.9F;
    }
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Product: '<S6>/Divide1' incorporates:
   *  Constant: '<S6>/Land_Lock_Thro'
   */
  rtb_Divide_l_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Gain_fj;

  /* DiscreteIntegrator: '<S527>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S526>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S527>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S528>/Discrete-Time Integrator5'
   *  Logic: '<S529>/AND'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S529>/Lower Test'
   *  RelationalOperator: '<S529>/Upper Test'
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
      FMS_Manual();
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
        /* Disable for SwitchCase: '<S469>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S459>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S362>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S340>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S350>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S35>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S145>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S196>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S186>/Switch Case' */
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
          /* Disable for SwitchCase: '<S469>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S459>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S362>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S340>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S350>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S35>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S145>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S196>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S186>/Switch Case' */
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
       *  Math: '<S491>/Math Function'
       *  Product: '<S493>/Divide'
       *  Sum: '<S447>/Subtract'
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
          /* Disable for SwitchCase: '<S469>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S459>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S362>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S340>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S350>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Takeoff' incorporates:
           *  ActionPort: '<S335>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S509>/cur_waypoint'
           *  DiscreteIntegrator: '<S505>/Integrator'
           *  DiscreteIntegrator: '<S505>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Takeoff' incorporates:
         *  ActionPort: '<S335>/Action Port'
         */
        /* Delay: '<S509>/cur_waypoint' incorporates:
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
        /* Product: '<S509>/Divide' incorporates:
         *  Delay: '<S509>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S509>/Sum1'
         *  Sum: '<S509>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Saturate: '<S509>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S509>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S510>/Trigonometric Function1' incorporates:
         *  Gain: '<S508>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S510>/Trigonometric Function3'
         */
        rtb_MathFunction_f_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S510>/Trigonometric Function' incorporates:
         *  Gain: '<S508>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S510>/Trigonometric Function2'
         */
        rtb_Gain_fj = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[1] = rtb_Gain_fj;

        /* SignalConversion: '<S510>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S510>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S510>/Gain' */
        rtb_Transpose[3] = -rtb_Gain_fj;

        /* Trigonometry: '<S510>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

        /* SignalConversion: '<S510>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S510>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S510>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S502>/Saturation1' */
        rtb_Add4_e5 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_f_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S502>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S509>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S509>/Multiply'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S502>/Sum'
         *  Sum: '<S509>/Sum3'
         *  Sum: '<S509>/Sum4'
         */
        rtb_Divide_l_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
                              FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_DiscreteTimeIntegrator_n = ((FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
          FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S502>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_l_idx_1;
        }

        /* Saturate: '<S502>/Saturation1' incorporates:
         *  Gain: '<S502>/Gain2'
         *  Product: '<S502>/Multiply'
         */
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S335>/Bus Assignment1'
         *  Constant: '<S335>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S335>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S502>/Saturation1' */
        if (rtb_Gain_fj > rtb_Add4_e5) {
          /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_e5;
        } else if (rtb_Gain_fj < rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        } else {
          /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        }

        if (rtb_Add3_c > rtb_Add4_e5) {
          /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_e5;
        } else if (rtb_Add3_c < rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_0;
        } else {
          /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S335>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S505>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S506>/Multiply1' incorporates:
         *  Constant: '<S506>/const1'
         *  DiscreteIntegrator: '<S505>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S501>/Switch' incorporates:
         *  Abs: '<S501>/Abs'
         *  Abs: '<S501>/Abs1'
         *  Constant: '<S501>/Takeoff_Speed'
         *  Constant: '<S503>/Constant'
         *  Constant: '<S504>/Constant'
         *  Gain: '<S501>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S501>/Logical Operator'
         *  RelationalOperator: '<S503>/Compare'
         *  RelationalOperator: '<S504>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S501>/Sum'
         *  Sum: '<S501>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Add4_e5 = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Add4_e5 = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S501>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S506>/Add' incorporates:
         *  DiscreteIntegrator: '<S505>/Integrator1'
         *  Sum: '<S505>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_a - rtb_Add4_e5) +
          rtb_Add3_c;

        /* Signum: '<S506>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S506>/Sign' */

        /* Sum: '<S506>/Add2' incorporates:
         *  Abs: '<S506>/Abs'
         *  Gain: '<S506>/Gain'
         *  Gain: '<S506>/Gain1'
         *  Product: '<S506>/Multiply2'
         *  Product: '<S506>/Multiply3'
         *  Sqrt: '<S506>/Sqrt'
         *  Sum: '<S506>/Add1'
         *  Sum: '<S506>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1)
          + FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_Add3_c;

        /* Sum: '<S506>/Add4' */
        rtb_Add4_e5 = (rtb_Divide_l_idx_1 - rtb_DiscreteTimeIntegrator_n) +
          rtb_Add3_c;

        /* Sum: '<S506>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d_m;

        /* Sum: '<S506>/Subtract1' */
        rtb_Divide_l_idx_1 -= FMS_ConstB.d_m;

        /* Signum: '<S506>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S506>/Sign1' */

        /* Signum: '<S506>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S506>/Sign2' */

        /* Sum: '<S506>/Add5' incorporates:
         *  Gain: '<S506>/Gain2'
         *  Product: '<S506>/Multiply4'
         *  Sum: '<S506>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_Add3_c - rtb_Divide_l_idx_1) * 0.5F
          * rtb_Add4_e5;

        /* Update for Delay: '<S509>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S505>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S505>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S506>/Add6' */
        rtb_Add3_c = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_m;

        /* Sum: '<S506>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_m;

        /* Signum: '<S506>/Sign5' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S506>/Sign5' */

        /* Signum: '<S506>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S506>/Sign3' */

        /* Signum: '<S506>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S506>/Sign4' */

        /* Signum: '<S506>/Sign6' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S506>/Sign6' */

        /* Update for DiscreteIntegrator: '<S505>/Integrator' incorporates:
         *  Constant: '<S506>/const'
         *  Gain: '<S506>/Gain3'
         *  Product: '<S506>/Divide'
         *  Product: '<S506>/Multiply5'
         *  Product: '<S506>/Multiply6'
         *  Sum: '<S506>/Subtract4'
         *  Sum: '<S506>/Subtract5'
         *  Sum: '<S506>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_m - rtb_Add4_e5) * FMS_ConstB.Gain4_a * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_MathFunction_f_idx_0 * 9.806F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S37>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Land' incorporates:
           *  ActionPort: '<S333>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S378>/Integrator'
           *  DiscreteIntegrator: '<S378>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Land' incorporates:
         *  ActionPort: '<S333>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S383>/Trigonometric Function1' incorporates:
         *  Gain: '<S382>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S383>/Trigonometric Function' incorporates:
         *  Gain: '<S382>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S383>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S383>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S383>/Gain' incorporates:
         *  Gain: '<S382>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S383>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S383>/Trigonometric Function3' incorporates:
         *  Gain: '<S382>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S383>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S383>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S383>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S376>/Saturation1' */
        rtb_MathFunction_f_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Add4_e5 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S380>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S380>/Sum'
         */
        rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S380>/Multiply' incorporates:
         *  SignalConversion: '<S380>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_l_idx_1;
        }

        /* End of Product: '<S380>/Multiply' */

        /* Saturate: '<S376>/Saturation1' incorporates:
         *  Gain: '<S380>/Gain2'
         */
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S333>/Bus Assignment1'
         *  Constant: '<S333>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S333>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S376>/Saturation1' */
        if (rtb_Gain_fj > rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        } else if (rtb_Gain_fj < rtb_Add4_e5) {
          /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_e5;
        } else {
          /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        }

        if (rtb_Add3_c > rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_0;
        } else if (rtb_Add3_c < rtb_Add4_e5) {
          /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_e5;
        } else {
          /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S333>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S378>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S379>/Multiply1' incorporates:
         *  Constant: '<S379>/const1'
         *  DiscreteIntegrator: '<S378>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S375>/Switch' incorporates:
         *  Constant: '<S375>/Land_Speed'
         *  Constant: '<S377>/Constant'
         *  Gain: '<S375>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S375>/Logical Operator'
         *  RelationalOperator: '<S377>/Compare'
         *  S-Function (sfix_bitop): '<S375>/cmd_p valid'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Add4_e5 = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Add4_e5 = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S375>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S379>/Add' incorporates:
         *  DiscreteIntegrator: '<S378>/Integrator1'
         *  Sum: '<S378>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_j - rtb_Add4_e5) +
          rtb_Add3_c;

        /* Signum: '<S379>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S379>/Sign' */

        /* Sum: '<S379>/Add2' incorporates:
         *  Abs: '<S379>/Abs'
         *  Gain: '<S379>/Gain'
         *  Gain: '<S379>/Gain1'
         *  Product: '<S379>/Multiply2'
         *  Product: '<S379>/Multiply3'
         *  Sqrt: '<S379>/Sqrt'
         *  Sum: '<S379>/Add1'
         *  Sum: '<S379>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1)
          + FMS_ConstB.d_p) * FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_Add3_c;

        /* Sum: '<S379>/Add4' */
        rtb_Add4_e5 = (rtb_Divide_l_idx_1 - rtb_DiscreteTimeIntegrator_n) +
          rtb_Add3_c;

        /* Sum: '<S379>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d_p;

        /* Sum: '<S379>/Subtract1' */
        rtb_Divide_l_idx_1 -= FMS_ConstB.d_p;

        /* Signum: '<S379>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S379>/Sign1' */

        /* Signum: '<S379>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S379>/Sign2' */

        /* Sum: '<S379>/Add5' incorporates:
         *  Gain: '<S379>/Gain2'
         *  Product: '<S379>/Multiply4'
         *  Sum: '<S379>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_Add3_c - rtb_Divide_l_idx_1) * 0.5F
          * rtb_Add4_e5;

        /* Update for DiscreteIntegrator: '<S378>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S378>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S379>/Add6' */
        rtb_Add3_c = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_p;

        /* Sum: '<S379>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_p;

        /* Signum: '<S379>/Sign5' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S379>/Sign5' */

        /* Signum: '<S379>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S379>/Sign3' */

        /* Signum: '<S379>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S379>/Sign4' */

        /* Signum: '<S379>/Sign6' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S379>/Sign6' */

        /* Update for DiscreteIntegrator: '<S378>/Integrator' incorporates:
         *  Constant: '<S379>/const'
         *  Gain: '<S379>/Gain3'
         *  Product: '<S379>/Divide'
         *  Product: '<S379>/Multiply5'
         *  Product: '<S379>/Multiply6'
         *  Sum: '<S379>/Subtract4'
         *  Sum: '<S379>/Subtract5'
         *  Sum: '<S379>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_p - rtb_Add4_e5) * FMS_ConstB.Gain4_e * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_MathFunction_f_idx_0 * 9.806F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S37>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S334>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S387>/Delay'
           *  Delay: '<S388>/Delay'
           *  Delay: '<S448>/Delay'
           *  DiscreteIntegrator: '<S391>/Integrator'
           *  DiscreteIntegrator: '<S391>/Integrator1'
           *  DiscreteIntegrator: '<S444>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S449>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S496>/Discrete-Time Integrator'
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

          /* End of InitializeConditions for SubSystem: '<S37>/Return' */

          /* SystemReset for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S334>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S460>/Motion Status'
           *  Chart: '<S470>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S37>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Return' incorporates:
         *  ActionPort: '<S334>/Action Port'
         */
        /* Delay: '<S448>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_l != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S444>/Switch2' incorporates:
         *  Constant: '<S444>/vel'
         *  Constant: '<S453>/Constant'
         *  RelationalOperator: '<S453>/Compare'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S444>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* RelationalOperator: '<S443>/Compare' incorporates:
         *  Constant: '<S500>/Constant'
         *  DiscreteIntegrator: '<S449>/Discrete-Time Integrator'
         *  RelationalOperator: '<S500>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* DiscreteIntegrator: '<S444>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S470>/Motion State' incorporates:
         *  Constant: '<S470>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S470>/Square'
         *  Math: '<S470>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S470>/Sqrt'
         *  Sum: '<S470>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S469>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S469>/Hold Control' incorporates:
             *  ActionPort: '<S472>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S469>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S469>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S469>/Hold Control' incorporates:
           *  ActionPort: '<S472>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S469>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S469>/Brake Control' incorporates:
           *  ActionPort: '<S471>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S469>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S469>/Move Control' incorporates:
             *  ActionPort: '<S473>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S469>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S469>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S469>/Move Control' incorporates:
           *  ActionPort: '<S473>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S469>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S469>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S460>/Motion Status' incorporates:
         *  Abs: '<S460>/Abs'
         *  Constant: '<S460>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S459>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ld;
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_ld = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_ld = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_ld = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_ld) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S459>/Hold Control' incorporates:
             *  ActionPort: '<S462>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S459>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S459>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S459>/Hold Control' incorporates:
           *  ActionPort: '<S462>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S459>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S459>/Brake Control' incorporates:
           *  ActionPort: '<S461>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S459>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S459>/Move Control' incorporates:
             *  ActionPort: '<S463>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S459>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S459>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S459>/Move Control' incorporates:
           *  ActionPort: '<S463>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S459>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S459>/Switch Case' */

        /* Switch: '<S386>/Switch' incorporates:
         *  Product: '<S448>/Multiply'
         *  Sum: '<S448>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S469>/Saturation1' */
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

          /* End of Saturate: '<S469>/Saturation1' */

          /* Saturate: '<S459>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S459>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S448>/Sum' incorporates:
           *  Delay: '<S448>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S497>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S444>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Add3_c = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S448>/Sum' incorporates:
           *  Delay: '<S448>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S444>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S456>/Sqrt' incorporates:
           *  Math: '<S456>/Square'
           *  Sum: '<S444>/Sum'
           *  Sum: '<S456>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
                             rtb_TmpSignalConversionAtMath_0 *
                             rtb_TmpSignalConversionAtMath_0);

          /* SignalConversion: '<S499>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* SignalConversion: '<S499>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S499>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S498>/Gain' incorporates:
           *  DiscreteIntegrator: '<S496>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S496>/Add'
           */
          rtb_Add4_e5 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S499>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S499>/Trigonometric Function1'
           */
          rtb_MathFunction_f_idx_0 = arm_cos_f32(rtb_Add4_e5);
          rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S499>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S499>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_Add4_e5);

          /* Gain: '<S499>/Gain' incorporates:
           *  Trigonometry: '<S499>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S499>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S499>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S499>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S499>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

          /* Switch: '<S455>/Switch2' incorporates:
           *  Constant: '<S444>/Constant2'
           *  DiscreteIntegrator: '<S444>/Acceleration_Speed'
           *  RelationalOperator: '<S455>/LowerRelop1'
           *  RelationalOperator: '<S455>/UpperRelop'
           *  Switch: '<S455>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_DiscreteTimeIntegrator_n)
          {
            rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
          } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
            /* Switch: '<S455>/Switch' incorporates:
             *  Constant: '<S444>/Constant2'
             */
            rtb_Add4_e5 = 0.0F;
          } else {
            rtb_Add4_e5 = FMS_DW.Acceleration_Speed_DSTATE_j;
          }

          /* End of Switch: '<S455>/Switch2' */

          /* Switch: '<S444>/Switch' */
          if (rtb_Sqrt_b > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
          } else {
            /* Gain: '<S444>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Sqrt_b;

            /* Switch: '<S454>/Switch2' incorporates:
             *  Constant: '<S444>/Constant1'
             *  RelationalOperator: '<S454>/LowerRelop1'
             *  RelationalOperator: '<S454>/UpperRelop'
             *  Switch: '<S454>/Switch'
             */
            if (rtb_Gain_fj > rtb_DiscreteTimeIntegrator_n) {
              rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S454>/Switch' incorporates:
                 *  Constant: '<S444>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S454>/Switch2' */
          }

          /* End of Switch: '<S444>/Switch' */

          /* Switch: '<S444>/Switch1' incorporates:
           *  Sum: '<S444>/Sum1'
           */
          if (rtb_Add4_e5 - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Add4_e5;
          }

          /* End of Switch: '<S444>/Switch1' */

          /* Sum: '<S497>/Sum of Elements' incorporates:
           *  Math: '<S497>/Math Function'
           */
          rtb_Add4_e5 = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_1;

          /* Math: '<S497>/Math Function1' incorporates:
           *  Sum: '<S497>/Sum of Elements'
           *
           * About '<S497>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Add4_e5 < 0.0F) {
            rtb_Add4_e5 = -sqrtf(fabsf(rtb_Add4_e5));
          } else {
            rtb_Add4_e5 = sqrtf(rtb_Add4_e5);
          }

          /* End of Math: '<S497>/Math Function1' */

          /* Switch: '<S497>/Switch' incorporates:
           *  Constant: '<S497>/Constant'
           *  Product: '<S497>/Product'
           */
          if (rtb_Add4_e5 <= 0.0F) {
            rtb_Add3_c = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Add4_e5 = 1.0F;
          }

          /* End of Switch: '<S497>/Switch' */

          /* Product: '<S495>/Multiply2' incorporates:
           *  Product: '<S497>/Divide'
           */
          rtb_MathFunction_f_idx_0 = rtb_Add3_c / rtb_Add4_e5 * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_l_idx_1 / rtb_Add4_e5;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S450>/Sum1' incorporates:
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S450>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_e5 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sqrt_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S450>/Divide' incorporates:
           *  Math: '<S451>/Square'
           *  Math: '<S452>/Square'
           *  Sqrt: '<S451>/Sqrt'
           *  Sqrt: '<S452>/Sqrt'
           *  Sum: '<S450>/Sum'
           *  Sum: '<S450>/Sum1'
           *  Sum: '<S451>/Sum of Elements'
           *  Sum: '<S452>/Sum of Elements'
           */
          rtb_Add4_e5 = sqrtf(rtb_Add4_e5 * rtb_Add4_e5 + rtb_Sqrt_b *
                              rtb_Sqrt_b) / sqrtf(rtb_Add3_c * rtb_Add3_c +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1);

          /* Saturate: '<S450>/Saturation' */
          if (rtb_Add4_e5 > 1.0F) {
            rtb_Add4_e5 = 1.0F;
          } else {
            if (rtb_Add4_e5 < 0.0F) {
              rtb_Add4_e5 = 0.0F;
            }
          }

          /* End of Saturate: '<S450>/Saturation' */

          /* Product: '<S448>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_MathFunction_f_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S441>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S450>/Multiply'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S441>/Sum2'
           *  Sum: '<S450>/Add'
           *  Sum: '<S450>/Subtract'
           */
          rtb_Gain_fj = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Add4_e5 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S441>/Saturation1' incorporates:
           *  Product: '<S448>/Multiply'
           */
          if (rtb_Gain_fj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Gain_fj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Gain_fj;
          }

          /* End of Saturate: '<S441>/Saturation1' */
        }

        /* End of Switch: '<S386>/Switch' */

        /* Delay: '<S388>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S391>/Integrator1' incorporates:
         *  Delay: '<S388>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S395>/Rem' incorporates:
         *  Constant: '<S395>/Constant1'
         *  DiscreteIntegrator: '<S391>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S390>/Sum'
         */
        rtb_Add3_c = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S395>/Switch' incorporates:
         *  Abs: '<S395>/Abs'
         *  Constant: '<S395>/Constant'
         *  Constant: '<S396>/Constant'
         *  Product: '<S395>/Multiply'
         *  RelationalOperator: '<S396>/Compare'
         *  Sum: '<S395>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S395>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S395>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S395>/Switch' */

        /* Gain: '<S390>/Gain2' */
        rtb_Add3_c *= FMS_PARAM.YAW_P;

        /* Saturate: '<S390>/Saturation' */
        if (rtb_Add3_c > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Add3_c = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Add3_c < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add3_c = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S390>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S334>/Bus Assignment1'
         *  Constant: '<S334>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S334>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add3_c;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S490>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S490>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S488>/Sum of Elements'
         */
        rtb_Add4_e5 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S490>/Math Function1' incorporates:
         *  Sum: '<S490>/Sum of Elements'
         *
         * About '<S490>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add4_e5));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add4_e5);
        }

        /* End of Math: '<S490>/Math Function1' */

        /* Switch: '<S490>/Switch' incorporates:
         *  Constant: '<S490>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S490>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Add3_c > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Add3_c;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S490>/Switch' */

        /* Delay: '<S387>/Delay' incorporates:
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
        /* Sum: '<S334>/Sum' incorporates:
         *  Delay: '<S387>/Delay'
         *  MATLAB Function: '<S446>/OutRegionRegWP'
         *  MATLAB Function: '<S446>/SearchL1RefWP'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S402>/Sum of Elements' incorporates:
         *  Math: '<S402>/Math Function'
         *  Sum: '<S334>/Sum'
         */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_P_l_idx_0 * rtb_P_l_idx_0;

        /* Math: '<S402>/Math Function1' incorporates:
         *  Sum: '<S402>/Sum of Elements'
         *
         * About '<S402>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S402>/Math Function1' */

        /* Switch: '<S402>/Switch' incorporates:
         *  Constant: '<S402>/Constant'
         *  Product: '<S402>/Product'
         *  Sum: '<S334>/Sum'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_MathFunction_f_idx_0 = rtb_TmpSignalConversionAtMath_0;
          rtb_Gain_fj = rtb_P_l_idx_0;
          rtb_MathFunction_f_idx_2 = rtb_Add3_c;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_Gain_fj = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S402>/Switch' */

        /* Product: '<S490>/Divide' */
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S493>/Sum of Elements' incorporates:
         *  Math: '<S493>/Math Function'
         *  SignalConversion: '<S493>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S493>/Math Function1' incorporates:
         *  Sum: '<S493>/Sum of Elements'
         *
         * About '<S493>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S493>/Math Function1' */

        /* Switch: '<S493>/Switch' incorporates:
         *  Constant: '<S493>/Constant'
         *  Product: '<S493>/Product'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Sum_ff[1];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Sum_ff[0];
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Add3_c;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S493>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S446>/NearbyRefWP' incorporates:
         *  Constant: '<S334>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S446>/SearchL1RefWP' incorporates:
         *  Constant: '<S334>/L1'
         *  Delay: '<S387>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Divide_l_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_P_l_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
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
        rtb_Sqrt_b = 0.0F;
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
          rtb_Sqrt_b = rtb_P_l_idx_0 * rtb_Add3_c + FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_iq_idx_1 = rtb_TmpSignalConversionAtMath_0 *
            rtb_Add3_c + FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S446>/OutRegionRegWP' incorporates:
         *  Delay: '<S387>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_l_idx_1 = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                              rtb_TmpSignalConversionAtMath_0 +
                              (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0]) *
                              rtb_P_l_idx_0) / (rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_l_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Divide_l_idx_1 * rtb_P_l_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S446>/Switch1' incorporates:
         *  Constant: '<S483>/Constant'
         *  RelationalOperator: '<S483>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S446>/Switch' incorporates:
           *  Constant: '<S482>/Constant'
           *  MATLAB Function: '<S446>/SearchL1RefWP'
           *  RelationalOperator: '<S482>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Sqrt_b;
            rtb_Sum_ff[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S446>/OutRegionRegWP' incorporates:
             *  Delay: '<S387>/Delay'
             *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Divide_l_idx_1 *
                rtb_TmpSignalConversionAtMath_0 + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S446>/Switch' */
        }

        /* End of Switch: '<S446>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S447>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Rem_p;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Rem_p * rtb_Rem_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S447>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S491>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S491>/Math Function' incorporates:
         *  Math: '<S489>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_p * rtb_Rem_p;

        /* Sum: '<S491>/Sum of Elements' incorporates:
         *  Math: '<S491>/Math Function'
         */
        rtb_Add3_c = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S491>/Math Function1' incorporates:
         *  Sum: '<S491>/Sum of Elements'
         *
         * About '<S491>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S491>/Math Function1' */

        /* Switch: '<S491>/Switch' incorporates:
         *  Constant: '<S491>/Constant'
         *  Product: '<S491>/Product'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Rem_p;
          rtb_MatrixConcatenate3[2] = rtb_Add3_c;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S491>/Switch' */

        /* Product: '<S491>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S494>/Sum of Elements' incorporates:
         *  Math: '<S494>/Math Function'
         *  SignalConversion: '<S494>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S494>/Math Function1' incorporates:
         *  Sum: '<S494>/Sum of Elements'
         *
         * About '<S494>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S494>/Math Function1' */

        /* Switch: '<S494>/Switch' incorporates:
         *  Constant: '<S494>/Constant'
         *  Product: '<S494>/Product'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_P_l_idx_0;
          rtb_MatrixConcatenate3[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_MatrixConcatenate3[2] = rtb_Add3_c;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S494>/Switch' */

        /* Product: '<S494>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S489>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S402>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S494>/Divide' incorporates:
         *  Product: '<S493>/Divide'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S493>/Divide' */
        rtb_Rem_p = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S402>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Sqrt: '<S488>/Sqrt' */
        rtb_Add3_c = sqrtf(rtb_Add4_e5);

        /* Gain: '<S447>/Gain' incorporates:
         *  Math: '<S447>/Square'
         */
        rtb_Add4_e5 = rtb_Add3_c * rtb_Add3_c * 2.0F;

        /* Sum: '<S492>/Subtract' incorporates:
         *  Product: '<S492>/Multiply'
         *  Product: '<S492>/Multiply1'
         */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_0 * rtb_Rem_p - rtb_P_l_idx_0
          * rtb_Sum_ff[0];

        /* Signum: '<S487>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S487>/Sign1' */

        /* Switch: '<S487>/Switch2' incorporates:
         *  Constant: '<S487>/Constant4'
         */
        if (rtb_Add3_c == 0.0F) {
          rtb_Add3_c = 1.0F;
        }

        /* End of Switch: '<S487>/Switch2' */

        /* DotProduct: '<S487>/Dot Product' */
        rtb_Rem_p = rtb_Sum_ff[0] * rtb_TmpSignalConversionAtMath_0 + rtb_Rem_p *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S487>/Acos' incorporates:
         *  DotProduct: '<S487>/Dot Product'
         */
        if (rtb_Rem_p > 1.0F) {
          rtb_Rem_p = 1.0F;
        } else {
          if (rtb_Rem_p < -1.0F) {
            rtb_Rem_p = -1.0F;
          }
        }

        /* Product: '<S487>/Multiply' incorporates:
         *  Trigonometry: '<S487>/Acos'
         */
        rtb_Add3_c *= acosf(rtb_Rem_p);

        /* Saturate: '<S447>/Saturation' */
        if (rtb_Add3_c > 1.57079637F) {
          rtb_Add3_c = 1.57079637F;
        } else {
          if (rtb_Add3_c < -1.57079637F) {
            rtb_Add3_c = -1.57079637F;
          }
        }

        /* End of Saturate: '<S447>/Saturation' */

        /* Product: '<S447>/Divide' incorporates:
         *  Constant: '<S334>/L1'
         *  Constant: '<S447>/Constant'
         *  MinMax: '<S447>/Max'
         *  MinMax: '<S447>/Min'
         *  Product: '<S447>/Multiply1'
         *  Sqrt: '<S489>/Sqrt'
         *  Sum: '<S489>/Sum of Elements'
         *  Trigonometry: '<S447>/Sin'
         */
        rtb_Add4_e5 = arm_sin_f32(rtb_Add3_c) * rtb_Add4_e5 / fminf(FMS_PARAM.L1,
          fmaxf(sqrtf(rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0]),
                0.5F));

        /* Sum: '<S400>/Subtract' incorporates:
         *  Product: '<S400>/Multiply'
         *  Product: '<S400>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sqrt_b * FMS_ConstB.Divide_d[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S389>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S389>/Sign1' */

        /* Switch: '<S389>/Switch2' incorporates:
         *  Constant: '<S389>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S389>/Switch2' */

        /* DotProduct: '<S389>/Dot Product' */
        rtb_Gain_fj = FMS_ConstB.Divide_d[0] * rtb_Sqrt_b + FMS_ConstB.Divide_d
          [1] * rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S389>/Acos' incorporates:
         *  DotProduct: '<S389>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S389>/Multiply' incorporates:
         *  Trigonometry: '<S389>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_Gain_fj);

        /* Math: '<S392>/Rem' incorporates:
         *  Constant: '<S392>/Constant1'
         *  Delay: '<S388>/Delay'
         *  Sum: '<S388>/Sum2'
         */
        rtb_Add3_c = rt_remf(rtb_MathFunction_f_idx_2 - FMS_DW.Delay_DSTATE_a,
                             6.28318548F);

        /* Switch: '<S392>/Switch' incorporates:
         *  Abs: '<S392>/Abs'
         *  Constant: '<S392>/Constant'
         *  Constant: '<S398>/Constant'
         *  Product: '<S392>/Multiply'
         *  RelationalOperator: '<S398>/Compare'
         *  Sum: '<S392>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S392>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S392>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S392>/Switch' */

        /* Sum: '<S388>/Sum' incorporates:
         *  Delay: '<S388>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Add3_c + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S397>/Multiply1' incorporates:
         *  Constant: '<S397>/const1'
         *  DiscreteIntegrator: '<S391>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S397>/Add' incorporates:
         *  DiscreteIntegrator: '<S391>/Integrator1'
         *  Sum: '<S391>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1)
          + rtb_Add3_c;

        /* Signum: '<S397>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S397>/Sign' */

        /* Sum: '<S397>/Add2' incorporates:
         *  Abs: '<S397>/Abs'
         *  Gain: '<S397>/Gain'
         *  Gain: '<S397>/Gain1'
         *  Product: '<S397>/Multiply2'
         *  Product: '<S397>/Multiply3'
         *  Sqrt: '<S397>/Sqrt'
         *  Sum: '<S397>/Add1'
         *  Sum: '<S397>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1) + FMS_ConstB.d_le) *
                           FMS_ConstB.d_le) - FMS_ConstB.d_le) * 0.5F *
          rtb_MathFunction_f_idx_0 + rtb_Add3_c;

        /* Sum: '<S397>/Add4' */
        rtb_MathFunction_f_idx_0 = (rtb_Divide_l_idx_1 - rtb_Rem_p) + rtb_Add3_c;

        /* Sum: '<S397>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d_le;

        /* Sum: '<S397>/Subtract1' */
        rtb_Divide_l_idx_1 -= FMS_ConstB.d_le;

        /* Signum: '<S397>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S397>/Sign1' */

        /* Signum: '<S397>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S397>/Sign2' */

        /* Sum: '<S397>/Add5' incorporates:
         *  Gain: '<S397>/Gain2'
         *  Product: '<S397>/Multiply4'
         *  Sum: '<S397>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Divide_l_idx_1) * 0.5F *
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S397>/Subtract3' */
        rtb_Add3_c = rtb_Rem_p - FMS_ConstB.d_le;

        /* Sum: '<S397>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Rem_p + FMS_ConstB.d_le;

        /* Product: '<S397>/Divide' */
        rtb_Sqrt_b = rtb_Rem_p / FMS_ConstB.d_le;

        /* Signum: '<S397>/Sign5' incorporates:
         *  Signum: '<S397>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Rem_p;
          rtb_MathFunction_f_idx_0 = rtb_Rem_p;
        }

        /* End of Signum: '<S397>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S388>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S393>/Rem' incorporates:
         *  Constant: '<S393>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S393>/Switch' incorporates:
         *  Abs: '<S393>/Abs'
         *  Constant: '<S393>/Constant'
         *  Constant: '<S399>/Constant'
         *  Product: '<S393>/Multiply'
         *  RelationalOperator: '<S399>/Compare'
         *  Sum: '<S393>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S393>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Gain_fj = 1.0F;
          } else {
            rtb_Gain_fj = rtb_Rem_p;
          }

          /* End of Signum: '<S393>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Gain_fj;
        }

        /* End of Switch: '<S393>/Switch' */

        /* Abs: '<S386>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S448>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S449>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S442>/Constant'
         *  RelationalOperator: '<S442>/Compare'
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

        /* End of Update for DiscreteIntegrator: '<S449>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S444>/Acceleration_Speed' incorporates:
         *  Constant: '<S444>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Product: '<S448>/Divide1' */
        rtb_Gain_fj = rtb_Add4_e5 / rtb_DiscreteTimeIntegrator_n;

        /* Saturate: '<S448>/Saturation' */
        if (rtb_Gain_fj > 0.314159274F) {
          rtb_Gain_fj = 0.314159274F;
        } else {
          if (rtb_Gain_fj < -0.314159274F) {
            rtb_Gain_fj = -0.314159274F;
          }
        }

        /* End of Saturate: '<S448>/Saturation' */

        /* Update for DiscreteIntegrator: '<S496>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Gain_fj;

        /* Update for Delay: '<S388>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S391>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S391>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S387>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S397>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S397>/Sign3' */

        /* Signum: '<S397>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S397>/Sign4' */

        /* Update for DiscreteIntegrator: '<S391>/Integrator' incorporates:
         *  Constant: '<S397>/const'
         *  Gain: '<S397>/Gain3'
         *  Product: '<S397>/Multiply5'
         *  Product: '<S397>/Multiply6'
         *  Sum: '<S397>/Subtract4'
         *  Sum: '<S397>/Subtract5'
         *  Sum: '<S397>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1)
          * FMS_ConstB.Gain4_np * ((rtb_Divide_l_idx_1 - rtb_Add3_c) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S391>/Integrator' */
        /* End of Outputs for SubSystem: '<S37>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S37>/Hold' incorporates:
           *  ActionPort: '<S332>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S341>/Motion Status'
           *  Chart: '<S351>/Motion State'
           *  Chart: '<S363>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S37>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Hold' incorporates:
         *  ActionPort: '<S332>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S341>/Motion Status' incorporates:
         *  Abs: '<S341>/Abs'
         *  Constant: '<S341>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S351>/Motion State' incorporates:
         *  Abs: '<S351>/Abs'
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

        /* End of Chart: '<S351>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S363>/Motion State' incorporates:
         *  Constant: '<S363>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S363>/Square'
         *  Math: '<S363>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S363>/Sqrt'
         *  Sum: '<S363>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S362>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S362>/Hold Control' incorporates:
             *  ActionPort: '<S365>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S362>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S362>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S362>/Hold Control' incorporates:
           *  ActionPort: '<S365>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S362>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S362>/Brake Control' incorporates:
           *  ActionPort: '<S364>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S362>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S362>/Move Control' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S362>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S362>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S362>/Move Control' incorporates:
           *  ActionPort: '<S366>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S362>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S362>/Switch Case' */

        /* SwitchCase: '<S340>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S340>/Hold Control' incorporates:
             *  ActionPort: '<S343>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S340>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Hold Control' incorporates:
           *  ActionPort: '<S343>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S340>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S340>/Brake Control' incorporates:
           *  ActionPort: '<S342>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S340>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S340>/Move Control' incorporates:
             *  ActionPort: '<S344>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S340>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Move Control' incorporates:
           *  ActionPort: '<S344>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S340>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S340>/Switch Case' */

        /* SwitchCase: '<S350>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S350>/Hold Control' incorporates:
             *  ActionPort: '<S353>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S350>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S350>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S350>/Hold Control' incorporates:
           *  ActionPort: '<S353>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S350>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S350>/Brake Control' incorporates:
           *  ActionPort: '<S352>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S350>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S350>/Move Control' incorporates:
             *  ActionPort: '<S354>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S350>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S350>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S350>/Move Control' incorporates:
           *  ActionPort: '<S354>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S350>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S350>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S332>/Bus Assignment'
         *  Constant: '<S332>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S332>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S350>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S350>/Saturation' */

        /* Saturate: '<S362>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S362>/Saturation1' */

        /* Saturate: '<S340>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S332>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S340>/Saturation1' */
        /* End of Outputs for SubSystem: '<S37>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S336>/Action Port'
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
       *  Math: '<S216>/Square'
       *  Math: '<S218>/Math Function'
       *  Sum: '<S174>/Subtract'
       *  Sum: '<S231>/Sum1'
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
        /* Disable for SwitchCase: '<S196>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S186>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S145>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S35>/Offboard' incorporates:
         *  ActionPort: '<S146>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S310>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S313>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S314>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S314>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S314>/Multiply1' incorporates:
         *  Product: '<S314>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S314>/Divide' incorporates:
         *  Constant: '<S314>/Constant'
         *  Constant: '<S314>/R'
         *  Sqrt: '<S314>/Sqrt'
         *  Sum: '<S314>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S314>/Product3' incorporates:
         *  Constant: '<S314>/Constant1'
         *  Product: '<S314>/Multiply1'
         *  Sum: '<S314>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S314>/Multiply2' incorporates:
         *  Trigonometry: '<S314>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S313>/Sum' incorporates:
         *  Gain: '<S310>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S318>/Abs' incorporates:
         *  Abs: '<S321>/Abs1'
         *  Switch: '<S318>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S318>/Switch1' incorporates:
         *  Abs: '<S318>/Abs'
         *  Bias: '<S318>/Bias2'
         *  Bias: '<S318>/Bias3'
         *  Constant: '<S315>/Constant'
         *  Constant: '<S315>/Constant1'
         *  Constant: '<S320>/Constant'
         *  Gain: '<S318>/Gain1'
         *  Product: '<S318>/Multiply'
         *  RelationalOperator: '<S320>/Compare'
         *  Switch: '<S315>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S321>/Switch1' incorporates:
           *  Bias: '<S321>/Bias2'
           *  Bias: '<S321>/Bias3'
           *  Constant: '<S321>/Constant'
           *  Constant: '<S322>/Constant'
           *  Math: '<S321>/Math Function'
           *  RelationalOperator: '<S322>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S321>/Switch1' */

          /* Signum: '<S318>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S318>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S315>/Sum' incorporates:
         *  Gain: '<S310>/Gain1'
         *  Gain: '<S310>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S313>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S313>/Multiply' incorporates:
         *  Gain: '<S313>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S317>/Switch1' incorporates:
         *  Abs: '<S317>/Abs1'
         *  Bias: '<S317>/Bias2'
         *  Bias: '<S317>/Bias3'
         *  Constant: '<S317>/Constant'
         *  Constant: '<S319>/Constant'
         *  Math: '<S317>/Math Function'
         *  RelationalOperator: '<S319>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S317>/Switch1' */

        /* Product: '<S313>/Multiply' incorporates:
         *  Gain: '<S313>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S291>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S295>/Multiply1'
         *  Product: '<S296>/Multiply3'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S304>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S304>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S304>/Trigonometric Function3' incorporates:
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S304>/Gain' incorporates:
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S304>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S304>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S304>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S304>/Trigonometric Function' incorporates:
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S304>/Trigonometric Function1' incorporates:
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S295>/Saturation' incorporates:
           *  Constant: '<S301>/Constant'
           *  Constant: '<S302>/Constant'
           *  Constant: '<S312>/Constant'
           *  DataTypeConversion: '<S310>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S294>/Logical Operator'
           *  Product: '<S295>/Multiply'
           *  Product: '<S316>/Multiply1'
           *  Product: '<S316>/Multiply2'
           *  RelationalOperator: '<S301>/Compare'
           *  RelationalOperator: '<S302>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S294>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S309>/lat_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S295>/Sum1'
           *  Sum: '<S316>/Sum2'
           *  Switch: '<S297>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Add4_e5 = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Add4_e5 = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Add4_e5 -
            FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Gain_fj > 4.0F) {
            rtb_Gain_fj = 4.0F;
          } else {
            if (rtb_Gain_fj < -4.0F) {
              rtb_Gain_fj = -4.0F;
            }
          }

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S295>/Saturation' incorporates:
           *  Constant: '<S301>/Constant'
           *  Constant: '<S302>/Constant'
           *  Constant: '<S312>/Constant'
           *  DataTypeConversion: '<S310>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S294>/Logical Operator'
           *  Product: '<S295>/Multiply'
           *  Product: '<S316>/Multiply3'
           *  Product: '<S316>/Multiply4'
           *  RelationalOperator: '<S301>/Compare'
           *  RelationalOperator: '<S302>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S294>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S309>/lon_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S295>/Sum1'
           *  Sum: '<S316>/Sum3'
           *  Switch: '<S297>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Add4_e5 = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Add4_e5 = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Add4_e5 -
            FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Add3_c > 4.0F) {
            rtb_Add3_c = 4.0F;
          } else {
            if (rtb_Add3_c < -4.0F) {
              rtb_Add3_c = -4.0F;
            }
          }

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S295>/Saturation' incorporates:
           *  Constant: '<S301>/Constant'
           *  Constant: '<S302>/Constant'
           *  Constant: '<S312>/Constant'
           *  DataTypeConversion: '<S310>/Data Type Conversion'
           *  DataTypeConversion: '<S310>/Data Type Conversion1'
           *  Gain: '<S298>/Gain'
           *  Gain: '<S310>/Gain2'
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S294>/Logical Operator'
           *  Product: '<S295>/Multiply'
           *  RelationalOperator: '<S301>/Compare'
           *  RelationalOperator: '<S302>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S294>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S309>/alt_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S295>/Sum1'
           *  Sum: '<S313>/Sum1'
           *  Switch: '<S297>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Add4_e5 = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Add4_e5 = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Add4_e5 -
            (-FMS_U.INS_Out.h_R) : 0.0F;
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
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Gain_fj);
          }

          /* SignalConversion: '<S238>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S238>/Constant4'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  Product: '<S295>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S238>/Trigonometric Function3' incorporates:
           *  Gain: '<S237>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S238>/Gain' incorporates:
           *  Gain: '<S237>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S238>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S238>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S238>/Constant3'
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S238>/Trigonometric Function' incorporates:
           *  Gain: '<S237>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S238>/Trigonometric Function1' incorporates:
           *  Gain: '<S237>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S238>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S228>/Multiply' incorporates:
           *  Constant: '<S236>/Constant'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/ax_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S238>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S228>/Multiply' incorporates:
           *  Constant: '<S236>/Constant'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/ay_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S238>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S228>/Multiply' incorporates:
           *  Constant: '<S236>/Constant'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S228>/Index Vector' incorporates:
           *  Product: '<S234>/Multiply'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S308>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S308>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S306>/Gain' incorporates:
           *  Gain: '<S239>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S296>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S308>/Trigonometric Function3' incorporates:
           *  Gain: '<S306>/Gain'
           *  Trigonometry: '<S308>/Trigonometric Function1'
           */
          rtb_MathFunction_f_idx_0 = arm_cos_f32(rtb_Add3_c);
          rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S308>/Trigonometric Function2' incorporates:
           *  Gain: '<S306>/Gain'
           *  Trigonometry: '<S308>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S308>/Gain' incorporates:
           *  Trigonometry: '<S308>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S308>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S308>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S308>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S308>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S308>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S307>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S308>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S307>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S308>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S307>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S307>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S307>/Constant4'
           */
          rtb_VectorConcatenate_e[5] = 0.0F;

          /* Trigonometry: '<S307>/Trigonometric Function3' incorporates:
           *  Gain: '<S305>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S307>/Trigonometric Function1'
           */
          rtb_Divide_l_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_e[4] = rtb_Divide_l_idx_1;

          /* Trigonometry: '<S307>/Trigonometric Function2' incorporates:
           *  Gain: '<S305>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S307>/Trigonometric Function'
           */
          rtb_DiscreteTimeIntegrator_n = arm_sin_f32
            (-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S307>/Gain' incorporates:
           *  Trigonometry: '<S307>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_e[3] = -rtb_DiscreteTimeIntegrator_n;

          /* SignalConversion: '<S307>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S307>/Constant3'
           */
          rtb_VectorConcatenate_e[2] = 0.0F;

          /* Trigonometry: '<S307>/Trigonometric Function' */
          rtb_VectorConcatenate_e[1] = rtb_DiscreteTimeIntegrator_n;

          /* Trigonometry: '<S307>/Trigonometric Function1' */
          rtb_VectorConcatenate_e[0] = rtb_Divide_l_idx_1;

          /* RelationalOperator: '<S312>/Compare' incorporates:
           *  Constant: '<S312>/Constant'
           *  S-Function (sfix_bitop): '<S309>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S309>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S309>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S310>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S310>/Data Type Conversion'
           *  Gain: '<S310>/Gain2'
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S316>/Multiply1'
           *  Product: '<S316>/Multiply2'
           *  Product: '<S316>/Multiply3'
           *  Product: '<S316>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S313>/Sum1'
           *  Sum: '<S316>/Sum2'
           *  Sum: '<S316>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S297>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S301>/Compare' incorporates:
           *  Constant: '<S301>/Constant'
           *  S-Function (sfix_bitop): '<S294>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S302>/Compare' incorporates:
           *  Constant: '<S302>/Constant'
           *  S-Function (sfix_bitop): '<S294>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S296>/Sum2' incorporates:
             *  Product: '<S296>/Multiply2'
             *  Switch: '<S297>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Add4_e5 = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Add4_e5 = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S296>/Saturation1' incorporates:
             *  Gain: '<S298>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S294>/Logical Operator'
             *  Product: '<S296>/Multiply'
             *  Product: '<S296>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             *  Sum: '<S296>/Sum2'
             */
            rtb_Gain_fj = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_Add4_e5 - ((rtb_VectorConcatenate_e[rtb_Compare_bv_0 + 3] *
                              FMS_U.INS_Out.y_R +
                              rtb_VectorConcatenate_e[rtb_Compare_bv_0] *
                              FMS_U.INS_Out.x_R) +
                             rtb_VectorConcatenate_e[rtb_Compare_bv_0 + 6] *
                             -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Gain_fj > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Gain_fj < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] = rtb_Gain_fj;
            }

            /* End of Saturate: '<S296>/Saturation1' */
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] *
              rtb_TmpSignalConversionAtMath_c[2] +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_TmpSignalConversionAtMath_c[1] +
               rtb_Transpose[rtb_Compare_bv_0] *
               rtb_TmpSignalConversionAtMath_c[0]);
          }

          /* SignalConversion: '<S240>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S240>/Constant4'
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  Product: '<S296>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S240>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S240>/Gain' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           *  Trigonometry: '<S240>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S240>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S240>/Constant3'
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S240>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S240>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S240>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S228>/Multiply' incorporates:
           *  Constant: '<S236>/Constant'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/ax_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S240>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S228>/Multiply' incorporates:
           *  Constant: '<S236>/Constant'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/ay_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S240>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S228>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S228>/Multiply' incorporates:
           *  Constant: '<S236>/Constant'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S228>/Index Vector' incorporates:
           *  Product: '<S235>/Multiply3'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         default:
          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S300>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S300>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S300>/Trigonometric Function3' incorporates:
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S300>/Gain' incorporates:
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S300>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S300>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S300>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S300>/Trigonometric Function' incorporates:
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S300>/Trigonometric Function1' incorporates:
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S309>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S294>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S312>/Compare' incorporates:
           *  Constant: '<S312>/Constant'
           *  S-Function (sfix_bitop): '<S309>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S309>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S294>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S312>/Compare' incorporates:
           *  Constant: '<S312>/Constant'
           *  S-Function (sfix_bitop): '<S309>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S309>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S294>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S312>/Compare' incorporates:
           *  Constant: '<S312>/Constant'
           *  S-Function (sfix_bitop): '<S309>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S310>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S310>/Data Type Conversion'
           *  Gain: '<S310>/Gain2'
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S316>/Multiply1'
           *  Product: '<S316>/Multiply2'
           *  Product: '<S316>/Multiply3'
           *  Product: '<S316>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S313>/Sum1'
           *  Sum: '<S316>/Sum2'
           *  Sum: '<S316>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S297>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S301>/Compare' incorporates:
           *  Constant: '<S301>/Constant'
           *  S-Function (sfix_bitop): '<S294>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S294>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S302>/Compare' incorporates:
           *  Constant: '<S302>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S293>/Sum2' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S297>/Switch' incorporates:
             *  Product: '<S293>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Add4_e5 = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Add4_e5 = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S293>/Saturation1' incorporates:
             *  Gain: '<S298>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S294>/Logical Operator'
             *  Product: '<S293>/Multiply'
             *  Product: '<S293>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             */
            rtb_Gain_fj = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_Add4_e5 - ((rtb_Transpose[rtb_Compare_bv_0 + 3] *
                              FMS_U.INS_Out.y_R + rtb_Transpose[rtb_Compare_bv_0]
                              * FMS_U.INS_Out.x_R) +
                             rtb_Transpose[rtb_Compare_bv_0 + 6] *
                             -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Gain_fj > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Gain_fj < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] = rtb_Gain_fj;
            }

            /* End of Saturate: '<S293>/Saturation1' */
          }

          /* End of Sum: '<S293>/Sum2' */

          /* MultiPortSwitch: '<S228>/Index Vector' incorporates:
           *  Constant: '<S236>/Constant'
           *  Product: '<S228>/Multiply'
           *  RelationalOperator: '<S236>/Compare'
           *  S-Function (sfix_bitop): '<S233>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S233>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S233>/az_cmd valid'
           */
          rtb_TmpSignalConversionAtMath_c[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S291>/Index Vector' */

        /* Sum: '<S287>/Sum1' incorporates:
         *  Constant: '<S287>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S287>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Add4_e5 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S288>/Abs' */
        rtb_Add3_c = fabsf(rtb_Add4_e5);

        /* Switch: '<S288>/Switch' incorporates:
         *  Constant: '<S288>/Constant'
         *  Constant: '<S289>/Constant'
         *  Product: '<S288>/Multiply'
         *  RelationalOperator: '<S289>/Compare'
         *  Sum: '<S288>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S288>/Sign' */
          if (rtb_Add4_e5 < 0.0F) {
            rtb_Add4_e5 = -1.0F;
          } else {
            if (rtb_Add4_e5 > 0.0F) {
              rtb_Add4_e5 = 1.0F;
            }
          }

          /* End of Signum: '<S288>/Sign' */
          rtb_Add4_e5 *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S288>/Switch' */

        /* Saturate: '<S287>/Saturation' */
        if (rtb_Add4_e5 > 0.314159274F) {
          rtb_Add4_e5 = 0.314159274F;
        } else {
          if (rtb_Add4_e5 < -0.314159274F) {
            rtb_Add4_e5 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S287>/Saturation' */

        /* Gain: '<S284>/Gain2' */
        rtb_Add4_e5 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S230>/Sum' incorporates:
         *  Constant: '<S286>/Constant'
         *  Constant: '<S290>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S284>/Multiply2'
         *  Product: '<S285>/Multiply1'
         *  RelationalOperator: '<S286>/Compare'
         *  RelationalOperator: '<S290>/Compare'
         *  S-Function (sfix_bitop): '<S284>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S285>/psi_rate_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Add4_e5 : 0.0F)
          + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S291>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_MathFunction_f_idx_0 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S291>/Gain2' */
        rtb_Add4_e5 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S292>/Index Vector' incorporates:
         *  Constant: '<S327>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S292>/Multiply'
         *  Product: '<S325>/Multiply'
         *  Product: '<S326>/Multiply3'
         *  RelationalOperator: '<S327>/Compare'
         *  S-Function (sfix_bitop): '<S324>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S324>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S324>/w_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S329>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S329>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S329>/Trigonometric Function3' incorporates:
           *  Gain: '<S328>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S329>/Gain' incorporates:
           *  Gain: '<S328>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S329>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S329>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S329>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S329>/Trigonometric Function' incorporates:
           *  Gain: '<S328>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S329>/Trigonometric Function1' incorporates:
           *  Gain: '<S328>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S329>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S292>/Multiply' incorporates:
           *  Constant: '<S327>/Constant'
           *  RelationalOperator: '<S327>/Compare'
           *  S-Function (sfix_bitop): '<S324>/u_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S329>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S292>/Multiply' incorporates:
           *  Constant: '<S327>/Constant'
           *  RelationalOperator: '<S327>/Compare'
           *  S-Function (sfix_bitop): '<S324>/v_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U
            ? FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S329>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S292>/Multiply' incorporates:
           *  Constant: '<S327>/Constant'
           *  RelationalOperator: '<S327>/Compare'
           *  S-Function (sfix_bitop): '<S324>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] *
               rtb_DiscreteTimeIntegrator_n + rtb_Transpose[rtb_Compare_bv_0] *
               rtb_Divide_l_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S331>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S331>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S330>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S326>/Subtract'
           */
          rtb_Divide_l_idx_1 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S331>/Trigonometric Function3' incorporates:
           *  Gain: '<S330>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Divide_l_idx_1);

          /* Gain: '<S331>/Gain' incorporates:
           *  Gain: '<S330>/Gain'
           *  Trigonometry: '<S331>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_l_idx_1);

          /* SignalConversion: '<S331>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S331>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S331>/Trigonometric Function' incorporates:
           *  Gain: '<S330>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Divide_l_idx_1);

          /* Trigonometry: '<S331>/Trigonometric Function1' incorporates:
           *  Gain: '<S330>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Divide_l_idx_1);

          /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S292>/Multiply' incorporates:
           *  Constant: '<S327>/Constant'
           *  RelationalOperator: '<S327>/Compare'
           *  S-Function (sfix_bitop): '<S324>/u_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S292>/Multiply' incorporates:
           *  Constant: '<S327>/Constant'
           *  RelationalOperator: '<S327>/Compare'
           *  S-Function (sfix_bitop): '<S324>/v_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U
            ? FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S292>/Multiply' incorporates:
           *  Constant: '<S327>/Constant'
           *  RelationalOperator: '<S327>/Compare'
           *  S-Function (sfix_bitop): '<S324>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
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

        /* End of MultiPortSwitch: '<S292>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_MathFunction_f_idx_0;

        /* Sum: '<S231>/Sum1' */
        rtb_Add3_c = rtb_Add4_e5 + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S248>/Switch' incorporates:
         *  Constant: '<S263>/Constant'
         *  Constant: '<S264>/Constant'
         *  Constant: '<S265>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S263>/Compare'
         *  RelationalOperator: '<S264>/Compare'
         *  RelationalOperator: '<S265>/Compare'
         *  S-Function (sfix_bitop): '<S248>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S248>/y_v_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S248>/Logical Operator' incorporates:
           *  Constant: '<S264>/Constant'
           *  Constant: '<S265>/Constant'
           *  RelationalOperator: '<S264>/Compare'
           *  RelationalOperator: '<S265>/Compare'
           *  S-Function (sfix_bitop): '<S248>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S248>/y_v_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S248>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S229>/u_cmd_valid' */
        /* MATLAB Function: '<S260>/bit_shift' incorporates:
         *  DataTypeConversion: '<S229>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_es << 6);

        /* End of Outputs for SubSystem: '<S229>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S229>/v_cmd_valid' */
        /* MATLAB Function: '<S261>/bit_shift' incorporates:
         *  DataTypeConversion: '<S229>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S229>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S249>/Switch' incorporates:
         *  Constant: '<S267>/Constant'
         *  Constant: '<S268>/Constant'
         *  Constant: '<S270>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S267>/Compare'
         *  RelationalOperator: '<S268>/Compare'
         *  RelationalOperator: '<S270>/Compare'
         *  S-Function (sfix_bitop): '<S249>/ax_cmd'
         *  S-Function (sfix_bitop): '<S249>/ay_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S249>/Logical Operator' incorporates:
           *  Constant: '<S268>/Constant'
           *  Constant: '<S270>/Constant'
           *  RelationalOperator: '<S268>/Compare'
           *  RelationalOperator: '<S270>/Compare'
           *  S-Function (sfix_bitop): '<S249>/ax_cmd'
           *  S-Function (sfix_bitop): '<S249>/ay_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S249>/Switch' */
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
        FMS_Y.FMS_Out.ax_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.az_cmd = rtb_TmpSignalConversionAtMath_c[2];

        /* Saturate: '<S230>/Saturation' */
        if (rtb_Gain_fj > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S146>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Gain_fj < -FMS_PARAM.YAW_RATE_LIM) {
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
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Gain_fj;
        }

        /* End of Saturate: '<S230>/Saturation' */

        /* Saturate: '<S231>/Saturation2' */
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

        /* End of Saturate: '<S231>/Saturation2' */

        /* Saturate: '<S231>/Saturation1' */
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

        /* End of Saturate: '<S231>/Saturation1' */

        /* Saturate: '<S231>/Saturation3' */
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

        /* End of Saturate: '<S231>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S229>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S229>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S229>/throttle_cmd_valid' */
        /* BusAssignment: '<S146>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S241>/Constant'
         *  Constant: '<S242>/Constant'
         *  Constant: '<S243>/Constant'
         *  Constant: '<S244>/Constant'
         *  Constant: '<S245>/Constant'
         *  Constant: '<S246>/Constant'
         *  Constant: '<S247>/Constant'
         *  Constant: '<S266>/Constant'
         *  Constant: '<S269>/Constant'
         *  DataTypeConversion: '<S229>/Data Type Conversion10'
         *  DataTypeConversion: '<S229>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S250>/bit_shift'
         *  MATLAB Function: '<S251>/bit_shift'
         *  MATLAB Function: '<S252>/bit_shift'
         *  MATLAB Function: '<S254>/bit_shift'
         *  MATLAB Function: '<S255>/bit_shift'
         *  MATLAB Function: '<S256>/bit_shift'
         *  MATLAB Function: '<S257>/bit_shift'
         *  MATLAB Function: '<S258>/bit_shift'
         *  MATLAB Function: '<S259>/bit_shift'
         *  MATLAB Function: '<S262>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S241>/Compare'
         *  RelationalOperator: '<S242>/Compare'
         *  RelationalOperator: '<S243>/Compare'
         *  RelationalOperator: '<S244>/Compare'
         *  RelationalOperator: '<S245>/Compare'
         *  RelationalOperator: '<S246>/Compare'
         *  RelationalOperator: '<S247>/Compare'
         *  RelationalOperator: '<S266>/Compare'
         *  RelationalOperator: '<S269>/Compare'
         *  S-Function (sfix_bitop): '<S229>/p_cmd'
         *  S-Function (sfix_bitop): '<S229>/phi_cmd'
         *  S-Function (sfix_bitop): '<S229>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S229>/q_cmd'
         *  S-Function (sfix_bitop): '<S229>/r_cmd'
         *  S-Function (sfix_bitop): '<S229>/theta_cmd'
         *  S-Function (sfix_bitop): '<S229>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S248>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S249>/az_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         *  Sum: '<S229>/Add'
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

        /* End of Outputs for SubSystem: '<S229>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S229>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S229>/q_cmd_valid' */
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
           *  Chart: '<S187>/Motion Status'
           *  Chart: '<S197>/Motion State'
           *  Delay: '<S153>/Delay'
           *  Delay: '<S175>/Delay'
           *  DiscreteIntegrator: '<S156>/Integrator'
           *  DiscreteIntegrator: '<S156>/Integrator1'
           *  DiscreteIntegrator: '<S171>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S223>/Discrete-Time Integrator'
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
          /* Disable for SwitchCase: '<S196>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S186>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S175>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S171>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S223>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S153>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S197>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S187>/Motion Status' */
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

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S171>/Switch2' incorporates:
         *  Constant: '<S171>/vel'
         *  Constant: '<S180>/Constant'
         *  RelationalOperator: '<S180>/Compare'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S171>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S148>/Delay Input1'
         *
         * Block description for '<S148>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S170>/Compare' incorporates:
         *  Constant: '<S227>/Constant'
         *  RelationalOperator: '<S227>/Compare'
         *  UnitDelay: '<S148>/Delay Input1'
         *
         * Block description for '<S148>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S171>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S197>/Motion State' incorporates:
         *  Constant: '<S197>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S197>/Square'
         *  Math: '<S197>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S197>/Sqrt'
         *  Sum: '<S197>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S196>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S196>/Hold Control' incorporates:
             *  ActionPort: '<S199>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S196>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S196>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S196>/Hold Control' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S196>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S196>/Brake Control' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S196>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S196>/Move Control' incorporates:
             *  ActionPort: '<S200>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S196>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S196>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S196>/Move Control' incorporates:
           *  ActionPort: '<S200>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S196>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S196>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S187>/Motion Status' incorporates:
         *  Abs: '<S187>/Abs'
         *  Constant: '<S187>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S186>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S186>/Hold Control' incorporates:
             *  ActionPort: '<S189>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S186>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S186>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S186>/Hold Control' incorporates:
           *  ActionPort: '<S189>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S186>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S186>/Brake Control' incorporates:
           *  ActionPort: '<S188>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S186>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S186>/Move Control' incorporates:
             *  ActionPort: '<S190>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S186>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S186>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S186>/Move Control' incorporates:
           *  ActionPort: '<S190>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S186>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S186>/Switch Case' */

        /* Switch: '<S151>/Switch' incorporates:
         *  Product: '<S175>/Multiply'
         *  Sum: '<S175>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S196>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S196>/Saturation1' */

          /* Saturate: '<S186>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S186>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S175>/Sum' incorporates:
           *  Delay: '<S175>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S224>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S171>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Sum_ff[0] = rtb_Divide_l_idx_1;

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

          /* Sqrt: '<S183>/Sqrt' incorporates:
           *  Math: '<S183>/Square'
           *  Sum: '<S171>/Sum'
           *  Sum: '<S183>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0
                             + rtb_Add3_c * rtb_Add3_c);

          /* SignalConversion: '<S226>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S226>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S226>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S225>/Gain' incorporates:
           *  DiscreteIntegrator: '<S223>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S223>/Add'
           */
          rtb_Add4_e5 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S226>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add4_e5);

          /* Gain: '<S226>/Gain' incorporates:
           *  Trigonometry: '<S226>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add4_e5);

          /* SignalConversion: '<S226>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S226>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S226>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add4_e5);

          /* Trigonometry: '<S226>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add4_e5);

          /* Switch: '<S182>/Switch2' incorporates:
           *  Constant: '<S171>/Constant2'
           *  DiscreteIntegrator: '<S171>/Acceleration_Speed'
           *  RelationalOperator: '<S182>/LowerRelop1'
           *  RelationalOperator: '<S182>/UpperRelop'
           *  Switch: '<S182>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE > rtb_DiscreteTimeIntegrator_n) {
            rtb_Add4_e5 = rtb_DiscreteTimeIntegrator_n;
          } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
            /* Switch: '<S182>/Switch' incorporates:
             *  Constant: '<S171>/Constant2'
             */
            rtb_Add4_e5 = 0.0F;
          } else {
            rtb_Add4_e5 = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S182>/Switch2' */

          /* Switch: '<S171>/Switch' */
          if (rtb_Add3_c > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
          } else {
            /* Gain: '<S171>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Add3_c;

            /* Switch: '<S181>/Switch2' incorporates:
             *  Constant: '<S171>/Constant1'
             *  RelationalOperator: '<S181>/LowerRelop1'
             *  RelationalOperator: '<S181>/UpperRelop'
             *  Switch: '<S181>/Switch'
             */
            if (rtb_Gain_fj > rtb_DiscreteTimeIntegrator_n) {
              rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S181>/Switch' incorporates:
                 *  Constant: '<S171>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S181>/Switch2' */
          }

          /* End of Switch: '<S171>/Switch' */

          /* Switch: '<S171>/Switch1' incorporates:
           *  Sum: '<S171>/Sum1'
           */
          if (rtb_Add4_e5 - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Add4_e5;
          }

          /* End of Switch: '<S171>/Switch1' */

          /* Sum: '<S224>/Sum of Elements' incorporates:
           *  Math: '<S224>/Math Function'
           */
          rtb_Add4_e5 = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_1;

          /* Math: '<S224>/Math Function1' incorporates:
           *  Sum: '<S224>/Sum of Elements'
           *
           * About '<S224>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Add4_e5 < 0.0F) {
            rtb_Add4_e5 = -sqrtf(fabsf(rtb_Add4_e5));
          } else {
            rtb_Add4_e5 = sqrtf(rtb_Add4_e5);
          }

          /* End of Math: '<S224>/Math Function1' */

          /* Switch: '<S224>/Switch' incorporates:
           *  Constant: '<S224>/Constant'
           *  Product: '<S224>/Product'
           */
          if (rtb_Add4_e5 > 0.0F) {
            rtb_Add3_c = rtb_Sum_ff[0];
          } else {
            rtb_Add3_c = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Add4_e5 = 1.0F;
          }

          /* End of Switch: '<S224>/Switch' */

          /* Product: '<S222>/Multiply2' incorporates:
           *  Product: '<S224>/Divide'
           */
          rtb_MathFunction_f_idx_0 = rtb_Add3_c / rtb_Add4_e5 * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_l_idx_1 / rtb_Add4_e5;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S177>/Sum1' incorporates:
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S177>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add4_e5 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

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
          rtb_Add4_e5 = sqrtf(rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1 +
                              rtb_Add4_e5 * rtb_Add4_e5) / sqrtf(rtb_Rem_p *
            rtb_Rem_p + rtb_Add3_c * rtb_Add3_c);

          /* Saturate: '<S177>/Saturation' */
          if (rtb_Add4_e5 > 1.0F) {
            rtb_Add4_e5 = 1.0F;
          } else {
            if (rtb_Add4_e5 < 0.0F) {
              rtb_Add4_e5 = 0.0F;
            }
          }

          /* End of Saturate: '<S177>/Saturation' */

          /* Product: '<S175>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_MathFunction_f_idx_0;
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
          rtb_Gain_fj = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Add4_e5 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S168>/Saturation1' incorporates:
           *  Product: '<S175>/Multiply'
           */
          if (rtb_Gain_fj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Gain_fj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Gain_fj;
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
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_l_idx_1;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S217>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S217>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Add4_e5 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S217>/Math Function1' incorporates:
         *  Sum: '<S217>/Sum of Elements'
         *
         * About '<S217>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Add4_e5));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Add4_e5);
        }

        /* End of Math: '<S217>/Math Function1' */

        /* Switch: '<S217>/Switch' incorporates:
         *  Constant: '<S217>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S217>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S217>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S149>/Sum' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Gain_fj = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_TmpSignalConversionAtDela_a[0] = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_MathFunction_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S167>/Sum of Elements' incorporates:
         *  Math: '<S167>/Math Function'
         *  Sum: '<S149>/Sum'
         */
        rtb_Add4_e5 = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0 +
          rtb_Gain_fj * rtb_Gain_fj;

        /* Math: '<S167>/Math Function1' incorporates:
         *  Sum: '<S167>/Sum of Elements'
         *
         * About '<S167>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Add4_e5));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Add4_e5);
        }

        /* End of Math: '<S167>/Math Function1' */

        /* Switch: '<S167>/Switch' incorporates:
         *  Constant: '<S167>/Constant'
         *  Product: '<S167>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_2 = rtb_Divide_l_idx_1;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_Gain_fj = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
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
                        rtb_TmpSignalConversionAtDela_a, &rtb_Add4_e5);

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
        rtb_Sqrt_b = 0.0F;
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
          rtb_Sqrt_b = (FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
                        [0]) * rtb_Add3_c + FMS_B.Cmd_In.cur_waypoint[0];
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
        rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Divide_l_idx_1 = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
                              * rtb_Rem_p + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_TmpSignalConversionAtMath_0) /
          (rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0 +
           rtb_Rem_p * rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_l_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_l_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_l_idx_0 = rtb_Divide_l_idx_1 * rtb_TmpSignalConversionAtMath_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S173>/Switch1' incorporates:
         *  Constant: '<S210>/Constant'
         *  RelationalOperator: '<S210>/Compare'
         */
        if (rtb_Add4_e5 <= 0.0F) {
          /* Switch: '<S173>/Switch' incorporates:
           *  Constant: '<S209>/Constant'
           *  MATLAB Function: '<S173>/SearchL1RefWP'
           *  RelationalOperator: '<S209>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_l_idx_0;

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
                rtb_Rem_p + FMS_B.Cmd_In.cur_waypoint[1];

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
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b * rtb_Sqrt_b;
        rtb_Add3_c = rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S174>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S218>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S218>/Math Function' incorporates:
         *  Math: '<S216>/Square'
         */
        rtb_Add4_e5 = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Sum: '<S218>/Sum of Elements' incorporates:
         *  Math: '<S218>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_Add4_e5 + rtb_TmpSignalConversionAtDela_a[0];

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
          rtb_MatrixConcatenate3[0] = rtb_Add3_c;
          rtb_MatrixConcatenate3[1] = rtb_Sqrt_b;
          rtb_MatrixConcatenate3[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S218>/Switch' */

        /* Product: '<S217>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_P_l_idx_0 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S220>/Sum of Elements' incorporates:
         *  Math: '<S220>/Math Function'
         *  SignalConversion: '<S220>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S220>/Math Function1' incorporates:
         *  Sum: '<S220>/Sum of Elements'
         *
         * About '<S220>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S220>/Math Function1' */

        /* Switch: '<S220>/Switch' incorporates:
         *  Constant: '<S220>/Constant'
         *  Product: '<S220>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_P_l_idx_0;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S220>/Switch' */

        /* Product: '<S218>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S221>/Sum of Elements' incorporates:
         *  Math: '<S221>/Math Function'
         *  SignalConversion: '<S221>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S221>/Math Function1' incorporates:
         *  Sum: '<S221>/Sum of Elements'
         *
         * About '<S221>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Divide_l_idx_1 = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S221>/Math Function1' */

        /* Switch: '<S221>/Switch' incorporates:
         *  Constant: '<S221>/Constant'
         *  Product: '<S221>/Product'
         */
        if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_P_l_idx_0;
          rtb_MatrixConcatenate3[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_MatrixConcatenate3[2] = rtb_Divide_l_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S221>/Switch' */

        /* Product: '<S221>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S220>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S167>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S221>/Divide' incorporates:
         *  Math: '<S216>/Square'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S220>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S167>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S215>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S215>/Square'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S215>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S174>/Gain' incorporates:
         *  Math: '<S174>/Square'
         */
        rtb_Gain_fj = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1 * 2.0F;

        /* Sum: '<S219>/Subtract' incorporates:
         *  Product: '<S219>/Multiply'
         *  Product: '<S219>/Multiply1'
         */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtDela_a[1] - rtb_P_l_idx_0 *
          rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S214>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S214>/Sign1' */

        /* Switch: '<S214>/Switch2' incorporates:
         *  Constant: '<S214>/Constant4'
         */
        if (rtb_Divide_l_idx_1 == 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        }

        /* End of Switch: '<S214>/Switch2' */

        /* DotProduct: '<S214>/Dot Product' */
        rtb_MathFunction_f_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S214>/Acos' incorporates:
         *  DotProduct: '<S214>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_0 > 1.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          }
        }

        /* Product: '<S214>/Multiply' incorporates:
         *  Trigonometry: '<S214>/Acos'
         */
        rtb_Divide_l_idx_1 *= acosf(rtb_MathFunction_f_idx_0);

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
         *  Sqrt: '<S216>/Sqrt'
         *  Sum: '<S216>/Sum of Elements'
         *  Trigonometry: '<S174>/Sin'
         */
        rtb_MathFunction_f_idx_2 = arm_sin_f32(rtb_Divide_l_idx_1) * rtb_Gain_fj
          / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Add4_e5 + rtb_Add3_c), 0.5F));

        /* Sum: '<S165>/Subtract' incorporates:
         *  Product: '<S165>/Multiply'
         *  Product: '<S165>/Multiply1'
         */
        rtb_Rem_p = rtb_Sqrt_b * FMS_ConstB.Divide[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S154>/Sign1' */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_p = -1.0F;
        } else {
          if (rtb_Rem_p > 0.0F) {
            rtb_Rem_p = 1.0F;
          }
        }

        /* End of Signum: '<S154>/Sign1' */

        /* Switch: '<S154>/Switch2' incorporates:
         *  Constant: '<S154>/Constant4'
         */
        if (rtb_Rem_p == 0.0F) {
          rtb_Rem_p = 1.0F;
        }

        /* End of Switch: '<S154>/Switch2' */

        /* DotProduct: '<S154>/Dot Product' */
        rtb_Gain_fj = FMS_ConstB.Divide[0] * rtb_Sqrt_b + FMS_ConstB.Divide[1] *
          rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S154>/Acos' incorporates:
         *  DotProduct: '<S154>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S154>/Multiply' incorporates:
         *  Trigonometry: '<S154>/Acos'
         */
        rtb_Rem_p *= acosf(rtb_Gain_fj);

        /* Math: '<S157>/Rem' incorporates:
         *  Constant: '<S157>/Constant1'
         *  Delay: '<S153>/Delay'
         *  Sum: '<S153>/Sum2'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_Rem_p - FMS_DW.Delay_DSTATE_h,
          6.28318548F);

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
        rtb_MathFunction_f_idx_0 = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) +
          rtb_Divide_l_idx_1;

        /* Signum: '<S162>/Sign' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_MathFunction_f_idx_0;
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
        rtb_Add4_e5 = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_0) +
                              FMS_ConstB.d_j) * FMS_ConstB.d_j) - FMS_ConstB.d_j)
          * 0.5F * rtb_Add3_c + rtb_Divide_l_idx_1;

        /* Sum: '<S162>/Add4' */
        rtb_Divide_l_idx_1 += rtb_MathFunction_f_idx_0 - rtb_Add4_e5;

        /* Sum: '<S162>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + FMS_ConstB.d_j;

        /* Sum: '<S162>/Subtract1' */
        rtb_MathFunction_f_idx_0 -= FMS_ConstB.d_j;

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
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S162>/Sign2' */

        /* Sum: '<S162>/Add5' incorporates:
         *  Gain: '<S162>/Gain2'
         *  Product: '<S162>/Multiply4'
         *  Sum: '<S162>/Subtract2'
         */
        rtb_Add4_e5 += (rtb_Add3_c - rtb_MathFunction_f_idx_0) * 0.5F *
          rtb_Divide_l_idx_1;

        /* Sum: '<S162>/Subtract3' */
        rtb_Add3_c = rtb_Add4_e5 - FMS_ConstB.d_j;

        /* Sum: '<S162>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Add4_e5 + FMS_ConstB.d_j;

        /* Product: '<S162>/Divide' */
        rtb_Sqrt_b = rtb_Add4_e5 / FMS_ConstB.d_j;

        /* Signum: '<S162>/Sign5' incorporates:
         *  Signum: '<S162>/Sign6'
         */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Add4_e5;
          rtb_MathFunction_f_idx_0 = rtb_Add4_e5;
        }

        /* End of Signum: '<S162>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S153>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_p -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S158>/Rem' incorporates:
         *  Constant: '<S158>/Constant1'
         */
        rtb_Add4_e5 = rt_remf(rtb_Rem_p, 6.28318548F);

        /* Switch: '<S158>/Switch' incorporates:
         *  Abs: '<S158>/Abs'
         *  Constant: '<S158>/Constant'
         *  Constant: '<S164>/Constant'
         *  Product: '<S158>/Multiply'
         *  RelationalOperator: '<S164>/Compare'
         *  Sum: '<S158>/Add'
         */
        if (fabsf(rtb_Add4_e5) > 3.14159274F) {
          /* Signum: '<S158>/Sign' */
          if (rtb_Add4_e5 < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else if (rtb_Add4_e5 > 0.0F) {
            rtb_Gain_fj = 1.0F;
          } else {
            rtb_Gain_fj = rtb_Add4_e5;
          }

          /* End of Signum: '<S158>/Sign' */
          rtb_Add4_e5 -= 6.28318548F * rtb_Gain_fj;
        }

        /* End of Switch: '<S158>/Switch' */

        /* Abs: '<S151>/Abs' */
        rtb_Add4_e5 = fabsf(rtb_Add4_e5);

        /* Update for Delay: '<S175>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S169>/Constant'
         *  RelationalOperator: '<S169>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_Add4_e5 <= 0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
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
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Product: '<S175>/Divide1' */
        rtb_Gain_fj = rtb_MathFunction_f_idx_2 / rtb_DiscreteTimeIntegrator_n;

        /* Saturate: '<S175>/Saturation' */
        if (rtb_Gain_fj > 0.314159274F) {
          rtb_Gain_fj = 0.314159274F;
        } else {
          if (rtb_Gain_fj < -0.314159274F) {
            rtb_Gain_fj = -0.314159274F;
          }
        }

        /* End of Saturate: '<S175>/Saturation' */

        /* Update for DiscreteIntegrator: '<S223>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Gain_fj;

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
        FMS_DW.Integrator_DSTATE_i += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1) *
          FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_1 - rtb_Add3_c) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 1.04719758F) * 0.004F;
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
          rtb_Add4_e5 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Add4_e5 = 0.0F;
        } else {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
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
          rtb_Add4_e5), 65536.0F) + 1000U);

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
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
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
        switch (rtb_state_c) {
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
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S132>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S132>/Hold Control' incorporates:
           *  ActionPort: '<S135>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
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
            rtb_Add4_e5 = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S125>/Saturation' */
            rtb_Add4_e5 = 0.0F;
          } else {
            /* Saturate: '<S125>/Saturation' incorporates:
             *  Constant: '<S125>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S29>/Signal Copy2'
             *  Sum: '<S125>/Sum'
             */
            rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_Add4_e5),
            65536.0F) + 1000U);
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
        rtb_DiscreteTimeIntegrator_n = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S127>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Add4_e5 = 0.0F;
        } else {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S127>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S131>/Add' incorporates:
         *  DiscreteIntegrator: '<S129>/Integrator1'
         *  Gain: '<S123>/Gain1'
         *  Gain: '<S127>/Gain'
         *  Sum: '<S129>/Subtract'
         */
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Add4_e5 * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_DiscreteTimeIntegrator_n;

        /* Signum: '<S131>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Gain_fj;
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
        rtb_Add4_e5 = (sqrtf((8.0F * fabsf(rtb_Gain_fj) + FMS_ConstB.d_l) *
                             FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Add4_e5 + rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S131>/Add4' */
        rtb_Divide_l_idx_1 = (rtb_Gain_fj - rtb_Add4_e5) +
          rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S131>/Add3' */
        rtb_Add3_c = rtb_Gain_fj + FMS_ConstB.d_l;

        /* Sum: '<S131>/Subtract1' */
        rtb_Gain_fj -= FMS_ConstB.d_l;

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
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S131>/Sign2' */

        /* Sum: '<S131>/Add5' incorporates:
         *  Gain: '<S131>/Gain2'
         *  Product: '<S131>/Multiply4'
         *  Sum: '<S131>/Subtract2'
         */
        rtb_Add4_e5 += (rtb_Add3_c - rtb_Gain_fj) * 0.5F * rtb_Divide_l_idx_1;

        /* Sum: '<S131>/Subtract3' */
        rtb_Add3_c = rtb_Add4_e5 - FMS_ConstB.d_l;

        /* Sum: '<S131>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Add4_e5 + FMS_ConstB.d_l;

        /* Product: '<S131>/Divide' */
        rtb_Sqrt_b = rtb_Add4_e5 / FMS_ConstB.d_l;

        /* Signum: '<S131>/Sign5' incorporates:
         *  Signum: '<S131>/Sign6'
         */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Add4_e5;
          rtb_MathFunction_f_idx_0 = rtb_Add4_e5;
        }

        /* End of Signum: '<S131>/Sign5' */

        /* Product: '<S130>/Multiply1' incorporates:
         *  Constant: '<S130>/const1'
         *  DiscreteIntegrator: '<S128>/Integrator'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S126>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Add4_e5 = 0.0F;
        } else {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S126>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S130>/Add' incorporates:
         *  DiscreteIntegrator: '<S128>/Integrator1'
         *  Gain: '<S123>/Gain'
         *  Gain: '<S126>/Gain'
         *  Sum: '<S128>/Subtract'
         */
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Add4_e5 * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_DiscreteTimeIntegrator_n;

        /* Signum: '<S130>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Gain_fj;
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
        rtb_Add4_e5 = (sqrtf((8.0F * fabsf(rtb_Gain_fj) + FMS_ConstB.d_h) *
                             FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F *
          rtb_Add4_e5 + rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S130>/Add4' */
        rtb_MathFunction_f_idx_2 = (rtb_Gain_fj - rtb_Add4_e5) +
          rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S130>/Add3' */
        rtb_DiscreteTimeIntegrator_n = rtb_Gain_fj + FMS_ConstB.d_h;

        /* Sum: '<S130>/Subtract1' */
        rtb_Gain_fj -= FMS_ConstB.d_h;

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
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S130>/Sign2' */

        /* Sum: '<S130>/Add5' incorporates:
         *  Gain: '<S130>/Gain2'
         *  Product: '<S130>/Multiply4'
         *  Sum: '<S130>/Subtract2'
         */
        rtb_Add4_e5 += (rtb_DiscreteTimeIntegrator_n - rtb_Gain_fj) * 0.5F *
          rtb_MathFunction_f_idx_2;

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
        FMS_DW.Integrator_DSTATE_a += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1) *
          FMS_ConstB.Gain4_j * ((rtb_Divide_l_idx_1 - rtb_Add3_c) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 12.566371F) * 0.004F;

        /* Sum: '<S130>/Add6' */
        rtb_Add3_c = rtb_Add4_e5 + FMS_ConstB.d_h;

        /* Sum: '<S130>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_Add4_e5 - FMS_ConstB.d_h;

        /* Signum: '<S130>/Sign5' */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Add4_e5;
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
        if (rtb_Add4_e5 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Add4_e5;
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
        FMS_DW.Integrator_DSTATE_c += ((rtb_Add4_e5 / FMS_ConstB.d_h -
          rtb_DiscreteTimeIntegrator_n) * FMS_ConstB.Gain4_n * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_MathFunction_f_idx_0 * 12.566371F) *
          0.004F;

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
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S49>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
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
            /* SystemReset for IfAction SubSystem: '<S67>/Hold Control' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S67>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S67>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S67>/Hold Control' incorporates:
           *  ActionPort: '<S70>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
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
        rtb_DiscreteTimeIntegrator_n = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S62>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Add4_e5 = 0.0F;
        } else {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S62>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S66>/Add' incorporates:
         *  DiscreteIntegrator: '<S64>/Integrator1'
         *  Gain: '<S47>/Gain1'
         *  Gain: '<S62>/Gain'
         *  Sum: '<S64>/Subtract'
         */
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Add4_e5 * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_DiscreteTimeIntegrator_n;

        /* Signum: '<S66>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Gain_fj;
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
        rtb_Add4_e5 = (sqrtf((8.0F * fabsf(rtb_Gain_fj) + FMS_ConstB.d) *
                             FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add4_e5
          + rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S66>/Add4' */
        rtb_Divide_l_idx_1 = (rtb_Gain_fj - rtb_Add4_e5) +
          rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S66>/Add3' */
        rtb_Add3_c = rtb_Gain_fj + FMS_ConstB.d;

        /* Sum: '<S66>/Subtract1' */
        rtb_Gain_fj -= FMS_ConstB.d;

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
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S66>/Sign2' */

        /* Sum: '<S66>/Add5' incorporates:
         *  Gain: '<S66>/Gain2'
         *  Product: '<S66>/Multiply4'
         *  Sum: '<S66>/Subtract2'
         */
        rtb_Add4_e5 += (rtb_Add3_c - rtb_Gain_fj) * 0.5F * rtb_Divide_l_idx_1;

        /* Sum: '<S66>/Subtract3' */
        rtb_Add3_c = rtb_Add4_e5 - FMS_ConstB.d;

        /* Sum: '<S66>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Add4_e5 + FMS_ConstB.d;

        /* Product: '<S66>/Divide' */
        rtb_Sqrt_b = rtb_Add4_e5 / FMS_ConstB.d;

        /* Signum: '<S66>/Sign5' incorporates:
         *  Signum: '<S66>/Sign6'
         */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Add4_e5;
          rtb_MathFunction_f_idx_0 = rtb_Add4_e5;
        }

        /* End of Signum: '<S66>/Sign5' */

        /* Product: '<S65>/Multiply1' incorporates:
         *  Constant: '<S65>/const1'
         *  DiscreteIntegrator: '<S63>/Integrator'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S61>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Add4_e5 = 0.0F;
        } else {
          rtb_Add4_e5 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S61>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S65>/Add' incorporates:
         *  DiscreteIntegrator: '<S63>/Integrator1'
         *  Gain: '<S47>/Gain'
         *  Gain: '<S61>/Gain'
         *  Sum: '<S63>/Subtract'
         */
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Add4_e5 * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_DiscreteTimeIntegrator_n;

        /* Signum: '<S65>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Add4_e5 = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_Add4_e5 = 1.0F;
        } else {
          rtb_Add4_e5 = rtb_Gain_fj;
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
        rtb_Add4_e5 = (sqrtf((8.0F * fabsf(rtb_Gain_fj) + FMS_ConstB.d_e) *
                             FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F *
          rtb_Add4_e5 + rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S65>/Add4' */
        rtb_MathFunction_f_idx_2 = (rtb_Gain_fj - rtb_Add4_e5) +
          rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S65>/Add3' */
        rtb_DiscreteTimeIntegrator_n = rtb_Gain_fj + FMS_ConstB.d_e;

        /* Sum: '<S65>/Subtract1' */
        rtb_Gain_fj -= FMS_ConstB.d_e;

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
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign2' */

        /* Sum: '<S65>/Add5' incorporates:
         *  Gain: '<S65>/Gain2'
         *  Product: '<S65>/Multiply4'
         *  Sum: '<S65>/Subtract2'
         */
        rtb_Add4_e5 += (rtb_DiscreteTimeIntegrator_n - rtb_Gain_fj) * 0.5F *
          rtb_MathFunction_f_idx_2;

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
        FMS_DW.Integrator_DSTATE += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1) *
          FMS_ConstB.Gain4 * ((rtb_Divide_l_idx_1 - rtb_Add3_c) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 12.566371F) * 0.004F;

        /* Sum: '<S65>/Add6' */
        rtb_Add3_c = rtb_Add4_e5 + FMS_ConstB.d_e;

        /* Sum: '<S65>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_Add4_e5 - FMS_ConstB.d_e;

        /* Signum: '<S65>/Sign5' */
        if (rtb_Add4_e5 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Add4_e5;
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
        if (rtb_Add4_e5 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Add4_e5 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Add4_e5;
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
        FMS_DW.Integrator_DSTATE_b += ((rtb_Add4_e5 / FMS_ConstB.d_e -
          rtb_DiscreteTimeIntegrator_n) * FMS_ConstB.Gain4_d * ((rtb_Add3_c -
          rtb_Divide_l_idx_1) * 0.5F) - rtb_MathFunction_f_idx_0 * 12.566371F) *
          0.004F;

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
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_i);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S83>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_o;
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
        switch (rtb_state_c) {
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
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
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
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S108>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S108>/Hold Control' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S108>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S108>/Brake Control' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S108>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S108>/Move Control' incorporates:
             *  ActionPort: '<S112>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S108>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S108>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S108>/Move Control' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
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
        switch (rtb_state_c) {
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
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S95>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S95>/Hold Control' incorporates:
           *  ActionPort: '<S98>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
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
   *  DiscreteIntegrator: '<S511>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S511>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S511>/Constant'
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

  /* Update for DiscreteIntegrator: '<S526>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S526>/Gain'
   *  Sum: '<S526>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S528>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S528>/Gain'
   *  Sum: '<S528>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S527>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S527>/Gain'
   *  Sum: '<S527>/Sum5'
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
  rtb_Add4_e5 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Add4_e5 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Add4_e5;
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
  rtb_Add4_e5 = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Add4_e5 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Add4_e5;
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
  /* Start for SwitchCase: '<S469>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S459>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S37>/Return' */

  /* Start for IfAction SubSystem: '<S37>/Hold' */
  /* Start for SwitchCase: '<S362>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S340>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S350>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S37>/Hold' */
  /* End of Start for SubSystem: '<S30>/SubMode' */

  /* Start for IfAction SubSystem: '<S30>/Auto' */
  /* Start for SwitchCase: '<S35>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S35>/Mission' */
  /* Start for Resettable SubSystem: '<S145>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S196>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S186>/Switch Case' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S526>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S528>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S527>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S509>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S505>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S505>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S378>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S378>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Return' */
  /* InitializeConditions for Delay: '<S448>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S444>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S496>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;

  /* InitializeConditions for Delay: '<S388>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S391>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S387>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S391>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S470>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S469>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S469>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S469>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S469>/Move Control' */

  /* SystemInitialize for Merge: '<S469>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S460>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S459>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S459>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S459>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S459>/Move Control' */

  /* SystemInitialize for Merge: '<S459>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold' */
  /* SystemInitialize for Chart: '<S341>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S351>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S363>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S362>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S362>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S362>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S362>/Move Control' */

  /* SystemInitialize for Merge: '<S362>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S340>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S340>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S340>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S340>/Move Control' */

  /* SystemInitialize for Merge: '<S340>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S350>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S350>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S350>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S350>/Move Control' */

  /* SystemInitialize for Merge: '<S350>/Merge' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S223>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S153>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S197>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S196>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S196>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S196>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S196>/Move Control' */

  /* SystemInitialize for Merge: '<S196>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S187>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S186>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S186>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S186>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S186>/Move Control' */

  /* SystemInitialize for Merge: '<S186>/Merge' */
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
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h);

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
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_o);

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
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S108>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S108>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S108>/Move Control' */

  /* SystemInitialize for Merge: '<S108>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S83>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S95>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_e);

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
