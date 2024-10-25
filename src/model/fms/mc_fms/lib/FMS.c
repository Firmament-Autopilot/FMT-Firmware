/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2112
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Oct 25 16:11:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S430>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S440>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S142>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o4                 ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S50>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S360>/Motion State' */
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
  1300U
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S6>/Land_Lock_Thro'
                                        *   '<S26>/Constant'
                                        *   '<S483>/Constant'
                                        *   '<S343>/L1'
                                        *   '<S47>/Gain'
                                        *   '<S47>/Gain1'
                                        *   '<S129>/Gain'
                                        *   '<S129>/Gain1'
                                        *   '<S131>/Constant'
                                        *   '<S158>/L1'
                                        *   '<S239>/Saturation'
                                        *   '<S240>/Saturation1'
                                        *   '<S240>/Saturation2'
                                        *   '<S240>/Saturation3'
                                        *   '<S384>/Land_Speed'
                                        *   '<S385>/Saturation1'
                                        *   '<S471>/Takeoff_Speed'
                                        *   '<S472>/Gain2'
                                        *   '<S472>/Saturation1'
                                        *   '<S49>/Saturation1'
                                        *   '<S62>/Dead Zone'
                                        *   '<S62>/Gain'
                                        *   '<S63>/Dead Zone'
                                        *   '<S63>/Gain'
                                        *   '<S70>/Saturation'
                                        *   '<S86>/Saturation1'
                                        *   '<S98>/Saturation'
                                        *   '<S111>/Saturation1'
                                        *   '<S133>/Dead Zone'
                                        *   '<S133>/Gain'
                                        *   '<S134>/Dead Zone'
                                        *   '<S134>/Gain'
                                        *   '<S141>/Saturation'
                                        *   '<S293>/Gain2'
                                        *   '<S300>/Gain1'
                                        *   '<S300>/Gain2'
                                        *   '<S349>/Saturation1'
                                        *   '<S359>/Saturation'
                                        *   '<S371>/Saturation1'
                                        *   '<S386>/Constant'
                                        *   '<S389>/Gain2'
                                        *   '<S411>/Gain'
                                        *   '<S411>/Saturation1'
                                        *   '<S414>/Constant'
                                        *   '<S414>/vel'
                                        *   '<S414>/Switch'
                                        *   '<S52>/Gain2'
                                        *   '<S53>/Gain1'
                                        *   '<S59>/Constant'
                                        *   '<S73>/Gain2'
                                        *   '<S74>/Gain1'
                                        *   '<S81>/Constant'
                                        *   '<S89>/Gain2'
                                        *   '<S90>/Gain1'
                                        *   '<S96>/Constant'
                                        *   '<S101>/Gain2'
                                        *   '<S102>/Gain1'
                                        *   '<S109>/Constant'
                                        *   '<S114>/Gain2'
                                        *   '<S115>/Gain6'
                                        *   '<S126>/Constant'
                                        *   '<S127>/Constant'
                                        *   '<S144>/Gain2'
                                        *   '<S145>/Gain1'
                                        *   '<S152>/Constant'
                                        *   '<S177>/Gain'
                                        *   '<S177>/Saturation1'
                                        *   '<S180>/Constant'
                                        *   '<S180>/vel'
                                        *   '<S180>/Switch'
                                        *   '<S352>/Gain2'
                                        *   '<S353>/Gain1'
                                        *   '<S362>/Gain2'
                                        *   '<S363>/Gain1'
                                        *   '<S374>/Gain2'
                                        *   '<S375>/Gain6'
                                        *   '<S398>/Gain2'
                                        *   '<S398>/Saturation'
                                        *   '<S399>/Integrator'
                                        *   '<S55>/Land_Speed'
                                        *   '<S56>/Constant'
                                        *   '<S58>/Dead Zone'
                                        *   '<S58>/Gain'
                                        *   '<S78>/Dead Zone'
                                        *   '<S78>/Gain'
                                        *   '<S92>/Land_Speed'
                                        *   '<S93>/Constant'
                                        *   '<S95>/Dead Zone'
                                        *   '<S95>/Gain'
                                        *   '<S106>/Dead Zone'
                                        *   '<S106>/Gain'
                                        *   '<S120>/Dead Zone'
                                        *   '<S120>/Gain'
                                        *   '<S121>/Dead Zone'
                                        *   '<S121>/Gain'
                                        *   '<S149>/Dead Zone'
                                        *   '<S149>/Gain'
                                        *   '<S164>/Gain2'
                                        *   '<S164>/Saturation'
                                        *   '<S165>/Integrator'
                                        *   '<S355>/Dead Zone'
                                        *   '<S355>/Gain'
                                        *   '<S367>/Dead Zone'
                                        *   '<S367>/Gain'
                                        *   '<S379>/Dead Zone'
                                        *   '<S379>/Gain'
                                        *   '<S380>/Dead Zone'
                                        *   '<S380>/Gain'
                                        *   '<S429>/Saturation1'
                                        *   '<S439>/Saturation1'
                                        *   '<S195>/Saturation1'
                                        *   '<S205>/Saturation1'
                                        *   '<S432>/Gain2'
                                        *   '<S433>/Gain1'
                                        *   '<S442>/Gain2'
                                        *   '<S443>/Gain6'
                                        *   '<S198>/Gain2'
                                        *   '<S199>/Gain1'
                                        *   '<S208>/Gain2'
                                        *   '<S209>/Gain6'
                                        *   '<S435>/Dead Zone'
                                        *   '<S435>/Gain'
                                        *   '<S447>/Dead Zone'
                                        *   '<S447>/Gain'
                                        *   '<S448>/Dead Zone'
                                        *   '<S448>/Gain'
                                        *   '<S201>/Dead Zone'
                                        *   '<S201>/Gain'
                                        *   '<S213>/Dead Zone'
                                        *   '<S213>/Gain'
                                        *   '<S214>/Dead Zone'
                                        *   '<S214>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 77, 67, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S12>/Constant1'
                                        *   '<S481>/Constant'
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
 *    '<S429>/Hold Control'
 *    '<S349>/Hold Control'
 *    '<S195>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S432>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S429>/Hold Control'
 *    '<S349>/Hold Control'
 *    '<S195>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S432>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S429>/Hold Control'
 *    '<S349>/Hold Control'
 *    '<S195>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S432>/Delay' incorporates:
   *  Gain: '<S434>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S432>/Gain2' incorporates:
   *  Delay: '<S432>/Delay'
   *  Gain: '<S434>/Gain'
   *  Sum: '<S432>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S432>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S429>/Brake Control'
 *    '<S349>/Brake Control'
 *    '<S359>/Brake Control'
 *    '<S195>/Brake Control'
 *    '<S141>/Brake Control'
 *    '<S49>/Brake Control'
 *    '<S70>/Brake Control'
 *    '<S86>/Brake Control'
 *    '<S98>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S431>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S431>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S429>/Move Control'
 *    '<S349>/Move Control'
 *    '<S195>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S429>/Move Control'
 *    '<S349>/Move Control'
 *    '<S195>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S429>/Move Control'
 *    '<S349>/Move Control'
 *    '<S195>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_mj;
  real32_T rtb_Subtract3_k;
  real32_T rtb_a_g;
  real32_T rtb_Add4_df;
  real32_T rtb_a_m;

  /* Product: '<S437>/Multiply1' incorporates:
   *  Constant: '<S437>/const1'
   *  DiscreteIntegrator: '<S436>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S435>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S435>/Dead Zone' */

  /* Sum: '<S437>/Add' incorporates:
   *  DiscreteIntegrator: '<S436>/Integrator1'
   *  Gain: '<S433>/Gain1'
   *  Gain: '<S435>/Gain'
   *  Sum: '<S436>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S437>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S437>/Sign' */

  /* Sum: '<S437>/Add2' incorporates:
   *  Abs: '<S437>/Abs'
   *  Gain: '<S437>/Gain'
   *  Gain: '<S437>/Gain1'
   *  Product: '<S437>/Multiply2'
   *  Product: '<S437>/Multiply3'
   *  Sqrt: '<S437>/Sqrt'
   *  Sum: '<S437>/Add1'
   *  Sum: '<S437>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S437>/Add4' */
  rtb_Add4_df = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S437>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S437>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S437>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S437>/Sign1' */

  /* Signum: '<S437>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S437>/Sign2' */

  /* Sum: '<S437>/Add5' incorporates:
   *  Gain: '<S437>/Gain2'
   *  Product: '<S437>/Multiply4'
   *  Sum: '<S437>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_df;

  /* SignalConversion: '<S433>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S436>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S436>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S436>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S437>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S437>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S437>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_df = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_df = 1.0F;
  } else {
    rtb_Add4_df = rtb_a_g;
  }

  /* End of Signum: '<S437>/Sign5' */

  /* Signum: '<S437>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S437>/Sign3' */

  /* Signum: '<S437>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S437>/Sign4' */

  /* Signum: '<S437>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S437>/Sign6' */

  /* Update for DiscreteIntegrator: '<S436>/Integrator' incorporates:
   *  Constant: '<S437>/const'
   *  Gain: '<S437>/Gain3'
   *  Product: '<S437>/Divide'
   *  Product: '<S437>/Multiply5'
   *  Product: '<S437>/Multiply6'
   *  Sum: '<S437>/Subtract4'
   *  Sum: '<S437>/Subtract5'
   *  Sum: '<S437>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_df) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S430>/Motion Status'
 *    '<S350>/Motion Status'
 *    '<S196>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S430>/Motion Status'
 *    '<S350>/Motion Status'
 *    '<S196>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S430>/Motion Status'
 *    '<S350>/Motion Status'
 *    '<S196>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S430>/Motion Status' */
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

  /* End of Chart: '<S430>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S439>/Hold Control'
 *    '<S371>/Hold Control'
 *    '<S205>/Hold Control'
 *    '<S111>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S442>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S439>/Hold Control'
 *    '<S371>/Hold Control'
 *    '<S205>/Hold Control'
 *    '<S111>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S442>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S439>/Hold Control'
 *    '<S371>/Hold Control'
 *    '<S205>/Hold Control'
 *    '<S111>/Hold Control'
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

  /* Delay: '<S442>/Delay' incorporates:
   *  SignalConversion: '<S442>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S446>/Trigonometric Function1' incorporates:
   *  Gain: '<S445>/Gain'
   *  Trigonometry: '<S446>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S446>/Trigonometric Function' incorporates:
   *  Gain: '<S445>/Gain'
   *  Trigonometry: '<S446>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S446>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S446>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S446>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S446>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S446>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S446>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S446>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S442>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S442>/Delay'
   *  SignalConversion: '<S442>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S442>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S442>/Multiply' incorporates:
   *  SignalConversion: '<S442>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S442>/Multiply' */

  /* Gain: '<S442>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S442>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S439>/Brake Control'
 *    '<S371>/Brake Control'
 *    '<S205>/Brake Control'
 *    '<S111>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S441>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S439>/Move Control'
 *    '<S371>/Move Control'
 *    '<S205>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S439>/Move Control'
 *    '<S371>/Move Control'
 *    '<S205>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S449>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S439>/Move Control'
 *    '<S371>/Move Control'
 *    '<S205>/Move Control'
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

  /* SignalConversion: '<S443>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S449>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S450>/Multiply1' incorporates:
   *  Constant: '<S450>/const1'
   *  DiscreteIntegrator: '<S449>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S443>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S449>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S450>/Multiply1' incorporates:
   *  Constant: '<S450>/const1'
   *  DiscreteIntegrator: '<S449>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S447>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S447>/Dead Zone' */

  /* Sum: '<S450>/Add' incorporates:
   *  DiscreteIntegrator: '<S449>/Integrator1'
   *  Gain: '<S443>/Gain6'
   *  Gain: '<S447>/Gain'
   *  Sum: '<S449>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S448>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S448>/Dead Zone' */

  /* Sum: '<S450>/Add' incorporates:
   *  DiscreteIntegrator: '<S449>/Integrator1'
   *  Gain: '<S443>/Gain6'
   *  Gain: '<S448>/Gain'
   *  Sum: '<S449>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S450>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S450>/Add2' incorporates:
   *  Abs: '<S450>/Abs'
   *  Gain: '<S450>/Gain'
   *  Gain: '<S450>/Gain1'
   *  Product: '<S450>/Multiply2'
   *  Product: '<S450>/Multiply3'
   *  Signum: '<S450>/Sign'
   *  Sqrt: '<S450>/Sqrt'
   *  Sum: '<S450>/Add1'
   *  Sum: '<S450>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S450>/Add3' incorporates:
   *  Signum: '<S450>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S450>/Subtract1' incorporates:
   *  Signum: '<S450>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S450>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S450>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S450>/Add5' incorporates:
   *  Gain: '<S450>/Gain2'
   *  Product: '<S450>/Multiply4'
   *  Signum: '<S450>/Sign'
   *  Sum: '<S450>/Add2'
   *  Sum: '<S450>/Add4'
   *  Sum: '<S450>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S449>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S449>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S450>/Sign3' incorporates:
   *  Sum: '<S450>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S450>/Sign4' incorporates:
   *  Sum: '<S450>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S450>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S450>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S450>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S450>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S449>/Integrator' incorporates:
   *  Constant: '<S450>/const'
   *  Gain: '<S450>/Gain3'
   *  Product: '<S450>/Divide'
   *  Product: '<S450>/Multiply5'
   *  Product: '<S450>/Multiply6'
   *  Sum: '<S450>/Subtract4'
   *  Sum: '<S450>/Subtract5'
   *  Sum: '<S450>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S450>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S450>/Add2' incorporates:
   *  Abs: '<S450>/Abs'
   *  Gain: '<S450>/Gain'
   *  Gain: '<S450>/Gain1'
   *  Product: '<S450>/Multiply2'
   *  Product: '<S450>/Multiply3'
   *  Signum: '<S450>/Sign'
   *  Sqrt: '<S450>/Sqrt'
   *  Sum: '<S450>/Add1'
   *  Sum: '<S450>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S450>/Add3' incorporates:
   *  Signum: '<S450>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S450>/Subtract1' incorporates:
   *  Signum: '<S450>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S450>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S450>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S450>/Add5' incorporates:
   *  Gain: '<S450>/Gain2'
   *  Product: '<S450>/Multiply4'
   *  Signum: '<S450>/Sign'
   *  Sum: '<S450>/Add2'
   *  Sum: '<S450>/Add4'
   *  Sum: '<S450>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S449>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S449>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S450>/Sign3' incorporates:
   *  Sum: '<S450>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S450>/Sign4' incorporates:
   *  Sum: '<S450>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S450>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S450>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S450>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S450>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S449>/Integrator' incorporates:
   *  Constant: '<S450>/const'
   *  Gain: '<S450>/Gain3'
   *  Product: '<S450>/Divide'
   *  Product: '<S450>/Multiply5'
   *  Product: '<S450>/Multiply6'
   *  Sum: '<S450>/Subtract4'
   *  Sum: '<S450>/Subtract5'
   *  Sum: '<S450>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S440>/Motion State'
 *    '<S372>/Motion State'
 *    '<S206>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S440>/Motion State'
 *    '<S372>/Motion State'
 *    '<S206>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S440>/Motion State'
 *    '<S372>/Motion State'
 *    '<S206>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S440>/Motion State' */
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

  /* End of Chart: '<S440>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S416>/NearbyRefWP'
 *    '<S182>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S454>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S359>/Hold Control'
 *    '<S141>/Hold Control'
 *    '<S70>/Hold Control'
 *    '<S98>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S362>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S359>/Hold Control'
 *    '<S141>/Hold Control'
 *    '<S70>/Hold Control'
 *    '<S98>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S362>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S359>/Hold Control'
 *    '<S141>/Hold Control'
 *    '<S70>/Hold Control'
 *    '<S98>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S362>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S362>/Sum' incorporates:
   *  Delay: '<S362>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S365>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S365>/Switch' incorporates:
   *  Constant: '<S365>/Constant'
   *  Constant: '<S366>/Constant'
   *  Product: '<S365>/Multiply'
   *  RelationalOperator: '<S366>/Compare'
   *  Sum: '<S365>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S365>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S365>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S365>/Switch' */

  /* Gain: '<S362>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S362>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S359>/Move Control'
 *    '<S141>/Move Control'
 *    '<S70>/Move Control'
 *    '<S98>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S368>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S368>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S359>/Move Control'
 *    '<S141>/Move Control'
 *    '<S70>/Move Control'
 *    '<S98>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S368>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S368>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S359>/Move Control'
 *    '<S141>/Move Control'
 *    '<S70>/Move Control'
 *    '<S98>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_ig;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_i3;
  real32_T rtb_a_p4;

  /* Product: '<S369>/Multiply1' incorporates:
   *  Constant: '<S369>/const1'
   *  DiscreteIntegrator: '<S368>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S367>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S367>/Dead Zone' */

  /* Sum: '<S369>/Add' incorporates:
   *  DiscreteIntegrator: '<S368>/Integrator1'
   *  Gain: '<S363>/Gain1'
   *  Gain: '<S367>/Gain'
   *  Sum: '<S368>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S369>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S369>/Sign' */

  /* Sum: '<S369>/Add2' incorporates:
   *  Abs: '<S369>/Abs'
   *  Gain: '<S369>/Gain'
   *  Gain: '<S369>/Gain1'
   *  Product: '<S369>/Multiply2'
   *  Product: '<S369>/Multiply3'
   *  Sqrt: '<S369>/Sqrt'
   *  Sum: '<S369>/Add1'
   *  Sum: '<S369>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S369>/Add4' */
  rtb_Add4_i3 = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S369>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S369>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S369>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S369>/Sign1' */

  /* Signum: '<S369>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S369>/Sign2' */

  /* Sum: '<S369>/Add5' incorporates:
   *  Gain: '<S369>/Gain2'
   *  Product: '<S369>/Multiply4'
   *  Sum: '<S369>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_i3;

  /* SignalConversion: '<S363>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S368>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S368>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S368>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S369>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S369>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S369>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_i3 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_i3 = 1.0F;
  } else {
    rtb_Add4_i3 = rtb_a_m;
  }

  /* End of Signum: '<S369>/Sign5' */

  /* Signum: '<S369>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S369>/Sign3' */

  /* Signum: '<S369>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S369>/Sign4' */

  /* Signum: '<S369>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S369>/Sign6' */

  /* Update for DiscreteIntegrator: '<S368>/Integrator' incorporates:
   *  Constant: '<S369>/const'
   *  Gain: '<S369>/Gain3'
   *  Product: '<S369>/Divide'
   *  Product: '<S369>/Multiply5'
   *  Product: '<S369>/Multiply6'
   *  Sum: '<S369>/Subtract4'
   *  Sum: '<S369>/Subtract5'
   *  Sum: '<S369>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_i3) *
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

  /* BusAssignment: '<S345>/Bus Assignment' incorporates:
   *  Constant: '<S345>/Constant'
   *  Constant: '<S345>/Constant2'
   *  SignalConversion: '<S345>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S345>/Bus Assignment' */
}

