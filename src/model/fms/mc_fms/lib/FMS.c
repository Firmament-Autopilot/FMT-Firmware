/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2325
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul 31 19:45:37 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S434>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S444>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S139>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o4                 ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S52>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S366>/Motion State' */
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
#define FMS_IN_Manual_b                ((uint8_T)3U)
#define FMS_IN_Mission_c               ((uint8_T)4U)
#define FMS_IN_Offboard_h              ((uint8_T)5U)
#define FMS_IN_Position_k              ((uint8_T)6U)
#define FMS_IN_Stabilize_k             ((uint8_T)7U)
#define FMS_IN_Unknown                 ((uint8_T)8U)

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
  0U,                                  /* ext_state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* mode */
  0U,                                  /* reset */
  0U,                                  /* wp_consume */
  0U,                                  /* wp_current */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* home */
  0U                                   /* error */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_5TTS1Nsavpy7t3kKdfSkeF FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  1.2F,
  1.5F,
  5.0F,
  1.5F,
  2.5F,
  1.57079601F,
  0.523599F,
  2.0F,
  5.0F,
  5.0F,
  1.2F,
  1.0F,
  0.5F,
  0.7F,
  0.6F,
  120U,
  1U,
  1300U,
  0.8F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S7>/Land_Lock_Thro'
                                        *   '<S28>/Constant'
                                        *   '<S497>/Constant'
                                        *   '<S49>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S126>/Gain'
                                        *   '<S126>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S242>/Saturation'
                                        *   '<S243>/Saturation1'
                                        *   '<S243>/Saturation2'
                                        *   '<S243>/Saturation3'
                                        *   '<S390>/Land_Speed'
                                        *   '<S391>/Saturation1'
                                        *   '<S400>/Gain'
                                        *   '<S484>/Takeoff_Speed'
                                        *   '<S485>/Gain2'
                                        *   '<S485>/Saturation1'
                                        *   '<S51>/Saturation1'
                                        *   '<S63>/Dead Zone'
                                        *   '<S63>/Gain'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S65>/Constant'
                                        *   '<S66>/Constant'
                                        *   '<S71>/Saturation'
                                        *   '<S86>/Saturation1'
                                        *   '<S97>/Saturation'
                                        *   '<S109>/Saturation1'
                                        *   '<S130>/Dead Zone'
                                        *   '<S130>/Gain'
                                        *   '<S131>/Dead Zone'
                                        *   '<S131>/Gain'
                                        *   '<S132>/Constant'
                                        *   '<S133>/Constant'
                                        *   '<S138>/Saturation'
                                        *   '<S156>/Gain'
                                        *   '<S298>/Gain2'
                                        *   '<S305>/Gain1'
                                        *   '<S305>/Gain2'
                                        *   '<S355>/Saturation1'
                                        *   '<S365>/Saturation'
                                        *   '<S377>/Saturation1'
                                        *   '<S392>/Constant'
                                        *   '<S395>/Gain2'
                                        *   '<S417>/Gain'
                                        *   '<S417>/Saturation1'
                                        *   '<S420>/vel'
                                        *   '<S425>/Constant'
                                        *   '<S425>/L1_GAIN'
                                        *   '<S53>/Gain2'
                                        *   '<S54>/Gain1'
                                        *   '<S60>/Constant'
                                        *   '<S73>/Gain2'
                                        *   '<S74>/Gain1'
                                        *   '<S81>/Constant'
                                        *   '<S88>/Gain2'
                                        *   '<S89>/Gain1'
                                        *   '<S95>/Constant'
                                        *   '<S99>/Gain2'
                                        *   '<S100>/Gain1'
                                        *   '<S107>/Constant'
                                        *   '<S111>/Gain2'
                                        *   '<S112>/Gain6'
                                        *   '<S123>/Constant'
                                        *   '<S124>/Constant'
                                        *   '<S140>/Gain2'
                                        *   '<S141>/Gain1'
                                        *   '<S148>/Constant'
                                        *   '<S173>/Gain'
                                        *   '<S173>/Saturation1'
                                        *   '<S176>/vel'
                                        *   '<S181>/Constant'
                                        *   '<S181>/L1_GAIN'
                                        *   '<S358>/Gain2'
                                        *   '<S359>/Gain1'
                                        *   '<S368>/Gain2'
                                        *   '<S369>/Gain1'
                                        *   '<S380>/Gain2'
                                        *   '<S381>/Gain6'
                                        *   '<S404>/Gain2'
                                        *   '<S404>/Saturation'
                                        *   '<S405>/Integrator'
                                        *   '<S56>/Land_Speed'
                                        *   '<S57>/Constant'
                                        *   '<S59>/Dead Zone'
                                        *   '<S59>/Gain'
                                        *   '<S78>/Dead Zone'
                                        *   '<S78>/Gain'
                                        *   '<S91>/Land_Speed'
                                        *   '<S92>/Constant'
                                        *   '<S94>/Dead Zone'
                                        *   '<S94>/Gain'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S117>/Dead Zone'
                                        *   '<S117>/Gain'
                                        *   '<S118>/Dead Zone'
                                        *   '<S118>/Gain'
                                        *   '<S119>/Constant'
                                        *   '<S145>/Dead Zone'
                                        *   '<S145>/Gain'
                                        *   '<S160>/Gain2'
                                        *   '<S160>/Saturation'
                                        *   '<S161>/Integrator'
                                        *   '<S361>/Dead Zone'
                                        *   '<S361>/Gain'
                                        *   '<S373>/Dead Zone'
                                        *   '<S373>/Gain'
                                        *   '<S385>/Dead Zone'
                                        *   '<S385>/Gain'
                                        *   '<S386>/Dead Zone'
                                        *   '<S386>/Gain'
                                        *   '<S433>/Saturation1'
                                        *   '<S443>/Saturation1'
                                        *   '<S189>/Saturation1'
                                        *   '<S199>/Saturation1'
                                        *   '<S436>/Gain2'
                                        *   '<S437>/Gain1'
                                        *   '<S446>/Gain2'
                                        *   '<S447>/Gain6'
                                        *   '<S192>/Gain2'
                                        *   '<S193>/Gain1'
                                        *   '<S202>/Gain2'
                                        *   '<S203>/Gain6'
                                        *   '<S439>/Dead Zone'
                                        *   '<S439>/Gain'
                                        *   '<S451>/Dead Zone'
                                        *   '<S451>/Gain'
                                        *   '<S452>/Dead Zone'
                                        *   '<S452>/Gain'
                                        *   '<S195>/Dead Zone'
                                        *   '<S195>/Gain'
                                        *   '<S207>/Dead Zone'
                                        *   '<S207>/Gain'
                                        *   '<S208>/Dead Zone'
                                        *   '<S208>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 77, 67, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S13>/Constant1'
                                        *   '<S495>/Constant'
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
static void FMS_Mode(void);
static void FMS_enter_internal_c1_FMS(void);
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_CheckCmdValid(FMS_Cmd cmd_in, PilotMode mode_in, uint32_T
  ins_flag, uint32_T error);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_Mission(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
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
 *    '<S433>/Hold Control'
 *    '<S355>/Hold Control'
 *    '<S189>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S436>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S433>/Hold Control'
 *    '<S355>/Hold Control'
 *    '<S189>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S436>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S433>/Hold Control'
 *    '<S355>/Hold Control'
 *    '<S189>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S436>/Delay' incorporates:
   *  Gain: '<S438>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S436>/Gain2' incorporates:
   *  Delay: '<S436>/Delay'
   *  Gain: '<S438>/Gain'
   *  Sum: '<S436>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S436>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S433>/Brake Control'
 *    '<S355>/Brake Control'
 *    '<S365>/Brake Control'
 *    '<S189>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S435>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S435>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S433>/Move Control'
 *    '<S355>/Move Control'
 *    '<S189>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S440>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S440>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S433>/Move Control'
 *    '<S355>/Move Control'
 *    '<S189>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S440>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S440>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S433>/Move Control'
 *    '<S355>/Move Control'
 *    '<S189>/Move Control'
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

  /* Product: '<S441>/Multiply1' incorporates:
   *  Constant: '<S441>/const1'
   *  DiscreteIntegrator: '<S440>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S439>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S439>/Dead Zone' */

  /* Sum: '<S441>/Add' incorporates:
   *  DiscreteIntegrator: '<S440>/Integrator1'
   *  Gain: '<S437>/Gain1'
   *  Gain: '<S439>/Gain'
   *  Sum: '<S440>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S441>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S441>/Sign' */

  /* Sum: '<S441>/Add2' incorporates:
   *  Abs: '<S441>/Abs'
   *  Gain: '<S441>/Gain'
   *  Gain: '<S441>/Gain1'
   *  Product: '<S441>/Multiply2'
   *  Product: '<S441>/Multiply3'
   *  Sqrt: '<S441>/Sqrt'
   *  Sum: '<S441>/Add1'
   *  Sum: '<S441>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S441>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S441>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S441>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S441>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S441>/Sign1' */

  /* Signum: '<S441>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S441>/Sign2' */

  /* Sum: '<S441>/Add5' incorporates:
   *  Gain: '<S441>/Gain2'
   *  Product: '<S441>/Multiply4'
   *  Sum: '<S441>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S437>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S440>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S440>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S440>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S441>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S441>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S441>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S441>/Sign5' */

  /* Signum: '<S441>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S441>/Sign3' */

  /* Signum: '<S441>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S441>/Sign4' */

  /* Signum: '<S441>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S441>/Sign6' */

  /* Update for DiscreteIntegrator: '<S440>/Integrator' incorporates:
   *  Constant: '<S441>/const'
   *  Gain: '<S441>/Gain3'
   *  Product: '<S441>/Divide'
   *  Product: '<S441>/Multiply5'
   *  Product: '<S441>/Multiply6'
   *  Sum: '<S441>/Subtract4'
   *  Sum: '<S441>/Subtract5'
   *  Sum: '<S441>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S434>/Motion Status'
 *    '<S356>/Motion Status'
 *    '<S190>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S434>/Motion Status'
 *    '<S356>/Motion Status'
 *    '<S190>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S434>/Motion Status'
 *    '<S356>/Motion Status'
 *    '<S190>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S434>/Motion Status' */
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

  /* End of Chart: '<S434>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S443>/Hold Control'
 *    '<S377>/Hold Control'
 *    '<S199>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S446>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S443>/Hold Control'
 *    '<S377>/Hold Control'
 *    '<S199>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S446>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S443>/Hold Control'
 *    '<S377>/Hold Control'
 *    '<S199>/Hold Control'
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

  /* Delay: '<S446>/Delay' incorporates:
   *  SignalConversion: '<S446>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S450>/Trigonometric Function1' incorporates:
   *  Gain: '<S449>/Gain'
   *  Trigonometry: '<S450>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S450>/Trigonometric Function' incorporates:
   *  Gain: '<S449>/Gain'
   *  Trigonometry: '<S450>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S450>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S450>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S450>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S450>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S450>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S450>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S450>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S446>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S446>/Delay'
   *  SignalConversion: '<S446>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S446>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S446>/Multiply' incorporates:
   *  SignalConversion: '<S446>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S446>/Multiply' */

  /* Gain: '<S446>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S446>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S443>/Brake Control'
 *    '<S377>/Brake Control'
 *    '<S199>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S445>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S443>/Move Control'
 *    '<S377>/Move Control'
 *    '<S199>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S443>/Move Control'
 *    '<S377>/Move Control'
 *    '<S199>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S443>/Move Control'
 *    '<S377>/Move Control'
 *    '<S199>/Move Control'
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

  /* SignalConversion: '<S447>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S453>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S454>/Multiply1' incorporates:
   *  Constant: '<S454>/const1'
   *  DiscreteIntegrator: '<S453>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S447>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S453>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S454>/Multiply1' incorporates:
   *  Constant: '<S454>/const1'
   *  DiscreteIntegrator: '<S453>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S451>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S451>/Dead Zone' */

  /* Sum: '<S454>/Add' incorporates:
   *  DiscreteIntegrator: '<S453>/Integrator1'
   *  Gain: '<S447>/Gain6'
   *  Gain: '<S451>/Gain'
   *  Sum: '<S453>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S452>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S452>/Dead Zone' */

  /* Sum: '<S454>/Add' incorporates:
   *  DiscreteIntegrator: '<S453>/Integrator1'
   *  Gain: '<S447>/Gain6'
   *  Gain: '<S452>/Gain'
   *  Sum: '<S453>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S454>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S454>/Add2' incorporates:
   *  Abs: '<S454>/Abs'
   *  Gain: '<S454>/Gain'
   *  Gain: '<S454>/Gain1'
   *  Product: '<S454>/Multiply2'
   *  Product: '<S454>/Multiply3'
   *  Signum: '<S454>/Sign'
   *  Sqrt: '<S454>/Sqrt'
   *  Sum: '<S454>/Add1'
   *  Sum: '<S454>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S454>/Add3' incorporates:
   *  Signum: '<S454>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S454>/Subtract1' incorporates:
   *  Signum: '<S454>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S454>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S454>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S454>/Add5' incorporates:
   *  Gain: '<S454>/Gain2'
   *  Product: '<S454>/Multiply4'
   *  Signum: '<S454>/Sign'
   *  Sum: '<S454>/Add2'
   *  Sum: '<S454>/Add4'
   *  Sum: '<S454>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S453>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S453>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S454>/Sign3' incorporates:
   *  Sum: '<S454>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S454>/Sign4' incorporates:
   *  Sum: '<S454>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S454>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S454>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S454>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S454>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S453>/Integrator' incorporates:
   *  Constant: '<S454>/const'
   *  Gain: '<S454>/Gain3'
   *  Product: '<S454>/Divide'
   *  Product: '<S454>/Multiply5'
   *  Product: '<S454>/Multiply6'
   *  Sum: '<S454>/Subtract4'
   *  Sum: '<S454>/Subtract5'
   *  Sum: '<S454>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S454>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S454>/Add2' incorporates:
   *  Abs: '<S454>/Abs'
   *  Gain: '<S454>/Gain'
   *  Gain: '<S454>/Gain1'
   *  Product: '<S454>/Multiply2'
   *  Product: '<S454>/Multiply3'
   *  Signum: '<S454>/Sign'
   *  Sqrt: '<S454>/Sqrt'
   *  Sum: '<S454>/Add1'
   *  Sum: '<S454>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S454>/Add3' incorporates:
   *  Signum: '<S454>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S454>/Subtract1' incorporates:
   *  Signum: '<S454>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S454>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S454>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S454>/Add5' incorporates:
   *  Gain: '<S454>/Gain2'
   *  Product: '<S454>/Multiply4'
   *  Signum: '<S454>/Sign'
   *  Sum: '<S454>/Add2'
   *  Sum: '<S454>/Add4'
   *  Sum: '<S454>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S453>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S453>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S454>/Sign3' incorporates:
   *  Sum: '<S454>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S454>/Sign4' incorporates:
   *  Sum: '<S454>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S454>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S454>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S454>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S454>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S453>/Integrator' incorporates:
   *  Constant: '<S454>/const'
   *  Gain: '<S454>/Gain3'
   *  Product: '<S454>/Divide'
   *  Product: '<S454>/Multiply5'
   *  Product: '<S454>/Multiply6'
   *  Sum: '<S454>/Subtract4'
   *  Sum: '<S454>/Subtract5'
   *  Sum: '<S454>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S444>/Motion State'
 *    '<S378>/Motion State'
 *    '<S200>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S444>/Motion State'
 *    '<S378>/Motion State'
 *    '<S200>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S444>/Motion State'
 *    '<S378>/Motion State'
 *    '<S200>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S444>/Motion State' */
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

  /* End of Chart: '<S444>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S422>/NearbyRefWP'
 *    '<S178>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S458>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S365>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S368>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S365>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S368>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S365>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_nb;

  /* Delay: '<S368>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S368>/Sum' incorporates:
   *  Delay: '<S368>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S371>/Abs' */
  rtb_Abs_nb = fabsf(rtb_psi_error_rad);

  /* Switch: '<S371>/Switch' incorporates:
   *  Constant: '<S371>/Constant'
   *  Constant: '<S372>/Constant'
   *  Product: '<S371>/Multiply'
   *  RelationalOperator: '<S372>/Compare'
   *  Sum: '<S371>/Subtract'
   */
  if (rtb_Abs_nb > 3.14159274F) {
    /* Signum: '<S371>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S371>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_nb - 6.28318548F;
  }

  /* End of Switch: '<S371>/Switch' */

  /* Gain: '<S368>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S368>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S365>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S374>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S374>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S365>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S374>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S374>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S365>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_ig;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_b;
  real32_T rtb_a_p4;

  /* Product: '<S375>/Multiply1' incorporates:
   *  Constant: '<S375>/const1'
   *  DiscreteIntegrator: '<S374>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S373>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S373>/Dead Zone' */

  /* Sum: '<S375>/Add' incorporates:
   *  DiscreteIntegrator: '<S374>/Integrator1'
   *  Gain: '<S369>/Gain1'
   *  Gain: '<S373>/Gain'
   *  Sum: '<S374>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S375>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S375>/Sign' */

  /* Sum: '<S375>/Add2' incorporates:
   *  Abs: '<S375>/Abs'
   *  Gain: '<S375>/Gain'
   *  Gain: '<S375>/Gain1'
   *  Product: '<S375>/Multiply2'
   *  Product: '<S375>/Multiply3'
   *  Sqrt: '<S375>/Sqrt'
   *  Sum: '<S375>/Add1'
   *  Sum: '<S375>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S375>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S375>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S375>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S375>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S375>/Sign1' */

  /* Signum: '<S375>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S375>/Sign2' */

  /* Sum: '<S375>/Add5' incorporates:
   *  Gain: '<S375>/Gain2'
   *  Product: '<S375>/Multiply4'
   *  Sum: '<S375>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S369>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S374>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S374>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S374>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S375>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S375>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S375>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S375>/Sign5' */

  /* Signum: '<S375>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S375>/Sign3' */

  /* Signum: '<S375>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S375>/Sign4' */

  /* Signum: '<S375>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S375>/Sign6' */

  /* Update for DiscreteIntegrator: '<S374>/Integrator' incorporates:
   *  Constant: '<S375>/const'
   *  Gain: '<S375>/Gain3'
   *  Product: '<S375>/Divide'
   *  Product: '<S375>/Multiply5'
   *  Product: '<S375>/Multiply6'
   *  Sum: '<S375>/Subtract4'
   *  Sum: '<S375>/Subtract5'
   *  Sum: '<S375>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_b) *
    localC->Gain4 * ((rtb_Add3_ig - rtb_Subtract3_l) * 0.5F) - rtb_a_p4 *
    15.707963F) * 0.004F;
}

/*
 * Output and update for action system:
 *    '<S39>/Unknown'
 *    '<S37>/Unknown'
 *    '<S36>/Unknown'
 *    '<S32>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S351>/Bus Assignment' incorporates:
   *  Constant: '<S351>/Constant'
   *  Constant: '<S351>/Constant2'
   *  SignalConversion: '<S351>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S351>/Bus Assignment' */
}

/*
 * System initialize for atomic system:
 *    '<S139>/Motion State'
 *    '<S72>/Motion State'
 *    '<S98>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S139>/Motion State'
 *    '<S72>/Motion State'
 *    '<S98>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S139>/Motion State'
 *    '<S72>/Motion State'
 *    '<S98>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S139>/Motion State' */
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

  /* End of Chart: '<S139>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S51>/Move Control'
 *    '<S86>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l, uint32_T
  rtu_FMS_In_i, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_j;

  /* DeadZone: '<S59>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_j = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_j = 0.0F;
  } else {
    rtb_Gain1_j = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S59>/Dead Zone' */

  /* Gain: '<S54>/Gain1' incorporates:
   *  Gain: '<S59>/Gain'
   */
  rtb_Gain1_j = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_j *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S56>/Land_Speed'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S58>/Constant'
   *  Gain: '<S56>/Gain'
   *  Logic: '<S54>/Logical Operator'
   *  MinMax: '<S56>/Min'
   *  RelationalOperator: '<S57>/Compare'
   *  RelationalOperator: '<S58>/Compare'
   *  S-Function (sfix_bitop): '<S54>/cmd_p valid'
   */
  if ((rtb_Gain1_j > 0.0F) && ((rtu_FMS_In_i & 256U) != 0U) && (rtu_FMS_In_l <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_j);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_j;
  }

  /* End of Switch: '<S54>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S52>/Motion Status'
 *    '<S87>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S52>/Motion Status'
 *    '<S87>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S52>/Motion Status'
 *    '<S87>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S52>/Motion Status' */
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

  /* End of Chart: '<S52>/Motion Status' */
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

/* Output and update for function-call system: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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

  /* Gain: '<S499>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S500>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S500>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S500>/Multiply1' incorporates:
   *  Product: '<S500>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S500>/Divide' incorporates:
   *  Constant: '<S500>/Constant'
   *  Constant: '<S500>/R'
   *  Sqrt: '<S500>/Sqrt'
   *  Sum: '<S500>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S500>/Product3' incorporates:
   *  Constant: '<S500>/Constant1'
   *  Product: '<S500>/Multiply1'
   *  Sum: '<S500>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S500>/Multiply2' incorporates:
   *  Trigonometry: '<S500>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S499>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S504>/Abs' incorporates:
   *  Abs: '<S507>/Abs1'
   *  Switch: '<S504>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S504>/Switch1' incorporates:
   *  Abs: '<S504>/Abs'
   *  Bias: '<S504>/Bias2'
   *  Bias: '<S504>/Bias3'
   *  Constant: '<S501>/Constant'
   *  Constant: '<S501>/Constant1'
   *  Constant: '<S506>/Constant'
   *  Gain: '<S504>/Gain1'
   *  Product: '<S504>/Multiply'
   *  RelationalOperator: '<S506>/Compare'
   *  Switch: '<S501>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S507>/Switch1' incorporates:
     *  Bias: '<S507>/Bias2'
     *  Bias: '<S507>/Bias3'
     *  Constant: '<S507>/Constant'
     *  Constant: '<S508>/Constant'
     *  Math: '<S507>/Math Function'
     *  RelationalOperator: '<S508>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S507>/Switch1' */

    /* Signum: '<S504>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S504>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S501>/Sum' incorporates:
   *  Sum: '<S499>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S499>/Multiply' incorporates:
   *  Gain: '<S499>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S503>/Switch1' incorporates:
   *  Abs: '<S503>/Abs1'
   *  Bias: '<S503>/Bias2'
   *  Bias: '<S503>/Bias3'
   *  Constant: '<S503>/Constant'
   *  Constant: '<S505>/Constant'
   *  Math: '<S503>/Math Function'
   *  RelationalOperator: '<S505>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S503>/Switch1' */

  /* Product: '<S499>/Multiply' incorporates:
   *  Gain: '<S499>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S499>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S502>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S502>/Sum2' incorporates:
   *  Product: '<S502>/Multiply1'
   *  Product: '<S502>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S502>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S502>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S502>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S496>/Data Type Conversion' incorporates:
   *  Gain: '<S499>/Gain'
   *  Sum: '<S499>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_ee;
  rty_pos[1] = (real32_T)rtb_Sum3_l;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Mode(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;

  /* Delay: '<S15>/Delay' */
  if (((FMS_DW.mode_prev != FMS_DW.mode_start) || (FMS_DW.flag_prev !=
        FMS_DW.flag_start)) && (FMS_DW.Delay_DSTATE_cn != PilotMode_None)) {
    FMS_B.degrade = 0.0;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    if (FMS_DW.Delay_DSTATE_cn == PilotMode_Offboard) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_DW.is_Mode = FMS_IN_Offboard_h;
        FMS_B.target_mode = PilotMode_Offboard;
      } else {
        FMS_B.degrade = 1.0;
        guard6 = true;
      }
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Mission) {
      guard6 = true;
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Position) {
      guard5 = true;
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Altitude) {
      guard4 = true;
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Stabilize) {
      guard3 = true;
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Acro) {
      guard2 = true;
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Manual) {
      guard1 = true;
    } else {
      FMS_DW.is_Mode = FMS_IN_Unknown;
      FMS_B.target_mode = PilotMode_None;
    }

    if (guard6) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 32U) != 0U) && ((FMS_U.INS_Out.flag & 64U)
           != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_DW.is_Mode = FMS_IN_Mission_c;
        FMS_B.target_mode = PilotMode_Mission;
      } else {
        FMS_B.degrade = 1.0;
        guard5 = true;
      }
    }

    if (guard5) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_DW.is_Mode = FMS_IN_Position_k;
        FMS_B.target_mode = PilotMode_Position;
      } else {
        FMS_B.degrade = 1.0;
        guard4 = true;
      }
    }

    if (guard4) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_DW.is_Mode = FMS_IN_Altitude;
        FMS_B.target_mode = PilotMode_Altitude;
      } else {
        FMS_B.degrade = 1.0;
        guard3 = true;
      }
    }

    if (guard3) {
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_DW.is_Mode = FMS_IN_Stabilize_k;
        FMS_B.target_mode = PilotMode_Stabilize;
      } else {
        FMS_B.degrade = 1.0;
        guard2 = true;
      }
    }

    if (guard2) {
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_DW.is_Mode = FMS_IN_Acro;
        FMS_B.target_mode = PilotMode_Acro;
      } else {
        FMS_B.degrade = 1.0;
        guard1 = true;
      }
    }

    if (guard1) {
      FMS_DW.is_Mode = FMS_IN_Manual_b;
      FMS_B.target_mode = PilotMode_Manual;
    }
  } else {
    switch (FMS_DW.is_Mode) {
     case FMS_IN_Acro:
      FMS_B.target_mode = PilotMode_Acro;
      break;

     case FMS_IN_Altitude:
      FMS_B.target_mode = PilotMode_Altitude;
      break;

     case FMS_IN_Manual_b:
      FMS_B.target_mode = PilotMode_Manual;
      break;

     case FMS_IN_Mission_c:
      FMS_B.target_mode = PilotMode_Mission;
      break;

     case FMS_IN_Offboard_h:
      FMS_B.target_mode = PilotMode_Offboard;
      break;

     case FMS_IN_Position_k:
      FMS_B.target_mode = PilotMode_Position;
      break;

     case FMS_IN_Stabilize_k:
      FMS_B.target_mode = PilotMode_Stabilize;
      break;

     default:
      FMS_B.target_mode = PilotMode_None;
      break;
    }
  }

  /* End of Delay: '<S15>/Delay' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_enter_internal_c1_FMS(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  FMS_B.degrade = 0.0;

  /* Delay: '<S15>/Delay' */
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  if (FMS_DW.Delay_DSTATE_cn == PilotMode_Offboard) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
    {
      FMS_DW.is_Mode = FMS_IN_Offboard_h;
      FMS_B.target_mode = PilotMode_Offboard;
    } else {
      FMS_B.degrade = 1.0;
      guard6 = true;
    }
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Mission) {
    guard6 = true;
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Position) {
    guard5 = true;
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Altitude) {
    guard4 = true;
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Stabilize) {
    guard3 = true;
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Acro) {
    guard2 = true;
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Manual) {
    guard1 = true;
  } else {
    FMS_DW.is_Mode = FMS_IN_Unknown;
    FMS_B.target_mode = PilotMode_None;
  }

  if (guard6) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 32U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
        && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
      FMS_DW.is_Mode = FMS_IN_Mission_c;
      FMS_B.target_mode = PilotMode_Mission;
    } else {
      FMS_B.degrade = 1.0;
      guard5 = true;
    }
  }

  if (guard5) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
    {
      FMS_DW.is_Mode = FMS_IN_Position_k;
      FMS_B.target_mode = PilotMode_Position;
    } else {
      FMS_B.degrade = 1.0;
      guard4 = true;
    }
  }

  if (guard4) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
    {
      FMS_DW.is_Mode = FMS_IN_Altitude;
      FMS_B.target_mode = PilotMode_Altitude;
    } else {
      FMS_B.degrade = 1.0;
      guard3 = true;
    }
  }

  if (guard3) {
    if ((FMS_U.INS_Out.flag & 4U) != 0U) {
      FMS_DW.is_Mode = FMS_IN_Stabilize_k;
      FMS_B.target_mode = PilotMode_Stabilize;
    } else {
      FMS_B.degrade = 1.0;
      guard2 = true;
    }
  }

  if (guard2) {
    if ((FMS_U.INS_Out.flag & 4U) != 0U) {
      FMS_DW.is_Mode = FMS_IN_Acro;
      FMS_B.target_mode = PilotMode_Acro;
    } else {
      FMS_B.degrade = 1.0;
      guard1 = true;
    }
  }

  if (guard1) {
    FMS_DW.is_Mode = FMS_IN_Manual_b;
    FMS_B.target_mode = PilotMode_Manual;
  }

  /* End of Delay: '<S15>/Delay' */
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
  ins_flag, uint32_T error)
{
  boolean_T valid;
  valid = false;
  switch (cmd_in) {
   case FMS_Cmd_Takeoff:
   case FMS_Cmd_Land:
   case FMS_Cmd_Return:
   case FMS_Cmd_Pause:
    if (((ins_flag & 1U) != 0U) && ((ins_flag & 4U) != 0U) && ((ins_flag & 8U)
         != 0U)) {
      if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag &
            128U) != 0U)) {
        valid = true;
      }

      if ((cmd_in == FMS_Cmd_Takeoff) && (error != 0U)) {
        valid = false;
      }
    }
    break;

   case FMS_Cmd_PreArm:
    if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag & 8U) ==
         0U) || (error != 0U)) {
    } else {
      switch (mode_in) {
       case PilotMode_Position:
       case PilotMode_Mission:
       case PilotMode_Offboard:
        if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag &
              128U) != 0U)) {
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
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] + FMS_DW.home
                         [2]);
        FMS_B.llo[0] = FMS_DW.llo[0];
        FMS_B.llo[1] = FMS_DW.llo[1];
        FMS_B.href = 0.0;
        FMS_B.psio = 0.0;

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
          FMS_B.psio, FMS_B.DataTypeConversion,
          &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

        /* End of Outputs for SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
        F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
          FMS_B.psio, FMS_B.DataTypeConversion,
          &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

        /* End of Outputs for SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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

  /* Outputs for Function Call SubSystem: '<S6>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S509>/Compare' incorporates:
   *  Abs: '<S498>/Abs'
   *  Constant: '<S509>/Constant'
   *  MinMax: '<S498>/Max'
   *  Sum: '<S498>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S6>/Vehicle.StickMoved' */
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
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_k
          >= 500) {
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
      if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >= FMS_B.Cmd_In.sp_waypoint
          [2]) {
        if (FMS_B.target_mode != PilotMode_None) {
          tmp = FMS_getArmMode(FMS_B.target_mode);
          if (tmp == 3.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Auto;
            FMS_enter_internal_Auto();
          } else if (tmp == 2.0) {
            FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_Assist;
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

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Arm(void)
{
  if (FMS_DW.is_Arm == FMS_IN_Auto) {
    if (FMS_DW.is_Auto == FMS_IN_Mission) {
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
    } else {
      FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
    }

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
  boolean_T b_sf_internal_predicateOutput;
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
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.is_SubMode = FMS_IN_Hold_h;
      FMS_B.state = VehicleState_Hold;
    } else if ((FMS_DW.mode_prev_n != FMS_DW.mode_start_a) && (FMS_B.target_mode
                != PilotMode_None)) {
      tmp = FMS_getArmMode(FMS_B.target_mode);
      if (tmp == 3.0) {
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_Auto;
        FMS_enter_internal_Auto();
      } else if (tmp == 2.0) {
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_Assist;
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
        b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_Land);
      } else {
        b_sf_internal_predicateOutput = false;
      }

      if (b_sf_internal_predicateOutput) {
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_SubMode;
        FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
        FMS_DW.stick_val[1] =
          FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
        FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
        FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_SubMode = FMS_IN_Land;
        FMS_B.state = VehicleState_Land;
        FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_B.on_ground;
      } else {
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Return);
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_B.Cmd_In.cur_waypoint[0] =
            FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
          FMS_B.Cmd_In.cur_waypoint[1] =
            FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
          FMS_B.Cmd_In.cur_waypoint[2] =
            FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
          FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
          FMS_B.Cmd_In.sp_waypoint[2] =
            FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
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
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_b)) {
        FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_b = sf_internal_predicateOutput;
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_n
          >= 500) {
        guard2 = true;
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Takeoff);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          guard2 = true;
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
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        } else {
          sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
          if ((FMS_DW.chartAbsoluteTimeCounter -
               FMS_DW.durationLastReferenceTick_2 >= 500) || ((FMS_B.target_mode
                == PilotMode_Offboard) && FMS_B.LogicalOperator &&
               (FMS_DW.prep_takeoff != 1.0)) || ((FMS_ManualArmEvent
                (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
                 FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
               ((FMS_B.target_mode != PilotMode_None) && (FMS_DW.prep_takeoff !=
                 1.0)))) {
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
            FMS_DW.durationLastReferenceTick_1_n5 =
              FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_Vehicle = FMS_IN_Arm;
            FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_B.on_ground;
            FMS_enter_internal_Arm();
          }
        }
      }
      break;
    }

    if (guard2) {
      FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_B.xy_R[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.xy_R[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S497>/Reshape' incorporates:
       *  Constant: '<S497>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S6>/Vehicle.PrepTakeoff' */
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

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard3 = false;
      guard4 = false;
      guard5 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          guard5 = true;
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
              guard5 = true;
            } else {
              guard4 = true;
            }
          } else {
            guard4 = true;
          }
        }
      } else {
        guard3 = true;
      }

      if (guard5) {
        FMS_DW.prep_mission_takeoff = 1.0;
        FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff == 1.0);
        FMS_DW.prep_takeoff = 0.0;
        FMS_DW.condWasTrueAtLastTimeStep_1_b = (FMS_DW.prep_takeoff == 1.0);
        guard3 = true;
      }

      if (guard4) {
        b_previousEvent = FMS_DW.sfEvent;
        FMS_DW.sfEvent = FMS_event_DisarmEvent;

        /* Chart: '<Root>/FMS State Machine' */
        FMS_c11_FMS();
        FMS_DW.sfEvent = b_previousEvent;
        if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
        } else {
          guard3 = true;
        }
      }

      if (guard3) {
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
    FMS_DW.mode_prev_n = FMS_B.target_mode;
    FMS_DW.mode_start_a = FMS_B.target_mode;
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
            FMS_B.target_mode, FMS_B.BusConversion_InsertedFor_FMSSt.flag,
            FMS_B.Add);
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
  FMS_Cmd rtb_DataTypeConversion1_fu;
  boolean_T rtb_FixPtRelationalOperator_me;
  real32_T rtb_Saturation_n;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_ft[3];
  uint16_T rtb_Divide_dr;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_a_l;
  real32_T rtb_Add4_d;
  boolean_T rtb_Compare_on;
  boolean_T rtb_LogicalOperator_aa;
  real32_T rtb_Sqrt_b;
  real32_T rtb_Integrator1_a;
  MotionState rtb_state_c;
  real32_T rtb_Rem_p;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_VectorConcatenate_ia[9];
  real32_T rtb_VectorConcatenate_ei[9];
  boolean_T rtb_LogicalOperator_a4;
  real32_T rtb_Sum_ff[2];
  real32_T rtb_TmpSignalConversionAtMath_c[3];
  real32_T rtb_Transpose_0[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  real32_T tmp_3[3];
  int32_T rtb_Compare_bv_0;
  real32_T rtb_P_l_idx_0;
  real32_T rtb_MathFunction_h_idx_1;
  real32_T rtb_Switch_mp_idx_2;
  real32_T rtb_Switch_mp_idx_1;
  real32_T rtb_Switch_f3_idx_2;
  real32_T rtb_Switch_f3_idx_1;
  real32_T rtb_MathFunction_f_idx_2;
  real32_T rtb_MathFunction_f_idx_1;
  real32_T rtb_Switch_mp_idx_0;
  real32_T rtb_Switch_f3_idx_0;
  real32_T rtb_MathFunction_f_idx_0;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real32_T rtb_Divide_l_idx_0;
  real_T rtb_Multiply_l5_idx_0;
  FMS_Error tmp_4;
  FMS_Error tmp_5;
  real32_T u1_tmp;
  uint32_T tmp_6;
  uint32_T tmp_7;
  uint32_T tmp_8;
  boolean_T guard1 = false;

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_fu = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S14>/Switch1' incorporates:
   *  Constant: '<S14>/Constant1'
   *  DataTypeConversion: '<S14>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S19>/FixPt Relational Operator'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  Switch: '<S14>/Switch2'
   *  UnitDelay: '<S19>/Delay Input1'
   *  UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S14>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_fu;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_a) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  DataTypeConversion: '<S15>/Data Type Conversion2'
   *  Delay: '<S15>/Delay'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S15>/Logical Operator'
   *  Logic: '<S15>/Logical Operator1'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/FixPt Relational Operator'
   *  Switch: '<S15>/Switch1'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_cn = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S15>/Switch1' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion1'
       *  Delay: '<S15>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_cn = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S15>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S15>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_DW.Delay_DSTATE_cn;
  FMS_DW.flag_prev = FMS_DW.flag_start;
  FMS_DW.flag_start = FMS_U.INS_Out.flag;
  if (FMS_DW.is_active_c1_FMS == 0U) {
    FMS_DW.mode_prev = FMS_DW.Delay_DSTATE_cn;
    FMS_DW.flag_prev = FMS_U.INS_Out.flag;
    FMS_DW.is_active_c1_FMS = 1U;
    FMS_enter_internal_c1_FMS();
  } else {
    FMS_Mode();
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S26>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
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
   *  RelationalOperator: '<S25>/FixPt Relational Operator'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
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
   *  Constant: '<S28>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S28>/Compare'
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

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Sqrt: '<S519>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S519>/Square'
   *  Sum: '<S519>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S515>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_l_idx_0 = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S516>/Square' incorporates:
   *  Math: '<S517>/Square'
   *  Math: '<S518>/Square'
   */
  rtb_Sqrt_b = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_0;

  /* Math: '<S516>/Square2' incorporates:
   *  Math: '<S517>/Square2'
   *  Math: '<S518>/Square2'
   */
  rtb_MathFunction_f_idx_1 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S516>/Square1' incorporates:
   *  Math: '<S517>/Square1'
   *  Math: '<S518>/Square1'
   */
  rtb_Saturation_n = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S516>/Square3' incorporates:
   *  Math: '<S517>/Square3'
   *  Math: '<S518>/Square3'
   */
  rtb_Add3_c = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0;

  /* Sum: '<S516>/Subtract' incorporates:
   *  Math: '<S516>/Square'
   *  Math: '<S516>/Square1'
   *  Math: '<S516>/Square2'
   *  Math: '<S516>/Square3'
   *  Sum: '<S516>/Add'
   *  Sum: '<S516>/Add1'
   */
  rtb_Transpose[0] = (rtb_Sqrt_b + rtb_Saturation_n) - (rtb_MathFunction_f_idx_1
    + rtb_Add3_c);

  /* Product: '<S516>/Multiply' incorporates:
   *  Product: '<S517>/Multiply'
   */
  rtb_Add4_d = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S516>/Multiply1' incorporates:
   *  Product: '<S517>/Multiply1'
   */
  rtb_a_l = rtb_Divide_l_idx_0 * rtb_MathFunction_f_idx_0;

  /* Gain: '<S516>/Gain' incorporates:
   *  Product: '<S516>/Multiply'
   *  Product: '<S516>/Multiply1'
   *  Sum: '<S516>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_Add4_d - rtb_a_l) * 2.0F;

  /* Product: '<S516>/Multiply2' incorporates:
   *  Product: '<S518>/Multiply'
   */
  rtb_Integrator1_a = rtb_Divide_l_idx_1 * rtb_MathFunction_f_idx_0;

  /* Product: '<S516>/Multiply3' incorporates:
   *  Product: '<S518>/Multiply1'
   */
  rtb_MathFunction_f_idx_2 = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_2;

  /* Gain: '<S516>/Gain1' incorporates:
   *  Product: '<S516>/Multiply2'
   *  Product: '<S516>/Multiply3'
   *  Sum: '<S516>/Add2'
   */
  rtb_Transpose[2] = (rtb_Integrator1_a + rtb_MathFunction_f_idx_2) * 2.0F;

  /* Gain: '<S517>/Gain' incorporates:
   *  Sum: '<S517>/Add3'
   */
  rtb_Transpose[3] = (rtb_Add4_d + rtb_a_l) * 2.0F;

  /* Sum: '<S517>/Subtract' incorporates:
   *  Sum: '<S517>/Add'
   *  Sum: '<S517>/Add1'
   */
  rtb_Transpose[4] = (rtb_Sqrt_b + rtb_MathFunction_f_idx_1) - (rtb_Saturation_n
    + rtb_Add3_c);

  /* Product: '<S517>/Multiply2' incorporates:
   *  Product: '<S518>/Multiply2'
   */
  rtb_Add4_d = rtb_Divide_l_idx_2 * rtb_MathFunction_f_idx_0;

  /* Product: '<S517>/Multiply3' incorporates:
   *  Product: '<S518>/Multiply3'
   */
  rtb_a_l = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_1;

  /* Gain: '<S517>/Gain1' incorporates:
   *  Product: '<S517>/Multiply2'
   *  Product: '<S517>/Multiply3'
   *  Sum: '<S517>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_Add4_d - rtb_a_l) * 2.0F;

  /* Gain: '<S518>/Gain' incorporates:
   *  Sum: '<S518>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Integrator1_a - rtb_MathFunction_f_idx_2) * 2.0F;

  /* Gain: '<S518>/Gain1' incorporates:
   *  Sum: '<S518>/Add2'
   */
  rtb_Transpose[7] = (rtb_Add4_d + rtb_a_l) * 2.0F;

  /* Sum: '<S518>/Subtract' incorporates:
   *  Sum: '<S518>/Add'
   *  Sum: '<S518>/Add1'
   */
  rtb_Transpose[8] = (rtb_Sqrt_b + rtb_Add3_c) - (rtb_Saturation_n +
    rtb_MathFunction_f_idx_1);

  /* Math: '<S7>/Transpose' */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_VectorConcatenate_ia[3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0];
    rtb_VectorConcatenate_ia[1 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 3];
    rtb_VectorConcatenate_ia[2 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 6];
  }

  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 9; rtb_Compare_bv_0++) {
    rtb_Transpose[rtb_Compare_bv_0] = rtb_VectorConcatenate_ia[rtb_Compare_bv_0];
  }

  /* End of Math: '<S7>/Transpose' */

  /* Product: '<S7>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S7>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S7>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S7>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_Multiply_ft[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 6] *
      FMS_U.INS_Out.az + (rtb_Transpose[rtb_Compare_bv_0 + 3] * FMS_U.INS_Out.ay
                          + rtb_Transpose[rtb_Compare_bv_0] * FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S7>/Multiply' */

  /* DiscreteIntegrator: '<S510>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_ft[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_ft[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_ft[2];
  }

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S7>/Sum of Elements'
   */
  rtb_Divide_dr = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S512>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S512>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_Sqrt_b = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Sqrt_b > 1.0F) {
    rtb_Sqrt_b = 1.0F;
  } else {
    if (rtb_Sqrt_b < 0.9F) {
      rtb_Sqrt_b = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_l_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Sqrt_b;

  /* DiscreteIntegrator: '<S511>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S510>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S511>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S512>/Discrete-Time Integrator5'
   *  Logic: '<S513>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S513>/Lower Test'
   *  RelationalOperator: '<S513>/Upper Test'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  FMS_B.on_ground = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) &&
                     ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) &&
                     ((-10.306F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d <
                      FMS_DW.DiscreteTimeIntegrator5_DSTAT_k));

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Delay: '<S11>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  Switch: '<S11>/Switch'
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_c) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = 0U;
    rtb_Switch_ga = 1U;
  } else {
    rtb_Switch_ga = FMS_DW.Delay_DSTATE_o;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S12>/Upper Limit'
   *  Constant: '<S9>/Constant'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S12>/Upper Test'
   *  RelationalOperator: '<S9>/Compare'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 3));

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  if (FMS_B.degrade > 0.0) {
    tmp_4 = FMS_Error_ModeDegradation;
  } else {
    tmp_4 = FMS_Error_None;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   */
  if (FMS_B.LogicalOperator2) {
    tmp_5 = FMS_Error_LostLink;
  } else {
    tmp_5 = FMS_Error_None;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Sum: '<S494>/Add' incorporates:
   *  DataTypeConversion: '<S27>/Data Type Conversion'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  FMS_B.Add = (uint32_T)tmp_4 + (uint32_T)tmp_5;

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
  FMS_DW.mode_prev_n = FMS_DW.mode_start_a;
  FMS_DW.mode_start_a = FMS_B.target_mode;
  FMS_DW.M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* SwitchCase: '<S30>/Switch Case' incorporates:
   *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S32>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S39>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S443>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S433>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S377>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S355>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S365>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S199>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S189>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S150>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S36>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S138>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S51>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S71>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S86>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S109>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S97>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S32>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S30>/Disarm' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S34>/Bus Assignment'
     *  Constant: '<S34>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S34>/Bus Assignment' incorporates:
     *  Constant: '<S34>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;

    /* End of Outputs for SubSystem: '<S30>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S30>/Standby' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S35>/Bus Assignment'
     *  Constant: '<S35>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S35>/Bus Assignment' incorporates:
     *  Constant: '<S35>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

    /* End of Outputs for SubSystem: '<S30>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S30>/Arm' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* SwitchCase: '<S32>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

    /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S39>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S443>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S433>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S377>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S355>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S365>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S199>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S189>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S150>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S138>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S71>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S109>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S97>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
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
      /* Outputs for IfAction SubSystem: '<S32>/SubMode' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* SwitchCase: '<S39>/Switch Case' incorporates:
       *  Math: '<S465>/Math Function'
       *  Product: '<S467>/Divide'
       *  Sum: '<S423>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_at;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_at) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S443>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S433>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S377>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S355>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S365>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Takeoff' incorporates:
           *  ActionPort: '<S350>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S492>/cur_waypoint'
           *  DiscreteIntegrator: '<S488>/Integrator'
           *  DiscreteIntegrator: '<S488>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Takeoff' incorporates:
         *  ActionPort: '<S350>/Action Port'
         */
        /* Delay: '<S492>/cur_waypoint' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j1 != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
          FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Product: '<S492>/Divide' incorporates:
         *  Delay: '<S492>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S492>/Sum1'
         *  Sum: '<S492>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S492>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S492>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S493>/Trigonometric Function1' incorporates:
         *  Gain: '<S491>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S493>/Trigonometric Function3'
         */
        rtb_Sqrt_b = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S493>/Trigonometric Function' incorporates:
         *  Gain: '<S491>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S493>/Trigonometric Function2'
         */
        rtb_MathFunction_f_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_f_idx_1;

        /* SignalConversion: '<S493>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S493>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S493>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_f_idx_1;

        /* Trigonometry: '<S493>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_Sqrt_b;

        /* SignalConversion: '<S493>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S493>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S493>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S485>/Saturation1' */
        rtb_Saturation_n = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Add4_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S485>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S492>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S492>/Multiply'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S485>/Sum'
         *  Sum: '<S492>/Sum3'
         *  Sum: '<S492>/Sum4'
         */
        rtb_a_l = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0])
                   * rtb_Add3_c + FMS_DW.cur_waypoint_DSTATE[0]) -
          FMS_U.INS_Out.x_R;
        rtb_Integrator1_a = ((FMS_B.Cmd_In.sp_waypoint[1] -
                              FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
                             FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S485>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l;
        }

        /* Saturate: '<S485>/Saturation1' incorporates:
         *  Gain: '<S485>/Gain2'
         *  Product: '<S485>/Multiply'
         */
        rtb_Sqrt_b = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S350>/Bus Assignment1'
         *  Constant: '<S350>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
         *  Constant: '<S350>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S485>/Saturation1' */
        if (rtb_Sqrt_b > rtb_Saturation_n) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_n;
        } else if (rtb_Sqrt_b < rtb_Add4_d) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_d;
        } else {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_b;
        }

        if (rtb_Add3_c > rtb_Saturation_n) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        } else if (rtb_Add3_c < rtb_Add4_d) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_d;
        } else {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S488>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S489>/Multiply1' incorporates:
         *  Constant: '<S489>/const1'
         *  DiscreteIntegrator: '<S488>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S484>/Switch' incorporates:
         *  Abs: '<S484>/Abs'
         *  Abs: '<S484>/Abs1'
         *  Constant: '<S484>/Takeoff_Speed'
         *  Constant: '<S486>/Constant'
         *  Constant: '<S487>/Constant'
         *  Gain: '<S484>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S484>/Logical Operator'
         *  RelationalOperator: '<S486>/Compare'
         *  RelationalOperator: '<S487>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S484>/Sum'
         *  Sum: '<S484>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Saturation_n = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Saturation_n = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S484>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S489>/Add' incorporates:
         *  DiscreteIntegrator: '<S488>/Integrator1'
         *  Sum: '<S488>/Subtract'
         */
        rtb_Saturation_n = (FMS_DW.Integrator1_DSTATE_a - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S489>/Sign' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Saturation_n;
        }

        /* End of Signum: '<S489>/Sign' */

        /* Sum: '<S489>/Add2' incorporates:
         *  Abs: '<S489>/Abs'
         *  Gain: '<S489>/Gain'
         *  Gain: '<S489>/Gain1'
         *  Product: '<S489>/Multiply2'
         *  Product: '<S489>/Multiply3'
         *  Sqrt: '<S489>/Sqrt'
         *  Sum: '<S489>/Add1'
         *  Sum: '<S489>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Saturation_n) + FMS_ConstB.d_m) *
                         FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F * rtb_Add4_d +
          rtb_Add3_c;

        /* Sum: '<S489>/Add4' */
        rtb_Add4_d = (rtb_Saturation_n - rtb_a_l) + rtb_Add3_c;

        /* Sum: '<S489>/Add3' */
        rtb_Add3_c = rtb_Saturation_n + FMS_ConstB.d_m;

        /* Sum: '<S489>/Subtract1' */
        rtb_Saturation_n -= FMS_ConstB.d_m;

        /* Signum: '<S489>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S489>/Sign1' */

        /* Signum: '<S489>/Sign2' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S489>/Sign2' */

        /* Sum: '<S489>/Add5' incorporates:
         *  Gain: '<S489>/Gain2'
         *  Product: '<S489>/Multiply4'
         *  Sum: '<S489>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Saturation_n) * 0.5F * rtb_Add4_d;

        /* Update for Delay: '<S492>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S488>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S488>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S489>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_m;

        /* Sum: '<S489>/Add6' */
        rtb_Sqrt_b = rtb_a_l + FMS_ConstB.d_m;

        /* Signum: '<S489>/Sign5' incorporates:
         *  Signum: '<S489>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S489>/Sign6' */
          rtb_Add4_d = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S489>/Sign6' */
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_l;

          /* Signum: '<S489>/Sign6' */
          rtb_Add4_d = rtb_a_l;
        }

        /* End of Signum: '<S489>/Sign5' */

        /* Signum: '<S489>/Sign3' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S489>/Sign3' */

        /* Signum: '<S489>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S489>/Sign4' */

        /* Update for DiscreteIntegrator: '<S488>/Integrator' incorporates:
         *  Constant: '<S489>/const'
         *  Gain: '<S489>/Gain3'
         *  Product: '<S489>/Divide'
         *  Product: '<S489>/Multiply5'
         *  Product: '<S489>/Multiply6'
         *  Sum: '<S489>/Subtract4'
         *  Sum: '<S489>/Subtract5'
         *  Sum: '<S489>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_a_l / FMS_ConstB.d_m -
          rtb_Saturation_n) * FMS_ConstB.Gain4_a * ((rtb_Sqrt_b - rtb_Add3_c) *
          0.5F) - rtb_Add4_d * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Land' incorporates:
           *  ActionPort: '<S348>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S393>/Integrator'
           *  DiscreteIntegrator: '<S393>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Land' incorporates:
         *  ActionPort: '<S348>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S398>/Trigonometric Function1' incorporates:
         *  Gain: '<S397>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S398>/Trigonometric Function' incorporates:
         *  Gain: '<S397>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S398>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S398>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S398>/Gain' incorporates:
         *  Gain: '<S397>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S398>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S398>/Trigonometric Function3' incorporates:
         *  Gain: '<S397>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S398>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S398>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S398>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S391>/Saturation1' */
        rtb_Saturation_n = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Add4_d = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S395>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S395>/Sum'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Sqrt_b = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S395>/Multiply' incorporates:
         *  SignalConversion: '<S395>/TmpSignal ConversionAtMultiplyInport2'
         *  Sum: '<S395>/Sum'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Sqrt_b + rtb_Transpose[rtb_Compare_bv_0] * rtb_Add3_c;
        }

        /* End of Product: '<S395>/Multiply' */

        /* Saturate: '<S391>/Saturation1' incorporates:
         *  Gain: '<S395>/Gain2'
         */
        rtb_Sqrt_b = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S348>/Bus Assignment1'
         *  Constant: '<S348>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
         *  Constant: '<S348>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S391>/Saturation1' */
        if (rtb_Sqrt_b > rtb_Saturation_n) {
          /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_n;
        } else if (rtb_Sqrt_b < rtb_Add4_d) {
          /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_d;
        } else {
          /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_b;
        }

        if (rtb_Add3_c > rtb_Saturation_n) {
          /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        } else if (rtb_Add3_c < rtb_Add4_d) {
          /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_d;
        } else {
          /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S348>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S393>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S394>/Multiply1' incorporates:
         *  Constant: '<S394>/const1'
         *  DiscreteIntegrator: '<S393>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S390>/Switch' incorporates:
         *  Constant: '<S390>/Land_Speed'
         *  Constant: '<S392>/Constant'
         *  Gain: '<S390>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S390>/Logical Operator'
         *  RelationalOperator: '<S392>/Compare'
         *  S-Function (sfix_bitop): '<S390>/cmd_p valid'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Saturation_n = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Saturation_n = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S390>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S394>/Add' incorporates:
         *  DiscreteIntegrator: '<S393>/Integrator1'
         *  Sum: '<S393>/Subtract'
         */
        rtb_Saturation_n = (FMS_DW.Integrator1_DSTATE_j - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S394>/Sign' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Saturation_n;
        }

        /* End of Signum: '<S394>/Sign' */

        /* Sum: '<S394>/Add2' incorporates:
         *  Abs: '<S394>/Abs'
         *  Gain: '<S394>/Gain'
         *  Gain: '<S394>/Gain1'
         *  Product: '<S394>/Multiply2'
         *  Product: '<S394>/Multiply3'
         *  Sqrt: '<S394>/Sqrt'
         *  Sum: '<S394>/Add1'
         *  Sum: '<S394>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Saturation_n) + FMS_ConstB.d_p) *
                         FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F * rtb_Add4_d +
          rtb_Add3_c;

        /* Sum: '<S394>/Add4' */
        rtb_Add4_d = (rtb_Saturation_n - rtb_a_l) + rtb_Add3_c;

        /* Sum: '<S394>/Add3' */
        rtb_Add3_c = rtb_Saturation_n + FMS_ConstB.d_p;

        /* Sum: '<S394>/Subtract1' */
        rtb_Saturation_n -= FMS_ConstB.d_p;

        /* Signum: '<S394>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S394>/Sign1' */

        /* Signum: '<S394>/Sign2' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S394>/Sign2' */

        /* Sum: '<S394>/Add5' incorporates:
         *  Gain: '<S394>/Gain2'
         *  Product: '<S394>/Multiply4'
         *  Sum: '<S394>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Saturation_n) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S393>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S393>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S394>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_p;

        /* Sum: '<S394>/Add6' */
        rtb_Sqrt_b = rtb_a_l + FMS_ConstB.d_p;

        /* Signum: '<S394>/Sign5' incorporates:
         *  Signum: '<S394>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S394>/Sign6' */
          rtb_Add4_d = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S394>/Sign6' */
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_l;

          /* Signum: '<S394>/Sign6' */
          rtb_Add4_d = rtb_a_l;
        }

        /* End of Signum: '<S394>/Sign5' */

        /* Signum: '<S394>/Sign3' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S394>/Sign3' */

        /* Signum: '<S394>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S394>/Sign4' */

        /* Update for DiscreteIntegrator: '<S393>/Integrator' incorporates:
         *  Constant: '<S394>/const'
         *  Gain: '<S394>/Gain3'
         *  Product: '<S394>/Divide'
         *  Product: '<S394>/Multiply5'
         *  Product: '<S394>/Multiply6'
         *  Sum: '<S394>/Subtract4'
         *  Sum: '<S394>/Subtract5'
         *  Sum: '<S394>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_a_l / FMS_ConstB.d_p -
          rtb_Saturation_n) * FMS_ConstB.Gain4_e * ((rtb_Sqrt_b - rtb_Add3_c) *
          0.5F) - rtb_Add4_d * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S349>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S401>/Delay'
           *  Delay: '<S402>/Delay'
           *  Delay: '<S424>/Delay'
           *  Delay: '<S424>/Delay1'
           *  DiscreteIntegrator: '<S405>/Integrator'
           *  DiscreteIntegrator: '<S405>/Integrator1'
           *  DiscreteIntegrator: '<S425>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S426>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S472>/Discrete-Time Integrator'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          FMS_DW.Delay1_DSTATE_b = false;
          FMS_DW.icLoad_l = 1U;
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
          FMS_DW.l1_heading_e = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Return' */

          /* SystemReset for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S349>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S434>/Motion Status'
           *  Chart: '<S444>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S39>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Return' incorporates:
         *  ActionPort: '<S349>/Action Port'
         */
        /* RelationalOperator: '<S419>/Compare' incorporates:
         *  Constant: '<S483>/Constant'
         *  DiscreteIntegrator: '<S426>/Discrete-Time Integrator'
         *  RelationalOperator: '<S483>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* Logic: '<S424>/Logical Operator' incorporates:
         *  Delay: '<S424>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE_b);

        /* Delay: '<S424>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if ((((FMS_PrevZCX.Delay_Reset_ZCE_l == POS_ZCSIG) != (int32_T)
              rtb_LogicalOperator_aa) && (FMS_PrevZCX.Delay_Reset_ZCE_l !=
              UNINITIALIZED_ZCSIG)) || rtb_LogicalOperator_aa) {
          FMS_DW.icLoad_l = 1U;
        }

        FMS_PrevZCX.Delay_Reset_ZCE_l = rtb_LogicalOperator_aa;
        if (FMS_DW.icLoad_l != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* RelationalOperator: '<S430>/Compare' incorporates:
         *  Constant: '<S430>/Constant'
         *  Delay: '<S424>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE_b = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S420>/Switch2' incorporates:
         *  Constant: '<S420>/vel'
         *  Delay: '<S424>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE_b) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_a_l = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_a_l = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S420>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S424>/Sum' incorporates:
         *  Delay: '<S424>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

        /* Sum: '<S425>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S424>/Sum' incorporates:
         *  Delay: '<S424>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_e[1];

        /* Sum: '<S425>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S482>/Sqrt' incorporates:
         *  Math: '<S482>/Square'
         *  Sum: '<S425>/Sum'
         *  Sum: '<S482>/Sum of Elements'
         */
        rtb_Sqrt_b = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
                           rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1);

        /* Gain: '<S425>/L1_GAIN' incorporates:
         *  Gain: '<S400>/Gain'
         */
        rtb_Saturation_n = FMS_PARAM.L1_GAIN * rtb_a_l;

        /* Switch: '<S425>/Switch' incorporates:
         *  Gain: '<S425>/L1_GAIN'
         *  Sum: '<S425>/Sum2'
         */
        if (rtb_Sqrt_b - rtb_Saturation_n >= 0.0F) {
          B = rtb_a_l;
        } else {
          /* Gain: '<S425>/Gain' */
          B = 0.5F * rtb_Sqrt_b;

          /* Switch: '<S480>/Switch2' incorporates:
           *  Constant: '<S425>/Constant1'
           *  RelationalOperator: '<S480>/LowerRelop1'
           *  RelationalOperator: '<S480>/UpperRelop'
           *  Switch: '<S480>/Switch'
           */
          if (B > rtb_a_l) {
            B = rtb_a_l;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S480>/Switch' incorporates:
               *  Constant: '<S425>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S480>/Switch2' */
        }

        /* End of Switch: '<S425>/Switch' */

        /* DiscreteIntegrator: '<S425>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Switch: '<S481>/Switch2' incorporates:
         *  Constant: '<S425>/Constant2'
         *  DiscreteIntegrator: '<S425>/Acceleration_Speed'
         *  RelationalOperator: '<S481>/LowerRelop1'
         *  RelationalOperator: '<S481>/UpperRelop'
         *  Switch: '<S481>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_a_l) {
          rtb_Integrator1_a = rtb_a_l;
        } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
          /* Switch: '<S481>/Switch' incorporates:
           *  Constant: '<S425>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE_j;
        }

        /* End of Switch: '<S481>/Switch2' */

        /* Switch: '<S425>/Switch1' incorporates:
         *  Sum: '<S425>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Integrator1_a = B;
        }

        /* End of Switch: '<S425>/Switch1' */

        /* DiscreteIntegrator: '<S472>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRe_e !=
             0)) {
          FMS_DW.l1_heading_e = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S444>/Motion State' incorporates:
         *  Constant: '<S444>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S444>/Square'
         *  Math: '<S444>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S444>/Sqrt'
         *  Sum: '<S444>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S443>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S443>/Hold Control' incorporates:
             *  ActionPort: '<S446>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S443>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S443>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S443>/Hold Control' incorporates:
           *  ActionPort: '<S446>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S443>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S443>/Brake Control' incorporates:
           *  ActionPort: '<S445>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S443>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S443>/Move Control' incorporates:
             *  ActionPort: '<S447>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S443>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S443>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S443>/Move Control' incorporates:
           *  ActionPort: '<S447>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S443>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S443>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S434>/Motion Status' incorporates:
         *  Abs: '<S434>/Abs'
         *  Constant: '<S434>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S433>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S433>/Hold Control' incorporates:
             *  ActionPort: '<S436>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S433>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S433>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S433>/Hold Control' incorporates:
           *  ActionPort: '<S436>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S433>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S433>/Brake Control' incorporates:
           *  ActionPort: '<S435>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S433>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S433>/Move Control' incorporates:
             *  ActionPort: '<S437>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S433>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S433>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S433>/Move Control' incorporates:
           *  ActionPort: '<S437>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S433>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S433>/Switch Case' */

        /* Switch: '<S400>/Switch' incorporates:
         *  Product: '<S424>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S443>/Saturation1' */
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

          /* End of Saturate: '<S443>/Saturation1' */

          /* Saturate: '<S433>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S433>/Saturation1' */
        } else {
          /* SignalConversion: '<S479>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S479>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S478>/Gain' incorporates:
           *  DiscreteIntegrator: '<S472>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S472>/Add'
           */
          rtb_MathFunction_f_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S479>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S479>/Trigonometric Function1'
           */
          rtb_Sqrt_b = arm_cos_f32(rtb_MathFunction_f_idx_0);
          rtb_Transpose[4] = rtb_Sqrt_b;

          /* Trigonometry: '<S479>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S479>/Trigonometric Function'
           */
          rtb_MathFunction_f_idx_1 = arm_sin_f32(rtb_MathFunction_f_idx_0);

          /* Gain: '<S479>/Gain' incorporates:
           *  Trigonometry: '<S479>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_f_idx_1;

          /* SignalConversion: '<S479>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S479>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S479>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_f_idx_1;

          /* Trigonometry: '<S479>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Sqrt_b;

          /* SignalConversion: '<S479>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Sum: '<S474>/Sum of Elements' incorporates:
           *  Math: '<S474>/Math Function'
           *  SignalConversion: '<S474>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_1 = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

          /* Math: '<S474>/Math Function1' incorporates:
           *  Sum: '<S474>/Sum of Elements'
           *
           * About '<S474>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_MathFunction_f_idx_0 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
          } else {
            rtb_MathFunction_f_idx_0 = sqrtf(rtb_Divide_l_idx_1);
          }

          /* End of Math: '<S474>/Math Function1' */

          /* Switch: '<S474>/Switch' incorporates:
           *  Constant: '<S474>/Constant'
           *  Product: '<S474>/Product'
           */
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = rtb_Add3_c;
            rtb_Divide_l_idx_1 = rtb_Add4_d;
          } else {
            rtb_Divide_l_idx_0 = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_MathFunction_f_idx_0 = 1.0F;
          }

          /* End of Switch: '<S474>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S427>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S427>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S427>/Divide' incorporates:
           *  Math: '<S428>/Square'
           *  Math: '<S429>/Square'
           *  Sqrt: '<S428>/Sqrt'
           *  Sqrt: '<S429>/Sqrt'
           *  Sum: '<S427>/Sum'
           *  Sum: '<S427>/Sum1'
           *  Sum: '<S428>/Sum of Elements'
           *  Sum: '<S429>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_Sqrt_b * rtb_Sqrt_b + rtb_MathFunction_f_idx_1 *
                             rtb_MathFunction_f_idx_1) / sqrtf(rtb_P_l_idx_0 *
            rtb_P_l_idx_0 + rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1);

          /* Saturate: '<S427>/Saturation' */
          if (rtb_Sqrt_b > 1.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            if (rtb_Sqrt_b < 0.0F) {
              rtb_Sqrt_b = 0.0F;
            }
          }

          /* End of Saturate: '<S427>/Saturation' */

          /* Product: '<S470>/Multiply2' incorporates:
           *  Product: '<S474>/Divide'
           */
          rtb_Divide_l_idx_0 = rtb_Divide_l_idx_0 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;

          /* Product: '<S424>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Divide_l_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_l_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S417>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S427>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S417>/Sum2'
           *  Sum: '<S427>/Add'
           *  Sum: '<S427>/Subtract'
           */
          rtb_Sqrt_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Sqrt_b +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S417>/Saturation1' incorporates:
           *  Product: '<S424>/Multiply'
           */
          if (rtb_Sqrt_b > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Sqrt_b < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Sqrt_b;
          }

          /* End of Saturate: '<S417>/Saturation1' */
        }

        /* End of Switch: '<S400>/Switch' */

        /* Delay: '<S402>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S405>/Integrator1' incorporates:
         *  Delay: '<S402>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S409>/Rem' incorporates:
         *  Constant: '<S409>/Constant1'
         *  DiscreteIntegrator: '<S405>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S404>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S409>/Switch' incorporates:
         *  Abs: '<S409>/Abs'
         *  Constant: '<S409>/Constant'
         *  Constant: '<S410>/Constant'
         *  Product: '<S409>/Multiply'
         *  RelationalOperator: '<S410>/Compare'
         *  Sum: '<S409>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S409>/Sign' */
          if (B < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (B > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = B;
          }

          /* End of Signum: '<S409>/Sign' */
          B -= 6.28318548F * rtb_Sqrt_b;
        }

        /* End of Switch: '<S409>/Switch' */

        /* Gain: '<S404>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S404>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S404>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S349>/Bus Assignment1'
         *  Constant: '<S349>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S349>/Bus Assignment1' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Sum: '<S476>/Sum of Elements' incorporates:
         *  Math: '<S476>/Math Function'
         *  SignalConversion: '<S476>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Add4_d * rtb_Add4_d + rtb_Add3_c * rtb_Add3_c;

        /* Math: '<S476>/Math Function1' incorporates:
         *  Sum: '<S476>/Sum of Elements'
         *
         * About '<S476>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S476>/Math Function1' */

        /* Switch: '<S476>/Switch' incorporates:
         *  Constant: '<S476>/Constant'
         *  Product: '<S476>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Add4_d;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Add3_c;
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S476>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S464>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S464>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S462>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S464>/Math Function1' incorporates:
         *  Sum: '<S464>/Sum of Elements'
         *
         * About '<S464>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S464>/Math Function1' */

        /* Switch: '<S464>/Switch' incorporates:
         *  Constant: '<S464>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S464>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S464>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S424>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S477>/Sum of Elements' incorporates:
         *  Math: '<S477>/Math Function'
         *  Sum: '<S424>/Sum1'
         */
        rtb_Rem_p = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S477>/Math Function1' incorporates:
         *  Sum: '<S477>/Sum of Elements'
         *
         * About '<S477>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S477>/Math Function1' */

        /* Switch: '<S477>/Switch' incorporates:
         *  Constant: '<S477>/Constant'
         *  Product: '<S477>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S477>/Switch' */

        /* Delay: '<S401>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S349>/Sum' incorporates:
         *  Delay: '<S401>/Delay'
         *  MATLAB Function: '<S422>/OutRegionRegWP'
         *  MATLAB Function: '<S422>/SearchL1RefWP'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S416>/Sum of Elements' incorporates:
         *  Math: '<S416>/Math Function'
         *  Sum: '<S349>/Sum'
         */
        rtb_Rem_p = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_P_l_idx_0 * rtb_P_l_idx_0;

        /* Math: '<S416>/Math Function1' incorporates:
         *  Sum: '<S416>/Sum of Elements'
         *
         * About '<S416>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S416>/Math Function1' */

        /* Switch: '<S416>/Switch' incorporates:
         *  Constant: '<S416>/Constant'
         *  Product: '<S416>/Product'
         *  Sum: '<S349>/Sum'
         */
        if (B > 0.0F) {
          rtb_Switch_f3_idx_0 = rtb_MathFunction_h_idx_1;
          rtb_Switch_f3_idx_1 = rtb_P_l_idx_0;
          rtb_Switch_f3_idx_2 = B;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S416>/Switch' */

        /* Product: '<S464>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S467>/Sum of Elements' incorporates:
         *  Math: '<S467>/Math Function'
         *  SignalConversion: '<S467>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Math: '<S467>/Math Function1' incorporates:
         *  Sum: '<S467>/Sum of Elements'
         *
         * About '<S467>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S467>/Math Function1' */

        /* Switch: '<S467>/Switch' incorporates:
         *  Constant: '<S467>/Constant'
         *  Product: '<S467>/Product'
         */
        if (B > 0.0F) {
          rtb_MathFunction_f_idx_0 = rtb_Sum_ff[1];
          rtb_MathFunction_f_idx_1 = rtb_Sum_ff[0];
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S467>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S422>/NearbyRefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, rtb_Saturation_n, rtb_Sum_ff,
                        &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S422>/SearchL1RefWP' incorporates:
         *  Delay: '<S401>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_P_l_idx_0 * rtb_P_l_idx_0 + rtb_MathFunction_h_idx_1 *
          rtb_MathFunction_h_idx_1;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        B = (rtb_P_l_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
             rtb_MathFunction_h_idx_1 * (FMS_DW.Delay_DSTATE_p[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     rtb_Saturation_n * rtb_Saturation_n) * (4.0F * rtb_Sqrt_b);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Add4_d = 0.0F;
        rtb_Divide_l_idx_0 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Sqrt_b);
          rtb_Sqrt_b = (-B - u1_tmp) / (2.0F * rtb_Sqrt_b);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Sqrt_b >= 0.0F) && (rtb_Sqrt_b <=
               1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Sqrt_b);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Sqrt_b >= 0.0F) && (rtb_Sqrt_b <= 1.0F)) {
              rtb_Add3_c = rtb_Sqrt_b;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Sqrt_b);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_Add4_d = rtb_P_l_idx_0 * rtb_Add3_c + FMS_DW.Delay_DSTATE_p[0];
          rtb_Divide_l_idx_0 = rtb_MathFunction_h_idx_1 * rtb_Add3_c +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S422>/OutRegionRegWP' incorporates:
         *  Delay: '<S401>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sqrt_b = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                      rtb_MathFunction_h_idx_1 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Sqrt_b <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Sqrt_b >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Sqrt_b * rtb_P_l_idx_0 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S422>/Switch1' incorporates:
         *  Constant: '<S457>/Constant'
         *  RelationalOperator: '<S457>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S422>/Switch' incorporates:
           *  Constant: '<S456>/Constant'
           *  MATLAB Function: '<S422>/SearchL1RefWP'
           *  RelationalOperator: '<S456>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Add4_d;
            rtb_Sum_ff[1] = rtb_Divide_l_idx_0;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S422>/OutRegionRegWP' incorporates:
             *  Delay: '<S401>/Delay'
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_a4) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Sqrt_b * rtb_MathFunction_h_idx_1 +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S422>/Switch' */
        }

        /* End of Switch: '<S422>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S423>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Sqrt_b;
        D = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S423>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S465>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S465>/Math Function' incorporates:
         *  Math: '<S463>/Square'
         */
        rtb_Rem_p = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Sum: '<S465>/Sum of Elements' incorporates:
         *  Math: '<S465>/Math Function'
         */
        rtb_Add4_d = rtb_Rem_p + D;

        /* Math: '<S465>/Math Function1' incorporates:
         *  Sum: '<S465>/Sum of Elements'
         *
         * About '<S465>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S465>/Math Function1' */

        /* Switch: '<S465>/Switch' incorporates:
         *  Constant: '<S465>/Constant'
         *  Product: '<S465>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Sqrt_b;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S465>/Switch' */

        /* Product: '<S465>/Divide' */
        rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S468>/Sum of Elements' incorporates:
         *  Math: '<S468>/Math Function'
         *  SignalConversion: '<S468>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add4_d = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_Add3_c * rtb_Add3_c;

        /* Math: '<S468>/Math Function1' incorporates:
         *  Sum: '<S468>/Sum of Elements'
         *
         * About '<S468>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S468>/Math Function1' */

        /* Switch: '<S468>/Switch' incorporates:
         *  Constant: '<S468>/Constant'
         *  Product: '<S468>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = rtb_Add3_c;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S468>/Switch' */

        /* Product: '<S468>/Divide' */
        rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];

        /* Math: '<S463>/Square' */
        D = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S416>/Divide' */
        rtb_Add4_d = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S477>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S476>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S468>/Divide' incorporates:
         *  Product: '<S467>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S467>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S416>/Divide' */
        rtb_Divide_l_idx_0 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S477>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S476>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S475>/Subtract' incorporates:
         *  Product: '<S475>/Multiply'
         *  Product: '<S475>/Multiply1'
         */
        B = rtb_P_l_idx_0 * rtb_MathFunction_f_idx_1 - rtb_MathFunction_f_idx_0 *
          rtb_Switch_mp_idx_0;

        /* Signum: '<S471>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S471>/Sign1' */

        /* Switch: '<S471>/Switch2' incorporates:
         *  Constant: '<S471>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S471>/Switch2' */

        /* DotProduct: '<S471>/Dot Product' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S471>/Acos' incorporates:
         *  DotProduct: '<S471>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_1 > 1.0F) {
          rtb_MathFunction_f_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 < -1.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S471>/Multiply' incorporates:
         *  Trigonometry: '<S471>/Acos'
         */
        B *= acosf(rtb_MathFunction_f_idx_1);

        /* Abs: '<S424>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S469>/Compare' incorporates:
         *  Constant: '<S469>/Constant'
         *  Delay: '<S424>/Delay1'
         */
        FMS_DW.Delay1_DSTATE_b = (B > 1.57079637F);

        /* Sqrt: '<S462>/Sqrt' */
        rtb_Divide_l_idx_1 = sqrtf(rtb_Divide_l_idx_1);

        /* Math: '<S423>/Square' */
        rtb_MathFunction_f_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

        /* Sum: '<S466>/Subtract' incorporates:
         *  Product: '<S466>/Multiply'
         *  Product: '<S466>/Multiply1'
         */
        rtb_Divide_l_idx_1 = rtb_Add3_c * rtb_Sqrt_b - rtb_MathFunction_h_idx_1 *
          rtb_Sum_ff[0];

        /* Signum: '<S461>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S461>/Sign1' */

        /* Switch: '<S461>/Switch2' incorporates:
         *  Constant: '<S461>/Constant4'
         */
        if (rtb_Divide_l_idx_1 == 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        }

        /* End of Switch: '<S461>/Switch2' */

        /* DotProduct: '<S461>/Dot Product' */
        rtb_Sqrt_b = rtb_Sum_ff[0] * rtb_Add3_c + rtb_Sqrt_b *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S461>/Acos' incorporates:
         *  DotProduct: '<S461>/Dot Product'
         */
        if (rtb_Sqrt_b > 1.0F) {
          rtb_Sqrt_b = 1.0F;
        } else {
          if (rtb_Sqrt_b < -1.0F) {
            rtb_Sqrt_b = -1.0F;
          }
        }

        /* Product: '<S461>/Multiply' incorporates:
         *  Trigonometry: '<S461>/Acos'
         */
        rtb_Divide_l_idx_1 *= acosf(rtb_Sqrt_b);

        /* Saturate: '<S423>/Saturation' */
        if (rtb_Divide_l_idx_1 > 1.57079637F) {
          rtb_Divide_l_idx_1 = 1.57079637F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.57079637F) {
            rtb_Divide_l_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S423>/Saturation' */

        /* Switch: '<S473>/Switch2' incorporates:
         *  Constant: '<S424>/Constant1'
         *  RelationalOperator: '<S473>/LowerRelop1'
         *  RelationalOperator: '<S473>/UpperRelop'
         *  Switch: '<S473>/Switch'
         */
        if (rtb_Integrator1_a > rtb_a_l) {
          rtb_Integrator1_a = rtb_a_l;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S473>/Switch' incorporates:
             *  Constant: '<S424>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S473>/Switch2' */

        /* Product: '<S424>/Divide1' incorporates:
         *  Constant: '<S423>/Constant'
         *  Gain: '<S423>/Gain'
         *  MinMax: '<S423>/Max'
         *  MinMax: '<S423>/Min'
         *  Product: '<S423>/Divide'
         *  Product: '<S423>/Multiply1'
         *  Sqrt: '<S463>/Sqrt'
         *  Sum: '<S463>/Sum of Elements'
         *  Trigonometry: '<S423>/Sin'
         */
        rtb_Divide_l_idx_1 = 2.0F * rtb_MathFunction_f_idx_0 * arm_sin_f32
          (rtb_Divide_l_idx_1) / fminf(rtb_Saturation_n, fmaxf(sqrtf(rtb_Rem_p +
          D), 0.5F)) / rtb_Integrator1_a;

        /* Saturate: '<S424>/Saturation' */
        if (rtb_Divide_l_idx_1 > 0.314159274F) {
          rtb_a_l = 0.314159274F;
        } else if (rtb_Divide_l_idx_1 < -0.314159274F) {
          rtb_a_l = -0.314159274F;
        } else {
          rtb_a_l = rtb_Divide_l_idx_1;
        }

        /* End of Saturate: '<S424>/Saturation' */

        /* Sum: '<S414>/Subtract' incorporates:
         *  Product: '<S414>/Multiply'
         *  Product: '<S414>/Multiply1'
         */
        rtb_Divide_l_idx_1 = rtb_Add4_d * FMS_ConstB.Divide_d[1] -
          rtb_Divide_l_idx_0 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S403>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S403>/Sign1' */

        /* Switch: '<S403>/Switch2' incorporates:
         *  Constant: '<S403>/Constant4'
         */
        if (rtb_Divide_l_idx_1 == 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        }

        /* End of Switch: '<S403>/Switch2' */

        /* DotProduct: '<S403>/Dot Product' */
        rtb_Sqrt_b = FMS_ConstB.Divide_d[0] * rtb_Add4_d + FMS_ConstB.Divide_d[1]
          * rtb_Divide_l_idx_0;

        /* Trigonometry: '<S403>/Acos' incorporates:
         *  DotProduct: '<S403>/Dot Product'
         */
        if (rtb_Sqrt_b > 1.0F) {
          rtb_Sqrt_b = 1.0F;
        } else {
          if (rtb_Sqrt_b < -1.0F) {
            rtb_Sqrt_b = -1.0F;
          }
        }

        /* Product: '<S403>/Multiply' incorporates:
         *  Trigonometry: '<S403>/Acos'
         */
        rtb_Divide_l_idx_1 *= acosf(rtb_Sqrt_b);

        /* Math: '<S406>/Rem' incorporates:
         *  Constant: '<S406>/Constant1'
         *  Delay: '<S402>/Delay'
         *  Sum: '<S402>/Sum2'
         */
        B = rt_remf(rtb_Divide_l_idx_1 - FMS_DW.Delay_DSTATE_a, 6.28318548F);

        /* Switch: '<S406>/Switch' incorporates:
         *  Abs: '<S406>/Abs'
         *  Constant: '<S406>/Constant'
         *  Constant: '<S412>/Constant'
         *  Product: '<S406>/Multiply'
         *  RelationalOperator: '<S412>/Compare'
         *  Sum: '<S406>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S406>/Sign' */
          if (B < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (B > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = B;
          }

          /* End of Signum: '<S406>/Sign' */
          B -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S406>/Switch' */

        /* Sum: '<S402>/Sum' incorporates:
         *  Delay: '<S402>/Delay'
         */
        rtb_Saturation_n = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S411>/Multiply1' incorporates:
         *  Constant: '<S411>/const1'
         *  DiscreteIntegrator: '<S405>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S411>/Add' incorporates:
         *  DiscreteIntegrator: '<S405>/Integrator1'
         *  Sum: '<S405>/Subtract'
         */
        rtb_Saturation_n = (FMS_DW.Integrator1_DSTATE_e - rtb_Saturation_n) + B;

        /* Signum: '<S411>/Sign' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Saturation_n;
        }

        /* End of Signum: '<S411>/Sign' */

        /* Sum: '<S411>/Add2' incorporates:
         *  Abs: '<S411>/Abs'
         *  Gain: '<S411>/Gain'
         *  Gain: '<S411>/Gain1'
         *  Product: '<S411>/Multiply2'
         *  Product: '<S411>/Multiply3'
         *  Sqrt: '<S411>/Sqrt'
         *  Sum: '<S411>/Add1'
         *  Sum: '<S411>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Saturation_n) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Add3_c
          + B;

        /* Sum: '<S411>/Add4' */
        rtb_Add4_d = (rtb_Saturation_n - rtb_Rem_p) + B;

        /* Sum: '<S411>/Add3' */
        rtb_Add3_c = rtb_Saturation_n + FMS_ConstB.d_l;

        /* Sum: '<S411>/Subtract1' */
        rtb_Saturation_n -= FMS_ConstB.d_l;

        /* Signum: '<S411>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S411>/Sign1' */

        /* Signum: '<S411>/Sign2' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S411>/Sign2' */

        /* Sum: '<S411>/Add5' incorporates:
         *  Gain: '<S411>/Gain2'
         *  Product: '<S411>/Multiply4'
         *  Sum: '<S411>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Saturation_n) * 0.5F * rtb_Add4_d;

        /* Sum: '<S411>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d_l;

        /* Sum: '<S411>/Subtract3' */
        rtb_Sqrt_b = rtb_Rem_p - FMS_ConstB.d_l;

        /* Product: '<S411>/Divide' */
        rtb_Add4_d = rtb_Rem_p / FMS_ConstB.d_l;

        /* Signum: '<S411>/Sign5' incorporates:
         *  Signum: '<S411>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Integrator1_a = -1.0F;

          /* Signum: '<S411>/Sign6' */
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_Integrator1_a = 1.0F;

          /* Signum: '<S411>/Sign6' */
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_Rem_p;

          /* Signum: '<S411>/Sign6' */
          rtb_Saturation_n = rtb_Rem_p;
        }

        /* End of Signum: '<S411>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S402>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_l_idx_1 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S407>/Rem' incorporates:
         *  Constant: '<S407>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_Divide_l_idx_1, 6.28318548F);

        /* Switch: '<S407>/Switch' incorporates:
         *  Abs: '<S407>/Abs'
         *  Constant: '<S407>/Constant'
         *  Constant: '<S413>/Constant'
         *  Product: '<S407>/Multiply'
         *  RelationalOperator: '<S413>/Compare'
         *  Sum: '<S407>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S407>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_0 = rtb_Rem_p;
          }

          /* End of Signum: '<S407>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Divide_l_idx_0;
        }

        /* End of Switch: '<S407>/Switch' */

        /* Abs: '<S400>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for DiscreteIntegrator: '<S426>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S418>/Constant'
         *  RelationalOperator: '<S418>/Compare'
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

        /* End of Update for DiscreteIntegrator: '<S426>/Discrete-Time Integrator' */

        /* Update for Delay: '<S424>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S425>/Acceleration_Speed' incorporates:
         *  Constant: '<S425>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S472>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_a_l;
        FMS_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S402>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S405>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S405>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S401>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S411>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S411>/Sign3' */

        /* Signum: '<S411>/Sign4' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S411>/Sign4' */

        /* Update for DiscreteIntegrator: '<S405>/Integrator' incorporates:
         *  Constant: '<S411>/const'
         *  Gain: '<S411>/Gain3'
         *  Product: '<S411>/Multiply5'
         *  Product: '<S411>/Multiply6'
         *  Sum: '<S411>/Subtract4'
         *  Sum: '<S411>/Subtract5'
         *  Sum: '<S411>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Add4_d - rtb_Integrator1_a) *
          FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Sqrt_b) * 0.5F) -
          rtb_Saturation_n * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S405>/Integrator' */
        /* End of Outputs for SubSystem: '<S39>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S39>/Hold' incorporates:
           *  ActionPort: '<S347>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S356>/Motion Status'
           *  Chart: '<S366>/Motion State'
           *  Chart: '<S378>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S39>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Hold' incorporates:
         *  ActionPort: '<S347>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S356>/Motion Status' incorporates:
         *  Abs: '<S356>/Abs'
         *  Constant: '<S356>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S366>/Motion State' incorporates:
         *  Abs: '<S366>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
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

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
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

        /* End of Chart: '<S366>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S378>/Motion State' incorporates:
         *  Constant: '<S378>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S378>/Square'
         *  Math: '<S378>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S378>/Sqrt'
         *  Sum: '<S378>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S377>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S377>/Hold Control' incorporates:
             *  ActionPort: '<S380>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S377>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S377>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S377>/Hold Control' incorporates:
           *  ActionPort: '<S380>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S377>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S377>/Brake Control' incorporates:
           *  ActionPort: '<S379>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S377>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S377>/Move Control' incorporates:
             *  ActionPort: '<S381>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S377>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S377>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S377>/Move Control' incorporates:
           *  ActionPort: '<S381>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S377>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S377>/Switch Case' */

        /* SwitchCase: '<S355>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S355>/Hold Control' incorporates:
             *  ActionPort: '<S358>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S355>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S355>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S355>/Hold Control' incorporates:
           *  ActionPort: '<S358>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S355>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S355>/Brake Control' incorporates:
           *  ActionPort: '<S357>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S355>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S355>/Move Control' incorporates:
             *  ActionPort: '<S359>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S355>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S355>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S355>/Move Control' incorporates:
           *  ActionPort: '<S359>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S355>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S355>/Switch Case' */

        /* SwitchCase: '<S365>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S365>/Hold Control' incorporates:
             *  ActionPort: '<S368>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S365>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S365>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S365>/Hold Control' incorporates:
           *  ActionPort: '<S368>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S365>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S365>/Brake Control' incorporates:
           *  ActionPort: '<S367>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S365>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S365>/Move Control' incorporates:
             *  ActionPort: '<S369>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S365>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S365>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S365>/Move Control' incorporates:
           *  ActionPort: '<S369>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S365>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S365>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S347>/Bus Assignment'
         *  Constant: '<S347>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S347>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S365>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S365>/Saturation' */

        /* Saturate: '<S377>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S377>/Saturation1' */

        /* Saturate: '<S355>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S347>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S355>/Saturation1' */
        /* End of Outputs for SubSystem: '<S39>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
         *  ActionPort: '<S351>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S39>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S39>/Switch Case' */
      /* End of Outputs for SubSystem: '<S32>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S32>/Auto' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* SwitchCase: '<S37>/Switch Case' incorporates:
       *  Math: '<S221>/Math Function'
       *  Product: '<S223>/Divide'
       *  Sum: '<S179>/Subtract'
       *  Sum: '<S243>/Sum1'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_i) && (rtPrevAction
           == 1)) {
        /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S199>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S189>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S150>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S37>/Offboard' incorporates:
         *  ActionPort: '<S151>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S324>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S327>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S328>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S328>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S328>/Multiply1' incorporates:
         *  Product: '<S328>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S328>/Divide' incorporates:
         *  Constant: '<S328>/Constant'
         *  Constant: '<S328>/R'
         *  Sqrt: '<S328>/Sqrt'
         *  Sum: '<S328>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S328>/Product3' incorporates:
         *  Constant: '<S328>/Constant1'
         *  Product: '<S328>/Multiply1'
         *  Sum: '<S328>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S328>/Multiply2' incorporates:
         *  Trigonometry: '<S328>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S327>/Sum' incorporates:
         *  Gain: '<S324>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S332>/Abs' incorporates:
         *  Abs: '<S335>/Abs1'
         *  Switch: '<S332>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S332>/Switch1' incorporates:
         *  Abs: '<S332>/Abs'
         *  Bias: '<S332>/Bias2'
         *  Bias: '<S332>/Bias3'
         *  Constant: '<S329>/Constant'
         *  Constant: '<S329>/Constant1'
         *  Constant: '<S334>/Constant'
         *  Gain: '<S332>/Gain1'
         *  Product: '<S332>/Multiply'
         *  RelationalOperator: '<S334>/Compare'
         *  Switch: '<S329>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S335>/Switch1' incorporates:
           *  Bias: '<S335>/Bias2'
           *  Bias: '<S335>/Bias3'
           *  Constant: '<S335>/Constant'
           *  Constant: '<S336>/Constant'
           *  Math: '<S335>/Math Function'
           *  RelationalOperator: '<S336>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S335>/Switch1' */

          /* Signum: '<S332>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S332>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S329>/Sum' incorporates:
         *  Gain: '<S324>/Gain1'
         *  Gain: '<S324>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S327>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S327>/Multiply' incorporates:
         *  Gain: '<S327>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S331>/Switch1' incorporates:
         *  Abs: '<S331>/Abs1'
         *  Bias: '<S331>/Bias2'
         *  Bias: '<S331>/Bias3'
         *  Constant: '<S331>/Constant'
         *  Constant: '<S333>/Constant'
         *  Math: '<S331>/Math Function'
         *  RelationalOperator: '<S333>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S331>/Switch1' */

        /* Product: '<S327>/Multiply' incorporates:
         *  Gain: '<S327>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S318>/Trigonometric Function1' incorporates:
         *  Gain: '<S317>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S318>/Trigonometric Function' incorporates:
         *  Gain: '<S317>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S318>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S318>/Gain' incorporates:
         *  Gain: '<S317>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S318>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S318>/Trigonometric Function3' incorporates:
         *  Gain: '<S317>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S318>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S318>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S305>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S309>/Multiply1'
         *  Product: '<S310>/Multiply3'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Switch: '<S311>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  DataTypeConversion: '<S324>/Data Type Conversion1'
           *  Product: '<S330>/Multiply1'
           *  Product: '<S330>/Multiply2'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S323>/lat_cmd valid'
           *  Sum: '<S330>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S315>/Constant'
           *  Constant: '<S316>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S315>/Compare'
           *  RelationalOperator: '<S316>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_a_l = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S311>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  DataTypeConversion: '<S324>/Data Type Conversion1'
           *  Product: '<S330>/Multiply3'
           *  Product: '<S330>/Multiply4'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S323>/lon_cmd valid'
           *  Sum: '<S330>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S315>/Constant'
           *  Constant: '<S316>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S315>/Compare'
           *  RelationalOperator: '<S316>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S311>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  DataTypeConversion: '<S324>/Data Type Conversion'
           *  DataTypeConversion: '<S324>/Data Type Conversion1'
           *  Gain: '<S324>/Gain2'
           *  Gain: '<S327>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S323>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S327>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S315>/Constant'
           *  Constant: '<S316>/Constant'
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S315>/Compare'
           *  RelationalOperator: '<S316>/Compare'
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Divide_l_idx_0 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 1:
          /* Switch: '<S311>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  DataTypeConversion: '<S324>/Data Type Conversion1'
           *  Product: '<S330>/Multiply1'
           *  Product: '<S330>/Multiply2'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S323>/lat_cmd valid'
           *  Sum: '<S330>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S315>/Constant'
           *  Constant: '<S316>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S315>/Compare'
           *  RelationalOperator: '<S316>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_a_l = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S311>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  DataTypeConversion: '<S324>/Data Type Conversion1'
           *  Product: '<S330>/Multiply3'
           *  Product: '<S330>/Multiply4'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S323>/lon_cmd valid'
           *  Sum: '<S330>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S315>/Constant'
           *  Constant: '<S316>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S315>/Compare'
           *  RelationalOperator: '<S316>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S311>/Switch' incorporates:
           *  Constant: '<S326>/Constant'
           *  DataTypeConversion: '<S324>/Data Type Conversion'
           *  DataTypeConversion: '<S324>/Data Type Conversion1'
           *  Gain: '<S324>/Gain2'
           *  Gain: '<S327>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S323>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S327>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S315>/Constant'
           *  Constant: '<S316>/Constant'
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S315>/Compare'
           *  RelationalOperator: '<S316>/Compare'
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Divide_l_idx_0 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 2:
          /* SignalConversion: '<S321>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S321>/Constant4'
           */
          rtb_VectorConcatenate_ia[5] = 0.0F;

          /* Trigonometry: '<S321>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S310>/Data Store Read'
           *  Gain: '<S319>/Gain'
           *  Trigonometry: '<S321>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(-FMS_DW.home[3]);
          rtb_VectorConcatenate_ia[4] = rtb_Saturation_n;

          /* Trigonometry: '<S321>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S310>/Data Store Read'
           *  Gain: '<S319>/Gain'
           *  Trigonometry: '<S321>/Trigonometric Function'
           */
          rtb_Add3_c = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S321>/Gain' incorporates:
           *  Trigonometry: '<S321>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ia[3] = -rtb_Add3_c;

          /* SignalConversion: '<S321>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S321>/Constant3'
           */
          rtb_VectorConcatenate_ia[2] = 0.0F;

          /* Trigonometry: '<S321>/Trigonometric Function' */
          rtb_VectorConcatenate_ia[1] = rtb_Add3_c;

          /* Trigonometry: '<S321>/Trigonometric Function1' */
          rtb_VectorConcatenate_ia[0] = rtb_Saturation_n;

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[6] = FMS_ConstB.VectorConcatenate3_ny[0];

          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[7] = FMS_ConstB.VectorConcatenate3_ny[1];

          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[8] = FMS_ConstB.VectorConcatenate3_ny[2];

          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S322>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S322>/Constant4'
           */
          rtb_VectorConcatenate_ei[5] = 0.0F;

          /* Gain: '<S320>/Gain' incorporates:
           *  DataStoreRead: '<S310>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S310>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S322>/Trigonometric Function3' incorporates:
           *  Gain: '<S320>/Gain'
           *  Trigonometry: '<S322>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(rtb_Add3_c);
          rtb_VectorConcatenate_ei[4] = rtb_Saturation_n;

          /* Trigonometry: '<S322>/Trigonometric Function2' incorporates:
           *  Gain: '<S320>/Gain'
           *  Trigonometry: '<S322>/Trigonometric Function'
           */
          rtb_Add3_c = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S322>/Gain' incorporates:
           *  Trigonometry: '<S322>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ei[3] = -rtb_Add3_c;

          /* SignalConversion: '<S322>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S322>/Constant3'
           */
          rtb_VectorConcatenate_ei[2] = 0.0F;

          /* Trigonometry: '<S322>/Trigonometric Function' */
          rtb_VectorConcatenate_ei[1] = rtb_Add3_c;

          /* Trigonometry: '<S322>/Trigonometric Function1' */
          rtb_VectorConcatenate_ei[0] = rtb_Saturation_n;

          /* RelationalOperator: '<S326>/Compare' incorporates:
           *  Constant: '<S326>/Constant'
           *  S-Function (sfix_bitop): '<S323>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S323>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S323>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S324>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S324>/Data Type Conversion'
           *  Gain: '<S324>/Gain2'
           *  Gain: '<S327>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S330>/Multiply1'
           *  Product: '<S330>/Multiply2'
           *  Product: '<S330>/Multiply3'
           *  Product: '<S330>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S327>/Sum1'
           *  Sum: '<S330>/Sum2'
           *  Sum: '<S330>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S311>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S315>/Compare' incorporates:
           *  Constant: '<S315>/Constant'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S316>/Compare' incorporates:
           *  Constant: '<S316>/Constant'
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S310>/Sum2' incorporates:
             *  Product: '<S310>/Multiply2'
             *  Switch: '<S311>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Product: '<S310>/Multiply' incorporates:
             *  Gain: '<S312>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S308>/Logical Operator'
             *  Product: '<S310>/Multiply2'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Sum: '<S310>/Sum2'
             */
            tmp_3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Saturation_n -
              ((rtb_VectorConcatenate_ia[rtb_Compare_bv_0 + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_ia[rtb_Compare_bv_0] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_ia[rtb_Compare_bv_0 +
               6] * -FMS_U.INS_Out.h_R) : 0.0F;
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_ei[rtb_Compare_bv_0 + 6] * tmp_3[2] +
              (rtb_VectorConcatenate_ei[rtb_Compare_bv_0 + 3] * tmp_3[1] +
               rtb_VectorConcatenate_ei[rtb_Compare_bv_0] * tmp_3[0]);
          }
          break;

         default:
          /* SignalConversion: '<S314>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[6] = FMS_ConstB.VectorConcatenate3_n[0];
          rtb_VectorConcatenate_ia[7] = FMS_ConstB.VectorConcatenate3_n[1];
          rtb_VectorConcatenate_ia[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S314>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S314>/Constant4'
           */
          rtb_VectorConcatenate_ia[5] = 0.0F;

          /* Trigonometry: '<S314>/Trigonometric Function3' incorporates:
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S314>/Gain' incorporates:
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S314>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ia[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S314>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S314>/Constant3'
           */
          rtb_VectorConcatenate_ia[2] = 0.0F;

          /* Trigonometry: '<S314>/Trigonometric Function' incorporates:
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S314>/Trigonometric Function1' incorporates:
           *  Gain: '<S313>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S323>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S326>/Compare' incorporates:
           *  Constant: '<S326>/Constant'
           *  S-Function (sfix_bitop): '<S323>/lat_cmd valid'
           */
          tmp[0] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S323>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S326>/Compare' incorporates:
           *  Constant: '<S326>/Constant'
           *  S-Function (sfix_bitop): '<S323>/lon_cmd valid'
           */
          tmp[1] = (tmp_7 > 0U);

          /* S-Function (sfix_bitop): '<S323>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           */
          tmp_8 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S326>/Compare' incorporates:
           *  Constant: '<S326>/Constant'
           *  S-Function (sfix_bitop): '<S323>/alt_cmd valid'
           */
          tmp[2] = (tmp_8 > 0U);

          /* DataTypeConversion: '<S324>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S324>/Data Type Conversion'
           *  Gain: '<S324>/Gain2'
           *  Gain: '<S327>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S330>/Multiply1'
           *  Product: '<S330>/Multiply2'
           *  Product: '<S330>/Multiply3'
           *  Product: '<S330>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S327>/Sum1'
           *  Sum: '<S330>/Sum2'
           *  Sum: '<S330>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S311>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S315>/Compare' incorporates:
           *  Constant: '<S315>/Constant'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S316>/Compare' incorporates:
           *  Constant: '<S316>/Constant'
           */
          tmp_2[0] = (tmp_6 > 0U);
          tmp_2[1] = (tmp_7 > 0U);
          tmp_2[2] = (tmp_8 > 0U);

          /* Sum: '<S307>/Sum2' incorporates:
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  Product: '<S307>/Multiply'
           *  Product: '<S307>/Multiply2'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S311>/Switch' incorporates:
             *  Product: '<S307>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            rtb_MatrixConcatenate3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Saturation_n -
              ((rtb_VectorConcatenate_ia[rtb_Compare_bv_0 + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_ia[rtb_Compare_bv_0] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_ia[rtb_Compare_bv_0 +
               6] * -FMS_U.INS_Out.h_R) : 0.0F;
          }

          /* End of Sum: '<S307>/Sum2' */
          break;
        }

        /* End of MultiPortSwitch: '<S305>/Index Vector' */

        /* Trigonometry: '<S251>/Trigonometric Function1' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S251>/Trigonometric Function' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S251>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S251>/Gain' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S251>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S251>/Trigonometric Function3' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S251>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S240>/Index Vector' incorporates:
         *  Constant: '<S249>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S240>/Multiply'
         *  Product: '<S247>/Multiply'
         *  Product: '<S248>/Multiply3'
         *  RelationalOperator: '<S249>/Compare'
         *  S-Function (sfix_bitop): '<S246>/ax_cmd valid'
         *  S-Function (sfix_bitop): '<S246>/ay_cmd valid'
         *  S-Function (sfix_bitop): '<S246>/az_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S249>/Constant'
           *  RelationalOperator: '<S249>/Compare'
           *  S-Function (sfix_bitop): '<S246>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S246>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S246>/az_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Divide_l_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 1:
          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S249>/Constant'
           *  RelationalOperator: '<S249>/Compare'
           *  S-Function (sfix_bitop): '<S246>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S246>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S246>/az_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Divide_l_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 2:
          /* SignalConversion: '<S253>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S253>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S252>/Gain' incorporates:
           *  DataStoreRead: '<S248>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S248>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S253>/Trigonometric Function3' incorporates:
           *  Gain: '<S252>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S253>/Gain' incorporates:
           *  Gain: '<S252>/Gain'
           *  Trigonometry: '<S253>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S253>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S253>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S253>/Trigonometric Function' incorporates:
           *  Gain: '<S252>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S253>/Trigonometric Function1' incorporates:
           *  Gain: '<S252>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S253>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S249>/Constant'
           *  RelationalOperator: '<S249>/Compare'
           *  S-Function (sfix_bitop): '<S246>/ax_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S253>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S249>/Constant'
           *  RelationalOperator: '<S249>/Compare'
           *  S-Function (sfix_bitop): '<S246>/ay_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S253>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S249>/Constant'
           *  RelationalOperator: '<S249>/Compare'
           *  S-Function (sfix_bitop): '<S246>/az_cmd valid'
           */
          rtb_Divide_l_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         default:
          rtb_TmpSignalConversionAtMath_c[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S240>/Index Vector' */

        /* Sum: '<S301>/Sum1' incorporates:
         *  Constant: '<S301>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S301>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Saturation_n = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S302>/Abs' */
        rtb_Add3_c = fabsf(rtb_Saturation_n);

        /* Switch: '<S302>/Switch' incorporates:
         *  Constant: '<S302>/Constant'
         *  Constant: '<S303>/Constant'
         *  Product: '<S302>/Multiply'
         *  RelationalOperator: '<S303>/Compare'
         *  Sum: '<S302>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S302>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* End of Signum: '<S302>/Sign' */
          rtb_Saturation_n *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S302>/Switch' */

        /* Saturate: '<S301>/Saturation' */
        if (rtb_Saturation_n > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else {
          if (rtb_Saturation_n < -0.314159274F) {
            rtb_Saturation_n = -0.314159274F;
          }
        }

        /* End of Saturate: '<S301>/Saturation' */

        /* Gain: '<S298>/Gain2' */
        rtb_Saturation_n *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S242>/Sum' incorporates:
         *  Constant: '<S300>/Constant'
         *  Constant: '<S304>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S298>/Multiply2'
         *  Product: '<S299>/Multiply1'
         *  RelationalOperator: '<S300>/Compare'
         *  RelationalOperator: '<S304>/Compare'
         *  S-Function (sfix_bitop): '<S298>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S299>/psi_rate_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Sqrt_b = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Saturation_n :
                      0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
          FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S305>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Add4_d = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S305>/Gain2' */
        rtb_Saturation_n = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S344>/Trigonometric Function1' incorporates:
         *  Gain: '<S343>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S344>/Trigonometric Function' incorporates:
         *  Gain: '<S343>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S344>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S344>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S344>/Gain' incorporates:
         *  Gain: '<S343>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S344>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S344>/Trigonometric Function3' incorporates:
         *  Gain: '<S343>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S344>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S344>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S344>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S306>/Index Vector' incorporates:
         *  Constant: '<S342>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S306>/Multiply'
         *  Product: '<S339>/Multiply'
         *  Product: '<S340>/Multiply3'
         *  RelationalOperator: '<S342>/Compare'
         *  S-Function (sfix_bitop): '<S338>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S338>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S338>/w_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S306>/Multiply' incorporates:
           *  Constant: '<S342>/Constant'
           *  RelationalOperator: '<S342>/Compare'
           *  S-Function (sfix_bitop): '<S338>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S338>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S338>/w_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Divide_l_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 1:
          /* Product: '<S306>/Multiply' incorporates:
           *  Constant: '<S342>/Constant'
           *  RelationalOperator: '<S342>/Compare'
           *  S-Function (sfix_bitop): '<S338>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S338>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S338>/w_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Divide_l_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
          }
          break;

         case 2:
          /* SignalConversion: '<S346>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S346>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S345>/Gain' incorporates:
           *  DataStoreRead: '<S340>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S340>/Subtract'
           */
          rtb_a_l = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S346>/Trigonometric Function3' incorporates:
           *  Gain: '<S345>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_a_l);

          /* Gain: '<S346>/Gain' incorporates:
           *  Gain: '<S345>/Gain'
           *  Trigonometry: '<S346>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_a_l);

          /* SignalConversion: '<S346>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S346>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S346>/Trigonometric Function' incorporates:
           *  Gain: '<S345>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_a_l);

          /* Trigonometry: '<S346>/Trigonometric Function1' incorporates:
           *  Gain: '<S345>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_a_l);

          /* SignalConversion: '<S346>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S306>/Multiply' incorporates:
           *  Constant: '<S342>/Constant'
           *  RelationalOperator: '<S342>/Compare'
           *  S-Function (sfix_bitop): '<S338>/u_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S346>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S306>/Multiply' incorporates:
           *  Constant: '<S342>/Constant'
           *  RelationalOperator: '<S342>/Compare'
           *  S-Function (sfix_bitop): '<S338>/v_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S346>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S306>/Multiply' incorporates:
           *  Constant: '<S342>/Constant'
           *  RelationalOperator: '<S342>/Compare'
           *  S-Function (sfix_bitop): '<S338>/w_cmd valid'
           */
          rtb_Divide_l_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l);
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

        /* End of MultiPortSwitch: '<S306>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_Add4_d;

        /* Sum: '<S243>/Sum1' */
        rtb_Saturation_n += rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S261>/Switch' incorporates:
         *  Constant: '<S276>/Constant'
         *  Constant: '<S278>/Constant'
         *  Constant: '<S279>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S276>/Compare'
         *  RelationalOperator: '<S278>/Compare'
         *  RelationalOperator: '<S279>/Compare'
         *  S-Function (sfix_bitop): '<S261>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S261>/y_v_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S261>/Logical Operator' incorporates:
           *  Constant: '<S277>/Constant'
           *  Constant: '<S278>/Constant'
           *  Constant: '<S279>/Constant'
           *  RelationalOperator: '<S277>/Compare'
           *  RelationalOperator: '<S278>/Compare'
           *  RelationalOperator: '<S279>/Compare'
           *  S-Function (sfix_bitop): '<S261>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S261>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S261>/y_v_cmd'
           */
          rtb_LogicalOperator_a4 = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_a4;
        } else {
          rtb_LogicalOperator_a4 = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S261>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S241>/u_cmd_valid' */
        /* MATLAB Function: '<S273>/bit_shift' incorporates:
         *  DataTypeConversion: '<S241>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_a4 << 6);

        /* End of Outputs for SubSystem: '<S241>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S241>/v_cmd_valid' */
        /* MATLAB Function: '<S274>/bit_shift' incorporates:
         *  DataTypeConversion: '<S241>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S241>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S262>/Switch' incorporates:
         *  Constant: '<S281>/Constant'
         *  Constant: '<S282>/Constant'
         *  Constant: '<S284>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S281>/Compare'
         *  RelationalOperator: '<S282>/Compare'
         *  RelationalOperator: '<S284>/Compare'
         *  S-Function (sfix_bitop): '<S262>/ax_cmd'
         *  S-Function (sfix_bitop): '<S262>/ay_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S262>/Logical Operator' incorporates:
           *  Constant: '<S282>/Constant'
           *  Constant: '<S284>/Constant'
           *  RelationalOperator: '<S282>/Compare'
           *  RelationalOperator: '<S284>/Compare'
           *  S-Function (sfix_bitop): '<S262>/ax_cmd'
           *  S-Function (sfix_bitop): '<S262>/ay_cmd'
           */
          rtb_LogicalOperator_a4 = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_a4;
        } else {
          rtb_LogicalOperator_a4 = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S262>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S151>/Bus Assignment'
         *  Constant: '<S151>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = FMS_U.Auto_Cmd.p_cmd;
        FMS_Y.FMS_Out.q_cmd = FMS_U.Auto_Cmd.q_cmd;
        FMS_Y.FMS_Out.r_cmd = FMS_U.Auto_Cmd.r_cmd;
        FMS_Y.FMS_Out.phi_cmd = FMS_U.Auto_Cmd.phi_cmd;
        FMS_Y.FMS_Out.theta_cmd = FMS_U.Auto_Cmd.theta_cmd;
        FMS_Y.FMS_Out.throttle_cmd = FMS_U.Auto_Cmd.throttle_cmd;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        FMS_Y.FMS_Out.ax_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.az_cmd = rtb_TmpSignalConversionAtMath_c[2];

        /* Saturate: '<S242>/Saturation' */
        if (rtb_Sqrt_b > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Sqrt_b < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Sqrt_b;
        }

        /* End of Saturate: '<S242>/Saturation' */

        /* Saturate: '<S243>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S243>/Saturation2' */

        /* Saturate: '<S243>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S243>/Saturation1' */

        /* Saturate: '<S243>/Saturation3' */
        if (rtb_Saturation_n > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_n < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;
        }

        /* End of Saturate: '<S243>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S241>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S241>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S241>/throttle_cmd_valid' */
        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  Constant: '<S254>/Constant'
         *  Constant: '<S255>/Constant'
         *  Constant: '<S256>/Constant'
         *  Constant: '<S257>/Constant'
         *  Constant: '<S258>/Constant'
         *  Constant: '<S259>/Constant'
         *  Constant: '<S260>/Constant'
         *  Constant: '<S280>/Constant'
         *  Constant: '<S283>/Constant'
         *  DataTypeConversion: '<S241>/Data Type Conversion10'
         *  DataTypeConversion: '<S241>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S263>/bit_shift'
         *  MATLAB Function: '<S264>/bit_shift'
         *  MATLAB Function: '<S265>/bit_shift'
         *  MATLAB Function: '<S267>/bit_shift'
         *  MATLAB Function: '<S268>/bit_shift'
         *  MATLAB Function: '<S269>/bit_shift'
         *  MATLAB Function: '<S270>/bit_shift'
         *  MATLAB Function: '<S271>/bit_shift'
         *  MATLAB Function: '<S272>/bit_shift'
         *  MATLAB Function: '<S275>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S254>/Compare'
         *  RelationalOperator: '<S255>/Compare'
         *  RelationalOperator: '<S256>/Compare'
         *  RelationalOperator: '<S257>/Compare'
         *  RelationalOperator: '<S258>/Compare'
         *  RelationalOperator: '<S259>/Compare'
         *  RelationalOperator: '<S260>/Compare'
         *  RelationalOperator: '<S280>/Compare'
         *  RelationalOperator: '<S283>/Compare'
         *  S-Function (sfix_bitop): '<S241>/p_cmd'
         *  S-Function (sfix_bitop): '<S241>/phi_cmd'
         *  S-Function (sfix_bitop): '<S241>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S241>/q_cmd'
         *  S-Function (sfix_bitop): '<S241>/r_cmd'
         *  S-Function (sfix_bitop): '<S241>/theta_cmd'
         *  S-Function (sfix_bitop): '<S241>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S261>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S262>/az_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         *  Sum: '<S241>/Add'
         */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
          ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
           ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
          (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_md) + rtb_y_c1)
          + (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
          (rtb_LogicalOperator_a4 << 9)) + (rtb_FixPtRelationalOperator_me << 10))
          + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

        /* End of Outputs for SubSystem: '<S241>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S241>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S241>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S37>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Mission' incorporates:
           *  ActionPort: '<S150>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  UnitDelay: '<S153>/Delay Input1'
           *
           * Block description for '<S153>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S37>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S37>/Mission' incorporates:
           *  ActionPort: '<S150>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S150>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S190>/Motion Status'
           *  Chart: '<S200>/Motion State'
           *  Delay: '<S158>/Delay'
           *  Delay: '<S180>/Delay'
           *  Delay: '<S180>/Delay1'
           *  DiscreteIntegrator: '<S161>/Integrator'
           *  DiscreteIntegrator: '<S161>/Integrator1'
           *  DiscreteIntegrator: '<S181>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S182>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S228>/Discrete-Time Integrator'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          FMS_DW.Delay1_DSTATE = false;
          FMS_DW.icLoad_h = 1U;
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S150>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S37>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Mission' incorporates:
         *  ActionPort: '<S150>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* RelationalOperator: '<S153>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S150>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S154>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S199>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S189>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for Delay: '<S180>/Delay1' */
          FMS_DW.Delay1_DSTATE = false;

          /* InitializeConditions for Delay: '<S180>/Delay' */
          FMS_DW.icLoad_h = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S181>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

          /* InitializeConditions for Delay: '<S158>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S200>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S190>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* DiscreteIntegrator: '<S182>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S175>/Compare' incorporates:
         *  Constant: '<S239>/Constant'
         *  RelationalOperator: '<S239>/Compare'
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* Logic: '<S180>/Logical Operator' incorporates:
         *  Delay: '<S180>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE);

        /* Delay: '<S180>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if ((((FMS_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) != (int32_T)
              rtb_LogicalOperator_aa) && (FMS_PrevZCX.Delay_Reset_ZCE !=
              UNINITIALIZED_ZCSIG)) || rtb_LogicalOperator_aa) {
          FMS_DW.icLoad_h = 1U;
        }

        FMS_PrevZCX.Delay_Reset_ZCE = rtb_LogicalOperator_aa;
        if (FMS_DW.icLoad_h != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_c[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_c[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* RelationalOperator: '<S186>/Compare' incorporates:
         *  Constant: '<S186>/Constant'
         *  Delay: '<S180>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S176>/Switch2' incorporates:
         *  Constant: '<S176>/vel'
         *  Delay: '<S180>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_a_l = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_a_l = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S176>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S180>/Sum' incorporates:
         *  Delay: '<S180>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_c[0];

        /* Sum: '<S181>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sqrt_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S180>/Sum' incorporates:
         *  Delay: '<S180>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_c[1];

        /* Sum: '<S181>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S238>/Sqrt' incorporates:
         *  Math: '<S238>/Square'
         *  Sum: '<S181>/Sum'
         *  Sum: '<S238>/Sum of Elements'
         */
        rtb_Sqrt_b = sqrtf(rtb_Sqrt_b * rtb_Sqrt_b + rtb_MathFunction_f_idx_1 *
                           rtb_MathFunction_f_idx_1);

        /* Gain: '<S181>/L1_GAIN' incorporates:
         *  Gain: '<S156>/Gain'
         */
        rtb_Saturation_n = FMS_PARAM.L1_GAIN * rtb_a_l;

        /* Switch: '<S181>/Switch' incorporates:
         *  Gain: '<S181>/L1_GAIN'
         *  Sum: '<S181>/Sum2'
         */
        if (rtb_Sqrt_b - rtb_Saturation_n >= 0.0F) {
          B = rtb_a_l;
        } else {
          /* Gain: '<S181>/Gain' */
          B = 0.5F * rtb_Sqrt_b;

          /* Switch: '<S236>/Switch2' incorporates:
           *  Constant: '<S181>/Constant1'
           *  RelationalOperator: '<S236>/LowerRelop1'
           *  RelationalOperator: '<S236>/UpperRelop'
           *  Switch: '<S236>/Switch'
           */
          if (B > rtb_a_l) {
            B = rtb_a_l;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S236>/Switch' incorporates:
               *  Constant: '<S181>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S236>/Switch2' */
        }

        /* End of Switch: '<S181>/Switch' */

        /* DiscreteIntegrator: '<S181>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Switch: '<S237>/Switch2' incorporates:
         *  Constant: '<S181>/Constant2'
         *  DiscreteIntegrator: '<S181>/Acceleration_Speed'
         *  RelationalOperator: '<S237>/LowerRelop1'
         *  RelationalOperator: '<S237>/UpperRelop'
         *  Switch: '<S237>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE > rtb_a_l) {
          rtb_Integrator1_a = rtb_a_l;
        } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
          /* Switch: '<S237>/Switch' incorporates:
           *  Constant: '<S181>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE;
        }

        /* End of Switch: '<S237>/Switch2' */

        /* Switch: '<S181>/Switch1' incorporates:
         *  Sum: '<S181>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Integrator1_a = B;
        }

        /* End of Switch: '<S181>/Switch1' */

        /* DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRese !=
             0)) {
          FMS_DW.l1_heading = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S200>/Motion State' incorporates:
         *  Constant: '<S200>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S200>/Square'
         *  Math: '<S200>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S200>/Sqrt'
         *  Sum: '<S200>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S199>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ai;
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_ai = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_ai = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_ai = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_ai) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ai != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S199>/Hold Control' incorporates:
             *  ActionPort: '<S202>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S199>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S199>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S199>/Hold Control' incorporates:
           *  ActionPort: '<S202>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S199>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S199>/Brake Control' incorporates:
           *  ActionPort: '<S201>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S199>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ai != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S199>/Move Control' incorporates:
             *  ActionPort: '<S203>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S199>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S199>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S199>/Move Control' incorporates:
           *  ActionPort: '<S203>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S199>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S199>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S190>/Motion Status' incorporates:
         *  Abs: '<S190>/Abs'
         *  Constant: '<S190>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S189>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S189>/Hold Control' incorporates:
             *  ActionPort: '<S192>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S189>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S189>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S189>/Hold Control' incorporates:
           *  ActionPort: '<S192>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e3,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S189>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S189>/Brake Control' incorporates:
           *  ActionPort: '<S191>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e3);

          /* End of Outputs for SubSystem: '<S189>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S189>/Move Control' incorporates:
             *  ActionPort: '<S193>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S189>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S189>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S189>/Move Control' incorporates:
           *  ActionPort: '<S193>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e3,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S189>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S189>/Switch Case' */

        /* Switch: '<S156>/Switch' incorporates:
         *  Product: '<S180>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S199>/Saturation1' */
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

          /* End of Saturate: '<S199>/Saturation1' */

          /* Saturate: '<S189>/Saturation1' */
          if (FMS_B.Merge_e3 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e3 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e3;
          }

          /* End of Saturate: '<S189>/Saturation1' */
        } else {
          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S235>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S234>/Gain' incorporates:
           *  DiscreteIntegrator: '<S228>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S228>/Add'
           */
          rtb_MathFunction_f_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S235>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_MathFunction_f_idx_0);

          /* Gain: '<S235>/Gain' incorporates:
           *  Trigonometry: '<S235>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_MathFunction_f_idx_0);

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S235>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_MathFunction_f_idx_0);

          /* Trigonometry: '<S235>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_MathFunction_f_idx_0);

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_d[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_d[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_d[2];

          /* Sum: '<S230>/Sum of Elements' incorporates:
           *  Math: '<S230>/Math Function'
           *  SignalConversion: '<S230>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_1 = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

          /* Math: '<S230>/Math Function1' incorporates:
           *  Sum: '<S230>/Sum of Elements'
           *
           * About '<S230>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_MathFunction_f_idx_0 = -sqrtf(fabsf(rtb_Divide_l_idx_1));
          } else {
            rtb_MathFunction_f_idx_0 = sqrtf(rtb_Divide_l_idx_1);
          }

          /* End of Math: '<S230>/Math Function1' */

          /* Switch: '<S230>/Switch' incorporates:
           *  Constant: '<S230>/Constant'
           *  Product: '<S230>/Product'
           */
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = rtb_Add3_c;
            rtb_Divide_l_idx_1 = rtb_Add4_d;
          } else {
            rtb_Divide_l_idx_0 = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_MathFunction_f_idx_0 = 1.0F;
          }

          /* End of Switch: '<S230>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S183>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_b = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S183>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_f_idx_2 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Switch_mp_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S183>/Divide' incorporates:
           *  Math: '<S184>/Square'
           *  Math: '<S185>/Square'
           *  Sqrt: '<S184>/Sqrt'
           *  Sqrt: '<S185>/Sqrt'
           *  Sum: '<S183>/Sum'
           *  Sum: '<S183>/Sum1'
           *  Sum: '<S184>/Sum of Elements'
           *  Sum: '<S185>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_MathFunction_f_idx_2 * rtb_MathFunction_f_idx_2
                             + rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1) /
            sqrtf(rtb_Sqrt_b * rtb_Sqrt_b + rtb_MathFunction_f_idx_1 *
                  rtb_MathFunction_f_idx_1);

          /* Saturate: '<S183>/Saturation' */
          if (rtb_Sqrt_b > 1.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            if (rtb_Sqrt_b < 0.0F) {
              rtb_Sqrt_b = 0.0F;
            }
          }

          /* End of Saturate: '<S183>/Saturation' */

          /* Product: '<S226>/Multiply2' incorporates:
           *  Product: '<S230>/Divide'
           */
          rtb_Divide_l_idx_0 = rtb_Divide_l_idx_0 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;

          /* Product: '<S180>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Divide_l_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_l_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S173>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S183>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S173>/Sum2'
           *  Sum: '<S183>/Add'
           *  Sum: '<S183>/Subtract'
           */
          rtb_Sqrt_b = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Sqrt_b +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S173>/Saturation1' incorporates:
           *  Product: '<S180>/Multiply'
           */
          if (rtb_Sqrt_b > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Sqrt_b < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Sqrt_b;
          }

          /* End of Saturate: '<S173>/Saturation1' */
        }

        /* End of Switch: '<S156>/Switch' */

        /* Delay: '<S158>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S161>/Integrator1' incorporates:
         *  Delay: '<S158>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S165>/Rem' incorporates:
         *  Constant: '<S165>/Constant1'
         *  DiscreteIntegrator: '<S161>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S160>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S165>/Switch' incorporates:
         *  Abs: '<S165>/Abs'
         *  Constant: '<S165>/Constant'
         *  Constant: '<S166>/Constant'
         *  Product: '<S165>/Multiply'
         *  RelationalOperator: '<S166>/Compare'
         *  Sum: '<S165>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S165>/Sign' */
          if (B < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (B > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = B;
          }

          /* End of Signum: '<S165>/Sign' */
          B -= 6.28318548F * rtb_Sqrt_b;
        }

        /* End of Switch: '<S165>/Switch' */

        /* Gain: '<S160>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S160>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S160>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S154>/Bus Assignment'
         *  Constant: '<S154>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S154>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Sum: '<S232>/Sum of Elements' incorporates:
         *  Math: '<S232>/Math Function'
         *  SignalConversion: '<S232>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Add4_d * rtb_Add4_d + rtb_Add3_c * rtb_Add3_c;

        /* Math: '<S232>/Math Function1' incorporates:
         *  Sum: '<S232>/Sum of Elements'
         *
         * About '<S232>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S232>/Math Function1' */

        /* Switch: '<S232>/Switch' incorporates:
         *  Constant: '<S232>/Constant'
         *  Product: '<S232>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Add4_d;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Add3_c;
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S232>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S220>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S220>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S220>/Math Function1' incorporates:
         *  Sum: '<S220>/Sum of Elements'
         *
         * About '<S220>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S220>/Math Function1' */

        /* Switch: '<S220>/Switch' incorporates:
         *  Constant: '<S220>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S220>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S220>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S154>/Sum' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S172>/Sum of Elements' incorporates:
         *  Math: '<S172>/Math Function'
         *  Sum: '<S154>/Sum'
         */
        rtb_Divide_l_idx_1 = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S172>/Math Function1' incorporates:
         *  Sum: '<S172>/Sum of Elements'
         *
         * About '<S172>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S172>/Math Function1' */

        /* Switch: '<S172>/Switch' incorporates:
         *  Constant: '<S172>/Constant'
         *  Product: '<S172>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S172>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S180>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_f3_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_f3_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S233>/Sum of Elements' incorporates:
         *  Math: '<S233>/Math Function'
         *  Sum: '<S180>/Sum1'
         */
        rtb_Divide_l_idx_1 = rtb_Switch_f3_idx_0 * rtb_Switch_f3_idx_0 +
          rtb_Switch_f3_idx_1 * rtb_Switch_f3_idx_1;

        /* Math: '<S233>/Math Function1' incorporates:
         *  Sum: '<S233>/Sum of Elements'
         *
         * About '<S233>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S233>/Math Function1' */

        /* Switch: '<S233>/Switch' incorporates:
         *  Constant: '<S233>/Constant'
         *  Product: '<S233>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_f3_idx_2 = B;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S233>/Switch' */

        /* Product: '<S220>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S223>/Sum of Elements' incorporates:
         *  Math: '<S223>/Math Function'
         *  SignalConversion: '<S223>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S223>/Math Function1' incorporates:
         *  Sum: '<S223>/Sum of Elements'
         *
         * About '<S223>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          B = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S223>/Math Function1' */

        /* Switch: '<S223>/Switch' incorporates:
         *  Constant: '<S223>/Constant'
         *  Product: '<S223>/Product'
         */
        if (B > 0.0F) {
          rtb_MathFunction_f_idx_0 = rtb_Sum_ff[1];
          rtb_MathFunction_f_idx_1 = rtb_Sum_ff[0];
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S223>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S178>/NearbyRefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, rtb_Saturation_n, rtb_Sum_ff,
                        &rtb_Divide_l_idx_1);

        /* MATLAB Function: '<S178>/SearchL1RefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sqrt_b = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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
                     rtb_Saturation_n * rtb_Saturation_n) * (4.0F * rtb_Sqrt_b);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Add4_d = 0.0F;
        rtb_Divide_l_idx_0 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Sqrt_b);
          rtb_Sqrt_b = (-B - u1_tmp) / (2.0F * rtb_Sqrt_b);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Sqrt_b >= 0.0F) && (rtb_Sqrt_b <=
               1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Sqrt_b);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Sqrt_b >= 0.0F) && (rtb_Sqrt_b <= 1.0F)) {
              rtb_Add3_c = rtb_Sqrt_b;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Sqrt_b);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Add4_d = (FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
                        [0]) * rtb_Add3_c + FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_0 = (FMS_B.Cmd_In.sp_waypoint[1] -
                                FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S178>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        B = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Sqrt_b = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) * B +
                      (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0]) *
                      rtb_P_l_idx_0) / (rtb_P_l_idx_0 * rtb_P_l_idx_0 + B * B);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Sqrt_b <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Sqrt_b >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = rtb_Sqrt_b * rtb_P_l_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Switch: '<S178>/Switch1' incorporates:
         *  Constant: '<S213>/Constant'
         *  RelationalOperator: '<S213>/Compare'
         */
        if (rtb_Divide_l_idx_1 <= 0.0F) {
          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S212>/Constant'
           *  MATLAB Function: '<S178>/SearchL1RefWP'
           *  RelationalOperator: '<S212>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Add4_d;
            rtb_Sum_ff[1] = rtb_Divide_l_idx_0;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S178>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else if (rtb_LogicalOperator_a4) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = rtb_Sqrt_b * B + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }
          }

          /* End of Switch: '<S178>/Switch' */
        }

        /* End of Switch: '<S178>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S179>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Sqrt_b;
        D = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S179>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S221>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S221>/Math Function' incorporates:
         *  Math: '<S219>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Sum: '<S221>/Sum of Elements' incorporates:
         *  Math: '<S221>/Math Function'
         */
        rtb_Rem_p = rtb_Divide_l_idx_1 + D;

        /* Math: '<S221>/Math Function1' incorporates:
         *  Sum: '<S221>/Sum of Elements'
         *
         * About '<S221>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S221>/Math Function1' */

        /* Switch: '<S221>/Switch' incorporates:
         *  Constant: '<S221>/Constant'
         *  Product: '<S221>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Sqrt_b;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S221>/Switch' */

        /* Product: '<S221>/Divide' */
        rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S224>/Sum of Elements' incorporates:
         *  Math: '<S224>/Math Function'
         *  SignalConversion: '<S224>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_Add3_c * rtb_Add3_c;

        /* Math: '<S224>/Math Function1' incorporates:
         *  Sum: '<S224>/Sum of Elements'
         *
         * About '<S224>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S224>/Math Function1' */

        /* Switch: '<S224>/Switch' incorporates:
         *  Constant: '<S224>/Constant'
         *  Product: '<S224>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = rtb_Add3_c;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S224>/Switch' */

        /* Product: '<S224>/Divide' */
        rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];

        /* Math: '<S219>/Square' */
        D = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S233>/Divide' */
        rtb_Add4_d = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S172>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S232>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S224>/Divide' incorporates:
         *  Product: '<S223>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S223>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S233>/Divide' */
        rtb_Divide_l_idx_0 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S172>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S232>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S231>/Subtract' incorporates:
         *  Product: '<S231>/Multiply'
         *  Product: '<S231>/Multiply1'
         */
        B = rtb_Add4_d * rtb_MathFunction_f_idx_1 - rtb_Divide_l_idx_0 *
          rtb_Switch_mp_idx_0;

        /* Signum: '<S227>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S227>/Sign1' */

        /* Switch: '<S227>/Switch2' incorporates:
         *  Constant: '<S227>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S227>/Switch2' */

        /* DotProduct: '<S227>/Dot Product' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_0 * rtb_Add4_d +
          rtb_MathFunction_f_idx_1 * rtb_Divide_l_idx_0;

        /* Trigonometry: '<S227>/Acos' incorporates:
         *  DotProduct: '<S227>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_1 > 1.0F) {
          rtb_MathFunction_f_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 < -1.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S227>/Multiply' incorporates:
         *  Trigonometry: '<S227>/Acos'
         */
        B *= acosf(rtb_MathFunction_f_idx_1);

        /* Abs: '<S180>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S225>/Compare' incorporates:
         *  Constant: '<S225>/Constant'
         *  Delay: '<S180>/Delay1'
         */
        FMS_DW.Delay1_DSTATE = (B > 1.57079637F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S218>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S218>/Square'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S218>/Sum of Elements'
         */
        rtb_Add4_d = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S179>/Square' */
        rtb_Divide_l_idx_0 = rtb_Add4_d * rtb_Add4_d;

        /* Sum: '<S222>/Subtract' incorporates:
         *  Product: '<S222>/Multiply'
         *  Product: '<S222>/Multiply1'
         */
        rtb_Add4_d = rtb_Add3_c * rtb_Sqrt_b - rtb_MathFunction_h_idx_1 *
          rtb_Sum_ff[0];

        /* Signum: '<S217>/Sign1' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S217>/Sign1' */

        /* Switch: '<S217>/Switch2' incorporates:
         *  Constant: '<S217>/Constant4'
         */
        if (rtb_Add4_d == 0.0F) {
          rtb_Add4_d = 1.0F;
        }

        /* End of Switch: '<S217>/Switch2' */

        /* DotProduct: '<S217>/Dot Product' */
        rtb_Sqrt_b = rtb_Sum_ff[0] * rtb_Add3_c + rtb_Sqrt_b *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S217>/Acos' incorporates:
         *  DotProduct: '<S217>/Dot Product'
         */
        if (rtb_Sqrt_b > 1.0F) {
          rtb_Sqrt_b = 1.0F;
        } else {
          if (rtb_Sqrt_b < -1.0F) {
            rtb_Sqrt_b = -1.0F;
          }
        }

        /* Product: '<S217>/Multiply' incorporates:
         *  Trigonometry: '<S217>/Acos'
         */
        rtb_Add4_d *= acosf(rtb_Sqrt_b);

        /* Saturate: '<S179>/Saturation' */
        if (rtb_Add4_d > 1.57079637F) {
          rtb_Add4_d = 1.57079637F;
        } else {
          if (rtb_Add4_d < -1.57079637F) {
            rtb_Add4_d = -1.57079637F;
          }
        }

        /* End of Saturate: '<S179>/Saturation' */

        /* Switch: '<S229>/Switch2' incorporates:
         *  Constant: '<S180>/Constant1'
         *  RelationalOperator: '<S229>/LowerRelop1'
         *  RelationalOperator: '<S229>/UpperRelop'
         *  Switch: '<S229>/Switch'
         */
        if (rtb_Integrator1_a > rtb_a_l) {
          rtb_Integrator1_a = rtb_a_l;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S229>/Switch' incorporates:
             *  Constant: '<S180>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S229>/Switch2' */

        /* Product: '<S180>/Divide1' incorporates:
         *  Constant: '<S179>/Constant'
         *  Gain: '<S179>/Gain'
         *  MinMax: '<S179>/Max'
         *  MinMax: '<S179>/Min'
         *  Product: '<S179>/Divide'
         *  Product: '<S179>/Multiply1'
         *  Sqrt: '<S219>/Sqrt'
         *  Sum: '<S219>/Sum of Elements'
         *  Trigonometry: '<S179>/Sin'
         */
        rtb_Add4_d = 2.0F * rtb_Divide_l_idx_0 * arm_sin_f32(rtb_Add4_d) / fminf
          (rtb_Saturation_n, fmaxf(sqrtf(rtb_Divide_l_idx_1 + D), 0.5F)) /
          rtb_Integrator1_a;

        /* Saturate: '<S180>/Saturation' */
        if (rtb_Add4_d > 0.314159274F) {
          rtb_a_l = 0.314159274F;
        } else if (rtb_Add4_d < -0.314159274F) {
          rtb_a_l = -0.314159274F;
        } else {
          rtb_a_l = rtb_Add4_d;
        }

        /* End of Saturate: '<S180>/Saturation' */

        /* Sum: '<S170>/Subtract' incorporates:
         *  Product: '<S170>/Multiply'
         *  Product: '<S170>/Multiply1'
         */
        rtb_Add4_d = rtb_P_l_idx_0 * FMS_ConstB.Divide[1] -
          rtb_MathFunction_f_idx_0 * FMS_ConstB.Divide[0];

        /* Signum: '<S159>/Sign1' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign1' */

        /* Switch: '<S159>/Switch2' incorporates:
         *  Constant: '<S159>/Constant4'
         */
        if (rtb_Add4_d == 0.0F) {
          rtb_Add4_d = 1.0F;
        }

        /* End of Switch: '<S159>/Switch2' */

        /* DotProduct: '<S159>/Dot Product' */
        rtb_Sqrt_b = FMS_ConstB.Divide[0] * rtb_P_l_idx_0 + FMS_ConstB.Divide[1]
          * rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S159>/Acos' incorporates:
         *  DotProduct: '<S159>/Dot Product'
         */
        if (rtb_Sqrt_b > 1.0F) {
          rtb_Sqrt_b = 1.0F;
        } else {
          if (rtb_Sqrt_b < -1.0F) {
            rtb_Sqrt_b = -1.0F;
          }
        }

        /* Product: '<S159>/Multiply' incorporates:
         *  Trigonometry: '<S159>/Acos'
         */
        rtb_Add4_d *= acosf(rtb_Sqrt_b);

        /* Math: '<S162>/Rem' incorporates:
         *  Constant: '<S162>/Constant1'
         *  Delay: '<S158>/Delay'
         *  Sum: '<S158>/Sum2'
         */
        B = rt_remf(rtb_Add4_d - FMS_DW.Delay_DSTATE_h, 6.28318548F);

        /* Switch: '<S162>/Switch' incorporates:
         *  Abs: '<S162>/Abs'
         *  Constant: '<S162>/Constant'
         *  Constant: '<S168>/Constant'
         *  Product: '<S162>/Multiply'
         *  RelationalOperator: '<S168>/Compare'
         *  Sum: '<S162>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S162>/Sign' */
          if (B < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (B > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = B;
          }

          /* End of Signum: '<S162>/Sign' */
          B -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Sum: '<S158>/Sum' incorporates:
         *  Delay: '<S158>/Delay'
         */
        rtb_Saturation_n = B + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S167>/Multiply1' incorporates:
         *  Constant: '<S167>/const1'
         *  DiscreteIntegrator: '<S161>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S167>/Add' incorporates:
         *  DiscreteIntegrator: '<S161>/Integrator1'
         *  Sum: '<S161>/Subtract'
         */
        rtb_Saturation_n = (FMS_DW.Integrator1_DSTATE_p - rtb_Saturation_n) + B;

        /* Signum: '<S167>/Sign' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Saturation_n;
        }

        /* End of Signum: '<S167>/Sign' */

        /* Sum: '<S167>/Add2' incorporates:
         *  Abs: '<S167>/Abs'
         *  Gain: '<S167>/Gain'
         *  Gain: '<S167>/Gain1'
         *  Product: '<S167>/Multiply2'
         *  Product: '<S167>/Multiply3'
         *  Sqrt: '<S167>/Sqrt'
         *  Sum: '<S167>/Add1'
         *  Sum: '<S167>/Subtract'
         */
        rtb_Divide_l_idx_1 = (sqrtf((8.0F * fabsf(rtb_Saturation_n) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c + B;

        /* Sum: '<S167>/Add4' */
        rtb_Sqrt_b = (rtb_Saturation_n - rtb_Divide_l_idx_1) + B;

        /* Sum: '<S167>/Add3' */
        rtb_Add3_c = rtb_Saturation_n + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract1' */
        rtb_Saturation_n -= FMS_ConstB.d;

        /* Signum: '<S167>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign1' */

        /* Signum: '<S167>/Sign2' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign2' */

        /* Sum: '<S167>/Add5' incorporates:
         *  Gain: '<S167>/Gain2'
         *  Product: '<S167>/Multiply4'
         *  Sum: '<S167>/Subtract2'
         */
        rtb_Divide_l_idx_1 += (rtb_Add3_c - rtb_Saturation_n) * 0.5F *
          rtb_Sqrt_b;

        /* Sum: '<S167>/Add6' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract3' */
        rtb_Sqrt_b = rtb_Divide_l_idx_1 - FMS_ConstB.d;

        /* Product: '<S167>/Divide' */
        rtb_Integrator1_a = rtb_Divide_l_idx_1 / FMS_ConstB.d;

        /* Signum: '<S167>/Sign5' incorporates:
         *  Signum: '<S167>/Sign6'
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_Divide_l_idx_0 = 1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Divide_l_idx_0 = rtb_Divide_l_idx_1;

          /* Signum: '<S167>/Sign6' */
          rtb_Saturation_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S167>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S158>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Add4_d -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S163>/Rem' incorporates:
         *  Constant: '<S163>/Constant1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_Add4_d, 6.28318548F);

        /* Switch: '<S163>/Switch' incorporates:
         *  Abs: '<S163>/Abs'
         *  Constant: '<S163>/Constant'
         *  Constant: '<S169>/Constant'
         *  Product: '<S163>/Multiply'
         *  RelationalOperator: '<S169>/Compare'
         *  Sum: '<S163>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S163>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Add4_d = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Add4_d = 1.0F;
          } else {
            rtb_Add4_d = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S163>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Add4_d;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Abs: '<S156>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S174>/Constant'
         *  RelationalOperator: '<S174>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_Divide_l_idx_1 <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */

        /* Update for Delay: '<S180>/Delay' */
        FMS_DW.icLoad_h = 0U;

        /* Update for DiscreteIntegrator: '<S181>/Acceleration_Speed' incorporates:
         *  Constant: '<S181>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_a_l;
        FMS_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S158>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S161>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S161>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Signum: '<S167>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign3' */

        /* Signum: '<S167>/Sign4' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign4' */

        /* Update for DiscreteIntegrator: '<S161>/Integrator' incorporates:
         *  Constant: '<S167>/const'
         *  Gain: '<S167>/Gain3'
         *  Product: '<S167>/Multiply5'
         *  Product: '<S167>/Multiply6'
         *  Sum: '<S167>/Subtract4'
         *  Sum: '<S167>/Subtract5'
         *  Sum: '<S167>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Integrator1_a - rtb_Divide_l_idx_0) *
          FMS_ConstB.Gain4 * ((rtb_Add3_c - rtb_Sqrt_b) * 0.5F) -
          rtb_Saturation_n * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S161>/Integrator' */
        /* End of Outputs for SubSystem: '<S150>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Update for UnitDelay: '<S153>/Delay Input1' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S37>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S152>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S37>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S37>/Switch Case' */
      /* End of Outputs for SubSystem: '<S32>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S32>/Assist' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* SwitchCase: '<S36>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S138>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S71>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S109>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S97>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S36>/Acro' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S41>/Bus Assignment'
         *  Constant: '<S41>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S41>/Bus Assignment' incorporates:
         *  Gain: '<S46>/Gain'
         *  Gain: '<S46>/Gain1'
         *  Gain: '<S46>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S47>/Saturation' incorporates:
         *  Constant: '<S47>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         *  Sum: '<S47>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S47>/Saturation' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S41>/Bus Assignment' incorporates:
         *  Constant: '<S47>/Constant5'
         *  Gain: '<S47>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S47>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_n), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S36>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Stabilize' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S132>/Integrator'
           *  DiscreteIntegrator: '<S132>/Integrator1'
           *  DiscreteIntegrator: '<S133>/Integrator'
           *  DiscreteIntegrator: '<S133>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_k = 0.0F;
          FMS_DW.Integrator_DSTATE_a = 0.0F;
          FMS_DW.Integrator1_DSTATE_nf = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S36>/Stabilize' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S139>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S36>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Stabilize' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S130>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S130>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S130>/Gain' */
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S131>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S131>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S131>/Gain' */
        rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Math: '<S134>/Square'
         *  SignalConversion: '<S134>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S135>/Sum of Elements'
         *  Switch: '<S126>/Switch'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

        /* Switch: '<S126>/Switch' incorporates:
         *  Constant: '<S129>/Constant'
         *  Product: '<S135>/Divide'
         *  RelationalOperator: '<S129>/Compare'
         *  Sqrt: '<S134>/Sqrt'
         *  Sum: '<S134>/Sum of Elements'
         */
        if (sqrtf(rtb_Saturation_n) > 1.0F) {
          /* Math: '<S135>/Math Function1'
           *
           * About '<S135>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S135>/Math Function1' */

          /* Switch: '<S135>/Switch' incorporates:
           *  Constant: '<S135>/Constant'
           *  Product: '<S135>/Product'
           */
          if (rtb_Saturation_n > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_Add4_d;
            rtb_MatrixConcatenate3[2] = rtb_Saturation_n;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S135>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Add4_d = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Logic: '<S126>/Logical Operator' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S136>/Multiply1' incorporates:
         *  Constant: '<S136>/const1'
         *  DiscreteIntegrator: '<S132>/Integrator'
         */
        rtb_a_l = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S136>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S132>/Integrator1'
         *  Gain: '<S126>/Gain'
         *  Product: '<S126>/Multiply'
         *  Sum: '<S132>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_k -
                             FMS_PARAM.ROLL_PITCH_LIM * rtb_Add3_c * (real32_T)
                             rtb_FixPtRelationalOperator_me) + rtb_a_l;

        /* Saturate: '<S136>/Saturation' incorporates:
         *  Constant: '<S132>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S136>/Saturation' */

        /* Product: '<S136>/Multiply7' incorporates:
         *  Constant: '<S136>/const'
         */
        rtb_Divide_l_idx_0 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S136>/Multiply' */
        rtb_Divide_l_idx_1 = rtb_Divide_l_idx_0 * FMS_ConstB.Square_c;

        /* Signum: '<S136>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Integrator1_a;
        }

        /* End of Signum: '<S136>/Sign' */

        /* Sum: '<S136>/Add2' incorporates:
         *  Abs: '<S136>/Abs'
         *  Gain: '<S136>/Gain'
         *  Gain: '<S136>/Gain1'
         *  Product: '<S136>/Multiply2'
         *  Product: '<S136>/Multiply3'
         *  Sqrt: '<S136>/Sqrt'
         *  Sum: '<S136>/Add1'
         *  Sum: '<S136>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
          rtb_Divide_l_idx_1) * rtb_Divide_l_idx_1) - rtb_Divide_l_idx_1) * 0.5F
          * rtb_Saturation_n + rtb_a_l;

        /* Sum: '<S136>/Add4' */
        rtb_Sqrt_b = (rtb_Integrator1_a - rtb_Saturation_n) + rtb_a_l;

        /* Sum: '<S136>/Add3' */
        rtb_Add3_c = rtb_Integrator1_a + rtb_Divide_l_idx_1;

        /* Sum: '<S136>/Subtract1' */
        rtb_Integrator1_a -= rtb_Divide_l_idx_1;

        /* Signum: '<S136>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign1' */

        /* Signum: '<S136>/Sign2' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign2' */

        /* Sum: '<S136>/Add5' incorporates:
         *  Gain: '<S136>/Gain2'
         *  Product: '<S136>/Multiply4'
         *  Sum: '<S136>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Integrator1_a) * 0.5F * rtb_Sqrt_b;

        /* Sum: '<S136>/Add6' */
        rtb_Add3_c = rtb_Saturation_n + rtb_Divide_l_idx_1;

        /* Sum: '<S136>/Subtract3' */
        rtb_Sqrt_b = rtb_Saturation_n - rtb_Divide_l_idx_1;

        /* Signum: '<S136>/Sign5' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_l = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_a_l = 1.0F;
        } else {
          rtb_a_l = rtb_Saturation_n;
        }

        /* End of Signum: '<S136>/Sign5' */

        /* Signum: '<S136>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign3' */

        /* Signum: '<S136>/Sign4' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign4' */

        /* Product: '<S136>/Multiply5' incorporates:
         *  Gain: '<S136>/Gain3'
         *  Gain: '<S136>/Gain4'
         *  Product: '<S136>/Divide'
         *  Sum: '<S136>/Subtract4'
         *  Sum: '<S136>/Subtract5'
         */
        rtb_Sqrt_b = (rtb_Saturation_n / rtb_Divide_l_idx_1 - rtb_a_l) *
          -rtb_Divide_l_idx_0 * ((rtb_Add3_c - rtb_Sqrt_b) * 0.5F);

        /* Signum: '<S136>/Sign6' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign6' */

        /* Product: '<S136>/Multiply6' */
        rtb_MathFunction_f_idx_0 = rtb_Saturation_n * rtb_Divide_l_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S139>/Motion State' incorporates:
         *  Abs: '<S139>/Abs'
         *  Abs: '<S139>/Abs1'
         *  Constant: '<S148>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S148>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S138>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_fs;
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_fs) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S138>/Hold Control' incorporates:
             *  ActionPort: '<S140>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S138>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S138>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S138>/Hold Control' incorporates:
           *  ActionPort: '<S140>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S138>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S138>/Move Control' incorporates:
             *  ActionPort: '<S141>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S138>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S138>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S138>/Move Control' incorporates:
           *  ActionPort: '<S141>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S138>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S138>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S128>/Switch' incorporates:
         *  Constant: '<S128>/Constant'
         *  Constant: '<S128>/Constant4'
         *  Constant: '<S128>/Constant5'
         *  Gain: '<S128>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Saturate: '<S128>/Saturation'
         *  SignalConversion: '<S31>/Signal Copy2'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         *  Sum: '<S128>/Add'
         *  Sum: '<S128>/Sum'
         */
        if (FMS_B.Compare) {
          rtb_y_md = FMS_PARAM.LAND_LOCK_THRO;
        } else {
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            /* Saturate: '<S128>/Saturation' */
            rtb_Saturation_n = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S128>/Saturation' */
            rtb_Saturation_n = 0.0F;
          } else {
            /* Saturate: '<S128>/Saturation' incorporates:
             *  Constant: '<S128>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S31>/Signal Copy2'
             *  Sum: '<S128>/Sum'
             */
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_Saturation_n),
            65536.0F) + 1000U);
        }

        /* End of Switch: '<S128>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S44>/Bus Assignment'
         *  Constant: '<S44>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S44>/Bus Assignment' incorporates:
         *  DiscreteIntegrator: '<S132>/Integrator1'
         *  DiscreteIntegrator: '<S133>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_k;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_nf;

        /* Saturate: '<S138>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S138>/Saturation' */

        /* BusAssignment: '<S44>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.throttle_cmd = rtb_y_md;

        /* Product: '<S137>/Multiply1' incorporates:
         *  Constant: '<S137>/const1'
         *  DiscreteIntegrator: '<S133>/Integrator'
         */
        rtb_Divide_l_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S137>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S133>/Integrator1'
         *  Gain: '<S126>/Gain1'
         *  Product: '<S126>/Multiply1'
         *  Sum: '<S133>/Subtract'
         */
        rtb_Divide_l_idx_0 = (FMS_DW.Integrator1_DSTATE_nf -
                              -FMS_PARAM.ROLL_PITCH_LIM * rtb_Add4_d * (real32_T)
                              rtb_FixPtRelationalOperator_me) +
          rtb_Divide_l_idx_1;

        /* Saturate: '<S137>/Saturation' incorporates:
         *  Constant: '<S133>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S137>/Saturation' */

        /* Product: '<S137>/Multiply7' incorporates:
         *  Constant: '<S137>/const'
         */
        rtb_Integrator1_a = 31.415926F * rtb_Saturation_n;

        /* Product: '<S137>/Multiply' */
        rtb_a_l = rtb_Integrator1_a * FMS_ConstB.Square_b;

        /* Signum: '<S137>/Sign' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S137>/Sign' */

        /* Sum: '<S137>/Add2' incorporates:
         *  Abs: '<S137>/Abs'
         *  Gain: '<S137>/Gain'
         *  Gain: '<S137>/Gain1'
         *  Product: '<S137>/Multiply2'
         *  Product: '<S137>/Multiply3'
         *  Sqrt: '<S137>/Sqrt'
         *  Sum: '<S137>/Add1'
         *  Sum: '<S137>/Subtract'
         */
        rtb_MathFunction_f_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_0) +
          rtb_a_l) * rtb_a_l) - rtb_a_l) * 0.5F * rtb_Saturation_n +
          rtb_Divide_l_idx_1;

        /* Sum: '<S137>/Add4' */
        rtb_Saturation_n = (rtb_Divide_l_idx_0 - rtb_MathFunction_f_idx_1) +
          rtb_Divide_l_idx_1;

        /* Sum: '<S137>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_0 + rtb_a_l;

        /* Sum: '<S137>/Subtract1' */
        rtb_Divide_l_idx_0 -= rtb_a_l;

        /* Signum: '<S137>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign1' */

        /* Signum: '<S137>/Sign2' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign2' */

        /* Sum: '<S137>/Add5' incorporates:
         *  Gain: '<S137>/Gain2'
         *  Product: '<S137>/Multiply4'
         *  Sum: '<S137>/Subtract2'
         */
        rtb_MathFunction_f_idx_1 += (rtb_Add3_c - rtb_Divide_l_idx_0) * 0.5F *
          rtb_Saturation_n;

        /* Update for DiscreteIntegrator: '<S132>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S132>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Update for DiscreteIntegrator: '<S132>/Integrator' incorporates:
         *  Sum: '<S136>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += (rtb_Sqrt_b - rtb_MathFunction_f_idx_0) *
          0.004F;

        /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S133>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_nf += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S137>/Subtract3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_1 - rtb_a_l;

        /* Sum: '<S137>/Add6' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_1 + rtb_a_l;

        /* Signum: '<S137>/Sign5' incorporates:
         *  Signum: '<S137>/Sign6'
         */
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Add4_d = -1.0F;
        } else if (rtb_MathFunction_f_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_1;

          /* Signum: '<S137>/Sign6' */
          rtb_Add4_d = rtb_MathFunction_f_idx_1;
        }

        /* End of Signum: '<S137>/Sign5' */

        /* Signum: '<S137>/Sign3' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign3' */

        /* Signum: '<S137>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign4' */

        /* Update for DiscreteIntegrator: '<S133>/Integrator' incorporates:
         *  Gain: '<S137>/Gain3'
         *  Gain: '<S137>/Gain4'
         *  Product: '<S137>/Divide'
         *  Product: '<S137>/Multiply5'
         *  Product: '<S137>/Multiply6'
         *  Sum: '<S137>/Subtract4'
         *  Sum: '<S137>/Subtract5'
         *  Sum: '<S137>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_MathFunction_f_idx_1 / rtb_a_l -
          rtb_Saturation_n) * -rtb_Integrator1_a * ((rtb_Sqrt_b - rtb_Add3_c) *
          0.5F) - rtb_Add4_d * rtb_Integrator1_a) * 0.004F;

        /* End of Outputs for SubSystem: '<S36>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Altitude' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S65>/Integrator'
           *  DiscreteIntegrator: '<S65>/Integrator1'
           *  DiscreteIntegrator: '<S66>/Integrator'
           *  DiscreteIntegrator: '<S66>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_n = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_i = 0.0F;
          FMS_DW.Integrator_DSTATE_g = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S36>/Altitude' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S52>/Motion Status'
           *  Chart: '<S72>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_b);

          /* End of SystemReset for SubSystem: '<S36>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Altitude' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S63>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S63>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S63>/Gain' */
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S64>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S64>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S64>/Gain' */
        rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

        /* Sum: '<S67>/Sum of Elements' incorporates:
         *  Math: '<S67>/Square'
         *  SignalConversion: '<S67>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S68>/Sum of Elements'
         *  Switch: '<S49>/Switch'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

        /* Switch: '<S49>/Switch' incorporates:
         *  Constant: '<S62>/Constant'
         *  Product: '<S68>/Divide'
         *  RelationalOperator: '<S62>/Compare'
         *  Sqrt: '<S67>/Sqrt'
         *  Sum: '<S67>/Sum of Elements'
         */
        if (sqrtf(rtb_Saturation_n) > 1.0F) {
          /* Math: '<S68>/Math Function1'
           *
           * About '<S68>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S68>/Math Function1' */

          /* Switch: '<S68>/Switch' incorporates:
           *  Constant: '<S68>/Constant'
           *  Product: '<S68>/Product'
           */
          if (rtb_Saturation_n > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_Add4_d;
            rtb_MatrixConcatenate3[2] = rtb_Saturation_n;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S68>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Add4_d = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Logic: '<S49>/Logical Operator' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S69>/Multiply1' incorporates:
         *  Constant: '<S69>/const1'
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        rtb_a_l = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S69>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  Gain: '<S49>/Gain'
         *  Product: '<S49>/Multiply'
         *  Sum: '<S65>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_n -
                             FMS_PARAM.ROLL_PITCH_LIM * rtb_Add3_c * (real32_T)
                             rtb_FixPtRelationalOperator_me) + rtb_a_l;

        /* Saturate: '<S69>/Saturation' incorporates:
         *  Constant: '<S65>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S69>/Saturation' */

        /* Product: '<S69>/Multiply7' incorporates:
         *  Constant: '<S69>/const'
         */
        rtb_Divide_l_idx_0 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S69>/Multiply' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 * FMS_ConstB.Square_m;

        /* Signum: '<S69>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Integrator1_a;
        }

        /* End of Signum: '<S69>/Sign' */

        /* Sum: '<S69>/Add2' incorporates:
         *  Abs: '<S69>/Abs'
         *  Gain: '<S69>/Gain'
         *  Gain: '<S69>/Gain1'
         *  Product: '<S69>/Multiply2'
         *  Product: '<S69>/Multiply3'
         *  Sqrt: '<S69>/Sqrt'
         *  Sum: '<S69>/Add1'
         *  Sum: '<S69>/Subtract'
         */
        rtb_Divide_l_idx_1 = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
          rtb_Saturation_n) * rtb_Saturation_n) - rtb_Saturation_n) * 0.5F *
          rtb_Add3_c + rtb_a_l;

        /* Sum: '<S69>/Add4' */
        rtb_Sqrt_b = (rtb_Integrator1_a - rtb_Divide_l_idx_1) + rtb_a_l;

        /* Sum: '<S69>/Add3' */
        rtb_Add3_c = rtb_Integrator1_a + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract1' */
        rtb_Integrator1_a -= rtb_Saturation_n;

        /* Signum: '<S69>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign1' */

        /* Signum: '<S69>/Sign2' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign2' */

        /* Sum: '<S69>/Add5' incorporates:
         *  Gain: '<S69>/Gain2'
         *  Product: '<S69>/Multiply4'
         *  Sum: '<S69>/Subtract2'
         */
        rtb_Divide_l_idx_1 += (rtb_Add3_c - rtb_Integrator1_a) * 0.5F *
          rtb_Sqrt_b;

        /* Sum: '<S69>/Add6' */
        rtb_Add3_c = rtb_Divide_l_idx_1 + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract3' */
        rtb_Sqrt_b = rtb_Divide_l_idx_1 - rtb_Saturation_n;

        /* Signum: '<S69>/Sign5' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_a_l = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_a_l = 1.0F;
        } else {
          rtb_a_l = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S69>/Sign5' */

        /* Signum: '<S69>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign3' */

        /* Signum: '<S69>/Sign4' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign4' */

        /* Product: '<S69>/Multiply5' incorporates:
         *  Gain: '<S69>/Gain3'
         *  Gain: '<S69>/Gain4'
         *  Product: '<S69>/Divide'
         *  Sum: '<S69>/Subtract4'
         *  Sum: '<S69>/Subtract5'
         */
        rtb_Sqrt_b = (rtb_Divide_l_idx_1 / rtb_Saturation_n - rtb_a_l) *
          -rtb_Divide_l_idx_0 * ((rtb_Add3_c - rtb_Sqrt_b) * 0.5F);

        /* Signum: '<S69>/Sign6' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign6' */

        /* Product: '<S69>/Multiply6' */
        rtb_MathFunction_f_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S52>/Motion Status' incorporates:
         *  Abs: '<S52>/Abs'
         *  Abs: '<S52>/Abs1'
         *  Constant: '<S60>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S60>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S51>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_m) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S51>/Hold Control' incorporates:
             *  ActionPort: '<S53>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S51>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S51>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S51>/Hold Control' incorporates:
           *  ActionPort: '<S53>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_lf,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S51>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S51>/Move Control' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_lf);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S51>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S51>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S48>/Switch' incorporates:
         *  Constant: '<S48>/Constant'
         *  Saturate: '<S51>/Saturation1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        if (FMS_B.Compare) {
          rtb_Divide_l_idx_1 = 0.5F;
        } else if (FMS_B.Merge_lf > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Divide_l_idx_1 = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_lf < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Divide_l_idx_1 = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Divide_l_idx_1 = FMS_B.Merge_lf;
        }

        /* End of Switch: '<S48>/Switch' */

        /* Chart: '<S72>/Motion State' incorporates:
         *  Abs: '<S72>/Abs'
         *  Abs: '<S72>/Abs1'
         *  Constant: '<S81>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S81>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_b);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S71>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_mn;
        FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_mn = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_mn = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_mn) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_mn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S71>/Hold Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S71>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_hb);

            /* End of SystemReset for SubSystem: '<S71>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S71>/Hold Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                            &FMS_DW.HoldControl_hb);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S71>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_mn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S71>/Move Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S71>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S71>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S71>/Move Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S71>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S71>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S42>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_n;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_i;

        /* Saturate: '<S71>/Saturation' */
        if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;
        }

        /* End of Saturate: '<S71>/Saturation' */

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Divide_l_idx_1;

        /* Product: '<S70>/Multiply1' incorporates:
         *  Constant: '<S70>/const1'
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        rtb_Divide_l_idx_1 = FMS_DW.Integrator_DSTATE_g * 0.04F;

        /* Sum: '<S70>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Gain: '<S49>/Gain1'
         *  Product: '<S49>/Multiply1'
         *  Sum: '<S66>/Subtract'
         */
        rtb_Divide_l_idx_0 = (FMS_DW.Integrator1_DSTATE_i -
                              -FMS_PARAM.ROLL_PITCH_LIM * rtb_Add4_d * (real32_T)
                              rtb_FixPtRelationalOperator_me) +
          rtb_Divide_l_idx_1;

        /* Saturate: '<S70>/Saturation' incorporates:
         *  Constant: '<S66>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S70>/Saturation' */

        /* Product: '<S70>/Multiply7' incorporates:
         *  Constant: '<S70>/const'
         */
        rtb_Integrator1_a = 31.415926F * rtb_Saturation_n;

        /* Product: '<S70>/Multiply' */
        rtb_a_l = rtb_Integrator1_a * FMS_ConstB.Square_i;

        /* Signum: '<S70>/Sign' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S70>/Sign' */

        /* Sum: '<S70>/Add2' incorporates:
         *  Abs: '<S70>/Abs'
         *  Gain: '<S70>/Gain'
         *  Gain: '<S70>/Gain1'
         *  Product: '<S70>/Multiply2'
         *  Product: '<S70>/Multiply3'
         *  Sqrt: '<S70>/Sqrt'
         *  Sum: '<S70>/Add1'
         *  Sum: '<S70>/Subtract'
         */
        rtb_MathFunction_f_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_0) +
          rtb_a_l) * rtb_a_l) - rtb_a_l) * 0.5F * rtb_Saturation_n +
          rtb_Divide_l_idx_1;

        /* Sum: '<S70>/Add4' */
        rtb_Saturation_n = (rtb_Divide_l_idx_0 - rtb_MathFunction_f_idx_1) +
          rtb_Divide_l_idx_1;

        /* Sum: '<S70>/Add3' */
        rtb_Add3_c = rtb_Divide_l_idx_0 + rtb_a_l;

        /* Sum: '<S70>/Subtract1' */
        rtb_Divide_l_idx_0 -= rtb_a_l;

        /* Signum: '<S70>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign1' */

        /* Signum: '<S70>/Sign2' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign2' */

        /* Sum: '<S70>/Add5' incorporates:
         *  Gain: '<S70>/Gain2'
         *  Product: '<S70>/Multiply4'
         *  Sum: '<S70>/Subtract2'
         */
        rtb_MathFunction_f_idx_1 += (rtb_Add3_c - rtb_Divide_l_idx_0) * 0.5F *
          rtb_Saturation_n;

        /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
         *  Sum: '<S69>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Sqrt_b - rtb_MathFunction_f_idx_0) *
          0.004F;

        /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_i += 0.004F * FMS_DW.Integrator_DSTATE_g;

        /* Sum: '<S70>/Subtract3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_1 - rtb_a_l;

        /* Sum: '<S70>/Add6' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_1 + rtb_a_l;

        /* Signum: '<S70>/Sign5' incorporates:
         *  Signum: '<S70>/Sign6'
         */
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Add4_d = -1.0F;
        } else if (rtb_MathFunction_f_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_1;

          /* Signum: '<S70>/Sign6' */
          rtb_Add4_d = rtb_MathFunction_f_idx_1;
        }

        /* End of Signum: '<S70>/Sign5' */

        /* Signum: '<S70>/Sign3' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign3' */

        /* Signum: '<S70>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign4' */

        /* Update for DiscreteIntegrator: '<S66>/Integrator' incorporates:
         *  Gain: '<S70>/Gain3'
         *  Gain: '<S70>/Gain4'
         *  Product: '<S70>/Divide'
         *  Product: '<S70>/Multiply5'
         *  Product: '<S70>/Multiply6'
         *  Sum: '<S70>/Subtract4'
         *  Sum: '<S70>/Subtract5'
         *  Sum: '<S70>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_g += ((rtb_MathFunction_f_idx_1 / rtb_a_l -
          rtb_Saturation_n) * -rtb_Integrator1_a * ((rtb_Sqrt_b - rtb_Add3_c) *
          0.5F) - rtb_Add4_d * rtb_Integrator1_a) * 0.004F;

        /* End of Outputs for SubSystem: '<S36>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S36>/Position' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S110>/Motion State'
           *  Chart: '<S87>/Motion Status'
           *  Chart: '<S98>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_h);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_l);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S36>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Position' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S87>/Motion Status' incorporates:
         *  Abs: '<S87>/Abs'
         *  Abs: '<S87>/Abs1'
         *  Constant: '<S95>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S95>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_h);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S86>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S86>/Hold Control' incorporates:
             *  ActionPort: '<S88>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S86>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_c);

            /* End of SystemReset for SubSystem: '<S86>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Hold Control' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S86>/Move Control' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S86>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S98>/Motion State' incorporates:
         *  Abs: '<S98>/Abs'
         *  Abs: '<S98>/Abs1'
         *  Constant: '<S107>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S107>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_l);

        /* Logic: '<S110>/Logical Operator' incorporates:
         *  Abs: '<S110>/Abs1'
         *  Abs: '<S110>/Abs2'
         *  Constant: '<S123>/Constant'
         *  Constant: '<S124>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S123>/Compare'
         *  RelationalOperator: '<S124>/Compare'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S110>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S110>/Square'
         *  Math: '<S110>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S110>/Sqrt'
         *  Sum: '<S110>/Add'
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

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.25F) ||
                (FMS_DW.temporalCounter_i1_i >= 750U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_ki = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
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

        /* End of Chart: '<S110>/Motion State' */

        /* SwitchCase: '<S109>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_ki) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_l = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_l) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S109>/Hold Control' incorporates:
             *  ActionPort: '<S111>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S109>/Switch Case' incorporates:
             *  Delay: '<S111>/Delay'
             */
            FMS_DW.icLoad = 1U;

            /* End of InitializeConditions for SubSystem: '<S109>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S109>/Hold Control' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          /* Delay: '<S111>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S115>/Trigonometric Function1' incorporates:
           *  Gain: '<S114>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S115>/Trigonometric Function' incorporates:
           *  Gain: '<S114>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S115>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S115>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S115>/Gain' incorporates:
           *  Gain: '<S114>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S115>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S115>/Trigonometric Function3' incorporates:
           *  Gain: '<S114>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S115>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S115>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* SignalConversion: '<S115>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S111>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S111>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S111>/Sum'
           */
          rtb_a_l = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_a = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S111>/Multiply' incorporates:
           *  SignalConversion: '<S111>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l;
          }

          /* End of Product: '<S111>/Multiply' */

          /* Gain: '<S111>/Gain2' */
          FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_Transpose_0[0];
          FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_Transpose_0[1];

          /* Update for Delay: '<S111>/Delay' */
          FMS_DW.icLoad = 0U;

          /* End of Outputs for SubSystem: '<S109>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S109>/Move Control' incorporates:
             *  ActionPort: '<S112>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S109>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S119>/Integrator'
             *  DiscreteIntegrator: '<S119>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE[0] = 0.0F;
            FMS_DW.Integrator_DSTATE[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE[1] = 0.0F;
            FMS_DW.Integrator_DSTATE[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S109>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S109>/Move Control' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S117>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S31>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S117>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S117>/Gain' */
          rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S118>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S31>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S118>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S118>/Gain' */
          rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

          /* Sum: '<S120>/Sum of Elements' incorporates:
           *  Math: '<S120>/Square'
           *  SignalConversion: '<S120>/TmpSignal ConversionAtSquareInport1'
           *  Sum: '<S121>/Sum of Elements'
           *  Switch: '<S112>/Switch'
           */
          rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

          /* Switch: '<S112>/Switch' incorporates:
           *  Constant: '<S116>/Constant'
           *  Product: '<S121>/Divide'
           *  RelationalOperator: '<S116>/Compare'
           *  Sqrt: '<S120>/Sqrt'
           *  Sum: '<S120>/Sum of Elements'
           */
          if (sqrtf(rtb_Saturation_n) > 1.0F) {
            /* Math: '<S121>/Math Function1'
             *
             * About '<S121>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_n < 0.0F) {
              rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
            } else {
              rtb_Saturation_n = sqrtf(rtb_Saturation_n);
            }

            /* End of Math: '<S121>/Math Function1' */

            /* Switch: '<S121>/Switch' incorporates:
             *  Constant: '<S121>/Constant'
             *  Product: '<S121>/Product'
             */
            if (rtb_Saturation_n > 0.0F) {
              rtb_MatrixConcatenate3[0] = rtb_Add3_c;
              rtb_MatrixConcatenate3[1] = rtb_Add4_d;
              rtb_MatrixConcatenate3[2] = rtb_Saturation_n;
            } else {
              rtb_MatrixConcatenate3[0] = 0.0F;
              rtb_MatrixConcatenate3[1] = 0.0F;
              rtb_MatrixConcatenate3[2] = 1.0F;
            }

            /* End of Switch: '<S121>/Switch' */
            rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
            rtb_Add4_d = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
          }

          /* Saturate: '<S122>/Saturation' incorporates:
           *  Constant: '<S119>/Constant'
           */
          if (FMS_PARAM.STICK_SENS > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else if (FMS_PARAM.STICK_SENS < 0.0F) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_PARAM.STICK_SENS;
          }

          /* End of Saturate: '<S122>/Saturation' */

          /* Product: '<S122>/Multiply7' incorporates:
           *  Constant: '<S122>/const'
           */
          rtb_Saturation_n *= 980.6F;

          /* Product: '<S122>/Multiply' */
          rtb_a_l = rtb_Saturation_n * FMS_ConstB.Square;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Sqrt_b = FMS_DW.Integrator_DSTATE[0] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Divide_l_idx_0 = (FMS_DW.Integrator1_DSTATE[0] -
                                FMS_PARAM.VEL_XY_LIM * rtb_Add3_c) + rtb_Sqrt_b;

          /* Signum: '<S122>/Sign' */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_l_idx_0;
          }

          /* Sum: '<S122>/Add2' incorporates:
           *  Abs: '<S122>/Abs'
           *  Gain: '<S122>/Gain'
           *  Gain: '<S122>/Gain1'
           *  Product: '<S122>/Multiply2'
           *  Product: '<S122>/Multiply3'
           *  Sqrt: '<S122>/Sqrt'
           *  Sum: '<S122>/Add1'
           *  Sum: '<S122>/Subtract'
           */
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_0) + rtb_a_l)
            * rtb_a_l) - rtb_a_l) * 0.5F * rtb_Add3_c + rtb_Sqrt_b;

          /* Sum: '<S122>/Add4' */
          rtb_Sqrt_b += rtb_Divide_l_idx_0 - rtb_Integrator1_a;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Divide_l_idx_0 + rtb_a_l;

          /* Sum: '<S122>/Subtract1' */
          rtb_Divide_l_idx_0 -= rtb_a_l;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_0 > 0.0F) {
              rtb_Divide_l_idx_0 = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Add3_c - rtb_Divide_l_idx_0) * 0.5F *
            rtb_Sqrt_b;

          /* SignalConversion: '<S112>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           */
          FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

          /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

          /* Signum: '<S122>/Sign4' incorporates:
           *  Sum: '<S122>/Subtract3'
           */
          rtb_Add3_c = rtb_Integrator1_a - rtb_a_l;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Sqrt_b = rtb_Integrator1_a + rtb_a_l;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_0 = rtb_Integrator1_a;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign6' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Integrator1_a;
          }

          /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
           *  Gain: '<S122>/Gain3'
           *  Gain: '<S122>/Gain4'
           *  Product: '<S122>/Divide'
           *  Product: '<S122>/Multiply5'
           *  Product: '<S122>/Multiply6'
           *  Sum: '<S122>/Subtract4'
           *  Sum: '<S122>/Subtract5'
           *  Sum: '<S122>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE[0] += ((rtb_Integrator1_a / rtb_a_l -
            rtb_Divide_l_idx_0) * -rtb_Saturation_n * ((rtb_Sqrt_b - rtb_Add3_c)
            * 0.5F) - rtb_Divide_l_idx_1 * rtb_Saturation_n) * 0.004F;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Sqrt_b = FMS_DW.Integrator_DSTATE[1] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Divide_l_idx_0 = (FMS_DW.Integrator1_DSTATE[1] -
                                FMS_PARAM.VEL_XY_LIM * rtb_Add4_d) + rtb_Sqrt_b;

          /* Signum: '<S122>/Sign' */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_l_idx_0;
          }

          /* Sum: '<S122>/Add2' incorporates:
           *  Abs: '<S122>/Abs'
           *  Gain: '<S122>/Gain'
           *  Gain: '<S122>/Gain1'
           *  Product: '<S122>/Multiply2'
           *  Product: '<S122>/Multiply3'
           *  Sqrt: '<S122>/Sqrt'
           *  Sum: '<S122>/Add1'
           *  Sum: '<S122>/Subtract'
           */
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_0) + rtb_a_l)
            * rtb_a_l) - rtb_a_l) * 0.5F * rtb_Add3_c + rtb_Sqrt_b;

          /* Sum: '<S122>/Add4' */
          rtb_Sqrt_b += rtb_Divide_l_idx_0 - rtb_Integrator1_a;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Divide_l_idx_0 + rtb_a_l;

          /* Sum: '<S122>/Subtract1' */
          rtb_Divide_l_idx_0 -= rtb_a_l;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_0 > 0.0F) {
              rtb_Divide_l_idx_0 = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Add3_c - rtb_Divide_l_idx_0) * 0.5F *
            rtb_Sqrt_b;

          /* SignalConversion: '<S112>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           */
          FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

          /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

          /* Signum: '<S122>/Sign4' incorporates:
           *  Sum: '<S122>/Subtract3'
           */
          rtb_Add3_c = rtb_Integrator1_a - rtb_a_l;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Sqrt_b = rtb_Integrator1_a + rtb_a_l;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_0 = rtb_Integrator1_a;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign6' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Integrator1_a;
          }

          /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
           *  Gain: '<S122>/Gain3'
           *  Gain: '<S122>/Gain4'
           *  Product: '<S122>/Divide'
           *  Product: '<S122>/Multiply5'
           *  Product: '<S122>/Multiply6'
           *  Sum: '<S122>/Subtract4'
           *  Sum: '<S122>/Subtract5'
           *  Sum: '<S122>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE[1] += ((rtb_Integrator1_a / rtb_a_l -
            rtb_Divide_l_idx_0) * -rtb_Saturation_n * ((rtb_Sqrt_b - rtb_Add3_c)
            * 0.5F) - rtb_Divide_l_idx_1 * rtb_Saturation_n) * 0.004F;

          /* End of Outputs for SubSystem: '<S109>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S109>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S83>/Switch' incorporates:
         *  Constant: '<S83>/Constant'
         *  Saturate: '<S86>/Saturation1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        if (FMS_B.Compare) {
          rtb_Saturation_n = 0.5F;
        } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Saturation_n = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Saturation_n = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Saturation_n = FMS_B.Merge_l;
        }

        /* End of Switch: '<S83>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S97>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bu;
        FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_bu = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_bu = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_bu) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bu != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S97>/Hold Control' incorporates:
             *  ActionPort: '<S99>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S97>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h2);

            /* End of SystemReset for SubSystem: '<S97>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S97>/Hold Control' incorporates:
           *  ActionPort: '<S99>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_e,
                            &FMS_DW.HoldControl_h2);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S97>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bu != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S97>/Move Control' incorporates:
             *  ActionPort: '<S100>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S97>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_m1);

            /* End of SystemReset for SubSystem: '<S97>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S97>/Move Control' incorporates:
           *  ActionPort: '<S100>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_e,
                            &FMS_ConstB.MoveControl_m1, &FMS_DW.MoveControl_m1);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S97>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S97>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S43>/Bus Assignment'
         *  Constant: '<S43>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S43>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S97>/Saturation' */
        if (FMS_B.Merge_e > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S97>/Saturation' */

        /* Saturate: '<S109>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S109>/Saturation1' */

        /* BusAssignment: '<S43>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;

        /* End of Outputs for SubSystem: '<S36>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S36>/Unknown' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S36>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S36>/Switch Case' */
      /* End of Outputs for SubSystem: '<S32>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S32>/Manual' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S38>/Bus Assignment'
       *  Constant: '<S38>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S38>/Bus Assignment' incorporates:
       *  Constant: '<S38>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S32>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S32>/Unknown' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S32>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S32>/Switch Case' */
    /* End of Outputs for SubSystem: '<S30>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S30>/Switch Case' */

  /* DataTypeConversion: '<S33>/Data Type Conversion' incorporates:
   *  Outport: '<Root>/FMS_Out'
   */
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* Sum: '<S33>/Sum' incorporates:
   *  Constant: '<S33>/Constant'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy5Inport1'
   */
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* BusAssignment: '<S33>/Bus Assignment' incorporates:
   *  DataStoreRead: '<S33>/Data Store Read'
   *  DiscreteIntegrator: '<S495>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy4Inport1'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];
  FMS_Y.FMS_Out.error = FMS_B.Add;

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_fu ==
    FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S14>/SetHome' incorporates:
   *  TriggerPort: '<S21>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S14>/SetHome' */

  /* Update for UnitDelay: '<S19>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S20>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_Saturation_n = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Saturation_n;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S26>/Delay Input1':
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

  /* Update for DiscreteIntegrator: '<S510>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S510>/Gain'
   *  Sum: '<S510>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_ft[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_ft[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_ft[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S512>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S512>/Gain'
   *  Sum: '<S512>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S511>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S511>/Gain'
   *  Sum: '<S511>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_l_idx_2 -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Saturation_n = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Saturation_n;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S11>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;

  /* Update for DiscreteIntegrator: '<S495>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S495>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;
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

  /* Start for SwitchCase: '<S30>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S30>/Arm' */
  /* Start for SwitchCase: '<S32>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S32>/SubMode' */
  /* Start for SwitchCase: '<S39>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S39>/Return' */
  /* Start for SwitchCase: '<S443>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S433>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S39>/Return' */

  /* Start for IfAction SubSystem: '<S39>/Hold' */
  /* Start for SwitchCase: '<S377>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S355>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S365>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S39>/Hold' */
  /* End of Start for SubSystem: '<S32>/SubMode' */

  /* Start for IfAction SubSystem: '<S32>/Auto' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S37>/Mission' */
  /* Start for Resettable SubSystem: '<S150>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S199>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

  /* Start for SwitchCase: '<S189>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S150>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S37>/Mission' */
  /* End of Start for SubSystem: '<S32>/Auto' */

  /* Start for IfAction SubSystem: '<S32>/Assist' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S36>/Stabilize' */
  /* Start for SwitchCase: '<S138>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S36>/Stabilize' */

  /* Start for IfAction SubSystem: '<S36>/Altitude' */
  /* Start for SwitchCase: '<S51>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S71>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;

  /* End of Start for SubSystem: '<S36>/Altitude' */

  /* Start for IfAction SubSystem: '<S36>/Position' */
  /* Start for SwitchCase: '<S86>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S109>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S97>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;

  /* End of Start for SubSystem: '<S36>/Position' */
  /* End of Start for SubSystem: '<S32>/Assist' */
  /* End of Start for SubSystem: '<S30>/Arm' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  FMS_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S510>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S512>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S511>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_Mode = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.is_active_c1_FMS = 0U;

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

  /* SystemInitialize for IfAction SubSystem: '<S30>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S32>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S39>/Takeoff' */
  /* InitializeConditions for Delay: '<S492>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S488>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S488>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S393>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S393>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Return' */
  /* InitializeConditions for DiscreteIntegrator: '<S426>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for Delay: '<S424>/Delay1' */
  FMS_DW.Delay1_DSTATE_b = false;

  /* InitializeConditions for Delay: '<S424>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S425>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S472>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for Delay: '<S402>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S405>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S401>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S405>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S444>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S443>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S443>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S443>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S443>/Move Control' */

  /* SystemInitialize for Merge: '<S443>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S434>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S433>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S433>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S433>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S433>/Move Control' */

  /* SystemInitialize for Merge: '<S433>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold' */
  /* SystemInitialize for Chart: '<S356>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S366>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S378>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S377>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S377>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S377>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S377>/Move Control' */

  /* SystemInitialize for Merge: '<S377>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S355>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S355>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S355>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S355>/Move Control' */

  /* SystemInitialize for Merge: '<S355>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S365>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S365>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S365>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S365>/Move Control' */

  /* SystemInitialize for Merge: '<S365>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S32>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S37>/Mission' */
  /* InitializeConditions for UnitDelay: '<S153>/Delay Input1'
   *
   * Block description for '<S153>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S150>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for Delay: '<S180>/Delay1' */
  FMS_DW.Delay1_DSTATE = false;

  /* InitializeConditions for Delay: '<S180>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S181>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for Delay: '<S158>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S200>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S199>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S199>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S199>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S199>/Move Control' */

  /* SystemInitialize for Merge: '<S199>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S190>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S189>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S189>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S189>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S189>/Move Control' */

  /* SystemInitialize for Merge: '<S189>/Merge' */
  FMS_B.Merge_e3 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S150>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S37>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S32>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S36>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S132>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_k = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S132>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S133>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nf = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S133>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S139>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S138>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S138>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S138>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S138>/Move Control' */

  /* SystemInitialize for Merge: '<S138>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* SystemInitialize for Chart: '<S52>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S51>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S51>/Hold Control' */

  /* SystemInitialize for Merge: '<S51>/Merge' */
  FMS_B.Merge_lf = 0.0F;

  /* SystemInitialize for Chart: '<S72>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_b);

  /* SystemInitialize for IfAction SubSystem: '<S71>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_hb);

  /* End of SystemInitialize for SubSystem: '<S71>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S71>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S71>/Move Control' */

  /* SystemInitialize for Merge: '<S71>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Position' */
  /* SystemInitialize for Chart: '<S87>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for IfAction SubSystem: '<S86>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_c);

  /* End of SystemInitialize for SubSystem: '<S86>/Hold Control' */

  /* SystemInitialize for Chart: '<S98>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_l);

  /* SystemInitialize for Chart: '<S110>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S109>/Hold Control' */
  /* InitializeConditions for Delay: '<S111>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S109>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S109>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/Move Control' */

  /* SystemInitialize for Merge: '<S109>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S109>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S109>/Move Control' */

  /* SystemInitialize for Merge: '<S109>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S86>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S97>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h2);

  /* End of SystemInitialize for SubSystem: '<S97>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S97>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_m1);

  /* End of SystemInitialize for SubSystem: '<S97>/Move Control' */

  /* SystemInitialize for Merge: '<S97>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Position' */
  /* End of SystemInitialize for SubSystem: '<S32>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S30>/Arm' */
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
