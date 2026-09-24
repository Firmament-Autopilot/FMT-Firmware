/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2393
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 24 19:57:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S446>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S456>/Motion State' */
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

/* Named constants for Chart: '<S378>/Motion State' */
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
                                        *   '<S509>/Constant1'
                                        *   '<S509>/Gain'
                                        *   '<S510>/Constant'
                                        *   '<S49>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S126>/Gain'
                                        *   '<S126>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S248>/Saturation'
                                        *   '<S249>/Saturation1'
                                        *   '<S249>/Saturation2'
                                        *   '<S249>/Saturation3'
                                        *   '<S402>/Land_Speed'
                                        *   '<S403>/Saturation1'
                                        *   '<S412>/Gain'
                                        *   '<S496>/Takeoff_Speed'
                                        *   '<S497>/Gain2'
                                        *   '<S497>/Saturation1'
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
                                        *   '<S304>/Gain2'
                                        *   '<S311>/Gain1'
                                        *   '<S311>/Gain2'
                                        *   '<S367>/Saturation1'
                                        *   '<S377>/Saturation'
                                        *   '<S389>/Saturation1'
                                        *   '<S404>/Constant'
                                        *   '<S407>/Gain2'
                                        *   '<S429>/Gain'
                                        *   '<S429>/Saturation1'
                                        *   '<S432>/vel'
                                        *   '<S437>/Constant'
                                        *   '<S437>/L1_GAIN'
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
                                        *   '<S370>/Gain2'
                                        *   '<S371>/Gain1'
                                        *   '<S380>/Gain2'
                                        *   '<S381>/Gain1'
                                        *   '<S392>/Gain2'
                                        *   '<S393>/Gain6'
                                        *   '<S416>/Gain2'
                                        *   '<S416>/Saturation'
                                        *   '<S417>/Integrator'
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
                                        *   '<S184>/Gain2'
                                        *   '<S184>/Relay'
                                        *   '<S184>/Saturation1'
                                        *   '<S373>/Dead Zone'
                                        *   '<S373>/Gain'
                                        *   '<S385>/Dead Zone'
                                        *   '<S385>/Gain'
                                        *   '<S397>/Dead Zone'
                                        *   '<S397>/Gain'
                                        *   '<S398>/Dead Zone'
                                        *   '<S398>/Gain'
                                        *   '<S445>/Saturation1'
                                        *   '<S455>/Saturation1'
                                        *   '<S195>/Saturation1'
                                        *   '<S205>/Saturation1'
                                        *   '<S448>/Gain2'
                                        *   '<S449>/Gain1'
                                        *   '<S458>/Gain2'
                                        *   '<S459>/Gain6'
                                        *   '<S198>/Gain2'
                                        *   '<S199>/Gain1'
                                        *   '<S208>/Gain2'
                                        *   '<S209>/Gain6'
                                        *   '<S451>/Dead Zone'
                                        *   '<S451>/Gain'
                                        *   '<S463>/Dead Zone'
                                        *   '<S463>/Gain'
                                        *   '<S464>/Dead Zone'
                                        *   '<S464>/Gain'
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
                                        *   '<S13>/Constant1'
                                        *   '<S507>/Constant'
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
 *    '<S445>/Hold Control'
 *    '<S367>/Hold Control'
 *    '<S195>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S448>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S445>/Hold Control'
 *    '<S367>/Hold Control'
 *    '<S195>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S448>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S445>/Hold Control'
 *    '<S367>/Hold Control'
 *    '<S195>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S448>/Delay' incorporates:
   *  Gain: '<S450>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S448>/Gain2' incorporates:
   *  Delay: '<S448>/Delay'
   *  Gain: '<S450>/Gain'
   *  Sum: '<S448>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.MC_Z_P;

  /* Update for Delay: '<S448>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S445>/Brake Control'
 *    '<S367>/Brake Control'
 *    '<S377>/Brake Control'
 *    '<S195>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S447>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S447>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S445>/Move Control'
 *    '<S367>/Move Control'
 *    '<S195>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S445>/Move Control'
 *    '<S367>/Move Control'
 *    '<S195>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S445>/Move Control'
 *    '<S367>/Move Control'
 *    '<S195>/Move Control'
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

  /* Product: '<S453>/Multiply1' incorporates:
   *  Constant: '<S453>/const1'
   *  DiscreteIntegrator: '<S452>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S451>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.MC_THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.MC_THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.MC_THROTTLE_DZ);
  }

  /* End of DeadZone: '<S451>/Dead Zone' */

  /* Sum: '<S453>/Add' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator1'
   *  Gain: '<S449>/Gain1'
   *  Gain: '<S451>/Gain'
   *  Sum: '<S452>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.MC_THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.MC_VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S453>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S453>/Sign' */

  /* Sum: '<S453>/Add2' incorporates:
   *  Abs: '<S453>/Abs'
   *  Gain: '<S453>/Gain'
   *  Gain: '<S453>/Gain1'
   *  Product: '<S453>/Multiply2'
   *  Product: '<S453>/Multiply3'
   *  Sqrt: '<S453>/Sqrt'
   *  Sum: '<S453>/Add1'
   *  Sum: '<S453>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S453>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S453>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S453>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S453>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S453>/Sign1' */

  /* Signum: '<S453>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S453>/Sign2' */

  /* Sum: '<S453>/Add5' incorporates:
   *  Gain: '<S453>/Gain2'
   *  Product: '<S453>/Multiply4'
   *  Sum: '<S453>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S449>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S452>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S453>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S453>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S453>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S453>/Sign5' */

  /* Signum: '<S453>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S453>/Sign3' */

  /* Signum: '<S453>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S453>/Sign4' */

  /* Signum: '<S453>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S453>/Sign6' */

  /* Update for DiscreteIntegrator: '<S452>/Integrator' incorporates:
   *  Constant: '<S453>/const'
   *  Gain: '<S453>/Gain3'
   *  Product: '<S453>/Divide'
   *  Product: '<S453>/Multiply5'
   *  Product: '<S453>/Multiply6'
   *  Sum: '<S453>/Subtract4'
   *  Sum: '<S453>/Subtract5'
   *  Sum: '<S453>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S446>/Motion Status'
 *    '<S368>/Motion Status'
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
 *    '<S446>/Motion Status'
 *    '<S368>/Motion Status'
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
 *    '<S446>/Motion Status'
 *    '<S368>/Motion Status'
 *    '<S196>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S446>/Motion Status' */
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

  /* End of Chart: '<S446>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S455>/Hold Control'
 *    '<S389>/Hold Control'
 *    '<S205>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S458>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S455>/Hold Control'
 *    '<S389>/Hold Control'
 *    '<S205>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S458>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S455>/Hold Control'
 *    '<S389>/Hold Control'
 *    '<S205>/Hold Control'
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

  /* Delay: '<S458>/Delay' incorporates:
   *  SignalConversion: '<S458>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S462>/Trigonometric Function1' incorporates:
   *  Gain: '<S461>/Gain'
   *  Trigonometry: '<S462>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S462>/Trigonometric Function' incorporates:
   *  Gain: '<S461>/Gain'
   *  Trigonometry: '<S462>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S462>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S462>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S462>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S462>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S462>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S462>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S462>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S458>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S458>/Delay'
   *  SignalConversion: '<S458>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S458>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S458>/Multiply' incorporates:
   *  SignalConversion: '<S458>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S458>/Multiply' */

  /* Gain: '<S458>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.MC_XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.MC_XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S458>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S455>/Brake Control'
 *    '<S389>/Brake Control'
 *    '<S205>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S457>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S455>/Move Control'
 *    '<S389>/Move Control'
 *    '<S205>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S455>/Move Control'
 *    '<S389>/Move Control'
 *    '<S205>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S455>/Move Control'
 *    '<S389>/Move Control'
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

  /* SignalConversion: '<S459>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S465>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S466>/Multiply1' incorporates:
   *  Constant: '<S466>/const1'
   *  DiscreteIntegrator: '<S465>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S459>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S465>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S466>/Multiply1' incorporates:
   *  Constant: '<S466>/const1'
   *  DiscreteIntegrator: '<S465>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S463>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.MC_PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.MC_PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.MC_PITCH_DZ);
  }

  /* End of DeadZone: '<S463>/Dead Zone' */

  /* Sum: '<S466>/Add' incorporates:
   *  DiscreteIntegrator: '<S465>/Integrator1'
   *  Gain: '<S459>/Gain6'
   *  Gain: '<S463>/Gain'
   *  Sum: '<S465>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.MC_PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.MC_VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S464>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.MC_ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.MC_ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.MC_ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.MC_ROLL_DZ);
  }

  /* End of DeadZone: '<S464>/Dead Zone' */

  /* Sum: '<S466>/Add' incorporates:
   *  DiscreteIntegrator: '<S465>/Integrator1'
   *  Gain: '<S459>/Gain6'
   *  Gain: '<S464>/Gain'
   *  Sum: '<S465>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.MC_ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.MC_VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S466>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S466>/Add2' incorporates:
   *  Abs: '<S466>/Abs'
   *  Gain: '<S466>/Gain'
   *  Gain: '<S466>/Gain1'
   *  Product: '<S466>/Multiply2'
   *  Product: '<S466>/Multiply3'
   *  Signum: '<S466>/Sign'
   *  Sqrt: '<S466>/Sqrt'
   *  Sum: '<S466>/Add1'
   *  Sum: '<S466>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S466>/Add3' incorporates:
   *  Signum: '<S466>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S466>/Subtract1' incorporates:
   *  Signum: '<S466>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S466>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S466>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S466>/Add5' incorporates:
   *  Gain: '<S466>/Gain2'
   *  Product: '<S466>/Multiply4'
   *  Signum: '<S466>/Sign'
   *  Sum: '<S466>/Add2'
   *  Sum: '<S466>/Add4'
   *  Sum: '<S466>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S465>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S465>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S466>/Sign3' incorporates:
   *  Sum: '<S466>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S466>/Sign4' incorporates:
   *  Sum: '<S466>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S466>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S466>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S466>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S466>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S465>/Integrator' incorporates:
   *  Constant: '<S466>/const'
   *  Gain: '<S466>/Gain3'
   *  Product: '<S466>/Divide'
   *  Product: '<S466>/Multiply5'
   *  Product: '<S466>/Multiply6'
   *  Sum: '<S466>/Subtract4'
   *  Sum: '<S466>/Subtract5'
   *  Sum: '<S466>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S466>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S466>/Add2' incorporates:
   *  Abs: '<S466>/Abs'
   *  Gain: '<S466>/Gain'
   *  Gain: '<S466>/Gain1'
   *  Product: '<S466>/Multiply2'
   *  Product: '<S466>/Multiply3'
   *  Signum: '<S466>/Sign'
   *  Sqrt: '<S466>/Sqrt'
   *  Sum: '<S466>/Add1'
   *  Sum: '<S466>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S466>/Add3' incorporates:
   *  Signum: '<S466>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S466>/Subtract1' incorporates:
   *  Signum: '<S466>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S466>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S466>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S466>/Add5' incorporates:
   *  Gain: '<S466>/Gain2'
   *  Product: '<S466>/Multiply4'
   *  Signum: '<S466>/Sign'
   *  Sum: '<S466>/Add2'
   *  Sum: '<S466>/Add4'
   *  Sum: '<S466>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S465>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S465>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S466>/Sign3' incorporates:
   *  Sum: '<S466>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S466>/Sign4' incorporates:
   *  Sum: '<S466>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S466>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S466>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S466>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S466>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S465>/Integrator' incorporates:
   *  Constant: '<S466>/const'
   *  Gain: '<S466>/Gain3'
   *  Product: '<S466>/Divide'
   *  Product: '<S466>/Multiply5'
   *  Product: '<S466>/Multiply6'
   *  Sum: '<S466>/Subtract4'
   *  Sum: '<S466>/Subtract5'
   *  Sum: '<S466>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S456>/Motion State'
 *    '<S390>/Motion State'
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
 *    '<S456>/Motion State'
 *    '<S390>/Motion State'
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
 *    '<S456>/Motion State'
 *    '<S390>/Motion State'
 *    '<S206>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S456>/Motion State' */
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

  /* End of Chart: '<S456>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S434>/NearbyRefWP'
 *    '<S178>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S470>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S377>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S380>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S377>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S380>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S377>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_nb;

  /* Delay: '<S380>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S380>/Sum' incorporates:
   *  Delay: '<S380>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S383>/Abs' */
  rtb_Abs_nb = fabsf(rtb_psi_error_rad);

  /* Switch: '<S383>/Switch' incorporates:
   *  Constant: '<S383>/Constant'
   *  Constant: '<S384>/Constant'
   *  Product: '<S383>/Multiply'
   *  RelationalOperator: '<S384>/Compare'
   *  Sum: '<S383>/Subtract'
   */
  if (rtb_Abs_nb > 3.14159274F) {
    /* Signum: '<S383>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S383>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_nb - 6.28318548F;
  }

  /* End of Switch: '<S383>/Switch' */

  /* Gain: '<S380>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.MC_YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S380>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S377>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S386>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S386>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S377>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S386>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S386>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S377>/Move Control'
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

  /* Product: '<S387>/Multiply1' incorporates:
   *  Constant: '<S387>/const1'
   *  DiscreteIntegrator: '<S386>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S385>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.MC_YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.MC_YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.MC_YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.MC_YAW_DZ);
  }

  /* End of DeadZone: '<S385>/Dead Zone' */

  /* Sum: '<S387>/Add' incorporates:
   *  DiscreteIntegrator: '<S386>/Integrator1'
   *  Gain: '<S381>/Gain1'
   *  Gain: '<S385>/Gain'
   *  Sum: '<S386>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.MC_YAW_DZ) * rtb_a_m * FMS_PARAM.MC_YAWRATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S387>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S387>/Sign' */

  /* Sum: '<S387>/Add2' incorporates:
   *  Abs: '<S387>/Abs'
   *  Gain: '<S387>/Gain'
   *  Gain: '<S387>/Gain1'
   *  Product: '<S387>/Multiply2'
   *  Product: '<S387>/Multiply3'
   *  Sqrt: '<S387>/Sqrt'
   *  Sum: '<S387>/Add1'
   *  Sum: '<S387>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S387>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S387>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S387>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S387>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S387>/Sign1' */

  /* Signum: '<S387>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S387>/Sign2' */

  /* Sum: '<S387>/Add5' incorporates:
   *  Gain: '<S387>/Gain2'
   *  Product: '<S387>/Multiply4'
   *  Sum: '<S387>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S381>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S386>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S386>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S386>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S387>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S387>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S387>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S387>/Sign5' */

  /* Signum: '<S387>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S387>/Sign3' */

  /* Signum: '<S387>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S387>/Sign4' */

  /* Signum: '<S387>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S387>/Sign6' */

  /* Update for DiscreteIntegrator: '<S386>/Integrator' incorporates:
   *  Constant: '<S387>/const'
   *  Gain: '<S387>/Gain3'
   *  Product: '<S387>/Divide'
   *  Product: '<S387>/Multiply5'
   *  Product: '<S387>/Multiply6'
   *  Sum: '<S387>/Subtract4'
   *  Sum: '<S387>/Subtract5'
   *  Sum: '<S387>/Subtract6'
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

  /* BusAssignment: '<S363>/Bus Assignment' incorporates:
   *  Constant: '<S363>/Constant'
   *  Constant: '<S363>/Constant2'
   *  SignalConversion: '<S363>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S363>/Bus Assignment' */
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

  /* Gain: '<S512>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S513>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S513>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S513>/Multiply1' incorporates:
   *  Product: '<S513>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S513>/Divide' incorporates:
   *  Constant: '<S513>/Constant'
   *  Constant: '<S513>/R'
   *  Sqrt: '<S513>/Sqrt'
   *  Sum: '<S513>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S513>/Product3' incorporates:
   *  Constant: '<S513>/Constant1'
   *  Product: '<S513>/Multiply1'
   *  Sum: '<S513>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S513>/Multiply2' incorporates:
   *  Trigonometry: '<S513>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S512>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S517>/Abs' incorporates:
   *  Abs: '<S520>/Abs1'
   *  Switch: '<S517>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S517>/Switch1' incorporates:
   *  Abs: '<S517>/Abs'
   *  Bias: '<S517>/Bias2'
   *  Bias: '<S517>/Bias3'
   *  Constant: '<S514>/Constant'
   *  Constant: '<S514>/Constant1'
   *  Constant: '<S519>/Constant'
   *  Gain: '<S517>/Gain1'
   *  Product: '<S517>/Multiply'
   *  RelationalOperator: '<S519>/Compare'
   *  Switch: '<S514>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S520>/Switch1' incorporates:
     *  Bias: '<S520>/Bias2'
     *  Bias: '<S520>/Bias3'
     *  Constant: '<S520>/Constant'
     *  Constant: '<S521>/Constant'
     *  Math: '<S520>/Math Function'
     *  RelationalOperator: '<S521>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S520>/Switch1' */

    /* Signum: '<S517>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S517>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S514>/Sum' incorporates:
   *  Sum: '<S512>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S512>/Multiply' incorporates:
   *  Gain: '<S512>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S516>/Switch1' incorporates:
   *  Abs: '<S516>/Abs1'
   *  Bias: '<S516>/Bias2'
   *  Bias: '<S516>/Bias3'
   *  Constant: '<S516>/Constant'
   *  Constant: '<S518>/Constant'
   *  Math: '<S516>/Math Function'
   *  RelationalOperator: '<S518>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S516>/Switch1' */

  /* Product: '<S512>/Multiply' incorporates:
   *  Gain: '<S512>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S512>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S515>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S515>/Sum2' incorporates:
   *  Product: '<S515>/Multiply1'
   *  Product: '<S515>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S515>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S515>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S515>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S508>/Data Type Conversion' incorporates:
   *  Gain: '<S512>/Gain'
   *  Sum: '<S512>/Sum1'
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
        /* Sum: '<S509>/Sum' */
        FMS_B.Switch1[0] = FMS_B.sp_waypoint[0] - FMS_B.cur_waypoint[0];
        FMS_B.Switch1[1] = FMS_B.sp_waypoint[1] - FMS_B.cur_waypoint[1];

        /* Gain: '<S509>/Gain' incorporates:
         *  Constant: '<S509>/Constant1'
         *  Product: '<S509>/Divide'
         *  Sum: '<S509>/Sum1'
         */
        rtb_reachable_distance = 1.0F / FMS_PARAM.MC_TAKEOFF_SPEED *
          (FMS_B.sp_waypoint[2] - FMS_B.cur_waypoint[2]) *
          (FMS_PARAM.MC_VEL_XY_LIM / 5.0F);

        /* Sqrt: '<S522>/Sqrt' incorporates:
         *  Math: '<S522>/Square'
         *  Sum: '<S522>/Sum of Elements'
         */
        rtb_Sqrt = sqrtf(FMS_B.Switch1[0] * FMS_B.Switch1[0] + FMS_B.Switch1[1] *
                         FMS_B.Switch1[1]);

        /* Switch: '<S509>/Switch1' incorporates:
         *  Product: '<S509>/Multiply'
         *  Sum: '<S509>/Sum2'
         *  Sum: '<S509>/Sum3'
         */
        if (rtb_Sqrt - rtb_reachable_distance > 0.0F) {
          /* Product: '<S509>/Divide1' */
          rtb_reachable_distance /= rtb_Sqrt;

          /* Saturate: '<S509>/Saturation' */
          if (rtb_reachable_distance > 1.0F) {
            rtb_reachable_distance = 1.0F;
          } else {
            if (rtb_reachable_distance < 0.0F) {
              rtb_reachable_distance = 0.0F;
            }
          }

          /* End of Saturate: '<S509>/Saturation' */
          FMS_B.Switch1[0] = rtb_reachable_distance * FMS_B.Switch1[0] +
            FMS_B.cur_waypoint[0];
          FMS_B.Switch1[1] = rtb_reachable_distance * FMS_B.Switch1[1] +
            FMS_B.cur_waypoint[1];
        } else {
          FMS_B.Switch1[0] = FMS_B.sp_waypoint[0];
          FMS_B.Switch1[1] = FMS_B.sp_waypoint[1];
        }

        /* End of Switch: '<S509>/Switch1' */
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
  /* RelationalOperator: '<S523>/Compare' incorporates:
   *  Abs: '<S511>/Abs'
   *  Constant: '<S523>/Constant'
   *  MinMax: '<S511>/Max'
   *  Sum: '<S511>/Sum'
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
      /* Reshape: '<S510>/Reshape' incorporates:
       *  Constant: '<S510>/Constant'
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
  real32_T rtb_P_l_idx_0;
  real32_T rtb_MathFunction_p_idx_1;
  real32_T rtb_MathFunction_p_idx_0;
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
  real_T rtb_Multiply_l5_idx_0;
  FMS_Error tmp_4;
  FMS_Error tmp_5;
  real32_T rtb_Transpose_tmp;
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

  /* Sqrt: '<S533>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S533>/Square'
   *  Sum: '<S533>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S529>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Subtract3_od = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S530>/Square' incorporates:
   *  Math: '<S531>/Square'
   *  Math: '<S532>/Square'
   */
  rtb_Gain_hc = rtb_Subtract3_od * rtb_Subtract3_od;

  /* Math: '<S530>/Square2' incorporates:
   *  Math: '<S531>/Square2'
   *  Math: '<S532>/Square2'
   */
  rtb_Transpose_tmp = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S530>/Square1' incorporates:
   *  Math: '<S531>/Square1'
   *  Math: '<S532>/Square1'
   */
  rtb_Saturation_n = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0;

  /* Math: '<S530>/Square3' incorporates:
   *  Math: '<S531>/Square3'
   *  Math: '<S532>/Square3'
   */
  rtb_Add3_c = rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1;

  /* Sum: '<S530>/Subtract' incorporates:
   *  Math: '<S530>/Square'
   *  Math: '<S530>/Square1'
   *  Math: '<S530>/Square2'
   *  Math: '<S530>/Square3'
   *  Sum: '<S530>/Add'
   *  Sum: '<S530>/Add1'
   */
  rtb_Transpose[0] = (rtb_Gain_hc + rtb_Saturation_n) - (rtb_Transpose_tmp +
    rtb_Add3_c);

  /* Product: '<S530>/Multiply' incorporates:
   *  Product: '<S531>/Multiply'
   */
  rtb_Add4_d = rtb_MathFunction_f_idx_0 * rtb_Divide_l_idx_2;

  /* Product: '<S530>/Multiply1' incorporates:
   *  Product: '<S531>/Multiply1'
   */
  rtb_Switch2_m = rtb_Subtract3_od * rtb_MathFunction_f_idx_1;

  /* Gain: '<S530>/Gain' incorporates:
   *  Product: '<S530>/Multiply'
   *  Product: '<S530>/Multiply1'
   *  Sum: '<S530>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_Add4_d - rtb_Switch2_m) * 2.0F;

  /* Product: '<S530>/Multiply2' incorporates:
   *  Product: '<S532>/Multiply'
   */
  rtb_Integrator1_a = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_1;

  /* Product: '<S530>/Multiply3' incorporates:
   *  Product: '<S532>/Multiply1'
   */
  rtb_MathFunction_p_idx_0 = rtb_Subtract3_od * rtb_Divide_l_idx_2;

  /* Gain: '<S530>/Gain1' incorporates:
   *  Product: '<S530>/Multiply2'
   *  Product: '<S530>/Multiply3'
   *  Sum: '<S530>/Add2'
   */
  rtb_Transpose[2] = (rtb_Integrator1_a + rtb_MathFunction_p_idx_0) * 2.0F;

  /* Gain: '<S531>/Gain' incorporates:
   *  Sum: '<S531>/Add3'
   */
  rtb_Transpose[3] = (rtb_Add4_d + rtb_Switch2_m) * 2.0F;

  /* Sum: '<S531>/Subtract' incorporates:
   *  Sum: '<S531>/Add'
   *  Sum: '<S531>/Add1'
   */
  rtb_Transpose[4] = (rtb_Gain_hc + rtb_Transpose_tmp) - (rtb_Saturation_n +
    rtb_Add3_c);

  /* Product: '<S531>/Multiply2' incorporates:
   *  Product: '<S532>/Multiply2'
   */
  rtb_Add4_d = rtb_Divide_l_idx_2 * rtb_MathFunction_f_idx_1;

  /* Product: '<S531>/Multiply3' incorporates:
   *  Product: '<S532>/Multiply3'
   */
  rtb_Switch2_m = rtb_Subtract3_od * rtb_MathFunction_f_idx_0;

  /* Gain: '<S531>/Gain1' incorporates:
   *  Product: '<S531>/Multiply2'
   *  Product: '<S531>/Multiply3'
   *  Sum: '<S531>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_Add4_d - rtb_Switch2_m) * 2.0F;

  /* Gain: '<S532>/Gain' incorporates:
   *  Sum: '<S532>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Integrator1_a - rtb_MathFunction_p_idx_0) * 2.0F;

  /* Gain: '<S532>/Gain1' incorporates:
   *  Sum: '<S532>/Add2'
   */
  rtb_Transpose[7] = (rtb_Add4_d + rtb_Switch2_m) * 2.0F;

  /* Sum: '<S532>/Subtract' incorporates:
   *  Sum: '<S532>/Add'
   *  Sum: '<S532>/Add1'
   */
  rtb_Transpose[8] = (rtb_Gain_hc + rtb_Add3_c) - (rtb_Saturation_n +
    rtb_Transpose_tmp);

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

  /* DiscreteIntegrator: '<S524>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S526>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S526>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_Subtract3_od = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32
    (FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Subtract3_od > 1.0F) {
    rtb_Subtract3_od = 1.0F;
  } else {
    if (rtb_Subtract3_od < 0.9F) {
      rtb_Subtract3_od = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_l_idx_2 = (real32_T)FMS_PARAM.MC_LAND_LOCK_THRO / rtb_Subtract3_od;

  /* DiscreteIntegrator: '<S525>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S524>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S525>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S526>/Discrete-Time Integrator5'
   *  Logic: '<S527>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S527>/Lower Test'
   *  RelationalOperator: '<S527>/Upper Test'
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

  /* Sum: '<S506>/Add' incorporates:
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
        /* Disable for SwitchCase: '<S455>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S445>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S389>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S367>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S377>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S205>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S195>/Switch Case' */
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
          /* Disable for SwitchCase: '<S455>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S445>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S389>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S367>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S377>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S150>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S205>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S195>/Switch Case' */
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
       *  Math: '<S477>/Math Function'
       *  Product: '<S479>/Divide'
       *  Sum: '<S435>/Subtract'
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
          /* Disable for SwitchCase: '<S455>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S445>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S389>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S367>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S377>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Takeoff' incorporates:
           *  ActionPort: '<S362>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S504>/cur_waypoint'
           *  DiscreteIntegrator: '<S500>/Integrator'
           *  DiscreteIntegrator: '<S500>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Takeoff' incorporates:
         *  ActionPort: '<S362>/Action Port'
         */
        /* Delay: '<S504>/cur_waypoint' incorporates:
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
        /* Product: '<S504>/Divide' incorporates:
         *  Delay: '<S504>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S504>/Sum1'
         *  Sum: '<S504>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S504>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S504>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S505>/Trigonometric Function1' incorporates:
         *  Gain: '<S503>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S505>/Trigonometric Function3'
         */
        rtb_Gain_hc = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_Gain_hc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S505>/Trigonometric Function' incorporates:
         *  Gain: '<S503>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S505>/Trigonometric Function2'
         */
        rtb_Transpose_tmp = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_Transpose_tmp;

        /* SignalConversion: '<S505>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S505>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S505>/Gain' */
        rtb_Transpose[3] = -rtb_Transpose_tmp;

        /* Trigonometry: '<S505>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_Gain_hc;

        /* SignalConversion: '<S505>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S505>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S505>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S497>/Saturation1' */
        rtb_Saturation_n = FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
        rtb_Add4_d = -FMS_PARAM.MC_VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S497>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S504>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S504>/Multiply'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S497>/Sum'
         *  Sum: '<S504>/Sum3'
         *  Sum: '<S504>/Sum4'
         */
        rtb_Switch2_m = ((FMS_B.Cmd_In.sp_waypoint[0] -
                          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
                         FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_Integrator1_a = ((FMS_B.Cmd_In.sp_waypoint[1] -
                              FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
                             FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S497>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Switch2_m;
        }

        /* Saturate: '<S497>/Saturation1' incorporates:
         *  Gain: '<S497>/Gain2'
         *  Product: '<S497>/Multiply'
         */
        rtb_Subtract3_od = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S362>/Bus Assignment1'
         *  Constant: '<S362>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
         *  Constant: '<S362>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S497>/Saturation1' */
        if (rtb_Subtract3_od > rtb_Saturation_n) {
          /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_n;
        } else if (rtb_Subtract3_od < rtb_Add4_d) {
          /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_d;
        } else {
          /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_od;
        }

        if (rtb_Add3_c > rtb_Saturation_n) {
          /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        } else if (rtb_Add3_c < rtb_Add4_d) {
          /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_d;
        } else {
          /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S362>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S500>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S501>/Multiply1' incorporates:
         *  Constant: '<S501>/const1'
         *  DiscreteIntegrator: '<S500>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S496>/Switch' incorporates:
         *  Abs: '<S496>/Abs'
         *  Abs: '<S496>/Abs1'
         *  Constant: '<S496>/Takeoff_Speed'
         *  Constant: '<S498>/Constant'
         *  Constant: '<S499>/Constant'
         *  Gain: '<S496>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S496>/Logical Operator'
         *  RelationalOperator: '<S498>/Compare'
         *  RelationalOperator: '<S499>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S496>/Sum'
         *  Sum: '<S496>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Saturation_n = -FMS_PARAM.MC_TAKEOFF_SPEED;
        } else {
          rtb_Saturation_n = 0.5F * -FMS_PARAM.MC_TAKEOFF_SPEED;
        }

        /* End of Switch: '<S496>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S501>/Add' incorporates:
         *  DiscreteIntegrator: '<S500>/Integrator1'
         *  Sum: '<S500>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_a - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S501>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Subtract3_od;
        }

        /* End of Signum: '<S501>/Sign' */

        /* Sum: '<S501>/Add2' incorporates:
         *  Abs: '<S501>/Abs'
         *  Gain: '<S501>/Gain'
         *  Gain: '<S501>/Gain1'
         *  Product: '<S501>/Multiply2'
         *  Product: '<S501>/Multiply3'
         *  Sqrt: '<S501>/Sqrt'
         *  Sum: '<S501>/Add1'
         *  Sum: '<S501>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S501>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Saturation_n) + rtb_Add3_c;

        /* Sum: '<S501>/Add3' */
        rtb_Add3_c = rtb_Subtract3_od + FMS_ConstB.d_m;

        /* Sum: '<S501>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_m;

        /* Signum: '<S501>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S501>/Sign1' */

        /* Signum: '<S501>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S501>/Sign2' */

        /* Sum: '<S501>/Add5' incorporates:
         *  Gain: '<S501>/Gain2'
         *  Product: '<S501>/Multiply4'
         *  Sum: '<S501>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F * rtb_Add4_d;

        /* Update for Delay: '<S504>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S500>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S500>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S501>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - FMS_ConstB.d_m;

        /* Sum: '<S501>/Add6' */
        rtb_Subtract3_od = rtb_Saturation_n + FMS_ConstB.d_m;

        /* Signum: '<S501>/Sign5' incorporates:
         *  Signum: '<S501>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S501>/Sign6' */
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S501>/Sign6' */
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S501>/Sign6' */
          rtb_Integrator1_a = rtb_Saturation_n;
        }

        /* End of Signum: '<S501>/Sign5' */

        /* Signum: '<S501>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S501>/Sign3' */

        /* Signum: '<S501>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S501>/Sign4' */

        /* Update for DiscreteIntegrator: '<S500>/Integrator' incorporates:
         *  Constant: '<S501>/const'
         *  Gain: '<S501>/Gain3'
         *  Product: '<S501>/Divide'
         *  Product: '<S501>/Multiply5'
         *  Product: '<S501>/Multiply6'
         *  Sum: '<S501>/Subtract4'
         *  Sum: '<S501>/Subtract5'
         *  Sum: '<S501>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_Saturation_n / FMS_ConstB.d_m -
          rtb_Gain_hc) * FMS_ConstB.Gain4_a * ((rtb_Subtract3_od - rtb_Add3_c) *
          0.5F) - rtb_Integrator1_a * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Land' incorporates:
           *  ActionPort: '<S360>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S405>/Integrator'
           *  DiscreteIntegrator: '<S405>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Land' incorporates:
         *  ActionPort: '<S360>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S410>/Trigonometric Function1' incorporates:
         *  Gain: '<S409>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S410>/Trigonometric Function' incorporates:
         *  Gain: '<S409>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S410>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S410>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S410>/Gain' incorporates:
         *  Gain: '<S409>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S410>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S410>/Trigonometric Function3' incorporates:
         *  Gain: '<S409>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S410>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S410>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S410>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S403>/Saturation1' */
        rtb_Gain_hc = FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
        rtb_Integrator1_a = -FMS_PARAM.MC_VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S407>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S407>/Sum'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S407>/Multiply' incorporates:
         *  SignalConversion: '<S407>/TmpSignal ConversionAtMultiplyInport2'
         *  Sum: '<S407>/Sum'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Subtract3_od + rtb_Transpose[rtb_Compare_bv_0] * rtb_Add3_c;
        }

        /* End of Product: '<S407>/Multiply' */

        /* Saturate: '<S403>/Saturation1' incorporates:
         *  Gain: '<S407>/Gain2'
         */
        rtb_Subtract3_od = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S360>/Bus Assignment1'
         *  Constant: '<S360>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
         *  Constant: '<S360>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S403>/Saturation1' */
        if (rtb_Subtract3_od > rtb_Gain_hc) {
          /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_hc;
        } else if (rtb_Subtract3_od < rtb_Integrator1_a) {
          /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Integrator1_a;
        } else {
          /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_od;
        }

        if (rtb_Add3_c > rtb_Gain_hc) {
          /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Gain_hc;
        } else if (rtb_Add3_c < rtb_Integrator1_a) {
          /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Integrator1_a;
        } else {
          /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S360>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S405>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S406>/Multiply1' incorporates:
         *  Constant: '<S406>/const1'
         *  DiscreteIntegrator: '<S405>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S402>/Switch' incorporates:
         *  Constant: '<S402>/Land_Speed'
         *  Constant: '<S404>/Constant'
         *  Gain: '<S402>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S402>/Logical Operator'
         *  RelationalOperator: '<S404>/Compare'
         *  S-Function (sfix_bitop): '<S402>/cmd_p valid'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.MC_ASSIST_LAND_H)) {
          rtb_Saturation_n = 0.5F * FMS_PARAM.MC_LAND_SPEED;
        } else {
          rtb_Saturation_n = FMS_PARAM.MC_LAND_SPEED;
        }

        /* End of Switch: '<S402>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S406>/Add' incorporates:
         *  DiscreteIntegrator: '<S405>/Integrator1'
         *  Sum: '<S405>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_j - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S406>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Subtract3_od;
        }

        /* End of Signum: '<S406>/Sign' */

        /* Sum: '<S406>/Add2' incorporates:
         *  Abs: '<S406>/Abs'
         *  Gain: '<S406>/Gain'
         *  Gain: '<S406>/Gain1'
         *  Product: '<S406>/Multiply2'
         *  Product: '<S406>/Multiply3'
         *  Sqrt: '<S406>/Sqrt'
         *  Sum: '<S406>/Add1'
         *  Sum: '<S406>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d_p) * FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S406>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Saturation_n) + rtb_Add3_c;

        /* Sum: '<S406>/Add3' */
        rtb_Add3_c = rtb_Subtract3_od + FMS_ConstB.d_p;

        /* Sum: '<S406>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_p;

        /* Signum: '<S406>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S406>/Sign1' */

        /* Signum: '<S406>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S406>/Sign2' */

        /* Sum: '<S406>/Add5' incorporates:
         *  Gain: '<S406>/Gain2'
         *  Product: '<S406>/Multiply4'
         *  Sum: '<S406>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S405>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S405>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S406>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - FMS_ConstB.d_p;

        /* Sum: '<S406>/Add6' */
        rtb_Subtract3_od = rtb_Saturation_n + FMS_ConstB.d_p;

        /* Signum: '<S406>/Sign5' incorporates:
         *  Signum: '<S406>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S406>/Sign6' */
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S406>/Sign6' */
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S406>/Sign6' */
          rtb_Integrator1_a = rtb_Saturation_n;
        }

        /* End of Signum: '<S406>/Sign5' */

        /* Signum: '<S406>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S406>/Sign3' */

        /* Signum: '<S406>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S406>/Sign4' */

        /* Update for DiscreteIntegrator: '<S405>/Integrator' incorporates:
         *  Constant: '<S406>/const'
         *  Gain: '<S406>/Gain3'
         *  Product: '<S406>/Divide'
         *  Product: '<S406>/Multiply5'
         *  Product: '<S406>/Multiply6'
         *  Sum: '<S406>/Subtract4'
         *  Sum: '<S406>/Subtract5'
         *  Sum: '<S406>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_Saturation_n / FMS_ConstB.d_p -
          rtb_Gain_hc) * FMS_ConstB.Gain4_e * ((rtb_Subtract3_od - rtb_Add3_c) *
          0.5F) - rtb_Integrator1_a * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S361>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S413>/Delay'
           *  Delay: '<S414>/Delay'
           *  Delay: '<S436>/Delay'
           *  Delay: '<S436>/Delay1'
           *  DiscreteIntegrator: '<S417>/Integrator'
           *  DiscreteIntegrator: '<S417>/Integrator1'
           *  DiscreteIntegrator: '<S437>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S438>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S484>/Discrete-Time Integrator'
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
           *  ActionPort: '<S361>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S446>/Motion Status'
           *  Chart: '<S456>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S39>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Return' incorporates:
         *  ActionPort: '<S361>/Action Port'
         */
        /* RelationalOperator: '<S431>/Compare' incorporates:
         *  Constant: '<S495>/Constant'
         *  DiscreteIntegrator: '<S438>/Discrete-Time Integrator'
         *  RelationalOperator: '<S495>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* Logic: '<S436>/Logical Operator' incorporates:
         *  Delay: '<S436>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE_b);

        /* Delay: '<S436>/Delay' incorporates:
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
        /* RelationalOperator: '<S442>/Compare' incorporates:
         *  Constant: '<S442>/Constant'
         *  Delay: '<S436>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE_b = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S432>/Switch2' incorporates:
         *  Constant: '<S432>/vel'
         *  Delay: '<S436>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE_b) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Switch2_m = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Switch2_m = FMS_PARAM.MC_CRUISE_SPEED;
        }

        /* End of Switch: '<S432>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S436>/Sum' incorporates:
         *  Delay: '<S436>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

        /* Sum: '<S437>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S436>/Sum' incorporates:
         *  Delay: '<S436>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_e[1];

        /* Sum: '<S437>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Transpose_tmp = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S494>/Sqrt' incorporates:
         *  Math: '<S494>/Square'
         *  Sum: '<S437>/Sum'
         *  Sum: '<S494>/Sum of Elements'
         */
        rtb_Subtract3_od = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_Transpose_tmp * rtb_Transpose_tmp);

        /* Gain: '<S437>/L1_GAIN' incorporates:
         *  Gain: '<S412>/Gain'
         */
        rtb_Saturation_n = FMS_PARAM.MC_L1_GAIN * rtb_Switch2_m;

        /* Switch: '<S437>/Switch' incorporates:
         *  Gain: '<S437>/L1_GAIN'
         *  Sum: '<S437>/Sum2'
         */
        if (rtb_Subtract3_od - rtb_Saturation_n >= 0.0F) {
          B = rtb_Switch2_m;
        } else {
          /* Gain: '<S437>/Gain' */
          B = 0.5F * rtb_Subtract3_od;

          /* Switch: '<S492>/Switch2' incorporates:
           *  Constant: '<S437>/Constant1'
           *  RelationalOperator: '<S492>/LowerRelop1'
           *  RelationalOperator: '<S492>/UpperRelop'
           *  Switch: '<S492>/Switch'
           */
          if (B > rtb_Switch2_m) {
            B = rtb_Switch2_m;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S492>/Switch' incorporates:
               *  Constant: '<S437>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S492>/Switch2' */
        }

        /* End of Switch: '<S437>/Switch' */

        /* DiscreteIntegrator: '<S437>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Switch: '<S493>/Switch2' incorporates:
         *  Constant: '<S437>/Constant2'
         *  DiscreteIntegrator: '<S437>/Acceleration_Speed'
         *  RelationalOperator: '<S493>/LowerRelop1'
         *  RelationalOperator: '<S493>/UpperRelop'
         *  Switch: '<S493>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_Switch2_m) {
          rtb_Integrator1_a = rtb_Switch2_m;
        } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
          /* Switch: '<S493>/Switch' incorporates:
           *  Constant: '<S437>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE_j;
        }

        /* End of Switch: '<S493>/Switch2' */

        /* Switch: '<S437>/Switch1' incorporates:
         *  Sum: '<S437>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Integrator1_a = B;
        }

        /* End of Switch: '<S437>/Switch1' */

        /* DiscreteIntegrator: '<S484>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRe_e !=
             0)) {
          FMS_DW.l1_heading_e = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S456>/Motion State' incorporates:
         *  Constant: '<S456>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S456>/Square'
         *  Math: '<S456>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S456>/Sqrt'
         *  Sum: '<S456>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S455>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S455>/Hold Control' incorporates:
             *  ActionPort: '<S458>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S455>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S455>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S455>/Hold Control' incorporates:
           *  ActionPort: '<S458>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S455>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S455>/Brake Control' incorporates:
           *  ActionPort: '<S457>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S455>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S455>/Move Control' incorporates:
             *  ActionPort: '<S459>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S455>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S455>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S455>/Move Control' incorporates:
           *  ActionPort: '<S459>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S455>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S455>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S446>/Motion Status' incorporates:
         *  Abs: '<S446>/Abs'
         *  Constant: '<S446>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S445>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S445>/Hold Control' incorporates:
             *  ActionPort: '<S448>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S445>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S445>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S445>/Hold Control' incorporates:
           *  ActionPort: '<S448>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S445>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S445>/Brake Control' incorporates:
           *  ActionPort: '<S447>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S445>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S445>/Move Control' incorporates:
             *  ActionPort: '<S449>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S445>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S445>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S445>/Move Control' incorporates:
           *  ActionPort: '<S449>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S445>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S445>/Switch Case' */

        /* Switch: '<S412>/Switch' incorporates:
         *  Product: '<S436>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S455>/Saturation1' */
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

          /* End of Saturate: '<S455>/Saturation1' */

          /* Saturate: '<S445>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.MC_VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.MC_VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S445>/Saturation1' */
        } else {
          /* SignalConversion: '<S491>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S491>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S490>/Gain' incorporates:
           *  DiscreteIntegrator: '<S484>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S484>/Add'
           */
          rtb_MathFunction_f_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S491>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S491>/Trigonometric Function1'
           */
          rtb_Gain_hc = arm_cos_f32(rtb_MathFunction_f_idx_1);
          rtb_Transpose[4] = rtb_Gain_hc;

          /* Trigonometry: '<S491>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S491>/Trigonometric Function'
           */
          rtb_Transpose_tmp = arm_sin_f32(rtb_MathFunction_f_idx_1);

          /* Gain: '<S491>/Gain' incorporates:
           *  Trigonometry: '<S491>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Transpose_tmp;

          /* SignalConversion: '<S491>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S491>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S491>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Transpose_tmp;

          /* Trigonometry: '<S491>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Gain_hc;

          /* SignalConversion: '<S491>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Sum: '<S486>/Sum of Elements' incorporates:
           *  Math: '<S486>/Math Function'
           *  SignalConversion: '<S486>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Gain_hc = rtb_Add3_c * rtb_Add3_c + rtb_Add4_d * rtb_Add4_d;

          /* Math: '<S486>/Math Function1' incorporates:
           *  Sum: '<S486>/Sum of Elements'
           *
           * About '<S486>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain_hc < 0.0F) {
            rtb_MathFunction_f_idx_1 = -sqrtf(fabsf(rtb_Gain_hc));
          } else {
            rtb_MathFunction_f_idx_1 = sqrtf(rtb_Gain_hc);
          }

          /* End of Math: '<S486>/Math Function1' */

          /* Switch: '<S486>/Switch' incorporates:
           *  Constant: '<S486>/Constant'
           *  Product: '<S486>/Product'
           */
          if (rtb_MathFunction_f_idx_1 > 0.0F) {
            rtb_Subtract3_od = rtb_Add3_c;
            rtb_MathFunction_f_idx_0 = rtb_Add4_d;
          } else {
            rtb_Subtract3_od = 0.0F;
            rtb_MathFunction_f_idx_0 = 0.0F;
            rtb_MathFunction_f_idx_1 = 1.0F;
          }

          /* End of Switch: '<S486>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S439>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Transpose_tmp = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S439>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Gain_hc = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_p_idx_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S439>/Divide' incorporates:
           *  Math: '<S440>/Square'
           *  Math: '<S441>/Square'
           *  Sqrt: '<S440>/Sqrt'
           *  Sqrt: '<S441>/Sqrt'
           *  Sum: '<S439>/Sum'
           *  Sum: '<S439>/Sum1'
           *  Sum: '<S440>/Sum of Elements'
           *  Sum: '<S441>/Sum of Elements'
           */
          rtb_Gain_hc = sqrtf(rtb_Gain_hc * rtb_Gain_hc +
                              rtb_MathFunction_p_idx_0 *
                              rtb_MathFunction_p_idx_0) / sqrtf(rtb_P_l_idx_0 *
            rtb_P_l_idx_0 + rtb_Transpose_tmp * rtb_Transpose_tmp);

          /* Saturate: '<S439>/Saturation' */
          if (rtb_Gain_hc > 1.0F) {
            rtb_Gain_hc = 1.0F;
          } else {
            if (rtb_Gain_hc < 0.0F) {
              rtb_Gain_hc = 0.0F;
            }
          }

          /* End of Saturate: '<S439>/Saturation' */

          /* Product: '<S482>/Multiply2' incorporates:
           *  Product: '<S486>/Divide'
           */
          rtb_Subtract3_od = rtb_Subtract3_od / rtb_MathFunction_f_idx_1 *
            rtb_Integrator1_a;
          rtb_MathFunction_f_idx_0 = rtb_MathFunction_f_idx_0 /
            rtb_MathFunction_f_idx_1 * rtb_Integrator1_a;

          /* Product: '<S436>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_MathFunction_f_idx_0 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Subtract3_od;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S429>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S439>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S429>/Sum2'
           *  Sum: '<S439>/Add'
           *  Sum: '<S439>/Subtract'
           */
          rtb_Subtract3_od = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Gain_hc +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.MC_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S429>/Saturation1' incorporates:
           *  Product: '<S436>/Multiply'
           */
          if (rtb_Subtract3_od > FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.MC_VEL_Z_LIM;
          } else if (rtb_Subtract3_od < -FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.MC_VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_od;
          }

          /* End of Saturate: '<S429>/Saturation1' */
        }

        /* End of Switch: '<S412>/Switch' */

        /* Delay: '<S414>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S417>/Integrator1' incorporates:
         *  Delay: '<S414>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S421>/Rem' incorporates:
         *  Constant: '<S421>/Constant1'
         *  DiscreteIntegrator: '<S417>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S416>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S421>/Switch' incorporates:
         *  Abs: '<S421>/Abs'
         *  Constant: '<S421>/Constant'
         *  Constant: '<S422>/Constant'
         *  Product: '<S421>/Multiply'
         *  RelationalOperator: '<S422>/Compare'
         *  Sum: '<S421>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S421>/Sign' */
          if (B < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else if (B > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          } else {
            rtb_Subtract3_od = B;
          }

          /* End of Signum: '<S421>/Sign' */
          B -= 6.28318548F * rtb_Subtract3_od;
        }

        /* End of Switch: '<S421>/Switch' */

        /* Gain: '<S416>/Gain2' */
        B *= FMS_PARAM.MC_YAW_P;

        /* Saturate: '<S416>/Saturation' */
        if (B > FMS_PARAM.MC_YAWRATE_LIM) {
          B = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (B < -FMS_PARAM.MC_YAWRATE_LIM) {
            B = -FMS_PARAM.MC_YAWRATE_LIM;
          }
        }

        /* End of Saturate: '<S416>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S361>/Bus Assignment1'
         *  Constant: '<S361>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S361>/Bus Assignment1' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Sum: '<S488>/Sum of Elements' incorporates:
         *  Math: '<S488>/Math Function'
         *  SignalConversion: '<S488>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Gain_hc = rtb_Add4_d * rtb_Add4_d + rtb_Add3_c * rtb_Add3_c;

        /* Math: '<S488>/Math Function1' incorporates:
         *  Sum: '<S488>/Sum of Elements'
         *
         * About '<S488>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S488>/Math Function1' */

        /* Switch: '<S488>/Switch' incorporates:
         *  Constant: '<S488>/Constant'
         *  Product: '<S488>/Product'
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

        /* End of Switch: '<S488>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S476>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S476>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S474>/Sum of Elements'
         */
        rtb_Gain_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S476>/Math Function1' incorporates:
         *  Sum: '<S476>/Sum of Elements'
         *
         * About '<S476>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S476>/Math Function1' */

        /* Switch: '<S476>/Switch' incorporates:
         *  Constant: '<S476>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S476>/Product'
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

        /* End of Switch: '<S476>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S436>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S489>/Sum of Elements' incorporates:
         *  Math: '<S489>/Math Function'
         *  Sum: '<S436>/Sum1'
         */
        rtb_Add3_c = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S489>/Math Function1' incorporates:
         *  Sum: '<S489>/Sum of Elements'
         *
         * About '<S489>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S489>/Math Function1' */

        /* Switch: '<S489>/Switch' incorporates:
         *  Constant: '<S489>/Constant'
         *  Product: '<S489>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S489>/Switch' */

        /* Delay: '<S413>/Delay' incorporates:
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
        /* Sum: '<S361>/Sum' incorporates:
         *  Delay: '<S413>/Delay'
         *  MATLAB Function: '<S434>/OutRegionRegWP'
         *  MATLAB Function: '<S434>/SearchL1RefWP'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_Transpose_tmp = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_p
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S428>/Sum of Elements' incorporates:
         *  Math: '<S428>/Math Function'
         *  Sum: '<S361>/Sum'
         */
        rtb_Add3_c = rtb_Transpose_tmp * rtb_Transpose_tmp + rtb_P_l_idx_0 *
          rtb_P_l_idx_0;

        /* Math: '<S428>/Math Function1' incorporates:
         *  Sum: '<S428>/Sum of Elements'
         *
         * About '<S428>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S428>/Math Function1' */

        /* Switch: '<S428>/Switch' incorporates:
         *  Constant: '<S428>/Constant'
         *  Product: '<S428>/Product'
         *  Sum: '<S361>/Sum'
         */
        if (B > 0.0F) {
          rtb_Switch_f3_idx_0 = rtb_Transpose_tmp;
          rtb_Switch_f3_idx_1 = rtb_P_l_idx_0;
          rtb_Switch_f3_idx_2 = B;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S428>/Switch' */

        /* Product: '<S476>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S479>/Sum of Elements' incorporates:
         *  Math: '<S479>/Math Function'
         *  SignalConversion: '<S479>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] * rtb_Sum_ff
          [0];

        /* Math: '<S479>/Math Function1' incorporates:
         *  Sum: '<S479>/Sum of Elements'
         *
         * About '<S479>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S479>/Math Function1' */

        /* Switch: '<S479>/Switch' incorporates:
         *  Constant: '<S479>/Constant'
         *  Product: '<S479>/Product'
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

        /* End of Switch: '<S479>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S434>/NearbyRefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, rtb_Saturation_n, rtb_Sum_ff,
                        &rtb_Add4_d);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S434>/SearchL1RefWP' incorporates:
         *  Delay: '<S413>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Subtract3_od = rtb_P_l_idx_0 * rtb_P_l_idx_0 + rtb_Transpose_tmp *
          rtb_Transpose_tmp;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        B = (rtb_P_l_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
             rtb_Transpose_tmp * (FMS_DW.Delay_DSTATE_p[1] - FMS_U.INS_Out.y_R))
          * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     rtb_Saturation_n * rtb_Saturation_n) * (4.0F *
          rtb_Subtract3_od);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_MathFunction_p_idx_0 = 0.0F;
        rtb_MathFunction_p_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          rtb_MathFunction_h_idx_1 = sqrtf(D);
          D = (-B + rtb_MathFunction_h_idx_1) / (2.0F * rtb_Subtract3_od);
          rtb_Subtract3_od = (-B - rtb_MathFunction_h_idx_1) / (2.0F *
            rtb_Subtract3_od);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Subtract3_od >= 0.0F) &&
              (rtb_Subtract3_od <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Subtract3_od);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Subtract3_od >= 0.0F) && (rtb_Subtract3_od <= 1.0F)) {
              rtb_Add3_c = rtb_Subtract3_od;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Subtract3_od);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_p_idx_0 = rtb_P_l_idx_0 * rtb_Add3_c +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_p_idx_1 = rtb_Transpose_tmp * rtb_Add3_c +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S434>/OutRegionRegWP' incorporates:
         *  Delay: '<S413>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Subtract3_od = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                            rtb_Transpose_tmp + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_Transpose_tmp * rtb_Transpose_tmp);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Subtract3_od <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Subtract3_od >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Subtract3_od * rtb_P_l_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S434>/Switch1' incorporates:
         *  Constant: '<S469>/Constant'
         *  RelationalOperator: '<S469>/Compare'
         */
        if (rtb_Add4_d <= 0.0F) {
          /* Switch: '<S434>/Switch' incorporates:
           *  Constant: '<S468>/Constant'
           *  MATLAB Function: '<S434>/SearchL1RefWP'
           *  RelationalOperator: '<S468>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0;
            rtb_Sum_ff[1] = rtb_MathFunction_p_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S434>/OutRegionRegWP' incorporates:
             *  Delay: '<S413>/Delay'
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_a4) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Subtract3_od * rtb_Transpose_tmp +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S434>/Switch' */
        }

        /* End of Switch: '<S434>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S435>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose_tmp = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Transpose_tmp;
        rtb_Subtract3_od = rtb_Transpose_tmp * rtb_Transpose_tmp;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S435>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S477>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose_tmp = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S477>/Math Function' incorporates:
         *  Math: '<S475>/Square'
         */
        rtb_Add3_c = rtb_Transpose_tmp * rtb_Transpose_tmp;

        /* Sum: '<S477>/Sum of Elements' incorporates:
         *  Math: '<S477>/Math Function'
         */
        rtb_MathFunction_p_idx_0 = rtb_Add3_c + rtb_Subtract3_od;

        /* Math: '<S477>/Math Function1' incorporates:
         *  Sum: '<S477>/Sum of Elements'
         *
         * About '<S477>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_MathFunction_p_idx_0));
        } else {
          B = sqrtf(rtb_MathFunction_p_idx_0);
        }

        /* End of Math: '<S477>/Math Function1' */

        /* Switch: '<S477>/Switch' incorporates:
         *  Constant: '<S477>/Constant'
         *  Product: '<S477>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Transpose_tmp;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S477>/Switch' */

        /* Product: '<S477>/Divide' */
        D = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S480>/Sum of Elements' incorporates:
         *  Math: '<S480>/Math Function'
         *  SignalConversion: '<S480>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction_p_idx_0 = rtb_MathFunction_h_idx_1 *
          rtb_MathFunction_h_idx_1 + D * D;

        /* Math: '<S480>/Math Function1' incorporates:
         *  Sum: '<S480>/Sum of Elements'
         *
         * About '<S480>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_MathFunction_p_idx_0));
        } else {
          B = sqrtf(rtb_MathFunction_p_idx_0);
        }

        /* End of Math: '<S480>/Math Function1' */

        /* Switch: '<S480>/Switch' incorporates:
         *  Constant: '<S480>/Constant'
         *  Product: '<S480>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = D;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S480>/Switch' */

        /* Product: '<S480>/Divide' */
        D = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];

        /* Math: '<S475>/Square' */
        rtb_Subtract3_od = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S428>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S489>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S488>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S480>/Divide' incorporates:
         *  Product: '<S479>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S479>/Divide' */
        rtb_Transpose_tmp = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S428>/Divide' */
        rtb_MathFunction_p_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S489>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S488>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S487>/Subtract' incorporates:
         *  Product: '<S487>/Multiply'
         *  Product: '<S487>/Multiply1'
         */
        B = rtb_P_l_idx_0 * rtb_MathFunction_f_idx_0 - rtb_MathFunction_f_idx_1 *
          rtb_Switch_mp_idx_0;

        /* Signum: '<S483>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S483>/Sign1' */

        /* Switch: '<S483>/Switch2' incorporates:
         *  Constant: '<S483>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S483>/Switch2' */

        /* DotProduct: '<S483>/Dot Product' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_1;

        /* Trigonometry: '<S483>/Acos' incorporates:
         *  DotProduct: '<S483>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_0 > 1.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          }
        }

        /* Product: '<S483>/Multiply' incorporates:
         *  Trigonometry: '<S483>/Acos'
         */
        B *= acosf(rtb_MathFunction_f_idx_0);

        /* Abs: '<S436>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S481>/Compare' incorporates:
         *  Constant: '<S481>/Constant'
         *  Delay: '<S436>/Delay1'
         */
        FMS_DW.Delay1_DSTATE_b = (B > 1.57079637F);

        /* Sqrt: '<S474>/Sqrt' */
        rtb_MathFunction_f_idx_0 = sqrtf(rtb_Gain_hc);

        /* Math: '<S435>/Square' */
        rtb_Add4_d = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0;

        /* Sum: '<S478>/Subtract' incorporates:
         *  Product: '<S478>/Multiply'
         *  Product: '<S478>/Multiply1'
         */
        rtb_MathFunction_f_idx_0 = D * rtb_Transpose_tmp -
          rtb_MathFunction_h_idx_1 * rtb_Sum_ff[0];

        /* Signum: '<S473>/Sign1' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S473>/Sign1' */

        /* Switch: '<S473>/Switch2' incorporates:
         *  Constant: '<S473>/Constant4'
         */
        if (rtb_MathFunction_f_idx_0 == 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        }

        /* End of Switch: '<S473>/Switch2' */

        /* DotProduct: '<S473>/Dot Product' */
        rtb_Transpose_tmp = rtb_Sum_ff[0] * D + rtb_Transpose_tmp *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S473>/Acos' incorporates:
         *  DotProduct: '<S473>/Dot Product'
         */
        if (rtb_Transpose_tmp > 1.0F) {
          rtb_Transpose_tmp = 1.0F;
        } else {
          if (rtb_Transpose_tmp < -1.0F) {
            rtb_Transpose_tmp = -1.0F;
          }
        }

        /* Product: '<S473>/Multiply' incorporates:
         *  Trigonometry: '<S473>/Acos'
         */
        rtb_MathFunction_f_idx_0 *= acosf(rtb_Transpose_tmp);

        /* Saturate: '<S435>/Saturation' */
        if (rtb_MathFunction_f_idx_0 > 1.57079637F) {
          rtb_MathFunction_f_idx_0 = 1.57079637F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.57079637F) {
            rtb_MathFunction_f_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S435>/Saturation' */

        /* Switch: '<S485>/Switch2' incorporates:
         *  Constant: '<S436>/Constant1'
         *  RelationalOperator: '<S485>/LowerRelop1'
         *  RelationalOperator: '<S485>/UpperRelop'
         *  Switch: '<S485>/Switch'
         */
        if (rtb_Integrator1_a > rtb_Switch2_m) {
          rtb_Integrator1_a = rtb_Switch2_m;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S485>/Switch' incorporates:
             *  Constant: '<S436>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S485>/Switch2' */

        /* Product: '<S436>/Divide1' incorporates:
         *  Constant: '<S435>/Constant'
         *  Gain: '<S435>/Gain'
         *  MinMax: '<S435>/Max'
         *  MinMax: '<S435>/Min'
         *  Product: '<S435>/Divide'
         *  Product: '<S435>/Multiply1'
         *  Sqrt: '<S475>/Sqrt'
         *  Sum: '<S475>/Sum of Elements'
         *  Trigonometry: '<S435>/Sin'
         */
        rtb_MathFunction_f_idx_0 = 2.0F * rtb_Add4_d * arm_sin_f32
          (rtb_MathFunction_f_idx_0) / fminf(rtb_Saturation_n, fmaxf(sqrtf
          (rtb_Add3_c + rtb_Subtract3_od), 0.5F)) / rtb_Integrator1_a;

        /* Saturate: '<S436>/Saturation' */
        if (rtb_MathFunction_f_idx_0 > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else if (rtb_MathFunction_f_idx_0 < -0.314159274F) {
          rtb_Saturation_n = -0.314159274F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_0;
        }

        /* End of Saturate: '<S436>/Saturation' */

        /* Sum: '<S426>/Subtract' incorporates:
         *  Product: '<S426>/Multiply'
         *  Product: '<S426>/Multiply1'
         */
        rtb_MathFunction_f_idx_0 = rtb_MathFunction_p_idx_0 *
          FMS_ConstB.Divide_d[1] - rtb_MathFunction_p_idx_1 *
          FMS_ConstB.Divide_d[0];

        /* Signum: '<S415>/Sign1' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S415>/Sign1' */

        /* Switch: '<S415>/Switch2' incorporates:
         *  Constant: '<S415>/Constant4'
         */
        if (rtb_MathFunction_f_idx_0 == 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        }

        /* End of Switch: '<S415>/Switch2' */

        /* DotProduct: '<S415>/Dot Product' */
        rtb_Subtract3_od = FMS_ConstB.Divide_d[0] * rtb_MathFunction_p_idx_0 +
          FMS_ConstB.Divide_d[1] * rtb_MathFunction_p_idx_1;

        /* Trigonometry: '<S415>/Acos' incorporates:
         *  DotProduct: '<S415>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S415>/Multiply' incorporates:
         *  Trigonometry: '<S415>/Acos'
         */
        rtb_MathFunction_f_idx_0 *= acosf(rtb_Subtract3_od);

        /* Math: '<S418>/Rem' incorporates:
         *  Constant: '<S418>/Constant1'
         *  Delay: '<S414>/Delay'
         *  Sum: '<S414>/Sum2'
         */
        B = rt_remf(rtb_MathFunction_f_idx_0 - FMS_DW.Delay_DSTATE_a,
                    6.28318548F);

        /* Switch: '<S418>/Switch' incorporates:
         *  Abs: '<S418>/Abs'
         *  Constant: '<S418>/Constant'
         *  Constant: '<S424>/Constant'
         *  Product: '<S418>/Multiply'
         *  RelationalOperator: '<S424>/Compare'
         *  Sum: '<S418>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S418>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S418>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S418>/Switch' */

        /* Sum: '<S414>/Sum' incorporates:
         *  Delay: '<S414>/Delay'
         */
        rtb_Add3_c = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S423>/Multiply1' incorporates:
         *  Constant: '<S423>/const1'
         *  DiscreteIntegrator: '<S417>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S423>/Add' incorporates:
         *  DiscreteIntegrator: '<S417>/Integrator1'
         *  Sum: '<S417>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_e - rtb_Add3_c) + B;

        /* Signum: '<S423>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Subtract3_od;
        }

        /* End of Signum: '<S423>/Sign' */

        /* Sum: '<S423>/Add2' incorporates:
         *  Abs: '<S423>/Abs'
         *  Gain: '<S423>/Gain'
         *  Gain: '<S423>/Gain1'
         *  Product: '<S423>/Multiply2'
         *  Product: '<S423>/Multiply3'
         *  Sqrt: '<S423>/Sqrt'
         *  Sum: '<S423>/Add1'
         *  Sum: '<S423>/Subtract'
         */
        rtb_Add4_d = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) + FMS_ConstB.d_l) *
                            FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Add3_c + B;

        /* Sum: '<S423>/Add4' */
        rtb_Switch2_m = (rtb_Subtract3_od - rtb_Add4_d) + B;

        /* Sum: '<S423>/Add3' */
        rtb_Add3_c = rtb_Subtract3_od + FMS_ConstB.d_l;

        /* Sum: '<S423>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_l;

        /* Signum: '<S423>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S423>/Sign1' */

        /* Signum: '<S423>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S423>/Sign2' */

        /* Sum: '<S423>/Add5' incorporates:
         *  Gain: '<S423>/Gain2'
         *  Product: '<S423>/Multiply4'
         *  Sum: '<S423>/Subtract2'
         */
        rtb_Add4_d += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F * rtb_Switch2_m;

        /* Sum: '<S423>/Add6' */
        rtb_Add3_c = rtb_Add4_d + FMS_ConstB.d_l;

        /* Sum: '<S423>/Subtract3' */
        rtb_Subtract3_od = rtb_Add4_d - FMS_ConstB.d_l;

        /* Product: '<S423>/Divide' */
        rtb_Switch2_m = rtb_Add4_d / FMS_ConstB.d_l;

        /* Signum: '<S423>/Sign5' incorporates:
         *  Signum: '<S423>/Sign6'
         */
        if (rtb_Add4_d < 0.0F) {
          rtb_Integrator1_a = -1.0F;

          /* Signum: '<S423>/Sign6' */
          rtb_Gain_hc = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Integrator1_a = 1.0F;

          /* Signum: '<S423>/Sign6' */
          rtb_Gain_hc = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_Add4_d;

          /* Signum: '<S423>/Sign6' */
          rtb_Gain_hc = rtb_Add4_d;
        }

        /* End of Signum: '<S423>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S414>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_0 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S419>/Rem' incorporates:
         *  Constant: '<S419>/Constant1'
         */
        rtb_Add4_d = rt_remf(rtb_MathFunction_f_idx_0, 6.28318548F);

        /* Switch: '<S419>/Switch' incorporates:
         *  Abs: '<S419>/Abs'
         *  Constant: '<S419>/Constant'
         *  Constant: '<S425>/Constant'
         *  Product: '<S419>/Multiply'
         *  RelationalOperator: '<S425>/Compare'
         *  Sum: '<S419>/Add'
         */
        if (fabsf(rtb_Add4_d) > 3.14159274F) {
          /* Signum: '<S419>/Sign' */
          if (rtb_Add4_d < 0.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_0 = rtb_Add4_d;
          }

          /* End of Signum: '<S419>/Sign' */
          rtb_Add4_d -= 6.28318548F * rtb_MathFunction_f_idx_0;
        }

        /* End of Switch: '<S419>/Switch' */

        /* Abs: '<S412>/Abs' */
        rtb_Add4_d = fabsf(rtb_Add4_d);

        /* Update for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S430>/Constant'
         *  RelationalOperator: '<S430>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_m = (uint8_T)((uint32_T)(rtb_Add4_d
          <= 0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_m);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' */

        /* Update for Delay: '<S436>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S437>/Acceleration_Speed' incorporates:
         *  Constant: '<S437>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.MC_CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S484>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Saturation_n;
        FMS_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S414>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S417>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S417>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S413>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S423>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S423>/Sign3' */

        /* Signum: '<S423>/Sign4' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S423>/Sign4' */

        /* Update for DiscreteIntegrator: '<S417>/Integrator' incorporates:
         *  Constant: '<S423>/const'
         *  Gain: '<S423>/Gain3'
         *  Product: '<S423>/Multiply5'
         *  Product: '<S423>/Multiply6'
         *  Sum: '<S423>/Subtract4'
         *  Sum: '<S423>/Subtract5'
         *  Sum: '<S423>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Switch2_m - rtb_Integrator1_a) *
          FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Subtract3_od) * 0.5F) -
          rtb_Gain_hc * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.MC_YAWRATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.MC_YAWRATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.MC_YAWRATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S417>/Integrator' */
        /* End of Outputs for SubSystem: '<S39>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S39>/Hold' incorporates:
           *  ActionPort: '<S359>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S368>/Motion Status'
           *  Chart: '<S378>/Motion State'
           *  Chart: '<S390>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S39>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Hold' incorporates:
         *  ActionPort: '<S359>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S368>/Motion Status' incorporates:
         *  Abs: '<S368>/Abs'
         *  Constant: '<S368>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S378>/Motion State' incorporates:
         *  Abs: '<S378>/Abs'
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

        /* End of Chart: '<S378>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S390>/Motion State' incorporates:
         *  Constant: '<S390>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S390>/Square'
         *  Math: '<S390>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S390>/Sqrt'
         *  Sum: '<S390>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S389>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S389>/Hold Control' incorporates:
             *  ActionPort: '<S392>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S389>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S389>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S389>/Hold Control' incorporates:
           *  ActionPort: '<S392>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S389>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S389>/Brake Control' incorporates:
           *  ActionPort: '<S391>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S389>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S389>/Move Control' incorporates:
             *  ActionPort: '<S393>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S389>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S389>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S389>/Move Control' incorporates:
           *  ActionPort: '<S393>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S389>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S389>/Switch Case' */

        /* SwitchCase: '<S367>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S367>/Hold Control' incorporates:
             *  ActionPort: '<S370>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S367>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S367>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S367>/Hold Control' incorporates:
           *  ActionPort: '<S370>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S367>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S367>/Brake Control' incorporates:
           *  ActionPort: '<S369>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S367>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S367>/Move Control' incorporates:
             *  ActionPort: '<S371>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S367>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S367>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S367>/Move Control' incorporates:
           *  ActionPort: '<S371>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S367>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S367>/Switch Case' */

        /* SwitchCase: '<S377>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S377>/Hold Control' incorporates:
             *  ActionPort: '<S380>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S377>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S377>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S377>/Hold Control' incorporates:
           *  ActionPort: '<S380>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S377>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S377>/Brake Control' incorporates:
           *  ActionPort: '<S379>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S377>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S377>/Move Control' incorporates:
             *  ActionPort: '<S381>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S377>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S377>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S377>/Move Control' incorporates:
           *  ActionPort: '<S381>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S377>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S377>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S359>/Bus Assignment'
         *  Constant: '<S359>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S359>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S377>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S377>/Saturation' */

        /* Saturate: '<S389>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.MC_VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.MC_VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S389>/Saturation1' */

        /* Saturate: '<S367>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.MC_VEL_Z_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.MC_VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.MC_VEL_Z_LIM) {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.MC_VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S359>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S367>/Saturation1' */
        /* End of Outputs for SubSystem: '<S39>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
         *  ActionPort: '<S363>/Action Port'
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
       *  Math: '<S227>/Math Function'
       *  Product: '<S229>/Divide'
       *  Sum: '<S179>/Subtract'
       *  Sum: '<S249>/Sum1'
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
        /* Disable for SwitchCase: '<S205>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S195>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S150>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S37>/Offboard' incorporates:
         *  ActionPort: '<S151>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S336>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S339>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S340>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S340>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S340>/Multiply1' incorporates:
         *  Product: '<S340>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S340>/Divide' incorporates:
         *  Constant: '<S340>/Constant'
         *  Constant: '<S340>/R'
         *  Sqrt: '<S340>/Sqrt'
         *  Sum: '<S340>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S340>/Product3' incorporates:
         *  Constant: '<S340>/Constant1'
         *  Product: '<S340>/Multiply1'
         *  Sum: '<S340>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S340>/Multiply2' incorporates:
         *  Trigonometry: '<S340>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S339>/Sum' incorporates:
         *  Gain: '<S336>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S344>/Abs' incorporates:
         *  Abs: '<S347>/Abs1'
         *  Switch: '<S344>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S344>/Switch1' incorporates:
         *  Abs: '<S344>/Abs'
         *  Bias: '<S344>/Bias2'
         *  Bias: '<S344>/Bias3'
         *  Constant: '<S341>/Constant'
         *  Constant: '<S341>/Constant1'
         *  Constant: '<S346>/Constant'
         *  Gain: '<S344>/Gain1'
         *  Product: '<S344>/Multiply'
         *  RelationalOperator: '<S346>/Compare'
         *  Switch: '<S341>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S347>/Switch1' incorporates:
           *  Bias: '<S347>/Bias2'
           *  Bias: '<S347>/Bias3'
           *  Constant: '<S347>/Constant'
           *  Constant: '<S348>/Constant'
           *  Math: '<S347>/Math Function'
           *  RelationalOperator: '<S348>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S347>/Switch1' */

          /* Signum: '<S344>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S344>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S341>/Sum' incorporates:
         *  Gain: '<S336>/Gain1'
         *  Gain: '<S336>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S339>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S339>/Multiply' incorporates:
         *  Gain: '<S339>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S343>/Switch1' incorporates:
         *  Abs: '<S343>/Abs1'
         *  Bias: '<S343>/Bias2'
         *  Bias: '<S343>/Bias3'
         *  Constant: '<S343>/Constant'
         *  Constant: '<S345>/Constant'
         *  Math: '<S343>/Math Function'
         *  RelationalOperator: '<S345>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S343>/Switch1' */

        /* Product: '<S339>/Multiply' incorporates:
         *  Gain: '<S339>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S311>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S315>/Multiply1'
         *  Product: '<S316>/Multiply3'
         *  Product: '<S317>/Multiply1'
         *  SignalConversion: '<S31>/Signal Copy'
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
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S326>/Gain' incorporates:
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
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
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Switch: '<S318>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  DataTypeConversion: '<S336>/Data Type Conversion1'
           *  Product: '<S342>/Multiply1'
           *  Product: '<S342>/Multiply2'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S335>/lat_cmd valid'
           *  Sum: '<S342>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S315>/Multiply' incorporates:
           *  Constant: '<S323>/Constant'
           *  Constant: '<S324>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S314>/Logical Operator'
           *  RelationalOperator: '<S323>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S314>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S315>/Sum1'
           */
          rtb_Switch2_m = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Switch: '<S318>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  DataTypeConversion: '<S336>/Data Type Conversion1'
           *  Product: '<S342>/Multiply3'
           *  Product: '<S342>/Multiply4'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S335>/lon_cmd valid'
           *  Sum: '<S342>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S315>/Multiply' incorporates:
           *  Constant: '<S323>/Constant'
           *  Constant: '<S324>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S314>/Logical Operator'
           *  RelationalOperator: '<S323>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S314>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S315>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Switch: '<S318>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  DataTypeConversion: '<S336>/Data Type Conversion'
           *  DataTypeConversion: '<S336>/Data Type Conversion1'
           *  Gain: '<S336>/Gain2'
           *  Gain: '<S339>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S335>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S339>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S315>/Multiply' incorporates:
           *  Constant: '<S323>/Constant'
           *  Constant: '<S324>/Constant'
           *  Gain: '<S319>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S314>/Logical Operator'
           *  RelationalOperator: '<S323>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S314>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S315>/Sum1'
           */
          rtb_MathFunction_f_idx_0 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 1:
          /* SignalConversion: '<S334>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iy[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iy[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iy[2];

          /* SignalConversion: '<S334>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S334>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S334>/Trigonometric Function3' incorporates:
           *  Gain: '<S333>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S334>/Gain' incorporates:
           *  Gain: '<S333>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S334>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S334>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S334>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S334>/Trigonometric Function' incorporates:
           *  Gain: '<S333>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S334>/Trigonometric Function1' incorporates:
           *  Gain: '<S333>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Switch: '<S318>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  DataTypeConversion: '<S336>/Data Type Conversion1'
           *  Product: '<S342>/Multiply1'
           *  Product: '<S342>/Multiply2'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S335>/lat_cmd valid'
           *  Sum: '<S342>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S317>/Multiply' incorporates:
           *  Constant: '<S323>/Constant'
           *  Constant: '<S324>/Constant'
           *  DataStoreRead: '<S317>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S314>/Logical Operator'
           *  RelationalOperator: '<S323>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S314>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S317>/Sum1'
           */
          rtb_Switch2_m = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? (rtb_Saturation_n -
            FMS_U.INS_Out.x_R) + FMS_DW.home[0] : 0.0F;

          /* Switch: '<S318>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  DataTypeConversion: '<S336>/Data Type Conversion1'
           *  Product: '<S342>/Multiply3'
           *  Product: '<S342>/Multiply4'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S335>/lon_cmd valid'
           *  Sum: '<S342>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S317>/Multiply' incorporates:
           *  Constant: '<S323>/Constant'
           *  Constant: '<S324>/Constant'
           *  DataStoreRead: '<S317>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S314>/Logical Operator'
           *  RelationalOperator: '<S323>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S314>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S317>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? (rtb_Saturation_n -
            FMS_U.INS_Out.y_R) + FMS_DW.home[1] : 0.0F;

          /* Switch: '<S318>/Switch' incorporates:
           *  Constant: '<S338>/Constant'
           *  DataTypeConversion: '<S336>/Data Type Conversion'
           *  DataTypeConversion: '<S336>/Data Type Conversion1'
           *  Gain: '<S336>/Gain2'
           *  Gain: '<S339>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S335>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S339>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S317>/Multiply' incorporates:
           *  Constant: '<S323>/Constant'
           *  Constant: '<S324>/Constant'
           *  DataStoreRead: '<S317>/Data Store Read'
           *  Gain: '<S319>/Gain'
           *  Gain: '<S332>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S314>/Logical Operator'
           *  RelationalOperator: '<S323>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S314>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S317>/Sum1'
           */
          rtb_MathFunction_f_idx_0 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? (rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R)) + -FMS_DW.home[2] : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 2:
          /* SignalConversion: '<S330>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S330>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S330>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S316>/Data Store Read'
           *  Gain: '<S328>/Gain'
           *  Trigonometry: '<S330>/Trigonometric Function1'
           */
          rtb_Gain_hc = arm_cos_f32(-FMS_DW.home[3]);
          rtb_Transpose[4] = rtb_Gain_hc;

          /* Trigonometry: '<S330>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S316>/Data Store Read'
           *  Gain: '<S328>/Gain'
           *  Trigonometry: '<S330>/Trigonometric Function'
           */
          rtb_Transpose_tmp = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S330>/Gain' incorporates:
           *  Trigonometry: '<S330>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Transpose_tmp;

          /* SignalConversion: '<S330>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S330>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S330>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Transpose_tmp;

          /* Trigonometry: '<S330>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Gain_hc;

          /* SignalConversion: '<S330>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_ny[0];

          /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S330>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_ny[1];

          /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S330>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_ny[2];

          /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S331>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S331>/Constant4'
           */
          rtb_VectorConcatenate_m[5] = 0.0F;

          /* Gain: '<S329>/Gain' incorporates:
           *  DataStoreRead: '<S316>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S316>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S331>/Trigonometric Function3' incorporates:
           *  Gain: '<S329>/Gain'
           *  Trigonometry: '<S331>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(rtb_Add3_c);
          rtb_VectorConcatenate_m[4] = rtb_Saturation_n;

          /* Trigonometry: '<S331>/Trigonometric Function2' incorporates:
           *  Gain: '<S329>/Gain'
           *  Trigonometry: '<S331>/Trigonometric Function'
           */
          rtb_Add3_c = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S331>/Gain' incorporates:
           *  Trigonometry: '<S331>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_m[3] = -rtb_Add3_c;

          /* SignalConversion: '<S331>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S331>/Constant3'
           */
          rtb_VectorConcatenate_m[2] = 0.0F;

          /* Trigonometry: '<S331>/Trigonometric Function' */
          rtb_VectorConcatenate_m[1] = rtb_Add3_c;

          /* Trigonometry: '<S331>/Trigonometric Function1' */
          rtb_VectorConcatenate_m[0] = rtb_Saturation_n;

          /* RelationalOperator: '<S338>/Compare' incorporates:
           *  Constant: '<S338>/Constant'
           *  S-Function (sfix_bitop): '<S335>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S335>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S335>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S336>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S336>/Data Type Conversion'
           *  Gain: '<S336>/Gain2'
           *  Gain: '<S339>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S342>/Multiply1'
           *  Product: '<S342>/Multiply2'
           *  Product: '<S342>/Multiply3'
           *  Product: '<S342>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S339>/Sum1'
           *  Sum: '<S342>/Sum2'
           *  Sum: '<S342>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S318>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* Sum: '<S316>/Sum' incorporates:
           *  DataStoreRead: '<S316>/Data Store Read'
           *  Gain: '<S319>/Gain'
           *  Gain: '<S327>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Switch2_m = FMS_U.INS_Out.x_R - FMS_DW.home[0];
          rtb_Integrator1_a = FMS_U.INS_Out.y_R - FMS_DW.home[1];
          rtb_MathFunction_f_idx_0 = -FMS_U.INS_Out.h_R - (-FMS_DW.home[2]);

          /* RelationalOperator: '<S323>/Compare' incorporates:
           *  Constant: '<S323>/Constant'
           *  S-Function (sfix_bitop): '<S314>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S324>/Compare' incorporates:
           *  Constant: '<S324>/Constant'
           *  S-Function (sfix_bitop): '<S314>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S316>/Sum2' incorporates:
             *  Product: '<S316>/Multiply2'
             *  Switch: '<S318>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Product: '<S316>/Multiply' incorporates:
             *  Logic: '<S314>/Logical Operator'
             *  Product: '<S316>/Multiply2'
             *  Sum: '<S316>/Sum'
             *  Sum: '<S316>/Sum2'
             */
            tmp_3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Saturation_n -
              ((rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
                rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m) +
               rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0) :
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
          /* SignalConversion: '<S322>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_n[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_n[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_n[2];

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

          /* S-Function (sfix_bitop): '<S335>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S314>/lat_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S338>/Compare' incorporates:
           *  Constant: '<S338>/Constant'
           *  S-Function (sfix_bitop): '<S335>/lat_cmd valid'
           */
          tmp[0] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S335>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S314>/lon_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S338>/Compare' incorporates:
           *  Constant: '<S338>/Constant'
           *  S-Function (sfix_bitop): '<S335>/lon_cmd valid'
           */
          tmp[1] = (tmp_7 > 0U);

          /* S-Function (sfix_bitop): '<S335>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S314>/alt_cmd valid'
           */
          tmp_8 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S338>/Compare' incorporates:
           *  Constant: '<S338>/Constant'
           *  S-Function (sfix_bitop): '<S335>/alt_cmd valid'
           */
          tmp[2] = (tmp_8 > 0U);

          /* DataTypeConversion: '<S336>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S336>/Data Type Conversion'
           *  Gain: '<S336>/Gain2'
           *  Gain: '<S339>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S342>/Multiply1'
           *  Product: '<S342>/Multiply2'
           *  Product: '<S342>/Multiply3'
           *  Product: '<S342>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S339>/Sum1'
           *  Sum: '<S342>/Sum2'
           *  Sum: '<S342>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S318>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* Sum: '<S313>/Sum' incorporates:
           *  DataStoreRead: '<S313>/Data Store Read'
           *  Gain: '<S319>/Gain'
           *  Gain: '<S320>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Add3_c = FMS_U.INS_Out.x_R - FMS_DW.home[0];
          rtb_Subtract3_od = FMS_U.INS_Out.y_R - FMS_DW.home[1];
          rtb_Add4_d = -FMS_U.INS_Out.h_R - (-FMS_DW.home[2]);

          /* RelationalOperator: '<S323>/Compare' incorporates:
           *  Constant: '<S323>/Constant'
           *  S-Function (sfix_bitop): '<S314>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S314>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S324>/Compare' incorporates:
           *  Constant: '<S324>/Constant'
           */
          tmp_2[0] = (tmp_6 > 0U);
          tmp_2[1] = (tmp_7 > 0U);
          tmp_2[2] = (tmp_8 > 0U);

          /* Sum: '<S313>/Sum2' incorporates:
           *  Logic: '<S314>/Logical Operator'
           *  Product: '<S313>/Multiply'
           *  Product: '<S313>/Multiply2'
           *  Sum: '<S313>/Sum'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S318>/Switch' incorporates:
             *  Product: '<S313>/Multiply2'
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

          /* End of Sum: '<S313>/Sum2' */
          break;
        }

        /* End of MultiPortSwitch: '<S311>/Index Vector' */

        /* Trigonometry: '<S257>/Trigonometric Function1' incorporates:
         *  Gain: '<S256>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S257>/Trigonometric Function' incorporates:
         *  Gain: '<S256>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S257>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S257>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S257>/Gain' incorporates:
         *  Gain: '<S256>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S257>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S257>/Trigonometric Function3' incorporates:
         *  Gain: '<S256>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S257>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S257>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S257>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S246>/Index Vector' incorporates:
         *  Constant: '<S255>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S246>/Multiply'
         *  Product: '<S253>/Multiply'
         *  Product: '<S254>/Multiply3'
         *  RelationalOperator: '<S255>/Compare'
         *  S-Function (sfix_bitop): '<S252>/ax_cmd valid'
         *  S-Function (sfix_bitop): '<S252>/ay_cmd valid'
         *  S-Function (sfix_bitop): '<S252>/az_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S246>/Multiply' incorporates:
           *  Constant: '<S255>/Constant'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S252>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/az_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_MathFunction_f_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 1:
          /* Product: '<S246>/Multiply' incorporates:
           *  Constant: '<S255>/Constant'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S252>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S252>/az_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_MathFunction_f_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 2:
          /* SignalConversion: '<S259>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S259>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S258>/Gain' incorporates:
           *  DataStoreRead: '<S254>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S254>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S259>/Trigonometric Function3' incorporates:
           *  Gain: '<S258>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S259>/Gain' incorporates:
           *  Gain: '<S258>/Gain'
           *  Trigonometry: '<S259>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S259>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S259>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S259>/Trigonometric Function' incorporates:
           *  Gain: '<S258>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S259>/Trigonometric Function1' incorporates:
           *  Gain: '<S258>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S259>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S246>/Multiply' incorporates:
           *  Constant: '<S255>/Constant'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S252>/ax_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S259>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S246>/Multiply' incorporates:
           *  Constant: '<S255>/Constant'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S252>/ay_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S259>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S246>/Multiply' incorporates:
           *  Constant: '<S255>/Constant'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S252>/az_cmd valid'
           */
          rtb_MathFunction_f_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
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

        /* End of MultiPortSwitch: '<S246>/Index Vector' */

        /* Sum: '<S307>/Sum1' incorporates:
         *  Constant: '<S307>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S307>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Saturation_n = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S308>/Abs' */
        rtb_Add3_c = fabsf(rtb_Saturation_n);

        /* Switch: '<S308>/Switch' incorporates:
         *  Constant: '<S308>/Constant'
         *  Constant: '<S309>/Constant'
         *  Product: '<S308>/Multiply'
         *  RelationalOperator: '<S309>/Compare'
         *  Sum: '<S308>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S308>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* End of Signum: '<S308>/Sign' */
          rtb_Saturation_n *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S308>/Switch' */

        /* Saturate: '<S307>/Saturation' */
        if (rtb_Saturation_n > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else {
          if (rtb_Saturation_n < -0.314159274F) {
            rtb_Saturation_n = -0.314159274F;
          }
        }

        /* End of Saturate: '<S307>/Saturation' */

        /* Gain: '<S304>/Gain2' */
        rtb_Saturation_n *= FMS_PARAM.MC_YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S248>/Sum' incorporates:
         *  Constant: '<S306>/Constant'
         *  Constant: '<S310>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S304>/Multiply2'
         *  Product: '<S305>/Multiply1'
         *  RelationalOperator: '<S306>/Compare'
         *  RelationalOperator: '<S310>/Compare'
         *  S-Function (sfix_bitop): '<S304>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S305>/psi_rate_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Subtract3_od = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                            rtb_Saturation_n : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask
          & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S311>/Gain1' */
        rtb_Add3_c = FMS_PARAM.MC_XY_P * rtb_MatrixConcatenate3[0];
        rtb_Add4_d = FMS_PARAM.MC_XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S311>/Gain2' */
        rtb_Saturation_n = FMS_PARAM.MC_Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S356>/Trigonometric Function1' incorporates:
         *  Gain: '<S355>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S356>/Trigonometric Function' incorporates:
         *  Gain: '<S355>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S356>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S356>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S356>/Gain' incorporates:
         *  Gain: '<S355>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S356>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S356>/Trigonometric Function3' incorporates:
         *  Gain: '<S355>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S356>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S356>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S356>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S312>/Index Vector' incorporates:
         *  Constant: '<S354>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S312>/Multiply'
         *  Product: '<S351>/Multiply'
         *  Product: '<S352>/Multiply3'
         *  RelationalOperator: '<S354>/Compare'
         *  S-Function (sfix_bitop): '<S350>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S350>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S350>/w_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S312>/Multiply' incorporates:
           *  Constant: '<S354>/Constant'
           *  RelationalOperator: '<S354>/Compare'
           *  S-Function (sfix_bitop): '<S350>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S350>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S350>/w_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_MathFunction_f_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 1:
          /* Product: '<S312>/Multiply' incorporates:
           *  Constant: '<S354>/Constant'
           *  RelationalOperator: '<S354>/Compare'
           *  S-Function (sfix_bitop): '<S350>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S350>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S350>/w_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_MathFunction_f_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_m);
          }
          break;

         case 2:
          /* SignalConversion: '<S358>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S358>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S357>/Gain' incorporates:
           *  DataStoreRead: '<S352>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S352>/Subtract'
           */
          rtb_Switch2_m = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S358>/Trigonometric Function3' incorporates:
           *  Gain: '<S357>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Switch2_m);

          /* Gain: '<S358>/Gain' incorporates:
           *  Gain: '<S357>/Gain'
           *  Trigonometry: '<S358>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Switch2_m);

          /* SignalConversion: '<S358>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S358>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S358>/Trigonometric Function' incorporates:
           *  Gain: '<S357>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Switch2_m);

          /* Trigonometry: '<S358>/Trigonometric Function1' incorporates:
           *  Gain: '<S357>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Switch2_m);

          /* SignalConversion: '<S358>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S312>/Multiply' incorporates:
           *  Constant: '<S354>/Constant'
           *  RelationalOperator: '<S354>/Compare'
           *  S-Function (sfix_bitop): '<S350>/u_cmd valid'
           */
          rtb_Switch2_m = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S358>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S312>/Multiply' incorporates:
           *  Constant: '<S354>/Constant'
           *  RelationalOperator: '<S354>/Compare'
           *  S-Function (sfix_bitop): '<S350>/v_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S358>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S312>/Multiply' incorporates:
           *  Constant: '<S354>/Constant'
           *  RelationalOperator: '<S354>/Compare'
           *  S-Function (sfix_bitop): '<S350>/w_cmd valid'
           */
          rtb_MathFunction_f_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_MathFunction_f_idx_0 +
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

        /* End of MultiPortSwitch: '<S312>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_Add4_d;

        /* Sum: '<S249>/Sum1' */
        rtb_Saturation_n += rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S267>/Switch' incorporates:
         *  Constant: '<S282>/Constant'
         *  Constant: '<S284>/Constant'
         *  Constant: '<S285>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S282>/Compare'
         *  RelationalOperator: '<S284>/Compare'
         *  RelationalOperator: '<S285>/Compare'
         *  S-Function (sfix_bitop): '<S267>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S267>/y_v_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S267>/Logical Operator' incorporates:
           *  Constant: '<S283>/Constant'
           *  Constant: '<S284>/Constant'
           *  Constant: '<S285>/Constant'
           *  RelationalOperator: '<S283>/Compare'
           *  RelationalOperator: '<S284>/Compare'
           *  RelationalOperator: '<S285>/Compare'
           *  S-Function (sfix_bitop): '<S267>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S267>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S267>/y_v_cmd'
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

        /* End of Switch: '<S267>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S247>/u_cmd_valid' */
        /* MATLAB Function: '<S279>/bit_shift' incorporates:
         *  DataTypeConversion: '<S247>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_a4 << 6);

        /* End of Outputs for SubSystem: '<S247>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S247>/v_cmd_valid' */
        /* MATLAB Function: '<S280>/bit_shift' incorporates:
         *  DataTypeConversion: '<S247>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S247>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S268>/Switch' incorporates:
         *  Constant: '<S287>/Constant'
         *  Constant: '<S288>/Constant'
         *  Constant: '<S290>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S287>/Compare'
         *  RelationalOperator: '<S288>/Compare'
         *  RelationalOperator: '<S290>/Compare'
         *  S-Function (sfix_bitop): '<S268>/ax_cmd'
         *  S-Function (sfix_bitop): '<S268>/ay_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S268>/Logical Operator' incorporates:
           *  Constant: '<S288>/Constant'
           *  Constant: '<S290>/Constant'
           *  RelationalOperator: '<S288>/Compare'
           *  RelationalOperator: '<S290>/Compare'
           *  S-Function (sfix_bitop): '<S268>/ax_cmd'
           *  S-Function (sfix_bitop): '<S268>/ay_cmd'
           */
          rtb_LogicalOperator_a4 = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_a4;
        } else {
          rtb_LogicalOperator_a4 = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S268>/Switch' */
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

        /* Saturate: '<S248>/Saturation' */
        if (rtb_Subtract3_od > FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.MC_YAWRATE_LIM;
        } else if (rtb_Subtract3_od < -FMS_PARAM.MC_YAWRATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_od;
        }

        /* End of Saturate: '<S248>/Saturation' */

        /* Saturate: '<S249>/Saturation2' */
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

        /* End of Saturate: '<S249>/Saturation2' */

        /* Saturate: '<S249>/Saturation1' */
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

        /* End of Saturate: '<S249>/Saturation1' */

        /* Saturate: '<S249>/Saturation3' */
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

        /* End of Saturate: '<S249>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S247>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S247>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S247>/throttle_cmd_valid' */
        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  Constant: '<S260>/Constant'
         *  Constant: '<S261>/Constant'
         *  Constant: '<S262>/Constant'
         *  Constant: '<S263>/Constant'
         *  Constant: '<S264>/Constant'
         *  Constant: '<S265>/Constant'
         *  Constant: '<S266>/Constant'
         *  Constant: '<S286>/Constant'
         *  Constant: '<S289>/Constant'
         *  DataTypeConversion: '<S247>/Data Type Conversion10'
         *  DataTypeConversion: '<S247>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S269>/bit_shift'
         *  MATLAB Function: '<S270>/bit_shift'
         *  MATLAB Function: '<S271>/bit_shift'
         *  MATLAB Function: '<S273>/bit_shift'
         *  MATLAB Function: '<S274>/bit_shift'
         *  MATLAB Function: '<S275>/bit_shift'
         *  MATLAB Function: '<S276>/bit_shift'
         *  MATLAB Function: '<S277>/bit_shift'
         *  MATLAB Function: '<S278>/bit_shift'
         *  MATLAB Function: '<S281>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S260>/Compare'
         *  RelationalOperator: '<S261>/Compare'
         *  RelationalOperator: '<S262>/Compare'
         *  RelationalOperator: '<S263>/Compare'
         *  RelationalOperator: '<S264>/Compare'
         *  RelationalOperator: '<S265>/Compare'
         *  RelationalOperator: '<S266>/Compare'
         *  RelationalOperator: '<S286>/Compare'
         *  RelationalOperator: '<S289>/Compare'
         *  S-Function (sfix_bitop): '<S247>/p_cmd'
         *  S-Function (sfix_bitop): '<S247>/phi_cmd'
         *  S-Function (sfix_bitop): '<S247>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S247>/q_cmd'
         *  S-Function (sfix_bitop): '<S247>/r_cmd'
         *  S-Function (sfix_bitop): '<S247>/theta_cmd'
         *  S-Function (sfix_bitop): '<S247>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S267>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S268>/az_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         *  Sum: '<S247>/Add'
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

        /* End of Outputs for SubSystem: '<S247>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S247>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S247>/q_cmd_valid' */
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
           *  Chart: '<S196>/Motion Status'
           *  Chart: '<S206>/Motion State'
           *  Delay: '<S158>/Delay'
           *  Delay: '<S180>/Delay'
           *  Delay: '<S180>/Delay1'
           *  DiscreteIntegrator: '<S161>/Integrator'
           *  DiscreteIntegrator: '<S161>/Integrator1'
           *  DiscreteIntegrator: '<S181>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S182>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
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
          /* Disable for SwitchCase: '<S205>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S195>/Switch Case' */
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

          /* InitializeConditions for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

          /* InitializeConditions for Delay: '<S158>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S206>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S196>/Motion Status' */
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
         *  Constant: '<S245>/Constant'
         *  RelationalOperator: '<S245>/Compare'
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
        /* RelationalOperator: '<S192>/Compare' incorporates:
         *  Constant: '<S192>/Constant'
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
          rtb_Add4_d = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Add4_d = FMS_PARAM.MC_CRUISE_SPEED;
        }

        /* End of Switch: '<S176>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S180>/Sum' incorporates:
         *  Delay: '<S180>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_c[0];

        /* Sum: '<S181>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Transpose_tmp = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S180>/Sum' incorporates:
         *  Delay: '<S180>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_c[1];

        /* Sum: '<S181>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_p_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S244>/Sqrt' incorporates:
         *  Math: '<S244>/Square'
         *  Sum: '<S181>/Sum'
         *  Sum: '<S244>/Sum of Elements'
         */
        rtb_Add3_c = sqrtf(rtb_Transpose_tmp * rtb_Transpose_tmp +
                           rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0);

        /* Gain: '<S181>/L1_GAIN' incorporates:
         *  Gain: '<S156>/Gain'
         */
        rtb_Saturation_n = FMS_PARAM.MC_L1_GAIN * rtb_Add4_d;

        /* Switch: '<S181>/Switch' incorporates:
         *  Gain: '<S181>/L1_GAIN'
         *  Sum: '<S181>/Sum2'
         */
        if (rtb_Add3_c - rtb_Saturation_n >= 0.0F) {
          B = rtb_Add4_d;
        } else {
          /* Gain: '<S181>/Gain' */
          B = 0.5F * rtb_Add3_c;

          /* Switch: '<S242>/Switch2' incorporates:
           *  Constant: '<S181>/Constant1'
           *  RelationalOperator: '<S242>/LowerRelop1'
           *  RelationalOperator: '<S242>/UpperRelop'
           *  Switch: '<S242>/Switch'
           */
          if (B > rtb_Add4_d) {
            B = rtb_Add4_d;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S242>/Switch' incorporates:
               *  Constant: '<S181>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S242>/Switch2' */
        }

        /* End of Switch: '<S181>/Switch' */

        /* DiscreteIntegrator: '<S181>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Switch: '<S243>/Switch2' incorporates:
         *  Constant: '<S181>/Constant2'
         *  DiscreteIntegrator: '<S181>/Acceleration_Speed'
         *  RelationalOperator: '<S243>/LowerRelop1'
         *  RelationalOperator: '<S243>/UpperRelop'
         *  Switch: '<S243>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Add4_d) {
          rtb_Integrator1_a = rtb_Add4_d;
        } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
          /* Switch: '<S243>/Switch' incorporates:
           *  Constant: '<S181>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE;
        }

        /* End of Switch: '<S243>/Switch2' */

        /* Switch: '<S181>/Switch1' incorporates:
         *  Sum: '<S181>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Switch2_m = B;
        } else {
          rtb_Switch2_m = rtb_Integrator1_a;
        }

        /* End of Switch: '<S181>/Switch1' */

        /* DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRese !=
             0)) {
          FMS_DW.l1_heading = 0.0F;
        }

        /* Math: '<S238>/Math Function' incorporates:
         *  Math: '<S236>/Math Function'
         *  SignalConversion: '<S238>/TmpSignal ConversionAtMath FunctionInport1'
         *  Switch: '<S156>/Switch'
         *  Switch: '<S184>/Switch'
         */
        rtb_Gain_hc = rtb_Subtract3_od * rtb_Subtract3_od;
        rtb_Add3_c = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0;

        /* Sum: '<S238>/Sum of Elements' incorporates:
         *  Math: '<S238>/Math Function'
         */
        rtb_MathFunction_p_idx_0 = rtb_Add3_c + rtb_Gain_hc;

        /* Math: '<S238>/Math Function1' incorporates:
         *  Sum: '<S238>/Sum of Elements'
         *
         * About '<S238>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          rtb_Integrator1_a = -sqrtf(fabsf(rtb_MathFunction_p_idx_0));
        } else {
          rtb_Integrator1_a = sqrtf(rtb_MathFunction_p_idx_0);
        }

        /* End of Math: '<S238>/Math Function1' */

        /* Switch: '<S238>/Switch' incorporates:
         *  Constant: '<S238>/Constant'
         *  Product: '<S238>/Product'
         */
        if (rtb_Integrator1_a > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_MathFunction_f_idx_0;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Subtract3_od;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Integrator1_a;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S238>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S206>/Motion State' incorporates:
         *  Constant: '<S206>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S206>/Square'
         *  Math: '<S206>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S206>/Sqrt'
         *  Sum: '<S206>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S205>/Switch Case' incorporates:
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
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
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
          if (FMS_DW.SwitchCase_ActiveSubsystem_ai != rtPrevAction) {
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
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S205>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S205>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S196>/Motion Status' incorporates:
         *  Abs: '<S196>/Abs'
         *  Constant: '<S196>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S195>/Switch Case' incorporates:
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
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e3,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S195>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S195>/Brake Control' incorporates:
           *  ActionPort: '<S197>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e3);

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
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e3,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S195>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S195>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S184>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Transpose_tmp = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_MathFunction_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S190>/Sqrt' incorporates:
         *  Math: '<S190>/Square'
         *  Sum: '<S184>/Sum'
         *  Sum: '<S190>/Sum of Elements'
         */
        rtb_Integrator1_a = sqrtf(rtb_MathFunction_p_idx_0 *
          rtb_MathFunction_p_idx_0 + rtb_Transpose_tmp * rtb_Transpose_tmp);

        /* Relay: '<S184>/Relay' */
        if (rtb_Integrator1_a >= 2.0F * FMS_PARAM.MC_ACCEPT_R) {
          FMS_DW.Relay_Mode = true;
        } else {
          if (rtb_Integrator1_a <= FMS_PARAM.MC_ACCEPT_R) {
            FMS_DW.Relay_Mode = false;
          }
        }

        /* Switch: '<S156>/Switch' incorporates:
         *  Relay: '<S184>/Relay'
         *  Switch: '<S184>/Switch'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S205>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_MathFunction_f_idx_0 = FMS_PARAM.MC_VEL_XY_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_MathFunction_f_idx_0 = -FMS_PARAM.MC_VEL_XY_LIM;
          } else {
            rtb_MathFunction_f_idx_0 = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_MathFunction_f_idx_1 = FMS_PARAM.MC_VEL_XY_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.MC_VEL_XY_LIM) {
            rtb_MathFunction_f_idx_1 = -FMS_PARAM.MC_VEL_XY_LIM;
          } else {
            rtb_MathFunction_f_idx_1 = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S205>/Saturation1' */

          /* Saturate: '<S195>/Saturation1' */
          if (FMS_B.Merge_e3 > FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_MathFunction_f_idx_2 = FMS_PARAM.MC_VEL_Z_LIM;
          } else if (FMS_B.Merge_e3 < -FMS_PARAM.MC_VEL_Z_LIM) {
            rtb_MathFunction_f_idx_2 = -FMS_PARAM.MC_VEL_Z_LIM;
          } else {
            rtb_MathFunction_f_idx_2 = FMS_B.Merge_e3;
          }

          /* End of Saturate: '<S195>/Saturation1' */
        } else {
          if (FMS_DW.Relay_Mode) {
            /* SignalConversion: '<S241>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S241>/Constant4'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S240>/Gain' incorporates:
             *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Sum: '<S234>/Add'
             *  Switch: '<S184>/Switch'
             */
            rtb_MathFunction_f_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S241>/Trigonometric Function3' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[4] = arm_cos_f32(rtb_MathFunction_f_idx_1);

            /* Gain: '<S241>/Gain' incorporates:
             *  Switch: '<S184>/Switch'
             *  Trigonometry: '<S241>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(rtb_MathFunction_f_idx_1);

            /* SignalConversion: '<S241>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S241>/Constant3'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[2] = 0.0F;

            /* Trigonometry: '<S241>/Trigonometric Function' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[1] = arm_sin_f32(rtb_MathFunction_f_idx_1);

            /* Trigonometry: '<S241>/Trigonometric Function1' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[0] = arm_cos_f32(rtb_MathFunction_f_idx_1);

            /* SignalConversion: '<S241>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_d[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_d[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Sum: '<S236>/Sum of Elements' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Gain_hc += rtb_Add3_c;

            /* Math: '<S236>/Math Function1' incorporates:
             *  Sum: '<S236>/Sum of Elements'
             *  Switch: '<S184>/Switch'
             *
             * About '<S236>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Gain_hc < 0.0F) {
              rtb_MathFunction_f_idx_1 = -sqrtf(fabsf(rtb_Gain_hc));
            } else {
              rtb_MathFunction_f_idx_1 = sqrtf(rtb_Gain_hc);
            }

            /* End of Math: '<S236>/Math Function1' */

            /* Switch: '<S236>/Switch' incorporates:
             *  Constant: '<S236>/Constant'
             *  Product: '<S236>/Product'
             *  Switch: '<S184>/Switch'
             */
            if (rtb_MathFunction_f_idx_1 <= 0.0F) {
              rtb_Subtract3_od = 0.0F;
              rtb_MathFunction_f_idx_0 = 0.0F;
              rtb_MathFunction_f_idx_1 = 1.0F;
            }

            /* End of Switch: '<S236>/Switch' */

            /* Product: '<S232>/Multiply2' incorporates:
             *  Product: '<S236>/Divide'
             *  Switch: '<S184>/Switch'
             */
            rtb_Subtract3_od = rtb_Subtract3_od / rtb_MathFunction_f_idx_1 *
              rtb_Switch2_m;
            rtb_MathFunction_f_idx_0 = rtb_MathFunction_f_idx_0 /
              rtb_MathFunction_f_idx_1 * rtb_Switch2_m;
            for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++)
            {
              rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0
                + 3] * rtb_MathFunction_f_idx_0 + rtb_Transpose[rtb_Compare_bv_0]
                * rtb_Subtract3_od;
            }

            /* Switch: '<S184>/Switch' incorporates:
             *  Product: '<S180>/Multiply'
             */
            rtb_MathFunction_f_idx_0 = rtb_Transpose_0[0];
            rtb_MathFunction_f_idx_1 = rtb_Transpose_0[1];
          } else {
            /* SignalConversion: '<S191>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_p[0];
            rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_p[1];
            rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_p[2];

            /* SignalConversion: '<S191>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S191>/Constant4'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Trigonometry: '<S191>/Trigonometric Function3' incorporates:
             *  Gain: '<S188>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S191>/Gain' incorporates:
             *  Gain: '<S188>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S184>/Switch'
             *  Trigonometry: '<S191>/Trigonometric Function2'
             */
            rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S191>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S191>/Constant3'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Trigonometry: '<S191>/Trigonometric Function' incorporates:
             *  Gain: '<S188>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S191>/Trigonometric Function1' incorporates:
             *  Gain: '<S188>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Switch: '<S184>/Switch'
             */
            rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Saturate: '<S184>/Saturation1' incorporates:
             *  Switch: '<S184>/Switch'
             */
            rtb_Gain_hc = FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
            rtb_Integrator1_a = -FMS_PARAM.MC_VEL_XY_LIM / 5.0F;
            for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++)
            {
              rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0
                + 3] * rtb_MathFunction_p_idx_0 + rtb_Transpose[rtb_Compare_bv_0]
                * rtb_Transpose_tmp;
            }

            /* Saturate: '<S184>/Saturation1' incorporates:
             *  Gain: '<S184>/Gain2'
             *  Product: '<S184>/Multiply'
             *  Sum: '<S184>/Sum'
             *  Switch: '<S184>/Switch'
             */
            rtb_MathFunction_f_idx_0 = FMS_PARAM.MC_XY_P * rtb_Transpose_0[0];
            if (rtb_MathFunction_f_idx_0 > rtb_Gain_hc) {
              rtb_MathFunction_f_idx_0 = rtb_Gain_hc;
            } else {
              if (rtb_MathFunction_f_idx_0 < rtb_Integrator1_a) {
                rtb_MathFunction_f_idx_0 = rtb_Integrator1_a;
              }
            }

            rtb_MathFunction_f_idx_1 = FMS_PARAM.MC_XY_P * rtb_Transpose_0[1];
            if (rtb_MathFunction_f_idx_1 > rtb_Gain_hc) {
              rtb_MathFunction_f_idx_1 = rtb_Gain_hc;
            } else {
              if (rtb_MathFunction_f_idx_1 < rtb_Integrator1_a) {
                rtb_MathFunction_f_idx_1 = rtb_Integrator1_a;
              }
            }
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S183>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Transpose_tmp = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S183>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Subtract3_od = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S183>/Divide' incorporates:
           *  Math: '<S185>/Square'
           *  Math: '<S186>/Square'
           *  Sqrt: '<S185>/Sqrt'
           *  Sqrt: '<S186>/Sqrt'
           *  Sum: '<S183>/Sum'
           *  Sum: '<S183>/Sum1'
           *  Sum: '<S185>/Sum of Elements'
           *  Sum: '<S186>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_Add3_c * rtb_Add3_c + rtb_Subtract3_od *
                             rtb_Subtract3_od) / sqrtf(rtb_Transpose_tmp *
            rtb_Transpose_tmp + rtb_MathFunction_p_idx_0 *
            rtb_MathFunction_p_idx_0);

          /* Saturate: '<S183>/Saturation' */
          if (rtb_Add3_c > 1.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            if (rtb_Add3_c < 0.0F) {
              rtb_Add3_c = 0.0F;
            }
          }

          /* End of Saturate: '<S183>/Saturation' */

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
          rtb_MathFunction_f_idx_2 = (FMS_U.INS_Out.h_R -
            ((FMS_B.Cmd_In.sp_waypoint[2] - FMS_B.Cmd_In.cur_waypoint[2]) *
             rtb_Add3_c + FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.MC_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S173>/Saturation1' */
          if (rtb_MathFunction_f_idx_2 > FMS_PARAM.MC_TAKEOFF_SPEED) {
            rtb_MathFunction_f_idx_2 = FMS_PARAM.MC_TAKEOFF_SPEED;
          } else {
            if (rtb_MathFunction_f_idx_2 < -FMS_PARAM.MC_LAND_SPEED) {
              rtb_MathFunction_f_idx_2 = -FMS_PARAM.MC_LAND_SPEED;
            }
          }

          /* End of Saturate: '<S173>/Saturation1' */
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
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S165>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S165>/Switch' */

        /* Gain: '<S160>/Gain2' */
        B *= FMS_PARAM.MC_YAW_P;

        /* Saturate: '<S160>/Saturation' */
        if (B > FMS_PARAM.MC_YAWRATE_LIM) {
          B = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (B < -FMS_PARAM.MC_YAWRATE_LIM) {
            B = -FMS_PARAM.MC_YAWRATE_LIM;
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
        FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_1;
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_f_idx_2;
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S226>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S226>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Gain_hc = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S226>/Math Function1' incorporates:
         *  Sum: '<S226>/Sum of Elements'
         *
         * About '<S226>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S226>/Math Function1' */

        /* Switch: '<S226>/Switch' incorporates:
         *  Constant: '<S226>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S226>/Product'
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

        /* End of Switch: '<S226>/Switch' */

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
        rtb_Gain_hc = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S172>/Math Function1' incorporates:
         *  Sum: '<S172>/Sum of Elements'
         *
         * About '<S172>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
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

        /* Sum: '<S239>/Sum of Elements' incorporates:
         *  Math: '<S239>/Math Function'
         *  Sum: '<S180>/Sum1'
         */
        rtb_Gain_hc = rtb_Switch_f3_idx_0 * rtb_Switch_f3_idx_0 +
          rtb_Switch_f3_idx_1 * rtb_Switch_f3_idx_1;

        /* Math: '<S239>/Math Function1' incorporates:
         *  Sum: '<S239>/Sum of Elements'
         *
         * About '<S239>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S239>/Math Function1' */

        /* Switch: '<S239>/Switch' incorporates:
         *  Constant: '<S239>/Constant'
         *  Product: '<S239>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_f3_idx_2 = B;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S239>/Switch' */

        /* Product: '<S226>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S229>/Sum of Elements' incorporates:
         *  Math: '<S229>/Math Function'
         *  SignalConversion: '<S229>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Gain_hc = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S229>/Math Function1' incorporates:
         *  Sum: '<S229>/Sum of Elements'
         *
         * About '<S229>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_hc < 0.0F) {
          B = -sqrtf(fabsf(rtb_Gain_hc));
        } else {
          B = sqrtf(rtb_Gain_hc);
        }

        /* End of Math: '<S229>/Math Function1' */

        /* Switch: '<S229>/Switch' incorporates:
         *  Constant: '<S229>/Constant'
         *  Product: '<S229>/Product'
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

        /* End of Switch: '<S229>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S178>/NearbyRefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, rtb_Saturation_n, rtb_Sum_ff,
                        &rtb_Integrator1_a);

        /* MATLAB Function: '<S178>/SearchL1RefWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Subtract3_od = rtb_Add3_c * rtb_Add3_c + rtb_Subtract3_od *
          rtb_Subtract3_od;

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
                     rtb_Saturation_n * rtb_Saturation_n) * (4.0F *
          rtb_Subtract3_od);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_MathFunction_p_idx_0 = 0.0F;
        rtb_MathFunction_p_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          rtb_MathFunction_h_idx_1 = sqrtf(D);
          D = (-B + rtb_MathFunction_h_idx_1) / (2.0F * rtb_Subtract3_od);
          rtb_Subtract3_od = (-B - rtb_MathFunction_h_idx_1) / (2.0F *
            rtb_Subtract3_od);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Subtract3_od >= 0.0F) &&
              (rtb_Subtract3_od <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, rtb_Subtract3_od);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((rtb_Subtract3_od >= 0.0F) && (rtb_Subtract3_od <= 1.0F)) {
              rtb_Add3_c = rtb_Subtract3_od;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Subtract3_od);
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
        /* MATLAB Function: '<S178>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Transpose_tmp = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Gain_hc = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Subtract3_od = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                            rtb_Gain_hc + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Transpose_tmp) /
          (rtb_Transpose_tmp * rtb_Transpose_tmp + rtb_Gain_hc * rtb_Gain_hc);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Subtract3_od <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Subtract3_od >= 1.0F);
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
          rtb_P_l_idx_0 = rtb_Subtract3_od * rtb_Transpose_tmp +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Switch: '<S178>/Switch1' incorporates:
         *  Constant: '<S219>/Constant'
         *  RelationalOperator: '<S219>/Compare'
         */
        if (rtb_Integrator1_a <= 0.0F) {
          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S218>/Constant'
           *  MATLAB Function: '<S178>/SearchL1RefWP'
           *  RelationalOperator: '<S218>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0;
            rtb_Sum_ff[1] = rtb_MathFunction_p_idx_1;
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
              rtb_Sum_ff[1] = rtb_Subtract3_od * rtb_Gain_hc +
                FMS_B.Cmd_In.cur_waypoint[1];

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
        rtb_Transpose_tmp = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Transpose_tmp;
        rtb_Add3_c = rtb_Transpose_tmp * rtb_Transpose_tmp;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S179>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S227>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose_tmp = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S227>/Math Function' incorporates:
         *  Math: '<S225>/Square'
         */
        rtb_Gain_hc = rtb_Transpose_tmp * rtb_Transpose_tmp;

        /* Sum: '<S227>/Sum of Elements' incorporates:
         *  Math: '<S227>/Math Function'
         */
        rtb_Add3_c += rtb_Gain_hc;

        /* Math: '<S227>/Math Function1' incorporates:
         *  Sum: '<S227>/Sum of Elements'
         *
         * About '<S227>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S227>/Math Function1' */

        /* Switch: '<S227>/Switch' incorporates:
         *  Constant: '<S227>/Constant'
         *  Product: '<S227>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Transpose_tmp;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S227>/Switch' */

        /* Product: '<S227>/Divide' */
        D = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S230>/Sum of Elements' incorporates:
         *  Math: '<S230>/Math Function'
         *  SignalConversion: '<S230>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 + D * D;

        /* Math: '<S230>/Math Function1' incorporates:
         *  Sum: '<S230>/Sum of Elements'
         *
         * About '<S230>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S230>/Math Function1' */

        /* Switch: '<S230>/Switch' incorporates:
         *  Constant: '<S230>/Constant'
         *  Product: '<S230>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = D;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S230>/Switch' */

        /* Product: '<S230>/Divide' */
        D = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];

        /* Math: '<S225>/Square' */
        rtb_Add3_c = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S239>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S172>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S238>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S230>/Divide' incorporates:
         *  Product: '<S229>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S229>/Divide' */
        rtb_Transpose_tmp = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S239>/Divide' */
        rtb_MathFunction_p_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S172>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S238>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S237>/Subtract' incorporates:
         *  Product: '<S237>/Multiply'
         *  Product: '<S237>/Multiply1'
         */
        B = rtb_MathFunction_p_idx_0 * rtb_MathFunction_f_idx_0 -
          rtb_MathFunction_p_idx_1 * rtb_Switch_mp_idx_0;

        /* Signum: '<S233>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S233>/Sign1' */

        /* Switch: '<S233>/Switch2' incorporates:
         *  Constant: '<S233>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S233>/Switch2' */

        /* DotProduct: '<S233>/Dot Product' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_0 *
          rtb_MathFunction_p_idx_0 + rtb_MathFunction_f_idx_0 *
          rtb_MathFunction_p_idx_1;

        /* Trigonometry: '<S233>/Acos' incorporates:
         *  DotProduct: '<S233>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_0 > 1.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          }
        }

        /* Product: '<S233>/Multiply' incorporates:
         *  Trigonometry: '<S233>/Acos'
         */
        B *= acosf(rtb_MathFunction_f_idx_0);

        /* Abs: '<S180>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S231>/Compare' incorporates:
         *  Constant: '<S231>/Constant'
         *  Delay: '<S180>/Delay1'
         */
        FMS_DW.Delay1_DSTATE = (B > 1.57079637F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S224>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S224>/Square'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S224>/Sum of Elements'
         */
        rtb_MathFunction_f_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S179>/Square' */
        rtb_Subtract3_od = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0;

        /* Sum: '<S228>/Subtract' incorporates:
         *  Product: '<S228>/Multiply'
         *  Product: '<S228>/Multiply1'
         */
        rtb_MathFunction_f_idx_0 = D * rtb_Transpose_tmp -
          rtb_MathFunction_h_idx_1 * rtb_Sum_ff[0];

        /* Signum: '<S223>/Sign1' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S223>/Sign1' */

        /* Switch: '<S223>/Switch2' incorporates:
         *  Constant: '<S223>/Constant4'
         */
        if (rtb_MathFunction_f_idx_0 == 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        }

        /* End of Switch: '<S223>/Switch2' */

        /* DotProduct: '<S223>/Dot Product' */
        rtb_Transpose_tmp = rtb_Sum_ff[0] * D + rtb_Transpose_tmp *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S223>/Acos' incorporates:
         *  DotProduct: '<S223>/Dot Product'
         */
        if (rtb_Transpose_tmp > 1.0F) {
          rtb_Transpose_tmp = 1.0F;
        } else {
          if (rtb_Transpose_tmp < -1.0F) {
            rtb_Transpose_tmp = -1.0F;
          }
        }

        /* Product: '<S223>/Multiply' incorporates:
         *  Trigonometry: '<S223>/Acos'
         */
        rtb_MathFunction_f_idx_0 *= acosf(rtb_Transpose_tmp);

        /* Saturate: '<S179>/Saturation' */
        if (rtb_MathFunction_f_idx_0 > 1.57079637F) {
          rtb_MathFunction_f_idx_0 = 1.57079637F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.57079637F) {
            rtb_MathFunction_f_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S179>/Saturation' */

        /* Switch: '<S235>/Switch2' incorporates:
         *  Constant: '<S180>/Constant1'
         *  RelationalOperator: '<S235>/LowerRelop1'
         *  RelationalOperator: '<S235>/UpperRelop'
         *  Switch: '<S235>/Switch'
         */
        if (rtb_Switch2_m > rtb_Add4_d) {
          rtb_Switch2_m = rtb_Add4_d;
        } else {
          if (rtb_Switch2_m < 0.5F) {
            /* Switch: '<S235>/Switch' incorporates:
             *  Constant: '<S180>/Constant1'
             */
            rtb_Switch2_m = 0.5F;
          }
        }

        /* End of Switch: '<S235>/Switch2' */

        /* Product: '<S180>/Divide1' incorporates:
         *  Constant: '<S179>/Constant'
         *  Gain: '<S179>/Gain'
         *  MinMax: '<S179>/Max'
         *  MinMax: '<S179>/Min'
         *  Product: '<S179>/Divide'
         *  Product: '<S179>/Multiply1'
         *  Sqrt: '<S225>/Sqrt'
         *  Sum: '<S225>/Sum of Elements'
         *  Trigonometry: '<S179>/Sin'
         */
        rtb_MathFunction_f_idx_0 = 2.0F * rtb_Subtract3_od * arm_sin_f32
          (rtb_MathFunction_f_idx_0) / fminf(rtb_Saturation_n, fmaxf(sqrtf
          (rtb_Gain_hc + rtb_Add3_c), 0.5F)) / rtb_Switch2_m;

        /* Saturate: '<S180>/Saturation' */
        if (rtb_MathFunction_f_idx_0 > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else if (rtb_MathFunction_f_idx_0 < -0.314159274F) {
          rtb_Saturation_n = -0.314159274F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_0;
        }

        /* End of Saturate: '<S180>/Saturation' */

        /* Sum: '<S170>/Subtract' incorporates:
         *  Product: '<S170>/Multiply'
         *  Product: '<S170>/Multiply1'
         */
        rtb_MathFunction_f_idx_0 = rtb_P_l_idx_0 * FMS_ConstB.Divide[1] -
          rtb_MathFunction_f_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S159>/Sign1' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign1' */

        /* Switch: '<S159>/Switch2' incorporates:
         *  Constant: '<S159>/Constant4'
         */
        if (rtb_MathFunction_f_idx_0 == 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        }

        /* End of Switch: '<S159>/Switch2' */

        /* DotProduct: '<S159>/Dot Product' */
        rtb_Subtract3_od = FMS_ConstB.Divide[0] * rtb_P_l_idx_0 +
          FMS_ConstB.Divide[1] * rtb_MathFunction_f_idx_1;

        /* Trigonometry: '<S159>/Acos' incorporates:
         *  DotProduct: '<S159>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S159>/Multiply' incorporates:
         *  Trigonometry: '<S159>/Acos'
         */
        rtb_MathFunction_f_idx_0 *= acosf(rtb_Subtract3_od);

        /* Math: '<S162>/Rem' incorporates:
         *  Constant: '<S162>/Constant1'
         *  Delay: '<S158>/Delay'
         *  Sum: '<S158>/Sum2'
         */
        B = rt_remf(rtb_MathFunction_f_idx_0 - FMS_DW.Delay_DSTATE_h,
                    6.28318548F);

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
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S162>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Sum: '<S158>/Sum' incorporates:
         *  Delay: '<S158>/Delay'
         */
        rtb_Add3_c = B + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S167>/Multiply1' incorporates:
         *  Constant: '<S167>/const1'
         *  DiscreteIntegrator: '<S161>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S167>/Add' incorporates:
         *  DiscreteIntegrator: '<S161>/Integrator1'
         *  Sum: '<S161>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) + B;

        /* Signum: '<S167>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Subtract3_od;
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
        rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c + B;

        /* Sum: '<S167>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Integrator1_a) + B;

        /* Sum: '<S167>/Add3' */
        rtb_Add3_c = rtb_Subtract3_od + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d;

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
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign2' */

        /* Sum: '<S167>/Add5' incorporates:
         *  Gain: '<S167>/Gain2'
         *  Product: '<S167>/Multiply4'
         *  Sum: '<S167>/Subtract2'
         */
        rtb_Integrator1_a += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F * rtb_Add4_d;

        /* Sum: '<S167>/Add6' */
        rtb_Add3_c = rtb_Integrator1_a + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract3' */
        rtb_Subtract3_od = rtb_Integrator1_a - FMS_ConstB.d;

        /* Product: '<S167>/Divide' */
        rtb_Add4_d = rtb_Integrator1_a / FMS_ConstB.d;

        /* Signum: '<S167>/Sign5' incorporates:
         *  Signum: '<S167>/Sign6'
         */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Switch2_m = -1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Gain_hc = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Switch2_m = 1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Gain_hc = 1.0F;
        } else {
          rtb_Switch2_m = rtb_Integrator1_a;

          /* Signum: '<S167>/Sign6' */
          rtb_Gain_hc = rtb_Integrator1_a;
        }

        /* End of Signum: '<S167>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S158>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_0 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S163>/Rem' incorporates:
         *  Constant: '<S163>/Constant1'
         */
        rtb_Integrator1_a = rt_remf(rtb_MathFunction_f_idx_0, 6.28318548F);

        /* Switch: '<S163>/Switch' incorporates:
         *  Abs: '<S163>/Abs'
         *  Constant: '<S163>/Constant'
         *  Constant: '<S169>/Constant'
         *  Product: '<S163>/Multiply'
         *  RelationalOperator: '<S169>/Compare'
         *  Sum: '<S163>/Add'
         */
        if (fabsf(rtb_Integrator1_a) > 3.14159274F) {
          /* Signum: '<S163>/Sign' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_0 = rtb_Integrator1_a;
          }

          /* End of Signum: '<S163>/Sign' */
          rtb_Integrator1_a -= 6.28318548F * rtb_MathFunction_f_idx_0;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Abs: '<S156>/Abs' */
        rtb_Integrator1_a = fabsf(rtb_Integrator1_a);

        /* Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S174>/Constant'
         *  RelationalOperator: '<S174>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_Integrator1_a <= 0.17453292F) +
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
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.MC_CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Saturation_n;
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
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
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
        FMS_DW.Integrator_DSTATE_i += ((rtb_Add4_d - rtb_Switch2_m) *
          FMS_ConstB.Gain4 * ((rtb_Add3_c - rtb_Subtract3_od) * 0.5F) -
          rtb_Gain_hc * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.MC_YAWRATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.MC_YAWRATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.MC_YAWRATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.MC_YAWRATE_LIM;
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
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.MC_ROLL_DZ) * rtb_Saturation_n;

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
        rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.MC_PITCH_DZ) * rtb_Saturation_n;

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
        rtb_Switch2_m = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S136>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S132>/Integrator1'
         *  Gain: '<S126>/Gain'
         *  Product: '<S126>/Multiply'
         *  Sum: '<S132>/Subtract'
         */
        rtb_MathFunction_f_idx_0 = (FMS_DW.Integrator1_DSTATE_k -
          FMS_PARAM.MC_ATT_LIM * rtb_Add3_c * (real32_T)
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
        rtb_Integrator1_a = 31.415926F * rtb_Saturation_n;

        /* Product: '<S136>/Multiply' */
        rtb_MathFunction_f_idx_1 = rtb_Integrator1_a * FMS_ConstB.Square_c;

        /* Signum: '<S136>/Sign' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_0;
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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_0) +
          rtb_MathFunction_f_idx_1) * rtb_MathFunction_f_idx_1) -
                            rtb_MathFunction_f_idx_1) * 0.5F * rtb_Saturation_n
          + rtb_Switch2_m;

        /* Sum: '<S136>/Add4' */
        rtb_Subtract3_od = (rtb_MathFunction_f_idx_0 - rtb_Saturation_n) +
          rtb_Switch2_m;

        /* Sum: '<S136>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + rtb_MathFunction_f_idx_1;

        /* Sum: '<S136>/Subtract1' */
        rtb_MathFunction_f_idx_0 -= rtb_MathFunction_f_idx_1;

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
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign2' */

        /* Sum: '<S136>/Add5' incorporates:
         *  Gain: '<S136>/Gain2'
         *  Product: '<S136>/Multiply4'
         *  Sum: '<S136>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_MathFunction_f_idx_0) * 0.5F *
          rtb_Subtract3_od;

        /* Sum: '<S136>/Add6' */
        rtb_Add3_c = rtb_Saturation_n + rtb_MathFunction_f_idx_1;

        /* Sum: '<S136>/Subtract3' */
        rtb_Subtract3_od = rtb_Saturation_n - rtb_MathFunction_f_idx_1;

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
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
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
        rtb_Subtract3_od = (rtb_Saturation_n / rtb_MathFunction_f_idx_1 -
                            rtb_Switch2_m) * -rtb_Integrator1_a * ((rtb_Add3_c -
          rtb_Subtract3_od) * 0.5F);

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
        rtb_Gain_hc = rtb_Saturation_n * rtb_Integrator1_a;

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
        rtb_MathFunction_f_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S137>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S133>/Integrator1'
         *  Gain: '<S126>/Gain1'
         *  Product: '<S126>/Multiply1'
         *  Sum: '<S133>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_nf -
                             -FMS_PARAM.MC_ATT_LIM * rtb_Add4_d * (real32_T)
                             rtb_FixPtRelationalOperator_me) +
          rtb_MathFunction_f_idx_1;

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
        rtb_MathFunction_f_idx_0 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S137>/Multiply' */
        rtb_Switch2_m = rtb_MathFunction_f_idx_0 * FMS_ConstB.Square_b;

        /* Signum: '<S137>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Integrator1_a;
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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
          rtb_Switch2_m) * rtb_Switch2_m) - rtb_Switch2_m) * 0.5F *
          rtb_Saturation_n + rtb_MathFunction_f_idx_1;

        /* Sum: '<S137>/Add4' */
        rtb_Add4_d = (rtb_Integrator1_a - rtb_Saturation_n) +
          rtb_MathFunction_f_idx_1;

        /* Sum: '<S137>/Add3' */
        rtb_Add3_c = rtb_Integrator1_a + rtb_Switch2_m;

        /* Sum: '<S137>/Subtract1' */
        rtb_Integrator1_a -= rtb_Switch2_m;

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
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign2' */

        /* Sum: '<S137>/Add5' incorporates:
         *  Gain: '<S137>/Gain2'
         *  Product: '<S137>/Multiply4'
         *  Sum: '<S137>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Integrator1_a) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S132>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S132>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Update for DiscreteIntegrator: '<S132>/Integrator' incorporates:
         *  Sum: '<S136>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += (rtb_Subtract3_od - rtb_Gain_hc) * 0.004F;

        /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S133>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_nf += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S137>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - rtb_Switch2_m;

        /* Sum: '<S137>/Add6' */
        rtb_Subtract3_od = rtb_Saturation_n + rtb_Switch2_m;

        /* Signum: '<S137>/Sign5' incorporates:
         *  Signum: '<S137>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S137>/Sign6' */
          rtb_Integrator1_a = rtb_Saturation_n;
        }

        /* End of Signum: '<S137>/Sign5' */

        /* Signum: '<S137>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
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
          rtb_Gain_hc) * -rtb_MathFunction_f_idx_0 * ((rtb_Subtract3_od -
          rtb_Add3_c) * 0.5F) - rtb_Integrator1_a * rtb_MathFunction_f_idx_0) *
          0.004F;

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
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.MC_ROLL_DZ) * rtb_Saturation_n;

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
        rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.MC_PITCH_DZ) * rtb_Saturation_n;

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
        rtb_Switch2_m = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S69>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  Gain: '<S49>/Gain'
         *  Product: '<S49>/Multiply'
         *  Sum: '<S65>/Subtract'
         */
        rtb_MathFunction_f_idx_0 = (FMS_DW.Integrator1_DSTATE_n -
          FMS_PARAM.MC_ATT_LIM * rtb_Add3_c * (real32_T)
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
        rtb_Integrator1_a = 31.415926F * rtb_Saturation_n;

        /* Product: '<S69>/Multiply' */
        rtb_Saturation_n = rtb_Integrator1_a * FMS_ConstB.Square_m;

        /* Signum: '<S69>/Sign' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_MathFunction_f_idx_0;
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
        rtb_MathFunction_f_idx_1 = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_0)
          + rtb_Saturation_n) * rtb_Saturation_n) - rtb_Saturation_n) * 0.5F *
          rtb_Add3_c + rtb_Switch2_m;

        /* Sum: '<S69>/Add4' */
        rtb_Subtract3_od = (rtb_MathFunction_f_idx_0 - rtb_MathFunction_f_idx_1)
          + rtb_Switch2_m;

        /* Sum: '<S69>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract1' */
        rtb_MathFunction_f_idx_0 -= rtb_Saturation_n;

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
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign2' */

        /* Sum: '<S69>/Add5' incorporates:
         *  Gain: '<S69>/Gain2'
         *  Product: '<S69>/Multiply4'
         *  Sum: '<S69>/Subtract2'
         */
        rtb_MathFunction_f_idx_1 += (rtb_Add3_c - rtb_MathFunction_f_idx_0) *
          0.5F * rtb_Subtract3_od;

        /* Sum: '<S69>/Add6' */
        rtb_Add3_c = rtb_MathFunction_f_idx_1 + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract3' */
        rtb_Subtract3_od = rtb_MathFunction_f_idx_1 - rtb_Saturation_n;

        /* Signum: '<S69>/Sign5' */
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_Switch2_m = -1.0F;
        } else if (rtb_MathFunction_f_idx_1 > 0.0F) {
          rtb_Switch2_m = 1.0F;
        } else {
          rtb_Switch2_m = rtb_MathFunction_f_idx_1;
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
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
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
        rtb_Subtract3_od = (rtb_MathFunction_f_idx_1 / rtb_Saturation_n -
                            rtb_Switch2_m) * -rtb_Integrator1_a * ((rtb_Add3_c -
          rtb_Subtract3_od) * 0.5F);

        /* Signum: '<S69>/Sign6' */
        if (rtb_MathFunction_f_idx_1 < 0.0F) {
          rtb_MathFunction_f_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign6' */

        /* Product: '<S69>/Multiply6' */
        rtb_Gain_hc = rtb_MathFunction_f_idx_1 * rtb_Integrator1_a;

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
          rtb_MathFunction_f_idx_1 = 0.5F;
        } else if (FMS_B.Merge_lf > FMS_PARAM.MC_VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_f_idx_1 = FMS_PARAM.MC_VEL_Z_LIM;
        } else if (FMS_B.Merge_lf < -FMS_PARAM.MC_VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_f_idx_1 = -FMS_PARAM.MC_VEL_Z_LIM;
        } else {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_f_idx_1 = FMS_B.Merge_lf;
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
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_f_idx_1;

        /* Product: '<S70>/Multiply1' incorporates:
         *  Constant: '<S70>/const1'
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        rtb_MathFunction_f_idx_1 = FMS_DW.Integrator_DSTATE_g * 0.04F;

        /* Sum: '<S70>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Gain: '<S49>/Gain1'
         *  Product: '<S49>/Multiply1'
         *  Sum: '<S66>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_i - -FMS_PARAM.MC_ATT_LIM
                             * rtb_Add4_d * (real32_T)
                             rtb_FixPtRelationalOperator_me) +
          rtb_MathFunction_f_idx_1;

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
        rtb_MathFunction_f_idx_0 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S70>/Multiply' */
        rtb_Switch2_m = rtb_MathFunction_f_idx_0 * FMS_ConstB.Square_i;

        /* Signum: '<S70>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Integrator1_a;
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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
          rtb_Switch2_m) * rtb_Switch2_m) - rtb_Switch2_m) * 0.5F *
          rtb_Saturation_n + rtb_MathFunction_f_idx_1;

        /* Sum: '<S70>/Add4' */
        rtb_Add4_d = (rtb_Integrator1_a - rtb_Saturation_n) +
          rtb_MathFunction_f_idx_1;

        /* Sum: '<S70>/Add3' */
        rtb_Add3_c = rtb_Integrator1_a + rtb_Switch2_m;

        /* Sum: '<S70>/Subtract1' */
        rtb_Integrator1_a -= rtb_Switch2_m;

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
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign2' */

        /* Sum: '<S70>/Add5' incorporates:
         *  Gain: '<S70>/Gain2'
         *  Product: '<S70>/Multiply4'
         *  Sum: '<S70>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Integrator1_a) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
         *  Sum: '<S69>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Subtract3_od - rtb_Gain_hc) * 0.004F;

        /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_i += 0.004F * FMS_DW.Integrator_DSTATE_g;

        /* Sum: '<S70>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - rtb_Switch2_m;

        /* Sum: '<S70>/Add6' */
        rtb_Subtract3_od = rtb_Saturation_n + rtb_Switch2_m;

        /* Signum: '<S70>/Sign5' incorporates:
         *  Signum: '<S70>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Gain_hc = -1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Gain_hc = 1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Gain_hc = rtb_Saturation_n;

          /* Signum: '<S70>/Sign6' */
          rtb_Integrator1_a = rtb_Saturation_n;
        }

        /* End of Signum: '<S70>/Sign5' */

        /* Signum: '<S70>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
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
          rtb_Gain_hc) * -rtb_MathFunction_f_idx_0 * ((rtb_Subtract3_od -
          rtb_Add3_c) * 0.5F) - rtb_Integrator1_a * rtb_MathFunction_f_idx_0) *
          0.004F;

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
          rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.MC_PITCH_DZ) * rtb_Saturation_n;

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
          rtb_Add4_d = 1.0F / (1.0F - FMS_PARAM.MC_ROLL_DZ) * rtb_Saturation_n;

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
          rtb_Transpose_tmp = FMS_DW.Integrator_DSTATE[0] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE[0] -
                              FMS_PARAM.MC_VEL_XY_LIM * rtb_Add3_c) +
            rtb_Transpose_tmp;

          /* Signum: '<S122>/Sign' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Subtract3_od > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Subtract3_od;
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
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
            rtb_Switch2_m) * rtb_Switch2_m) - rtb_Switch2_m) * 0.5F * rtb_Add3_c
            + rtb_Transpose_tmp;

          /* Sum: '<S122>/Add4' */
          rtb_Transpose_tmp += rtb_Subtract3_od - rtb_Integrator1_a;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Subtract3_od + rtb_Switch2_m;

          /* Sum: '<S122>/Subtract1' */
          rtb_Subtract3_od -= rtb_Switch2_m;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else {
            if (rtb_Subtract3_od > 0.0F) {
              rtb_Subtract3_od = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F *
            rtb_Transpose_tmp;

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
          rtb_Subtract3_od = rtb_Integrator1_a + rtb_Switch2_m;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_0 = rtb_Integrator1_a;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else {
            if (rtb_Subtract3_od > 0.0F) {
              rtb_Subtract3_od = 1.0F;
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
            rtb_MathFunction_f_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_1 = rtb_Integrator1_a;
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
            rtb_MathFunction_f_idx_0) * -rtb_Saturation_n * ((rtb_Subtract3_od -
            rtb_Add3_c) * 0.5F) - rtb_MathFunction_f_idx_1 * rtb_Saturation_n) *
            0.004F;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Transpose_tmp = FMS_DW.Integrator_DSTATE[1] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE[1] -
                              FMS_PARAM.MC_VEL_XY_LIM * rtb_Add4_d) +
            rtb_Transpose_tmp;

          /* Signum: '<S122>/Sign' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Subtract3_od > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Subtract3_od;
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
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
            rtb_Switch2_m) * rtb_Switch2_m) - rtb_Switch2_m) * 0.5F * rtb_Add3_c
            + rtb_Transpose_tmp;

          /* Sum: '<S122>/Add4' */
          rtb_Transpose_tmp += rtb_Subtract3_od - rtb_Integrator1_a;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Subtract3_od + rtb_Switch2_m;

          /* Sum: '<S122>/Subtract1' */
          rtb_Subtract3_od -= rtb_Switch2_m;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else {
            if (rtb_Subtract3_od > 0.0F) {
              rtb_Subtract3_od = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Add3_c - rtb_Subtract3_od) * 0.5F *
            rtb_Transpose_tmp;

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
          rtb_Subtract3_od = rtb_Integrator1_a + rtb_Switch2_m;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_0 = rtb_Integrator1_a;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else {
            if (rtb_Subtract3_od > 0.0F) {
              rtb_Subtract3_od = 1.0F;
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
            rtb_MathFunction_f_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_f_idx_1 = 1.0F;
          } else {
            rtb_MathFunction_f_idx_1 = rtb_Integrator1_a;
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
            rtb_MathFunction_f_idx_0) * -rtb_Saturation_n * ((rtb_Subtract3_od -
            rtb_Add3_c) * 0.5F) - rtb_MathFunction_f_idx_1 * rtb_Saturation_n) *
            0.004F;

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
   *  DiscreteIntegrator: '<S507>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S524>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S524>/Gain'
   *  Sum: '<S524>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_ft[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_ft[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_ft[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S526>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S526>/Gain'
   *  Sum: '<S526>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S525>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S525>/Gain'
   *  Sum: '<S525>/Sum5'
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

  /* Update for DiscreteIntegrator: '<S507>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S507>/Constant'
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
  /* Start for SwitchCase: '<S455>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S445>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S39>/Return' */

  /* Start for IfAction SubSystem: '<S39>/Hold' */
  /* Start for SwitchCase: '<S389>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S367>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S377>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S39>/Hold' */
  /* End of Start for SubSystem: '<S32>/SubMode' */

  /* Start for IfAction SubSystem: '<S32>/Auto' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S37>/Mission' */
  /* Start for Resettable SubSystem: '<S150>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S205>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

  /* Start for SwitchCase: '<S195>/Switch Case' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S524>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S526>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S525>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S504>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S500>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S500>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S405>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S405>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Return' */
  /* InitializeConditions for DiscreteIntegrator: '<S438>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for Delay: '<S436>/Delay1' */
  FMS_DW.Delay1_DSTATE_b = false;

  /* InitializeConditions for Delay: '<S436>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S437>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S484>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for Delay: '<S414>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S413>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S456>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S455>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S455>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S455>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S455>/Move Control' */

  /* SystemInitialize for Merge: '<S455>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S446>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S445>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S445>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S445>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S445>/Move Control' */

  /* SystemInitialize for Merge: '<S445>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold' */
  /* SystemInitialize for Chart: '<S368>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S378>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S390>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S389>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S389>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S389>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S389>/Move Control' */

  /* SystemInitialize for Merge: '<S389>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S367>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S367>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S367>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S367>/Move Control' */

  /* SystemInitialize for Merge: '<S367>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S377>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S377>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S377>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S377>/Move Control' */

  /* SystemInitialize for Merge: '<S377>/Merge' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for Delay: '<S158>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

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