/*
 * System initialize for atomic system:
 *    '<S142>/Motion State'
 *    '<S71>/Motion State'
 *    '<S99>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S142>/Motion State'
 *    '<S71>/Motion State'
 *    '<S99>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S142>/Motion State'
 *    '<S71>/Motion State'
 *    '<S99>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S142>/Motion State' */
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

  /* End of Chart: '<S142>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S49>/Move Control'
 *    '<S86>/Move Control'
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
 *    '<S50>/Motion Status'
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
 *    '<S50>/Motion Status'
 *    '<S87>/Motion Status'
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

  /* Gain: '<S485>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S486>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S486>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S486>/Multiply1' incorporates:
   *  Product: '<S486>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S486>/Divide' incorporates:
   *  Constant: '<S486>/Constant'
   *  Constant: '<S486>/R'
   *  Sqrt: '<S486>/Sqrt'
   *  Sum: '<S486>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S486>/Product3' incorporates:
   *  Constant: '<S486>/Constant1'
   *  Product: '<S486>/Multiply1'
   *  Sum: '<S486>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S486>/Multiply2' incorporates:
   *  Trigonometry: '<S486>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S485>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S490>/Abs' incorporates:
   *  Abs: '<S493>/Abs1'
   *  Switch: '<S490>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S490>/Switch1' incorporates:
   *  Abs: '<S490>/Abs'
   *  Bias: '<S490>/Bias2'
   *  Bias: '<S490>/Bias3'
   *  Constant: '<S487>/Constant'
   *  Constant: '<S487>/Constant1'
   *  Constant: '<S492>/Constant'
   *  Gain: '<S490>/Gain1'
   *  Product: '<S490>/Multiply'
   *  RelationalOperator: '<S492>/Compare'
   *  Switch: '<S487>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S493>/Switch1' incorporates:
     *  Bias: '<S493>/Bias2'
     *  Bias: '<S493>/Bias3'
     *  Constant: '<S493>/Constant'
     *  Constant: '<S494>/Constant'
     *  Math: '<S493>/Math Function'
     *  RelationalOperator: '<S494>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S493>/Switch1' */

    /* Signum: '<S490>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S490>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S487>/Sum' incorporates:
   *  Sum: '<S485>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S485>/Multiply' incorporates:
   *  Gain: '<S485>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S489>/Switch1' incorporates:
   *  Abs: '<S489>/Abs1'
   *  Bias: '<S489>/Bias2'
   *  Bias: '<S489>/Bias3'
   *  Constant: '<S489>/Constant'
   *  Constant: '<S491>/Constant'
   *  Math: '<S489>/Math Function'
   *  RelationalOperator: '<S491>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S489>/Switch1' */

  /* Product: '<S485>/Multiply' incorporates:
   *  Gain: '<S485>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S485>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S488>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S488>/Sum2' incorporates:
   *  Product: '<S488>/Multiply1'
   *  Product: '<S488>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S488>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S488>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S488>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S482>/Data Type Conversion' incorporates:
   *  Gain: '<S485>/Gain'
   *  Sum: '<S485>/Sum1'
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
    if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag & 8U) ==
         0U)) {
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
  /* RelationalOperator: '<S495>/Compare' incorporates:
   *  Abs: '<S484>/Abs'
   *  Constant: '<S495>/Constant'
   *  MinMax: '<S484>/Max'
   *  Sum: '<S484>/Sum'
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
                == PilotMode_Offboard) && FMS_B.LogicalOperator) ||
              ((FMS_ManualArmEvent
                (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
                 FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
               (FMS_B.target_mode != PilotMode_None))) {
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
      FMS_B.xy_R[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.xy_R[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;

      /* Outputs for Function Call SubSystem: '<S5>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S483>/Reshape' incorporates:
       *  Constant: '<S483>/Constant'
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
  uint16_T rtb_Divide_dr;
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_a_l;
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
  real32_T rtb_Divide_lr_idx_2;
  real32_T rtb_Divide_lr_idx_1;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* Sqrt: '<S505>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S505>/Square'
   *  Sum: '<S505>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S501>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3_c = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_a_l = FMS_U.INS_Out.quat[3] / rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S502>/Square' incorporates:
   *  Math: '<S503>/Square'
   *  Math: '<S504>/Square'
   */
  rtb_MathFunction_f_idx_0 = rtb_Add3_c * rtb_Add3_c;

  /* Math: '<S502>/Square2' incorporates:
   *  Math: '<S503>/Square2'
   *  Math: '<S504>/Square2'
   */
  rtb_Gain_fj = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S502>/Square1' incorporates:
   *  Math: '<S503>/Square1'
   *  Math: '<S504>/Square1'
   */
  rtb_DiscreteTimeIntegrator_n = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S502>/Square3' incorporates:
   *  Math: '<S503>/Square3'
   *  Math: '<S504>/Square3'
   */
  rtb_Sqrt_b = rtb_a_l * rtb_a_l;

  /* Sum: '<S502>/Subtract' incorporates:
   *  Math: '<S502>/Square'
   *  Math: '<S502>/Square1'
   *  Math: '<S502>/Square2'
   *  Math: '<S502>/Square3'
   *  Sum: '<S502>/Add'
   *  Sum: '<S502>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_f_idx_0 + rtb_DiscreteTimeIntegrator_n) -
    (rtb_Gain_fj + rtb_Sqrt_b);

  /* Product: '<S502>/Multiply' incorporates:
   *  Product: '<S503>/Multiply'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S502>/Multiply1' incorporates:
   *  Product: '<S503>/Multiply1'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_a_l;

  /* Gain: '<S502>/Gain' incorporates:
   *  Product: '<S502>/Multiply'
   *  Product: '<S502>/Multiply1'
   *  Sum: '<S502>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Product: '<S502>/Multiply2' incorporates:
   *  Product: '<S504>/Multiply'
   */
  rtb_Rem_p = rtb_Divide_lr_idx_1 * rtb_a_l;

  /* Product: '<S502>/Multiply3' incorporates:
   *  Product: '<S504>/Multiply1'
   */
  rtb_TmpSignalConversionAtMath_0 = rtb_Add3_c * rtb_Divide_lr_idx_2;

  /* Gain: '<S502>/Gain1' incorporates:
   *  Product: '<S502>/Multiply2'
   *  Product: '<S502>/Multiply3'
   *  Sum: '<S502>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_p + rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S503>/Gain' incorporates:
   *  Sum: '<S503>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S503>/Subtract' incorporates:
   *  Sum: '<S503>/Add'
   *  Sum: '<S503>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_f_idx_0 + rtb_Gain_fj) -
    (rtb_DiscreteTimeIntegrator_n + rtb_Sqrt_b);

  /* Product: '<S503>/Multiply2' incorporates:
   *  Product: '<S504>/Multiply2'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_lr_idx_2 * rtb_a_l;

  /* Product: '<S503>/Multiply3' incorporates:
   *  Product: '<S504>/Multiply3'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Divide_lr_idx_1;

  /* Gain: '<S503>/Gain1' incorporates:
   *  Product: '<S503>/Multiply2'
   *  Product: '<S503>/Multiply3'
   *  Sum: '<S503>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Gain: '<S504>/Gain' incorporates:
   *  Sum: '<S504>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_p - rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S504>/Gain1' incorporates:
   *  Sum: '<S504>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S504>/Subtract' incorporates:
   *  Sum: '<S504>/Add'
   *  Sum: '<S504>/Add1'
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

  /* DiscreteIntegrator: '<S496>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_o[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_o[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_o[2];
  }

  /* Product: '<S6>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S6>/Sum of Elements'
   */
  rtb_Divide_dr = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S498>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S498>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
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
  rtb_Divide_lr_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Gain_fj;

  /* DiscreteIntegrator: '<S497>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_lr_idx_2;
  }

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S496>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S497>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S498>/Discrete-Time Integrator5'
   *  Logic: '<S499>/AND'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S499>/Lower Test'
   *  RelationalOperator: '<S499>/Upper Test'
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
    rtb_Switch_ga = 1U;
  } else {
    rtb_Switch_ga = FMS_DW.Delay_DSTATE_o;
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
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 2));

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
        /* Disable for SwitchCase: '<S439>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S429>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S371>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S349>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S359>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S35>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S154>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S205>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S195>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S154>/Mission_SubSystem' */
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
        /* Disable for SwitchCase: '<S141>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S49>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S70>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S86>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S111>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S98>/Switch Case' */
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
          /* Disable for SwitchCase: '<S439>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S429>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S371>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S349>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S359>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S35>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S154>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S205>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S195>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S154>/Mission_SubSystem' */
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
          /* Disable for SwitchCase: '<S141>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S49>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S70>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S111>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S98>/Switch Case' */
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
       *  Math: '<S461>/Math Function'
       *  Product: '<S463>/Divide'
       *  Sum: '<S417>/Subtract'
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
          /* Disable for SwitchCase: '<S439>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S429>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S371>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S349>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S359>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Takeoff' incorporates:
           *  ActionPort: '<S344>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S479>/cur_waypoint'
           *  DiscreteIntegrator: '<S475>/Integrator'
           *  DiscreteIntegrator: '<S475>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Takeoff' incorporates:
         *  ActionPort: '<S344>/Action Port'
         */
        /* Delay: '<S479>/cur_waypoint' incorporates:
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
        /* Product: '<S479>/Divide' incorporates:
         *  Delay: '<S479>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S479>/Sum1'
         *  Sum: '<S479>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Saturate: '<S479>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S479>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S480>/Trigonometric Function1' incorporates:
         *  Gain: '<S478>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S480>/Trigonometric Function3'
         */
        rtb_MathFunction_f_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S480>/Trigonometric Function' incorporates:
         *  Gain: '<S478>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S480>/Trigonometric Function2'
         */
        rtb_Gain_fj = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[1] = rtb_Gain_fj;

        /* SignalConversion: '<S480>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S480>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S480>/Gain' */
        rtb_Transpose[3] = -rtb_Gain_fj;

        /* Trigonometry: '<S480>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

        /* SignalConversion: '<S480>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S480>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S480>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S472>/Saturation1' */
        rtb_DiscreteTimeIntegrator_n = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_f_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S472>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S479>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S479>/Multiply'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S472>/Sum'
         *  Sum: '<S479>/Sum3'
         *  Sum: '<S479>/Sum4'
         */
        rtb_Divide_lr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
          FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_a_l = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE[1])
                   * rtb_Add3_c + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S472>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_a_l + rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1;
        }

        /* Saturate: '<S472>/Saturation1' incorporates:
         *  Gain: '<S472>/Gain2'
         *  Product: '<S472>/Multiply'
         */
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S344>/Bus Assignment1'
         *  Constant: '<S344>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S344>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S472>/Saturation1' */
        if (rtb_Gain_fj > rtb_DiscreteTimeIntegrator_n) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_DiscreteTimeIntegrator_n;
        } else if (rtb_Gain_fj < rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        }

        if (rtb_Add3_c > rtb_DiscreteTimeIntegrator_n) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_DiscreteTimeIntegrator_n;
        } else if (rtb_Add3_c < rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_0;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S475>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S476>/Multiply1' incorporates:
         *  Constant: '<S476>/const1'
         *  DiscreteIntegrator: '<S475>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S471>/Switch' incorporates:
         *  Abs: '<S471>/Abs'
         *  Abs: '<S471>/Abs1'
         *  Constant: '<S471>/Takeoff_Speed'
         *  Constant: '<S473>/Constant'
         *  Constant: '<S474>/Constant'
         *  Gain: '<S471>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S471>/Logical Operator'
         *  RelationalOperator: '<S473>/Compare'
         *  RelationalOperator: '<S474>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S471>/Sum'
         *  Sum: '<S471>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_a_l = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_a_l = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S471>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S476>/Add' incorporates:
         *  DiscreteIntegrator: '<S475>/Integrator1'
         *  Sum: '<S475>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_a - rtb_a_l) +
          rtb_Add3_c;

        /* Signum: '<S476>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S476>/Sign' */

        /* Sum: '<S476>/Add2' incorporates:
         *  Abs: '<S476>/Abs'
         *  Gain: '<S476>/Gain'
         *  Gain: '<S476>/Gain1'
         *  Product: '<S476>/Multiply2'
         *  Product: '<S476>/Multiply3'
         *  Sqrt: '<S476>/Sqrt'
         *  Sum: '<S476>/Add1'
         *  Sum: '<S476>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_m) *
                         FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_Add3_c;

        /* Sum: '<S476>/Add4' */
        rtb_DiscreteTimeIntegrator_n = (rtb_Divide_lr_idx_1 - rtb_a_l) +
          rtb_Add3_c;

        /* Sum: '<S476>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_m;

        /* Sum: '<S476>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_m;

        /* Signum: '<S476>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S476>/Sign1' */

        /* Signum: '<S476>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S476>/Sign2' */

        /* Sum: '<S476>/Add5' incorporates:
         *  Gain: '<S476>/Gain2'
         *  Product: '<S476>/Multiply4'
         *  Sum: '<S476>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_DiscreteTimeIntegrator_n;

        /* Update for Delay: '<S479>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S475>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S475>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S476>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_m;

        /* Sum: '<S476>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_a_l + FMS_ConstB.d_m;

        /* Signum: '<S476>/Sign5' incorporates:
         *  Signum: '<S476>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S476>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S476>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_a_l;

          /* Signum: '<S476>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = rtb_a_l;
        }

        /* End of Signum: '<S476>/Sign5' */

        /* Signum: '<S476>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S476>/Sign3' */

        /* Signum: '<S476>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S476>/Sign4' */

        /* Update for DiscreteIntegrator: '<S475>/Integrator' incorporates:
         *  Constant: '<S476>/const'
         *  Gain: '<S476>/Gain3'
         *  Product: '<S476>/Divide'
         *  Product: '<S476>/Multiply5'
         *  Product: '<S476>/Multiply6'
         *  Sum: '<S476>/Subtract4'
         *  Sum: '<S476>/Subtract5'
         *  Sum: '<S476>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_a_l / FMS_ConstB.d_m -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4_a * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_DiscreteTimeIntegrator_n * 9.806F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S37>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Land' incorporates:
           *  ActionPort: '<S342>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S387>/Integrator'
           *  DiscreteIntegrator: '<S387>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Land' incorporates:
         *  ActionPort: '<S342>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S392>/Trigonometric Function1' incorporates:
         *  Gain: '<S391>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S392>/Trigonometric Function' incorporates:
         *  Gain: '<S391>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S392>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S392>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S392>/Gain' incorporates:
         *  Gain: '<S391>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S392>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S392>/Trigonometric Function3' incorporates:
         *  Gain: '<S391>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S392>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S392>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S392>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S385>/Saturation1' */
        rtb_MathFunction_f_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_DiscreteTimeIntegrator_n = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S389>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S389>/Sum'
         */
        rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_a_l = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S389>/Multiply' incorporates:
         *  SignalConversion: '<S389>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_a_l + rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1;
        }

        /* End of Product: '<S389>/Multiply' */

        /* Saturate: '<S385>/Saturation1' incorporates:
         *  Gain: '<S389>/Gain2'
         */
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S342>/Bus Assignment1'
         *  Constant: '<S342>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S342>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S385>/Saturation1' */
        if (rtb_Gain_fj > rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        } else if (rtb_Gain_fj < rtb_DiscreteTimeIntegrator_n) {
          /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_DiscreteTimeIntegrator_n;
        } else {
          /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        }

        if (rtb_Add3_c > rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_0;
        } else if (rtb_Add3_c < rtb_DiscreteTimeIntegrator_n) {
          /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_DiscreteTimeIntegrator_n;
        } else {
          /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S342>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S387>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S388>/Multiply1' incorporates:
         *  Constant: '<S388>/const1'
         *  DiscreteIntegrator: '<S387>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S384>/Switch' incorporates:
         *  Constant: '<S384>/Land_Speed'
         *  Constant: '<S386>/Constant'
         *  Gain: '<S384>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S384>/Logical Operator'
         *  RelationalOperator: '<S386>/Compare'
         *  S-Function (sfix_bitop): '<S384>/cmd_p valid'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_a_l = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_a_l = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S384>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S388>/Add' incorporates:
         *  DiscreteIntegrator: '<S387>/Integrator1'
         *  Sum: '<S387>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_j - rtb_a_l) +
          rtb_Add3_c;

        /* Signum: '<S388>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S388>/Sign' */

        /* Sum: '<S388>/Add2' incorporates:
         *  Abs: '<S388>/Abs'
         *  Gain: '<S388>/Gain'
         *  Gain: '<S388>/Gain1'
         *  Product: '<S388>/Multiply2'
         *  Product: '<S388>/Multiply3'
         *  Sqrt: '<S388>/Sqrt'
         *  Sum: '<S388>/Add1'
         *  Sum: '<S388>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_p) *
                         FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_Add3_c;

        /* Sum: '<S388>/Add4' */
        rtb_DiscreteTimeIntegrator_n = (rtb_Divide_lr_idx_1 - rtb_a_l) +
          rtb_Add3_c;

        /* Sum: '<S388>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_p;

        /* Sum: '<S388>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_p;

        /* Signum: '<S388>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign1' */

        /* Signum: '<S388>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign2' */

        /* Sum: '<S388>/Add5' incorporates:
         *  Gain: '<S388>/Gain2'
         *  Product: '<S388>/Multiply4'
         *  Sum: '<S388>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_DiscreteTimeIntegrator_n;

        /* Update for DiscreteIntegrator: '<S387>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S387>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S388>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_p;

        /* Sum: '<S388>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_a_l + FMS_ConstB.d_p;

        /* Signum: '<S388>/Sign5' incorporates:
         *  Signum: '<S388>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S388>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S388>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_a_l;

          /* Signum: '<S388>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = rtb_a_l;
        }

        /* End of Signum: '<S388>/Sign5' */

        /* Signum: '<S388>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign3' */

        /* Signum: '<S388>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign4' */

        /* Update for DiscreteIntegrator: '<S387>/Integrator' incorporates:
         *  Constant: '<S388>/const'
         *  Gain: '<S388>/Gain3'
         *  Product: '<S388>/Divide'
         *  Product: '<S388>/Multiply5'
         *  Product: '<S388>/Multiply6'
         *  Sum: '<S388>/Subtract4'
         *  Sum: '<S388>/Subtract5'
         *  Sum: '<S388>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_a_l / FMS_ConstB.d_p -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4_e * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_DiscreteTimeIntegrator_n * 9.806F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S37>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S343>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S395>/Delay'
           *  Delay: '<S396>/Delay'
           *  Delay: '<S418>/Delay'
           *  DiscreteIntegrator: '<S399>/Integrator'
           *  DiscreteIntegrator: '<S399>/Integrator1'
           *  DiscreteIntegrator: '<S414>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S419>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_l = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
          FMS_DW.l1_heading_e = 0.0F;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Return' */

          /* SystemReset for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S343>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S430>/Motion Status'
           *  Chart: '<S440>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S37>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Return' incorporates:
         *  ActionPort: '<S343>/Action Port'
         */
        /* Delay: '<S418>/Delay' incorporates:
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
        /* Switch: '<S414>/Switch2' incorporates:
         *  Constant: '<S414>/vel'
         *  Constant: '<S423>/Constant'
         *  RelationalOperator: '<S423>/Compare'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S414>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* RelationalOperator: '<S413>/Compare' incorporates:
         *  Constant: '<S470>/Constant'
         *  DiscreteIntegrator: '<S419>/Discrete-Time Integrator'
         *  RelationalOperator: '<S470>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* DiscreteIntegrator: '<S414>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S440>/Motion State' incorporates:
         *  Constant: '<S440>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S440>/Square'
         *  Math: '<S440>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S440>/Sqrt'
         *  Sum: '<S440>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S439>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S439>/Hold Control' incorporates:
             *  ActionPort: '<S442>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S439>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S439>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S439>/Hold Control' incorporates:
           *  ActionPort: '<S442>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S439>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S439>/Brake Control' incorporates:
           *  ActionPort: '<S441>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S439>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S439>/Move Control' incorporates:
             *  ActionPort: '<S443>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S439>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S439>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S439>/Move Control' incorporates:
           *  ActionPort: '<S443>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S439>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S439>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S430>/Motion Status' incorporates:
         *  Abs: '<S430>/Abs'
         *  Constant: '<S430>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S429>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S429>/Hold Control' incorporates:
             *  ActionPort: '<S432>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S429>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S429>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S429>/Hold Control' incorporates:
           *  ActionPort: '<S432>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S429>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S429>/Brake Control' incorporates:
           *  ActionPort: '<S431>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S429>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S429>/Move Control' incorporates:
             *  ActionPort: '<S433>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S429>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S429>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S429>/Move Control' incorporates:
           *  ActionPort: '<S433>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S429>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S429>/Switch Case' */

        /* Switch: '<S394>/Switch' incorporates:
         *  Product: '<S418>/Multiply'
         *  Sum: '<S418>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S439>/Saturation1' */
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

          /* End of Saturate: '<S439>/Saturation1' */

          /* Saturate: '<S429>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S429>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S418>/Sum' incorporates:
           *  Delay: '<S418>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S467>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S414>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Add3_c = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S418>/Sum' incorporates:
           *  Delay: '<S418>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S414>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S426>/Sqrt' incorporates:
           *  Math: '<S426>/Square'
           *  Sum: '<S414>/Sum'
           *  Sum: '<S426>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
                             rtb_TmpSignalConversionAtMath_0 *
                             rtb_TmpSignalConversionAtMath_0);

          /* SignalConversion: '<S469>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* SignalConversion: '<S469>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S469>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S468>/Gain' incorporates:
           *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S466>/Add'
           */
          rtb_a_l = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S469>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S469>/Trigonometric Function1'
           */
          rtb_MathFunction_f_idx_0 = arm_cos_f32(rtb_a_l);
          rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S469>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S469>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_a_l);

          /* Gain: '<S469>/Gain' incorporates:
           *  Trigonometry: '<S469>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S469>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S469>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S469>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S469>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

          /* Switch: '<S425>/Switch2' incorporates:
           *  Constant: '<S414>/Constant2'
           *  DiscreteIntegrator: '<S414>/Acceleration_Speed'
           *  RelationalOperator: '<S425>/LowerRelop1'
           *  RelationalOperator: '<S425>/UpperRelop'
           *  Switch: '<S425>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_DiscreteTimeIntegrator_n)
          {
            rtb_a_l = rtb_DiscreteTimeIntegrator_n;
          } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
            /* Switch: '<S425>/Switch' incorporates:
             *  Constant: '<S414>/Constant2'
             */
            rtb_a_l = 0.0F;
          } else {
            rtb_a_l = FMS_DW.Acceleration_Speed_DSTATE_j;
          }

          /* End of Switch: '<S425>/Switch2' */

          /* Switch: '<S414>/Switch' */
          if (rtb_Sqrt_b > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
          } else {
            /* Gain: '<S414>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Sqrt_b;

            /* Switch: '<S424>/Switch2' incorporates:
             *  Constant: '<S414>/Constant1'
             *  RelationalOperator: '<S424>/LowerRelop1'
             *  RelationalOperator: '<S424>/UpperRelop'
             *  Switch: '<S424>/Switch'
             */
            if (rtb_Gain_fj > rtb_DiscreteTimeIntegrator_n) {
              rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S424>/Switch' incorporates:
                 *  Constant: '<S414>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S424>/Switch2' */
          }

          /* End of Switch: '<S414>/Switch' */

          /* Switch: '<S414>/Switch1' incorporates:
           *  Sum: '<S414>/Sum1'
           */
          if (rtb_a_l - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_a_l;
          }

          /* End of Switch: '<S414>/Switch1' */

          /* Sum: '<S467>/Sum of Elements' incorporates:
           *  Math: '<S467>/Math Function'
           */
          rtb_a_l = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_lr_idx_1 *
            rtb_Divide_lr_idx_1;

          /* Math: '<S467>/Math Function1' incorporates:
           *  Sum: '<S467>/Sum of Elements'
           *
           * About '<S467>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_l < 0.0F) {
            rtb_a_l = -sqrtf(fabsf(rtb_a_l));
          } else {
            rtb_a_l = sqrtf(rtb_a_l);
          }

          /* End of Math: '<S467>/Math Function1' */

          /* Switch: '<S467>/Switch' incorporates:
           *  Constant: '<S467>/Constant'
           *  Product: '<S467>/Product'
           */
          if (rtb_a_l <= 0.0F) {
            rtb_Add3_c = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_a_l = 1.0F;
          }

          /* End of Switch: '<S467>/Switch' */

          /* Product: '<S465>/Multiply2' incorporates:
           *  Product: '<S467>/Divide'
           */
          rtb_MathFunction_f_idx_0 = rtb_Add3_c / rtb_a_l * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_lr_idx_1 / rtb_a_l;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S420>/Sum1' incorporates:
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S420>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_l = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sqrt_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S420>/Divide' incorporates:
           *  Math: '<S421>/Square'
           *  Math: '<S422>/Square'
           *  Sqrt: '<S421>/Sqrt'
           *  Sqrt: '<S422>/Sqrt'
           *  Sum: '<S420>/Sum'
           *  Sum: '<S420>/Sum1'
           *  Sum: '<S421>/Sum of Elements'
           *  Sum: '<S422>/Sum of Elements'
           */
          rtb_a_l = sqrtf(rtb_a_l * rtb_a_l + rtb_Sqrt_b * rtb_Sqrt_b) / sqrtf
            (rtb_Add3_c * rtb_Add3_c + rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1);

          /* Saturate: '<S420>/Saturation' */
          if (rtb_a_l > 1.0F) {
            rtb_a_l = 1.0F;
          } else {
            if (rtb_a_l < 0.0F) {
              rtb_a_l = 0.0F;
            }
          }

          /* End of Saturate: '<S420>/Saturation' */

          /* Product: '<S418>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_MathFunction_f_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S411>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S420>/Multiply'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S411>/Sum2'
           *  Sum: '<S420>/Add'
           *  Sum: '<S420>/Subtract'
           */
          rtb_Gain_fj = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_a_l + FMS_B.Cmd_In.cur_waypoint
            [2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S411>/Saturation1' incorporates:
           *  Product: '<S418>/Multiply'
           */
          if (rtb_Gain_fj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Gain_fj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Gain_fj;
          }

          /* End of Saturate: '<S411>/Saturation1' */
        }

        /* End of Switch: '<S394>/Switch' */

        /* Delay: '<S396>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S399>/Integrator1' incorporates:
         *  Delay: '<S396>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_eh = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S403>/Rem' incorporates:
         *  Constant: '<S403>/Constant1'
         *  DiscreteIntegrator: '<S399>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S398>/Sum'
         */
        rtb_Add3_c = rt_remf(FMS_DW.Integrator1_DSTATE_eh - FMS_U.INS_Out.psi,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S403>/Switch' incorporates:
         *  Abs: '<S403>/Abs'
         *  Constant: '<S403>/Constant'
         *  Constant: '<S404>/Constant'
         *  Product: '<S403>/Multiply'
         *  RelationalOperator: '<S404>/Compare'
         *  Sum: '<S403>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S403>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          } else {
            rtb_Divide_lr_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S403>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_lr_idx_1;
        }

        /* End of Switch: '<S403>/Switch' */

        /* Gain: '<S398>/Gain2' */
        rtb_Add3_c *= FMS_PARAM.YAW_P;

        /* Saturate: '<S398>/Saturation' */
        if (rtb_Add3_c > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Add3_c = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Add3_c < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add3_c = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S398>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S343>/Bus Assignment1'
         *  Constant: '<S343>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S343>/Bus Assignment1' incorporates:
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
        /* Sum: '<S460>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S460>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S458>/Sum of Elements'
         */
        rtb_a_l = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S460>/Math Function1' incorporates:
         *  Sum: '<S460>/Sum of Elements'
         *
         * About '<S460>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_a_l < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_a_l));
        } else {
          rtb_Add3_c = sqrtf(rtb_a_l);
        }

        /* End of Math: '<S460>/Math Function1' */

        /* Switch: '<S460>/Switch' incorporates:
         *  Constant: '<S460>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S460>/Product'
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

        /* End of Switch: '<S460>/Switch' */

        /* Delay: '<S395>/Delay' incorporates:
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
        /* Sum: '<S343>/Sum' incorporates:
         *  Delay: '<S395>/Delay'
         *  MATLAB Function: '<S416>/OutRegionRegWP'
         *  MATLAB Function: '<S416>/SearchL1RefWP'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S410>/Sum of Elements' incorporates:
         *  Math: '<S410>/Math Function'
         *  Sum: '<S343>/Sum'
         */
        rtb_Divide_lr_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_P_l_idx_0 * rtb_P_l_idx_0;

        /* Math: '<S410>/Math Function1' incorporates:
         *  Sum: '<S410>/Sum of Elements'
         *
         * About '<S410>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S410>/Math Function1' */

        /* Switch: '<S410>/Switch' incorporates:
         *  Constant: '<S410>/Constant'
         *  Product: '<S410>/Product'
         *  Sum: '<S343>/Sum'
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

        /* End of Switch: '<S410>/Switch' */

        /* Product: '<S460>/Divide' */
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S463>/Sum of Elements' incorporates:
         *  Math: '<S463>/Math Function'
         *  SignalConversion: '<S463>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S463>/Math Function1' incorporates:
         *  Sum: '<S463>/Sum of Elements'
         *
         * About '<S463>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S463>/Math Function1' */

        /* Switch: '<S463>/Switch' incorporates:
         *  Constant: '<S463>/Constant'
         *  Product: '<S463>/Product'
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

        /* End of Switch: '<S463>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S416>/NearbyRefWP' incorporates:
         *  Constant: '<S343>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S416>/SearchL1RefWP' incorporates:
         *  Constant: '<S343>/L1'
         *  Delay: '<S395>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Divide_lr_idx_1);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Sqrt_b = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Divide_lr_idx_1);
          rtb_Divide_lr_idx_1 = (-B - u1_tmp) / (2.0F * rtb_Divide_lr_idx_1);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Divide_lr_idx_1 >= 0.0F) &&
              (rtb_Divide_lr_idx_1 <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Divide_lr_idx_1);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Divide_lr_idx_1 >= 0.0F) && (rtb_Divide_lr_idx_1 <= 1.0F))
            {
              rtb_Add3_c = rtb_Divide_lr_idx_1;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Divide_lr_idx_1);
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
        /* MATLAB Function: '<S416>/OutRegionRegWP' incorporates:
         *  Delay: '<S395>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_lr_idx_1 = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
          rtb_TmpSignalConversionAtMath_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_lr_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_lr_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Divide_lr_idx_1 * rtb_P_l_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S416>/Switch1' incorporates:
         *  Constant: '<S453>/Constant'
         *  RelationalOperator: '<S453>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S416>/Switch' incorporates:
           *  Constant: '<S452>/Constant'
           *  MATLAB Function: '<S416>/SearchL1RefWP'
           *  RelationalOperator: '<S452>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Sqrt_b;
            rtb_Sum_ff[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S416>/OutRegionRegWP' incorporates:
             *  Delay: '<S395>/Delay'
             *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Divide_lr_idx_1 *
                rtb_TmpSignalConversionAtMath_0 + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S416>/Switch' */
        }

        /* End of Switch: '<S416>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S417>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Rem_p;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Rem_p * rtb_Rem_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S417>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S461>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S461>/Math Function' incorporates:
         *  Math: '<S459>/Square'
         */
        rtb_Divide_lr_idx_1 = rtb_Rem_p * rtb_Rem_p;

        /* Sum: '<S461>/Sum of Elements' incorporates:
         *  Math: '<S461>/Math Function'
         */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S461>/Math Function1' incorporates:
         *  Sum: '<S461>/Sum of Elements'
         *
         * About '<S461>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S461>/Math Function1' */

        /* Switch: '<S461>/Switch' incorporates:
         *  Constant: '<S461>/Constant'
         *  Product: '<S461>/Product'
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

        /* End of Switch: '<S461>/Switch' */

        /* Product: '<S461>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S464>/Sum of Elements' incorporates:
         *  Math: '<S464>/Math Function'
         *  SignalConversion: '<S464>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S464>/Math Function1' incorporates:
         *  Sum: '<S464>/Sum of Elements'
         *
         * About '<S464>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S464>/Math Function1' */

        /* Switch: '<S464>/Switch' incorporates:
         *  Constant: '<S464>/Constant'
         *  Product: '<S464>/Product'
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

        /* End of Switch: '<S464>/Switch' */

        /* Product: '<S464>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S459>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S410>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S464>/Divide' incorporates:
         *  Product: '<S463>/Divide'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S463>/Divide' */
        rtb_Rem_p = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S410>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Sqrt: '<S458>/Sqrt' */
        rtb_Add3_c = sqrtf(rtb_a_l);

        /* Gain: '<S417>/Gain' incorporates:
         *  Math: '<S417>/Square'
         */
        rtb_MathFunction_f_idx_0 = rtb_Add3_c * rtb_Add3_c * 2.0F;

        /* Sum: '<S462>/Subtract' incorporates:
         *  Product: '<S462>/Multiply'
         *  Product: '<S462>/Multiply1'
         */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_0 * rtb_Rem_p - rtb_P_l_idx_0
          * rtb_Sum_ff[0];

        /* Signum: '<S457>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S457>/Sign1' */

        /* Switch: '<S457>/Switch2' incorporates:
         *  Constant: '<S457>/Constant4'
         */
        if (rtb_Add3_c == 0.0F) {
          rtb_Add3_c = 1.0F;
        }

        /* End of Switch: '<S457>/Switch2' */

        /* DotProduct: '<S457>/Dot Product' */
        rtb_Rem_p = rtb_Sum_ff[0] * rtb_TmpSignalConversionAtMath_0 + rtb_Rem_p *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S457>/Acos' incorporates:
         *  DotProduct: '<S457>/Dot Product'
         */
        if (rtb_Rem_p > 1.0F) {
          rtb_Rem_p = 1.0F;
        } else {
          if (rtb_Rem_p < -1.0F) {
            rtb_Rem_p = -1.0F;
          }
        }

        /* Product: '<S457>/Multiply' incorporates:
         *  Trigonometry: '<S457>/Acos'
         */
        rtb_Add3_c *= acosf(rtb_Rem_p);

        /* Saturate: '<S417>/Saturation' */
        if (rtb_Add3_c > 1.57079637F) {
          rtb_Add3_c = 1.57079637F;
        } else {
          if (rtb_Add3_c < -1.57079637F) {
            rtb_Add3_c = -1.57079637F;
          }
        }

        /* End of Saturate: '<S417>/Saturation' */

        /* Product: '<S417>/Divide' incorporates:
         *  Constant: '<S343>/L1'
         *  Constant: '<S417>/Constant'
         *  MinMax: '<S417>/Max'
         *  MinMax: '<S417>/Min'
         *  Product: '<S417>/Multiply1'
         *  Sqrt: '<S459>/Sqrt'
         *  Sum: '<S459>/Sum of Elements'
         *  Trigonometry: '<S417>/Sin'
         */
        rtb_a_l = arm_sin_f32(rtb_Add3_c) * rtb_MathFunction_f_idx_0 / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Divide_lr_idx_1 +
             rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S408>/Subtract' incorporates:
         *  Product: '<S408>/Multiply'
         *  Product: '<S408>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sqrt_b * FMS_ConstB.Divide_d[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S397>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S397>/Sign1' */

        /* Switch: '<S397>/Switch2' incorporates:
         *  Constant: '<S397>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S397>/Switch2' */

        /* DotProduct: '<S397>/Dot Product' */
        rtb_Gain_fj = FMS_ConstB.Divide_d[0] * rtb_Sqrt_b + FMS_ConstB.Divide_d
          [1] * rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S397>/Acos' incorporates:
         *  DotProduct: '<S397>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S397>/Multiply' incorporates:
         *  Trigonometry: '<S397>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_Gain_fj);

        /* Math: '<S400>/Rem' incorporates:
         *  Constant: '<S400>/Constant1'
         *  Delay: '<S396>/Delay'
         *  Sum: '<S396>/Sum2'
         */
        rtb_Add3_c = rt_remf(rtb_MathFunction_f_idx_2 - FMS_DW.Delay_DSTATE_a,
                             6.28318548F);

        /* Switch: '<S400>/Switch' incorporates:
         *  Abs: '<S400>/Abs'
         *  Constant: '<S400>/Constant'
         *  Constant: '<S406>/Constant'
         *  Product: '<S400>/Multiply'
         *  RelationalOperator: '<S406>/Compare'
         *  Sum: '<S400>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S400>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          } else {
            rtb_Divide_lr_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S400>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_lr_idx_1;
        }

        /* End of Switch: '<S400>/Switch' */

        /* Sum: '<S396>/Sum' incorporates:
         *  Delay: '<S396>/Delay'
         */
        rtb_Divide_lr_idx_1 = rtb_Add3_c + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S405>/Multiply1' incorporates:
         *  Constant: '<S405>/const1'
         *  DiscreteIntegrator: '<S399>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_b * 0.785398185F;

        /* Sum: '<S405>/Add' incorporates:
         *  DiscreteIntegrator: '<S399>/Integrator1'
         *  Sum: '<S399>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_eh -
          rtb_Divide_lr_idx_1) + rtb_Add3_c;

        /* Signum: '<S405>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S405>/Sign' */

        /* Sum: '<S405>/Add2' incorporates:
         *  Abs: '<S405>/Abs'
         *  Gain: '<S405>/Gain'
         *  Gain: '<S405>/Gain1'
         *  Product: '<S405>/Multiply2'
         *  Product: '<S405>/Multiply3'
         *  Sqrt: '<S405>/Sqrt'
         *  Sum: '<S405>/Add1'
         *  Sum: '<S405>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_le)
                           * FMS_ConstB.d_le) - FMS_ConstB.d_le) * 0.5F *
          rtb_MathFunction_f_idx_0 + rtb_Add3_c;

        /* Sum: '<S405>/Add4' */
        rtb_MathFunction_f_idx_0 = (rtb_Divide_lr_idx_1 - rtb_Rem_p) +
          rtb_Add3_c;

        /* Sum: '<S405>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_le;

        /* Sum: '<S405>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_le;

        /* Signum: '<S405>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S405>/Sign1' */

        /* Signum: '<S405>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S405>/Sign2' */

        /* Sum: '<S405>/Add5' incorporates:
         *  Gain: '<S405>/Gain2'
         *  Product: '<S405>/Multiply4'
         *  Sum: '<S405>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S405>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d_le;

        /* Sum: '<S405>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Rem_p - FMS_ConstB.d_le;

        /* Product: '<S405>/Divide' */
        rtb_Sqrt_b = rtb_Rem_p / FMS_ConstB.d_le;

        /* Signum: '<S405>/Sign5' incorporates:
         *  Signum: '<S405>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S405>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S405>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Rem_p;

          /* Signum: '<S405>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_Rem_p;
        }

        /* End of Signum: '<S405>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S396>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S401>/Rem' incorporates:
         *  Constant: '<S401>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S401>/Switch' incorporates:
         *  Abs: '<S401>/Abs'
         *  Constant: '<S401>/Constant'
         *  Constant: '<S407>/Constant'
         *  Product: '<S401>/Multiply'
         *  RelationalOperator: '<S407>/Compare'
         *  Sum: '<S401>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S401>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Gain_fj = 1.0F;
          } else {
            rtb_Gain_fj = rtb_Rem_p;
          }

          /* End of Signum: '<S401>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Gain_fj;
        }

        /* End of Switch: '<S401>/Switch' */

        /* Abs: '<S394>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S418>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S419>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S412>/Constant'
         *  RelationalOperator: '<S412>/Compare'
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

        /* End of Update for DiscreteIntegrator: '<S419>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S414>/Acceleration_Speed' incorporates:
         *  Constant: '<S414>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Product: '<S418>/Divide1' */
        rtb_Gain_fj = rtb_a_l / rtb_DiscreteTimeIntegrator_n;

        /* Saturate: '<S418>/Saturation' */
        if (rtb_Gain_fj > 0.314159274F) {
          rtb_Gain_fj = 0.314159274F;
        } else {
          if (rtb_Gain_fj < -0.314159274F) {
            rtb_Gain_fj = -0.314159274F;
          }
        }

        /* End of Saturate: '<S418>/Saturation' */

        /* Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Gain_fj;

        /* Update for Delay: '<S396>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S399>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S399>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_eh += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Update for Delay: '<S395>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S405>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S405>/Sign3' */

        /* Signum: '<S405>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S405>/Sign4' */

        /* Update for DiscreteIntegrator: '<S399>/Integrator' incorporates:
         *  Constant: '<S405>/const'
         *  Gain: '<S405>/Gain3'
         *  Product: '<S405>/Multiply5'
         *  Product: '<S405>/Multiply6'
         *  Sum: '<S405>/Subtract4'
         *  Sum: '<S405>/Subtract5'
         *  Sum: '<S405>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1) *
          FMS_ConstB.Gain4_np * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_b >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_b = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_b <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_b = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S399>/Integrator' */
        /* End of Outputs for SubSystem: '<S37>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S37>/Hold' incorporates:
           *  ActionPort: '<S341>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S350>/Motion Status'
           *  Chart: '<S360>/Motion State'
           *  Chart: '<S372>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S37>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Hold' incorporates:
         *  ActionPort: '<S341>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S350>/Motion Status' incorporates:
         *  Abs: '<S350>/Abs'
         *  Constant: '<S350>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S360>/Motion State' incorporates:
         *  Abs: '<S360>/Abs'
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

        /* End of Chart: '<S360>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S372>/Motion State' incorporates:
         *  Constant: '<S372>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S372>/Square'
         *  Math: '<S372>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S372>/Sqrt'
         *  Sum: '<S372>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S371>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S371>/Hold Control' incorporates:
             *  ActionPort: '<S374>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S371>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S371>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S371>/Hold Control' incorporates:
           *  ActionPort: '<S374>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S371>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S371>/Brake Control' incorporates:
           *  ActionPort: '<S373>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S371>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S371>/Move Control' incorporates:
             *  ActionPort: '<S375>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S371>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S371>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S371>/Move Control' incorporates:
           *  ActionPort: '<S375>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S371>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S371>/Switch Case' */

        /* SwitchCase: '<S349>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S349>/Hold Control' incorporates:
             *  ActionPort: '<S352>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S349>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S349>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S349>/Hold Control' incorporates:
           *  ActionPort: '<S352>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S349>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S349>/Brake Control' incorporates:
           *  ActionPort: '<S351>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S349>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S349>/Move Control' incorporates:
             *  ActionPort: '<S353>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S349>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S349>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S349>/Move Control' incorporates:
           *  ActionPort: '<S353>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S349>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S349>/Switch Case' */

        /* SwitchCase: '<S359>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S359>/Hold Control' incorporates:
             *  ActionPort: '<S362>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S359>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S359>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S359>/Hold Control' incorporates:
           *  ActionPort: '<S362>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S359>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S359>/Brake Control' incorporates:
           *  ActionPort: '<S361>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S359>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S359>/Move Control' incorporates:
             *  ActionPort: '<S363>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S359>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S359>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S359>/Move Control' incorporates:
           *  ActionPort: '<S363>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S359>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S359>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S341>/Bus Assignment'
         *  Constant: '<S341>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S341>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S359>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S359>/Saturation' */

        /* Saturate: '<S371>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S371>/Saturation1' */

        /* Saturate: '<S349>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S341>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S349>/Saturation1' */
        /* End of Outputs for SubSystem: '<S37>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S345>/Action Port'
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
       *  Math: '<S225>/Square'
       *  Math: '<S227>/Math Function'
       *  Sum: '<S183>/Subtract'
       *  Sum: '<S240>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S154>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S205>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S195>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S154>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S35>/Offboard' incorporates:
         *  ActionPort: '<S155>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S319>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S322>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S323>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S323>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S323>/Multiply1' incorporates:
         *  Product: '<S323>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S323>/Divide' incorporates:
         *  Constant: '<S323>/Constant'
         *  Constant: '<S323>/R'
         *  Sqrt: '<S323>/Sqrt'
         *  Sum: '<S323>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S323>/Product3' incorporates:
         *  Constant: '<S323>/Constant1'
         *  Product: '<S323>/Multiply1'
         *  Sum: '<S323>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S323>/Multiply2' incorporates:
         *  Trigonometry: '<S323>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S322>/Sum' incorporates:
         *  Gain: '<S319>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S327>/Abs' incorporates:
         *  Abs: '<S330>/Abs1'
         *  Switch: '<S327>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S327>/Switch1' incorporates:
         *  Abs: '<S327>/Abs'
         *  Bias: '<S327>/Bias2'
         *  Bias: '<S327>/Bias3'
         *  Constant: '<S324>/Constant'
         *  Constant: '<S324>/Constant1'
         *  Constant: '<S329>/Constant'
         *  Gain: '<S327>/Gain1'
         *  Product: '<S327>/Multiply'
         *  RelationalOperator: '<S329>/Compare'
         *  Switch: '<S324>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S330>/Switch1' incorporates:
           *  Bias: '<S330>/Bias2'
           *  Bias: '<S330>/Bias3'
           *  Constant: '<S330>/Constant'
           *  Constant: '<S331>/Constant'
           *  Math: '<S330>/Math Function'
           *  RelationalOperator: '<S331>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S330>/Switch1' */

          /* Signum: '<S327>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S327>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S324>/Sum' incorporates:
         *  Gain: '<S319>/Gain1'
         *  Gain: '<S319>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S322>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S322>/Multiply' incorporates:
         *  Gain: '<S322>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S326>/Switch1' incorporates:
         *  Abs: '<S326>/Abs1'
         *  Bias: '<S326>/Bias2'
         *  Bias: '<S326>/Bias3'
         *  Constant: '<S326>/Constant'
         *  Constant: '<S328>/Constant'
         *  Math: '<S326>/Math Function'
         *  RelationalOperator: '<S328>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S326>/Switch1' */

        /* Product: '<S322>/Multiply' incorporates:
         *  Gain: '<S322>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S300>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S304>/Multiply1'
         *  Product: '<S305>/Multiply3'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S313>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S313>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S313>/Trigonometric Function3' incorporates:
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S313>/Gain' incorporates:
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S313>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S313>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S313>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S313>/Trigonometric Function' incorporates:
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S313>/Trigonometric Function1' incorporates:
           *  Gain: '<S312>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S304>/Saturation' incorporates:
           *  Constant: '<S310>/Constant'
           *  Constant: '<S311>/Constant'
           *  Constant: '<S321>/Constant'
           *  DataTypeConversion: '<S319>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S303>/Logical Operator'
           *  Product: '<S304>/Multiply'
           *  Product: '<S325>/Multiply1'
           *  Product: '<S325>/Multiply2'
           *  RelationalOperator: '<S310>/Compare'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S321>/Compare'
           *  S-Function (sfix_bitop): '<S303>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S318>/lat_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S304>/Sum1'
           *  Sum: '<S325>/Sum2'
           *  Switch: '<S306>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_a_l = (real32_T)(rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o2 +
                                 rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_a_l = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_a_l -
            FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Gain_fj > 4.0F) {
            rtb_Gain_fj = 4.0F;
          } else {
            if (rtb_Gain_fj < -4.0F) {
              rtb_Gain_fj = -4.0F;
            }
          }

          /* SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S304>/Saturation' incorporates:
           *  Constant: '<S310>/Constant'
           *  Constant: '<S311>/Constant'
           *  Constant: '<S321>/Constant'
           *  DataTypeConversion: '<S319>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S303>/Logical Operator'
           *  Product: '<S304>/Multiply'
           *  Product: '<S325>/Multiply3'
           *  Product: '<S325>/Multiply4'
           *  RelationalOperator: '<S310>/Compare'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S321>/Compare'
           *  S-Function (sfix_bitop): '<S303>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S318>/lon_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S304>/Sum1'
           *  Sum: '<S325>/Sum3'
           *  Switch: '<S306>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_a_l = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                 rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_a_l = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_a_l -
            FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Add3_c > 4.0F) {
            rtb_Add3_c = 4.0F;
          } else {
            if (rtb_Add3_c < -4.0F) {
              rtb_Add3_c = -4.0F;
            }
          }

          /* SignalConversion: '<S313>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S304>/Saturation' incorporates:
           *  Constant: '<S310>/Constant'
           *  Constant: '<S311>/Constant'
           *  Constant: '<S321>/Constant'
           *  DataTypeConversion: '<S319>/Data Type Conversion'
           *  DataTypeConversion: '<S319>/Data Type Conversion1'
           *  Gain: '<S307>/Gain'
           *  Gain: '<S319>/Gain2'
           *  Gain: '<S322>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S303>/Logical Operator'
           *  Product: '<S304>/Multiply'
           *  RelationalOperator: '<S310>/Compare'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S321>/Compare'
           *  S-Function (sfix_bitop): '<S303>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S318>/alt_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S304>/Sum1'
           *  Sum: '<S322>/Sum1'
           *  Switch: '<S306>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_a_l = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd + -FMS_U.INS_Out.alt_0);
          } else {
            rtb_a_l = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_Divide_lr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_a_l -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_Divide_lr_idx_1 > 2.0F) {
            rtb_Divide_lr_idx_1 = 2.0F;
          } else {
            if (rtb_Divide_lr_idx_1 < -2.0F) {
              rtb_Divide_lr_idx_1 = -2.0F;
            }
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Add3_c +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Gain_fj);
          }

          /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S247>/Constant4'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  Product: '<S304>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S247>/Trigonometric Function3' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S247>/Gain' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S247>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S247>/Constant3'
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S247>/Trigonometric Function' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S247>/Trigonometric Function1' incorporates:
           *  Gain: '<S246>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S237>/Multiply' incorporates:
           *  Constant: '<S245>/Constant'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/ax_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S237>/Multiply' incorporates:
           *  Constant: '<S245>/Constant'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/ay_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S237>/Multiply' incorporates:
           *  Constant: '<S245>/Constant'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S237>/Index Vector' incorporates:
           *  Product: '<S243>/Multiply'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_a_l +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S317>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S317>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S315>/Gain' incorporates:
           *  Gain: '<S248>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S305>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S317>/Trigonometric Function3' incorporates:
           *  Gain: '<S315>/Gain'
           *  Trigonometry: '<S317>/Trigonometric Function1'
           */
          rtb_MathFunction_f_idx_0 = arm_cos_f32(rtb_Add3_c);
          rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S317>/Trigonometric Function2' incorporates:
           *  Gain: '<S315>/Gain'
           *  Trigonometry: '<S317>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S317>/Gain' incorporates:
           *  Trigonometry: '<S317>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S317>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S317>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S317>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S317>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S316>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S316>/Constant4'
           */
          rtb_VectorConcatenate_e[5] = 0.0F;

          /* Trigonometry: '<S316>/Trigonometric Function3' incorporates:
           *  Gain: '<S314>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S316>/Trigonometric Function1'
           */
          rtb_Divide_lr_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_e[4] = rtb_Divide_lr_idx_1;

          /* Trigonometry: '<S316>/Trigonometric Function2' incorporates:
           *  Gain: '<S314>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S316>/Trigonometric Function'
           */
          rtb_DiscreteTimeIntegrator_n = arm_sin_f32
            (-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S316>/Gain' incorporates:
           *  Trigonometry: '<S316>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_e[3] = -rtb_DiscreteTimeIntegrator_n;

          /* SignalConversion: '<S316>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S316>/Constant3'
           */
          rtb_VectorConcatenate_e[2] = 0.0F;

          /* Trigonometry: '<S316>/Trigonometric Function' */
          rtb_VectorConcatenate_e[1] = rtb_DiscreteTimeIntegrator_n;

          /* Trigonometry: '<S316>/Trigonometric Function1' */
          rtb_VectorConcatenate_e[0] = rtb_Divide_lr_idx_1;

          /* RelationalOperator: '<S321>/Compare' incorporates:
           *  Constant: '<S321>/Constant'
           *  S-Function (sfix_bitop): '<S318>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S318>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S318>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S319>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S319>/Data Type Conversion'
           *  Gain: '<S319>/Gain2'
           *  Gain: '<S322>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S325>/Multiply1'
           *  Product: '<S325>/Multiply2'
           *  Product: '<S325>/Multiply3'
           *  Product: '<S325>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S322>/Sum1'
           *  Sum: '<S325>/Sum2'
           *  Sum: '<S325>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S306>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S310>/Compare' incorporates:
           *  Constant: '<S310>/Constant'
           *  S-Function (sfix_bitop): '<S303>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S311>/Compare' incorporates:
           *  Constant: '<S311>/Constant'
           *  S-Function (sfix_bitop): '<S303>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S305>/Sum2' incorporates:
             *  Product: '<S305>/Multiply2'
             *  Switch: '<S306>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_a_l = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_a_l = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S305>/Saturation1' incorporates:
             *  Gain: '<S307>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S303>/Logical Operator'
             *  Product: '<S305>/Multiply'
             *  Product: '<S305>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             *  Sum: '<S305>/Sum2'
             */
            rtb_Gain_fj = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_a_l - ((rtb_VectorConcatenate_e[rtb_Compare_bv_0 + 3] *
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

            /* End of Saturate: '<S305>/Saturation1' */
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

          /* SignalConversion: '<S249>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S249>/Constant4'
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  Product: '<S305>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S249>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S249>/Gain' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           *  Trigonometry: '<S249>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S249>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S249>/Constant3'
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S249>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S249>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S249>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S237>/Multiply' incorporates:
           *  Constant: '<S245>/Constant'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/ax_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S249>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S237>/Multiply' incorporates:
           *  Constant: '<S245>/Constant'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/ay_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S249>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S237>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S237>/Multiply' incorporates:
           *  Constant: '<S245>/Constant'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S237>/Index Vector' incorporates:
           *  Product: '<S244>/Multiply3'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_a_l +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         default:
          /* SignalConversion: '<S309>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S309>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S309>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S309>/Trigonometric Function3' incorporates:
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S309>/Gain' incorporates:
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S309>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S309>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S309>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S309>/Trigonometric Function' incorporates:
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S309>/Trigonometric Function1' incorporates:
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S318>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S303>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S321>/Compare' incorporates:
           *  Constant: '<S321>/Constant'
           *  S-Function (sfix_bitop): '<S318>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S318>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S303>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S321>/Compare' incorporates:
           *  Constant: '<S321>/Constant'
           *  S-Function (sfix_bitop): '<S318>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S318>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S303>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S321>/Compare' incorporates:
           *  Constant: '<S321>/Constant'
           *  S-Function (sfix_bitop): '<S318>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S319>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S319>/Data Type Conversion'
           *  Gain: '<S319>/Gain2'
           *  Gain: '<S322>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S325>/Multiply1'
           *  Product: '<S325>/Multiply2'
           *  Product: '<S325>/Multiply3'
           *  Product: '<S325>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S322>/Sum1'
           *  Sum: '<S325>/Sum2'
           *  Sum: '<S325>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S306>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S310>/Compare' incorporates:
           *  Constant: '<S310>/Constant'
           *  S-Function (sfix_bitop): '<S303>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S303>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S311>/Compare' incorporates:
           *  Constant: '<S311>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S302>/Sum2' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S306>/Switch' incorporates:
             *  Product: '<S302>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_a_l = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_a_l = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S302>/Saturation1' incorporates:
             *  Gain: '<S307>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S303>/Logical Operator'
             *  Product: '<S302>/Multiply'
             *  Product: '<S302>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             */
            rtb_Gain_fj = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_a_l - ((rtb_Transpose[rtb_Compare_bv_0 + 3] *
                          FMS_U.INS_Out.y_R + rtb_Transpose[rtb_Compare_bv_0] *
                          FMS_U.INS_Out.x_R) + rtb_Transpose[rtb_Compare_bv_0 +
                         6] * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Gain_fj > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Gain_fj < FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] = rtb_Gain_fj;
            }

            /* End of Saturate: '<S302>/Saturation1' */
          }

          /* End of Sum: '<S302>/Sum2' */

          /* MultiPortSwitch: '<S237>/Index Vector' incorporates:
           *  Constant: '<S245>/Constant'
           *  Product: '<S237>/Multiply'
           *  RelationalOperator: '<S245>/Compare'
           *  S-Function (sfix_bitop): '<S242>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/az_cmd valid'
           */
          rtb_TmpSignalConversionAtMath_c[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S300>/Index Vector' */

        /* Sum: '<S296>/Sum1' incorporates:
         *  Constant: '<S296>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S296>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_0 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F)
          - FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S297>/Abs' */
        rtb_Add3_c = fabsf(rtb_MathFunction_f_idx_0);

        /* Switch: '<S297>/Switch' incorporates:
         *  Constant: '<S297>/Constant'
         *  Constant: '<S298>/Constant'
         *  Product: '<S297>/Multiply'
         *  RelationalOperator: '<S298>/Compare'
         *  Sum: '<S297>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S297>/Sign' */
          if (rtb_MathFunction_f_idx_0 < 0.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          } else {
            if (rtb_MathFunction_f_idx_0 > 0.0F) {
              rtb_MathFunction_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S297>/Sign' */
          rtb_MathFunction_f_idx_0 *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S297>/Switch' */

        /* Saturate: '<S296>/Saturation' */
        if (rtb_MathFunction_f_idx_0 > 0.314159274F) {
          rtb_MathFunction_f_idx_0 = 0.314159274F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -0.314159274F) {
            rtb_MathFunction_f_idx_0 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S296>/Saturation' */

        /* Gain: '<S293>/Gain2' */
        rtb_MathFunction_f_idx_0 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S239>/Sum' incorporates:
         *  Constant: '<S295>/Constant'
         *  Constant: '<S299>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S293>/Multiply2'
         *  Product: '<S294>/Multiply1'
         *  RelationalOperator: '<S295>/Compare'
         *  RelationalOperator: '<S299>/Compare'
         *  S-Function (sfix_bitop): '<S293>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S294>/psi_rate_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                       rtb_MathFunction_f_idx_0 : 0.0F) +
          ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
           0.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S300>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_DiscreteTimeIntegrator_n = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S300>/Gain2' */
        rtb_MathFunction_f_idx_0 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S301>/Index Vector' incorporates:
         *  Constant: '<S336>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S301>/Multiply'
         *  Product: '<S334>/Multiply'
         *  Product: '<S335>/Multiply3'
         *  RelationalOperator: '<S336>/Compare'
         *  S-Function (sfix_bitop): '<S333>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S333>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S333>/w_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S338>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S338>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S338>/Trigonometric Function3' incorporates:
           *  Gain: '<S337>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S338>/Gain' incorporates:
           *  Gain: '<S337>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S338>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S338>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S338>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S338>/Trigonometric Function' incorporates:
           *  Gain: '<S337>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S338>/Trigonometric Function1' incorporates:
           *  Gain: '<S337>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S338>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S301>/Multiply' incorporates:
           *  Constant: '<S336>/Constant'
           *  RelationalOperator: '<S336>/Compare'
           *  S-Function (sfix_bitop): '<S333>/u_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S338>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S301>/Multiply' incorporates:
           *  Constant: '<S336>/Constant'
           *  RelationalOperator: '<S336>/Compare'
           *  S-Function (sfix_bitop): '<S333>/v_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S338>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S301>/Multiply' incorporates:
           *  Constant: '<S336>/Constant'
           *  RelationalOperator: '<S336>/Compare'
           *  S-Function (sfix_bitop): '<S333>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_a_l +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S340>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S340>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S339>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S335>/Subtract'
           */
          rtb_Divide_lr_idx_1 = -(FMS_U.INS_Out.psi -
            FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S340>/Trigonometric Function3' incorporates:
           *  Gain: '<S339>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Divide_lr_idx_1);

          /* Gain: '<S340>/Gain' incorporates:
           *  Gain: '<S339>/Gain'
           *  Trigonometry: '<S340>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_lr_idx_1);

          /* SignalConversion: '<S340>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S340>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S340>/Trigonometric Function' incorporates:
           *  Gain: '<S339>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Divide_lr_idx_1);

          /* Trigonometry: '<S340>/Trigonometric Function1' incorporates:
           *  Gain: '<S339>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Divide_lr_idx_1);

          /* SignalConversion: '<S340>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S301>/Multiply' incorporates:
           *  Constant: '<S336>/Constant'
           *  RelationalOperator: '<S336>/Compare'
           *  S-Function (sfix_bitop): '<S333>/u_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S340>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S301>/Multiply' incorporates:
           *  Constant: '<S336>/Constant'
           *  RelationalOperator: '<S336>/Compare'
           *  S-Function (sfix_bitop): '<S333>/v_cmd valid'
           */
          rtb_a_l = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S340>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S301>/Multiply' incorporates:
           *  Constant: '<S336>/Constant'
           *  RelationalOperator: '<S336>/Compare'
           *  S-Function (sfix_bitop): '<S333>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_a_l +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
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

        /* End of MultiPortSwitch: '<S301>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S240>/Sum1' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S257>/Switch' incorporates:
         *  Constant: '<S272>/Constant'
         *  Constant: '<S273>/Constant'
         *  Constant: '<S274>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S272>/Compare'
         *  RelationalOperator: '<S273>/Compare'
         *  RelationalOperator: '<S274>/Compare'
         *  S-Function (sfix_bitop): '<S257>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S257>/y_v_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S257>/Logical Operator' incorporates:
           *  Constant: '<S273>/Constant'
           *  Constant: '<S274>/Constant'
           *  RelationalOperator: '<S273>/Compare'
           *  RelationalOperator: '<S274>/Compare'
           *  S-Function (sfix_bitop): '<S257>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S257>/y_v_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S257>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S238>/u_cmd_valid' */
        /* MATLAB Function: '<S269>/bit_shift' incorporates:
         *  DataTypeConversion: '<S238>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_es << 6);

        /* End of Outputs for SubSystem: '<S238>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S238>/v_cmd_valid' */
        /* MATLAB Function: '<S270>/bit_shift' incorporates:
         *  DataTypeConversion: '<S238>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S238>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S258>/Switch' incorporates:
         *  Constant: '<S276>/Constant'
         *  Constant: '<S277>/Constant'
         *  Constant: '<S279>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S276>/Compare'
         *  RelationalOperator: '<S277>/Compare'
         *  RelationalOperator: '<S279>/Compare'
         *  S-Function (sfix_bitop): '<S258>/ax_cmd'
         *  S-Function (sfix_bitop): '<S258>/ay_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S258>/Logical Operator' incorporates:
           *  Constant: '<S277>/Constant'
           *  Constant: '<S279>/Constant'
           *  RelationalOperator: '<S277>/Compare'
           *  RelationalOperator: '<S279>/Compare'
           *  S-Function (sfix_bitop): '<S258>/ax_cmd'
           *  S-Function (sfix_bitop): '<S258>/ay_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S258>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S155>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S155>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S155>/Bus Assignment' incorporates:
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

        /* Saturate: '<S239>/Saturation' */
        if (rtb_Gain_fj > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Gain_fj < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Gain_fj;
        }

        /* End of Saturate: '<S239>/Saturation' */

        /* Saturate: '<S240>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S240>/Saturation2' */

        /* Saturate: '<S240>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S240>/Saturation1' */

        /* Saturate: '<S240>/Saturation3' */
        if (rtb_Add3_c > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S155>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S240>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S238>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S238>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S238>/throttle_cmd_valid' */
        /* BusAssignment: '<S155>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S250>/Constant'
         *  Constant: '<S251>/Constant'
         *  Constant: '<S252>/Constant'
         *  Constant: '<S253>/Constant'
         *  Constant: '<S254>/Constant'
         *  Constant: '<S255>/Constant'
         *  Constant: '<S256>/Constant'
         *  Constant: '<S275>/Constant'
         *  Constant: '<S278>/Constant'
         *  DataTypeConversion: '<S238>/Data Type Conversion10'
         *  DataTypeConversion: '<S238>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S259>/bit_shift'
         *  MATLAB Function: '<S260>/bit_shift'
         *  MATLAB Function: '<S261>/bit_shift'
         *  MATLAB Function: '<S263>/bit_shift'
         *  MATLAB Function: '<S264>/bit_shift'
         *  MATLAB Function: '<S265>/bit_shift'
         *  MATLAB Function: '<S266>/bit_shift'
         *  MATLAB Function: '<S267>/bit_shift'
         *  MATLAB Function: '<S268>/bit_shift'
         *  MATLAB Function: '<S271>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S250>/Compare'
         *  RelationalOperator: '<S251>/Compare'
         *  RelationalOperator: '<S252>/Compare'
         *  RelationalOperator: '<S253>/Compare'
         *  RelationalOperator: '<S254>/Compare'
         *  RelationalOperator: '<S255>/Compare'
         *  RelationalOperator: '<S256>/Compare'
         *  RelationalOperator: '<S275>/Compare'
         *  RelationalOperator: '<S278>/Compare'
         *  S-Function (sfix_bitop): '<S238>/p_cmd'
         *  S-Function (sfix_bitop): '<S238>/phi_cmd'
         *  S-Function (sfix_bitop): '<S238>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S238>/q_cmd'
         *  S-Function (sfix_bitop): '<S238>/r_cmd'
         *  S-Function (sfix_bitop): '<S238>/theta_cmd'
         *  S-Function (sfix_bitop): '<S238>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S257>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S258>/az_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         *  Sum: '<S238>/Add'
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

        /* End of Outputs for SubSystem: '<S238>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S238>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S238>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S35>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S35>/Mission' incorporates:
           *  ActionPort: '<S154>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S35>/Switch Case' incorporates:
           *  UnitDelay: '<S157>/Delay Input1'
           *
           * Block description for '<S157>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S35>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S35>/Mission' incorporates:
           *  ActionPort: '<S154>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S154>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S35>/Switch Case' incorporates:
           *  Chart: '<S196>/Motion Status'
           *  Chart: '<S206>/Motion State'
           *  Delay: '<S162>/Delay'
           *  Delay: '<S184>/Delay'
           *  DiscreteIntegrator: '<S165>/Integrator'
           *  DiscreteIntegrator: '<S165>/Integrator1'
           *  DiscreteIntegrator: '<S180>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S185>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S232>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_ip = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S154>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S35>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S35>/Mission' incorporates:
         *  ActionPort: '<S154>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S157>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S157>/Delay Input1'
         *
         * Block description for '<S157>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S154>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S158>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S205>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S195>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S184>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S180>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S232>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S162>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S165>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S165>/Integrator' */
          FMS_DW.Integrator_DSTATE_ip = 0.0F;

          /* SystemReset for Chart: '<S206>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S196>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* Delay: '<S184>/Delay' incorporates:
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
        /* Switch: '<S180>/Switch2' incorporates:
         *  Constant: '<S180>/vel'
         *  Constant: '<S189>/Constant'
         *  RelationalOperator: '<S189>/Compare'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S180>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* DiscreteIntegrator: '<S185>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S157>/Delay Input1'
         *
         * Block description for '<S157>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S179>/Compare' incorporates:
         *  Constant: '<S236>/Constant'
         *  RelationalOperator: '<S236>/Compare'
         *  UnitDelay: '<S157>/Delay Input1'
         *
         * Block description for '<S157>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S180>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S206>/Motion State' incorporates:
         *  Constant: '<S206>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S206>/Square'
         *  Math: '<S206>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S206>/Sqrt'
         *  Sum: '<S206>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S205>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S205>/Hold Control' incorporates:
             *  ActionPort: '<S208>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S205>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S205>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S205>/Hold Control' incorporates:
           *  ActionPort: '<S208>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S205>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S205>/Brake Control' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S205>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S205>/Move Control' incorporates:
             *  ActionPort: '<S209>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S205>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S205>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S205>/Move Control' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S205>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S205>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S196>/Motion Status' incorporates:
         *  Abs: '<S196>/Abs'
         *  Constant: '<S196>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S195>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S195>/Hold Control' incorporates:
             *  ActionPort: '<S198>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S195>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S195>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S195>/Hold Control' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S195>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S195>/Brake Control' incorporates:
           *  ActionPort: '<S197>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S195>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S195>/Move Control' incorporates:
             *  ActionPort: '<S199>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S195>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S195>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S195>/Move Control' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S195>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S195>/Switch Case' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Product: '<S184>/Multiply'
         *  Sum: '<S184>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S205>/Saturation1' */
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

          /* End of Saturate: '<S205>/Saturation1' */

          /* Saturate: '<S195>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S195>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S184>/Sum' incorporates:
           *  Delay: '<S184>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S233>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S180>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Sum_ff[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S184>/Sum' incorporates:
           *  Delay: '<S184>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* Sum: '<S180>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S192>/Sqrt' incorporates:
           *  Math: '<S192>/Square'
           *  Sum: '<S180>/Sum'
           *  Sum: '<S192>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0
                             + rtb_Add3_c * rtb_Add3_c);

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S235>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S234>/Gain' incorporates:
           *  DiscreteIntegrator: '<S232>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S232>/Add'
           */
          rtb_a_l = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S235>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_a_l);

          /* Gain: '<S235>/Gain' incorporates:
           *  Trigonometry: '<S235>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_a_l);

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S235>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_a_l);

          /* Trigonometry: '<S235>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_a_l);

          /* Switch: '<S191>/Switch2' incorporates:
           *  Constant: '<S180>/Constant2'
           *  DiscreteIntegrator: '<S180>/Acceleration_Speed'
           *  RelationalOperator: '<S191>/LowerRelop1'
           *  RelationalOperator: '<S191>/UpperRelop'
           *  Switch: '<S191>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE > rtb_DiscreteTimeIntegrator_n) {
            rtb_a_l = rtb_DiscreteTimeIntegrator_n;
          } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
            /* Switch: '<S191>/Switch' incorporates:
             *  Constant: '<S180>/Constant2'
             */
            rtb_a_l = 0.0F;
          } else {
            rtb_a_l = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S191>/Switch2' */

          /* Switch: '<S180>/Switch' */
          if (rtb_Add3_c > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
          } else {
            /* Gain: '<S180>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Add3_c;

            /* Switch: '<S190>/Switch2' incorporates:
             *  Constant: '<S180>/Constant1'
             *  RelationalOperator: '<S190>/LowerRelop1'
             *  RelationalOperator: '<S190>/UpperRelop'
             *  Switch: '<S190>/Switch'
             */
            if (rtb_Gain_fj > rtb_DiscreteTimeIntegrator_n) {
              rtb_Gain_fj = rtb_DiscreteTimeIntegrator_n;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S190>/Switch' incorporates:
                 *  Constant: '<S180>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S190>/Switch2' */
          }

          /* End of Switch: '<S180>/Switch' */

          /* Switch: '<S180>/Switch1' incorporates:
           *  Sum: '<S180>/Sum1'
           */
          if (rtb_a_l - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_a_l;
          }

          /* End of Switch: '<S180>/Switch1' */

          /* Sum: '<S233>/Sum of Elements' incorporates:
           *  Math: '<S233>/Math Function'
           */
          rtb_a_l = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_lr_idx_1 *
            rtb_Divide_lr_idx_1;

          /* Math: '<S233>/Math Function1' incorporates:
           *  Sum: '<S233>/Sum of Elements'
           *
           * About '<S233>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_l < 0.0F) {
            rtb_a_l = -sqrtf(fabsf(rtb_a_l));
          } else {
            rtb_a_l = sqrtf(rtb_a_l);
          }

          /* End of Math: '<S233>/Math Function1' */

          /* Switch: '<S233>/Switch' incorporates:
           *  Constant: '<S233>/Constant'
           *  Product: '<S233>/Product'
           */
          if (rtb_a_l > 0.0F) {
            rtb_Add3_c = rtb_Sum_ff[0];
          } else {
            rtb_Add3_c = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_a_l = 1.0F;
          }

          /* End of Switch: '<S233>/Switch' */

          /* Product: '<S231>/Multiply2' incorporates:
           *  Product: '<S233>/Divide'
           */
          rtb_MathFunction_f_idx_0 = rtb_Add3_c / rtb_a_l * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_lr_idx_1 / rtb_a_l;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S186>/Sum1' incorporates:
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_l = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S186>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S186>/Divide' incorporates:
           *  Math: '<S187>/Square'
           *  Math: '<S188>/Square'
           *  Sqrt: '<S187>/Sqrt'
           *  Sqrt: '<S188>/Sqrt'
           *  Sum: '<S186>/Sum'
           *  Sum: '<S186>/Sum1'
           *  Sum: '<S187>/Sum of Elements'
           *  Sum: '<S188>/Sum of Elements'
           */
          rtb_a_l = sqrtf(rtb_Sqrt_b * rtb_Sqrt_b + rtb_Add3_c * rtb_Add3_c) /
            sqrtf(rtb_Rem_p * rtb_Rem_p + rtb_a_l * rtb_a_l);

          /* Saturate: '<S186>/Saturation' */
          if (rtb_a_l > 1.0F) {
            rtb_a_l = 1.0F;
          } else {
            if (rtb_a_l < 0.0F) {
              rtb_a_l = 0.0F;
            }
          }

          /* End of Saturate: '<S186>/Saturation' */

          /* Product: '<S184>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_MathFunction_f_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S177>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S186>/Multiply'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S177>/Sum2'
           *  Sum: '<S186>/Add'
           *  Sum: '<S186>/Subtract'
           */
          rtb_Gain_fj = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_a_l + FMS_B.Cmd_In.cur_waypoint
            [2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S177>/Saturation1' incorporates:
           *  Product: '<S184>/Multiply'
           */
          if (rtb_Gain_fj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Gain_fj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Gain_fj;
          }

          /* End of Saturate: '<S177>/Saturation1' */
        }

        /* End of Switch: '<S160>/Switch' */

        /* Delay: '<S162>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S165>/Integrator1' incorporates:
         *  Delay: '<S162>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S169>/Rem' incorporates:
         *  Constant: '<S169>/Constant1'
         *  DiscreteIntegrator: '<S165>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S164>/Sum'
         */
        rtb_Divide_lr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_p -
          FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S169>/Switch' incorporates:
         *  Abs: '<S169>/Abs'
         *  Constant: '<S169>/Constant'
         *  Constant: '<S170>/Constant'
         *  Product: '<S169>/Multiply'
         *  RelationalOperator: '<S170>/Compare'
         *  Sum: '<S169>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_1) > 3.14159274F) {
          /* Signum: '<S169>/Sign' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_lr_idx_1;
          }

          /* End of Signum: '<S169>/Sign' */
          rtb_Divide_lr_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S169>/Switch' */

        /* Gain: '<S164>/Gain2' */
        rtb_Divide_lr_idx_1 *= FMS_PARAM.YAW_P;

        /* Saturate: '<S164>/Saturation' */
        if (rtb_Divide_lr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Divide_lr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Divide_lr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_lr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S164>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S158>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S158>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S158>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_lr_idx_1;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S226>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S226>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_a_l = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S226>/Math Function1' incorporates:
         *  Sum: '<S226>/Sum of Elements'
         *
         * About '<S226>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_a_l < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_a_l));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_a_l);
        }

        /* End of Math: '<S226>/Math Function1' */

        /* Switch: '<S226>/Switch' incorporates:
         *  Constant: '<S226>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S226>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Divide_lr_idx_1;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S226>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S158>/Sum' incorporates:
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

        /* Sum: '<S176>/Sum of Elements' incorporates:
         *  Math: '<S176>/Math Function'
         *  Sum: '<S158>/Sum'
         */
        rtb_a_l = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0 +
          rtb_Gain_fj * rtb_Gain_fj;

        /* Math: '<S176>/Math Function1' incorporates:
         *  Sum: '<S176>/Sum of Elements'
         *
         * About '<S176>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_a_l < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_a_l));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_a_l);
        }

        /* End of Math: '<S176>/Math Function1' */

        /* Switch: '<S176>/Switch' incorporates:
         *  Constant: '<S176>/Constant'
         *  Product: '<S176>/Product'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_2 = rtb_Divide_lr_idx_1;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_Gain_fj = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S176>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S182>/NearbyRefWP' incorporates:
         *  Constant: '<S158>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_a_l);

        /* MATLAB Function: '<S182>/SearchL1RefWP' incorporates:
         *  Constant: '<S158>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Divide_lr_idx_1 = rtb_Add3_c * rtb_Add3_c + rtb_Divide_lr_idx_1 *
          rtb_Divide_lr_idx_1;

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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Divide_lr_idx_1);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Sqrt_b = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Divide_lr_idx_1);
          rtb_Divide_lr_idx_1 = (-B - u1_tmp) / (2.0F * rtb_Divide_lr_idx_1);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Divide_lr_idx_1 >= 0.0F) &&
              (rtb_Divide_lr_idx_1 <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Divide_lr_idx_1);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Divide_lr_idx_1 >= 0.0F) && (rtb_Divide_lr_idx_1 <= 1.0F))
            {
              rtb_Add3_c = rtb_Divide_lr_idx_1;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Divide_lr_idx_1);
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
        /* MATLAB Function: '<S182>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Divide_lr_idx_1 = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
          * rtb_Rem_p + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0]) *
          rtb_TmpSignalConversionAtMath_0) / (rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_Rem_p * rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_lr_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_lr_idx_1 >= 1.0F);
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
          rtb_P_l_idx_0 = rtb_Divide_lr_idx_1 * rtb_TmpSignalConversionAtMath_0
            + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S182>/Switch1' incorporates:
         *  Constant: '<S219>/Constant'
         *  RelationalOperator: '<S219>/Compare'
         */
        if (rtb_a_l <= 0.0F) {
          /* Switch: '<S182>/Switch' incorporates:
           *  Constant: '<S218>/Constant'
           *  MATLAB Function: '<S182>/SearchL1RefWP'
           *  RelationalOperator: '<S218>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S182>/OutRegionRegWP' incorporates:
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
              rtb_TmpSignalConversionAtDela_a[1] = rtb_Divide_lr_idx_1 *
                rtb_Rem_p + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }
          }

          /* End of Switch: '<S182>/Switch' */
        }

        /* End of Switch: '<S182>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S183>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b * rtb_Sqrt_b;
        rtb_Add3_c = rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S183>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S227>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S227>/Math Function' incorporates:
         *  Math: '<S225>/Square'
         */
        rtb_a_l = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Sum: '<S227>/Sum of Elements' incorporates:
         *  Math: '<S227>/Math Function'
         */
        rtb_Divide_lr_idx_1 = rtb_a_l + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S227>/Math Function1' incorporates:
         *  Sum: '<S227>/Sum of Elements'
         *
         * About '<S227>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S227>/Math Function1' */

        /* Switch: '<S227>/Switch' incorporates:
         *  Constant: '<S227>/Constant'
         *  Product: '<S227>/Product'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Add3_c;
          rtb_MatrixConcatenate3[1] = rtb_Sqrt_b;
          rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S227>/Switch' */

        /* Product: '<S226>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_P_l_idx_0 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S229>/Sum of Elements' incorporates:
         *  Math: '<S229>/Math Function'
         *  SignalConversion: '<S229>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S229>/Math Function1' incorporates:
         *  Sum: '<S229>/Sum of Elements'
         *
         * About '<S229>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S229>/Math Function1' */

        /* Switch: '<S229>/Switch' incorporates:
         *  Constant: '<S229>/Constant'
         *  Product: '<S229>/Product'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_P_l_idx_0;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Divide_lr_idx_1;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S229>/Switch' */

        /* Product: '<S227>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S230>/Sum of Elements' incorporates:
         *  Math: '<S230>/Math Function'
         *  SignalConversion: '<S230>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S230>/Math Function1' incorporates:
         *  Sum: '<S230>/Sum of Elements'
         *
         * About '<S230>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S230>/Math Function1' */

        /* Switch: '<S230>/Switch' incorporates:
         *  Constant: '<S230>/Constant'
         *  Product: '<S230>/Product'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_P_l_idx_0;
          rtb_MatrixConcatenate3[1] = rtb_TmpSignalConversionAtMath_0;
          rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S230>/Switch' */

        /* Product: '<S230>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S229>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S176>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S230>/Divide' incorporates:
         *  Math: '<S225>/Square'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S229>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S176>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S224>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S224>/Square'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S224>/Sum of Elements'
         */
        rtb_Divide_lr_idx_1 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S183>/Gain' incorporates:
         *  Math: '<S183>/Square'
         */
        rtb_Gain_fj = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1 * 2.0F;

        /* Sum: '<S228>/Subtract' incorporates:
         *  Product: '<S228>/Multiply'
         *  Product: '<S228>/Multiply1'
         */
        rtb_Divide_lr_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtDela_a[1] - rtb_P_l_idx_0 *
          rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S223>/Sign1' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S223>/Sign1' */

        /* Switch: '<S223>/Switch2' incorporates:
         *  Constant: '<S223>/Constant4'
         */
        if (rtb_Divide_lr_idx_1 == 0.0F) {
          rtb_Divide_lr_idx_1 = 1.0F;
        }

        /* End of Switch: '<S223>/Switch2' */

        /* DotProduct: '<S223>/Dot Product' */
        rtb_MathFunction_f_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S223>/Acos' incorporates:
         *  DotProduct: '<S223>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_0 > 1.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          }
        }

        /* Product: '<S223>/Multiply' incorporates:
         *  Trigonometry: '<S223>/Acos'
         */
        rtb_Divide_lr_idx_1 *= acosf(rtb_MathFunction_f_idx_0);

        /* Saturate: '<S183>/Saturation' */
        if (rtb_Divide_lr_idx_1 > 1.57079637F) {
          rtb_Divide_lr_idx_1 = 1.57079637F;
        } else {
          if (rtb_Divide_lr_idx_1 < -1.57079637F) {
            rtb_Divide_lr_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S183>/Saturation' */

        /* Product: '<S183>/Divide' incorporates:
         *  Constant: '<S158>/L1'
         *  Constant: '<S183>/Constant'
         *  MinMax: '<S183>/Max'
         *  MinMax: '<S183>/Min'
         *  Product: '<S183>/Multiply1'
         *  Sqrt: '<S225>/Sqrt'
         *  Sum: '<S225>/Sum of Elements'
         *  Trigonometry: '<S183>/Sin'
         */
        rtb_MathFunction_f_idx_2 = arm_sin_f32(rtb_Divide_lr_idx_1) *
          rtb_Gain_fj / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_a_l + rtb_Add3_c),
          0.5F));

        /* Sum: '<S174>/Subtract' incorporates:
         *  Product: '<S174>/Multiply'
         *  Product: '<S174>/Multiply1'
         */
        rtb_Rem_p = rtb_Sqrt_b * FMS_ConstB.Divide[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S163>/Sign1' */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_p = -1.0F;
        } else {
          if (rtb_Rem_p > 0.0F) {
            rtb_Rem_p = 1.0F;
          }
        }

        /* End of Signum: '<S163>/Sign1' */

        /* Switch: '<S163>/Switch2' incorporates:
         *  Constant: '<S163>/Constant4'
         */
        if (rtb_Rem_p == 0.0F) {
          rtb_Rem_p = 1.0F;
        }

        /* End of Switch: '<S163>/Switch2' */

        /* DotProduct: '<S163>/Dot Product' */
        rtb_Gain_fj = FMS_ConstB.Divide[0] * rtb_Sqrt_b + FMS_ConstB.Divide[1] *
          rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S163>/Acos' incorporates:
         *  DotProduct: '<S163>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S163>/Multiply' incorporates:
         *  Trigonometry: '<S163>/Acos'
         */
        rtb_Rem_p *= acosf(rtb_Gain_fj);

        /* Math: '<S166>/Rem' incorporates:
         *  Constant: '<S166>/Constant1'
         *  Delay: '<S162>/Delay'
         *  Sum: '<S162>/Sum2'
         */
        rtb_Divide_lr_idx_1 = rt_remf(rtb_Rem_p - FMS_DW.Delay_DSTATE_h,
          6.28318548F);

        /* Switch: '<S166>/Switch' incorporates:
         *  Abs: '<S166>/Abs'
         *  Constant: '<S166>/Constant'
         *  Constant: '<S172>/Constant'
         *  Product: '<S166>/Multiply'
         *  RelationalOperator: '<S172>/Compare'
         *  Sum: '<S166>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_1) > 3.14159274F) {
          /* Signum: '<S166>/Sign' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_lr_idx_1;
          }

          /* End of Signum: '<S166>/Sign' */
          rtb_Divide_lr_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S166>/Switch' */

        /* Sum: '<S162>/Sum' incorporates:
         *  Delay: '<S162>/Delay'
         */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S171>/Multiply1' incorporates:
         *  Constant: '<S171>/const1'
         *  DiscreteIntegrator: '<S165>/Integrator'
         */
        rtb_Divide_lr_idx_1 = FMS_DW.Integrator_DSTATE_ip * 0.785398185F;

        /* Sum: '<S171>/Add' incorporates:
         *  DiscreteIntegrator: '<S165>/Integrator1'
         *  Sum: '<S165>/Subtract'
         */
        rtb_MathFunction_f_idx_0 = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) +
          rtb_Divide_lr_idx_1;

        /* Signum: '<S171>/Sign' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_MathFunction_f_idx_0;
        }

        /* End of Signum: '<S171>/Sign' */

        /* Sum: '<S171>/Add2' incorporates:
         *  Abs: '<S171>/Abs'
         *  Gain: '<S171>/Gain'
         *  Gain: '<S171>/Gain1'
         *  Product: '<S171>/Multiply2'
         *  Product: '<S171>/Multiply3'
         *  Sqrt: '<S171>/Sqrt'
         *  Sum: '<S171>/Add1'
         *  Sum: '<S171>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_0) +
                          FMS_ConstB.d_j) * FMS_ConstB.d_j) - FMS_ConstB.d_j) *
          0.5F * rtb_Add3_c + rtb_Divide_lr_idx_1;

        /* Sum: '<S171>/Add4' */
        rtb_Divide_lr_idx_1 += rtb_MathFunction_f_idx_0 - rtb_a_l;

        /* Sum: '<S171>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + FMS_ConstB.d_j;

        /* Sum: '<S171>/Subtract1' */
        rtb_MathFunction_f_idx_0 -= FMS_ConstB.d_j;

        /* Signum: '<S171>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S171>/Sign1' */

        /* Signum: '<S171>/Sign2' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S171>/Sign2' */

        /* Sum: '<S171>/Add5' incorporates:
         *  Gain: '<S171>/Gain2'
         *  Product: '<S171>/Multiply4'
         *  Sum: '<S171>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_MathFunction_f_idx_0) * 0.5F *
          rtb_Divide_lr_idx_1;

        /* Sum: '<S171>/Add6' */
        rtb_Add3_c = rtb_a_l + FMS_ConstB.d_j;

        /* Sum: '<S171>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_a_l - FMS_ConstB.d_j;

        /* Product: '<S171>/Divide' */
        rtb_Sqrt_b = rtb_a_l / FMS_ConstB.d_j;

        /* Signum: '<S171>/Sign5' incorporates:
         *  Signum: '<S171>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S171>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S171>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_a_l;

          /* Signum: '<S171>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_a_l;
        }

        /* End of Signum: '<S171>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S162>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_p -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S167>/Rem' incorporates:
         *  Constant: '<S167>/Constant1'
         */
        rtb_a_l = rt_remf(rtb_Rem_p, 6.28318548F);

        /* Switch: '<S167>/Switch' incorporates:
         *  Abs: '<S167>/Abs'
         *  Constant: '<S167>/Constant'
         *  Constant: '<S173>/Constant'
         *  Product: '<S167>/Multiply'
         *  RelationalOperator: '<S173>/Compare'
         *  Sum: '<S167>/Add'
         */
        if (fabsf(rtb_a_l) > 3.14159274F) {
          /* Signum: '<S167>/Sign' */
          if (rtb_a_l < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else if (rtb_a_l > 0.0F) {
            rtb_Gain_fj = 1.0F;
          } else {
            rtb_Gain_fj = rtb_a_l;
          }

          /* End of Signum: '<S167>/Sign' */
          rtb_a_l -= 6.28318548F * rtb_Gain_fj;
        }

        /* End of Switch: '<S167>/Switch' */

        /* Abs: '<S160>/Abs' */
        rtb_a_l = fabsf(rtb_a_l);

        /* Update for Delay: '<S184>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S178>/Constant'
         *  RelationalOperator: '<S178>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(rtb_a_l <=
          0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S180>/Acceleration_Speed' incorporates:
         *  Constant: '<S180>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Product: '<S184>/Divide1' */
        rtb_Gain_fj = rtb_MathFunction_f_idx_2 / rtb_DiscreteTimeIntegrator_n;

        /* Saturate: '<S184>/Saturation' */
        if (rtb_Gain_fj > 0.314159274F) {
          rtb_Gain_fj = 0.314159274F;
        } else {
          if (rtb_Gain_fj < -0.314159274F) {
            rtb_Gain_fj = -0.314159274F;
          }
        }

        /* End of Saturate: '<S184>/Saturation' */

        /* Update for DiscreteIntegrator: '<S232>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Gain_fj;

        /* Update for Delay: '<S162>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S165>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S165>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_ip;

        /* Signum: '<S171>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S171>/Sign3' */

        /* Signum: '<S171>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S171>/Sign4' */

        /* Update for DiscreteIntegrator: '<S165>/Integrator' incorporates:
         *  Constant: '<S171>/const'
         *  Gain: '<S171>/Gain3'
         *  Product: '<S171>/Multiply5'
         *  Product: '<S171>/Multiply6'
         *  Sum: '<S171>/Subtract4'
         *  Sum: '<S171>/Subtract5'
         *  Sum: '<S171>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_ip += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1)
          * FMS_ConstB.Gain4_c5 * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_ip >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_ip = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_ip <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_ip = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S165>/Integrator' */
        /* End of Outputs for SubSystem: '<S154>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Update for UnitDelay: '<S157>/Delay Input1' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S157>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S35>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S35>/Unknown' incorporates:
         *  ActionPort: '<S156>/Action Port'
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
          /* Disable for SwitchCase: '<S141>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S49>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S70>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S111>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S98>/Switch Case' */
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
          rtb_a_l = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_a_l = 0.0F;
        } else {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
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
          rtb_a_l), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S34>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Stabilize' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S135>/Integrator'
           *  DiscreteIntegrator: '<S135>/Integrator1'
           *  DiscreteIntegrator: '<S136>/Integrator'
           *  DiscreteIntegrator: '<S136>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_l = 0.0F;
          FMS_DW.Integrator_DSTATE_cm = 0.0F;
          FMS_DW.Integrator1_DSTATE_h = 0.0F;
          FMS_DW.Integrator_DSTATE_a = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S34>/Stabilize' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S142>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S34>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Stabilize' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S133>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_a_l = 0.0F;
        } else {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S133>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S133>/Gain' */
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_a_l;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S134>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_a_l = 0.0F;
        } else {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S134>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S134>/Gain' */
        rtb_DiscreteTimeIntegrator_n = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_a_l;

        /* Sum: '<S137>/Sum of Elements' incorporates:
         *  Math: '<S137>/Square'
         *  SignalConversion: '<S137>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S138>/Sum of Elements'
         *  Switch: '<S129>/Switch'
         */
        rtb_a_l = rtb_Add3_c * rtb_Add3_c + rtb_DiscreteTimeIntegrator_n *
          rtb_DiscreteTimeIntegrator_n;

        /* Switch: '<S129>/Switch' incorporates:
         *  Constant: '<S132>/Constant'
         *  Product: '<S138>/Divide'
         *  RelationalOperator: '<S132>/Compare'
         *  Sqrt: '<S137>/Sqrt'
         *  Sum: '<S137>/Sum of Elements'
         */
        if (sqrtf(rtb_a_l) > 1.0F) {
          /* Math: '<S138>/Math Function1'
           *
           * About '<S138>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_l < 0.0F) {
            rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_a_l));
          } else {
            rtb_Divide_lr_idx_1 = sqrtf(rtb_a_l);
          }

          /* End of Math: '<S138>/Math Function1' */

          /* Switch: '<S138>/Switch' incorporates:
           *  Constant: '<S138>/Constant'
           *  Product: '<S138>/Product'
           */
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_DiscreteTimeIntegrator_n;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S138>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_DiscreteTimeIntegrator_n = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];
        }

        /* Product: '<S139>/Multiply1' incorporates:
         *  Constant: '<S139>/const1'
         *  DiscreteIntegrator: '<S135>/Integrator'
         */
        rtb_Divide_lr_idx_1 = FMS_DW.Integrator_DSTATE_cm * 0.04F;

        /* Sum: '<S139>/Add' incorporates:
         *  DiscreteIntegrator: '<S135>/Integrator1'
         *  Gain: '<S129>/Gain'
         *  Sum: '<S135>/Subtract'
         */
        rtb_a_l = (FMS_DW.Integrator1_DSTATE_l - FMS_PARAM.ROLL_PITCH_LIM *
                   rtb_Add3_c) + rtb_Divide_lr_idx_1;

        /* Signum: '<S139>/Sign' */
        if (rtb_a_l < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_a_l;
        }

        /* End of Signum: '<S139>/Sign' */

        /* Sum: '<S139>/Add2' incorporates:
         *  Abs: '<S139>/Abs'
         *  Gain: '<S139>/Gain'
         *  Gain: '<S139>/Gain1'
         *  Product: '<S139>/Multiply2'
         *  Product: '<S139>/Multiply3'
         *  Sqrt: '<S139>/Sqrt'
         *  Sum: '<S139>/Add1'
         *  Sum: '<S139>/Subtract'
         */
        rtb_Gain_fj = (sqrtf((8.0F * fabsf(rtb_a_l) + FMS_ConstB.d_h) *
                             FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F *
          rtb_Add3_c + rtb_Divide_lr_idx_1;

        /* Sum: '<S139>/Add4' */
        rtb_Divide_lr_idx_1 += rtb_a_l - rtb_Gain_fj;

        /* Sum: '<S139>/Add3' */
        rtb_Add3_c = rtb_a_l + FMS_ConstB.d_h;

        /* Sum: '<S139>/Subtract1' */
        rtb_a_l -= FMS_ConstB.d_h;

        /* Signum: '<S139>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign1' */

        /* Signum: '<S139>/Sign2' */
        if (rtb_a_l < 0.0F) {
          rtb_a_l = -1.0F;
        } else {
          if (rtb_a_l > 0.0F) {
            rtb_a_l = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign2' */

        /* Sum: '<S139>/Add5' incorporates:
         *  Gain: '<S139>/Gain2'
         *  Product: '<S139>/Multiply4'
         *  Sum: '<S139>/Subtract2'
         */
        rtb_Gain_fj += (rtb_Add3_c - rtb_a_l) * 0.5F * rtb_Divide_lr_idx_1;

        /* Sum: '<S139>/Add6' */
        rtb_Add3_c = rtb_Gain_fj + FMS_ConstB.d_h;

        /* Sum: '<S139>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Gain_fj - FMS_ConstB.d_h;

        /* Product: '<S139>/Divide' */
        rtb_Sqrt_b = rtb_Gain_fj / FMS_ConstB.d_h;

        /* Signum: '<S139>/Sign5' incorporates:
         *  Signum: '<S139>/Sign6'
         */
        if (rtb_Gain_fj < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S139>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S139>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Gain_fj;

          /* Signum: '<S139>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_Gain_fj;
        }

        /* End of Signum: '<S139>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Logic: '<S129>/Logical Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* Chart: '<S142>/Motion State' incorporates:
         *  Abs: '<S142>/Abs'
         *  Abs: '<S142>/Abs1'
         *  Constant: '<S152>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S152>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S141>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S141>/Hold Control' incorporates:
             *  ActionPort: '<S144>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S141>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S141>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S141>/Hold Control' incorporates:
           *  ActionPort: '<S144>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S141>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S141>/Brake Control' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S141>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S141>/Move Control' incorporates:
             *  ActionPort: '<S145>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S141>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S141>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S141>/Move Control' incorporates:
           *  ActionPort: '<S145>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S141>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S141>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S131>/Switch' incorporates:
         *  Constant: '<S131>/Constant'
         *  Constant: '<S131>/Constant4'
         *  Constant: '<S131>/Constant5'
         *  Gain: '<S131>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Saturate: '<S131>/Saturation'
         *  SignalConversion: '<S29>/Signal Copy2'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         *  Sum: '<S131>/Add'
         *  Sum: '<S131>/Sum'
         */
        if (FMS_B.Compare) {
          rtb_y_md = FMS_PARAM.LAND_LOCK_THRO;
        } else {
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            /* Saturate: '<S131>/Saturation' */
            rtb_a_l = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S131>/Saturation' */
            rtb_a_l = 0.0F;
          } else {
            /* Saturate: '<S131>/Saturation' incorporates:
             *  Constant: '<S131>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S29>/Signal Copy2'
             *  Sum: '<S131>/Sum'
             */
            rtb_a_l = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_a_l),
            65536.0F) + 1000U);
        }

        /* End of Switch: '<S131>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S42>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DataTypeConversion: '<S129>/Data Type Conversion'
         *  DiscreteIntegrator: '<S135>/Integrator1'
         *  DiscreteIntegrator: '<S136>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S129>/Multiply'
         *  Product: '<S129>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_l;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_h;

        /* Saturate: '<S141>/Saturation' */
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

        /* End of Saturate: '<S141>/Saturation' */

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.throttle_cmd = rtb_y_md;

        /* Product: '<S140>/Multiply1' incorporates:
         *  Constant: '<S140>/const1'
         *  DiscreteIntegrator: '<S136>/Integrator'
         */
        rtb_MathFunction_f_idx_2 = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S140>/Add' incorporates:
         *  DiscreteIntegrator: '<S136>/Integrator1'
         *  Gain: '<S129>/Gain1'
         *  Sum: '<S136>/Subtract'
         */
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_h - -FMS_PARAM.ROLL_PITCH_LIM *
                       rtb_DiscreteTimeIntegrator_n) + rtb_MathFunction_f_idx_2;

        /* Signum: '<S140>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Gain_fj;
        }

        /* End of Signum: '<S140>/Sign' */

        /* Sum: '<S140>/Add2' incorporates:
         *  Abs: '<S140>/Abs'
         *  Gain: '<S140>/Gain'
         *  Gain: '<S140>/Gain1'
         *  Product: '<S140>/Multiply2'
         *  Product: '<S140>/Multiply3'
         *  Sqrt: '<S140>/Sqrt'
         *  Sum: '<S140>/Add1'
         *  Sum: '<S140>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Gain_fj) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_MathFunction_f_idx_2;

        /* Sum: '<S140>/Add4' */
        rtb_MathFunction_f_idx_2 += rtb_Gain_fj - rtb_a_l;

        /* Sum: '<S140>/Add3' */
        rtb_DiscreteTimeIntegrator_n = rtb_Gain_fj + FMS_ConstB.d_l;

        /* Sum: '<S140>/Subtract1' */
        rtb_Gain_fj -= FMS_ConstB.d_l;

        /* Signum: '<S140>/Sign1' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else {
          if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }
        }

        /* End of Signum: '<S140>/Sign1' */

        /* Signum: '<S140>/Sign2' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S140>/Sign2' */

        /* Sum: '<S140>/Add5' incorporates:
         *  Gain: '<S140>/Gain2'
         *  Product: '<S140>/Multiply4'
         *  Sum: '<S140>/Subtract2'
         */
        rtb_a_l += (rtb_DiscreteTimeIntegrator_n - rtb_Gain_fj) * 0.5F *
          rtb_MathFunction_f_idx_2;

        /* Update for DiscreteIntegrator: '<S135>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S135>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_cm;

        /* Signum: '<S139>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign3' */

        /* Signum: '<S139>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign4' */

        /* Update for DiscreteIntegrator: '<S135>/Integrator' incorporates:
         *  Constant: '<S139>/const'
         *  Gain: '<S139>/Gain3'
         *  Product: '<S139>/Multiply5'
         *  Product: '<S139>/Multiply6'
         *  Sum: '<S139>/Subtract4'
         *  Sum: '<S139>/Subtract5'
         *  Sum: '<S139>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cm += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1)
          * FMS_ConstB.Gain4_nf * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S136>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S136>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Sum: '<S140>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_l;

        /* Sum: '<S140>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_a_l + FMS_ConstB.d_l;

        /* Signum: '<S140>/Sign5' incorporates:
         *  Signum: '<S140>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S140>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S140>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_a_l;

          /* Signum: '<S140>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = rtb_a_l;
        }

        /* End of Signum: '<S140>/Sign5' */

        /* Signum: '<S140>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S140>/Sign3' */

        /* Signum: '<S140>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S140>/Sign4' */

        /* Update for DiscreteIntegrator: '<S136>/Integrator' incorporates:
         *  Constant: '<S140>/const'
         *  Gain: '<S140>/Gain3'
         *  Product: '<S140>/Divide'
         *  Product: '<S140>/Multiply5'
         *  Product: '<S140>/Multiply6'
         *  Sum: '<S140>/Subtract4'
         *  Sum: '<S140>/Subtract5'
         *  Sum: '<S140>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += ((rtb_a_l / FMS_ConstB.d_l -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4_j * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_DiscreteTimeIntegrator_n * 12.566371F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S34>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Altitude' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S64>/Integrator'
           *  DiscreteIntegrator: '<S64>/Integrator1'
           *  DiscreteIntegrator: '<S65>/Integrator'
           *  DiscreteIntegrator: '<S65>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_g = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_e = 0.0F;
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S34>/Altitude' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S50>/Motion Status'
           *  Chart: '<S71>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S34>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Altitude' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S62>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_a_l = 0.0F;
        } else {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S62>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S62>/Gain' */
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_a_l;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S63>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_a_l = 0.0F;
        } else {
          rtb_a_l = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S63>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S63>/Gain' */
        rtb_DiscreteTimeIntegrator_n = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_a_l;

        /* Sum: '<S66>/Sum of Elements' incorporates:
         *  Math: '<S66>/Square'
         *  SignalConversion: '<S66>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S67>/Sum of Elements'
         *  Switch: '<S47>/Switch'
         */
        rtb_a_l = rtb_Add3_c * rtb_Add3_c + rtb_DiscreteTimeIntegrator_n *
          rtb_DiscreteTimeIntegrator_n;

        /* Switch: '<S47>/Switch' incorporates:
         *  Constant: '<S61>/Constant'
         *  Product: '<S67>/Divide'
         *  RelationalOperator: '<S61>/Compare'
         *  Sqrt: '<S66>/Sqrt'
         *  Sum: '<S66>/Sum of Elements'
         */
        if (sqrtf(rtb_a_l) > 1.0F) {
          /* Math: '<S67>/Math Function1'
           *
           * About '<S67>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_l < 0.0F) {
            rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_a_l));
          } else {
            rtb_Divide_lr_idx_1 = sqrtf(rtb_a_l);
          }

          /* End of Math: '<S67>/Math Function1' */

          /* Switch: '<S67>/Switch' incorporates:
           *  Constant: '<S67>/Constant'
           *  Product: '<S67>/Product'
           */
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_DiscreteTimeIntegrator_n;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S67>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_DiscreteTimeIntegrator_n = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];
        }

        /* Product: '<S68>/Multiply1' incorporates:
         *  Constant: '<S68>/const1'
         *  DiscreteIntegrator: '<S64>/Integrator'
         */
        rtb_MathFunction_f_idx_2 = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S68>/Add' incorporates:
         *  DiscreteIntegrator: '<S64>/Integrator1'
         *  Gain: '<S47>/Gain'
         *  Sum: '<S64>/Subtract'
         */
        rtb_a_l = (FMS_DW.Integrator1_DSTATE_g - FMS_PARAM.ROLL_PITCH_LIM *
                   rtb_Add3_c) + rtb_MathFunction_f_idx_2;

        /* Signum: '<S68>/Sign' */
        if (rtb_a_l < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_a_l;
        }

        /* End of Signum: '<S68>/Sign' */

        /* Sum: '<S68>/Add2' incorporates:
         *  Abs: '<S68>/Abs'
         *  Gain: '<S68>/Gain'
         *  Gain: '<S68>/Gain1'
         *  Product: '<S68>/Multiply2'
         *  Product: '<S68>/Multiply3'
         *  Sqrt: '<S68>/Sqrt'
         *  Sum: '<S68>/Add1'
         *  Sum: '<S68>/Subtract'
         */
        rtb_Gain_fj = (sqrtf((8.0F * fabsf(rtb_a_l) + FMS_ConstB.d_i) *
                             FMS_ConstB.d_i) - FMS_ConstB.d_i) * 0.5F *
          rtb_Add3_c + rtb_MathFunction_f_idx_2;

        /* Sum: '<S68>/Add4' */
        rtb_Divide_lr_idx_1 = (rtb_a_l - rtb_Gain_fj) + rtb_MathFunction_f_idx_2;

        /* Sum: '<S68>/Add3' */
        rtb_Add3_c = rtb_a_l + FMS_ConstB.d_i;

        /* Sum: '<S68>/Subtract1' */
        rtb_a_l -= FMS_ConstB.d_i;

        /* Signum: '<S68>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S68>/Sign1' */

        /* Signum: '<S68>/Sign2' */
        if (rtb_a_l < 0.0F) {
          rtb_a_l = -1.0F;
        } else {
          if (rtb_a_l > 0.0F) {
            rtb_a_l = 1.0F;
          }
        }

        /* End of Signum: '<S68>/Sign2' */

        /* Sum: '<S68>/Add5' incorporates:
         *  Gain: '<S68>/Gain2'
         *  Product: '<S68>/Multiply4'
         *  Sum: '<S68>/Subtract2'
         */
        rtb_Gain_fj += (rtb_Add3_c - rtb_a_l) * 0.5F * rtb_Divide_lr_idx_1;

        /* Sum: '<S68>/Add6' */
        rtb_Add3_c = rtb_Gain_fj + FMS_ConstB.d_i;

        /* Sum: '<S68>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Gain_fj - FMS_ConstB.d_i;

        /* Product: '<S68>/Divide' */
        rtb_Sqrt_b = rtb_Gain_fj / FMS_ConstB.d_i;

        /* Signum: '<S68>/Sign5' incorporates:
         *  Signum: '<S68>/Sign6'
         */
        if (rtb_Gain_fj < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S68>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S68>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Gain_fj;

          /* Signum: '<S68>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_Gain_fj;
        }

        /* End of Signum: '<S68>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Logic: '<S47>/Logical Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

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
          rtb_MathFunction_f_idx_2 = 0.5F;
        } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S49>/Saturation1' */
          rtb_MathFunction_f_idx_2 = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S49>/Saturation1' */
          rtb_MathFunction_f_idx_2 = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S49>/Saturation1' */
          rtb_MathFunction_f_idx_2 = FMS_B.Merge_l;
        }

        /* End of Switch: '<S46>/Switch' */

        /* Chart: '<S71>/Motion State' incorporates:
         *  Abs: '<S71>/Abs'
         *  Abs: '<S71>/Abs1'
         *  Constant: '<S81>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S81>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S70>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S70>/Hold Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S70>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S70>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S70>/Hold Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                            &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S70>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S70>/Brake Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S70>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S70>/Move Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S70>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S70>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S70>/Move Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S70>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S70>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S40>/Bus Assignment'
         *  Constant: '<S40>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DataTypeConversion: '<S47>/Data Type Conversion'
         *  DiscreteIntegrator: '<S64>/Integrator1'
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S47>/Multiply'
         *  Product: '<S47>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_g;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_e;

        /* Saturate: '<S70>/Saturation' */
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

        /* End of Saturate: '<S70>/Saturation' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_f_idx_2;

        /* Product: '<S69>/Multiply1' incorporates:
         *  Constant: '<S69>/const1'
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        rtb_MathFunction_f_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

        /* Sum: '<S69>/Add' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  Gain: '<S47>/Gain1'
         *  Sum: '<S65>/Subtract'
         */
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_e - -FMS_PARAM.ROLL_PITCH_LIM *
                       rtb_DiscreteTimeIntegrator_n) + rtb_MathFunction_f_idx_2;

        /* Signum: '<S69>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_Gain_fj;
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
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Gain_fj) + FMS_ConstB.d_o) *
                         FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_MathFunction_f_idx_2;

        /* Sum: '<S69>/Add4' */
        rtb_MathFunction_f_idx_2 += rtb_Gain_fj - rtb_a_l;

        /* Sum: '<S69>/Add3' */
        rtb_DiscreteTimeIntegrator_n = rtb_Gain_fj + FMS_ConstB.d_o;

        /* Sum: '<S69>/Subtract1' */
        rtb_Gain_fj -= FMS_ConstB.d_o;

        /* Signum: '<S69>/Sign1' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else {
          if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign1' */

        /* Signum: '<S69>/Sign2' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign2' */

        /* Sum: '<S69>/Add5' incorporates:
         *  Gain: '<S69>/Gain2'
         *  Product: '<S69>/Multiply4'
         *  Sum: '<S69>/Subtract2'
         */
        rtb_a_l += (rtb_DiscreteTimeIntegrator_n - rtb_Gain_fj) * 0.5F *
          rtb_MathFunction_f_idx_2;

        /* Update for DiscreteIntegrator: '<S64>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S64>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Signum: '<S68>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S68>/Sign3' */

        /* Signum: '<S68>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S68>/Sign4' */

        /* Update for DiscreteIntegrator: '<S64>/Integrator' incorporates:
         *  Constant: '<S68>/const'
         *  Gain: '<S68>/Gain3'
         *  Product: '<S68>/Multiply5'
         *  Product: '<S68>/Multiply6'
         *  Sum: '<S68>/Subtract4'
         *  Sum: '<S68>/Subtract5'
         *  Sum: '<S68>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1) *
          FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S69>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_o;

        /* Sum: '<S69>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_a_l + FMS_ConstB.d_o;

        /* Signum: '<S69>/Sign5' incorporates:
         *  Signum: '<S69>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S69>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S69>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_a_l;

          /* Signum: '<S69>/Sign6' */
          rtb_DiscreteTimeIntegrator_n = rtb_a_l;
        }

        /* End of Signum: '<S69>/Sign5' */

        /* Signum: '<S69>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign3' */

        /* Signum: '<S69>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign4' */

        /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
         *  Constant: '<S69>/const'
         *  Gain: '<S69>/Gain3'
         *  Product: '<S69>/Divide'
         *  Product: '<S69>/Multiply5'
         *  Product: '<S69>/Multiply6'
         *  Sum: '<S69>/Subtract4'
         *  Sum: '<S69>/Subtract5'
         *  Sum: '<S69>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_a_l / FMS_ConstB.d_o -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4_c * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_DiscreteTimeIntegrator_n * 12.566371F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S34>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S34>/Position' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S112>/Motion State'
           *  Chart: '<S87>/Motion Status'
           *  Chart: '<S99>/Motion State'
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
        /* Chart: '<S87>/Motion Status' incorporates:
         *  Abs: '<S87>/Abs'
         *  Abs: '<S87>/Abs1'
         *  Constant: '<S96>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S96>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_i);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S86>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S86>/Hold Control' incorporates:
             *  ActionPort: '<S89>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S86>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S86>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Hold Control' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S86>/Brake Control' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S86>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S86>/Move Control' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S86>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S99>/Motion State' incorporates:
         *  Abs: '<S99>/Abs'
         *  Abs: '<S99>/Abs1'
         *  Constant: '<S109>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S109>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S112>/Logical Operator' incorporates:
         *  Abs: '<S112>/Abs1'
         *  Abs: '<S112>/Abs2'
         *  Constant: '<S126>/Constant'
         *  Constant: '<S127>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S126>/Compare'
         *  RelationalOperator: '<S127>/Compare'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S112>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S112>/Square'
         *  Math: '<S112>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S112>/Sqrt'
         *  Sum: '<S112>/Add'
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

        /* End of Chart: '<S112>/Motion State' */

        /* SwitchCase: '<S111>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
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
            /* SystemReset for IfAction SubSystem: '<S111>/Hold Control' incorporates:
             *  ActionPort: '<S114>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S111>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S111>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S111>/Hold Control' incorporates:
           *  ActionPort: '<S114>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S111>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S111>/Brake Control' incorporates:
           *  ActionPort: '<S113>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S111>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S111>/Move Control' incorporates:
             *  ActionPort: '<S115>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S111>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S122>/Integrator'
             *  DiscreteIntegrator: '<S122>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE[0] = 0.0F;
            FMS_DW.Integrator_DSTATE[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE[1] = 0.0F;
            FMS_DW.Integrator_DSTATE[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S111>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S111>/Move Control' incorporates:
           *  ActionPort: '<S115>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S120>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S29>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_a_l = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_a_l = 0.0F;
          } else {
            rtb_a_l = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S120>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S120>/Gain' */
          rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_a_l;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S121>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S29>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_a_l = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_a_l = 0.0F;
          } else {
            rtb_a_l = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S121>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S121>/Gain' */
          rtb_DiscreteTimeIntegrator_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
            rtb_a_l;

          /* Sum: '<S123>/Sum of Elements' incorporates:
           *  Math: '<S123>/Square'
           *  SignalConversion: '<S123>/TmpSignal ConversionAtSquareInport1'
           *  Sum: '<S124>/Sum of Elements'
           *  Switch: '<S115>/Switch'
           */
          rtb_a_l = rtb_Add3_c * rtb_Add3_c + rtb_DiscreteTimeIntegrator_n *
            rtb_DiscreteTimeIntegrator_n;

          /* Switch: '<S115>/Switch' incorporates:
           *  Constant: '<S119>/Constant'
           *  Product: '<S124>/Divide'
           *  RelationalOperator: '<S119>/Compare'
           *  Sqrt: '<S123>/Sqrt'
           *  Sum: '<S123>/Sum of Elements'
           */
          if (sqrtf(rtb_a_l) > 1.0F) {
            /* Math: '<S124>/Math Function1'
             *
             * About '<S124>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_l < 0.0F) {
              rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_a_l));
            } else {
              rtb_Divide_lr_idx_1 = sqrtf(rtb_a_l);
            }

            /* End of Math: '<S124>/Math Function1' */

            /* Switch: '<S124>/Switch' incorporates:
             *  Constant: '<S124>/Constant'
             *  Product: '<S124>/Product'
             */
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_MatrixConcatenate3[0] = rtb_Add3_c;
              rtb_MatrixConcatenate3[1] = rtb_DiscreteTimeIntegrator_n;
              rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
            } else {
              rtb_MatrixConcatenate3[0] = 0.0F;
              rtb_MatrixConcatenate3[1] = 0.0F;
              rtb_MatrixConcatenate3[2] = 1.0F;
            }

            /* End of Switch: '<S124>/Switch' */
            rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
            rtb_DiscreteTimeIntegrator_n = rtb_MatrixConcatenate3[1] /
              rtb_MatrixConcatenate3[2];
          }

          /* Product: '<S125>/Multiply1' incorporates:
           *  Constant: '<S125>/const1'
           *  DiscreteIntegrator: '<S122>/Integrator'
           */
          rtb_MathFunction_f_idx_0 = FMS_DW.Integrator_DSTATE[0] * 0.05F;

          /* Sum: '<S125>/Add' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator1'
           *  Gain: '<S115>/Gain6'
           *  Sum: '<S122>/Subtract'
           */
          rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM *
                        rtb_Add3_c) + rtb_MathFunction_f_idx_0;

          /* Signum: '<S125>/Sign' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Sqrt_b > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Sqrt_b;
          }

          /* Sum: '<S125>/Add2' incorporates:
           *  Abs: '<S125>/Abs'
           *  Gain: '<S125>/Gain'
           *  Gain: '<S125>/Gain1'
           *  Product: '<S125>/Multiply2'
           *  Product: '<S125>/Multiply3'
           *  Sqrt: '<S125>/Sqrt'
           *  Sum: '<S125>/Add1'
           *  Sum: '<S125>/Subtract'
           */
          rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) + FMS_ConstB.d) *
                             FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c +
            rtb_MathFunction_f_idx_0;

          /* Sum: '<S125>/Add4' */
          rtb_MathFunction_f_idx_0 += rtb_Sqrt_b - rtb_Rem_p;

          /* Sum: '<S125>/Add3' */
          rtb_Add3_c = rtb_Sqrt_b + FMS_ConstB.d;

          /* Sum: '<S125>/Subtract1' */
          rtb_Sqrt_b -= FMS_ConstB.d;

          /* Signum: '<S125>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S125>/Sign2' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Sum: '<S125>/Add5' incorporates:
           *  Gain: '<S125>/Gain2'
           *  Product: '<S125>/Multiply4'
           *  Sum: '<S125>/Subtract2'
           */
          rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F *
            rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S115>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator1'
           */
          FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

          /* Update for DiscreteIntegrator: '<S122>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

          /* Signum: '<S125>/Sign4' incorporates:
           *  Sum: '<S125>/Subtract3'
           */
          rtb_Add3_c = rtb_Rem_p - FMS_ConstB.d;

          /* Signum: '<S125>/Sign3' incorporates:
           *  Sum: '<S125>/Add6'
           */
          rtb_Divide_lr_idx_1 = rtb_Rem_p + FMS_ConstB.d;

          /* Signum: '<S125>/Sign5' */
          if (rtb_Rem_p < 0.0F) {
            rtb_a_l = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_a_l = 1.0F;
          } else {
            rtb_a_l = rtb_Rem_p;
          }

          /* Signum: '<S125>/Sign3' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_1 = 1.0F;
            }
          }

          /* Signum: '<S125>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S125>/Sign6' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_Rem_p;
          }

          /* Update for DiscreteIntegrator: '<S122>/Integrator' incorporates:
           *  Constant: '<S125>/const'
           *  Gain: '<S125>/Gain3'
           *  Product: '<S125>/Divide'
           *  Product: '<S125>/Multiply5'
           *  Product: '<S125>/Multiply6'
           *  Sum: '<S125>/Subtract4'
           *  Sum: '<S125>/Subtract5'
           *  Sum: '<S125>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE[0] += ((rtb_Rem_p / FMS_ConstB.d - rtb_a_l) *
            FMS_ConstB.Gain4 * ((rtb_Divide_lr_idx_1 - rtb_Add3_c) * 0.5F) -
            rtb_Sqrt_b * 58.836F) * 0.004F;

          /* Product: '<S125>/Multiply1' incorporates:
           *  Constant: '<S125>/const1'
           *  DiscreteIntegrator: '<S122>/Integrator'
           */
          rtb_MathFunction_f_idx_0 = FMS_DW.Integrator_DSTATE[1] * 0.05F;

          /* Sum: '<S125>/Add' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator1'
           *  Gain: '<S115>/Gain6'
           *  Sum: '<S122>/Subtract'
           */
          rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                        rtb_DiscreteTimeIntegrator_n) + rtb_MathFunction_f_idx_0;

          /* Signum: '<S125>/Sign' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Sqrt_b > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Sqrt_b;
          }

          /* Sum: '<S125>/Add2' incorporates:
           *  Abs: '<S125>/Abs'
           *  Gain: '<S125>/Gain'
           *  Gain: '<S125>/Gain1'
           *  Product: '<S125>/Multiply2'
           *  Product: '<S125>/Multiply3'
           *  Sqrt: '<S125>/Sqrt'
           *  Sum: '<S125>/Add1'
           *  Sum: '<S125>/Subtract'
           */
          rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) + FMS_ConstB.d) *
                             FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c +
            rtb_MathFunction_f_idx_0;

          /* Sum: '<S125>/Add4' */
          rtb_MathFunction_f_idx_0 += rtb_Sqrt_b - rtb_Rem_p;

          /* Sum: '<S125>/Add3' */
          rtb_Add3_c = rtb_Sqrt_b + FMS_ConstB.d;

          /* Sum: '<S125>/Subtract1' */
          rtb_Sqrt_b -= FMS_ConstB.d;

          /* Signum: '<S125>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S125>/Sign2' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Sum: '<S125>/Add5' incorporates:
           *  Gain: '<S125>/Gain2'
           *  Product: '<S125>/Multiply4'
           *  Sum: '<S125>/Subtract2'
           */
          rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F *
            rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S115>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator1'
           */
          FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

          /* Update for DiscreteIntegrator: '<S122>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S122>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

          /* Signum: '<S125>/Sign4' incorporates:
           *  Sum: '<S125>/Subtract3'
           */
          rtb_Add3_c = rtb_Rem_p - FMS_ConstB.d;

          /* Signum: '<S125>/Sign3' incorporates:
           *  Sum: '<S125>/Add6'
           */
          rtb_Divide_lr_idx_1 = rtb_Rem_p + FMS_ConstB.d;

          /* Signum: '<S125>/Sign5' */
          if (rtb_Rem_p < 0.0F) {
            rtb_a_l = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_a_l = 1.0F;
          } else {
            rtb_a_l = rtb_Rem_p;
          }

          /* Signum: '<S125>/Sign3' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_1 = 1.0F;
            }
          }

          /* Signum: '<S125>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S125>/Sign6' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_Rem_p;
          }

          /* Update for DiscreteIntegrator: '<S122>/Integrator' incorporates:
           *  Constant: '<S125>/const'
           *  Gain: '<S125>/Gain3'
           *  Product: '<S125>/Divide'
           *  Product: '<S125>/Multiply5'
           *  Product: '<S125>/Multiply6'
           *  Sum: '<S125>/Subtract4'
           *  Sum: '<S125>/Subtract5'
           *  Sum: '<S125>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE[1] += ((rtb_Rem_p / FMS_ConstB.d - rtb_a_l) *
            FMS_ConstB.Gain4 * ((rtb_Divide_lr_idx_1 - rtb_Add3_c) * 0.5F) -
            rtb_Sqrt_b * 58.836F) * 0.004F;

          /* End of Outputs for SubSystem: '<S111>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S111>/Switch Case' */

        /* SwitchCase: '<S98>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S98>/Hold Control' incorporates:
             *  ActionPort: '<S101>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S98>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S98>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S98>/Hold Control' incorporates:
           *  ActionPort: '<S101>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                            &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S98>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S98>/Brake Control' incorporates:
           *  ActionPort: '<S100>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S98>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S98>/Move Control' incorporates:
             *  ActionPort: '<S102>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S98>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S98>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S98>/Move Control' incorporates:
           *  ActionPort: '<S102>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S98>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S98>/Switch Case' */

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

        /* Saturate: '<S98>/Saturation' */
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

        /* End of Saturate: '<S98>/Saturation' */

        /* Saturate: '<S111>/Saturation1' */
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

        /* End of Saturate: '<S111>/Saturation1' */

        /* Saturate: '<S86>/Saturation1' */
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

        /* End of Saturate: '<S86>/Saturation1' */
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
   *  DiscreteIntegrator: '<S481>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S481>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S481>/Constant'
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

  /* Update for DiscreteIntegrator: '<S496>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S496>/Gain'
   *  Sum: '<S496>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S498>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S498>/Gain'
   *  Sum: '<S498>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S497>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S497>/Gain'
   *  Sum: '<S497>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_lr_idx_2 -
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
  rtb_a_l = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_a_l < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_a_l;
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
  rtb_a_l = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_a_l < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_a_l;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S10>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;
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
  /* Start for SwitchCase: '<S439>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S429>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S37>/Return' */

  /* Start for IfAction SubSystem: '<S37>/Hold' */
  /* Start for SwitchCase: '<S371>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S349>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S359>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S37>/Hold' */
  /* End of Start for SubSystem: '<S30>/SubMode' */

  /* Start for IfAction SubSystem: '<S30>/Auto' */
  /* Start for SwitchCase: '<S35>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S35>/Mission' */
  /* Start for Resettable SubSystem: '<S154>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S205>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S195>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S154>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S35>/Mission' */
  /* End of Start for SubSystem: '<S30>/Auto' */

  /* Start for IfAction SubSystem: '<S30>/Assist' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S34>/Stabilize' */
  /* Start for SwitchCase: '<S141>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S34>/Stabilize' */

  /* Start for IfAction SubSystem: '<S34>/Altitude' */
  /* Start for SwitchCase: '<S49>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S70>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S34>/Altitude' */

  /* Start for IfAction SubSystem: '<S34>/Position' */
  /* Start for SwitchCase: '<S86>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S111>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S98>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S34>/Position' */
  /* End of Start for SubSystem: '<S30>/Assist' */
  /* End of Start for SubSystem: '<S28>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S496>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S498>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S497>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S479>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S475>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S475>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S387>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S387>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Return' */
  /* InitializeConditions for Delay: '<S418>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S419>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S414>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S466>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;

  /* InitializeConditions for Delay: '<S396>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S399>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S395>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S399>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S440>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S439>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S439>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S439>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S439>/Move Control' */

  /* SystemInitialize for Merge: '<S439>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S430>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S429>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S429>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S429>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S429>/Move Control' */

  /* SystemInitialize for Merge: '<S429>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold' */
  /* SystemInitialize for Chart: '<S350>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S360>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S372>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S371>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S371>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S371>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S371>/Move Control' */

  /* SystemInitialize for Merge: '<S371>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S349>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S349>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S349>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S349>/Move Control' */

  /* SystemInitialize for Merge: '<S349>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S359>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S359>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S359>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S359>/Move Control' */

  /* SystemInitialize for Merge: '<S359>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S30>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S35>/Mission' */
  /* InitializeConditions for UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S154>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S184>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S180>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S232>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S162>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S165>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S165>/Integrator' */
  FMS_DW.Integrator_DSTATE_ip = 0.0F;

  /* SystemInitialize for Chart: '<S206>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S205>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S205>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S205>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S205>/Move Control' */

  /* SystemInitialize for Merge: '<S205>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S196>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S195>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S195>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S195>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S195>/Move Control' */

  /* SystemInitialize for Merge: '<S195>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S154>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S35>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S30>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S34>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator' */
  FMS_DW.Integrator_DSTATE_cm = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* SystemInitialize for Chart: '<S142>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S141>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S141>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S141>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S141>/Move Control' */

  /* SystemInitialize for Merge: '<S141>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S64>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S64>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S50>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S49>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S49>/Hold Control' */

  /* SystemInitialize for Merge: '<S49>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S71>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S70>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S70>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S70>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S70>/Move Control' */

  /* SystemInitialize for Merge: '<S70>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Position' */
  /* SystemInitialize for Chart: '<S87>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for IfAction SubSystem: '<S86>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S86>/Hold Control' */

  /* SystemInitialize for Chart: '<S99>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S112>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S111>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S111>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S111>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S111>/Move Control' */

  /* SystemInitialize for Merge: '<S111>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S111>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S111>/Move Control' */

  /* SystemInitialize for Merge: '<S111>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S86>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S98>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S98>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S98>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S98>/Move Control' */

  /* SystemInitialize for Merge: '<S98>/Merge' */
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
