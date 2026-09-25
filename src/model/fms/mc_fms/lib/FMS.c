/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2403
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Sep 25 08:52:15 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S442>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S452>/Motion State' */
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

/* Named constants for Chart: '<S374>/Motion State' */
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
#define FMS_IN_Takeoff_Waypoint        ((uint8_T)9U)
#define FMS_IN_Takeoff_d               ((uint8_T)8U)
#define FMS_IN_Waypoint                ((uint8_T)10U)
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
struct_VObA8ypT3yo2zSwMqlxWZC FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  1.2F,
  1.5F,
  5.0F,
  2.5F,
  2.5F,
  1.57079637F,
  0.52359879F,
  2.0F,
  5.0F,
  5.0F,
  1.2F,
  1.0F,
  0.5F,
  0.3F,
  0.6F,
  120U,
  1U,
  1300U,
  0.5F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S7>/Land_Lock_Thro'
                                        *   '<S28>/Constant'
                                        *   '<S505>/Constant1'
                                        *   '<S505>/Gain'
                                        *   '<S506>/Constant'
                                        *   '<S49>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S126>/Gain'
                                        *   '<S126>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S244>/Saturation'
                                        *   '<S245>/Saturation1'
                                        *   '<S245>/Saturation2'
                                        *   '<S245>/Saturation3'
                                        *   '<S398>/Land_Speed'
                                        *   '<S399>/Saturation1'
                                        *   '<S408>/Gain'
                                        *   '<S492>/Takeoff_Speed'
                                        *   '<S493>/Gain2'
                                        *   '<S493>/Saturation1'
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
                                        *   '<S300>/Gain2'
                                        *   '<S307>/Gain1'
                                        *   '<S307>/Gain2'
                                        *   '<S363>/Saturation1'
                                        *   '<S373>/Saturation'
                                        *   '<S385>/Saturation1'
                                        *   '<S400>/Constant'
                                        *   '<S403>/Gain2'
                                        *   '<S425>/Gain'
                                        *   '<S425>/Saturation1'
                                        *   '<S428>/vel'
                                        *   '<S433>/Constant'
                                        *   '<S433>/L1_GAIN'
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
                                        *   '<S169>/Gain'
                                        *   '<S169>/Saturation1'
                                        *   '<S172>/vel'
                                        *   '<S177>/Constant'
                                        *   '<S177>/L1_GAIN'
                                        *   '<S366>/Gain2'
                                        *   '<S367>/Gain1'
                                        *   '<S376>/Gain2'
                                        *   '<S377>/Gain1'
                                        *   '<S388>/Gain2'
                                        *   '<S389>/Gain6'
                                        *   '<S412>/Gain2'
                                        *   '<S412>/Saturation'
                                        *   '<S413>/Integrator'
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
                                        *   '<S159>/Gain2'
                                        *   '<S159>/Saturation'
                                        *   '<S160>/Integrator'
                                        *   '<S180>/Gain2'
                                        *   '<S180>/Relay'
                                        *   '<S180>/Saturation1'
                                        *   '<S369>/Dead Zone'
                                        *   '<S369>/Gain'
                                        *   '<S381>/Dead Zone'
                                        *   '<S381>/Gain'
                                        *   '<S393>/Dead Zone'
                                        *   '<S393>/Gain'
                                        *   '<S394>/Dead Zone'
                                        *   '<S394>/Gain'
                                        *   '<S441>/Saturation1'
                                        *   '<S451>/Saturation1'
                                        *   '<S191>/Saturation1'
                                        *   '<S201>/Saturation1'
                                        *   '<S444>/Gain2'
                                        *   '<S445>/Gain1'
                                        *   '<S454>/Gain2'
                                        *   '<S455>/Gain6'
                                        *   '<S194>/Gain2'
                                        *   '<S195>/Gain1'
                                        *   '<S204>/Gain2'
                                        *   '<S205>/Gain6'
                                        *   '<S447>/Dead Zone'
                                        *   '<S447>/Gain'
                                        *   '<S459>/Dead Zone'
                                        *   '<S459>/Gain'
                                        *   '<S460>/Dead Zone'
                                        *   '<S460>/Gain'
                                        *   '<S197>/Dead Zone'
                                        *   '<S197>/Gain'
                                        *   '<S209>/Dead Zone'
                                        *   '<S209>/Gain'
                                        *   '<S210>/Dead Zone'
                                        *   '<S210>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 77, 67, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S13>/Constant1'
                                        *   '<S503>/Constant'
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
static void FMS_exit_internal_Mode(void);
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
static real32_T FMS_norm_c(const real32_T x[2]);
static real32_T FMS_norm(const real32_T x[3]);
static void FMS_exit_internal_Mission(void);
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
 *    '<S441>/Hold Control'
 *    '<S363>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S444>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S441>/Hold Control'
 *    '<S363>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S444>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S441>/Hold Control'
 *    '<S363>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S444>/Delay' incorporates:
   *  Gain: '<S446>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S444>/Gain2' incorporates:
   *  Delay: '<S444>/Delay'
   *  Gain: '<S446>/Gain'
   *  Sum: '<S444>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.MC_Z_P;

  /* Update for Delay: '<S444>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S441>/Brake Control'
 *    '<S363>/Brake Control'
 *    '<S373>/Brake Control'
 *    '<S191>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S443>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S443>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S441>/Move Control'
 *    '<S363>/Move Control'
 *    '<S191>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S441>/Move Control'
 *    '<S363>/Move Control'
 *    '<S191>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S441>/Move Control'
 *    '<S363>/Move Control'
 *    '<S191>/Move Control'
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

  /* Product: '<S449>/Multiply1' incorporates:
   *  Constant: '<S449>/const1'
   *  DiscreteIntegrator: '<S448>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S447>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.MC_THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.MC_THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.MC_THROTTLE_DZ);
  }

  /* End of DeadZone: '<S447>/Dead Zone' */

  /* Sum: '<S449>/Add' incorporates:
   *  DiscreteIntegrator: '<S448>/Integrator1'
   *  Gain: '<S445>/Gain1'
   *  Gain: '<S447>/Gain'
   *  Sum: '<S448>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.MC_THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.MC_VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S449>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S449>/Sign' */

  /* Sum: '<S449>/Add2' incorporates:
   *  Abs: '<S449>/Abs'
   *  Gain: '<S449>/Gain'
   *  Gain: '<S449>/Gain1'
   *  Product: '<S449>/Multiply2'
   *  Product: '<S449>/Multiply3'
   *  Sqrt: '<S449>/Sqrt'
   *  Sum: '<S449>/Add1'
   *  Sum: '<S449>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S449>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S449>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S449>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S449>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S449>/Sign1' */

  /* Signum: '<S449>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S449>/Sign2' */

  /* Sum: '<S449>/Add5' incorporates:
   *  Gain: '<S449>/Gain2'
   *  Product: '<S449>/Multiply4'
   *  Sum: '<S449>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S445>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S448>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S448>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S448>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S449>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S449>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S449>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S449>/Sign5' */

  /* Signum: '<S449>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S449>/Sign3' */

  /* Signum: '<S449>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S449>/Sign4' */

  /* Signum: '<S449>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S449>/Sign6' */

  /* Update for DiscreteIntegrator: '<S448>/Integrator' incorporates:
   *  Constant: '<S449>/const'
   *  Gain: '<S449>/Gain3'
   *  Product: '<S449>/Divide'
   *  Product: '<S449>/Multiply5'
   *  Product: '<S449>/Multiply6'
   *  Sum: '<S449>/Subtract4'
   *  Sum: '<S449>/Subtract5'
   *  Sum: '<S449>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S442>/Motion Status'
 *    '<S364>/Motion Status'
 *    '<S192>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S442>/Motion Status'
 *    '<S364>/Motion Status'
 *    '<S192>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S442>/Motion Status'
 *    '<S364>/Motion Status'
 *    '<S192>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S442>/Motion Status' */
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

  /* End of Chart: '<S442>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S451>/Hold Control'
 *    '<S385>/Hold Control'
 *    '<S201>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S454>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S451>/Hold Control'
 *    '<S385>/Hold Control'
 *    '<S201>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S454>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S451>/Hold Control'
 *    '<S385>/Hold Control'
 *    '<S201>/Hold Control'
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

  /* Delay: '<S454>/Delay' incorporates:
   *  SignalConversion: '<S454>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S458>/Trigonometric Function1' incorporates:
   *  Gain: '<S457>/Gain'
   *  Trigonometry: '<S458>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S458>/Trigonometric Function' incorporates:
   *  Gain: '<S457>/Gain'
   *  Trigonometry: '<S458>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S458>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S458>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S458>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S458>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S458>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S458>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S458>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S454>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S454>/Delay'
   *  SignalConversion: '<S454>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S454>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S454>/Multiply' incorporates:
   *  SignalConversion: '<S454>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S454>/Multiply' */

  /* Gain: '<S454>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.MC_XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.MC_XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S454>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S451>/Brake Control'
 *    '<S385>/Brake Control'
 *    '<S201>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S453>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S451>/Move Control'
 *    '<S385>/Move Control'
 *    '<S201>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S451>/Move Control'
 *    '<S385>/Move Control'
 *    '<S201>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S451>/Move Control'
 *    '<S385>/Move Control'
 *    '<S201>/Move Control'
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

  /* SignalConversion: '<S455>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S461>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S462>/Multiply1' incorporates:
   *  Constant: '<S462>/const1'
   *  DiscreteIntegrator: '<S461>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S455>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S461>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S462>/Multiply1' incorporates:
   *  Constant: '<S462>/const1'
   *  DiscreteIntegrator: '<S461>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S459>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.MC_PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.MC_PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.MC_PITCH_DZ);
  }

  /* End of DeadZone: '<S459>/Dead Zone' */

  /* Sum: '<S462>/Add' incorporates:
   *  DiscreteIntegrator: '<S461>/Integrator1'
   *  Gain: '<S455>/Gain6'
   *  Gain: '<S459>/Gain'
   *  Sum: '<S461>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.MC_PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.MC_VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S460>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.MC_ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.MC_ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.MC_ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.MC_ROLL_DZ);
  }

  /* End of DeadZone: '<S460>/Dead Zone' */

  /* Sum: '<S462>/Add' incorporates:
   *  DiscreteIntegrator: '<S461>/Integrator1'
   *  Gain: '<S455>/Gain6'
   *  Gain: '<S460>/Gain'
   *  Sum: '<S461>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.MC_ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.MC_VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S462>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S462>/Add2' incorporates:
   *  Abs: '<S462>/Abs'
   *  Gain: '<S462>/Gain'
   *  Gain: '<S462>/Gain1'
   *  Product: '<S462>/Multiply2'
   *  Product: '<S462>/Multiply3'
   *  Signum: '<S462>/Sign'
   *  Sqrt: '<S462>/Sqrt'
   *  Sum: '<S462>/Add1'
   *  Sum: '<S462>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S462>/Add3' incorporates:
   *  Signum: '<S462>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S462>/Subtract1' incorporates:
   *  Signum: '<S462>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S462>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S462>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S462>/Add5' incorporates:
   *  Gain: '<S462>/Gain2'
   *  Product: '<S462>/Multiply4'
   *  Signum: '<S462>/Sign'
   *  Sum: '<S462>/Add2'
   *  Sum: '<S462>/Add4'
   *  Sum: '<S462>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S461>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S461>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S462>/Sign3' incorporates:
   *  Sum: '<S462>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S462>/Sign4' incorporates:
   *  Sum: '<S462>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S462>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S462>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S462>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S462>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S461>/Integrator' incorporates:
   *  Constant: '<S462>/const'
   *  Gain: '<S462>/Gain3'
   *  Product: '<S462>/Divide'
   *  Product: '<S462>/Multiply5'
   *  Product: '<S462>/Multiply6'
   *  Sum: '<S462>/Subtract4'
   *  Sum: '<S462>/Subtract5'
   *  Sum: '<S462>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S462>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S462>/Add2' incorporates:
   *  Abs: '<S462>/Abs'
   *  Gain: '<S462>/Gain'
   *  Gain: '<S462>/Gain1'
   *  Product: '<S462>/Multiply2'
   *  Product: '<S462>/Multiply3'
   *  Signum: '<S462>/Sign'
   *  Sqrt: '<S462>/Sqrt'
   *  Sum: '<S462>/Add1'
   *  Sum: '<S462>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S462>/Add3' incorporates:
   *  Signum: '<S462>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S462>/Subtract1' incorporates:
   *  Signum: '<S462>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S462>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S462>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S462>/Add5' incorporates:
   *  Gain: '<S462>/Gain2'
   *  Product: '<S462>/Multiply4'
   *  Signum: '<S462>/Sign'
   *  Sum: '<S462>/Add2'
   *  Sum: '<S462>/Add4'
   *  Sum: '<S462>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S461>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S461>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S462>/Sign3' incorporates:
   *  Sum: '<S462>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S462>/Sign4' incorporates:
   *  Sum: '<S462>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S462>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S462>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S462>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S462>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S461>/Integrator' incorporates:
   *  Constant: '<S462>/const'
   *  Gain: '<S462>/Gain3'
   *  Product: '<S462>/Divide'
   *  Product: '<S462>/Multiply5'
   *  Product: '<S462>/Multiply6'
   *  Sum: '<S462>/Subtract4'
   *  Sum: '<S462>/Subtract5'
   *  Sum: '<S462>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S452>/Motion State'
 *    '<S386>/Motion State'
 *    '<S202>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S452>/Motion State'
 *    '<S386>/Motion State'
 *    '<S202>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S452>/Motion State'
 *    '<S386>/Motion State'
 *    '<S202>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S452>/Motion State' */
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

  /* End of Chart: '<S452>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S430>/NearbyRefWP'
 *    '<S174>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S466>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S373>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S376>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S373>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S376>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S373>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_nb;

  /* Delay: '<S376>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S376>/Sum' incorporates:
   *  Delay: '<S376>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S379>/Abs' */
  rtb_Abs_nb = fabsf(rtb_psi_error_rad);

  /* Switch: '<S379>/Switch' incorporates:
   *  Constant: '<S379>/Constant'
   *  Constant: '<S380>/Constant'
   *  Product: '<S379>/Multiply'
   *  RelationalOperator: '<S380>/Compare'
   *  Sum: '<S379>/Subtract'
   */
  if (rtb_Abs_nb > 3.14159274F) {
    /* Signum: '<S379>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S379>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_nb - 6.28318548F;
  }

  /* End of Switch: '<S379>/Switch' */

  /* Gain: '<S376>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.MC_YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S376>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S373>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S373>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S373>/Move Control'
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

  /* Product: '<S383>/Multiply1' incorporates:
   *  Constant: '<S383>/const1'
   *  DiscreteIntegrator: '<S382>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S381>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.MC_YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.MC_YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.MC_YAW_DZ);
  }

  /* End of DeadZone: '<S381>/Dead Zone' */

  /* Sum: '<S383>/Add' incorporates:
   *  DiscreteIntegrator: '<S382>/Integrator1'
   *  Gain: '<S377>/Gain1'
   *  Gain: '<S381>/Gain'
   *  Sum: '<S382>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.MC_YAW_DZ) * rtb_a_m * FMS_PARAM.MC_YAWRATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S383>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S383>/Sign' */

  /* Sum: '<S383>/Add2' incorporates:
   *  Abs: '<S383>/Abs'
   *  Gain: '<S383>/Gain'
   *  Gain: '<S383>/Gain1'
   *  Product: '<S383>/Multiply2'
   *  Product: '<S383>/Multiply3'
   *  Sqrt: '<S383>/Sqrt'
   *  Sum: '<S383>/Add1'
   *  Sum: '<S383>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S383>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S383>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S383>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S383>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign1' */

  /* Signum: '<S383>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign2' */

  /* Sum: '<S383>/Add5' incorporates:
   *  Gain: '<S383>/Gain2'
   *  Product: '<S383>/Multiply4'
   *  Sum: '<S383>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S377>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S382>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S382>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S382>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S383>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S383>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S383>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S383>/Sign5' */

  /* Signum: '<S383>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign3' */

  /* Signum: '<S383>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign4' */

  /* Signum: '<S383>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S383>/Sign6' */

  /* Update for DiscreteIntegrator: '<S382>/Integrator' incorporates:
   *  Constant: '<S383>/const'
   *  Gain: '<S383>/Gain3'
   *  Product: '<S383>/Divide'
   *  Product: '<S383>/Multiply5'
   *  Product: '<S383>/Multiply6'
   *  Sum: '<S383>/Subtract4'
   *  Sum: '<S383>/Subtract5'
   *  Sum: '<S383>/Subtract6'
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

  /* BusAssignment: '<S359>/Bus Assignment' incorporates:
   *  Constant: '<S359>/Constant'
   *  Constant: '<S359>/Constant2'
   *  SignalConversion: '<S359>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S359>/Bus Assignment' */
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
  if (rtu_FMS_In > FMS_PARAM.MC_THROTTLE_DZ) {
    rtb_Gain1_j = rtu_FMS_In - FMS_PARAM.MC_THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_THROTTLE_DZ) {
    rtb_Gain1_j = 0.0F;
  } else {
    rtb_Gain1_j = rtu_FMS_In - (-FMS_PARAM.MC_THROTTLE_DZ);
  }

  /* End of DeadZone: '<S59>/Dead Zone' */

  /* Gain: '<S54>/Gain1' incorporates:
   *  Gain: '<S59>/Gain'
   */
  rtb_Gain1_j = 1.0F / (1.0F - FMS_PARAM.MC_THROTTLE_DZ) * rtb_Gain1_j *
    -FMS_PARAM.MC_VEL_Z_LIM;

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
       FMS_PARAM.MC_ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.MC_LAND_SPEED, rtb_Gain1_j);
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

  /* Gain: '<S508>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S509>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S509>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S509>/Multiply1' incorporates:
   *  Product: '<S509>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S509>/Divide' incorporates:
   *  Constant: '<S509>/Constant'
   *  Constant: '<S509>/R'
   *  Sqrt: '<S509>/Sqrt'
   *  Sum: '<S509>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S509>/Product3' incorporates:
   *  Constant: '<S509>/Constant1'
   *  Product: '<S509>/Multiply1'
   *  Sum: '<S509>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S509>/Multiply2' incorporates:
   *  Trigonometry: '<S509>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S508>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S513>/Abs' incorporates:
   *  Abs: '<S516>/Abs1'
   *  Switch: '<S513>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S513>/Switch1' incorporates:
   *  Abs: '<S513>/Abs'
   *  Bias: '<S513>/Bias2'
   *  Bias: '<S513>/Bias3'
   *  Constant: '<S510>/Constant'
   *  Constant: '<S510>/Constant1'
   *  Constant: '<S515>/Constant'
   *  Gain: '<S513>/Gain1'
   *  Product: '<S513>/Multiply'
   *  RelationalOperator: '<S515>/Compare'
   *  Switch: '<S510>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S516>/Switch1' incorporates:
     *  Bias: '<S516>/Bias2'
     *  Bias: '<S516>/Bias3'
     *  Constant: '<S516>/Constant'
     *  Constant: '<S517>/Constant'
     *  Math: '<S516>/Math Function'
     *  RelationalOperator: '<S517>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S516>/Switch1' */

    /* Signum: '<S513>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S513>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S510>/Sum' incorporates:
   *  Sum: '<S508>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S508>/Multiply' incorporates:
   *  Gain: '<S508>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S512>/Switch1' incorporates:
   *  Abs: '<S512>/Abs1'
   *  Bias: '<S512>/Bias2'
   *  Bias: '<S512>/Bias3'
   *  Constant: '<S512>/Constant'
   *  Constant: '<S514>/Constant'
   *  Math: '<S512>/Math Function'
   *  RelationalOperator: '<S514>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S512>/Switch1' */

  /* Product: '<S508>/Multiply' incorporates:
   *  Gain: '<S508>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S508>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S511>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S511>/Sum2' incorporates:
   *  Product: '<S511>/Multiply1'
   *  Product: '<S511>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S511>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S511>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S511>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S504>/Data Type Conversion' incorporates:
   *  Gain: '<S508>/Gain'
   *  Sum: '<S508>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_ee;
  rty_pos[1] = (real32_T)rtb_Sum3_l;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_exit_internal_Mode(void)
{
  FMS_DW.is_Mode = FMS_IN_NO_ACTIVE_CHILD_h;
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
        FMS_exit_internal_Mode();
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
        FMS_exit_internal_Mode();
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
static real32_T FMS_norm_c(const real32_T x[2])
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
static real32_T FMS_norm(const real32_T x[3])
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

  absxk = fabsf(x[2]);
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
static void FMS_exit_internal_Mission(void)
{
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_h;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Mission(void)
{
  real32_T rtb_reachable_distance;
  real32_T rtb_Sqrt;
  real32_T tmp[2];
  real32_T tmp_0[3];
  uint32_T qY;
  int32_T tmp_1;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_exit_internal_Mission();
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
        tmp_1 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_1 > 255U) {
          tmp_1 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_1;
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
        tmp_1 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_1 > 255U) {
          tmp_1 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_1;
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
        FMS_B.cur_waypoint[0] = FMS_B.Cmd_In.cur_waypoint[0];
        FMS_B.sp_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
        FMS_B.cur_waypoint[1] = FMS_B.Cmd_In.cur_waypoint[1];
        FMS_B.sp_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
        FMS_B.cur_waypoint[2] = FMS_B.Cmd_In.cur_waypoint[2];
        FMS_B.sp_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.Takeoff.reachable_wp' */
        /* Sum: '<S505>/Sum' */
        FMS_B.Switch1[0] = FMS_B.sp_waypoint[0] - FMS_B.cur_waypoint[0];
        FMS_B.Switch1[1] = FMS_B.sp_waypoint[1] - FMS_B.cur_waypoint[1];

        /* Gain: '<S505>/Gain' incorporates:
         *  Constant: '<S505>/Constant1'
         *  Product: '<S505>/Divide'
         *  Sum: '<S505>/Sum1'
         */
        rtb_reachable_distance = 1.0F / FMS_PARAM.MC_TAKEOFF_SPEED *
          (FMS_B.sp_waypoint[2] - FMS_B.cur_waypoint[2]) *
          (FMS_PARAM.MC_VEL_XY_LIM / 5.0F);

        /* Sqrt: '<S518>/Sqrt' incorporates:
         *  Math: '<S518>/Square'
         *  Sum: '<S518>/Sum of Elements'
         */
        rtb_Sqrt = sqrtf(FMS_B.Switch1[0] * FMS_B.Switch1[0] + FMS_B.Switch1[1] *
                         FMS_B.Switch1[1]);

        /* Switch: '<S505>/Switch1' incorporates:
         *  Product: '<S505>/Multiply'
         *  Sum: '<S505>/Sum2'
         *  Sum: '<S505>/Sum3'
         */
        if (rtb_Sqrt - rtb_reachable_distance > 0.0F) {
          /* Product: '<S505>/Divide1' */
          rtb_reachable_distance /= rtb_Sqrt;

          /* Saturate: '<S505>/Saturation' */
          if (rtb_reachable_distance > 1.0F) {
            rtb_reachable_distance = 1.0F;
          } else {
            if (rtb_reachable_distance < 0.0F) {
              rtb_reachable_distance = 0.0F;
            }
          }

          /* End of Saturate: '<S505>/Saturation' */
          FMS_B.Switch1[0] = rtb_reachable_distance * FMS_B.Switch1[0] +
            FMS_B.cur_waypoint[0];
          FMS_B.Switch1[1] = rtb_reachable_distance * FMS_B.Switch1[1] +
            FMS_B.cur_waypoint[1];
        } else {
          FMS_B.Switch1[0] = FMS_B.sp_waypoint[0];
          FMS_B.Switch1[1] = FMS_B.sp_waypoint[1];
        }

        /* End of Switch: '<S505>/Switch1' */
        /* End of Outputs for SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.Takeoff.reachable_wp' */
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.Switch1[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.Switch1[1];
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

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_U.Mission_Data.param4[FMS_B.wp_index - 1] >= 0.0F) {
          FMS_B.Cmd_In.set_yaw = FMS_U.Mission_Data.param4[FMS_B.wp_index - 1] /
            180.0F * 3.14159274F;
        } else {
          FMS_B.Cmd_In.set_yaw = atan2f(FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1], FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0]);
        }

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
      if (FMS_norm_c(tmp) < 0.5F) {
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
      tmp_1 = (int32_T)(FMS_B.wp_index + 1U);
      if ((uint32_T)tmp_1 > 255U) {
        tmp_1 = 255;
      }

      FMS_B.wp_index = (uint8_T)tmp_1;
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
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];

        /* Constant: '<Root>/ACCEPT_R' */
        if (FMS_norm_c(tmp) <= FMS_PARAM.MC_ACCEPT_R) {
          FMS_DW.is_Mission = FMS_IN_Takeoff_Waypoint;
          FMS_B.Cmd_In.cur_waypoint[0] =
            FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
          FMS_B.Cmd_In.cur_waypoint[1] =
            FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
          FMS_B.Cmd_In.cur_waypoint[2] =
            FMS_B.BusConversion_InsertedFor_FMSSt.h_R;

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

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
          F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
            FMS_B.psio, FMS_B.DataTypeConversion,
            &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
          FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
          FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
          FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
          FMS_B.state = VehicleState_Mission;
        } else {
          tmp_1 = (int32_T)(FMS_B.wp_index + 1U);
          if ((uint32_T)tmp_1 > 255U) {
            tmp_1 = 255;
          }

          FMS_B.wp_index = (uint8_T)tmp_1;
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
      }
      break;

     case FMS_IN_Takeoff_Waypoint:
      tmp_0[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp_0[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];
      tmp_0[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R -
        FMS_B.Cmd_In.sp_waypoint[2];

      /* Constant: '<Root>/ACCEPT_R' */
      if (FMS_norm(tmp_0) <= FMS_PARAM.MC_ACCEPT_R) {
        tmp_1 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_1 > 255U) {
          tmp_1 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_1;
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
      tmp_0[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp_0[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];
      tmp_0[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R -
        FMS_B.Cmd_In.sp_waypoint[2];

      /* Constant: '<Root>/ACCEPT_R' */
      if (FMS_norm(tmp_0) <= FMS_PARAM.MC_ACCEPT_R) {
        FMS_B.Cmd_In.set_speed = 0.0F;
        FMS_B.Cmd_In.set_yaw = -1.0F;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] > 0.0F) {
          FMS_DW.is_Mission = FMS_IN_Hold_d;
          FMS_DW.temporalCounter_i1 = 0U;
          FMS_B.state = VehicleState_Hold;
        } else {
          tmp_1 = (int32_T)(FMS_B.wp_index + 1U);
          if ((uint32_T)tmp_1 > 255U) {
            tmp_1 = 255;
          }

          FMS_B.wp_index = (uint8_T)tmp_1;
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
    FMS_B.Cmd_In.set_yaw = -1.0F;
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

  /* Outputs for Function Call SubSystem: '<S6>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S519>/Compare' incorporates:
   *  Abs: '<S507>/Abs'
   *  Constant: '<S519>/Constant'
   *  MinMax: '<S507>/Max'
   *  Sum: '<S507>/Sum'
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
      if (y <= FMS_PARAM.MC_ACCEPT_R) {
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
      FMS_exit_internal_Mission();
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
      /* Reshape: '<S506>/Reshape' incorporates:
       *  Constant: '<S506>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.MC_TAKEOFF_H;

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
    FMS_DW.cmd_prev = FMS_B.Switch1_c;
    FMS_DW.cmd_start = FMS_B.Switch1_c;
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
        if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.Switch1_c !=
             FMS_Cmd_None)) {
          FMS_DW.save_cmd = FMS_B.Switch1_c;
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
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  real32_T rtb_Saturation_n;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_ft[3];
  uint16_T rtb_Divide_dr;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_Subtract3_od;
  real32_T rtb_Add4_d;
  boolean_T rtb_Compare_on;
  boolean_T rtb_LogicalOperator_aa;
  real32_T rtb_Switch2_m;
  real32_T rtb_Integrator1_a;
  MotionState rtb_state_c;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_VectorConcatenate_m[9];
  real32_T rtb_Rem_g;
  real32_T rtb_Gain_hc;
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
  real32_T rtb_MathFunction_p_idx_1;
  real32_T rtb_MathFunction_p_idx_0;
  real32_T rtb_MathFunction_h_idx_1;
  real32_T rtb_MathFunction_h_idx_0;
  real32_T rtb_Switch_mp_idx_2;
  real32_T rtb_Switch_mp_idx_1;
  real32_T rtb_Switch_f3_idx_2;
  real32_T rtb_Switch_f3_idx_1;
  real32_T rtb_MathFunction_f_idx_2;
  real32_T rtb_MathFunction_f_idx_1;
  real32_T rtb_Switch_mp_idx_0;
  real32_T rtb_Switch_f3_idx_0;
  real32_T rtb_Divide_l_idx_2;
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
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

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
    FMS_B.Switch1_c = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S14>/Switch2' */
    FMS_B.Switch1_c = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1_c = FMS_Cmd_None;
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
      rtb_FixPtRelationalOperator_me || (FMS_PARAM.MC_LOST_RETURN_EN == 0)) {
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
    FMS_PARAM.MC_LOST_RETURN_TIME) && (FMS_PARAM.MC_LOST_RETURN_EN != 0));

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

  /* Sqrt: '<S529>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S529>/Square'
   *  Sum: '<S529>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S525>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3_c = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_MathFunction_p_idx_0 = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S526>/Square' incorporates:
   *  Math: '<S527>/Square'
   *  Math: '<S528>/Square'
   */
  rtb_Gain_hc = rtb_Add3_c * rtb_Add3_c;

  /* Math: '<S526>/Square2' incorporates:
   *  Math: '<S527>/Square2'
   *  Math: '<S528>/Square2'
   */
  rtb_Rem_g = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S526>/Square1' incorporates:
   *  Math: '<S527>/Square1'
   *  Math: '<S528>/Square1'
   */
  rtb_Saturation_n = rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1;

  /* Math: '<S526>/Square3' incorporates:
   *  Math: '<S527>/Square3'
   *  Math: '<S528>/Square3'
   */
  rtb_Subtract3_od = rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

  /* Sum: '<S526>/Subtract' incorporates:
   *  Math: '<S526>/Square'
   *  Math: '<S526>/Square1'
   *  Math: '<S526>/Square2'
   *  Math: '<S526>/Square3'
   *  Sum: '<S526>/Add'
   *  Sum: '<S526>/Add1'
   */
  rtb_Transpose[0] = (rtb_Gain_hc + rtb_Saturation_n) - (rtb_Rem_g +
    rtb_Subtract3_od);

  /* Product: '<S526>/Multiply' incorporates:
   *  Product: '<S527>/Multiply'
   */
  rtb_Add4_d = rtb_MathFunction_f_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S526>/Multiply1' incorporates:
   *  Product: '<S527>/Multiply1'
   */
  rtb_Switch2_m = rtb_Add3_c * rtb_MathFunction_p_idx_0;

  /* Gain: '<S526>/Gain' incorporates:
   *  Product: '<S526>/Multiply'
   *  Product: '<S526>/Multiply1'
   *  Sum: '<S526>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_Add4_d - rtb_Switch2_m) * 2.0F;

  /* Product: '<S526>/Multiply2' incorporates:
   *  Product: '<S528>/Multiply'
   */
  rtb_Integrator1_a = rtb_MathFunction_f_idx_1 * rtb_MathFunction_p_idx_0;

  /* Product: '<S526>/Multiply3' incorporates:
   *  Product: '<S528>/Multiply1'
   */
  rtb_MathFunction_p_idx_1 = rtb_Add3_c * rtb_Divide_l_idx_2;

  /* Gain: '<S526>/Gain1' incorporates:
   *  Product: '<S526>/Multiply2'
   *  Product: '<S526>/Multiply3'
   *  Sum: '<S526>/Add2'
   */
  rtb_Transpose[2] = (rtb_Integrator1_a + rtb_MathFunction_p_idx_1) * 2.0F;

  /* Gain: '<S527>/Gain' incorporates:
   *  Sum: '<S527>/Add3'
   */
  rtb_Transpose[3] = (rtb_Add4_d + rtb_Switch2_m) * 2.0F;

  /* Sum: '<S527>/Subtract' incorporates:
   *  Sum: '<S527>/Add'
   *  Sum: '<S527>/Add1'
   */
  rtb_Transpose[4] = (rtb_Gain_hc + rtb_Rem_g) - (rtb_Saturation_n +
    rtb_Subtract3_od);

  /* Product: '<S527>/Multiply2' incorporates:
   *  Product: '<S528>/Multiply2'
   */
  rtb_Add4_d = rtb_Divide_l_idx_2 * rtb_MathFunction_p_idx_0;

  /* Product: '<S527>/Multiply3' incorporates:
   *  Product: '<S528>/Multiply3'
   */
  rtb_Switch2_m = rtb_Add3_c * rtb_MathFunction_f_idx_1;

  /* Gain: '<S527>/Gain1' incorporates:
   *  Product: '<S527>/Multiply2'
   *  Product: '<S527>/Multiply3'
   *  Sum: '<S527>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_Add4_d - rtb_Switch2_m) * 2.0F;

  /* Gain: '<S528>/Gain' incorporates:
   *  Sum: '<S528>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Integrator1_a - rtb_MathFunction_p_idx_1) * 2.0F;

  /* Gain: '<S528>/Gain1' incorporates:
   *  Sum: '<S528>/Add2'
   */
  rtb_Transpose[7] = (rtb_Add4_d + rtb_Switch2_m) * 2.0F;

  /* Sum: '<S528>/Subtract' incorporates:
   *  Sum: '<S528>/Add'
   *  Sum: '<S528>/Add1'
   */
  rtb_Transpose[8] = (rtb_Gain_hc + rtb_Subtract3_od) - (rtb_Saturation_n +
    rtb_Rem_g);

  /* Math: '<S7>/Transpose' */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_VectorConcatenate_m[3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0];
    rtb_VectorConcatenate_m[1 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 3];
    rtb_VectorConcatenate_m[2 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 6];
  }

  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 9; rtb_Compare_bv_0++) {
    rtb_Transpose[rtb_Compare_bv_0] = rtb_VectorConcatenate_m[rtb_Compare_bv_0];
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

  /* DiscreteIntegrator: '<S520>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S522>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S522>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_Add3_c = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Add3_c > 1.0F) {
    rtb_Add3_c = 1.0F;
  } else {
    if (rtb_Add3_c < 0.9F) {
      rtb_Add3_c = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_l_idx_2 = (real32_T)FMS_PARAM.MC_LAND_LOCK_THRO / rtb_Add3_c;

  /* DiscreteIntegrator: '<S521>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S520>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S521>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S522>/Discrete-Time Integrator5'
   *  Logic: '<S523>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S523>/Lower Test'
   *  RelationalOperator: '<S523>/Upper Test'
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

  /* Sum: '<S502>/Add' incorporates:
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
  FMS_DW.cmd_start = FMS_B.Switch1_c;
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
        /* Disable for SwitchCase: '<S451>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S441>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S385>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S363>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S373>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S201>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S191>/Switch Case' */
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
          /* Disable for SwitchCase: '<S451>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S441>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S363>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S201>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S191>/Switch Case' */
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
       *  Math: '<S473>/Math Function'
       *  Product: '<S475>/Divide'
       *  Sum: '<S431>/Subtract'
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
          /* Disable for SwitchCase: '<S451>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S441>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S363>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Takeoff' incorporates:
           *  ActionPort: '<S358>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S500>/cur_waypoint'
           *  DiscreteIntegrator: '<S496>/Integrator'
           *  DiscreteIntegrator: '<S496>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Takeoff' incorporates:
         *  ActionPort: '<S358>/Action Port'
         */
        /* Delay: '<S500>/cur_waypoint' incorporates:
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
        /* Product: '<S500>/Divide' incorporates:
         *  Delay: '<S500>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S500>/Sum1'
         *  Sum: '<S500>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S500>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S500>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S501>/Trigonometric Function1' incorporates:
         *  Gain: '<S499>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S501>/Trigonometric Function3'
         */
        rtb_Gain_hc = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_Gain_hc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S501>/Trigonometric Function' incorporates:
         *  Gain: '<S499>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S501>/Trigonometric Function2'
         */
        rtb_Rem_g = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_Rem_g;

        /* SignalConversion: '<S501>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S501>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S501>/Gain' */
        rtb_Transpose[3] = -rtb_Rem_g;

        /* Trigonometry: '<S501>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_Gain_hc;

        /* SignalConversion: '<S501>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S501>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S501>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S493>/Saturation1' */
        rtb_Saturation_n = FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
        rtb_Subtract3_od = -FMS_PARAM.MC_VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S493>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S500>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S500>/Multiply'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S493>/Sum'
         *  Sum: '<S500>/Sum3'
         *  Sum: '<S500>/Sum4'
         */
        rtb_Switch2_m = ((FMS_B.Cmd_In.sp_waypoint[0] -
                          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
                         FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_Integrator1_a = ((FMS_B.Cmd_In.sp_waypoint[1] -
                              FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
                             FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S493>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Switch2_m;
        }

        /* Saturate: '<S493>/Saturation1' incorporates:
         *  Gain: '<S493>/Gain2'
         *  Product: '<S493>/Multiply'
         */
        rtb_Add3_c = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
        rtb_Add4_d = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S358>/Bus Assignment1'
         *  Constant: '<S358>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
         *  Constant: '<S358>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S493>/Saturation1' */
        if (rtb_Add3_c > rtb_Saturation_n) {
          /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_n;
        } else if (rtb_Add3_c < rtb_Subtract3_od) {
          /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_od;
        } else {
          /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add3_c;
        }

        if (rtb_Add4_d > rtb_Saturation_n) {
          /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        } else if (rtb_Add4_d < rtb_Subtract3_od) {
          /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Subtract3_od;
        } else {
          /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_d;
        }

        /* BusAssignment: '<S358>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S496>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S497>/Multiply1' incorporates:
         *  Constant: '<S497>/const1'
         *  DiscreteIntegrator: '<S496>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S492>/Switch' incorporates:
         *  Abs: '<S492>/Abs'
         *  Abs: '<S492>/Abs1'
         *  Constant: '<S492>/Takeoff_Speed'
         *  Constant: '<S494>/Constant'
         *  Constant: '<S495>/Constant'
         *  Gain: '<S492>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S492>/Logical Operator'
         *  RelationalOperator: '<S494>/Compare'
         *  RelationalOperator: '<S495>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S492>/Sum'
         *  Sum: '<S492>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Saturation_n = -FMS_PARAM.MC_TAKEOFF_SPEED;
        } else {
          rtb_Saturation_n = 0.5F * -FMS_PARAM.MC_TAKEOFF_SPEED;
        }

        /* End of Switch: '<S492>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S497>/Add' incorporates:
         *  DiscreteIntegrator: '<S496>/Integrator1'
         *  Sum: '<S496>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_a - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S497>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Subtract3_od;
        }

        /* End of Signum: '<S497>/Sign' */

        /* Sum: '<S497>/Add2' incorporates:
         *  Abs: '<S497>/Abs'
         *  Gain: '<S497>/Gain'
         *  Gain: '<S497>/Gain1'
         *  Product: '<S497>/Multiply2'
         *  Product: '<S497>/Multiply3'
         *  Sqrt: '<S497>/Sqrt'
         *  Sum: '<S497>/Add1'
         *  Sum: '<S497>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S497>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Saturation_n) + rtb_Add3_c;

        /* Sum: '<S497>/Add3' */
        rtb_Add3_c = rtb_Subtract3_od + FMS_ConstB.d_m;

        /* Sum: '<S497>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_m;

        /* Signum: '<S497>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S497>/Sign1' */

        /* Signum: '<S497>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S497>/Sign2' */

        /* Sum: '<S497>/Add5' incorporates:
         *  Gain: '<S497>/Gain2'
         *  Product: '<S497>/Multiply4'
         *  Sum: '<S497>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F * rtb_Add4_d;

        /* Update for Delay: '<S500>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S496>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S496>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S497>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - FMS_ConstB.d_m;

        /* Sum: '<S497>/Add6' */
        rtb_Add4_d = rtb_Saturation_n + FMS_ConstB.d_m;

        /* Signum: '<S497>/Sign5' incorporates:
         *  Signum: '<S497>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S497>/Sign6' */
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S497>/Sign6' */
          rtb_MathFunction_p_idx_0 = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S497>/Sign6' */
          rtb_MathFunction_p_idx_0 = rtb_Saturation_n;
        }

        /* End of Signum: '<S497>/Sign5' */

        /* Signum: '<S497>/Sign3' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S497>/Sign3' */

        /* Signum: '<S497>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S497>/Sign4' */

        /* Update for DiscreteIntegrator: '<S496>/Integrator' incorporates:
         *  Constant: '<S497>/const'
         *  Gain: '<S497>/Gain3'
         *  Product: '<S497>/Divide'
         *  Product: '<S497>/Multiply5'
         *  Product: '<S497>/Multiply6'
         *  Sum: '<S497>/Subtract4'
         *  Sum: '<S497>/Subtract5'
         *  Sum: '<S497>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_Saturation_n / FMS_ConstB.d_m -
          rtb_Gain_hc) * FMS_ConstB.Gain4_a * ((rtb_Add4_d - rtb_Add3_c) * 0.5F)
          - rtb_MathFunction_p_idx_0 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Land' incorporates:
           *  ActionPort: '<S356>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S401>/Integrator'
           *  DiscreteIntegrator: '<S401>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Land' incorporates:
         *  ActionPort: '<S356>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S406>/Trigonometric Function1' incorporates:
         *  Gain: '<S405>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S406>/Trigonometric Function' incorporates:
         *  Gain: '<S405>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S406>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S406>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S406>/Gain' incorporates:
         *  Gain: '<S405>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S406>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S406>/Trigonometric Function3' incorporates:
         *  Gain: '<S405>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S406>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S406>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S406>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S399>/Saturation1' */
        rtb_Gain_hc = FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
        rtb_MathFunction_p_idx_0 = -FMS_PARAM.MC_VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S403>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S403>/Sum'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S403>/Multiply' incorporates:
         *  SignalConversion: '<S403>/TmpSignal ConversionAtMultiplyInport2'
         *  Sum: '<S403>/Sum'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Subtract3_od + rtb_Transpose[rtb_Compare_bv_0] * rtb_Add3_c;
        }

        /* End of Product: '<S403>/Multiply' */

        /* Saturate: '<S399>/Saturation1' incorporates:
         *  Gain: '<S403>/Gain2'
         */
        rtb_Add3_c = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
        rtb_Add4_d = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S356>/Bus Assignment1'
         *  Constant: '<S356>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
         *  Constant: '<S356>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S399>/Saturation1' */
        if (rtb_Add3_c > rtb_Gain_hc) {
          /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_hc;
        } else if (rtb_Add3_c < rtb_MathFunction_p_idx_0) {
          /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_p_idx_0;
        } else {
          /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add3_c;
        }

        if (rtb_Add4_d > rtb_Gain_hc) {
          /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Gain_hc;
        } else if (rtb_Add4_d < rtb_MathFunction_p_idx_0) {
          /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_p_idx_0;
        } else {
          /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_d;
        }

        /* BusAssignment: '<S356>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S401>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S402>/Multiply1' incorporates:
         *  Constant: '<S402>/const1'
         *  DiscreteIntegrator: '<S401>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S398>/Switch' incorporates:
         *  Constant: '<S398>/Land_Speed'
         *  Constant: '<S400>/Constant'
         *  Gain: '<S398>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S398>/Logical Operator'
         *  RelationalOperator: '<S400>/Compare'
         *  S-Function (sfix_bitop): '<S398>/cmd_p valid'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.MC_ASSIST_LAND_H)) {
          rtb_Saturation_n = 0.5F * FMS_PARAM.MC_LAND_SPEED;
        } else {
          rtb_Saturation_n = FMS_PARAM.MC_LAND_SPEED;
        }

        /* End of Switch: '<S398>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S402>/Add' incorporates:
         *  DiscreteIntegrator: '<S401>/Integrator1'
         *  Sum: '<S401>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_j - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S402>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Subtract3_od;
        }

        /* End of Signum: '<S402>/Sign' */

        /* Sum: '<S402>/Add2' incorporates:
         *  Abs: '<S402>/Abs'
         *  Gain: '<S402>/Gain'
         *  Gain: '<S402>/Gain1'
         *  Product: '<S402>/Multiply2'
         *  Product: '<S402>/Multiply3'
         *  Sqrt: '<S402>/Sqrt'
         *  Sum: '<S402>/Add1'
         *  Sum: '<S402>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d_p) * FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S402>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Saturation_n) + rtb_Add3_c;

        /* Sum: '<S402>/Add3' */
        rtb_Add3_c = rtb_Subtract3_od + FMS_ConstB.d_p;

        /* Sum: '<S402>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_p;

        /* Signum: '<S402>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S402>/Sign1' */

        /* Signum: '<S402>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S402>/Sign2' */

        /* Sum: '<S402>/Add5' incorporates:
         *  Gain: '<S402>/Gain2'
         *  Product: '<S402>/Multiply4'
         *  Sum: '<S402>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S401>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S401>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S402>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - FMS_ConstB.d_p;

        /* Sum: '<S402>/Add6' */
        rtb_Add4_d = rtb_Saturation_n + FMS_ConstB.d_p;

        /* Signum: '<S402>/Sign5' incorporates:
         *  Signum: '<S402>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S402>/Sign6' */
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S402>/Sign6' */
          rtb_MathFunction_p_idx_0 = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S402>/Sign6' */
          rtb_MathFunction_p_idx_0 = rtb_Saturation_n;
        }

        /* End of Signum: '<S402>/Sign5' */

        /* Signum: '<S402>/Sign3' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S402>/Sign3' */

        /* Signum: '<S402>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S402>/Sign4' */

        /* Update for DiscreteIntegrator: '<S401>/Integrator' incorporates:
         *  Constant: '<S402>/const'
         *  Gain: '<S402>/Gain3'
         *  Product: '<S402>/Divide'
         *  Product: '<S402>/Multiply5'
         *  Product: '<S402>/Multiply6'
         *  Sum: '<S402>/Subtract4'
         *  Sum: '<S402>/Subtract5'
         *  Sum: '<S402>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_Saturation_n / FMS_ConstB.d_p -
          rtb_Gain_hc) * FMS_ConstB.Gain4_e * ((rtb_Add4_d - rtb_Add3_c) * 0.5F)
          - rtb_MathFunction_p_idx_0 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S357>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S409>/Delay'
           *  Delay: '<S410>/Delay'
           *  Delay: '<S432>/Delay'
           *  Delay: '<S432>/Delay1'
           *  DiscreteIntegrator: '<S413>/Integrator'
           *  DiscreteIntegrator: '<S413>/Integrator1'
           *  DiscreteIntegrator: '<S433>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S434>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S480>/Discrete-Time Integrator'
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
           *  ActionPort: '<S357>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S442>/Motion Status'
           *  Chart: '<S452>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S39>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Return' incorporates:
         *  ActionPort: '<S357>/Action Port'
         */
        /* RelationalOperator: '<S427>/Compare' incorporates:
         *  Constant: '<S491>/Constant'
         *  DiscreteIntegrator: '<S434>/Discrete-Time Integrator'
         *  RelationalOperator: '<S491>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* Logic: '<S432>/Logical Operator' incorporates:
         *  Delay: '<S432>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE_b);

        /* Delay: '<S432>/Delay' incorporates:
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
        /* RelationalOperator: '<S438>/Compare' incorporates:
         *  Constant: '<S438>/Constant'
         *  Delay: '<S432>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE_b = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S428>/Switch2' incorporates:
         *  Constant: '<S428>/vel'
         *  Delay: '<S432>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE_b) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Switch2_m = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Switch2_m = FMS_PARAM.MC_CRUISE_SPEED;
        }

        /* End of Switch: '<S428>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S432>/Sum' incorporates:
         *  Delay: '<S432>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

        /* Sum: '<S433>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint
          [0];

        /* Sum: '<S432>/Sum' incorporates:
         *  Delay: '<S432>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_e[1];

        /* Sum: '<S433>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_g = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S490>/Sqrt' incorporates:
         *  Math: '<S490>/Square'
         *  Sum: '<S433>/Sum'
         *  Sum: '<S490>/Sum of Elements'
         */
        rtb_Add3_c = sqrtf(rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
                           rtb_Rem_g * rtb_Rem_g);

        /* Gain: '<S433>/L1_GAIN' incorporates:
         *  Gain: '<S408>/Gain'
         */
        rtb_Saturation_n = FMS_PARAM.MC_L1_GAIN * rtb_Switch2_m;

        /* Switch: '<S433>/Switch' incorporates:
         *  Gain: '<S433>/L1_GAIN'
         *  Sum: '<S433>/Sum2'
         */
        if (rtb_Add3_c - rtb_Saturation_n >= 0.0F) {
          B = rtb_Switch2_m;
        } else {
          /* Gain: '<S433>/Gain' */
          B = 0.5F * rtb_Add3_c;

          /* Switch: '<S488>/Switch2' incorporates:
           *  Constant: '<S433>/Constant1'
           *  RelationalOperator: '<S488>/LowerRelop1'
           *  RelationalOperator: '<S488>/UpperRelop'
           *  Switch: '<S488>/Switch'
           */
          if (B > rtb_Switch2_m) {
            B = rtb_Switch2_m;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S488>/Switch' incorporates:
               *  Constant: '<S433>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S488>/Switch2' */
        }

        /* End of Switch: '<S433>/Switch' */

        /* DiscreteIntegrator: '<S433>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Switch: '<S489>/Switch2' incorporates:
         *  Constant: '<S433>/Constant2'
         *  DiscreteIntegrator: '<S433>/Acceleration_Speed'
         *  RelationalOperator: '<S489>/LowerRelop1'
         *  RelationalOperator: '<S489>/UpperRelop'
         *  Switch: '<S489>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_Switch2_m) {
          rtb_Integrator1_a = rtb_Switch2_m;
        } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
          /* Switch: '<S489>/Switch' incorporates:
           *  Constant: '<S433>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE_j;
        }

        /* End of Switch: '<S489>/Switch2' */

        /* Switch: '<S433>/Switch1' incorporates:
         *  Sum: '<S433>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Integrator1_a = B;
        }

        /* End of Switch: '<S433>/Switch1' */

        /* DiscreteIntegrator: '<S480>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRe_e !=
             0)) {
          FMS_DW.l1_heading_e = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S452>/Motion State' incorporates:
         *  Constant: '<S452>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S452>/Square'
         *  Math: '<S452>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S452>/Sqrt'
         *  Sum: '<S452>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S451>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S451>/Hold Control' incorporates:
             *  ActionPort: '<S454>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S451>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S451>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S451>/Hold Control' incorporates:
           *  ActionPort: '<S454>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S451>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S451>/Brake Control' incorporates:
           *  ActionPort: '<S453>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S451>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S451>/Move Control' incorporates:
             *  ActionPort: '<S455>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S451>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S451>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S451>/Move Control' incorporates:
           *  ActionPort: '<S455>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S451>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S451>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S442>/Motion Status' incorporates:
         *  Abs: '<S442>/Abs'
         *  Constant: '<S442>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S441>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S441>/Hold Control' incorporates:
             *  ActionPort: '<S444>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S441>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S441>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S441>/Hold Control' incorporates:
           *  ActionPort: '<S444>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S441>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S441>/Brake Control' incorporates:
           *  ActionPort: '<S443>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S441>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S441>/Move Control' incorporates:
             *  ActionPort: '<S445>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S441>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S441>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S441>/Move Control' incorporates:
           *  ActionPort: '<S445>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S441>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S441>/Switch Case' */

        /* Switch: '<S408>/Switch' incorporates:
         *  Product: '<S432>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S451>/Saturation1' */
          if (FMS_B.Merge_a[0] > FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_PARAM.MC_VEL_XY_LIM;
          } else if (FMS_B.Merge_a[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = -FMS_PARAM.MC_VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_B.Merge_a[0];
          }

          if (FMS_B.Merge_a[1] > FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_PARAM.MC_VEL_XY_LIM;
          } else if (FMS_B.Merge_a[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = -FMS_PARAM.MC_VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_B.Merge_a[1];
          }

          /* End of Saturate: '<S451>/Saturation1' */

          /* Saturate: '<S441>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.MC_VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.MC_VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S441>/Saturation1' */
        } else {
          /* SignalConversion: '<S487>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S487>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S486>/Gain' incorporates:
           *  DiscreteIntegrator: '<S480>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S480>/Add'
           */
          rtb_MathFunction_p_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S487>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S487>/Trigonometric Function1'
           */
          rtb_Gain_hc = arm_cos_f32(rtb_MathFunction_p_idx_0);
          rtb_Transpose[4] = rtb_Gain_hc;

          /* Trigonometry: '<S487>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S487>/Trigonometric Function'
           */
          rtb_Rem_g = arm_sin_f32(rtb_MathFunction_p_idx_0);

          /* Gain: '<S487>/Gain' incorporates:
           *  Trigonometry: '<S487>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Rem_g;

          /* SignalConversion: '<S487>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S487>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S487>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Rem_g;

          /* Trigonometry: '<S487>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Gain_hc;

          /* SignalConversion: '<S487>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Sum: '<S482>/Sum of Elements' incorporates:
           *  Math: '<S482>/Math Function'
           *  SignalConversion: '<S482>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Gain_hc = rtb_Add4_d * rtb_Add4_d + rtb_Subtract3_od *
            rtb_Subtract3_od;

          /* Math: '<S482>/Math Function1' incorporates:
           *  Sum: '<S482>/Sum of Elements'
           *
           * About '<S482>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain_hc < 0.0F) {
            rtb_MathFunction_p_idx_0 = -sqrtf(fabsf(rtb_Gain_hc));
          } else {
            rtb_MathFunction_p_idx_0 = sqrtf(rtb_Gain_hc);
          }

          /* End of Math: '<S482>/Math Function1' */

          /* Switch: '<S482>/Switch' incorporates:
           *  Constant: '<S482>/Constant'
           *  Product: '<S482>/Product'
           */
          if (rtb_MathFunction_p_idx_0 > 0.0F) {
            rtb_Add3_c = rtb_Add4_d;
            rtb_MathFunction_f_idx_1 = rtb_Subtract3_od;
          } else {
            rtb_Add3_c = 0.0F;
            rtb_MathFunction_f_idx_1 = 0.0F;
            rtb_MathFunction_p_idx_0 = 1.0F;
          }

          /* End of Switch: '<S482>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S435>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Rem_g = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S435>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Gain_hc = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_p_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S435>/Divide' incorporates:
           *  Math: '<S436>/Square'
           *  Math: '<S437>/Square'
           *  Sqrt: '<S436>/Sqrt'
           *  Sqrt: '<S437>/Sqrt'
           *  Sum: '<S435>/Sum'
           *  Sum: '<S435>/Sum1'
           *  Sum: '<S436>/Sum of Elements'
           *  Sum: '<S437>/Sum of Elements'
           */
          rtb_Gain_hc = sqrtf(rtb_Gain_hc * rtb_Gain_hc +
                              rtb_MathFunction_p_idx_1 *
                              rtb_MathFunction_p_idx_1) / sqrtf
            (rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 + rtb_Rem_g *
             rtb_Rem_g);

          /* Saturate: '<S435>/Saturation' */
          if (rtb_Gain_hc > 1.0F) {
            rtb_Gain_hc = 1.0F;
          } else {
            if (rtb_Gain_hc < 0.0F) {
              rtb_Gain_hc = 0.0F;
            }
          }

          /* End of Saturate: '<S435>/Saturation' */

          /* Product: '<S478>/Multiply2' incorporates:
           *  Product: '<S482>/Divide'
           */
          rtb_Add3_c = rtb_Add3_c / rtb_MathFunction_p_idx_0 * rtb_Integrator1_a;
          rtb_MathFunction_f_idx_1 = rtb_MathFunction_f_idx_1 /
            rtb_MathFunction_p_idx_0 * rtb_Integrator1_a;

          /* Product: '<S432>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_MathFunction_f_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Add3_c;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S425>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S435>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S425>/Sum2'
           *  Sum: '<S435>/Add'
           *  Sum: '<S435>/Subtract'
           */
          rtb_Add3_c = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Gain_hc +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.MC_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S425>/Saturation1' incorporates:
           *  Product: '<S432>/Multiply'
           */
          if (rtb_Add3_c > FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.MC_VEL_Z_LIM;
          } else if (rtb_Add3_c < -FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.MC_VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Add3_c;
          }

          /* End of Saturate: '<S425>/Saturation1' */
        }

        /* End of Switch: '<S408>/Switch' */

        /* Delay: '<S410>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S413>/Integrator1' incorporates:
         *  Delay: '<S410>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S417>/Rem' incorporates:
         *  Constant: '<S417>/Constant1'
         *  DiscreteIntegrator: '<S413>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S412>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S417>/Switch' incorporates:
         *  Abs: '<S417>/Abs'
         *  Constant: '<S417>/Constant'
         *  Constant: '<S418>/Constant'
         *  Product: '<S417>/Multiply'
         *  RelationalOperator: '<S418>/Compare'
         *  Sum: '<S417>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S417>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S417>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S417>/Switch' */

        /* Gain: '<S412>/Gain2' */
        B *= FMS_PARAM.MC_YAW_P;

        /* Saturate: '<S412>/Saturation' */
        if (B > FMS_PARAM.MC_YAWRATE_LIM) {
          B = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (B < -FMS_PARAM.MC_YAWRATE_LIM) {
            B = -FMS_PARAM.MC_YAWRATE_LIM;
          }
        }

        /* End of Saturate: '<S412>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S357>/Bus Assignment1'
         *  Constant: '<S357>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S357>/Bus Assignment1' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Sum: '<S484>/Sum of Elements' incorporates:
         *  Math: '<S484>/Math Function'
         *  SignalConversion: '<S484>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Gain_hc = rtb_Subtract3_od * rtb_Subtract3_od + rtb_Add4_d *
          rtb_Add4_d;

        /* Math: '<S484>/Math Function1' incorporates:
         *  Sum: '<S484>/Sum of Elements'
         *
         * About '<S484>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S484>/Math Function1' */

        /* Switch: '<S484>/Switch' incorporates:
         *  Constant: '<S484>/Constant'
         *  Product: '<S484>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Subtract3_od;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Add4_d;
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S484>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S472>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S472>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S470>/Sum of Elements'
         */
        rtb_Gain_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S472>/Math Function1' incorporates:
         *  Sum: '<S472>/Sum of Elements'
         *
         * About '<S472>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S472>/Math Function1' */

        /* Switch: '<S472>/Switch' incorporates:
         *  Constant: '<S472>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S472>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract3_od = FMS_U.INS_Out.vn;
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_Subtract3_od = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S472>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S432>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S485>/Sum of Elements' incorporates:
         *  Math: '<S485>/Math Function'
         *  Sum: '<S432>/Sum1'
         */
        rtb_Add4_d = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S485>/Math Function1' incorporates:
         *  Sum: '<S485>/Sum of Elements'
         *
         * About '<S485>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S485>/Math Function1' */

        /* Switch: '<S485>/Switch' incorporates:
         *  Constant: '<S485>/Constant'
         *  Product: '<S485>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S485>/Switch' */

        /* Delay: '<S409>/Delay' incorporates:
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
        /* Sum: '<S357>/Sum' incorporates:
         *  Delay: '<S409>/Delay'
         *  MATLAB Function: '<S430>/OutRegionRegWP'
         *  MATLAB Function: '<S430>/SearchL1RefWP'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.Delay_DSTATE_p[0];
        rtb_Rem_g = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S424>/Sum of Elements' incorporates:
         *  Math: '<S424>/Math Function'
         *  Sum: '<S357>/Sum'
         */
        rtb_Add4_d = rtb_Rem_g * rtb_Rem_g + rtb_MathFunction_h_idx_1 *
          rtb_MathFunction_h_idx_1;

        /* Math: '<S424>/Math Function1' incorporates:
         *  Sum: '<S424>/Sum of Elements'
         *
         * About '<S424>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S424>/Math Function1' */

        /* Switch: '<S424>/Switch' incorporates:
         *  Constant: '<S424>/Constant'
         *  Product: '<S424>/Product'
         *  Sum: '<S357>/Sum'
         */
        if (B > 0.0F) {
          rtb_Switch_f3_idx_0 = rtb_Rem_g;
          rtb_Switch_f3_idx_1 = rtb_MathFunction_h_idx_1;
          rtb_Switch_f3_idx_2 = B;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S424>/Switch' */

        /* Product: '<S472>/Divide' */
        rtb_Sum_ff[0] = rtb_Subtract3_od / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S475>/Sum of Elements' incorporates:
         *  Math: '<S475>/Math Function'
         *  SignalConversion: '<S475>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add4_d = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] * rtb_Sum_ff
          [0];

        /* Math: '<S475>/Math Function1' incorporates:
         *  Sum: '<S475>/Sum of Elements'
         *
         * About '<S475>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S475>/Math Function1' */

        /* Switch: '<S475>/Switch' incorporates:
         *  Constant: '<S475>/Constant'
         *  Product: '<S475>/Product'
         */
        if (B > 0.0F) {
          rtb_Subtract3_od = rtb_Sum_ff[1];
          rtb_MathFunction_f_idx_1 = rtb_Sum_ff[0];
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_Subtract3_od = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S475>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S430>/NearbyRefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, rtb_Saturation_n, rtb_Sum_ff,
                        &rtb_MathFunction_h_idx_0);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S430>/SearchL1RefWP' incorporates:
         *  Delay: '<S409>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Add4_d = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_Rem_g * rtb_Rem_g;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        B = (rtb_MathFunction_h_idx_1 * (FMS_DW.Delay_DSTATE_p[0] -
              FMS_U.INS_Out.x_R) + rtb_Rem_g * (FMS_DW.Delay_DSTATE_p[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     rtb_Saturation_n * rtb_Saturation_n) * (4.0F * rtb_Add4_d);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_MathFunction_p_idx_0 = 0.0F;
        rtb_MathFunction_p_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Add4_d);
          rtb_Add4_d = (-B - u1_tmp) / (2.0F * rtb_Add4_d);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Add4_d >= 0.0F) && (rtb_Add4_d <=
               1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Add4_d);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Add4_d >= 0.0F) && (rtb_Add4_d <= 1.0F)) {
              rtb_Add3_c = rtb_Add4_d;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Add4_d);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_p_idx_0 = rtb_MathFunction_h_idx_1 * rtb_Add3_c +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_p_idx_1 = rtb_Rem_g * rtb_Add3_c +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S430>/OutRegionRegWP' incorporates:
         *  Delay: '<S409>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) * rtb_Rem_g
                      + (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0]) *
                      rtb_MathFunction_h_idx_1) / (rtb_MathFunction_h_idx_1 *
          rtb_MathFunction_h_idx_1 + rtb_Rem_g * rtb_Rem_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Add4_d <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Add4_d >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          D = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          D = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          D = rtb_Add4_d * rtb_MathFunction_h_idx_1 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S430>/Switch1' incorporates:
         *  Constant: '<S465>/Constant'
         *  RelationalOperator: '<S465>/Compare'
         */
        if (rtb_MathFunction_h_idx_0 <= 0.0F) {
          /* Switch: '<S430>/Switch' incorporates:
           *  Constant: '<S464>/Constant'
           *  MATLAB Function: '<S430>/SearchL1RefWP'
           *  RelationalOperator: '<S464>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0;
            rtb_Sum_ff[1] = rtb_MathFunction_p_idx_1;
          } else {
            rtb_Sum_ff[0] = D;

            /* MATLAB Function: '<S430>/OutRegionRegWP' incorporates:
             *  Delay: '<S409>/Delay'
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_a4) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Add4_d * rtb_Rem_g + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S430>/Switch' */
        }

        /* End of Switch: '<S430>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S431>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_g = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Rem_g;
        rtb_Add3_c = rtb_Rem_g * rtb_Rem_g;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S431>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S473>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_g = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S473>/Math Function' incorporates:
         *  Math: '<S471>/Square'
         */
        rtb_Add4_d = rtb_Rem_g * rtb_Rem_g;

        /* Sum: '<S473>/Sum of Elements' incorporates:
         *  Math: '<S473>/Math Function'
         */
        rtb_MathFunction_p_idx_0 = rtb_Add4_d + rtb_Add3_c;

        /* Math: '<S473>/Math Function1' incorporates:
         *  Sum: '<S473>/Sum of Elements'
         *
         * About '<S473>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_MathFunction_p_idx_0));
        } else {
          B = sqrtf(rtb_MathFunction_p_idx_0);
        }

        /* End of Math: '<S473>/Math Function1' */

        /* Switch: '<S473>/Switch' incorporates:
         *  Constant: '<S473>/Constant'
         *  Product: '<S473>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Rem_g;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S473>/Switch' */

        /* Product: '<S473>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S476>/Sum of Elements' incorporates:
         *  Math: '<S476>/Math Function'
         *  SignalConversion: '<S476>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction_p_idx_0 = rtb_MathFunction_h_idx_1 *
          rtb_MathFunction_h_idx_1 + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Math: '<S476>/Math Function1' incorporates:
         *  Sum: '<S476>/Sum of Elements'
         *
         * About '<S476>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_MathFunction_p_idx_0));
        } else {
          B = sqrtf(rtb_MathFunction_p_idx_0);
        }

        /* End of Math: '<S476>/Math Function1' */

        /* Switch: '<S476>/Switch' incorporates:
         *  Constant: '<S476>/Constant'
         *  Product: '<S476>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S476>/Switch' */

        /* Product: '<S476>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S471>/Square' */
        rtb_Add3_c = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S424>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S485>/Divide' */
        D = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S484>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_Subtract3_od / rtb_MathFunction_f_idx_2;

        /* Product: '<S476>/Divide' incorporates:
         *  Product: '<S475>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S475>/Divide' */
        rtb_Rem_g = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S424>/Divide' */
        rtb_MathFunction_p_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S485>/Divide' */
        rtb_Subtract3_od = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S484>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S483>/Subtract' incorporates:
         *  Product: '<S483>/Multiply'
         *  Product: '<S483>/Multiply1'
         */
        B = D * rtb_MathFunction_f_idx_1 - rtb_Subtract3_od *
          rtb_Switch_mp_idx_0;

        /* Signum: '<S479>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S479>/Sign1' */

        /* Switch: '<S479>/Switch2' incorporates:
         *  Constant: '<S479>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S479>/Switch2' */

        /* DotProduct: '<S479>/Dot Product' */
        rtb_Subtract3_od = rtb_Switch_mp_idx_0 * D + rtb_MathFunction_f_idx_1 *
          rtb_Subtract3_od;

        /* Trigonometry: '<S479>/Acos' incorporates:
         *  DotProduct: '<S479>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S479>/Multiply' incorporates:
         *  Trigonometry: '<S479>/Acos'
         */
        B *= acosf(rtb_Subtract3_od);

        /* Abs: '<S432>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S477>/Compare' incorporates:
         *  Constant: '<S477>/Constant'
         *  Delay: '<S432>/Delay1'
         */
        FMS_DW.Delay1_DSTATE_b = (B > 1.57079637F);

        /* Sqrt: '<S470>/Sqrt' */
        rtb_Subtract3_od = sqrtf(rtb_Gain_hc);

        /* Math: '<S431>/Square' */
        rtb_MathFunction_f_idx_1 = rtb_Subtract3_od * rtb_Subtract3_od;

        /* Sum: '<S474>/Subtract' incorporates:
         *  Product: '<S474>/Multiply'
         *  Product: '<S474>/Multiply1'
         */
        rtb_Subtract3_od = rtb_MathFunction_h_idx_0 * rtb_Rem_g -
          rtb_MathFunction_h_idx_1 * rtb_Sum_ff[0];

        /* Signum: '<S469>/Sign1' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S469>/Sign1' */

        /* Switch: '<S469>/Switch2' incorporates:
         *  Constant: '<S469>/Constant4'
         */
        if (rtb_Subtract3_od == 0.0F) {
          rtb_Subtract3_od = 1.0F;
        }

        /* End of Switch: '<S469>/Switch2' */

        /* DotProduct: '<S469>/Dot Product' */
        rtb_Rem_g = rtb_Sum_ff[0] * rtb_MathFunction_h_idx_0 + rtb_Rem_g *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S469>/Acos' incorporates:
         *  DotProduct: '<S469>/Dot Product'
         */
        if (rtb_Rem_g > 1.0F) {
          rtb_Rem_g = 1.0F;
        } else {
          if (rtb_Rem_g < -1.0F) {
            rtb_Rem_g = -1.0F;
          }
        }

        /* Product: '<S469>/Multiply' incorporates:
         *  Trigonometry: '<S469>/Acos'
         */
        rtb_Subtract3_od *= acosf(rtb_Rem_g);

        /* Saturate: '<S431>/Saturation' */
        if (rtb_Subtract3_od > 1.57079637F) {
          rtb_Subtract3_od = 1.57079637F;
        } else {
          if (rtb_Subtract3_od < -1.57079637F) {
            rtb_Subtract3_od = -1.57079637F;
          }
        }

        /* End of Saturate: '<S431>/Saturation' */

        /* Switch: '<S481>/Switch2' incorporates:
         *  Constant: '<S432>/Constant1'
         *  RelationalOperator: '<S481>/LowerRelop1'
         *  RelationalOperator: '<S481>/UpperRelop'
         *  Switch: '<S481>/Switch'
         */
        if (rtb_Integrator1_a > rtb_Switch2_m) {
          rtb_Integrator1_a = rtb_Switch2_m;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S481>/Switch' incorporates:
             *  Constant: '<S432>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S481>/Switch2' */

        /* Product: '<S432>/Divide1' incorporates:
         *  Constant: '<S431>/Constant'
         *  Gain: '<S431>/Gain'
         *  MinMax: '<S431>/Max'
         *  MinMax: '<S431>/Min'
         *  Product: '<S431>/Divide'
         *  Product: '<S431>/Multiply1'
         *  Sqrt: '<S471>/Sqrt'
         *  Sum: '<S471>/Sum of Elements'
         *  Trigonometry: '<S431>/Sin'
         */
        rtb_Subtract3_od = 2.0F * rtb_MathFunction_f_idx_1 * arm_sin_f32
          (rtb_Subtract3_od) / fminf(rtb_Saturation_n, fmaxf(sqrtf(rtb_Add4_d +
          rtb_Add3_c), 0.5F)) / rtb_Integrator1_a;

        /* Saturate: '<S432>/Saturation' */
        if (rtb_Subtract3_od > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else if (rtb_Subtract3_od < -0.314159274F) {
          rtb_Saturation_n = -0.314159274F;
        } else {
          rtb_Saturation_n = rtb_Subtract3_od;
        }

        /* End of Saturate: '<S432>/Saturation' */

        /* Sum: '<S422>/Subtract' incorporates:
         *  Product: '<S422>/Multiply'
         *  Product: '<S422>/Multiply1'
         */
        rtb_Subtract3_od = rtb_MathFunction_p_idx_0 * FMS_ConstB.Divide[1] -
          rtb_MathFunction_p_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S411>/Sign1' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S411>/Sign1' */

        /* Switch: '<S411>/Switch2' incorporates:
         *  Constant: '<S411>/Constant4'
         */
        if (rtb_Subtract3_od == 0.0F) {
          rtb_Subtract3_od = 1.0F;
        }

        /* End of Switch: '<S411>/Switch2' */

        /* DotProduct: '<S411>/Dot Product' */
        rtb_Add3_c = FMS_ConstB.Divide[0] * rtb_MathFunction_p_idx_0 +
          FMS_ConstB.Divide[1] * rtb_MathFunction_p_idx_1;

        /* Trigonometry: '<S411>/Acos' incorporates:
         *  DotProduct: '<S411>/Dot Product'
         */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < -1.0F) {
            rtb_Add3_c = -1.0F;
          }
        }

        /* Product: '<S411>/Multiply' incorporates:
         *  Trigonometry: '<S411>/Acos'
         */
        rtb_Subtract3_od *= acosf(rtb_Add3_c);

        /* Math: '<S414>/Rem' incorporates:
         *  Constant: '<S414>/Constant1'
         *  Delay: '<S410>/Delay'
         *  Sum: '<S410>/Sum2'
         */
        B = rt_remf(rtb_Subtract3_od - FMS_DW.Delay_DSTATE_a, 6.28318548F);

        /* Switch: '<S414>/Switch' incorporates:
         *  Abs: '<S414>/Abs'
         *  Constant: '<S414>/Constant'
         *  Constant: '<S420>/Constant'
         *  Product: '<S414>/Multiply'
         *  RelationalOperator: '<S420>/Compare'
         *  Sum: '<S414>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S414>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S414>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S414>/Switch' */

        /* Sum: '<S410>/Sum' incorporates:
         *  Delay: '<S410>/Delay'
         */
        rtb_Add3_c = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S419>/Multiply1' incorporates:
         *  Constant: '<S419>/const1'
         *  DiscreteIntegrator: '<S413>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S419>/Add' incorporates:
         *  DiscreteIntegrator: '<S413>/Integrator1'
         *  Sum: '<S413>/Subtract'
         */
        rtb_Add4_d = (FMS_DW.Integrator1_DSTATE_e - rtb_Add3_c) + B;

        /* Signum: '<S419>/Sign' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Add4_d;
        }

        /* End of Signum: '<S419>/Sign' */

        /* Sum: '<S419>/Add2' incorporates:
         *  Abs: '<S419>/Abs'
         *  Gain: '<S419>/Gain'
         *  Gain: '<S419>/Gain1'
         *  Product: '<S419>/Multiply2'
         *  Product: '<S419>/Multiply3'
         *  Sqrt: '<S419>/Sqrt'
         *  Sum: '<S419>/Add1'
         *  Sum: '<S419>/Subtract'
         */
        rtb_MathFunction_h_idx_0 = (sqrtf((8.0F * fabsf(rtb_Add4_d) +
          FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Add3_c + B;

        /* Sum: '<S419>/Add4' */
        rtb_Switch2_m = (rtb_Add4_d - rtb_MathFunction_h_idx_0) + B;

        /* Sum: '<S419>/Add3' */
        rtb_Add3_c = rtb_Add4_d + FMS_ConstB.d_l;

        /* Sum: '<S419>/Subtract1' */
        rtb_Add4_d -= FMS_ConstB.d_l;

        /* Signum: '<S419>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S419>/Sign1' */

        /* Signum: '<S419>/Sign2' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S419>/Sign2' */

        /* Sum: '<S419>/Add5' incorporates:
         *  Gain: '<S419>/Gain2'
         *  Product: '<S419>/Multiply4'
         *  Sum: '<S419>/Subtract2'
         */
        rtb_MathFunction_h_idx_0 += (rtb_Add3_c - rtb_Add4_d) * 0.5F *
          rtb_Switch2_m;

        /* Sum: '<S419>/Add6' */
        rtb_Add3_c = rtb_MathFunction_h_idx_0 + FMS_ConstB.d_l;

        /* Sum: '<S419>/Subtract3' */
        rtb_Add4_d = rtb_MathFunction_h_idx_0 - FMS_ConstB.d_l;

        /* Product: '<S419>/Divide' */
        rtb_Switch2_m = rtb_MathFunction_h_idx_0 / FMS_ConstB.d_l;

        /* Signum: '<S419>/Sign5' incorporates:
         *  Signum: '<S419>/Sign6'
         */
        if (rtb_MathFunction_h_idx_0 < 0.0F) {
          rtb_Integrator1_a = -1.0F;

          /* Signum: '<S419>/Sign6' */
          rtb_Gain_hc = -1.0F;
        } else if (rtb_MathFunction_h_idx_0 > 0.0F) {
          rtb_Integrator1_a = 1.0F;

          /* Signum: '<S419>/Sign6' */
          rtb_Gain_hc = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_MathFunction_h_idx_0;

          /* Signum: '<S419>/Sign6' */
          rtb_Gain_hc = rtb_MathFunction_h_idx_0;
        }

        /* End of Signum: '<S419>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S410>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Subtract3_od -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S415>/Rem' incorporates:
         *  Constant: '<S415>/Constant1'
         */
        rtb_MathFunction_h_idx_0 = rt_remf(rtb_Subtract3_od, 6.28318548F);

        /* Switch: '<S415>/Switch' incorporates:
         *  Abs: '<S415>/Abs'
         *  Constant: '<S415>/Constant'
         *  Constant: '<S421>/Constant'
         *  Product: '<S415>/Multiply'
         *  RelationalOperator: '<S421>/Compare'
         *  Sum: '<S415>/Add'
         */
        if (fabsf(rtb_MathFunction_h_idx_0) > 3.14159274F) {
          /* Signum: '<S415>/Sign' */
          if (rtb_MathFunction_h_idx_0 < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else if (rtb_MathFunction_h_idx_0 > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          } else {
            rtb_Subtract3_od = rtb_MathFunction_h_idx_0;
          }

          /* End of Signum: '<S415>/Sign' */
          rtb_MathFunction_h_idx_0 -= 6.28318548F * rtb_Subtract3_od;
        }

        /* End of Switch: '<S415>/Switch' */

        /* Abs: '<S408>/Abs' */
        rtb_MathFunction_h_idx_0 = fabsf(rtb_MathFunction_h_idx_0);

        /* Update for DiscreteIntegrator: '<S434>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S426>/Constant'
         *  RelationalOperator: '<S426>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_m = (uint8_T)((uint32_T)
          (rtb_MathFunction_h_idx_0 <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S434>/Discrete-Time Integrator' */

        /* Update for Delay: '<S432>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S433>/Acceleration_Speed' incorporates:
         *  Constant: '<S433>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.MC_CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S480>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Saturation_n;
        FMS_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S410>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S413>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S413>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S409>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S419>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S419>/Sign3' */

        /* Signum: '<S419>/Sign4' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S419>/Sign4' */

        /* Update for DiscreteIntegrator: '<S413>/Integrator' incorporates:
         *  Constant: '<S419>/const'
         *  Gain: '<S419>/Gain3'
         *  Product: '<S419>/Multiply5'
         *  Product: '<S419>/Multiply6'
         *  Sum: '<S419>/Subtract4'
         *  Sum: '<S419>/Subtract5'
         *  Sum: '<S419>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Switch2_m - rtb_Integrator1_a) *
          FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Add4_d) * 0.5F) - rtb_Gain_hc *
          1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.MC_YAWRATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.MC_YAWRATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.MC_YAWRATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S413>/Integrator' */
        /* End of Outputs for SubSystem: '<S39>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S39>/Hold' incorporates:
           *  ActionPort: '<S355>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S364>/Motion Status'
           *  Chart: '<S374>/Motion State'
           *  Chart: '<S386>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S39>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Hold' incorporates:
         *  ActionPort: '<S355>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S364>/Motion Status' incorporates:
         *  Abs: '<S364>/Abs'
         *  Constant: '<S364>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S374>/Motion State' incorporates:
         *  Abs: '<S374>/Abs'
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

        /* End of Chart: '<S374>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S386>/Motion State' incorporates:
         *  Constant: '<S386>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S386>/Square'
         *  Math: '<S386>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S386>/Sqrt'
         *  Sum: '<S386>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S385>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S385>/Hold Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S385>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S385>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S385>/Hold Control' incorporates:
           *  ActionPort: '<S388>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S385>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S385>/Brake Control' incorporates:
           *  ActionPort: '<S387>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S385>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S385>/Move Control' incorporates:
             *  ActionPort: '<S389>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S385>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S385>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S385>/Move Control' incorporates:
           *  ActionPort: '<S389>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S385>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S385>/Switch Case' */

        /* SwitchCase: '<S363>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S363>/Hold Control' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S363>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S363>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S363>/Hold Control' incorporates:
           *  ActionPort: '<S366>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S363>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S363>/Brake Control' incorporates:
           *  ActionPort: '<S365>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S363>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S363>/Move Control' incorporates:
             *  ActionPort: '<S367>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S363>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S363>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S363>/Move Control' incorporates:
           *  ActionPort: '<S367>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S363>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S363>/Switch Case' */

        /* SwitchCase: '<S373>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S373>/Hold Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S373>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S373>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S373>/Hold Control' incorporates:
           *  ActionPort: '<S376>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S373>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S373>/Brake Control' incorporates:
           *  ActionPort: '<S375>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S373>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S373>/Move Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S373>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S373>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S373>/Move Control' incorporates:
           *  ActionPort: '<S377>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S373>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S373>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S355>/Bus Assignment'
         *  Constant: '<S355>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S355>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S373>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S373>/Saturation' */

        /* Saturate: '<S385>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S385>/Saturation1' */

        /* Saturate: '<S363>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.MC_VEL_Z_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.MC_VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.MC_VEL_Z_LIM) {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.MC_VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S355>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S363>/Saturation1' */
        /* End of Outputs for SubSystem: '<S39>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
         *  ActionPort: '<S359>/Action Port'
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
       *  Math: '<S223>/Math Function'
       *  Product: '<S225>/Divide'
       *  Sum: '<S175>/Subtract'
       *  Sum: '<S245>/Sum1'
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
        /* Disable for SwitchCase: '<S201>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S191>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S150>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S37>/Offboard' incorporates:
         *  ActionPort: '<S151>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S332>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S335>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S336>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S336>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S336>/Multiply1' incorporates:
         *  Product: '<S336>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S336>/Divide' incorporates:
         *  Constant: '<S336>/Constant'
         *  Constant: '<S336>/R'
         *  Sqrt: '<S336>/Sqrt'
         *  Sum: '<S336>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S336>/Product3' incorporates:
         *  Constant: '<S336>/Constant1'
         *  Product: '<S336>/Multiply1'
         *  Sum: '<S336>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S336>/Multiply2' incorporates:
         *  Trigonometry: '<S336>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S335>/Sum' incorporates:
         *  Gain: '<S332>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S340>/Abs' incorporates:
         *  Abs: '<S343>/Abs1'
         *  Switch: '<S340>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S340>/Switch1' incorporates:
         *  Abs: '<S340>/Abs'
         *  Bias: '<S340>/Bias2'
         *  Bias: '<S340>/Bias3'
         *  Constant: '<S337>/Constant'
         *  Constant: '<S337>/Constant1'
         *  Constant: '<S342>/Constant'
         *  Gain: '<S340>/Gain1'
         *  Product: '<S340>/Multiply'
         *  RelationalOperator: '<S342>/Compare'
         *  Switch: '<S337>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S343>/Switch1' incorporates:
           *  Bias: '<S343>/Bias2'
           *  Bias: '<S343>/Bias3'
           *  Constant: '<S343>/Constant'
           *  Constant: '<S344>/Constant'
           *  Math: '<S343>/Math Function'
           *  RelationalOperator: '<S344>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S343>/Switch1' */

          /* Signum: '<S340>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S340>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S337>/Sum' incorporates:
         *  Gain: '<S332>/Gain1'
         *  Gain: '<S332>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S335>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S335>/Multiply' incorporates:
         *  Gain: '<S335>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S339>/Switch1' incorporates:
         *  Abs: '<S339>/Abs1'
         *  Bias: '<S339>/Bias2'
         *  Bias: '<S339>/Bias3'
         *  Constant: '<S339>/Constant'
         *  Constant: '<S341>/Constant'
         *  Math: '<S339>/Math Function'
         *  RelationalOperator: '<S341>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S339>/Switch1' */

        /* Product: '<S335>/Multiply' incorporates:
         *  Gain: '<S335>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S307>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S311>/Multiply1'
         *  Product: '<S312>/Multiply3'
         *  Product: '<S313>/Multiply1'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S322>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S322>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S322>/Trigonometric Function3' incorporates:
           *  Gain: '<S321>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S322>/Gain' incorporates:
           *  Gain: '<S321>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S322>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S322>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S322>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S322>/Trigonometric Function' incorporates:
           *  Gain: '<S321>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S322>/Trigonometric Function1' incorporates:
           *  Gain: '<S321>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  DataTypeConversion: '<S332>/Data Type Conversion1'
           *  Product: '<S338>/Multiply1'
           *  Product: '<S338>/Multiply2'
           *  RelationalOperator: '<S334>/Compare'
           *  S-Function (sfix_bitop): '<S331>/lat_cmd valid'
           *  Sum: '<S338>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S311>/Multiply' incorporates:
           *  Constant: '<S319>/Constant'
           *  Constant: '<S320>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S310>/Logical Operator'
           *  RelationalOperator: '<S319>/Compare'
           *  RelationalOperator: '<S320>/Compare'
           *  S-Function (sfix_bitop): '<S310>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S311>/Sum1'
           */
          rtb_Switch2_m = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;

          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  DataTypeConversion: '<S332>/Data Type Conversion1'
           *  Product: '<S338>/Multiply3'
           *  Product: '<S338>/Multiply4'
           *  RelationalOperator: '<S334>/Compare'
           *  S-Function (sfix_bitop): '<S331>/lon_cmd valid'
           *  Sum: '<S338>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S311>/Multiply' incorporates:
           *  Constant: '<S319>/Constant'
           *  Constant: '<S320>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S310>/Logical Operator'
           *  RelationalOperator: '<S319>/Compare'
           *  RelationalOperator: '<S320>/Compare'
           *  S-Function (sfix_bitop): '<S310>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S311>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;

          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  DataTypeConversion: '<S332>/Data Type Conversion'
           *  DataTypeConversion: '<S332>/Data Type Conversion1'
           *  Gain: '<S332>/Gain2'
           *  Gain: '<S335>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S334>/Compare'
           *  S-Function (sfix_bitop): '<S331>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S335>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S311>/Multiply' incorporates:
           *  Constant: '<S319>/Constant'
           *  Constant: '<S320>/Constant'
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S310>/Logical Operator'
           *  RelationalOperator: '<S319>/Compare'
           *  RelationalOperator: '<S320>/Compare'
           *  S-Function (sfix_bitop): '<S310>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S311>/Sum1'
           */
          rtb_MathFunction_f_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 1:
          /* SignalConversion: '<S330>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iy[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iy[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iy[2];

          /* SignalConversion: '<S330>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S330>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S330>/Trigonometric Function3' incorporates:
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S330>/Gain' incorporates:
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S330>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S330>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S330>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S330>/Trigonometric Function' incorporates:
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S330>/Trigonometric Function1' incorporates:
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  DataTypeConversion: '<S332>/Data Type Conversion1'
           *  Product: '<S338>/Multiply1'
           *  Product: '<S338>/Multiply2'
           *  RelationalOperator: '<S334>/Compare'
           *  S-Function (sfix_bitop): '<S331>/lat_cmd valid'
           *  Sum: '<S338>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S313>/Multiply' incorporates:
           *  Constant: '<S319>/Constant'
           *  Constant: '<S320>/Constant'
           *  DataStoreRead: '<S313>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S310>/Logical Operator'
           *  RelationalOperator: '<S319>/Compare'
           *  RelationalOperator: '<S320>/Compare'
           *  S-Function (sfix_bitop): '<S310>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S313>/Sum1'
           */
          rtb_Switch2_m = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? (rtb_Saturation_n -
            FMS_U.INS_Out.x_R) + FMS_DW.home[0] : 0.0F;

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  DataTypeConversion: '<S332>/Data Type Conversion1'
           *  Product: '<S338>/Multiply3'
           *  Product: '<S338>/Multiply4'
           *  RelationalOperator: '<S334>/Compare'
           *  S-Function (sfix_bitop): '<S331>/lon_cmd valid'
           *  Sum: '<S338>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S313>/Multiply' incorporates:
           *  Constant: '<S319>/Constant'
           *  Constant: '<S320>/Constant'
           *  DataStoreRead: '<S313>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S310>/Logical Operator'
           *  RelationalOperator: '<S319>/Compare'
           *  RelationalOperator: '<S320>/Compare'
           *  S-Function (sfix_bitop): '<S310>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S313>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? (rtb_Saturation_n -
            FMS_U.INS_Out.y_R) + FMS_DW.home[1] : 0.0F;

          /* Switch: '<S314>/Switch' incorporates:
           *  Constant: '<S334>/Constant'
           *  DataTypeConversion: '<S332>/Data Type Conversion'
           *  DataTypeConversion: '<S332>/Data Type Conversion1'
           *  Gain: '<S332>/Gain2'
           *  Gain: '<S335>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S334>/Compare'
           *  S-Function (sfix_bitop): '<S331>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S335>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S313>/Multiply' incorporates:
           *  Constant: '<S319>/Constant'
           *  Constant: '<S320>/Constant'
           *  DataStoreRead: '<S313>/Data Store Read'
           *  Gain: '<S315>/Gain'
           *  Gain: '<S328>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S310>/Logical Operator'
           *  RelationalOperator: '<S319>/Compare'
           *  RelationalOperator: '<S320>/Compare'
           *  S-Function (sfix_bitop): '<S310>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S313>/Sum1'
           */
          rtb_MathFunction_f_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? (rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R)) + -FMS_DW.home[2] : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 2:
          /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S326>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S326>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S312>/Data Store Read'
           *  Gain: '<S324>/Gain'
           *  Trigonometry: '<S326>/Trigonometric Function1'
           */
          rtb_Gain_hc = arm_cos_f32(-FMS_DW.home[3]);
          rtb_Transpose[4] = rtb_Gain_hc;

          /* Trigonometry: '<S326>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S312>/Data Store Read'
           *  Gain: '<S324>/Gain'
           *  Trigonometry: '<S326>/Trigonometric Function'
           */
          rtb_Rem_g = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S326>/Gain' incorporates:
           *  Trigonometry: '<S326>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Rem_g;

          /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S326>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S326>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Rem_g;

          /* Trigonometry: '<S326>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Gain_hc;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_ny[0];

          /* SignalConversion: '<S327>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_ny[1];

          /* SignalConversion: '<S327>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_ny[2];

          /* SignalConversion: '<S327>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S327>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S327>/Constant4'
           */
          rtb_VectorConcatenate_m[5] = 0.0F;

          /* Gain: '<S325>/Gain' incorporates:
           *  DataStoreRead: '<S312>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S312>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S327>/Trigonometric Function3' incorporates:
           *  Gain: '<S325>/Gain'
           *  Trigonometry: '<S327>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(rtb_Add3_c);
          rtb_VectorConcatenate_m[4] = rtb_Saturation_n;

          /* Trigonometry: '<S327>/Trigonometric Function2' incorporates:
           *  Gain: '<S325>/Gain'
           *  Trigonometry: '<S327>/Trigonometric Function'
           */
          rtb_Add3_c = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S327>/Gain' incorporates:
           *  Trigonometry: '<S327>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_m[3] = -rtb_Add3_c;

          /* SignalConversion: '<S327>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S327>/Constant3'
           */
          rtb_VectorConcatenate_m[2] = 0.0F;

          /* Trigonometry: '<S327>/Trigonometric Function' */
          rtb_VectorConcatenate_m[1] = rtb_Add3_c;

          /* Trigonometry: '<S327>/Trigonometric Function1' */
          rtb_VectorConcatenate_m[0] = rtb_Saturation_n;

          /* RelationalOperator: '<S334>/Compare' incorporates:
           *  Constant: '<S334>/Constant'
           *  S-Function (sfix_bitop): '<S331>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S331>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S331>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S332>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S332>/Data Type Conversion'
           *  Gain: '<S332>/Gain2'
           *  Gain: '<S335>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S338>/Multiply1'
           *  Product: '<S338>/Multiply2'
           *  Product: '<S338>/Multiply3'
           *  Product: '<S338>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S335>/Sum1'
           *  Sum: '<S338>/Sum2'
           *  Sum: '<S338>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S314>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* Sum: '<S312>/Sum' incorporates:
           *  DataStoreRead: '<S312>/Data Store Read'
           *  Gain: '<S315>/Gain'
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Switch2_m = FMS_U.INS_Out.x_R - FMS_DW.home[0];
          rtb_Integrator1_a = FMS_U.INS_Out.y_R - FMS_DW.home[1];
          rtb_MathFunction_f_idx_1 = -FMS_U.INS_Out.h_R - (-FMS_DW.home[2]);

          /* RelationalOperator: '<S319>/Compare' incorporates:
           *  Constant: '<S319>/Constant'
           *  S-Function (sfix_bitop): '<S310>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S320>/Compare' incorporates:
           *  Constant: '<S320>/Constant'
           *  S-Function (sfix_bitop): '<S310>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S312>/Sum2' incorporates:
             *  Product: '<S312>/Multiply2'
             *  Switch: '<S314>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Product: '<S312>/Multiply' incorporates:
             *  Logic: '<S310>/Logical Operator'
             *  Product: '<S312>/Multiply2'
             *  Sum: '<S312>/Sum'
             *  Sum: '<S312>/Sum2'
             */
            tmp_3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Saturation_n -
              ((rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
                rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m) +
               rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1) :
              0.0F;
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_m[rtb_Compare_bv_0 + 6] * tmp_3[2] +
              (rtb_VectorConcatenate_m[rtb_Compare_bv_0 + 3] * tmp_3[1] +
               rtb_VectorConcatenate_m[rtb_Compare_bv_0] * tmp_3[0]);
          }
          break;

         default:
          /* SignalConversion: '<S318>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_n[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_n[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S318>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S318>/Trigonometric Function3' incorporates:
           *  Gain: '<S317>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S318>/Gain' incorporates:
           *  Gain: '<S317>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S318>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S318>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S318>/Trigonometric Function' incorporates:
           *  Gain: '<S317>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S318>/Trigonometric Function1' incorporates:
           *  Gain: '<S317>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S331>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S310>/lat_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S334>/Compare' incorporates:
           *  Constant: '<S334>/Constant'
           *  S-Function (sfix_bitop): '<S331>/lat_cmd valid'
           */
          tmp[0] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S331>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S310>/lon_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S334>/Compare' incorporates:
           *  Constant: '<S334>/Constant'
           *  S-Function (sfix_bitop): '<S331>/lon_cmd valid'
           */
          tmp[1] = (tmp_7 > 0U);

          /* S-Function (sfix_bitop): '<S331>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S310>/alt_cmd valid'
           */
          tmp_8 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S334>/Compare' incorporates:
           *  Constant: '<S334>/Constant'
           *  S-Function (sfix_bitop): '<S331>/alt_cmd valid'
           */
          tmp[2] = (tmp_8 > 0U);

          /* DataTypeConversion: '<S332>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S332>/Data Type Conversion'
           *  Gain: '<S332>/Gain2'
           *  Gain: '<S335>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S338>/Multiply1'
           *  Product: '<S338>/Multiply2'
           *  Product: '<S338>/Multiply3'
           *  Product: '<S338>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S335>/Sum1'
           *  Sum: '<S338>/Sum2'
           *  Sum: '<S338>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S314>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* Sum: '<S309>/Sum' incorporates:
           *  DataStoreRead: '<S309>/Data Store Read'
           *  Gain: '<S315>/Gain'
           *  Gain: '<S316>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Add3_c = FMS_U.INS_Out.x_R - FMS_DW.home[0];
          rtb_Subtract3_od = FMS_U.INS_Out.y_R - FMS_DW.home[1];
          rtb_Add4_d = -FMS_U.INS_Out.h_R - (-FMS_DW.home[2]);

          /* RelationalOperator: '<S319>/Compare' incorporates:
           *  Constant: '<S319>/Constant'
           *  S-Function (sfix_bitop): '<S310>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S310>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S320>/Compare' incorporates:
           *  Constant: '<S320>/Constant'
           */
          tmp_2[0] = (tmp_6 > 0U);
          tmp_2[1] = (tmp_7 > 0U);
          tmp_2[2] = (tmp_8 > 0U);

          /* Sum: '<S309>/Sum2' incorporates:
           *  Logic: '<S310>/Logical Operator'
           *  Product: '<S309>/Multiply'
           *  Product: '<S309>/Multiply2'
           *  Sum: '<S309>/Sum'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S314>/Switch' incorporates:
             *  Product: '<S309>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            rtb_MatrixConcatenate3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Saturation_n -
              ((rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Subtract3_od +
                rtb_Transpose[rtb_Compare_bv_0] * rtb_Add3_c) +
               rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Add4_d) : 0.0F;
          }

          /* End of Sum: '<S309>/Sum2' */
          break;
        }

        /* End of MultiPortSwitch: '<S307>/Index Vector' */

        /* Trigonometry: '<S253>/Trigonometric Function1' incorporates:
         *  Gain: '<S252>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S253>/Trigonometric Function' incorporates:
         *  Gain: '<S252>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S253>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S253>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S253>/Gain' incorporates:
         *  Gain: '<S252>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S253>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S253>/Trigonometric Function3' incorporates:
         *  Gain: '<S252>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S253>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S253>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S253>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S242>/Index Vector' incorporates:
         *  Constant: '<S251>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S242>/Multiply'
         *  Product: '<S249>/Multiply'
         *  Product: '<S250>/Multiply3'
         *  RelationalOperator: '<S251>/Compare'
         *  S-Function (sfix_bitop): '<S248>/ax_cmd valid'
         *  S-Function (sfix_bitop): '<S248>/ay_cmd valid'
         *  S-Function (sfix_bitop): '<S248>/az_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S242>/Multiply' incorporates:
           *  Constant: '<S251>/Constant'
           *  RelationalOperator: '<S251>/Compare'
           *  S-Function (sfix_bitop): '<S248>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S248>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S248>/az_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_MathFunction_f_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 1:
          /* Product: '<S242>/Multiply' incorporates:
           *  Constant: '<S251>/Constant'
           *  RelationalOperator: '<S251>/Compare'
           *  S-Function (sfix_bitop): '<S248>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S248>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S248>/az_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_MathFunction_f_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 2:
          /* SignalConversion: '<S255>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S255>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S254>/Gain' incorporates:
           *  DataStoreRead: '<S250>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S250>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S255>/Trigonometric Function3' incorporates:
           *  Gain: '<S254>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S255>/Gain' incorporates:
           *  Gain: '<S254>/Gain'
           *  Trigonometry: '<S255>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S255>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S255>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S255>/Trigonometric Function' incorporates:
           *  Gain: '<S254>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S255>/Trigonometric Function1' incorporates:
           *  Gain: '<S254>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S255>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S242>/Multiply' incorporates:
           *  Constant: '<S251>/Constant'
           *  RelationalOperator: '<S251>/Compare'
           *  S-Function (sfix_bitop): '<S248>/ax_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S255>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S242>/Multiply' incorporates:
           *  Constant: '<S251>/Constant'
           *  RelationalOperator: '<S251>/Compare'
           *  S-Function (sfix_bitop): '<S248>/ay_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S255>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S242>/Multiply' incorporates:
           *  Constant: '<S251>/Constant'
           *  RelationalOperator: '<S251>/Compare'
           *  S-Function (sfix_bitop): '<S248>/az_cmd valid'
           */
          rtb_MathFunction_f_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
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

        /* End of MultiPortSwitch: '<S242>/Index Vector' */

        /* Sum: '<S303>/Sum1' incorporates:
         *  Constant: '<S303>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S303>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Saturation_n = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S304>/Abs' */
        rtb_Add3_c = fabsf(rtb_Saturation_n);

        /* Switch: '<S304>/Switch' incorporates:
         *  Constant: '<S304>/Constant'
         *  Constant: '<S305>/Constant'
         *  Product: '<S304>/Multiply'
         *  RelationalOperator: '<S305>/Compare'
         *  Sum: '<S304>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S304>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* End of Signum: '<S304>/Sign' */
          rtb_Saturation_n *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S304>/Switch' */

        /* Saturate: '<S303>/Saturation' */
        if (rtb_Saturation_n > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else {
          if (rtb_Saturation_n < -0.314159274F) {
            rtb_Saturation_n = -0.314159274F;
          }
        }

        /* End of Saturate: '<S303>/Saturation' */

        /* Gain: '<S300>/Gain2' */
        rtb_Saturation_n *= FMS_PARAM.MC_YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S244>/Sum' incorporates:
         *  Constant: '<S302>/Constant'
         *  Constant: '<S306>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S300>/Multiply2'
         *  Product: '<S301>/Multiply1'
         *  RelationalOperator: '<S302>/Compare'
         *  RelationalOperator: '<S306>/Compare'
         *  S-Function (sfix_bitop): '<S300>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S301>/psi_rate_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Saturation_n :
                      0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
          FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S307>/Gain1' */
        rtb_Add4_d = FMS_PARAM.MC_XY_P * rtb_MatrixConcatenate3[0];
        rtb_Subtract3_od = FMS_PARAM.MC_XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S307>/Gain2' */
        rtb_Saturation_n = FMS_PARAM.MC_Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S352>/Trigonometric Function1' incorporates:
         *  Gain: '<S351>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S352>/Trigonometric Function' incorporates:
         *  Gain: '<S351>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S352>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S352>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S352>/Gain' incorporates:
         *  Gain: '<S351>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S352>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S352>/Trigonometric Function3' incorporates:
         *  Gain: '<S351>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S352>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S352>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S352>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S308>/Index Vector' incorporates:
         *  Constant: '<S350>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S308>/Multiply'
         *  Product: '<S347>/Multiply'
         *  Product: '<S348>/Multiply3'
         *  RelationalOperator: '<S350>/Compare'
         *  S-Function (sfix_bitop): '<S346>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S346>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S346>/w_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S308>/Multiply' incorporates:
           *  Constant: '<S350>/Constant'
           *  RelationalOperator: '<S350>/Compare'
           *  S-Function (sfix_bitop): '<S346>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S346>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S346>/w_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_MathFunction_f_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 1:
          /* Product: '<S308>/Multiply' incorporates:
           *  Constant: '<S350>/Constant'
           *  RelationalOperator: '<S350>/Compare'
           *  S-Function (sfix_bitop): '<S346>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S346>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S346>/w_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_MathFunction_f_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 2:
          /* SignalConversion: '<S354>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S354>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S353>/Gain' incorporates:
           *  DataStoreRead: '<S348>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S348>/Subtract'
           */
          rtb_Switch2_m = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S354>/Trigonometric Function3' incorporates:
           *  Gain: '<S353>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Switch2_m);

          /* Gain: '<S354>/Gain' incorporates:
           *  Gain: '<S353>/Gain'
           *  Trigonometry: '<S354>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Switch2_m);

          /* SignalConversion: '<S354>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S354>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S354>/Trigonometric Function' incorporates:
           *  Gain: '<S353>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Switch2_m);

          /* Trigonometry: '<S354>/Trigonometric Function1' incorporates:
           *  Gain: '<S353>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Switch2_m);

          /* SignalConversion: '<S354>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S308>/Multiply' incorporates:
           *  Constant: '<S350>/Constant'
           *  RelationalOperator: '<S350>/Compare'
           *  S-Function (sfix_bitop): '<S346>/u_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S354>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S308>/Multiply' incorporates:
           *  Constant: '<S350>/Constant'
           *  RelationalOperator: '<S350>/Compare'
           *  S-Function (sfix_bitop): '<S346>/v_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S354>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S308>/Multiply' incorporates:
           *  Constant: '<S350>/Constant'
           *  RelationalOperator: '<S350>/Compare'
           *  S-Function (sfix_bitop): '<S346>/w_cmd valid'
           */
          rtb_MathFunction_f_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
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

        /* End of MultiPortSwitch: '<S308>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add4_d;
        rtb_MatrixConcatenate3[1] += rtb_Subtract3_od;

        /* Sum: '<S245>/Sum1' */
        rtb_Saturation_n += rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S263>/Switch' incorporates:
         *  Constant: '<S278>/Constant'
         *  Constant: '<S280>/Constant'
         *  Constant: '<S281>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S278>/Compare'
         *  RelationalOperator: '<S280>/Compare'
         *  RelationalOperator: '<S281>/Compare'
         *  S-Function (sfix_bitop): '<S263>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S263>/y_v_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S263>/Logical Operator' incorporates:
           *  Constant: '<S279>/Constant'
           *  Constant: '<S280>/Constant'
           *  Constant: '<S281>/Constant'
           *  RelationalOperator: '<S279>/Compare'
           *  RelationalOperator: '<S280>/Compare'
           *  RelationalOperator: '<S281>/Compare'
           *  S-Function (sfix_bitop): '<S263>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S263>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S263>/y_v_cmd'
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

        /* End of Switch: '<S263>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S243>/u_cmd_valid' */
        /* MATLAB Function: '<S275>/bit_shift' incorporates:
         *  DataTypeConversion: '<S243>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_a4 << 6);

        /* End of Outputs for SubSystem: '<S243>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S243>/v_cmd_valid' */
        /* MATLAB Function: '<S276>/bit_shift' incorporates:
         *  DataTypeConversion: '<S243>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S243>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S264>/Switch' incorporates:
         *  Constant: '<S283>/Constant'
         *  Constant: '<S284>/Constant'
         *  Constant: '<S286>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S283>/Compare'
         *  RelationalOperator: '<S284>/Compare'
         *  RelationalOperator: '<S286>/Compare'
         *  S-Function (sfix_bitop): '<S264>/ax_cmd'
         *  S-Function (sfix_bitop): '<S264>/ay_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S264>/Logical Operator' incorporates:
           *  Constant: '<S284>/Constant'
           *  Constant: '<S286>/Constant'
           *  RelationalOperator: '<S284>/Compare'
           *  RelationalOperator: '<S286>/Compare'
           *  S-Function (sfix_bitop): '<S264>/ax_cmd'
           *  S-Function (sfix_bitop): '<S264>/ay_cmd'
           */
          rtb_LogicalOperator_a4 = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_a4;
        } else {
          rtb_LogicalOperator_a4 = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S264>/Switch' */
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

        /* Saturate: '<S244>/Saturation' */
        if (rtb_Add3_c > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S244>/Saturation' */

        /* Saturate: '<S245>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S245>/Saturation2' */

        /* Saturate: '<S245>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S245>/Saturation1' */

        /* Saturate: '<S245>/Saturation3' */
        if (rtb_Saturation_n > FMS_PARAM.MC_VEL_Z_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.MC_VEL_Z_LIM;
        } else if (rtb_Saturation_n < -FMS_PARAM.MC_VEL_Z_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.MC_VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;
        }

        /* End of Saturate: '<S245>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S243>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S243>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S243>/throttle_cmd_valid' */
        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  Constant: '<S256>/Constant'
         *  Constant: '<S257>/Constant'
         *  Constant: '<S258>/Constant'
         *  Constant: '<S259>/Constant'
         *  Constant: '<S260>/Constant'
         *  Constant: '<S261>/Constant'
         *  Constant: '<S262>/Constant'
         *  Constant: '<S282>/Constant'
         *  Constant: '<S285>/Constant'
         *  DataTypeConversion: '<S243>/Data Type Conversion10'
         *  DataTypeConversion: '<S243>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S265>/bit_shift'
         *  MATLAB Function: '<S266>/bit_shift'
         *  MATLAB Function: '<S267>/bit_shift'
         *  MATLAB Function: '<S269>/bit_shift'
         *  MATLAB Function: '<S270>/bit_shift'
         *  MATLAB Function: '<S271>/bit_shift'
         *  MATLAB Function: '<S272>/bit_shift'
         *  MATLAB Function: '<S273>/bit_shift'
         *  MATLAB Function: '<S274>/bit_shift'
         *  MATLAB Function: '<S277>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S256>/Compare'
         *  RelationalOperator: '<S257>/Compare'
         *  RelationalOperator: '<S258>/Compare'
         *  RelationalOperator: '<S259>/Compare'
         *  RelationalOperator: '<S260>/Compare'
         *  RelationalOperator: '<S261>/Compare'
         *  RelationalOperator: '<S262>/Compare'
         *  RelationalOperator: '<S282>/Compare'
         *  RelationalOperator: '<S285>/Compare'
         *  S-Function (sfix_bitop): '<S243>/p_cmd'
         *  S-Function (sfix_bitop): '<S243>/phi_cmd'
         *  S-Function (sfix_bitop): '<S243>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S243>/q_cmd'
         *  S-Function (sfix_bitop): '<S243>/r_cmd'
         *  S-Function (sfix_bitop): '<S243>/theta_cmd'
         *  S-Function (sfix_bitop): '<S243>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S263>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S264>/az_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         *  Sum: '<S243>/Add'
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

        /* End of Outputs for SubSystem: '<S243>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S243>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S243>/q_cmd_valid' */
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
           *  Chart: '<S192>/Motion Status'
           *  Chart: '<S202>/Motion State'
           *  Delay: '<S158>/Delay'
           *  Delay: '<S176>/Delay'
           *  Delay: '<S176>/Delay1'
           *  DiscreteIntegrator: '<S160>/Integrator'
           *  DiscreteIntegrator: '<S160>/Integrator1'
           *  DiscreteIntegrator: '<S177>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S178>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S230>/Discrete-Time Integrator'
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
          /* Disable for SwitchCase: '<S201>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S191>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for DiscreteIntegrator: '<S178>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for Delay: '<S176>/Delay1' */
          FMS_DW.Delay1_DSTATE = false;

          /* InitializeConditions for Delay: '<S176>/Delay' */
          FMS_DW.icLoad_h = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S177>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

          /* InitializeConditions for Delay: '<S158>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S202>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S192>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* DiscreteIntegrator: '<S178>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S171>/Compare' incorporates:
         *  Constant: '<S241>/Constant'
         *  RelationalOperator: '<S241>/Compare'
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* Logic: '<S176>/Logical Operator' incorporates:
         *  Delay: '<S176>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE);

        /* Delay: '<S176>/Delay' incorporates:
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
        /* RelationalOperator: '<S188>/Compare' incorporates:
         *  Constant: '<S188>/Constant'
         *  Delay: '<S176>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S172>/Switch2' incorporates:
         *  Constant: '<S172>/vel'
         *  Delay: '<S176>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Switch2_m = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Switch2_m = FMS_PARAM.MC_CRUISE_SPEED;
        }

        /* End of Switch: '<S172>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S176>/Sum' incorporates:
         *  Delay: '<S176>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_c[0];

        /* Sum: '<S177>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_g = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S176>/Sum' incorporates:
         *  Delay: '<S176>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_c[1];

        /* Sum: '<S177>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_p_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S240>/Sqrt' incorporates:
         *  Math: '<S240>/Square'
         *  Sum: '<S177>/Sum'
         *  Sum: '<S240>/Sum of Elements'
         */
        rtb_Subtract3_od = sqrtf(rtb_Rem_g * rtb_Rem_g +
          rtb_MathFunction_p_idx_1 * rtb_MathFunction_p_idx_1);

        /* Gain: '<S177>/L1_GAIN' incorporates:
         *  Gain: '<S156>/Gain'
         */
        rtb_Saturation_n = FMS_PARAM.MC_L1_GAIN * rtb_Switch2_m;

        /* Switch: '<S177>/Switch' incorporates:
         *  Gain: '<S177>/L1_GAIN'
         *  Sum: '<S177>/Sum2'
         */
        if (rtb_Subtract3_od - rtb_Saturation_n >= 0.0F) {
          B = rtb_Switch2_m;
        } else {
          /* Gain: '<S177>/Gain' */
          B = 0.5F * rtb_Subtract3_od;

          /* Switch: '<S238>/Switch2' incorporates:
           *  Constant: '<S177>/Constant1'
           *  RelationalOperator: '<S238>/LowerRelop1'
           *  RelationalOperator: '<S238>/UpperRelop'
           *  Switch: '<S238>/Switch'
           */
          if (B > rtb_Switch2_m) {
            B = rtb_Switch2_m;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S238>/Switch' incorporates:
               *  Constant: '<S177>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S238>/Switch2' */
        }

        /* End of Switch: '<S177>/Switch' */

        /* DiscreteIntegrator: '<S177>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Switch: '<S239>/Switch2' incorporates:
         *  Constant: '<S177>/Constant2'
         *  DiscreteIntegrator: '<S177>/Acceleration_Speed'
         *  RelationalOperator: '<S239>/LowerRelop1'
         *  RelationalOperator: '<S239>/UpperRelop'
         *  Switch: '<S239>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Switch2_m) {
          rtb_Subtract3_od = rtb_Switch2_m;
        } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
          /* Switch: '<S239>/Switch' incorporates:
           *  Constant: '<S177>/Constant2'
           */
          rtb_Subtract3_od = 0.0F;
        } else {
          rtb_Subtract3_od = FMS_DW.Acceleration_Speed_DSTATE;
        }

        /* End of Switch: '<S239>/Switch2' */

        /* Switch: '<S177>/Switch1' incorporates:
         *  Sum: '<S177>/Sum1'
         */
        if (rtb_Subtract3_od - B >= 0.0F) {
          rtb_Integrator1_a = B;
        } else {
          rtb_Integrator1_a = rtb_Subtract3_od;
        }

        /* End of Switch: '<S177>/Switch1' */

        /* DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRese !=
             0)) {
          FMS_DW.l1_heading = 0.0F;
        }

        /* Math: '<S234>/Math Function' incorporates:
         *  Math: '<S232>/Math Function'
         *  SignalConversion: '<S234>/TmpSignal ConversionAtMath FunctionInport1'
         *  Switch: '<S156>/Switch'
         *  Switch: '<S180>/Switch'
         */
        rtb_Gain_hc = rtb_Add3_c * rtb_Add3_c;
        rtb_Add4_d = rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1;

        /* Sum: '<S234>/Sum of Elements' incorporates:
         *  Math: '<S234>/Math Function'
         */
        rtb_MathFunction_p_idx_0 = rtb_Add4_d + rtb_Gain_hc;

        /* Math: '<S234>/Math Function1' incorporates:
         *  Sum: '<S234>/Sum of Elements'
         *
         * About '<S234>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_MathFunction_p_idx_0));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_MathFunction_p_idx_0);
        }

        /* End of Math: '<S234>/Math Function1' */

        /* Switch: '<S234>/Switch' incorporates:
         *  Constant: '<S234>/Constant'
         *  Product: '<S234>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_MathFunction_f_idx_1;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Add3_c;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_od;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S234>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S202>/Motion State' incorporates:
         *  Constant: '<S202>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S202>/Square'
         *  Math: '<S202>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S202>/Sqrt'
         *  Sum: '<S202>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S201>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S201>/Hold Control' incorporates:
             *  ActionPort: '<S204>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S201>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S201>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S201>/Hold Control' incorporates:
           *  ActionPort: '<S204>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S201>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S201>/Brake Control' incorporates:
           *  ActionPort: '<S203>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S201>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ai != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S201>/Move Control' incorporates:
             *  ActionPort: '<S205>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S201>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S201>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S201>/Move Control' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S201>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S201>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S192>/Motion Status' incorporates:
         *  Abs: '<S192>/Abs'
         *  Constant: '<S192>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S191>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S191>/Hold Control' incorporates:
             *  ActionPort: '<S194>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S191>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S191>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S191>/Hold Control' incorporates:
           *  ActionPort: '<S194>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e3,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S191>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S191>/Brake Control' incorporates:
           *  ActionPort: '<S193>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e3);

          /* End of Outputs for SubSystem: '<S191>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S191>/Move Control' incorporates:
             *  ActionPort: '<S195>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S191>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S191>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S191>/Move Control' incorporates:
           *  ActionPort: '<S195>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e3,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S191>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S191>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S180>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_g = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_MathFunction_p_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S186>/Sqrt' incorporates:
         *  Math: '<S186>/Square'
         *  Sum: '<S180>/Sum'
         *  Sum: '<S186>/Sum of Elements'
         */
        rtb_Subtract3_od = sqrtf(rtb_MathFunction_p_idx_1 *
          rtb_MathFunction_p_idx_1 + rtb_Rem_g * rtb_Rem_g);

        /* Relay: '<S180>/Relay' */
        if (rtb_Subtract3_od >= 2.0F * FMS_PARAM.MC_ACCEPT_R) {
          FMS_DW.Relay_Mode = true;
        } else {
          if (rtb_Subtract3_od <= FMS_PARAM.MC_ACCEPT_R) {
            FMS_DW.Relay_Mode = false;
          }
        }

        /* Switch: '<S156>/Switch' incorporates:
         *  Relay: '<S180>/Relay'
         *  Switch: '<S180>/Switch'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S201>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_Subtract3_od = FMS_PARAM.MC_VEL_XY_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_Subtract3_od = -FMS_PARAM.MC_VEL_XY_LIM;
          } else {
            rtb_Subtract3_od = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_MathFunction_f_idx_1 = FMS_PARAM.MC_VEL_XY_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_MathFunction_f_idx_1 = -FMS_PARAM.MC_VEL_XY_LIM;
          } else {
            rtb_MathFunction_f_idx_1 = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S201>/Saturation1' */

          /* Saturate: '<S191>/Saturation1' */
          if (FMS_B.Merge_e3 > FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_MathFunction_f_idx_2 = FMS_PARAM.MC_VEL_Z_LIM;
          } else if (FMS_B.Merge_e3 < -FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_MathFunction_f_idx_2 = -FMS_PARAM.MC_VEL_Z_LIM;
          } else {
            rtb_MathFunction_f_idx_2 = FMS_B.Merge_e3;
          }

          /* End of Saturate: '<S191>/Saturation1' */
        } else {
          if (FMS_DW.Relay_Mode) {
            /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S237>/Constant4'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S236>/Gain' incorporates:
             *  DiscreteIntegrator: '<S230>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Sum: '<S230>/Add'
             *  Switch: '<S180>/Switch'
             */
            rtb_MathFunction_p_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S237>/Trigonometric Function3' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[4] = arm_cos_f32(rtb_MathFunction_p_idx_0);

            /* Gain: '<S237>/Gain' incorporates:
             *  Switch: '<S180>/Switch'
             *  Trigonometry: '<S237>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_MathFunction_p_idx_0);

            /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S237>/Constant3'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S237>/Trigonometric Function' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[1] = arm_sin_f32(rtb_MathFunction_p_idx_0);

            /* Trigonometry: '<S237>/Trigonometric Function1' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[0] = arm_cos_f32(rtb_MathFunction_p_idx_0);

            /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_d[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_d[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Sum: '<S232>/Sum of Elements' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Gain_hc += rtb_Add4_d;

            /* Math: '<S232>/Math Function1' incorporates:
             *  Sum: '<S232>/Sum of Elements'
             *  Switch: '<S180>/Switch'
             *
             * About '<S232>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Gain_hc < 0.0F) {
              rtb_MathFunction_p_idx_0 = -sqrtf(fabsf(rtb_Gain_hc));
            } else {
              rtb_MathFunction_p_idx_0 = sqrtf(rtb_Gain_hc);
            }

            /* End of Math: '<S232>/Math Function1' */

            /* Switch: '<S232>/Switch' incorporates:
             *  Constant: '<S232>/Constant'
             *  Product: '<S232>/Product'
             *  Switch: '<S180>/Switch'
             */
            if (rtb_MathFunction_p_idx_0 <= 0.0F) {
              rtb_Add3_c = 0.0F;
              rtb_MathFunction_f_idx_1 = 0.0F;
              rtb_MathFunction_p_idx_0 = 1.0F;
            }

            /* End of Switch: '<S232>/Switch' */

            /* Product: '<S228>/Multiply2' incorporates:
             *  Product: '<S232>/Divide'
             *  Switch: '<S180>/Switch'
             */
            rtb_Add3_c = rtb_Add3_c / rtb_MathFunction_p_idx_0 *
              rtb_Integrator1_a;
            rtb_MathFunction_f_idx_1 = rtb_MathFunction_f_idx_1 /
              rtb_MathFunction_p_idx_0 * rtb_Integrator1_a;
            for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++)
            {
              rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0
                + 3] * rtb_MathFunction_f_idx_1 + rtb_Transpose[rtb_Compare_bv_0]
                * rtb_Add3_c;
            }

            /* Switch: '<S180>/Switch' incorporates:
             *  Product: '<S176>/Multiply'
             */
            rtb_Subtract3_od = rtb_Transpose_0[0];
            rtb_MathFunction_f_idx_1 = rtb_Transpose_0[1];
          } else {
            /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_p[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_p[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_p[2];

            /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S187>/Constant4'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Trigonometry: '<S187>/Trigonometric Function3' incorporates:
             *  Gain: '<S184>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S187>/Gain' incorporates:
             *  Gain: '<S184>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S180>/Switch'
             *  Trigonometry: '<S187>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S187>/Constant3'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Trigonometry: '<S187>/Trigonometric Function' incorporates:
             *  Gain: '<S184>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S187>/Trigonometric Function1' incorporates:
             *  Gain: '<S184>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S180>/Switch'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Saturate: '<S180>/Saturation1' incorporates:
             *  Switch: '<S180>/Switch'
             */
            rtb_Gain_hc = FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
            rtb_MathFunction_p_idx_0 = -FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
            for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++)
            {
              rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0
                + 3] * rtb_MathFunction_p_idx_1 + rtb_Transpose[rtb_Compare_bv_0]
                * rtb_Rem_g;
            }

            /* Saturate: '<S180>/Saturation1' incorporates:
             *  Gain: '<S180>/Gain2'
             *  Product: '<S180>/Multiply'
             *  Sum: '<S180>/Sum'
             *  Switch: '<S180>/Switch'
             */
            rtb_Subtract3_od = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
            if (rtb_Subtract3_od > rtb_Gain_hc) {
              rtb_Subtract3_od = rtb_Gain_hc;
            } else {
              if (rtb_Subtract3_od < rtb_MathFunction_p_idx_0) {
                rtb_Subtract3_od = rtb_MathFunction_p_idx_0;
              }
            }

            rtb_MathFunction_f_idx_1 = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];
            if (rtb_MathFunction_f_idx_1 > rtb_Gain_hc) {
              rtb_MathFunction_f_idx_1 = rtb_Gain_hc;
            } else {
              if (rtb_MathFunction_f_idx_1 < rtb_MathFunction_p_idx_0) {
                rtb_MathFunction_f_idx_1 = rtb_MathFunction_p_idx_0;
              }
            }
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S179>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_g = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_p_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S179>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add4_d = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S179>/Divide' incorporates:
           *  Math: '<S181>/Square'
           *  Math: '<S182>/Square'
           *  Sqrt: '<S181>/Sqrt'
           *  Sqrt: '<S182>/Sqrt'
           *  Sum: '<S179>/Sum'
           *  Sum: '<S179>/Sum1'
           *  Sum: '<S181>/Sum of Elements'
           *  Sum: '<S182>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d) /
            sqrtf(rtb_Rem_g * rtb_Rem_g + rtb_MathFunction_p_idx_1 *
                  rtb_MathFunction_p_idx_1);

          /* Saturate: '<S179>/Saturation' */
          if (rtb_Add3_c > 1.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            if (rtb_Add3_c < 0.0F) {
              rtb_Add3_c = 0.0F;
            }
          }

          /* End of Saturate: '<S179>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S169>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S179>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S169>/Sum2'
           *  Sum: '<S179>/Add'
           *  Sum: '<S179>/Subtract'
           */
          rtb_MathFunction_f_idx_2 = (FMS_U.INS_Out.h_R -
            ((FMS_B.Cmd_In.sp_waypoint[2] - FMS_B.Cmd_In.cur_waypoint[2]) *
             rtb_Add3_c + FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.MC_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S169>/Saturation1' */
          if (rtb_MathFunction_f_idx_2 > FMS_PARAM.MC_TAKEOFF_SPEED) {
            rtb_MathFunction_f_idx_2 = FMS_PARAM.MC_TAKEOFF_SPEED;
          } else {
            if (rtb_MathFunction_f_idx_2 < -FMS_PARAM.MC_LAND_SPEED) {
              rtb_MathFunction_f_idx_2 = -FMS_PARAM.MC_LAND_SPEED;
            }
          }

          /* End of Saturate: '<S169>/Saturation1' */
        }

        /* Delay: '<S158>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S160>/Integrator1' incorporates:
         *  Delay: '<S158>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S164>/Rem' incorporates:
         *  Constant: '<S164>/Constant1'
         *  DiscreteIntegrator: '<S160>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S159>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S164>/Switch' incorporates:
         *  Abs: '<S164>/Abs'
         *  Constant: '<S164>/Constant'
         *  Constant: '<S165>/Constant'
         *  Product: '<S164>/Multiply'
         *  RelationalOperator: '<S165>/Compare'
         *  Sum: '<S164>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S164>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S164>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S164>/Switch' */

        /* Gain: '<S159>/Gain2' */
        B *= FMS_PARAM.MC_YAW_P;

        /* Saturate: '<S159>/Saturation' */
        if (B > FMS_PARAM.MC_YAWRATE_LIM) {
          B = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (B < -FMS_PARAM.MC_YAWRATE_LIM) {
            B = -FMS_PARAM.MC_YAWRATE_LIM;
          }
        }

        /* End of Saturate: '<S159>/Saturation' */

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
        FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_od;
        FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_1;
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_f_idx_2;
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S222>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S222>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Gain_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S222>/Math Function1' incorporates:
         *  Sum: '<S222>/Sum of Elements'
         *
         * About '<S222>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S222>/Math Function1' */

        /* Switch: '<S222>/Switch' incorporates:
         *  Constant: '<S222>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S222>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract3_od = FMS_U.INS_Out.vn;
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_Subtract3_od = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S222>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S176>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S235>/Sum of Elements' incorporates:
         *  Math: '<S235>/Math Function'
         *  Sum: '<S176>/Sum1'
         */
        rtb_Gain_hc = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S235>/Math Function1' incorporates:
         *  Sum: '<S235>/Sum of Elements'
         *
         * About '<S235>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S235>/Math Function1' */

        /* Switch: '<S235>/Switch' incorporates:
         *  Constant: '<S235>/Constant'
         *  Product: '<S235>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S235>/Switch' */

        /* Product: '<S222>/Divide' */
        rtb_Sum_ff[0] = rtb_Subtract3_od / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S225>/Sum of Elements' incorporates:
         *  Math: '<S225>/Math Function'
         *  SignalConversion: '<S225>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Gain_hc = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S225>/Math Function1' incorporates:
         *  Sum: '<S225>/Sum of Elements'
         *
         * About '<S225>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S225>/Math Function1' */

        /* Switch: '<S225>/Switch' incorporates:
         *  Constant: '<S225>/Constant'
         *  Product: '<S225>/Product'
         */
        if (B > 0.0F) {
          rtb_Subtract3_od = rtb_Sum_ff[1];
          rtb_MathFunction_f_idx_1 = rtb_Sum_ff[0];
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_Subtract3_od = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S225>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S174>/NearbyRefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, rtb_Saturation_n, rtb_Sum_ff,
                        &rtb_Rem_g);

        /* MATLAB Function: '<S174>/SearchL1RefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add4_d = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

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
                     rtb_Saturation_n * rtb_Saturation_n) * (4.0F * rtb_Add4_d);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_MathFunction_p_idx_0 = 0.0F;
        rtb_MathFunction_p_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Add4_d);
          rtb_Add4_d = (-B - u1_tmp) / (2.0F * rtb_Add4_d);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Add4_d >= 0.0F) && (rtb_Add4_d <=
               1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Add4_d);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Add4_d >= 0.0F) && (rtb_Add4_d <= 1.0F)) {
              rtb_Add3_c = rtb_Add4_d;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Add4_d);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_p_idx_0 = (FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_p_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S174>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_f3_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Gain_hc = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Add4_d = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                      rtb_Gain_hc + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Switch_f3_idx_1) /
          (rtb_Switch_f3_idx_1 * rtb_Switch_f3_idx_1 + rtb_Gain_hc * rtb_Gain_hc);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Add4_d <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Add4_d >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          D = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          D = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          D = rtb_Add4_d * rtb_Switch_f3_idx_1 + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Switch: '<S174>/Switch1' incorporates:
         *  Constant: '<S215>/Constant'
         *  RelationalOperator: '<S215>/Compare'
         */
        if (rtb_Rem_g <= 0.0F) {
          /* Switch: '<S174>/Switch' incorporates:
           *  Constant: '<S214>/Constant'
           *  MATLAB Function: '<S174>/SearchL1RefWP'
           *  RelationalOperator: '<S214>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0;
            rtb_Sum_ff[1] = rtb_MathFunction_p_idx_1;
          } else {
            rtb_Sum_ff[0] = D;

            /* MATLAB Function: '<S174>/OutRegionRegWP' incorporates:
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
              rtb_Sum_ff[1] = rtb_Add4_d * rtb_Gain_hc +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }
          }

          /* End of Switch: '<S174>/Switch' */
        }

        /* End of Switch: '<S174>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S175>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_g = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Rem_g;
        rtb_Add4_d = rtb_Rem_g * rtb_Rem_g;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S175>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S223>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_g = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S223>/Math Function' incorporates:
         *  Math: '<S221>/Square'
         */
        rtb_Gain_hc = rtb_Rem_g * rtb_Rem_g;

        /* Sum: '<S223>/Sum of Elements' incorporates:
         *  Math: '<S223>/Math Function'
         */
        rtb_Add4_d += rtb_Gain_hc;

        /* Math: '<S223>/Math Function1' incorporates:
         *  Sum: '<S223>/Sum of Elements'
         *
         * About '<S223>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S223>/Math Function1' */

        /* Switch: '<S223>/Switch' incorporates:
         *  Constant: '<S223>/Constant'
         *  Product: '<S223>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Rem_g;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S223>/Switch' */

        /* Product: '<S223>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S226>/Sum of Elements' incorporates:
         *  Math: '<S226>/Math Function'
         *  SignalConversion: '<S226>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add4_d = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Math: '<S226>/Math Function1' incorporates:
         *  Sum: '<S226>/Sum of Elements'
         *
         * About '<S226>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add4_d < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add4_d));
        } else {
          B = sqrtf(rtb_Add4_d);
        }

        /* End of Math: '<S226>/Math Function1' */

        /* Switch: '<S226>/Switch' incorporates:
         *  Constant: '<S226>/Constant'
         *  Product: '<S226>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S226>/Switch' */

        /* Product: '<S226>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S221>/Square' */
        rtb_Add4_d = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S235>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S234>/Divide' */
        D = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_Subtract3_od / rtb_MathFunction_f_idx_2;

        /* Product: '<S226>/Divide' incorporates:
         *  Product: '<S225>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S225>/Divide' */
        rtb_Rem_g = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S235>/Divide' */
        rtb_MathFunction_p_idx_1 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S234>/Divide' */
        rtb_Subtract3_od = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S233>/Subtract' incorporates:
         *  Product: '<S233>/Multiply'
         *  Product: '<S233>/Multiply1'
         */
        B = rtb_MathFunction_p_idx_0 * rtb_Subtract3_od -
          rtb_MathFunction_p_idx_1 * D;

        /* Signum: '<S229>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S229>/Sign1' */

        /* Switch: '<S229>/Switch2' incorporates:
         *  Constant: '<S229>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S229>/Switch2' */

        /* DotProduct: '<S229>/Dot Product' */
        rtb_Switch_f3_idx_1 = D * rtb_MathFunction_p_idx_0 + rtb_Subtract3_od *
          rtb_MathFunction_p_idx_1;

        /* Trigonometry: '<S229>/Acos' incorporates:
         *  DotProduct: '<S229>/Dot Product'
         */
        if (rtb_Switch_f3_idx_1 > 1.0F) {
          rtb_Switch_f3_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_f3_idx_1 < -1.0F) {
            rtb_Switch_f3_idx_1 = -1.0F;
          }
        }

        /* Product: '<S229>/Multiply' incorporates:
         *  Trigonometry: '<S229>/Acos'
         */
        B *= acosf(rtb_Switch_f3_idx_1);

        /* Abs: '<S176>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S227>/Compare' incorporates:
         *  Constant: '<S227>/Constant'
         *  Delay: '<S176>/Delay1'
         */
        FMS_DW.Delay1_DSTATE = (B > 1.57079637F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S220>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S220>/Square'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S220>/Sum of Elements'
         */
        rtb_Add3_c = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S175>/Square' */
        rtb_Subtract3_od = rtb_Add3_c * rtb_Add3_c;

        /* Sum: '<S224>/Subtract' incorporates:
         *  Product: '<S224>/Multiply'
         *  Product: '<S224>/Multiply1'
         */
        rtb_Add3_c = rtb_MathFunction_h_idx_0 * rtb_Rem_g -
          rtb_MathFunction_h_idx_1 * rtb_Sum_ff[0];

        /* Signum: '<S219>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S219>/Sign1' */

        /* Switch: '<S219>/Switch2' incorporates:
         *  Constant: '<S219>/Constant4'
         */
        if (rtb_Add3_c == 0.0F) {
          rtb_Add3_c = 1.0F;
        }

        /* End of Switch: '<S219>/Switch2' */

        /* DotProduct: '<S219>/Dot Product' */
        rtb_Rem_g = rtb_Sum_ff[0] * rtb_MathFunction_h_idx_0 + rtb_Rem_g *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S219>/Acos' incorporates:
         *  DotProduct: '<S219>/Dot Product'
         */
        if (rtb_Rem_g > 1.0F) {
          rtb_Rem_g = 1.0F;
        } else {
          if (rtb_Rem_g < -1.0F) {
            rtb_Rem_g = -1.0F;
          }
        }

        /* Product: '<S219>/Multiply' incorporates:
         *  Trigonometry: '<S219>/Acos'
         */
        rtb_Add3_c *= acosf(rtb_Rem_g);

        /* Saturate: '<S175>/Saturation' */
        if (rtb_Add3_c > 1.57079637F) {
          rtb_Add3_c = 1.57079637F;
        } else {
          if (rtb_Add3_c < -1.57079637F) {
            rtb_Add3_c = -1.57079637F;
          }
        }

        /* End of Saturate: '<S175>/Saturation' */

        /* Switch: '<S231>/Switch2' incorporates:
         *  Constant: '<S176>/Constant1'
         *  RelationalOperator: '<S231>/LowerRelop1'
         *  RelationalOperator: '<S231>/UpperRelop'
         *  Switch: '<S231>/Switch'
         */
        if (rtb_Integrator1_a > rtb_Switch2_m) {
          rtb_Integrator1_a = rtb_Switch2_m;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S231>/Switch' incorporates:
             *  Constant: '<S176>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S231>/Switch2' */

        /* Product: '<S176>/Divide1' incorporates:
         *  Constant: '<S175>/Constant'
         *  Gain: '<S175>/Gain'
         *  MinMax: '<S175>/Max'
         *  MinMax: '<S175>/Min'
         *  Product: '<S175>/Divide'
         *  Product: '<S175>/Multiply1'
         *  Sqrt: '<S221>/Sqrt'
         *  Sum: '<S221>/Sum of Elements'
         *  Trigonometry: '<S175>/Sin'
         */
        rtb_Add3_c = 2.0F * rtb_Subtract3_od * arm_sin_f32(rtb_Add3_c) / fminf
          (rtb_Saturation_n, fmaxf(sqrtf(rtb_Gain_hc + rtb_Add4_d), 0.5F)) /
          rtb_Integrator1_a;

        /* Saturate: '<S176>/Saturation' */
        if (rtb_Add3_c > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else if (rtb_Add3_c < -0.314159274F) {
          rtb_Saturation_n = -0.314159274F;
        } else {
          rtb_Saturation_n = rtb_Add3_c;
        }

        /* End of Saturate: '<S176>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S161>/Rem' incorporates:
         *  Constant: '<S161>/Constant1'
         *  Delay: '<S158>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S158>/Sum2'
         */
        rtb_Add3_c = rt_remf(FMS_B.Cmd_In.set_yaw - FMS_DW.Delay_DSTATE_h,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S161>/Switch' incorporates:
         *  Abs: '<S161>/Abs'
         *  Constant: '<S161>/Constant'
         *  Constant: '<S167>/Constant'
         *  Product: '<S161>/Multiply'
         *  RelationalOperator: '<S167>/Compare'
         *  Sum: '<S161>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S161>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          } else {
            rtb_Subtract3_od = rtb_Add3_c;
          }

          /* End of Signum: '<S161>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Subtract3_od;
        }

        /* End of Switch: '<S161>/Switch' */

        /* Sum: '<S158>/Sum' incorporates:
         *  Delay: '<S158>/Delay'
         */
        rtb_Subtract3_od = rtb_Add3_c + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S166>/Multiply1' incorporates:
         *  Constant: '<S166>/const1'
         *  DiscreteIntegrator: '<S160>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S166>/Add' incorporates:
         *  DiscreteIntegrator: '<S160>/Integrator1'
         *  Sum: '<S160>/Subtract'
         */
        B = (FMS_DW.Integrator1_DSTATE_p - rtb_Subtract3_od) + rtb_Add3_c;

        /* Signum: '<S166>/Sign' */
        if (B < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else if (B > 0.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          rtb_Subtract3_od = B;
        }

        /* End of Signum: '<S166>/Sign' */

        /* Sum: '<S166>/Add2' incorporates:
         *  Abs: '<S166>/Abs'
         *  Gain: '<S166>/Gain'
         *  Gain: '<S166>/Gain1'
         *  Product: '<S166>/Multiply2'
         *  Product: '<S166>/Multiply3'
         *  Sqrt: '<S166>/Sqrt'
         *  Sum: '<S166>/Add1'
         *  Sum: '<S166>/Subtract'
         */
        rtb_Rem_g = (sqrtf((8.0F * fabsf(B) + FMS_ConstB.d) * FMS_ConstB.d) -
                     FMS_ConstB.d) * 0.5F * rtb_Subtract3_od + rtb_Add3_c;

        /* Sum: '<S166>/Add4' */
        rtb_Subtract3_od = (B - rtb_Rem_g) + rtb_Add3_c;

        /* Sum: '<S166>/Add3' */
        rtb_Add3_c = B + FMS_ConstB.d;

        /* Sum: '<S166>/Subtract1' */
        B -= FMS_ConstB.d;

        /* Signum: '<S166>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S166>/Sign1' */

        /* Signum: '<S166>/Sign2' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S166>/Sign2' */

        /* Sum: '<S166>/Add5' incorporates:
         *  Gain: '<S166>/Gain2'
         *  Product: '<S166>/Multiply4'
         *  Sum: '<S166>/Subtract2'
         */
        rtb_Rem_g += (rtb_Add3_c - B) * 0.5F * rtb_Subtract3_od;

        /* Sum: '<S166>/Add6' */
        rtb_Add3_c = rtb_Rem_g + FMS_ConstB.d;

        /* Sum: '<S166>/Subtract3' */
        rtb_Add4_d = rtb_Rem_g - FMS_ConstB.d;

        /* Product: '<S166>/Divide' */
        rtb_Subtract3_od = rtb_Rem_g / FMS_ConstB.d;

        /* Signum: '<S166>/Sign5' incorporates:
         *  Signum: '<S166>/Sign6'
         */
        if (rtb_Rem_g < 0.0F) {
          rtb_Switch2_m = -1.0F;

          /* Signum: '<S166>/Sign6' */
          rtb_Gain_hc = -1.0F;
        } else if (rtb_Rem_g > 0.0F) {
          rtb_Switch2_m = 1.0F;

          /* Signum: '<S166>/Sign6' */
          rtb_Gain_hc = 1.0F;
        } else {
          rtb_Switch2_m = rtb_Rem_g;

          /* Signum: '<S166>/Sign6' */
          rtb_Gain_hc = rtb_Rem_g;
        }

        /* End of Signum: '<S166>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S162>/Rem' incorporates:
         *  Constant: '<S162>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S158>/Sum1'
         */
        rtb_Rem_g = rt_remf(FMS_B.Cmd_In.set_yaw - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S162>/Switch' incorporates:
         *  Abs: '<S162>/Abs'
         *  Constant: '<S162>/Constant'
         *  Constant: '<S168>/Constant'
         *  Product: '<S162>/Multiply'
         *  RelationalOperator: '<S168>/Compare'
         *  Sum: '<S162>/Add'
         */
        if (fabsf(rtb_Rem_g) > 3.14159274F) {
          /* Signum: '<S162>/Sign' */
          if (rtb_Rem_g < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else if (rtb_Rem_g > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          } else {
            rtb_Integrator1_a = rtb_Rem_g;
          }

          /* End of Signum: '<S162>/Sign' */
          rtb_Rem_g -= 6.28318548F * rtb_Integrator1_a;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Abs: '<S156>/Abs' */
        rtb_Rem_g = fabsf(rtb_Rem_g);

        /* Update for DiscreteIntegrator: '<S178>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S170>/Constant'
         *  RelationalOperator: '<S170>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(rtb_Rem_g <=
          0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S178>/Discrete-Time Integrator' */

        /* Update for Delay: '<S176>/Delay' */
        FMS_DW.icLoad_h = 0U;

        /* Update for DiscreteIntegrator: '<S177>/Acceleration_Speed' incorporates:
         *  Constant: '<S177>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.MC_CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Saturation_n;
        FMS_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S158>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S160>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S160>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Signum: '<S166>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S166>/Sign3' */

        /* Signum: '<S166>/Sign4' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S166>/Sign4' */

        /* Update for DiscreteIntegrator: '<S160>/Integrator' incorporates:
         *  Constant: '<S166>/const'
         *  Gain: '<S166>/Gain3'
         *  Product: '<S166>/Multiply5'
         *  Product: '<S166>/Multiply6'
         *  Sum: '<S166>/Subtract4'
         *  Sum: '<S166>/Subtract5'
         *  Sum: '<S166>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Subtract3_od - rtb_Switch2_m) *
          FMS_ConstB.Gain4 * ((rtb_Add3_c - rtb_Add4_d) * 0.5F) - rtb_Gain_hc *
          1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.MC_YAWRATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.MC_YAWRATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.MC_YAWRATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S160>/Integrator' */
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
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.MC_ROLL_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.MC_ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.MC_ROLL_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.MC_ROLL_DZ);
        }

        /* End of DeadZone: '<S130>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S130>/Gain' */
        rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.MC_ROLL_DZ) * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S131>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.MC_PITCH_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.MC_PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.MC_PITCH_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.MC_PITCH_DZ);
        }

        /* End of DeadZone: '<S131>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S131>/Gain' */
        rtb_Subtract3_od = 1.0F / (1.0F - FMS_PARAM.MC_PITCH_DZ) *
          rtb_Saturation_n;

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Math: '<S134>/Square'
         *  SignalConversion: '<S134>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S135>/Sum of Elements'
         *  Switch: '<S126>/Switch'
         */
        rtb_Saturation_n = rtb_Add4_d * rtb_Add4_d + rtb_Subtract3_od *
          rtb_Subtract3_od;

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
            rtb_MatrixConcatenate3[0] = rtb_Add4_d;
            rtb_MatrixConcatenate3[1] = rtb_Subtract3_od;
            rtb_MatrixConcatenate3[2] = rtb_Saturation_n;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S135>/Switch' */
          rtb_Add4_d = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Subtract3_od = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3
            [2];
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
        rtb_Switch2_m = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S136>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S132>/Integrator1'
         *  Gain: '<S126>/Gain'
         *  Product: '<S126>/Multiply'
         *  Sum: '<S132>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_k - FMS_PARAM.MC_ATT_LIM *
                             rtb_Add4_d * (real32_T)
                             rtb_FixPtRelationalOperator_me) + rtb_Switch2_m;

        /* Saturate: '<S136>/Saturation' incorporates:
         *  Constant: '<S132>/Constant'
         */
        if (FMS_PARAM.MC_STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.MC_STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.MC_STICK_SENS;
        }

        /* End of Saturate: '<S136>/Saturation' */

        /* Product: '<S136>/Multiply7' incorporates:
         *  Constant: '<S136>/const'
         */
        rtb_MathFunction_f_idx_1 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S136>/Multiply' */
        rtb_Gain_hc = rtb_MathFunction_f_idx_1 * FMS_ConstB.Square_c;

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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) + rtb_Gain_hc)
          * rtb_Gain_hc) - rtb_Gain_hc) * 0.5F * rtb_Saturation_n +
          rtb_Switch2_m;

        /* Sum: '<S136>/Add4' */
        rtb_Add4_d = (rtb_Integrator1_a - rtb_Saturation_n) + rtb_Switch2_m;

        /* Sum: '<S136>/Add3' */
        rtb_Add3_c = rtb_Integrator1_a + rtb_Gain_hc;

        /* Sum: '<S136>/Subtract1' */
        rtb_Integrator1_a -= rtb_Gain_hc;

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
        rtb_Saturation_n += (rtb_Add3_c - rtb_Integrator1_a) * 0.5F * rtb_Add4_d;

        /* Sum: '<S136>/Add6' */
        rtb_Add3_c = rtb_Saturation_n + rtb_Gain_hc;

        /* Sum: '<S136>/Subtract3' */
        rtb_Add4_d = rtb_Saturation_n - rtb_Gain_hc;

        /* Signum: '<S136>/Sign5' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Switch2_m = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Switch2_m = 1.0F;
        } else {
          rtb_Switch2_m = rtb_Saturation_n;
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
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
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
        rtb_Add4_d = (rtb_Saturation_n / rtb_Gain_hc - rtb_Switch2_m) *
          -rtb_MathFunction_f_idx_1 * ((rtb_Add3_c - rtb_Add4_d) * 0.5F);

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
        rtb_Rem_g = rtb_Saturation_n * rtb_MathFunction_f_idx_1;

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
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.MC_YAW_DZ,
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
          rtb_y_md = FMS_PARAM.MC_LAND_LOCK_THRO;
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
        if (FMS_B.Merge_j > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
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
        rtb_Gain_hc = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S137>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S133>/Integrator1'
         *  Gain: '<S126>/Gain1'
         *  Product: '<S126>/Multiply1'
         *  Sum: '<S133>/Subtract'
         */
        rtb_MathFunction_f_idx_1 = (FMS_DW.Integrator1_DSTATE_nf -
          -FMS_PARAM.MC_ATT_LIM * rtb_Subtract3_od * (real32_T)
          rtb_FixPtRelationalOperator_me) + rtb_Gain_hc;

        /* Saturate: '<S137>/Saturation' incorporates:
         *  Constant: '<S133>/Constant'
         */
        if (FMS_PARAM.MC_STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.MC_STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.MC_STICK_SENS;
        }

        /* End of Saturate: '<S137>/Saturation' */

        /* Product: '<S137>/Multiply7' incorporates:
         *  Constant: '<S137>/const'
         */
        rtb_Integrator1_a = 31.415926F * rtb_Saturation_n;

        /* Product: '<S137>/Multiply' */
        rtb_Switch2_m = rtb_Integrator1_a * FMS_ConstB.Square_b;

        /* Signum: '<S137>/Sign' */
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_MathFunction_f_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_1;
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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_1) +
          rtb_Switch2_m) * rtb_Switch2_m) - rtb_Switch2_m) * 0.5F *
          rtb_Saturation_n + rtb_Gain_hc;

        /* Sum: '<S137>/Add4' */
        rtb_Subtract3_od = (rtb_MathFunction_f_idx_1 - rtb_Saturation_n) +
          rtb_Gain_hc;

        /* Sum: '<S137>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_1 + rtb_Switch2_m;

        /* Sum: '<S137>/Subtract1' */
        rtb_MathFunction_f_idx_1 -= rtb_Switch2_m;

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
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_MathFunction_f_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign2' */

        /* Sum: '<S137>/Add5' incorporates:
         *  Gain: '<S137>/Gain2'
         *  Product: '<S137>/Multiply4'
         *  Sum: '<S137>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_MathFunction_f_idx_1) * 0.5F *
          rtb_Subtract3_od;

        /* Update for DiscreteIntegrator: '<S132>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S132>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Update for DiscreteIntegrator: '<S132>/Integrator' incorporates:
         *  Sum: '<S136>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += (rtb_Add4_d - rtb_Rem_g) * 0.004F;

        /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S133>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_nf += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S137>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - rtb_Switch2_m;

        /* Sum: '<S137>/Add6' */
        rtb_Add4_d = rtb_Saturation_n + rtb_Switch2_m;

        /* Signum: '<S137>/Sign5' incorporates:
         *  Signum: '<S137>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_MathFunction_p_idx_0 = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S137>/Sign6' */
          rtb_MathFunction_p_idx_0 = rtb_Saturation_n;
        }

        /* End of Signum: '<S137>/Sign5' */

        /* Signum: '<S137>/Sign3' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
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
        FMS_DW.Integrator_DSTATE_b += ((rtb_Saturation_n / rtb_Switch2_m -
          rtb_Gain_hc) * -rtb_Integrator1_a * ((rtb_Add4_d - rtb_Add3_c) * 0.5F)
          - rtb_MathFunction_p_idx_0 * rtb_Integrator1_a) * 0.004F;

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
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.MC_ROLL_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.MC_ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.MC_ROLL_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.MC_ROLL_DZ);
        }

        /* End of DeadZone: '<S63>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S63>/Gain' */
        rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.MC_ROLL_DZ) * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S64>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.MC_PITCH_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.MC_PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.MC_PITCH_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.MC_PITCH_DZ);
        }

        /* End of DeadZone: '<S64>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S64>/Gain' */
        rtb_Subtract3_od = 1.0F / (1.0F - FMS_PARAM.MC_PITCH_DZ) *
          rtb_Saturation_n;

        /* Sum: '<S67>/Sum of Elements' incorporates:
         *  Math: '<S67>/Square'
         *  SignalConversion: '<S67>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S68>/Sum of Elements'
         *  Switch: '<S49>/Switch'
         */
        rtb_Saturation_n = rtb_Add4_d * rtb_Add4_d + rtb_Subtract3_od *
          rtb_Subtract3_od;

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
            rtb_MatrixConcatenate3[0] = rtb_Add4_d;
            rtb_MatrixConcatenate3[1] = rtb_Subtract3_od;
            rtb_MatrixConcatenate3[2] = rtb_Saturation_n;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S68>/Switch' */
          rtb_Add4_d = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Subtract3_od = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3
            [2];
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
        rtb_Switch2_m = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S69>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  Gain: '<S49>/Gain'
         *  Product: '<S49>/Multiply'
         *  Sum: '<S65>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_n - FMS_PARAM.MC_ATT_LIM *
                             rtb_Add4_d * (real32_T)
                             rtb_FixPtRelationalOperator_me) + rtb_Switch2_m;

        /* Saturate: '<S69>/Saturation' incorporates:
         *  Constant: '<S65>/Constant'
         */
        if (FMS_PARAM.MC_STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.MC_STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.MC_STICK_SENS;
        }

        /* End of Saturate: '<S69>/Saturation' */

        /* Product: '<S69>/Multiply7' incorporates:
         *  Constant: '<S69>/const'
         */
        rtb_MathFunction_f_idx_1 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S69>/Multiply' */
        rtb_Saturation_n = rtb_MathFunction_f_idx_1 * FMS_ConstB.Square_m;

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
        rtb_Gain_hc = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) + rtb_Saturation_n)
                             * rtb_Saturation_n) - rtb_Saturation_n) * 0.5F *
          rtb_Add3_c + rtb_Switch2_m;

        /* Sum: '<S69>/Add4' */
        rtb_Add4_d = (rtb_Integrator1_a - rtb_Gain_hc) + rtb_Switch2_m;

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
        rtb_Gain_hc += (rtb_Add3_c - rtb_Integrator1_a) * 0.5F * rtb_Add4_d;

        /* Sum: '<S69>/Add6' */
        rtb_Add3_c = rtb_Gain_hc + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract3' */
        rtb_Add4_d = rtb_Gain_hc - rtb_Saturation_n;

        /* Signum: '<S69>/Sign5' */
        if (rtb_Gain_hc < 0.0F) {
          rtb_Switch2_m = -1.0F;
        } else if (rtb_Gain_hc > 0.0F) {
          rtb_Switch2_m = 1.0F;
        } else {
          rtb_Switch2_m = rtb_Gain_hc;
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
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
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
        rtb_Add4_d = (rtb_Gain_hc / rtb_Saturation_n - rtb_Switch2_m) *
          -rtb_MathFunction_f_idx_1 * ((rtb_Add3_c - rtb_Add4_d) * 0.5F);

        /* Signum: '<S69>/Sign6' */
        if (rtb_Gain_hc < 0.0F) {
          rtb_Gain_hc = -1.0F;
        } else {
          if (rtb_Gain_hc > 0.0F) {
            rtb_Gain_hc = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign6' */

        /* Product: '<S69>/Multiply6' */
        rtb_Rem_g = rtb_Gain_hc * rtb_MathFunction_f_idx_1;

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
                           FMS_PARAM.MC_THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
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
          rtb_Gain_hc = 0.5F;
        } else if (FMS_B.Merge_lf > FMS_PARAM.MC_VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Gain_hc = FMS_PARAM.MC_VEL_Z_LIM;
        } else if (FMS_B.Merge_lf < -FMS_PARAM.MC_VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Gain_hc = -FMS_PARAM.MC_VEL_Z_LIM;
        } else {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Gain_hc = FMS_B.Merge_lf;
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
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.MC_YAW_DZ,
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
        if (FMS_B.Merge_h > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (FMS_B.Merge_h < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
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
        FMS_Y.FMS_Out.w_cmd = rtb_Gain_hc;

        /* Product: '<S70>/Multiply1' incorporates:
         *  Constant: '<S70>/const1'
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        rtb_Gain_hc = FMS_DW.Integrator_DSTATE_g * 0.04F;

        /* Sum: '<S70>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Gain: '<S49>/Gain1'
         *  Product: '<S49>/Multiply1'
         *  Sum: '<S66>/Subtract'
         */
        rtb_MathFunction_f_idx_1 = (FMS_DW.Integrator1_DSTATE_i -
          -FMS_PARAM.MC_ATT_LIM * rtb_Subtract3_od * (real32_T)
          rtb_FixPtRelationalOperator_me) + rtb_Gain_hc;

        /* Saturate: '<S70>/Saturation' incorporates:
         *  Constant: '<S66>/Constant'
         */
        if (FMS_PARAM.MC_STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.MC_STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.MC_STICK_SENS;
        }

        /* End of Saturate: '<S70>/Saturation' */

        /* Product: '<S70>/Multiply7' incorporates:
         *  Constant: '<S70>/const'
         */
        rtb_Integrator1_a = 31.415926F * rtb_Saturation_n;

        /* Product: '<S70>/Multiply' */
        rtb_Switch2_m = rtb_Integrator1_a * FMS_ConstB.Square_i;

        /* Signum: '<S70>/Sign' */
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_MathFunction_f_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_1;
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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_1) +
          rtb_Switch2_m) * rtb_Switch2_m) - rtb_Switch2_m) * 0.5F *
          rtb_Saturation_n + rtb_Gain_hc;

        /* Sum: '<S70>/Add4' */
        rtb_Subtract3_od = (rtb_MathFunction_f_idx_1 - rtb_Saturation_n) +
          rtb_Gain_hc;

        /* Sum: '<S70>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_1 + rtb_Switch2_m;

        /* Sum: '<S70>/Subtract1' */
        rtb_MathFunction_f_idx_1 -= rtb_Switch2_m;

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
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_MathFunction_f_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign2' */

        /* Sum: '<S70>/Add5' incorporates:
         *  Gain: '<S70>/Gain2'
         *  Product: '<S70>/Multiply4'
         *  Sum: '<S70>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_MathFunction_f_idx_1) * 0.5F *
          rtb_Subtract3_od;

        /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
         *  Sum: '<S69>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Add4_d - rtb_Rem_g) * 0.004F;

        /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_i += 0.004F * FMS_DW.Integrator_DSTATE_g;

        /* Sum: '<S70>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - rtb_Switch2_m;

        /* Sum: '<S70>/Add6' */
        rtb_Add4_d = rtb_Saturation_n + rtb_Switch2_m;

        /* Signum: '<S70>/Sign5' incorporates:
         *  Signum: '<S70>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_MathFunction_p_idx_0 = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S70>/Sign6' */
          rtb_MathFunction_p_idx_0 = rtb_Saturation_n;
        }

        /* End of Signum: '<S70>/Sign5' */

        /* Signum: '<S70>/Sign3' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
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
        FMS_DW.Integrator_DSTATE_g += ((rtb_Saturation_n / rtb_Switch2_m -
          rtb_Gain_hc) * -rtb_Integrator1_a * ((rtb_Add4_d - rtb_Add3_c) * 0.5F)
          - rtb_MathFunction_p_idx_0 * rtb_Integrator1_a) * 0.004F;

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
                           FMS_PARAM.MC_THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
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
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.MC_YAW_DZ,
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
          FMS_PARAM.MC_PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.MC_ROLL_DZ));

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
          rtb_Switch2_m = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_a = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S111>/Multiply' incorporates:
           *  SignalConversion: '<S111>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Switch2_m;
          }

          /* End of Product: '<S111>/Multiply' */

          /* Gain: '<S111>/Gain2' */
          FMS_B.Merge[0] = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
          FMS_B.Merge[1] = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];

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
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.MC_PITCH_DZ) {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.MC_PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.MC_PITCH_DZ) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.MC_PITCH_DZ);
          }

          /* End of DeadZone: '<S117>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S117>/Gain' */
          rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.MC_PITCH_DZ) * rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S118>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S31>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.MC_ROLL_DZ) {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.MC_ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.MC_ROLL_DZ) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.MC_ROLL_DZ);
          }

          /* End of DeadZone: '<S118>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S118>/Gain' */
          rtb_Subtract3_od = 1.0F / (1.0F - FMS_PARAM.MC_ROLL_DZ) *
            rtb_Saturation_n;

          /* Sum: '<S120>/Sum of Elements' incorporates:
           *  Math: '<S120>/Square'
           *  SignalConversion: '<S120>/TmpSignal ConversionAtSquareInport1'
           *  Sum: '<S121>/Sum of Elements'
           *  Switch: '<S112>/Switch'
           */
          rtb_Saturation_n = rtb_Add4_d * rtb_Add4_d + rtb_Subtract3_od *
            rtb_Subtract3_od;

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
              rtb_MatrixConcatenate3[0] = rtb_Add4_d;
              rtb_MatrixConcatenate3[1] = rtb_Subtract3_od;
              rtb_MatrixConcatenate3[2] = rtb_Saturation_n;
            } else {
              rtb_MatrixConcatenate3[0] = 0.0F;
              rtb_MatrixConcatenate3[1] = 0.0F;
              rtb_MatrixConcatenate3[2] = 1.0F;
            }

            /* End of Switch: '<S121>/Switch' */
            rtb_Add4_d = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
            rtb_Subtract3_od = rtb_MatrixConcatenate3[1] /
              rtb_MatrixConcatenate3[2];
          }

          /* Saturate: '<S122>/Saturation' incorporates:
           *  Constant: '<S119>/Constant'
           */
          if (FMS_PARAM.MC_STICK_SENS > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else if (FMS_PARAM.MC_STICK_SENS < 0.0F) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_PARAM.MC_STICK_SENS;
          }

          /* End of Saturate: '<S122>/Saturation' */

          /* Product: '<S122>/Multiply7' incorporates:
           *  Constant: '<S122>/const'
           */
          rtb_Saturation_n *= 980.6F;

          /* Product: '<S122>/Multiply' */
          rtb_Switch2_m = rtb_Saturation_n * FMS_ConstB.Square;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Rem_g = FMS_DW.Integrator_DSTATE[0] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Add4_d = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.MC_VEL_XY_LIM *
                        rtb_Add4_d) + rtb_Rem_g;

          /* Signum: '<S122>/Sign' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Add4_d;
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
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Add4_d) + rtb_Switch2_m) *
            rtb_Switch2_m) - rtb_Switch2_m) * 0.5F * rtb_Add3_c + rtb_Rem_g;

          /* Sum: '<S122>/Add4' */
          rtb_Rem_g += rtb_Add4_d - rtb_Integrator1_a;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Add4_d + rtb_Switch2_m;

          /* Sum: '<S122>/Subtract1' */
          rtb_Add4_d -= rtb_Switch2_m;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add4_d = -1.0F;
          } else {
            if (rtb_Add4_d > 0.0F) {
              rtb_Add4_d = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Add3_c - rtb_Add4_d) * 0.5F * rtb_Rem_g;

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
          rtb_Add3_c = rtb_Integrator1_a - rtb_Switch2_m;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Add4_d = rtb_Integrator1_a + rtb_Switch2_m;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_1 = rtb_Integrator1_a;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add4_d = -1.0F;
          } else {
            if (rtb_Add4_d > 0.0F) {
              rtb_Add4_d = 1.0F;
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
            rtb_Gain_hc = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Gain_hc = 1.0F;
          } else {
            rtb_Gain_hc = rtb_Integrator1_a;
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
          FMS_DW.Integrator_DSTATE[0] += ((rtb_Integrator1_a / rtb_Switch2_m -
            rtb_MathFunction_f_idx_1) * -rtb_Saturation_n * ((rtb_Add4_d -
            rtb_Add3_c) * 0.5F) - rtb_Gain_hc * rtb_Saturation_n) * 0.004F;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Rem_g = FMS_DW.Integrator_DSTATE[1] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Add4_d = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.MC_VEL_XY_LIM *
                        rtb_Subtract3_od) + rtb_Rem_g;

          /* Signum: '<S122>/Sign' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Add4_d;
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
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Add4_d) + rtb_Switch2_m) *
            rtb_Switch2_m) - rtb_Switch2_m) * 0.5F * rtb_Add3_c + rtb_Rem_g;

          /* Sum: '<S122>/Add4' */
          rtb_Rem_g += rtb_Add4_d - rtb_Integrator1_a;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Add4_d + rtb_Switch2_m;

          /* Sum: '<S122>/Subtract1' */
          rtb_Add4_d -= rtb_Switch2_m;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add4_d = -1.0F;
          } else {
            if (rtb_Add4_d > 0.0F) {
              rtb_Add4_d = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Add3_c - rtb_Add4_d) * 0.5F * rtb_Rem_g;

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
          rtb_Add3_c = rtb_Integrator1_a - rtb_Switch2_m;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Add4_d = rtb_Integrator1_a + rtb_Switch2_m;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_1 = rtb_Integrator1_a;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Add4_d = -1.0F;
          } else {
            if (rtb_Add4_d > 0.0F) {
              rtb_Add4_d = 1.0F;
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
            rtb_Gain_hc = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Gain_hc = 1.0F;
          } else {
            rtb_Gain_hc = rtb_Integrator1_a;
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
          FMS_DW.Integrator_DSTATE[1] += ((rtb_Integrator1_a / rtb_Switch2_m -
            rtb_MathFunction_f_idx_1) * -rtb_Saturation_n * ((rtb_Add4_d -
            rtb_Add3_c) * 0.5F) - rtb_Gain_hc * rtb_Saturation_n) * 0.004F;

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
        } else if (FMS_B.Merge_l > FMS_PARAM.MC_VEL_Z_LIM) {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Saturation_n = FMS_PARAM.MC_VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.MC_VEL_Z_LIM) {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Saturation_n = -FMS_PARAM.MC_VEL_Z_LIM;
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
        if (FMS_B.Merge_e > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S97>/Saturation' */

        /* Saturate: '<S109>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
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
   *  DiscreteIntegrator: '<S503>/Discrete-Time Integrator'
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
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

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

  /* Update for DiscreteIntegrator: '<S520>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S520>/Gain'
   *  Sum: '<S520>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_ft[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_ft[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_ft[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S522>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S522>/Gain'
   *  Sum: '<S522>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S521>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S521>/Gain'
   *  Sum: '<S521>/Sum5'
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

  /* Update for DiscreteIntegrator: '<S503>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S503>/Constant'
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
    FMS_B.Switch1_c = FMS_Cmd_None;
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
  /* Start for SwitchCase: '<S451>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S441>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S39>/Return' */

  /* Start for IfAction SubSystem: '<S39>/Hold' */
  /* Start for SwitchCase: '<S385>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S363>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S373>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S39>/Hold' */
  /* End of Start for SubSystem: '<S32>/SubMode' */

  /* Start for IfAction SubSystem: '<S32>/Auto' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S37>/Mission' */
  /* Start for Resettable SubSystem: '<S150>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S201>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

  /* Start for SwitchCase: '<S191>/Switch Case' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S520>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S522>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S521>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S500>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S496>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S496>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S401>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S401>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Return' */
  /* InitializeConditions for DiscreteIntegrator: '<S434>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for Delay: '<S432>/Delay1' */
  FMS_DW.Delay1_DSTATE_b = false;

  /* InitializeConditions for Delay: '<S432>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S433>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S480>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for Delay: '<S410>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S413>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S409>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S413>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S452>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S451>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S451>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S451>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S451>/Move Control' */

  /* SystemInitialize for Merge: '<S451>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S442>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S441>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S441>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S441>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S441>/Move Control' */

  /* SystemInitialize for Merge: '<S441>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold' */
  /* SystemInitialize for Chart: '<S364>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S374>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S386>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S385>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S385>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S385>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S385>/Move Control' */

  /* SystemInitialize for Merge: '<S385>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S363>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S363>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S363>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S363>/Move Control' */

  /* SystemInitialize for Merge: '<S363>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S373>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S373>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S373>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S373>/Move Control' */

  /* SystemInitialize for Merge: '<S373>/Merge' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S178>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for Delay: '<S176>/Delay1' */
  FMS_DW.Delay1_DSTATE = false;

  /* InitializeConditions for Delay: '<S176>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S177>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for Delay: '<S158>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S202>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S201>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S201>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S201>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S201>/Move Control' */

  /* SystemInitialize for Merge: '<S201>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S192>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S191>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S191>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S191>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S191>/Move Control' */

  /* SystemInitialize for Merge: '<S191>/Merge' */
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
